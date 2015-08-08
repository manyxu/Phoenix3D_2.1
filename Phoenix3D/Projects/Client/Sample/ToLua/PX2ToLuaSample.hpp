// PX2ToLuaSoccer.hpp

#ifndef PX2TOLUASOCCER_HPP
#define PX2TOLUASOCCER_HPP

#include "PX2CorePre.hpp"
#include "Score.hpp"
using namespace PX2;

#define PX2_LUA

#if defined (PX2_LUA)

#if (defined(_WIN32) || defined(WIN32)) && defined(_DEBUG)
#pragma warning (disable:4800)
#pragma warning (disable:4505)
#endif

struct lua_State;
extern int  tolua_PX2Soccer_open (lua_State* tolua_S);

#endif

#endif