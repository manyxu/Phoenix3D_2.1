// PX2SocketImpl.hpp

#ifndef PX2SOCKETIMPL_HPP
#define PX2SOCKETIMPL_HPP

#include "PX2NetPre.hpp"
#include "PX2NetDefine.hpp"
#include "PX2Timespan.hpp"
#include "PX2SocketAddress.hpp"

namespace PX2
{

	class SocketImpl
	{
	public:
		SocketImpl (const SocketImpl&);
		virtual ~SocketImpl ();

		SocketImpl& operator = (const SocketImpl&);

		// Socket  «∑Ò”––ß
		bool IsInitialized() const;

		enum SelectMode
		{
			SELECT_READ  = 1,
			SELECT_WRITE = 2,
			SELECT_ERROR = 4
		};

		virtual SocketImpl* AcceptConnection (SocketAddress &clientAddr);
		virtual int Connect (const SocketAddress &address);
		virtual void Connect (const SocketAddress &address, 
			const Timespan& timeout);
		virtual void ConnectNB (const SocketAddress& address);

		virtual void Bind (const SocketAddress& address,
			bool reuseAddress = false);
		virtual void Bind6 (const SocketAddress& address, 
			bool reuseAddress = false, bool ipV6Only = false);

		virtual void Listen (int backlog = 64);

		virtual void Close();

		virtual void ShutdownReceive();
		virtual void ShutdownSend();
		virtual void Shutdown();

		virtual int SendBytes (const void* buffer, int length, int flags = 0);
		virtual int ReceiveBytes (void* buffer, int length, int flags = 0);
		virtual int SendTo (const void* buffer, int length, 
			const SocketAddress& address, int flags = 0);
		virtual int ReceiveFrom (void* buffer, int length, 
			SocketAddress& address, int flags = 0);
		virtual void SendUrgent (unsigned char data);

		virtual int Available();
		virtual bool Poll (const Timespan& timeout, int mode);

		virtual void SetSendBufferSize (int size);
		virtual int GetSendBufferSize ();

		virtual void SetReceiveBufferSize (int size);
		virtual int GetReceiveBufferSize ();

		virtual void SetSendTimeout (const Timespan& timeout);
		virtual Timespan GetSendTimeout ();

		virtual void SetReceiveTimeout (const Timespan& timeout);
		virtual Timespan GetReceiveTimeout ();

		virtual SocketAddress GetAddress();
		virtual SocketAddress GetPeerAddress();

		// Sets and Gets
		void SetOption (int level, int option, int val);
		void SetOption (int level, int option, unsigned val);
		void SetOption (int level, int option, unsigned char val);
		void SetOption (int level, int option, const Timespan &val);
		void SetOption (int level, int option, const IPAddress &val);
		virtual void SetRawOption (int level, int option, const void *val,
			px2_socklen_t length);

		void GetOption (int level, int option, int &val);
		void GetOption (int level, int option, unsigned &val);
		void GetOption (int level, int option, unsigned char& val);
		void GetOption (int level, int option, Timespan& val);
		void GetOption (int level, int option, IPAddress& val);
		virtual void GetRawOption (int level, int option, void *val, 
			px2_socklen_t &length);

		void SetLinger (bool on, int seconds);
		void GetLinger (bool &on, int &seconds);

		void SetNoDelay (bool flag);
		bool GetNoDelay ();

		void SetKeepAlive (bool flag);
		bool GetKeepAlive ();

		void SetReuseAddress (bool flag);
		bool GetReuseAddress ();

		void SetReusePort (bool flag);
		bool GetReusePort ();

		void SetOOBInline (bool flag);
		bool GetOOBInline ();

		void SetBroadcast (bool flag);
		bool GetBroadcast ();

		virtual void SetBlocking (bool flag);
		virtual bool IsBlocking () const;

		virtual bool Secure () const;

		int GetSocketError();

		px2_socket_t GetSocket() const;

		void Ioctl (px2_ioctl_request_t request, int &arg);
		void Ioctl (px2_ioctl_request_t request, void *arg);

	protected:
		SocketImpl();
		SocketImpl(px2_socket_t sockfd);

		virtual void Init (int af);
		void InitSocket (int af, int type, int proto = 0);
		void Reset (px2_socket_t fd = PX2_INVALID_SOCKET);

	private:
		px2_socket_t mSocket;
		bool mIsBlocking;

		friend class Socket;
		friend class SecureSocketImpl;
	};

	extern Pointer0<SocketImpl> SocketImplPtr;

#include "PX2SocketImpl.inl"

}

#endif