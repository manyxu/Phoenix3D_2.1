// PX2SocketImpl.cpp

#include "PX2NetPre.hpp"
#include "PX2SocketImpl.hpp"
#include "PX2StreamSocketImpl.hpp"
#include "PX2NetError.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
SocketImpl::SocketImpl ()
	:
mSocket(PX2_INVALID_SOCKET),
mIsBlocking(true)
{
}
//----------------------------------------------------------------------------
SocketImpl::SocketImpl (px2_socket_t sockfd)
	:
mSocket(sockfd),
mIsBlocking(true)
{
}
//----------------------------------------------------------------------------
SocketImpl::~SocketImpl ()
{
	Close();
}
//----------------------------------------------------------------------------
SocketImpl* SocketImpl::AcceptConnection (SocketAddress &clientAddr)
{
	if (mSocket == PX2_INVALID_SOCKET)
	{
		assertion(false, "invalid socket.\n");
		return 0;
	}

	char buffer[SocketAddress::MAX_ADDRESS_LENGTH];
	struct sockaddr *sa = reinterpret_cast<struct sockaddr*>(buffer);
	px2_socklen_t saLen = sizeof(buffer);
	px2_socket_t sd;

	do
	{
		sd = ::accept(mSocket, sa, &saLen);
	}
	while (sd == PX2_INVALID_SOCKET && NetError::LastError() == PX2_EINTR);

	if (sd != PX2_INVALID_SOCKET)
	{
		clientAddr = SocketAddress(sa, saLen);
		return new0 StreamSocketImpl(sd);
	}
	NetError::Error(); // will throw
	return 0;
}
//----------------------------------------------------------------------------
int SocketImpl::Connect (const SocketAddress& address)
{
	if (mSocket == PX2_INVALID_SOCKET)
	{
		Init(address.GetAF());
	}

	int rc = ::connect(mSocket, address.GetAddr(), address.GetAddrLength());
	if (0 != rc)
	{
		int err = NetError::LastError();
		NetError::Error(err, address.ToString());
	}

	return rc;
}
//----------------------------------------------------------------------------
void SocketImpl::Connect(const SocketAddress& address, const Timespan& timeout)
{
	if (mSocket == PX2_INVALID_SOCKET)
	{
		Init(address.GetAF());
	}

	SetBlocking(false);

	int rc = ::connect(mSocket, address.GetAddr(), address.GetAddrLength());

	if (rc != 0)
	{
		int err = NetError::LastError();

		if (err != PX2_EINPROGRESS && err != PX2_EWOULDBLOCK)
		{
			NetError::Error(err, address.ToString());
		}

		if (!Poll(timeout, SELECT_READ | SELECT_WRITE | SELECT_ERROR))
		{
			assertion(false, "connect timed out:%s", address.ToString());
		}

		err = GetSocketError();
		if (err != 0)
		{
			NetError::Error(err);
		}
	}

	SetBlocking(true);
}
//----------------------------------------------------------------------------
void SocketImpl::ConnectNB(const SocketAddress& address)
{
	if (mSocket == PX2_INVALID_SOCKET)
	{
		Init(address.GetAF());
	}

	SetBlocking(false);

	int rc = ::connect(mSocket, address.GetAddr(), address.GetAddrLength());

	if (rc != 0)
	{
		int err = NetError::LastError();

		if (err != PX2_EINPROGRESS && err != PX2_EWOULDBLOCK)
		{
			NetError::Error(err, address.ToString());
		}
	}
}
//----------------------------------------------------------------------------
void SocketImpl::Bind(const SocketAddress& address, bool reuseAddress)
{
	if (mSocket == PX2_INVALID_SOCKET)
	{
		Init(address.GetAF());
	}

	if (reuseAddress)
	{
		SetReuseAddress(true);
		SetReusePort(true);
	}

	int rc = ::bind(mSocket, address.GetAddr(), address.GetAddrLength());

	if (rc != 0)
	{
		NetError::Error(address.ToString());
	}
}
//----------------------------------------------------------------------------
void SocketImpl::Bind6(const SocketAddress& address, bool reuseAddress, 
	bool ipV6Only)
{
#if defined(PX2_HAVE_IPV6)
	if (address.GetFamily() != IPAddress::IPv6)
	{
		assertion(false, "SocketAddress must be an IPv6 address");
	}

	if (mSocket == PX2_INVALID_SOCKET)
	{
		Init(address.GetAF());
	}
#ifdef IPV6_V6ONLY
	SetOption(IPPROTO_IPV6, IPV6_V6ONLY, ipV6Only ? 1 : 0);
#else
	if (ipV6Only)
	{
		assertion(false, "IPV6_V6ONLY not defined.");
	}
#endif
	if (reuseAddress)
	{
		SetReuseAddress(true);
		SetReusePort(true);
	}
	int rc = ::bind(mSocket, address.GetAddr(), address.GetAddrLength());
	if (rc != 0)
	{
		NetError::Error(address.ToString());
	}
#else
	assertion(false, "No IPv6 support available.\n");
#endif
}
//----------------------------------------------------------------------------
void SocketImpl::Listen (int backlog)
{
	if (mSocket == PX2_INVALID_SOCKET)
	{
		assertion(false, "InvalidSocket.\n");
	}

	int rc = ::listen(mSocket, backlog);
	if (rc != 0)
	{
		NetError::Error();
	}
}
//----------------------------------------------------------------------------
void SocketImpl::Close()
{
	if (mSocket != PX2_INVALID_SOCKET)
	{
		px2_closesocket(mSocket);
		mSocket = PX2_INVALID_SOCKET;
	}
}
//----------------------------------------------------------------------------
void SocketImpl::ShutdownReceive()
{
	if (mSocket == PX2_INVALID_SOCKET)
	{
		assertion(false, "Invalid socket.\n");
	}

	int rc = ::shutdown(mSocket, 0);
	if (rc != 0)
	{
		NetError::Error();
	}
}
//----------------------------------------------------------------------------
void SocketImpl::ShutdownSend()
{
	if (mSocket != PX2_INVALID_SOCKET)
	{
		int rc = ::shutdown(mSocket, 1);
		if (rc != 0)
			NetError::Error();
	}
}
//----------------------------------------------------------------------------
void SocketImpl::Shutdown()
{
	if (mSocket != PX2_INVALID_SOCKET)
	{
		int rc = ::shutdown(mSocket, 2);

		if (rc != 0) NetError::Error();
	}
}
//----------------------------------------------------------------------------
int SocketImpl::SendBytes(const void* buffer, int length, int flags)
{
	int rc;
	if (mSocket == PX2_INVALID_SOCKET)
	{
		assertion(false, "Invalid socket.\n");
	}

	rc = ::send(mSocket, reinterpret_cast<const char*>(buffer), length, flags);

	if(rc < 0)
	{
		int err = NetError::LastError();
		if(err==PX2_EWOULDBLOCK || err==PX2_EINTR) return 0; //继续
		else return -1; //连接断掉
	}
	else return rc;
}
//----------------------------------------------------------------------------
int SocketImpl::ReceiveBytes (void* buffer, int length, int flags)
{
	int rc;
	if (mSocket == PX2_INVALID_SOCKET)
	{
		assertion(false, "Invalid socket.\n");
	}

	rc = ::recv(mSocket, reinterpret_cast<char*>(buffer), length, flags);
	
	if(rc == 0) return -1; //连接被关掉， 需要重连
	else if(rc < 0)
	{
		int err = NetError::LastError();
		if(err==PX2_EWOULDBLOCK || err==PX2_EINTR) return 0; //继续
		else return -1; //连接断掉
	}
	else return rc;
}
//----------------------------------------------------------------------------
int SocketImpl::SendTo (const void* buffer, int length, 
	const SocketAddress& address, int flags)
{
	int rc;
	//do
	{
		if (mSocket == PX2_INVALID_SOCKET)
		{
			assertion(false, "Invalid socket.\n");
		}

		rc = ::sendto(mSocket, reinterpret_cast<const char*>(buffer), length, 
			flags, address.GetAddr(), address.GetAddrLength());

	}	
	//while (mIsBlocking && rc < 0 && LastError() == PX2_EINTR);

	if (rc < 0)
	{
		NetError::Error();
	}

	return rc;
}
//----------------------------------------------------------------------------
int SocketImpl::ReceiveFrom (void* buffer, int length, SocketAddress& address,
	int flags)
{
	char abuffer[SocketAddress::MAX_ADDRESS_LENGTH];
	struct sockaddr* sa = reinterpret_cast<struct sockaddr*>(abuffer);
	px2_socklen_t saLen = sizeof(abuffer);
	int rc;
	//do
	{
		if (mSocket == PX2_INVALID_SOCKET)
		{
			assertion(false, "Invalid socket.\n");
		}

		rc = ::recvfrom(mSocket, reinterpret_cast<char*>(buffer), length,
			flags, sa, &saLen);
	}
	//while (mIsBlocking && rc < 0 && LastError() == PX2_EINTR);

	if (rc >= 0)
	{
		address = SocketAddress(sa, saLen);
	}
	else
	{
		//int err = LastError();
		//if (err == PX2_EAGAIN && !mIsBlocking)
		//	;
		//else if (err == PX2_EAGAIN || err == PX2_ETIMEDOUT)
		//{
		//	assertion(false, "time out.\n");
		//}
		//else
		//	NetError::Error(err);
	}
	return rc;
}
//----------------------------------------------------------------------------
void SocketImpl::SendUrgent(unsigned char data)
{
	if (mSocket == PX2_INVALID_SOCKET)
	{
		assertion(false, "Invalid socket.\n");
	}

	int rc = ::send(mSocket, reinterpret_cast<const char*>(&data), 
		sizeof(data), MSG_OOB);

	if (rc < 0)
		NetError::Error();
}
//----------------------------------------------------------------------------
int SocketImpl::Available()
{
#ifndef __ANDROID__
	int result;
	Ioctl(FIONREAD, result);
	return result;
#else
	return -1;
#endif
}
//----------------------------------------------------------------------------
bool SocketImpl::Secure() const
{
	return false;
}
//----------------------------------------------------------------------------
bool SocketImpl::Poll(const Timespan& timeout, int mode)
{
	px2_socket_t sockfd = mSocket;

	if (sockfd == PX2_INVALID_SOCKET)
	{
		assertion(false, "Invalid socket.\n");
	}

#if defined(PX2_HAVE_FD_EPOLL)

	int epollfd = epoll_create(1);
	if (epollfd < 0)
	{
		char buf[1024];
		strerror_r(errno, buf, sizeof(buf));
		NetError::Error(std::string("Can't create epoll queue: ") + buf);
	}

	struct epoll_event evin;
	memset(&evin, 0, sizeof(evin));

	if (mode & SELECT_READ)
		evin.events |= EPOLLIN;
	if (mode & SELECT_WRITE)
		evin.events |= EPOLLOUT;
	if (mode & SELECT_ERROR)
		evin.events |= EPOLLERR;

	if (epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &evin) < 0)
	{
		char buf[1024];
		strerror_r(errno, buf, sizeof(buf));
		::close(epollfd);
		NetError::Error(std::string("Can't insert socket to epoll queue: ") + buf);
	}

	Timespan remainingTime(timeout);
	int rc;
	do
	{
		struct epoll_event evout;
		memset(&evout, 0, sizeof(evout));

		Timestamp start;
		rc = epoll_wait(epollfd, &evout, 1, remainingTime.totalMilliseconds());
		if (rc < 0 && LastError() == PX2_EINTR)
		{
			Timestamp end;
			Timespan waited = end - start;
			if (waited < remainingTime)
				remainingTime -= waited;
			else
				remainingTime = 0;
		}
	}
	while (rc < 0 && LastError() == PX2_EINTR);

	::close(epollfd);
	if (rc < 0)
		NetError::Error();
	return rc > 0; 

#elif defined(PX2_HAVE_FD_POLL)

	pollfd pollBuf;

	memset(&pollBuf, 0, sizeof(pollfd));
	pollBuf.fd = mSocket;
	if (mode & SELECT_READ) pollBuf.events |= POLLIN;
	if (mode & SELECT_WRITE) pollBuf.events |= POLLOUT;

	Timespan remainingTime(timeout);
	int rc;
	do
	{
		Timestamp start;
		rc = ::poll(&pollBuf, 1, remainingTime.totalMilliseconds());

		if (rc < 0 && LastError() == PX2_EINTR)
		{
			Timestamp end;
			Timespan waited = end - start;
			if (waited < remainingTime)
				remainingTime -= waited;
			else
				remainingTime = 0;
		}
	}
	while (rc < 0 && LastError() == PX2_EINTR);

#elif defined WIN32 || defined _WIN32

	fd_set fdRead;
	fd_set fdWrite;
	fd_set fdExcept;
	FD_ZERO(&fdRead);
	FD_ZERO(&fdWrite);
	FD_ZERO(&fdExcept);
	if (mode & SELECT_READ)
	{
		FD_SET(sockfd, &fdRead);
	}
	if (mode & SELECT_WRITE)
	{
		FD_SET(sockfd, &fdWrite);
	}
	if (mode & SELECT_ERROR)
	{
		FD_SET(sockfd, &fdExcept);
	}
	Timespan remainingTime(timeout);
	int errorCode = 0;
	int rc;
	do
	{
		struct timeval tv;
		tv.tv_sec  = (long) remainingTime.TotalSeconds();
		tv.tv_usec = (long) remainingTime.Useconds();
		Timestamp start;
		rc = ::select(int(sockfd) + 1, &fdRead, &fdWrite, &fdExcept, &tv);
		if (rc < 0 && (errorCode = NetError::LastError()) == PX2_EINTR)
		{
			Timestamp end;
			Timespan waited = end - start;
			if (waited < remainingTime)
				remainingTime -= waited;
			else
				remainingTime = 0;
		}
	}
	while (rc < 0 && errorCode == PX2_EINTR);

	if (rc < 0)
		NetError::Error(errorCode);

	return rc > 0; 

#else // PX2_HAVE_FD_EPOLL

return false;

#endif
}
//----------------------------------------------------------------------------
void SocketImpl::SetSendBufferSize(int size)
{
	SetOption(SOL_SOCKET, SO_SNDBUF, size);
}
//----------------------------------------------------------------------------
int SocketImpl::GetSendBufferSize()
{
	int result;
	GetOption(SOL_SOCKET, SO_SNDBUF, result);
	return result;
}
//----------------------------------------------------------------------------
void SocketImpl::SetReceiveBufferSize(int size)
{
	SetOption(SOL_SOCKET, SO_RCVBUF, size);
}
//----------------------------------------------------------------------------
int SocketImpl::GetReceiveBufferSize()
{
	int result;
	GetOption(SOL_SOCKET, SO_RCVBUF, result);
	return result;
}
//----------------------------------------------------------------------------
void SocketImpl::SetSendTimeout(const Timespan& timeout)
{
#if defined(_WIN32) || defined(WIN32)
	int val = (int) timeout.TotalMilliseconds();
	SetOption(SOL_SOCKET, SO_SNDTIMEO, val);
#else
	SetOption(SOL_SOCKET, SO_SNDTIMEO, timeout);
#endif
}
//----------------------------------------------------------------------------
Timespan SocketImpl::GetSendTimeout()
{
	Timespan result;
#if defined(_WIN32) || defined(WIN32)
	int val;
	GetOption(SOL_SOCKET, SO_SNDTIMEO, val);
	result = Timespan::TimeDiff(val)*1000;
#else
	GetOption(SOL_SOCKET, SO_SNDTIMEO, result);
#endif
	return result;
}
//----------------------------------------------------------------------------
void SocketImpl::SetReceiveTimeout(const Timespan& timeout)
{
#if defined(_WIN32) || defined(WIN32)
	int val = (int) timeout.TotalMilliseconds();
	SetOption(SOL_SOCKET, SO_RCVTIMEO, val);
#else
	SetOption(SOL_SOCKET, SO_RCVTIMEO, timeout);
#endif
}
//----------------------------------------------------------------------------
Timespan SocketImpl::GetReceiveTimeout()
{
	Timespan result;

#if defined(_WIN32) || defined(WIN32)
	int val;
	GetOption(SOL_SOCKET, SO_RCVTIMEO, val);
	result = Timespan::TimeDiff(val)*1000;
#else
	GetOption(SOL_SOCKET, SO_RCVTIMEO, result);
#endif

	return result;
}
//----------------------------------------------------------------------------
SocketAddress SocketImpl::GetAddress()
{
	if (mSocket == PX2_INVALID_SOCKET)
	{
		assertion(false, "Invalid socket.\n");
	}

	char buffer[SocketAddress::MAX_ADDRESS_LENGTH];
	struct sockaddr* sa = reinterpret_cast<struct sockaddr*>(buffer);
	px2_socklen_t saLen = sizeof(buffer);
	int rc = ::getsockname(mSocket, sa, &saLen);
	if (rc == 0)
		return SocketAddress(sa, saLen);
	else 
		NetError::Error();
	return SocketAddress();
}
//----------------------------------------------------------------------------
SocketAddress SocketImpl::GetPeerAddress()
{
	if (mSocket == PX2_INVALID_SOCKET)
	{
		assertion(false, "Invalid socket.\n");
	}

	char buffer[SocketAddress::MAX_ADDRESS_LENGTH];
	struct sockaddr* sa = reinterpret_cast<struct sockaddr*>(buffer);
	px2_socklen_t saLen = sizeof(buffer);
	int rc = ::getpeername(mSocket, sa, &saLen);
	if (rc == 0)
		return SocketAddress(sa, saLen);
	else 
		NetError::Error();
	return SocketAddress();
}
//----------------------------------------------------------------------------
void SocketImpl::SetOption(int level, int option, int val)
{
	SetRawOption(level, option, &val, sizeof(val));
}
//----------------------------------------------------------------------------
void SocketImpl::SetOption(int level, int option, unsigned val)
{
	SetRawOption(level, option, &val, sizeof(val));
}
//----------------------------------------------------------------------------
void SocketImpl::SetOption(int level, int option, unsigned char val)
{
	SetRawOption(level, option, &val, sizeof(val));
}
//----------------------------------------------------------------------------
void SocketImpl::SetOption(int level, int option, const IPAddress& val)
{
	SetRawOption(level, option, val.GetAddr(), val.GetAddrLength());
}
//----------------------------------------------------------------------------
void SocketImpl::SetOption(int level, int option, const Timespan& val)
{
	struct timeval tv;
	tv.tv_sec  = (long) val.TotalSeconds();
	tv.tv_usec = (long) val.Useconds();

	SetRawOption(level, option, &tv, sizeof(tv));
}
//----------------------------------------------------------------------------
void SocketImpl::SetRawOption(int level, int option, const void* val, 
	px2_socklen_t length)
{
	if (mSocket == PX2_INVALID_SOCKET)
	{
		assertion(false, "Invalid socket.\n");
	}

	int rc = ::setsockopt(mSocket, level, option, 
		reinterpret_cast<const char*>(val), length);

	if (rc == -1) NetError::Error();
}
//----------------------------------------------------------------------------
void SocketImpl::GetOption(int level, int option, int& val)
{
	px2_socklen_t len = sizeof(val);
	GetRawOption(level, option, &val, len);
}
//----------------------------------------------------------------------------
void SocketImpl::GetOption(int level, int option, unsigned& val)
{
	px2_socklen_t len = sizeof(val);
	GetRawOption(level, option, &val, len);
}
//----------------------------------------------------------------------------
void SocketImpl::GetOption(int level, int option, unsigned char& val)
{
	px2_socklen_t len = sizeof(val);
	GetRawOption(level, option, &val, len);
}
//----------------------------------------------------------------------------
void SocketImpl::GetOption(int level, int option, Timespan& val)
{
	struct timeval tv;
	px2_socklen_t len = sizeof(tv);
	GetRawOption(level, option, &tv, len);
	val.Assign(tv.tv_sec, tv.tv_usec);
}
//----------------------------------------------------------------------------
void SocketImpl::GetOption(int level, int option, IPAddress& val)
{
	char buffer[IPAddress::MAX_ADDRESS_LENGTH];
	px2_socklen_t len = sizeof(buffer);
	GetRawOption(level, option, buffer, len);
	val = IPAddress(buffer, len);
}
//----------------------------------------------------------------------------
void SocketImpl::GetRawOption(int level, int option, void* val, 
	px2_socklen_t& length)
{
	if (mSocket == PX2_INVALID_SOCKET)
	{
		assertion(false, "Invalid socket.\n");
	}

	int rc = ::getsockopt(mSocket, level, option, 
		reinterpret_cast<char*>(val), &length);

	if (rc == -1) 
		NetError::Error();
}
//----------------------------------------------------------------------------
void SocketImpl::SetLinger(bool on, int seconds)
{
	struct linger l;
	l.l_onoff  = (unsigned short)(on ? 1 : 0);
	l.l_linger = (unsigned short)seconds;
	SetRawOption(SOL_SOCKET, SO_LINGER, &l, sizeof(l));
}
//----------------------------------------------------------------------------
void SocketImpl::GetLinger(bool& on, int& seconds)
{
	struct linger l;
	px2_socklen_t len = sizeof(l);
	GetRawOption(SOL_SOCKET, SO_LINGER, &l, len);
	on = l.l_onoff != 0;
	seconds = l.l_linger;
}
//----------------------------------------------------------------------------
void SocketImpl::SetNoDelay(bool flag)
{
#ifdef WIN32
	int val = flag ? 1 : 0;
	SetOption(IPPROTO_TCP, TCP_NODELAY, val);
#endif
}
//----------------------------------------------------------------------------
bool SocketImpl::GetNoDelay()
{
#ifdef WIN32
	int val(0);
	GetOption(IPPROTO_TCP, TCP_NODELAY, val);
	return val != 0;
#else
	return false;
#endif
}
//----------------------------------------------------------------------------
void SocketImpl::SetKeepAlive(bool flag)
{
	int val = flag ? 1 : 0;
	SetOption(SOL_SOCKET, SO_KEEPALIVE, val);
}
//----------------------------------------------------------------------------
bool SocketImpl::GetKeepAlive()
{
	int val(0);
	GetOption(SOL_SOCKET, SO_KEEPALIVE, val);
	return val != 0;
}
//----------------------------------------------------------------------------
void SocketImpl::SetReuseAddress(bool flag)
{
	int val = flag ? 1 : 0;
	SetOption(SOL_SOCKET, SO_REUSEADDR, val);
}
//----------------------------------------------------------------------------
bool SocketImpl::GetReuseAddress()
{
	int val(0);
	GetOption(SOL_SOCKET, SO_REUSEADDR, val);
	return val != 0;
}
//----------------------------------------------------------------------------
void SocketImpl::SetReusePort(bool flag)
{
	PX2_UNUSED(flag);
}
//----------------------------------------------------------------------------
bool SocketImpl::GetReusePort()
{
	return false;
}
//----------------------------------------------------------------------------
void SocketImpl::SetOOBInline(bool flag)
{
	int val = flag ? 1 : 0;
	SetOption(SOL_SOCKET, SO_OOBINLINE, val);
}
//----------------------------------------------------------------------------
bool SocketImpl::GetOOBInline()
{
	int val(0);
	GetOption(SOL_SOCKET, SO_OOBINLINE, val);
	return val != 0;
}
//----------------------------------------------------------------------------
void SocketImpl::SetBroadcast(bool flag)
{
	int val = flag ? 1 : 0;
	SetOption(SOL_SOCKET, SO_BROADCAST, val);
}
//----------------------------------------------------------------------------
bool SocketImpl::GetBroadcast()
{
	int val(0);
	GetOption(SOL_SOCKET, SO_BROADCAST, val);
	return val != 0;
}
//----------------------------------------------------------------------------
void SocketImpl::SetBlocking(bool flag)
{
	mIsBlocking = flag;

	if (!IsInitialized())
		return;

#if defined(_WIN32) || defined(WIN32)
	int arg = flag ? 0 : 1;
	Ioctl(FIONBIO, arg);
#elif defined(__LINUX__)
	int arg = fcntl(F_GETFL);
	long flags = arg & ~O_NONBLOCK;
	if (!flag)
		flags |= O_NONBLOCK;
	fcntl(F_SETFL, flags);
#elif defined (__APPLE__)
    
#elif defined(__ANDROID__)
	int arg = fcntl(mSocket, F_GETFL);
	long flags = arg & ~O_NONBLOCK;
	if (!flag)
		flags |= O_NONBLOCK;
	fcntl(mSocket, F_SETFL, O_NONBLOCK);
#endif
}
//----------------------------------------------------------------------------
int SocketImpl::GetSocketError()
{
	int result(0);
	GetOption(SOL_SOCKET, SO_ERROR, result);
	return result;
}
//----------------------------------------------------------------------------
void SocketImpl::Init(int af)
{
	InitSocket(af, SOCK_STREAM);
}
//----------------------------------------------------------------------------
void SocketImpl::InitSocket(int af, int type, int proto)
{
	assertion(mSocket == PX2_INVALID_SOCKET, "invalid socket.\n");

	mSocket = ::socket(af, type, proto);

	if (mSocket == PX2_INVALID_SOCKET)
		NetError::Error();

	SetBlocking(mIsBlocking);
}
//----------------------------------------------------------------------------
void SocketImpl::Ioctl(px2_ioctl_request_t request, int& arg)
{
#if defined(_WIN32) || defined(WIN32)
	int rc = ioctlsocket(mSocket, request, reinterpret_cast<u_long*>(&arg));
#else
	int rc = ::ioctl(mSocket, request, &arg);
#endif
	if (rc != 0)
	{
		NetError::Error();
	}
}
//----------------------------------------------------------------------------
void SocketImpl::Ioctl(px2_ioctl_request_t request, void* arg)
{
#if defined(_WIN32) || defined(WIN32)
	int rc = ioctlsocket(mSocket, request, reinterpret_cast<u_long*>(arg));
#else
	int rc = ::ioctl(mSocket, request, arg);
#endif
	if (rc != 0)
	{
		NetError::Error();
	}
}
//----------------------------------------------------------------------------
void SocketImpl::Reset (px2_socket_t aSocket)
{
	mSocket = aSocket;
}
//----------------------------------------------------------------------------