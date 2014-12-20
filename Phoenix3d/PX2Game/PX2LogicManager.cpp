/*
*
* ÎÄ¼þÃû³Æ	£º	PX2LogicManager.cpp
*
*/

#include "PX2LogicManager.hpp"
#include "PX2Skill.hpp"
#include "PX2SkillStepRangeTime.hpp"
#include "PX2SkillStepFarTrack.hpp"
#include "PX2SkillStepLink.hpp"
#include "PX2Character.hpp"
#include "PX2Character2DFrames8.hpp"
#include "PX2Item.hpp"
#include "PX2Animation2DFrames8.hpp"
#include "PX2Animation3DSkeleton.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2XMLData.hpp"
#include "PX2ResourceManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
LogicManager::LogicManager ()
{
	mActorLogicNames.push_back("Character");
	mActorLogicNames.push_back("Animation3DSkeleton");
	mActorLogicNames.push_back("Skill");
	mActorLogicNames.push_back("SkillStepRangeTime");
	mActorLogicNames.push_back("SkillStepFarTrack");
	mActorLogicNames.push_back("SkillStepLink");
	mActorLogicNames.push_back("Item");
}
//----------------------------------------------------------------------------
LogicManager::~LogicManager()
{
}
//----------------------------------------------------------------------------
Gameable *LogicManager::Factory (const std::string &name)
{
	if ("Character" == name)
	{
		return new0 Character();
	}
	else if ("Animation3DSkeleton" == name)
	{
		return new0 Animation3DSkeleton();
	}
	else if ("Character2DFrames8" == name)
	{
		return new0 Character2DFrames8();
	}
	else if ("Animation2DFrames8" == name)
	{
		return new0 Animation2DFrames8();
	}
	else if ("Skill" == name)
	{
		return new0 Skill();
	}
	else if ("SkillStepRangeTime" == name)
	{
		return new0 SkillStepRangeTime();
	}
	else if ("SkillStepFarTrack" == name)
	{
		return new0 SkillStepFarTrack();
	}
	else if ("SkillStepLink" == name)
	{
		return new0 SkillStepLink();
	}
	else if ("Item" == name)
	{
		return new0 Item();
	}

	return 0;
}
//----------------------------------------------------------------------------
Gameable *LogicManager::LoadFromXML (const std::string &filename)
{
	char *buffer = 0;
	int bufferSize = 0;
	if (PX2_RM.LoadBuffer(filename, bufferSize, buffer))
	{
		XMLData data;
		if (data.LoadBuffer(buffer, bufferSize))
		{
			XMLNode rootNode = data.GetRootNode();
			if (!rootNode.IsNull())
			{
				Gameable *gameable = CreateFromRttiName(
					rootNode.AttributeToString("RttiName"));
				Character *character = DynamicCast<Character>(gameable);
				if (character)
				{
					character->RemoveAllAnims();
				}

				if (gameable)
				{
					XMLNode classNode = rootNode.GetChild("Class");
					std::string typeName = classNode.AttributeToString("Type");
					gameable->LoadFromXMLNode(classNode);

					return gameable;
				}
			}
		}
	}

	return 0;
}
//----------------------------------------------------------------------------
Gameable *LogicManager::CreateFromRttiName (const std::string &rttiName)
{
	std::string ns("PX2.");
	std::string name = rttiName.substr(ns.length(), rttiName.length()-ns.length());

	return Factory(name);
}
//----------------------------------------------------------------------------
Gameable *LogicManager::LoadFromBinary (const std::string &filename)
{
	Gameable *gamable = DynamicCast<Gameable>(PX2_RM.BlockLoad(filename));
	return gamable;
}
//----------------------------------------------------------------------------