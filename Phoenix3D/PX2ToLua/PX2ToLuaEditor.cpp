/*
** Lua binding: PX2Editor
** Generated automatically by tolua++-1.0.92 on 03/02/15 18:03:09.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_PX2Editor_open (lua_State* tolua_S);

#include "PX2ToLuaEditor.hpp"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_EditMap (lua_State* tolua_S)
{
 EditMap* self = (EditMap*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_SelectResData (lua_State* tolua_S)
{
 SelectResData* self = (SelectResData*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Edit (lua_State* tolua_S)
{
 Edit* self = (Edit*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"PX2::ObjectPtr");
 tolua_usertype(tolua_S,"E_MainFrame");
 tolua_usertype(tolua_S,"wxFrame");
 tolua_usertype(tolua_S,"Singleton<NirMan>");
 tolua_usertype(tolua_S,"wxMenu");
 tolua_usertype(tolua_S,"APoint");
 tolua_usertype(tolua_S,"GeoObjFactory");
 tolua_usertype(tolua_S,"Edit");
 tolua_usertype(tolua_S,"EditParams");
 tolua_usertype(tolua_S,"PX2wxAuiToolBar");
 tolua_usertype(tolua_S,"SelectResData");
 tolua_usertype(tolua_S,"EditMap");
 tolua_usertype(tolua_S,"PX2::Object");
 tolua_usertype(tolua_S,"NirMan");
 tolua_usertype(tolua_S,"std::vector<std::string>");
 tolua_usertype(tolua_S,"wxMenuItem");
 tolua_usertype(tolua_S,"wxEvtHandler");
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

/* method: OnSetting of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnSetting00
static int tolua_PX2Editor_E_MainFrame_OnSetting00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnSetting'", NULL);
#endif
  {
   self->OnSetting();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnSetting'.",&tolua_err);
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

/* method: SetCurMenu of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_SetCurMenu00
static int tolua_PX2Editor_NirMan_SetCurMenu00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCurMenu'", NULL);
#endif
  {
   self->SetCurMenu(menu);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCurMenu'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCurMenu of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_GetCurMenu00
static int tolua_PX2Editor_NirMan_GetCurMenu00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCurMenu'", NULL);
#endif
  {
   wxMenu* tolua_ret = (wxMenu*)  self->GetCurMenu();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wxMenu");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCurMenu'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddSubMenu of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_AddSubMenu00
static int tolua_PX2Editor_NirMan_AddSubMenu00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NirMan",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wxMenu",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NirMan* self = (NirMan*)  tolua_tousertype(tolua_S,1,0);
  wxMenu* menu = ((wxMenu*)  tolua_tousertype(tolua_S,2,0));
  const std::string title = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddSubMenu'", NULL);
#endif
  {
   wxMenu* tolua_ret = (wxMenu*)  self->AddSubMenu(menu,title);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wxMenu");
   tolua_pushcppstring(tolua_S,(const char*)title);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddSubMenu'.",&tolua_err);
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

/* method: SetCurToolBar of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_SetCurToolBar00
static int tolua_PX2Editor_NirMan_SetCurToolBar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NirMan",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2wxAuiToolBar",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NirMan* self = (NirMan*)  tolua_tousertype(tolua_S,1,0);
  PX2wxAuiToolBar* toolBar = ((PX2wxAuiToolBar*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCurToolBar'", NULL);
#endif
  {
   self->SetCurToolBar(toolBar);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCurToolBar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCurToolBar of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_GetCurToolBar00
static int tolua_PX2Editor_NirMan_GetCurToolBar00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCurToolBar'", NULL);
#endif
  {
   PX2wxAuiToolBar* tolua_ret = (PX2wxAuiToolBar*)  self->GetCurToolBar();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"PX2wxAuiToolBar");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCurToolBar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddTool of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_AddTool00
static int tolua_PX2Editor_NirMan_AddTool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NirMan",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NirMan* self = (NirMan*)  tolua_tousertype(tolua_S,1,0);
  const std::string icon = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string script = ((std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddTool'", NULL);
#endif
  {
   self->AddTool(icon,script);
   tolua_pushcppstring(tolua_S,(const char*)icon);
   tolua_pushcppstring(tolua_S,(const char*)script);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddTool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddToolSeparater of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_AddToolSeparater00
static int tolua_PX2Editor_NirMan_AddToolSeparater00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddToolSeparater'", NULL);
#endif
  {
   self->AddToolSeparater();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddToolSeparater'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddMenuTool of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_AddMenuTool00
static int tolua_PX2Editor_NirMan_AddMenuTool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NirMan",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NirMan* self = (NirMan*)  tolua_tousertype(tolua_S,1,0);
  const std::string menuTitle = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string script = ((std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddMenuTool'", NULL);
#endif
  {
   self->AddMenuTool(menuTitle,script);
   tolua_pushcppstring(tolua_S,(const char*)menuTitle);
   tolua_pushcppstring(tolua_S,(const char*)script);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddMenuTool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProjTreeLevel of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_SetProjTreeLevel00
static int tolua_PX2Editor_NirMan_SetProjTreeLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NirMan",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NirMan* self = (NirMan*)  tolua_tousertype(tolua_S,1,0);
  int level = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProjTreeLevel'", NULL);
#endif
  {
   self->SetProjTreeLevel(level);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProjTreeLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MessageBox of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_MessageBox00
static int tolua_PX2Editor_NirMan_MessageBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NirMan",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NirMan* self = (NirMan*)  tolua_tousertype(tolua_S,1,0);
  const std::string caption = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string content = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MessageBox'", NULL);
#endif
  {
   self->MessageBox(caption,content);
   tolua_pushcppstring(tolua_S,(const char*)caption);
   tolua_pushcppstring(tolua_S,(const char*)content);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MessageBox'.",&tolua_err);
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

/* method: new of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_new00
static int tolua_PX2Editor_Edit_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Edit* tolua_ret = (Edit*)  Mtolua_new((Edit)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Edit");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_new00_local
static int tolua_PX2Editor_Edit_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Edit* tolua_ret = (Edit*)  Mtolua_new((Edit)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Edit");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_delete00
static int tolua_PX2Editor_Edit_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Initlize of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_Initlize00
static int tolua_PX2Editor_Edit_Initlize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Initlize'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Initlize();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Initlize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Ternamate of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_Ternamate00
static int tolua_PX2Editor_Edit_Ternamate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Ternamate'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Ternamate();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Ternamate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Reset of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_Reset00
static int tolua_PX2Editor_Edit_Reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Reset'", NULL);
#endif
  {
   self->Reset();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Reset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEditType of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_SetEditType00
static int tolua_PX2Editor_Edit_SetEditType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Edit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
  Edit::EditType type = ((Edit::EditType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEditType'", NULL);
#endif
  {
   self->SetEditType(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEditType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEditType of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_GetEditType00
static int tolua_PX2Editor_Edit_GetEditType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Edit* self = (const Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEditType'", NULL);
#endif
  {
   Edit::EditType tolua_ret = (Edit::EditType)  self->GetEditType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEditType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEditMode of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_SetEditMode00
static int tolua_PX2Editor_Edit_SetEditMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Edit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
  Edit::EditMode mode = ((Edit::EditMode) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEditMode'", NULL);
#endif
  {
   self->SetEditMode(mode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEditMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEditMode of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_GetEditMode00
static int tolua_PX2Editor_Edit_GetEditMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Edit* self = (const Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEditMode'", NULL);
#endif
  {
   Edit::EditMode tolua_ret = (Edit::EditMode)  self->GetEditMode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEditMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEditMap of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_GetEditMap00
static int tolua_PX2Editor_Edit_GetEditMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEditMap'", NULL);
#endif
  {
   EditMap* tolua_ret = (EditMap*)  self->GetEditMap();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EditMap");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEditMap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGOF of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_GetGOF00
static int tolua_PX2Editor_Edit_GetGOF00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGOF'", NULL);
#endif
  {
   GeoObjFactory* tolua_ret = (GeoObjFactory*)  self->GetGOF();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GeoObjFactory");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGOF'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEditID of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_GetEditID00
static int tolua_PX2Editor_Edit_GetEditID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   int tolua_ret = (int)  Edit::GetEditID();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEditID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEditParams of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_GetEditParams00
static int tolua_PX2Editor_Edit_GetEditParams00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEditParams'", NULL);
#endif
  {
   EditParams* tolua_ret = (EditParams*)  self->GetEditParams();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EditParams");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEditParams'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: IsAltDown of class  Edit */
#ifndef TOLUA_DISABLE_tolua_get_Edit_IsAltDown
static int tolua_get_Edit_IsAltDown(lua_State* tolua_S)
{
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'IsAltDown'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->IsAltDown);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: IsAltDown of class  Edit */
#ifndef TOLUA_DISABLE_tolua_set_Edit_IsAltDown
static int tolua_set_Edit_IsAltDown(lua_State* tolua_S)
{
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'IsAltDown'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->IsAltDown = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: IsCtrlDown of class  Edit */
#ifndef TOLUA_DISABLE_tolua_get_Edit_IsCtrlDown
static int tolua_get_Edit_IsCtrlDown(lua_State* tolua_S)
{
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'IsCtrlDown'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->IsCtrlDown);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: IsCtrlDown of class  Edit */
#ifndef TOLUA_DISABLE_tolua_set_Edit_IsCtrlDown
static int tolua_set_Edit_IsCtrlDown(lua_State* tolua_S)
{
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'IsCtrlDown'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->IsCtrlDown = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: IsShiftDown of class  Edit */
#ifndef TOLUA_DISABLE_tolua_get_Edit_IsShiftDown
static int tolua_get_Edit_IsShiftDown(lua_State* tolua_S)
{
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'IsShiftDown'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->IsShiftDown);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: IsShiftDown of class  Edit */
#ifndef TOLUA_DISABLE_tolua_set_Edit_IsShiftDown
static int tolua_set_Edit_IsShiftDown(lua_State* tolua_S)
{
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'IsShiftDown'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->IsShiftDown = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPickPos of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_SetPickPos00
static int tolua_PX2Editor_Edit_SetPickPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Edit",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPickPos'", NULL);
#endif
  {
   self->SetPickPos(*pos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPickPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPickPos of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_GetPickPos00
static int tolua_PX2Editor_Edit_GetPickPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Edit* self = (const Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPickPos'", NULL);
#endif
  {
   const APoint& tolua_ret = (const APoint&)  self->GetPickPos();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const APoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPickPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DeleteSelection of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_DeleteSelection00
static int tolua_PX2Editor_Edit_DeleteSelection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DeleteSelection'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->DeleteSelection();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DeleteSelection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSelectPath_ChildFilenames of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_SetSelectPath_ChildFilenames00
static int tolua_PX2Editor_Edit_SetSelectPath_ChildFilenames00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Edit",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const std::vector<std::string>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
  const std::vector<std::string>* filenamess = ((const std::vector<std::string>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSelectPath_ChildFilenames'", NULL);
#endif
  {
   self->SetSelectPath_ChildFilenames(*filenamess);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSelectPath_ChildFilenames'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSelectPath_ChildPaths of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_SetSelectPath_ChildPaths00
static int tolua_PX2Editor_Edit_SetSelectPath_ChildPaths00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Edit",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const std::vector<std::string>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
  const std::vector<std::string>* paths = ((const std::vector<std::string>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSelectPath_ChildPaths'", NULL);
#endif
  {
   self->SetSelectPath_ChildPaths(*paths);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSelectPath_ChildPaths'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSelectPath_ChildFilenames of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_GetSelectPath_ChildFilenames00
static int tolua_PX2Editor_Edit_GetSelectPath_ChildFilenames00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Edit* self = (const Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSelectPath_ChildFilenames'", NULL);
#endif
  {
   const std::vector<std::string>& tolua_ret = (const std::vector<std::string>&)  self->GetSelectPath_ChildFilenames();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const std::vector<std::string>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSelectPath_ChildFilenames'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSelectPath_ChildPaths of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_GetSelectPath_ChildPaths00
static int tolua_PX2Editor_Edit_GetSelectPath_ChildPaths00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Edit* self = (const Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSelectPath_ChildPaths'", NULL);
#endif
  {
   const std::vector<std::string>& tolua_ret = (const std::vector<std::string>&)  self->GetSelectPath_ChildPaths();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const std::vector<std::string>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSelectPath_ChildPaths'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSelectedResource of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_SetSelectedResource00
static int tolua_PX2Editor_Edit_SetSelectedResource00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Edit",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const SelectResData",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
  const SelectResData* data = ((const SelectResData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSelectedResource'", NULL);
#endif
  {
   self->SetSelectedResource(*data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSelectedResource'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSelectedResource of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_GetSelectedResource00
static int tolua_PX2Editor_Edit_GetSelectedResource00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Edit* self = (const Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSelectedResource'", NULL);
#endif
  {
   const SelectResData& tolua_ret = (const SelectResData&)  self->GetSelectedResource();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const SelectResData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSelectedResource'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCopyObject of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_SetCopyObject00
static int tolua_PX2Editor_Edit_SetCopyObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Edit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2::Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
  PX2::Object* obj = ((PX2::Object*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCopyObject'", NULL);
#endif
  {
   self->SetCopyObject(obj);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCopyObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCopyObject of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_GetCopyObject00
static int tolua_PX2Editor_Edit_GetCopyObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCopyObject'", NULL);
#endif
  {
   PX2::Object* tolua_ret = (PX2::Object*)  self->GetCopyObject();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"PX2::Object");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCopyObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PasteCopyedObject of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_PasteCopyedObject00
static int tolua_PX2Editor_Edit_PasteCopyedObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Edit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PasteCopyedObject'", NULL);
#endif
  {
   self->PasteCopyedObject();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PasteCopyedObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  EditMap */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_EditMap_new00
static int tolua_PX2Editor_EditMap_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EditMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   EditMap* tolua_ret = (EditMap*)  Mtolua_new((EditMap)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EditMap");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  EditMap */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_EditMap_new00_local
static int tolua_PX2Editor_EditMap_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EditMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   EditMap* tolua_ret = (EditMap*)  Mtolua_new((EditMap)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EditMap");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  EditMap */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_EditMap_delete00
static int tolua_PX2Editor_EditMap_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditMap* self = (EditMap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: NewProject of class  EditMap */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_EditMap_NewProject00
static int tolua_PX2Editor_EditMap_NewProject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditMap",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditMap* self = (EditMap*)  tolua_tousertype(tolua_S,1,0);
  const std::string pathname = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string projName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  int height = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NewProject'", NULL);
#endif
  {
   self->NewProject(pathname,projName,width,height);
   tolua_pushcppstring(tolua_S,(const char*)pathname);
   tolua_pushcppstring(tolua_S,(const char*)projName);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'NewProject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadProject of class  EditMap */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_EditMap_LoadProject00
static int tolua_PX2Editor_EditMap_LoadProject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditMap",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditMap* self = (EditMap*)  tolua_tousertype(tolua_S,1,0);
  const char* pathname = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadProject'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->LoadProject(pathname);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadProject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SaveProject of class  EditMap */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_EditMap_SaveProject00
static int tolua_PX2Editor_EditMap_SaveProject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditMap* self = (EditMap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SaveProject'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SaveProject();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaveProject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SaveProjectAs of class  EditMap */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_EditMap_SaveProjectAs00
static int tolua_PX2Editor_EditMap_SaveProjectAs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditMap",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditMap* self = (EditMap*)  tolua_tousertype(tolua_S,1,0);
  const char* pathname = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SaveProjectAs'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SaveProjectAs(pathname);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaveProjectAs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CloseProject of class  EditMap */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_EditMap_CloseProject00
static int tolua_PX2Editor_EditMap_CloseProject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditMap* self = (EditMap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CloseProject'", NULL);
#endif
  {
   self->CloseProject();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CloseProject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetProjectFilePath of class  EditMap */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_EditMap_GetProjectFilePath00
static int tolua_PX2Editor_EditMap_GetProjectFilePath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditMap* self = (EditMap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetProjectFilePath'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetProjectFilePath();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetProjectFilePath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: NewScene of class  EditMap */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_EditMap_NewScene00
static int tolua_PX2Editor_EditMap_NewScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditMap* self = (EditMap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NewScene'", NULL);
#endif
  {
   self->NewScene();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'NewScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadScene of class  EditMap */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_EditMap_LoadScene00
static int tolua_PX2Editor_EditMap_LoadScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditMap",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditMap* self = (EditMap*)  tolua_tousertype(tolua_S,1,0);
  const std::string pathname = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadScene'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->LoadScene(pathname);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)pathname);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SaveScene of class  EditMap */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_EditMap_SaveScene00
static int tolua_PX2Editor_EditMap_SaveScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditMap",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditMap* self = (EditMap*)  tolua_tousertype(tolua_S,1,0);
  const std::string pathname = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SaveScene'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SaveScene(pathname);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)pathname);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaveScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SaveSceneAs of class  EditMap */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_EditMap_SaveSceneAs00
static int tolua_PX2Editor_EditMap_SaveSceneAs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditMap",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditMap* self = (EditMap*)  tolua_tousertype(tolua_S,1,0);
  const std::string pathname = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SaveSceneAs'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SaveSceneAs(pathname);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)pathname);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaveSceneAs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CloseScene of class  EditMap */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_EditMap_CloseScene00
static int tolua_PX2Editor_EditMap_CloseScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EditMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditMap* self = (EditMap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CloseScene'", NULL);
#endif
  {
   self->CloseScene();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CloseScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SelectResData */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_SelectResData_new00
static int tolua_PX2Editor_SelectResData_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SelectResData",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SelectResData::SelectResType type = ((SelectResData::SelectResType) (int)  tolua_tonumber(tolua_S,2,SelectResData::RT_NORMAL));
  {
   SelectResData* tolua_ret = (SelectResData*)  Mtolua_new((SelectResData)(type));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SelectResData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  SelectResData */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_SelectResData_new00_local
static int tolua_PX2Editor_SelectResData_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SelectResData",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SelectResData::SelectResType type = ((SelectResData::SelectResType) (int)  tolua_tonumber(tolua_S,2,SelectResData::RT_NORMAL));
  {
   SelectResData* tolua_ret = (SelectResData*)  Mtolua_new((SelectResData)(type));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SelectResData");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  SelectResData */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_SelectResData_delete00
static int tolua_PX2Editor_SelectResData_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SelectResData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SelectResData* self = (SelectResData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSelectResType of class  SelectResData */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_SelectResData_GetSelectResType00
static int tolua_PX2Editor_SelectResData_GetSelectResType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const SelectResData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const SelectResData* self = (const SelectResData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSelectResType'", NULL);
#endif
  {
   SelectResData::SelectResType tolua_ret = (SelectResData::SelectResType)  self->GetSelectResType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSelectResType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ResPathname of class  SelectResData */
#ifndef TOLUA_DISABLE_tolua_get_SelectResData_ResPathname
static int tolua_get_SelectResData_ResPathname(lua_State* tolua_S)
{
  SelectResData* self = (SelectResData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ResPathname'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->ResPathname);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ResPathname of class  SelectResData */
#ifndef TOLUA_DISABLE_tolua_set_SelectResData_ResPathname
static int tolua_set_SelectResData_ResPathname(lua_State* tolua_S)
{
  SelectResData* self = (SelectResData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ResPathname'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ResPathname = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: TheObject of class  SelectResData */
#ifndef TOLUA_DISABLE_tolua_get_SelectResData_TheObject
static int tolua_get_SelectResData_TheObject(lua_State* tolua_S)
{
  SelectResData* self = (SelectResData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TheObject'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->TheObject,"PX2::ObjectPtr");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: TheObject of class  SelectResData */
#ifndef TOLUA_DISABLE_tolua_set_SelectResData_TheObject
static int tolua_set_SelectResData_TheObject(lua_State* tolua_S)
{
  SelectResData* self = (SelectResData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TheObject'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"PX2::ObjectPtr",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->TheObject = *((PX2::ObjectPtr*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: EleName of class  SelectResData */
#ifndef TOLUA_DISABLE_tolua_get_SelectResData_EleName
static int tolua_get_SelectResData_EleName(lua_State* tolua_S)
{
  SelectResData* self = (SelectResData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'EleName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->EleName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: EleName of class  SelectResData */
#ifndef TOLUA_DISABLE_tolua_set_SelectResData_EleName
static int tolua_set_SelectResData_EleName(lua_State* tolua_S)
{
  SelectResData* self = (SelectResData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'EleName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->EleName = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
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
   tolua_function(tolua_S,"OnSetting",tolua_PX2Editor_E_MainFrame_OnSetting00);
   tolua_function(tolua_S,"AddMainMenuItem",tolua_PX2Editor_E_MainFrame_AddMainMenuItem00);
   tolua_function(tolua_S,"AddMenuItem",tolua_PX2Editor_E_MainFrame_AddMenuItem00);
   tolua_function(tolua_S,"AddSeparater",tolua_PX2Editor_E_MainFrame_AddSeparater00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"NirMan","NirMan","wxEvtHandler",NULL);
  tolua_beginmodule(tolua_S,"NirMan");
   tolua_function(tolua_S,"SetCurMenu",tolua_PX2Editor_NirMan_SetCurMenu00);
   tolua_function(tolua_S,"GetCurMenu",tolua_PX2Editor_NirMan_GetCurMenu00);
   tolua_function(tolua_S,"AddSubMenu",tolua_PX2Editor_NirMan_AddSubMenu00);
   tolua_function(tolua_S,"AddMenuItem",tolua_PX2Editor_NirMan_AddMenuItem00);
   tolua_function(tolua_S,"AddSeparater",tolua_PX2Editor_NirMan_AddSeparater00);
   tolua_function(tolua_S,"SetCurToolBar",tolua_PX2Editor_NirMan_SetCurToolBar00);
   tolua_function(tolua_S,"GetCurToolBar",tolua_PX2Editor_NirMan_GetCurToolBar00);
   tolua_function(tolua_S,"AddTool",tolua_PX2Editor_NirMan_AddTool00);
   tolua_function(tolua_S,"AddToolSeparater",tolua_PX2Editor_NirMan_AddToolSeparater00);
   tolua_function(tolua_S,"AddMenuTool",tolua_PX2Editor_NirMan_AddMenuTool00);
   tolua_function(tolua_S,"SetProjTreeLevel",tolua_PX2Editor_NirMan_SetProjTreeLevel00);
   tolua_function(tolua_S,"MessageBox",tolua_PX2Editor_NirMan_MessageBox00);
   tolua_variable(tolua_S,"__Singleton_NirMan___",tolua_get_NirMan___Singleton_NirMan___,NULL);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"RVT_SCENEUI",RVT_SCENEUI);
  tolua_constant(tolua_S,"RVT_LOGIC",RVT_LOGIC);
  tolua_constant(tolua_S,"RVT_RES",RVT_RES);
  tolua_constant(tolua_S,"RVT_TIMELINE",RVT_TIMELINE);
  tolua_constant(tolua_S,"RVT_MAX_TYPE",RVT_MAX_TYPE);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Edit","Edit","",tolua_collect_Edit);
  #else
  tolua_cclass(tolua_S,"Edit","Edit","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Edit");
   tolua_function(tolua_S,"new",tolua_PX2Editor_Edit_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2Editor_Edit_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2Editor_Edit_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2Editor_Edit_delete00);
   tolua_function(tolua_S,"Initlize",tolua_PX2Editor_Edit_Initlize00);
   tolua_function(tolua_S,"Ternamate",tolua_PX2Editor_Edit_Ternamate00);
   tolua_function(tolua_S,"Reset",tolua_PX2Editor_Edit_Reset00);
   tolua_constant(tolua_S,"ET_SCENE",Edit::ET_SCENE);
   tolua_constant(tolua_S,"ET_TERRAIN",Edit::ET_TERRAIN);
   tolua_constant(tolua_S,"ET_UI",Edit::ET_UI);
   tolua_constant(tolua_S,"ET_MAXTYPE",Edit::ET_MAXTYPE);
   tolua_function(tolua_S,"SetEditType",tolua_PX2Editor_Edit_SetEditType00);
   tolua_function(tolua_S,"GetEditType",tolua_PX2Editor_Edit_GetEditType00);
   tolua_constant(tolua_S,"EM_NONE",Edit::EM_NONE);
   tolua_constant(tolua_S,"EM_SELECT",Edit::EM_SELECT);
   tolua_constant(tolua_S,"EM_TRANSLATE",Edit::EM_TRANSLATE);
   tolua_constant(tolua_S,"EM_ROLATE",Edit::EM_ROLATE);
   tolua_constant(tolua_S,"EM_SCALE",Edit::EM_SCALE);
   tolua_constant(tolua_S,"EM_MAX_MODE",Edit::EM_MAX_MODE);
   tolua_function(tolua_S,"SetEditMode",tolua_PX2Editor_Edit_SetEditMode00);
   tolua_function(tolua_S,"GetEditMode",tolua_PX2Editor_Edit_GetEditMode00);
   tolua_function(tolua_S,"GetEditMap",tolua_PX2Editor_Edit_GetEditMap00);
   tolua_function(tolua_S,"GetGOF",tolua_PX2Editor_Edit_GetGOF00);
   tolua_function(tolua_S,"GetEditID",tolua_PX2Editor_Edit_GetEditID00);
   tolua_function(tolua_S,"GetEditParams",tolua_PX2Editor_Edit_GetEditParams00);
   tolua_variable(tolua_S,"IsAltDown",tolua_get_Edit_IsAltDown,tolua_set_Edit_IsAltDown);
   tolua_variable(tolua_S,"IsCtrlDown",tolua_get_Edit_IsCtrlDown,tolua_set_Edit_IsCtrlDown);
   tolua_variable(tolua_S,"IsShiftDown",tolua_get_Edit_IsShiftDown,tolua_set_Edit_IsShiftDown);
   tolua_function(tolua_S,"SetPickPos",tolua_PX2Editor_Edit_SetPickPos00);
   tolua_function(tolua_S,"GetPickPos",tolua_PX2Editor_Edit_GetPickPos00);
   tolua_function(tolua_S,"DeleteSelection",tolua_PX2Editor_Edit_DeleteSelection00);
   tolua_function(tolua_S,"SetSelectPath_ChildFilenames",tolua_PX2Editor_Edit_SetSelectPath_ChildFilenames00);
   tolua_function(tolua_S,"SetSelectPath_ChildPaths",tolua_PX2Editor_Edit_SetSelectPath_ChildPaths00);
   tolua_function(tolua_S,"GetSelectPath_ChildFilenames",tolua_PX2Editor_Edit_GetSelectPath_ChildFilenames00);
   tolua_function(tolua_S,"GetSelectPath_ChildPaths",tolua_PX2Editor_Edit_GetSelectPath_ChildPaths00);
   tolua_function(tolua_S,"SetSelectedResource",tolua_PX2Editor_Edit_SetSelectedResource00);
   tolua_function(tolua_S,"GetSelectedResource",tolua_PX2Editor_Edit_GetSelectedResource00);
   tolua_function(tolua_S,"SetCopyObject",tolua_PX2Editor_Edit_SetCopyObject00);
   tolua_function(tolua_S,"GetCopyObject",tolua_PX2Editor_Edit_GetCopyObject00);
   tolua_function(tolua_S,"PasteCopyedObject",tolua_PX2Editor_Edit_PasteCopyedObject00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"EditMap","EditMap","",tolua_collect_EditMap);
  #else
  tolua_cclass(tolua_S,"EditMap","EditMap","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"EditMap");
   tolua_function(tolua_S,"new",tolua_PX2Editor_EditMap_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2Editor_EditMap_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2Editor_EditMap_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2Editor_EditMap_delete00);
   tolua_function(tolua_S,"NewProject",tolua_PX2Editor_EditMap_NewProject00);
   tolua_function(tolua_S,"LoadProject",tolua_PX2Editor_EditMap_LoadProject00);
   tolua_function(tolua_S,"SaveProject",tolua_PX2Editor_EditMap_SaveProject00);
   tolua_function(tolua_S,"SaveProjectAs",tolua_PX2Editor_EditMap_SaveProjectAs00);
   tolua_function(tolua_S,"CloseProject",tolua_PX2Editor_EditMap_CloseProject00);
   tolua_function(tolua_S,"GetProjectFilePath",tolua_PX2Editor_EditMap_GetProjectFilePath00);
   tolua_function(tolua_S,"NewScene",tolua_PX2Editor_EditMap_NewScene00);
   tolua_function(tolua_S,"LoadScene",tolua_PX2Editor_EditMap_LoadScene00);
   tolua_function(tolua_S,"SaveScene",tolua_PX2Editor_EditMap_SaveScene00);
   tolua_function(tolua_S,"SaveSceneAs",tolua_PX2Editor_EditMap_SaveSceneAs00);
   tolua_function(tolua_S,"CloseScene",tolua_PX2Editor_EditMap_CloseScene00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"SelectResData","SelectResData","",tolua_collect_SelectResData);
  #else
  tolua_cclass(tolua_S,"SelectResData","SelectResData","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"SelectResData");
   tolua_constant(tolua_S,"RT_NORMAL",SelectResData::RT_NORMAL);
   tolua_constant(tolua_S,"RT_TEXPACKELEMENT",SelectResData::RT_TEXPACKELEMENT);
   tolua_constant(tolua_S,"RT_MAX_TYPE",SelectResData::RT_MAX_TYPE);
   tolua_function(tolua_S,"new",tolua_PX2Editor_SelectResData_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2Editor_SelectResData_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2Editor_SelectResData_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2Editor_SelectResData_delete00);
   tolua_function(tolua_S,"GetSelectResType",tolua_PX2Editor_SelectResData_GetSelectResType00);
   tolua_variable(tolua_S,"ResPathname",tolua_get_SelectResData_ResPathname,tolua_set_SelectResData_ResPathname);
   tolua_variable(tolua_S,"TheObject",tolua_get_SelectResData_TheObject,tolua_set_SelectResData_TheObject);
   tolua_variable(tolua_S,"EleName",tolua_get_SelectResData_EleName,tolua_set_SelectResData_EleName);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_PX2Editor (lua_State* tolua_S) {
 return tolua_PX2Editor_open(tolua_S);
};
#endif

