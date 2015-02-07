/*
*
* ÎÄ¼þÃû³Æ	£º	PX2StreamSocket.hpp
*
*/

#ifndef PX2STREAMSOCKET_HPP
#define PX2STREAMSOCKET_HPP

#include "PX2NetPre.hpp"
#include "PX2Socket.hpp"
#include "PX2StreamSocketImpl.hpp"

namespace PX2
{

	class StreamSocket: public Socket
	{
	public:
		StreamSocket();
		explicit StreamSocket(const SocketAddress& address);
		explicit StreamSocket(IPAddress::Family family);
		StreamSocket(const Socket& socket);
		virtual ~StreamSocket();

		StreamSocket& operator = (const Socket& socket);

		int Connect(const SocketAddress& address);
		void Connect(const SocketAddress& address, const Timespan& timeout);
		void ConnectNB(const SocketAddress& address);

		void ShutdownReceive();
		void ShutdownSend();
		void Shutdown();

		int SendBytes(const void* buffer, int length, int flags = 0);
		int ReceiveBytes(void* buffer, int length, int flags = 0);

		void SendUrgent(unsigned char data);

		StreamSocket (SocketImpl* impl);

	private:
		enum
		{
			BUFFER_SIZE = 1024
		};

		friend class ServerSocket;
		friend class SocketIOS;
	};

}

#endif