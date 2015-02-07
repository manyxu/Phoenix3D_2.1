/*
*
* ÎÄ¼þÃû³Æ	£º	PX2NetPre.hpp
*
*/

#ifndef PX2NETPRE_HPP
#define PX2NETPRE_HPP

#include "PX2CorePre.hpp"

#if defined(_WIN32) || defined(WIN32)

#include <winsock2.h>
#include <Mswsock.h>
#include <MSTCPIP.h>
#include <ws2tcpip.h>

#define PX2_HAVE_ADDRINFO

#else

#include <sys/types.h>
#include <sys/socket.h>
#ifdef __MARMALADE__
#include <netdb.h>
#include <unistd.h>
#include <sys/ioctl.h>
#define INADDR_NONE 0xffffffff
#else
#include <sys/epoll.h>
#endif
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <errno.h>
#include <fcntl.h>

#endif

#endif