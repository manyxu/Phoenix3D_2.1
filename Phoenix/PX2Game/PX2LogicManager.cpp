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
	else if ("Item" == name)
	{
		return new0 Item();
	}

	return 0;
}
//----------------------------------------------------------------------------