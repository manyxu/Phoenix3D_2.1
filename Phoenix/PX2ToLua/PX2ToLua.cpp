/*
** Lua binding: PX2
** Generated automatically by tolua++-1.0.92 on 01/02/15 10:58:31.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_PX2_open (lua_State* tolua_S);

#include "PX2ToLua.hpp"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Transform (lua_State* tolua_S)
{
 Transform* self = (Transform*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_UIProgressBar (lua_State* tolua_S)
{
 UIProgressBar* self = (UIProgressBar*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_UIRangeFrame (lua_State* tolua_S)
{
 UIRangeFrame* self = (UIRangeFrame*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_UIView (lua_State* tolua_S)
{
 UIView* self = (UIView*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_UICheckButton (lua_State* tolua_S)
{
 UICheckButton* self = (UICheckButton*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_UIButton (lua_State* tolua_S)
{
 UIButton* self = (UIButton*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Controlledable (lua_State* tolua_S)
{
 Controlledable* self = (Controlledable*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_UIButtonBase (lua_State* tolua_S)
{
 UIButtonBase* self = (UIButtonBase*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Movable (lua_State* tolua_S)
{
 Movable* self = (Movable*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_UIFrame (lua_State* tolua_S)
{
 UIFrame* self = (UIFrame*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_APoint (lua_State* tolua_S)
{
 APoint* self = (APoint*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_UIEditBox (lua_State* tolua_S)
{
 UIEditBox* self = (UIEditBox*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_AVector (lua_State* tolua_S)
{
 AVector* self = (AVector*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_int64_t (lua_State* tolua_S)
{
 int64_t* self = (int64_t*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_TriMesh (lua_State* tolua_S)
{
 TriMesh* self = (TriMesh*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_UIInputStaticText (lua_State* tolua_S)
{
 UIInputStaticText* self = (UIInputStaticText*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_UIStaticText (lua_State* tolua_S)
{
 UIStaticText* self = (UIStaticText*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Sound (lua_State* tolua_S)
{
 Sound* self = (Sound*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_SoundSystemInitInfo (lua_State* tolua_S)
{
 SoundSystemInitInfo* self = (SoundSystemInitInfo*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_SoundCreateInfo3D (lua_State* tolua_S)
{
 SoundCreateInfo3D* self = (SoundCreateInfo3D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_ResHandle (lua_State* tolua_S)
{
 ResHandle* self = (ResHandle*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_HPoint (lua_State* tolua_S)
{
 HPoint* self = (HPoint*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Float3 (lua_State* tolua_S)
{
 Float3* self = (Float3*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Camera (lua_State* tolua_S)
{
 Camera* self = (Camera*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Renderable (lua_State* tolua_S)
{
 Renderable* self = (Renderable*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Vector2f (lua_State* tolua_S)
{
 Vector2f* self = (Vector2f*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_InputEventData (lua_State* tolua_S)
{
 InputEventData* self = (InputEventData*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_SwitchNode (lua_State* tolua_S)
{
 SwitchNode* self = (SwitchNode*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Triangles (lua_State* tolua_S)
{
 Triangles* self = (Triangles*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Texture__Format (lua_State* tolua_S)
{
 Texture::Format* self = (Texture::Format*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"ShaderParameters");
 tolua_usertype(tolua_S,"OffsetProperty");
 tolua_usertype(tolua_S,"std::vector<MultiTouchState>");
 tolua_usertype(tolua_S,"TexPackElement");
 tolua_usertype(tolua_S,"Controlledable");
 tolua_usertype(tolua_S,"ResHandle");
 tolua_usertype(tolua_S,"UIFrame");
 tolua_usertype(tolua_S,"AVector");
 tolua_usertype(tolua_S,"Triangles");
 tolua_usertype(tolua_S,"TriMesh");
 tolua_usertype(tolua_S,"Float4");
 tolua_usertype(tolua_S,"LanguageManager");
 tolua_usertype(tolua_S,"ScriptManager");
 tolua_usertype(tolua_S,"Texture2D");
 tolua_usertype(tolua_S,"UIButtonBase");
 tolua_usertype(tolua_S,"Transform");
 tolua_usertype(tolua_S,"Vector3f");
 tolua_usertype(tolua_S,"UICheckButton");
 tolua_usertype(tolua_S,"Movable");
 tolua_usertype(tolua_S,"IndexBuffer");
 tolua_usertype(tolua_S,"SwitchNode");
 tolua_usertype(tolua_S,"MouseState");
 tolua_usertype(tolua_S,"VertexBuffer");
 tolua_usertype(tolua_S,"MultiTouchState");
 tolua_usertype(tolua_S,"DepthProperty");
 tolua_usertype(tolua_S,"Font");
 tolua_usertype(tolua_S,"Renderable");
 tolua_usertype(tolua_S,"Texture::Format");
 tolua_usertype(tolua_S,"Sizef");
 tolua_usertype(tolua_S,"UIProgressBar");
 tolua_usertype(tolua_S,"Texture3D");
 tolua_usertype(tolua_S,"RenderTarget");
 tolua_usertype(tolua_S,"ResourceManager");
 tolua_usertype(tolua_S,"PixelShader");
 tolua_usertype(tolua_S,"Logger");
 tolua_usertype(tolua_S,"std::vector<Pointer0<UIPicBox> >");
 tolua_usertype(tolua_S,"UIPicBox");
 tolua_usertype(tolua_S,"Controller");
 tolua_usertype(tolua_S,"Culler");
 tolua_usertype(tolua_S,"UIView");
 tolua_usertype(tolua_S,"HPoint");
 tolua_usertype(tolua_S,"SoundSystem");
 tolua_usertype(tolua_S,"Camera");
 tolua_usertype(tolua_S,"Object");
 tolua_usertype(tolua_S,"TexPack");
 tolua_usertype(tolua_S,"Renderer");
 tolua_usertype(tolua_S,"Singleton<UIManager>");
 tolua_usertype(tolua_S,"Node");
 tolua_usertype(tolua_S,"UIInputStaticText");
 tolua_usertype(tolua_S,"UIRangeFrame");
 tolua_usertype(tolua_S,"UIProgressBarCtrl");
 tolua_usertype(tolua_S,"TextureCube");
 tolua_usertype(tolua_S,"Event");
 tolua_usertype(tolua_S,"VisibleSet");
 tolua_usertype(tolua_S,"UIButton");
 tolua_usertype(tolua_S,"UIEditBox");
 tolua_usertype(tolua_S,"VertexShader");
 tolua_usertype(tolua_S,"UIStaticText");
 tolua_usertype(tolua_S,"APoint");
 tolua_usertype(tolua_S,"AlphaProperty");
 tolua_usertype(tolua_S,"VertexFormat");
 tolua_usertype(tolua_S,"UIManager");
 tolua_usertype(tolua_S,"Light");
 tolua_usertype(tolua_S,"Sound");
 tolua_usertype(tolua_S,"GlobalMaterial");
 tolua_usertype(tolua_S,"std::map<std::string,UIViewPtr>");
 tolua_usertype(tolua_S,"SoundCreateInfo3D");
 tolua_usertype(tolua_S,"HMatrix");
 tolua_usertype(tolua_S,"MaterialInstance");
 tolua_usertype(tolua_S,"WireProperty");
 tolua_usertype(tolua_S,"Vector2f");
 tolua_usertype(tolua_S,"EventHandler");
 tolua_usertype(tolua_S,"StencilProperty");
 tolua_usertype(tolua_S,"Float3");
 tolua_usertype(tolua_S,"SoundSystemInitInfo");
 tolua_usertype(tolua_S,"Buffer::Locking");
 tolua_usertype(tolua_S,"CullProperty");
 tolua_usertype(tolua_S,"InputEventData");
 tolua_usertype(tolua_S,"Bound");
 tolua_usertype(tolua_S,"Texture1D");
 tolua_usertype(tolua_S,"int64_t");
}

/* method: GetResourcePath of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_GetResourcePath00
static int tolua_PX2_Object_GetResourcePath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Object* self = (const Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetResourcePath'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetResourcePath();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetResourcePath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetName of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_SetName00
static int tolua_PX2_Object_SetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetName'", NULL);
#endif
  {
   self->SetName(name);
   tolua_pushcppstring(tolua_S,(const char*)name);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetName of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_GetName00
static int tolua_PX2_Object_GetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Object* self = (const Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetName'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetObjectByName of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_GetObjectByName00
static int tolua_PX2_Object_GetObjectByName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObjectByName'", NULL);
#endif
  {
   Object* tolua_ret = (Object*)  self->GetObjectByName(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Object");
   tolua_pushcppstring(tolua_S,(const char*)name);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetObjectByName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetTimeInMicroseconds */
#ifndef TOLUA_DISABLE_tolua_PX2_GetTimeInMicroseconds00
static int tolua_PX2_GetTimeInMicroseconds00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   int64_t tolua_ret = (int64_t)  GetTimeInMicroseconds();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((int64_t)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"int64_t");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(int64_t));
     tolua_pushusertype(tolua_S,tolua_obj,"int64_t");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTimeInMicroseconds'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetTimeInSeconds */
#ifndef TOLUA_DISABLE_tolua_PX2_GetTimeInSeconds00
static int tolua_PX2_GetTimeInSeconds00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   double tolua_ret = (double)  GetTimeInSeconds();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTimeInSeconds'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSingleton of class  Logger */
#ifndef TOLUA_DISABLE_tolua_PX2_Logger_GetSingleton00
static int tolua_PX2_Logger_GetSingleton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Logger",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Logger& tolua_ret = (Logger&)  Logger::GetSingleton();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Logger");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSingleton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LogInfo of class  Logger */
#ifndef TOLUA_DISABLE_tolua_PX2_Logger_LogInfo00
static int tolua_PX2_Logger_LogInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Logger",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Logger* self = (Logger*)  tolua_tousertype(tolua_S,1,0);
  const std::string tag = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string info = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LogInfo'", NULL);
#endif
  {
   self->LogInfo(tag,info);
   tolua_pushcppstring(tolua_S,(const char*)tag);
   tolua_pushcppstring(tolua_S,(const char*)info);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LogInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LogError of class  Logger */
#ifndef TOLUA_DISABLE_tolua_PX2_Logger_LogError00
static int tolua_PX2_Logger_LogError00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Logger",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Logger* self = (Logger*)  tolua_tousertype(tolua_S,1,0);
  const std::string tag = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string info = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LogError'", NULL);
#endif
  {
   self->LogError(tag,info);
   tolua_pushcppstring(tolua_S,(const char*)tag);
   tolua_pushcppstring(tolua_S,(const char*)info);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LogError'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LogUser of class  Logger */
#ifndef TOLUA_DISABLE_tolua_PX2_Logger_LogUser00
static int tolua_PX2_Logger_LogUser00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Logger",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Logger* self = (Logger*)  tolua_tousertype(tolua_S,1,0);
  const std::string tag = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string info = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LogUser'", NULL);
#endif
  {
   self->LogUser(tag,info);
   tolua_pushcppstring(tolua_S,(const char*)tag);
   tolua_pushcppstring(tolua_S,(const char*)info);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LogUser'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  APoint */
#ifndef TOLUA_DISABLE_tolua_PX2_APoint_new00
static int tolua_PX2_APoint_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"APoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   APoint* tolua_ret = (APoint*)  Mtolua_new((APoint)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"APoint");
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

/* method: new_local of class  APoint */
#ifndef TOLUA_DISABLE_tolua_PX2_APoint_new00_local
static int tolua_PX2_APoint_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"APoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   APoint* tolua_ret = (APoint*)  Mtolua_new((APoint)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"APoint");
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

/* method: new of class  APoint */
#ifndef TOLUA_DISABLE_tolua_PX2_APoint_new01
static int tolua_PX2_APoint_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"APoint",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const APoint* pnt = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
  {
   APoint* tolua_ret = (APoint*)  Mtolua_new((APoint)(*pnt));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"APoint");
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_APoint_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  APoint */
#ifndef TOLUA_DISABLE_tolua_PX2_APoint_new01_local
static int tolua_PX2_APoint_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"APoint",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const APoint* pnt = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
  {
   APoint* tolua_ret = (APoint*)  Mtolua_new((APoint)(*pnt));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"APoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_APoint_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  APoint */
#ifndef TOLUA_DISABLE_tolua_PX2_APoint_new02
static int tolua_PX2_APoint_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"APoint",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   APoint* tolua_ret = (APoint*)  Mtolua_new((APoint)(x,y,z));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"APoint");
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_APoint_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  APoint */
#ifndef TOLUA_DISABLE_tolua_PX2_APoint_new02_local
static int tolua_PX2_APoint_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"APoint",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   APoint* tolua_ret = (APoint*)  Mtolua_new((APoint)(x,y,z));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"APoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_APoint_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  APoint */
#ifndef TOLUA_DISABLE_tolua_PX2_APoint_delete00
static int tolua_PX2_APoint_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"APoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  APoint* self = (APoint*)  tolua_tousertype(tolua_S,1,0);
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

/* method: operator- of class  APoint */
#ifndef TOLUA_DISABLE_tolua_PX2_APoint__sub00
static int tolua_PX2_APoint__sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const APoint",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const APoint* self = (const APoint*)  tolua_tousertype(tolua_S,1,0);
  const APoint* pnt = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   AVector tolua_ret = (AVector)  self->operator-(*pnt);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((AVector)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(AVector));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  APoint */
#ifndef TOLUA_DISABLE_tolua_PX2_APoint__add00
static int tolua_PX2_APoint__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const APoint",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const APoint* self = (const APoint*)  tolua_tousertype(tolua_S,1,0);
  const AVector* vec = ((const AVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   APoint tolua_ret = (APoint)  self->operator+(*vec);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((APoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"APoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(APoint));
     tolua_pushusertype(tolua_S,tolua_obj,"APoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  APoint */
#ifndef TOLUA_DISABLE_tolua_PX2_APoint__sub01
static int tolua_PX2_APoint__sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const APoint",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const APoint* self = (const APoint*)  tolua_tousertype(tolua_S,1,0);
  const AVector* vec = ((const AVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   APoint tolua_ret = (APoint)  self->operator-(*vec);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((APoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"APoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(APoint));
     tolua_pushusertype(tolua_S,tolua_obj,"APoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_APoint__sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  APoint */
#ifndef TOLUA_DISABLE_tolua_PX2_APoint__add01
static int tolua_PX2_APoint__add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const APoint",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const APoint* self = (const APoint*)  tolua_tousertype(tolua_S,1,0);
  const APoint* pnt = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   APoint tolua_ret = (APoint)  self->operator+(*pnt);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((APoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"APoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(APoint));
     tolua_pushusertype(tolua_S,tolua_obj,"APoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_APoint__add00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  APoint */
#ifndef TOLUA_DISABLE_tolua_PX2_APoint__mul00
static int tolua_PX2_APoint__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const APoint",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const APoint* self = (const APoint*)  tolua_tousertype(tolua_S,1,0);
  float scalar = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   APoint tolua_ret = (APoint)  self->operator*(scalar);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((APoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"APoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(APoint));
     tolua_pushusertype(tolua_S,tolua_obj,"APoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  APoint */
#ifndef TOLUA_DISABLE_tolua_PX2_APoint__div00
static int tolua_PX2_APoint__div00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const APoint",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const APoint* self = (const APoint*)  tolua_tousertype(tolua_S,1,0);
  float scalar = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   APoint tolua_ret = (APoint)  self->operator/(scalar);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((APoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"APoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(APoint));
     tolua_pushusertype(tolua_S,tolua_obj,"APoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  APoint */
#ifndef TOLUA_DISABLE_tolua_PX2_APoint__sub02
static int tolua_PX2_APoint__sub02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const APoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const APoint* self = (const APoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   APoint tolua_ret = (APoint)  self->operator-();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((APoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"APoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(APoint));
     tolua_pushusertype(tolua_S,tolua_obj,"APoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_APoint__sub01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Dot of class  APoint */
#ifndef TOLUA_DISABLE_tolua_PX2_APoint_Dot00
static int tolua_PX2_APoint_Dot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const APoint",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const APoint* self = (const APoint*)  tolua_tousertype(tolua_S,1,0);
  const AVector* vec = ((const AVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Dot'", NULL);
#endif
  {
   float tolua_ret = (float)  self->Dot(*vec);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Dot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ORIGIN of class  APoint */
#ifndef TOLUA_DISABLE_tolua_get_APoint_ORIGIN
static int tolua_get_APoint_ORIGIN(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&APoint::ORIGIN,"const APoint");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector_new00
static int tolua_PX2_AVector_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AVector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   AVector* tolua_ret = (AVector*)  Mtolua_new((AVector)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AVector");
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

/* method: new_local of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector_new00_local
static int tolua_PX2_AVector_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AVector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   AVector* tolua_ret = (AVector*)  Mtolua_new((AVector)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AVector");
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

/* method: new of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector_new01
static int tolua_PX2_AVector_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AVector",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const AVector* vec = ((const AVector*)  tolua_tousertype(tolua_S,2,0));
  {
   AVector* tolua_ret = (AVector*)  Mtolua_new((AVector)(*vec));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AVector");
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_AVector_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector_new01_local
static int tolua_PX2_AVector_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AVector",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const AVector* vec = ((const AVector*)  tolua_tousertype(tolua_S,2,0));
  {
   AVector* tolua_ret = (AVector*)  Mtolua_new((AVector)(*vec));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_AVector_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector_new02
static int tolua_PX2_AVector_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AVector",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   AVector* tolua_ret = (AVector*)  Mtolua_new((AVector)(x,y,z));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AVector");
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_AVector_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector_new02_local
static int tolua_PX2_AVector_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AVector",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   AVector* tolua_ret = (AVector*)  Mtolua_new((AVector)(x,y,z));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_AVector_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector_new03
static int tolua_PX2_AVector_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AVector",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Float3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Float3* tuple = ((const Float3*)  tolua_tousertype(tolua_S,2,0));
  {
   AVector* tolua_ret = (AVector*)  Mtolua_new((AVector)(*tuple));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AVector");
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_AVector_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector_new03_local
static int tolua_PX2_AVector_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AVector",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Float3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Float3* tuple = ((const Float3*)  tolua_tousertype(tolua_S,2,0));
  {
   AVector* tolua_ret = (AVector*)  Mtolua_new((AVector)(*tuple));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_AVector_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector_new04
static int tolua_PX2_AVector_new04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AVector",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3f",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector3f* vec = ((const Vector3f*)  tolua_tousertype(tolua_S,2,0));
  {
   AVector* tolua_ret = (AVector*)  Mtolua_new((AVector)(*vec));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AVector");
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_AVector_new03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector_new04_local
static int tolua_PX2_AVector_new04_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AVector",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3f",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector3f* vec = ((const Vector3f*)  tolua_tousertype(tolua_S,2,0));
  {
   AVector* tolua_ret = (AVector*)  Mtolua_new((AVector)(*vec));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_AVector_new03_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector_delete00
static int tolua_PX2_AVector_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AVector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AVector* self = (AVector*)  tolua_tousertype(tolua_S,1,0);
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

/* method: operator+ of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector__add00
static int tolua_PX2_AVector__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const AVector",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const AVector* self = (const AVector*)  tolua_tousertype(tolua_S,1,0);
  const AVector* vec = ((const AVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   AVector tolua_ret = (AVector)  self->operator+(*vec);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((AVector)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(AVector));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector__sub00
static int tolua_PX2_AVector__sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const AVector",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const AVector* self = (const AVector*)  tolua_tousertype(tolua_S,1,0);
  const AVector* vec = ((const AVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   AVector tolua_ret = (AVector)  self->operator-(*vec);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((AVector)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(AVector));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector__mul00
static int tolua_PX2_AVector__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const AVector",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const AVector* self = (const AVector*)  tolua_tousertype(tolua_S,1,0);
  float scalar = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   AVector tolua_ret = (AVector)  self->operator*(scalar);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((AVector)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(AVector));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector__div00
static int tolua_PX2_AVector__div00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const AVector",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const AVector* self = (const AVector*)  tolua_tousertype(tolua_S,1,0);
  float scalar = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   AVector tolua_ret = (AVector)  self->operator/(scalar);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((AVector)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(AVector));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector__sub01
static int tolua_PX2_AVector__sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const AVector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const AVector* self = (const AVector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   AVector tolua_ret = (AVector)  self->operator-();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((AVector)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(AVector));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_AVector__sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Length of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector_Length00
static int tolua_PX2_AVector_Length00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const AVector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const AVector* self = (const AVector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Length'", NULL);
#endif
  {
   float tolua_ret = (float)  self->Length();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Length'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SquaredLength of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector_SquaredLength00
static int tolua_PX2_AVector_SquaredLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const AVector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const AVector* self = (const AVector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SquaredLength'", NULL);
#endif
  {
   float tolua_ret = (float)  self->SquaredLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SquaredLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Dot of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector_Dot00
static int tolua_PX2_AVector_Dot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const AVector",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const AVector* self = (const AVector*)  tolua_tousertype(tolua_S,1,0);
  const AVector* vec = ((const AVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Dot'", NULL);
#endif
  {
   float tolua_ret = (float)  self->Dot(*vec);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Dot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Normalize of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector_Normalize00
static int tolua_PX2_AVector_Normalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AVector",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AVector* self = (AVector*)  tolua_tousertype(tolua_S,1,0);
  const float epsilon = ((const float)  tolua_tonumber(tolua_S,2,Mathf::ZERO_TOLERANCE));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Normalize'", NULL);
#endif
  {
   float tolua_ret = (float)  self->Normalize(epsilon);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Cross of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector_Cross00
static int tolua_PX2_AVector_Cross00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const AVector",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const AVector* self = (const AVector*)  tolua_tousertype(tolua_S,1,0);
  const AVector* vec = ((const AVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Cross'", NULL);
#endif
  {
   AVector tolua_ret = (AVector)  self->Cross(*vec);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((AVector)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(AVector));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Cross'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UnitCross of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector_UnitCross00
static int tolua_PX2_AVector_UnitCross00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const AVector",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const AVector* self = (const AVector*)  tolua_tousertype(tolua_S,1,0);
  const AVector* vec = ((const AVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UnitCross'", NULL);
#endif
  {
   AVector tolua_ret = (AVector)  self->UnitCross(*vec);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((AVector)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(AVector));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UnitCross'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Orthonormalize of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector_Orthonormalize00
static int tolua_PX2_AVector_Orthonormalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AVector",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AVector",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"AVector",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AVector* vec0 = ((AVector*)  tolua_tousertype(tolua_S,2,0));
  AVector* vec1 = ((AVector*)  tolua_tousertype(tolua_S,3,0));
  AVector* vec2 = ((AVector*)  tolua_tousertype(tolua_S,4,0));
  {
   AVector::Orthonormalize(*vec0,*vec1,*vec2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Orthonormalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Orthonormalize of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector_Orthonormalize01
static int tolua_PX2_AVector_Orthonormalize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AVector",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"AVector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  AVector* vec = ((AVector*)  tolua_tousertype(tolua_S,2,0));
  {
   AVector::Orthonormalize(vec);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_AVector_Orthonormalize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GenerateOrthonormalBasis of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector_GenerateOrthonormalBasis00
static int tolua_PX2_AVector_GenerateOrthonormalBasis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AVector",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AVector",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"AVector",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AVector* vec0 = ((AVector*)  tolua_tousertype(tolua_S,2,0));
  AVector* vec1 = ((AVector*)  tolua_tousertype(tolua_S,3,0));
  AVector* vec2 = ((AVector*)  tolua_tousertype(tolua_S,4,0));
  {
   AVector::GenerateOrthonormalBasis(*vec0,*vec1,*vec2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GenerateOrthonormalBasis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GenerateComplementBasis of class  AVector */
#ifndef TOLUA_DISABLE_tolua_PX2_AVector_GenerateComplementBasis00
static int tolua_PX2_AVector_GenerateComplementBasis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AVector",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AVector",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"AVector",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AVector* vec0 = ((AVector*)  tolua_tousertype(tolua_S,2,0));
  AVector* vec1 = ((AVector*)  tolua_tousertype(tolua_S,3,0));
  const AVector* vec2 = ((const AVector*)  tolua_tousertype(tolua_S,4,0));
  {
   AVector::GenerateComplementBasis(*vec0,*vec1,*vec2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GenerateComplementBasis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ZERO of class  AVector */
#ifndef TOLUA_DISABLE_tolua_get_AVector_ZERO
static int tolua_get_AVector_ZERO(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&AVector::ZERO,"const AVector");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: UNIT_X of class  AVector */
#ifndef TOLUA_DISABLE_tolua_get_AVector_UNIT_X
static int tolua_get_AVector_UNIT_X(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&AVector::UNIT_X,"const AVector");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: UNIT_Y of class  AVector */
#ifndef TOLUA_DISABLE_tolua_get_AVector_UNIT_Y
static int tolua_get_AVector_UNIT_Y(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&AVector::UNIT_Y,"const AVector");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: UNIT_Z of class  AVector */
#ifndef TOLUA_DISABLE_tolua_get_AVector_UNIT_Z
static int tolua_get_AVector_UNIT_Z(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&AVector::UNIT_Z,"const AVector");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  HPoint */
#ifndef TOLUA_DISABLE_tolua_PX2_HPoint_new00
static int tolua_PX2_HPoint_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"HPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   HPoint* tolua_ret = (HPoint*)  Mtolua_new((HPoint)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"HPoint");
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

/* method: new_local of class  HPoint */
#ifndef TOLUA_DISABLE_tolua_PX2_HPoint_new00_local
static int tolua_PX2_HPoint_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"HPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   HPoint* tolua_ret = (HPoint*)  Mtolua_new((HPoint)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"HPoint");
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

/* method: new of class  HPoint */
#ifndef TOLUA_DISABLE_tolua_PX2_HPoint_new01
static int tolua_PX2_HPoint_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"HPoint",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const HPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const HPoint* pnt = ((const HPoint*)  tolua_tousertype(tolua_S,2,0));
  {
   HPoint* tolua_ret = (HPoint*)  Mtolua_new((HPoint)(*pnt));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"HPoint");
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_HPoint_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  HPoint */
#ifndef TOLUA_DISABLE_tolua_PX2_HPoint_new01_local
static int tolua_PX2_HPoint_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"HPoint",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const HPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const HPoint* pnt = ((const HPoint*)  tolua_tousertype(tolua_S,2,0));
  {
   HPoint* tolua_ret = (HPoint*)  Mtolua_new((HPoint)(*pnt));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"HPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_HPoint_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  HPoint */
#ifndef TOLUA_DISABLE_tolua_PX2_HPoint_new02
static int tolua_PX2_HPoint_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"HPoint",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  float w = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   HPoint* tolua_ret = (HPoint*)  Mtolua_new((HPoint)(x,y,z,w));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"HPoint");
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_HPoint_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  HPoint */
#ifndef TOLUA_DISABLE_tolua_PX2_HPoint_new02_local
static int tolua_PX2_HPoint_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"HPoint",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  float w = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   HPoint* tolua_ret = (HPoint*)  Mtolua_new((HPoint)(x,y,z,w));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"HPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_HPoint_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  HPoint */
#ifndef TOLUA_DISABLE_tolua_PX2_HPoint_delete00
static int tolua_PX2_HPoint_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HPoint* self = (HPoint*)  tolua_tousertype(tolua_S,1,0);
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

/* method: operator[] of class  HPoint */
#ifndef TOLUA_DISABLE_tolua_PX2_HPoint__geti00
static int tolua_PX2_HPoint__geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const HPoint",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const HPoint* self = (const HPoint*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'", NULL);
#endif
  {
   float tolua_ret = (float)  self->operator[](i);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator&[] of class  HPoint */
#ifndef TOLUA_DISABLE_tolua_PX2_HPoint__seti00
static int tolua_PX2_HPoint__seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HPoint",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HPoint* self = (HPoint*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  float tolua_value = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'", NULL);
#endif
  self->operator[](i) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator[] of class  HPoint */
#ifndef TOLUA_DISABLE_tolua_PX2_HPoint__geti01
static int tolua_PX2_HPoint__geti01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HPoint",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  HPoint* self = (HPoint*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'", NULL);
#endif
  {
   float tolua_ret = (float)  self->operator[](i);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_HPoint__geti00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: X of class  HPoint */
#ifndef TOLUA_DISABLE_tolua_PX2_HPoint_X00
static int tolua_PX2_HPoint_X00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const HPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const HPoint* self = (const HPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'X'", NULL);
#endif
  {
   float tolua_ret = (float)  self->X();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'X'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: X of class  HPoint */
#ifndef TOLUA_DISABLE_tolua_PX2_HPoint_X01
static int tolua_PX2_HPoint_X01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  HPoint* self = (HPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'X'", NULL);
#endif
  {
   float tolua_ret = (float)  self->X();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_HPoint_X00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Y of class  HPoint */
#ifndef TOLUA_DISABLE_tolua_PX2_HPoint_Y00
static int tolua_PX2_HPoint_Y00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const HPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const HPoint* self = (const HPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Y'", NULL);
#endif
  {
   float tolua_ret = (float)  self->Y();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Y'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Y of class  HPoint */
#ifndef TOLUA_DISABLE_tolua_PX2_HPoint_Y01
static int tolua_PX2_HPoint_Y01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  HPoint* self = (HPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Y'", NULL);
#endif
  {
   float tolua_ret = (float)  self->Y();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_HPoint_Y00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Z of class  HPoint */
#ifndef TOLUA_DISABLE_tolua_PX2_HPoint_Z00
static int tolua_PX2_HPoint_Z00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const HPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const HPoint* self = (const HPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Z'", NULL);
#endif
  {
   float tolua_ret = (float)  self->Z();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Z'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Z of class  HPoint */
#ifndef TOLUA_DISABLE_tolua_PX2_HPoint_Z01
static int tolua_PX2_HPoint_Z01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  HPoint* self = (HPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Z'", NULL);
#endif
  {
   float tolua_ret = (float)  self->Z();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_HPoint_Z00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: W of class  HPoint */
#ifndef TOLUA_DISABLE_tolua_PX2_HPoint_W00
static int tolua_PX2_HPoint_W00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const HPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const HPoint* self = (const HPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'W'", NULL);
#endif
  {
   float tolua_ret = (float)  self->W();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'W'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: W of class  HPoint */
#ifndef TOLUA_DISABLE_tolua_PX2_HPoint_W01
static int tolua_PX2_HPoint_W01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  HPoint* self = (HPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'W'", NULL);
#endif
  {
   float tolua_ret = (float)  self->W();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_HPoint_W00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  HPoint */
#ifndef TOLUA_DISABLE_tolua_PX2_HPoint__eq00
static int tolua_PX2_HPoint__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const HPoint",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const HPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const HPoint* self = (const HPoint*)  tolua_tousertype(tolua_S,1,0);
  const HPoint* pnt = ((const HPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*pnt);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator< of class  HPoint */
#ifndef TOLUA_DISABLE_tolua_PX2_HPoint__lt00
static int tolua_PX2_HPoint__lt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const HPoint",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const HPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const HPoint* self = (const HPoint*)  tolua_tousertype(tolua_S,1,0);
  const HPoint* pnt = ((const HPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator<'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator<(*pnt);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.lt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator<= of class  HPoint */
#ifndef TOLUA_DISABLE_tolua_PX2_HPoint__le00
static int tolua_PX2_HPoint__le00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const HPoint",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const HPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const HPoint* self = (const HPoint*)  tolua_tousertype(tolua_S,1,0);
  const HPoint* pnt = ((const HPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator<='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator<=(*pnt);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.le'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_new00
static int tolua_PX2_Transform_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Transform* tolua_ret = (Transform*)  Mtolua_new((Transform)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Transform");
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

/* method: new_local of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_new00_local
static int tolua_PX2_Transform_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Transform* tolua_ret = (Transform*)  Mtolua_new((Transform)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Transform");
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

/* method: delete of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_delete00
static int tolua_PX2_Transform_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
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

/* method: MakeIdentity of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_MakeIdentity00
static int tolua_PX2_Transform_MakeIdentity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MakeIdentity'", NULL);
#endif
  {
   self->MakeIdentity();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MakeIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MakeUnitScale of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_MakeUnitScale00
static int tolua_PX2_Transform_MakeUnitScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MakeUnitScale'", NULL);
#endif
  {
   self->MakeUnitScale();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MakeUnitScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsIdentity of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_IsIdentity00
static int tolua_PX2_Transform_IsIdentity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsIdentity'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsIdentity();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsRSMatrix of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_IsRSMatrix00
static int tolua_PX2_Transform_IsRSMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsRSMatrix'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsRSMatrix();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsRSMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsUniformScale of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_IsUniformScale00
static int tolua_PX2_Transform_IsUniformScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsUniformScale'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsUniformScale();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsUniformScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRotate of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_SetRotate00
static int tolua_PX2_Transform_SetRotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const HMatrix",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  const HMatrix* rotate = ((const HMatrix*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRotate'", NULL);
#endif
  {
   self->SetRotate(*rotate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMatrix of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_SetMatrix00
static int tolua_PX2_Transform_SetMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const HMatrix",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  const HMatrix* matrix = ((const HMatrix*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMatrix'", NULL);
#endif
  {
   self->SetMatrix(*matrix);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTranslate of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_SetTranslate00
static int tolua_PX2_Transform_SetTranslate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  const APoint* translate = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTranslate'", NULL);
#endif
  {
   self->SetTranslate(*translate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTranslate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScale of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_SetScale00
static int tolua_PX2_Transform_SetScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  const APoint* scale = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScale'", NULL);
#endif
  {
   self->SetScale(*scale);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUniformScale of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_SetUniformScale00
static int tolua_PX2_Transform_SetUniformScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  float scale = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUniformScale'", NULL);
#endif
  {
   self->SetUniformScale(scale);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUniformScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRotate of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_GetRotate00
static int tolua_PX2_Transform_GetRotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRotate'", NULL);
#endif
  {
   const HMatrix& tolua_ret = (const HMatrix&)  self->GetRotate();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const HMatrix");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMatrix of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_GetMatrix00
static int tolua_PX2_Transform_GetMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMatrix'", NULL);
#endif
  {
   const HMatrix& tolua_ret = (const HMatrix&)  self->GetMatrix();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const HMatrix");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTranslate of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_GetTranslate00
static int tolua_PX2_Transform_GetTranslate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTranslate'", NULL);
#endif
  {
   const APoint& tolua_ret = (const APoint&)  self->GetTranslate();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const APoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTranslate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScale of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_GetScale00
static int tolua_PX2_Transform_GetScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScale'", NULL);
#endif
  {
   const APoint& tolua_ret = (const APoint&)  self->GetScale();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const APoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUniformScale of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_GetUniformScale00
static int tolua_PX2_Transform_GetUniformScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUniformScale'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetUniformScale();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUniformScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNorm of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_GetNorm00
static int tolua_PX2_Transform_GetNorm00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNorm'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetNorm();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNorm'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform__mul00
static int tolua_PX2_Transform__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
  const APoint* pnt = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   APoint tolua_ret = (APoint)  self->operator*(*pnt);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((APoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"APoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(APoint));
     tolua_pushusertype(tolua_S,tolua_obj,"APoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform__mul01
static int tolua_PX2_Transform__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
  const AVector* vec = ((const AVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   AVector tolua_ret = (AVector)  self->operator*(*vec);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((AVector)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(AVector));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_Transform__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform__mul02
static int tolua_PX2_Transform__mul02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Transform",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
  const Transform* transform = ((const Transform*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Transform tolua_ret = (Transform)  self->operator*(*transform);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Transform)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Transform");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Transform));
     tolua_pushusertype(tolua_S,tolua_obj,"Transform");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_Transform__mul01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Matrix of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_Matrix00
static int tolua_PX2_Transform_Matrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Matrix'", NULL);
#endif
  {
   const HMatrix& tolua_ret = (const HMatrix&)  self->Matrix();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const HMatrix");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Matrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Inverse of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_Inverse00
static int tolua_PX2_Transform_Inverse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Inverse'", NULL);
#endif
  {
   const HMatrix& tolua_ret = (const HMatrix&)  self->Inverse();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const HMatrix");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Inverse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InverseTransform of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_InverseTransform00
static int tolua_PX2_Transform_InverseTransform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InverseTransform'", NULL);
#endif
  {
   Transform tolua_ret = (Transform)  self->InverseTransform();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Transform)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Transform");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Transform));
     tolua_pushusertype(tolua_S,tolua_obj,"Transform");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InverseTransform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: IDENTITY of class  Transform */
#ifndef TOLUA_DISABLE_tolua_get_Transform_IDENTITY
static int tolua_get_Transform_IDENTITY(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Transform::IDENTITY,"const Transform");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetStreamingSize of class  Transform */
#ifndef TOLUA_DISABLE_tolua_PX2_Transform_GetStreamingSize00
static int tolua_PX2_Transform_GetStreamingSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   int tolua_ret = (int)  Transform::GetStreamingSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetStreamingSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Controlledable */
#ifndef TOLUA_DISABLE_tolua_PX2_Controlledable_delete00
static int tolua_PX2_Controlledable_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Controlledable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Controlledable* self = (Controlledable*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetNumControllers of class  Controlledable */
#ifndef TOLUA_DISABLE_tolua_PX2_Controlledable_GetNumControllers00
static int tolua_PX2_Controlledable_GetNumControllers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Controlledable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Controlledable* self = (const Controlledable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumControllers'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetNumControllers();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumControllers'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetController of class  Controlledable */
#ifndef TOLUA_DISABLE_tolua_PX2_Controlledable_GetController00
static int tolua_PX2_Controlledable_GetController00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Controlledable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Controlledable* self = (const Controlledable*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetController'", NULL);
#endif
  {
   Controller* tolua_ret = (Controller*)  self->GetController(i);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Controller");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetController'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AttachController of class  Controlledable */
#ifndef TOLUA_DISABLE_tolua_PX2_Controlledable_AttachController00
static int tolua_PX2_Controlledable_AttachController00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Controlledable",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Controller",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Controlledable* self = (Controlledable*)  tolua_tousertype(tolua_S,1,0);
  Controller* controller = ((Controller*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AttachController'", NULL);
#endif
  {
   self->AttachController(controller);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AttachController'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DetachController of class  Controlledable */
#ifndef TOLUA_DISABLE_tolua_PX2_Controlledable_DetachController00
static int tolua_PX2_Controlledable_DetachController00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Controlledable",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Controller",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Controlledable* self = (Controlledable*)  tolua_tousertype(tolua_S,1,0);
  Controller* controller = ((Controller*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DetachController'", NULL);
#endif
  {
   self->DetachController(controller);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DetachController'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DetachAllControllers of class  Controlledable */
#ifndef TOLUA_DISABLE_tolua_PX2_Controlledable_DetachAllControllers00
static int tolua_PX2_Controlledable_DetachAllControllers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Controlledable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Controlledable* self = (Controlledable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DetachAllControllers'", NULL);
#endif
  {
   self->DetachAllControllers();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DetachAllControllers'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Movable */
#ifndef TOLUA_DISABLE_tolua_PX2_Movable_delete00
static int tolua_PX2_Movable_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Movable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Movable* self = (Movable*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: LocalTransform of class  Movable */
#ifndef TOLUA_DISABLE_tolua_get_Movable_LocalTransform
static int tolua_get_Movable_LocalTransform(lua_State* tolua_S)
{
  Movable* self = (Movable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LocalTransform'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->LocalTransform,"Transform");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: LocalTransform of class  Movable */
#ifndef TOLUA_DISABLE_tolua_set_Movable_LocalTransform
static int tolua_set_Movable_LocalTransform(lua_State* tolua_S)
{
  Movable* self = (Movable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LocalTransform'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Transform",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->LocalTransform = *((Transform*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WorldTransform of class  Movable */
#ifndef TOLUA_DISABLE_tolua_get_Movable_WorldTransform
static int tolua_get_Movable_WorldTransform(lua_State* tolua_S)
{
  Movable* self = (Movable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WorldTransform'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->WorldTransform,"Transform");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: WorldTransform of class  Movable */
#ifndef TOLUA_DISABLE_tolua_set_Movable_WorldTransform
static int tolua_set_Movable_WorldTransform(lua_State* tolua_S)
{
  Movable* self = (Movable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WorldTransform'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Transform",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->WorldTransform = *((Transform*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WorldTransformIsCurrent of class  Movable */
#ifndef TOLUA_DISABLE_tolua_get_Movable_WorldTransformIsCurrent
static int tolua_get_Movable_WorldTransformIsCurrent(lua_State* tolua_S)
{
  Movable* self = (Movable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WorldTransformIsCurrent'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->WorldTransformIsCurrent);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: WorldTransformIsCurrent of class  Movable */
#ifndef TOLUA_DISABLE_tolua_set_Movable_WorldTransformIsCurrent
static int tolua_set_Movable_WorldTransformIsCurrent(lua_State* tolua_S)
{
  Movable* self = (Movable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WorldTransformIsCurrent'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->WorldTransformIsCurrent = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WorldBound of class  Movable */
#ifndef TOLUA_DISABLE_tolua_get_Movable_WorldBound
static int tolua_get_Movable_WorldBound(lua_State* tolua_S)
{
  Movable* self = (Movable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WorldBound'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->WorldBound,"Bound");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: WorldBound of class  Movable */
#ifndef TOLUA_DISABLE_tolua_set_Movable_WorldBound
static int tolua_set_Movable_WorldBound(lua_State* tolua_S)
{
  Movable* self = (Movable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WorldBound'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Bound",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->WorldBound = *((Bound*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WorldBoundIsCurrent of class  Movable */
#ifndef TOLUA_DISABLE_tolua_get_Movable_WorldBoundIsCurrent
static int tolua_get_Movable_WorldBoundIsCurrent(lua_State* tolua_S)
{
  Movable* self = (Movable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WorldBoundIsCurrent'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->WorldBoundIsCurrent);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: WorldBoundIsCurrent of class  Movable */
#ifndef TOLUA_DISABLE_tolua_set_Movable_WorldBoundIsCurrent
static int tolua_set_Movable_WorldBoundIsCurrent(lua_State* tolua_S)
{
  Movable* self = (Movable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'WorldBoundIsCurrent'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->WorldBoundIsCurrent = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Culling of class  Movable */
#ifndef TOLUA_DISABLE_tolua_get_Movable_Culling
static int tolua_get_Movable_Culling(lua_State* tolua_S)
{
  Movable* self = (Movable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Culling'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Culling);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Culling of class  Movable */
#ifndef TOLUA_DISABLE_tolua_set_Movable_Culling
static int tolua_set_Movable_Culling(lua_State* tolua_S)
{
  Movable* self = (Movable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Culling'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Culling = ((Movable::CullingMode) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: Show of class  Movable */
#ifndef TOLUA_DISABLE_tolua_PX2_Movable_Show00
static int tolua_PX2_Movable_Show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Movable",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Movable* self = (Movable*)  tolua_tousertype(tolua_S,1,0);
  bool show = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Show'", NULL);
#endif
  {
   self->Show(show);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsShow of class  Movable */
#ifndef TOLUA_DISABLE_tolua_PX2_Movable_IsShow00
static int tolua_PX2_Movable_IsShow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Movable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Movable* self = (const Movable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsShow'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsShow();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsShow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Movable */
#ifndef TOLUA_DISABLE_tolua_PX2_Movable_Update00
static int tolua_PX2_Movable_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Movable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Movable* self = (Movable*)  tolua_tousertype(tolua_S,1,0);
  double applicationTime = ((double)  tolua_tonumber(tolua_S,2,-Mathd::MAX_REAL));
  bool initiator = ((bool)  tolua_toboolean(tolua_S,3,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(applicationTime,initiator);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetParent of class  Movable */
#ifndef TOLUA_DISABLE_tolua_PX2_Movable_GetParent00
static int tolua_PX2_Movable_GetParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Movable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Movable* self = (Movable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetParent'", NULL);
#endif
  {
   Movable* tolua_ret = (Movable*)  self->GetParent();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Movable");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_delete00
static int tolua_PX2_Renderable_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderable* self = (Renderable*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetPrimitiveType of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_GetPrimitiveType00
static int tolua_PX2_Renderable_GetPrimitiveType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderable* self = (const Renderable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPrimitiveType'", NULL);
#endif
  {
   Renderable::PrimitiveType tolua_ret = (Renderable::PrimitiveType)  self->GetPrimitiveType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPrimitiveType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVertexFormat of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_SetVertexFormat00
static int tolua_PX2_Renderable_SetVertexFormat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderable",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"VertexFormat",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderable* self = (Renderable*)  tolua_tousertype(tolua_S,1,0);
  VertexFormat* vformat = ((VertexFormat*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVertexFormat'", NULL);
#endif
  {
   self->SetVertexFormat(vformat);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVertexFormat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVertexFormat of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_GetVertexFormat00
static int tolua_PX2_Renderable_GetVertexFormat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderable* self = (const Renderable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVertexFormat'", NULL);
#endif
  {
   const VertexFormat* tolua_ret = (const VertexFormat*)  self->GetVertexFormat();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const VertexFormat");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVertexFormat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVertexFormat of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_GetVertexFormat01
static int tolua_PX2_Renderable_GetVertexFormat01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderable* self = (Renderable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVertexFormat'", NULL);
#endif
  {
   VertexFormat* tolua_ret = (VertexFormat*)  self->GetVertexFormat();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"VertexFormat");
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_Renderable_GetVertexFormat00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVertexBuffer of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_SetVertexBuffer00
static int tolua_PX2_Renderable_SetVertexBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderable",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"VertexBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderable* self = (Renderable*)  tolua_tousertype(tolua_S,1,0);
  VertexBuffer* vbuffer = ((VertexBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVertexBuffer'", NULL);
#endif
  {
   self->SetVertexBuffer(vbuffer);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVertexBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVertexBuffer of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_GetVertexBuffer00
static int tolua_PX2_Renderable_GetVertexBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderable* self = (const Renderable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVertexBuffer'", NULL);
#endif
  {
   const VertexBuffer* tolua_ret = (const VertexBuffer*)  self->GetVertexBuffer();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const VertexBuffer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVertexBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVertexBuffer of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_GetVertexBuffer01
static int tolua_PX2_Renderable_GetVertexBuffer01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderable* self = (Renderable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVertexBuffer'", NULL);
#endif
  {
   VertexBuffer* tolua_ret = (VertexBuffer*)  self->GetVertexBuffer();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"VertexBuffer");
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_Renderable_GetVertexBuffer00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIndexBuffer of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_SetIndexBuffer00
static int tolua_PX2_Renderable_SetIndexBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderable",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"IndexBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderable* self = (Renderable*)  tolua_tousertype(tolua_S,1,0);
  IndexBuffer* ibuffer = ((IndexBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIndexBuffer'", NULL);
#endif
  {
   self->SetIndexBuffer(ibuffer);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIndexBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIndexBuffer of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_GetIndexBuffer00
static int tolua_PX2_Renderable_GetIndexBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderable* self = (const Renderable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIndexBuffer'", NULL);
#endif
  {
   const IndexBuffer* tolua_ret = (const IndexBuffer*)  self->GetIndexBuffer();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const IndexBuffer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIndexBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIndexBuffer of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_GetIndexBuffer01
static int tolua_PX2_Renderable_GetIndexBuffer01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderable* self = (Renderable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIndexBuffer'", NULL);
#endif
  {
   IndexBuffer* tolua_ret = (IndexBuffer*)  self->GetIndexBuffer();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"IndexBuffer");
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_Renderable_GetIndexBuffer00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetModelBound of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_GetModelBound00
static int tolua_PX2_Renderable_GetModelBound00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderable* self = (const Renderable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetModelBound'", NULL);
#endif
  {
   const Bound& tolua_ret = (const Bound&)  self->GetModelBound();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Bound");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetModelBound'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetModelBound of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_GetModelBound01
static int tolua_PX2_Renderable_GetModelBound01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderable* self = (Renderable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetModelBound'", NULL);
#endif
  {
   Bound& tolua_ret = (Bound&)  self->GetModelBound();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Bound");
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_Renderable_GetModelBound00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddRenderUsage of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_AddRenderUsage00
static int tolua_PX2_Renderable_AddRenderUsage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderable* self = (Renderable*)  tolua_tousertype(tolua_S,1,0);
  Renderable::RenderUsage usage = ((Renderable::RenderUsage) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddRenderUsage'", NULL);
#endif
  {
   self->AddRenderUsage(usage);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddRenderUsage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveRenderUsage of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_RemoveRenderUsage00
static int tolua_PX2_Renderable_RemoveRenderUsage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderable* self = (Renderable*)  tolua_tousertype(tolua_S,1,0);
  Renderable::RenderUsage usage = ((Renderable::RenderUsage) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveRenderUsage'", NULL);
#endif
  {
   self->RemoveRenderUsage(usage);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveRenderUsage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRenderUsage of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_GetRenderUsage00
static int tolua_PX2_Renderable_GetRenderUsage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderable* self = (Renderable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRenderUsage'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->GetRenderUsage();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRenderUsage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRenderLayer of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_SetRenderLayer00
static int tolua_PX2_Renderable_SetRenderLayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderable* self = (Renderable*)  tolua_tousertype(tolua_S,1,0);
  Renderable::RenderLayer layer = ((Renderable::RenderLayer) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRenderLayer'", NULL);
#endif
  {
   self->SetRenderLayer(layer);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRenderLayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSortIndex of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_GetSortIndex00
static int tolua_PX2_Renderable_GetSortIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderable* self = (Renderable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSortIndex'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->GetSortIndex();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSortIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaterialInstance of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_SetMaterialInstance00
static int tolua_PX2_Renderable_SetMaterialInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderable",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"MaterialInstance",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderable* self = (Renderable*)  tolua_tousertype(tolua_S,1,0);
  MaterialInstance* material = ((MaterialInstance*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaterialInstance'", NULL);
#endif
  {
   self->SetMaterialInstance(material);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaterialInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaterialInstance of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_GetMaterialInstance00
static int tolua_PX2_Renderable_GetMaterialInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderable* self = (const Renderable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaterialInstance'", NULL);
#endif
  {
   MaterialInstance* tolua_ret = (MaterialInstance*)  self->GetMaterialInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MaterialInstance");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaterialInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddLight of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_AddLight00
static int tolua_PX2_Renderable_AddLight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderable",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderable* self = (Renderable*)  tolua_tousertype(tolua_S,1,0);
  Light* light = ((Light*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddLight'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->AddLight(light);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddLight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveLight of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_RemoveLight00
static int tolua_PX2_Renderable_RemoveLight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderable",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Light",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderable* self = (Renderable*)  tolua_tousertype(tolua_S,1,0);
  Light* light = ((Light*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveLight'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->RemoveLight(light);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveLight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearLights of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_ClearLights00
static int tolua_PX2_Renderable_ClearLights00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderable* self = (Renderable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearLights'", NULL);
#endif
  {
   self->ClearLights();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearLights'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumLights of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_GetNumLights00
static int tolua_PX2_Renderable_GetNumLights00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderable* self = (Renderable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumLights'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetNumLights();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumLights'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLight of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_GetLight00
static int tolua_PX2_Renderable_GetLight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderable* self = (Renderable*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLight'", NULL);
#endif
  {
   Light* tolua_ret = (Light*)  self->GetLight(i);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Light");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UpdateModelSpace of class  Renderable */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderable_UpdateModelSpace00
static int tolua_PX2_Renderable_UpdateModelSpace00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderable* self = (Renderable*)  tolua_tousertype(tolua_S,1,0);
  Renderable::UpdateType type = ((Renderable::UpdateType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UpdateModelSpace'", NULL);
#endif
  {
   self->UpdateModelSpace(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UpdateModelSpace'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Triangles */
#ifndef TOLUA_DISABLE_tolua_PX2_Triangles_delete00
static int tolua_PX2_Triangles_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Triangles",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Triangles* self = (Triangles*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetNumTriangles of class  Triangles */
#ifndef TOLUA_DISABLE_tolua_PX2_Triangles_GetNumTriangles00
static int tolua_PX2_Triangles_GetNumTriangles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Triangles",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Triangles* self = (const Triangles*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumTriangles'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetNumTriangles();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumTriangles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTriangle of class  Triangles */
#ifndef TOLUA_DISABLE_tolua_PX2_Triangles_GetTriangle00
static int tolua_PX2_Triangles_GetTriangle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Triangles",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Triangles* self = (const Triangles*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  int v0 = ((int)  tolua_tonumber(tolua_S,3,0));
  int v1 = ((int)  tolua_tonumber(tolua_S,4,0));
  int v2 = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTriangle'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetTriangle(i,v0,v1,v2);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)v0);
   tolua_pushnumber(tolua_S,(lua_Number)v1);
   tolua_pushnumber(tolua_S,(lua_Number)v2);
  }
 }
 return 4;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTriangle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetModelTriangle of class  Triangles */
#ifndef TOLUA_DISABLE_tolua_PX2_Triangles_GetModelTriangle00
static int tolua_PX2_Triangles_GetModelTriangle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Triangles",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"APoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Triangles* self = (const Triangles*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  APoint* modelTriangle = ((APoint*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetModelTriangle'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetModelTriangle(i,modelTriangle);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetModelTriangle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWorldTriangle of class  Triangles */
#ifndef TOLUA_DISABLE_tolua_PX2_Triangles_GetWorldTriangle00
static int tolua_PX2_Triangles_GetWorldTriangle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Triangles",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"APoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Triangles* self = (const Triangles*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  APoint* worldTriangle = ((APoint*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWorldTriangle'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetWorldTriangle(i,worldTriangle);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWorldTriangle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumVertices of class  Triangles */
#ifndef TOLUA_DISABLE_tolua_PX2_Triangles_GetNumVertices00
static int tolua_PX2_Triangles_GetNumVertices00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Triangles",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Triangles* self = (const Triangles*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumVertices'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetNumVertices();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumVertices'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWorldTransform of class  Triangles */
#ifndef TOLUA_DISABLE_tolua_PX2_Triangles_GetWorldTransform00
static int tolua_PX2_Triangles_GetWorldTransform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Triangles",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Triangles* self = (const Triangles*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWorldTransform'", NULL);
#endif
  {
   const Transform& tolua_ret = (const Transform&)  self->GetWorldTransform();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Transform");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWorldTransform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPosition of class  Triangles */
#ifndef TOLUA_DISABLE_tolua_PX2_Triangles_GetPosition00
static int tolua_PX2_Triangles_GetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Triangles",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Triangles* self = (const Triangles*)  tolua_tousertype(tolua_S,1,0);
  int v = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPosition'", NULL);
#endif
  {
   Float3 tolua_ret = (Float3)  self->GetPosition(v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Float3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Float3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Float3));
     tolua_pushusertype(tolua_S,tolua_obj,"Float3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UpdateModelSpace of class  Triangles */
#ifndef TOLUA_DISABLE_tolua_PX2_Triangles_UpdateModelSpace00
static int tolua_PX2_Triangles_UpdateModelSpace00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Triangles",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Triangles* self = (Triangles*)  tolua_tousertype(tolua_S,1,0);
  Renderable::UpdateType type = ((Renderable::UpdateType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UpdateModelSpace'", NULL);
#endif
  {
   self->UpdateModelSpace(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UpdateModelSpace'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  TriMesh */
#ifndef TOLUA_DISABLE_tolua_PX2_TriMesh_new00
static int tolua_PX2_TriMesh_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TriMesh",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"VertexFormat",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"VertexBuffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"IndexBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VertexFormat* vformat = ((VertexFormat*)  tolua_tousertype(tolua_S,2,0));
  VertexBuffer* vbuffer = ((VertexBuffer*)  tolua_tousertype(tolua_S,3,0));
  IndexBuffer* ibuffer = ((IndexBuffer*)  tolua_tousertype(tolua_S,4,0));
  {
   TriMesh* tolua_ret = (TriMesh*)  Mtolua_new((TriMesh)(vformat,vbuffer,ibuffer));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TriMesh");
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

/* method: new_local of class  TriMesh */
#ifndef TOLUA_DISABLE_tolua_PX2_TriMesh_new00_local
static int tolua_PX2_TriMesh_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TriMesh",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"VertexFormat",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"VertexBuffer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"IndexBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VertexFormat* vformat = ((VertexFormat*)  tolua_tousertype(tolua_S,2,0));
  VertexBuffer* vbuffer = ((VertexBuffer*)  tolua_tousertype(tolua_S,3,0));
  IndexBuffer* ibuffer = ((IndexBuffer*)  tolua_tousertype(tolua_S,4,0));
  {
   TriMesh* tolua_ret = (TriMesh*)  Mtolua_new((TriMesh)(vformat,vbuffer,ibuffer));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TriMesh");
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

/* method: delete of class  TriMesh */
#ifndef TOLUA_DISABLE_tolua_PX2_TriMesh_delete00
static int tolua_PX2_TriMesh_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TriMesh",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TriMesh* self = (TriMesh*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetNumTriangles of class  TriMesh */
#ifndef TOLUA_DISABLE_tolua_PX2_TriMesh_GetNumTriangles00
static int tolua_PX2_TriMesh_GetNumTriangles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TriMesh",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TriMesh* self = (const TriMesh*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumTriangles'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetNumTriangles();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumTriangles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTriangle of class  TriMesh */
#ifndef TOLUA_DISABLE_tolua_PX2_TriMesh_GetTriangle00
static int tolua_PX2_TriMesh_GetTriangle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TriMesh",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TriMesh* self = (const TriMesh*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  int v0 = ((int)  tolua_tonumber(tolua_S,3,0));
  int v1 = ((int)  tolua_tonumber(tolua_S,4,0));
  int v2 = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTriangle'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetTriangle(i,v0,v1,v2);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)v0);
   tolua_pushnumber(tolua_S,(lua_Number)v1);
   tolua_pushnumber(tolua_S,(lua_Number)v2);
  }
 }
 return 4;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTriangle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SwitchNode */
#ifndef TOLUA_DISABLE_tolua_PX2_SwitchNode_new00
static int tolua_PX2_SwitchNode_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SwitchNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SwitchNode* tolua_ret = (SwitchNode*)  Mtolua_new((SwitchNode)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SwitchNode");
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

/* method: new_local of class  SwitchNode */
#ifndef TOLUA_DISABLE_tolua_PX2_SwitchNode_new00_local
static int tolua_PX2_SwitchNode_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SwitchNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SwitchNode* tolua_ret = (SwitchNode*)  Mtolua_new((SwitchNode)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SwitchNode");
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

/* method: delete of class  SwitchNode */
#ifndef TOLUA_DISABLE_tolua_PX2_SwitchNode_delete00
static int tolua_PX2_SwitchNode_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SwitchNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SwitchNode* self = (SwitchNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Create of class  SwitchNode */
#ifndef TOLUA_DISABLE_tolua_PX2_SwitchNode_Create00
static int tolua_PX2_SwitchNode_Create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SwitchNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SwitchNode* tolua_ret = (SwitchNode*)  SwitchNode::Create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SwitchNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetActiveChild of class  SwitchNode */
#ifndef TOLUA_DISABLE_tolua_PX2_SwitchNode_SetActiveChild00
static int tolua_PX2_SwitchNode_SetActiveChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SwitchNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SwitchNode* self = (SwitchNode*)  tolua_tousertype(tolua_S,1,0);
  int activeChild = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetActiveChild'", NULL);
#endif
  {
   self->SetActiveChild(activeChild);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetActiveChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetActiveChild of class  SwitchNode */
#ifndef TOLUA_DISABLE_tolua_PX2_SwitchNode_GetActiveChild00
static int tolua_PX2_SwitchNode_GetActiveChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const SwitchNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const SwitchNode* self = (const SwitchNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetActiveChild'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetActiveChild();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetActiveChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DisableAllChildren of class  SwitchNode */
#ifndef TOLUA_DISABLE_tolua_PX2_SwitchNode_DisableAllChildren00
static int tolua_PX2_SwitchNode_DisableAllChildren00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SwitchNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SwitchNode* self = (SwitchNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DisableAllChildren'", NULL);
#endif
  {
   self->DisableAllChildren();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DisableAllChildren'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_new00
static int tolua_PX2_Camera_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Camera",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  bool isPerspective = ((bool)  tolua_toboolean(tolua_S,2,true));
  {
   Camera* tolua_ret = (Camera*)  Mtolua_new((Camera)(isPerspective));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Camera");
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

/* method: new_local of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_new00_local
static int tolua_PX2_Camera_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Camera",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  bool isPerspective = ((bool)  tolua_toboolean(tolua_S,2,true));
  {
   Camera* tolua_ret = (Camera*)  Mtolua_new((Camera)(isPerspective));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Camera");
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

/* method: delete of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_delete00
static int tolua_PX2_Camera_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetFrame of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_SetFrame00
static int tolua_PX2_Camera_SetFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const AVector",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const AVector",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
  const APoint* position = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
  const AVector* dVector = ((const AVector*)  tolua_tousertype(tolua_S,3,0));
  const AVector* uVector = ((const AVector*)  tolua_tousertype(tolua_S,4,0));
  const AVector* rVector = ((const AVector*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFrame'", NULL);
#endif
  {
   self->SetFrame(*position,*dVector,*uVector,*rVector);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_SetPosition00
static int tolua_PX2_Camera_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
  const APoint* position = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(*position);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAxes of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_SetAxes00
static int tolua_PX2_Camera_SetAxes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AVector",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const AVector",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
  const AVector* dVector = ((const AVector*)  tolua_tousertype(tolua_S,2,0));
  const AVector* uVector = ((const AVector*)  tolua_tousertype(tolua_S,3,0));
  const AVector* rVector = ((const AVector*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAxes'", NULL);
#endif
  {
   self->SetAxes(*dVector,*uVector,*rVector);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAxes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPosition of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_GetPosition00
static int tolua_PX2_Camera_GetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Camera* self = (const Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPosition'", NULL);
#endif
  {
   APoint tolua_ret = (APoint)  self->GetPosition();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((APoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"APoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(APoint));
     tolua_pushusertype(tolua_S,tolua_obj,"APoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDVector of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_GetDVector00
static int tolua_PX2_Camera_GetDVector00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Camera* self = (const Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDVector'", NULL);
#endif
  {
   AVector tolua_ret = (AVector)  self->GetDVector();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((AVector)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(AVector));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUVector of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_GetUVector00
static int tolua_PX2_Camera_GetUVector00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Camera* self = (const Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUVector'", NULL);
#endif
  {
   AVector tolua_ret = (AVector)  self->GetUVector();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((AVector)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(AVector));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRVector of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_GetRVector00
static int tolua_PX2_Camera_GetRVector00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Camera* self = (const Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRVector'", NULL);
#endif
  {
   AVector tolua_ret = (AVector)  self->GetRVector();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((AVector)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(AVector));
     tolua_pushusertype(tolua_S,tolua_obj,"AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetViewMatrix of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_GetViewMatrix00
static int tolua_PX2_Camera_GetViewMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Camera* self = (const Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetViewMatrix'", NULL);
#endif
  {
   const HMatrix& tolua_ret = (const HMatrix&)  self->GetViewMatrix();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const HMatrix");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetViewMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsPerspective of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_IsPerspective00
static int tolua_PX2_Camera_IsPerspective00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Camera* self = (const Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsPerspective'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsPerspective();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsPerspective'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFrustum of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_SetFrustum00
static int tolua_PX2_Camera_SetFrustum00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Camera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
  float dMin = ((float)  tolua_tonumber(tolua_S,2,0));
  float dMax = ((float)  tolua_tonumber(tolua_S,3,0));
  float uMin = ((float)  tolua_tonumber(tolua_S,4,0));
  float uMax = ((float)  tolua_tonumber(tolua_S,5,0));
  float rMin = ((float)  tolua_tonumber(tolua_S,6,0));
  float rMax = ((float)  tolua_tonumber(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFrustum'", NULL);
#endif
  {
   self->SetFrustum(dMin,dMax,uMin,uMax,rMin,rMax);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFrustum'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFrustum of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_SetFrustum01
static int tolua_PX2_Camera_SetFrustum01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Camera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
  const float frustum = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFrustum'", NULL);
#endif
  {
   self->SetFrustum(&frustum);
   tolua_pushnumber(tolua_S,(lua_Number)frustum);
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_Camera_SetFrustum00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFrustum of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_SetFrustum02
static int tolua_PX2_Camera_SetFrustum02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Camera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
  float upFovDegrees = ((float)  tolua_tonumber(tolua_S,2,0));
  float aspectRatio = ((float)  tolua_tonumber(tolua_S,3,0));
  float dMin = ((float)  tolua_tonumber(tolua_S,4,0));
  float dMax = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFrustum'", NULL);
#endif
  {
   self->SetFrustum(upFovDegrees,aspectRatio,dMin,dMax);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Camera_SetFrustum01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFrustum of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_GetFrustum00
static int tolua_PX2_Camera_GetFrustum00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Camera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Camera* self = (const Camera*)  tolua_tousertype(tolua_S,1,0);
  float dMin = ((float)  tolua_tonumber(tolua_S,2,0));
  float dMax = ((float)  tolua_tonumber(tolua_S,3,0));
  float uMin = ((float)  tolua_tonumber(tolua_S,4,0));
  float uMax = ((float)  tolua_tonumber(tolua_S,5,0));
  float rMin = ((float)  tolua_tonumber(tolua_S,6,0));
  float rMax = ((float)  tolua_tonumber(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFrustum'", NULL);
#endif
  {
   self->GetFrustum(dMin,dMax,uMin,uMax,rMin,rMax);
   tolua_pushnumber(tolua_S,(lua_Number)dMin);
   tolua_pushnumber(tolua_S,(lua_Number)dMax);
   tolua_pushnumber(tolua_S,(lua_Number)uMin);
   tolua_pushnumber(tolua_S,(lua_Number)uMax);
   tolua_pushnumber(tolua_S,(lua_Number)rMin);
   tolua_pushnumber(tolua_S,(lua_Number)rMax);
  }
 }
 return 6;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFrustum'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFrustum of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_GetFrustum01
static int tolua_PX2_Camera_GetFrustum01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Camera* self = (const Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFrustum'", NULL);
#endif
  {
   const void* tolua_ret = (const void*)  self->GetFrustum();
   tolua_pushuserdata(tolua_S,(void*)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_Camera_GetFrustum00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFrustum of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_GetFrustum02
static int tolua_PX2_Camera_GetFrustum02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Camera",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Camera* self = (const Camera*)  tolua_tousertype(tolua_S,1,0);
  float upFovDegrees = ((float)  tolua_tonumber(tolua_S,2,0));
  float aspectRatio = ((float)  tolua_tonumber(tolua_S,3,0));
  float dMin = ((float)  tolua_tonumber(tolua_S,4,0));
  float dMax = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFrustum'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetFrustum(upFovDegrees,aspectRatio,dMin,dMax);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)upFovDegrees);
   tolua_pushnumber(tolua_S,(lua_Number)aspectRatio);
   tolua_pushnumber(tolua_S,(lua_Number)dMin);
   tolua_pushnumber(tolua_S,(lua_Number)dMax);
  }
 }
 return 5;
tolua_lerror:
 return tolua_PX2_Camera_GetFrustum01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDMin of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_GetDMin00
static int tolua_PX2_Camera_GetDMin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Camera* self = (const Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDMin'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetDMin();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDMin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDMax of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_GetDMax00
static int tolua_PX2_Camera_GetDMax00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Camera* self = (const Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDMax'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetDMax();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDMax'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUMin of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_GetUMin00
static int tolua_PX2_Camera_GetUMin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Camera* self = (const Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUMin'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetUMin();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUMin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUMax of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_GetUMax00
static int tolua_PX2_Camera_GetUMax00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Camera* self = (const Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUMax'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetUMax();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUMax'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRMin of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_GetRMin00
static int tolua_PX2_Camera_GetRMin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Camera* self = (const Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRMin'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetRMin();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRMin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRMax of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_GetRMax00
static int tolua_PX2_Camera_GetRMax00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Camera* self = (const Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRMax'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetRMax();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRMax'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDepthType of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_GetDepthType00
static int tolua_PX2_Camera_GetDepthType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Camera* self = (const Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDepthType'", NULL);
#endif
  {
   Camera::DepthType tolua_ret = (Camera::DepthType)  self->GetDepthType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDepthType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetProjectionMatrix of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_GetProjectionMatrix00
static int tolua_PX2_Camera_GetProjectionMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Camera* self = (const Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetProjectionMatrix'", NULL);
#endif
  {
   const HMatrix& tolua_ret = (const HMatrix&)  self->GetProjectionMatrix();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const HMatrix");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetProjectionMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetProjectionViewMatrix of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_GetProjectionViewMatrix00
static int tolua_PX2_Camera_GetProjectionViewMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Camera* self = (const Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetProjectionViewMatrix'", NULL);
#endif
  {
   const HMatrix& tolua_ret = (const HMatrix&)  self->GetProjectionViewMatrix();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const HMatrix");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetProjectionViewMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPreViewMatrix of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_SetPreViewMatrix00
static int tolua_PX2_Camera_SetPreViewMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const HMatrix",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
  const HMatrix* preViewMatrix = ((const HMatrix*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPreViewMatrix'", NULL);
#endif
  {
   self->SetPreViewMatrix(*preViewMatrix);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPreViewMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPreViewMatrix of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_GetPreViewMatrix00
static int tolua_PX2_Camera_GetPreViewMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Camera* self = (const Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPreViewMatrix'", NULL);
#endif
  {
   const HMatrix& tolua_ret = (const HMatrix&)  self->GetPreViewMatrix();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const HMatrix");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPreViewMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PreViewIsIdentity of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_PreViewIsIdentity00
static int tolua_PX2_Camera_PreViewIsIdentity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Camera* self = (const Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PreViewIsIdentity'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->PreViewIsIdentity();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PreViewIsIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPostProjectionMatrix of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_SetPostProjectionMatrix00
static int tolua_PX2_Camera_SetPostProjectionMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const HMatrix",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Camera* self = (Camera*)  tolua_tousertype(tolua_S,1,0);
  const HMatrix* postProjMatrix = ((const HMatrix*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPostProjectionMatrix'", NULL);
#endif
  {
   self->SetPostProjectionMatrix(*postProjMatrix);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPostProjectionMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPostProjectionMatrix of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_GetPostProjectionMatrix00
static int tolua_PX2_Camera_GetPostProjectionMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Camera* self = (const Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPostProjectionMatrix'", NULL);
#endif
  {
   const HMatrix& tolua_ret = (const HMatrix&)  self->GetPostProjectionMatrix();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const HMatrix");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPostProjectionMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PostProjectionIsIdentity of class  Camera */
#ifndef TOLUA_DISABLE_tolua_PX2_Camera_PostProjectionIsIdentity00
static int tolua_PX2_Camera_PostProjectionIsIdentity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Camera* self = (const Camera*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PostProjectionIsIdentity'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->PostProjectionIsIdentity();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PostProjectionIsIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Initialize of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Initialize00
static int tolua_PX2_Renderer_Initialize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"Texture::Format",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"Texture::Format",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
  Texture::Format colorFormat = *((Texture::Format*)  tolua_tousertype(tolua_S,4,0));
  Texture::Format depthStencilFormat = *((Texture::Format*)  tolua_tousertype(tolua_S,5,0));
  int numMultisamples = ((int)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Initialize'", NULL);
#endif
  {
   self->Initialize(width,height,colorFormat,depthStencilFormat,numMultisamples);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Initialize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Terminate of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Terminate00
static int tolua_PX2_Renderer_Terminate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Terminate'", NULL);
#endif
  {
   self->Terminate();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Terminate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDefaultRenderer of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_SetDefaultRenderer00
static int tolua_PX2_Renderer_SetDefaultRenderer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* renderer = ((Renderer*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::SetDefaultRenderer(renderer);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDefaultRenderer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDefaultRenderer of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetDefaultRenderer00
static int tolua_PX2_Renderer_GetDefaultRenderer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Renderer* tolua_ret = (Renderer*)  Renderer::GetDefaultRenderer();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Renderer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDefaultRenderer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWidth of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetWidth00
static int tolua_PX2_Renderer_GetWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWidth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHeight of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetHeight00
static int tolua_PX2_Renderer_GetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHeight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetColorFormat of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetColorFormat00
static int tolua_PX2_Renderer_GetColorFormat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetColorFormat'", NULL);
#endif
  {
   Texture::Format tolua_ret = (Texture::Format)  self->GetColorFormat();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Texture::Format)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Texture::Format");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Texture::Format));
     tolua_pushusertype(tolua_S,tolua_obj,"Texture::Format");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetColorFormat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDepthStencilFormat of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetDepthStencilFormat00
static int tolua_PX2_Renderer_GetDepthStencilFormat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDepthStencilFormat'", NULL);
#endif
  {
   Texture::Format tolua_ret = (Texture::Format)  self->GetDepthStencilFormat();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Texture::Format)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Texture::Format");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Texture::Format));
     tolua_pushusertype(tolua_S,tolua_obj,"Texture::Format");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDepthStencilFormat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumMultisamples of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetNumMultisamples00
static int tolua_PX2_Renderer_GetNumMultisamples00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumMultisamples'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetNumMultisamples();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumMultisamples'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Bind of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Bind00
static int tolua_PX2_Renderer_Bind00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const VertexFormat",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const VertexFormat* vformat = ((const VertexFormat*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Bind'", NULL);
#endif
  {
   self->Bind(vformat);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Bind'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BindAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_BindAll00
static int tolua_PX2_Renderer_BindAll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const VertexFormat",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const VertexFormat* vformat = ((const VertexFormat*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::BindAll(vformat);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BindAll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Unbind of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Unbind00
static int tolua_PX2_Renderer_Unbind00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const VertexFormat",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const VertexFormat* vformat = ((const VertexFormat*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Unbind'", NULL);
#endif
  {
   self->Unbind(vformat);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Unbind'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UnbindAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_UnbindAll00
static int tolua_PX2_Renderer_UnbindAll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const VertexFormat",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const VertexFormat* vformat = ((const VertexFormat*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::UnbindAll(vformat);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UnbindAll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Enable of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Enable00
static int tolua_PX2_Renderer_Enable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const VertexFormat",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const VertexFormat* vformat = ((const VertexFormat*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Enable'", NULL);
#endif
  {
   self->Enable(vformat);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Enable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Disable of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Disable00
static int tolua_PX2_Renderer_Disable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const VertexFormat",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const VertexFormat* vformat = ((const VertexFormat*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Disable'", NULL);
#endif
  {
   self->Disable(vformat);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Disable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Bind of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Bind01
static int tolua_PX2_Renderer_Bind01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const VertexBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const VertexBuffer* vbuffer = ((const VertexBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Bind'", NULL);
#endif
  {
   self->Bind(vbuffer);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Bind00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: BindAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_BindAll01
static int tolua_PX2_Renderer_BindAll01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const VertexBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const VertexBuffer* vbuffer = ((const VertexBuffer*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::BindAll(vbuffer);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_BindAll00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Unbind of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Unbind01
static int tolua_PX2_Renderer_Unbind01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const VertexBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const VertexBuffer* vbuffer = ((const VertexBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Unbind'", NULL);
#endif
  {
   self->Unbind(vbuffer);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Unbind00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UnbindAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_UnbindAll01
static int tolua_PX2_Renderer_UnbindAll01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const VertexBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const VertexBuffer* vbuffer = ((const VertexBuffer*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::UnbindAll(vbuffer);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_UnbindAll00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Enable of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Enable01
static int tolua_PX2_Renderer_Enable01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const VertexBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const VertexBuffer* vbuffer = ((const VertexBuffer*)  tolua_tousertype(tolua_S,2,0));
  unsigned int streamIndex = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  unsigned int offset = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Enable'", NULL);
#endif
  {
   self->Enable(vbuffer,streamIndex,offset);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Enable00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Disable of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Disable01
static int tolua_PX2_Renderer_Disable01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const VertexBuffer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const VertexBuffer* vbuffer = ((const VertexBuffer*)  tolua_tousertype(tolua_S,2,0));
  unsigned int streamIndex = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Disable'", NULL);
#endif
  {
   self->Disable(vbuffer,streamIndex);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Disable00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lock of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Lock00
static int tolua_PX2_Renderer_Lock00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const VertexBuffer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Buffer::Locking",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const VertexBuffer* vbuffer = ((const VertexBuffer*)  tolua_tousertype(tolua_S,2,0));
  Buffer::Locking mode = *((Buffer::Locking*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lock'", NULL);
#endif
  {
   void* tolua_ret = (void*)  self->Lock(vbuffer,mode);
   tolua_pushuserdata(tolua_S,(void*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Lock'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Unlock of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Unlock00
static int tolua_PX2_Renderer_Unlock00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const VertexBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const VertexBuffer* vbuffer = ((const VertexBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Unlock'", NULL);
#endif
  {
   self->Unlock(vbuffer);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Unlock'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Update00
static int tolua_PX2_Renderer_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const VertexBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const VertexBuffer* vbuffer = ((const VertexBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(vbuffer);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UpdateAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_UpdateAll00
static int tolua_PX2_Renderer_UpdateAll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const VertexBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const VertexBuffer* vbuffer = ((const VertexBuffer*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::UpdateAll(vbuffer);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UpdateAll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Bind of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Bind02
static int tolua_PX2_Renderer_Bind02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const IndexBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const IndexBuffer* ibuffer = ((const IndexBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Bind'", NULL);
#endif
  {
   self->Bind(ibuffer);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Bind01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: BindAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_BindAll02
static int tolua_PX2_Renderer_BindAll02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const IndexBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const IndexBuffer* ibuffer = ((const IndexBuffer*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::BindAll(ibuffer);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_BindAll01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Unbind of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Unbind02
static int tolua_PX2_Renderer_Unbind02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const IndexBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const IndexBuffer* ibuffer = ((const IndexBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Unbind'", NULL);
#endif
  {
   self->Unbind(ibuffer);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Unbind01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UnbindAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_UnbindAll02
static int tolua_PX2_Renderer_UnbindAll02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const IndexBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const IndexBuffer* ibuffer = ((const IndexBuffer*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::UnbindAll(ibuffer);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_UnbindAll01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Enable of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Enable02
static int tolua_PX2_Renderer_Enable02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const IndexBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const IndexBuffer* ibuffer = ((const IndexBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Enable'", NULL);
#endif
  {
   self->Enable(ibuffer);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Enable01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Disable of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Disable02
static int tolua_PX2_Renderer_Disable02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const IndexBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const IndexBuffer* ibuffer = ((const IndexBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Disable'", NULL);
#endif
  {
   self->Disable(ibuffer);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Disable01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lock of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Lock01
static int tolua_PX2_Renderer_Lock01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const IndexBuffer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Buffer::Locking",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const IndexBuffer* ibuffer = ((const IndexBuffer*)  tolua_tousertype(tolua_S,2,0));
  Buffer::Locking mode = *((Buffer::Locking*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lock'", NULL);
#endif
  {
   void* tolua_ret = (void*)  self->Lock(ibuffer,mode);
   tolua_pushuserdata(tolua_S,(void*)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_Renderer_Lock00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Unlock of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Unlock01
static int tolua_PX2_Renderer_Unlock01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const IndexBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const IndexBuffer* ibuffer = ((const IndexBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Unlock'", NULL);
#endif
  {
   self->Unlock(ibuffer);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Unlock00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Update01
static int tolua_PX2_Renderer_Update01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const IndexBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const IndexBuffer* ibuffer = ((const IndexBuffer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(ibuffer);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Update00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UpdateAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_UpdateAll01
static int tolua_PX2_Renderer_UpdateAll01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const IndexBuffer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const IndexBuffer* ibuffer = ((const IndexBuffer*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::UpdateAll(ibuffer);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_UpdateAll00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Bind of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Bind03
static int tolua_PX2_Renderer_Bind03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture1D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Texture1D* texture = ((const Texture1D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Bind'", NULL);
#endif
  {
   self->Bind(texture);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Bind02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: BindAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_BindAll03
static int tolua_PX2_Renderer_BindAll03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture1D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Texture1D* texture = ((const Texture1D*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::BindAll(texture);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_BindAll02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Unbind of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Unbind03
static int tolua_PX2_Renderer_Unbind03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture1D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Texture1D* texture = ((const Texture1D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Unbind'", NULL);
#endif
  {
   self->Unbind(texture);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Unbind02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UnbindAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_UnbindAll03
static int tolua_PX2_Renderer_UnbindAll03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture1D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Texture1D* texture = ((const Texture1D*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::UnbindAll(texture);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_UnbindAll02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Enable of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Enable03
static int tolua_PX2_Renderer_Enable03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture1D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Texture1D* texture = ((const Texture1D*)  tolua_tousertype(tolua_S,2,0));
  int textureUnit = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Enable'", NULL);
#endif
  {
   self->Enable(texture,textureUnit);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Enable02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Disable of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Disable03
static int tolua_PX2_Renderer_Disable03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture1D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Texture1D* texture = ((const Texture1D*)  tolua_tousertype(tolua_S,2,0));
  int textureUnit = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Disable'", NULL);
#endif
  {
   self->Disable(texture,textureUnit);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Disable02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lock of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Lock02
static int tolua_PX2_Renderer_Lock02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture1D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"Buffer::Locking",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Texture1D* texture = ((const Texture1D*)  tolua_tousertype(tolua_S,2,0));
  int level = ((int)  tolua_tonumber(tolua_S,3,0));
  Buffer::Locking mode = *((Buffer::Locking*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lock'", NULL);
#endif
  {
   void* tolua_ret = (void*)  self->Lock(texture,level,mode);
   tolua_pushuserdata(tolua_S,(void*)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_Renderer_Lock01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Unlock of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Unlock02
static int tolua_PX2_Renderer_Unlock02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture1D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Texture1D* texture = ((const Texture1D*)  tolua_tousertype(tolua_S,2,0));
  int level = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Unlock'", NULL);
#endif
  {
   self->Unlock(texture,level);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Unlock01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Update02
static int tolua_PX2_Renderer_Update02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture1D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Texture1D* texture = ((const Texture1D*)  tolua_tousertype(tolua_S,2,0));
  int level = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(texture,level);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Update01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UpdateAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_UpdateAll02
static int tolua_PX2_Renderer_UpdateAll02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture1D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Texture1D* texture = ((const Texture1D*)  tolua_tousertype(tolua_S,2,0));
  int level = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   Renderer::UpdateAll(texture,level);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_UpdateAll01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Bind of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Bind04
static int tolua_PX2_Renderer_Bind04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Texture2D* texture = ((const Texture2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Bind'", NULL);
#endif
  {
   self->Bind(texture);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Bind03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: BindAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_BindAll04
static int tolua_PX2_Renderer_BindAll04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Texture2D* texture = ((const Texture2D*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::BindAll(texture);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_BindAll03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Unbind of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Unbind04
static int tolua_PX2_Renderer_Unbind04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Texture2D* texture = ((const Texture2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Unbind'", NULL);
#endif
  {
   self->Unbind(texture);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Unbind03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UnbindAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_UnbindAll04
static int tolua_PX2_Renderer_UnbindAll04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Texture2D* texture = ((const Texture2D*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::UnbindAll(texture);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_UnbindAll03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Enable of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Enable04
static int tolua_PX2_Renderer_Enable04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Texture2D* texture = ((const Texture2D*)  tolua_tousertype(tolua_S,2,0));
  int textureUnit = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Enable'", NULL);
#endif
  {
   self->Enable(texture,textureUnit);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Enable03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Enable of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Enable05
static int tolua_PX2_Renderer_Enable05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Texture2D* texture = ((const Texture2D*)  tolua_tousertype(tolua_S,2,0));
  int textureUnit = ((int)  tolua_tonumber(tolua_S,3,0));
  int loc = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Enable'", NULL);
#endif
  {
   self->Enable(texture,textureUnit,loc);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Enable04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Disable of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Disable04
static int tolua_PX2_Renderer_Disable04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Texture2D* texture = ((const Texture2D*)  tolua_tousertype(tolua_S,2,0));
  int textureUnit = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Disable'", NULL);
#endif
  {
   self->Disable(texture,textureUnit);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Disable03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lock of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Lock03
static int tolua_PX2_Renderer_Lock03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"Buffer::Locking",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Texture2D* texture = ((const Texture2D*)  tolua_tousertype(tolua_S,2,0));
  int level = ((int)  tolua_tonumber(tolua_S,3,0));
  Buffer::Locking mode = *((Buffer::Locking*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lock'", NULL);
#endif
  {
   void* tolua_ret = (void*)  self->Lock(texture,level,mode);
   tolua_pushuserdata(tolua_S,(void*)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_Renderer_Lock02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Unlock of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Unlock03
static int tolua_PX2_Renderer_Unlock03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Texture2D* texture = ((const Texture2D*)  tolua_tousertype(tolua_S,2,0));
  int level = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Unlock'", NULL);
#endif
  {
   self->Unlock(texture,level);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Unlock02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Update03
static int tolua_PX2_Renderer_Update03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Texture2D* texture = ((const Texture2D*)  tolua_tousertype(tolua_S,2,0));
  int level = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(texture,level);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Update02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UpdateAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_UpdateAll03
static int tolua_PX2_Renderer_UpdateAll03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Texture2D* texture = ((const Texture2D*)  tolua_tousertype(tolua_S,2,0));
  int level = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   Renderer::UpdateAll(texture,level);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_UpdateAll02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Bind of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Bind05
static int tolua_PX2_Renderer_Bind05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Texture3D* texture = ((const Texture3D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Bind'", NULL);
#endif
  {
   self->Bind(texture);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Bind04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: BindAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_BindAll05
static int tolua_PX2_Renderer_BindAll05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Texture3D* texture = ((const Texture3D*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::BindAll(texture);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_BindAll04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Unbind of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Unbind05
static int tolua_PX2_Renderer_Unbind05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Texture3D* texture = ((const Texture3D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Unbind'", NULL);
#endif
  {
   self->Unbind(texture);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Unbind04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UnbindAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_UnbindAll05
static int tolua_PX2_Renderer_UnbindAll05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Texture3D* texture = ((const Texture3D*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::UnbindAll(texture);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_UnbindAll04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Enable of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Enable06
static int tolua_PX2_Renderer_Enable06(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Texture3D* texture = ((const Texture3D*)  tolua_tousertype(tolua_S,2,0));
  int textureUnit = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Enable'", NULL);
#endif
  {
   self->Enable(texture,textureUnit);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Enable05(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Disable of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Disable05
static int tolua_PX2_Renderer_Disable05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Texture3D* texture = ((const Texture3D*)  tolua_tousertype(tolua_S,2,0));
  int textureUnit = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Disable'", NULL);
#endif
  {
   self->Disable(texture,textureUnit);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Disable04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lock of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Lock04
static int tolua_PX2_Renderer_Lock04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"Buffer::Locking",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Texture3D* texture = ((const Texture3D*)  tolua_tousertype(tolua_S,2,0));
  int level = ((int)  tolua_tonumber(tolua_S,3,0));
  Buffer::Locking mode = *((Buffer::Locking*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lock'", NULL);
#endif
  {
   void* tolua_ret = (void*)  self->Lock(texture,level,mode);
   tolua_pushuserdata(tolua_S,(void*)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_Renderer_Lock03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Unlock of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Unlock04
static int tolua_PX2_Renderer_Unlock04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Texture3D* texture = ((const Texture3D*)  tolua_tousertype(tolua_S,2,0));
  int level = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Unlock'", NULL);
#endif
  {
   self->Unlock(texture,level);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Unlock03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Update04
static int tolua_PX2_Renderer_Update04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Texture3D* texture = ((const Texture3D*)  tolua_tousertype(tolua_S,2,0));
  int level = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(texture,level);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Update03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UpdateAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_UpdateAll04
static int tolua_PX2_Renderer_UpdateAll04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Texture3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Texture3D* texture = ((const Texture3D*)  tolua_tousertype(tolua_S,2,0));
  int level = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   Renderer::UpdateAll(texture,level);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_UpdateAll03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Bind of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Bind06
static int tolua_PX2_Renderer_Bind06(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TextureCube",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const TextureCube* texture = ((const TextureCube*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Bind'", NULL);
#endif
  {
   self->Bind(texture);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Bind05(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: BindAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_BindAll06
static int tolua_PX2_Renderer_BindAll06(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TextureCube",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const TextureCube* texture = ((const TextureCube*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::BindAll(texture);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_BindAll05(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Unbind of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Unbind06
static int tolua_PX2_Renderer_Unbind06(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TextureCube",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const TextureCube* texture = ((const TextureCube*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Unbind'", NULL);
#endif
  {
   self->Unbind(texture);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Unbind05(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UnbindAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_UnbindAll06
static int tolua_PX2_Renderer_UnbindAll06(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TextureCube",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const TextureCube* texture = ((const TextureCube*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::UnbindAll(texture);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_UnbindAll05(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Enable of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Enable07
static int tolua_PX2_Renderer_Enable07(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TextureCube",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const TextureCube* texture = ((const TextureCube*)  tolua_tousertype(tolua_S,2,0));
  int textureUnit = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Enable'", NULL);
#endif
  {
   self->Enable(texture,textureUnit);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Enable06(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Disable of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Disable06
static int tolua_PX2_Renderer_Disable06(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TextureCube",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const TextureCube* texture = ((const TextureCube*)  tolua_tousertype(tolua_S,2,0));
  int textureUnit = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Disable'", NULL);
#endif
  {
   self->Disable(texture,textureUnit);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Disable05(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Lock of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Lock05
static int tolua_PX2_Renderer_Lock05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TextureCube",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"Buffer::Locking",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const TextureCube* texture = ((const TextureCube*)  tolua_tousertype(tolua_S,2,0));
  int face = ((int)  tolua_tonumber(tolua_S,3,0));
  int level = ((int)  tolua_tonumber(tolua_S,4,0));
  Buffer::Locking mode = *((Buffer::Locking*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Lock'", NULL);
#endif
  {
   void* tolua_ret = (void*)  self->Lock(texture,face,level,mode);
   tolua_pushuserdata(tolua_S,(void*)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_Renderer_Lock04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Unlock of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Unlock05
static int tolua_PX2_Renderer_Unlock05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TextureCube",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const TextureCube* texture = ((const TextureCube*)  tolua_tousertype(tolua_S,2,0));
  int face = ((int)  tolua_tonumber(tolua_S,3,0));
  int level = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Unlock'", NULL);
#endif
  {
   self->Unlock(texture,face,level);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Unlock04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Update05
static int tolua_PX2_Renderer_Update05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TextureCube",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const TextureCube* texture = ((const TextureCube*)  tolua_tousertype(tolua_S,2,0));
  int face = ((int)  tolua_tonumber(tolua_S,3,0));
  int level = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(texture,face,level);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Update04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UpdateAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_UpdateAll05
static int tolua_PX2_Renderer_UpdateAll05(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TextureCube",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const TextureCube* texture = ((const TextureCube*)  tolua_tousertype(tolua_S,2,0));
  int face = ((int)  tolua_tonumber(tolua_S,3,0));
  int level = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   Renderer::UpdateAll(texture,face,level);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_UpdateAll04(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Bind of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Bind07
static int tolua_PX2_Renderer_Bind07(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const RenderTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const RenderTarget* renderTarget = ((const RenderTarget*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Bind'", NULL);
#endif
  {
   self->Bind(renderTarget);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Bind06(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: BindAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_BindAll07
static int tolua_PX2_Renderer_BindAll07(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const RenderTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const RenderTarget* renderTarget = ((const RenderTarget*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::BindAll(renderTarget);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_BindAll06(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Unbind of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Unbind07
static int tolua_PX2_Renderer_Unbind07(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const RenderTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const RenderTarget* renderTarget = ((const RenderTarget*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Unbind'", NULL);
#endif
  {
   self->Unbind(renderTarget);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Unbind06(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UnbindAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_UnbindAll07
static int tolua_PX2_Renderer_UnbindAll07(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const RenderTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const RenderTarget* renderTarget = ((const RenderTarget*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::UnbindAll(renderTarget);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_UnbindAll06(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Enable of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Enable08
static int tolua_PX2_Renderer_Enable08(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const RenderTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const RenderTarget* renderTarget = ((const RenderTarget*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Enable'", NULL);
#endif
  {
   self->Enable(renderTarget);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Enable07(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Disable of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Disable07
static int tolua_PX2_Renderer_Disable07(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const RenderTarget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const RenderTarget* renderTarget = ((const RenderTarget*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Disable'", NULL);
#endif
  {
   self->Disable(renderTarget);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Disable06(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReadColor of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_ReadColor00
static int tolua_PX2_Renderer_ReadColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const RenderTarget",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"Texture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  const RenderTarget* renderTarget = ((const RenderTarget*)  tolua_tousertype(tolua_S,3,0));
  Texture2D* texture = ((Texture2D*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReadColor'", NULL);
#endif
  {
   self->ReadColor(i,renderTarget,texture);
    tolua_pushusertype(tolua_S,(void*)texture,"Texture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReadColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Bind of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Bind08
static int tolua_PX2_Renderer_Bind08(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const VertexShader",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const VertexShader* vshader = ((const VertexShader*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Bind'", NULL);
#endif
  {
   self->Bind(vshader);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Bind07(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: BindAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_BindAll08
static int tolua_PX2_Renderer_BindAll08(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const VertexShader",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const VertexShader* vshader = ((const VertexShader*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::BindAll(vshader);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_BindAll07(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Unbind of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Unbind08
static int tolua_PX2_Renderer_Unbind08(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const VertexShader",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const VertexShader* vshader = ((const VertexShader*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Unbind'", NULL);
#endif
  {
   self->Unbind(vshader);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Unbind07(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UnbindAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_UnbindAll08
static int tolua_PX2_Renderer_UnbindAll08(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const VertexShader",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const VertexShader* vshader = ((const VertexShader*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::UnbindAll(vshader);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_UnbindAll07(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Enable of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Enable09
static int tolua_PX2_Renderer_Enable09(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const VertexShader",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const ShaderParameters",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const VertexShader* vshader = ((const VertexShader*)  tolua_tousertype(tolua_S,2,0));
  const ShaderParameters* parameters = ((const ShaderParameters*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Enable'", NULL);
#endif
  {
   self->Enable(vshader,parameters);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Enable08(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Disable of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Disable08
static int tolua_PX2_Renderer_Disable08(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const VertexShader",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const ShaderParameters",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const VertexShader* vshader = ((const VertexShader*)  tolua_tousertype(tolua_S,2,0));
  const ShaderParameters* parameters = ((const ShaderParameters*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Disable'", NULL);
#endif
  {
   self->Disable(vshader,parameters);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Disable07(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Bind of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Bind09
static int tolua_PX2_Renderer_Bind09(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const PixelShader",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const PixelShader* pshader = ((const PixelShader*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Bind'", NULL);
#endif
  {
   self->Bind(pshader);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Bind08(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: BindAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_BindAll09
static int tolua_PX2_Renderer_BindAll09(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const PixelShader",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const PixelShader* pshader = ((const PixelShader*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::BindAll(pshader);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_BindAll08(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Unbind of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Unbind09
static int tolua_PX2_Renderer_Unbind09(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const PixelShader",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const PixelShader* pshader = ((const PixelShader*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Unbind'", NULL);
#endif
  {
   self->Unbind(pshader);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Unbind08(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UnbindAll of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_UnbindAll09
static int tolua_PX2_Renderer_UnbindAll09(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const PixelShader",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const PixelShader* pshader = ((const PixelShader*)  tolua_tousertype(tolua_S,2,0));
  {
   Renderer::UnbindAll(pshader);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_UnbindAll08(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Enable of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Enable10
static int tolua_PX2_Renderer_Enable10(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const PixelShader",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const ShaderParameters",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const PixelShader* pshader = ((const PixelShader*)  tolua_tousertype(tolua_S,2,0));
  const ShaderParameters* parameters = ((const ShaderParameters*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Enable'", NULL);
#endif
  {
   self->Enable(pshader,parameters);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Enable09(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Disable of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Disable09
static int tolua_PX2_Renderer_Disable09(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const PixelShader",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const ShaderParameters",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const PixelShader* pshader = ((const PixelShader*)  tolua_tousertype(tolua_S,2,0));
  const ShaderParameters* parameters = ((const ShaderParameters*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Disable'", NULL);
#endif
  {
   self->Disable(pshader,parameters);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Disable08(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAlphaProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetAlphaProperty00
static int tolua_PX2_Renderer_GetAlphaProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAlphaProperty'", NULL);
#endif
  {
   const AlphaProperty* tolua_ret = (const AlphaProperty*)  self->GetAlphaProperty();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const AlphaProperty");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAlphaProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCullProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetCullProperty00
static int tolua_PX2_Renderer_GetCullProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCullProperty'", NULL);
#endif
  {
   const CullProperty* tolua_ret = (const CullProperty*)  self->GetCullProperty();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const CullProperty");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCullProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDepthProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetDepthProperty00
static int tolua_PX2_Renderer_GetDepthProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDepthProperty'", NULL);
#endif
  {
   const DepthProperty* tolua_ret = (const DepthProperty*)  self->GetDepthProperty();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const DepthProperty");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDepthProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOffsetProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetOffsetProperty00
static int tolua_PX2_Renderer_GetOffsetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOffsetProperty'", NULL);
#endif
  {
   const OffsetProperty* tolua_ret = (const OffsetProperty*)  self->GetOffsetProperty();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const OffsetProperty");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOffsetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetStencilProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetStencilProperty00
static int tolua_PX2_Renderer_GetStencilProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetStencilProperty'", NULL);
#endif
  {
   const StencilProperty* tolua_ret = (const StencilProperty*)  self->GetStencilProperty();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const StencilProperty");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetStencilProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWireProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetWireProperty00
static int tolua_PX2_Renderer_GetWireProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWireProperty'", NULL);
#endif
  {
   const WireProperty* tolua_ret = (const WireProperty*)  self->GetWireProperty();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const WireProperty");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWireProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCamera of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_SetCamera00
static int tolua_PX2_Renderer_SetCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  Camera* camera = ((Camera*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCamera'", NULL);
#endif
  {
   self->SetCamera(camera);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCamera of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetCamera00
static int tolua_PX2_Renderer_GetCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCamera'", NULL);
#endif
  {
   Camera* tolua_ret = (Camera*)  self->GetCamera();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Camera");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCamera of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetCamera01
static int tolua_PX2_Renderer_GetCamera01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCamera'", NULL);
#endif
  {
   const Camera* tolua_ret = (const Camera*)  self->GetCamera();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const Camera");
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_Renderer_GetCamera00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetViewMatrix of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetViewMatrix00
static int tolua_PX2_Renderer_GetViewMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetViewMatrix'", NULL);
#endif
  {
   const HMatrix& tolua_ret = (const HMatrix&)  self->GetViewMatrix();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const HMatrix");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetViewMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetProjectionMatrix of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetProjectionMatrix00
static int tolua_PX2_Renderer_GetProjectionMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetProjectionMatrix'", NULL);
#endif
  {
   const HMatrix& tolua_ret = (const HMatrix&)  self->GetProjectionMatrix();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const HMatrix");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetProjectionMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPostProjectionMatrix of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetPostProjectionMatrix00
static int tolua_PX2_Renderer_GetPostProjectionMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPostProjectionMatrix'", NULL);
#endif
  {
   const HMatrix& tolua_ret = (const HMatrix&)  self->GetPostProjectionMatrix();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const HMatrix");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPostProjectionMatrix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPickRay of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetPickRay00
static int tolua_PX2_Renderer_GetPickRay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"APoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  APoint* origin = ((APoint*)  tolua_tousertype(tolua_S,4,0));
  AVector* direction = ((AVector*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPickRay'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetPickRay(x,y,*origin,*direction);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPickRay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PointWorldToViewPort of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_PointWorldToViewPort00
static int tolua_PX2_Renderer_PointWorldToViewPort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const APoint* point = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
  bool isInBack = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PointWorldToViewPort'", NULL);
#endif
  {
   Vector2f tolua_ret = (Vector2f)  self->PointWorldToViewPort(*point,&isInBack);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2f)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2f");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2f));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2f");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
   tolua_pushboolean(tolua_S,(bool)isInBack);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PointWorldToViewPort'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetClearColor of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_SetClearColor00
static int tolua_PX2_Renderer_SetClearColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Float4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Float4* clearColor = ((const Float4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetClearColor'", NULL);
#endif
  {
   self->SetClearColor(*clearColor);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetClearColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetClearColor of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetClearColor00
static int tolua_PX2_Renderer_GetClearColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetClearColor'", NULL);
#endif
  {
   const Float4& tolua_ret = (const Float4&)  self->GetClearColor();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Float4");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetClearColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetClearDepth of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_SetClearDepth00
static int tolua_PX2_Renderer_SetClearDepth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  float clearDepth = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetClearDepth'", NULL);
#endif
  {
   self->SetClearDepth(clearDepth);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetClearDepth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetClearDepth of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetClearDepth00
static int tolua_PX2_Renderer_GetClearDepth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetClearDepth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetClearDepth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetClearDepth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetClearStencil of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_SetClearStencil00
static int tolua_PX2_Renderer_SetClearStencil00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  unsigned int clearStencil = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetClearStencil'", NULL);
#endif
  {
   self->SetClearStencil(clearStencil);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetClearStencil'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetClearStencil of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetClearStencil00
static int tolua_PX2_Renderer_GetClearStencil00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetClearStencil'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->GetClearStencil();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetClearStencil'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetColorMask of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetColorMask00
static int tolua_PX2_Renderer_GetColorMask00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
  bool allowRed = ((bool)  tolua_toboolean(tolua_S,2,0));
  bool allowGreen = ((bool)  tolua_toboolean(tolua_S,3,0));
  bool allowBlue = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool allowAlpha = ((bool)  tolua_toboolean(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetColorMask'", NULL);
#endif
  {
   self->GetColorMask(allowRed,allowGreen,allowBlue,allowAlpha);
   tolua_pushboolean(tolua_S,(bool)allowRed);
   tolua_pushboolean(tolua_S,(bool)allowGreen);
   tolua_pushboolean(tolua_S,(bool)allowBlue);
   tolua_pushboolean(tolua_S,(bool)allowAlpha);
  }
 }
 return 4;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetColorMask'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOverrideAlphaProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_SetOverrideAlphaProperty00
static int tolua_PX2_Renderer_SetOverrideAlphaProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const AlphaProperty",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const AlphaProperty* alphaState = ((const AlphaProperty*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOverrideAlphaProperty'", NULL);
#endif
  {
   self->SetOverrideAlphaProperty(alphaState);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOverrideAlphaProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOverrideCullProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_SetOverrideCullProperty00
static int tolua_PX2_Renderer_SetOverrideCullProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const CullProperty",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const CullProperty* cullState = ((const CullProperty*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOverrideCullProperty'", NULL);
#endif
  {
   self->SetOverrideCullProperty(cullState);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOverrideCullProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOverrideDepthProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_SetOverrideDepthProperty00
static int tolua_PX2_Renderer_SetOverrideDepthProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const DepthProperty",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const DepthProperty* depthState = ((const DepthProperty*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOverrideDepthProperty'", NULL);
#endif
  {
   self->SetOverrideDepthProperty(depthState);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOverrideDepthProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOverrideOffsetProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_SetOverrideOffsetProperty00
static int tolua_PX2_Renderer_SetOverrideOffsetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const OffsetProperty",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const OffsetProperty* offsetState = ((const OffsetProperty*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOverrideOffsetProperty'", NULL);
#endif
  {
   self->SetOverrideOffsetProperty(offsetState);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOverrideOffsetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOverrideStencilProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_SetOverrideStencilProperty00
static int tolua_PX2_Renderer_SetOverrideStencilProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const StencilProperty",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const StencilProperty* stencilState = ((const StencilProperty*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOverrideStencilProperty'", NULL);
#endif
  {
   self->SetOverrideStencilProperty(stencilState);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOverrideStencilProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOverrideWireProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_SetOverrideWireProperty00
static int tolua_PX2_Renderer_SetOverrideWireProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const WireProperty",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const WireProperty* wireState = ((const WireProperty*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOverrideWireProperty'", NULL);
#endif
  {
   self->SetOverrideWireProperty(wireState);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOverrideWireProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOverrideAlphaProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetOverrideAlphaProperty00
static int tolua_PX2_Renderer_GetOverrideAlphaProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOverrideAlphaProperty'", NULL);
#endif
  {
   const AlphaProperty* tolua_ret = (const AlphaProperty*)  self->GetOverrideAlphaProperty();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const AlphaProperty");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOverrideAlphaProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOverrideCullProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetOverrideCullProperty00
static int tolua_PX2_Renderer_GetOverrideCullProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOverrideCullProperty'", NULL);
#endif
  {
   const CullProperty* tolua_ret = (const CullProperty*)  self->GetOverrideCullProperty();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const CullProperty");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOverrideCullProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOverrideDepthProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetOverrideDepthProperty00
static int tolua_PX2_Renderer_GetOverrideDepthProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOverrideDepthProperty'", NULL);
#endif
  {
   const DepthProperty* tolua_ret = (const DepthProperty*)  self->GetOverrideDepthProperty();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const DepthProperty");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOverrideDepthProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOverrideOffsetProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetOverrideOffsetProperty00
static int tolua_PX2_Renderer_GetOverrideOffsetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOverrideOffsetProperty'", NULL);
#endif
  {
   const OffsetProperty* tolua_ret = (const OffsetProperty*)  self->GetOverrideOffsetProperty();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const OffsetProperty");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOverrideOffsetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOverrideStencilProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetOverrideStencilProperty00
static int tolua_PX2_Renderer_GetOverrideStencilProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOverrideStencilProperty'", NULL);
#endif
  {
   const StencilProperty* tolua_ret = (const StencilProperty*)  self->GetOverrideStencilProperty();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const StencilProperty");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOverrideStencilProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOverrideWireProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetOverrideWireProperty00
static int tolua_PX2_Renderer_GetOverrideWireProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOverrideWireProperty'", NULL);
#endif
  {
   const WireProperty* tolua_ret = (const WireProperty*)  self->GetOverrideWireProperty();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const WireProperty");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOverrideWireProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetReverseCullOrder of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_SetReverseCullOrder00
static int tolua_PX2_Renderer_SetReverseCullOrder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  bool reverseCullOrder = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetReverseCullOrder'", NULL);
#endif
  {
   self->SetReverseCullOrder(reverseCullOrder);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetReverseCullOrder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetReverseCullOrder of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetReverseCullOrder00
static int tolua_PX2_Renderer_GetReverseCullOrder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetReverseCullOrder'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetReverseCullOrder();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetReverseCullOrder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Draw of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Draw00
static int tolua_PX2_Renderer_Draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const VisibleSet",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"GlobalMaterial",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const VisibleSet* visibleSet = ((const VisibleSet*)  tolua_tousertype(tolua_S,2,0));
  GlobalMaterial* globalMaterial = ((GlobalMaterial*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Draw'", NULL);
#endif
  {
   self->Draw(*visibleSet,globalMaterial);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Draw of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Draw01
static int tolua_PX2_Renderer_Draw01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Renderable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Renderable* renderable = ((const Renderable*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Draw'", NULL);
#endif
  {
   self->Draw(renderable);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Draw00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Draw of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Draw02
static int tolua_PX2_Renderer_Draw02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Renderable",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const MaterialInstance",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const Renderable* renderable = ((const Renderable*)  tolua_tousertype(tolua_S,2,0));
  const MaterialInstance* instance = ((const MaterialInstance*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Draw'", NULL);
#endif
  {
   self->Draw(renderable,instance);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_Draw01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAlphaProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_SetAlphaProperty00
static int tolua_PX2_Renderer_SetAlphaProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const AlphaProperty",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const AlphaProperty* alphaState = ((const AlphaProperty*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAlphaProperty'", NULL);
#endif
  {
   self->SetAlphaProperty(alphaState);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAlphaProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCullProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_SetCullProperty00
static int tolua_PX2_Renderer_SetCullProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const CullProperty",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const CullProperty* cullState = ((const CullProperty*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCullProperty'", NULL);
#endif
  {
   self->SetCullProperty(cullState);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCullProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDepthProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_SetDepthProperty00
static int tolua_PX2_Renderer_SetDepthProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const DepthProperty",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const DepthProperty* depthState = ((const DepthProperty*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDepthProperty'", NULL);
#endif
  {
   self->SetDepthProperty(depthState);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDepthProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOffsetProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_SetOffsetProperty00
static int tolua_PX2_Renderer_SetOffsetProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const OffsetProperty",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const OffsetProperty* offsetState = ((const OffsetProperty*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOffsetProperty'", NULL);
#endif
  {
   self->SetOffsetProperty(offsetState);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOffsetProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetStencilProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_SetStencilProperty00
static int tolua_PX2_Renderer_SetStencilProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const StencilProperty",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const StencilProperty* stencilState = ((const StencilProperty*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetStencilProperty'", NULL);
#endif
  {
   self->SetStencilProperty(stencilState);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetStencilProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWireProperty of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_SetWireProperty00
static int tolua_PX2_Renderer_SetWireProperty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const WireProperty",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  const WireProperty* wireState = ((const WireProperty*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWireProperty'", NULL);
#endif
  {
   self->SetWireProperty(wireState);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWireProperty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetViewport of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_SetViewport00
static int tolua_PX2_Renderer_SetViewport00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  int xPosition = ((int)  tolua_tonumber(tolua_S,2,0));
  int yPosition = ((int)  tolua_tonumber(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  int height = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetViewport'", NULL);
#endif
  {
   self->SetViewport(xPosition,yPosition,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetViewport'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetViewport of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetViewport00
static int tolua_PX2_Renderer_GetViewport00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
  int xPosition = ((int)  tolua_tonumber(tolua_S,2,0));
  int yPosition = ((int)  tolua_tonumber(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  int height = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetViewport'", NULL);
#endif
  {
   self->GetViewport(xPosition,yPosition,width,height);
   tolua_pushnumber(tolua_S,(lua_Number)xPosition);
   tolua_pushnumber(tolua_S,(lua_Number)yPosition);
   tolua_pushnumber(tolua_S,(lua_Number)width);
   tolua_pushnumber(tolua_S,(lua_Number)height);
  }
 }
 return 4;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetViewport'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDepthRange of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_SetDepthRange00
static int tolua_PX2_Renderer_SetDepthRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  float zMin = ((float)  tolua_tonumber(tolua_S,2,0));
  float zMax = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDepthRange'", NULL);
#endif
  {
   self->SetDepthRange(zMin,zMax);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDepthRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDepthRange of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_GetDepthRange00
static int tolua_PX2_Renderer_GetDepthRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Renderer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Renderer* self = (const Renderer*)  tolua_tousertype(tolua_S,1,0);
  float zMin = ((float)  tolua_tonumber(tolua_S,2,0));
  float zMax = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDepthRange'", NULL);
#endif
  {
   self->GetDepthRange(zMin,zMax);
   tolua_pushnumber(tolua_S,(lua_Number)zMin);
   tolua_pushnumber(tolua_S,(lua_Number)zMax);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDepthRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Resize of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_Resize00
static int tolua_PX2_Renderer_Resize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Resize'", NULL);
#endif
  {
   self->Resize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Resize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResizeWindow of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_ResizeWindow00
static int tolua_PX2_Renderer_ResizeWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResizeWindow'", NULL);
#endif
  {
   self->ResizeWindow(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResizeWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearColorBuffer of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_ClearColorBuffer00
static int tolua_PX2_Renderer_ClearColorBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearColorBuffer'", NULL);
#endif
  {
   self->ClearColorBuffer();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearColorBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearDepthBuffer of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_ClearDepthBuffer00
static int tolua_PX2_Renderer_ClearDepthBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearDepthBuffer'", NULL);
#endif
  {
   self->ClearDepthBuffer();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearDepthBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearStencilBuffer of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_ClearStencilBuffer00
static int tolua_PX2_Renderer_ClearStencilBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearStencilBuffer'", NULL);
#endif
  {
   self->ClearStencilBuffer();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearStencilBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearBuffers of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_ClearBuffers00
static int tolua_PX2_Renderer_ClearBuffers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearBuffers'", NULL);
#endif
  {
   self->ClearBuffers();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearBuffers'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearColorBuffer of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_ClearColorBuffer01
static int tolua_PX2_Renderer_ClearColorBuffer01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int w = ((int)  tolua_tonumber(tolua_S,4,0));
  int h = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearColorBuffer'", NULL);
#endif
  {
   self->ClearColorBuffer(x,y,w,h);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_ClearColorBuffer00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearDepthBuffer of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_ClearDepthBuffer01
static int tolua_PX2_Renderer_ClearDepthBuffer01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int w = ((int)  tolua_tonumber(tolua_S,4,0));
  int h = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearDepthBuffer'", NULL);
#endif
  {
   self->ClearDepthBuffer(x,y,w,h);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_ClearDepthBuffer00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearStencilBuffer of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_ClearStencilBuffer01
static int tolua_PX2_Renderer_ClearStencilBuffer01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int w = ((int)  tolua_tonumber(tolua_S,4,0));
  int h = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearStencilBuffer'", NULL);
#endif
  {
   self->ClearStencilBuffer(x,y,w,h);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_ClearStencilBuffer00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearBuffers of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_ClearBuffers01
static int tolua_PX2_Renderer_ClearBuffers01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int w = ((int)  tolua_tonumber(tolua_S,4,0));
  int h = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearBuffers'", NULL);
#endif
  {
   self->ClearBuffers(x,y,w,h);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Renderer_ClearBuffers00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: DisplayColorBuffer of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_DisplayColorBuffer00
static int tolua_PX2_Renderer_DisplayColorBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DisplayColorBuffer'", NULL);
#endif
  {
   self->DisplayColorBuffer();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DisplayColorBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetColorMask of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_PX2_Renderer_SetColorMask00
static int tolua_PX2_Renderer_SetColorMask00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
  bool allowRed = ((bool)  tolua_toboolean(tolua_S,2,0));
  bool allowGreen = ((bool)  tolua_toboolean(tolua_S,3,0));
  bool allowBlue = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool allowAlpha = ((bool)  tolua_toboolean(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetColorMask'", NULL);
#endif
  {
   self->SetColorMask(allowRed,allowGreen,allowBlue,allowAlpha);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetColorMask'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  InputEventData */
#ifndef TOLUA_DISABLE_tolua_PX2_InputEventData_new00
static int tolua_PX2_InputEventData_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"InputEventData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   InputEventData* tolua_ret = (InputEventData*)  Mtolua_new((InputEventData)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"InputEventData");
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

/* method: new_local of class  InputEventData */
#ifndef TOLUA_DISABLE_tolua_PX2_InputEventData_new00_local
static int tolua_PX2_InputEventData_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"InputEventData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   InputEventData* tolua_ret = (InputEventData*)  Mtolua_new((InputEventData)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"InputEventData");
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

/* method: delete of class  InputEventData */
#ifndef TOLUA_DISABLE_tolua_PX2_InputEventData_delete00
static int tolua_PX2_InputEventData_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"InputEventData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  InputEventData* self = (InputEventData*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: KCode of class  InputEventData */
#ifndef TOLUA_DISABLE_tolua_get_InputEventData_KCode
static int tolua_get_InputEventData_KCode(lua_State* tolua_S)
{
  InputEventData* self = (InputEventData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'KCode'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->KCode);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: KCode of class  InputEventData */
#ifndef TOLUA_DISABLE_tolua_set_InputEventData_KCode
static int tolua_set_InputEventData_KCode(lua_State* tolua_S)
{
  InputEventData* self = (InputEventData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'KCode'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->KCode = ((KeyCode) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MButtonID of class  InputEventData */
#ifndef TOLUA_DISABLE_tolua_get_InputEventData_MButtonID
static int tolua_get_InputEventData_MButtonID(lua_State* tolua_S)
{
  InputEventData* self = (InputEventData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MButtonID'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->MButtonID);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MButtonID of class  InputEventData */
#ifndef TOLUA_DISABLE_tolua_set_InputEventData_MButtonID
static int tolua_set_InputEventData_MButtonID(lua_State* tolua_S)
{
  InputEventData* self = (InputEventData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MButtonID'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MButtonID = ((MouseButtonID) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MState of class  InputEventData */
#ifndef TOLUA_DISABLE_tolua_get_InputEventData_MState
static int tolua_get_InputEventData_MState(lua_State* tolua_S)
{
  InputEventData* self = (InputEventData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MState'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->MState,"MouseState");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MState of class  InputEventData */
#ifndef TOLUA_DISABLE_tolua_set_InputEventData_MState
static int tolua_set_InputEventData_MState(lua_State* tolua_S)
{
  InputEventData* self = (InputEventData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MState'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"MouseState",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MState = *((MouseState*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: TState of class  InputEventData */
#ifndef TOLUA_DISABLE_tolua_get_InputEventData_TState
static int tolua_get_InputEventData_TState(lua_State* tolua_S)
{
  InputEventData* self = (InputEventData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TState'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->TState,"MultiTouchState");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: TState of class  InputEventData */
#ifndef TOLUA_DISABLE_tolua_set_InputEventData_TState
static int tolua_set_InputEventData_TState(lua_State* tolua_S)
{
  InputEventData* self = (InputEventData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TState'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"MultiTouchState",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->TState = *((MultiTouchState*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: TStates of class  InputEventData */
#ifndef TOLUA_DISABLE_tolua_get_InputEventData_TStates
static int tolua_get_InputEventData_TStates(lua_State* tolua_S)
{
  InputEventData* self = (InputEventData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TStates'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->TStates,"std::vector<MultiTouchState>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: TStates of class  InputEventData */
#ifndef TOLUA_DISABLE_tolua_set_InputEventData_TStates
static int tolua_set_InputEventData_TStates(lua_State* tolua_S)
{
  InputEventData* self = (InputEventData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TStates'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<MultiTouchState>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->TStates = *((std::vector<MultiTouchState>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ViewID of class  InputEventData */
#ifndef TOLUA_DISABLE_tolua_get_InputEventData_ViewID
static int tolua_get_InputEventData_ViewID(lua_State* tolua_S)
{
  InputEventData* self = (InputEventData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ViewID'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ViewID);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ViewID of class  InputEventData */
#ifndef TOLUA_DISABLE_tolua_set_InputEventData_ViewID
static int tolua_set_InputEventData_ViewID(lua_State* tolua_S)
{
  InputEventData* self = (InputEventData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ViewID'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ViewID = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSingleton of class  ScriptManager */
#ifndef TOLUA_DISABLE_tolua_PX2_ScriptManager_GetSingleton00
static int tolua_PX2_ScriptManager_GetSingleton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ScriptManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ScriptManager& tolua_ret = (ScriptManager&)  ScriptManager::GetSingleton();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ScriptManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSingleton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CallString of class  ScriptManager */
#ifndef TOLUA_DISABLE_tolua_PX2_ScriptManager_CallString00
static int tolua_PX2_ScriptManager_CallString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScriptManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScriptManager* self = (ScriptManager*)  tolua_tousertype(tolua_S,1,0);
  const char* str = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CallString'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->CallString(str);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CallString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CallFile of class  ScriptManager */
#ifndef TOLUA_DISABLE_tolua_PX2_ScriptManager_CallFile00
static int tolua_PX2_ScriptManager_CallFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScriptManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScriptManager* self = (ScriptManager*)  tolua_tousertype(tolua_S,1,0);
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CallFile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->CallFile(filename);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CallFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSingleton of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_PX2_ResourceManager_GetSingleton00
static int tolua_PX2_ResourceManager_GetSingleton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ResourceManager& tolua_ret = (ResourceManager&)  ResourceManager::GetSingleton();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ResourceManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSingleton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_PX2_ResourceManager_Clear00
static int tolua_PX2_ResourceManager_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'", NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BlockLoad of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_PX2_ResourceManager_BlockLoad00
static int tolua_PX2_ResourceManager_BlockLoad00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BlockLoad'", NULL);
#endif
  {
   Object* tolua_ret = (Object*)  self->BlockLoad(filename);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Object");
   tolua_pushcppstring(tolua_S,(const char*)filename);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BlockLoad'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: BackgroundLoad of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_PX2_ResourceManager_BackgroundLoad00
static int tolua_PX2_ResourceManager_BackgroundLoad00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BackgroundLoad'", NULL);
#endif
  {
   ResHandle tolua_ret = (ResHandle)  self->BackgroundLoad(filename);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((ResHandle)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"ResHandle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(ResHandle));
     tolua_pushusertype(tolua_S,tolua_obj,"ResHandle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
   tolua_pushcppstring(tolua_S,(const char*)filename);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BackgroundLoad'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CheckRes of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_PX2_ResourceManager_CheckRes00
static int tolua_PX2_ResourceManager_CheckRes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ResHandle",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  ResHandle handle = *((ResHandle*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CheckRes'", NULL);
#endif
  {
   Object* tolua_ret = (Object*)  self->CheckRes(handle);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Object");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CheckRes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetResLoadState of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_PX2_ResourceManager_GetResLoadState00
static int tolua_PX2_ResourceManager_GetResLoadState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ResHandle",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  ResHandle handle = *((ResHandle*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetResLoadState'", NULL);
#endif
  {
   ResourceManager::LoadState tolua_ret = (ResourceManager::LoadState)  self->GetResLoadState(handle);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetResLoadState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUseGarbageCollect of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_PX2_ResourceManager_SetUseGarbageCollect00
static int tolua_PX2_ResourceManager_SetUseGarbageCollect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  bool use = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUseGarbageCollect'", NULL);
#endif
  {
   self->SetUseGarbageCollect(use);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUseGarbageCollect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsUseGarbageCollect of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_PX2_ResourceManager_IsUseGarbageCollect00
static int tolua_PX2_ResourceManager_IsUseGarbageCollect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ResourceManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ResourceManager* self = (const ResourceManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsUseGarbageCollect'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsUseGarbageCollect();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsUseGarbageCollect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetGarbageCollectTime of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_PX2_ResourceManager_SetGarbageCollectTime00
static int tolua_PX2_ResourceManager_SetGarbageCollectTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  float seconds = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetGarbageCollectTime'", NULL);
#endif
  {
   self->SetGarbageCollectTime(seconds);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetGarbageCollectTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGarbageCollectTime of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_PX2_ResourceManager_GetGarbageCollectTime00
static int tolua_PX2_ResourceManager_GetGarbageCollectTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ResourceManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ResourceManager* self = (const ResourceManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGarbageCollectTime'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetGarbageCollectTime();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGarbageCollectTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadBuffer of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_PX2_ResourceManager_LoadBuffer00
static int tolua_PX2_ResourceManager_LoadBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  int bufferSize = ((int)  tolua_tonumber(tolua_S,3,0));
  char* buffer = ((char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadBuffer'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->LoadBuffer(filename,bufferSize,buffer);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)filename);
   tolua_pushnumber(tolua_S,(lua_Number)bufferSize);
   tolua_pushstring(tolua_S,(const char*)buffer);
  }
 }
 return 4;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddTexPack of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_PX2_ResourceManager_AddTexPack00
static int tolua_PX2_ResourceManager_AddTexPack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string texPackPath = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddTexPack'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->AddTexPack(texPackPath);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)texPackPath);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddTexPack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTexPack of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_PX2_ResourceManager_GetTexPack00
static int tolua_PX2_ResourceManager_GetTexPack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string texPackPath = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTexPack'", NULL);
#endif
  {
   const TexPack& tolua_ret = (const TexPack&)  self->GetTexPack(texPackPath);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const TexPack");
   tolua_pushcppstring(tolua_S,(const char*)texPackPath);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTexPack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTexPackElement of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_PX2_ResourceManager_GetTexPackElement00
static int tolua_PX2_ResourceManager_GetTexPackElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string texPackPath = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string eleName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTexPackElement'", NULL);
#endif
  {
   const TexPackElement& tolua_ret = (const TexPackElement&)  self->GetTexPackElement(texPackPath,eleName);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const TexPackElement");
   tolua_pushcppstring(tolua_S,(const char*)texPackPath);
   tolua_pushcppstring(tolua_S,(const char*)eleName);
  }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTexPackElement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWriteablePath of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_PX2_ResourceManager_GetWriteablePath00
static int tolua_PX2_ResourceManager_GetWriteablePath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWriteablePath'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetWriteablePath();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWriteablePath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetResourcePath of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_PX2_ResourceManager_GetResourcePath00
static int tolua_PX2_ResourceManager_GetResourcePath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const std::string tolua_ret = (const std::string)  ResourceManager::GetResourcePath();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetResourcePath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DDSKeepCompressed of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_PX2_ResourceManager_DDSKeepCompressed00
static int tolua_PX2_ResourceManager_DDSKeepCompressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
  bool keep = ((bool)  tolua_toboolean(tolua_S,2,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DDSKeepCompressed'", NULL);
#endif
  {
   self->DDSKeepCompressed(keep);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DDSKeepCompressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsDDSKeepCompressed of class  ResourceManager */
#ifndef TOLUA_DISABLE_tolua_PX2_ResourceManager_IsDDSKeepCompressed00
static int tolua_PX2_ResourceManager_IsDDSKeepCompressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ResourceManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ResourceManager* self = (ResourceManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsDDSKeepCompressed'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsDDSKeepCompressed();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsDDSKeepCompressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSingleton of class  LanguageManager */
#ifndef TOLUA_DISABLE_tolua_PX2_LanguageManager_GetSingleton00
static int tolua_PX2_LanguageManager_GetSingleton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LanguageManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LanguageManager& tolua_ret = (LanguageManager&)  LanguageManager::GetSingleton();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"LanguageManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSingleton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Load of class  LanguageManager */
#ifndef TOLUA_DISABLE_tolua_PX2_LanguageManager_Load00
static int tolua_PX2_LanguageManager_Load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LanguageManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LanguageManager* self = (LanguageManager*)  tolua_tousertype(tolua_S,1,0);
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Load'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Load(filename);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLanguage of class  LanguageManager */
#ifndef TOLUA_DISABLE_tolua_PX2_LanguageManager_SetLanguage00
static int tolua_PX2_LanguageManager_SetLanguage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LanguageManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LanguageManager* self = (LanguageManager*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLanguage'", NULL);
#endif
  {
   self->SetLanguage(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLanguage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetValue of class  LanguageManager */
#ifndef TOLUA_DISABLE_tolua_PX2_LanguageManager_GetValue00
static int tolua_PX2_LanguageManager_GetValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LanguageManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LanguageManager* self = (LanguageManager*)  tolua_tousertype(tolua_S,1,0);
  std::string key = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetValue'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetValue(key);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetValue of class  LanguageManager */
#ifndef TOLUA_DISABLE_tolua_PX2_LanguageManager_GetValue01
static int tolua_PX2_LanguageManager_GetValue01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LanguageManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  LanguageManager* self = (LanguageManager*)  tolua_tousertype(tolua_S,1,0);
  std::string key = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  int index = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetValue'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetValue(key,index);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_LanguageManager_GetValue00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Sound */
#ifndef TOLUA_DISABLE_tolua_PX2_Sound_delete00
static int tolua_PX2_Sound_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
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

/* method: IsPlaying of class  Sound */
#ifndef TOLUA_DISABLE_tolua_PX2_Sound_IsPlaying00
static int tolua_PX2_Sound_IsPlaying00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsPlaying'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsPlaying();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsPlaying'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVolume of class  Sound */
#ifndef TOLUA_DISABLE_tolua_PX2_Sound_SetVolume00
static int tolua_PX2_Sound_SetVolume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
  float volume = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVolume'", NULL);
#endif
  {
   self->SetVolume(volume);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVolume'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPaused of class  Sound */
#ifndef TOLUA_DISABLE_tolua_PX2_Sound_SetPaused00
static int tolua_PX2_Sound_SetPaused00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
  bool paused = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPaused'", NULL);
#endif
  {
   self->SetPaused(paused);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPaused'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Stop of class  Sound */
#ifndef TOLUA_DISABLE_tolua_PX2_Sound_Stop00
static int tolua_PX2_Sound_Stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Stop'", NULL);
#endif
  {
   self->Stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  Sound */
#ifndef TOLUA_DISABLE_tolua_PX2_Sound_SetPosition00
static int tolua_PX2_Sound_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
  const APoint* position = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(*position);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVelocity of class  Sound */
#ifndef TOLUA_DISABLE_tolua_PX2_Sound_SetVelocity00
static int tolua_PX2_Sound_SetVelocity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
  const AVector* velocity = ((const AVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVelocity'", NULL);
#endif
  {
   self->SetVelocity(*velocity);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVelocity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDistance of class  Sound */
#ifndef TOLUA_DISABLE_tolua_PX2_Sound_SetDistance00
static int tolua_PX2_Sound_SetDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Sound",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Sound* self = (Sound*)  tolua_tousertype(tolua_S,1,0);
  float minDistance = ((float)  tolua_tonumber(tolua_S,2,0));
  float maxDistance = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDistance'", NULL);
#endif
  {
   self->SetDistance(minDistance,maxDistance);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SoundSystemInitInfo */
#ifndef TOLUA_DISABLE_tolua_PX2_SoundSystemInitInfo_new00
static int tolua_PX2_SoundSystemInitInfo_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SoundSystemInitInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SoundSystemInitInfo* tolua_ret = (SoundSystemInitInfo*)  Mtolua_new((SoundSystemInitInfo)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SoundSystemInitInfo");
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

/* method: new_local of class  SoundSystemInitInfo */
#ifndef TOLUA_DISABLE_tolua_PX2_SoundSystemInitInfo_new00_local
static int tolua_PX2_SoundSystemInitInfo_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SoundSystemInitInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SoundSystemInitInfo* tolua_ret = (SoundSystemInitInfo*)  Mtolua_new((SoundSystemInitInfo)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SoundSystemInitInfo");
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

/* get function: MaxChannels of class  SoundSystemInitInfo */
#ifndef TOLUA_DISABLE_tolua_get_SoundSystemInitInfo_MaxChannels
static int tolua_get_SoundSystemInitInfo_MaxChannels(lua_State* tolua_S)
{
  SoundSystemInitInfo* self = (SoundSystemInitInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MaxChannels'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->MaxChannels);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MaxChannels of class  SoundSystemInitInfo */
#ifndef TOLUA_DISABLE_tolua_set_SoundSystemInitInfo_MaxChannels
static int tolua_set_SoundSystemInitInfo_MaxChannels(lua_State* tolua_S)
{
  SoundSystemInitInfo* self = (SoundSystemInitInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MaxChannels'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MaxChannels = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DopplerScale of class  SoundSystemInitInfo */
#ifndef TOLUA_DISABLE_tolua_get_SoundSystemInitInfo_DopplerScale
static int tolua_get_SoundSystemInitInfo_DopplerScale(lua_State* tolua_S)
{
  SoundSystemInitInfo* self = (SoundSystemInitInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'DopplerScale'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->DopplerScale);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: DopplerScale of class  SoundSystemInitInfo */
#ifndef TOLUA_DISABLE_tolua_set_SoundSystemInitInfo_DopplerScale
static int tolua_set_SoundSystemInitInfo_DopplerScale(lua_State* tolua_S)
{
  SoundSystemInitInfo* self = (SoundSystemInitInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'DopplerScale'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->DopplerScale = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DistanceFactor of class  SoundSystemInitInfo */
#ifndef TOLUA_DISABLE_tolua_get_SoundSystemInitInfo_DistanceFactor
static int tolua_get_SoundSystemInitInfo_DistanceFactor(lua_State* tolua_S)
{
  SoundSystemInitInfo* self = (SoundSystemInitInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'DistanceFactor'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->DistanceFactor);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: DistanceFactor of class  SoundSystemInitInfo */
#ifndef TOLUA_DISABLE_tolua_set_SoundSystemInitInfo_DistanceFactor
static int tolua_set_SoundSystemInitInfo_DistanceFactor(lua_State* tolua_S)
{
  SoundSystemInitInfo* self = (SoundSystemInitInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'DistanceFactor'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->DistanceFactor = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: RolloffScale of class  SoundSystemInitInfo */
#ifndef TOLUA_DISABLE_tolua_get_SoundSystemInitInfo_RolloffScale
static int tolua_get_SoundSystemInitInfo_RolloffScale(lua_State* tolua_S)
{
  SoundSystemInitInfo* self = (SoundSystemInitInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'RolloffScale'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->RolloffScale);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: RolloffScale of class  SoundSystemInitInfo */
#ifndef TOLUA_DISABLE_tolua_set_SoundSystemInitInfo_RolloffScale
static int tolua_set_SoundSystemInitInfo_RolloffScale(lua_State* tolua_S)
{
  SoundSystemInitInfo* self = (SoundSystemInitInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'RolloffScale'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->RolloffScale = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SoundCreateInfo3D */
#ifndef TOLUA_DISABLE_tolua_PX2_SoundCreateInfo3D_new00
static int tolua_PX2_SoundCreateInfo3D_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SoundCreateInfo3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SoundCreateInfo3D* tolua_ret = (SoundCreateInfo3D*)  Mtolua_new((SoundCreateInfo3D)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SoundCreateInfo3D");
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

/* method: new_local of class  SoundCreateInfo3D */
#ifndef TOLUA_DISABLE_tolua_PX2_SoundCreateInfo3D_new00_local
static int tolua_PX2_SoundCreateInfo3D_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SoundCreateInfo3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SoundCreateInfo3D* tolua_ret = (SoundCreateInfo3D*)  Mtolua_new((SoundCreateInfo3D)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SoundCreateInfo3D");
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

/* get function: MinDistance of class  SoundCreateInfo3D */
#ifndef TOLUA_DISABLE_tolua_get_SoundCreateInfo3D_MinDistance
static int tolua_get_SoundCreateInfo3D_MinDistance(lua_State* tolua_S)
{
  SoundCreateInfo3D* self = (SoundCreateInfo3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MinDistance'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->MinDistance);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MinDistance of class  SoundCreateInfo3D */
#ifndef TOLUA_DISABLE_tolua_set_SoundCreateInfo3D_MinDistance
static int tolua_set_SoundCreateInfo3D_MinDistance(lua_State* tolua_S)
{
  SoundCreateInfo3D* self = (SoundCreateInfo3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MinDistance'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MinDistance = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MaxDistance of class  SoundCreateInfo3D */
#ifndef TOLUA_DISABLE_tolua_get_SoundCreateInfo3D_MaxDistance
static int tolua_get_SoundCreateInfo3D_MaxDistance(lua_State* tolua_S)
{
  SoundCreateInfo3D* self = (SoundCreateInfo3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MaxDistance'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->MaxDistance);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MaxDistance of class  SoundCreateInfo3D */
#ifndef TOLUA_DISABLE_tolua_set_SoundCreateInfo3D_MaxDistance
static int tolua_set_SoundCreateInfo3D_MaxDistance(lua_State* tolua_S)
{
  SoundCreateInfo3D* self = (SoundCreateInfo3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MaxDistance'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MaxDistance = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Volume of class  SoundCreateInfo3D */
#ifndef TOLUA_DISABLE_tolua_get_SoundCreateInfo3D_Volume
static int tolua_get_SoundCreateInfo3D_Volume(lua_State* tolua_S)
{
  SoundCreateInfo3D* self = (SoundCreateInfo3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Volume'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Volume);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Volume of class  SoundCreateInfo3D */
#ifndef TOLUA_DISABLE_tolua_set_SoundCreateInfo3D_Volume
static int tolua_set_SoundCreateInfo3D_Volume(lua_State* tolua_S)
{
  SoundCreateInfo3D* self = (SoundCreateInfo3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Volume'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Volume = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Position of class  SoundCreateInfo3D */
#ifndef TOLUA_DISABLE_tolua_get_SoundCreateInfo3D_Position
static int tolua_get_SoundCreateInfo3D_Position(lua_State* tolua_S)
{
  SoundCreateInfo3D* self = (SoundCreateInfo3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Position'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->Position,"APoint");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Position of class  SoundCreateInfo3D */
#ifndef TOLUA_DISABLE_tolua_set_SoundCreateInfo3D_Position
static int tolua_set_SoundCreateInfo3D_Position(lua_State* tolua_S)
{
  SoundCreateInfo3D* self = (SoundCreateInfo3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Position'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"APoint",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Position = *((APoint*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Velocity of class  SoundCreateInfo3D */
#ifndef TOLUA_DISABLE_tolua_get_SoundCreateInfo3D_Velocity
static int tolua_get_SoundCreateInfo3D_Velocity(lua_State* tolua_S)
{
  SoundCreateInfo3D* self = (SoundCreateInfo3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Velocity'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->Velocity,"AVector");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Velocity of class  SoundCreateInfo3D */
#ifndef TOLUA_DISABLE_tolua_set_SoundCreateInfo3D_Velocity
static int tolua_set_SoundCreateInfo3D_Velocity(lua_State* tolua_S)
{
  SoundCreateInfo3D* self = (SoundCreateInfo3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Velocity'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AVector",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Velocity = *((AVector*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: IsLoop of class  SoundCreateInfo3D */
#ifndef TOLUA_DISABLE_tolua_get_SoundCreateInfo3D_IsLoop
static int tolua_get_SoundCreateInfo3D_IsLoop(lua_State* tolua_S)
{
  SoundCreateInfo3D* self = (SoundCreateInfo3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'IsLoop'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->IsLoop);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: IsLoop of class  SoundCreateInfo3D */
#ifndef TOLUA_DISABLE_tolua_set_SoundCreateInfo3D_IsLoop
static int tolua_set_SoundCreateInfo3D_IsLoop(lua_State* tolua_S)
{
  SoundCreateInfo3D* self = (SoundCreateInfo3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'IsLoop'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->IsLoop = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSingleton of class  SoundSystem */
#ifndef TOLUA_DISABLE_tolua_PX2_SoundSystem_GetSingleton00
static int tolua_PX2_SoundSystem_GetSingleton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SoundSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SoundSystem& tolua_ret = (SoundSystem&)  SoundSystem::GetSingleton();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"SoundSystem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSingleton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSystemType of class  SoundSystem */
#ifndef TOLUA_DISABLE_tolua_PX2_SoundSystem_GetSystemType00
static int tolua_PX2_SoundSystem_GetSystemType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const SoundSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const SoundSystem* self = (const SoundSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSystemType'", NULL);
#endif
  {
   SoundSystem::SystemType tolua_ret = (SoundSystem::SystemType)  self->GetSystemType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSystemType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxNumPlaySameTime of class  SoundSystem */
#ifndef TOLUA_DISABLE_tolua_PX2_SoundSystem_SetMaxNumPlaySameTime00
static int tolua_PX2_SoundSystem_SetMaxNumPlaySameTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SoundSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SoundSystem* self = (SoundSystem*)  tolua_tousertype(tolua_S,1,0);
  int num = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxNumPlaySameTime'", NULL);
#endif
  {
   self->SetMaxNumPlaySameTime(num);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxNumPlaySameTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxNumPlaySameTime of class  SoundSystem */
#ifndef TOLUA_DISABLE_tolua_PX2_SoundSystem_GetMaxNumPlaySameTime00
static int tolua_PX2_SoundSystem_GetMaxNumPlaySameTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const SoundSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const SoundSystem* self = (const SoundSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxNumPlaySameTime'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetMaxNumPlaySameTime();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxNumPlaySameTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlaySameTimeRange of class  SoundSystem */
#ifndef TOLUA_DISABLE_tolua_PX2_SoundSystem_SetPlaySameTimeRange00
static int tolua_PX2_SoundSystem_SetPlaySameTimeRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SoundSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SoundSystem* self = (SoundSystem*)  tolua_tousertype(tolua_S,1,0);
  float time = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlaySameTimeRange'", NULL);
#endif
  {
   self->SetPlaySameTimeRange(time);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlaySameTimeRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlaySameTimeRange of class  SoundSystem */
#ifndef TOLUA_DISABLE_tolua_PX2_SoundSystem_GetPlaySameTimeRange00
static int tolua_PX2_SoundSystem_GetPlaySameTimeRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const SoundSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const SoundSystem* self = (const SoundSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlaySameTimeRange'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlaySameTimeRange();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlaySameTimeRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetListener of class  SoundSystem */
#ifndef TOLUA_DISABLE_tolua_PX2_SoundSystem_SetListener00
static int tolua_PX2_SoundSystem_SetListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SoundSystem",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const AVector",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"const AVector",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"const AVector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SoundSystem* self = (SoundSystem*)  tolua_tousertype(tolua_S,1,0);
  const APoint* position = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
  const AVector* velocity = ((const AVector*)  tolua_tousertype(tolua_S,3,0));
  const AVector* forward = ((const AVector*)  tolua_tousertype(tolua_S,4,0));
  const AVector* up = ((const AVector*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetListener'", NULL);
#endif
  {
   self->SetListener(position,velocity,forward,up);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetListenerPos of class  SoundSystem */
#ifndef TOLUA_DISABLE_tolua_PX2_SoundSystem_GetListenerPos00
static int tolua_PX2_SoundSystem_GetListenerPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const SoundSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const SoundSystem* self = (const SoundSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetListenerPos'", NULL);
#endif
  {
   const APoint& tolua_ret = (const APoint&)  self->GetListenerPos();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const APoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetListenerPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PlayMusic of class  SoundSystem */
#ifndef TOLUA_DISABLE_tolua_PX2_SoundSystem_PlayMusic00
static int tolua_PX2_SoundSystem_PlayMusic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SoundSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SoundSystem* self = (SoundSystem*)  tolua_tousertype(tolua_S,1,0);
  int channel = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* filename = ((const char*)  tolua_tostring(tolua_S,3,0));
  bool isLoop = ((bool)  tolua_toboolean(tolua_S,4,0));
  float fadeSeconds = ((float)  tolua_tonumber(tolua_S,5,0));
  float volume = ((float)  tolua_tonumber(tolua_S,6,1.0f));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PlayMusic'", NULL);
#endif
  {
   self->PlayMusic(channel,filename,isLoop,fadeSeconds,volume);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PlayMusic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMusicVolume of class  SoundSystem */
#ifndef TOLUA_DISABLE_tolua_PX2_SoundSystem_SetMusicVolume00
static int tolua_PX2_SoundSystem_SetMusicVolume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SoundSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SoundSystem* self = (SoundSystem*)  tolua_tousertype(tolua_S,1,0);
  int channel = ((int)  tolua_tonumber(tolua_S,2,0));
  float volume = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMusicVolume'", NULL);
#endif
  {
   self->SetMusicVolume(channel,volume);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMusicVolume'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PlaySound2DControl of class  SoundSystem */
#ifndef TOLUA_DISABLE_tolua_PX2_SoundSystem_PlaySound2DControl00
static int tolua_PX2_SoundSystem_PlaySound2DControl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SoundSystem",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"Sound",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SoundSystem* self = (SoundSystem*)  tolua_tousertype(tolua_S,1,0);
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
  float volume = ((float)  tolua_tonumber(tolua_S,3,0));
  bool isLoop = ((bool)  tolua_toboolean(tolua_S,4,0));
  Sound* sound = ((Sound*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PlaySound2DControl'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->PlaySound2DControl(filename,volume,isLoop,sound);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
    tolua_pushusertype(tolua_S,(void*)sound,"Sound");
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PlaySound2DControl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PlaySound3DControl of class  SoundSystem */
#ifndef TOLUA_DISABLE_tolua_PX2_SoundSystem_PlaySound3DControl00
static int tolua_PX2_SoundSystem_PlaySound3DControl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SoundSystem",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const SoundCreateInfo3D",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,4,"Sound",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SoundSystem* self = (SoundSystem*)  tolua_tousertype(tolua_S,1,0);
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
  const SoundCreateInfo3D* createInfo = ((const SoundCreateInfo3D*)  tolua_tousertype(tolua_S,3,0));
  Sound* sound = ((Sound*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PlaySound3DControl'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->PlaySound3DControl(filename,*createInfo,sound);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
    tolua_pushusertype(tolua_S,(void*)sound,"Sound");
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PlaySound3DControl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CanPlaySameTime of class  SoundSystem */
#ifndef TOLUA_DISABLE_tolua_PX2_SoundSystem_CanPlaySameTime00
static int tolua_PX2_SoundSystem_CanPlaySameTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SoundSystem",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SoundSystem* self = (SoundSystem*)  tolua_tousertype(tolua_S,1,0);
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  float playTime = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CanPlaySameTime'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->CanPlaySameTime(filename,playTime);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)filename);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CanPlaySameTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumPlaySameTime of class  SoundSystem */
#ifndef TOLUA_DISABLE_tolua_PX2_SoundSystem_GetNumPlaySameTime00
static int tolua_PX2_SoundSystem_GetNumPlaySameTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SoundSystem",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SoundSystem* self = (SoundSystem*)  tolua_tousertype(tolua_S,1,0);
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumPlaySameTime'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetNumPlaySameTime(filename);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)filename);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumPlaySameTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDynamic of class  UIPicBox */
#ifndef TOLUA_DISABLE_tolua_PX2_UIPicBox_SetDynamic00
static int tolua_PX2_UIPicBox_SetDynamic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIPicBox",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIPicBox* self = (UIPicBox*)  tolua_tousertype(tolua_S,1,0);
  bool dyn = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDynamic'", NULL);
#endif
  {
   self->SetDynamic(dyn);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDynamic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsDynamic of class  UIPicBox */
#ifndef TOLUA_DISABLE_tolua_PX2_UIPicBox_IsDynamic00
static int tolua_PX2_UIPicBox_IsDynamic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const UIPicBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const UIPicBox* self = (const UIPicBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsDynamic'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsDynamic();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsDynamic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  UIFrame */
#ifndef TOLUA_DISABLE_tolua_PX2_UIFrame_new00
static int tolua_PX2_UIFrame_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIFrame* tolua_ret = (UIFrame*)  Mtolua_new((UIFrame)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIFrame");
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

/* method: new_local of class  UIFrame */
#ifndef TOLUA_DISABLE_tolua_PX2_UIFrame_new00_local
static int tolua_PX2_UIFrame_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIFrame* tolua_ret = (UIFrame*)  Mtolua_new((UIFrame)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIFrame");
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

/* method: delete of class  UIFrame */
#ifndef TOLUA_DISABLE_tolua_PX2_UIFrame_delete00
static int tolua_PX2_UIFrame_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIFrame* self = (UIFrame*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetObjectByName of class  UIFrame */
#ifndef TOLUA_DISABLE_tolua_PX2_UIFrame_GetObjectByName00
static int tolua_PX2_UIFrame_GetObjectByName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIFrame",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIFrame* self = (UIFrame*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObjectByName'", NULL);
#endif
  {
   Object* tolua_ret = (Object*)  self->GetObjectByName(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Object");
   tolua_pushcppstring(tolua_S,(const char*)name);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetObjectByName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  UIStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIStaticText_new00
static int tolua_PX2_UIStaticText_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIStaticText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIStaticText* tolua_ret = (UIStaticText*)  Mtolua_new((UIStaticText)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIStaticText");
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

/* method: new_local of class  UIStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIStaticText_new00_local
static int tolua_PX2_UIStaticText_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIStaticText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIStaticText* tolua_ret = (UIStaticText*)  Mtolua_new((UIStaticText)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIStaticText");
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

/* method: delete of class  UIStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIStaticText_delete00
static int tolua_PX2_UIStaticText_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIStaticText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIStaticText* self = (UIStaticText*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetFont of class  UIStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIStaticText_SetFont00
static int tolua_PX2_UIStaticText_SetFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIStaticText",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIStaticText* self = (UIStaticText*)  tolua_tousertype(tolua_S,1,0);
  const std::string fontFilename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  int fontWidth = ((int)  tolua_tonumber(tolua_S,3,0));
  int fontHeight = ((int)  tolua_tonumber(tolua_S,4,0));
  unsigned int fontStyle = ((unsigned int)  tolua_tonumber(tolua_S,5,FES_NORMAL));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFont'", NULL);
#endif
  {
   self->SetFont(fontFilename,fontWidth,fontHeight,fontStyle);
   tolua_pushcppstring(tolua_S,(const char*)fontFilename);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFont of class  UIStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIStaticText_GetFont00
static int tolua_PX2_UIStaticText_GetFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIStaticText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIStaticText* self = (UIStaticText*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFont'", NULL);
#endif
  {
   Font* tolua_ret = (Font*)  self->GetFont();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Font");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetText of class  UIStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIStaticText_SetText00
static int tolua_PX2_UIStaticText_SetText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIStaticText",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIStaticText* self = (UIStaticText*)  tolua_tousertype(tolua_S,1,0);
  std::string text = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetText'", NULL);
#endif
  {
   self->SetText(text);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetText of class  UIStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIStaticText_GetText00
static int tolua_PX2_UIStaticText_GetText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const UIStaticText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const UIStaticText* self = (const UIStaticText*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetText'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetText();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFontStyle of class  UIStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIStaticText_SetFontStyle00
static int tolua_PX2_UIStaticText_SetFontStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIStaticText",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIStaticText* self = (UIStaticText*)  tolua_tousertype(tolua_S,1,0);
  int style = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFontStyle'", NULL);
#endif
  {
   self->SetFontStyle(style);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFontStyle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFontStyle of class  UIStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIStaticText_GetFontStyle00
static int tolua_PX2_UIStaticText_GetFontStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIStaticText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIStaticText* self = (UIStaticText*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFontStyle'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetFontStyle();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFontStyle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDrawStyle of class  UIStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIStaticText_SetDrawStyle00
static int tolua_PX2_UIStaticText_SetDrawStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIStaticText",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIStaticText* self = (UIStaticText*)  tolua_tousertype(tolua_S,1,0);
  int style = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDrawStyle'", NULL);
#endif
  {
   self->SetDrawStyle(style);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDrawStyle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDrawStyle of class  UIStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIStaticText_GetDrawStyle00
static int tolua_PX2_UIStaticText_GetDrawStyle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIStaticText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIStaticText* self = (UIStaticText*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDrawStyle'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetDrawStyle();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDrawStyle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetColor of class  UIStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIStaticText_SetColor00
static int tolua_PX2_UIStaticText_SetColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIStaticText",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Float3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIStaticText* self = (UIStaticText*)  tolua_tousertype(tolua_S,1,0);
  Float3 color = *((Float3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetColor'", NULL);
#endif
  {
   self->SetColor(color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetColor of class  UIStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIStaticText_GetColor00
static int tolua_PX2_UIStaticText_GetColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const UIStaticText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const UIStaticText* self = (const UIStaticText*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetColor'", NULL);
#endif
  {
   const Float3& tolua_ret = (const Float3&)  self->GetColor();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Float3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAlpha of class  UIStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIStaticText_SetAlpha00
static int tolua_PX2_UIStaticText_SetAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIStaticText",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIStaticText* self = (UIStaticText*)  tolua_tousertype(tolua_S,1,0);
  float alpha = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAlpha'", NULL);
#endif
  {
   self->SetAlpha(alpha);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAlpha of class  UIStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIStaticText_GetAlpha00
static int tolua_PX2_UIStaticText_GetAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIStaticText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIStaticText* self = (UIStaticText*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAlpha'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetAlpha();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFontWidth of class  UIStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIStaticText_SetFontWidth00
static int tolua_PX2_UIStaticText_SetFontWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIStaticText",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIStaticText* self = (UIStaticText*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFontWidth'", NULL);
#endif
  {
   self->SetFontWidth(width);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFontWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFontWidth of class  UIStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIStaticText_GetFontWidth00
static int tolua_PX2_UIStaticText_GetFontWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIStaticText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIStaticText* self = (UIStaticText*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFontWidth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetFontWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFontWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFontHeight of class  UIStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIStaticText_SetFontHeight00
static int tolua_PX2_UIStaticText_SetFontHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIStaticText",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIStaticText* self = (UIStaticText*)  tolua_tousertype(tolua_S,1,0);
  int height = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFontHeight'", NULL);
#endif
  {
   self->SetFontHeight(height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFontHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFontHeight of class  UIStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIStaticText_GetFontHeight00
static int tolua_PX2_UIStaticText_GetFontHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIStaticText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIStaticText* self = (UIStaticText*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFontHeight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetFontHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFontHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDoubleSide of class  UIStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIStaticText_SetDoubleSide00
static int tolua_PX2_UIStaticText_SetDoubleSide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIStaticText",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIStaticText* self = (UIStaticText*)  tolua_tousertype(tolua_S,1,0);
  bool d = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDoubleSide'", NULL);
#endif
  {
   self->SetDoubleSide(d);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDoubleSide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsDoubleSide of class  UIStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIStaticText_IsDoubleSide00
static int tolua_PX2_UIStaticText_IsDoubleSide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIStaticText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIStaticText* self = (UIStaticText*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsDoubleSide'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsDoubleSide();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsDoubleSide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  UIInputStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIInputStaticText_new00
static int tolua_PX2_UIInputStaticText_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIInputStaticText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIInputStaticText* tolua_ret = (UIInputStaticText*)  Mtolua_new((UIInputStaticText)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIInputStaticText");
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

/* method: new_local of class  UIInputStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIInputStaticText_new00_local
static int tolua_PX2_UIInputStaticText_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIInputStaticText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIInputStaticText* tolua_ret = (UIInputStaticText*)  Mtolua_new((UIInputStaticText)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIInputStaticText");
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

/* method: delete of class  UIInputStaticText */
#ifndef TOLUA_DISABLE_tolua_PX2_UIInputStaticText_delete00
static int tolua_PX2_UIInputStaticText_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIInputStaticText",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIInputStaticText* self = (UIInputStaticText*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  UIEditBox */
#ifndef TOLUA_DISABLE_tolua_PX2_UIEditBox_new00
static int tolua_PX2_UIEditBox_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIEditBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIEditBox* tolua_ret = (UIEditBox*)  Mtolua_new((UIEditBox)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIEditBox");
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

/* method: new_local of class  UIEditBox */
#ifndef TOLUA_DISABLE_tolua_PX2_UIEditBox_new00_local
static int tolua_PX2_UIEditBox_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIEditBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIEditBox* tolua_ret = (UIEditBox*)  Mtolua_new((UIEditBox)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIEditBox");
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

/* method: delete of class  UIEditBox */
#ifndef TOLUA_DISABLE_tolua_PX2_UIEditBox_delete00
static int tolua_PX2_UIEditBox_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIEditBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIEditBox* self = (UIEditBox*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetPassword of class  UIEditBox */
#ifndef TOLUA_DISABLE_tolua_PX2_UIEditBox_SetPassword00
static int tolua_PX2_UIEditBox_SetPassword00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIEditBox",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIEditBox* self = (UIEditBox*)  tolua_tousertype(tolua_S,1,0);
  bool isPassword = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPassword'", NULL);
#endif
  {
   self->SetPassword(isPassword);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPassword'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsPassword of class  UIEditBox */
#ifndef TOLUA_DISABLE_tolua_PX2_UIEditBox_IsPassword00
static int tolua_PX2_UIEditBox_IsPassword00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const UIEditBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const UIEditBox* self = (const UIEditBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsPassword'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsPassword();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsPassword'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  UIEditBox */
#ifndef TOLUA_DISABLE_tolua_PX2_UIEditBox_SetSize00
static int tolua_PX2_UIEditBox_SetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIEditBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIEditBox* self = (UIEditBox*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
  {
   self->SetSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  UIEditBox */
#ifndef TOLUA_DISABLE_tolua_PX2_UIEditBox_SetSize01
static int tolua_PX2_UIEditBox_SetSize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIEditBox",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sizef",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  UIEditBox* self = (UIEditBox*)  tolua_tousertype(tolua_S,1,0);
  const Sizef* size = ((const Sizef*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
  {
   self->SetSize(*size);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_UIEditBox_SetSize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWidth of class  UIEditBox */
#ifndef TOLUA_DISABLE_tolua_PX2_UIEditBox_GetWidth00
static int tolua_PX2_UIEditBox_GetWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const UIEditBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const UIEditBox* self = (const UIEditBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWidth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHeight of class  UIEditBox */
#ifndef TOLUA_DISABLE_tolua_PX2_UIEditBox_GetHeight00
static int tolua_PX2_UIEditBox_GetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const UIEditBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const UIEditBox* self = (const UIEditBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSize of class  UIEditBox */
#ifndef TOLUA_DISABLE_tolua_PX2_UIEditBox_GetSize00
static int tolua_PX2_UIEditBox_GetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const UIEditBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const UIEditBox* self = (const UIEditBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSize'", NULL);
#endif
  {
   const Sizef& tolua_ret = (const Sizef&)  self->GetSize();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Sizef");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetText of class  UIEditBox */
#ifndef TOLUA_DISABLE_tolua_PX2_UIEditBox_SetText00
static int tolua_PX2_UIEditBox_SetText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIEditBox",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIEditBox* self = (UIEditBox*)  tolua_tousertype(tolua_S,1,0);
  const std::string text = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetText'", NULL);
#endif
  {
   self->SetText(text);
   tolua_pushcppstring(tolua_S,(const char*)text);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetText of class  UIEditBox */
#ifndef TOLUA_DISABLE_tolua_PX2_UIEditBox_GetText00
static int tolua_PX2_UIEditBox_GetText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const UIEditBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const UIEditBox* self = (const UIEditBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetText'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetText();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRealText of class  UIEditBox */
#ifndef TOLUA_DISABLE_tolua_PX2_UIEditBox_GetRealText00
static int tolua_PX2_UIEditBox_GetRealText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const UIEditBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const UIEditBox* self = (const UIEditBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRealText'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetRealText();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRealText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  UIButtonBase */
#ifndef TOLUA_DISABLE_tolua_PX2_UIButtonBase_delete00
static int tolua_PX2_UIButtonBase_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIButtonBase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIButtonBase* self = (UIButtonBase*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetButtonState of class  UIButtonBase */
#ifndef TOLUA_DISABLE_tolua_PX2_UIButtonBase_SetButtonState00
static int tolua_PX2_UIButtonBase_SetButtonState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIButtonBase",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIButtonBase* self = (UIButtonBase*)  tolua_tousertype(tolua_S,1,0);
  UIButtonBase::ButtonState state = ((UIButtonBase::ButtonState) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetButtonState'", NULL);
#endif
  {
   self->SetButtonState(state);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetButtonState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetButtonState of class  UIButtonBase */
#ifndef TOLUA_DISABLE_tolua_PX2_UIButtonBase_GetButtonState00
static int tolua_PX2_UIButtonBase_GetButtonState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const UIButtonBase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const UIButtonBase* self = (const UIButtonBase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetButtonState'", NULL);
#endif
  {
   UIButtonBase::ButtonState tolua_ret = (UIButtonBase::ButtonState)  self->GetButtonState();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetButtonState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPicBox of class  UIButtonBase */
#ifndef TOLUA_DISABLE_tolua_PX2_UIButtonBase_SetPicBox00
static int tolua_PX2_UIButtonBase_SetPicBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIButtonBase",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"UIPicBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIButtonBase* self = (UIButtonBase*)  tolua_tousertype(tolua_S,1,0);
  UIButtonBase::ButtonState state = ((UIButtonBase::ButtonState) (int)  tolua_tonumber(tolua_S,2,0));
  UIPicBox* pic = ((UIPicBox*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPicBox'", NULL);
#endif
  {
   self->SetPicBox(state,pic);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPicBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPicBoxAtState of class  UIButtonBase */
#ifndef TOLUA_DISABLE_tolua_PX2_UIButtonBase_GetPicBoxAtState00
static int tolua_PX2_UIButtonBase_GetPicBoxAtState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIButtonBase",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIButtonBase* self = (UIButtonBase*)  tolua_tousertype(tolua_S,1,0);
  UIButtonBase::ButtonState state = ((UIButtonBase::ButtonState) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPicBoxAtState'", NULL);
#endif
  {
   UIPicBox* tolua_ret = (UIPicBox*)  self->GetPicBoxAtState(state);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIPicBox");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPicBoxAtState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  UIButtonBase */
#ifndef TOLUA_DISABLE_tolua_PX2_UIButtonBase_SetSize00
static int tolua_PX2_UIButtonBase_SetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIButtonBase",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIButtonBase* self = (UIButtonBase*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
  {
   self->SetSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  UIButtonBase */
#ifndef TOLUA_DISABLE_tolua_PX2_UIButtonBase_SetSize01
static int tolua_PX2_UIButtonBase_SetSize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIButtonBase",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sizef",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  UIButtonBase* self = (UIButtonBase*)  tolua_tousertype(tolua_S,1,0);
  const Sizef* size = ((const Sizef*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
  {
   self->SetSize(*size);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_UIButtonBase_SetSize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSize of class  UIButtonBase */
#ifndef TOLUA_DISABLE_tolua_PX2_UIButtonBase_GetSize00
static int tolua_PX2_UIButtonBase_GetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const UIButtonBase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const UIButtonBase* self = (const UIButtonBase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSize'", NULL);
#endif
  {
   const Sizef& tolua_ret = (const Sizef&)  self->GetSize();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Sizef");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWidth of class  UIButtonBase */
#ifndef TOLUA_DISABLE_tolua_PX2_UIButtonBase_SetWidth00
static int tolua_PX2_UIButtonBase_SetWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIButtonBase",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIButtonBase* self = (UIButtonBase*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWidth'", NULL);
#endif
  {
   self->SetWidth(width);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWidth of class  UIButtonBase */
#ifndef TOLUA_DISABLE_tolua_PX2_UIButtonBase_GetWidth00
static int tolua_PX2_UIButtonBase_GetWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIButtonBase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIButtonBase* self = (UIButtonBase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWidth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHeight of class  UIButtonBase */
#ifndef TOLUA_DISABLE_tolua_PX2_UIButtonBase_SetHeight00
static int tolua_PX2_UIButtonBase_SetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIButtonBase",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIButtonBase* self = (UIButtonBase*)  tolua_tousertype(tolua_S,1,0);
  float height = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHeight'", NULL);
#endif
  {
   self->SetHeight(height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHeight of class  UIButtonBase */
#ifndef TOLUA_DISABLE_tolua_PX2_UIButtonBase_GetHeight00
static int tolua_PX2_UIButtonBase_GetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIButtonBase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIButtonBase* self = (UIButtonBase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  UIButton */
#ifndef TOLUA_DISABLE_tolua_PX2_UIButton_new00
static int tolua_PX2_UIButton_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIButton",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIButton* tolua_ret = (UIButton*)  Mtolua_new((UIButton)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIButton");
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

/* method: new_local of class  UIButton */
#ifndef TOLUA_DISABLE_tolua_PX2_UIButton_new00_local
static int tolua_PX2_UIButton_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIButton",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIButton* tolua_ret = (UIButton*)  Mtolua_new((UIButton)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIButton");
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

/* method: delete of class  UIButton */
#ifndef TOLUA_DISABLE_tolua_PX2_UIButton_delete00
static int tolua_PX2_UIButton_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIButton* self = (UIButton*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  UICheckButton */
#ifndef TOLUA_DISABLE_tolua_PX2_UICheckButton_new00
static int tolua_PX2_UICheckButton_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UICheckButton",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UICheckButton* tolua_ret = (UICheckButton*)  Mtolua_new((UICheckButton)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UICheckButton");
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

/* method: new_local of class  UICheckButton */
#ifndef TOLUA_DISABLE_tolua_PX2_UICheckButton_new00_local
static int tolua_PX2_UICheckButton_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UICheckButton",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UICheckButton* tolua_ret = (UICheckButton*)  Mtolua_new((UICheckButton)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UICheckButton");
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

/* method: delete of class  UICheckButton */
#ifndef TOLUA_DISABLE_tolua_PX2_UICheckButton_delete00
static int tolua_PX2_UICheckButton_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UICheckButton",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UICheckButton* self = (UICheckButton*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Enable of class  UICheckButton */
#ifndef TOLUA_DISABLE_tolua_PX2_UICheckButton_Enable00
static int tolua_PX2_UICheckButton_Enable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UICheckButton",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UICheckButton* self = (UICheckButton*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Enable'", NULL);
#endif
  {
   self->Enable(enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Enable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnEvent of class  UICheckButton */
#ifndef TOLUA_DISABLE_tolua_PX2_UICheckButton_OnEvent00
static int tolua_PX2_UICheckButton_OnEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UICheckButton",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UICheckButton* self = (UICheckButton*)  tolua_tousertype(tolua_S,1,0);
  Event* event = ((Event*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnEvent'", NULL);
#endif
  {
   self->OnEvent(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnCheck of class  UICheckButton */
#ifndef TOLUA_DISABLE_tolua_PX2_UICheckButton_OnCheck00
static int tolua_PX2_UICheckButton_OnCheck00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UICheckButton",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UICheckButton* self = (UICheckButton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnCheck'", NULL);
#endif
  {
   self->OnCheck();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnCheck'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnDisCheck of class  UICheckButton */
#ifndef TOLUA_DISABLE_tolua_PX2_UICheckButton_OnDisCheck00
static int tolua_PX2_UICheckButton_OnDisCheck00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UICheckButton",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UICheckButton* self = (UICheckButton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnDisCheck'", NULL);
#endif
  {
   self->OnDisCheck();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnDisCheck'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  UIProgressBar */
#ifndef TOLUA_DISABLE_tolua_PX2_UIProgressBar_new00
static int tolua_PX2_UIProgressBar_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIProgressBar",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIProgressBar* tolua_ret = (UIProgressBar*)  Mtolua_new((UIProgressBar)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIProgressBar");
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

/* method: new_local of class  UIProgressBar */
#ifndef TOLUA_DISABLE_tolua_PX2_UIProgressBar_new00_local
static int tolua_PX2_UIProgressBar_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIProgressBar",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIProgressBar* tolua_ret = (UIProgressBar*)  Mtolua_new((UIProgressBar)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIProgressBar");
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

/* method: delete of class  UIProgressBar */
#ifndef TOLUA_DISABLE_tolua_PX2_UIProgressBar_delete00
static int tolua_PX2_UIProgressBar_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIProgressBar",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIProgressBar* self = (UIProgressBar*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetBackPicBox of class  UIProgressBar */
#ifndef TOLUA_DISABLE_tolua_PX2_UIProgressBar_SetBackPicBox00
static int tolua_PX2_UIProgressBar_SetBackPicBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIProgressBar",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"UIPicBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIProgressBar* self = (UIProgressBar*)  tolua_tousertype(tolua_S,1,0);
  UIPicBox* picBox = ((UIPicBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBackPicBox'", NULL);
#endif
  {
   self->SetBackPicBox(picBox);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBackPicBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProgressPicBox of class  UIProgressBar */
#ifndef TOLUA_DISABLE_tolua_PX2_UIProgressBar_SetProgressPicBox00
static int tolua_PX2_UIProgressBar_SetProgressPicBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIProgressBar",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"UIPicBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIProgressBar* self = (UIProgressBar*)  tolua_tousertype(tolua_S,1,0);
  UIPicBox* picBox = ((UIPicBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProgressPicBox'", NULL);
#endif
  {
   self->SetProgressPicBox(picBox);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProgressPicBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOverPicBox of class  UIProgressBar */
#ifndef TOLUA_DISABLE_tolua_PX2_UIProgressBar_SetOverPicBox00
static int tolua_PX2_UIProgressBar_SetOverPicBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIProgressBar",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"UIPicBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIProgressBar* self = (UIProgressBar*)  tolua_tousertype(tolua_S,1,0);
  UIPicBox* picBox = ((UIPicBox*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOverPicBox'", NULL);
#endif
  {
   self->SetOverPicBox(picBox);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOverPicBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBackPicBox of class  UIProgressBar */
#ifndef TOLUA_DISABLE_tolua_PX2_UIProgressBar_GetBackPicBox00
static int tolua_PX2_UIProgressBar_GetBackPicBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIProgressBar",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIProgressBar* self = (UIProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBackPicBox'", NULL);
#endif
  {
   UIPicBox* tolua_ret = (UIPicBox*)  self->GetBackPicBox();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIPicBox");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBackPicBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetProgressPicBox of class  UIProgressBar */
#ifndef TOLUA_DISABLE_tolua_PX2_UIProgressBar_GetProgressPicBox00
static int tolua_PX2_UIProgressBar_GetProgressPicBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIProgressBar",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIProgressBar* self = (UIProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetProgressPicBox'", NULL);
#endif
  {
   UIPicBox* tolua_ret = (UIPicBox*)  self->GetProgressPicBox();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIPicBox");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetProgressPicBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOverPicBox of class  UIProgressBar */
#ifndef TOLUA_DISABLE_tolua_PX2_UIProgressBar_GetOverPicBox00
static int tolua_PX2_UIProgressBar_GetOverPicBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIProgressBar",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIProgressBar* self = (UIProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOverPicBox'", NULL);
#endif
  {
   UIPicBox* tolua_ret = (UIPicBox*)  self->GetOverPicBox();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIPicBox");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOverPicBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  UIProgressBar */
#ifndef TOLUA_DISABLE_tolua_PX2_UIProgressBar_SetSize00
static int tolua_PX2_UIProgressBar_SetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIProgressBar",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIProgressBar* self = (UIProgressBar*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
  {
   self->SetSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  UIProgressBar */
#ifndef TOLUA_DISABLE_tolua_PX2_UIProgressBar_SetSize01
static int tolua_PX2_UIProgressBar_SetSize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIProgressBar",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sizef",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  UIProgressBar* self = (UIProgressBar*)  tolua_tousertype(tolua_S,1,0);
  const Sizef* size = ((const Sizef*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
  {
   self->SetSize(*size);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_UIProgressBar_SetSize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWidth of class  UIProgressBar */
#ifndef TOLUA_DISABLE_tolua_PX2_UIProgressBar_GetWidth00
static int tolua_PX2_UIProgressBar_GetWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const UIProgressBar",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const UIProgressBar* self = (const UIProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWidth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHeight of class  UIProgressBar */
#ifndef TOLUA_DISABLE_tolua_PX2_UIProgressBar_GetHeight00
static int tolua_PX2_UIProgressBar_GetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const UIProgressBar",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const UIProgressBar* self = (const UIProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSize of class  UIProgressBar */
#ifndef TOLUA_DISABLE_tolua_PX2_UIProgressBar_GetSize00
static int tolua_PX2_UIProgressBar_GetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const UIProgressBar",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const UIProgressBar* self = (const UIProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSize'", NULL);
#endif
  {
   const Sizef& tolua_ret = (const Sizef&)  self->GetSize();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Sizef");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProgress of class  UIProgressBar */
#ifndef TOLUA_DISABLE_tolua_PX2_UIProgressBar_SetProgress00
static int tolua_PX2_UIProgressBar_SetProgress00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIProgressBar",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIProgressBar* self = (UIProgressBar*)  tolua_tousertype(tolua_S,1,0);
  float progress = ((float)  tolua_tonumber(tolua_S,2,0));
  bool useCallback = ((bool)  tolua_toboolean(tolua_S,3,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProgress'", NULL);
#endif
  {
   self->SetProgress(progress,useCallback);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProgress'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetProgress of class  UIProgressBar */
#ifndef TOLUA_DISABLE_tolua_PX2_UIProgressBar_GetProgress00
static int tolua_PX2_UIProgressBar_GetProgress00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const UIProgressBar",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const UIProgressBar* self = (const UIProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetProgress'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetProgress();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetProgress'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProgressAnimInit of class  UIProgressBar */
#ifndef TOLUA_DISABLE_tolua_PX2_UIProgressBar_SetProgressAnimInit00
static int tolua_PX2_UIProgressBar_SetProgressAnimInit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIProgressBar",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIProgressBar* self = (UIProgressBar*)  tolua_tousertype(tolua_S,1,0);
  float progress = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProgressAnimInit'", NULL);
#endif
  {
   self->SetProgressAnimInit(progress);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProgressAnimInit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProgressAnim of class  UIProgressBar */
#ifndef TOLUA_DISABLE_tolua_PX2_UIProgressBar_SetProgressAnim00
static int tolua_PX2_UIProgressBar_SetProgressAnim00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIProgressBar",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIProgressBar* self = (UIProgressBar*)  tolua_tousertype(tolua_S,1,0);
  float progress = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProgressAnim'", NULL);
#endif
  {
   self->SetProgressAnim(progress);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProgressAnim'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetProgressAnimSpeed of class  UIProgressBar */
#ifndef TOLUA_DISABLE_tolua_PX2_UIProgressBar_SetProgressAnimSpeed00
static int tolua_PX2_UIProgressBar_SetProgressAnimSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIProgressBar",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIProgressBar* self = (UIProgressBar*)  tolua_tousertype(tolua_S,1,0);
  float speed = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetProgressAnimSpeed'", NULL);
#endif
  {
   self->SetProgressAnimSpeed(speed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetProgressAnimSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetProgressAnimSpeed of class  UIProgressBar */
#ifndef TOLUA_DISABLE_tolua_PX2_UIProgressBar_GetProgressAnimSpeed00
static int tolua_PX2_UIProgressBar_GetProgressAnimSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIProgressBar",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIProgressBar* self = (UIProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetProgressAnimSpeed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetProgressAnimSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetProgressAnimSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetProgressBarCtrl of class  UIProgressBar */
#ifndef TOLUA_DISABLE_tolua_PX2_UIProgressBar_GetProgressBarCtrl00
static int tolua_PX2_UIProgressBar_GetProgressBarCtrl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIProgressBar",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIProgressBar* self = (UIProgressBar*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetProgressBarCtrl'", NULL);
#endif
  {
   UIProgressBarCtrl* tolua_ret = (UIProgressBarCtrl*)  self->GetProgressBarCtrl();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIProgressBarCtrl");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetProgressBarCtrl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  UIRangeFrame */
#ifndef TOLUA_DISABLE_tolua_PX2_UIRangeFrame_new00
static int tolua_PX2_UIRangeFrame_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIRangeFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIRangeFrame* tolua_ret = (UIRangeFrame*)  Mtolua_new((UIRangeFrame)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIRangeFrame");
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

/* method: new_local of class  UIRangeFrame */
#ifndef TOLUA_DISABLE_tolua_PX2_UIRangeFrame_new00_local
static int tolua_PX2_UIRangeFrame_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIRangeFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIRangeFrame* tolua_ret = (UIRangeFrame*)  Mtolua_new((UIRangeFrame)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIRangeFrame");
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

/* method: delete of class  UIRangeFrame */
#ifndef TOLUA_DISABLE_tolua_PX2_UIRangeFrame_delete00
static int tolua_PX2_UIRangeFrame_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIRangeFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIRangeFrame* self = (UIRangeFrame*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetSize of class  UIRangeFrame */
#ifndef TOLUA_DISABLE_tolua_PX2_UIRangeFrame_SetSize00
static int tolua_PX2_UIRangeFrame_SetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIRangeFrame",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIRangeFrame* self = (UIRangeFrame*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
  {
   self->SetSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  UIRangeFrame */
#ifndef TOLUA_DISABLE_tolua_PX2_UIRangeFrame_SetSize01
static int tolua_PX2_UIRangeFrame_SetSize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIRangeFrame",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sizef",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  UIRangeFrame* self = (UIRangeFrame*)  tolua_tousertype(tolua_S,1,0);
  const Sizef* size = ((const Sizef*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
  {
   self->SetSize(*size);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_UIRangeFrame_SetSize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWidth of class  UIRangeFrame */
#ifndef TOLUA_DISABLE_tolua_PX2_UIRangeFrame_GetWidth00
static int tolua_PX2_UIRangeFrame_GetWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const UIRangeFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const UIRangeFrame* self = (const UIRangeFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWidth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHeight of class  UIRangeFrame */
#ifndef TOLUA_DISABLE_tolua_PX2_UIRangeFrame_GetHeight00
static int tolua_PX2_UIRangeFrame_GetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const UIRangeFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const UIRangeFrame* self = (const UIRangeFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSize of class  UIRangeFrame */
#ifndef TOLUA_DISABLE_tolua_PX2_UIRangeFrame_GetSize00
static int tolua_PX2_UIRangeFrame_GetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const UIRangeFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const UIRangeFrame* self = (const UIRangeFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSize'", NULL);
#endif
  {
   const Sizef& tolua_ret = (const Sizef&)  self->GetSize();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Sizef");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AttachChild of class  UIRangeFrame */
#ifndef TOLUA_DISABLE_tolua_PX2_UIRangeFrame_AttachChild00
static int tolua_PX2_UIRangeFrame_AttachChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIRangeFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Movable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIRangeFrame* self = (UIRangeFrame*)  tolua_tousertype(tolua_S,1,0);
  Movable* child = ((Movable*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AttachChild'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AttachChild(child);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AttachChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDefaultView of class  UIManager */
#ifndef TOLUA_DISABLE_tolua_PX2_UIManager_GetDefaultView00
static int tolua_PX2_UIManager_GetDefaultView00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIManager* self = (UIManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDefaultView'", NULL);
#endif
  {
   UIView* tolua_ret = (UIView*)  self->GetDefaultView();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIView");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDefaultView'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddUIView of class  UIManager */
#ifndef TOLUA_DISABLE_tolua_PX2_UIManager_AddUIView00
static int tolua_PX2_UIManager_AddUIView00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"UIView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIManager* self = (UIManager*)  tolua_tousertype(tolua_S,1,0);
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  UIView* view = ((UIView*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddUIView'", NULL);
#endif
  {
   self->AddUIView(name,view);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddUIView'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUIViews of class  UIManager */
#ifndef TOLUA_DISABLE_tolua_PX2_UIManager_GetUIViews00
static int tolua_PX2_UIManager_GetUIViews00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIManager* self = (UIManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUIViews'", NULL);
#endif
  {
   std::map<std::string,UIViewPtr>& tolua_ret = (std::map<std::string,UIViewPtr>&)  self->GetUIViews();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"std::map<std::string,UIViewPtr>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUIViews'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUIView of class  UIManager */
#ifndef TOLUA_DISABLE_tolua_PX2_UIManager_GetUIView00
static int tolua_PX2_UIManager_GetUIView00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIManager* self = (UIManager*)  tolua_tousertype(tolua_S,1,0);
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUIView'", NULL);
#endif
  {
   UIView* tolua_ret = (UIView*)  self->GetUIView(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIView");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUIView'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateUIPicBox of class  UIManager */
#ifndef TOLUA_DISABLE_tolua_PX2_UIManager_CreateUIPicBox00
static int tolua_PX2_UIManager_CreateUIPicBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIManager* self = (UIManager*)  tolua_tousertype(tolua_S,1,0);
  const APoint* localPos = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateUIPicBox'", NULL);
#endif
  {
   UIPicBox* tolua_ret = (UIPicBox*)  self->CreateUIPicBox(*localPos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIPicBox");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateUIPicBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateUIPicBox of class  UIManager */
#ifndef TOLUA_DISABLE_tolua_PX2_UIManager_CreateUIPicBox01
static int tolua_PX2_UIManager_CreateUIPicBox01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  UIManager* self = (UIManager*)  tolua_tousertype(tolua_S,1,0);
  const APoint* localPos = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
  const std::string texPack = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateUIPicBox'", NULL);
#endif
  {
   UIPicBox* tolua_ret = (UIPicBox*)  self->CreateUIPicBox(*localPos,texPack);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIPicBox");
   tolua_pushcppstring(tolua_S,(const char*)texPack);
  }
 }
 return 2;
tolua_lerror:
 return tolua_PX2_UIManager_CreateUIPicBox00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateUIStaticText of class  UIManager */
#ifndef TOLUA_DISABLE_tolua_PX2_UIManager_CreateUIStaticText00
static int tolua_PX2_UIManager_CreateUIStaticText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIManager* self = (UIManager*)  tolua_tousertype(tolua_S,1,0);
  const APoint* localPos = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateUIStaticText'", NULL);
#endif
  {
   UIStaticText* tolua_ret = (UIStaticText*)  self->CreateUIStaticText(*localPos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIStaticText");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateUIStaticText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateUIFrame of class  UIManager */
#ifndef TOLUA_DISABLE_tolua_PX2_UIManager_CreateUIFrame00
static int tolua_PX2_UIManager_CreateUIFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIManager* self = (UIManager*)  tolua_tousertype(tolua_S,1,0);
  const APoint* localPos = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateUIFrame'", NULL);
#endif
  {
   UIFrame* tolua_ret = (UIFrame*)  self->CreateUIFrame(*localPos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIFrame");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateUIFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateUIButton of class  UIManager */
#ifndef TOLUA_DISABLE_tolua_PX2_UIManager_CreateUIButton00
static int tolua_PX2_UIManager_CreateUIButton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIManager* self = (UIManager*)  tolua_tousertype(tolua_S,1,0);
  const APoint* localPos = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateUIButton'", NULL);
#endif
  {
   UIButton* tolua_ret = (UIButton*)  self->CreateUIButton(*localPos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIButton");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateUIButton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __EventHandler__ of class  UIManager */
#ifndef TOLUA_DISABLE_tolua_get_UIManager___EventHandler__
static int tolua_get_UIManager___EventHandler__(lua_State* tolua_S)
{
  UIManager* self = (UIManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__EventHandler__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<EventHandler*>(self), "EventHandler");
#else
   tolua_pushusertype(tolua_S,(void*)((EventHandler*)self), "EventHandler");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  UIView */
#ifndef TOLUA_DISABLE_tolua_PX2_UIView_new00
static int tolua_PX2_UIView_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIView",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int id = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   UIView* tolua_ret = (UIView*)  Mtolua_new((UIView)(id));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIView");
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

/* method: new_local of class  UIView */
#ifndef TOLUA_DISABLE_tolua_PX2_UIView_new00_local
static int tolua_PX2_UIView_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIView",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int id = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   UIView* tolua_ret = (UIView*)  Mtolua_new((UIView)(id));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIView");
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

/* method: delete of class  UIView */
#ifndef TOLUA_DISABLE_tolua_PX2_UIView_delete00
static int tolua_PX2_UIView_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIView* self = (UIView*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetID of class  UIView */
#ifndef TOLUA_DISABLE_tolua_PX2_UIView_GetID00
static int tolua_PX2_UIView_GetID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIView* self = (UIView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetID'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetID();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  UIView */
#ifndef TOLUA_DISABLE_tolua_PX2_UIView_SetSize00
static int tolua_PX2_UIView_SetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIView",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIView* self = (UIView*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
  {
   self->SetSize(width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  UIView */
#ifndef TOLUA_DISABLE_tolua_PX2_UIView_SetSize01
static int tolua_PX2_UIView_SetSize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIView",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sizef",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  UIView* self = (UIView*)  tolua_tousertype(tolua_S,1,0);
  const Sizef* size = ((const Sizef*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'", NULL);
#endif
  {
   self->SetSize(*size);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_UIView_SetSize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSize of class  UIView */
#ifndef TOLUA_DISABLE_tolua_PX2_UIView_GetSize00
static int tolua_PX2_UIView_GetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const UIView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const UIView* self = (const UIView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSize'", NULL);
#endif
  {
   const Sizef& tolua_ret = (const Sizef&)  self->GetSize();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Sizef");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWidth of class  UIView */
#ifndef TOLUA_DISABLE_tolua_PX2_UIView_SetWidth00
static int tolua_PX2_UIView_SetWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIView",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIView* self = (UIView*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWidth'", NULL);
#endif
  {
   self->SetWidth(width);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWidth of class  UIView */
#ifndef TOLUA_DISABLE_tolua_PX2_UIView_GetWidth00
static int tolua_PX2_UIView_GetWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIView* self = (UIView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWidth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHeight of class  UIView */
#ifndef TOLUA_DISABLE_tolua_PX2_UIView_SetHeight00
static int tolua_PX2_UIView_SetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIView",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIView* self = (UIView*)  tolua_tousertype(tolua_S,1,0);
  float height = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHeight'", NULL);
#endif
  {
   self->SetHeight(height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHeight of class  UIView */
#ifndef TOLUA_DISABLE_tolua_PX2_UIView_GetHeight00
static int tolua_PX2_UIView_GetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIView* self = (UIView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRenderer of class  UIView */
#ifndef TOLUA_DISABLE_tolua_PX2_UIView_SetRenderer00
static int tolua_PX2_UIView_SetRenderer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIView",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIView* self = (UIView*)  tolua_tousertype(tolua_S,1,0);
  Renderer* renderer = ((Renderer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRenderer'", NULL);
#endif
  {
   self->SetRenderer(renderer);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRenderer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRenderer of class  UIView */
#ifndef TOLUA_DISABLE_tolua_PX2_UIView_GetRenderer00
static int tolua_PX2_UIView_GetRenderer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIView* self = (UIView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRenderer'", NULL);
#endif
  {
   Renderer* tolua_ret = (Renderer*)  self->GetRenderer();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Renderer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRenderer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMainFrame of class  UIView */
#ifndef TOLUA_DISABLE_tolua_PX2_UIView_SetMainFrame00
static int tolua_PX2_UIView_SetMainFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIView",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"UIFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIView* self = (UIView*)  tolua_tousertype(tolua_S,1,0);
  UIFrame* frame = ((UIFrame*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMainFrame'", NULL);
#endif
  {
   self->SetMainFrame(frame);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMainFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMainFrame of class  UIView */
#ifndef TOLUA_DISABLE_tolua_PX2_UIView_GetMainFrame00
static int tolua_PX2_UIView_GetMainFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIView* self = (UIView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMainFrame'", NULL);
#endif
  {
   UIFrame* tolua_ret = (UIFrame*)  self->GetMainFrame();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIFrame");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMainFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCamera of class  UIView */
#ifndef TOLUA_DISABLE_tolua_PX2_UIView_GetCamera00
static int tolua_PX2_UIView_GetCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIView* self = (UIView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCamera'", NULL);
#endif
  {
   Camera* tolua_ret = (Camera*)  self->GetCamera();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Camera");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCuller of class  UIView */
#ifndef TOLUA_DISABLE_tolua_PX2_UIView_GetCuller00
static int tolua_PX2_UIView_GetCuller00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIView* self = (UIView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCuller'", NULL);
#endif
  {
   Culler& tolua_ret = (Culler&)  self->GetCuller();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Culler");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCuller'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPickedPicBoxs of class  UIView */
#ifndef TOLUA_DISABLE_tolua_PX2_UIView_GetPickedPicBoxs00
static int tolua_PX2_UIView_GetPickedPicBoxs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIView* self = (UIView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPickedPicBoxs'", NULL);
#endif
  {
   std::vector<Pointer0<UIPicBox> >& tolua_ret = (std::vector<Pointer0<UIPicBox> >&)  self->GetPickedPicBoxs();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"std::vector<Pointer0<UIPicBox> >");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPickedPicBoxs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_PX2_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"Object","Object","",NULL);
  tolua_beginmodule(tolua_S,"Object");
   tolua_function(tolua_S,"GetResourcePath",tolua_PX2_Object_GetResourcePath00);
   tolua_function(tolua_S,"SetName",tolua_PX2_Object_SetName00);
   tolua_function(tolua_S,"GetName",tolua_PX2_Object_GetName00);
   tolua_function(tolua_S,"GetObjectByName",tolua_PX2_Object_GetObjectByName00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"GetTimeInMicroseconds",tolua_PX2_GetTimeInMicroseconds00);
  tolua_function(tolua_S,"GetTimeInSeconds",tolua_PX2_GetTimeInSeconds00);
  tolua_cclass(tolua_S,"Logger","Logger","",NULL);
  tolua_beginmodule(tolua_S,"Logger");
   tolua_function(tolua_S,"GetSingleton",tolua_PX2_Logger_GetSingleton00);
   tolua_function(tolua_S,"LogInfo",tolua_PX2_Logger_LogInfo00);
   tolua_function(tolua_S,"LogError",tolua_PX2_Logger_LogError00);
   tolua_function(tolua_S,"LogUser",tolua_PX2_Logger_LogUser00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"APoint","APoint","HPoint",tolua_collect_APoint);
  #else
  tolua_cclass(tolua_S,"APoint","APoint","HPoint",NULL);
  #endif
  tolua_beginmodule(tolua_S,"APoint");
   tolua_function(tolua_S,"new",tolua_PX2_APoint_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_APoint_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_APoint_new00_local);
   tolua_function(tolua_S,"new",tolua_PX2_APoint_new01);
   tolua_function(tolua_S,"new_local",tolua_PX2_APoint_new01_local);
   tolua_function(tolua_S,".call",tolua_PX2_APoint_new01_local);
   tolua_function(tolua_S,"new",tolua_PX2_APoint_new02);
   tolua_function(tolua_S,"new_local",tolua_PX2_APoint_new02_local);
   tolua_function(tolua_S,".call",tolua_PX2_APoint_new02_local);
   tolua_function(tolua_S,"delete",tolua_PX2_APoint_delete00);
   tolua_function(tolua_S,".sub",tolua_PX2_APoint__sub00);
   tolua_function(tolua_S,".add",tolua_PX2_APoint__add00);
   tolua_function(tolua_S,".sub",tolua_PX2_APoint__sub01);
   tolua_function(tolua_S,".add",tolua_PX2_APoint__add01);
   tolua_function(tolua_S,".mul",tolua_PX2_APoint__mul00);
   tolua_function(tolua_S,".div",tolua_PX2_APoint__div00);
   tolua_function(tolua_S,".sub",tolua_PX2_APoint__sub02);
   tolua_function(tolua_S,"Dot",tolua_PX2_APoint_Dot00);
   tolua_variable(tolua_S,"ORIGIN",tolua_get_APoint_ORIGIN,NULL);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"AVector","AVector","HPoint",tolua_collect_AVector);
  #else
  tolua_cclass(tolua_S,"AVector","AVector","HPoint",NULL);
  #endif
  tolua_beginmodule(tolua_S,"AVector");
   tolua_function(tolua_S,"new",tolua_PX2_AVector_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_AVector_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_AVector_new00_local);
   tolua_function(tolua_S,"new",tolua_PX2_AVector_new01);
   tolua_function(tolua_S,"new_local",tolua_PX2_AVector_new01_local);
   tolua_function(tolua_S,".call",tolua_PX2_AVector_new01_local);
   tolua_function(tolua_S,"new",tolua_PX2_AVector_new02);
   tolua_function(tolua_S,"new_local",tolua_PX2_AVector_new02_local);
   tolua_function(tolua_S,".call",tolua_PX2_AVector_new02_local);
   tolua_function(tolua_S,"new",tolua_PX2_AVector_new03);
   tolua_function(tolua_S,"new_local",tolua_PX2_AVector_new03_local);
   tolua_function(tolua_S,".call",tolua_PX2_AVector_new03_local);
   tolua_function(tolua_S,"new",tolua_PX2_AVector_new04);
   tolua_function(tolua_S,"new_local",tolua_PX2_AVector_new04_local);
   tolua_function(tolua_S,".call",tolua_PX2_AVector_new04_local);
   tolua_function(tolua_S,"delete",tolua_PX2_AVector_delete00);
   tolua_function(tolua_S,".add",tolua_PX2_AVector__add00);
   tolua_function(tolua_S,".sub",tolua_PX2_AVector__sub00);
   tolua_function(tolua_S,".mul",tolua_PX2_AVector__mul00);
   tolua_function(tolua_S,".div",tolua_PX2_AVector__div00);
   tolua_function(tolua_S,".sub",tolua_PX2_AVector__sub01);
   tolua_function(tolua_S,"Length",tolua_PX2_AVector_Length00);
   tolua_function(tolua_S,"SquaredLength",tolua_PX2_AVector_SquaredLength00);
   tolua_function(tolua_S,"Dot",tolua_PX2_AVector_Dot00);
   tolua_function(tolua_S,"Normalize",tolua_PX2_AVector_Normalize00);
   tolua_function(tolua_S,"Cross",tolua_PX2_AVector_Cross00);
   tolua_function(tolua_S,"UnitCross",tolua_PX2_AVector_UnitCross00);
   tolua_function(tolua_S,"Orthonormalize",tolua_PX2_AVector_Orthonormalize00);
   tolua_function(tolua_S,"Orthonormalize",tolua_PX2_AVector_Orthonormalize01);
   tolua_function(tolua_S,"GenerateOrthonormalBasis",tolua_PX2_AVector_GenerateOrthonormalBasis00);
   tolua_function(tolua_S,"GenerateComplementBasis",tolua_PX2_AVector_GenerateComplementBasis00);
   tolua_variable(tolua_S,"ZERO",tolua_get_AVector_ZERO,NULL);
   tolua_variable(tolua_S,"UNIT_X",tolua_get_AVector_UNIT_X,NULL);
   tolua_variable(tolua_S,"UNIT_Y",tolua_get_AVector_UNIT_Y,NULL);
   tolua_variable(tolua_S,"UNIT_Z",tolua_get_AVector_UNIT_Z,NULL);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"HPoint","HPoint","",tolua_collect_HPoint);
  #else
  tolua_cclass(tolua_S,"HPoint","HPoint","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"HPoint");
   tolua_function(tolua_S,"new",tolua_PX2_HPoint_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_HPoint_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_HPoint_new00_local);
   tolua_function(tolua_S,"new",tolua_PX2_HPoint_new01);
   tolua_function(tolua_S,"new_local",tolua_PX2_HPoint_new01_local);
   tolua_function(tolua_S,".call",tolua_PX2_HPoint_new01_local);
   tolua_function(tolua_S,"new",tolua_PX2_HPoint_new02);
   tolua_function(tolua_S,"new_local",tolua_PX2_HPoint_new02_local);
   tolua_function(tolua_S,".call",tolua_PX2_HPoint_new02_local);
   tolua_function(tolua_S,"delete",tolua_PX2_HPoint_delete00);
   tolua_function(tolua_S,".geti",tolua_PX2_HPoint__geti00);
   tolua_function(tolua_S,".seti",tolua_PX2_HPoint__seti00);
   tolua_function(tolua_S,".geti",tolua_PX2_HPoint__geti01);
   tolua_function(tolua_S,"X",tolua_PX2_HPoint_X00);
   tolua_function(tolua_S,"X",tolua_PX2_HPoint_X01);
   tolua_function(tolua_S,"Y",tolua_PX2_HPoint_Y00);
   tolua_function(tolua_S,"Y",tolua_PX2_HPoint_Y01);
   tolua_function(tolua_S,"Z",tolua_PX2_HPoint_Z00);
   tolua_function(tolua_S,"Z",tolua_PX2_HPoint_Z01);
   tolua_function(tolua_S,"W",tolua_PX2_HPoint_W00);
   tolua_function(tolua_S,"W",tolua_PX2_HPoint_W01);
   tolua_function(tolua_S,".eq",tolua_PX2_HPoint__eq00);
   tolua_function(tolua_S,".lt",tolua_PX2_HPoint__lt00);
   tolua_function(tolua_S,".le",tolua_PX2_HPoint__le00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Transform","Transform","",tolua_collect_Transform);
  #else
  tolua_cclass(tolua_S,"Transform","Transform","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Transform");
   tolua_function(tolua_S,"new",tolua_PX2_Transform_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_Transform_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_Transform_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_Transform_delete00);
   tolua_function(tolua_S,"MakeIdentity",tolua_PX2_Transform_MakeIdentity00);
   tolua_function(tolua_S,"MakeUnitScale",tolua_PX2_Transform_MakeUnitScale00);
   tolua_function(tolua_S,"IsIdentity",tolua_PX2_Transform_IsIdentity00);
   tolua_function(tolua_S,"IsRSMatrix",tolua_PX2_Transform_IsRSMatrix00);
   tolua_function(tolua_S,"IsUniformScale",tolua_PX2_Transform_IsUniformScale00);
   tolua_function(tolua_S,"SetRotate",tolua_PX2_Transform_SetRotate00);
   tolua_function(tolua_S,"SetMatrix",tolua_PX2_Transform_SetMatrix00);
   tolua_function(tolua_S,"SetTranslate",tolua_PX2_Transform_SetTranslate00);
   tolua_function(tolua_S,"SetScale",tolua_PX2_Transform_SetScale00);
   tolua_function(tolua_S,"SetUniformScale",tolua_PX2_Transform_SetUniformScale00);
   tolua_function(tolua_S,"GetRotate",tolua_PX2_Transform_GetRotate00);
   tolua_function(tolua_S,"GetMatrix",tolua_PX2_Transform_GetMatrix00);
   tolua_function(tolua_S,"GetTranslate",tolua_PX2_Transform_GetTranslate00);
   tolua_function(tolua_S,"GetScale",tolua_PX2_Transform_GetScale00);
   tolua_function(tolua_S,"GetUniformScale",tolua_PX2_Transform_GetUniformScale00);
   tolua_function(tolua_S,"GetNorm",tolua_PX2_Transform_GetNorm00);
   tolua_function(tolua_S,".mul",tolua_PX2_Transform__mul00);
   tolua_function(tolua_S,".mul",tolua_PX2_Transform__mul01);
   tolua_function(tolua_S,".mul",tolua_PX2_Transform__mul02);
   tolua_function(tolua_S,"Matrix",tolua_PX2_Transform_Matrix00);
   tolua_function(tolua_S,"Inverse",tolua_PX2_Transform_Inverse00);
   tolua_function(tolua_S,"InverseTransform",tolua_PX2_Transform_InverseTransform00);
   tolua_variable(tolua_S,"IDENTITY",tolua_get_Transform_IDENTITY,NULL);
   tolua_function(tolua_S,"GetStreamingSize",tolua_PX2_Transform_GetStreamingSize00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Controlledable","Controlledable","Object",tolua_collect_Controlledable);
  #else
  tolua_cclass(tolua_S,"Controlledable","Controlledable","Object",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Controlledable");
   tolua_function(tolua_S,"delete",tolua_PX2_Controlledable_delete00);
   tolua_function(tolua_S,"GetNumControllers",tolua_PX2_Controlledable_GetNumControllers00);
   tolua_function(tolua_S,"GetController",tolua_PX2_Controlledable_GetController00);
   tolua_function(tolua_S,"AttachController",tolua_PX2_Controlledable_AttachController00);
   tolua_function(tolua_S,"DetachController",tolua_PX2_Controlledable_DetachController00);
   tolua_function(tolua_S,"DetachAllControllers",tolua_PX2_Controlledable_DetachAllControllers00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Movable","Movable","Controlledable",tolua_collect_Movable);
  #else
  tolua_cclass(tolua_S,"Movable","Movable","Controlledable",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Movable");
   tolua_function(tolua_S,"delete",tolua_PX2_Movable_delete00);
   tolua_variable(tolua_S,"LocalTransform",tolua_get_Movable_LocalTransform,tolua_set_Movable_LocalTransform);
   tolua_variable(tolua_S,"WorldTransform",tolua_get_Movable_WorldTransform,tolua_set_Movable_WorldTransform);
   tolua_variable(tolua_S,"WorldTransformIsCurrent",tolua_get_Movable_WorldTransformIsCurrent,tolua_set_Movable_WorldTransformIsCurrent);
   tolua_variable(tolua_S,"WorldBound",tolua_get_Movable_WorldBound,tolua_set_Movable_WorldBound);
   tolua_variable(tolua_S,"WorldBoundIsCurrent",tolua_get_Movable_WorldBoundIsCurrent,tolua_set_Movable_WorldBoundIsCurrent);
   tolua_constant(tolua_S,"CULL_DYNAMIC",Movable::CULL_DYNAMIC);
   tolua_constant(tolua_S,"CULL_ALWAYS",Movable::CULL_ALWAYS);
   tolua_constant(tolua_S,"CULL_NEVER",Movable::CULL_NEVER);
   tolua_variable(tolua_S,"Culling",tolua_get_Movable_Culling,tolua_set_Movable_Culling);
   tolua_function(tolua_S,"Show",tolua_PX2_Movable_Show00);
   tolua_function(tolua_S,"IsShow",tolua_PX2_Movable_IsShow00);
   tolua_function(tolua_S,"Update",tolua_PX2_Movable_Update00);
   tolua_function(tolua_S,"GetParent",tolua_PX2_Movable_GetParent00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Renderable","Renderable","Movable",tolua_collect_Renderable);
  #else
  tolua_cclass(tolua_S,"Renderable","Renderable","Movable",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Renderable");
   tolua_constant(tolua_S,"PT_NONE",Renderable::PT_NONE);
   tolua_constant(tolua_S,"PT_POLYPOINT",Renderable::PT_POLYPOINT);
   tolua_constant(tolua_S,"PT_POLYSEGMENTS_DISJOINT",Renderable::PT_POLYSEGMENTS_DISJOINT);
   tolua_constant(tolua_S,"PT_POLYSEGMENTS_CONTIGUOUS",Renderable::PT_POLYSEGMENTS_CONTIGUOUS);
   tolua_constant(tolua_S,"PT_TRIANGLES",Renderable::PT_TRIANGLES);
   tolua_constant(tolua_S,"PT_TRIMESH",Renderable::PT_TRIMESH);
   tolua_constant(tolua_S,"PT_TRISTRIP",Renderable::PT_TRISTRIP);
   tolua_constant(tolua_S,"PT_TRIFAN",Renderable::PT_TRIFAN);
   tolua_constant(tolua_S,"PT_MAX_QUANTITY",Renderable::PT_MAX_QUANTITY);
   tolua_function(tolua_S,"delete",tolua_PX2_Renderable_delete00);
   tolua_function(tolua_S,"GetPrimitiveType",tolua_PX2_Renderable_GetPrimitiveType00);
   tolua_function(tolua_S,"SetVertexFormat",tolua_PX2_Renderable_SetVertexFormat00);
   tolua_function(tolua_S,"GetVertexFormat",tolua_PX2_Renderable_GetVertexFormat00);
   tolua_function(tolua_S,"GetVertexFormat",tolua_PX2_Renderable_GetVertexFormat01);
   tolua_function(tolua_S,"SetVertexBuffer",tolua_PX2_Renderable_SetVertexBuffer00);
   tolua_function(tolua_S,"GetVertexBuffer",tolua_PX2_Renderable_GetVertexBuffer00);
   tolua_function(tolua_S,"GetVertexBuffer",tolua_PX2_Renderable_GetVertexBuffer01);
   tolua_function(tolua_S,"SetIndexBuffer",tolua_PX2_Renderable_SetIndexBuffer00);
   tolua_function(tolua_S,"GetIndexBuffer",tolua_PX2_Renderable_GetIndexBuffer00);
   tolua_function(tolua_S,"GetIndexBuffer",tolua_PX2_Renderable_GetIndexBuffer01);
   tolua_function(tolua_S,"GetModelBound",tolua_PX2_Renderable_GetModelBound00);
   tolua_function(tolua_S,"GetModelBound",tolua_PX2_Renderable_GetModelBound01);
   tolua_constant(tolua_S,"RU_UI",Renderable::RU_UI);
   tolua_constant(tolua_S,"RU_GENERAL",Renderable::RU_GENERAL);
   tolua_constant(tolua_S,"RU_REFLECT",Renderable::RU_REFLECT);
   tolua_constant(tolua_S,"RU_SHADOWMAP",Renderable::RU_SHADOWMAP);
   tolua_constant(tolua_S,"RU_QUANTITY",Renderable::RU_QUANTITY);
   tolua_function(tolua_S,"AddRenderUsage",tolua_PX2_Renderable_AddRenderUsage00);
   tolua_function(tolua_S,"RemoveRenderUsage",tolua_PX2_Renderable_RemoveRenderUsage00);
   tolua_function(tolua_S,"GetRenderUsage",tolua_PX2_Renderable_GetRenderUsage00);
   tolua_constant(tolua_S,"RL_BACKGROUND",Renderable::RL_BACKGROUND);
   tolua_constant(tolua_S,"RL_SKY",Renderable::RL_SKY);
   tolua_constant(tolua_S,"RL_TERRAIN",Renderable::RL_TERRAIN);
   tolua_constant(tolua_S,"RL_SCENE",Renderable::RL_SCENE);
   tolua_constant(tolua_S,"RL_UI",Renderable::RL_UI);
   tolua_function(tolua_S,"SetRenderLayer",tolua_PX2_Renderable_SetRenderLayer00);
   tolua_function(tolua_S,"GetSortIndex",tolua_PX2_Renderable_GetSortIndex00);
   tolua_function(tolua_S,"SetMaterialInstance",tolua_PX2_Renderable_SetMaterialInstance00);
   tolua_function(tolua_S,"GetMaterialInstance",tolua_PX2_Renderable_GetMaterialInstance00);
   tolua_function(tolua_S,"AddLight",tolua_PX2_Renderable_AddLight00);
   tolua_function(tolua_S,"RemoveLight",tolua_PX2_Renderable_RemoveLight00);
   tolua_function(tolua_S,"ClearLights",tolua_PX2_Renderable_ClearLights00);
   tolua_function(tolua_S,"GetNumLights",tolua_PX2_Renderable_GetNumLights00);
   tolua_function(tolua_S,"GetLight",tolua_PX2_Renderable_GetLight00);
   tolua_constant(tolua_S,"GU_MODEL_BOUND_ONLY",Renderable::GU_MODEL_BOUND_ONLY);
   tolua_constant(tolua_S,"GU_NORMALS",Renderable::GU_NORMALS);
   tolua_constant(tolua_S,"GU_USE_GEOMETRY",Renderable::GU_USE_GEOMETRY);
   tolua_constant(tolua_S,"GU_USE_TCOORD_CHANNEL",Renderable::GU_USE_TCOORD_CHANNEL);
   tolua_function(tolua_S,"UpdateModelSpace",tolua_PX2_Renderable_UpdateModelSpace00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Triangles","Triangles","Renderable",tolua_collect_Triangles);
  #else
  tolua_cclass(tolua_S,"Triangles","Triangles","Renderable",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Triangles");
   tolua_function(tolua_S,"delete",tolua_PX2_Triangles_delete00);
   tolua_function(tolua_S,"GetNumTriangles",tolua_PX2_Triangles_GetNumTriangles00);
   tolua_function(tolua_S,"GetTriangle",tolua_PX2_Triangles_GetTriangle00);
   tolua_function(tolua_S,"GetModelTriangle",tolua_PX2_Triangles_GetModelTriangle00);
   tolua_function(tolua_S,"GetWorldTriangle",tolua_PX2_Triangles_GetWorldTriangle00);
   tolua_function(tolua_S,"GetNumVertices",tolua_PX2_Triangles_GetNumVertices00);
   tolua_function(tolua_S,"GetWorldTransform",tolua_PX2_Triangles_GetWorldTransform00);
   tolua_function(tolua_S,"GetPosition",tolua_PX2_Triangles_GetPosition00);
   tolua_function(tolua_S,"UpdateModelSpace",tolua_PX2_Triangles_UpdateModelSpace00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"TriMesh","TriMesh","Triangles",tolua_collect_TriMesh);
  #else
  tolua_cclass(tolua_S,"TriMesh","TriMesh","Triangles",NULL);
  #endif
  tolua_beginmodule(tolua_S,"TriMesh");
   tolua_function(tolua_S,"new",tolua_PX2_TriMesh_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_TriMesh_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_TriMesh_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_TriMesh_delete00);
   tolua_function(tolua_S,"GetNumTriangles",tolua_PX2_TriMesh_GetNumTriangles00);
   tolua_function(tolua_S,"GetTriangle",tolua_PX2_TriMesh_GetTriangle00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Node","Node","Movable",NULL);
  tolua_beginmodule(tolua_S,"Node");
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"SwitchNode","SwitchNode","Node",tolua_collect_SwitchNode);
  #else
  tolua_cclass(tolua_S,"SwitchNode","SwitchNode","Node",NULL);
  #endif
  tolua_beginmodule(tolua_S,"SwitchNode");
   tolua_function(tolua_S,"new",tolua_PX2_SwitchNode_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_SwitchNode_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_SwitchNode_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_SwitchNode_delete00);
   tolua_function(tolua_S,"Create",tolua_PX2_SwitchNode_Create00);
   tolua_constant(tolua_S,"SN_INVALID_CHILD",SwitchNode::SN_INVALID_CHILD);
   tolua_function(tolua_S,"SetActiveChild",tolua_PX2_SwitchNode_SetActiveChild00);
   tolua_function(tolua_S,"GetActiveChild",tolua_PX2_SwitchNode_GetActiveChild00);
   tolua_function(tolua_S,"DisableAllChildren",tolua_PX2_SwitchNode_DisableAllChildren00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Camera","Camera","Object",tolua_collect_Camera);
  #else
  tolua_cclass(tolua_S,"Camera","Camera","Object",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Camera");
   tolua_function(tolua_S,"new",tolua_PX2_Camera_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_Camera_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_Camera_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_Camera_delete00);
   tolua_function(tolua_S,"SetFrame",tolua_PX2_Camera_SetFrame00);
   tolua_function(tolua_S,"SetPosition",tolua_PX2_Camera_SetPosition00);
   tolua_function(tolua_S,"SetAxes",tolua_PX2_Camera_SetAxes00);
   tolua_function(tolua_S,"GetPosition",tolua_PX2_Camera_GetPosition00);
   tolua_function(tolua_S,"GetDVector",tolua_PX2_Camera_GetDVector00);
   tolua_function(tolua_S,"GetUVector",tolua_PX2_Camera_GetUVector00);
   tolua_function(tolua_S,"GetRVector",tolua_PX2_Camera_GetRVector00);
   tolua_function(tolua_S,"GetViewMatrix",tolua_PX2_Camera_GetViewMatrix00);
   tolua_constant(tolua_S,"VF_DMIN",Camera::VF_DMIN);
   tolua_constant(tolua_S,"VF_DMAX",Camera::VF_DMAX);
   tolua_constant(tolua_S,"VF_UMIN",Camera::VF_UMIN);
   tolua_constant(tolua_S,"VF_UMAX",Camera::VF_UMAX);
   tolua_constant(tolua_S,"VF_RMIN",Camera::VF_RMIN);
   tolua_constant(tolua_S,"VF_RMAX",Camera::VF_RMAX);
   tolua_constant(tolua_S,"VF_QUANTITY",Camera::VF_QUANTITY);
   tolua_function(tolua_S,"IsPerspective",tolua_PX2_Camera_IsPerspective00);
   tolua_function(tolua_S,"SetFrustum",tolua_PX2_Camera_SetFrustum00);
   tolua_function(tolua_S,"SetFrustum",tolua_PX2_Camera_SetFrustum01);
   tolua_function(tolua_S,"SetFrustum",tolua_PX2_Camera_SetFrustum02);
   tolua_function(tolua_S,"GetFrustum",tolua_PX2_Camera_GetFrustum00);
   tolua_function(tolua_S,"GetFrustum",tolua_PX2_Camera_GetFrustum01);
   tolua_function(tolua_S,"GetFrustum",tolua_PX2_Camera_GetFrustum02);
   tolua_function(tolua_S,"GetDMin",tolua_PX2_Camera_GetDMin00);
   tolua_function(tolua_S,"GetDMax",tolua_PX2_Camera_GetDMax00);
   tolua_function(tolua_S,"GetUMin",tolua_PX2_Camera_GetUMin00);
   tolua_function(tolua_S,"GetUMax",tolua_PX2_Camera_GetUMax00);
   tolua_function(tolua_S,"GetRMin",tolua_PX2_Camera_GetRMin00);
   tolua_function(tolua_S,"GetRMax",tolua_PX2_Camera_GetRMax00);
   tolua_constant(tolua_S,"PM_DEPTH_ZERO_TO_ONE",Camera::PM_DEPTH_ZERO_TO_ONE);
   tolua_constant(tolua_S,"PM_DEPTH_MINUS_ONE_TO_ONE",Camera::PM_DEPTH_MINUS_ONE_TO_ONE);
   tolua_constant(tolua_S,"PM_DEPTH_QUANTITY",Camera::PM_DEPTH_QUANTITY);
   tolua_function(tolua_S,"GetDepthType",tolua_PX2_Camera_GetDepthType00);
   tolua_function(tolua_S,"GetProjectionMatrix",tolua_PX2_Camera_GetProjectionMatrix00);
   tolua_function(tolua_S,"GetProjectionViewMatrix",tolua_PX2_Camera_GetProjectionViewMatrix00);
   tolua_function(tolua_S,"SetPreViewMatrix",tolua_PX2_Camera_SetPreViewMatrix00);
   tolua_function(tolua_S,"GetPreViewMatrix",tolua_PX2_Camera_GetPreViewMatrix00);
   tolua_function(tolua_S,"PreViewIsIdentity",tolua_PX2_Camera_PreViewIsIdentity00);
   tolua_function(tolua_S,"SetPostProjectionMatrix",tolua_PX2_Camera_SetPostProjectionMatrix00);
   tolua_function(tolua_S,"GetPostProjectionMatrix",tolua_PX2_Camera_GetPostProjectionMatrix00);
   tolua_function(tolua_S,"PostProjectionIsIdentity",tolua_PX2_Camera_PostProjectionIsIdentity00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Renderer","Renderer","",NULL);
  tolua_beginmodule(tolua_S,"Renderer");
   tolua_function(tolua_S,"Initialize",tolua_PX2_Renderer_Initialize00);
   tolua_function(tolua_S,"Terminate",tolua_PX2_Renderer_Terminate00);
   tolua_function(tolua_S,"SetDefaultRenderer",tolua_PX2_Renderer_SetDefaultRenderer00);
   tolua_function(tolua_S,"GetDefaultRenderer",tolua_PX2_Renderer_GetDefaultRenderer00);
   tolua_function(tolua_S,"GetWidth",tolua_PX2_Renderer_GetWidth00);
   tolua_function(tolua_S,"GetHeight",tolua_PX2_Renderer_GetHeight00);
   tolua_function(tolua_S,"GetColorFormat",tolua_PX2_Renderer_GetColorFormat00);
   tolua_function(tolua_S,"GetDepthStencilFormat",tolua_PX2_Renderer_GetDepthStencilFormat00);
   tolua_function(tolua_S,"GetNumMultisamples",tolua_PX2_Renderer_GetNumMultisamples00);
   tolua_function(tolua_S,"Bind",tolua_PX2_Renderer_Bind00);
   tolua_function(tolua_S,"BindAll",tolua_PX2_Renderer_BindAll00);
   tolua_function(tolua_S,"Unbind",tolua_PX2_Renderer_Unbind00);
   tolua_function(tolua_S,"UnbindAll",tolua_PX2_Renderer_UnbindAll00);
   tolua_function(tolua_S,"Enable",tolua_PX2_Renderer_Enable00);
   tolua_function(tolua_S,"Disable",tolua_PX2_Renderer_Disable00);
   tolua_function(tolua_S,"Bind",tolua_PX2_Renderer_Bind01);
   tolua_function(tolua_S,"BindAll",tolua_PX2_Renderer_BindAll01);
   tolua_function(tolua_S,"Unbind",tolua_PX2_Renderer_Unbind01);
   tolua_function(tolua_S,"UnbindAll",tolua_PX2_Renderer_UnbindAll01);
   tolua_function(tolua_S,"Enable",tolua_PX2_Renderer_Enable01);
   tolua_function(tolua_S,"Disable",tolua_PX2_Renderer_Disable01);
   tolua_function(tolua_S,"Lock",tolua_PX2_Renderer_Lock00);
   tolua_function(tolua_S,"Unlock",tolua_PX2_Renderer_Unlock00);
   tolua_function(tolua_S,"Update",tolua_PX2_Renderer_Update00);
   tolua_function(tolua_S,"UpdateAll",tolua_PX2_Renderer_UpdateAll00);
   tolua_function(tolua_S,"Bind",tolua_PX2_Renderer_Bind02);
   tolua_function(tolua_S,"BindAll",tolua_PX2_Renderer_BindAll02);
   tolua_function(tolua_S,"Unbind",tolua_PX2_Renderer_Unbind02);
   tolua_function(tolua_S,"UnbindAll",tolua_PX2_Renderer_UnbindAll02);
   tolua_function(tolua_S,"Enable",tolua_PX2_Renderer_Enable02);
   tolua_function(tolua_S,"Disable",tolua_PX2_Renderer_Disable02);
   tolua_function(tolua_S,"Lock",tolua_PX2_Renderer_Lock01);
   tolua_function(tolua_S,"Unlock",tolua_PX2_Renderer_Unlock01);
   tolua_function(tolua_S,"Update",tolua_PX2_Renderer_Update01);
   tolua_function(tolua_S,"UpdateAll",tolua_PX2_Renderer_UpdateAll01);
   tolua_function(tolua_S,"Bind",tolua_PX2_Renderer_Bind03);
   tolua_function(tolua_S,"BindAll",tolua_PX2_Renderer_BindAll03);
   tolua_function(tolua_S,"Unbind",tolua_PX2_Renderer_Unbind03);
   tolua_function(tolua_S,"UnbindAll",tolua_PX2_Renderer_UnbindAll03);
   tolua_function(tolua_S,"Enable",tolua_PX2_Renderer_Enable03);
   tolua_function(tolua_S,"Disable",tolua_PX2_Renderer_Disable03);
   tolua_function(tolua_S,"Lock",tolua_PX2_Renderer_Lock02);
   tolua_function(tolua_S,"Unlock",tolua_PX2_Renderer_Unlock02);
   tolua_function(tolua_S,"Update",tolua_PX2_Renderer_Update02);
   tolua_function(tolua_S,"UpdateAll",tolua_PX2_Renderer_UpdateAll02);
   tolua_function(tolua_S,"Bind",tolua_PX2_Renderer_Bind04);
   tolua_function(tolua_S,"BindAll",tolua_PX2_Renderer_BindAll04);
   tolua_function(tolua_S,"Unbind",tolua_PX2_Renderer_Unbind04);
   tolua_function(tolua_S,"UnbindAll",tolua_PX2_Renderer_UnbindAll04);
   tolua_function(tolua_S,"Enable",tolua_PX2_Renderer_Enable04);
   tolua_function(tolua_S,"Enable",tolua_PX2_Renderer_Enable05);
   tolua_function(tolua_S,"Disable",tolua_PX2_Renderer_Disable04);
   tolua_function(tolua_S,"Lock",tolua_PX2_Renderer_Lock03);
   tolua_function(tolua_S,"Unlock",tolua_PX2_Renderer_Unlock03);
   tolua_function(tolua_S,"Update",tolua_PX2_Renderer_Update03);
   tolua_function(tolua_S,"UpdateAll",tolua_PX2_Renderer_UpdateAll03);
   tolua_function(tolua_S,"Bind",tolua_PX2_Renderer_Bind05);
   tolua_function(tolua_S,"BindAll",tolua_PX2_Renderer_BindAll05);
   tolua_function(tolua_S,"Unbind",tolua_PX2_Renderer_Unbind05);
   tolua_function(tolua_S,"UnbindAll",tolua_PX2_Renderer_UnbindAll05);
   tolua_function(tolua_S,"Enable",tolua_PX2_Renderer_Enable06);
   tolua_function(tolua_S,"Disable",tolua_PX2_Renderer_Disable05);
   tolua_function(tolua_S,"Lock",tolua_PX2_Renderer_Lock04);
   tolua_function(tolua_S,"Unlock",tolua_PX2_Renderer_Unlock04);
   tolua_function(tolua_S,"Update",tolua_PX2_Renderer_Update04);
   tolua_function(tolua_S,"UpdateAll",tolua_PX2_Renderer_UpdateAll04);
   tolua_function(tolua_S,"Bind",tolua_PX2_Renderer_Bind06);
   tolua_function(tolua_S,"BindAll",tolua_PX2_Renderer_BindAll06);
   tolua_function(tolua_S,"Unbind",tolua_PX2_Renderer_Unbind06);
   tolua_function(tolua_S,"UnbindAll",tolua_PX2_Renderer_UnbindAll06);
   tolua_function(tolua_S,"Enable",tolua_PX2_Renderer_Enable07);
   tolua_function(tolua_S,"Disable",tolua_PX2_Renderer_Disable06);
   tolua_function(tolua_S,"Lock",tolua_PX2_Renderer_Lock05);
   tolua_function(tolua_S,"Unlock",tolua_PX2_Renderer_Unlock05);
   tolua_function(tolua_S,"Update",tolua_PX2_Renderer_Update05);
   tolua_function(tolua_S,"UpdateAll",tolua_PX2_Renderer_UpdateAll05);
   tolua_function(tolua_S,"Bind",tolua_PX2_Renderer_Bind07);
   tolua_function(tolua_S,"BindAll",tolua_PX2_Renderer_BindAll07);
   tolua_function(tolua_S,"Unbind",tolua_PX2_Renderer_Unbind07);
   tolua_function(tolua_S,"UnbindAll",tolua_PX2_Renderer_UnbindAll07);
   tolua_function(tolua_S,"Enable",tolua_PX2_Renderer_Enable08);
   tolua_function(tolua_S,"Disable",tolua_PX2_Renderer_Disable07);
   tolua_function(tolua_S,"ReadColor",tolua_PX2_Renderer_ReadColor00);
   tolua_function(tolua_S,"Bind",tolua_PX2_Renderer_Bind08);
   tolua_function(tolua_S,"BindAll",tolua_PX2_Renderer_BindAll08);
   tolua_function(tolua_S,"Unbind",tolua_PX2_Renderer_Unbind08);
   tolua_function(tolua_S,"UnbindAll",tolua_PX2_Renderer_UnbindAll08);
   tolua_function(tolua_S,"Enable",tolua_PX2_Renderer_Enable09);
   tolua_function(tolua_S,"Disable",tolua_PX2_Renderer_Disable08);
   tolua_function(tolua_S,"Bind",tolua_PX2_Renderer_Bind09);
   tolua_function(tolua_S,"BindAll",tolua_PX2_Renderer_BindAll09);
   tolua_function(tolua_S,"Unbind",tolua_PX2_Renderer_Unbind09);
   tolua_function(tolua_S,"UnbindAll",tolua_PX2_Renderer_UnbindAll09);
   tolua_function(tolua_S,"Enable",tolua_PX2_Renderer_Enable10);
   tolua_function(tolua_S,"Disable",tolua_PX2_Renderer_Disable09);
   tolua_function(tolua_S,"GetAlphaProperty",tolua_PX2_Renderer_GetAlphaProperty00);
   tolua_function(tolua_S,"GetCullProperty",tolua_PX2_Renderer_GetCullProperty00);
   tolua_function(tolua_S,"GetDepthProperty",tolua_PX2_Renderer_GetDepthProperty00);
   tolua_function(tolua_S,"GetOffsetProperty",tolua_PX2_Renderer_GetOffsetProperty00);
   tolua_function(tolua_S,"GetStencilProperty",tolua_PX2_Renderer_GetStencilProperty00);
   tolua_function(tolua_S,"GetWireProperty",tolua_PX2_Renderer_GetWireProperty00);
   tolua_function(tolua_S,"SetCamera",tolua_PX2_Renderer_SetCamera00);
   tolua_function(tolua_S,"GetCamera",tolua_PX2_Renderer_GetCamera00);
   tolua_function(tolua_S,"GetCamera",tolua_PX2_Renderer_GetCamera01);
   tolua_function(tolua_S,"GetViewMatrix",tolua_PX2_Renderer_GetViewMatrix00);
   tolua_function(tolua_S,"GetProjectionMatrix",tolua_PX2_Renderer_GetProjectionMatrix00);
   tolua_function(tolua_S,"GetPostProjectionMatrix",tolua_PX2_Renderer_GetPostProjectionMatrix00);
   tolua_function(tolua_S,"GetPickRay",tolua_PX2_Renderer_GetPickRay00);
   tolua_function(tolua_S,"PointWorldToViewPort",tolua_PX2_Renderer_PointWorldToViewPort00);
   tolua_function(tolua_S,"SetClearColor",tolua_PX2_Renderer_SetClearColor00);
   tolua_function(tolua_S,"GetClearColor",tolua_PX2_Renderer_GetClearColor00);
   tolua_function(tolua_S,"SetClearDepth",tolua_PX2_Renderer_SetClearDepth00);
   tolua_function(tolua_S,"GetClearDepth",tolua_PX2_Renderer_GetClearDepth00);
   tolua_function(tolua_S,"SetClearStencil",tolua_PX2_Renderer_SetClearStencil00);
   tolua_function(tolua_S,"GetClearStencil",tolua_PX2_Renderer_GetClearStencil00);
   tolua_function(tolua_S,"GetColorMask",tolua_PX2_Renderer_GetColorMask00);
   tolua_function(tolua_S,"SetOverrideAlphaProperty",tolua_PX2_Renderer_SetOverrideAlphaProperty00);
   tolua_function(tolua_S,"SetOverrideCullProperty",tolua_PX2_Renderer_SetOverrideCullProperty00);
   tolua_function(tolua_S,"SetOverrideDepthProperty",tolua_PX2_Renderer_SetOverrideDepthProperty00);
   tolua_function(tolua_S,"SetOverrideOffsetProperty",tolua_PX2_Renderer_SetOverrideOffsetProperty00);
   tolua_function(tolua_S,"SetOverrideStencilProperty",tolua_PX2_Renderer_SetOverrideStencilProperty00);
   tolua_function(tolua_S,"SetOverrideWireProperty",tolua_PX2_Renderer_SetOverrideWireProperty00);
   tolua_function(tolua_S,"GetOverrideAlphaProperty",tolua_PX2_Renderer_GetOverrideAlphaProperty00);
   tolua_function(tolua_S,"GetOverrideCullProperty",tolua_PX2_Renderer_GetOverrideCullProperty00);
   tolua_function(tolua_S,"GetOverrideDepthProperty",tolua_PX2_Renderer_GetOverrideDepthProperty00);
   tolua_function(tolua_S,"GetOverrideOffsetProperty",tolua_PX2_Renderer_GetOverrideOffsetProperty00);
   tolua_function(tolua_S,"GetOverrideStencilProperty",tolua_PX2_Renderer_GetOverrideStencilProperty00);
   tolua_function(tolua_S,"GetOverrideWireProperty",tolua_PX2_Renderer_GetOverrideWireProperty00);
   tolua_function(tolua_S,"SetReverseCullOrder",tolua_PX2_Renderer_SetReverseCullOrder00);
   tolua_function(tolua_S,"GetReverseCullOrder",tolua_PX2_Renderer_GetReverseCullOrder00);
   tolua_function(tolua_S,"Draw",tolua_PX2_Renderer_Draw00);
   tolua_function(tolua_S,"Draw",tolua_PX2_Renderer_Draw01);
   tolua_function(tolua_S,"Draw",tolua_PX2_Renderer_Draw02);
   tolua_function(tolua_S,"SetAlphaProperty",tolua_PX2_Renderer_SetAlphaProperty00);
   tolua_function(tolua_S,"SetCullProperty",tolua_PX2_Renderer_SetCullProperty00);
   tolua_function(tolua_S,"SetDepthProperty",tolua_PX2_Renderer_SetDepthProperty00);
   tolua_function(tolua_S,"SetOffsetProperty",tolua_PX2_Renderer_SetOffsetProperty00);
   tolua_function(tolua_S,"SetStencilProperty",tolua_PX2_Renderer_SetStencilProperty00);
   tolua_function(tolua_S,"SetWireProperty",tolua_PX2_Renderer_SetWireProperty00);
   tolua_function(tolua_S,"SetViewport",tolua_PX2_Renderer_SetViewport00);
   tolua_function(tolua_S,"GetViewport",tolua_PX2_Renderer_GetViewport00);
   tolua_function(tolua_S,"SetDepthRange",tolua_PX2_Renderer_SetDepthRange00);
   tolua_function(tolua_S,"GetDepthRange",tolua_PX2_Renderer_GetDepthRange00);
   tolua_function(tolua_S,"Resize",tolua_PX2_Renderer_Resize00);
   tolua_function(tolua_S,"ResizeWindow",tolua_PX2_Renderer_ResizeWindow00);
   tolua_function(tolua_S,"ClearColorBuffer",tolua_PX2_Renderer_ClearColorBuffer00);
   tolua_function(tolua_S,"ClearDepthBuffer",tolua_PX2_Renderer_ClearDepthBuffer00);
   tolua_function(tolua_S,"ClearStencilBuffer",tolua_PX2_Renderer_ClearStencilBuffer00);
   tolua_function(tolua_S,"ClearBuffers",tolua_PX2_Renderer_ClearBuffers00);
   tolua_function(tolua_S,"ClearColorBuffer",tolua_PX2_Renderer_ClearColorBuffer01);
   tolua_function(tolua_S,"ClearDepthBuffer",tolua_PX2_Renderer_ClearDepthBuffer01);
   tolua_function(tolua_S,"ClearStencilBuffer",tolua_PX2_Renderer_ClearStencilBuffer01);
   tolua_function(tolua_S,"ClearBuffers",tolua_PX2_Renderer_ClearBuffers01);
   tolua_function(tolua_S,"DisplayColorBuffer",tolua_PX2_Renderer_DisplayColorBuffer00);
   tolua_function(tolua_S,"SetColorMask",tolua_PX2_Renderer_SetColorMask00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"KC_UNASSIGNED",KC_UNASSIGNED);
  tolua_constant(tolua_S,"KC_ESCAPE",KC_ESCAPE);
  tolua_constant(tolua_S,"KC_1",KC_1);
  tolua_constant(tolua_S,"KC_2",KC_2);
  tolua_constant(tolua_S,"KC_3",KC_3);
  tolua_constant(tolua_S,"KC_4",KC_4);
  tolua_constant(tolua_S,"KC_5",KC_5);
  tolua_constant(tolua_S,"KC_6",KC_6);
  tolua_constant(tolua_S,"KC_7",KC_7);
  tolua_constant(tolua_S,"KC_8",KC_8);
  tolua_constant(tolua_S,"KC_9",KC_9);
  tolua_constant(tolua_S,"KC_0",KC_0);
  tolua_constant(tolua_S,"KC_MINUS",KC_MINUS);
  tolua_constant(tolua_S,"KC_EQUALS",KC_EQUALS);
  tolua_constant(tolua_S,"KC_BACK",KC_BACK);
  tolua_constant(tolua_S,"KC_TAB",KC_TAB);
  tolua_constant(tolua_S,"KC_Q",KC_Q);
  tolua_constant(tolua_S,"KC_W",KC_W);
  tolua_constant(tolua_S,"KC_E",KC_E);
  tolua_constant(tolua_S,"KC_R",KC_R);
  tolua_constant(tolua_S,"KC_T",KC_T);
  tolua_constant(tolua_S,"KC_Y",KC_Y);
  tolua_constant(tolua_S,"KC_U",KC_U);
  tolua_constant(tolua_S,"KC_I",KC_I);
  tolua_constant(tolua_S,"KC_O",KC_O);
  tolua_constant(tolua_S,"KC_P",KC_P);
  tolua_constant(tolua_S,"KC_LBRACKET",KC_LBRACKET);
  tolua_constant(tolua_S,"KC_RBRACKET",KC_RBRACKET);
  tolua_constant(tolua_S,"KC_RETURN",KC_RETURN);
  tolua_constant(tolua_S,"KC_LCONTROL",KC_LCONTROL);
  tolua_constant(tolua_S,"KC_A",KC_A);
  tolua_constant(tolua_S,"KC_S",KC_S);
  tolua_constant(tolua_S,"KC_D",KC_D);
  tolua_constant(tolua_S,"KC_F",KC_F);
  tolua_constant(tolua_S,"KC_G",KC_G);
  tolua_constant(tolua_S,"KC_H",KC_H);
  tolua_constant(tolua_S,"KC_J",KC_J);
  tolua_constant(tolua_S,"KC_K",KC_K);
  tolua_constant(tolua_S,"KC_L",KC_L);
  tolua_constant(tolua_S,"KC_SEMICOLON",KC_SEMICOLON);
  tolua_constant(tolua_S,"KC_APOSTROPHE",KC_APOSTROPHE);
  tolua_constant(tolua_S,"KC_GRAVE",KC_GRAVE);
  tolua_constant(tolua_S,"KC_LSHIFT",KC_LSHIFT);
  tolua_constant(tolua_S,"KC_BACKSLASH",KC_BACKSLASH);
  tolua_constant(tolua_S,"KC_Z",KC_Z);
  tolua_constant(tolua_S,"KC_X",KC_X);
  tolua_constant(tolua_S,"KC_C",KC_C);
  tolua_constant(tolua_S,"KC_V",KC_V);
  tolua_constant(tolua_S,"KC_B",KC_B);
  tolua_constant(tolua_S,"KC_N",KC_N);
  tolua_constant(tolua_S,"KC_M",KC_M);
  tolua_constant(tolua_S,"KC_COMMA",KC_COMMA);
  tolua_constant(tolua_S,"KC_PERIOD",KC_PERIOD);
  tolua_constant(tolua_S,"KC_SLASH",KC_SLASH);
  tolua_constant(tolua_S,"KC_RSHIFT",KC_RSHIFT);
  tolua_constant(tolua_S,"KC_MULTIPLY",KC_MULTIPLY);
  tolua_constant(tolua_S,"KC_LMENU",KC_LMENU);
  tolua_constant(tolua_S,"KC_SPACE",KC_SPACE);
  tolua_constant(tolua_S,"KC_CAPITAL",KC_CAPITAL);
  tolua_constant(tolua_S,"KC_F1",KC_F1);
  tolua_constant(tolua_S,"KC_F2",KC_F2);
  tolua_constant(tolua_S,"KC_F3",KC_F3);
  tolua_constant(tolua_S,"KC_F4",KC_F4);
  tolua_constant(tolua_S,"KC_F5",KC_F5);
  tolua_constant(tolua_S,"KC_F6",KC_F6);
  tolua_constant(tolua_S,"KC_F7",KC_F7);
  tolua_constant(tolua_S,"KC_F8",KC_F8);
  tolua_constant(tolua_S,"KC_F9",KC_F9);
  tolua_constant(tolua_S,"KC_F10",KC_F10);
  tolua_constant(tolua_S,"KC_NUMLOCK",KC_NUMLOCK);
  tolua_constant(tolua_S,"KC_SCROLL",KC_SCROLL);
  tolua_constant(tolua_S,"KC_NUMPAD7",KC_NUMPAD7);
  tolua_constant(tolua_S,"KC_NUMPAD8",KC_NUMPAD8);
  tolua_constant(tolua_S,"KC_NUMPAD9",KC_NUMPAD9);
  tolua_constant(tolua_S,"KC_SUBTRACT",KC_SUBTRACT);
  tolua_constant(tolua_S,"KC_NUMPAD4",KC_NUMPAD4);
  tolua_constant(tolua_S,"KC_NUMPAD5",KC_NUMPAD5);
  tolua_constant(tolua_S,"KC_NUMPAD6",KC_NUMPAD6);
  tolua_constant(tolua_S,"KC_ADD",KC_ADD);
  tolua_constant(tolua_S,"KC_NUMPAD1",KC_NUMPAD1);
  tolua_constant(tolua_S,"KC_NUMPAD2",KC_NUMPAD2);
  tolua_constant(tolua_S,"KC_NUMPAD3",KC_NUMPAD3);
  tolua_constant(tolua_S,"KC_NUMPAD0",KC_NUMPAD0);
  tolua_constant(tolua_S,"KC_DECIMAL",KC_DECIMAL);
  tolua_constant(tolua_S,"KC_OEM_102",KC_OEM_102);
  tolua_constant(tolua_S,"KC_F11",KC_F11);
  tolua_constant(tolua_S,"KC_F12",KC_F12);
  tolua_constant(tolua_S,"KC_F13",KC_F13);
  tolua_constant(tolua_S,"KC_F14",KC_F14);
  tolua_constant(tolua_S,"KC_F15",KC_F15);
  tolua_constant(tolua_S,"KC_KANA",KC_KANA);
  tolua_constant(tolua_S,"KC_ABNT_C1",KC_ABNT_C1);
  tolua_constant(tolua_S,"KC_CONVERT",KC_CONVERT);
  tolua_constant(tolua_S,"KC_NOCONVERT",KC_NOCONVERT);
  tolua_constant(tolua_S,"KC_YEN",KC_YEN);
  tolua_constant(tolua_S,"KC_ABNT_C2",KC_ABNT_C2);
  tolua_constant(tolua_S,"KC_NUMPADEQUALS",KC_NUMPADEQUALS);
  tolua_constant(tolua_S,"KC_PREVTRACK",KC_PREVTRACK);
  tolua_constant(tolua_S,"KC_AT",KC_AT);
  tolua_constant(tolua_S,"KC_COLON",KC_COLON);
  tolua_constant(tolua_S,"KC_UNDERLINE",KC_UNDERLINE);
  tolua_constant(tolua_S,"KC_KANJI",KC_KANJI);
  tolua_constant(tolua_S,"KC_STOP",KC_STOP);
  tolua_constant(tolua_S,"KC_AX",KC_AX);
  tolua_constant(tolua_S,"KC_UNLABELED",KC_UNLABELED);
  tolua_constant(tolua_S,"KC_NEXTTRACK",KC_NEXTTRACK);
  tolua_constant(tolua_S,"KC_NUMPADENTER",KC_NUMPADENTER);
  tolua_constant(tolua_S,"KC_RCONTROL",KC_RCONTROL);
  tolua_constant(tolua_S,"KC_MUTE",KC_MUTE);
  tolua_constant(tolua_S,"KC_CALCULATOR",KC_CALCULATOR);
  tolua_constant(tolua_S,"KC_PLAYPAUSE",KC_PLAYPAUSE);
  tolua_constant(tolua_S,"KC_MEDIASTOP",KC_MEDIASTOP);
  tolua_constant(tolua_S,"KC_VOLUMEDOWN",KC_VOLUMEDOWN);
  tolua_constant(tolua_S,"KC_VOLUMEUP",KC_VOLUMEUP);
  tolua_constant(tolua_S,"KC_WEBHOME",KC_WEBHOME);
  tolua_constant(tolua_S,"KC_NUMPADCOMMA",KC_NUMPADCOMMA);
  tolua_constant(tolua_S,"KC_DIVIDE",KC_DIVIDE);
  tolua_constant(tolua_S,"KC_SYSRQ",KC_SYSRQ);
  tolua_constant(tolua_S,"KC_RMENU",KC_RMENU);
  tolua_constant(tolua_S,"KC_PAUSE",KC_PAUSE);
  tolua_constant(tolua_S,"KC_HOME",KC_HOME);
  tolua_constant(tolua_S,"KC_UP",KC_UP);
  tolua_constant(tolua_S,"KC_PGUP",KC_PGUP);
  tolua_constant(tolua_S,"KC_LEFT",KC_LEFT);
  tolua_constant(tolua_S,"KC_RIGHT",KC_RIGHT);
  tolua_constant(tolua_S,"KC_END",KC_END);
  tolua_constant(tolua_S,"KC_DOWN",KC_DOWN);
  tolua_constant(tolua_S,"KC_PGDOWN",KC_PGDOWN);
  tolua_constant(tolua_S,"KC_INSERT",KC_INSERT);
  tolua_constant(tolua_S,"KC_DELETE",KC_DELETE);
  tolua_constant(tolua_S,"KC_LWIN",KC_LWIN);
  tolua_constant(tolua_S,"KC_RWIN",KC_RWIN);
  tolua_constant(tolua_S,"KC_APPS",KC_APPS);
  tolua_constant(tolua_S,"KC_POWER",KC_POWER);
  tolua_constant(tolua_S,"KC_SLEEP",KC_SLEEP);
  tolua_constant(tolua_S,"KC_WAKE",KC_WAKE);
  tolua_constant(tolua_S,"KC_WEBSEARCH",KC_WEBSEARCH);
  tolua_constant(tolua_S,"KC_WEBFAVORITES",KC_WEBFAVORITES);
  tolua_constant(tolua_S,"KC_WEBREFRESH",KC_WEBREFRESH);
  tolua_constant(tolua_S,"KC_WEBSTOP",KC_WEBSTOP);
  tolua_constant(tolua_S,"KC_WEBFORWARD",KC_WEBFORWARD);
  tolua_constant(tolua_S,"KC_WEBBACK",KC_WEBBACK);
  tolua_constant(tolua_S,"KC_MYCOMPUTER",KC_MYCOMPUTER);
  tolua_constant(tolua_S,"KC_MAIL",KC_MAIL);
  tolua_constant(tolua_S,"KC_MEDIASELECT",KC_MEDIASELECT);
  tolua_constant(tolua_S,"MBID_LEFT",MBID_LEFT);
  tolua_constant(tolua_S,"MBID_RIGHT",MBID_RIGHT);
  tolua_constant(tolua_S,"MBID_MIDDLE",MBID_MIDDLE);
  tolua_constant(tolua_S,"MBID_Button3",MBID_Button3);
  tolua_constant(tolua_S,"MBID_Button4",MBID_Button4);
  tolua_constant(tolua_S,"MBID_Button5",MBID_Button5);
  tolua_constant(tolua_S,"MBID_Button6",MBID_Button6);
  tolua_constant(tolua_S,"MBID_Button7",MBID_Button7);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"InputEventData","InputEventData","",tolua_collect_InputEventData);
  #else
  tolua_cclass(tolua_S,"InputEventData","InputEventData","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"InputEventData");
   tolua_function(tolua_S,"new",tolua_PX2_InputEventData_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_InputEventData_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_InputEventData_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_InputEventData_delete00);
   tolua_variable(tolua_S,"KCode",tolua_get_InputEventData_KCode,tolua_set_InputEventData_KCode);
   tolua_variable(tolua_S,"MButtonID",tolua_get_InputEventData_MButtonID,tolua_set_InputEventData_MButtonID);
   tolua_variable(tolua_S,"MState",tolua_get_InputEventData_MState,tolua_set_InputEventData_MState);
   tolua_variable(tolua_S,"TState",tolua_get_InputEventData_TState,tolua_set_InputEventData_TState);
   tolua_variable(tolua_S,"TStates",tolua_get_InputEventData_TStates,tolua_set_InputEventData_TStates);
   tolua_variable(tolua_S,"ViewID",tolua_get_InputEventData_ViewID,tolua_set_InputEventData_ViewID);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ScriptManager","ScriptManager","",NULL);
  tolua_beginmodule(tolua_S,"ScriptManager");
   tolua_function(tolua_S,"GetSingleton",tolua_PX2_ScriptManager_GetSingleton00);
   tolua_function(tolua_S,"CallString",tolua_PX2_ScriptManager_CallString00);
   tolua_function(tolua_S,"CallFile",tolua_PX2_ScriptManager_CallFile00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ResourceManager","ResourceManager","",NULL);
  tolua_beginmodule(tolua_S,"ResourceManager");
   tolua_function(tolua_S,"GetSingleton",tolua_PX2_ResourceManager_GetSingleton00);
   tolua_constant(tolua_S,"LS_UNLOADED",ResourceManager::LS_UNLOADED);
   tolua_constant(tolua_S,"LS_LOADQUE",ResourceManager::LS_LOADQUE);
   tolua_constant(tolua_S,"LS_LOADING",ResourceManager::LS_LOADING);
   tolua_constant(tolua_S,"LS_LOADED",ResourceManager::LS_LOADED);
   tolua_constant(tolua_S,"LS_MAX_STATE",ResourceManager::LS_MAX_STATE);
   tolua_function(tolua_S,"Clear",tolua_PX2_ResourceManager_Clear00);
   tolua_function(tolua_S,"BlockLoad",tolua_PX2_ResourceManager_BlockLoad00);
   tolua_function(tolua_S,"BackgroundLoad",tolua_PX2_ResourceManager_BackgroundLoad00);
   tolua_function(tolua_S,"CheckRes",tolua_PX2_ResourceManager_CheckRes00);
   tolua_function(tolua_S,"GetResLoadState",tolua_PX2_ResourceManager_GetResLoadState00);
   tolua_function(tolua_S,"SetUseGarbageCollect",tolua_PX2_ResourceManager_SetUseGarbageCollect00);
   tolua_function(tolua_S,"IsUseGarbageCollect",tolua_PX2_ResourceManager_IsUseGarbageCollect00);
   tolua_function(tolua_S,"SetGarbageCollectTime",tolua_PX2_ResourceManager_SetGarbageCollectTime00);
   tolua_function(tolua_S,"GetGarbageCollectTime",tolua_PX2_ResourceManager_GetGarbageCollectTime00);
   tolua_function(tolua_S,"LoadBuffer",tolua_PX2_ResourceManager_LoadBuffer00);
   tolua_function(tolua_S,"AddTexPack",tolua_PX2_ResourceManager_AddTexPack00);
   tolua_function(tolua_S,"GetTexPack",tolua_PX2_ResourceManager_GetTexPack00);
   tolua_function(tolua_S,"GetTexPackElement",tolua_PX2_ResourceManager_GetTexPackElement00);
   tolua_function(tolua_S,"GetWriteablePath",tolua_PX2_ResourceManager_GetWriteablePath00);
   tolua_function(tolua_S,"GetResourcePath",tolua_PX2_ResourceManager_GetResourcePath00);
   tolua_function(tolua_S,"DDSKeepCompressed",tolua_PX2_ResourceManager_DDSKeepCompressed00);
   tolua_function(tolua_S,"IsDDSKeepCompressed",tolua_PX2_ResourceManager_IsDDSKeepCompressed00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"LanguageManager","LanguageManager","",NULL);
  tolua_beginmodule(tolua_S,"LanguageManager");
   tolua_function(tolua_S,"GetSingleton",tolua_PX2_LanguageManager_GetSingleton00);
   tolua_function(tolua_S,"Load",tolua_PX2_LanguageManager_Load00);
   tolua_function(tolua_S,"SetLanguage",tolua_PX2_LanguageManager_SetLanguage00);
   tolua_function(tolua_S,"GetValue",tolua_PX2_LanguageManager_GetValue00);
   tolua_function(tolua_S,"GetValue",tolua_PX2_LanguageManager_GetValue01);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Sound","Sound","",tolua_collect_Sound);
  #else
  tolua_cclass(tolua_S,"Sound","Sound","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Sound");
   tolua_function(tolua_S,"delete",tolua_PX2_Sound_delete00);
   tolua_function(tolua_S,"IsPlaying",tolua_PX2_Sound_IsPlaying00);
   tolua_function(tolua_S,"SetVolume",tolua_PX2_Sound_SetVolume00);
   tolua_function(tolua_S,"SetPaused",tolua_PX2_Sound_SetPaused00);
   tolua_function(tolua_S,"Stop",tolua_PX2_Sound_Stop00);
   tolua_function(tolua_S,"SetPosition",tolua_PX2_Sound_SetPosition00);
   tolua_function(tolua_S,"SetVelocity",tolua_PX2_Sound_SetVelocity00);
   tolua_function(tolua_S,"SetDistance",tolua_PX2_Sound_SetDistance00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"SoundSystemInitInfo","SoundSystemInitInfo","",tolua_collect_SoundSystemInitInfo);
  #else
  tolua_cclass(tolua_S,"SoundSystemInitInfo","SoundSystemInitInfo","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"SoundSystemInitInfo");
   tolua_function(tolua_S,"new",tolua_PX2_SoundSystemInitInfo_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_SoundSystemInitInfo_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_SoundSystemInitInfo_new00_local);
   tolua_variable(tolua_S,"MaxChannels",tolua_get_SoundSystemInitInfo_MaxChannels,tolua_set_SoundSystemInitInfo_MaxChannels);
   tolua_variable(tolua_S,"DopplerScale",tolua_get_SoundSystemInitInfo_DopplerScale,tolua_set_SoundSystemInitInfo_DopplerScale);
   tolua_variable(tolua_S,"DistanceFactor",tolua_get_SoundSystemInitInfo_DistanceFactor,tolua_set_SoundSystemInitInfo_DistanceFactor);
   tolua_variable(tolua_S,"RolloffScale",tolua_get_SoundSystemInitInfo_RolloffScale,tolua_set_SoundSystemInitInfo_RolloffScale);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"SoundCreateInfo3D","SoundCreateInfo3D","",tolua_collect_SoundCreateInfo3D);
  #else
  tolua_cclass(tolua_S,"SoundCreateInfo3D","SoundCreateInfo3D","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"SoundCreateInfo3D");
   tolua_function(tolua_S,"new",tolua_PX2_SoundCreateInfo3D_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_SoundCreateInfo3D_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_SoundCreateInfo3D_new00_local);
   tolua_variable(tolua_S,"MinDistance",tolua_get_SoundCreateInfo3D_MinDistance,tolua_set_SoundCreateInfo3D_MinDistance);
   tolua_variable(tolua_S,"MaxDistance",tolua_get_SoundCreateInfo3D_MaxDistance,tolua_set_SoundCreateInfo3D_MaxDistance);
   tolua_variable(tolua_S,"Volume",tolua_get_SoundCreateInfo3D_Volume,tolua_set_SoundCreateInfo3D_Volume);
   tolua_variable(tolua_S,"Position",tolua_get_SoundCreateInfo3D_Position,tolua_set_SoundCreateInfo3D_Position);
   tolua_variable(tolua_S,"Velocity",tolua_get_SoundCreateInfo3D_Velocity,tolua_set_SoundCreateInfo3D_Velocity);
   tolua_variable(tolua_S,"IsLoop",tolua_get_SoundCreateInfo3D_IsLoop,tolua_set_SoundCreateInfo3D_IsLoop);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"SoundSystem","SoundSystem","",NULL);
  tolua_beginmodule(tolua_S,"SoundSystem");
   tolua_function(tolua_S,"GetSingleton",tolua_PX2_SoundSystem_GetSingleton00);
   tolua_constant(tolua_S,"ST_NULL",SoundSystem::ST_NULL);
   tolua_constant(tolua_S,"ST_FMOD",SoundSystem::ST_FMOD);
   tolua_constant(tolua_S,"ST_ANDROID",SoundSystem::ST_ANDROID);
   tolua_constant(tolua_S,"ST_MARM",SoundSystem::ST_MARM);
   tolua_constant(tolua_S,"ST_MAX_TYPE",SoundSystem::ST_MAX_TYPE);
   tolua_function(tolua_S,"GetSystemType",tolua_PX2_SoundSystem_GetSystemType00);
   tolua_function(tolua_S,"SetMaxNumPlaySameTime",tolua_PX2_SoundSystem_SetMaxNumPlaySameTime00);
   tolua_function(tolua_S,"GetMaxNumPlaySameTime",tolua_PX2_SoundSystem_GetMaxNumPlaySameTime00);
   tolua_function(tolua_S,"SetPlaySameTimeRange",tolua_PX2_SoundSystem_SetPlaySameTimeRange00);
   tolua_function(tolua_S,"GetPlaySameTimeRange",tolua_PX2_SoundSystem_GetPlaySameTimeRange00);
   tolua_function(tolua_S,"SetListener",tolua_PX2_SoundSystem_SetListener00);
   tolua_function(tolua_S,"GetListenerPos",tolua_PX2_SoundSystem_GetListenerPos00);
   tolua_function(tolua_S,"PlayMusic",tolua_PX2_SoundSystem_PlayMusic00);
   tolua_function(tolua_S,"SetMusicVolume",tolua_PX2_SoundSystem_SetMusicVolume00);
   tolua_function(tolua_S,"PlaySound2DControl",tolua_PX2_SoundSystem_PlaySound2DControl00);
   tolua_function(tolua_S,"PlaySound3DControl",tolua_PX2_SoundSystem_PlaySound3DControl00);
   tolua_function(tolua_S,"CanPlaySameTime",tolua_PX2_SoundSystem_CanPlaySameTime00);
   tolua_function(tolua_S,"GetNumPlaySameTime",tolua_PX2_SoundSystem_GetNumPlaySameTime00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"UICT_NONE",UICT_NONE);
  tolua_constant(tolua_S,"UICT_PRESSED",UICT_PRESSED);
  tolua_constant(tolua_S,"UICT_RELEASED",UICT_RELEASED);
  tolua_constant(tolua_S,"UICT_RELEASED_NOTVALIED",UICT_RELEASED_NOTVALIED);
  tolua_constant(tolua_S,"UICT_PROGRESSCHANGED",UICT_PROGRESSCHANGED);
  tolua_constant(tolua_S,"UICT_EDITBOX_ATTACHWITHIME",UICT_EDITBOX_ATTACHWITHIME);
  tolua_constant(tolua_S,"UICT_EDITBOX_DETACHWITHIME",UICT_EDITBOX_DETACHWITHIME);
  tolua_constant(tolua_S,"UICT_EDITBOX_TEXTCHANGED",UICT_EDITBOX_TEXTCHANGED);
  tolua_constant(tolua_S,"UICT_EDITBOX_ENTER",UICT_EDITBOX_ENTER);
  tolua_constant(tolua_S,"UICT_MAX_TYPE",UICT_MAX_TYPE);
  tolua_cclass(tolua_S,"UIPicBox","UIPicBox","TriMesh",NULL);
  tolua_beginmodule(tolua_S,"UIPicBox");
   tolua_function(tolua_S,"SetDynamic",tolua_PX2_UIPicBox_SetDynamic00);
   tolua_function(tolua_S,"IsDynamic",tolua_PX2_UIPicBox_IsDynamic00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"UIFrame","UIFrame","Node",tolua_collect_UIFrame);
  #else
  tolua_cclass(tolua_S,"UIFrame","UIFrame","Node",NULL);
  #endif
  tolua_beginmodule(tolua_S,"UIFrame");
   tolua_function(tolua_S,"new",tolua_PX2_UIFrame_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_UIFrame_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_UIFrame_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_UIFrame_delete00);
   tolua_function(tolua_S,"GetObjectByName",tolua_PX2_UIFrame_GetObjectByName00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"UIStaticText","UIStaticText","TriMesh",tolua_collect_UIStaticText);
  #else
  tolua_cclass(tolua_S,"UIStaticText","UIStaticText","TriMesh",NULL);
  #endif
  tolua_beginmodule(tolua_S,"UIStaticText");
   tolua_function(tolua_S,"new",tolua_PX2_UIStaticText_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_UIStaticText_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_UIStaticText_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_UIStaticText_delete00);
   tolua_function(tolua_S,"SetFont",tolua_PX2_UIStaticText_SetFont00);
   tolua_function(tolua_S,"GetFont",tolua_PX2_UIStaticText_GetFont00);
   tolua_function(tolua_S,"SetText",tolua_PX2_UIStaticText_SetText00);
   tolua_function(tolua_S,"GetText",tolua_PX2_UIStaticText_GetText00);
   tolua_function(tolua_S,"SetFontStyle",tolua_PX2_UIStaticText_SetFontStyle00);
   tolua_function(tolua_S,"GetFontStyle",tolua_PX2_UIStaticText_GetFontStyle00);
   tolua_function(tolua_S,"SetDrawStyle",tolua_PX2_UIStaticText_SetDrawStyle00);
   tolua_function(tolua_S,"GetDrawStyle",tolua_PX2_UIStaticText_GetDrawStyle00);
   tolua_function(tolua_S,"SetColor",tolua_PX2_UIStaticText_SetColor00);
   tolua_function(tolua_S,"GetColor",tolua_PX2_UIStaticText_GetColor00);
   tolua_function(tolua_S,"SetAlpha",tolua_PX2_UIStaticText_SetAlpha00);
   tolua_function(tolua_S,"GetAlpha",tolua_PX2_UIStaticText_GetAlpha00);
   tolua_function(tolua_S,"SetFontWidth",tolua_PX2_UIStaticText_SetFontWidth00);
   tolua_function(tolua_S,"GetFontWidth",tolua_PX2_UIStaticText_GetFontWidth00);
   tolua_function(tolua_S,"SetFontHeight",tolua_PX2_UIStaticText_SetFontHeight00);
   tolua_function(tolua_S,"GetFontHeight",tolua_PX2_UIStaticText_GetFontHeight00);
   tolua_function(tolua_S,"SetDoubleSide",tolua_PX2_UIStaticText_SetDoubleSide00);
   tolua_function(tolua_S,"IsDoubleSide",tolua_PX2_UIStaticText_IsDoubleSide00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"UIInputStaticText","UIInputStaticText","UIStaticText",tolua_collect_UIInputStaticText);
  #else
  tolua_cclass(tolua_S,"UIInputStaticText","UIInputStaticText","UIStaticText",NULL);
  #endif
  tolua_beginmodule(tolua_S,"UIInputStaticText");
   tolua_function(tolua_S,"new",tolua_PX2_UIInputStaticText_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_UIInputStaticText_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_UIInputStaticText_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_UIInputStaticText_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"UIEditBox","UIEditBox","UIFrame",tolua_collect_UIEditBox);
  #else
  tolua_cclass(tolua_S,"UIEditBox","UIEditBox","UIFrame",NULL);
  #endif
  tolua_beginmodule(tolua_S,"UIEditBox");
   tolua_function(tolua_S,"new",tolua_PX2_UIEditBox_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_UIEditBox_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_UIEditBox_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_UIEditBox_delete00);
   tolua_function(tolua_S,"SetPassword",tolua_PX2_UIEditBox_SetPassword00);
   tolua_function(tolua_S,"IsPassword",tolua_PX2_UIEditBox_IsPassword00);
   tolua_function(tolua_S,"SetSize",tolua_PX2_UIEditBox_SetSize00);
   tolua_function(tolua_S,"SetSize",tolua_PX2_UIEditBox_SetSize01);
   tolua_function(tolua_S,"GetWidth",tolua_PX2_UIEditBox_GetWidth00);
   tolua_function(tolua_S,"GetHeight",tolua_PX2_UIEditBox_GetHeight00);
   tolua_function(tolua_S,"GetSize",tolua_PX2_UIEditBox_GetSize00);
   tolua_function(tolua_S,"SetText",tolua_PX2_UIEditBox_SetText00);
   tolua_function(tolua_S,"GetText",tolua_PX2_UIEditBox_GetText00);
   tolua_function(tolua_S,"GetRealText",tolua_PX2_UIEditBox_GetRealText00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"UIButtonBase","UIButtonBase","UIFrame",tolua_collect_UIButtonBase);
  #else
  tolua_cclass(tolua_S,"UIButtonBase","UIButtonBase","UIFrame",NULL);
  #endif
  tolua_beginmodule(tolua_S,"UIButtonBase");
   tolua_function(tolua_S,"delete",tolua_PX2_UIButtonBase_delete00);
   tolua_constant(tolua_S,"BS_NORMAL",UIButtonBase::BS_NORMAL);
   tolua_constant(tolua_S,"BS_OVER",UIButtonBase::BS_OVER);
   tolua_constant(tolua_S,"BS_DOWN",UIButtonBase::BS_DOWN);
   tolua_constant(tolua_S,"BS_DISABLED",UIButtonBase::BS_DISABLED);
   tolua_constant(tolua_S,"BS_MAX_STATE",UIButtonBase::BS_MAX_STATE);
   tolua_function(tolua_S,"SetButtonState",tolua_PX2_UIButtonBase_SetButtonState00);
   tolua_function(tolua_S,"GetButtonState",tolua_PX2_UIButtonBase_GetButtonState00);
   tolua_function(tolua_S,"SetPicBox",tolua_PX2_UIButtonBase_SetPicBox00);
   tolua_function(tolua_S,"GetPicBoxAtState",tolua_PX2_UIButtonBase_GetPicBoxAtState00);
   tolua_function(tolua_S,"SetSize",tolua_PX2_UIButtonBase_SetSize00);
   tolua_function(tolua_S,"SetSize",tolua_PX2_UIButtonBase_SetSize01);
   tolua_function(tolua_S,"GetSize",tolua_PX2_UIButtonBase_GetSize00);
   tolua_function(tolua_S,"SetWidth",tolua_PX2_UIButtonBase_SetWidth00);
   tolua_function(tolua_S,"GetWidth",tolua_PX2_UIButtonBase_GetWidth00);
   tolua_function(tolua_S,"SetHeight",tolua_PX2_UIButtonBase_SetHeight00);
   tolua_function(tolua_S,"GetHeight",tolua_PX2_UIButtonBase_GetHeight00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"UIButton","UIButton","UIButtonBase",tolua_collect_UIButton);
  #else
  tolua_cclass(tolua_S,"UIButton","UIButton","UIButtonBase",NULL);
  #endif
  tolua_beginmodule(tolua_S,"UIButton");
   tolua_function(tolua_S,"new",tolua_PX2_UIButton_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_UIButton_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_UIButton_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_UIButton_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"UICheckButton","UICheckButton","UIButtonBase",tolua_collect_UICheckButton);
  #else
  tolua_cclass(tolua_S,"UICheckButton","UICheckButton","UIButtonBase",NULL);
  #endif
  tolua_beginmodule(tolua_S,"UICheckButton");
   tolua_function(tolua_S,"new",tolua_PX2_UICheckButton_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_UICheckButton_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_UICheckButton_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_UICheckButton_delete00);
   tolua_function(tolua_S,"Enable",tolua_PX2_UICheckButton_Enable00);
   tolua_function(tolua_S,"OnEvent",tolua_PX2_UICheckButton_OnEvent00);
   tolua_function(tolua_S,"OnCheck",tolua_PX2_UICheckButton_OnCheck00);
   tolua_function(tolua_S,"OnDisCheck",tolua_PX2_UICheckButton_OnDisCheck00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"UIProgressBar","UIProgressBar","UIFrame",tolua_collect_UIProgressBar);
  #else
  tolua_cclass(tolua_S,"UIProgressBar","UIProgressBar","UIFrame",NULL);
  #endif
  tolua_beginmodule(tolua_S,"UIProgressBar");
   tolua_function(tolua_S,"new",tolua_PX2_UIProgressBar_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_UIProgressBar_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_UIProgressBar_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_UIProgressBar_delete00);
   tolua_function(tolua_S,"SetBackPicBox",tolua_PX2_UIProgressBar_SetBackPicBox00);
   tolua_function(tolua_S,"SetProgressPicBox",tolua_PX2_UIProgressBar_SetProgressPicBox00);
   tolua_function(tolua_S,"SetOverPicBox",tolua_PX2_UIProgressBar_SetOverPicBox00);
   tolua_function(tolua_S,"GetBackPicBox",tolua_PX2_UIProgressBar_GetBackPicBox00);
   tolua_function(tolua_S,"GetProgressPicBox",tolua_PX2_UIProgressBar_GetProgressPicBox00);
   tolua_function(tolua_S,"GetOverPicBox",tolua_PX2_UIProgressBar_GetOverPicBox00);
   tolua_function(tolua_S,"SetSize",tolua_PX2_UIProgressBar_SetSize00);
   tolua_function(tolua_S,"SetSize",tolua_PX2_UIProgressBar_SetSize01);
   tolua_function(tolua_S,"GetWidth",tolua_PX2_UIProgressBar_GetWidth00);
   tolua_function(tolua_S,"GetHeight",tolua_PX2_UIProgressBar_GetHeight00);
   tolua_function(tolua_S,"GetSize",tolua_PX2_UIProgressBar_GetSize00);
   tolua_function(tolua_S,"SetProgress",tolua_PX2_UIProgressBar_SetProgress00);
   tolua_function(tolua_S,"GetProgress",tolua_PX2_UIProgressBar_GetProgress00);
   tolua_function(tolua_S,"SetProgressAnimInit",tolua_PX2_UIProgressBar_SetProgressAnimInit00);
   tolua_function(tolua_S,"SetProgressAnim",tolua_PX2_UIProgressBar_SetProgressAnim00);
   tolua_function(tolua_S,"SetProgressAnimSpeed",tolua_PX2_UIProgressBar_SetProgressAnimSpeed00);
   tolua_function(tolua_S,"GetProgressAnimSpeed",tolua_PX2_UIProgressBar_GetProgressAnimSpeed00);
   tolua_function(tolua_S,"GetProgressBarCtrl",tolua_PX2_UIProgressBar_GetProgressBarCtrl00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"UIRangeFrame","UIRangeFrame","UIFrame",tolua_collect_UIRangeFrame);
  #else
  tolua_cclass(tolua_S,"UIRangeFrame","UIRangeFrame","UIFrame",NULL);
  #endif
  tolua_beginmodule(tolua_S,"UIRangeFrame");
   tolua_function(tolua_S,"new",tolua_PX2_UIRangeFrame_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_UIRangeFrame_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_UIRangeFrame_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_UIRangeFrame_delete00);
   tolua_function(tolua_S,"SetSize",tolua_PX2_UIRangeFrame_SetSize00);
   tolua_function(tolua_S,"SetSize",tolua_PX2_UIRangeFrame_SetSize01);
   tolua_function(tolua_S,"GetWidth",tolua_PX2_UIRangeFrame_GetWidth00);
   tolua_function(tolua_S,"GetHeight",tolua_PX2_UIRangeFrame_GetHeight00);
   tolua_function(tolua_S,"GetSize",tolua_PX2_UIRangeFrame_GetSize00);
   tolua_function(tolua_S,"AttachChild",tolua_PX2_UIRangeFrame_AttachChild00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"UIManager","UIManager","Singleton<UIManager>",NULL);
  tolua_beginmodule(tolua_S,"UIManager");
   tolua_function(tolua_S,"GetDefaultView",tolua_PX2_UIManager_GetDefaultView00);
   tolua_function(tolua_S,"AddUIView",tolua_PX2_UIManager_AddUIView00);
   tolua_function(tolua_S,"GetUIViews",tolua_PX2_UIManager_GetUIViews00);
   tolua_function(tolua_S,"GetUIView",tolua_PX2_UIManager_GetUIView00);
   tolua_function(tolua_S,"CreateUIPicBox",tolua_PX2_UIManager_CreateUIPicBox00);
   tolua_function(tolua_S,"CreateUIPicBox",tolua_PX2_UIManager_CreateUIPicBox01);
   tolua_function(tolua_S,"CreateUIStaticText",tolua_PX2_UIManager_CreateUIStaticText00);
   tolua_function(tolua_S,"CreateUIFrame",tolua_PX2_UIManager_CreateUIFrame00);
   tolua_function(tolua_S,"CreateUIButton",tolua_PX2_UIManager_CreateUIButton00);
   tolua_variable(tolua_S,"__EventHandler__",tolua_get_UIManager___EventHandler__,NULL);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"UIView","UIView","",tolua_collect_UIView);
  #else
  tolua_cclass(tolua_S,"UIView","UIView","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"UIView");
   tolua_function(tolua_S,"new",tolua_PX2_UIView_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_UIView_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_UIView_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_UIView_delete00);
   tolua_function(tolua_S,"GetID",tolua_PX2_UIView_GetID00);
   tolua_function(tolua_S,"SetSize",tolua_PX2_UIView_SetSize00);
   tolua_function(tolua_S,"SetSize",tolua_PX2_UIView_SetSize01);
   tolua_function(tolua_S,"GetSize",tolua_PX2_UIView_GetSize00);
   tolua_function(tolua_S,"SetWidth",tolua_PX2_UIView_SetWidth00);
   tolua_function(tolua_S,"GetWidth",tolua_PX2_UIView_GetWidth00);
   tolua_function(tolua_S,"SetHeight",tolua_PX2_UIView_SetHeight00);
   tolua_function(tolua_S,"GetHeight",tolua_PX2_UIView_GetHeight00);
   tolua_function(tolua_S,"SetRenderer",tolua_PX2_UIView_SetRenderer00);
   tolua_function(tolua_S,"GetRenderer",tolua_PX2_UIView_GetRenderer00);
   tolua_function(tolua_S,"SetMainFrame",tolua_PX2_UIView_SetMainFrame00);
   tolua_function(tolua_S,"GetMainFrame",tolua_PX2_UIView_GetMainFrame00);
   tolua_function(tolua_S,"GetCamera",tolua_PX2_UIView_GetCamera00);
   tolua_function(tolua_S,"GetCuller",tolua_PX2_UIView_GetCuller00);
   tolua_function(tolua_S,"GetPickedPicBoxs",tolua_PX2_UIView_GetPickedPicBoxs00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_PX2 (lua_State* tolua_S) {
 return tolua_PX2_open(tolua_S);
};
#endif

