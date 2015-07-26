// PX2NetPre.hpp

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
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <errno.h>
#include <fcntl.h>

#ifdef __IOS__

#include <netdb.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/fcntl.h>

#define INADDR_NONE 0xffffffff
#define PX2_HAVE_ADDRINFO

#else

#include <sys/epoll.h>

#endif

#endif

#if defined(PX2_NET_DLL_EXPORT)
// For the DLL library.
#define PX2_NET_ITEM __declspec(dllexport)
#elif defined(PX2_NET_DLL_IMPORT)
// For a client of the DLL library.
#define PX2_NET_ITEM __declspec(dllimport)
#else
// For the static library and for Apple/Linux.
#define PX2_NET_ITEM
#endif

#endif