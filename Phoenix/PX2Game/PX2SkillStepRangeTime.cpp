/*
*
* 文件名称	：	PX2SkillStepRangeTime.cpp
*
*/

#include "PX2SkillStepRangeTime.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2DeletingManager.hpp"
#include "PX2AddingManager.hpp"
#include "PX2Character.hpp"
#include "PX2Scene.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, SkillStep, SkillStepRangeTime);
PX2_IMPLEMENT_STREAM(SkillStepRangeTime);
PX2_IMPLEMENT_FACTORY(SkillStepRangeTime);
PX2_IMPLEMENT_DEFAULT_NAMES(SkillStep, SkillStepRangeTime);

//----------------------------------------------------------------------------
SkillStepRangeTime::SkillStepRangeTime ()
	:
SkillStep(M_RANGETIME),
mTimeType(TT_ANIMPERCENT),
mValue(0.0f)
{
}
//----------------------------------------------------------------------------
SkillStepRangeTime::~SkillStepRangeTime ()
{
}
//----------------------------------------------------------------------------
void SkillStepRangeTime::OnEnter (SkillInstance *instance)
{
	SkillStep::OnEnter(instance);

	Skill *skill = instance->GetSkill();
	Character *character = skill->GetCharacter();
	Scene *scene = character->GetScene();
	Node *sceneNode = DynamicCast<Node>(scene->GetSceneNode());

	float allProb = mAnimProb + mAnimProb1;
	float prob = Mathf::IntervalRandom(0.0f, allProb);

	std::string animName = mAnimName;
	std::string selfEffectFilename = mSelfEffectFilename;
	std::string selfEffectAnchor = mSelfEffectAnchor;
	float selfEffectTime = mSelfEffectTime;
	std::string selfPosEffectFilename = mSelfPosEffectFilename;
	std::string selfPosEffectAnchor = mSelfPosEffectAnchor;
	float selfPosEffectTime = mSelfPosEffectTime;
	float selfPosEffectDelayTime = mSelfPosEffectDelayTime;

	int animIndex = 0;
	if (prob <= mAnimProb)
	{
		animIndex = 0;
		animName = mAnimName;
		selfEffectFilename = mSelfEffectFilename;
		selfEffectAnchor = mSelfEffectAnchor;
		selfEffectTime = mSelfEffectTime;
		selfPosEffectFilename = mSelfPosEffectFilename;
		selfPosEffectAnchor = mSelfPosEffectAnchor;
		selfPosEffectTime = mSelfPosEffectTime;
		selfPosEffectDelayTime = mSelfPosEffectDelayTime;
	}
	else
	{
		animIndex = 1;
		animName = mAnimName1;
		selfEffectFilename = mSelfEffect1Filename;
		selfEffectAnchor = mSelfEffect1Anchor;
		selfEffectTime = mSelfEffect1Time;
		selfPosEffectFilename = mSelfPosEffect1Filename;
		selfPosEffectAnchor = mSelfPosEffect1Anchor;
		selfPosEffectTime = mSelfPosEffect1Time;
		selfPosEffectDelayTime = mSelfPosEffectDelayTime1;
	}

	if (!animName.empty())
		character->PlayAnimByName(animName);

	// self effect
	if (!selfEffectFilename.empty())
	{	
		std::string anchorName = "center";

		if (!selfEffectAnchor.empty())
			anchorName = selfEffectAnchor;

		Node *anchor = character->GetAnchor(anchorName);
		if (anchor)
		{
			Object *obj = PX2_RM.BlockLoadShareCopy(selfEffectFilename, false,
				false, true);
			if (obj)
			{
				EffectNode *effectNode = DynamicCast<EffectNode>(obj);
				if (effectNode)
				{
					effectNode->SetSelfCtrled(true);
					//anchor->AttachChild(effectNode);
					effectNode->ResetPlay();

					PX2_ADM.AddAddingObj(anchor, effectNode, selfPosEffectDelayTime, true);
					PX2_DM.AddDeletingObj(effectNode, selfEffectTime, 3.0f);
				}
			}
		}
	}

	// self pos effect
	if (!selfPosEffectFilename.empty())
	{
		APoint pos = character->GetPosition();
		Transform trans;
		trans.SetTranslate(pos);
		trans.SetRotate(character->GetMovable()->WorldTransform.GetRotate());

		if (!selfPosEffectAnchor.empty())
		{
			Node *anchor = character->GetAnchor(selfPosEffectAnchor);
			if (anchor)
			{
				trans = anchor->WorldTransform;
			}
		}

		Object *obj = PX2_RM.BlockLoadShareCopy(selfPosEffectFilename, false,
			false, true);
		if (obj)
		{
			EffectNode *effectNode = DynamicCast<EffectNode>(obj);
			if (effectNode)
			{
				effectNode->SetSelfCtrled(true);
				effectNode->WorldTransform = trans;
				effectNode->WorldTransformIsCurrent = true;
				sceneNode->AttachChild(effectNode);
				effectNode->ResetPlay();

				PX2_DM.AddDeletingObj(effectNode, selfPosEffectTime, 3.0f);
			}
		}
	}

	// target effect
	if (!mTargetEffectFilename.empty())
	{
		for (int i=0; i<instance->GetNumTargets(); i++)
		{
			std::string anchorName = "center";

			if (!mTargetEffectAnchor.empty())
				anchorName = mTargetEffectAnchor;

			Character *target = instance->GetTargetCharacter(i);
			if (target)
			{
				Node *anchor = target->GetAnchor(anchorName);
				if (!anchor)
				{
					anchor = DynamicCast<Node>(target->GetMovable());
				}

				if (anchor)
				{
					Object *obj = PX2_RM.BlockLoadShareCopy(mTargetEffectFilename,
						false, false, true);
					EffectNode *effectNode = DynamicCast<EffectNode>(obj);
					if (effectNode)
					{
						effectNode->SetSelfCtrled(true);
						anchor->AttachChild(effectNode);
						effectNode->ResetPlay();

						PX2_DM.AddDeletingObj(effectNode,
							mTargetEffectTime, 3.0f);
					}
				}
			}
		}
	}

	// target pos effect
	if (!mTargetPosEffectFilename.empty())
	{
		for (int i=0; i<instance->GetNumTargets(); i++)
		{
			Character *target = instance->GetTargetCharacter(i);
			if (target)
			{
				const APoint &pos = target->GetPosition();
				Transform trans;
				trans.SetTranslate(pos);

				Object *obj = PX2_RM.BlockLoadShareCopy(mTargetPosEffectFilename, false, false, true);
				if (obj)
				{
					EffectNode *effectNode = DynamicCast<EffectNode>(obj);
					if (effectNode)
					{
						effectNode->SetSelfCtrled(true);
						effectNode->WorldTransform = trans;
						effectNode->WorldTransformIsCurrent = true;
						sceneNode->AttachChild(effectNode);
						effectNode->ResetPlay();

						PX2_DM.AddDeletingObj(effectNode, mTargetPosEffectTime, 3.0f);
					}
				}
			}
		}
	}

	// animed target pos effect
	if (!mAnimedTargetPosEffectFilename.empty())
	{
		int animTargetID = instance->GetAimTarget();
		Character *aimTarget = DynamicCast<Character>(scene->GetActorByID(animTargetID));
		if (aimTarget)
		{
			const APoint &pos = aimTarget->GetPosition();
			Transform trans;
			trans.SetTranslate(pos);

			Object *obj = PX2_RM.BlockLoadShareCopy(mAnimedTargetPosEffectFilename, false, false, true);
			if (obj)
			{
				EffectNode *effectNode = DynamicCast<EffectNode>(obj);
				if (effectNode)
				{
					effectNode->SetSelfCtrled(true);
					effectNode->WorldTransform = trans;
					effectNode->WorldTransformIsCurrent = true;
					sceneNode->AttachChild(effectNode);
					effectNode->ResetPlay();

					PX2_DM.AddDeletingObj(effectNode, selfPosEffectTime, 3.0f);
				}
			}
		}
	}
}
//----------------------------------------------------------------------------
float SkillStepRangeTime::GetTime ()
{
	if (TT_TIME == mTimeType)
	{
		return mValue;
	}
	else
	{
		Animation *anim = mSkill->GetCharacter()->GetAnimByName(mAnimName);
		if (anim)
		{
			float animTime = anim->GetTime();
			return animTime * mValue;
		}
	}

	return 0.0f;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void SkillStepRangeTime::RegistProperties ()
{
	SkillStep::RegistProperties();

	AddPropertyClass("SkillStepRangeTime");

	std::vector<std::string> rangeTimeTypes;
	rangeTimeTypes.push_back("TT_TIME");
	rangeTimeTypes.push_back("TT_ANIMPERCENT");

	AddPropertyEnum ("TimeType", (int)GetTimeType(), rangeTimeTypes);
	AddProperty("Value", PT_FLOAT, GetValue());
}
//----------------------------------------------------------------------------
void SkillStepRangeTime::OnPropertyChanged (const PropertyObject &obj)
{
	SkillStep::OnPropertyChanged(obj);

	if ("TimeType" == obj.Name)
	{
		SetTimeType((TimeType)PX2_ANY_AS(obj.Data, int));
	}
	else if ("Value" == obj.Name)
	{
		SetValue(PX2_ANY_AS(obj.Data, float));
	}
}
//----------------------------------------------------------------------------
void SkillStepRangeTime::SaveToXMLNode (XMLNode nodeParent)
{
	XMLNode nodeClass = nodeParent.NewChild("Class");
	nodeClass.SetAttributeString("Type", "SkillStepRangeTime");
	
	SkillStep::SaveToXMLNode(nodeClass);
	
	XMLNode nodeProperty = nodeClass.NewChild("Property");
	nodeProperty.SetAttributeInt("TimeType", (int)GetTimeType());
	nodeProperty.SetAttributeFloat("Value", GetValue());

/*
	XMLNode nodeClass("Class");
	nodeClass.Create(nodeParent.mDoc);
	nodeClass.SetAttributeString("Type", "SkillStepRangeTime");
	nodeParent.LinkEndChild(nodeClass);

	SkillStep::SaveToXMLNode(nodeClass);

	XMLNode nodeProperty("Property");
	nodeProperty.Create(nodeClass.mDoc);
	nodeClass.LinkEndChild(nodeProperty);
	nodeProperty.SetAttributeInt("TimeType", (int)GetTimeType());
	nodeProperty.SetAttributeFloat("Value", GetValue());
*/
}
//----------------------------------------------------------------------------
void SkillStepRangeTime::LoadFromXMLNode (XMLNode node)
{
	XMLNode nodeClass = node.GetChild("Class");
	if (!nodeClass.IsNull())
	{
		SkillStep::LoadFromXMLNode(nodeClass);
	}
	else
	{
		assertion(false, "");
	}

	XMLNode nodeProperty = node.GetChild("Property");
	if (!nodeProperty.IsNull())
	{
		if (nodeProperty.HasAttribute("RangeTime"))
		{
			SetValue(0.3f);
		}
		else
		{
			SetTimeType((TimeType)nodeProperty.AttributeToInt("TimeType"));
			SetValue(nodeProperty.AttributeToFloat("Value"));
		}
	}
	else
	{
		assertion(false, "");
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
SkillStepRangeTime::SkillStepRangeTime (LoadConstructor value)
	:
SkillStep(value),
mTimeType(TT_ANIMPERCENT),
mValue(0.0f)
{
}
//----------------------------------------------------------------------------
void SkillStepRangeTime::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	SkillStep::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadEnum(mTimeType);
	source.Read(mValue);

	PX2_END_DEBUG_STREAM_LOAD(SkillStepRangeTime, source);
}
//----------------------------------------------------------------------------
void SkillStepRangeTime::Link (InStream& source)
{
	SkillStep::Link(source);
}
//----------------------------------------------------------------------------
void SkillStepRangeTime::PostLink ()
{
	SkillStep::PostLink();
}
//----------------------------------------------------------------------------
bool SkillStepRangeTime::Register (OutStream& target) const
{
	if (SkillStep::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void SkillStepRangeTime::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	SkillStep::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteEnum(mTimeType);
	target.Write(mValue);

	PX2_END_DEBUG_STREAM_SAVE(SkillStepRangeTime, target);
}
//----------------------------------------------------------------------------
int SkillStepRangeTime::GetStreamingSize (Stream &stream) const
{
	int size = SkillStep::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_ENUMSIZE(mTimeType);
	size += sizeof(mValue);

	return size;
}
//----------------------------------------------------------------------------