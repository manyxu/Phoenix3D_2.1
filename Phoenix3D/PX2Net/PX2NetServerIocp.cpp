// PX2NetServerIocp.cpp

#include "PX2NetServerIocp.hpp"
#include "PX2Assert.hpp"
#include "PX2Log.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
ServerIocp::ServerIocp(int port, int numMaxConnects, int numMaxMsgHandlers,
	BufferEventQueue *peventque) :
	ServerImp(port, numMaxConnects, numMaxMsgHandlers, peventque),
mOLBufMgr(50000)
{
	int numMaxContext = numMaxConnects;

	mAllContext = new ClientContext[numMaxContext];
	mFreeContext.reserve(numMaxContext);

	for (int i = 0; i < numMaxContext; i++)
	{
		mFreeContext.push_back(&mAllContext[i]);
	}

	mCurClientID = 0;
}
//----------------------------------------------------------------------------
ServerIocp::~ServerIocp()
{
}
//----------------------------------------------------------------------------
bool ServerIocp::Start()
{
	mIsShutdown = false;
	mNumListenThread = 0;
	mNumIOWorkerThread = 0;

	mhCompletionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, 0);
	if (NULL == mhCompletionPort)
		return false;

	if (!_SetupIOWorkers())
	{
		return false;
	}

	if (!_SetupListener())
	{
		return false;
	}

	return true;
}
//----------------------------------------------------------------------------
void ServerIocp::Shutdown()
{
	mIsShutdown = true;

	while (mNumListenThread > 0)
	{
		Sleep(100);
	}

	DisconnectAll();

	while (mNumIOWorkerThread > 0)
	{
		PostQueuedCompletionStatus(mhCompletionPort, 0, 0, NULL);
		Sleep(10);
	}

	if (mhEvent != WSA_INVALID_EVENT)
	{
		WSACloseEvent(mhEvent);
	}

	if (INVALID_SOCKET != mSktListenSocket)
	{
		closesocket(mSktListenSocket);
	}

	if (NULL != mhCompletionPort)
	{
		CloseHandle(mhCompletionPort);
	}
}
//----------------------------------------------------------------------------
void ServerIocp::DisconnectClient(unsigned int clientID)
{
	ScopedCS cs(&mContextMapMutex);

	std::map<unsigned int, ClientContext *>::iterator iter = mClientMap.find(clientID);
	if (iter != mClientMap.end())
	{
		ClientContext *pcontext = iter->second;
		mClientMap.erase(iter);

		_EnterPendingIO(pcontext);

		PostQueuedCompletionStatus(mhCompletionPort, 0xffffffff, 
			(ULONG_PTR)pcontext, NULL);
	}
}
//----------------------------------------------------------------------------
void ServerIocp::DisconnectAll()
{
	ScopedCS cs(&mContextMapMutex);

	std::map<unsigned int, ClientContext *>::iterator iter = mClientMap.begin();
	while (iter != mClientMap.end())
	{
		ClientContext *pcontext = iter->second;
		iter = mClientMap.erase(iter);

		_EnterPendingIO(pcontext);

		PostQueuedCompletionStatus(mhCompletionPort, 0xffffffff, 
			(ULONG_PTR)pcontext, NULL);
	}
}
//----------------------------------------------------------------------------
bool ServerIocp::PostWrite(unsigned int clientid, char *psrc, int srclen)
{
	ScopedCS cs(&mContextMapMutex);

	ClientContext *pcontext = _GetClientContext(clientid);
	return _PostWrite(pcontext, psrc, srclen);
}
//----------------------------------------------------------------------------
bool ServerIocp::_SetupIOWorkers()
{
	if (mNumMaxWorkers < 0)
	{
		SYSTEM_INFO sysinfo;
		GetSystemInfo(&sysinfo);
		mNumMaxWorkers = sysinfo.dwNumberOfProcessors * 2 + 1;
	}

	for (int i = 0; i < mNumMaxWorkers; i++)
	{
		DWORD threadid;
		HANDLE h = CreateThread(NULL, 0, _IOWorkerThreadProc, this, 0,
			&threadid);
		if (h == NULL) return false;

		CloseHandle(h);
	}

	return true;
}
//-----------------------------------------------------------------------------
DWORD WINAPI ServerIocp::_IOWorkerThreadProc(LPVOID pParam)
{
	ServerIocp* pthis = reinterpret_cast<ServerIocp*>(pParam);
	if (pthis)
	{
		return pthis->_DoIOWork();
	}

	return 1;
}
//----------------------------------------------------------------------------
unsigned int ServerIocp::_DoIOWork()
{
	DWORD iobytes = 0;
	ClientContext *pcontext = 0;
	LPOVERLAPPED poverlapped = 0;
	OverlapBuffer *polbuf = 0;
	UINT error_code = 0;

	InterlockedIncrement(&mNumIOWorkerThread);

	while (error_code == 0)
	{
		BOOL b = GetQueuedCompletionStatus(mhCompletionPort, &iobytes,
			(PULONG_PTR)&pcontext, &poverlapped, INFINITE);

		if (0 == pcontext) // quit
		{
			error_code = 1;
			break;
		}

		if (!b || 0==iobytes)
		{
			PX2_LOG_ERROR("GetQueuedCompletionStatus error, ret=%d, iobytes=%d", (int)b, (int)iobytes);
			_CloseClientSocket(pcontext);

			if (poverlapped != NULL)
			{
				polbuf = CONTAINING_RECORD(poverlapped, OverlapBuffer, mSysData);
				mOLBufMgr.FreeBuffer(polbuf);
			}
		}
		else
		{
			if (iobytes == 0xffffffff)
			{
				PX2_LOG_ERROR("disconnect applied");
				_CloseClientSocket(pcontext);
			}
			else if (poverlapped != NULL)
			{
				bool op_succeed = false;
				polbuf = CONTAINING_RECORD(poverlapped, OverlapBuffer, mSysData);
				switch (polbuf->GetOperation())
				{
				case IOCP_READ:
					op_succeed = _OnRead(pcontext, polbuf, iobytes);
					break;

				case IOCP_WRITE:
					op_succeed = _OnWrite(pcontext, polbuf, iobytes);
					break;
				default:
					assert(0);
					break;
				}

				if (!op_succeed)
				{
					PX2_LOG_ERROR("io operation failed, op=%d", polbuf->GetOperation());
					_CloseClientSocket(pcontext);
				}
			}
		}

		_LeavePendingIO(pcontext);
	}

	InterlockedDecrement(&mNumIOWorkerThread);

	return error_code;
}
//----------------------------------------------------------------------------
bool ServerIocp::_SetupListener()
{
	mSktListenSocket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_IP, NULL, 0,
		WSA_FLAG_OVERLAPPED);

	if (INVALID_SOCKET == mSktListenSocket)
		return false;

	mListenSocket = StreamSocket(mSktListenSocket);

	// Event for handling Network IO
	mhEvent = WSACreateEvent();
	if (WSA_INVALID_EVENT == mhEvent)
		return false;

	int ret;
	ret = WSAEventSelect(mSktListenSocket, mhEvent, FD_ACCEPT);
	if (ret == SOCKET_ERROR)
		return false;

	SOCKADDR_IN	sa;
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = htonl(INADDR_ANY);
	sa.sin_port = htons((unsigned short)mListenPort);

	if (bind(mSktListenSocket, (LPSOCKADDR)&sa, sizeof(sockaddr)) == SOCKET_ERROR)
	{
		return false;
	}

	if (listen(mSktListenSocket, SOMAXCONN) == SOCKET_ERROR)
	{
		return false;
	}

	HANDLE h = CreateThread(NULL, 0, _ListnerThreadProc, this, 0, NULL);
	if (NULL == h)
	{
		return false;
	}
	CloseHandle(h);

	return true;
}
//----------------------------------------------------------------------------
DWORD WINAPI ServerIocp::_ListnerThreadProc(LPVOID pParam)
{
	ServerIocp *pthis = reinterpret_cast<ServerIocp *>(pParam);
	if (pthis)
	{
		pthis->_DoListen();
	}

	return 1;
}
//----------------------------------------------------------------------------
unsigned int ServerIocp::_DoListen()
{
	InterlockedIncrement(&mNumListenThread);

	UINT error_code = 0;
	while (!mIsShutdown)
	{
		DWORD wait_ret = WSAWaitForMultipleEvents(1, &mhEvent, FALSE, 100, FALSE);

		if (mIsShutdown) break;

		if (WSA_WAIT_TIMEOUT == wait_ret) continue;

		WSANETWORKEVENTS events;
		if (WSAEnumNetworkEvents(mSktListenSocket, mhEvent, &events) == SOCKET_ERROR)
		{
			error_code = 2;
			break;
		}

		if (events.lNetworkEvents & FD_ACCEPT)
		{
			if (events.iErrorCode[FD_ACCEPT_BIT] == 0)
			{
				SOCKET s = WSAAccept(mSktListenSocket, NULL, NULL, 0, 0);

				if (s == INVALID_SOCKET)
				{
					if (WSAGetLastError() != WSAEWOULDBLOCK)
					{
						assertion(false, "");
						// log
					}
				}
				else
				{
					_AddClientSocket(s);
				}
			}
			else
			{
				error_code = 3;
				break;
			}
		}

	}

	InterlockedDecrement(&mNumListenThread);

	return error_code;
}
//-----------------------------------------------------------------------------
static void _MyCloseSocket(SOCKET s, bool gracefull = true)
{
	if (s == INVALID_SOCKET) return;

	if (!gracefull)
	{
		LINGER lingerStruct;
		lingerStruct.l_onoff = 1;
		lingerStruct.l_linger = 0;
		setsockopt(s, SOL_SOCKET, SO_LINGER, (char *)&lingerStruct, sizeof(lingerStruct));
	}

	CancelIo((HANDLE)s);
	closesocket(s);
}
//----------------------------------------------------------------------------
bool ServerIocp::_AddClientSocket(px2_socket_t s)
{
	assertion(s != INVALID_SOCKET, "socket must valid");

	ClientContext* pcontext = _AllocContext(s);
	if (pcontext == NULL)
	{
		_MyCloseSocket(s, false);
		return false;
	}

	if (CreateIoCompletionPort((HANDLE)s, mhCompletionPort, (ULONG_PTR)pcontext, 0) == NULL)
	{
		PX2_LOG_ERROR("add socket to completion port error");
		goto error_handle;
	}

	if (!_PostRead(pcontext, 0))
	{
		PX2_LOG_ERROR("post read error");
		goto error_handle;
	}

	mBufferEventQue->PostConnectEvent(pcontext->mClientID);
	
	return true;

error_handle:

	DisconnectClient(pcontext->mClientID);

	return false;
}
//----------------------------------------------------------------------------
void ServerIocp::_CloseClientSocket(ClientContext *pcontext)
{
	SOCKET tmp_s = INVALID_SOCKET;
	
	{
		ScopedCS cs(&mContextLock);

		if (pcontext->mSocket != INVALID_SOCKET)
		{
			tmp_s = pcontext->mSocket;
			pcontext->mSocket = INVALID_SOCKET;
		}
	}

	if (tmp_s != INVALID_SOCKET)
		_MyCloseSocket(tmp_s);
}
//----------------------------------------------------------------------------
ClientContext *ServerIocp::_GetClientContext(unsigned int clientid)
{
	ScopedCS cs(&mContextLock);

	std::map<unsigned int, ClientContext *>::iterator iter = 
		mClientMap.find(clientid);
	if (iter == mClientMap.end())
	{
		return 0;
	}
	else
	{
		return iter->second;
	}
}
//----------------------------------------------------------------------------
const char *WindowsWSAErrorCode2Text(unsigned int dw)
{
	const char *error = "";
	// Put your own common error text here (give more explaination etc..) 
	switch (dw)
	{
	case WSAEFAULT:
		error = "WSAEFAULT	The buf parameter is not completely contained in a valid part of the user address space.";
		break;
	case WSAENOTCONN:
		error = "WSAENOTCONN	The socket is not connected.";
		break;
	case WSAEINTR:
		error = "WSAEINTR	The (blocking) call was canceled through WSACancelBlockingCall.	";
		break;
	case WSAENOTSOCK:
		error = " WSAENOTSOCK	The descriptor s is not a socket.";
		break;
	case WSANOTINITIALISED:
		error = "WSANOTINITIALISED: A successful WSAStartup call must occur before using this function.";
		break;
	case WSAENETDOWN:
		error = "WSAENETDOWN	The network subsystem has failed.";
		break;
	case WSAEINPROGRESS:
		error = "WSAEINPROGRESS	A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function.";
		break;
	case WSAENETRESET:
		error = " WSAENETRESET	The connection has been broken due to the keep-alive activity detecting a failure while the operation was in progress.";
		break;
	case WSAEOPNOTSUPP:
		error = "WSAEOPNOTSUPP	MSG_OOB was specified, but the socket is not stream-style such as type SOCK_STREAM, OOB data is not supported in the communication domain associated with this socket, or the socket is unidirectional and supports only send operations.	";
		break;
	case WSAESHUTDOWN:
		error = "WSAESHUTDOWN	The socket has been shut down; it is not possible to receive on a socket after shutdown has been invoked with how set to SD_RECEIVE or SD_BOTH.";
		break;
	case WSAEWOULDBLOCK:
		error = " WSAEWOULDBLOCK	The socket is marked as nonblocking and the receive operation would block.	";
		break;
	case WSAEMSGSIZE:
		error = " WSAENOTSOCK		The message was too large to fit into the specified buffer and was truncated.";
		break;
	case WSAEINVAL:
		error = "WSAEINVAL	The socket has not been bound with bind, or an unknown flag was specified, or MSG_OOB was specified for a socket with SO_OOBINLINE enabled or (for byte stream sockets only) len was zero or negative.	";
	case WSAECONNABORTED:
		error = " 	WSAECONNABORTED	The virtual circuit was terminated due to a time-out or other failure. The application should close the socket as it is no longer usable.";
		break;
	case WSAETIMEDOUT:
		error = "WSAETIMEDOUT	The connection has been dropped because of a network failure or because the peer system failed to respond.	";
		break;
	case WSAECONNRESET:
		//error="WSAECONNRESET	The virtual circuit was reset by the remote side executing a hard or abortive close."; 
		error = "WSAECONNRESET Connection dropped..";
		break;

	case WSA_OPERATION_ABORTED:
		error = "The overlapped operation has been canceled due to the closure of the socket.";
		break;

	case WSAEDISCON:
		error = "Socket s is message oriented and the virtual circuit was gracefully closed by the remote side.";
		break;

	default:
		error = "unknown error";
		break;
	}

	return error;
}
//----------------------------------------------------------------------------
void ServerIocp::_EnterPendingIO(ClientContext *pcontext)
{
	ScopedCS cs(&mContextLock);

	pcontext->mNumPendingIO++;
}
//----------------------------------------------------------------------------
void ServerIocp::_LeavePendingIO(ClientContext *pcontext)
{
	bool needfree = false;
	{
		ScopedCS cs(&mContextLock);

		pcontext->mNumPendingIO--;

		if (pcontext->mNumPendingIO == 0 && pcontext->mSocket == INVALID_SOCKET) 
			needfree = true;
	}

	if (needfree)
	{
		mBufferEventQue->PostDisconnectEvent(pcontext->mClientID);

		_FreeContext(pcontext);
	}
}
//----------------------------------------------------------------------------
bool ServerIocp::_PostRead(ClientContext *pcontext, OverlapBuffer *pbuf)
{
	if (0 == pbuf)
	{
		pbuf = mOLBufMgr.AllocBuffer(IOCP_READ);
		
		if (pbuf == NULL)
		{
			PX2_LOG_ERROR("alloc buffer error");

			return false;
		}
	}

	pbuf->PrepareRecv();

	DWORD recvbytes = 0;
	DWORD flags = MSG_PARTIAL;
	memset(&pbuf->mSysData, 0, sizeof(OVERLAPPED));

	_EnterPendingIO(pcontext);

	int ret = WSARecv(pcontext->mSocket, &pbuf->mWSABuf, 1, &recvbytes, &flags, &pbuf->mSysData, 0);

	if (ret == SOCKET_ERROR && WSAGetLastError() != WSA_IO_PENDING)
	{
		mOLBufMgr.FreeBuffer(pbuf);
		
		_LeavePendingIO(pcontext);

		const char *pstr = WindowsWSAErrorCode2Text(WSAGetLastError());

		PX2_LOG_ERROR("wsarecv error: %s", pstr);

		return false;
	}

	return true;
}
//----------------------------------------------------------------------------
bool ServerIocp::_PostWrite(ClientContext *pcontext, char *psrc, int srclen)
{
	if (pcontext == NULL || pcontext->mSocket == PX2_INVALID_SOCKET)
	{
		return false;
	}

	int cursor = 0;
	while (cursor < srclen)
	{
		OverlapBuffer *pbuf = mOLBufMgr.AllocBuffer(IOCP_WRITE);
		if (pbuf == 0)
		{
			PX2_LOG_ERROR("AllocBuffer error");
			return false;
		}

		cursor += pbuf->PushData(psrc + cursor, srclen - cursor);
		pbuf->PrepareSend();

		DWORD sendbytes = 0;
		DWORD flags = MSG_PARTIAL;
		memset(&pbuf->mSysData, 0, sizeof(OVERLAPPED));

		_EnterPendingIO(pcontext);

		int ret = WSASend(pcontext->mSocket, &pbuf->mWSABuf, 1, &sendbytes, flags, &pbuf->mSysData, NULL);
		if (ret == 0)
		{
		}
		else
		{
			assert(ret == SOCKET_ERROR);
			if (WSAGetLastError() != WSA_IO_PENDING)
			{
				PX2_LOG_ERROR("WSASend error");
				_LeavePendingIO(pcontext);
				mOLBufMgr.FreeBuffer(pbuf);
				
				return false;
			}
		}
	}

	assert(cursor == srclen);

	return true;
}
//----------------------------------------------------------------------------
#define PACKAGE_LEN_BYTES 2
bool ServerIocp::_OnRead(ClientContext *pcontext, OverlapBuffer *pbuf, 
	unsigned int nbytes)
{
	pbuf->DataAppended(nbytes);

	for (;;)
	{
		int num_readbytes = 0;
		int srclen = pbuf->GetDataLen();

		if (pcontext->mBufferEvent)
		{
			int need_len = pcontext->mPackageTotalLength - pcontext->mBufferEvent->mDataLength;
			num_readbytes = need_len <= srclen ? need_len : srclen;
		}
		else if (srclen >= PACKAGE_LEN_BYTES)
		{
			int pkglen = pbuf->PopUShort();
			srclen = pbuf->GetDataLen();
			pcontext->mPackageTotalLength = pkglen;

			BufferEvent *pevent = mBufferEventQue->AllocBufferEvent(pkglen);
			if (pevent == NULL)
			{
				PX2_LOG_ERROR("AllocBufferEvent error");
				mOLBufMgr.FreeBuffer(pbuf);

				return false;
			}

			pevent->m_ClientID = pcontext->mClientID;
			pcontext->mBufferEvent = pevent;

			num_readbytes = pkglen <= srclen ? pkglen : srclen;
		}
		else
		{
			break;
		}

		if (num_readbytes > 0)
		{
			assertion(0!=pcontext->mBufferEvent, "");

			char *pdest = pcontext->mBufferEvent->PrepareDataSpace(num_readbytes);
			if (0 != pdest)
			{
				pbuf->PopData(pdest, num_readbytes);
			}

			if (pcontext->mBufferEvent->mDataLength >= pcontext->mPackageTotalLength)
			{
				if (pcontext->mBufferEvent->mDataLength != pcontext->mPackageTotalLength)
				{
					mOLBufMgr.FreeBuffer(pbuf);
					PX2_LOG_ERROR("wrong data received, datalen=%d, pkglen=%d",	pcontext->mBufferEvent->mDataLength, pcontext->mPackageTotalLength);
					return false;
				}

				mBufferEventQue->PostBufferEvent(pcontext->mBufferEvent);
				
				pcontext->mBufferEvent = NULL;
			}
		}
		else break;
	}

	return _PostRead(pcontext, pbuf);
}
//----------------------------------------------------------------------------
bool ServerIocp::_OnWrite(ClientContext *pcontext, OverlapBuffer *pbuf,
	unsigned int nbytes)
{
	PX2_UNUSED(pcontext);

	if ((int)nbytes != pbuf->GetDataLen())
	{
		PX2_LOG_ERROR("write error");

		mOLBufMgr.FreeBuffer(pbuf);

		return false;
	}

	mOLBufMgr.FreeBuffer(pbuf);

	return true;
}
//----------------------------------------------------------------------------