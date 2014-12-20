/*
*
* ÎÄ¼þÃû³Æ	£º	PX2System.cpp
*
*/

#include "PX2System.hpp"

#if defined(_WIN32) || defined(WIN32)
#include <Windows.h>
#include <Iphlpapi.h>
#pragma comment(lib, "Iphlpapi.lib")
#elif defined(__LINUX__) || defined(__ANDROID__)
#include <sys/stat.h>
#elif defined(__APPLE__) || defined(__IOS__)
#include <unistd.h>
#elif defined(__MARMALADE__)
#include <unistd.h>
#include "s3eDevice.h"
#endif

using namespace PX2;

//----------------------------------------------------------------------------
void System::SleepSeconds (float seconds)
{
#if defined(_WIN32) || defined(WIN32)
	Sleep((DWORD)(seconds*1000.0));
#elif defined(__MARMALADE__)
	s3eDeviceYield(int(seconds*1000));
#else
	timespec ts;
	ts.tv_sec = int(seconds);
	ts.tv_nsec = int((seconds-ts.tv_sec)*1000000000);
	nanosleep(&ts, NULL);
#endif
}
//----------------------------------------------------------------------------
int System::GetNumCPUs ()
{
#if defined(_WIN32) || defined(WIN32)
	SYSTEM_INFO  info;
	GetSystemInfo(&info);
	return (long)info.dwNumberOfProcessors;
#elif defined(__MARMALADE__)
	int num = s3eDeviceGetInt(S3E_DEVICE_NUM_CPU_CORES);
	if(num == -1)
	{
		num = 1;
	}
	return num;
#else
	return sysconf(_SC_NPROCESSORS_ONLN);
#endif
}
//----------------------------------------------------------------------------
int System::GetCurrentThreadID ()
{
#if defined(_WIN32) || defined(WIN32)
	return (int)GetCurrentThreadId();
#else
	return (int)pthread_self();
#endif
}
//----------------------------------------------------------------------------
#if defined(_WIN32) || defined(WIN32)
std::string System::GetUniqueID ()
{
	std::string idstr("no_mac");

	PIP_ADAPTER_INFO pAdapterInfo;
	DWORD dwRetVal = 0;
	pAdapterInfo = (IP_ADAPTER_INFO *) malloc( sizeof(IP_ADAPTER_INFO) );
	ULONG ulOutBufLen = sizeof(IP_ADAPTER_INFO);

	if (GetAdaptersInfo( pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW) {
		free(pAdapterInfo);
		pAdapterInfo = (IP_ADAPTER_INFO *) malloc (ulOutBufLen); 
	}

	if ((dwRetVal = GetAdaptersInfo( pAdapterInfo, &ulOutBufLen)) == NO_ERROR) {
		PIP_ADAPTER_INFO pAdapter = pAdapterInfo;
		while (pAdapter)
		{
			__int64 val = (__int64)pAdapter->Address;
			PX2_UNUSED(val);
			if( pAdapter->AddressLength > 0 && (__int64)pAdapter->Address != 0 )
			{
				char macstr[256];
				sprintf(macstr,"%02x-%02x-%02x-%02x-%02x-%02x",pAdapter->Address[0],pAdapter->Address[1],pAdapter->Address[2],
					pAdapter->Address[3],pAdapter->Address[4],pAdapter->Address[5]);
				idstr = macstr;
				break;
			}
			pAdapter = pAdapter->Next;
		}
	}
	free(pAdapterInfo);
	return idstr;
}
#elif defined(__MARMALADE__)
std::string System::GetUniqueID ()
{
	return std::string(s3eDeviceGetString(S3E_DEVICE_UNIQUE_ID));
}
#else
std::string System::GetUniqueID ()
{
	return std::string("xxx");
}
#endif
