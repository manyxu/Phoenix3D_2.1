/*
** Lua binding: PX2Soccer
** Generated automatically by tolua++-1.0.92 on 07/22/15 23:29:10.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_PX2Soccer_open (lua_State* tolua_S);

#include "SoccerLua.hpp"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"SoccerManager");
}

/* method: GetSingleton of class  SoccerManager */
#ifndef TOLUA_DISABLE_tolua_PX2Soccer_SoccerManager_GetSingleton00
static int tolua_PX2Soccer_SoccerManager_GetSingleton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SoccerManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SoccerManager& tolua_ret = (SoccerManager&)  SoccerManager::GetSingleton();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"SoccerManager");
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

/* method: GetSingletonPtr of class  SoccerManager */
#ifndef TOLUA_DISABLE_tolua_PX2Soccer_SoccerManager_GetSingletonPtr00
static int tolua_PX2Soccer_SoccerManager_GetSingletonPtr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SoccerManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SoccerManager* tolua_ret = (SoccerManager*)  SoccerManager::GetSingletonPtr();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SoccerManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSingletonPtr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Initlize of class  SoccerManager */
#ifndef TOLUA_DISABLE_tolua_PX2Soccer_SoccerManager_Initlize00
static int tolua_PX2Soccer_SoccerManager_Initlize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SoccerManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SoccerManager* self = (SoccerManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Initlize'", NULL);
#endif
  {
   self->Initlize();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Initlize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Ternamate of class  SoccerManager */
#ifndef TOLUA_DISABLE_tolua_PX2Soccer_SoccerManager_Ternamate00
static int tolua_PX2Soccer_SoccerManager_Ternamate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SoccerManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SoccerManager* self = (SoccerManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Ternamate'", NULL);
#endif
  {
   self->Ternamate();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Ternamate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_PX2Soccer_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"SoccerManager","SoccerManager","",NULL);
  tolua_beginmodule(tolua_S,"SoccerManager");
   tolua_function(tolua_S,"GetSingleton",tolua_PX2Soccer_SoccerManager_GetSingleton00);
   tolua_function(tolua_S,"GetSingletonPtr",tolua_PX2Soccer_SoccerManager_GetSingletonPtr00);
   tolua_function(tolua_S,"Initlize",tolua_PX2Soccer_SoccerManager_Initlize00);
   tolua_function(tolua_S,"Ternamate",tolua_PX2Soccer_SoccerManager_Ternamate00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_PX2Soccer (lua_State* tolua_S) {
 return tolua_PX2Soccer_open(tolua_S);
};
#endif

