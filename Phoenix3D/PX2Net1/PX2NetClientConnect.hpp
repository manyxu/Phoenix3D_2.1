/*
*
* 文件名称	：	PX2ClientConnect.hpp
*
*/

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

	class ClientConnect
	{
	public:
		typedef int (ClientConnect::*ServerMsgHandleFunc)(const void *pbuffer, int buflen);

	public:
		ClientConnect(int num_msghandlers);
		virtual ~ClientConnect();

		void RegisterHandler(int msgid, ServerMsgHandleFunc msgfunc, bool need_answer=true, int other_answer_msg=-1);

		StreamSocket &GetSocket ();
		int Connect (const SocketAddress &addr);
		int Disconnect();
		int GetConnectState ();
		void SetConnectState(int state);

		//出现网络错误时， 调用此函数试图重连，并且把之前没确认发到的消息重新再发
		//传入需要在消息重发前需要发送的复位消息， 如果为NULL， 就不会发复位消息
		int Reconnect(BufferEvent *pevent=NULL); 

		template<class T>
		int SendMsgToServer(int msgid, const T &msg)
		{
			BufferEvent *pevent = MsgToBufferEvent(msgid, msg, mSendQue);
			if(pevent == 0) return -1;
			mSendQue->PostBufferEvent(pevent);

			/*
			if(mConnectState==CONNSTATE_CONNECTED && mMsgHandlers[msgid].need_answer)
			{
				SetConnectState(CONNSTATE_WAITSERVER);
			}*/
			return 0;
		}

		template<class T>
		BufferEvent *CreateSendEvent(int msgid, const T &msg)
		{
			return MsgToBufferEvent(msgid, msg, mSendQue);
		}

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

		//发送消息后， 如果是需要服务器确认的， 不直接释放， 等服务器返回确认消息后再释放
		//如果中间出现网络错误， 重新连接，重发所有需要确认消息
		std::vector<BufferEvent *>mWaitConfirmMsg; 

		StreamSocket mSocket;

	private:
		void InternalConnect();
		void InternalDisconnect();
		void ConfirmMsgCome(int msgid); //对每条服务器消息， 判断是否是之前发出消息的返回消息， 如果是， 清理掉等待服务器消息
		int HandleServerMsg ();
		int HandleServerBufferEvent(BufferEvent *pevent);
		int OnReservedMsg (const void *pbuffer, int buflen);
		int ClientOnRead();
		int ClientOnWrite();
	};

#include "PX2NetClientConnect.inl"

	typedef Pointer0<ClientConnect> ClientConnectPtr;

}

#endif