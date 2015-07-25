// PX2DynLib.cpp

#include "PX2DynLib.hpp"
#include "PX2Log.hpp"
using namespace PX2;

#if defined(_WIN32) || defined(WIN32)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#if defined __APPLE__
#include "macPlugins.h"
#endif

//----------------------------------------------------------------------------
DynLib::DynLib(const std::string &name)
{
	mName = name;
	mhInst = NULL;
}
//----------------------------------------------------------------------------
DynLib::~DynLib()
{
}
//----------------------------------------------------------------------------
const std::string &DynLib::GetName()
{
	return mName;
}
//----------------------------------------------------------------------------
void DynLib::Load()
{
	PX2_LOG_INFO("Loading library: %s", mName.c_str());

	mhInst = (PLUGIN_HANDLE)PLUGIN_LOAD(mName.c_str());

	if (!mhInst)
	{
		PX2_LOG_ERROR("Could not load dynamic library %s . System Error: %s",
			mName.c_str(), DynlibError().c_str());
	}
}
//----------------------------------------------------------------------------
void DynLib::Unload()
{
	PX2_LOG_INFO("Unloading library %s", mName.c_str());

	if (PLUGIN_UNLOAD(mhInst))
	{
		PX2_LOG_ERROR("Could not unload dynamic library %s . System Error: %s", 
			mName.c_str(), DynlibError().c_str());
	}
}
//----------------------------------------------------------------------------
void* DynLib::GetSymbol(const std::string &strName)
{
	return (void*)PLUGIN_GETSYM(mhInst, strName.c_str());
}
//----------------------------------------------------------------------------
std::string DynLib::DynlibError()
{
#if defined(_WIN32) || defined(WIN32)
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		GetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf,
		0,
		NULL
		);
	std::string ret = (char*)lpMsgBuf;
	LocalFree(lpMsgBuf);
	return ret;
#elif defined (__LINUX__)
	return std::string(dlerror());
#elif defined (__LINUX__)
	return std::string(mac_errorBundle());
#else
	return st::string("");
#endif
}
//----------------------------------------------------------------------------