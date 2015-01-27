/*
** Lua binding: PX2Editor
** Generated automatically by tolua++-1.0.92 on 01/27/15 14:15:46.
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
 tolua_usertype(tolua_S,"Singleton<NirMan>");
 tolua_usertype(tolua_S,"NirMan");
 tolua_usertype(tolua_S,"wxMenu");
 tolua_usertype(tolua_S,"wxEvtHandler");
 tolua_usertype(tolua_S,"wxMenuItem");
 tolua_usertype(tolua_S,"wxCommandEvent");
 tolua_usertype(tolua_S,"E_MainFrame");
}

/* method: OnNewProject of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnNewProject00
static int tolua_PX2Editor_E_MainFrame_OnNewProject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnNewProject'", NULL);
#endif
  {
   self->OnNewProject();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnNewProject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnOpenProject of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnOpenProject00
static int tolua_PX2Editor_E_MainFrame_OnOpenProject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnOpenProject'", NULL);
#endif
  {
   self->OnOpenProject();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnOpenProject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnSaveProject of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnSaveProject00
static int tolua_PX2Editor_E_MainFrame_OnSaveProject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnSaveProject'", NULL);
#endif
  {
   self->OnSaveProject();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnSaveProject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnSaveProjectAs of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnSaveProjectAs00
static int tolua_PX2Editor_E_MainFrame_OnSaveProjectAs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnSaveProjectAs'", NULL);
#endif
  {
   self->OnSaveProjectAs();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnSaveProjectAs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnCloseProject of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnCloseProject00
static int tolua_PX2Editor_E_MainFrame_OnCloseProject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnCloseProject'", NULL);
#endif
  {
   self->OnCloseProject();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnCloseProject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnNewScene of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnNewScene00
static int tolua_PX2Editor_E_MainFrame_OnNewScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnNewScene'", NULL);
#endif
  {
   self->OnNewScene();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnNewScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnOpenScene of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnOpenScene00
static int tolua_PX2Editor_E_MainFrame_OnOpenScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnOpenScene'", NULL);
#endif
  {
   self->OnOpenScene();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnOpenScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnSaveScene of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnSaveScene00
static int tolua_PX2Editor_E_MainFrame_OnSaveScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnSaveScene'", NULL);
#endif
  {
   self->OnSaveScene();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnSaveScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnSaveSceneAs of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnSaveSceneAs00
static int tolua_PX2Editor_E_MainFrame_OnSaveSceneAs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnSaveSceneAs'", NULL);
#endif
  {
   self->OnSaveSceneAs();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnSaveSceneAs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnCloseScene of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnCloseScene00
static int tolua_PX2Editor_E_MainFrame_OnCloseScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnCloseScene'", NULL);
#endif
  {
   self->OnCloseScene();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnCloseScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnSetEditMode of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnSetEditMode00
static int tolua_PX2Editor_E_MainFrame_OnSetEditMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  int type = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnSetEditMode'", NULL);
#endif
  {
   self->OnSetEditMode(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnSetEditMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

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

/* method: GetEditMenu of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_GetEditMenu00
static int tolua_PX2Editor_NirMan_GetEditMenu00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NirMan",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NirMan* self = (NirMan*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEditMenu'", NULL);
#endif
  {
   wxMenu* tolua_ret = (wxMenu*)  self->GetEditMenu();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wxMenu");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEditMenu'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddMenuItem of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_AddMenuItem00
static int tolua_PX2Editor_NirMan_AddMenuItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NirMan",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wxMenu",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NirMan* self = (NirMan*)  tolua_tousertype(tolua_S,1,0);
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

/* method: AddSeparater of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_AddSeparater00
static int tolua_PX2Editor_NirMan_AddSeparater00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NirMan",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wxMenu",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NirMan* self = (NirMan*)  tolua_tousertype(tolua_S,1,0);
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

/* method: OnMenuItem of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_OnMenuItem00
static int tolua_PX2Editor_NirMan_OnMenuItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NirMan",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"wxCommandEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NirMan* self = (NirMan*)  tolua_tousertype(tolua_S,1,0);
  wxCommandEvent* e = ((wxCommandEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnMenuItem'", NULL);
#endif
  {
   self->OnMenuItem(*e);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnMenuItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __Singleton<NirMan>__ of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_get_NirMan___Singleton_NirMan___
static int tolua_get_NirMan___Singleton_NirMan___(lua_State* tolua_S)
{
  NirMan* self = (NirMan*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__Singleton<NirMan>__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<Singleton<NirMan>*>(self), "Singleton<NirMan>");
#else
   tolua_pushusertype(tolua_S,(void*)((Singleton<NirMan>*)self), "Singleton<NirMan>");
#endif
 return 1;
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
   tolua_function(tolua_S,"OnNewProject",tolua_PX2Editor_E_MainFrame_OnNewProject00);
   tolua_function(tolua_S,"OnOpenProject",tolua_PX2Editor_E_MainFrame_OnOpenProject00);
   tolua_function(tolua_S,"OnSaveProject",tolua_PX2Editor_E_MainFrame_OnSaveProject00);
   tolua_function(tolua_S,"OnSaveProjectAs",tolua_PX2Editor_E_MainFrame_OnSaveProjectAs00);
   tolua_function(tolua_S,"OnCloseProject",tolua_PX2Editor_E_MainFrame_OnCloseProject00);
   tolua_function(tolua_S,"OnNewScene",tolua_PX2Editor_E_MainFrame_OnNewScene00);
   tolua_function(tolua_S,"OnOpenScene",tolua_PX2Editor_E_MainFrame_OnOpenScene00);
   tolua_function(tolua_S,"OnSaveScene",tolua_PX2Editor_E_MainFrame_OnSaveScene00);
   tolua_function(tolua_S,"OnSaveSceneAs",tolua_PX2Editor_E_MainFrame_OnSaveSceneAs00);
   tolua_function(tolua_S,"OnCloseScene",tolua_PX2Editor_E_MainFrame_OnCloseScene00);
   tolua_function(tolua_S,"OnSetEditMode",tolua_PX2Editor_E_MainFrame_OnSetEditMode00);
   tolua_function(tolua_S,"AddMainMenuItem",tolua_PX2Editor_E_MainFrame_AddMainMenuItem00);
   tolua_function(tolua_S,"AddMenuItem",tolua_PX2Editor_E_MainFrame_AddMenuItem00);
   tolua_function(tolua_S,"AddSeparater",tolua_PX2Editor_E_MainFrame_AddSeparater00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"NirMan","NirMan","wxEvtHandler",NULL);
  tolua_beginmodule(tolua_S,"NirMan");
   tolua_function(tolua_S,"GetEditMenu",tolua_PX2Editor_NirMan_GetEditMenu00);
   tolua_function(tolua_S,"AddMenuItem",tolua_PX2Editor_NirMan_AddMenuItem00);
   tolua_function(tolua_S,"AddSeparater",tolua_PX2Editor_NirMan_AddSeparater00);
   tolua_function(tolua_S,"OnMenuItem",tolua_PX2Editor_NirMan_OnMenuItem00);
   tolua_variable(tolua_S,"__Singleton_NirMan___",tolua_get_NirMan___Singleton_NirMan___,NULL);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_PX2Editor (lua_State* tolua_S) {
 return tolua_PX2Editor_open(tolua_S);
};
#endif

