/*
*
* ÎÄ¼þÃû³Æ	£º	PX2ToLua.hpp
*
*/

#ifndef PX2TOLUA_HPP
#define PX2TOLUA_HPP

#include "PX2Core.hpp"
#include "PX2Mathematics.hpp"
#include "PX2Graphics.hpp"
#include "PX2Renderers.hpp"
#include "PX2EventWorld.hpp"
#include "PX2Input.hpp"
#include "PX2Unity.hpp"
#include "PX2SoundSystem.hpp"
#include "PX2UserInterface.hpp"
#include "PX2Terrains.hpp"
#include "PX2Effect.hpp"
#include "PX2Game.hpp"

// the game
#include "X_Heads.hpp"

using namespace PX2;

#define PX2_LUA

#if defined (PX2_LUA)

#if (defined(_WIN32) || defined(WIN32)) && defined(_DEBUG)
#pragma warning (disable:4800)
#endif

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}
#include "tolua++.h"
extern int  tolua_PX2_open (lua_State* tolua_S);
#endif

#endif