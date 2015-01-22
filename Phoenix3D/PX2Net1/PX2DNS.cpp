/*
*
* ÎÄ¼þÃû³Æ	£º	PX2DNS.cpp
*
*/

#include "PX2DNS.hpp"
#include "PX2SocketAddress.hpp"
#include "PX2Log.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
HostEntry DNS::GetHostByName (const std::string &hostname)
{
#if defined(PX2_HAVE_ADDRINFO)
	struct addrinfo* ai;
	struct addrinfo hints;
	std::memset(&hints, 0, sizeof(hints));
	hints.ai_flags = AI_CANONNAME | AI_ADDRCONFIG;
	int rc = getaddrinfo(hostname.c_str(), NULL, &hints, &ai); 
	if (rc == 0)
	{
		HostEntry result(ai);
		freeaddrinfo(ai);
		return result;
	}
	else
	{
		Aierror(rc, hostname);
	}
#else

#ifdef __ANDROID__
	return HostEntry();
#else
	struct hostent* he = gethostbyname(hostname.c_str());
	if (he)
	{
		return HostEntry(he);
	}
#endif

#endif

	Error(LastError(), hostname);

	assertion(false, "GetHostByName error.\n");

	return HostEntry();
}
//----------------------------------------------------------------------------
HostEntry DNS::GetHostByAddress (const IPAddress &address)
{
#if defined(PX2_HAVE_ADDRINFO)
	SocketAddress sa(address, 0);
	static char fqname[1024];
	int rc = getnameinfo(sa.GetAddr(), sa.GetAddrLength(), fqname, 
		sizeof(fqname), NULL,
		0, NI_NAMEREQD); 
	if (rc == 0)
	{
		struct addrinfo* pAI;
		struct addrinfo hints;
		std::memset(&hints, 0, sizeof(hints));
		hints.ai_flags = AI_CANONNAME | AI_ADDRCONFIG;
		rc = getaddrinfo(fqname, NULL, &hints, &pAI);
		if (rc == 0)
		{
			HostEntry result(pAI);
			freeaddrinfo(pAI);
			return result;
		}
		else
		{
			Aierror(rc, address.ToString());
		}
	}
	else
	{
		Aierror(rc, address.ToString());
	}
#else

#ifndef __ANDROID__
	struct hostent* he = gethostbyaddr(
		reinterpret_cast<const char*>(address.GetAddr()), 
		address.GetAddrLength(), address.GetAF());
	if (he)
	{
		return HostEntry(he);
	}
#else
	return HostEntry();
#endif


#endif
	int err = LastError();
	Error(err, address.ToString());
	assertion(false, "");
	return HostEntry();
}
//----------------------------------------------------------------------------
HostEntry DNS::Resolve(const std::string &address)
{
	IPAddress ip;

	if (IPAddress::TryParse(address, ip))
		return GetHostByAddress(ip);

	return GetHostByName(address);
}
//----------------------------------------------------------------------------
IPAddress DNS::ResolveOne (const std::string &address)
{
	const HostEntry& entry = Resolve(address);

	if (!entry.GetAddresses().empty())
		return entry.GetAddresses()[0];

	assertion(false, "ResolveOne failed.\n");
	PX2_LOG_SERVER_ERROR("ResolveOne failed.\n");

	return IPAddress();
}
//----------------------------------------------------------------------------
HostEntry DNS::GetThisHost()
{
	return GetHostByName(GetHostName());
}
//----------------------------------------------------------------------------
std::string DNS::GetHostName ()
{
	char buffer[256];
	int rc = gethostname(buffer, sizeof(buffer));
	if (rc == 0)
	{
		return std::string(buffer);
	}

	assertion(false, "Cannot get host name.\n");
	PX2_LOG_SERVER_ERROR("Cannot get host name.");

	return "";
}
//----------------------------------------------------------------------------
int DNS::LastError()
{
#if defined(_WIN32) || defined(WIN32)
	return ::GetLastError();
#else

#ifndef __ANDROID__
	return h_errno;
#else
	return -1;
#endif

#endif
}
//----------------------------------------------------------------------------
void DNS::Error (int code, const std::string& arg)
{
	PX2_UNUSED(arg);
	PX2_UNUSED(code);

	//switch (code)
	//{
	//case PX2_ESYSNOTREADY:
	//	assertion(false, "Net subsystem not ready.\n");
	//	PX2_LOG_SERVER_ERROR("Net subsystem not ready.\n");
	//	break;
	//case PX2_ENOTINIT:
	//	assertion(false, "Net subsystem not initialized.\n");
	//	break;
	//case PX2_HOST_NOT_FOUND:
	//	assertion(false, "Host not found.\n");
	//	break;
	//case PX2_TRY_AGAIN:
	//	assertion(false, "Temporary DNS error while resolving.\n");
	//	break;
	//case PX2_NO_RECOVERY:
	//	assertion(false, "Non recoverable DNS error while resolving.\n");
	//	break;
	//case PX2_NO_DATA:
	//	assertion(false, "No address found.\n");
	//	break;
	//default:
	//	assertion(false, "%d", code);
	//	break;
	//}
}
//----------------------------------------------------------------------------
void DNS::Aierror (int code, const std::string& arg)
{
	PX2_UNUSED(arg);
	PX2_UNUSED(code);

//#if defined(PX2_HAVE_IPV6)
//	switch (code)
//	{
//	case EAI_AGAIN:
//		assertion(false, "Temporary DNS error while resolving.\n");
//		break;
//	case EAI_FAIL:
//		assertion(false, "Non recoverable DNS error while resolving.\n");
//#if !defined(_WIN32) && !defined(WIN32)
//#if defined(EAI_NODATA)
//	case EAI_NODATA:
//		assertion(false, "no address found.\n");
//		break;
//#endif
//#endif
//	case EAI_NONAME:
//		assertion(false, "Hose not found.\n");
//		break;
//#if defined(EAI_SYSTEM)
//	case EAI_SYSTEM:
//		error(lastError(), arg);
//		break;
//#endif
//#if defined(_WIN32) || defined(WIN32)
//	case WSANO_DATA:
//		assertion(false, "Host not found.\n");
//		break;
//#endif
//	default:
//		assertion(false, "EAI:%d", code);
//		break;
//	}
//#endif // PX2_HAVE_IPV6
}
//----------------------------------------------------------------------------