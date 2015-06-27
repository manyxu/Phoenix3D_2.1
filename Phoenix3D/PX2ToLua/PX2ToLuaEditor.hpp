// PX2ToLuaEditor.hpp

#ifndef PX2TOLUAEDITOR_HPP
#define PX2TOLUAEDITOR_HPP

#include "PX2CorePre.hpp"
#include "PX2E_MainFrame.hpp"
#include "PX2E_NirMan.hpp"
#include "PX2E_Define.hpp"
#include "PX2Edits.hpp"
using namespace PX2Editor;
using namespace PX2;

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