// PX2NetServer.cpp

#include "PX2NetServer.hpp"
#include "PX2Log.hpp"
#include "PX2NetServerIocp.hpp"
#include "PX2Time.hpp"
#include "PX2System.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
Server::Server()
{
}
//----------------------------------------------------------------------------
Server::Server(ServerType serverType, int port, int numMaxConnects, 
	int numMaxMsgHandlers):
	mServerType(serverType),
	mPort(port),
	mNumMaxConnects(numMaxConnects),
	mNumMaxMsgHandlers(numMaxMsgHandlers)
{
	int max_events[] = {
		100000, 100000, 100000, 100000, 100000, 100000,
		100000, 100000, 100000, 100000, 100000, 100000,
		100000, 100000, 100000, 100000, 100000, 100000,
		100000, 100000 };

	mBufferEventQue = new BufferEventQueue(64, 1024 * 64, max_events);

	mMsgHandlers.resize(numMaxMsgHandlers, 0);

	RegisterHandler(BufferEvent::MSGID_RESERVED, &Server::OnReservedMsg);

	if (ST_IOCP == serverType)
	{
		mServerImp = new0 ServerIocp(mPort, mNumMaxConnects, mNumMaxMsgHandlers,
			mBufferEventQue);
	}
	else
	{
		assertion(false, "not support now");
	}
}
//-----------------------------------------------------------------------------
Server::~Server()
{
}
//-----------------------------------------------------------------------------
const std::vector<int> &Server::GetThreadIDs() const
{
	return mServerImp->GetThreadIDs();
}
//-----------------------------------------------------------------------------
void Server::LogStatus()
{
	int events_alloc[20];

	//int n1 = mServerImp->GetNumUsedBuffer();
	int n1 = 0;
	int n2 = mServerImp->GetClientMapSize();
	int n3 = mBufferEventQue->GetNumAllocEvent();
	int n4 = mBufferEventQue->GetEventQueLen();
	int n5 = mBufferEventQue->GetNumEventInPool(events_alloc);

	printf("sys info: %d, %d, %d, %d, %d, %d, %d, %d\n", n1, n2, n3, n4, n5,
		events_alloc[0], events_alloc[1], events_alloc[2]);
}
//-----------------------------------------------------------------------------
bool Server::Start()
{
	if (!mServerImp->Start())
	{
		PX2_LOG_ERROR("iocp server start failed\n");
		return false;
	}

	PX2_LOG_INFO("server start succeeded\n");
	
	return true;
}
//-----------------------------------------------------------------------------
void Server::Shutdown()
{
	mServerImp->Shutdown();
}
//-----------------------------------------------------------------------------
void Server::Run()
{
	while (true)
	{
		HandleClientEvents();

		System::SleepSeconds(0.1f);
	}
}
//-----------------------------------------------------------------------------
int Server::GetNumConnects()
{
	return mServerImp->GetNumUsedContext();
}
//-----------------------------------------------------------------------------
void Server::DisconnectClient(unsigned int clientid)
{
	mServerImp->DisconnectClient(clientid);
}
//----------------------------------------------------------------------------
int Server::HandleClientEvent(BufferEvent *ent)
{
	int msgid = ReadMessageID(ent->mBuffer);

	if (msgid < 0 || msgid >= int(mMsgHandlers.size()))
		return CER_MSGID_OUTRANGE;

	MsgHandleFunc pfunc = mMsgHandlers[msgid];
	if (!pfunc)
		return CER_HANDLER_NULL;

	return (this->*pfunc)(ent->m_ClientID,
		((const char *)ent->mBuffer) + MSGID_BYTES,
		ent->mDataLength - MSGID_BYTES);
}
//----------------------------------------------------------------------------
void Server::HandleClientEvents()
{
	BufferEvent *ent = 0;

	while (0 != (ent = mBufferEventQue->PopBufferEvent()))
	{
		int result = HandleClientEvent(ent);

		if (CER_SUCCEED != result)
		{
			PX2_LOG_ERROR("HandleClientEvent error, clientid=%d, result=%d£¬msgid=%d",
				ent->m_ClientID, result, ReadMessageID(ent->mBuffer));
			
			mServerImp->DisconnectClient(ent->m_ClientID); //!!!ÊÇ·ñÓ¦¸Ã¶Ïµô
		}

		mBufferEventQue->FreeBufferEvent(ent);
	}
}
//----------------------------------------------------------------------------
void Server::RegisterHandler(int msgid, MsgHandleFunc msgfunc)
{
	assertion(msgid >= 0 && msgid<(int)mMsgHandlers.size(), 
		"msgid must be in range");

	mMsgHandlers[msgid] = msgfunc;
}
//----------------------------------------------------------------------------
int Server::OnReservedMsg(unsigned int clientid, const void *pbuffer, int buflen)
{
	char flags = *(const char *)pbuffer;

	if (flags == 0) //connect
	{
		PX2_LOG_INFO("clientid=%d connect", clientid);

		OnConnect(clientid);
	}
	else if (flags == 1) //disconnect
	{
		PX2_LOG_INFO("clientid=%d disconnect", clientid);

		OnDisconnect(clientid);
	}

	return 0;
}
//----------------------------------------------------------------------------