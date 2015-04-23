// PX2ClientConnect.hpp

#ifndef PX2NETCLIENTCONNECT_HPP
#define PX2NETCLIENTCONNECT_HPP

#include "PX2NetPre.hpp"
#include "PX2NetEventBuffer.hpp"
#include "PX2SmartPointer.hpp"
#include "PX2SocketAddress.hpp"
#include "PX2StreamSocket.hpp"

namespace PX2
{

	enum
	{
		CONNSTATE_INIT = 0,
		CONNSTATE_TRYCONNECT,
		CONNSTATE_CONNECTED,
		CONNSTATE_CONN_ERROR, //连接出错状态， 等待重连
		CONNSTATE_WAITSERVER, //向服务器发送完消息， 等待回复消息
	};

	class ClientConnector
	{
	public:
		typedef int (ClientConnector::*ServerMsgHandleFunc)(const void *pbuffer, int buflen);

	public:
		ClientConnector(int num_msghandlers);
		virtual ~ClientConnector();

		void RegisterHandler(int msgid, ServerMsgHandleFunc msgfunc, bool need_answer=true, int other_answer_msg=-1);

		StreamSocket &GetSocket ();
		int ConnectB(const std::string &ip, int16_t port);
		int ConnectB(const SocketAddress &addr);
		int ConnectNB(const std::string &ip, int16_t port);
		int ConnectNB(const SocketAddress &addr);
		void Disconnect();
		int GetConnectState ();
		void SetConnectState(int state);

		//出现网络错误时， 调用此函数试图重连，并且把之前没确认发到的消息重新再发
		//传入需要在消息重发前需要发送的复位消息， 如果为NULL， 就不会发复位消息
		int Reconnect(BufferEvent *ent = 0);

		template<class T>
		int SendMsgToServer(int msgid, const T &msg);

		template<class T>
		BufferEvent *CreateSendEvent(int msgid, const T &msg);

		int Update(float elapsedSeconds);

	private:
		struct ServerMsgDesc
		{
			ServerMsgHandleFunc handler;
			bool need_answer;
			int other_answermsg;
		};
		std::vector<ServerMsgDesc>mMsgHandlers;

		BufferEventQueue *mSendQue;
		BufferEventQueue *mRecvQue;

		int mConnectState;
		float mConnStateTime; //处在此状态的时间

		char *mRecvBuf;
		int mRecvLen;
		char *mSendBuf;
		int mSendLen;

		SocketAddress mAddr;
		StreamSocket mSocket;

	private:
		int _InternalConnectB();
		int _InternalConnectNB();
		void _InternalDisconnect();
		int _HandleServerMsg ();
		int _HandleServerBufferEvent(BufferEvent *pevent);
		int _OnReservedMsg (const void *pbuffer, int buflen);
		int _ClientOnRead();
		int _ClientOnWrite();
	};

#include "PX2NetClientConnector.inl"
	typedef Pointer0<ClientConnector> ClientConnectPtr;

}

#endif