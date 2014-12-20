/*
*
* 文件名称	：	PX2GameObject.cpp
*
*/

#include "PX2Gameable.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2XMLData.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2LogicManager.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Netable, Gameable);
PX2_IMPLEMENT_STREAM(Gameable);
PX2_IMPLEMENT_FACTORY(Gameable);

//----------------------------------------------------------------------------
Gameable::Gameable ()
	:
mIsEnable(true),
mServerID(-1)
{
}
//----------------------------------------------------------------------------
Gameable::~Gameable ()
{
	if (IsRegistedToScriptSystem())
		UnRegistToScriptSystem();
}
//----------------------------------------------------------------------------
void Gameable::SetServerID (int serverID)
{
	mServerID = serverID;
}
//----------------------------------------------------------------------------
void Gameable::SetScriptHandler_Init (const std::string &handler)
{
	mScriptHandler_Init = handler;
}
//----------------------------------------------------------------------------
void Gameable::Initlize ()
{
	if (!IsRegistedToScriptSystem())
		RegistToScriptSystem();

	if (!mScriptHandler_Init.empty())
		CallString(mScriptHandler_Init.c_str());
}
//----------------------------------------------------------------------------
void Gameable::SetUserScriptName(const std::string &scriptName)
{
	mUserScriptName = scriptName;
}
//----------------------------------------------------------------------------
bool Gameable::RegistToScriptSystem ()
{
	if (!ScriptManager::GetSingletonPtr())
		return false;

	const std::string &rttiName = GetRttiType().GetName();
	const std::string spaceName = "PX2.";
	size_t nameLength = rttiName.size()-spaceName.length();
	std::string className = rttiName.substr(spaceName.length(), nameLength);

	if (!mUserScriptName.empty())
	{
		mScriptName = mUserScriptName;
	}
	else
	{
		mScriptName = className + "_ScriptID_"
			+ StringHelp::IntToString(PX2_SM.GetNextRegistObjectID());
	}

	PX2_SM.AddGlobalName(mScriptName, this);	
	PX2_SM.SetUserTypePointer(mScriptName.c_str(), className.c_str(), this);

	return true;
}
//----------------------------------------------------------------------------
bool Gameable::UnRegistToScriptSystem ()
{
	if (!ScriptManager::GetSingletonPtr())
		return false;

	const std::string &rttiName = GetRttiType().GetName();
	const std::string spaceName = "PX2.";
	size_t nameLength = rttiName.size()-spaceName.length();
	std::string className = rttiName.substr(spaceName.length(), nameLength);

	PX2_SM.RemoveGlobalName(mScriptName);	
	PX2_SM.SetUserTypePointer(mScriptName.c_str(), className.c_str(), 0);

	return true;
}
//----------------------------------------------------------------------------
bool Gameable::IsRegistedToScriptSystem ()
{
	if (!ScriptManager::GetSingletonPtr())
		return false;

	return PX2_SM.IsGlobalNameExist(mScriptName);
}
//----------------------------------------------------------------------------
void Gameable::CallString (const char *fun, const char *format, ...)
{
	if (!ScriptManager::GetSingletonPtr())
		return;

	va_list argptr;
	va_start(argptr, format);

	PX2_SM.CallObjectFuntionValist(mScriptName.c_str(), fun, format, argptr);

	va_end(argptr);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void Gameable::RegistProperties ()
{
	Netable::RegistProperties();

	AddPropertyClass("Gameable");
	AddProperty("IsEnable", PT_BOOL, IsEnable());
}
//----------------------------------------------------------------------------
void Gameable::OnPropertyChanged (const PropertyObject &obj)
{
	Netable::OnPropertyChanged(obj);

	if ("IsEnable" == obj.Name)
	{
		Enable(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("ScriptHandler_Init" == obj.Name)
	{
		SetScriptHandler_Init(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("UserScriptName" == obj.Name)
	{
		SetUserScriptName(PX2_ANY_AS(obj.Data, std::string));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称支持
//----------------------------------------------------------------------------
Object* Gameable::GetObjectByName (const std::string& name)
{
	Object* found = Netable::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	return 0;
}
//----------------------------------------------------------------------------
void Gameable::GetAllObjectsByName (const std::string& name,
	std::vector<Object*>& objects)
{
	Netable::GetAllObjectsByName(name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Gameable::Gameable (LoadConstructor value)
	:
Netable(value),
mIsEnable(true),
mServerID(-1)
{
}
//----------------------------------------------------------------------------
void Gameable::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Netable::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadBool(mIsEnable);	
	source.ReadString(mScriptHandler_Init);
	source.ReadString(mUserScriptName);

	PX2_END_DEBUG_STREAM_LOAD(Gameable, source);
}
//----------------------------------------------------------------------------
void Gameable::Link (InStream& source)
{
	Netable::Link(source);
}
//----------------------------------------------------------------------------
void Gameable::PostLink ()
{
	Netable::PostLink();
}
//----------------------------------------------------------------------------
bool Gameable::Register (OutStream& target) const
{
	if (Netable::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void Gameable::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Netable::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteBool(mIsEnable);
	target.WriteString(mScriptHandler_Init);
	target.WriteString(mUserScriptName);

	PX2_END_DEBUG_STREAM_SAVE(Gameable, target);
}
//----------------------------------------------------------------------------
int Gameable::GetStreamingSize (Stream &stream) const
{
	int size = Netable::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_BOOLSIZE(mIsEnable);
	size += PX2_STRINGSIZE(mScriptHandler_Init);
	size += PX2_STRINGSIZE(mUserScriptName);

	return size;
}
//----------------------------------------------------------------------------