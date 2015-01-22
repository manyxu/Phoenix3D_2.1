/*
** Lua binding: PX2Editor
** Generated automatically by tolua++-1.0.92 on 01/22/15 11:55:27.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_PX2Editor_open (lua_State* tolua_S);

#include "PX2ToLuaEditor.hpp"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"wxFrame");
 tolua_usertype(tolua_S,"wxMenuItem");
 tolua_usertype(tolua_S,"wxMenu");
 tolua_usertype(tolua_S,"E_MainFrame");
}

/* method: AddMainMenuItem of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddMainMenuItem00
static int tolua_PX2Editor_E_MainFrame_AddMainMenuItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  const std::string title = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddMainMenuItem'", NULL);
#endif
  {
   wxMenu* tolua_ret = (wxMenu*)  self->AddMainMenuItem(title);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wxMenu");
   tolua_pushcppstring(tolua_S,(const char*)title);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddMainMenuItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddMenuItem of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddMenuItem00
static int tolua_PX2Editor_E_MainFrame_AddMenuItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wxMenu",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  wxMenu* menu = ((wxMenu*)  tolua_tousertype(tolua_S,2,0));
  const std::string title = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string script = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddMenuItem'", NULL);
#endif
  {
   wxMenuItem* tolua_ret = (wxMenuItem*)  self->AddMenuItem(menu,title,script);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wxMenuItem");
   tolua_pushcppstring(tolua_S,(const char*)title);
   tolua_pushcppstring(tolua_S,(const char*)script);
  }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddMenuItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddSeparater of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddSeparater00
static int tolua_PX2Editor_E_MainFrame_AddSeparater00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wxMenu",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  wxMenu* menu = ((wxMenu*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddSeparater'", NULL);
#endif
  {
   self->AddSeparater(menu);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddSeparater'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_PX2Editor_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"E_MainFrame","E_MainFrame","wxFrame",NULL);
  tolua_beginmodule(tolua_S,"E_MainFrame");
   tolua_function(tolua_S,"AddMainMenuItem",tolua_PX2Editor_E_MainFrame_AddMainMenuItem00);
   tolua_function(tolua_S,"AddMenuItem",tolua_PX2Editor_E_MainFrame_AddMenuItem00);
   tolua_function(tolua_S,"AddSeparater",tolua_PX2Editor_E_MainFrame_AddSeparater00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_PX2Editor (lua_State* tolua_S) {
 return tolua_PX2Editor_open(tolua_S);
};
#endif

