/*
*
* 文件名称	：	PX2ClientConnect.cpp
*
*/

#include "PX2NetClientConnect.hpp"
#include "PX2Log.hpp"
#include "PX2SocketImpl.hpp"
#include "PX2NetError.hpp"
#include "PX2Time.hpp"
#include "PX2System.hpp"
using namespace PX2;

const int max_recvbuf = 64*1024;
const int max_sendbuf = 64*1024;
//----------------------------------------------------------------------------
int ClientConnect::ClientOnRead()
{
	int nbytes = mSocket.ReceiveBytes(mRecvBuf+mRecvLen, max_recvbuf-mRecvLen, 0);

	if(nbytes < 0)
	{
		return -1;
	}

	mRecvLen += nbytes;
	while(mRecvLen >= MSGLEN_BYTES)
	{
		int msglen = *(unsigned short *)mRecvBuf;
		int pkglen = msglen + MSGLEN_BYTES;
		if(pkglen > max_recvbuf)
		{
			return -2;
		}

		if(mRecvLen >= pkglen)
		{
			BufferEvent *pevent = mRecvQue->AllocBufferEvent(msglen);
			pevent->PushData(mRecvBuf+2, msglen);
			mRecvQue->PostBufferEvent(pevent);

			memmove(mRecvBuf, mRecvBuf+pkglen, mRecvLen-pkglen);
			mRecvLen -= pkglen;
		}
		else break;
	}

	return 0;
}
//----------------------------------------------------------------------------
int ClientConnect::ClientOnWrite()
{
	if(mSendLen == 0)
	{
		if(mWaitConfirmMsg.size() > 0) //有等待确认的消息， 就停止发送后续的消息
		{
			if(mConnStateTime > 3.0f) //等待太长， 认为是断线
			{
				return -1;
			}
			else return 0;
		}

		BufferEvent *pevent = mSendQue->PopBufferEvent();

		if(pevent == 0)
		{
			return 0;
		}

		int msgid = pevent->GetMessageID();
		if(msgid == BufferEvent::MSGID_RESERVED)
		{
			mSendQue->FreeBufferEvent(pevent);
			return -1;
		}

		assert(pevent->m_DataLen+2 <= max_sendbuf);
		*(unsigned short *)mSendBuf = (unsigned short)pevent->m_DataLen;
		memcpy(mSendBuf+2, pevent->m_Buffer, pevent->m_DataLen);
		mSendLen = pevent->m_DataLen + 2;

		/* 不再使用底层的检查断线机制
		if(mMsgHandlers[msgid].need_answer)
		{
			mWaitConfirmMsg.push_back(pevent);
		}
		else*/ 
			mSendQue->FreeBufferEvent(pevent);
	}

	int nbytes = mSocket.SendBytes(mSendBuf, mSendLen, 0);
	if(nbytes < 0)
	{
		return -1;
	}

	if(nbytes > 0)
	{
		memmove(mSendBuf, mSendBuf+nbytes, mSendLen-nbytes);
		mSendLen -= nbytes;
		assert(mSendLen >= 0);
	}

	return 0;
}
//----------------------------------------------------------------------------
ClientConnect::ClientConnect(int num_msghandlers) 
	: 
mConnectState(CONNSTATE_INIT),
mConnStateTime(0)
{
	int max_events[] = {1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024 };
	mSendQue = new BufferEventQueue(16, 64*1024, max_events);
	mRecvQue = new BufferEventQueue(16, 64*1024, max_events);

	mRecvBuf = new char[max_recvbuf];
	mSendBuf = new char[max_sendbuf];
	mRecvLen = mSendLen = 0;

	ServerMsgDesc tmpdesc = {NULL, false, -1};
	mMsgHandlers.resize(num_msghandlers, tmpdesc);
	RegisterHandler(0, &ClientConnect::OnReservedMsg);
}
//----------------------------------------------------------------------------
ClientConnect::~ClientConnect()
{
	delete mSendQue;
	delete mRecvQue;
	delete[] mRecvBuf;
	delete[] mSendBuf;
}
//----------------------------------------------------------------------------
void ClientConnect::InternalConnect()
{
	mRecvLen = 0;
	mSendLen = 0;

	if(0 != mSocket.Connect(mAddr))
	{
		int err = NetError::LastError();
		if(err == PX2_EISCONN)
		{
			SetConnectState(CONNSTATE_CONNECTED);
		}
		else if(err == PX2_EWOULDBLOCK)
		{
			SetConnectState(CONNSTATE_TRYCONNECT);
		}
	}
	else
	{
		SetConnectState(CONNSTATE_CONNECTED);
	}

	SetConnectState(CONNSTATE_CONNECTED);
}
//----------------------------------------------------------------------------
int ClientConnect::Connect (const SocketAddress &addr)
{
	mAddr = addr;
	
	InternalConnect();
	return 0;
}
//----------------------------------------------------------------------------
void ClientConnect::InternalDisconnect()
{
	mRecvLen = 0;
	mSendLen = 0;

	mSocket.Shutdown();
	mSocket.Close();
}

//----------------------------------------------------------------------------
int ClientConnect::Disconnect()
{
	InternalDisconnect();
	SetConnectState(CONNSTATE_INIT);

	return 0;
}
//----------------------------------------------------------------------------
int ClientConnect::Reconnect(BufferEvent *pevent)
{
	assert(mConnectState == CONNSTATE_CONN_ERROR);

	InternalDisconnect();
	InternalConnect();

	if(mConnectState == CONNSTATE_CONN_ERROR)
	{
		return -1;
	}

	for(size_t i=mWaitConfirmMsg.size(); i>0; i--)
	{
		mSendQue->InsertEventFront(mWaitConfirmMsg[i-1]);
	}
	mWaitConfirmMsg.resize(0);

	if(pevent)
	{
		mSendQue->InsertEventFront(pevent);
	}

	return 0;
}
//----------------------------------------------------------------------------
void ClientConnect::RegisterHandler(int msgid, ServerMsgHandleFunc msgfunc, bool need_answer, int other_answer_msg)
{
	assert(msgid>=0 && msgid<int(mMsgHandlers.size()));

	mMsgHandlers[msgid].handler = msgfunc;
	mMsgHandlers[msgid].need_answer = need_answer;
	mMsgHandlers[msgid].other_answermsg = other_answer_msg;
}
//----------------------------------------------------------------------------
int ClientConnect::OnReservedMsg(const void *pbuffer, int buflen)
{
	PX2_UNUSED(buflen);

	char flags = *(const char *)pbuffer;
	if(flags == 0) SetConnectState(CONNSTATE_CONNECTED);
	else if(flags == 1) SetConnectState(CONNSTATE_INIT);
	else
	{
		assertion(false, "");
	}

	return 0;
}
//----------------------------------------------------------------------------
int ClientConnect::Update(float elapsedSeconds)
{
	mConnStateTime += elapsedSeconds;
	if (CONNSTATE_INIT == mConnectState || CONNSTATE_CONN_ERROR == mConnectState)
	{
		return 0;
	}

	Socket::SocketList listRead;
	Socket::SocketList listWrite;
	Socket::SocketList listExcept;
	listRead.push_back(mSocket);
	listWrite.push_back(mSocket);
	listExcept.push_back(mSocket);
	Timespan span(5000);

	int rc = mSocket.Select(listRead, listWrite, listExcept, span);
	if (rc == -1)
	{
		PX2_LOG_ERROR("mSocket.Select error.");

		return -1;
	}

	if (rc == 0)
	{
		// 超时进入下一轮循环
		return 0;
	}

	if(CONNSTATE_TRYCONNECT == mConnectState)
	{
		if(listWrite.size() > 0)
		{
			SetConnectState(CONNSTATE_CONNECTED);
		}
		if(listExcept.size() > 0)
		{
			SetConnectState(CONNSTATE_INIT);
			return 0;
		}
	}
	else
	{
		if(listRead.size() > 0)
		{
			if (ClientOnRead() < 0)
			{
				SetConnectState(CONNSTATE_CONN_ERROR);
				return -1;
			}
		}

		if(listWrite.size() > 0)
		{
			if(ClientOnWrite() < 0)
			{
				SetConnectState(CONNSTATE_CONN_ERROR);
				return -1;
			}
		}

		if(listExcept.size() > 0)
		{
			SetConnectState(CONNSTATE_CONN_ERROR);
			return -1;
		}
	}
	return HandleServerMsg();
}

//----------------------------------------------------------------------------
void ClientConnect::ConfirmMsgCome(int msgid)
{
	std::vector<BufferEvent *>::iterator iter = mWaitConfirmMsg.begin();
	for(; iter!=mWaitConfirmMsg.end(); iter++)
	{
		BufferEvent *pevent2 = *iter;
		int msgid2 = pevent2->GetMessageID();
		if(msgid==msgid2 || msgid==mMsgHandlers[msgid2].other_answermsg) //收到服务器confirm的消息
		{
			mWaitConfirmMsg.erase(iter);
			mSendQue->FreeBufferEvent(pevent2);
			break;
		}
	}

	if(mConnectState==CONNSTATE_WAITSERVER && mWaitConfirmMsg.empty())
	{
		SetConnectState(CONNSTATE_CONNECTED);
	}
}
//----------------------------------------------------------------------------
int ClientConnect::HandleServerBufferEvent(BufferEvent *pevent)
{
	int msgid = ReadMessageID(pevent->m_Buffer);

	if(msgid<0 || msgid>=int(mMsgHandlers.size()))
	{
		return -2;
	}

	ConfirmMsgCome(msgid);

	ServerMsgHandleFunc func = mMsgHandlers[msgid].handler;
	if(func == NULL)
	{
		return -3;
	}

	if((this->*func)(pevent->m_Buffer+MSGID_BYTES, pevent->m_DataLen-MSGID_BYTES) < 0)
	{
		return -4;
	}
	return 0;
}

int ClientConnect::HandleServerMsg()
{
	BufferEvent *pevent;
	while((pevent=mRecvQue->PopBufferEvent()) != NULL)
	{
		int ret = HandleServerBufferEvent(pevent);
		mRecvQue->FreeBufferEvent(pevent);

		if(ret < 0) return ret;
	}
	return 0;
}
//----------------------------------------------------------------------------