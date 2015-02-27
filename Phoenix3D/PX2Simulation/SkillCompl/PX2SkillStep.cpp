// PX2SkillStep.cpp

#include "PX2SkillStep.hpp"
#include "PX2Skill.hpp"
#include "PX2Character.hpp"
#include "PX2ScriptManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
// SkillStep_AnimObj
//----------------------------------------------------------------------------
SkillStep_AnimObj::SkillStep_AnimObj() :
ID(0),
Probability(0.0f)
{
}
//----------------------------------------------------------------------------
SkillStep_AnimObj::~SkillStep_AnimObj()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
SkillStep_EffectObj::SkillStep_EffectObj() :
AnchorID(0),
DelayTime(0.0f)
{
}
//----------------------------------------------------------------------------
SkillStep_EffectObj::~SkillStep_EffectObj()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// SkillStep
//----------------------------------------------------------------------------
PX2_IMPLEMENT_RTTI(PX2, Object, SkillStep);
PX2_IMPLEMENT_STREAM(SkillStep);
PX2_IMPLEMENT_FACTORY(SkillStep);
PX2_IMPLEMENT_DEFAULT_NAMES(Object, SkillStep);

//----------------------------------------------------------------------------
SkillStep::SkillStep() :
mSkill(0),
mCurEnteredSkillInstance(0),
mProbability(0.0f),
mMode(M_RANGETIME),
mSkillCallOverTimeType(TT_ANIMPERCENT),
mSkillCallOverValue(0.0f),
mIsSkillCallOverAtThisStep(false),
mCurActAnimID(0)
{
}
//----------------------------------------------------------------------------
SkillStep::SkillStep(Mode mode) :
mMode(mode),
mSkill(0),
mCurEnteredSkillInstance(0),
mProbability(0.0f),
mSkillCallOverTimeType(TT_ANIMPERCENT),
mSkillCallOverValue(0.0f),
mIsSkillCallOverAtThisStep(false),
mCurActAnimID(0)
{

}
//----------------------------------------------------------------------------
SkillStep::~SkillStep()
{
}
//----------------------------------------------------------------------------
float SkillStep::GetSkillCallOverTime() const
{
	if (TT_TIME == mSkillCallOverTimeType)
	{
		return mSkillCallOverValue;
	}
	else
	{
		Animation *anim = mSkill->GetCharacter()->GetAnimByID(mCurActAnimID);
		if (anim)
			return anim->GetTime() * mSkillCallOverValue;
	}

	return 0.0f;
}
//----------------------------------------------------------------------------
void SkillStep::AddAnim(int id, float prob)
{
	SkillStep_AnimObj animObj;
	animObj.ID = id;
	animObj.Probability = prob;

	mAnimObjs.push_back(animObj);
}
//----------------------------------------------------------------------------
int SkillStep::GetNumAnims() const
{
	return (int)mAnimObjs.size();
}
//----------------------------------------------------------------------------
int SkillStep::GetAnimID(int i) const
{
	if (0 <= i && i < (int)mAnimObjs.size())
	{
		return mAnimObjs[i].ID;
	}

	return 0;
}
//----------------------------------------------------------------------------
float SkillStep::GetAnimProbability(int i) const
{
	if (0 <= i && i < (int)mAnimObjs.size())
	{
		return mAnimObjs[i].Probability;
	}

	return 0;
}
//----------------------------------------------------------------------------
std::vector<SkillStep_AnimObj> &SkillStep::GetSkillStepAnimObjects()
{
	return mAnimObjs;
}
//----------------------------------------------------------------------------
void SkillStep::AddEffectObj(EffectType type, const SkillStep_EffectObj &obj)
{
	mEffectObjs[type] = obj;
}
//----------------------------------------------------------------------------
SkillStep_EffectObj *SkillStep::GetEffectObj(EffectType type)
{
	std::map<EffectType, SkillStep_EffectObj>::iterator it = 
		mEffectObjs.find(type);
	if (it != mEffectObjs.end())
	{
		return &(it->second);
	}

	return 0;
}
//----------------------------------------------------------------------------
void SkillStep::OnEnter(SkillInstance *instance)
{
	PX2_UNUSED(instance);

	if (ScriptManager::GetSingletonPtr())
	{
		if (!mScriptHandler_Enter.empty())
		{
			CallString(mScriptHandler_Enter.c_str());
		}
	}
}
//----------------------------------------------------------------------------
void SkillStep::OnLeave(SkillInstance *instance)
{
	PX2_UNUSED(instance);
}
//----------------------------------------------------------------------------
bool SkillStep::SetNextStep(SkillStep *next)
{
	if (next == this)
		return false;

	if (mNextStep == next)
		return false;

	if (mNextStep)
		mNextStep->SetSkill(0);

	mNextStep = next;
	if (mNextStep)
		mNextStep->SetSkill(GetSkill());

	return true;
}
//----------------------------------------------------------------------------
void Skill::ClearSkillInstance()
{
	mSkillInstances.clear();
}
//----------------------------------------------------------------------------
bool Skill::SetFirstSkillStep(SkillStep *step)
{
	if (mFirstSkillStep == step)
		return false;

	if (mFirstSkillStep)
		mFirstSkillStep->SetSkill(0);

	mFirstSkillStep = step;

	if (mFirstSkillStep)
		mFirstSkillStep->SetSkill(this);

	return true;
}
//----------------------------------------------------------------------------
SkillStep *Skill::GetSkillStepByName(const std::string &name)
{
	SkillStep *step = mFirstSkillStep;

	while (step)
	{
		if (step->GetName() == name)
			return step;

		step = step->GetNextStep();
	}

	return 0;
}
//----------------------------------------------------------------------------
SkillStep *Skill::GetLastSkillStep()
{
	SkillStep *beforeStep = mFirstSkillStep;
	SkillStep *step = mFirstSkillStep;

	while (step)
	{
		beforeStep = step;
		step = step->GetNextStep();
	}

	return beforeStep;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
SkillStep::SkillStep(LoadConstructor value) :
Object(value),
mSkill(0),
mCurEnteredSkillInstance(0),
mProbability(0.0f),
mMode(M_RANGETIME),
mSkillCallOverTimeType(TT_ANIMPERCENT),
mSkillCallOverValue(0.0f),
mIsSkillCallOverAtThisStep(false),
mCurActAnimID(0)
{
	PX2_UNUSED(value);
}
//----------------------------------------------------------------------------
void SkillStep::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Object::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(SkillStep, source);
}
//----------------------------------------------------------------------------
void SkillStep::Link(InStream& source)
{
	Object::Link(source);
}
//----------------------------------------------------------------------------
void SkillStep::PostLink()
{
	Object::PostLink();
}
//----------------------------------------------------------------------------
bool SkillStep::Register(OutStream& target) const
{
	if (Object::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void SkillStep::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Object::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(SkillStep, target);
}
//----------------------------------------------------------------------------
int SkillStep::GetStreamingSize(Stream &stream) const
{
	int size = Object::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------