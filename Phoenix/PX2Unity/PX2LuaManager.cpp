/*
*
* ÎÄ¼þÃû³Æ	£º	PX2LuaManager.cpp
*
*/

#include "PX2LuaManager.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2Assert.hpp"

#if defined(_WIN32) || defined(WIN32)
#include <Windows.h>
#endif

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}
#include "tolua++.h"
using namespace PX2;

//----------------------------------------------------------------------------
// LuaStackBackup
//----------------------------------------------------------------------------
LuaStackBackup::LuaStackBackup (lua_State *luaState)
	:
mState(luaState)
{
	mTop = lua_gettop(mState);
}
//----------------------------------------------------------------------------
LuaStackBackup::~LuaStackBackup ()
{
	lua_settop(mState, mTop);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
static int GetGlobal (lua_State *mState)
{
	if (lua_isstring(mState,1) == false)
	{
		lua_pushnil(mState);
	}
	else 
	{
		lua_getglobal(mState, lua_tostring(mState,1));
	}

	return 1;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// LuaManager
//----------------------------------------------------------------------------
LuaManager::LuaManager ()
	:
mState(0)
{
	mType = ST_LUA;

	mState = lua_open();
	luaL_openlibs(mState);
	lua_register(mState, "GetGlobal", GetGlobal);
}
//----------------------------------------------------------------------------
LuaManager::~LuaManager ()
{
	if(mState) 
	{
		lua_close(mState);
	}
}
//----------------------------------------------------------------------------
void LuaManager::SetLuaState (lua_State *state)
{
	mState = state;
	lua_register(mState, "GetGlobal", GetGlobal);
}
//----------------------------------------------------------------------------
bool LuaManager::CallString (const char *str)
{
	LuaStackBackup stackbackup(mState);

	int status = luaL_dostring(mState, str);

	if (status != 0)
	{
		const char *err = lua_tostring(mState, -1);

		if (!PX2_GR.IsInEditor())
		{

#if defined(_WIN32) || defined(WIN32)
			::MessageBox(0, err, "CallString::luaL_dostring error.\n", MB_OK);
#endif
			assertion(false, "CallString::luaL_dostring %s error:%s.\n", str, err);
		}

		PX2_LOG_ERROR("CallString::luaL_dostring %s error:%s.\n", str, err);

		return false;
	}

	return true;
}
//----------------------------------------------------------------------------
bool LuaManager::CallFile (const char *filename)
{
	bool ret = false;

	int bufferSize = 0;
	char *buffer = 0;
	if (ResourceManager::GetSingleton().LoadBuffer(filename, bufferSize,
		buffer))
	{
		ret = CallBuffer(buffer, (unsigned long)bufferSize);
	}

	return ret;

//	if (luaL_loadfile(mState, filename) != 0)
//	{
//		const char *err = lua_tostring(mState, -1);
//
//#if defined(_WIN32) || defined(WIN32)
//		::MessageBox(0, err, "CallFile::luaL_loadfile error.\n", MB_OK);
//#endif
//		PX2_LOG_ERROR("CallFile::luaL_loadfile error: %s.\n", err);
//
//		return false;
//	}
//
//	if (lua_pcall(mState, 0, 0, 0) != 0)
//	{
//		const char *err = lua_tostring(mState, -1);
//
//#if defined(_WIN32) || defined(WIN32)
//		::MessageBox(0, err, "CallFile::lua_pcall error.\n", MB_OK);
//#endif
//		PX2_LOG_ERROR("CallFile::lua_pcall error:%s.\n", err);
//
//		return false;
//	}
//
//	return true;
}
//----------------------------------------------------------------------------
bool LuaManager::CallBuffer (const char *buffer, unsigned long size)
{
	if (luaL_loadbuffer(
		mState, buffer, (size_t)size, lua_tostring(mState, -1)) != 0)
	{
		const char *err = lua_tostring(mState, -1);

#if defined(_WIN32) || defined(WIN32)
		::MessageBox(0, err, "CallBuffer::luaL_loadbuffer error.\n", MB_OK);
#endif
		PX2_LOG_ERROR("CallBuffer::luaL_loadbuffer error:%s.\n", err);

		return false;
	}

	if (lua_pcall(mState, 0, 0, 0) != 0)
	{
		const char *err = lua_tostring(mState, -1);

#if defined(_WIN32) || defined(WIN32)
		::MessageBox(0, err, "CallBuffer::lua_pcall error.\n", MB_OK);
#endif
		PX2_LOG_ERROR("CallBuffer::lua_pcall error:%s.\n", err);

		return false;
	}

	return true;
}
//----------------------------------------------------------------------------
void LuaManager::SetUserTypePointer (const char *luaName, 
	const char *className, void *ptr)
{
	LuaStackBackup stackbackup(mState);

	tolua_pushusertype(mState, ptr, className);

	lua_setglobal(mState, luaName);
}
//----------------------------------------------------------------------------
bool LuaManager::CallObjectFunction (const char *objectName, 
	const char *funName, const char *format, ...)
{
	lua_getglobal(mState, "this");
	lua_getglobal(mState, objectName);
	lua_setglobal(mState, "this");

	va_list argptr;
	va_start(argptr, format);
	const char *pfmt = format;
	int count = 0;
	static const char *args[] = {"arg1", "arg2", "arg3", "arg4"};
	while (pfmt[count])
	{
		if(*pfmt == 'i')
		{
			int value = va_arg(argptr, int);
			lua_pushnumber(mState, value);
		}
		else if(*pfmt == 'f')
		{
			float value = (float)(va_arg(argptr, double));
			lua_pushnumber(mState, value);
		}
		else if(*pfmt == 's')
		{
			char *str = va_arg(argptr, char *);
			lua_pushstring(mState, str);
		}
		else
		{
			assertion(false, "");
		}
		lua_setglobal(mState, args[count++]);
	}
	va_end(argptr);

	{
		CallString(funName);
	}

	lua_setglobal(mState, "this");

	return true;
}
//----------------------------------------------------------------------------
bool LuaManager::CallObjectFuntionValist (const char *objectName, 
	const char *funName, const char *format, va_list valist)
{
	lua_getglobal(mState, "this");
	lua_getglobal(mState, objectName);
	lua_setglobal(mState, "this");

	const char *pfmt = format;
	int count = 0;
	static const char *args[] = {"arg1", "arg2", "arg3", "arg4"};
	while (pfmt[count])
	{
		if(*pfmt == 'i')
		{
			int value = va_arg(valist, int);
			lua_pushnumber(mState, value);
		}
		else if(*pfmt == 'f')
		{
			float value = (float)(va_arg(valist, double));
			lua_pushnumber(mState, value);
		}
		else if(*pfmt == 's')
		{
			char *str = va_arg(valist, char *);
			lua_pushstring(mState, str);
		}
		else
		{
			assertion(false, "");
		}
		lua_setglobal(mState, args[count++]);
	}

	{
		CallString(funName);
	}

	lua_setglobal(mState, "this");

	return true;
}
//----------------------------------------------------------------------------