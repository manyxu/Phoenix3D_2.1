// PX2ScriptManager.cpp

#include "PX2ScriptManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
ScriptManager::ScriptManager() :
mNextRegistObjectID(0)
{
}
//----------------------------------------------------------------------------
ScriptManager::~ScriptManager()
{
}
//----------------------------------------------------------------------------
void ScriptManager::Clear()
{
	mGlobals.clear();
}
//----------------------------------------------------------------------------
bool ScriptManager::IsGlobalNameExist(const std::string &objectName)
{
	std::map<std::string, void*>::iterator it = mGlobals.find(objectName);
	if (it != mGlobals.end())
		return true;

	return false;
}
//----------------------------------------------------------------------------
bool ScriptManager::AddGlobalName(const std::string &objectName,
	void *object)
{
	mGlobals[objectName] = object;

	return true;
}
//----------------------------------------------------------------------------
bool ScriptManager::RemoveGlobalName(const std::string &objectName)
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
int ScriptManager::GetNextRegistObjectID()
{
	return ++mNextRegistObjectID;
}
//----------------------------------------------------------------------------