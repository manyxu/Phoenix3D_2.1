// PX2ServerSocket.hpp

#ifndef PX2SERVERSOCKET_HPP
#define PX2SERVERSOCKET_HPP

#include "PX2NetPre.hpp"
#include "PX2Socket.hpp"
#include "PX2StreamSocket.hpp"

namespace PX2
{

	class PX2_NET_ITEM ServerSocket : public Socket
	{
	public:
		ServerSocket();
		ServerSocket(const Socket& socket);
		ServerSocket(const SocketAddress& address, int backlog = 64);
		ServerSocket(int16_t port, int backlog = 64);
		virtual ~ServerSocket();

		ServerSocket& operator = (const Socket& socket);

		virtual void Bind(const SocketAddress& address,
			bool reuseAddress = false);
		virtual void Bind(int16_t port, bool reuseAddress = false);
		virtual void Bind6(const SocketAddress& address,
			bool reuseAddress = false, bool ipV6Only = false);
		virtual void Bind6(int16_t port, bool reuseAddress = false,
			bool ipV6Only = false);
		virtual void Listen(int backlog = 64);
		virtual StreamSocket AcceptConnection(SocketAddress& clientAddr);
		virtual StreamSocket AcceptConnection();

	protected:
		ServerSocket(SocketImpl* pImpl, bool);
	};

}

#endif