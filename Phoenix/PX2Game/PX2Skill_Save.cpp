/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Skill_Save.cpp
*
*/

#include "PX2Skill.hpp"
#include "PX2LogicManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void Skill::SaveToXMLNode (XMLNode nodeParent)
{
	XMLNode nodeClass = nodeParent.NewChild("Class");
	nodeClass.SetAttributeString("Type", "Skill");

	Gameable::SaveToXMLNode(nodeClass);

	XMLNode nodeProperty = nodeClass.NewChild("Property");
	nodeProperty.SetAttributeString("ScriptHandler_OnAdded", GetScriptHandler_OnAdded());
	nodeProperty.SetAttributeString("ScriptHandler_OnRemove", GetScriptHandler_OnRemove());
	nodeProperty.SetAttributeInt("TypeID", GetTypeID());
	nodeProperty.SetAttributeString("TypeString", GetTypeString());
	nodeProperty.SetAttributeFloat("ActivateProbability", GetActivateProbability());
	nodeProperty.SetAttributeInt("Priority", GetPriority());
	nodeProperty.SetAttributeBool("IsPositive", IsPositive());
	nodeProperty.SetAttributeBool("IsDieActivate", IsDieActivate());
	nodeProperty.SetAttributeInt("RangeType", (int)GetRangeType());
	nodeProperty.SetAttributeBool("IsHasTrack", IsHasTrack());
	nodeProperty.SetAttributeInt("ShapeType", (int)GetShapeType());
	nodeProperty.SetAttributeFloat("BaseRadiusLength", GetRadiusLength());
	nodeProperty.SetAttributeFloat("BaseWidth", GetWidth());
	nodeProperty.SetAttributeFloat("BaseFanDegree", GetFanDegree());
	nodeProperty.SetAttributeBool("IsRangeAffect", IsRangeAffect());
	nodeProperty.SetAttributeInt("NumTargetsLock", GetNumTargetsLock());
	nodeProperty.SetAttributeInt("NumMultiInstance", GetNumMultiInstance());
	nodeProperty.SetAttributeFloat("BaseCDTime", GetCDTime());
	nodeProperty.SetAttributeInt("Level", GetLevel());
	nodeProperty.SetAttributeInt("MaxLevel", GetMaxLevel());
	nodeProperty.SetAttributeInt("AffectGroupType", (int)GetAffectGroupType());
	nodeProperty.SetAttributeBool("IsActivateNeedCharacterAnimTarget", IsActivateNeedCharacterAnimTarget());
	nodeProperty.SetAttributeInt("ActivateAllowTimes", GetActivateAllowTimes());

	if (mFirstSkillStep)
	{
		XMLNode nodeObject = nodeClass.NewChild("Object");
		nodeObject.SetAttributeString("RttiName", mFirstSkillStep->GetRttiType().GetName());

		mFirstSkillStep->SaveToXMLNode(nodeObject);
	}
}
//----------------------------------------------------------------------------
void Skill::LoadFromXMLNode (XMLNode node)
{
	XMLNode nodeClass = node.GetChild("Class");
	if (!nodeClass.IsNull())
	{
		Gameable::LoadFromXMLNode(nodeClass);
	}
	else
	{
		assertion(false, "");
	}

	XMLNode nodeProperty = node.GetChild("Property");
	if (!nodeProperty.IsNull())
	{
		if (nodeProperty.HasAttribute("ScriptHandler_OnAdded"))
		{
			SetScriptHandler_OnAdded(nodeProperty.AttributeToString("ScriptHandler_OnAdded"));
		}
		if (nodeProperty.HasAttribute("ScriptHandler_OnRemove"))
		{
			SetScriptHandler_OnRemove(nodeProperty.AttributeToString("ScriptHandler_OnRemove"));
		}
		if (nodeProperty.HasAttribute("TypeID"))
		{
			SetTypeID(nodeProperty.AttributeToInt("TypeID"));
		}
		SetTypeString(nodeProperty.AttributeToString("TypeString"));
		if (nodeProperty.HasAttribute("ActivateProbability"))
		{
			SetActivateProbability(nodeProperty.AttributeToFloat("ActivateProbability"));
		}
		if (nodeProperty.HasAttribute("Priority"))
		{
			SetPriority(nodeProperty.AttributeToInt("Priority"));
		}
		if (nodeProperty.HasAttribute("IsPositive"))
		{
			SetPositive(nodeProperty.AttributeToBool("IsPositive"));
		}
		if (nodeProperty.HasAttribute("IsDieActivate"))
		{
			SetDieActivate(nodeProperty.AttributeToBool("IsDieActivate"));
		}
		SetRangeType((RangeType)nodeProperty.AttributeToInt("RangeType"));
		SetHasTrack(nodeProperty.AttributeToBool("IsHasTrack"));
		SetShapeType((ShapeType)nodeProperty.AttributeToInt("ShapeType"));
		SetRadiusLength(nodeProperty.AttributeToFloat("BaseRadiusLength"));
		SetWidth(nodeProperty.AttributeToFloat("BaseWidth"));
		SetFanDegree(nodeProperty.AttributeToFloat("BaseFanDegree"));
		SetBeRangeAffect(nodeProperty.AttributeToBool("IsRangeAffect"));
		SetNumTargetsLock(nodeProperty.AttributeToInt("NumTargetsLock"));

		if (nodeProperty.HasAttribute("AffectGroupType"))
		{
			SetAffectGroupType((AffectGroupType)nodeProperty.AttributeToInt("AffectGroupType"));
		}

		if (nodeProperty.HasAttribute("IsActivateNeedCharacterAnimTarget"))
		{
			SetActivateNeedCharacterAimTarget(nodeProperty.AttributeToBool("IsActivateNeedCharacterAnimTarget"));
		}

		if (nodeProperty.HasAttribute("ActivateAllowTimes"))
		{
			SetActivateAllowTimes(nodeProperty.AttributeToInt("ActivateAllowTimes"));
		}
	}
	else
	{
		assertion(false, "");
	}

	XMLNode nodeObject = node.GetChild("Object");
	if (!nodeObject.IsNull())
	{
		std::string rttiName = nodeObject.AttributeToString("RttiName");
		Gameable *gameable = LogicManager::GetSingleton().CreateFromRttiName(rttiName);
		if (gameable)
		{
			XMLNode objectClassNode = nodeObject.GetChild("Class");
			if (!objectClassNode.IsNull())
			{
				gameable->LoadFromXMLNode(objectClassNode);
			}
			else
			{
				assertion(false, "");
			}
		}

		SkillStep *skillStep = DynamicCast<SkillStep>(gameable);
		if (skillStep)
		{
			SetFirstSkillStep(skillStep);
		}
	}
}
//----------------------------------------------------------------------------