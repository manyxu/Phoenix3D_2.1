// PX2NetServerImp.hpp

#ifndef PX2NETSERVERIMP_HPP
#define PX2NETSERVERIMP_HPP

#include "PX2NetPre.hpp"
#include "PX2SmartPointer.hpp"
#include "PX2StreamSocket.hpp"
#include "PX2NetEventBuffer.hpp"

namespace PX2
{


	class ClientContext
	{
	public:
		void Init(const StreamSocket &s, unsigned int clientid);

	public:
		px2_socket_t mSocket;
		unsigned int mClientID;
		long mNumPendingIO;

		BufferEvent *m_pBufferEvent;
		int m_PackageTotalLen;
	};

	class ServerImp
	{
	public:
		ServerImp(int port, int numMaxConnects, int numMaxMsgHandlers,
			BufferEventQueue *peventque);
		virtual ~ServerImp();

		virtual bool Start();
		virtual void Shutdown();

		int GetNumUsedContext();
		int GetClientMapSize();

		virtual void DisconnectClient(unsigned int clientID) = 0;
		virtual void DisconnectAll() = 0;

	protected:
		ClientContext *_AllocContext(const StreamSocket &socket);
		void _FreeContext(ClientContext *pcontext);
		ClientContext *_GetClientContext(unsigned int clientid);

		void _EnterPendingIO(ClientContext *pcontext);
		void _LeavePendingIO(ClientContext *pcontext);

		bool mIsShutdown;
		int mListenPort;
		int mNumMaxConnects;
		int mNumMaxWorkers;
		volatile long mNumListenThread;
		volatile long mNumIOWorkerThread;

		StreamSocket mListenSocket;

		ClientContext *mAllContext;
		std::vector<ClientContext *> mFreeContext;
		std::map<unsigned int, ClientContext *> mClientMap;
		unsigned int mCurClientID;

		Mutex mContextMapMutex;
		Mutex mContextLock;

		BufferEventQueue *mBufferEventQue;
	};
	typedef Pointer0<ServerImp> ServerImpPtr;

}

#endif