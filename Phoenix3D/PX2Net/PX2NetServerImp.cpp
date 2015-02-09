// PX2NetServerImp.cpp

#include "PX2NetServerImp.hpp"
#include "PX2ScopedCS.hpp"
#include "PX2Log.hpp"
#include "PX2Assert.hpp"
using namespace PX2;

//-----------------------------------------------------------------------------
// ClientContext
//-----------------------------------------------------------------------------
void ClientContext::Init(px2_socket_t s, unsigned int clientID)
{
	mSocket = s;
	mClientID = clientID;
	mNumPendingIO = 0;
	mBufferEvent = 0;
	mPackageTotalLength = 0;
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ServerImp
//-----------------------------------------------------------------------------
ServerImp::ServerImp(int port, int numMaxConnects, int numMaxMsgHandlers,
	BufferEventQueue *peventque) :
mIsShutdown(true),
mListenPort(port),
mNumMaxConnects(numMaxConnects),
mNumMaxWorkers(numMaxMsgHandlers),
mBufferEventQue(peventque),
mCurClientID(0),
mNumListenThread(0),
mNumIOWorkerThread(0)
{
}
//-----------------------------------------------------------------------------
ServerImp::~ServerImp()
{
}
//-----------------------------------------------------------------------------
int ServerImp::GetNumUsedContext()
{
	ScopedCS cs(&mContextMapMutex);

	return mNumMaxConnects - int(mFreeContext.size());
}
//-----------------------------------------------------------------------------
int ServerImp::GetClientMapSize()
{
	ScopedCS cs(&mContextMapMutex);

	return int(mClientMap.size());
}
//-----------------------------------------------------------------------------
ClientContext *ServerImp::_AllocContext(px2_socket_t socket)
{
	ScopedCS cs(&mContextMapMutex);

	size_t i = mFreeContext.size();
	if (0 == i)
	{
		PX2_LOG_ERROR("alloc context failed");
		return 0;
	}
	else
	{
		ClientContext *pcontext = mFreeContext[i - 1];
		mFreeContext.pop_back();

		mCurClientID++;
		
		if (mCurClientID == 0) 
			mCurClientID++;

		pcontext->Init(socket, mCurClientID);

		assertion(mClientMap.find(mCurClientID) == mClientMap.end(), 
			"%d must not in mClientMap", mCurClientID);

		mClientMap[mCurClientID] = pcontext;

		return pcontext;
	}
}
//-----------------------------------------------------------------------------
void ServerImp::_FreeContext(ClientContext *pcontext)
{
	ScopedCS cs(&mContextMapMutex);

	//!!!
	assertion(INVALID_SOCKET==pcontext->mSocket, "");

	if (pcontext->mBufferEvent)
	{
		mBufferEventQue->FreeBufferEvent(pcontext->mBufferEvent);
		pcontext->mBufferEvent = NULL;
	}

	mClientMap.erase(pcontext->mClientID);
	mFreeContext.push_back(pcontext);
}
//-----------------------------------------------------------------------------
ClientContext *ServerImp::_GetClientContext(unsigned int clientid)
{
	ScopedCS cs(&mContextMapMutex);

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
//-----------------------------------------------------------------------------
void ServerImp::_EnterPendingIO(ClientContext *pcontext)
{
	ScopedCS cs(&mContextLock);

	pcontext->mNumPendingIO++;
}
//----------------------------------------------------------------------------
void ServerImp::_LeavePendingIO(ClientContext *pcontext)
{
	bool needfree = false;
	{
		ScopedCS tmplock(&mContextLock);

		pcontext->mNumPendingIO--;

		if (pcontext->mNumPendingIO == 0 && pcontext->mSocket == PX2_INVALID_SOCKET)
			needfree = true;
	}

	if (needfree)
	{
		mBufferEventQue->PostDisconnectEvent(pcontext->mClientID);

		_FreeContext(pcontext);
	}
}
//----------------------------------------------------------------------------