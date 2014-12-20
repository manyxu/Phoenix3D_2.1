/*
*
* 文件名称	：	PX2Item.cpp
*
*/

#include "PX2Item.hpp"
#include "PX2StateMachine.hpp"
#include "PX2SkillInstance.hpp"
#include "PX2ScriptManager.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Actor, Item);
PX2_IMPLEMENT_STREAM(Item);
PX2_IMPLEMENT_FACTORY(Item);
PX2_IMPLEMENT_DEFAULT_NAMES(Actor, Item);

//----------------------------------------------------------------------------
Item::Item ()
	:
mCharacter(0),
mIsCanBeEquipped(true),
mIsEquippedDoUse(true),
mIsEquipped(false),
mLevel(0),
mCanUseNow(false),
mIsUsing(false)
{
}
//----------------------------------------------------------------------------
Item::~Item ()
{
}
//----------------------------------------------------------------------------
void Item::SetLevel (int level)
{
	mLevel = level;
}
//----------------------------------------------------------------------------
void Item::Use (bool use)
{
	mIsUsing = use;
	
	if (ScriptManager::GetSingletonPtr())
	{
		if (!IsRegistedToScriptSystem())
			RegistToScriptSystem();
	}

	if (ScriptManager::GetSingletonPtr())
	{
		if (!mScriptHandler_Use.empty())
		{
			CallString(mScriptHandler_Use.c_str(), "i", mIsUsing? 1 : 0);
		}
	}
}
//----------------------------------------------------------------------------
void Item::AddScriptHandler_OnBeAffect (const std::string &name,
	const std::string &handler)
{
	mScriptHandlers_OnBeAffect[name] = handler;
}
//----------------------------------------------------------------------------
void Item::RemoveScriptHandler_OnBeAffect (const std::string &name)
{
	std::map<std::string, std::string>::iterator it =
		mScriptHandlers_OnBeAffect.find(name);	
	if (it != mScriptHandlers_OnBeAffect.end())
	{
		mScriptHandlers_OnBeAffect.erase(it);
	}
}
//----------------------------------------------------------------------------
void Item::AddScriptHandler_OnSucAffect (const std::string &name, 
	const std::string &handler)
{
	mScriptHandlers_OnSucAffect[name] = handler;
}
//----------------------------------------------------------------------------
void Item::RemoveScriptHandler_OnSucAffect (const std::string &name)
{
	std::map<std::string, std::string>::iterator it =
		mScriptHandlers_OnSucAffect.find(name);	
	if (it != mScriptHandlers_OnSucAffect.end())
	{
		mScriptHandlers_OnSucAffect.erase(it);
	}
}
//----------------------------------------------------------------------------
void Item::OnBeAffect (AffectObject *ao)
{
	PX2_UNUSED(ao);

	std::map<std::string, std::string>::iterator it =
		mScriptHandlers_OnBeAffect.begin();
	for (; it!=mScriptHandlers_OnBeAffect.end(); it++)
	{
		CallString(it->second.c_str());
	}
}
//----------------------------------------------------------------------------
void Item::OnSucAffect (AffectObject *ao)
{
	PX2_UNUSED(ao);

	std::map<std::string, std::string>::iterator it =
		mScriptHandlers_OnSucAffect.begin();
	for (; it!=mScriptHandlers_OnSucAffect.end(); it++)
	{
		CallString(it->second.c_str());
	}
}
//----------------------------------------------------------------------------
void Item::SetEquipped (bool equip)
{
	mIsEquipped = equip;

	if (mIsEquippedDoUse)
	{
		Use(mIsEquipped);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void Item::RegistProperties ()
{
	Actor::RegistProperties();

	AddPropertyClass("Item");
	AddProperty("IsEquipped()", PT_BOOL, IsEquipped(), false);
	AddProperty("ScriptHandler_Use", PT_STRING, GetScriptHandler_Use());
}
//----------------------------------------------------------------------------
void Item::OnPropertyChanged (const PropertyObject &obj)
{
	Actor::OnPropertyChanged(obj);

	if ("ScriptHandler_Use" == obj.Name)
	{
		SetScriptHandler_Use(PX2_ANY_AS(obj.Data, std::string));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Item::Item (LoadConstructor value)
	:
Actor(value),
mCharacter(0),
mIsCanBeEquipped(true),
mIsEquippedDoUse(true),
mIsEquipped(false),
mLevel(0),
mCanUseNow(false),
mIsUsing(false)
{
}
//----------------------------------------------------------------------------
void Item::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Actor::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadString(mTypeString);
	source.ReadBool(mIsCanBeEquipped);
	source.ReadBool(mIsEquippedDoUse);
	source.ReadBool(mIsEquipped);
	source.Read(mLevel);
	source.ReadString(mScriptHandler_Use);

	int numHandlersOnBeAffect = 0;
	source.Read(numHandlersOnBeAffect);
	for (int i=0; i<numHandlersOnBeAffect; i++)
	{
		std::string first;
		std::string second;
		source.ReadString(first);
		source.ReadString(second);

		mScriptHandlers_OnBeAffect[first] = second;
	}

	int numHandlersOnSucAffect = 0;
	source.Read(numHandlersOnSucAffect);
	for (int i=0; i<numHandlersOnSucAffect; i++)
	{
		std::string first;
		std::string second;
		source.ReadString(first);
		source.ReadString(second);

		mScriptHandlers_OnSucAffect[first] = second;
	}

	PX2_END_DEBUG_STREAM_LOAD(Item, source);
}
//----------------------------------------------------------------------------
void Item::Link (InStream& source)
{
	Actor::Link(source);
}
//----------------------------------------------------------------------------
void Item::PostLink ()
{
	Actor::PostLink();
}
//----------------------------------------------------------------------------
bool Item::Register (OutStream& target) const
{
	if (Actor::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void Item::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Actor::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteString(mTypeString);
	target.WriteBool(mIsCanBeEquipped);
	target.WriteBool(mIsEquippedDoUse);
	target.WriteBool(mIsEquipped);
	target.Write(mLevel);
	target.WriteString(mScriptHandler_Use);

	int numHandlersOnBeAffect = (int)mScriptHandlers_OnBeAffect.size();
	target.Write(numHandlersOnBeAffect);
	std::map<std::string, std::string>::const_iterator it = mScriptHandlers_OnBeAffect.begin();
	for (; it!=mScriptHandlers_OnBeAffect.end(); it++)
	{
		target.WriteString(it->first);
		target.WriteString(it->second);
	}

	int numHandlersOnSucAffect = (int)mScriptHandlers_OnSucAffect.size();
	target.Write(numHandlersOnSucAffect);
	std::map<std::string, std::string>::const_iterator it1 = mScriptHandlers_OnSucAffect.begin();
	for (; it1!=mScriptHandlers_OnSucAffect.end(); it1++)
	{
		target.WriteString(it1->first);
		target.WriteString(it1->second);
	}

	PX2_END_DEBUG_STREAM_SAVE(Item, target);
}
//----------------------------------------------------------------------------
int Item::GetStreamingSize (Stream &stream) const
{
	int size = Actor::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_STRINGSIZE(mTypeString);
	size += PX2_BOOLSIZE(mIsCanBeEquipped);
	size += PX2_BOOLSIZE(mIsEquippedDoUse);
	size += PX2_BOOLSIZE(mIsEquipped);
	size += sizeof(mLevel);
	size += PX2_STRINGSIZE(mScriptHandler_Use);

	int numHandlersOnBeAffect = (int)mScriptHandlers_OnBeAffect.size();
	size += sizeof(numHandlersOnBeAffect);
	std::map<std::string, std::string>::const_iterator it = mScriptHandlers_OnBeAffect.begin();
	for (; it!=mScriptHandlers_OnBeAffect.end(); it++)
	{
		size += PX2_STRINGSIZE(it->first);
		size += PX2_STRINGSIZE(it->second);
	}

	int numHandlersOnSucAffect = (int)mScriptHandlers_OnSucAffect.size();
	size += sizeof(numHandlersOnSucAffect);
	std::map<std::string, std::string>::const_iterator it1 = mScriptHandlers_OnSucAffect.begin();
	for (; it1!=mScriptHandlers_OnSucAffect.end(); it1++)
	{
		size += PX2_STRINGSIZE(it1->first);
		size += PX2_STRINGSIZE(it1->second);
	}

	return size;
}
//----------------------------------------------------------------------------