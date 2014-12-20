/*
*
* ÎÄ¼þÃû³Æ	£º	PX2ScriptManager.cpp
*
*/

#include "PX2ScriptManager.hpp"
#include "PX2LuaManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
ScriptManager::ScriptManager ()
	:
mType(ST_MAX_TYPE),
mNextRegistObjectID(0)
{
}
//----------------------------------------------------------------------------
ScriptManager::~ScriptManager ()
{
}
//----------------------------------------------------------------------------
ScriptManager *ScriptManager::Create (ScriptType type)
{
	ScriptManager *sm = 0;

	if (type == ST_LUA)
	{
		sm = new0 LuaManager();
	}

	return sm;
}
//----------------------------------------------------------------------------
void ScriptManager::Initlize ()
{
}
//----------------------------------------------------------------------------
void ScriptManager::Clear ()
{
	mGlobals.clear();
}
//----------------------------------------------------------------------------
bool ScriptManager::IsGlobalNameExist (const std::string &objectName)
{
	std::map<std::string, void*>::iterator it = mGlobals.find(objectName);
	if (it != mGlobals.end())
		return true;

	return false;
}
//----------------------------------------------------------------------------
bool ScriptManager::AddGlobalName (const std::string &objectName, 
	void *object)
{
	//if (IsGlobalNameExist(objectName))
	//{
	//	assertion(false, "ScriptSystem global %s exist.\n", objectName.c_str());
	//	PX2_LOG_ERROR("ScriptSystem global %s exist.", objectName.c_str());

	//	return false;
	//}

	mGlobals[objectName] = object;

	return true;
}
//----------------------------------------------------------------------------
bool ScriptManager::RemoveGlobalName (const std::string &objectName)
{
	std::map<std::string, void*>::iterator it = mGlobals.find(objectName);
	if (it != mGlobals.end())
	{
		mGlobals.erase(it);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
int ScriptManager::GetNextRegistObjectID ()
{
	return ++mNextRegistObjectID;
}
//----------------------------------------------------------------------------