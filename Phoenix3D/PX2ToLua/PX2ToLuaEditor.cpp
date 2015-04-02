/*
** Lua binding: PX2Editor
** Generated automatically by tolua++-1.0.92 on 04/02/15 16:09:34.
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
 tolua_usertype(tolua_S,"EffectableController");
 tolua_usertype(tolua_S,"CurveGroup");
 tolua_usertype(tolua_S,"Node");
 tolua_usertype(tolua_S,"PX2::ObjectPtr");
 tolua_usertype(tolua_S,"CurveCtrl");
 tolua_usertype(tolua_S,"E_MainFrame");
 tolua_usertype(tolua_S,"wxFrame");
 tolua_usertype(tolua_S,"Singleton<NirMan>");
 tolua_usertype(tolua_S,"PX2::UICurveGroup");
 tolua_usertype(tolua_S,"wxMenu");
 tolua_usertype(tolua_S,"APoint");
 tolua_usertype(tolua_S,"Curve");
 tolua_usertype(tolua_S,"GeoObjFactory");
 tolua_usertype(tolua_S,"PX2::Object");
 tolua_usertype(tolua_S,"Float2");
 tolua_usertype(tolua_S,"PX2::Polysegment");
 tolua_usertype(tolua_S,"PX2::Movable");
 tolua_usertype(tolua_S,"Edit");
 tolua_usertype(tolua_S,"RenderStep");
 tolua_usertype(tolua_S,"wxMenuItem");
 tolua_usertype(tolua_S,"PX2wxAuiToolBar");
 tolua_usertype(tolua_S,"SelectResData");
 tolua_usertype(tolua_S,"std::vector<std::string>");
 tolua_usertype(tolua_S,"EditMap");
 tolua_usertype(tolua_S,"wxAuiManager");
 tolua_usertype(tolua_S,"Object");
 tolua_usertype(tolua_S,"TimeLineEdit");
 tolua_usertype(tolua_S,"NirMan");
 tolua_usertype(tolua_S,"EditParams");
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

/* method: OnExit of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnExit00
static int tolua_PX2Editor_E_MainFrame_OnExit00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnExit'", NULL);
#endif
  {
   self->OnExit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnExit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnImport of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnImport00
static int tolua_PX2Editor_E_MainFrame_OnImport00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnImport'", NULL);
#endif
  {
   self->OnImport();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnImport'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnExport of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnExport00
static int tolua_PX2Editor_E_MainFrame_OnExport00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnExport'", NULL);
#endif
  {
   self->OnExport();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnExport'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnShowWindow of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnShowWindow00
static int tolua_PX2Editor_E_MainFrame_OnShowWindow00(lua_State* tolua_S)
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
  const std::string tag = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnShowWindow'", NULL);
#endif
  {
   self->OnShowWindow(tag);
   tolua_pushcppstring(tolua_S,(const char*)tag);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnShowWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnEditorSimulate of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnEditorSimulate00
static int tolua_PX2Editor_E_MainFrame_OnEditorSimulate00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnEditorSimulate'", NULL);
#endif
  {
   self->OnEditorSimulate();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnEditorSimulate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnEditorPlay of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnEditorPlay00
static int tolua_PX2Editor_E_MainFrame_OnEditorPlay00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnEditorPlay'", NULL);
#endif
  {
   self->OnEditorPlay();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnEditorPlay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnEditorStop of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnEditorStop00
static int tolua_PX2Editor_E_MainFrame_OnEditorStop00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnEditorStop'", NULL);
#endif
  {
   self->OnEditorStop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnEditorStop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnPlay of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnPlay00
static int tolua_PX2Editor_E_MainFrame_OnPlay00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnPlay'", NULL);
#endif
  {
   self->OnPlay();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnPlay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnPlayConfig of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnPlayConfig00
static int tolua_PX2Editor_E_MainFrame_OnPlayConfig00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnPlayConfig'", NULL);
#endif
  {
   self->OnPlayConfig();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnPlayConfig'.",&tolua_err);
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

/* method: OnCreateTerrain of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnCreateTerrain00
static int tolua_PX2Editor_E_MainFrame_OnCreateTerrain00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnCreateTerrain'", NULL);
#endif
  {
   self->OnCreateTerrain();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnCreateTerrain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnCreateTerrainPange of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnCreateTerrainPange00
static int tolua_PX2Editor_E_MainFrame_OnCreateTerrainPange00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnCreateTerrainPange'", NULL);
#endif
  {
   self->OnCreateTerrainPange();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnCreateTerrainPange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InspChangeWindow of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_InspChangeWindow00
static int tolua_PX2Editor_E_MainFrame_InspChangeWindow00(lua_State* tolua_S)
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
  int windowType = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InspChangeWindow'", NULL);
#endif
  {
   self->InspChangeWindow(windowType);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InspChangeWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnResRefresh of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnResRefresh00
static int tolua_PX2Editor_E_MainFrame_OnResRefresh00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnResRefresh'", NULL);
#endif
  {
   self->OnResRefresh();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnResRefresh'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnResClear of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnResClear00
static int tolua_PX2Editor_E_MainFrame_OnResClear00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnResClear'", NULL);
#endif
  {
   self->OnResClear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnResClear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnResOpen of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnResOpen00
static int tolua_PX2Editor_E_MainFrame_OnResOpen00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnResOpen'", NULL);
#endif
  {
   self->OnResOpen();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnResOpen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnResCopyResPath of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnResCopyResPath00
static int tolua_PX2Editor_E_MainFrame_OnResCopyResPath00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnResCopyResPath'", NULL);
#endif
  {
   self->OnResCopyResPath();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnResCopyResPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: TimeLine_UIGroup_Delete of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_TimeLine_UIGroup_Delete00
static int tolua_PX2Editor_E_MainFrame_TimeLine_UIGroup_Delete00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'TimeLine_UIGroup_Delete'", NULL);
#endif
  {
   self->TimeLine_UIGroup_Delete();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TimeLine_UIGroup_Delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: TimeLine_UIGroup_DeleteAll of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_TimeLine_UIGroup_DeleteAll00
static int tolua_PX2Editor_E_MainFrame_TimeLine_UIGroup_DeleteAll00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'TimeLine_UIGroup_DeleteAll'", NULL);
#endif
  {
   self->TimeLine_UIGroup_DeleteAll();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TimeLine_UIGroup_DeleteAll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: TimeLine_SelectCtrl_InValue of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_TimeLine_SelectCtrl_InValue00
static int tolua_PX2Editor_E_MainFrame_TimeLine_SelectCtrl_InValue00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'TimeLine_SelectCtrl_InValue'", NULL);
#endif
  {
   self->TimeLine_SelectCtrl_InValue();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TimeLine_SelectCtrl_InValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: TimeLine_SelectCtrl_OutValue of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_TimeLine_SelectCtrl_OutValue00
static int tolua_PX2Editor_E_MainFrame_TimeLine_SelectCtrl_OutValue00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'TimeLine_SelectCtrl_OutValue'", NULL);
#endif
  {
   self->TimeLine_SelectCtrl_OutValue();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TimeLine_SelectCtrl_OutValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: TimeLine_SelectCtrl_Delete of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_TimeLine_SelectCtrl_Delete00
static int tolua_PX2Editor_E_MainFrame_TimeLine_SelectCtrl_Delete00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'TimeLine_SelectCtrl_Delete'", NULL);
#endif
  {
   self->TimeLine_SelectCtrl_Delete();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TimeLine_SelectCtrl_Delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnProjectTreeShowLevel of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnProjectTreeShowLevel00
static int tolua_PX2Editor_E_MainFrame_OnProjectTreeShowLevel00(lua_State* tolua_S)
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
  int level = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnProjectTreeShowLevel'", NULL);
#endif
  {
   self->OnProjectTreeShowLevel(level);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnProjectTreeShowLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnProjectExpandSelect of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnProjectExpandSelect00
static int tolua_PX2Editor_E_MainFrame_OnProjectExpandSelect00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnProjectExpandSelect'", NULL);
#endif
  {
   self->OnProjectExpandSelect();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnProjectExpandSelect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnProjectCollapseSelect of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnProjectCollapseSelect00
static int tolua_PX2Editor_E_MainFrame_OnProjectCollapseSelect00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnProjectCollapseSelect'", NULL);
#endif
  {
   self->OnProjectCollapseSelect();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnProjectCollapseSelect'.",&tolua_err);
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

/* method: AddMenuItem of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddMenuItem01
static int tolua_PX2Editor_E_MainFrame_AddMenuItem01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wxMenu",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  wxMenu* menu = ((wxMenu*)  tolua_tousertype(tolua_S,2,0));
  const std::string title = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string script = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  const std::string tag = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddMenuItem'", NULL);
#endif
  {
   wxMenuItem* tolua_ret = (wxMenuItem*)  self->AddMenuItem(menu,title,script,tag);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wxMenuItem");
   tolua_pushcppstring(tolua_S,(const char*)title);
   tolua_pushcppstring(tolua_S,(const char*)script);
   tolua_pushcppstring(tolua_S,(const char*)tag);
  }
 }
 return 4;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_AddMenuItem00(tolua_S);
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

/* method: EnableMenusTag of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_EnableMenusTag00
static int tolua_PX2Editor_E_MainFrame_EnableMenusTag00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  const std::string tag = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  bool enable = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'EnableMenusTag'", NULL);
#endif
  {
   self->EnableMenusTag(tag,enable);
   tolua_pushcppstring(tolua_S,(const char*)tag);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EnableMenusTag'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAuiMananger of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_GetAuiMananger00
static int tolua_PX2Editor_E_MainFrame_GetAuiMananger00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAuiMananger'", NULL);
#endif
  {
   wxAuiManager* tolua_ret = (wxAuiManager*)  self->GetAuiMananger();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wxAuiManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAuiMananger'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddTool of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddTool00
static int tolua_PX2Editor_E_MainFrame_AddTool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2wxAuiToolBar",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  PX2wxAuiToolBar* toolBar = ((PX2wxAuiToolBar*)  tolua_tousertype(tolua_S,2,0));
  const std::string icon = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string script = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddTool'", NULL);
#endif
  {
   self->AddTool(toolBar,icon,script);
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

/* method: AddTool of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddTool01
static int tolua_PX2Editor_E_MainFrame_AddTool01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2wxAuiToolBar",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  PX2wxAuiToolBar* toolBar = ((PX2wxAuiToolBar*)  tolua_tousertype(tolua_S,2,0));
  const std::string icon = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string script = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  const std::string helpStr = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
  int type = ((int)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddTool'", NULL);
#endif
  {
   self->AddTool(toolBar,icon,script,helpStr,type);
   tolua_pushcppstring(tolua_S,(const char*)icon);
   tolua_pushcppstring(tolua_S,(const char*)script);
   tolua_pushcppstring(tolua_S,(const char*)helpStr);
  }
 }
 return 3;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_AddTool00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddToolChoose of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddToolChoose00
static int tolua_PX2Editor_E_MainFrame_AddToolChoose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2wxAuiToolBar",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  PX2wxAuiToolBar* toolBar = ((PX2wxAuiToolBar*)  tolua_tousertype(tolua_S,2,0));
  const std::string script = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string choose0 = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddToolChoose'", NULL);
#endif
  {
   self->AddToolChoose(toolBar,script,choose0);
   tolua_pushcppstring(tolua_S,(const char*)script);
   tolua_pushcppstring(tolua_S,(const char*)choose0);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddToolChoose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddToolChoose of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddToolChoose01
static int tolua_PX2Editor_E_MainFrame_AddToolChoose01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2wxAuiToolBar",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  PX2wxAuiToolBar* toolBar = ((PX2wxAuiToolBar*)  tolua_tousertype(tolua_S,2,0));
  const std::string script = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string choose0 = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  const std::string choose1 = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddToolChoose'", NULL);
#endif
  {
   self->AddToolChoose(toolBar,script,choose0,choose1);
   tolua_pushcppstring(tolua_S,(const char*)script);
   tolua_pushcppstring(tolua_S,(const char*)choose0);
   tolua_pushcppstring(tolua_S,(const char*)choose1);
  }
 }
 return 3;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_AddToolChoose00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddToolChoose of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddToolChoose02
static int tolua_PX2Editor_E_MainFrame_AddToolChoose02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2wxAuiToolBar",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  PX2wxAuiToolBar* toolBar = ((PX2wxAuiToolBar*)  tolua_tousertype(tolua_S,2,0));
  const std::string script = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string choose0 = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  const std::string choose1 = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
  const std::string choose2 = ((const std::string)  tolua_tocppstring(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddToolChoose'", NULL);
#endif
  {
   self->AddToolChoose(toolBar,script,choose0,choose1,choose2);
   tolua_pushcppstring(tolua_S,(const char*)script);
   tolua_pushcppstring(tolua_S,(const char*)choose0);
   tolua_pushcppstring(tolua_S,(const char*)choose1);
   tolua_pushcppstring(tolua_S,(const char*)choose2);
  }
 }
 return 4;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_AddToolChoose01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddToolChoose of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddToolChoose03
static int tolua_PX2Editor_E_MainFrame_AddToolChoose03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2wxAuiToolBar",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,6,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  PX2wxAuiToolBar* toolBar = ((PX2wxAuiToolBar*)  tolua_tousertype(tolua_S,2,0));
  const std::string script = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string choose0 = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  const std::string choose1 = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
  const std::string choose2 = ((const std::string)  tolua_tocppstring(tolua_S,6,0));
  const std::string choose3 = ((const std::string)  tolua_tocppstring(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddToolChoose'", NULL);
#endif
  {
   self->AddToolChoose(toolBar,script,choose0,choose1,choose2,choose3);
   tolua_pushcppstring(tolua_S,(const char*)script);
   tolua_pushcppstring(tolua_S,(const char*)choose0);
   tolua_pushcppstring(tolua_S,(const char*)choose1);
   tolua_pushcppstring(tolua_S,(const char*)choose2);
   tolua_pushcppstring(tolua_S,(const char*)choose3);
  }
 }
 return 5;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_AddToolChoose02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddToolChoose of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddToolChoose04
static int tolua_PX2Editor_E_MainFrame_AddToolChoose04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2wxAuiToolBar",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,6,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,7,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,8,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  PX2wxAuiToolBar* toolBar = ((PX2wxAuiToolBar*)  tolua_tousertype(tolua_S,2,0));
  const std::string script = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string choose0 = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  const std::string choose1 = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
  const std::string choose2 = ((const std::string)  tolua_tocppstring(tolua_S,6,0));
  const std::string choose3 = ((const std::string)  tolua_tocppstring(tolua_S,7,0));
  const std::string choose4 = ((const std::string)  tolua_tocppstring(tolua_S,8,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddToolChoose'", NULL);
#endif
  {
   self->AddToolChoose(toolBar,script,choose0,choose1,choose2,choose3,choose4);
   tolua_pushcppstring(tolua_S,(const char*)script);
   tolua_pushcppstring(tolua_S,(const char*)choose0);
   tolua_pushcppstring(tolua_S,(const char*)choose1);
   tolua_pushcppstring(tolua_S,(const char*)choose2);
   tolua_pushcppstring(tolua_S,(const char*)choose3);
   tolua_pushcppstring(tolua_S,(const char*)choose4);
  }
 }
 return 6;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_AddToolChoose03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddToolSeparater of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddToolSeparater00
static int tolua_PX2Editor_E_MainFrame_AddToolSeparater00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2wxAuiToolBar",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  PX2wxAuiToolBar* toolBar = ((PX2wxAuiToolBar*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddToolSeparater'", NULL);
#endif
  {
   self->AddToolSeparater(toolBar);
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

/* method: AddToolStretch of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddToolStretch00
static int tolua_PX2Editor_E_MainFrame_AddToolStretch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2wxAuiToolBar",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  PX2wxAuiToolBar* toolBar = ((PX2wxAuiToolBar*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddToolStretch'", NULL);
#endif
  {
   self->AddToolStretch(toolBar);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddToolStretch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnNewProject of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnNewProject01
static int tolua_PX2Editor_E_MainFrame_OnNewProject01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
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
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnNewProject00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnOpenProject of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnOpenProject01
static int tolua_PX2Editor_E_MainFrame_OnOpenProject01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
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
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnOpenProject00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnSaveProject of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnSaveProject01
static int tolua_PX2Editor_E_MainFrame_OnSaveProject01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
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
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnSaveProject00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnSaveProjectAs of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnSaveProjectAs01
static int tolua_PX2Editor_E_MainFrame_OnSaveProjectAs01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
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
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnSaveProjectAs00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnCloseProject of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnCloseProject01
static int tolua_PX2Editor_E_MainFrame_OnCloseProject01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
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
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnCloseProject00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnNewScene of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnNewScene01
static int tolua_PX2Editor_E_MainFrame_OnNewScene01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
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
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnNewScene00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnOpenScene of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnOpenScene01
static int tolua_PX2Editor_E_MainFrame_OnOpenScene01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
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
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnOpenScene00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnSaveScene of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnSaveScene01
static int tolua_PX2Editor_E_MainFrame_OnSaveScene01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
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
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnSaveScene00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnSaveSceneAs of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnSaveSceneAs01
static int tolua_PX2Editor_E_MainFrame_OnSaveSceneAs01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
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
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnSaveSceneAs00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnCloseScene of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnCloseScene01
static int tolua_PX2Editor_E_MainFrame_OnCloseScene01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
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
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnCloseScene00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnExit of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnExit01
static int tolua_PX2Editor_E_MainFrame_OnExit01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnExit'", NULL);
#endif
  {
   self->OnExit();
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnExit00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnImport of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnImport01
static int tolua_PX2Editor_E_MainFrame_OnImport01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnImport'", NULL);
#endif
  {
   self->OnImport();
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnImport00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnExport of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnExport01
static int tolua_PX2Editor_E_MainFrame_OnExport01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnExport'", NULL);
#endif
  {
   self->OnExport();
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnExport00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnShowWindow of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnShowWindow01
static int tolua_PX2Editor_E_MainFrame_OnShowWindow01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  const std::string tag = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnShowWindow'", NULL);
#endif
  {
   self->OnShowWindow(tag);
   tolua_pushcppstring(tolua_S,(const char*)tag);
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnShowWindow00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnEditorSimulate of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnEditorSimulate01
static int tolua_PX2Editor_E_MainFrame_OnEditorSimulate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnEditorSimulate'", NULL);
#endif
  {
   self->OnEditorSimulate();
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnEditorSimulate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnEditorPlay of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnEditorPlay01
static int tolua_PX2Editor_E_MainFrame_OnEditorPlay01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnEditorPlay'", NULL);
#endif
  {
   self->OnEditorPlay();
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnEditorPlay00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnEditorStop of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnEditorStop01
static int tolua_PX2Editor_E_MainFrame_OnEditorStop01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnEditorStop'", NULL);
#endif
  {
   self->OnEditorStop();
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnEditorStop00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnPlay of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnPlay01
static int tolua_PX2Editor_E_MainFrame_OnPlay01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnPlay'", NULL);
#endif
  {
   self->OnPlay();
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnPlay00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnPlayConfig of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnPlayConfig01
static int tolua_PX2Editor_E_MainFrame_OnPlayConfig01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnPlayConfig'", NULL);
#endif
  {
   self->OnPlayConfig();
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnPlayConfig00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnSetEditMode of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnSetEditMode01
static int tolua_PX2Editor_E_MainFrame_OnSetEditMode01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
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
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnSetEditMode00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnSetting of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnSetting01
static int tolua_PX2Editor_E_MainFrame_OnSetting01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
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
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnSetting00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnCreateTerrain of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnCreateTerrain01
static int tolua_PX2Editor_E_MainFrame_OnCreateTerrain01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnCreateTerrain'", NULL);
#endif
  {
   self->OnCreateTerrain();
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnCreateTerrain00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnCreateTerrainPange of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnCreateTerrainPange01
static int tolua_PX2Editor_E_MainFrame_OnCreateTerrainPange01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnCreateTerrainPange'", NULL);
#endif
  {
   self->OnCreateTerrainPange();
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnCreateTerrainPange00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: InspChangeWindow of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_InspChangeWindow01
static int tolua_PX2Editor_E_MainFrame_InspChangeWindow01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  int windowType = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InspChangeWindow'", NULL);
#endif
  {
   self->InspChangeWindow(windowType);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_InspChangeWindow00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnResRefresh of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnResRefresh01
static int tolua_PX2Editor_E_MainFrame_OnResRefresh01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnResRefresh'", NULL);
#endif
  {
   self->OnResRefresh();
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnResRefresh00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnResClear of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnResClear01
static int tolua_PX2Editor_E_MainFrame_OnResClear01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnResClear'", NULL);
#endif
  {
   self->OnResClear();
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnResClear00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnResOpen of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnResOpen01
static int tolua_PX2Editor_E_MainFrame_OnResOpen01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnResOpen'", NULL);
#endif
  {
   self->OnResOpen();
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnResOpen00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnResCopyResPath of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnResCopyResPath01
static int tolua_PX2Editor_E_MainFrame_OnResCopyResPath01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnResCopyResPath'", NULL);
#endif
  {
   self->OnResCopyResPath();
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnResCopyResPath00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: TimeLine_UIGroup_Delete of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_TimeLine_UIGroup_Delete01
static int tolua_PX2Editor_E_MainFrame_TimeLine_UIGroup_Delete01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'TimeLine_UIGroup_Delete'", NULL);
#endif
  {
   self->TimeLine_UIGroup_Delete();
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_TimeLine_UIGroup_Delete00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: TimeLine_UIGroup_DeleteAll of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_TimeLine_UIGroup_DeleteAll01
static int tolua_PX2Editor_E_MainFrame_TimeLine_UIGroup_DeleteAll01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'TimeLine_UIGroup_DeleteAll'", NULL);
#endif
  {
   self->TimeLine_UIGroup_DeleteAll();
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_TimeLine_UIGroup_DeleteAll00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: TimeLine_SelectCtrl_InValue of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_TimeLine_SelectCtrl_InValue01
static int tolua_PX2Editor_E_MainFrame_TimeLine_SelectCtrl_InValue01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'TimeLine_SelectCtrl_InValue'", NULL);
#endif
  {
   self->TimeLine_SelectCtrl_InValue();
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_TimeLine_SelectCtrl_InValue00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: TimeLine_SelectCtrl_OutValue of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_TimeLine_SelectCtrl_OutValue01
static int tolua_PX2Editor_E_MainFrame_TimeLine_SelectCtrl_OutValue01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'TimeLine_SelectCtrl_OutValue'", NULL);
#endif
  {
   self->TimeLine_SelectCtrl_OutValue();
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_TimeLine_SelectCtrl_OutValue00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: TimeLine_SelectCtrl_Delete of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_TimeLine_SelectCtrl_Delete01
static int tolua_PX2Editor_E_MainFrame_TimeLine_SelectCtrl_Delete01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'TimeLine_SelectCtrl_Delete'", NULL);
#endif
  {
   self->TimeLine_SelectCtrl_Delete();
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_TimeLine_SelectCtrl_Delete00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnProjectTreeShowLevel of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnProjectTreeShowLevel01
static int tolua_PX2Editor_E_MainFrame_OnProjectTreeShowLevel01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  int level = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnProjectTreeShowLevel'", NULL);
#endif
  {
   self->OnProjectTreeShowLevel(level);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnProjectTreeShowLevel00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnProjectExpandSelect of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnProjectExpandSelect01
static int tolua_PX2Editor_E_MainFrame_OnProjectExpandSelect01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnProjectExpandSelect'", NULL);
#endif
  {
   self->OnProjectExpandSelect();
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnProjectExpandSelect00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnProjectCollapseSelect of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_OnProjectCollapseSelect01
static int tolua_PX2Editor_E_MainFrame_OnProjectCollapseSelect01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnProjectCollapseSelect'", NULL);
#endif
  {
   self->OnProjectCollapseSelect();
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_OnProjectCollapseSelect00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddMainMenuItem of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddMainMenuItem01
static int tolua_PX2Editor_E_MainFrame_AddMainMenuItem01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
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
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_AddMainMenuItem00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddMenuItem of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddMenuItem02
static int tolua_PX2Editor_E_MainFrame_AddMenuItem02(lua_State* tolua_S)
{
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
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_AddMenuItem01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddMenuItem of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddMenuItem03
static int tolua_PX2Editor_E_MainFrame_AddMenuItem03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wxMenu",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  wxMenu* menu = ((wxMenu*)  tolua_tousertype(tolua_S,2,0));
  const std::string title = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string script = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  const std::string tag = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddMenuItem'", NULL);
#endif
  {
   wxMenuItem* tolua_ret = (wxMenuItem*)  self->AddMenuItem(menu,title,script,tag);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wxMenuItem");
   tolua_pushcppstring(tolua_S,(const char*)title);
   tolua_pushcppstring(tolua_S,(const char*)script);
   tolua_pushcppstring(tolua_S,(const char*)tag);
  }
 }
 return 4;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_AddMenuItem02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddSeparater of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddSeparater01
static int tolua_PX2Editor_E_MainFrame_AddSeparater01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wxMenu",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
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
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_AddSeparater00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: EnableMenusTag of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_EnableMenusTag01
static int tolua_PX2Editor_E_MainFrame_EnableMenusTag01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  const std::string tag = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  bool enable = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'EnableMenusTag'", NULL);
#endif
  {
   self->EnableMenusTag(tag,enable);
   tolua_pushcppstring(tolua_S,(const char*)tag);
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_EnableMenusTag00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAuiMananger of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_GetAuiMananger01
static int tolua_PX2Editor_E_MainFrame_GetAuiMananger01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAuiMananger'", NULL);
#endif
  {
   wxAuiManager* tolua_ret = (wxAuiManager*)  self->GetAuiMananger();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"wxAuiManager");
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_GetAuiMananger00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddTool of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddTool02
static int tolua_PX2Editor_E_MainFrame_AddTool02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2wxAuiToolBar",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  PX2wxAuiToolBar* toolBar = ((PX2wxAuiToolBar*)  tolua_tousertype(tolua_S,2,0));
  const std::string icon = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string script = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddTool'", NULL);
#endif
  {
   self->AddTool(toolBar,icon,script);
   tolua_pushcppstring(tolua_S,(const char*)icon);
   tolua_pushcppstring(tolua_S,(const char*)script);
  }
 }
 return 2;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_AddTool01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddTool of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddTool03
static int tolua_PX2Editor_E_MainFrame_AddTool03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2wxAuiToolBar",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  PX2wxAuiToolBar* toolBar = ((PX2wxAuiToolBar*)  tolua_tousertype(tolua_S,2,0));
  const std::string icon = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string script = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  const std::string helpStr = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
  int type = ((int)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddTool'", NULL);
#endif
  {
   self->AddTool(toolBar,icon,script,helpStr,type);
   tolua_pushcppstring(tolua_S,(const char*)icon);
   tolua_pushcppstring(tolua_S,(const char*)script);
   tolua_pushcppstring(tolua_S,(const char*)helpStr);
  }
 }
 return 3;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_AddTool02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddToolChoose of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddToolChoose05
static int tolua_PX2Editor_E_MainFrame_AddToolChoose05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2wxAuiToolBar",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  PX2wxAuiToolBar* toolBar = ((PX2wxAuiToolBar*)  tolua_tousertype(tolua_S,2,0));
  const std::string script = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string choose0 = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddToolChoose'", NULL);
#endif
  {
   self->AddToolChoose(toolBar,script,choose0);
   tolua_pushcppstring(tolua_S,(const char*)script);
   tolua_pushcppstring(tolua_S,(const char*)choose0);
  }
 }
 return 2;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_AddToolChoose04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddToolChoose of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddToolChoose06
static int tolua_PX2Editor_E_MainFrame_AddToolChoose06(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2wxAuiToolBar",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  PX2wxAuiToolBar* toolBar = ((PX2wxAuiToolBar*)  tolua_tousertype(tolua_S,2,0));
  const std::string script = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string choose0 = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  const std::string choose1 = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddToolChoose'", NULL);
#endif
  {
   self->AddToolChoose(toolBar,script,choose0,choose1);
   tolua_pushcppstring(tolua_S,(const char*)script);
   tolua_pushcppstring(tolua_S,(const char*)choose0);
   tolua_pushcppstring(tolua_S,(const char*)choose1);
  }
 }
 return 3;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_AddToolChoose05(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddToolChoose of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddToolChoose07
static int tolua_PX2Editor_E_MainFrame_AddToolChoose07(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2wxAuiToolBar",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  PX2wxAuiToolBar* toolBar = ((PX2wxAuiToolBar*)  tolua_tousertype(tolua_S,2,0));
  const std::string script = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string choose0 = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  const std::string choose1 = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
  const std::string choose2 = ((const std::string)  tolua_tocppstring(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddToolChoose'", NULL);
#endif
  {
   self->AddToolChoose(toolBar,script,choose0,choose1,choose2);
   tolua_pushcppstring(tolua_S,(const char*)script);
   tolua_pushcppstring(tolua_S,(const char*)choose0);
   tolua_pushcppstring(tolua_S,(const char*)choose1);
   tolua_pushcppstring(tolua_S,(const char*)choose2);
  }
 }
 return 4;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_AddToolChoose06(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddToolChoose of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddToolChoose08
static int tolua_PX2Editor_E_MainFrame_AddToolChoose08(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2wxAuiToolBar",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,6,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  PX2wxAuiToolBar* toolBar = ((PX2wxAuiToolBar*)  tolua_tousertype(tolua_S,2,0));
  const std::string script = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string choose0 = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  const std::string choose1 = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
  const std::string choose2 = ((const std::string)  tolua_tocppstring(tolua_S,6,0));
  const std::string choose3 = ((const std::string)  tolua_tocppstring(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddToolChoose'", NULL);
#endif
  {
   self->AddToolChoose(toolBar,script,choose0,choose1,choose2,choose3);
   tolua_pushcppstring(tolua_S,(const char*)script);
   tolua_pushcppstring(tolua_S,(const char*)choose0);
   tolua_pushcppstring(tolua_S,(const char*)choose1);
   tolua_pushcppstring(tolua_S,(const char*)choose2);
   tolua_pushcppstring(tolua_S,(const char*)choose3);
  }
 }
 return 5;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_AddToolChoose07(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddToolChoose of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddToolChoose09
static int tolua_PX2Editor_E_MainFrame_AddToolChoose09(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2wxAuiToolBar",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,6,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,7,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,8,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  PX2wxAuiToolBar* toolBar = ((PX2wxAuiToolBar*)  tolua_tousertype(tolua_S,2,0));
  const std::string script = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string choose0 = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  const std::string choose1 = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
  const std::string choose2 = ((const std::string)  tolua_tocppstring(tolua_S,6,0));
  const std::string choose3 = ((const std::string)  tolua_tocppstring(tolua_S,7,0));
  const std::string choose4 = ((const std::string)  tolua_tocppstring(tolua_S,8,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddToolChoose'", NULL);
#endif
  {
   self->AddToolChoose(toolBar,script,choose0,choose1,choose2,choose3,choose4);
   tolua_pushcppstring(tolua_S,(const char*)script);
   tolua_pushcppstring(tolua_S,(const char*)choose0);
   tolua_pushcppstring(tolua_S,(const char*)choose1);
   tolua_pushcppstring(tolua_S,(const char*)choose2);
   tolua_pushcppstring(tolua_S,(const char*)choose3);
   tolua_pushcppstring(tolua_S,(const char*)choose4);
  }
 }
 return 6;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_AddToolChoose08(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddToolSeparater of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddToolSeparater01
static int tolua_PX2Editor_E_MainFrame_AddToolSeparater01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2wxAuiToolBar",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  PX2wxAuiToolBar* toolBar = ((PX2wxAuiToolBar*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddToolSeparater'", NULL);
#endif
  {
   self->AddToolSeparater(toolBar);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_AddToolSeparater00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddToolStretch of class  E_MainFrame */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_E_MainFrame_AddToolStretch01
static int tolua_PX2Editor_E_MainFrame_AddToolStretch01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"E_MainFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2wxAuiToolBar",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  E_MainFrame* self = (E_MainFrame*)  tolua_tousertype(tolua_S,1,0);
  PX2wxAuiToolBar* toolBar = ((PX2wxAuiToolBar*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddToolStretch'", NULL);
#endif
  {
   self->AddToolStretch(toolBar);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2Editor_E_MainFrame_AddToolStretch00(tolua_S);
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

/* method: RefreshEffectableControllerModules of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_RefreshEffectableControllerModules00
static int tolua_PX2Editor_NirMan_RefreshEffectableControllerModules00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NirMan",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"wxMenu",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"EffectableController",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NirMan* self = (NirMan*)  tolua_tousertype(tolua_S,1,0);
  wxMenu* menu = ((wxMenu*)  tolua_tousertype(tolua_S,2,0));
  EffectableController* eftCtrl = ((EffectableController*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RefreshEffectableControllerModules'", NULL);
#endif
  {
   self->RefreshEffectableControllerModules(menu,eftCtrl);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RefreshEffectableControllerModules'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateEffectableControllerModule of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_CreateEffectableControllerModule00
static int tolua_PX2Editor_NirMan_CreateEffectableControllerModule00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NirMan",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NirMan* self = (NirMan*)  tolua_tousertype(tolua_S,1,0);
  const std::string typeStr = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateEffectableControllerModule'", NULL);
#endif
  {
   self->CreateEffectableControllerModule(typeStr);
   tolua_pushcppstring(tolua_S,(const char*)typeStr);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateEffectableControllerModule'.",&tolua_err);
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

/* method: AddTool of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_AddTool01
static int tolua_PX2Editor_NirMan_AddTool01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NirMan",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NirMan* self = (NirMan*)  tolua_tousertype(tolua_S,1,0);
  const std::string icon = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string script = ((std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string helpStr = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  int type = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddTool'", NULL);
#endif
  {
   self->AddTool(icon,script,helpStr,type);
   tolua_pushcppstring(tolua_S,(const char*)icon);
   tolua_pushcppstring(tolua_S,(const char*)script);
   tolua_pushcppstring(tolua_S,(const char*)helpStr);
  }
 }
 return 3;
tolua_lerror:
 return tolua_PX2Editor_NirMan_AddTool00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddToolChoose of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_AddToolChoose00
static int tolua_PX2Editor_NirMan_AddToolChoose00(lua_State* tolua_S)
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
  const std::string script = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string choose0 = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddToolChoose'", NULL);
#endif
  {
   self->AddToolChoose(script,choose0);
   tolua_pushcppstring(tolua_S,(const char*)script);
   tolua_pushcppstring(tolua_S,(const char*)choose0);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddToolChoose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddToolChoose of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_AddToolChoose01
static int tolua_PX2Editor_NirMan_AddToolChoose01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NirMan",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NirMan* self = (NirMan*)  tolua_tousertype(tolua_S,1,0);
  const std::string script = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string choose0 = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string choose1 = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddToolChoose'", NULL);
#endif
  {
   self->AddToolChoose(script,choose0,choose1);
   tolua_pushcppstring(tolua_S,(const char*)script);
   tolua_pushcppstring(tolua_S,(const char*)choose0);
   tolua_pushcppstring(tolua_S,(const char*)choose1);
  }
 }
 return 3;
tolua_lerror:
 return tolua_PX2Editor_NirMan_AddToolChoose00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddToolChoose of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_AddToolChoose02
static int tolua_PX2Editor_NirMan_AddToolChoose02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NirMan",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NirMan* self = (NirMan*)  tolua_tousertype(tolua_S,1,0);
  const std::string script = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string choose0 = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string choose1 = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  const std::string choose2 = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddToolChoose'", NULL);
#endif
  {
   self->AddToolChoose(script,choose0,choose1,choose2);
   tolua_pushcppstring(tolua_S,(const char*)script);
   tolua_pushcppstring(tolua_S,(const char*)choose0);
   tolua_pushcppstring(tolua_S,(const char*)choose1);
   tolua_pushcppstring(tolua_S,(const char*)choose2);
  }
 }
 return 4;
tolua_lerror:
 return tolua_PX2Editor_NirMan_AddToolChoose01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddToolChoose of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_AddToolChoose03
static int tolua_PX2Editor_NirMan_AddToolChoose03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NirMan",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NirMan* self = (NirMan*)  tolua_tousertype(tolua_S,1,0);
  const std::string script = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string choose0 = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string choose1 = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  const std::string choose2 = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
  const std::string choose3 = ((const std::string)  tolua_tocppstring(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddToolChoose'", NULL);
#endif
  {
   self->AddToolChoose(script,choose0,choose1,choose2,choose3);
   tolua_pushcppstring(tolua_S,(const char*)script);
   tolua_pushcppstring(tolua_S,(const char*)choose0);
   tolua_pushcppstring(tolua_S,(const char*)choose1);
   tolua_pushcppstring(tolua_S,(const char*)choose2);
   tolua_pushcppstring(tolua_S,(const char*)choose3);
  }
 }
 return 5;
tolua_lerror:
 return tolua_PX2Editor_NirMan_AddToolChoose02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddToolChoose of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_AddToolChoose04
static int tolua_PX2Editor_NirMan_AddToolChoose04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NirMan",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,6,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  NirMan* self = (NirMan*)  tolua_tousertype(tolua_S,1,0);
  const std::string script = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string choose0 = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string choose1 = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  const std::string choose2 = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
  const std::string choose3 = ((const std::string)  tolua_tocppstring(tolua_S,6,0));
  const std::string choose4 = ((const std::string)  tolua_tocppstring(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddToolChoose'", NULL);
#endif
  {
   self->AddToolChoose(script,choose0,choose1,choose2,choose3,choose4);
   tolua_pushcppstring(tolua_S,(const char*)script);
   tolua_pushcppstring(tolua_S,(const char*)choose0);
   tolua_pushcppstring(tolua_S,(const char*)choose1);
   tolua_pushcppstring(tolua_S,(const char*)choose2);
   tolua_pushcppstring(tolua_S,(const char*)choose3);
   tolua_pushcppstring(tolua_S,(const char*)choose4);
  }
 }
 return 6;
tolua_lerror:
 return tolua_PX2Editor_NirMan_AddToolChoose03(tolua_S);
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

/* method: AddToolStretch of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_AddToolStretch00
static int tolua_PX2Editor_NirMan_AddToolStretch00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddToolStretch'", NULL);
#endif
  {
   self->AddToolStretch();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddToolStretch'.",&tolua_err);
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

/* method: TaggleProjectShowHelpNode of class  NirMan */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_NirMan_TaggleProjectShowHelpNode00
static int tolua_PX2Editor_NirMan_TaggleProjectShowHelpNode00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'TaggleProjectShowHelpNode'", NULL);
#endif
  {
   self->TaggleProjectShowHelpNode();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TaggleProjectShowHelpNode'.",&tolua_err);
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
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NirMan* self = (NirMan*)  tolua_tousertype(tolua_S,1,0);
  const std::string caption = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string content = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  int type = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MessageBox'", NULL);
#endif
  {
   int tolua_ret = (int)  self->MessageBox(caption,content,type);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)caption);
   tolua_pushcppstring(tolua_S,(const char*)content);
  }
 }
 return 3;
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

/* method: SetEditAxisMode of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_SetEditAxisMode00
static int tolua_PX2Editor_Edit_SetEditAxisMode00(lua_State* tolua_S)
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
  Edit::EditAxisMode mode = ((Edit::EditAxisMode) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEditAxisMode'", NULL);
#endif
  {
   self->SetEditAxisMode(mode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEditAxisMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEdtiAxisMode of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_GetEdtiAxisMode00
static int tolua_PX2Editor_Edit_GetEdtiAxisMode00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEdtiAxisMode'", NULL);
#endif
  {
   Edit::EditAxisMode tolua_ret = (Edit::EditAxisMode)  self->GetEdtiAxisMode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEdtiAxisMode'.",&tolua_err);
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

/* method: OnFindSelectInProjTree of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_OnFindSelectInProjTree00
static int tolua_PX2Editor_Edit_OnFindSelectInProjTree00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnFindSelectInProjTree'", NULL);
#endif
  {
   self->OnFindSelectInProjTree();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnFindSelectInProjTree'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnFindSelectInResTree of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_OnFindSelectInResTree00
static int tolua_PX2Editor_Edit_OnFindSelectInResTree00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnFindSelectInResTree'", NULL);
#endif
  {
   self->OnFindSelectInResTree();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnFindSelectInResTree'.",&tolua_err);
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
     !tolua_isusertype(tolua_S,2,"Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Edit* self = (Edit*)  tolua_tousertype(tolua_S,1,0);
  Object* obj = ((Object*)  tolua_tousertype(tolua_S,2,0));
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
   Object* tolua_ret = (Object*)  self->GetCopyObject();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Object");
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

/* method: AnimPlay of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_AnimPlay00
static int tolua_PX2Editor_Edit_AnimPlay00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AnimPlay'", NULL);
#endif
  {
   self->AnimPlay();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AnimPlay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AnimResetPlay of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_AnimResetPlay00
static int tolua_PX2Editor_Edit_AnimResetPlay00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AnimResetPlay'", NULL);
#endif
  {
   self->AnimResetPlay();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AnimResetPlay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AnimStop of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_AnimStop00
static int tolua_PX2Editor_Edit_AnimStop00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AnimStop'", NULL);
#endif
  {
   self->AnimStop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AnimStop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AnimReset of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_AnimReset00
static int tolua_PX2Editor_Edit_AnimReset00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AnimReset'", NULL);
#endif
  {
   self->AnimReset();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AnimReset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsAnimPlaying of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_IsAnimPlaying00
static int tolua_PX2Editor_Edit_IsAnimPlaying00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsAnimPlaying'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsAnimPlaying();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsAnimPlaying'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AnimPlayStop of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_AnimPlayStop00
static int tolua_PX2Editor_Edit_AnimPlayStop00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AnimPlayStop'", NULL);
#endif
  {
   self->AnimPlayStop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AnimPlayStop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTimeLineEdit of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_GetTimeLineEdit00
static int tolua_PX2Editor_Edit_GetTimeLineEdit00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTimeLineEdit'", NULL);
#endif
  {
   TimeLineEdit* tolua_ret = (TimeLineEdit*)  self->GetTimeLineEdit();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TimeLineEdit");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTimeLineEdit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MakeSelectTimeLineEdit of class  Edit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_Edit_MakeSelectTimeLineEdit00
static int tolua_PX2Editor_Edit_MakeSelectTimeLineEdit00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MakeSelectTimeLineEdit'", NULL);
#endif
  {
   self->MakeSelectTimeLineEdit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MakeSelectTimeLineEdit'.",&tolua_err);
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
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EditMap* self = (EditMap*)  tolua_tousertype(tolua_S,1,0);
  const std::string pathname = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string projName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  int so = ((int)  tolua_tonumber(tolua_S,4,0));
  int width = ((int)  tolua_tonumber(tolua_S,5,0));
  int height = ((int)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NewProject'", NULL);
#endif
  {
   self->NewProject(pathname,projName,so,width,height);
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

/* method: SetTimeLineRenderStep_UIGroup of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_SetTimeLineRenderStep_UIGroup00
static int tolua_PX2Editor_TimeLineEdit_SetTimeLineRenderStep_UIGroup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RenderStep",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
  RenderStep* renderStep = ((RenderStep*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTimeLineRenderStep_UIGroup'", NULL);
#endif
  {
   self->SetTimeLineRenderStep_UIGroup(renderStep);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTimeLineRenderStep_UIGroup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTimeLineRenderStep_UIGroup of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_GetTimeLineRenderStep_UIGroup00
static int tolua_PX2Editor_TimeLineEdit_GetTimeLineRenderStep_UIGroup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TimeLineEdit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TimeLineEdit* self = (const TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTimeLineRenderStep_UIGroup'", NULL);
#endif
  {
   RenderStep* tolua_ret = (RenderStep*)  self->GetTimeLineRenderStep_UIGroup();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RenderStep");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTimeLineRenderStep_UIGroup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTimeLineRenderStep_Grid of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_SetTimeLineRenderStep_Grid00
static int tolua_PX2Editor_TimeLineEdit_SetTimeLineRenderStep_Grid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RenderStep",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
  RenderStep* renderStep = ((RenderStep*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTimeLineRenderStep_Grid'", NULL);
#endif
  {
   self->SetTimeLineRenderStep_Grid(renderStep);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTimeLineRenderStep_Grid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTimeLineRenderStep_Grid of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_GetTimeLineRenderStep_Grid00
static int tolua_PX2Editor_TimeLineEdit_GetTimeLineRenderStep_Grid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TimeLineEdit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TimeLineEdit* self = (const TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTimeLineRenderStep_Grid'", NULL);
#endif
  {
   RenderStep* tolua_ret = (RenderStep*)  self->GetTimeLineRenderStep_Grid();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RenderStep");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTimeLineRenderStep_Grid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCurveEditNode_Grid of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_GetCurveEditNode_Grid00
static int tolua_PX2Editor_TimeLineEdit_GetCurveEditNode_Grid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCurveEditNode_Grid'", NULL);
#endif
  {
   Node* tolua_ret = (Node*)  self->GetCurveEditNode_Grid();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCurveEditNode_Grid'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGridPoly of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_GetGridPoly00
static int tolua_PX2Editor_TimeLineEdit_GetGridPoly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGridPoly'", NULL);
#endif
  {
   PX2::Polysegment* tolua_ret = (PX2::Polysegment*)  self->GetGridPoly();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"PX2::Polysegment");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGridPoly'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCtrlsScale of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_SetCtrlsScale00
static int tolua_PX2Editor_TimeLineEdit_SetCtrlsScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Float2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
  const Float2* scale = ((const Float2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCtrlsScale'", NULL);
#endif
  {
   self->SetCtrlsScale(*scale);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCtrlsScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCtrlsScale of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_GetCtrlsScale00
static int tolua_PX2Editor_TimeLineEdit_GetCtrlsScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TimeLineEdit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TimeLineEdit* self = (const TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCtrlsScale'", NULL);
#endif
  {
   const Float2& tolua_ret = (const Float2&)  self->GetCtrlsScale();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Float2");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCtrlsScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInRange of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_GetInRange00
static int tolua_PX2Editor_TimeLineEdit_GetInRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
  float inMin = ((float)  tolua_tonumber(tolua_S,2,0));
  float inMax = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetInRange'", NULL);
#endif
  {
   self->GetInRange(inMin,inMax);
   tolua_pushnumber(tolua_S,(lua_Number)inMin);
   tolua_pushnumber(tolua_S,(lua_Number)inMax);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOutRange of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_GetOutRange00
static int tolua_PX2Editor_TimeLineEdit_GetOutRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
  float outMin = ((float)  tolua_tonumber(tolua_S,2,0));
  float outMax = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOutRange'", NULL);
#endif
  {
   self->GetOutRange(outMin,outMax);
   tolua_pushnumber(tolua_S,(lua_Number)outMin);
   tolua_pushnumber(tolua_S,(lua_Number)outMax);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOutRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateAddCurveGroup of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_CreateAddCurveGroup00
static int tolua_PX2Editor_TimeLineEdit_CreateAddCurveGroup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2::Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
  PX2::Object* obj = ((PX2::Object*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateAddCurveGroup'", NULL);
#endif
  {
   self->CreateAddCurveGroup(obj);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateAddCurveGroup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReCreateAddCurveGroup of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_ReCreateAddCurveGroup00
static int tolua_PX2Editor_TimeLineEdit_ReCreateAddCurveGroup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2::Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
  PX2::Object* obj = ((PX2::Object*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReCreateAddCurveGroup'", NULL);
#endif
  {
   self->ReCreateAddCurveGroup(obj);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReCreateAddCurveGroup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HasCurveGroup of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_HasCurveGroup00
static int tolua_PX2Editor_TimeLineEdit_HasCurveGroup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2::Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
  PX2::Object* obj = ((PX2::Object*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasCurveGroup'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->HasCurveGroup(obj);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasCurveGroup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveGroup of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_RemoveGroup00
static int tolua_PX2Editor_TimeLineEdit_RemoveGroup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2::Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
  PX2::Object* obj = ((PX2::Object*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveGroup'", NULL);
#endif
  {
   self->RemoveGroup(obj);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveGroup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCurveGroup of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_GetCurveGroup00
static int tolua_PX2Editor_TimeLineEdit_GetCurveGroup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2::Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
  PX2::Object* obj = ((PX2::Object*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCurveGroup'", NULL);
#endif
  {
   CurveGroup* tolua_ret = (CurveGroup*)  self->GetCurveGroup(obj);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CurveGroup");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCurveGroup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCurveGroup of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_GetCurveGroup01
static int tolua_PX2Editor_TimeLineEdit_GetCurveGroup01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Curve",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
  Curve* curve = ((Curve*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCurveGroup'", NULL);
#endif
  {
   CurveGroup* tolua_ret = (CurveGroup*)  self->GetCurveGroup(curve);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CurveGroup");
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2Editor_TimeLineEdit_GetCurveGroup00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UpdateCurve of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_UpdateCurve00
static int tolua_PX2Editor_TimeLineEdit_UpdateCurve00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2::Object",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
  PX2::Object* obj = ((PX2::Object*)  tolua_tousertype(tolua_S,2,0));
  bool addRemovePoint = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UpdateCurve'", NULL);
#endif
  {
   self->UpdateCurve(obj,addRemovePoint);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UpdateCurve'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearGroup of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_ClearGroup00
static int tolua_PX2Editor_TimeLineEdit_ClearGroup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2::UICurveGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
  PX2::UICurveGroup* uiGroup = ((PX2::UICurveGroup*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearGroup'", NULL);
#endif
  {
   self->ClearGroup(uiGroup);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearGroup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearAllGroups of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_ClearAllGroups00
static int tolua_PX2Editor_TimeLineEdit_ClearAllGroups00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearAllGroups'", NULL);
#endif
  {
   self->ClearAllGroups();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearAllGroups'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: HasCurve of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_HasCurve00
static int tolua_PX2Editor_TimeLineEdit_HasCurve00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Curve",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
  Curve* curve = ((Curve*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasCurve'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->HasCurve(curve);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasCurve'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddCurve of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_AddCurve00
static int tolua_PX2Editor_TimeLineEdit_AddCurve00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Curve",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
  Curve* curve = ((Curve*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddCurve'", NULL);
#endif
  {
   self->AddCurve(curve);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddCurve'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveCurve of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_RemoveCurve00
static int tolua_PX2Editor_TimeLineEdit_RemoveCurve00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Curve",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
  Curve* curve = ((Curve*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveCurve'", NULL);
#endif
  {
   self->RemoveCurve(curve);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveCurve'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumCurves of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_GetNumCurves00
static int tolua_PX2Editor_TimeLineEdit_GetNumCurves00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TimeLineEdit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TimeLineEdit* self = (const TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumCurves'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetNumCurves();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumCurves'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCurve of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_GetCurve00
static int tolua_PX2Editor_TimeLineEdit_GetCurve00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCurve'", NULL);
#endif
  {
   Curve* tolua_ret = (Curve*)  self->GetCurve(i);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Curve");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCurve'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetActiveCurve of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_SetActiveCurve00
static int tolua_PX2Editor_TimeLineEdit_SetActiveCurve00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Curve",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
  Curve* curve = ((Curve*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetActiveCurve'", NULL);
#endif
  {
   self->SetActiveCurve(curve);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetActiveCurve'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetActiveCurve of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_GetActiveCurve00
static int tolua_PX2Editor_TimeLineEdit_GetActiveCurve00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetActiveCurve'", NULL);
#endif
  {
   Curve* tolua_ret = (Curve*)  self->GetActiveCurve();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Curve");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetActiveCurve'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: TrySelectCurve of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_TrySelectCurve00
static int tolua_PX2Editor_TimeLineEdit_TrySelectCurve00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2::Movable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
  PX2::Movable* mov = ((PX2::Movable*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'TrySelectCurve'", NULL);
#endif
  {
   CurveCtrl* tolua_ret = (CurveCtrl*)  self->TrySelectCurve(mov);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CurveCtrl");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TrySelectCurve'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSelectedCurveCtrl of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_SetSelectedCurveCtrl00
static int tolua_PX2Editor_TimeLineEdit_SetSelectedCurveCtrl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CurveCtrl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
  CurveCtrl* ctrl = ((CurveCtrl*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSelectedCurveCtrl'", NULL);
#endif
  {
   self->SetSelectedCurveCtrl(ctrl);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSelectedCurveCtrl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSelectedCurveCtrl of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_GetSelectedCurveCtrl00
static int tolua_PX2Editor_TimeLineEdit_GetSelectedCurveCtrl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSelectedCurveCtrl'", NULL);
#endif
  {
   CurveCtrl* tolua_ret = (CurveCtrl*)  self->GetSelectedCurveCtrl();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CurveCtrl");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSelectedCurveCtrl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSelectedUICurveGroup of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_SetSelectedUICurveGroup00
static int tolua_PX2Editor_TimeLineEdit_SetSelectedUICurveGroup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2::UICurveGroup",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
  PX2::UICurveGroup* group = ((PX2::UICurveGroup*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSelectedUICurveGroup'", NULL);
#endif
  {
   self->SetSelectedUICurveGroup(group);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSelectedUICurveGroup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSelectedUICurveGroup of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_GetSelectedUICurveGroup00
static int tolua_PX2Editor_TimeLineEdit_GetSelectedUICurveGroup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSelectedUICurveGroup'", NULL);
#endif
  {
   PX2::UICurveGroup* tolua_ret = (PX2::UICurveGroup*)  self->GetSelectedUICurveGroup();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"PX2::UICurveGroup");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSelectedUICurveGroup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Fit_Hor of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_Fit_Hor00
static int tolua_PX2Editor_TimeLineEdit_Fit_Hor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Fit_Hor'", NULL);
#endif
  {
   self->Fit_Hor();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Fit_Hor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Fit_Ver of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_Fit_Ver00
static int tolua_PX2Editor_TimeLineEdit_Fit_Ver00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Fit_Ver'", NULL);
#endif
  {
   self->Fit_Ver();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Fit_Ver'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Fit_All of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_Fit_All00
static int tolua_PX2Editor_TimeLineEdit_Fit_All00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Fit_All'", NULL);
#endif
  {
   self->Fit_All();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Fit_All'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Fit_Selected of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_Fit_Selected00
static int tolua_PX2Editor_TimeLineEdit_Fit_Selected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Fit_Selected'", NULL);
#endif
  {
   self->Fit_Selected();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Fit_Selected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Pan of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_Pan00
static int tolua_PX2Editor_TimeLineEdit_Pan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Pan'", NULL);
#endif
  {
   self->Pan();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Pan'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Zoom of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_Zoom00
static int tolua_PX2Editor_TimeLineEdit_Zoom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Zoom'", NULL);
#endif
  {
   self->Zoom();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Zoom'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Auto of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_Auto00
static int tolua_PX2Editor_TimeLineEdit_Auto00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Auto'", NULL);
#endif
  {
   self->Auto();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Auto'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clamp of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_Clamp00
static int tolua_PX2Editor_TimeLineEdit_Clamp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clamp'", NULL);
#endif
  {
   self->Clamp();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clamp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: User of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_User00
static int tolua_PX2Editor_TimeLineEdit_User00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'User'", NULL);
#endif
  {
   self->User();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'User'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Break of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_Break00
static int tolua_PX2Editor_TimeLineEdit_Break00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Break'", NULL);
#endif
  {
   self->Break();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Break'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Linear of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_Linear00
static int tolua_PX2Editor_TimeLineEdit_Linear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Linear'", NULL);
#endif
  {
   self->Linear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Linear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Constant of class  TimeLineEdit */
#ifndef TOLUA_DISABLE_tolua_PX2Editor_TimeLineEdit_Constant00
static int tolua_PX2Editor_TimeLineEdit_Constant00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TimeLineEdit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TimeLineEdit* self = (TimeLineEdit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Constant'", NULL);
#endif
  {
   self->Constant();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Constant'.",&tolua_err);
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
   tolua_function(tolua_S,"OnExit",tolua_PX2Editor_E_MainFrame_OnExit00);
   tolua_function(tolua_S,"OnImport",tolua_PX2Editor_E_MainFrame_OnImport00);
   tolua_function(tolua_S,"OnExport",tolua_PX2Editor_E_MainFrame_OnExport00);
   tolua_function(tolua_S,"OnShowWindow",tolua_PX2Editor_E_MainFrame_OnShowWindow00);
   tolua_function(tolua_S,"OnEditorSimulate",tolua_PX2Editor_E_MainFrame_OnEditorSimulate00);
   tolua_function(tolua_S,"OnEditorPlay",tolua_PX2Editor_E_MainFrame_OnEditorPlay00);
   tolua_function(tolua_S,"OnEditorStop",tolua_PX2Editor_E_MainFrame_OnEditorStop00);
   tolua_function(tolua_S,"OnPlay",tolua_PX2Editor_E_MainFrame_OnPlay00);
   tolua_function(tolua_S,"OnPlayConfig",tolua_PX2Editor_E_MainFrame_OnPlayConfig00);
   tolua_function(tolua_S,"OnSetEditMode",tolua_PX2Editor_E_MainFrame_OnSetEditMode00);
   tolua_function(tolua_S,"OnSetting",tolua_PX2Editor_E_MainFrame_OnSetting00);
   tolua_function(tolua_S,"OnCreateTerrain",tolua_PX2Editor_E_MainFrame_OnCreateTerrain00);
   tolua_function(tolua_S,"OnCreateTerrainPange",tolua_PX2Editor_E_MainFrame_OnCreateTerrainPange00);
   tolua_function(tolua_S,"InspChangeWindow",tolua_PX2Editor_E_MainFrame_InspChangeWindow00);
   tolua_function(tolua_S,"OnResRefresh",tolua_PX2Editor_E_MainFrame_OnResRefresh00);
   tolua_function(tolua_S,"OnResClear",tolua_PX2Editor_E_MainFrame_OnResClear00);
   tolua_function(tolua_S,"OnResOpen",tolua_PX2Editor_E_MainFrame_OnResOpen00);
   tolua_function(tolua_S,"OnResCopyResPath",tolua_PX2Editor_E_MainFrame_OnResCopyResPath00);
   tolua_function(tolua_S,"TimeLine_UIGroup_Delete",tolua_PX2Editor_E_MainFrame_TimeLine_UIGroup_Delete00);
   tolua_function(tolua_S,"TimeLine_UIGroup_DeleteAll",tolua_PX2Editor_E_MainFrame_TimeLine_UIGroup_DeleteAll00);
   tolua_function(tolua_S,"TimeLine_SelectCtrl_InValue",tolua_PX2Editor_E_MainFrame_TimeLine_SelectCtrl_InValue00);
   tolua_function(tolua_S,"TimeLine_SelectCtrl_OutValue",tolua_PX2Editor_E_MainFrame_TimeLine_SelectCtrl_OutValue00);
   tolua_function(tolua_S,"TimeLine_SelectCtrl_Delete",tolua_PX2Editor_E_MainFrame_TimeLine_SelectCtrl_Delete00);
   tolua_function(tolua_S,"OnProjectTreeShowLevel",tolua_PX2Editor_E_MainFrame_OnProjectTreeShowLevel00);
   tolua_function(tolua_S,"OnProjectExpandSelect",tolua_PX2Editor_E_MainFrame_OnProjectExpandSelect00);
   tolua_function(tolua_S,"OnProjectCollapseSelect",tolua_PX2Editor_E_MainFrame_OnProjectCollapseSelect00);
   tolua_function(tolua_S,"AddMainMenuItem",tolua_PX2Editor_E_MainFrame_AddMainMenuItem00);
   tolua_function(tolua_S,"AddMenuItem",tolua_PX2Editor_E_MainFrame_AddMenuItem00);
   tolua_function(tolua_S,"AddMenuItem",tolua_PX2Editor_E_MainFrame_AddMenuItem01);
   tolua_function(tolua_S,"AddSeparater",tolua_PX2Editor_E_MainFrame_AddSeparater00);
   tolua_function(tolua_S,"EnableMenusTag",tolua_PX2Editor_E_MainFrame_EnableMenusTag00);
   tolua_function(tolua_S,"GetAuiMananger",tolua_PX2Editor_E_MainFrame_GetAuiMananger00);
   tolua_function(tolua_S,"AddTool",tolua_PX2Editor_E_MainFrame_AddTool00);
   tolua_function(tolua_S,"AddTool",tolua_PX2Editor_E_MainFrame_AddTool01);
   tolua_function(tolua_S,"AddToolChoose",tolua_PX2Editor_E_MainFrame_AddToolChoose00);
   tolua_function(tolua_S,"AddToolChoose",tolua_PX2Editor_E_MainFrame_AddToolChoose01);
   tolua_function(tolua_S,"AddToolChoose",tolua_PX2Editor_E_MainFrame_AddToolChoose02);
   tolua_function(tolua_S,"AddToolChoose",tolua_PX2Editor_E_MainFrame_AddToolChoose03);
   tolua_function(tolua_S,"AddToolChoose",tolua_PX2Editor_E_MainFrame_AddToolChoose04);
   tolua_function(tolua_S,"AddToolSeparater",tolua_PX2Editor_E_MainFrame_AddToolSeparater00);
   tolua_function(tolua_S,"AddToolStretch",tolua_PX2Editor_E_MainFrame_AddToolStretch00);
   tolua_function(tolua_S,"OnNewProject",tolua_PX2Editor_E_MainFrame_OnNewProject01);
   tolua_function(tolua_S,"OnOpenProject",tolua_PX2Editor_E_MainFrame_OnOpenProject01);
   tolua_function(tolua_S,"OnSaveProject",tolua_PX2Editor_E_MainFrame_OnSaveProject01);
   tolua_function(tolua_S,"OnSaveProjectAs",tolua_PX2Editor_E_MainFrame_OnSaveProjectAs01);
   tolua_function(tolua_S,"OnCloseProject",tolua_PX2Editor_E_MainFrame_OnCloseProject01);
   tolua_function(tolua_S,"OnNewScene",tolua_PX2Editor_E_MainFrame_OnNewScene01);
   tolua_function(tolua_S,"OnOpenScene",tolua_PX2Editor_E_MainFrame_OnOpenScene01);
   tolua_function(tolua_S,"OnSaveScene",tolua_PX2Editor_E_MainFrame_OnSaveScene01);
   tolua_function(tolua_S,"OnSaveSceneAs",tolua_PX2Editor_E_MainFrame_OnSaveSceneAs01);
   tolua_function(tolua_S,"OnCloseScene",tolua_PX2Editor_E_MainFrame_OnCloseScene01);
   tolua_function(tolua_S,"OnExit",tolua_PX2Editor_E_MainFrame_OnExit01);
   tolua_function(tolua_S,"OnImport",tolua_PX2Editor_E_MainFrame_OnImport01);
   tolua_function(tolua_S,"OnExport",tolua_PX2Editor_E_MainFrame_OnExport01);
   tolua_function(tolua_S,"OnShowWindow",tolua_PX2Editor_E_MainFrame_OnShowWindow01);
   tolua_function(tolua_S,"OnEditorSimulate",tolua_PX2Editor_E_MainFrame_OnEditorSimulate01);
   tolua_function(tolua_S,"OnEditorPlay",tolua_PX2Editor_E_MainFrame_OnEditorPlay01);
   tolua_function(tolua_S,"OnEditorStop",tolua_PX2Editor_E_MainFrame_OnEditorStop01);
   tolua_function(tolua_S,"OnPlay",tolua_PX2Editor_E_MainFrame_OnPlay01);
   tolua_function(tolua_S,"OnPlayConfig",tolua_PX2Editor_E_MainFrame_OnPlayConfig01);
   tolua_function(tolua_S,"OnSetEditMode",tolua_PX2Editor_E_MainFrame_OnSetEditMode01);
   tolua_function(tolua_S,"OnSetting",tolua_PX2Editor_E_MainFrame_OnSetting01);
   tolua_function(tolua_S,"OnCreateTerrain",tolua_PX2Editor_E_MainFrame_OnCreateTerrain01);
   tolua_function(tolua_S,"OnCreateTerrainPange",tolua_PX2Editor_E_MainFrame_OnCreateTerrainPange01);
   tolua_function(tolua_S,"InspChangeWindow",tolua_PX2Editor_E_MainFrame_InspChangeWindow01);
   tolua_function(tolua_S,"OnResRefresh",tolua_PX2Editor_E_MainFrame_OnResRefresh01);
   tolua_function(tolua_S,"OnResClear",tolua_PX2Editor_E_MainFrame_OnResClear01);
   tolua_function(tolua_S,"OnResOpen",tolua_PX2Editor_E_MainFrame_OnResOpen01);
   tolua_function(tolua_S,"OnResCopyResPath",tolua_PX2Editor_E_MainFrame_OnResCopyResPath01);
   tolua_function(tolua_S,"TimeLine_UIGroup_Delete",tolua_PX2Editor_E_MainFrame_TimeLine_UIGroup_Delete01);
   tolua_function(tolua_S,"TimeLine_UIGroup_DeleteAll",tolua_PX2Editor_E_MainFrame_TimeLine_UIGroup_DeleteAll01);
   tolua_function(tolua_S,"TimeLine_SelectCtrl_InValue",tolua_PX2Editor_E_MainFrame_TimeLine_SelectCtrl_InValue01);
   tolua_function(tolua_S,"TimeLine_SelectCtrl_OutValue",tolua_PX2Editor_E_MainFrame_TimeLine_SelectCtrl_OutValue01);
   tolua_function(tolua_S,"TimeLine_SelectCtrl_Delete",tolua_PX2Editor_E_MainFrame_TimeLine_SelectCtrl_Delete01);
   tolua_function(tolua_S,"OnProjectTreeShowLevel",tolua_PX2Editor_E_MainFrame_OnProjectTreeShowLevel01);
   tolua_function(tolua_S,"OnProjectExpandSelect",tolua_PX2Editor_E_MainFrame_OnProjectExpandSelect01);
   tolua_function(tolua_S,"OnProjectCollapseSelect",tolua_PX2Editor_E_MainFrame_OnProjectCollapseSelect01);
   tolua_function(tolua_S,"AddMainMenuItem",tolua_PX2Editor_E_MainFrame_AddMainMenuItem01);
   tolua_function(tolua_S,"AddMenuItem",tolua_PX2Editor_E_MainFrame_AddMenuItem02);
   tolua_function(tolua_S,"AddMenuItem",tolua_PX2Editor_E_MainFrame_AddMenuItem03);
   tolua_function(tolua_S,"AddSeparater",tolua_PX2Editor_E_MainFrame_AddSeparater01);
   tolua_function(tolua_S,"EnableMenusTag",tolua_PX2Editor_E_MainFrame_EnableMenusTag01);
   tolua_function(tolua_S,"GetAuiMananger",tolua_PX2Editor_E_MainFrame_GetAuiMananger01);
   tolua_function(tolua_S,"AddTool",tolua_PX2Editor_E_MainFrame_AddTool02);
   tolua_function(tolua_S,"AddTool",tolua_PX2Editor_E_MainFrame_AddTool03);
   tolua_function(tolua_S,"AddToolChoose",tolua_PX2Editor_E_MainFrame_AddToolChoose05);
   tolua_function(tolua_S,"AddToolChoose",tolua_PX2Editor_E_MainFrame_AddToolChoose06);
   tolua_function(tolua_S,"AddToolChoose",tolua_PX2Editor_E_MainFrame_AddToolChoose07);
   tolua_function(tolua_S,"AddToolChoose",tolua_PX2Editor_E_MainFrame_AddToolChoose08);
   tolua_function(tolua_S,"AddToolChoose",tolua_PX2Editor_E_MainFrame_AddToolChoose09);
   tolua_function(tolua_S,"AddToolSeparater",tolua_PX2Editor_E_MainFrame_AddToolSeparater01);
   tolua_function(tolua_S,"AddToolStretch",tolua_PX2Editor_E_MainFrame_AddToolStretch01);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"NirMan","NirMan","wxEvtHandler",NULL);
  tolua_beginmodule(tolua_S,"NirMan");
   tolua_function(tolua_S,"SetCurMenu",tolua_PX2Editor_NirMan_SetCurMenu00);
   tolua_function(tolua_S,"GetCurMenu",tolua_PX2Editor_NirMan_GetCurMenu00);
   tolua_function(tolua_S,"AddSubMenu",tolua_PX2Editor_NirMan_AddSubMenu00);
   tolua_function(tolua_S,"AddMenuItem",tolua_PX2Editor_NirMan_AddMenuItem00);
   tolua_function(tolua_S,"AddSeparater",tolua_PX2Editor_NirMan_AddSeparater00);
   tolua_function(tolua_S,"RefreshEffectableControllerModules",tolua_PX2Editor_NirMan_RefreshEffectableControllerModules00);
   tolua_function(tolua_S,"CreateEffectableControllerModule",tolua_PX2Editor_NirMan_CreateEffectableControllerModule00);
   tolua_function(tolua_S,"SetCurToolBar",tolua_PX2Editor_NirMan_SetCurToolBar00);
   tolua_function(tolua_S,"GetCurToolBar",tolua_PX2Editor_NirMan_GetCurToolBar00);
   tolua_function(tolua_S,"AddTool",tolua_PX2Editor_NirMan_AddTool00);
   tolua_function(tolua_S,"AddTool",tolua_PX2Editor_NirMan_AddTool01);
   tolua_function(tolua_S,"AddToolChoose",tolua_PX2Editor_NirMan_AddToolChoose00);
   tolua_function(tolua_S,"AddToolChoose",tolua_PX2Editor_NirMan_AddToolChoose01);
   tolua_function(tolua_S,"AddToolChoose",tolua_PX2Editor_NirMan_AddToolChoose02);
   tolua_function(tolua_S,"AddToolChoose",tolua_PX2Editor_NirMan_AddToolChoose03);
   tolua_function(tolua_S,"AddToolChoose",tolua_PX2Editor_NirMan_AddToolChoose04);
   tolua_function(tolua_S,"AddToolSeparater",tolua_PX2Editor_NirMan_AddToolSeparater00);
   tolua_function(tolua_S,"AddToolStretch",tolua_PX2Editor_NirMan_AddToolStretch00);
   tolua_function(tolua_S,"SetProjTreeLevel",tolua_PX2Editor_NirMan_SetProjTreeLevel00);
   tolua_function(tolua_S,"TaggleProjectShowHelpNode",tolua_PX2Editor_NirMan_TaggleProjectShowHelpNode00);
   tolua_function(tolua_S,"MessageBox",tolua_PX2Editor_NirMan_MessageBox00);
   tolua_variable(tolua_S,"__Singleton_NirMan___",tolua_get_NirMan___Singleton_NirMan___,NULL);
  tolua_endmodule(tolua_S);
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
   tolua_constant(tolua_S,"EAM_WORLD",Edit::EAM_WORLD);
   tolua_constant(tolua_S,"EAM_LOCAL",Edit::EAM_LOCAL);
   tolua_constant(tolua_S,"EAM_PARENT",Edit::EAM_PARENT);
   tolua_constant(tolua_S,"EMA_MAX_MODE",Edit::EMA_MAX_MODE);
   tolua_function(tolua_S,"SetEditAxisMode",tolua_PX2Editor_Edit_SetEditAxisMode00);
   tolua_function(tolua_S,"GetEdtiAxisMode",tolua_PX2Editor_Edit_GetEdtiAxisMode00);
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
   tolua_function(tolua_S,"OnFindSelectInProjTree",tolua_PX2Editor_Edit_OnFindSelectInProjTree00);
   tolua_function(tolua_S,"OnFindSelectInResTree",tolua_PX2Editor_Edit_OnFindSelectInResTree00);
   tolua_function(tolua_S,"SetCopyObject",tolua_PX2Editor_Edit_SetCopyObject00);
   tolua_function(tolua_S,"GetCopyObject",tolua_PX2Editor_Edit_GetCopyObject00);
   tolua_function(tolua_S,"PasteCopyedObject",tolua_PX2Editor_Edit_PasteCopyedObject00);
   tolua_function(tolua_S,"AnimPlay",tolua_PX2Editor_Edit_AnimPlay00);
   tolua_function(tolua_S,"AnimResetPlay",tolua_PX2Editor_Edit_AnimResetPlay00);
   tolua_function(tolua_S,"AnimStop",tolua_PX2Editor_Edit_AnimStop00);
   tolua_function(tolua_S,"AnimReset",tolua_PX2Editor_Edit_AnimReset00);
   tolua_function(tolua_S,"IsAnimPlaying",tolua_PX2Editor_Edit_IsAnimPlaying00);
   tolua_function(tolua_S,"AnimPlayStop",tolua_PX2Editor_Edit_AnimPlayStop00);
   tolua_function(tolua_S,"GetTimeLineEdit",tolua_PX2Editor_Edit_GetTimeLineEdit00);
   tolua_function(tolua_S,"MakeSelectTimeLineEdit",tolua_PX2Editor_Edit_MakeSelectTimeLineEdit00);
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
  tolua_constant(tolua_S,"SM_SINGLE",SM_SINGLE);
  tolua_constant(tolua_S,"SM_MULTI",SM_MULTI);
  tolua_constant(tolua_S,"SM_MAX_TYPE",SM_MAX_TYPE);
  tolua_constant(tolua_S,"RVT_SCENEUI",RVT_SCENEUI);
  tolua_constant(tolua_S,"RVT_LOGIC",RVT_LOGIC);
  tolua_constant(tolua_S,"RVT_RES",RVT_RES);
  tolua_constant(tolua_S,"RVT_PREVIEW",RVT_PREVIEW);
  tolua_constant(tolua_S,"RVT_TIMELINE",RVT_TIMELINE);
  tolua_constant(tolua_S,"PVT_PROJECT",PVT_PROJECT);
  tolua_constant(tolua_S,"RVT_MAX_TYPE",RVT_MAX_TYPE);
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
  tolua_cclass(tolua_S,"TimeLineEdit","TimeLineEdit","",NULL);
  tolua_beginmodule(tolua_S,"TimeLineEdit");
   tolua_function(tolua_S,"SetTimeLineRenderStep_UIGroup",tolua_PX2Editor_TimeLineEdit_SetTimeLineRenderStep_UIGroup00);
   tolua_function(tolua_S,"GetTimeLineRenderStep_UIGroup",tolua_PX2Editor_TimeLineEdit_GetTimeLineRenderStep_UIGroup00);
   tolua_function(tolua_S,"SetTimeLineRenderStep_Grid",tolua_PX2Editor_TimeLineEdit_SetTimeLineRenderStep_Grid00);
   tolua_function(tolua_S,"GetTimeLineRenderStep_Grid",tolua_PX2Editor_TimeLineEdit_GetTimeLineRenderStep_Grid00);
   tolua_function(tolua_S,"GetCurveEditNode_Grid",tolua_PX2Editor_TimeLineEdit_GetCurveEditNode_Grid00);
   tolua_function(tolua_S,"GetGridPoly",tolua_PX2Editor_TimeLineEdit_GetGridPoly00);
   tolua_function(tolua_S,"SetCtrlsScale",tolua_PX2Editor_TimeLineEdit_SetCtrlsScale00);
   tolua_function(tolua_S,"GetCtrlsScale",tolua_PX2Editor_TimeLineEdit_GetCtrlsScale00);
   tolua_function(tolua_S,"GetInRange",tolua_PX2Editor_TimeLineEdit_GetInRange00);
   tolua_function(tolua_S,"GetOutRange",tolua_PX2Editor_TimeLineEdit_GetOutRange00);
   tolua_function(tolua_S,"CreateAddCurveGroup",tolua_PX2Editor_TimeLineEdit_CreateAddCurveGroup00);
   tolua_function(tolua_S,"ReCreateAddCurveGroup",tolua_PX2Editor_TimeLineEdit_ReCreateAddCurveGroup00);
   tolua_function(tolua_S,"HasCurveGroup",tolua_PX2Editor_TimeLineEdit_HasCurveGroup00);
   tolua_function(tolua_S,"RemoveGroup",tolua_PX2Editor_TimeLineEdit_RemoveGroup00);
   tolua_function(tolua_S,"GetCurveGroup",tolua_PX2Editor_TimeLineEdit_GetCurveGroup00);
   tolua_function(tolua_S,"GetCurveGroup",tolua_PX2Editor_TimeLineEdit_GetCurveGroup01);
   tolua_function(tolua_S,"UpdateCurve",tolua_PX2Editor_TimeLineEdit_UpdateCurve00);
   tolua_function(tolua_S,"ClearGroup",tolua_PX2Editor_TimeLineEdit_ClearGroup00);
   tolua_function(tolua_S,"ClearAllGroups",tolua_PX2Editor_TimeLineEdit_ClearAllGroups00);
   tolua_function(tolua_S,"HasCurve",tolua_PX2Editor_TimeLineEdit_HasCurve00);
   tolua_function(tolua_S,"AddCurve",tolua_PX2Editor_TimeLineEdit_AddCurve00);
   tolua_function(tolua_S,"RemoveCurve",tolua_PX2Editor_TimeLineEdit_RemoveCurve00);
   tolua_function(tolua_S,"GetNumCurves",tolua_PX2Editor_TimeLineEdit_GetNumCurves00);
   tolua_function(tolua_S,"GetCurve",tolua_PX2Editor_TimeLineEdit_GetCurve00);
   tolua_function(tolua_S,"SetActiveCurve",tolua_PX2Editor_TimeLineEdit_SetActiveCurve00);
   tolua_function(tolua_S,"GetActiveCurve",tolua_PX2Editor_TimeLineEdit_GetActiveCurve00);
   tolua_function(tolua_S,"TrySelectCurve",tolua_PX2Editor_TimeLineEdit_TrySelectCurve00);
   tolua_function(tolua_S,"SetSelectedCurveCtrl",tolua_PX2Editor_TimeLineEdit_SetSelectedCurveCtrl00);
   tolua_function(tolua_S,"GetSelectedCurveCtrl",tolua_PX2Editor_TimeLineEdit_GetSelectedCurveCtrl00);
   tolua_function(tolua_S,"SetSelectedUICurveGroup",tolua_PX2Editor_TimeLineEdit_SetSelectedUICurveGroup00);
   tolua_function(tolua_S,"GetSelectedUICurveGroup",tolua_PX2Editor_TimeLineEdit_GetSelectedUICurveGroup00);
   tolua_function(tolua_S,"Fit_Hor",tolua_PX2Editor_TimeLineEdit_Fit_Hor00);
   tolua_function(tolua_S,"Fit_Ver",tolua_PX2Editor_TimeLineEdit_Fit_Ver00);
   tolua_function(tolua_S,"Fit_All",tolua_PX2Editor_TimeLineEdit_Fit_All00);
   tolua_function(tolua_S,"Fit_Selected",tolua_PX2Editor_TimeLineEdit_Fit_Selected00);
   tolua_function(tolua_S,"Pan",tolua_PX2Editor_TimeLineEdit_Pan00);
   tolua_function(tolua_S,"Zoom",tolua_PX2Editor_TimeLineEdit_Zoom00);
   tolua_function(tolua_S,"Auto",tolua_PX2Editor_TimeLineEdit_Auto00);
   tolua_function(tolua_S,"Clamp",tolua_PX2Editor_TimeLineEdit_Clamp00);
   tolua_function(tolua_S,"User",tolua_PX2Editor_TimeLineEdit_User00);
   tolua_function(tolua_S,"Break",tolua_PX2Editor_TimeLineEdit_Break00);
   tolua_function(tolua_S,"Linear",tolua_PX2Editor_TimeLineEdit_Linear00);
   tolua_function(tolua_S,"Constant",tolua_PX2Editor_TimeLineEdit_Constant00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_PX2Editor (lua_State* tolua_S) {
 return tolua_PX2Editor_open(tolua_S);
};
#endif

