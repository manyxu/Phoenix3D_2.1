// PX2ToLuaEditor.hpp

#ifndef PX2TOLUA_HPP
#define PX2TOLUA_HPP

#include "PX2CorePre.hpp"
#include "PX2E_MainFrame.hpp"
using namespace PX2Editor;

#define PX2_LUA

#if defined (PX2_LUA)

#if (defined(_WIN32) || defined(WIN32)) && defined(_DEBUG)
#pragma warning (disable:4800)
#pragma warning (disable:4505)
#endif

struct lua_State;
extern int  tolua_PX2Editor_open (lua_State* tolua_S);

#endif

#endif