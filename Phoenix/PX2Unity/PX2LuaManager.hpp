/*
*
* ÎÄ¼þÃû³Æ	£º	PX2LuaManager.hpp
*
*/

#ifndef PX2LUAMANAGER_HPP
#define PX2LUAMANAGER_HPP

#include "PX2ScriptManager.hpp"

struct lua_State;

namespace PX2
{

	class LuaStackBackup
	{
	public:
		LuaStackBackup (lua_State *luaState);
		~LuaStackBackup ();

	private:
		lua_State *mState;
		int	mTop;
	};

	class LuaManager : public ScriptManager
	{
	public:
		LuaManager ();
		virtual ~LuaManager ();

		void SetLuaState (lua_State *state);
		lua_State *GetLuaState ();

		virtual bool CallString (const char *str);
		virtual bool CallFile (const char *filename);
		virtual bool CallBuffer (const char *buffer, unsigned long size);
		virtual bool CallObjectFunction (const char *objectName, const char *funName,
			const char *format="", ...);
		virtual bool CallObjectFuntionValist (const char *objectName, 
			const char *funName, const char *format, va_list valist);
		virtual void SetUserTypePointer (const char *luaName, const char *className,
			void *ptr);

	protected:
		lua_State *mState;
	};

#include "PX2LuaManager.inl"

}

#endif