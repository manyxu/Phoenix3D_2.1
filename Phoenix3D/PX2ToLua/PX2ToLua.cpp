/*
** Lua binding: PX2
** Generated automatically by tolua++-1.0.92 on 03/10/15 10:45:47.
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

static int tolua_collect_Effectable (lua_State* tolua_S)
{
 Effectable* self = (Effectable*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Transform (lua_State* tolua_S)
{
 Transform* self = (Transform*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_ParticleEmitter (lua_State* tolua_S)
{
 ParticleEmitter* self = (ParticleEmitter*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CameraActor (lua_State* tolua_S)
{
 CameraActor* self = (CameraActor*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_EffectModel (lua_State* tolua_S)
{
 EffectModel* self = (EffectModel*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CameraShake (lua_State* tolua_S)
{
 CameraShake* self = (CameraShake*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Creater (lua_State* tolua_S)
{
 Creater* self = (Creater*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Controlledable (lua_State* tolua_S)
{
 Controlledable* self = (Controlledable*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Billboard (lua_State* tolua_S)
{
 Billboard* self = (Billboard*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Rtti (lua_State* tolua_S)
{
 Rtti* self = (Rtti*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_RibbonEmitter (lua_State* tolua_S)
{
 RibbonEmitter* self = (RibbonEmitter*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_APoint (lua_State* tolua_S)
{
 APoint* self = (APoint*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_EffectModelNode (lua_State* tolua_S)
{
 EffectModelNode* self = (EffectModelNode*) tolua_tousertype(tolua_S,1,0);
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

static int tolua_collect_Actor (lua_State* tolua_S)
{
 Actor* self = (Actor*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Scene (lua_State* tolua_S)
{
 Scene* self = (Scene*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CameraShakeChannel (lua_State* tolua_S)
{
 CameraShakeChannel* self = (CameraShakeChannel*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Soundable (lua_State* tolua_S)
{
 Soundable* self = (Soundable*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_BeamEmitter (lua_State* tolua_S)
{
 BeamEmitter* self = (BeamEmitter*) tolua_tousertype(tolua_S,1,0);
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

static int tolua_collect_Movable (lua_State* tolua_S)
{
 Movable* self = (Movable*) tolua_tousertype(tolua_S,1,0);
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
 tolua_usertype(tolua_S,"TexPackElement");
 tolua_usertype(tolua_S,"Controlledable");
 tolua_usertype(tolua_S,"Stream");
 tolua_usertype(tolua_S,"ResHandle");
 tolua_usertype(tolua_S,"UIFrame");
 tolua_usertype(tolua_S,"EffectModel");
 tolua_usertype(tolua_S,"Node");
 tolua_usertype(tolua_S,"int64_t");
 tolua_usertype(tolua_S,"TriMesh");
 tolua_usertype(tolua_S,"Float4");
 tolua_usertype(tolua_S,"LanguageManager");
 tolua_usertype(tolua_S,"Soundable");
 tolua_usertype(tolua_S,"std::vector<std::string>");
 tolua_usertype(tolua_S,"ScriptManager");
 tolua_usertype(tolua_S,"Texture2D");
 tolua_usertype(tolua_S,"Float2");
 tolua_usertype(tolua_S,"Effectable");
 tolua_usertype(tolua_S,"Transform");
 tolua_usertype(tolua_S,"Vector3f");
 tolua_usertype(tolua_S,"PX2::APoint");
 tolua_usertype(tolua_S,"UICheckButton");
 tolua_usertype(tolua_S,"Rtti");
 tolua_usertype(tolua_S,"Project");
 tolua_usertype(tolua_S,"IndexBuffer");
 tolua_usertype(tolua_S,"EffectActor");
 tolua_usertype(tolua_S,"SwitchNode");
 tolua_usertype(tolua_S,"Actor");
 tolua_usertype(tolua_S,"VertexBuffer");
 tolua_usertype(tolua_S,"Event");
 tolua_usertype(tolua_S,"DepthProperty");
 tolua_usertype(tolua_S,"UIText");
 tolua_usertype(tolua_S,"Renderable");
 tolua_usertype(tolua_S,"Texture::Format");
 tolua_usertype(tolua_S,"Sizef");
 tolua_usertype(tolua_S,"UIProgressBar");
 tolua_usertype(tolua_S,"Texture3D");
 tolua_usertype(tolua_S,"RenderTarget");
 tolua_usertype(tolua_S,"Selection");
 tolua_usertype(tolua_S,"ResourceManager");
 tolua_usertype(tolua_S,"PixelShader");
 tolua_usertype(tolua_S,"Creater");
 tolua_usertype(tolua_S,"Logger");
 tolua_usertype(tolua_S,"CameraActor");
 tolua_usertype(tolua_S,"Scene");
 tolua_usertype(tolua_S,"UIPicBox");
 tolua_usertype(tolua_S,"Controller");
 tolua_usertype(tolua_S,"HMatrix");
 tolua_usertype(tolua_S,"UIEditBox");
 tolua_usertype(tolua_S,"HPoint");
 tolua_usertype(tolua_S,"UIButton");
 tolua_usertype(tolua_S,"Camera");
 tolua_usertype(tolua_S,"Object");
 tolua_usertype(tolua_S,"TexPack");
 tolua_usertype(tolua_S,"Billboard");
 tolua_usertype(tolua_S,"PX2::AVector");
 tolua_usertype(tolua_S,"Vector2f");
 tolua_usertype(tolua_S,"RenderStep");
 tolua_usertype(tolua_S,"EffectableController");
 tolua_usertype(tolua_S,"RibbonEmitter");
 tolua_usertype(tolua_S,"TextureCube");
 tolua_usertype(tolua_S,"ParticleEmitter");
 tolua_usertype(tolua_S,"VisibleSet");
 tolua_usertype(tolua_S,"EffectModelNode");
 tolua_usertype(tolua_S,"CameraShakeChannel");
 tolua_usertype(tolua_S,"VertexShader");
 tolua_usertype(tolua_S,"CameraShake");
 tolua_usertype(tolua_S,"Character");
 tolua_usertype(tolua_S,"AlphaProperty");
 tolua_usertype(tolua_S,"VertexFormat");
 tolua_usertype(tolua_S,"BeamEmitter");
 tolua_usertype(tolua_S,"Renderer");
 tolua_usertype(tolua_S,"APoint");
 tolua_usertype(tolua_S,"GlobalMaterial");
 tolua_usertype(tolua_S,"AVector");
 tolua_usertype(tolua_S,"std::vector<Object*>");
 tolua_usertype(tolua_S,"Triangles");
 tolua_usertype(tolua_S,"MaterialInstance");
 tolua_usertype(tolua_S,"WireProperty");
 tolua_usertype(tolua_S,"std::bitset<PX2_ACTOR_BS_SIZE>");
 tolua_usertype(tolua_S,"PX2::Object");
 tolua_usertype(tolua_S,"StencilProperty");
 tolua_usertype(tolua_S,"Float3");
 tolua_usertype(tolua_S,"Light");
 tolua_usertype(tolua_S,"CullProperty");
 tolua_usertype(tolua_S,"Movable");
 tolua_usertype(tolua_S,"Texture1D");
 tolua_usertype(tolua_S,"Bound");
 tolua_usertype(tolua_S,"ObjectEventHandler");
 tolua_usertype(tolua_S,"Buffer::Locking");
}

/* method: new of class  Rtti */
#ifndef TOLUA_DISABLE_tolua_PX2_Rtti_new00
static int tolua_PX2_Rtti_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Rtti",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"const Rtti",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  unsigned short version = ((unsigned short)  tolua_tonumber(tolua_S,3,0));
  const Rtti* baseType = ((const Rtti*)  tolua_tousertype(tolua_S,4,0));
  {
   Rtti* tolua_ret = (Rtti*)  Mtolua_new((Rtti)(name,version,baseType));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rtti");
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

/* method: new_local of class  Rtti */
#ifndef TOLUA_DISABLE_tolua_PX2_Rtti_new00_local
static int tolua_PX2_Rtti_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Rtti",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"const Rtti",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  unsigned short version = ((unsigned short)  tolua_tonumber(tolua_S,3,0));
  const Rtti* baseType = ((const Rtti*)  tolua_tousertype(tolua_S,4,0));
  {
   Rtti* tolua_ret = (Rtti*)  Mtolua_new((Rtti)(name,version,baseType));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rtti");
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

/* method: delete of class  Rtti */
#ifndef TOLUA_DISABLE_tolua_PX2_Rtti_delete00
static int tolua_PX2_Rtti_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Rtti",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Rtti* self = (Rtti*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetName of class  Rtti */
#ifndef TOLUA_DISABLE_tolua_PX2_Rtti_GetName00
static int tolua_PX2_Rtti_GetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Rtti",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Rtti* self = (const Rtti*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetName'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->GetName();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
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

/* method: GetVersion of class  Rtti */
#ifndef TOLUA_DISABLE_tolua_PX2_Rtti_GetVersion00
static int tolua_PX2_Rtti_GetVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Rtti",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Rtti* self = (const Rtti*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVersion'", NULL);
#endif
  {
   unsigned short tolua_ret = (unsigned short)  self->GetVersion();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsExactly of class  Rtti */
#ifndef TOLUA_DISABLE_tolua_PX2_Rtti_IsExactly00
static int tolua_PX2_Rtti_IsExactly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Rtti",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rtti",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Rtti* self = (const Rtti*)  tolua_tousertype(tolua_S,1,0);
  const Rtti* type = ((const Rtti*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsExactly'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsExactly(*type);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsExactly'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsDerived of class  Rtti */
#ifndef TOLUA_DISABLE_tolua_PX2_Rtti_IsDerived00
static int tolua_PX2_Rtti_IsDerived00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Rtti",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rtti",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Rtti* self = (const Rtti*)  tolua_tousertype(tolua_S,1,0);
  const Rtti* type = ((const Rtti*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsDerived'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsDerived(*type);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsDerived'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Enable of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_Enable00
static int tolua_PX2_Object_Enable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
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

/* method: IsEnable of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_IsEnable00
static int tolua_PX2_Object_IsEnable00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsEnable'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsEnable();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsEnable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRttiType of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_GetRttiType00
static int tolua_PX2_Object_GetRttiType00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRttiType'", NULL);
#endif
  {
   const Rtti& tolua_ret = (const Rtti&)  self->GetRttiType();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Rtti");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRttiType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRttiVersion of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_GetRttiVersion00
static int tolua_PX2_Object_GetRttiVersion00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRttiVersion'", NULL);
#endif
  {
   unsigned short tolua_ret = (unsigned short)  self->GetRttiVersion();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRttiVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsExactly of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_IsExactly00
static int tolua_PX2_Object_IsExactly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Object",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rtti",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Object* self = (const Object*)  tolua_tousertype(tolua_S,1,0);
  const Rtti* type = ((const Rtti*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsExactly'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsExactly(*type);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsExactly'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsDerived of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_IsDerived00
static int tolua_PX2_Object_IsDerived00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Object",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Rtti",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Object* self = (const Object*)  tolua_tousertype(tolua_S,1,0);
  const Rtti* type = ((const Rtti*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsDerived'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsDerived(*type);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsDerived'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsExactlyTypeOf of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_IsExactlyTypeOf00
static int tolua_PX2_Object_IsExactlyTypeOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Object",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Object* self = (const Object*)  tolua_tousertype(tolua_S,1,0);
  const Object* object = ((const Object*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsExactlyTypeOf'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsExactlyTypeOf(object);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsExactlyTypeOf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsDerivedTypeOf of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_IsDerivedTypeOf00
static int tolua_PX2_Object_IsDerivedTypeOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Object",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Object* self = (const Object*)  tolua_tousertype(tolua_S,1,0);
  const Object* object = ((const Object*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsDerivedTypeOf'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsDerivedTypeOf(object);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsDerivedTypeOf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: TYPE of class  Object */
#ifndef TOLUA_DISABLE_tolua_get_Object_TYPE
static int tolua_get_Object_TYPE(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Object::TYPE,"const Rtti");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUserDataFloat of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_SetUserDataFloat00
static int tolua_PX2_Object_SetUserDataFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  float val = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUserDataFloat'", NULL);
#endif
  {
   self->SetUserDataFloat(name,val);
   tolua_pushcppstring(tolua_S,(const char*)name);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUserDataFloat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUserDataFloat of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_GetUserDataFloat00
static int tolua_PX2_Object_GetUserDataFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Object",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Object* self = (const Object*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  bool isValied = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUserDataFloat'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetUserDataFloat(name,&isValied);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)name);
   tolua_pushboolean(tolua_S,(bool)isValied);
  }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUserDataFloat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetResourcePath of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_SetResourcePath00
static int tolua_PX2_Object_SetResourcePath00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetResourcePath'", NULL);
#endif
  {
   self->SetResourcePath(name);
   tolua_pushcppstring(tolua_S,(const char*)name);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetResourcePath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

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

/* get function: mCurStream of class  Object */
#ifndef TOLUA_DISABLE_tolua_get_Object_mCurStream_ptr
static int tolua_get_Object_mCurStream_ptr(lua_State* tolua_S)
{
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mCurStream'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->mCurStream,"Stream");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mCurStream of class  Object */
#ifndef TOLUA_DISABLE_tolua_set_Object_mCurStream_ptr
static int tolua_set_Object_mCurStream_ptr(lua_State* tolua_S)
{
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mCurStream'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Stream",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mCurStream = ((Stream*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
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

/* method: GetAllObjectsByName of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_GetAllObjectsByName00
static int tolua_PX2_Object_GetAllObjectsByName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"std::vector<Object*>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  std::vector<Object*>* objects = ((std::vector<Object*>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllObjectsByName'", NULL);
#endif
  {
   self->GetAllObjectsByName(name,*objects);
   tolua_pushcppstring(tolua_S,(const char*)name);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllObjectsByName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetID of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_SetID00
static int tolua_PX2_Object_SetID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
  int id = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetID'", NULL);
#endif
  {
   self->SetID(id);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetID of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_GetID00
static int tolua_PX2_Object_GetID00(lua_State* tolua_S)
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

/* method: GetObjectByID of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_GetObjectByID00
static int tolua_PX2_Object_GetObjectByID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
  int id = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObjectByID'", NULL);
#endif
  {
   Object* tolua_ret = (Object*)  self->GetObjectByID(id);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Object");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetObjectByID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAllObjectsByID of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_GetAllObjectsByID00
static int tolua_PX2_Object_GetAllObjectsByID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"std::vector<Object*>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
  int id = ((int)  tolua_tonumber(tolua_S,2,0));
  std::vector<Object*>* objects = ((std::vector<Object*>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllObjectsByID'", NULL);
#endif
  {
   self->GetAllObjectsByID(id,*objects);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllObjectsByID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ComeInEventWorld of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_ComeInEventWorld00
static int tolua_PX2_Object_ComeInEventWorld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ComeInEventWorld'", NULL);
#endif
  {
   self->ComeInEventWorld();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ComeInEventWorld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GoOutEventWorld of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_GoOutEventWorld00
static int tolua_PX2_Object_GoOutEventWorld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GoOutEventWorld'", NULL);
#endif
  {
   self->GoOutEventWorld();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GoOutEventWorld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsInEventWorld of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_IsInEventWorld00
static int tolua_PX2_Object_IsInEventWorld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsInEventWorld'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsInEventWorld();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsInEventWorld'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEventHandler of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_GetEventHandler00
static int tolua_PX2_Object_GetEventHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEventHandler'", NULL);
#endif
  {
   ObjectEventHandler* tolua_ret = (ObjectEventHandler*)  self->GetEventHandler();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ObjectEventHandler");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEventHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DoExecute of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_DoExecute00
static int tolua_PX2_Object_DoExecute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Event",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
  Event* event = ((Event*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DoExecute'", NULL);
#endif
  {
   self->DoExecute(event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DoExecute'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUserScriptName of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_SetUserScriptName00
static int tolua_PX2_Object_SetUserScriptName00(lua_State* tolua_S)
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
  const std::string scriptName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUserScriptName'", NULL);
#endif
  {
   self->SetUserScriptName(scriptName);
   tolua_pushcppstring(tolua_S,(const char*)scriptName);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUserScriptName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUserScriptName of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_GetUserScriptName00
static int tolua_PX2_Object_GetUserScriptName00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUserScriptName'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetUserScriptName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUserScriptName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScriptName of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_GetScriptName00
static int tolua_PX2_Object_GetScriptName00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScriptName'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetScriptName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScriptName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RegistToScriptSystem of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_RegistToScriptSystem00
static int tolua_PX2_Object_RegistToScriptSystem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RegistToScriptSystem'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->RegistToScriptSystem();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RegistToScriptSystem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UnRegistToScriptSystem of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_UnRegistToScriptSystem00
static int tolua_PX2_Object_UnRegistToScriptSystem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UnRegistToScriptSystem'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->UnRegistToScriptSystem();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UnRegistToScriptSystem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsRegistedToScriptSystem of class  Object */
#ifndef TOLUA_DISABLE_tolua_PX2_Object_IsRegistedToScriptSystem00
static int tolua_PX2_Object_IsRegistedToScriptSystem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsRegistedToScriptSystem'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsRegistedToScriptSystem();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsRegistedToScriptSystem'.",&tolua_err);
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

/* method: Add of class  LanguageManager */
#ifndef TOLUA_DISABLE_tolua_PX2_LanguageManager_Add00
static int tolua_PX2_LanguageManager_Add00(lua_State* tolua_S)
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Add(filename);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddItem of class  LanguageManager */
#ifndef TOLUA_DISABLE_tolua_PX2_LanguageManager_AddItem00
static int tolua_PX2_LanguageManager_AddItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LanguageManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LanguageManager* self = (LanguageManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string langauge0 = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const std::string langauge1 = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddItem'", NULL);
#endif
  {
   self->AddItem(key,langauge0,langauge1);
   tolua_pushcppstring(tolua_S,(const char*)key);
   tolua_pushcppstring(tolua_S,(const char*)langauge0);
   tolua_pushcppstring(tolua_S,(const char*)langauge1);
  }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddItem1 of class  LanguageManager */
#ifndef TOLUA_DISABLE_tolua_PX2_LanguageManager_AddItem100
static int tolua_PX2_LanguageManager_AddItem100(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LanguageManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LanguageManager* self = (LanguageManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string langauge0 = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddItem1'", NULL);
#endif
  {
   self->AddItem1(key,langauge0);
   tolua_pushcppstring(tolua_S,(const char*)key);
   tolua_pushcppstring(tolua_S,(const char*)langauge0);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddItem1'.",&tolua_err);
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

/* method: HasValue of class  LanguageManager */
#ifndef TOLUA_DISABLE_tolua_PX2_LanguageManager_HasValue00
static int tolua_PX2_LanguageManager_HasValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const LanguageManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const LanguageManager* self = (const LanguageManager*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'HasValue'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->HasValue(key);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'HasValue'.",&tolua_err);
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
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetValue'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetValue(key);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  LanguageManager */
#ifndef TOLUA_DISABLE_tolua_PX2_LanguageManager_Clear00
static int tolua_PX2_LanguageManager_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LanguageManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LanguageManager* self = (LanguageManager*)  tolua_tousertype(tolua_S,1,0);
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

/* method: delete of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_delete00
static int tolua_PX2_Effectable_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Update of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_Update00
static int tolua_PX2_Effectable_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  double applicationTime = ((double)  tolua_tonumber(tolua_S,2,0));
  bool initiator = ((bool)  tolua_toboolean(tolua_S,3,0));
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

/* method: GetEffectableController of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetEffectableController00
static int tolua_PX2_Effectable_GetEffectableController00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEffectableController'", NULL);
#endif
  {
   EffectableController* tolua_ret = (EffectableController*)  self->GetEffectableController();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EffectableController");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEffectableController'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFixedBound of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetFixedBound00
static int tolua_PX2_Effectable_SetFixedBound00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  bool fixed = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFixedBound'", NULL);
#endif
  {
   self->SetFixedBound(fixed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFixedBound'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsFixedBound of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_IsFixedBound00
static int tolua_PX2_Effectable_IsFixedBound00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsFixedBound'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsFixedBound();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsFixedBound'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFixedBoundCenter of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetFixedBoundCenter00
static int tolua_PX2_Effectable_SetFixedBoundCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  const APoint* center = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFixedBoundCenter'", NULL);
#endif
  {
   self->SetFixedBoundCenter(*center);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFixedBoundCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFixedBoundCenter of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetFixedBoundCenter00
static int tolua_PX2_Effectable_GetFixedBoundCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFixedBoundCenter'", NULL);
#endif
  {
   APoint tolua_ret = (APoint)  self->GetFixedBoundCenter();
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
 tolua_error(tolua_S,"#ferror in function 'GetFixedBoundCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFixedBoundRadius of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetFixedBoundRadius00
static int tolua_PX2_Effectable_SetFixedBoundRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  float radius = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFixedBoundRadius'", NULL);
#endif
  {
   self->SetFixedBoundRadius(radius);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFixedBoundRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFixedBoundRadius of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetFixedBoundRadius00
static int tolua_PX2_Effectable_GetFixedBoundRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFixedBoundRadius'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetFixedBoundRadius();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFixedBoundRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLocal of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetLocal00
static int tolua_PX2_Effectable_SetLocal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  bool l = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLocal'", NULL);
#endif
  {
   self->SetLocal(l);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLocal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsLocal of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_IsLocal00
static int tolua_PX2_Effectable_IsLocal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsLocal'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsLocal();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsLocal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitSizeX of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetEmitSizeX00
static int tolua_PX2_Effectable_SetEmitSizeX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  float val = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitSizeX'", NULL);
#endif
  {
   self->SetEmitSizeX(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitSizeX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitSizeX of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetEmitSizeX00
static int tolua_PX2_Effectable_GetEmitSizeX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitSizeX'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetEmitSizeX();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitSizeX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitSizeY of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetEmitSizeY00
static int tolua_PX2_Effectable_SetEmitSizeY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  float val = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitSizeY'", NULL);
#endif
  {
   self->SetEmitSizeY(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitSizeY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitSizeY of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetEmitSizeY00
static int tolua_PX2_Effectable_GetEmitSizeY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitSizeY'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetEmitSizeY();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitSizeY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitSizeZ of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetEmitSizeZ00
static int tolua_PX2_Effectable_SetEmitSizeZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  float val = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitSizeZ'", NULL);
#endif
  {
   self->SetEmitSizeZ(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitSizeZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitSizeZ of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetEmitSizeZ00
static int tolua_PX2_Effectable_GetEmitSizeZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitSizeZ'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetEmitSizeZ();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitSizeZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitSizeXYZ of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetEmitSizeXYZ00
static int tolua_PX2_Effectable_SetEmitSizeXYZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  float val = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitSizeXYZ'", NULL);
#endif
  {
   self->SetEmitSizeXYZ(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitSizeXYZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitColor of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetEmitColor00
static int tolua_PX2_Effectable_SetEmitColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Float3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  const Float3* color = ((const Float3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitColor'", NULL);
#endif
  {
   self->SetEmitColor(*color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitColor of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetEmitColor00
static int tolua_PX2_Effectable_GetEmitColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitColor'", NULL);
#endif
  {
   const Float3& tolua_ret = (const Float3&)  self->GetEmitColor();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Float3");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitAlpha of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetEmitAlpha00
static int tolua_PX2_Effectable_SetEmitAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  float alpha = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitAlpha'", NULL);
#endif
  {
   self->SetEmitAlpha(alpha);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitAlpha of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetEmitAlpha00
static int tolua_PX2_Effectable_GetEmitAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitAlpha'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetEmitAlpha();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitAlpha'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitLife of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetEmitLife00
static int tolua_PX2_Effectable_SetEmitLife00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  float life = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitLife'", NULL);
#endif
  {
   self->SetEmitLife(life);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitLife'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitLife of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetEmitLife00
static int tolua_PX2_Effectable_GetEmitLife00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitLife'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetEmitLife();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitLife'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFaceType of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetFaceType00
static int tolua_PX2_Effectable_SetFaceType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  Effectable::FaceType type = ((Effectable::FaceType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFaceType'", NULL);
#endif
  {
   self->SetFaceType(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFaceType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFaceType of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetFaceType00
static int tolua_PX2_Effectable_GetFaceType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFaceType'", NULL);
#endif
  {
   Effectable::FaceType tolua_ret = (Effectable::FaceType)  self->GetFaceType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFaceType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaterialType of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetMaterialType00
static int tolua_PX2_Effectable_SetMaterialType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  Effectable::MaterialType type = ((Effectable::MaterialType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaterialType'", NULL);
#endif
  {
   self->SetMaterialType(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaterialType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaterialType of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetMaterialType00
static int tolua_PX2_Effectable_GetMaterialType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaterialType'", NULL);
#endif
  {
   Effectable::MaterialType tolua_ret = (Effectable::MaterialType)  self->GetMaterialType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaterialType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBackCull of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetBackCull00
static int tolua_PX2_Effectable_SetBackCull00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  bool isBackCull = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBackCull'", NULL);
#endif
  {
   self->SetBackCull(isBackCull);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBackCull'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsBackCull of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_IsBackCull00
static int tolua_PX2_Effectable_IsBackCull00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsBackCull'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsBackCull();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsBackCull'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBlendMode of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetBlendMode00
static int tolua_PX2_Effectable_SetBlendMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  Effectable::BlendMode mode = ((Effectable::BlendMode) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBlendMode'", NULL);
#endif
  {
   self->SetBlendMode(mode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBlendMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBlendMode of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetBlendMode00
static int tolua_PX2_Effectable_GetBlendMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBlendMode'", NULL);
#endif
  {
   Effectable::BlendMode tolua_ret = (Effectable::BlendMode)  self->GetBlendMode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBlendMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTexMode of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetTexMode00
static int tolua_PX2_Effectable_SetTexMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  Effectable::TexMode mode = ((Effectable::TexMode) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTexMode'", NULL);
#endif
  {
   self->SetTexMode(mode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTexMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTexMode of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetTexMode00
static int tolua_PX2_Effectable_GetTexMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTexMode'", NULL);
#endif
  {
   Effectable::TexMode tolua_ret = (Effectable::TexMode)  self->GetTexMode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTexMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTex of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetTex00
static int tolua_PX2_Effectable_SetTex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTex'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SetTex(filename);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)filename);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTex of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetTex00
static int tolua_PX2_Effectable_GetTex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTex'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetTex();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTexPack_Ele of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetTexPack_Ele00
static int tolua_PX2_Effectable_SetTexPack_Ele00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  const std::string packFileName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string eleName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTexPack_Ele'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SetTexPack_Ele(packFileName,eleName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)packFileName);
   tolua_pushcppstring(tolua_S,(const char*)eleName);
  }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTexPack_Ele'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTexPack_Ele of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetTexPack_Ele00
static int tolua_PX2_Effectable_GetTexPack_Ele00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
  std::string packFileName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string eleName = ((std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTexPack_Ele'", NULL);
#endif
  {
   self->GetTexPack_Ele(packFileName,eleName);
   tolua_pushcppstring(tolua_S,(const char*)packFileName);
   tolua_pushcppstring(tolua_S,(const char*)eleName);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTexPack_Ele'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTexAnim of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetTexAnim00
static int tolua_PX2_Effectable_SetTexAnim00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTexAnim'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SetTexAnim(filename);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)filename);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTexAnim'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTexAnim of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetTexAnim00
static int tolua_PX2_Effectable_GetTexAnim00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTexAnim'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetTexAnim();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTexAnim'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTexAnim_Repeat of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetTexAnim_Repeat00
static int tolua_PX2_Effectable_SetTexAnim_Repeat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Float2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  const Float2* repeat = ((const Float2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTexAnim_Repeat'", NULL);
#endif
  {
   self->SetTexAnim_Repeat(*repeat);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTexAnim_Repeat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTexAnim_Repeat of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetTexAnim_Repeat00
static int tolua_PX2_Effectable_GetTexAnim_Repeat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTexAnim_Repeat'", NULL);
#endif
  {
   const Float2& tolua_ret = (const Float2&)  self->GetTexAnim_Repeat();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Float2");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTexAnim_Repeat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddTexsAnim_Frame of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_AddTexsAnim_Frame00
static int tolua_PX2_Effectable_AddTexsAnim_Frame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddTexsAnim_Frame'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->AddTexsAnim_Frame(filename);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)filename);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddTexsAnim_Frame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTexPackAnim of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetTexPackAnim00
static int tolua_PX2_Effectable_SetTexPackAnim00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  const std::string texPackFilename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTexPackAnim'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SetTexPackAnim(texPackFilename);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)texPackFilename);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTexPackAnim'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTexPackAnim of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetTexPackAnim00
static int tolua_PX2_Effectable_GetTexPackAnim00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTexPackAnim'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetTexPackAnim();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTexPackAnim'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddTexPackAnim_Frame of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_AddTexPackAnim_Frame00
static int tolua_PX2_Effectable_AddTexPackAnim_Frame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  const std::string texPackFilename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  const std::string eleName = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddTexPackAnim_Frame'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->AddTexPackAnim_Frame(texPackFilename,eleName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)texPackFilename);
   tolua_pushcppstring(tolua_S,(const char*)eleName);
  }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddTexPackAnim_Frame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumTexAnimTexPackAnimFrames of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetNumTexAnimTexPackAnimFrames00
static int tolua_PX2_Effectable_GetNumTexAnimTexPackAnimFrames00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumTexAnimTexPackAnimFrames'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetNumTexAnimTexPackAnimFrames();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumTexAnimTexPackAnimFrames'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ClearTexAnimTexPackAnimFrames of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_ClearTexAnimTexPackAnimFrames00
static int tolua_PX2_Effectable_ClearTexAnimTexPackAnimFrames00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearTexAnimTexPackAnimFrames'", NULL);
#endif
  {
   self->ClearTexAnimTexPackAnimFrames();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearTexAnimTexPackAnimFrames'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAnimInterval of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetAnimInterval00
static int tolua_PX2_Effectable_SetAnimInterval00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  float seconds = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAnimInterval'", NULL);
#endif
  {
   self->SetAnimInterval(seconds);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAnimInterval'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAnimInterval of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetAnimInterval00
static int tolua_PX2_Effectable_GetAnimInterval00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAnimInterval'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetAnimInterval();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAnimInterval'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAnimStartDoRandom of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetAnimStartDoRandom00
static int tolua_PX2_Effectable_SetAnimStartDoRandom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  bool doRandom = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAnimStartDoRandom'", NULL);
#endif
  {
   self->SetAnimStartDoRandom(doRandom);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAnimStartDoRandom'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsAnimStartDoRandom of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_IsAnimStartDoRandom00
static int tolua_PX2_Effectable_IsAnimStartDoRandom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsAnimStartDoRandom'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsAnimStartDoRandom();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsAnimStartDoRandom'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUserNumAnimFrames of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetUserNumAnimFrames00
static int tolua_PX2_Effectable_SetUserNumAnimFrames00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  int userNumAnimFrames = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUserNumAnimFrames'", NULL);
#endif
  {
   self->SetUserNumAnimFrames(userNumAnimFrames);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUserNumAnimFrames'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUserNumAnimFrames of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetUserNumAnimFrames00
static int tolua_PX2_Effectable_GetUserNumAnimFrames00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUserNumAnimFrames'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetUserNumAnimFrames();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUserNumAnimFrames'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumAnimFrames of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetNumAnimFrames00
static int tolua_PX2_Effectable_GetNumAnimFrames00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumAnimFrames'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetNumAnimFrames();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumAnimFrames'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAnimFramesPlayOnce of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetAnimFramesPlayOnce00
static int tolua_PX2_Effectable_SetAnimFramesPlayOnce00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  bool playOnce = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAnimFramesPlayOnce'", NULL);
#endif
  {
   self->SetAnimFramesPlayOnce(playOnce);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAnimFramesPlayOnce'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsAnimFramesPlayOnce of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_IsAnimFramesPlayOnce00
static int tolua_PX2_Effectable_IsAnimFramesPlayOnce00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsAnimFramesPlayOnce'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsAnimFramesPlayOnce();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsAnimFramesPlayOnce'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaskTex of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetMaskTex00
static int tolua_PX2_Effectable_SetMaskTex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaskTex'", NULL);
#endif
  {
   self->SetMaskTex(filename);
   tolua_pushcppstring(tolua_S,(const char*)filename);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaskTex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaskTex of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetMaskTex00
static int tolua_PX2_Effectable_GetMaskTex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaskTex'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetMaskTex();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaskTex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitUV0_Offset of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetEmitUV0_Offset00
static int tolua_PX2_Effectable_SetEmitUV0_Offset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Float2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  const Float2* offset = ((const Float2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitUV0_Offset'", NULL);
#endif
  {
   self->SetEmitUV0_Offset(*offset);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitUV0_Offset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitUV0_Offset of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetEmitUV0_Offset00
static int tolua_PX2_Effectable_GetEmitUV0_Offset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitUV0_Offset'", NULL);
#endif
  {
   const Float2& tolua_ret = (const Float2&)  self->GetEmitUV0_Offset();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Float2");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitUV0_Offset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitUV0_Speed of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetEmitUV0_Speed00
static int tolua_PX2_Effectable_SetEmitUV0_Speed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Float2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  const Float2* speed = ((const Float2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitUV0_Speed'", NULL);
#endif
  {
   self->SetEmitUV0_Speed(*speed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitUV0_Speed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitUV0_Speed of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetEmitUV0_Speed00
static int tolua_PX2_Effectable_GetEmitUV0_Speed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitUV0_Speed'", NULL);
#endif
  {
   const Float2& tolua_ret = (const Float2&)  self->GetEmitUV0_Speed();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Float2");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitUV0_Speed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitUV0_Repeat of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetEmitUV0_Repeat00
static int tolua_PX2_Effectable_SetEmitUV0_Repeat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Float2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  const Float2* repeat = ((const Float2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitUV0_Repeat'", NULL);
#endif
  {
   self->SetEmitUV0_Repeat(*repeat);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitUV0_Repeat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitUV0_Repeat of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetEmitUV0_Repeat00
static int tolua_PX2_Effectable_GetEmitUV0_Repeat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitUV0_Repeat'", NULL);
#endif
  {
   const Float2& tolua_ret = (const Float2&)  self->GetEmitUV0_Repeat();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Float2");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitUV0_Repeat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUV1_Offset of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetUV1_Offset00
static int tolua_PX2_Effectable_SetUV1_Offset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Float2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  const Float2* offset = ((const Float2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUV1_Offset'", NULL);
#endif
  {
   self->SetUV1_Offset(*offset);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUV1_Offset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUV1_Offset of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetUV1_Offset00
static int tolua_PX2_Effectable_GetUV1_Offset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUV1_Offset'", NULL);
#endif
  {
   const Float2& tolua_ret = (const Float2&)  self->GetUV1_Offset();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Float2");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUV1_Offset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUV1_Repeat of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetUV1_Repeat00
static int tolua_PX2_Effectable_SetUV1_Repeat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Float2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  const Float2* repeat = ((const Float2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUV1_Repeat'", NULL);
#endif
  {
   self->SetUV1_Repeat(*repeat);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUV1_Repeat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUV1_Repeat of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetUV1_Repeat00
static int tolua_PX2_Effectable_GetUV1_Repeat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUV1_Repeat'", NULL);
#endif
  {
   const Float2& tolua_ret = (const Float2&)  self->GetUV1_Repeat();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Float2");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUV1_Repeat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUV1_Speed of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetUV1_Speed00
static int tolua_PX2_Effectable_SetUV1_Speed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Float2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  const Float2* speed = ((const Float2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUV1_Speed'", NULL);
#endif
  {
   self->SetUV1_Speed(*speed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUV1_Speed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUV1_Speed of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetUV1_Speed00
static int tolua_PX2_Effectable_GetUV1_Speed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUV1_Speed'", NULL);
#endif
  {
   const Float2& tolua_ret = (const Float2&)  self->GetUV1_Speed();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Float2");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUV1_Speed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCoordinateType0 of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetCoordinateType000
static int tolua_PX2_Effectable_SetCoordinateType000(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  Effectable::CoordinateType type = ((Effectable::CoordinateType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCoordinateType0'", NULL);
#endif
  {
   self->SetCoordinateType0(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCoordinateType0'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCoordinateType0 of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetCoordinateType000
static int tolua_PX2_Effectable_GetCoordinateType000(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCoordinateType0'", NULL);
#endif
  {
   Effectable::CoordinateType tolua_ret = (Effectable::CoordinateType)  self->GetCoordinateType0();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCoordinateType0'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCoordinateType1 of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_SetCoordinateType100
static int tolua_PX2_Effectable_SetCoordinateType100(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Effectable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Effectable* self = (Effectable*)  tolua_tousertype(tolua_S,1,0);
  Effectable::CoordinateType type = ((Effectable::CoordinateType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCoordinateType1'", NULL);
#endif
  {
   self->SetCoordinateType1(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCoordinateType1'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCoordinateType1 of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetCoordinateType100
static int tolua_PX2_Effectable_GetCoordinateType100(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCoordinateType1'", NULL);
#endif
  {
   Effectable::CoordinateType tolua_ret = (Effectable::CoordinateType)  self->GetCoordinateType1();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCoordinateType1'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAllModuleNames_EA of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetAllModuleNames_EA00
static int tolua_PX2_Effectable_GetAllModuleNames_EA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllModuleNames_EA'", NULL);
#endif
  {
   const std::vector<std::string>& tolua_ret = (const std::vector<std::string>&)  self->GetAllModuleNames_EA();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const std::vector<std::string>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllModuleNames_EA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAllModuleNames_EO of class  Effectable */
#ifndef TOLUA_DISABLE_tolua_PX2_Effectable_GetAllModuleNames_EO00
static int tolua_PX2_Effectable_GetAllModuleNames_EO00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Effectable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Effectable* self = (const Effectable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllModuleNames_EO'", NULL);
#endif
  {
   const std::vector<std::string>& tolua_ret = (const std::vector<std::string>&)  self->GetAllModuleNames_EO();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const std::vector<std::string>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllModuleNames_EO'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_new00
static int tolua_PX2_BeamEmitter_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"BeamEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   BeamEmitter* tolua_ret = (BeamEmitter*)  Mtolua_new((BeamEmitter)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"BeamEmitter");
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

/* method: new_local of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_new00_local
static int tolua_PX2_BeamEmitter_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"BeamEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   BeamEmitter* tolua_ret = (BeamEmitter*)  Mtolua_new((BeamEmitter)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"BeamEmitter");
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

/* method: delete of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_delete00
static int tolua_PX2_BeamEmitter_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BeamEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BeamEmitter* self = (BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetNumMaxBeams of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_SetNumMaxBeams00
static int tolua_PX2_BeamEmitter_SetNumMaxBeams00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BeamEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BeamEmitter* self = (BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
  int num = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetNumMaxBeams'", NULL);
#endif
  {
   self->SetNumMaxBeams(num);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNumMaxBeams'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumMaxBeams of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_GetNumMaxBeams00
static int tolua_PX2_BeamEmitter_GetNumMaxBeams00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const BeamEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const BeamEmitter* self = (const BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumMaxBeams'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetNumMaxBeams();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumMaxBeams'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitRate of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_SetEmitRate00
static int tolua_PX2_BeamEmitter_SetEmitRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BeamEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BeamEmitter* self = (BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
  float rate = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitRate'", NULL);
#endif
  {
   self->SetEmitRate(rate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitRate of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_GetEmitRate00
static int tolua_PX2_BeamEmitter_GetEmitRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const BeamEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const BeamEmitter* self = (const BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitRate'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetEmitRate();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitStartPos of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_SetEmitStartPos00
static int tolua_PX2_BeamEmitter_SetEmitStartPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BeamEmitter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BeamEmitter* self = (BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
  const APoint* startPos = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitStartPos'", NULL);
#endif
  {
   self->SetEmitStartPos(*startPos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitStartPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitStartPos of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_GetEmitStartPos00
static int tolua_PX2_BeamEmitter_GetEmitStartPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const BeamEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const BeamEmitter* self = (const BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitStartPos'", NULL);
#endif
  {
   const APoint& tolua_ret = (const APoint&)  self->GetEmitStartPos();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const APoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitStartPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitEndPos of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_SetEmitEndPos00
static int tolua_PX2_BeamEmitter_SetEmitEndPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BeamEmitter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BeamEmitter* self = (BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
  const APoint* endPos = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitEndPos'", NULL);
#endif
  {
   self->SetEmitEndPos(*endPos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitEndPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitEndPos of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_GetEmitEndPos00
static int tolua_PX2_BeamEmitter_GetEmitEndPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const BeamEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const BeamEmitter* self = (const BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitEndPos'", NULL);
#endif
  {
   const APoint& tolua_ret = (const APoint&)  self->GetEmitEndPos();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const APoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitEndPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetStartPosUseLocal of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_SetStartPosUseLocal00
static int tolua_PX2_BeamEmitter_SetStartPosUseLocal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BeamEmitter",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BeamEmitter* self = (BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
  bool startUseLocal = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetStartPosUseLocal'", NULL);
#endif
  {
   self->SetStartPosUseLocal(startUseLocal);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetStartPosUseLocal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsStartPosUseLocal of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_IsStartPosUseLocal00
static int tolua_PX2_BeamEmitter_IsStartPosUseLocal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const BeamEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const BeamEmitter* self = (const BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsStartPosUseLocal'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsStartPosUseLocal();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsStartPosUseLocal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSimpleLineWave of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_SetSimpleLineWave00
static int tolua_PX2_BeamEmitter_SetSimpleLineWave00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BeamEmitter",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BeamEmitter* self = (BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
  bool simpleLineWave = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSimpleLineWave'", NULL);
#endif
  {
   self->SetSimpleLineWave(simpleLineWave);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSimpleLineWave'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsSimpleLineWave of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_IsSimpleLineWave00
static int tolua_PX2_BeamEmitter_IsSimpleLineWave00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const BeamEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const BeamEmitter* self = (const BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsSimpleLineWave'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsSimpleLineWave();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsSimpleLineWave'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSimpleLineDoAlphaDisAfterStopSpeed of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_SetSimpleLineDoAlphaDisAfterStopSpeed00
static int tolua_PX2_BeamEmitter_SetSimpleLineDoAlphaDisAfterStopSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BeamEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BeamEmitter* self = (BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
  float speed = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSimpleLineDoAlphaDisAfterStopSpeed'", NULL);
#endif
  {
   self->SetSimpleLineDoAlphaDisAfterStopSpeed(speed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSimpleLineDoAlphaDisAfterStopSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSimpleLineDoAlphaDisAfterStopSpeed of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_GetSimpleLineDoAlphaDisAfterStopSpeed00
static int tolua_PX2_BeamEmitter_GetSimpleLineDoAlphaDisAfterStopSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const BeamEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const BeamEmitter* self = (const BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSimpleLineDoAlphaDisAfterStopSpeed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetSimpleLineDoAlphaDisAfterStopSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSimpleLineDoAlphaDisAfterStopSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWaveTypeUp of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_SetWaveTypeUp00
static int tolua_PX2_BeamEmitter_SetWaveTypeUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BeamEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BeamEmitter* self = (BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
  BeamEmitter::WaveType type = ((BeamEmitter::WaveType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWaveTypeUp'", NULL);
#endif
  {
   self->SetWaveTypeUp(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWaveTypeUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWaveTypeUp of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_GetWaveTypeUp00
static int tolua_PX2_BeamEmitter_GetWaveTypeUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const BeamEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const BeamEmitter* self = (const BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWaveTypeUp'", NULL);
#endif
  {
   BeamEmitter::WaveType tolua_ret = (BeamEmitter::WaveType)  self->GetWaveTypeUp();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWaveTypeUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWaveTypeExtend of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_SetWaveTypeExtend00
static int tolua_PX2_BeamEmitter_SetWaveTypeExtend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BeamEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BeamEmitter* self = (BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
  BeamEmitter::WaveType type = ((BeamEmitter::WaveType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWaveTypeExtend'", NULL);
#endif
  {
   self->SetWaveTypeExtend(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWaveTypeExtend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWaveTypeExtend of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_GetWaveTypeExtend00
static int tolua_PX2_BeamEmitter_GetWaveTypeExtend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const BeamEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const BeamEmitter* self = (const BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWaveTypeExtend'", NULL);
#endif
  {
   BeamEmitter::WaveType tolua_ret = (BeamEmitter::WaveType)  self->GetWaveTypeExtend();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWaveTypeExtend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetNumLowFrequency of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_SetNumLowFrequency00
static int tolua_PX2_BeamEmitter_SetNumLowFrequency00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BeamEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BeamEmitter* self = (BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
  int numLow = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetNumLowFrequency'", NULL);
#endif
  {
   self->SetNumLowFrequency(numLow);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNumLowFrequency'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumLowFrequency of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_GetNumLowFrequency00
static int tolua_PX2_BeamEmitter_GetNumLowFrequency00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const BeamEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const BeamEmitter* self = (const BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumLowFrequency'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetNumLowFrequency();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumLowFrequency'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetNumHighFrequency of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_SetNumHighFrequency00
static int tolua_PX2_BeamEmitter_SetNumHighFrequency00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BeamEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BeamEmitter* self = (BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
  int numHigh = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetNumHighFrequency'", NULL);
#endif
  {
   self->SetNumHighFrequency(numHigh);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNumHighFrequency'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumHighFrequency of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_GetNumHighFrequency00
static int tolua_PX2_BeamEmitter_GetNumHighFrequency00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const BeamEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const BeamEmitter* self = (const BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumHighFrequency'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetNumHighFrequency();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumHighFrequency'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLowFrequencyRangeUp of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_SetLowFrequencyRangeUp00
static int tolua_PX2_BeamEmitter_SetLowFrequencyRangeUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BeamEmitter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Float2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BeamEmitter* self = (BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
  const Float2* range = ((const Float2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLowFrequencyRangeUp'", NULL);
#endif
  {
   self->SetLowFrequencyRangeUp(*range);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLowFrequencyRangeUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLowFrequencyRangeExtend of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_SetLowFrequencyRangeExtend00
static int tolua_PX2_BeamEmitter_SetLowFrequencyRangeExtend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BeamEmitter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Float2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BeamEmitter* self = (BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
  const Float2* range = ((const Float2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLowFrequencyRangeExtend'", NULL);
#endif
  {
   self->SetLowFrequencyRangeExtend(*range);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLowFrequencyRangeExtend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLowFrequencyRangeUp of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_GetLowFrequencyRangeUp00
static int tolua_PX2_BeamEmitter_GetLowFrequencyRangeUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const BeamEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const BeamEmitter* self = (const BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLowFrequencyRangeUp'", NULL);
#endif
  {
   const Float2& tolua_ret = (const Float2&)  self->GetLowFrequencyRangeUp();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Float2");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLowFrequencyRangeUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLowFrequencyRangeExtend of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_GetLowFrequencyRangeExtend00
static int tolua_PX2_BeamEmitter_GetLowFrequencyRangeExtend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const BeamEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const BeamEmitter* self = (const BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLowFrequencyRangeExtend'", NULL);
#endif
  {
   const Float2& tolua_ret = (const Float2&)  self->GetLowFrequencyRangeExtend();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Float2");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLowFrequencyRangeExtend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHighFrequencyRangeUp of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_SetHighFrequencyRangeUp00
static int tolua_PX2_BeamEmitter_SetHighFrequencyRangeUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BeamEmitter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Float2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BeamEmitter* self = (BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
  const Float2* range = ((const Float2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHighFrequencyRangeUp'", NULL);
#endif
  {
   self->SetHighFrequencyRangeUp(*range);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHighFrequencyRangeUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHighFrequencyRangeExtend of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_SetHighFrequencyRangeExtend00
static int tolua_PX2_BeamEmitter_SetHighFrequencyRangeExtend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BeamEmitter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Float2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BeamEmitter* self = (BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
  const Float2* range = ((const Float2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHighFrequencyRangeExtend'", NULL);
#endif
  {
   self->SetHighFrequencyRangeExtend(*range);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHighFrequencyRangeExtend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHighFrequencyRangeUp of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_GetHighFrequencyRangeUp00
static int tolua_PX2_BeamEmitter_GetHighFrequencyRangeUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const BeamEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const BeamEmitter* self = (const BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHighFrequencyRangeUp'", NULL);
#endif
  {
   const Float2& tolua_ret = (const Float2&)  self->GetHighFrequencyRangeUp();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Float2");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHighFrequencyRangeUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHighFrequencyRangeExtend of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_GetHighFrequencyRangeExtend00
static int tolua_PX2_BeamEmitter_GetHighFrequencyRangeExtend00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const BeamEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const BeamEmitter* self = (const BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHighFrequencyRangeExtend'", NULL);
#endif
  {
   const Float2& tolua_ret = (const Float2&)  self->GetHighFrequencyRangeExtend();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Float2");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHighFrequencyRangeExtend'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAllModuleNames_EA of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_GetAllModuleNames_EA00
static int tolua_PX2_BeamEmitter_GetAllModuleNames_EA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const BeamEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const BeamEmitter* self = (const BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllModuleNames_EA'", NULL);
#endif
  {
   const std::vector<std::string>& tolua_ret = (const std::vector<std::string>&)  self->GetAllModuleNames_EA();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const std::vector<std::string>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllModuleNames_EA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAllModuleNames_EO of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_BeamEmitter_GetAllModuleNames_EO00
static int tolua_PX2_BeamEmitter_GetAllModuleNames_EO00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const BeamEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const BeamEmitter* self = (const BeamEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllModuleNames_EO'", NULL);
#endif
  {
   const std::vector<std::string>& tolua_ret = (const std::vector<std::string>&)  self->GetAllModuleNames_EO();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const std::vector<std::string>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllModuleNames_EO'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: msModuleNames_EA of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_get_BeamEmitter_msModuleNames_EA
static int tolua_get_BeamEmitter_msModuleNames_EA(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&BeamEmitter::msModuleNames_EA,"std::vector<std::string>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: msModuleNames_EA of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_set_BeamEmitter_msModuleNames_EA
static int tolua_set_BeamEmitter_msModuleNames_EA(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<std::string>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  BeamEmitter::msModuleNames_EA = *((std::vector<std::string>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: msModuleNames_EO of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_get_BeamEmitter_msModuleNames_EO
static int tolua_get_BeamEmitter_msModuleNames_EO(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&BeamEmitter::msModuleNames_EO,"std::vector<std::string>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: msModuleNames_EO of class  BeamEmitter */
#ifndef TOLUA_DISABLE_tolua_set_BeamEmitter_msModuleNames_EO
static int tolua_set_BeamEmitter_msModuleNames_EO(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<std::string>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  BeamEmitter::msModuleNames_EO = *((std::vector<std::string>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_PX2_Billboard_new00
static int tolua_PX2_Billboard_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Billboard* tolua_ret = (Billboard*)  Mtolua_new((Billboard)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Billboard");
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

/* method: new_local of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_PX2_Billboard_new00_local
static int tolua_PX2_Billboard_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Billboard* tolua_ret = (Billboard*)  Mtolua_new((Billboard)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Billboard");
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

/* method: delete of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_PX2_Billboard_delete00
static int tolua_PX2_Billboard_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Billboard* self = (Billboard*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetDynamic of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_PX2_Billboard_SetDynamic00
static int tolua_PX2_Billboard_SetDynamic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Billboard",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Billboard* self = (Billboard*)  tolua_tousertype(tolua_S,1,0);
  bool isDynamic = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDynamic'", NULL);
#endif
  {
   self->SetDynamic(isDynamic);
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

/* method: IsDynamic of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_PX2_Billboard_IsDynamic00
static int tolua_PX2_Billboard_IsDynamic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Billboard* self = (const Billboard*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetAnchorPoint of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_PX2_Billboard_SetAnchorPoint00
static int tolua_PX2_Billboard_SetAnchorPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Billboard",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Billboard* self = (Billboard*)  tolua_tousertype(tolua_S,1,0);
  float anchX = ((float)  tolua_tonumber(tolua_S,2,0));
  float anchZ = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAnchorPoint'", NULL);
#endif
  {
   self->SetAnchorPoint(anchX,anchZ);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAnchorPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAnchorPoint of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_PX2_Billboard_SetAnchorPoint01
static int tolua_PX2_Billboard_SetAnchorPoint01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Billboard",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Float2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Billboard* self = (Billboard*)  tolua_tousertype(tolua_S,1,0);
  const Float2* anchor = ((const Float2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAnchorPoint'", NULL);
#endif
  {
   self->SetAnchorPoint(*anchor);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Billboard_SetAnchorPoint00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAnchorPoint of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_PX2_Billboard_GetAnchorPoint00
static int tolua_PX2_Billboard_GetAnchorPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Billboard* self = (const Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAnchorPoint'", NULL);
#endif
  {
   const Float2& tolua_ret = (const Float2&)  self->GetAnchorPoint();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Float2");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAnchorPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUseTexAsSize of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_PX2_Billboard_SetUseTexAsSize00
static int tolua_PX2_Billboard_SetUseTexAsSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Billboard",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Billboard* self = (Billboard*)  tolua_tousertype(tolua_S,1,0);
  bool use = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUseTexAsSize'", NULL);
#endif
  {
   self->SetUseTexAsSize(use);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUseTexAsSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsUseTexAsSize of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_PX2_Billboard_IsUseTexAsSize00
static int tolua_PX2_Billboard_IsUseTexAsSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Billboard* self = (const Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsUseTexAsSize'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsUseTexAsSize();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsUseTexAsSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUseTrim of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_PX2_Billboard_SetUseTrim00
static int tolua_PX2_Billboard_SetUseTrim00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Billboard",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Billboard* self = (Billboard*)  tolua_tousertype(tolua_S,1,0);
  bool useTrim = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUseTrim'", NULL);
#endif
  {
   self->SetUseTrim(useTrim);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUseTrim'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsUseTrim of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_PX2_Billboard_IsUseTrim00
static int tolua_PX2_Billboard_IsUseTrim00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Billboard* self = (const Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsUseTrim'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsUseTrim();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsUseTrim'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDoAlphaDisAfterStop of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_PX2_Billboard_SetDoAlphaDisAfterStop00
static int tolua_PX2_Billboard_SetDoAlphaDisAfterStop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Billboard",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Billboard* self = (Billboard*)  tolua_tousertype(tolua_S,1,0);
  bool doAlphaDis = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDoAlphaDisAfterStop'", NULL);
#endif
  {
   self->SetDoAlphaDisAfterStop(doAlphaDis);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDoAlphaDisAfterStop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsDoAlphaDisAfterStop of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_PX2_Billboard_IsDoAlphaDisAfterStop00
static int tolua_PX2_Billboard_IsDoAlphaDisAfterStop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Billboard* self = (const Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsDoAlphaDisAfterStop'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsDoAlphaDisAfterStop();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsDoAlphaDisAfterStop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDoAlphaDisAfterStopSpeed of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_PX2_Billboard_SetDoAlphaDisAfterStopSpeed00
static int tolua_PX2_Billboard_SetDoAlphaDisAfterStopSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Billboard",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Billboard* self = (Billboard*)  tolua_tousertype(tolua_S,1,0);
  float speed = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDoAlphaDisAfterStopSpeed'", NULL);
#endif
  {
   self->SetDoAlphaDisAfterStopSpeed(speed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDoAlphaDisAfterStopSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDoAlphaDisAfterStopSpeed of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_PX2_Billboard_GetDoAlphaDisAfterStopSpeed00
static int tolua_PX2_Billboard_GetDoAlphaDisAfterStopSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Billboard* self = (const Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDoAlphaDisAfterStopSpeed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetDoAlphaDisAfterStopSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDoAlphaDisAfterStopSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSizeImmediate of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_PX2_Billboard_SetSizeImmediate00
static int tolua_PX2_Billboard_SetSizeImmediate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Billboard",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Billboard* self = (Billboard*)  tolua_tousertype(tolua_S,1,0);
  float sizeX = ((float)  tolua_tonumber(tolua_S,2,0));
  float sizeY = ((float)  tolua_tonumber(tolua_S,3,0));
  float sizeZ = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSizeImmediate'", NULL);
#endif
  {
   self->SetSizeImmediate(sizeX,sizeY,sizeZ);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSizeImmediate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAllModuleNames_EA of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_PX2_Billboard_GetAllModuleNames_EA00
static int tolua_PX2_Billboard_GetAllModuleNames_EA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Billboard* self = (const Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllModuleNames_EA'", NULL);
#endif
  {
   const std::vector<std::string>& tolua_ret = (const std::vector<std::string>&)  self->GetAllModuleNames_EA();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const std::vector<std::string>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllModuleNames_EA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAllModuleNames_EO of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_PX2_Billboard_GetAllModuleNames_EO00
static int tolua_PX2_Billboard_GetAllModuleNames_EO00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Billboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Billboard* self = (const Billboard*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllModuleNames_EO'", NULL);
#endif
  {
   const std::vector<std::string>& tolua_ret = (const std::vector<std::string>&)  self->GetAllModuleNames_EO();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const std::vector<std::string>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllModuleNames_EO'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: msModuleNames_EA of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_get_Billboard_msModuleNames_EA
static int tolua_get_Billboard_msModuleNames_EA(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Billboard::msModuleNames_EA,"std::vector<std::string>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: msModuleNames_EA of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_set_Billboard_msModuleNames_EA
static int tolua_set_Billboard_msModuleNames_EA(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<std::string>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Billboard::msModuleNames_EA = *((std::vector<std::string>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: msModuleNames_EO of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_get_Billboard_msModuleNames_EO
static int tolua_get_Billboard_msModuleNames_EO(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Billboard::msModuleNames_EO,"std::vector<std::string>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: msModuleNames_EO of class  Billboard */
#ifndef TOLUA_DISABLE_tolua_set_Billboard_msModuleNames_EO
static int tolua_set_Billboard_msModuleNames_EO(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<std::string>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Billboard::msModuleNames_EO = *((std::vector<std::string>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraShake_new00
static int tolua_PX2_CameraShake_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CameraShake",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CameraShake* tolua_ret = (CameraShake*)  Mtolua_new((CameraShake)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CameraShake");
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

/* method: new_local of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraShake_new00_local
static int tolua_PX2_CameraShake_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CameraShake",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CameraShake* tolua_ret = (CameraShake*)  Mtolua_new((CameraShake)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CameraShake");
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

/* method: delete of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraShake_delete00
static int tolua_PX2_CameraShake_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CameraShake",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CameraShake* self = (CameraShake*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Play of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraShake_Play00
static int tolua_PX2_CameraShake_Play00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CameraShake",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CameraShake* self = (CameraShake*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Play'", NULL);
#endif
  {
   self->Play();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Play'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Stop of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraShake_Stop00
static int tolua_PX2_CameraShake_Stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CameraShake",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CameraShake* self = (CameraShake*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetUseX of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraShake_SetUseX00
static int tolua_PX2_CameraShake_SetUseX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CameraShake",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CameraShake* self = (CameraShake*)  tolua_tousertype(tolua_S,1,0);
  bool use = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUseX'", NULL);
#endif
  {
   self->SetUseX(use);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUseX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsUseX of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraShake_IsUseX00
static int tolua_PX2_CameraShake_IsUseX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CameraShake",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CameraShake* self = (const CameraShake*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsUseX'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsUseX();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsUseX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUseY of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraShake_SetUseY00
static int tolua_PX2_CameraShake_SetUseY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CameraShake",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CameraShake* self = (CameraShake*)  tolua_tousertype(tolua_S,1,0);
  bool use = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUseY'", NULL);
#endif
  {
   self->SetUseY(use);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUseY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsUseY of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraShake_IsUseY00
static int tolua_PX2_CameraShake_IsUseY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CameraShake",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CameraShake* self = (const CameraShake*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsUseY'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsUseY();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsUseY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUseZ of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraShake_SetUseZ00
static int tolua_PX2_CameraShake_SetUseZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CameraShake",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CameraShake* self = (CameraShake*)  tolua_tousertype(tolua_S,1,0);
  bool use = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUseZ'", NULL);
#endif
  {
   self->SetUseZ(use);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUseZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsUseZ of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraShake_IsUseZ00
static int tolua_PX2_CameraShake_IsUseZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CameraShake",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CameraShake* self = (const CameraShake*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsUseZ'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsUseZ();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsUseZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxDistance of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraShake_SetMaxDistance00
static int tolua_PX2_CameraShake_SetMaxDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CameraShake",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CameraShake* self = (CameraShake*)  tolua_tousertype(tolua_S,1,0);
  float dist = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxDistance'", NULL);
#endif
  {
   self->SetMaxDistance(dist);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxDistance of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraShake_GetMaxDistance00
static int tolua_PX2_CameraShake_GetMaxDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CameraShake",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CameraShake* self = (const CameraShake*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxDistance'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetMaxDistance();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitStrength of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraShake_SetEmitStrength00
static int tolua_PX2_CameraShake_SetEmitStrength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CameraShake",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CameraShake* self = (CameraShake*)  tolua_tousertype(tolua_S,1,0);
  float strength = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitStrength'", NULL);
#endif
  {
   self->SetEmitStrength(strength);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitStrength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitStrength of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraShake_GetEmitStrength00
static int tolua_PX2_CameraShake_GetEmitStrength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CameraShake",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CameraShake* self = (const CameraShake*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitStrength'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetEmitStrength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitStrength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetShakeChannel of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraShake_GetShakeChannel00
static int tolua_PX2_CameraShake_GetShakeChannel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CameraShake",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CameraShake* self = (const CameraShake*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetShakeChannel'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetShakeChannel();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetShakeChannel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAllModuleNames_EA of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraShake_GetAllModuleNames_EA00
static int tolua_PX2_CameraShake_GetAllModuleNames_EA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CameraShake",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CameraShake* self = (const CameraShake*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllModuleNames_EA'", NULL);
#endif
  {
   const std::vector<std::string>& tolua_ret = (const std::vector<std::string>&)  self->GetAllModuleNames_EA();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const std::vector<std::string>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllModuleNames_EA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAllModuleNames_EO of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraShake_GetAllModuleNames_EO00
static int tolua_PX2_CameraShake_GetAllModuleNames_EO00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CameraShake",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CameraShake* self = (const CameraShake*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllModuleNames_EO'", NULL);
#endif
  {
   const std::vector<std::string>& tolua_ret = (const std::vector<std::string>&)  self->GetAllModuleNames_EO();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const std::vector<std::string>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllModuleNames_EO'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AllocChannel of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraShake_AllocChannel00
static int tolua_PX2_CameraShake_AllocChannel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CameraShake",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float maxDist = ((float)  tolua_tonumber(tolua_S,2,0));
  bool useX = ((bool)  tolua_toboolean(tolua_S,3,0));
  bool useY = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool useZ = ((bool)  tolua_toboolean(tolua_S,5,0));
  {
   int tolua_ret = (int)  CameraShake::AllocChannel(maxDist,useX,useY,useZ);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AllocChannel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FreeChannel of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraShake_FreeChannel00
static int tolua_PX2_CameraShake_FreeChannel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CameraShake",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int channel = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   CameraShake::FreeChannel(channel);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FreeChannel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetChannelShake of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraShake_SetChannelShake00
static int tolua_PX2_CameraShake_SetChannelShake00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CameraShake",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int channel = ((int)  tolua_tonumber(tolua_S,2,0));
  float strength = ((float)  tolua_tonumber(tolua_S,3,0));
  const APoint* shakeObjPos = ((const APoint*)  tolua_tousertype(tolua_S,4,0));
  {
   CameraShake::SetChannelShake(channel,strength,*shakeObjPos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetChannelShake'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ShakeCamera of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraShake_ShakeCamera00
static int tolua_PX2_CameraShake_ShakeCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CameraShake",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const APoint* recvCenter = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
  {
   float tolua_ret = (float)  CameraShake::ShakeCamera(*recvCenter);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ShakeCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ShakeChannels of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_get_PX2_CameraShake_ShakeChannels
static int tolua_get_PX2_CameraShake_ShakeChannels(lua_State* tolua_S)
{
 int tolua_index;
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=CameraShake::NUMSHAKEMAXCHANNELS)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&CameraShake::ShakeChannels[tolua_index],"CameraShakeChannel");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ShakeChannels of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_set_PX2_CameraShake_ShakeChannels
static int tolua_set_PX2_CameraShake_ShakeChannels(lua_State* tolua_S)
{
 int tolua_index;
  CameraShake* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (CameraShake*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=CameraShake::NUMSHAKEMAXCHANNELS)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->ShakeChannels[tolua_index] = *((CameraShakeChannel*)  tolua_tousertype(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: msModuleNames_EA of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_get_CameraShake_msModuleNames_EA
static int tolua_get_CameraShake_msModuleNames_EA(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&CameraShake::msModuleNames_EA,"std::vector<std::string>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: msModuleNames_EA of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_set_CameraShake_msModuleNames_EA
static int tolua_set_CameraShake_msModuleNames_EA(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<std::string>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  CameraShake::msModuleNames_EA = *((std::vector<std::string>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: msModuleNames_EO of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_get_CameraShake_msModuleNames_EO
static int tolua_get_CameraShake_msModuleNames_EO(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&CameraShake::msModuleNames_EO,"std::vector<std::string>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: msModuleNames_EO of class  CameraShake */
#ifndef TOLUA_DISABLE_tolua_set_CameraShake_msModuleNames_EO
static int tolua_set_CameraShake_msModuleNames_EO(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<std::string>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  CameraShake::msModuleNames_EO = *((std::vector<std::string>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  EffectModel */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModel_new00
static int tolua_PX2_EffectModel_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EffectModel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   EffectModel* tolua_ret = (EffectModel*)  Mtolua_new((EffectModel)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EffectModel");
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

/* method: new_local of class  EffectModel */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModel_new00_local
static int tolua_PX2_EffectModel_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EffectModel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   EffectModel* tolua_ret = (EffectModel*)  Mtolua_new((EffectModel)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EffectModel");
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

/* method: delete of class  EffectModel */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModel_delete00
static int tolua_PX2_EffectModel_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EffectModel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EffectModel* self = (EffectModel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Reset of class  EffectModel */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModel_Reset00
static int tolua_PX2_EffectModel_Reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EffectModel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EffectModel* self = (EffectModel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetModelType of class  EffectModel */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModel_SetModelType00
static int tolua_PX2_EffectModel_SetModelType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EffectModel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EffectModel* self = (EffectModel*)  tolua_tousertype(tolua_S,1,0);
  EffectModel::ModelType modelType = ((EffectModel::ModelType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetModelType'", NULL);
#endif
  {
   self->SetModelType(modelType);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetModelType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetModelType of class  EffectModel */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModel_GetModelType00
static int tolua_PX2_EffectModel_GetModelType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const EffectModel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const EffectModel* self = (const EffectModel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetModelType'", NULL);
#endif
  {
   EffectModel::ModelType tolua_ret = (EffectModel::ModelType)  self->GetModelType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetModelType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRadiusSample of class  EffectModel */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModel_SetRadiusSample00
static int tolua_PX2_EffectModel_SetRadiusSample00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EffectModel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EffectModel* self = (EffectModel*)  tolua_tousertype(tolua_S,1,0);
  int radiusSample = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRadiusSample'", NULL);
#endif
  {
   self->SetRadiusSample(radiusSample);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRadiusSample'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRadiusSample of class  EffectModel */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModel_GetRadiusSample00
static int tolua_PX2_EffectModel_GetRadiusSample00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const EffectModel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const EffectModel* self = (const EffectModel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRadiusSample'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetRadiusSample();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRadiusSample'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetZSample of class  EffectModel */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModel_SetZSample00
static int tolua_PX2_EffectModel_SetZSample00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EffectModel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EffectModel* self = (EffectModel*)  tolua_tousertype(tolua_S,1,0);
  int zSample = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetZSample'", NULL);
#endif
  {
   self->SetZSample(zSample);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetZSample'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetZSample of class  EffectModel */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModel_GetZSample00
static int tolua_PX2_EffectModel_GetZSample00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const EffectModel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const EffectModel* self = (const EffectModel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetZSample'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetZSample();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetZSample'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHeightAlphaType of class  EffectModel */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModel_SetHeightAlphaType00
static int tolua_PX2_EffectModel_SetHeightAlphaType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EffectModel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EffectModel* self = (EffectModel*)  tolua_tousertype(tolua_S,1,0);
  EffectModel::HeightAlphaType type = ((EffectModel::HeightAlphaType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHeightAlphaType'", NULL);
#endif
  {
   self->SetHeightAlphaType(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHeightAlphaType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHeightAlphaType of class  EffectModel */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModel_GetHeightAlphaType00
static int tolua_PX2_EffectModel_GetHeightAlphaType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const EffectModel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const EffectModel* self = (const EffectModel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHeightAlphaType'", NULL);
#endif
  {
   EffectModel::HeightAlphaType tolua_ret = (EffectModel::HeightAlphaType)  self->GetHeightAlphaType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHeightAlphaType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetModelFilename of class  EffectModel */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModel_SetModelFilename00
static int tolua_PX2_EffectModel_SetModelFilename00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EffectModel",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EffectModel* self = (EffectModel*)  tolua_tousertype(tolua_S,1,0);
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetModelFilename'", NULL);
#endif
  {
   self->SetModelFilename(filename);
   tolua_pushcppstring(tolua_S,(const char*)filename);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetModelFilename'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetModelFilename of class  EffectModel */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModel_GetModelFilename00
static int tolua_PX2_EffectModel_GetModelFilename00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const EffectModel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const EffectModel* self = (const EffectModel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetModelFilename'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetModelFilename();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetModelFilename'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAllModuleNames_EA of class  EffectModel */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModel_GetAllModuleNames_EA00
static int tolua_PX2_EffectModel_GetAllModuleNames_EA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const EffectModel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const EffectModel* self = (const EffectModel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllModuleNames_EA'", NULL);
#endif
  {
   const std::vector<std::string>& tolua_ret = (const std::vector<std::string>&)  self->GetAllModuleNames_EA();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const std::vector<std::string>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllModuleNames_EA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAllModuleNames_EO of class  EffectModel */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModel_GetAllModuleNames_EO00
static int tolua_PX2_EffectModel_GetAllModuleNames_EO00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const EffectModel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const EffectModel* self = (const EffectModel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllModuleNames_EO'", NULL);
#endif
  {
   const std::vector<std::string>& tolua_ret = (const std::vector<std::string>&)  self->GetAllModuleNames_EO();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const std::vector<std::string>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllModuleNames_EO'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: msModuleNames_EA of class  EffectModel */
#ifndef TOLUA_DISABLE_tolua_get_EffectModel_msModuleNames_EA
static int tolua_get_EffectModel_msModuleNames_EA(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EffectModel::msModuleNames_EA,"std::vector<std::string>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: msModuleNames_EA of class  EffectModel */
#ifndef TOLUA_DISABLE_tolua_set_EffectModel_msModuleNames_EA
static int tolua_set_EffectModel_msModuleNames_EA(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<std::string>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  EffectModel::msModuleNames_EA = *((std::vector<std::string>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: msModuleNames_EO of class  EffectModel */
#ifndef TOLUA_DISABLE_tolua_get_EffectModel_msModuleNames_EO
static int tolua_get_EffectModel_msModuleNames_EO(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EffectModel::msModuleNames_EO,"std::vector<std::string>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: msModuleNames_EO of class  EffectModel */
#ifndef TOLUA_DISABLE_tolua_set_EffectModel_msModuleNames_EO
static int tolua_set_EffectModel_msModuleNames_EO(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<std::string>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  EffectModel::msModuleNames_EO = *((std::vector<std::string>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  EffectModelNode */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModelNode_new00
static int tolua_PX2_EffectModelNode_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EffectModelNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   EffectModelNode* tolua_ret = (EffectModelNode*)  Mtolua_new((EffectModelNode)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EffectModelNode");
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

/* method: new_local of class  EffectModelNode */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModelNode_new00_local
static int tolua_PX2_EffectModelNode_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EffectModelNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   EffectModelNode* tolua_ret = (EffectModelNode*)  Mtolua_new((EffectModelNode)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EffectModelNode");
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

/* method: delete of class  EffectModelNode */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModelNode_delete00
static int tolua_PX2_EffectModelNode_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EffectModelNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EffectModelNode* self = (EffectModelNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetModelFilename of class  EffectModelNode */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModelNode_SetModelFilename00
static int tolua_PX2_EffectModelNode_SetModelFilename00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EffectModelNode",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EffectModelNode* self = (EffectModelNode*)  tolua_tousertype(tolua_S,1,0);
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetModelFilename'", NULL);
#endif
  {
   self->SetModelFilename(filename);
   tolua_pushcppstring(tolua_S,(const char*)filename);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetModelFilename'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetModelFilename of class  EffectModelNode */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModelNode_GetModelFilename00
static int tolua_PX2_EffectModelNode_GetModelFilename00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const EffectModelNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const EffectModelNode* self = (const EffectModelNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetModelFilename'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetModelFilename();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetModelFilename'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCoordinateType0 of class  EffectModelNode */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModelNode_SetCoordinateType000
static int tolua_PX2_EffectModelNode_SetCoordinateType000(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EffectModelNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EffectModelNode* self = (EffectModelNode*)  tolua_tousertype(tolua_S,1,0);
  EffectModelNode::CoordinateType type = ((EffectModelNode::CoordinateType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCoordinateType0'", NULL);
#endif
  {
   self->SetCoordinateType0(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCoordinateType0'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCoordinateType0 of class  EffectModelNode */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModelNode_GetCoordinateType000
static int tolua_PX2_EffectModelNode_GetCoordinateType000(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const EffectModelNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const EffectModelNode* self = (const EffectModelNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCoordinateType0'", NULL);
#endif
  {
   EffectModelNode::CoordinateType tolua_ret = (EffectModelNode::CoordinateType)  self->GetCoordinateType0();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCoordinateType0'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCoordinateType1 of class  EffectModelNode */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModelNode_SetCoordinateType100
static int tolua_PX2_EffectModelNode_SetCoordinateType100(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EffectModelNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EffectModelNode* self = (EffectModelNode*)  tolua_tousertype(tolua_S,1,0);
  EffectModelNode::CoordinateType type = ((EffectModelNode::CoordinateType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCoordinateType1'", NULL);
#endif
  {
   self->SetCoordinateType1(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCoordinateType1'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCoordinateType1 of class  EffectModelNode */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModelNode_GetCoordinateType100
static int tolua_PX2_EffectModelNode_GetCoordinateType100(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const EffectModelNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const EffectModelNode* self = (const EffectModelNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCoordinateType1'", NULL);
#endif
  {
   EffectModelNode::CoordinateType tolua_ret = (EffectModelNode::CoordinateType)  self->GetCoordinateType1();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCoordinateType1'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUVSpeed of class  EffectModelNode */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModelNode_SetUVSpeed00
static int tolua_PX2_EffectModelNode_SetUVSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EffectModelNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Float2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EffectModelNode* self = (EffectModelNode*)  tolua_tousertype(tolua_S,1,0);
  const Float2* uv = ((const Float2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUVSpeed'", NULL);
#endif
  {
   self->SetUVSpeed(*uv);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUVSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUVSpeed of class  EffectModelNode */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModelNode_GetUVSpeed00
static int tolua_PX2_EffectModelNode_GetUVSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const EffectModelNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const EffectModelNode* self = (const EffectModelNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUVSpeed'", NULL);
#endif
  {
   const Float2& tolua_ret = (const Float2&)  self->GetUVSpeed();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Float2");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUVSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTextureFilename of class  EffectModelNode */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModelNode_SetTextureFilename00
static int tolua_PX2_EffectModelNode_SetTextureFilename00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EffectModelNode",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EffectModelNode* self = (EffectModelNode*)  tolua_tousertype(tolua_S,1,0);
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTextureFilename'", NULL);
#endif
  {
   self->SetTextureFilename(filename);
   tolua_pushcppstring(tolua_S,(const char*)filename);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTextureFilename'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextureFilename of class  EffectModelNode */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModelNode_GetTextureFilename00
static int tolua_PX2_EffectModelNode_GetTextureFilename00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const EffectModelNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const EffectModelNode* self = (const EffectModelNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextureFilename'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetTextureFilename();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextureFilename'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Reset of class  EffectModelNode */
#ifndef TOLUA_DISABLE_tolua_PX2_EffectModelNode_Reset00
static int tolua_PX2_EffectModelNode_Reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EffectModelNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EffectModelNode* self = (EffectModelNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_new00
static int tolua_PX2_ParticleEmitter_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ParticleEmitter* tolua_ret = (ParticleEmitter*)  Mtolua_new((ParticleEmitter)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ParticleEmitter");
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

/* method: new_local of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_new00_local
static int tolua_PX2_ParticleEmitter_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ParticleEmitter* tolua_ret = (ParticleEmitter*)  Mtolua_new((ParticleEmitter)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ParticleEmitter");
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

/* method: delete of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_delete00
static int tolua_PX2_ParticleEmitter_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetMaxNumParticles of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetMaxNumParticles00
static int tolua_PX2_ParticleEmitter_SetMaxNumParticles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  int num = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxNumParticles'", NULL);
#endif
  {
   self->SetMaxNumParticles(num);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxNumParticles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxNumParticles of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetMaxNumParticles00
static int tolua_PX2_ParticleEmitter_GetMaxNumParticles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxNumParticles'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetMaxNumParticles();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxNumParticles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBlast of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetBlast00
static int tolua_PX2_ParticleEmitter_SetBlast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  bool blast = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBlast'", NULL);
#endif
  {
   self->SetBlast(blast);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBlast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsBlast of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_IsBlast00
static int tolua_PX2_ParticleEmitter_IsBlast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsBlast'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsBlast();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsBlast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDrawType of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetDrawType00
static int tolua_PX2_ParticleEmitter_SetDrawType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  ParticleEmitter::DrawType type = ((ParticleEmitter::DrawType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDrawType'", NULL);
#endif
  {
   self->SetDrawType(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDrawType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDrawType of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetDrawType00
static int tolua_PX2_ParticleEmitter_GetDrawType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDrawType'", NULL);
#endif
  {
   ParticleEmitter::DrawType tolua_ret = (ParticleEmitter::DrawType)  self->GetDrawType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDrawType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetModelFilename of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetModelFilename00
static int tolua_PX2_ParticleEmitter_SetModelFilename00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetModelFilename'", NULL);
#endif
  {
   self->SetModelFilename(filename);
   tolua_pushcppstring(tolua_S,(const char*)filename);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetModelFilename'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetModelFilename of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetModelFilename00
static int tolua_PX2_ParticleEmitter_GetModelFilename00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetModelFilename'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetModelFilename();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetModelFilename'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAnchorPoint of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetAnchorPoint00
static int tolua_PX2_ParticleEmitter_SetAnchorPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Float2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  const Float2* point = ((const Float2*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAnchorPoint'", NULL);
#endif
  {
   self->SetAnchorPoint(*point);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAnchorPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAnchorPoint of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetAnchorPoint00
static int tolua_PX2_ParticleEmitter_GetAnchorPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAnchorPoint'", NULL);
#endif
  {
   const Float2& tolua_ret = (const Float2&)  self->GetAnchorPoint();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Float2");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAnchorPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitRate of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetEmitRate00
static int tolua_PX2_ParticleEmitter_SetEmitRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  float rate = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitRate'", NULL);
#endif
  {
   self->SetEmitRate(rate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitRate of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetEmitRate00
static int tolua_PX2_ParticleEmitter_GetEmitRate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitRate'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetEmitRate();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitRate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitDirDynamic of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetEmitDirDynamic00
static int tolua_PX2_ParticleEmitter_SetEmitDirDynamic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  bool dyn = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitDirDynamic'", NULL);
#endif
  {
   self->SetEmitDirDynamic(dyn);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitDirDynamic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsEmitDirDynamic of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_IsEmitDirDynamic00
static int tolua_PX2_ParticleEmitter_IsEmitDirDynamic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsEmitDirDynamic'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsEmitDirDynamic();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsEmitDirDynamic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitDir of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetEmitDir00
static int tolua_PX2_ParticleEmitter_SetEmitDir00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  const AVector* dir = ((const AVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitDir'", NULL);
#endif
  {
   self->SetEmitDir(*dir);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitDir'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitDir of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetEmitDir00
static int tolua_PX2_ParticleEmitter_GetEmitDir00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitDir'", NULL);
#endif
  {
   AVector& tolua_ret = (AVector&)  self->GetEmitDir();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"AVector");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitDir'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitDirLocal of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetEmitDirLocal00
static int tolua_PX2_ParticleEmitter_SetEmitDirLocal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  bool isLocal = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitDirLocal'", NULL);
#endif
  {
   self->SetEmitDirLocal(isLocal);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitDirLocal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsEmitDirLocal of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_IsEmitDirLocal00
static int tolua_PX2_ParticleEmitter_IsEmitDirLocal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsEmitDirLocal'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsEmitDirLocal();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsEmitDirLocal'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitDirType of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetEmitDirType00
static int tolua_PX2_ParticleEmitter_SetEmitDirType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  ParticleEmitter::EmitDirType type = ((ParticleEmitter::EmitDirType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitDirType'", NULL);
#endif
  {
   self->SetEmitDirType(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitDirType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitDirType of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetEmitDirType00
static int tolua_PX2_ParticleEmitter_GetEmitDirType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitDirType'", NULL);
#endif
  {
   ParticleEmitter::EmitDirType tolua_ret = (ParticleEmitter::EmitDirType)  self->GetEmitDirType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitDirType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitSpeed of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetEmitSpeed00
static int tolua_PX2_ParticleEmitter_SetEmitSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  float speed = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitSpeed'", NULL);
#endif
  {
   self->SetEmitSpeed(speed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitSpeed of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetEmitSpeed00
static int tolua_PX2_ParticleEmitter_GetEmitSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitSpeed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetEmitSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitAccelerateDir of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetEmitAccelerateDir00
static int tolua_PX2_ParticleEmitter_SetEmitAccelerateDir00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  const AVector* dir = ((const AVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitAccelerateDir'", NULL);
#endif
  {
   self->SetEmitAccelerateDir(*dir);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitAccelerateDir'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitAccelerateDir of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetEmitAccelerateDir00
static int tolua_PX2_ParticleEmitter_GetEmitAccelerateDir00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitAccelerateDir'", NULL);
#endif
  {
   const AVector& tolua_ret = (const AVector&)  self->GetEmitAccelerateDir();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const AVector");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitAccelerateDir'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitAccelerate of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetEmitAccelerate00
static int tolua_PX2_ParticleEmitter_SetEmitAccelerate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  float val = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitAccelerate'", NULL);
#endif
  {
   self->SetEmitAccelerate(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitAccelerate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitAccelerate of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetEmitAccelerate00
static int tolua_PX2_ParticleEmitter_GetEmitAccelerate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitAccelerate'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetEmitAccelerate();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitAccelerate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitAttractPoint of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetEmitAttractPoint00
static int tolua_PX2_ParticleEmitter_SetEmitAttractPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitAttractPoint'", NULL);
#endif
  {
   self->SetEmitAttractPoint(*pos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitAttractPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitAttactPoint of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetEmitAttactPoint00
static int tolua_PX2_ParticleEmitter_GetEmitAttactPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitAttactPoint'", NULL);
#endif
  {
   const APoint& tolua_ret = (const APoint&)  self->GetEmitAttactPoint();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const APoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitAttactPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitAttactStrength of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetEmitAttactStrength00
static int tolua_PX2_ParticleEmitter_SetEmitAttactStrength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  const AVector* strength = ((const AVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitAttactStrength'", NULL);
#endif
  {
   self->SetEmitAttactStrength(*strength);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitAttactStrength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitAttackStrength of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetEmitAttackStrength00
static int tolua_PX2_ParticleEmitter_GetEmitAttackStrength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitAttackStrength'", NULL);
#endif
  {
   const AVector& tolua_ret = (const AVector&)  self->GetEmitAttackStrength();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const AVector");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitAttackStrength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetObstruct of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetObstruct00
static int tolua_PX2_ParticleEmitter_SetObstruct00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  const AVector* obs = ((const AVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetObstruct'", NULL);
#endif
  {
   self->SetObstruct(*obs);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetObstruct'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetObstruct of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetObstruct00
static int tolua_PX2_ParticleEmitter_GetObstruct00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObstruct'", NULL);
#endif
  {
   const AVector& tolua_ret = (const AVector&)  self->GetObstruct();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const AVector");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetObstruct'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRotateAxisType of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetRotateAxisType00
static int tolua_PX2_ParticleEmitter_SetRotateAxisType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  ParticleEmitter::RotateAxisType type = ((ParticleEmitter::RotateAxisType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRotateAxisType'", NULL);
#endif
  {
   self->SetRotateAxisType(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRotateAxisType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRotateAxisType of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetRotateAxisType00
static int tolua_PX2_ParticleEmitter_GetRotateAxisType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRotateAxisType'", NULL);
#endif
  {
   ParticleEmitter::RotateAxisType tolua_ret = (ParticleEmitter::RotateAxisType)  self->GetRotateAxisType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRotateAxisType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitRotateAxis of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetEmitRotateAxis00
static int tolua_PX2_ParticleEmitter_SetEmitRotateAxis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  const AVector* dir = ((const AVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitRotateAxis'", NULL);
#endif
  {
   self->SetEmitRotateAxis(*dir);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitRotateAxis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitRotateAxis of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetEmitRotateAxis00
static int tolua_PX2_ParticleEmitter_GetEmitRotateAxis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitRotateAxis'", NULL);
#endif
  {
   const AVector tolua_ret = (const AVector)  self->GetEmitRotateAxis();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((AVector)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"const AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(const AVector));
     tolua_pushusertype(tolua_S,tolua_obj,"const AVector");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitRotateAxis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitRotateDegree of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetEmitRotateDegree00
static int tolua_PX2_ParticleEmitter_SetEmitRotateDegree00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  float degree = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitRotateDegree'", NULL);
#endif
  {
   self->SetEmitRotateDegree(degree);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitRotateDegree'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitRotateDegree of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetEmitRotateDegree00
static int tolua_PX2_ParticleEmitter_GetEmitRotateDegree00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitRotateDegree'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetEmitRotateDegree();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitRotateDegree'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEmitRotateSpeed of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetEmitRotateSpeed00
static int tolua_PX2_ParticleEmitter_SetEmitRotateSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  float speed = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEmitRotateSpeed'", NULL);
#endif
  {
   self->SetEmitRotateSpeed(speed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEmitRotateSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEmitRotateSpeed of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetEmitRotateSpeed00
static int tolua_PX2_ParticleEmitter_GetEmitRotateSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEmitRotateSpeed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetEmitRotateSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEmitRotateSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCollisionType of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetCollisionType00
static int tolua_PX2_ParticleEmitter_SetCollisionType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  ParticleEmitter::CollisionType type = ((ParticleEmitter::CollisionType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCollisionType'", NULL);
#endif
  {
   self->SetCollisionType(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCollisionType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCollisionType of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetCollisionType00
static int tolua_PX2_ParticleEmitter_GetCollisionType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCollisionType'", NULL);
#endif
  {
   ParticleEmitter::CollisionType tolua_ret = (ParticleEmitter::CollisionType)  self->GetCollisionType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCollisionType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCollisionOption of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetCollisionOption00
static int tolua_PX2_ParticleEmitter_SetCollisionOption00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  ParticleEmitter::CollisionOption type = ((ParticleEmitter::CollisionOption) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCollisionOption'", NULL);
#endif
  {
   self->SetCollisionOption(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCollisionOption'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCollisionOption of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetCollisionOption00
static int tolua_PX2_ParticleEmitter_GetCollisionOption00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCollisionOption'", NULL);
#endif
  {
   ParticleEmitter::CollisionOption tolua_ret = (ParticleEmitter::CollisionOption)  self->GetCollisionOption();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCollisionOption'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCollisionFaceHeight of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetCollisionFaceHeight00
static int tolua_PX2_ParticleEmitter_SetCollisionFaceHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  float height = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCollisionFaceHeight'", NULL);
#endif
  {
   self->SetCollisionFaceHeight(height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCollisionFaceHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCollisionFaceHeight of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetCollisionFaceHeight00
static int tolua_PX2_ParticleEmitter_GetCollisionFaceHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCollisionFaceHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetCollisionFaceHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCollisionFaceHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCollisionSpeedPercent of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetCollisionSpeedPercent00
static int tolua_PX2_ParticleEmitter_SetCollisionSpeedPercent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  float percent = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCollisionSpeedPercent'", NULL);
#endif
  {
   self->SetCollisionSpeedPercent(percent);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCollisionSpeedPercent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCollisionSpeedPercent of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetCollisionSpeedPercent00
static int tolua_PX2_ParticleEmitter_GetCollisionSpeedPercent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCollisionSpeedPercent'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetCollisionSpeedPercent();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCollisionSpeedPercent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlacerType of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetPlacerType00
static int tolua_PX2_ParticleEmitter_SetPlacerType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  ParticleEmitter::PlacerType type = ((ParticleEmitter::PlacerType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlacerType'", NULL);
#endif
  {
   self->SetPlacerType(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlacerType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlacerType of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetPlacerType00
static int tolua_PX2_ParticleEmitter_GetPlacerType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlacerType'", NULL);
#endif
  {
   ParticleEmitter::PlacerType tolua_ret = (ParticleEmitter::PlacerType)  self->GetPlacerType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlacerType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlacerInLength of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetPlacerInLength00
static int tolua_PX2_ParticleEmitter_SetPlacerInLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  float val = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlacerInLength'", NULL);
#endif
  {
   self->SetPlacerInLength(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlacerInLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlacerOutLength of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetPlacerOutLength00
static int tolua_PX2_ParticleEmitter_SetPlacerOutLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  float val = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlacerOutLength'", NULL);
#endif
  {
   self->SetPlacerOutLength(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlacerOutLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlacerInWidth of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetPlacerInWidth00
static int tolua_PX2_ParticleEmitter_SetPlacerInWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  float val = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlacerInWidth'", NULL);
#endif
  {
   self->SetPlacerInWidth(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlacerInWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlacerOutWidth of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetPlacerOutWidth00
static int tolua_PX2_ParticleEmitter_SetPlacerOutWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  float val = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlacerOutWidth'", NULL);
#endif
  {
   self->SetPlacerOutWidth(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlacerOutWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlacerInHeight of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetPlacerInHeight00
static int tolua_PX2_ParticleEmitter_SetPlacerInHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  float val = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlacerInHeight'", NULL);
#endif
  {
   self->SetPlacerInHeight(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlacerInHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlacerOutHeight of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_SetPlacerOutHeight00
static int tolua_PX2_ParticleEmitter_SetPlacerOutHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ParticleEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ParticleEmitter* self = (ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
  float val = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlacerOutHeight'", NULL);
#endif
  {
   self->SetPlacerOutHeight(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlacerOutHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlacerInLength of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetPlacerInLength00
static int tolua_PX2_ParticleEmitter_GetPlacerInLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlacerInLength'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlacerInLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlacerInLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlacerOutLength of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetPlacerOutLength00
static int tolua_PX2_ParticleEmitter_GetPlacerOutLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlacerOutLength'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlacerOutLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlacerOutLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlacerInWidth of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetPlacerInWidth00
static int tolua_PX2_ParticleEmitter_GetPlacerInWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlacerInWidth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlacerInWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlacerInWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlacerOutWidth of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetPlacerOutWidth00
static int tolua_PX2_ParticleEmitter_GetPlacerOutWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlacerOutWidth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlacerOutWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlacerOutWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlacerInHeight of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetPlacerInHeight00
static int tolua_PX2_ParticleEmitter_GetPlacerInHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlacerInHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlacerInHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlacerInHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlacerOutHeight of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetPlacerOutHeight00
static int tolua_PX2_ParticleEmitter_GetPlacerOutHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlacerOutHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlacerOutHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlacerOutHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlacerAPoint of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetPlacerAPoint00
static int tolua_PX2_ParticleEmitter_GetPlacerAPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlacerAPoint'", NULL);
#endif
  {
   APoint tolua_ret = (APoint)  self->GetPlacerAPoint();
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
 tolua_error(tolua_S,"#ferror in function 'GetPlacerAPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAllModuleNames_EA of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetAllModuleNames_EA00
static int tolua_PX2_ParticleEmitter_GetAllModuleNames_EA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllModuleNames_EA'", NULL);
#endif
  {
   const std::vector<std::string>& tolua_ret = (const std::vector<std::string>&)  self->GetAllModuleNames_EA();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const std::vector<std::string>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllModuleNames_EA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAllModuleNames_EO of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_ParticleEmitter_GetAllModuleNames_EO00
static int tolua_PX2_ParticleEmitter_GetAllModuleNames_EO00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ParticleEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ParticleEmitter* self = (const ParticleEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllModuleNames_EO'", NULL);
#endif
  {
   const std::vector<std::string>& tolua_ret = (const std::vector<std::string>&)  self->GetAllModuleNames_EO();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const std::vector<std::string>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllModuleNames_EO'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: msModuleNames_EA of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_get_ParticleEmitter_msModuleNames_EA
static int tolua_get_ParticleEmitter_msModuleNames_EA(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ParticleEmitter::msModuleNames_EA,"std::vector<std::string>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: msModuleNames_EA of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_set_ParticleEmitter_msModuleNames_EA
static int tolua_set_ParticleEmitter_msModuleNames_EA(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<std::string>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  ParticleEmitter::msModuleNames_EA = *((std::vector<std::string>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: msModuleNames_EO of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_get_ParticleEmitter_msModuleNames_EO
static int tolua_get_ParticleEmitter_msModuleNames_EO(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&ParticleEmitter::msModuleNames_EO,"std::vector<std::string>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: msModuleNames_EO of class  ParticleEmitter */
#ifndef TOLUA_DISABLE_tolua_set_ParticleEmitter_msModuleNames_EO
static int tolua_set_ParticleEmitter_msModuleNames_EO(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<std::string>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  ParticleEmitter::msModuleNames_EO = *((std::vector<std::string>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  RibbonEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_RibbonEmitter_new00
static int tolua_PX2_RibbonEmitter_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RibbonEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   RibbonEmitter* tolua_ret = (RibbonEmitter*)  Mtolua_new((RibbonEmitter)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RibbonEmitter");
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

/* method: new_local of class  RibbonEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_RibbonEmitter_new00_local
static int tolua_PX2_RibbonEmitter_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RibbonEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   RibbonEmitter* tolua_ret = (RibbonEmitter*)  Mtolua_new((RibbonEmitter)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RibbonEmitter");
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

/* method: delete of class  RibbonEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_RibbonEmitter_delete00
static int tolua_PX2_RibbonEmitter_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RibbonEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RibbonEmitter* self = (RibbonEmitter*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetLength of class  RibbonEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_RibbonEmitter_SetLength00
static int tolua_PX2_RibbonEmitter_SetLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RibbonEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RibbonEmitter* self = (RibbonEmitter*)  tolua_tousertype(tolua_S,1,0);
  float length = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLength'", NULL);
#endif
  {
   self->SetLength(length);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLength of class  RibbonEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_RibbonEmitter_GetLength00
static int tolua_PX2_RibbonEmitter_GetLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const RibbonEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const RibbonEmitter* self = (const RibbonEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLength'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSegLength of class  RibbonEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_RibbonEmitter_SetSegLength00
static int tolua_PX2_RibbonEmitter_SetSegLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RibbonEmitter",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RibbonEmitter* self = (RibbonEmitter*)  tolua_tousertype(tolua_S,1,0);
  float length = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSegLength'", NULL);
#endif
  {
   self->SetSegLength(length);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSegLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSegLength of class  RibbonEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_RibbonEmitter_GetSegLength00
static int tolua_PX2_RibbonEmitter_GetSegLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const RibbonEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const RibbonEmitter* self = (const RibbonEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSegLength'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetSegLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSegLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAllModuleNames_EA of class  RibbonEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_RibbonEmitter_GetAllModuleNames_EA00
static int tolua_PX2_RibbonEmitter_GetAllModuleNames_EA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const RibbonEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const RibbonEmitter* self = (const RibbonEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllModuleNames_EA'", NULL);
#endif
  {
   const std::vector<std::string>& tolua_ret = (const std::vector<std::string>&)  self->GetAllModuleNames_EA();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const std::vector<std::string>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllModuleNames_EA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAllModuleNames_EO of class  RibbonEmitter */
#ifndef TOLUA_DISABLE_tolua_PX2_RibbonEmitter_GetAllModuleNames_EO00
static int tolua_PX2_RibbonEmitter_GetAllModuleNames_EO00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const RibbonEmitter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const RibbonEmitter* self = (const RibbonEmitter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllModuleNames_EO'", NULL);
#endif
  {
   const std::vector<std::string>& tolua_ret = (const std::vector<std::string>&)  self->GetAllModuleNames_EO();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const std::vector<std::string>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllModuleNames_EO'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: msModuleNames_EA of class  RibbonEmitter */
#ifndef TOLUA_DISABLE_tolua_get_RibbonEmitter_msModuleNames_EA
static int tolua_get_RibbonEmitter_msModuleNames_EA(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&RibbonEmitter::msModuleNames_EA,"std::vector<std::string>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: msModuleNames_EA of class  RibbonEmitter */
#ifndef TOLUA_DISABLE_tolua_set_RibbonEmitter_msModuleNames_EA
static int tolua_set_RibbonEmitter_msModuleNames_EA(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<std::string>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  RibbonEmitter::msModuleNames_EA = *((std::vector<std::string>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: msModuleNames_EO of class  RibbonEmitter */
#ifndef TOLUA_DISABLE_tolua_get_RibbonEmitter_msModuleNames_EO
static int tolua_get_RibbonEmitter_msModuleNames_EO(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&RibbonEmitter::msModuleNames_EO,"std::vector<std::string>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: msModuleNames_EO of class  RibbonEmitter */
#ifndef TOLUA_DISABLE_tolua_set_RibbonEmitter_msModuleNames_EO
static int tolua_set_RibbonEmitter_msModuleNames_EO(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<std::string>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  RibbonEmitter::msModuleNames_EO = *((std::vector<std::string>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_new00
static int tolua_PX2_Soundable_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Soundable",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,"Data/engine/ling.ogg"));
  {
   Soundable* tolua_ret = (Soundable*)  Mtolua_new((Soundable)(filename));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Soundable");
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

/* method: new_local of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_new00_local
static int tolua_PX2_Soundable_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Soundable",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,"Data/engine/ling.ogg"));
  {
   Soundable* tolua_ret = (Soundable*)  Mtolua_new((Soundable)(filename));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Soundable");
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

/* method: delete of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_delete00
static int tolua_PX2_Soundable_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Soundable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Soundable* self = (Soundable*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetSourceType of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_SetSourceType00
static int tolua_PX2_Soundable_SetSourceType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Soundable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Soundable* self = (Soundable*)  tolua_tousertype(tolua_S,1,0);
  Soundable::SourceType st = ((Soundable::SourceType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSourceType'", NULL);
#endif
  {
   self->SetSourceType(st);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSourceType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSourceType of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_GetSourceType00
static int tolua_PX2_Soundable_GetSourceType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Soundable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Soundable* self = (const Soundable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSourceType'", NULL);
#endif
  {
   Soundable::SourceType tolua_ret = (Soundable::SourceType)  self->GetSourceType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSourceType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMusicChannel of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_SetMusicChannel00
static int tolua_PX2_Soundable_SetMusicChannel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Soundable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Soundable* self = (Soundable*)  tolua_tousertype(tolua_S,1,0);
  int channel = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMusicChannel'", NULL);
#endif
  {
   self->SetMusicChannel(channel);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMusicChannel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMusicChannel of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_GetMusicChannel00
static int tolua_PX2_Soundable_GetMusicChannel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Soundable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Soundable* self = (const Soundable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMusicChannel'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetMusicChannel();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMusicChannel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Reset of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_Reset00
static int tolua_PX2_Soundable_Reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Soundable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Soundable* self = (Soundable*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Play of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_Play00
static int tolua_PX2_Soundable_Play00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Soundable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Soundable* self = (Soundable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Play'", NULL);
#endif
  {
   self->Play();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Play'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Stop of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_Stop00
static int tolua_PX2_Soundable_Stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Soundable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Soundable* self = (Soundable*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetIngoreStopSound of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_SetIngoreStopSound00
static int tolua_PX2_Soundable_SetIngoreStopSound00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Soundable",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Soundable* self = (Soundable*)  tolua_tousertype(tolua_S,1,0);
  bool stop = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIngoreStopSound'", NULL);
#endif
  {
   self->SetIngoreStopSound(stop);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIngoreStopSound'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsIngoreStopSound of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_IsIngoreStopSound00
static int tolua_PX2_Soundable_IsIngoreStopSound00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Soundable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Soundable* self = (const Soundable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsIngoreStopSound'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsIngoreStopSound();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsIngoreStopSound'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSoundFilename of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_SetSoundFilename00
static int tolua_PX2_Soundable_SetSoundFilename00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Soundable",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Soundable* self = (Soundable*)  tolua_tousertype(tolua_S,1,0);
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSoundFilename'", NULL);
#endif
  {
   self->SetSoundFilename(filename);
   tolua_pushcppstring(tolua_S,(const char*)filename);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSoundFilename'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSoundFilename of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_GetSoundFilename00
static int tolua_PX2_Soundable_GetSoundFilename00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Soundable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Soundable* self = (const Soundable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSoundFilename'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetSoundFilename();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSoundFilename'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Set3D of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_Set3D00
static int tolua_PX2_Soundable_Set3D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Soundable",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Soundable* self = (Soundable*)  tolua_tousertype(tolua_S,1,0);
  bool is3D = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set3D'", NULL);
#endif
  {
   self->Set3D(is3D);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set3D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Is3D of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_Is3D00
static int tolua_PX2_Soundable_Is3D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Soundable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Soundable* self = (const Soundable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Is3D'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Is3D();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Is3D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVolume of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_SetVolume00
static int tolua_PX2_Soundable_SetVolume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Soundable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Soundable* self = (Soundable*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetVolume of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_GetVolume00
static int tolua_PX2_Soundable_GetVolume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Soundable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Soundable* self = (const Soundable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVolume'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetVolume();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVolume'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVelocity of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_SetVelocity00
static int tolua_PX2_Soundable_SetVelocity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Soundable",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Soundable* self = (Soundable*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetVelocity of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_GetVelocity00
static int tolua_PX2_Soundable_GetVelocity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Soundable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Soundable* self = (const Soundable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVelocity'", NULL);
#endif
  {
   const AVector& tolua_ret = (const AVector&)  self->GetVelocity();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const AVector");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVelocity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDistance of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_SetDistance00
static int tolua_PX2_Soundable_SetDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Soundable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Soundable* self = (Soundable*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetMinDistance of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_SetMinDistance00
static int tolua_PX2_Soundable_SetMinDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Soundable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Soundable* self = (Soundable*)  tolua_tousertype(tolua_S,1,0);
  float minDistance = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMinDistance'", NULL);
#endif
  {
   self->SetMinDistance(minDistance);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMinDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaxDistance of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_SetMaxDistance00
static int tolua_PX2_Soundable_SetMaxDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Soundable",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Soundable* self = (Soundable*)  tolua_tousertype(tolua_S,1,0);
  float maxDistance = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaxDistance'", NULL);
#endif
  {
   self->SetMaxDistance(maxDistance);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaxDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMinDistance of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_GetMinDistance00
static int tolua_PX2_Soundable_GetMinDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Soundable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Soundable* self = (const Soundable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMinDistance'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetMinDistance();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMinDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaxDistance of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_GetMaxDistance00
static int tolua_PX2_Soundable_GetMaxDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Soundable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Soundable* self = (const Soundable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaxDistance'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetMaxDistance();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaxDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLoop of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_SetLoop00
static int tolua_PX2_Soundable_SetLoop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Soundable",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Soundable* self = (Soundable*)  tolua_tousertype(tolua_S,1,0);
  bool isLoop = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLoop'", NULL);
#endif
  {
   self->SetLoop(isLoop);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLoop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsLoop of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_IsLoop00
static int tolua_PX2_Soundable_IsLoop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Soundable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Soundable* self = (const Soundable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsLoop'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsLoop();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsLoop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDistanceUseX of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_SetDistanceUseX00
static int tolua_PX2_Soundable_SetDistanceUseX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Soundable",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Soundable* self = (Soundable*)  tolua_tousertype(tolua_S,1,0);
  bool use = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDistanceUseX'", NULL);
#endif
  {
   self->SetDistanceUseX(use);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDistanceUseX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsDistanceUseX of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_IsDistanceUseX00
static int tolua_PX2_Soundable_IsDistanceUseX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Soundable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Soundable* self = (const Soundable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsDistanceUseX'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsDistanceUseX();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsDistanceUseX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDistanceUseY of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_SetDistanceUseY00
static int tolua_PX2_Soundable_SetDistanceUseY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Soundable",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Soundable* self = (Soundable*)  tolua_tousertype(tolua_S,1,0);
  bool use = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDistanceUseY'", NULL);
#endif
  {
   self->SetDistanceUseY(use);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDistanceUseY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsDistanceUseY of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_IsDistanceUseY00
static int tolua_PX2_Soundable_IsDistanceUseY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Soundable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Soundable* self = (const Soundable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsDistanceUseY'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsDistanceUseY();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsDistanceUseY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDistanceUseZ of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_SetDistanceUseZ00
static int tolua_PX2_Soundable_SetDistanceUseZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Soundable",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Soundable* self = (Soundable*)  tolua_tousertype(tolua_S,1,0);
  bool use = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDistanceUseZ'", NULL);
#endif
  {
   self->SetDistanceUseZ(use);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDistanceUseZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsDistanceUseZ of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_IsDistanceUseZ00
static int tolua_PX2_Soundable_IsDistanceUseZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Soundable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Soundable* self = (const Soundable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsDistanceUseZ'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsDistanceUseZ();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsDistanceUseZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAllModuleNames_EA of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_GetAllModuleNames_EA00
static int tolua_PX2_Soundable_GetAllModuleNames_EA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Soundable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Soundable* self = (const Soundable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllModuleNames_EA'", NULL);
#endif
  {
   const std::vector<std::string>& tolua_ret = (const std::vector<std::string>&)  self->GetAllModuleNames_EA();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const std::vector<std::string>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllModuleNames_EA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAllModuleNames_EO of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_PX2_Soundable_GetAllModuleNames_EO00
static int tolua_PX2_Soundable_GetAllModuleNames_EO00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Soundable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Soundable* self = (const Soundable*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllModuleNames_EO'", NULL);
#endif
  {
   const std::vector<std::string>& tolua_ret = (const std::vector<std::string>&)  self->GetAllModuleNames_EO();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const std::vector<std::string>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllModuleNames_EO'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: msModuleNames_EA of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_get_Soundable_msModuleNames_EA
static int tolua_get_Soundable_msModuleNames_EA(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Soundable::msModuleNames_EA,"std::vector<std::string>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: msModuleNames_EA of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_set_Soundable_msModuleNames_EA
static int tolua_set_Soundable_msModuleNames_EA(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<std::string>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Soundable::msModuleNames_EA = *((std::vector<std::string>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: msModuleNames_EO of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_get_Soundable_msModuleNames_EO
static int tolua_get_Soundable_msModuleNames_EO(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Soundable::msModuleNames_EO,"std::vector<std::string>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: msModuleNames_EO of class  Soundable */
#ifndef TOLUA_DISABLE_tolua_set_Soundable_msModuleNames_EO
static int tolua_set_Soundable_msModuleNames_EO(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<std::string>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Soundable::msModuleNames_EO = *((std::vector<std::string>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: Save of class  Project */
#ifndef TOLUA_DISABLE_tolua_PX2_Project_Save00
static int tolua_PX2_Project_Save00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Project",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Project* self = (Project*)  tolua_tousertype(tolua_S,1,0);
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Save'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Save(filename);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)filename);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Save'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SaveConfig of class  Project */
#ifndef TOLUA_DISABLE_tolua_PX2_Project_SaveConfig00
static int tolua_PX2_Project_SaveConfig00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Project",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Project* self = (Project*)  tolua_tousertype(tolua_S,1,0);
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SaveConfig'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SaveConfig(filename);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)filename);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaveConfig'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Load of class  Project */
#ifndef TOLUA_DISABLE_tolua_PX2_Project_Load00
static int tolua_PX2_Project_Load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Project",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Project* self = (Project*)  tolua_tousertype(tolua_S,1,0);
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Load'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Load(filename);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)filename);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSize of class  Project */
#ifndef TOLUA_DISABLE_tolua_PX2_Project_SetSize00
static int tolua_PX2_Project_SetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Project",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Project* self = (Project*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetSize of class  Project */
#ifndef TOLUA_DISABLE_tolua_PX2_Project_SetSize01
static int tolua_PX2_Project_SetSize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Project",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Sizef",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Project* self = (Project*)  tolua_tousertype(tolua_S,1,0);
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
 return tolua_PX2_Project_SetSize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSize of class  Project */
#ifndef TOLUA_DISABLE_tolua_PX2_Project_GetSize00
static int tolua_PX2_Project_GetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Project",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Project* self = (const Project*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetWidth of class  Project */
#ifndef TOLUA_DISABLE_tolua_PX2_Project_GetWidth00
static int tolua_PX2_Project_GetWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Project",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Project* self = (const Project*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetHeight of class  Project */
#ifndef TOLUA_DISABLE_tolua_PX2_Project_GetHeight00
static int tolua_PX2_Project_GetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Project",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Project* self = (const Project*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetBackgroundColor of class  Project */
#ifndef TOLUA_DISABLE_tolua_PX2_Project_SetBackgroundColor00
static int tolua_PX2_Project_SetBackgroundColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Project",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Float4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Project* self = (Project*)  tolua_tousertype(tolua_S,1,0);
  const Float4* color = ((const Float4*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBackgroundColor'", NULL);
#endif
  {
   self->SetBackgroundColor(*color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBackgroundColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBackgroundColor of class  Project */
#ifndef TOLUA_DISABLE_tolua_PX2_Project_GetBackgroundColor00
static int tolua_PX2_Project_GetBackgroundColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Project",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Project* self = (const Project*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBackgroundColor'", NULL);
#endif
  {
   const Float4& tolua_ret = (const Float4&)  self->GetBackgroundColor();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Float4");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBackgroundColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScene of class  Project */
#ifndef TOLUA_DISABLE_tolua_PX2_Project_SetScene00
static int tolua_PX2_Project_SetScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Project",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Project* self = (Project*)  tolua_tousertype(tolua_S,1,0);
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScene'", NULL);
#endif
  {
   self->SetScene(scene);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScene of class  Project */
#ifndef TOLUA_DISABLE_tolua_PX2_Project_GetScene00
static int tolua_PX2_Project_GetScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Project",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Project* self = (Project*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScene'", NULL);
#endif
  {
   Scene* tolua_ret = (Scene*)  self->GetScene();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Scene");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSceneFilename of class  Project */
#ifndef TOLUA_DISABLE_tolua_PX2_Project_GetSceneFilename00
static int tolua_PX2_Project_GetSceneFilename00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Project",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Project* self = (const Project*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSceneFilename'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetSceneFilename();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSceneFilename'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSceneRenderStep of class  Project */
#ifndef TOLUA_DISABLE_tolua_PX2_Project_GetSceneRenderStep00
static int tolua_PX2_Project_GetSceneRenderStep00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Project",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Project* self = (Project*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSceneRenderStep'", NULL);
#endif
  {
   RenderStep* tolua_ret = (RenderStep*)  self->GetSceneRenderStep();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RenderStep");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSceneRenderStep'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUIFrame of class  Project */
#ifndef TOLUA_DISABLE_tolua_PX2_Project_SetUIFrame00
static int tolua_PX2_Project_SetUIFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Project",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"UIFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Project* self = (Project*)  tolua_tousertype(tolua_S,1,0);
  UIFrame* ui = ((UIFrame*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUIFrame'", NULL);
#endif
  {
   self->SetUIFrame(ui);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUIFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUIFrame of class  Project */
#ifndef TOLUA_DISABLE_tolua_PX2_Project_GetUIFrame00
static int tolua_PX2_Project_GetUIFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Project",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Project* self = (Project*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUIFrame'", NULL);
#endif
  {
   UIFrame* tolua_ret = (UIFrame*)  self->GetUIFrame();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIFrame");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUIFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUIFilename of class  Project */
#ifndef TOLUA_DISABLE_tolua_PX2_Project_GetUIFilename00
static int tolua_PX2_Project_GetUIFilename00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Project",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Project* self = (const Project*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUIFilename'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetUIFilename();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUIFilename'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddObject of class  Selection */
#ifndef TOLUA_DISABLE_tolua_PX2_Selection_AddObject00
static int tolua_PX2_Selection_AddObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Selection",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2::Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Selection* self = (Selection*)  tolua_tousertype(tolua_S,1,0);
  PX2::Object* obj = ((PX2::Object*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddObject'", NULL);
#endif
  {
   self->AddObject(obj);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveObject of class  Selection */
#ifndef TOLUA_DISABLE_tolua_PX2_Selection_RemoveObject00
static int tolua_PX2_Selection_RemoveObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Selection",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2::Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Selection* self = (Selection*)  tolua_tousertype(tolua_S,1,0);
  PX2::Object* obj = ((PX2::Object*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveObject'", NULL);
#endif
  {
   self->RemoveObject(obj);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetObjectAt of class  Selection */
#ifndef TOLUA_DISABLE_tolua_PX2_Selection_GetObjectAt00
static int tolua_PX2_Selection_GetObjectAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Selection",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Selection* self = (Selection*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObjectAt'", NULL);
#endif
  {
   Object* tolua_ret = (Object*)  self->GetObjectAt(i);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Object");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetObjectAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumObjects of class  Selection */
#ifndef TOLUA_DISABLE_tolua_PX2_Selection_GetNumObjects00
static int tolua_PX2_Selection_GetNumObjects00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Selection",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Selection* self = (Selection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumObjects'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetNumObjects();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumObjects'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsObjectIn of class  Selection */
#ifndef TOLUA_DISABLE_tolua_PX2_Selection_IsObjectIn00
static int tolua_PX2_Selection_IsObjectIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Selection",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"PX2::Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Selection* self = (Selection*)  tolua_tousertype(tolua_S,1,0);
  PX2::Object* obj = ((PX2::Object*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsObjectIn'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsObjectIn(obj);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsObjectIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Clear of class  Selection */
#ifndef TOLUA_DISABLE_tolua_PX2_Selection_Clear00
static int tolua_PX2_Selection_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Selection",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Selection* self = (Selection*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetFirstObject of class  Selection */
#ifndef TOLUA_DISABLE_tolua_PX2_Selection_GetFirstObject00
static int tolua_PX2_Selection_GetFirstObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Selection",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Selection* self = (const Selection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFirstObject'", NULL);
#endif
  {
   Object* tolua_ret = (Object*)  self->GetFirstObject();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Object");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFirstObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Translate of class  Selection */
#ifndef TOLUA_DISABLE_tolua_PX2_Selection_Translate00
static int tolua_PX2_Selection_Translate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Selection",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"PX2::AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Selection* self = (Selection*)  tolua_tousertype(tolua_S,1,0);
  PX2::AVector vec = *((PX2::AVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Translate'", NULL);
#endif
  {
   self->Translate(vec);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Translate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: TranslateTo of class  Selection */
#ifndef TOLUA_DISABLE_tolua_PX2_Selection_TranslateTo00
static int tolua_PX2_Selection_TranslateTo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Selection",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"PX2::APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Selection* self = (Selection*)  tolua_tousertype(tolua_S,1,0);
  PX2::APoint pos = *((PX2::APoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'TranslateTo'", NULL);
#endif
  {
   self->TranslateTo(pos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TranslateTo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddRolate of class  Selection */
#ifndef TOLUA_DISABLE_tolua_PX2_Selection_AddRolate00
static int tolua_PX2_Selection_AddRolate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Selection",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"PX2::AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Selection* self = (Selection*)  tolua_tousertype(tolua_S,1,0);
  PX2::AVector vec = *((PX2::AVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddRolate'", NULL);
#endif
  {
   self->AddRolate(vec);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddRolate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddScale of class  Selection */
#ifndef TOLUA_DISABLE_tolua_PX2_Selection_AddScale00
static int tolua_PX2_Selection_AddScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Selection",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"PX2::AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Selection* self = (Selection*)  tolua_tousertype(tolua_S,1,0);
  PX2::AVector vec = *((PX2::AVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddScale'", NULL);
#endif
  {
   self->AddScale(vec);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCenter of class  Selection */
#ifndef TOLUA_DISABLE_tolua_PX2_Selection_GetCenter00
static int tolua_PX2_Selection_GetCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Selection",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Selection* self = (const Selection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCenter'", NULL);
#endif
  {
   const PX2::APoint& tolua_ret = (const PX2::APoint&)  self->GetCenter();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const PX2::APoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRadius of class  Selection */
#ifndef TOLUA_DISABLE_tolua_PX2_Selection_GetRadius00
static int tolua_PX2_Selection_GetRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Selection",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Selection* self = (const Selection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRadius'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetRadius();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_new00
static int tolua_PX2_Creater_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Creater* tolua_ret = (Creater*)  Mtolua_new((Creater)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Creater");
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

/* method: new_local of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_new00_local
static int tolua_PX2_Creater_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Creater* tolua_ret = (Creater*)  Mtolua_new((Creater)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Creater");
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

/* method: delete of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_delete00
static int tolua_PX2_Creater_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
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

/* method: CreateActor_Rectangle of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_CreateActor_Rectangle00
static int tolua_PX2_Creater_CreateActor_Rectangle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,2,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateActor_Rectangle'", NULL);
#endif
  {
   Actor* tolua_ret = (Actor*)  self->CreateActor_Rectangle(scene,*pos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Actor");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateActor_Rectangle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateActor_Box of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_CreateActor_Box00
static int tolua_PX2_Creater_CreateActor_Box00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,2,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateActor_Box'", NULL);
#endif
  {
   Actor* tolua_ret = (Actor*)  self->CreateActor_Box(scene,*pos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Actor");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateActor_Box'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateActor_Sphere of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_CreateActor_Sphere00
static int tolua_PX2_Creater_CreateActor_Sphere00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,2,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateActor_Sphere'", NULL);
#endif
  {
   Actor* tolua_ret = (Actor*)  self->CreateActor_Sphere(scene,*pos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Actor");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateActor_Sphere'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateActor_Effect of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_CreateActor_Effect00
static int tolua_PX2_Creater_CreateActor_Effect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,2,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateActor_Effect'", NULL);
#endif
  {
   Actor* tolua_ret = (Actor*)  self->CreateActor_Effect(scene,*pos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Actor");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateActor_Effect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateActor_Character of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_CreateActor_Character00
static int tolua_PX2_Creater_CreateActor_Character00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,2,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateActor_Character'", NULL);
#endif
  {
   Character* tolua_ret = (Character*)  self->CreateActor_Character(scene,*pos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Character");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateActor_Character'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateRectangle of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_CreateRectangle00
static int tolua_PX2_Creater_CreateRectangle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const APoint",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Node* parent = ((Node*)  tolua_tousertype(tolua_S,2,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,3,0));
  bool isPosWorld = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool doAdd = ((bool)  tolua_toboolean(tolua_S,5,true));
  bool usePickPos = ((bool)  tolua_toboolean(tolua_S,6,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateRectangle'", NULL);
#endif
  {
   Movable* tolua_ret = (Movable*)  self->CreateRectangle(parent,*pos,isPosWorld,doAdd,usePickPos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Movable");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateRectangle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateBox of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_CreateBox00
static int tolua_PX2_Creater_CreateBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const APoint",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Node* parent = ((Node*)  tolua_tousertype(tolua_S,2,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,3,0));
  bool isPosWorld = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool doAdd = ((bool)  tolua_toboolean(tolua_S,5,true));
  bool usePickPos = ((bool)  tolua_toboolean(tolua_S,6,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateBox'", NULL);
#endif
  {
   Movable* tolua_ret = (Movable*)  self->CreateBox(parent,*pos,isPosWorld,doAdd,usePickPos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Movable");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateSphere of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_CreateSphere00
static int tolua_PX2_Creater_CreateSphere00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const APoint",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,1,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Node* parent = ((Node*)  tolua_tousertype(tolua_S,2,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,3,0));
  bool isPosWorld = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool doAdd = ((bool)  tolua_toboolean(tolua_S,5,true));
  bool usePickPos = ((bool)  tolua_toboolean(tolua_S,6,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateSphere'", NULL);
#endif
  {
   Movable* tolua_ret = (Movable*)  self->CreateSphere(parent,*pos,isPosWorld,doAdd,usePickPos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Movable");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateSphere'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateUIFrame of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_CreateUIFrame00
static int tolua_PX2_Creater_CreateUIFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const APoint",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Node* parent = ((Node*)  tolua_tousertype(tolua_S,2,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,3,0));
  bool isPosWorld = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool usePickPos = ((bool)  tolua_toboolean(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateUIFrame'", NULL);
#endif
  {
   UIFrame* tolua_ret = (UIFrame*)  self->CreateUIFrame(parent,*pos,isPosWorld,usePickPos);
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

/* method: CreateUIPicBox of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_CreateUIPicBox00
static int tolua_PX2_Creater_CreateUIPicBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const APoint",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Node* parent = ((Node*)  tolua_tousertype(tolua_S,2,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,3,0));
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  bool isPosWorld = ((bool)  tolua_toboolean(tolua_S,5,0));
  bool usePickPos = ((bool)  tolua_toboolean(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateUIPicBox'", NULL);
#endif
  {
   UIPicBox* tolua_ret = (UIPicBox*)  self->CreateUIPicBox(parent,*pos,filename,isPosWorld,usePickPos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIPicBox");
   tolua_pushcppstring(tolua_S,(const char*)filename);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateUIPicBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateUIPicBox of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_CreateUIPicBox01
static int tolua_PX2_Creater_CreateUIPicBox01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const APoint",0,&tolua_err)) ||
     !tolua_iscppstring(tolua_S,4,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Node* parent = ((Node*)  tolua_tousertype(tolua_S,2,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,3,0));
  const std::string texPack = ((const std::string)  tolua_tocppstring(tolua_S,4,0));
  const std::string eleName = ((const std::string)  tolua_tocppstring(tolua_S,5,0));
  bool isPosWorld = ((bool)  tolua_toboolean(tolua_S,6,0));
  bool usePickPos = ((bool)  tolua_toboolean(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateUIPicBox'", NULL);
#endif
  {
   UIPicBox* tolua_ret = (UIPicBox*)  self->CreateUIPicBox(parent,*pos,texPack,eleName,isPosWorld,usePickPos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIPicBox");
   tolua_pushcppstring(tolua_S,(const char*)texPack);
   tolua_pushcppstring(tolua_S,(const char*)eleName);
  }
 }
 return 3;
tolua_lerror:
 return tolua_PX2_Creater_CreateUIPicBox00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateUIText of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_CreateUIText00
static int tolua_PX2_Creater_CreateUIText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const APoint",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Node* parent = ((Node*)  tolua_tousertype(tolua_S,2,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,3,0));
  bool isPosWorld = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool usePickPos = ((bool)  tolua_toboolean(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateUIText'", NULL);
#endif
  {
   UIText* tolua_ret = (UIText*)  self->CreateUIText(parent,*pos,isPosWorld,usePickPos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIText");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateUIText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateUIButton of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_CreateUIButton00
static int tolua_PX2_Creater_CreateUIButton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const APoint",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Node* parent = ((Node*)  tolua_tousertype(tolua_S,2,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,3,0));
  bool isPosWorld = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool usePickPos = ((bool)  tolua_toboolean(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateUIButton'", NULL);
#endif
  {
   UIButton* tolua_ret = (UIButton*)  self->CreateUIButton(parent,*pos,isPosWorld,usePickPos);
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

/* method: CreateUICheckButton of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_CreateUICheckButton00
static int tolua_PX2_Creater_CreateUICheckButton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const APoint",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Node* parent = ((Node*)  tolua_tousertype(tolua_S,2,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,3,0));
  bool isPosWorld = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool usePickPos = ((bool)  tolua_toboolean(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateUICheckButton'", NULL);
#endif
  {
   UICheckButton* tolua_ret = (UICheckButton*)  self->CreateUICheckButton(parent,*pos,isPosWorld,usePickPos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UICheckButton");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateUICheckButton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateUIEditBox of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_CreateUIEditBox00
static int tolua_PX2_Creater_CreateUIEditBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const APoint",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Node* parent = ((Node*)  tolua_tousertype(tolua_S,2,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,3,0));
  bool isPosWorld = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool usePickPos = ((bool)  tolua_toboolean(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateUIEditBox'", NULL);
#endif
  {
   UIEditBox* tolua_ret = (UIEditBox*)  self->CreateUIEditBox(parent,*pos,isPosWorld,usePickPos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIEditBox");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateUIEditBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateUIProgressBar of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_CreateUIProgressBar00
static int tolua_PX2_Creater_CreateUIProgressBar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const APoint",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Node* parent = ((Node*)  tolua_tousertype(tolua_S,2,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,3,0));
  bool isPosWorld = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool usePickPos = ((bool)  tolua_toboolean(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateUIProgressBar'", NULL);
#endif
  {
   UIProgressBar* tolua_ret = (UIProgressBar*)  self->CreateUIProgressBar(parent,*pos,isPosWorld,usePickPos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIProgressBar");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateUIProgressBar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateParticleEmitter of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_CreateParticleEmitter00
static int tolua_PX2_Creater_CreateParticleEmitter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const APoint",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Node* parent = ((Node*)  tolua_tousertype(tolua_S,2,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,3,0));
  bool isPosWorld = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool usePickPos = ((bool)  tolua_toboolean(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateParticleEmitter'", NULL);
#endif
  {
   ParticleEmitter* tolua_ret = (ParticleEmitter*)  self->CreateParticleEmitter(parent,*pos,isPosWorld,usePickPos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ParticleEmitter");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateParticleEmitter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateBillboard of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_CreateBillboard00
static int tolua_PX2_Creater_CreateBillboard00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const APoint",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Node* parent = ((Node*)  tolua_tousertype(tolua_S,2,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,3,0));
  bool isPosWorld = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool usePickPos = ((bool)  tolua_toboolean(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateBillboard'", NULL);
#endif
  {
   Billboard* tolua_ret = (Billboard*)  self->CreateBillboard(parent,*pos,isPosWorld,usePickPos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Billboard");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateBillboard'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateBeamEmitter of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_CreateBeamEmitter00
static int tolua_PX2_Creater_CreateBeamEmitter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const APoint",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Node* parent = ((Node*)  tolua_tousertype(tolua_S,2,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,3,0));
  bool isPosWorld = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool usePickPos = ((bool)  tolua_toboolean(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateBeamEmitter'", NULL);
#endif
  {
   BeamEmitter* tolua_ret = (BeamEmitter*)  self->CreateBeamEmitter(parent,*pos,isPosWorld,usePickPos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"BeamEmitter");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateBeamEmitter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateRibbonEmitter of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_CreateRibbonEmitter00
static int tolua_PX2_Creater_CreateRibbonEmitter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const APoint",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Node* parent = ((Node*)  tolua_tousertype(tolua_S,2,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,3,0));
  bool isPosWorld = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool usePickPos = ((bool)  tolua_toboolean(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateRibbonEmitter'", NULL);
#endif
  {
   RibbonEmitter* tolua_ret = (RibbonEmitter*)  self->CreateRibbonEmitter(parent,*pos,isPosWorld,usePickPos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RibbonEmitter");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateRibbonEmitter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateSoundable of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_CreateSoundable00
static int tolua_PX2_Creater_CreateSoundable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Node",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const APoint",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Node* parent = ((Node*)  tolua_tousertype(tolua_S,2,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,3,0));
  bool isPosWorld = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool usePickPos = ((bool)  tolua_toboolean(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateSoundable'", NULL);
#endif
  {
   Soundable* tolua_ret = (Soundable*)  self->CreateSoundable(parent,*pos,isPosWorld,usePickPos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Soundable");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateSoundable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddActor of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_AddActor00
static int tolua_PX2_Creater_AddActor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,2,0));
  const std::string resPath = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddActor'", NULL);
#endif
  {
   Actor* tolua_ret = (Actor*)  self->AddActor(scene,resPath,*pos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Actor");
   tolua_pushcppstring(tolua_S,(const char*)resPath);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddActor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddCharacter of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_AddCharacter00
static int tolua_PX2_Creater_AddCharacter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,2,0));
  const std::string resPath = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddCharacter'", NULL);
#endif
  {
   Character* tolua_ret = (Character*)  self->AddCharacter(scene,resPath,*pos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Character");
   tolua_pushcppstring(tolua_S,(const char*)resPath);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddCharacter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddEffectActor of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_AddEffectActor00
static int tolua_PX2_Creater_AddEffectActor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Scene",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Scene* scene = ((Scene*)  tolua_tousertype(tolua_S,2,0));
  const std::string resPath = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddEffectActor'", NULL);
#endif
  {
   EffectActor* tolua_ret = (EffectActor*)  self->AddEffectActor(scene,resPath,*pos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EffectActor");
   tolua_pushcppstring(tolua_S,(const char*)resPath);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddEffectActor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddObject of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_AddObject00
static int tolua_PX2_Creater_AddObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Object",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Object",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Object* parent = ((Object*)  tolua_tousertype(tolua_S,2,0));
  Object* obj = ((Object*)  tolua_tousertype(tolua_S,3,0));
  bool command = ((bool)  tolua_toboolean(tolua_S,4,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddObject'", NULL);
#endif
  {
   self->AddObject(parent,obj,command);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveObject of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_RemoveObject00
static int tolua_PX2_Creater_RemoveObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Object",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Object* obj = ((Object*)  tolua_tousertype(tolua_S,2,0));
  bool command = ((bool)  tolua_toboolean(tolua_S,3,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveObject'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->RemoveObject(obj,command);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ConvertToNode of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_ConvertToNode00
static int tolua_PX2_Creater_ConvertToNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Object* obj = ((Object*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ConvertToNode'", NULL);
#endif
  {
   Node* tolua_ret = (Node*)  self->ConvertToNode(obj);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ConvertToNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ConvertToActor of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_ConvertToActor00
static int tolua_PX2_Creater_ConvertToActor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Object* obj = ((Object*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ConvertToActor'", NULL);
#endif
  {
   Actor* tolua_ret = (Actor*)  self->ConvertToActor(obj);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Actor");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ConvertToActor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ConvertToUIPicBox of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_ConvertToUIPicBox00
static int tolua_PX2_Creater_ConvertToUIPicBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Object* obj = ((Object*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ConvertToUIPicBox'", NULL);
#endif
  {
   UIPicBox* tolua_ret = (UIPicBox*)  self->ConvertToUIPicBox(obj);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIPicBox");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ConvertToUIPicBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ConvertToUIFrame of class  Creater */
#ifndef TOLUA_DISABLE_tolua_PX2_Creater_ConvertToUIFrame00
static int tolua_PX2_Creater_ConvertToUIFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Creater",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Creater* self = (Creater*)  tolua_tousertype(tolua_S,1,0);
  Object* obj = ((Object*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ConvertToUIFrame'", NULL);
#endif
  {
   UIFrame* tolua_ret = (UIFrame*)  self->ConvertToUIFrame(obj);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIFrame");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ConvertToUIFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Scene */
#ifndef TOLUA_DISABLE_tolua_PX2_Scene_new00
static int tolua_PX2_Scene_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Scene* tolua_ret = (Scene*)  Mtolua_new((Scene)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Scene");
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

/* method: new_local of class  Scene */
#ifndef TOLUA_DISABLE_tolua_PX2_Scene_new00_local
static int tolua_PX2_Scene_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Scene* tolua_ret = (Scene*)  Mtolua_new((Scene)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Scene");
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

/* method: delete of class  Scene */
#ifndef TOLUA_DISABLE_tolua_PX2_Scene_delete00
static int tolua_PX2_Scene_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetUseCameraActor of class  Scene */
#ifndef TOLUA_DISABLE_tolua_PX2_Scene_SetUseCameraActor00
static int tolua_PX2_Scene_SetUseCameraActor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CameraActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
  CameraActor* cameraActor = ((CameraActor*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUseCameraActor'", NULL);
#endif
  {
   self->SetUseCameraActor(cameraActor);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUseCameraActor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUseCameraActor of class  Scene */
#ifndef TOLUA_DISABLE_tolua_PX2_Scene_GetUseCameraActor00
static int tolua_PX2_Scene_GetUseCameraActor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUseCameraActor'", NULL);
#endif
  {
   CameraActor* tolua_ret = (CameraActor*)  self->GetUseCameraActor();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CameraActor");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUseCameraActor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AttachChild of class  Scene */
#ifndef TOLUA_DISABLE_tolua_PX2_Scene_AttachChild00
static int tolua_PX2_Scene_AttachChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Scene",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Movable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Scene* self = (Scene*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_new00
static int tolua_PX2_Actor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Actor* tolua_ret = (Actor*)  Mtolua_new((Actor)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Actor");
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

/* method: new_local of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_new00_local
static int tolua_PX2_Actor_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Actor* tolua_ret = (Actor*)  Mtolua_new((Actor)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Actor");
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

/* method: delete of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_delete00
static int tolua_PX2_Actor_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetTypeID of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_SetTypeID00
static int tolua_PX2_Actor_SetTypeID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
  int typeID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTypeID'", NULL);
#endif
  {
   self->SetTypeID(typeID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTypeID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTypeID of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_GetTypeID00
static int tolua_PX2_Actor_GetTypeID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Actor* self = (const Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTypeID'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetTypeID();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTypeID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetGroup of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_SetGroup00
static int tolua_PX2_Actor_SetGroup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
  int group = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetGroup'", NULL);
#endif
  {
   self->SetGroup(group);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetGroup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGroup of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_GetGroup00
static int tolua_PX2_Actor_GetGroup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Actor* self = (const Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGroup'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetGroup();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGroup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBitSet of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_GetBitSet00
static int tolua_PX2_Actor_GetBitSet00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBitSet'", NULL);
#endif
  {
   std::bitset<PX2_ACTOR_BS_SIZE>& tolua_ret = (std::bitset<PX2_ACTOR_BS_SIZE>&)  self->GetBitSet();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"std::bitset<PX2_ACTOR_BS_SIZE>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBitSet'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBitSet of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_GetBitSet01
static int tolua_PX2_Actor_GetBitSet01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Actor* self = (const Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBitSet'", NULL);
#endif
  {
   const std::bitset<PX2_ACTOR_BS_SIZE>& tolua_ret = (const std::bitset<PX2_ACTOR_BS_SIZE>&)  self->GetBitSet();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const std::bitset<PX2_ACTOR_BS_SIZE>");
  }
 }
 return 1;
tolua_lerror:
 return tolua_PX2_Actor_GetBitSet00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsContainAllBits of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_IsContainAllBits00
static int tolua_PX2_Actor_IsContainAllBits00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Actor",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const std::bitset<PX2_ACTOR_BS_SIZE>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Actor* self = (const Actor*)  tolua_tousertype(tolua_S,1,0);
  const std::bitset<PX2_ACTOR_BS_SIZE>* bits = ((const std::bitset<PX2_ACTOR_BS_SIZE>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsContainAllBits'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsContainAllBits(*bits);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsContainAllBits'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMovableFilename of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_SetMovableFilename00
static int tolua_PX2_Actor_SetMovableFilename00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
  const std::string filename = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  bool shareVI = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMovableFilename'", NULL);
#endif
  {
   self->SetMovableFilename(filename,shareVI);
   tolua_pushcppstring(tolua_S,(const char*)filename);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMovableFilename'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMovableFilename of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_GetMovableFilename00
static int tolua_PX2_Actor_GetMovableFilename00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Actor* self = (const Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMovableFilename'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->GetMovableFilename();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMovableFilename'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsShareVI of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_IsShareVI00
static int tolua_PX2_Actor_IsShareVI00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Actor* self = (const Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsShareVI'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsShareVI();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsShareVI'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMovable of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_SetMovable00
static int tolua_PX2_Actor_SetMovable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Movable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
  Movable* mov = ((Movable*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMovable'", NULL);
#endif
  {
   self->SetMovable(mov);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMovable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMovable of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_GetMovable00
static int tolua_PX2_Actor_GetMovable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMovable'", NULL);
#endif
  {
   Movable* tolua_ret = (Movable*)  self->GetMovable();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Movable");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMovable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateHelpNode of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_CreateHelpNode00
static int tolua_PX2_Actor_CreateHelpNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateHelpNode'", NULL);
#endif
  {
   Node* tolua_ret = (Node*)  self->CreateHelpNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateHelpNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNodeHelp of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_GetNodeHelp00
static int tolua_PX2_Actor_GetNodeHelp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNodeHelp'", NULL);
#endif
  {
   Node* tolua_ret = (Node*)  self->GetNodeHelp();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNodeHelp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPickable of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_SetPickable00
static int tolua_PX2_Actor_SetPickable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
  bool isPickable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPickable'", NULL);
#endif
  {
   self->SetPickable(isPickable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPickable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsPickable of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_IsPickable00
static int tolua_PX2_Actor_IsPickable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Actor* self = (const Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsPickable'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsPickable();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsPickable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFace of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_SetFace00
static int tolua_PX2_Actor_SetFace00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
  const AVector* dir = ((const AVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFace'", NULL);
#endif
  {
   self->SetFace(*dir);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFace'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFace of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_SetFace01
static int tolua_PX2_Actor_SetFace01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AVector",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
  const AVector* dir = ((const AVector*)  tolua_tousertype(tolua_S,2,0));
  const AVector* uping = ((const AVector*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFace'", NULL);
#endif
  {
   self->SetFace(*dir,*uping);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_Actor_SetFace00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFace of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_GetFace00
static int tolua_PX2_Actor_GetFace00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFace'", NULL);
#endif
  {
   AVector tolua_ret = (AVector)  self->GetFace();
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
 tolua_error(tolua_S,"#ferror in function 'GetFace'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRDUVector of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_GetRDUVector00
static int tolua_PX2_Actor_GetRDUVector00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AVector",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"AVector",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
  AVector* r = ((AVector*)  tolua_tousertype(tolua_S,2,0));
  AVector* d = ((AVector*)  tolua_tousertype(tolua_S,3,0));
  AVector* u = ((AVector*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRDUVector'", NULL);
#endif
  {
   self->GetRDUVector(*r,*d,*u);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRDUVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHeading of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_SetHeading00
static int tolua_PX2_Actor_SetHeading00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AVector",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
  const AVector* heading = ((const AVector*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHeading'", NULL);
#endif
  {
   self->SetHeading(*heading);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHeading'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHeading of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_GetHeading00
static int tolua_PX2_Actor_GetHeading00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Actor* self = (const Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHeading'", NULL);
#endif
  {
   const AVector& tolua_ret = (const AVector&)  self->GetHeading();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const AVector");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHeading'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CollectAnchors of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_CollectAnchors00
static int tolua_PX2_Actor_CollectAnchors00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CollectAnchors'", NULL);
#endif
  {
   self->CollectAnchors();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CollectAnchors'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAnchorPos of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_GetAnchorPos00
static int tolua_PX2_Actor_GetAnchorPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
  int id = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAnchorPos'", NULL);
#endif
  {
   APoint tolua_ret = (APoint)  self->GetAnchorPos(id);
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
 tolua_error(tolua_S,"#ferror in function 'GetAnchorPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAnchor of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_GetAnchor00
static int tolua_PX2_Actor_GetAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
  int id = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAnchor'", NULL);
#endif
  {
   Node* tolua_ret = (Node*)  self->GetAnchor(id);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRadius of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_SetRadius00
static int tolua_PX2_Actor_SetRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
  float radius = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRadius'", NULL);
#endif
  {
   self->SetRadius(radius);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRadius of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_GetRadius00
static int tolua_PX2_Actor_GetRadius00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Actor* self = (const Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRadius'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetRadius();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRadius'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHegiht of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_SetHegiht00
static int tolua_PX2_Actor_SetHegiht00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
  float height = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHegiht'", NULL);
#endif
  {
   self->SetHegiht(height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHegiht'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHeight of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_GetHeight00
static int tolua_PX2_Actor_GetHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Actor* self = (const Actor*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetSceneContainer of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_GetSceneContainer00
static int tolua_PX2_Actor_GetSceneContainer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Actor* self = (const Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSceneContainer'", NULL);
#endif
  {
   void* tolua_ret = (void*)  self->GetSceneContainer();
   tolua_pushuserdata(tolua_S,(void*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSceneContainer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSceneContainerIndex of class  Actor */
#ifndef TOLUA_DISABLE_tolua_PX2_Actor_GetSceneContainerIndex00
static int tolua_PX2_Actor_GetSceneContainerIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Actor* self = (const Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSceneContainerIndex'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetSceneContainerIndex();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSceneContainerIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CameraActor */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraActor_new00
static int tolua_PX2_CameraActor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CameraActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CameraActor* tolua_ret = (CameraActor*)  Mtolua_new((CameraActor)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CameraActor");
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

/* method: new_local of class  CameraActor */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraActor_new00_local
static int tolua_PX2_CameraActor_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CameraActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CameraActor* tolua_ret = (CameraActor*)  Mtolua_new((CameraActor)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CameraActor");
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

/* method: delete of class  CameraActor */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraActor_delete00
static int tolua_PX2_CameraActor_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CameraActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CameraActor* self = (CameraActor*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetFOV of class  CameraActor */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraActor_SetFOV00
static int tolua_PX2_CameraActor_SetFOV00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CameraActor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CameraActor* self = (CameraActor*)  tolua_tousertype(tolua_S,1,0);
  float fov = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFOV'", NULL);
#endif
  {
   self->SetFOV(fov);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFOV'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFOV of class  CameraActor */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraActor_GetFOV00
static int tolua_PX2_CameraActor_GetFOV00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CameraActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CameraActor* self = (const CameraActor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFOV'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetFOV();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFOV'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LookAt of class  CameraActor */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraActor_LookAt00
static int tolua_PX2_CameraActor_LookAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CameraActor",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const APoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CameraActor* self = (CameraActor*)  tolua_tousertype(tolua_S,1,0);
  const APoint* pos = ((const APoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LookAt'", NULL);
#endif
  {
   self->LookAt(*pos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LookAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LookAt of class  CameraActor */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraActor_LookAt01
static int tolua_PX2_CameraActor_LookAt01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CameraActor",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Movable",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CameraActor* self = (CameraActor*)  tolua_tousertype(tolua_S,1,0);
  const Movable* mov = ((const Movable*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LookAt'", NULL);
#endif
  {
   self->LookAt(mov);
  }
 }
 return 0;
tolua_lerror:
 return tolua_PX2_CameraActor_LookAt00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCamera of class  CameraActor */
#ifndef TOLUA_DISABLE_tolua_PX2_CameraActor_GetCamera00
static int tolua_PX2_CameraActor_GetCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CameraActor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CameraActor* self = (CameraActor*)  tolua_tousertype(tolua_S,1,0);
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

/* Open function */
TOLUA_API int tolua_PX2_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Rtti","Rtti","",tolua_collect_Rtti);
  #else
  tolua_cclass(tolua_S,"Rtti","Rtti","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Rtti");
   tolua_function(tolua_S,"new",tolua_PX2_Rtti_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_Rtti_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_Rtti_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_Rtti_delete00);
   tolua_function(tolua_S,"GetName",tolua_PX2_Rtti_GetName00);
   tolua_function(tolua_S,"GetVersion",tolua_PX2_Rtti_GetVersion00);
   tolua_function(tolua_S,"IsExactly",tolua_PX2_Rtti_IsExactly00);
   tolua_function(tolua_S,"IsDerived",tolua_PX2_Rtti_IsDerived00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Object","Object","",NULL);
  tolua_beginmodule(tolua_S,"Object");
   tolua_function(tolua_S,"Enable",tolua_PX2_Object_Enable00);
   tolua_function(tolua_S,"IsEnable",tolua_PX2_Object_IsEnable00);
   tolua_function(tolua_S,"GetRttiType",tolua_PX2_Object_GetRttiType00);
   tolua_function(tolua_S,"GetRttiVersion",tolua_PX2_Object_GetRttiVersion00);
   tolua_function(tolua_S,"IsExactly",tolua_PX2_Object_IsExactly00);
   tolua_function(tolua_S,"IsDerived",tolua_PX2_Object_IsDerived00);
   tolua_function(tolua_S,"IsExactlyTypeOf",tolua_PX2_Object_IsExactlyTypeOf00);
   tolua_function(tolua_S,"IsDerivedTypeOf",tolua_PX2_Object_IsDerivedTypeOf00);
   tolua_variable(tolua_S,"TYPE",tolua_get_Object_TYPE,NULL);
   tolua_function(tolua_S,"SetUserDataFloat",tolua_PX2_Object_SetUserDataFloat00);
   tolua_function(tolua_S,"GetUserDataFloat",tolua_PX2_Object_GetUserDataFloat00);
   tolua_function(tolua_S,"SetResourcePath",tolua_PX2_Object_SetResourcePath00);
   tolua_function(tolua_S,"GetResourcePath",tolua_PX2_Object_GetResourcePath00);
   tolua_variable(tolua_S,"mCurStream",tolua_get_Object_mCurStream_ptr,tolua_set_Object_mCurStream_ptr);
   tolua_function(tolua_S,"SetName",tolua_PX2_Object_SetName00);
   tolua_function(tolua_S,"GetName",tolua_PX2_Object_GetName00);
   tolua_function(tolua_S,"GetObjectByName",tolua_PX2_Object_GetObjectByName00);
   tolua_function(tolua_S,"GetAllObjectsByName",tolua_PX2_Object_GetAllObjectsByName00);
   tolua_function(tolua_S,"SetID",tolua_PX2_Object_SetID00);
   tolua_function(tolua_S,"GetID",tolua_PX2_Object_GetID00);
   tolua_function(tolua_S,"GetObjectByID",tolua_PX2_Object_GetObjectByID00);
   tolua_function(tolua_S,"GetAllObjectsByID",tolua_PX2_Object_GetAllObjectsByID00);
   tolua_function(tolua_S,"ComeInEventWorld",tolua_PX2_Object_ComeInEventWorld00);
   tolua_function(tolua_S,"GoOutEventWorld",tolua_PX2_Object_GoOutEventWorld00);
   tolua_function(tolua_S,"IsInEventWorld",tolua_PX2_Object_IsInEventWorld00);
   tolua_function(tolua_S,"GetEventHandler",tolua_PX2_Object_GetEventHandler00);
   tolua_function(tolua_S,"DoExecute",tolua_PX2_Object_DoExecute00);
   tolua_function(tolua_S,"SetUserScriptName",tolua_PX2_Object_SetUserScriptName00);
   tolua_function(tolua_S,"GetUserScriptName",tolua_PX2_Object_GetUserScriptName00);
   tolua_function(tolua_S,"GetScriptName",tolua_PX2_Object_GetScriptName00);
   tolua_function(tolua_S,"RegistToScriptSystem",tolua_PX2_Object_RegistToScriptSystem00);
   tolua_function(tolua_S,"UnRegistToScriptSystem",tolua_PX2_Object_UnRegistToScriptSystem00);
   tolua_function(tolua_S,"IsRegistedToScriptSystem",tolua_PX2_Object_IsRegistedToScriptSystem00);
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
   tolua_function(tolua_S,"Load",tolua_PX2_LanguageManager_Load00);
   tolua_function(tolua_S,"Add",tolua_PX2_LanguageManager_Add00);
   tolua_function(tolua_S,"AddItem",tolua_PX2_LanguageManager_AddItem00);
   tolua_function(tolua_S,"AddItem1",tolua_PX2_LanguageManager_AddItem100);
   tolua_function(tolua_S,"SetLanguage",tolua_PX2_LanguageManager_SetLanguage00);
   tolua_function(tolua_S,"HasValue",tolua_PX2_LanguageManager_HasValue00);
   tolua_function(tolua_S,"GetValue",tolua_PX2_LanguageManager_GetValue00);
   tolua_function(tolua_S,"Clear",tolua_PX2_LanguageManager_Clear00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Effectable","Effectable","TriMesh",tolua_collect_Effectable);
  #else
  tolua_cclass(tolua_S,"Effectable","Effectable","TriMesh",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Effectable");
   tolua_function(tolua_S,"delete",tolua_PX2_Effectable_delete00);
   tolua_function(tolua_S,"Update",tolua_PX2_Effectable_Update00);
   tolua_function(tolua_S,"GetEffectableController",tolua_PX2_Effectable_GetEffectableController00);
   tolua_function(tolua_S,"SetFixedBound",tolua_PX2_Effectable_SetFixedBound00);
   tolua_function(tolua_S,"IsFixedBound",tolua_PX2_Effectable_IsFixedBound00);
   tolua_function(tolua_S,"SetFixedBoundCenter",tolua_PX2_Effectable_SetFixedBoundCenter00);
   tolua_function(tolua_S,"GetFixedBoundCenter",tolua_PX2_Effectable_GetFixedBoundCenter00);
   tolua_function(tolua_S,"SetFixedBoundRadius",tolua_PX2_Effectable_SetFixedBoundRadius00);
   tolua_function(tolua_S,"GetFixedBoundRadius",tolua_PX2_Effectable_GetFixedBoundRadius00);
   tolua_function(tolua_S,"SetLocal",tolua_PX2_Effectable_SetLocal00);
   tolua_function(tolua_S,"IsLocal",tolua_PX2_Effectable_IsLocal00);
   tolua_function(tolua_S,"SetEmitSizeX",tolua_PX2_Effectable_SetEmitSizeX00);
   tolua_function(tolua_S,"GetEmitSizeX",tolua_PX2_Effectable_GetEmitSizeX00);
   tolua_function(tolua_S,"SetEmitSizeY",tolua_PX2_Effectable_SetEmitSizeY00);
   tolua_function(tolua_S,"GetEmitSizeY",tolua_PX2_Effectable_GetEmitSizeY00);
   tolua_function(tolua_S,"SetEmitSizeZ",tolua_PX2_Effectable_SetEmitSizeZ00);
   tolua_function(tolua_S,"GetEmitSizeZ",tolua_PX2_Effectable_GetEmitSizeZ00);
   tolua_function(tolua_S,"SetEmitSizeXYZ",tolua_PX2_Effectable_SetEmitSizeXYZ00);
   tolua_function(tolua_S,"SetEmitColor",tolua_PX2_Effectable_SetEmitColor00);
   tolua_function(tolua_S,"GetEmitColor",tolua_PX2_Effectable_GetEmitColor00);
   tolua_function(tolua_S,"SetEmitAlpha",tolua_PX2_Effectable_SetEmitAlpha00);
   tolua_function(tolua_S,"GetEmitAlpha",tolua_PX2_Effectable_GetEmitAlpha00);
   tolua_function(tolua_S,"SetEmitLife",tolua_PX2_Effectable_SetEmitLife00);
   tolua_function(tolua_S,"GetEmitLife",tolua_PX2_Effectable_GetEmitLife00);
   tolua_constant(tolua_S,"FT_X",Effectable::FT_X);
   tolua_constant(tolua_S,"FT_NX",Effectable::FT_NX);
   tolua_constant(tolua_S,"FT_Y",Effectable::FT_Y);
   tolua_constant(tolua_S,"FT_NY",Effectable::FT_NY);
   tolua_constant(tolua_S,"FT_Z",Effectable::FT_Z);
   tolua_constant(tolua_S,"FT_NZ",Effectable::FT_NZ);
   tolua_constant(tolua_S,"FT_CAMERA",Effectable::FT_CAMERA);
   tolua_constant(tolua_S,"FT_SPEEDDIR",Effectable::FT_SPEEDDIR);
   tolua_constant(tolua_S,"FT_FREE",Effectable::FT_FREE);
   tolua_constant(tolua_S,"FT_CAMERA_ZUP",Effectable::FT_CAMERA_ZUP);
   tolua_constant(tolua_S,"FT_CAMERA_ALIGN_EMITDIR",Effectable::FT_CAMERA_ALIGN_EMITDIR);
   tolua_constant(tolua_S,"FT_MAX_TYPE",Effectable::FT_MAX_TYPE);
   tolua_function(tolua_S,"SetFaceType",tolua_PX2_Effectable_SetFaceType00);
   tolua_function(tolua_S,"GetFaceType",tolua_PX2_Effectable_GetFaceType00);
   tolua_constant(tolua_S,"MT_TEX",Effectable::MT_TEX);
   tolua_constant(tolua_S,"MT_TEX_MASK_MULTIPLY",Effectable::MT_TEX_MASK_MULTIPLY);
   tolua_constant(tolua_S,"MT_TEX_MASK_ADD",Effectable::MT_TEX_MASK_ADD);
   tolua_constant(tolua_S,"MT_MAX_TYPE",Effectable::MT_MAX_TYPE);
   tolua_function(tolua_S,"SetMaterialType",tolua_PX2_Effectable_SetMaterialType00);
   tolua_function(tolua_S,"GetMaterialType",tolua_PX2_Effectable_GetMaterialType00);
   tolua_function(tolua_S,"SetBackCull",tolua_PX2_Effectable_SetBackCull00);
   tolua_function(tolua_S,"IsBackCull",tolua_PX2_Effectable_IsBackCull00);
   tolua_constant(tolua_S,"BM_NONE",Effectable::BM_NONE);
   tolua_constant(tolua_S,"BM_ALPHATEST85",Effectable::BM_ALPHATEST85);
   tolua_constant(tolua_S,"BM_BLEND_SCRCALPHA_DSTONEMIUSSRCALPHA",Effectable::BM_BLEND_SCRCALPHA_DSTONEMIUSSRCALPHA);
   tolua_constant(tolua_S,"BM_BLEND_SRCALPHA_DSTONE",Effectable::BM_BLEND_SRCALPHA_DSTONE);
   tolua_constant(tolua_S,"BM_BLEND_SRCCOLOR_DSTONEMIUSSRCCOLOR",Effectable::BM_BLEND_SRCCOLOR_DSTONEMIUSSRCCOLOR);
   tolua_constant(tolua_S,"BM_BLEND_SRCCOLOR_DSTONE",Effectable::BM_BLEND_SRCCOLOR_DSTONE);
   tolua_constant(tolua_S,"BM_BLEND_SRCONE_DSTONE",Effectable::BM_BLEND_SRCONE_DSTONE);
   tolua_constant(tolua_S,"BM_BLEND_SRCONE_DSTONEMIUSSRCALPHA",Effectable::BM_BLEND_SRCONE_DSTONEMIUSSRCALPHA);
   tolua_constant(tolua_S,"BM_BLEND_SRCONE_DSTONEMIUSSRCCOLOR",Effectable::BM_BLEND_SRCONE_DSTONEMIUSSRCCOLOR);
   tolua_constant(tolua_S,"BM_MAX_MODE",Effectable::BM_MAX_MODE);
   tolua_function(tolua_S,"SetBlendMode",tolua_PX2_Effectable_SetBlendMode00);
   tolua_function(tolua_S,"GetBlendMode",tolua_PX2_Effectable_GetBlendMode00);
   tolua_constant(tolua_S,"TM_TEX",Effectable::TM_TEX);
   tolua_constant(tolua_S,"TM_TEXPACK_ELE",Effectable::TM_TEXPACK_ELE);
   tolua_constant(tolua_S,"TM_TEX_ANIM",Effectable::TM_TEX_ANIM);
   tolua_constant(tolua_S,"TM_TEXS_ANIM",Effectable::TM_TEXS_ANIM);
   tolua_constant(tolua_S,"TM_TEXPACK_ANIM",Effectable::TM_TEXPACK_ANIM);
   tolua_constant(tolua_S,"TM_MAX_MODE",Effectable::TM_MAX_MODE);
   tolua_function(tolua_S,"SetTexMode",tolua_PX2_Effectable_SetTexMode00);
   tolua_function(tolua_S,"GetTexMode",tolua_PX2_Effectable_GetTexMode00);
   tolua_function(tolua_S,"SetTex",tolua_PX2_Effectable_SetTex00);
   tolua_function(tolua_S,"GetTex",tolua_PX2_Effectable_GetTex00);
   tolua_function(tolua_S,"SetTexPack_Ele",tolua_PX2_Effectable_SetTexPack_Ele00);
   tolua_function(tolua_S,"GetTexPack_Ele",tolua_PX2_Effectable_GetTexPack_Ele00);
   tolua_function(tolua_S,"SetTexAnim",tolua_PX2_Effectable_SetTexAnim00);
   tolua_function(tolua_S,"GetTexAnim",tolua_PX2_Effectable_GetTexAnim00);
   tolua_function(tolua_S,"SetTexAnim_Repeat",tolua_PX2_Effectable_SetTexAnim_Repeat00);
   tolua_function(tolua_S,"GetTexAnim_Repeat",tolua_PX2_Effectable_GetTexAnim_Repeat00);
   tolua_function(tolua_S,"AddTexsAnim_Frame",tolua_PX2_Effectable_AddTexsAnim_Frame00);
   tolua_function(tolua_S,"SetTexPackAnim",tolua_PX2_Effectable_SetTexPackAnim00);
   tolua_function(tolua_S,"GetTexPackAnim",tolua_PX2_Effectable_GetTexPackAnim00);
   tolua_function(tolua_S,"AddTexPackAnim_Frame",tolua_PX2_Effectable_AddTexPackAnim_Frame00);
   tolua_function(tolua_S,"GetNumTexAnimTexPackAnimFrames",tolua_PX2_Effectable_GetNumTexAnimTexPackAnimFrames00);
   tolua_function(tolua_S,"ClearTexAnimTexPackAnimFrames",tolua_PX2_Effectable_ClearTexAnimTexPackAnimFrames00);
   tolua_function(tolua_S,"SetAnimInterval",tolua_PX2_Effectable_SetAnimInterval00);
   tolua_function(tolua_S,"GetAnimInterval",tolua_PX2_Effectable_GetAnimInterval00);
   tolua_function(tolua_S,"SetAnimStartDoRandom",tolua_PX2_Effectable_SetAnimStartDoRandom00);
   tolua_function(tolua_S,"IsAnimStartDoRandom",tolua_PX2_Effectable_IsAnimStartDoRandom00);
   tolua_function(tolua_S,"SetUserNumAnimFrames",tolua_PX2_Effectable_SetUserNumAnimFrames00);
   tolua_function(tolua_S,"GetUserNumAnimFrames",tolua_PX2_Effectable_GetUserNumAnimFrames00);
   tolua_function(tolua_S,"GetNumAnimFrames",tolua_PX2_Effectable_GetNumAnimFrames00);
   tolua_function(tolua_S,"SetAnimFramesPlayOnce",tolua_PX2_Effectable_SetAnimFramesPlayOnce00);
   tolua_function(tolua_S,"IsAnimFramesPlayOnce",tolua_PX2_Effectable_IsAnimFramesPlayOnce00);
   tolua_function(tolua_S,"SetMaskTex",tolua_PX2_Effectable_SetMaskTex00);
   tolua_function(tolua_S,"GetMaskTex",tolua_PX2_Effectable_GetMaskTex00);
   tolua_function(tolua_S,"SetEmitUV0_Offset",tolua_PX2_Effectable_SetEmitUV0_Offset00);
   tolua_function(tolua_S,"GetEmitUV0_Offset",tolua_PX2_Effectable_GetEmitUV0_Offset00);
   tolua_function(tolua_S,"SetEmitUV0_Speed",tolua_PX2_Effectable_SetEmitUV0_Speed00);
   tolua_function(tolua_S,"GetEmitUV0_Speed",tolua_PX2_Effectable_GetEmitUV0_Speed00);
   tolua_function(tolua_S,"SetEmitUV0_Repeat",tolua_PX2_Effectable_SetEmitUV0_Repeat00);
   tolua_function(tolua_S,"GetEmitUV0_Repeat",tolua_PX2_Effectable_GetEmitUV0_Repeat00);
   tolua_function(tolua_S,"SetUV1_Offset",tolua_PX2_Effectable_SetUV1_Offset00);
   tolua_function(tolua_S,"GetUV1_Offset",tolua_PX2_Effectable_GetUV1_Offset00);
   tolua_function(tolua_S,"SetUV1_Repeat",tolua_PX2_Effectable_SetUV1_Repeat00);
   tolua_function(tolua_S,"GetUV1_Repeat",tolua_PX2_Effectable_GetUV1_Repeat00);
   tolua_function(tolua_S,"SetUV1_Speed",tolua_PX2_Effectable_SetUV1_Speed00);
   tolua_function(tolua_S,"GetUV1_Speed",tolua_PX2_Effectable_GetUV1_Speed00);
   tolua_constant(tolua_S,"CT_CLAMP",Effectable::CT_CLAMP);
   tolua_constant(tolua_S,"CT_REPEAT",Effectable::CT_REPEAT);
   tolua_constant(tolua_S,"CT_MAX_TYPE",Effectable::CT_MAX_TYPE);
   tolua_function(tolua_S,"SetCoordinateType0",tolua_PX2_Effectable_SetCoordinateType000);
   tolua_function(tolua_S,"GetCoordinateType0",tolua_PX2_Effectable_GetCoordinateType000);
   tolua_function(tolua_S,"SetCoordinateType1",tolua_PX2_Effectable_SetCoordinateType100);
   tolua_function(tolua_S,"GetCoordinateType1",tolua_PX2_Effectable_GetCoordinateType100);
   tolua_function(tolua_S,"GetAllModuleNames_EA",tolua_PX2_Effectable_GetAllModuleNames_EA00);
   tolua_function(tolua_S,"GetAllModuleNames_EO",tolua_PX2_Effectable_GetAllModuleNames_EO00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"BeamEmitter","BeamEmitter","Effectable",tolua_collect_BeamEmitter);
  #else
  tolua_cclass(tolua_S,"BeamEmitter","BeamEmitter","Effectable",NULL);
  #endif
  tolua_beginmodule(tolua_S,"BeamEmitter");
   tolua_function(tolua_S,"new",tolua_PX2_BeamEmitter_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_BeamEmitter_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_BeamEmitter_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_BeamEmitter_delete00);
   tolua_function(tolua_S,"SetNumMaxBeams",tolua_PX2_BeamEmitter_SetNumMaxBeams00);
   tolua_function(tolua_S,"GetNumMaxBeams",tolua_PX2_BeamEmitter_GetNumMaxBeams00);
   tolua_function(tolua_S,"SetEmitRate",tolua_PX2_BeamEmitter_SetEmitRate00);
   tolua_function(tolua_S,"GetEmitRate",tolua_PX2_BeamEmitter_GetEmitRate00);
   tolua_function(tolua_S,"SetEmitStartPos",tolua_PX2_BeamEmitter_SetEmitStartPos00);
   tolua_function(tolua_S,"GetEmitStartPos",tolua_PX2_BeamEmitter_GetEmitStartPos00);
   tolua_function(tolua_S,"SetEmitEndPos",tolua_PX2_BeamEmitter_SetEmitEndPos00);
   tolua_function(tolua_S,"GetEmitEndPos",tolua_PX2_BeamEmitter_GetEmitEndPos00);
   tolua_function(tolua_S,"SetStartPosUseLocal",tolua_PX2_BeamEmitter_SetStartPosUseLocal00);
   tolua_function(tolua_S,"IsStartPosUseLocal",tolua_PX2_BeamEmitter_IsStartPosUseLocal00);
   tolua_function(tolua_S,"SetSimpleLineWave",tolua_PX2_BeamEmitter_SetSimpleLineWave00);
   tolua_function(tolua_S,"IsSimpleLineWave",tolua_PX2_BeamEmitter_IsSimpleLineWave00);
   tolua_function(tolua_S,"SetSimpleLineDoAlphaDisAfterStopSpeed",tolua_PX2_BeamEmitter_SetSimpleLineDoAlphaDisAfterStopSpeed00);
   tolua_function(tolua_S,"GetSimpleLineDoAlphaDisAfterStopSpeed",tolua_PX2_BeamEmitter_GetSimpleLineDoAlphaDisAfterStopSpeed00);
   tolua_constant(tolua_S,"WT_RANDOM",BeamEmitter::WT_RANDOM);
   tolua_constant(tolua_S,"WT_SIN",BeamEmitter::WT_SIN);
   tolua_constant(tolua_S,"WT_LINE",BeamEmitter::WT_LINE);
   tolua_constant(tolua_S,"WT_MAX_TYPE",BeamEmitter::WT_MAX_TYPE);
   tolua_function(tolua_S,"SetWaveTypeUp",tolua_PX2_BeamEmitter_SetWaveTypeUp00);
   tolua_function(tolua_S,"GetWaveTypeUp",tolua_PX2_BeamEmitter_GetWaveTypeUp00);
   tolua_function(tolua_S,"SetWaveTypeExtend",tolua_PX2_BeamEmitter_SetWaveTypeExtend00);
   tolua_function(tolua_S,"GetWaveTypeExtend",tolua_PX2_BeamEmitter_GetWaveTypeExtend00);
   tolua_function(tolua_S,"SetNumLowFrequency",tolua_PX2_BeamEmitter_SetNumLowFrequency00);
   tolua_function(tolua_S,"GetNumLowFrequency",tolua_PX2_BeamEmitter_GetNumLowFrequency00);
   tolua_function(tolua_S,"SetNumHighFrequency",tolua_PX2_BeamEmitter_SetNumHighFrequency00);
   tolua_function(tolua_S,"GetNumHighFrequency",tolua_PX2_BeamEmitter_GetNumHighFrequency00);
   tolua_function(tolua_S,"SetLowFrequencyRangeUp",tolua_PX2_BeamEmitter_SetLowFrequencyRangeUp00);
   tolua_function(tolua_S,"SetLowFrequencyRangeExtend",tolua_PX2_BeamEmitter_SetLowFrequencyRangeExtend00);
   tolua_function(tolua_S,"GetLowFrequencyRangeUp",tolua_PX2_BeamEmitter_GetLowFrequencyRangeUp00);
   tolua_function(tolua_S,"GetLowFrequencyRangeExtend",tolua_PX2_BeamEmitter_GetLowFrequencyRangeExtend00);
   tolua_function(tolua_S,"SetHighFrequencyRangeUp",tolua_PX2_BeamEmitter_SetHighFrequencyRangeUp00);
   tolua_function(tolua_S,"SetHighFrequencyRangeExtend",tolua_PX2_BeamEmitter_SetHighFrequencyRangeExtend00);
   tolua_function(tolua_S,"GetHighFrequencyRangeUp",tolua_PX2_BeamEmitter_GetHighFrequencyRangeUp00);
   tolua_function(tolua_S,"GetHighFrequencyRangeExtend",tolua_PX2_BeamEmitter_GetHighFrequencyRangeExtend00);
   tolua_function(tolua_S,"GetAllModuleNames_EA",tolua_PX2_BeamEmitter_GetAllModuleNames_EA00);
   tolua_function(tolua_S,"GetAllModuleNames_EO",tolua_PX2_BeamEmitter_GetAllModuleNames_EO00);
   tolua_variable(tolua_S,"msModuleNames_EA",tolua_get_BeamEmitter_msModuleNames_EA,tolua_set_BeamEmitter_msModuleNames_EA);
   tolua_variable(tolua_S,"msModuleNames_EO",tolua_get_BeamEmitter_msModuleNames_EO,tolua_set_BeamEmitter_msModuleNames_EO);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Billboard","Billboard","Effectable",tolua_collect_Billboard);
  #else
  tolua_cclass(tolua_S,"Billboard","Billboard","Effectable",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Billboard");
   tolua_function(tolua_S,"new",tolua_PX2_Billboard_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_Billboard_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_Billboard_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_Billboard_delete00);
   tolua_function(tolua_S,"SetDynamic",tolua_PX2_Billboard_SetDynamic00);
   tolua_function(tolua_S,"IsDynamic",tolua_PX2_Billboard_IsDynamic00);
   tolua_function(tolua_S,"SetAnchorPoint",tolua_PX2_Billboard_SetAnchorPoint00);
   tolua_function(tolua_S,"SetAnchorPoint",tolua_PX2_Billboard_SetAnchorPoint01);
   tolua_function(tolua_S,"GetAnchorPoint",tolua_PX2_Billboard_GetAnchorPoint00);
   tolua_function(tolua_S,"SetUseTexAsSize",tolua_PX2_Billboard_SetUseTexAsSize00);
   tolua_function(tolua_S,"IsUseTexAsSize",tolua_PX2_Billboard_IsUseTexAsSize00);
   tolua_function(tolua_S,"SetUseTrim",tolua_PX2_Billboard_SetUseTrim00);
   tolua_function(tolua_S,"IsUseTrim",tolua_PX2_Billboard_IsUseTrim00);
   tolua_function(tolua_S,"SetDoAlphaDisAfterStop",tolua_PX2_Billboard_SetDoAlphaDisAfterStop00);
   tolua_function(tolua_S,"IsDoAlphaDisAfterStop",tolua_PX2_Billboard_IsDoAlphaDisAfterStop00);
   tolua_function(tolua_S,"SetDoAlphaDisAfterStopSpeed",tolua_PX2_Billboard_SetDoAlphaDisAfterStopSpeed00);
   tolua_function(tolua_S,"GetDoAlphaDisAfterStopSpeed",tolua_PX2_Billboard_GetDoAlphaDisAfterStopSpeed00);
   tolua_function(tolua_S,"SetSizeImmediate",tolua_PX2_Billboard_SetSizeImmediate00);
   tolua_function(tolua_S,"GetAllModuleNames_EA",tolua_PX2_Billboard_GetAllModuleNames_EA00);
   tolua_function(tolua_S,"GetAllModuleNames_EO",tolua_PX2_Billboard_GetAllModuleNames_EO00);
   tolua_variable(tolua_S,"msModuleNames_EA",tolua_get_Billboard_msModuleNames_EA,tolua_set_Billboard_msModuleNames_EA);
   tolua_variable(tolua_S,"msModuleNames_EO",tolua_get_Billboard_msModuleNames_EO,tolua_set_Billboard_msModuleNames_EO);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CameraShake","CameraShake","Effectable",tolua_collect_CameraShake);
  #else
  tolua_cclass(tolua_S,"CameraShake","CameraShake","Effectable",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CameraShake");
   tolua_function(tolua_S,"new",tolua_PX2_CameraShake_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_CameraShake_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_CameraShake_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_CameraShake_delete00);
   tolua_function(tolua_S,"Play",tolua_PX2_CameraShake_Play00);
   tolua_function(tolua_S,"Stop",tolua_PX2_CameraShake_Stop00);
   tolua_function(tolua_S,"SetUseX",tolua_PX2_CameraShake_SetUseX00);
   tolua_function(tolua_S,"IsUseX",tolua_PX2_CameraShake_IsUseX00);
   tolua_function(tolua_S,"SetUseY",tolua_PX2_CameraShake_SetUseY00);
   tolua_function(tolua_S,"IsUseY",tolua_PX2_CameraShake_IsUseY00);
   tolua_function(tolua_S,"SetUseZ",tolua_PX2_CameraShake_SetUseZ00);
   tolua_function(tolua_S,"IsUseZ",tolua_PX2_CameraShake_IsUseZ00);
   tolua_function(tolua_S,"SetMaxDistance",tolua_PX2_CameraShake_SetMaxDistance00);
   tolua_function(tolua_S,"GetMaxDistance",tolua_PX2_CameraShake_GetMaxDistance00);
   tolua_function(tolua_S,"SetEmitStrength",tolua_PX2_CameraShake_SetEmitStrength00);
   tolua_function(tolua_S,"GetEmitStrength",tolua_PX2_CameraShake_GetEmitStrength00);
   tolua_function(tolua_S,"GetShakeChannel",tolua_PX2_CameraShake_GetShakeChannel00);
   tolua_function(tolua_S,"GetAllModuleNames_EA",tolua_PX2_CameraShake_GetAllModuleNames_EA00);
   tolua_function(tolua_S,"GetAllModuleNames_EO",tolua_PX2_CameraShake_GetAllModuleNames_EO00);
   tolua_function(tolua_S,"AllocChannel",tolua_PX2_CameraShake_AllocChannel00);
   tolua_function(tolua_S,"FreeChannel",tolua_PX2_CameraShake_FreeChannel00);
   tolua_function(tolua_S,"SetChannelShake",tolua_PX2_CameraShake_SetChannelShake00);
   tolua_function(tolua_S,"ShakeCamera",tolua_PX2_CameraShake_ShakeCamera00);
   tolua_constant(tolua_S,"NUMSHAKEMAXCHANNELS",CameraShake::NUMSHAKEMAXCHANNELS);
   tolua_array(tolua_S,"ShakeChannels",tolua_get_PX2_CameraShake_ShakeChannels,tolua_set_PX2_CameraShake_ShakeChannels);
   tolua_variable(tolua_S,"msModuleNames_EA",tolua_get_CameraShake_msModuleNames_EA,tolua_set_CameraShake_msModuleNames_EA);
   tolua_variable(tolua_S,"msModuleNames_EO",tolua_get_CameraShake_msModuleNames_EO,tolua_set_CameraShake_msModuleNames_EO);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"EffectModel","EffectModel","Effectable",tolua_collect_EffectModel);
  #else
  tolua_cclass(tolua_S,"EffectModel","EffectModel","Effectable",NULL);
  #endif
  tolua_beginmodule(tolua_S,"EffectModel");
   tolua_function(tolua_S,"new",tolua_PX2_EffectModel_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_EffectModel_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_EffectModel_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_EffectModel_delete00);
   tolua_function(tolua_S,"Reset",tolua_PX2_EffectModel_Reset00);
   tolua_constant(tolua_S,"MT_SPHERE",EffectModel::MT_SPHERE);
   tolua_constant(tolua_S,"MT_CYLINDEROPEN",EffectModel::MT_CYLINDEROPEN);
   tolua_constant(tolua_S,"MT_MODEL",EffectModel::MT_MODEL);
   tolua_constant(tolua_S,"MT_MAX_TYPE",EffectModel::MT_MAX_TYPE);
   tolua_function(tolua_S,"SetModelType",tolua_PX2_EffectModel_SetModelType00);
   tolua_function(tolua_S,"GetModelType",tolua_PX2_EffectModel_GetModelType00);
   tolua_function(tolua_S,"SetRadiusSample",tolua_PX2_EffectModel_SetRadiusSample00);
   tolua_function(tolua_S,"GetRadiusSample",tolua_PX2_EffectModel_GetRadiusSample00);
   tolua_function(tolua_S,"SetZSample",tolua_PX2_EffectModel_SetZSample00);
   tolua_function(tolua_S,"GetZSample",tolua_PX2_EffectModel_GetZSample00);
   tolua_constant(tolua_S,"HAT_NORMAL",EffectModel::HAT_NORMAL);
   tolua_constant(tolua_S,"HAT_H2L_APPEAR",EffectModel::HAT_H2L_APPEAR);
   tolua_constant(tolua_S,"HAT_H2L_DISAPPEAR",EffectModel::HAT_H2L_DISAPPEAR);
   tolua_constant(tolua_S,"HAT_H2L_APPEAR_DISAPPEAR",EffectModel::HAT_H2L_APPEAR_DISAPPEAR);
   tolua_constant(tolua_S,"HAT_H2L_DISAPPEAR_APPEAR",EffectModel::HAT_H2L_DISAPPEAR_APPEAR);
   tolua_constant(tolua_S,"HAT_MAX_TYPE",EffectModel::HAT_MAX_TYPE);
   tolua_function(tolua_S,"SetHeightAlphaType",tolua_PX2_EffectModel_SetHeightAlphaType00);
   tolua_function(tolua_S,"GetHeightAlphaType",tolua_PX2_EffectModel_GetHeightAlphaType00);
   tolua_function(tolua_S,"SetModelFilename",tolua_PX2_EffectModel_SetModelFilename00);
   tolua_function(tolua_S,"GetModelFilename",tolua_PX2_EffectModel_GetModelFilename00);
   tolua_function(tolua_S,"GetAllModuleNames_EA",tolua_PX2_EffectModel_GetAllModuleNames_EA00);
   tolua_function(tolua_S,"GetAllModuleNames_EO",tolua_PX2_EffectModel_GetAllModuleNames_EO00);
   tolua_variable(tolua_S,"msModuleNames_EA",tolua_get_EffectModel_msModuleNames_EA,tolua_set_EffectModel_msModuleNames_EA);
   tolua_variable(tolua_S,"msModuleNames_EO",tolua_get_EffectModel_msModuleNames_EO,tolua_set_EffectModel_msModuleNames_EO);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"EffectModelNode","EffectModelNode","Node",tolua_collect_EffectModelNode);
  #else
  tolua_cclass(tolua_S,"EffectModelNode","EffectModelNode","Node",NULL);
  #endif
  tolua_beginmodule(tolua_S,"EffectModelNode");
   tolua_function(tolua_S,"new",tolua_PX2_EffectModelNode_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_EffectModelNode_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_EffectModelNode_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_EffectModelNode_delete00);
   tolua_function(tolua_S,"SetModelFilename",tolua_PX2_EffectModelNode_SetModelFilename00);
   tolua_function(tolua_S,"GetModelFilename",tolua_PX2_EffectModelNode_GetModelFilename00);
   tolua_constant(tolua_S,"CT_CLAMP",EffectModelNode::CT_CLAMP);
   tolua_constant(tolua_S,"CT_REPEAT",EffectModelNode::CT_REPEAT);
   tolua_constant(tolua_S,"CT_MAX_TYPE",EffectModelNode::CT_MAX_TYPE);
   tolua_function(tolua_S,"SetCoordinateType0",tolua_PX2_EffectModelNode_SetCoordinateType000);
   tolua_function(tolua_S,"GetCoordinateType0",tolua_PX2_EffectModelNode_GetCoordinateType000);
   tolua_function(tolua_S,"SetCoordinateType1",tolua_PX2_EffectModelNode_SetCoordinateType100);
   tolua_function(tolua_S,"GetCoordinateType1",tolua_PX2_EffectModelNode_GetCoordinateType100);
   tolua_function(tolua_S,"SetUVSpeed",tolua_PX2_EffectModelNode_SetUVSpeed00);
   tolua_function(tolua_S,"GetUVSpeed",tolua_PX2_EffectModelNode_GetUVSpeed00);
   tolua_function(tolua_S,"SetTextureFilename",tolua_PX2_EffectModelNode_SetTextureFilename00);
   tolua_function(tolua_S,"GetTextureFilename",tolua_PX2_EffectModelNode_GetTextureFilename00);
   tolua_function(tolua_S,"Reset",tolua_PX2_EffectModelNode_Reset00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"ParticleEmitter","ParticleEmitter","Effectable",tolua_collect_ParticleEmitter);
  #else
  tolua_cclass(tolua_S,"ParticleEmitter","ParticleEmitter","Effectable",NULL);
  #endif
  tolua_beginmodule(tolua_S,"ParticleEmitter");
   tolua_function(tolua_S,"new",tolua_PX2_ParticleEmitter_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_ParticleEmitter_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_ParticleEmitter_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_ParticleEmitter_delete00);
   tolua_function(tolua_S,"SetMaxNumParticles",tolua_PX2_ParticleEmitter_SetMaxNumParticles00);
   tolua_function(tolua_S,"GetMaxNumParticles",tolua_PX2_ParticleEmitter_GetMaxNumParticles00);
   tolua_function(tolua_S,"SetBlast",tolua_PX2_ParticleEmitter_SetBlast00);
   tolua_function(tolua_S,"IsBlast",tolua_PX2_ParticleEmitter_IsBlast00);
   tolua_constant(tolua_S,"DT_NORMAL",ParticleEmitter::DT_NORMAL);
   tolua_constant(tolua_S,"DT_MODEL",ParticleEmitter::DT_MODEL);
   tolua_constant(tolua_S,"DT_MAX_TYPE",ParticleEmitter::DT_MAX_TYPE);
   tolua_function(tolua_S,"SetDrawType",tolua_PX2_ParticleEmitter_SetDrawType00);
   tolua_function(tolua_S,"GetDrawType",tolua_PX2_ParticleEmitter_GetDrawType00);
   tolua_function(tolua_S,"SetModelFilename",tolua_PX2_ParticleEmitter_SetModelFilename00);
   tolua_function(tolua_S,"GetModelFilename",tolua_PX2_ParticleEmitter_GetModelFilename00);
   tolua_function(tolua_S,"SetAnchorPoint",tolua_PX2_ParticleEmitter_SetAnchorPoint00);
   tolua_function(tolua_S,"GetAnchorPoint",tolua_PX2_ParticleEmitter_GetAnchorPoint00);
   tolua_function(tolua_S,"SetEmitRate",tolua_PX2_ParticleEmitter_SetEmitRate00);
   tolua_function(tolua_S,"GetEmitRate",tolua_PX2_ParticleEmitter_GetEmitRate00);
   tolua_function(tolua_S,"SetEmitDirDynamic",tolua_PX2_ParticleEmitter_SetEmitDirDynamic00);
   tolua_function(tolua_S,"IsEmitDirDynamic",tolua_PX2_ParticleEmitter_IsEmitDirDynamic00);
   tolua_function(tolua_S,"SetEmitDir",tolua_PX2_ParticleEmitter_SetEmitDir00);
   tolua_function(tolua_S,"GetEmitDir",tolua_PX2_ParticleEmitter_GetEmitDir00);
   tolua_function(tolua_S,"SetEmitDirLocal",tolua_PX2_ParticleEmitter_SetEmitDirLocal00);
   tolua_function(tolua_S,"IsEmitDirLocal",tolua_PX2_ParticleEmitter_IsEmitDirLocal00);
   tolua_constant(tolua_S,"EST_NORMAL",ParticleEmitter::EST_NORMAL);
   tolua_constant(tolua_S,"EST_TOATTRACTPOINT",ParticleEmitter::EST_TOATTRACTPOINT);
   tolua_constant(tolua_S,"EST_LEVELATTRACTPOINT",ParticleEmitter::EST_LEVELATTRACTPOINT);
   tolua_constant(tolua_S,"EST_MAX_TYPE",ParticleEmitter::EST_MAX_TYPE);
   tolua_function(tolua_S,"SetEmitDirType",tolua_PX2_ParticleEmitter_SetEmitDirType00);
   tolua_function(tolua_S,"GetEmitDirType",tolua_PX2_ParticleEmitter_GetEmitDirType00);
   tolua_function(tolua_S,"SetEmitSpeed",tolua_PX2_ParticleEmitter_SetEmitSpeed00);
   tolua_function(tolua_S,"GetEmitSpeed",tolua_PX2_ParticleEmitter_GetEmitSpeed00);
   tolua_function(tolua_S,"SetEmitAccelerateDir",tolua_PX2_ParticleEmitter_SetEmitAccelerateDir00);
   tolua_function(tolua_S,"GetEmitAccelerateDir",tolua_PX2_ParticleEmitter_GetEmitAccelerateDir00);
   tolua_function(tolua_S,"SetEmitAccelerate",tolua_PX2_ParticleEmitter_SetEmitAccelerate00);
   tolua_function(tolua_S,"GetEmitAccelerate",tolua_PX2_ParticleEmitter_GetEmitAccelerate00);
   tolua_function(tolua_S,"SetEmitAttractPoint",tolua_PX2_ParticleEmitter_SetEmitAttractPoint00);
   tolua_function(tolua_S,"GetEmitAttactPoint",tolua_PX2_ParticleEmitter_GetEmitAttactPoint00);
   tolua_function(tolua_S,"SetEmitAttactStrength",tolua_PX2_ParticleEmitter_SetEmitAttactStrength00);
   tolua_function(tolua_S,"GetEmitAttackStrength",tolua_PX2_ParticleEmitter_GetEmitAttackStrength00);
   tolua_function(tolua_S,"SetObstruct",tolua_PX2_ParticleEmitter_SetObstruct00);
   tolua_function(tolua_S,"GetObstruct",tolua_PX2_ParticleEmitter_GetObstruct00);
   tolua_constant(tolua_S,"RAT_D",ParticleEmitter::RAT_D);
   tolua_constant(tolua_S,"RAT_U",ParticleEmitter::RAT_U);
   tolua_constant(tolua_S,"RAT_R",ParticleEmitter::RAT_R);
   tolua_constant(tolua_S,"RAT_FREE",ParticleEmitter::RAT_FREE);
   tolua_constant(tolua_S,"RAT_MAX_TYPE",ParticleEmitter::RAT_MAX_TYPE);
   tolua_function(tolua_S,"SetRotateAxisType",tolua_PX2_ParticleEmitter_SetRotateAxisType00);
   tolua_function(tolua_S,"GetRotateAxisType",tolua_PX2_ParticleEmitter_GetRotateAxisType00);
   tolua_function(tolua_S,"SetEmitRotateAxis",tolua_PX2_ParticleEmitter_SetEmitRotateAxis00);
   tolua_function(tolua_S,"GetEmitRotateAxis",tolua_PX2_ParticleEmitter_GetEmitRotateAxis00);
   tolua_function(tolua_S,"SetEmitRotateDegree",tolua_PX2_ParticleEmitter_SetEmitRotateDegree00);
   tolua_function(tolua_S,"GetEmitRotateDegree",tolua_PX2_ParticleEmitter_GetEmitRotateDegree00);
   tolua_function(tolua_S,"SetEmitRotateSpeed",tolua_PX2_ParticleEmitter_SetEmitRotateSpeed00);
   tolua_function(tolua_S,"GetEmitRotateSpeed",tolua_PX2_ParticleEmitter_GetEmitRotateSpeed00);
   tolua_constant(tolua_S,"CT_NONE",ParticleEmitter::CT_NONE);
   tolua_constant(tolua_S,"CT_FACE_HEIGHTUP",ParticleEmitter::CT_FACE_HEIGHTUP);
   tolua_constant(tolua_S,"CT_MAX_TYPE",ParticleEmitter::CT_MAX_TYPE);
   tolua_function(tolua_S,"SetCollisionType",tolua_PX2_ParticleEmitter_SetCollisionType00);
   tolua_function(tolua_S,"GetCollisionType",tolua_PX2_ParticleEmitter_GetCollisionType00);
   tolua_constant(tolua_S,"CO_REFLECT",ParticleEmitter::CO_REFLECT);
   tolua_constant(tolua_S,"CO_DEAD",ParticleEmitter::CO_DEAD);
   tolua_constant(tolua_S,"CO_MAX_TYPE",ParticleEmitter::CO_MAX_TYPE);
   tolua_function(tolua_S,"SetCollisionOption",tolua_PX2_ParticleEmitter_SetCollisionOption00);
   tolua_function(tolua_S,"GetCollisionOption",tolua_PX2_ParticleEmitter_GetCollisionOption00);
   tolua_function(tolua_S,"SetCollisionFaceHeight",tolua_PX2_ParticleEmitter_SetCollisionFaceHeight00);
   tolua_function(tolua_S,"GetCollisionFaceHeight",tolua_PX2_ParticleEmitter_GetCollisionFaceHeight00);
   tolua_function(tolua_S,"SetCollisionSpeedPercent",tolua_PX2_ParticleEmitter_SetCollisionSpeedPercent00);
   tolua_function(tolua_S,"GetCollisionSpeedPercent",tolua_PX2_ParticleEmitter_GetCollisionSpeedPercent00);
   tolua_constant(tolua_S,"PT_BOX",ParticleEmitter::PT_BOX);
   tolua_constant(tolua_S,"PT_SPHERE",ParticleEmitter::PT_SPHERE);
   tolua_constant(tolua_S,"PT_COLUMN",ParticleEmitter::PT_COLUMN);
   tolua_constant(tolua_S,"PT_MAX_TYPE",ParticleEmitter::PT_MAX_TYPE);
   tolua_function(tolua_S,"SetPlacerType",tolua_PX2_ParticleEmitter_SetPlacerType00);
   tolua_function(tolua_S,"GetPlacerType",tolua_PX2_ParticleEmitter_GetPlacerType00);
   tolua_function(tolua_S,"SetPlacerInLength",tolua_PX2_ParticleEmitter_SetPlacerInLength00);
   tolua_function(tolua_S,"SetPlacerOutLength",tolua_PX2_ParticleEmitter_SetPlacerOutLength00);
   tolua_function(tolua_S,"SetPlacerInWidth",tolua_PX2_ParticleEmitter_SetPlacerInWidth00);
   tolua_function(tolua_S,"SetPlacerOutWidth",tolua_PX2_ParticleEmitter_SetPlacerOutWidth00);
   tolua_function(tolua_S,"SetPlacerInHeight",tolua_PX2_ParticleEmitter_SetPlacerInHeight00);
   tolua_function(tolua_S,"SetPlacerOutHeight",tolua_PX2_ParticleEmitter_SetPlacerOutHeight00);
   tolua_function(tolua_S,"GetPlacerInLength",tolua_PX2_ParticleEmitter_GetPlacerInLength00);
   tolua_function(tolua_S,"GetPlacerOutLength",tolua_PX2_ParticleEmitter_GetPlacerOutLength00);
   tolua_function(tolua_S,"GetPlacerInWidth",tolua_PX2_ParticleEmitter_GetPlacerInWidth00);
   tolua_function(tolua_S,"GetPlacerOutWidth",tolua_PX2_ParticleEmitter_GetPlacerOutWidth00);
   tolua_function(tolua_S,"GetPlacerInHeight",tolua_PX2_ParticleEmitter_GetPlacerInHeight00);
   tolua_function(tolua_S,"GetPlacerOutHeight",tolua_PX2_ParticleEmitter_GetPlacerOutHeight00);
   tolua_function(tolua_S,"GetPlacerAPoint",tolua_PX2_ParticleEmitter_GetPlacerAPoint00);
   tolua_function(tolua_S,"GetAllModuleNames_EA",tolua_PX2_ParticleEmitter_GetAllModuleNames_EA00);
   tolua_function(tolua_S,"GetAllModuleNames_EO",tolua_PX2_ParticleEmitter_GetAllModuleNames_EO00);
   tolua_variable(tolua_S,"msModuleNames_EA",tolua_get_ParticleEmitter_msModuleNames_EA,tolua_set_ParticleEmitter_msModuleNames_EA);
   tolua_variable(tolua_S,"msModuleNames_EO",tolua_get_ParticleEmitter_msModuleNames_EO,tolua_set_ParticleEmitter_msModuleNames_EO);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"RibbonEmitter","RibbonEmitter","Effectable",tolua_collect_RibbonEmitter);
  #else
  tolua_cclass(tolua_S,"RibbonEmitter","RibbonEmitter","Effectable",NULL);
  #endif
  tolua_beginmodule(tolua_S,"RibbonEmitter");
   tolua_function(tolua_S,"new",tolua_PX2_RibbonEmitter_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_RibbonEmitter_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_RibbonEmitter_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_RibbonEmitter_delete00);
   tolua_function(tolua_S,"SetLength",tolua_PX2_RibbonEmitter_SetLength00);
   tolua_function(tolua_S,"GetLength",tolua_PX2_RibbonEmitter_GetLength00);
   tolua_function(tolua_S,"SetSegLength",tolua_PX2_RibbonEmitter_SetSegLength00);
   tolua_function(tolua_S,"GetSegLength",tolua_PX2_RibbonEmitter_GetSegLength00);
   tolua_function(tolua_S,"GetAllModuleNames_EA",tolua_PX2_RibbonEmitter_GetAllModuleNames_EA00);
   tolua_function(tolua_S,"GetAllModuleNames_EO",tolua_PX2_RibbonEmitter_GetAllModuleNames_EO00);
   tolua_variable(tolua_S,"msModuleNames_EA",tolua_get_RibbonEmitter_msModuleNames_EA,tolua_set_RibbonEmitter_msModuleNames_EA);
   tolua_variable(tolua_S,"msModuleNames_EO",tolua_get_RibbonEmitter_msModuleNames_EO,tolua_set_RibbonEmitter_msModuleNames_EO);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Soundable","Soundable","Effectable",tolua_collect_Soundable);
  #else
  tolua_cclass(tolua_S,"Soundable","Soundable","Effectable",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Soundable");
   tolua_function(tolua_S,"new",tolua_PX2_Soundable_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_Soundable_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_Soundable_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_Soundable_delete00);
   tolua_constant(tolua_S,"ST_SOUND",Soundable::ST_SOUND);
   tolua_constant(tolua_S,"ST_MUSIC",Soundable::ST_MUSIC);
   tolua_constant(tolua_S,"ST_MAX_TYPE",Soundable::ST_MAX_TYPE);
   tolua_function(tolua_S,"SetSourceType",tolua_PX2_Soundable_SetSourceType00);
   tolua_function(tolua_S,"GetSourceType",tolua_PX2_Soundable_GetSourceType00);
   tolua_function(tolua_S,"SetMusicChannel",tolua_PX2_Soundable_SetMusicChannel00);
   tolua_function(tolua_S,"GetMusicChannel",tolua_PX2_Soundable_GetMusicChannel00);
   tolua_function(tolua_S,"Reset",tolua_PX2_Soundable_Reset00);
   tolua_function(tolua_S,"Play",tolua_PX2_Soundable_Play00);
   tolua_function(tolua_S,"Stop",tolua_PX2_Soundable_Stop00);
   tolua_function(tolua_S,"SetIngoreStopSound",tolua_PX2_Soundable_SetIngoreStopSound00);
   tolua_function(tolua_S,"IsIngoreStopSound",tolua_PX2_Soundable_IsIngoreStopSound00);
   tolua_function(tolua_S,"SetSoundFilename",tolua_PX2_Soundable_SetSoundFilename00);
   tolua_function(tolua_S,"GetSoundFilename",tolua_PX2_Soundable_GetSoundFilename00);
   tolua_function(tolua_S,"Set3D",tolua_PX2_Soundable_Set3D00);
   tolua_function(tolua_S,"Is3D",tolua_PX2_Soundable_Is3D00);
   tolua_function(tolua_S,"SetVolume",tolua_PX2_Soundable_SetVolume00);
   tolua_function(tolua_S,"GetVolume",tolua_PX2_Soundable_GetVolume00);
   tolua_function(tolua_S,"SetVelocity",tolua_PX2_Soundable_SetVelocity00);
   tolua_function(tolua_S,"GetVelocity",tolua_PX2_Soundable_GetVelocity00);
   tolua_function(tolua_S,"SetDistance",tolua_PX2_Soundable_SetDistance00);
   tolua_function(tolua_S,"SetMinDistance",tolua_PX2_Soundable_SetMinDistance00);
   tolua_function(tolua_S,"SetMaxDistance",tolua_PX2_Soundable_SetMaxDistance00);
   tolua_function(tolua_S,"GetMinDistance",tolua_PX2_Soundable_GetMinDistance00);
   tolua_function(tolua_S,"GetMaxDistance",tolua_PX2_Soundable_GetMaxDistance00);
   tolua_function(tolua_S,"SetLoop",tolua_PX2_Soundable_SetLoop00);
   tolua_function(tolua_S,"IsLoop",tolua_PX2_Soundable_IsLoop00);
   tolua_function(tolua_S,"SetDistanceUseX",tolua_PX2_Soundable_SetDistanceUseX00);
   tolua_function(tolua_S,"IsDistanceUseX",tolua_PX2_Soundable_IsDistanceUseX00);
   tolua_function(tolua_S,"SetDistanceUseY",tolua_PX2_Soundable_SetDistanceUseY00);
   tolua_function(tolua_S,"IsDistanceUseY",tolua_PX2_Soundable_IsDistanceUseY00);
   tolua_function(tolua_S,"SetDistanceUseZ",tolua_PX2_Soundable_SetDistanceUseZ00);
   tolua_function(tolua_S,"IsDistanceUseZ",tolua_PX2_Soundable_IsDistanceUseZ00);
   tolua_function(tolua_S,"GetAllModuleNames_EA",tolua_PX2_Soundable_GetAllModuleNames_EA00);
   tolua_function(tolua_S,"GetAllModuleNames_EO",tolua_PX2_Soundable_GetAllModuleNames_EO00);
   tolua_variable(tolua_S,"msModuleNames_EA",tolua_get_Soundable_msModuleNames_EA,tolua_set_Soundable_msModuleNames_EA);
   tolua_variable(tolua_S,"msModuleNames_EO",tolua_get_Soundable_msModuleNames_EO,tolua_set_Soundable_msModuleNames_EO);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Project","Project","",NULL);
  tolua_beginmodule(tolua_S,"Project");
   tolua_function(tolua_S,"Save",tolua_PX2_Project_Save00);
   tolua_function(tolua_S,"SaveConfig",tolua_PX2_Project_SaveConfig00);
   tolua_function(tolua_S,"Load",tolua_PX2_Project_Load00);
   tolua_function(tolua_S,"SetSize",tolua_PX2_Project_SetSize00);
   tolua_function(tolua_S,"SetSize",tolua_PX2_Project_SetSize01);
   tolua_function(tolua_S,"GetSize",tolua_PX2_Project_GetSize00);
   tolua_function(tolua_S,"GetWidth",tolua_PX2_Project_GetWidth00);
   tolua_function(tolua_S,"GetHeight",tolua_PX2_Project_GetHeight00);
   tolua_function(tolua_S,"SetBackgroundColor",tolua_PX2_Project_SetBackgroundColor00);
   tolua_function(tolua_S,"GetBackgroundColor",tolua_PX2_Project_GetBackgroundColor00);
   tolua_function(tolua_S,"SetScene",tolua_PX2_Project_SetScene00);
   tolua_function(tolua_S,"GetScene",tolua_PX2_Project_GetScene00);
   tolua_function(tolua_S,"GetSceneFilename",tolua_PX2_Project_GetSceneFilename00);
   tolua_function(tolua_S,"GetSceneRenderStep",tolua_PX2_Project_GetSceneRenderStep00);
   tolua_function(tolua_S,"SetUIFrame",tolua_PX2_Project_SetUIFrame00);
   tolua_function(tolua_S,"GetUIFrame",tolua_PX2_Project_GetUIFrame00);
   tolua_function(tolua_S,"GetUIFilename",tolua_PX2_Project_GetUIFilename00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Selection","Selection","",NULL);
  tolua_beginmodule(tolua_S,"Selection");
   tolua_function(tolua_S,"AddObject",tolua_PX2_Selection_AddObject00);
   tolua_function(tolua_S,"RemoveObject",tolua_PX2_Selection_RemoveObject00);
   tolua_function(tolua_S,"GetObjectAt",tolua_PX2_Selection_GetObjectAt00);
   tolua_function(tolua_S,"GetNumObjects",tolua_PX2_Selection_GetNumObjects00);
   tolua_function(tolua_S,"IsObjectIn",tolua_PX2_Selection_IsObjectIn00);
   tolua_function(tolua_S,"Clear",tolua_PX2_Selection_Clear00);
   tolua_function(tolua_S,"GetFirstObject",tolua_PX2_Selection_GetFirstObject00);
   tolua_function(tolua_S,"Translate",tolua_PX2_Selection_Translate00);
   tolua_function(tolua_S,"TranslateTo",tolua_PX2_Selection_TranslateTo00);
   tolua_function(tolua_S,"AddRolate",tolua_PX2_Selection_AddRolate00);
   tolua_function(tolua_S,"AddScale",tolua_PX2_Selection_AddScale00);
   tolua_function(tolua_S,"GetCenter",tolua_PX2_Selection_GetCenter00);
   tolua_function(tolua_S,"GetRadius",tolua_PX2_Selection_GetRadius00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Creater","Creater","",tolua_collect_Creater);
  #else
  tolua_cclass(tolua_S,"Creater","Creater","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Creater");
   tolua_function(tolua_S,"new",tolua_PX2_Creater_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_Creater_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_Creater_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_Creater_delete00);
   tolua_function(tolua_S,"CreateActor_Rectangle",tolua_PX2_Creater_CreateActor_Rectangle00);
   tolua_function(tolua_S,"CreateActor_Box",tolua_PX2_Creater_CreateActor_Box00);
   tolua_function(tolua_S,"CreateActor_Sphere",tolua_PX2_Creater_CreateActor_Sphere00);
   tolua_function(tolua_S,"CreateActor_Effect",tolua_PX2_Creater_CreateActor_Effect00);
   tolua_function(tolua_S,"CreateActor_Character",tolua_PX2_Creater_CreateActor_Character00);
   tolua_function(tolua_S,"CreateRectangle",tolua_PX2_Creater_CreateRectangle00);
   tolua_function(tolua_S,"CreateBox",tolua_PX2_Creater_CreateBox00);
   tolua_function(tolua_S,"CreateSphere",tolua_PX2_Creater_CreateSphere00);
   tolua_function(tolua_S,"CreateUIFrame",tolua_PX2_Creater_CreateUIFrame00);
   tolua_function(tolua_S,"CreateUIPicBox",tolua_PX2_Creater_CreateUIPicBox00);
   tolua_function(tolua_S,"CreateUIPicBox",tolua_PX2_Creater_CreateUIPicBox01);
   tolua_function(tolua_S,"CreateUIText",tolua_PX2_Creater_CreateUIText00);
   tolua_function(tolua_S,"CreateUIButton",tolua_PX2_Creater_CreateUIButton00);
   tolua_function(tolua_S,"CreateUICheckButton",tolua_PX2_Creater_CreateUICheckButton00);
   tolua_function(tolua_S,"CreateUIEditBox",tolua_PX2_Creater_CreateUIEditBox00);
   tolua_function(tolua_S,"CreateUIProgressBar",tolua_PX2_Creater_CreateUIProgressBar00);
   tolua_function(tolua_S,"CreateParticleEmitter",tolua_PX2_Creater_CreateParticleEmitter00);
   tolua_function(tolua_S,"CreateBillboard",tolua_PX2_Creater_CreateBillboard00);
   tolua_function(tolua_S,"CreateBeamEmitter",tolua_PX2_Creater_CreateBeamEmitter00);
   tolua_function(tolua_S,"CreateRibbonEmitter",tolua_PX2_Creater_CreateRibbonEmitter00);
   tolua_function(tolua_S,"CreateSoundable",tolua_PX2_Creater_CreateSoundable00);
   tolua_function(tolua_S,"AddActor",tolua_PX2_Creater_AddActor00);
   tolua_function(tolua_S,"AddCharacter",tolua_PX2_Creater_AddCharacter00);
   tolua_function(tolua_S,"AddEffectActor",tolua_PX2_Creater_AddEffectActor00);
   tolua_function(tolua_S,"AddObject",tolua_PX2_Creater_AddObject00);
   tolua_function(tolua_S,"RemoveObject",tolua_PX2_Creater_RemoveObject00);
   tolua_function(tolua_S,"ConvertToNode",tolua_PX2_Creater_ConvertToNode00);
   tolua_function(tolua_S,"ConvertToActor",tolua_PX2_Creater_ConvertToActor00);
   tolua_function(tolua_S,"ConvertToUIPicBox",tolua_PX2_Creater_ConvertToUIPicBox00);
   tolua_function(tolua_S,"ConvertToUIFrame",tolua_PX2_Creater_ConvertToUIFrame00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Scene","Scene","Node",tolua_collect_Scene);
  #else
  tolua_cclass(tolua_S,"Scene","Scene","Node",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Scene");
   tolua_function(tolua_S,"new",tolua_PX2_Scene_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_Scene_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_Scene_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_Scene_delete00);
   tolua_function(tolua_S,"SetUseCameraActor",tolua_PX2_Scene_SetUseCameraActor00);
   tolua_function(tolua_S,"GetUseCameraActor",tolua_PX2_Scene_GetUseCameraActor00);
   tolua_function(tolua_S,"AttachChild",tolua_PX2_Scene_AttachChild00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Actor","Actor","Node",tolua_collect_Actor);
  #else
  tolua_cclass(tolua_S,"Actor","Actor","Node",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Actor");
   tolua_function(tolua_S,"new",tolua_PX2_Actor_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_Actor_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_Actor_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_Actor_delete00);
   tolua_function(tolua_S,"SetTypeID",tolua_PX2_Actor_SetTypeID00);
   tolua_function(tolua_S,"GetTypeID",tolua_PX2_Actor_GetTypeID00);
   tolua_function(tolua_S,"SetGroup",tolua_PX2_Actor_SetGroup00);
   tolua_function(tolua_S,"GetGroup",tolua_PX2_Actor_GetGroup00);
   tolua_constant(tolua_S,"BST_CHARACTER",Actor::BST_CHARACTER);
   tolua_constant(tolua_S,"BST_BUILDINGINGORE",Actor::BST_BUILDINGINGORE);
   tolua_constant(tolua_S,"BST_BUILDING",Actor::BST_BUILDING);
   tolua_constant(tolua_S,"BST_CANBEAIMED",Actor::BST_CANBEAIMED);
   tolua_constant(tolua_S,"BST_GROUP1",Actor::BST_GROUP1);
   tolua_constant(tolua_S,"BST_GROUP2",Actor::BST_GROUP2);
   tolua_constant(tolua_S,"BST_MAX_TYPE",Actor::BST_MAX_TYPE);
   tolua_function(tolua_S,"GetBitSet",tolua_PX2_Actor_GetBitSet00);
   tolua_function(tolua_S,"GetBitSet",tolua_PX2_Actor_GetBitSet01);
   tolua_function(tolua_S,"IsContainAllBits",tolua_PX2_Actor_IsContainAllBits00);
   tolua_function(tolua_S,"SetMovableFilename",tolua_PX2_Actor_SetMovableFilename00);
   tolua_function(tolua_S,"GetMovableFilename",tolua_PX2_Actor_GetMovableFilename00);
   tolua_function(tolua_S,"IsShareVI",tolua_PX2_Actor_IsShareVI00);
   tolua_function(tolua_S,"SetMovable",tolua_PX2_Actor_SetMovable00);
   tolua_function(tolua_S,"GetMovable",tolua_PX2_Actor_GetMovable00);
   tolua_function(tolua_S,"CreateHelpNode",tolua_PX2_Actor_CreateHelpNode00);
   tolua_function(tolua_S,"GetNodeHelp",tolua_PX2_Actor_GetNodeHelp00);
   tolua_function(tolua_S,"SetPickable",tolua_PX2_Actor_SetPickable00);
   tolua_function(tolua_S,"IsPickable",tolua_PX2_Actor_IsPickable00);
   tolua_function(tolua_S,"SetFace",tolua_PX2_Actor_SetFace00);
   tolua_function(tolua_S,"SetFace",tolua_PX2_Actor_SetFace01);
   tolua_function(tolua_S,"GetFace",tolua_PX2_Actor_GetFace00);
   tolua_function(tolua_S,"GetRDUVector",tolua_PX2_Actor_GetRDUVector00);
   tolua_function(tolua_S,"SetHeading",tolua_PX2_Actor_SetHeading00);
   tolua_function(tolua_S,"GetHeading",tolua_PX2_Actor_GetHeading00);
   tolua_function(tolua_S,"CollectAnchors",tolua_PX2_Actor_CollectAnchors00);
   tolua_function(tolua_S,"GetAnchorPos",tolua_PX2_Actor_GetAnchorPos00);
   tolua_function(tolua_S,"GetAnchor",tolua_PX2_Actor_GetAnchor00);
   tolua_function(tolua_S,"SetRadius",tolua_PX2_Actor_SetRadius00);
   tolua_function(tolua_S,"GetRadius",tolua_PX2_Actor_GetRadius00);
   tolua_function(tolua_S,"SetHegiht",tolua_PX2_Actor_SetHegiht00);
   tolua_function(tolua_S,"GetHeight",tolua_PX2_Actor_GetHeight00);
   tolua_function(tolua_S,"GetSceneContainer",tolua_PX2_Actor_GetSceneContainer00);
   tolua_function(tolua_S,"GetSceneContainerIndex",tolua_PX2_Actor_GetSceneContainerIndex00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CameraActor","CameraActor","Actor",tolua_collect_CameraActor);
  #else
  tolua_cclass(tolua_S,"CameraActor","CameraActor","Actor",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CameraActor");
   tolua_function(tolua_S,"new",tolua_PX2_CameraActor_new00);
   tolua_function(tolua_S,"new_local",tolua_PX2_CameraActor_new00_local);
   tolua_function(tolua_S,".call",tolua_PX2_CameraActor_new00_local);
   tolua_function(tolua_S,"delete",tolua_PX2_CameraActor_delete00);
   tolua_function(tolua_S,"SetFOV",tolua_PX2_CameraActor_SetFOV00);
   tolua_function(tolua_S,"GetFOV",tolua_PX2_CameraActor_GetFOV00);
   tolua_function(tolua_S,"LookAt",tolua_PX2_CameraActor_LookAt00);
   tolua_function(tolua_S,"LookAt",tolua_PX2_CameraActor_LookAt01);
   tolua_function(tolua_S,"GetCamera",tolua_PX2_CameraActor_GetCamera00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_PX2 (lua_State* tolua_S) {
 return tolua_PX2_open(tolua_S);
};
#endif

