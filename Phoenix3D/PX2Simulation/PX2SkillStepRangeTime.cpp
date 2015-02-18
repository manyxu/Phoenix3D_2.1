// PX2SkillStepRangeTime.cpp

#include "PX2SkillStepRangeTime.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2Character.hpp"
#include "PX2Scene.hpp"
#include "PX2SkillInstance.hpp"
#include "PX2Skill.hpp"
#include "PX2AddDeleteManager.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, SkillStep, SkillStepRangeTime);
PX2_IMPLEMENT_STREAM(SkillStepRangeTime);
PX2_IMPLEMENT_FACTORY(SkillStepRangeTime);
PX2_IMPLEMENT_DEFAULT_NAMES(SkillStep, SkillStepRangeTime);

//----------------------------------------------------------------------------
SkillStepRangeTime::SkillStepRangeTime() :
SkillStep(M_RANGETIME),
mTimeType(TT_ANIMPERCENT),
mValue(0.0f)
{
}
//----------------------------------------------------------------------------
SkillStepRangeTime::~SkillStepRangeTime()
{
}
//----------------------------------------------------------------------------
void SkillStepRangeTime::OnEnter(SkillInstance *instance)
{
	SkillStep::OnEnter(instance);

	Skill *skill = instance->GetSkill();
	Character *character = skill->GetCharacter();
	Scene *scene = DynamicCast<Scene>(character->GetParent());

	float allProb = 0.0f;
	std::vector<float> probs;
	for (int i = 0; i < (int)mAnimObjs.size(); i++)
	{
		allProb += mAnimObjs[i].Probability;
		probs.push_back(allProb);
	}
	float prob = Mathf::IntervalRandom(0.0f, allProb);
	int animIndex = 0;
	for (int i = 0; i < (int)probs.size(); i++)
	{
		if (prob <= probs[i])
		{
			animIndex = i;
			break;
		}
	}

	SkillStep_AnimObj *animObj = 0;
	if (0 <= animIndex && animIndex < (int)mAnimObjs.size())
	{
		animObj = &mAnimObjs[animIndex];
	}

	if (animObj)
	{
		mCurActAnimID = animObj->ID;
		character->PlayAnimByID(animObj->ID);
	}

	std::map<EffectType, SkillStep_EffectObj>::iterator it = mEffectObjs.begin();
	for (; it != mEffectObjs.end(); it++)
	{
		EffectType type = it->first;
		SkillStep_EffectObj &effectObj = it->second;

		Movable *mov = DynamicCast<Movable>(PX2_RM.BlockLoadShareCopy(
			effectObj.EffectFilename, false, false, true));
		if (mov)
		{
			mov->SetSelfCtrled(true);

			if (ET_SELF == type)
			{
				Node *anchor = character->GetAnchor(effectObj.AnchorID);
				if (anchor)
				{
					PX2_ADM.AddAddingObj(anchor, mov, effectObj.DelayTime, true);
					PX2_ADM.AddDeletingObj(mov, 5.0f, 3.0f);
				}
			}
			else if (ET_SELF_POS == type)
			{
				APoint anchorPos = character->GetAnchorPos(effectObj.AnchorID);
				mov->LocalTransform.SetTranslate(anchorPos);

				PX2_ADM.AddAddingObj(scene, mov, effectObj.DelayTime, true);
				PX2_ADM.AddDeletingObj(mov, 5.0f, 3.0f);
			}
			else if (ET_TARGET == type)
			{
				for (int i = 0; i < instance->GetNumTargets(); i++)
				{
					Character *target = instance->GetTargetCharacter(i);
					if (target)
					{
						Node *anchor = target->GetAnchor(effectObj.AnchorID);
						if (anchor)
						{
							PX2_ADM.AddAddingObj(anchor, mov, effectObj.DelayTime, true);
							PX2_ADM.AddDeletingObj(mov, 5.0f, 3.0f);
						}
					}
				}
			}
			else if (ET_TARGET_POS == type)
			{
				for (int i = 0; i < instance->GetNumTargets(); i++)
				{
					Character *target = instance->GetTargetCharacter(i);
					if (target)
					{
						APoint anchorPos = character->GetAnchorPos(effectObj.AnchorID);
						mov->LocalTransform.SetTranslate(anchorPos);
						PX2_ADM.AddAddingObj(scene, mov, effectObj.DelayTime, true);
						PX2_ADM.AddDeletingObj(mov, 5.0f, 3.0f);
					}
				}
			}
			else if (ET_AIMEDTARGET == type)
			{
				int animTargetID = instance->GetAimTarget();
				Character *aimTarget = DynamicCast<Character>(scene->GetActorByID(animTargetID));
				if (aimTarget)
				{
					Node *anchor = aimTarget->GetAnchor(effectObj.AnchorID);
					if (anchor)
					{
						PX2_ADM.AddAddingObj(anchor, mov, effectObj.DelayTime, true);
						PX2_ADM.AddDeletingObj(mov, 5.0f, 3.0f);
					}
				}
			}
			else if (ET_AIMEDTARGET_POS == type)
			{
				int animTargetID = instance->GetAimTarget();
				Character *aimTarget = DynamicCast<Character>(scene->GetActorByID(animTargetID));
				if (aimTarget)
				{
					APoint anchorPos = aimTarget->GetAnchorPos(effectObj.AnchorID);
					mov->LocalTransform.SetTranslate(anchorPos);
					PX2_ADM.AddAddingObj(scene, mov, effectObj.DelayTime, true);
					PX2_ADM.AddDeletingObj(mov, 5.0f, 3.0f);
				}
			}
		}
	}
}
//----------------------------------------------------------------------------
float SkillStepRangeTime::GetTime()
{
	if (TT_TIME == mTimeType)
	{
		return mValue;
	}
	else
	{
		Animation *anim = mSkill->GetCharacter()->GetAnimByID(mCurActAnimID);
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
void SkillStepRangeTime::RegistProperties()
{
	SkillStep::RegistProperties();

	AddPropertyClass("SkillStepRangeTime");

	std::vector<std::string> rangeTimeTypes;
	rangeTimeTypes.push_back("TT_TIME");
	rangeTimeTypes.push_back("TT_ANIMPERCENT");

	AddPropertyEnum("TimeType", (int)GetTimeType(), rangeTimeTypes);
	AddProperty("Value", PT_FLOAT, GetValue());
}
//----------------------------------------------------------------------------
void SkillStepRangeTime::OnPropertyChanged(const PropertyObject &obj)
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

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
SkillStepRangeTime::SkillStepRangeTime(LoadConstructor value)
:
SkillStep(value),
mTimeType(TT_ANIMPERCENT),
mValue(0.0f)
{
}
//----------------------------------------------------------------------------
void SkillStepRangeTime::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	SkillStep::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadEnum(mTimeType);
	source.Read(mValue);

	PX2_END_DEBUG_STREAM_LOAD(SkillStepRangeTime, source);
}
//----------------------------------------------------------------------------
void SkillStepRangeTime::Link(InStream& source)
{
	SkillStep::Link(source);
}
//----------------------------------------------------------------------------
void SkillStepRangeTime::PostLink()
{
	SkillStep::PostLink();
}
//----------------------------------------------------------------------------
bool SkillStepRangeTime::Register(OutStream& target) const
{
	if (SkillStep::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void SkillStepRangeTime::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	SkillStep::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteEnum(mTimeType);
	target.Write(mValue);

	PX2_END_DEBUG_STREAM_SAVE(SkillStepRangeTime, target);
}
//----------------------------------------------------------------------------
int SkillStepRangeTime::GetStreamingSize(Stream &stream) const
{
	int size = SkillStep::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_ENUMSIZE(mTimeType);
	size += sizeof(mValue);

	return size;
}
//----------------------------------------------------------------------------