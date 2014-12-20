/*
*
* 文件名称	：	PX2SkillStep.cpp
*
*/

#include "PX2SkillStep.hpp"
#include "PX2Character.hpp"
#include "PX2Scene.hpp"
#include "PX2Skill.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2DeletingManager.hpp"
#include "PX2LogicManager.hpp"
#include "PX2ScriptManager.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Gameable, SkillStep);
PX2_IMPLEMENT_STREAM(SkillStep);
PX2_IMPLEMENT_FACTORY(SkillStep);
PX2_IMPLEMENT_DEFAULT_NAMES(Gameable, SkillStep);

//----------------------------------------------------------------------------
SkillStep::SkillStep (Mode mode)
	:
mSkill(0),
mCurEnteredSkillInstance(0),
mProbability(1),
mMode(mode),
mAnimProb(1.0f),
mAnimProb1(0.0f),
mIsSkillCallOverAtThisStep(false),
mSkillCallOverTimeType(TT_ANIMPERCENT),
mSkillCallOverValue(1.0f),
mSelfEffectTime(4.0f),
mSelfPosEffectTime(4.0f),
mSelfPosEffectDelayTime(0.0f),
mSelfEffect1Time(4.0f),
mSelfPosEffect1Time(4.0f),
mSelfPosEffectDelayTime1(0.0f),
mTargetEffectTime(4.0f),
mTargetPosEffectTime(4.0f)
{
}
//----------------------------------------------------------------------------
SkillStep::~SkillStep ()
{
}
//----------------------------------------------------------------------------
void SkillStep::SetSkill (Skill *skill)
{
	mSkill = skill;

	SkillStep *nextStep = GetNextStep();
	if (nextStep)
	{
		nextStep->SetSkill(mSkill);
	}
}
//----------------------------------------------------------------------------
float SkillStep::GetSkillCallOverTime () const
{
	if (TT_TIME == mSkillCallOverTimeType)
	{
		return mSkillCallOverValue;
	}
	else
	{
		Animation *anim = mSkill->GetCharacter()->GetAnimByName(mAnimName);
		if (anim)
		{
			return anim->GetTime() * mSkillCallOverValue;
		}
	}

	return 0.0f;
}
//----------------------------------------------------------------------------
bool SkillStep::SetNextStep (SkillStep *next)
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
void SkillStep::OnLeave (SkillInstance *instance)
{
	PX2_UNUSED(instance);

	if (ScriptManager::GetSingletonPtr())
	{
		if (!IsRegistedToScriptSystem())
			RegistToScriptSystem();
	}

	if (ScriptManager::GetSingletonPtr())
	{
		if (!mScriptHandler_Leave.empty())
		{
			CallString(mScriptHandler_Leave.c_str());
		}
	}

	mCurEnteredSkillInstance = 0;
}
//----------------------------------------------------------------------------
void SkillStep::OnEnter (SkillInstance *instance)
{
	if (ScriptManager::GetSingletonPtr())
	{
		if (!IsRegistedToScriptSystem())
			RegistToScriptSystem();
	}

	mCurEnteredSkillInstance = instance;

	if (ScriptManager::GetSingletonPtr())
	{
		if (!mScriptHandler_Enter.empty())
		{
			CallString(mScriptHandler_Enter.c_str());
		}
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property 
//----------------------------------------------------------------------------
void SkillStep::RegistProperties ()
{
	Gameable::RegistProperties();

	AddPropertyClass("SkillStep");

	std::vector<std::string> modes;
	modes.push_back("M_RANGETIME");
	modes.push_back("M_CONDITION_FLYTO");
	AddPropertyEnum("Mode", (int)GetMode(), modes, false);

	AddProperty("Probability", PT_FLOAT, GetProbability());

	AddProperty("IsSkillCallOverAtThisStep", PT_BOOL, IsSkillCallOverAtThisStep());
	std::vector<std::string> callOverTimeTypes;
	callOverTimeTypes.push_back("TT_TIME");
	callOverTimeTypes.push_back("TT_ANIMPERCENT");
	AddPropertyEnum("SkillCallOverTimeType", (int)GetSkillCallOverTimeType(), callOverTimeTypes);
	AddProperty("SkillCallOverValue", PT_FLOAT, GetSkillCallOverValue());

	AddProperty("AnimName", PT_STRING, GetAnimName());
	AddProperty("AnimName1", PT_STRING, GetAnimName1());

	AddProperty("SelfEffectFilename", PT_STRINGBUTTON, GetSelfEffectFilename());
	AddProperty("SelfEffectAnchor", PT_STRING, GetSelfEffectAnchor());
	AddProperty("SelfEffectTime", PT_FLOAT, GetSelfEffectTime());

	AddProperty("SelfPosEffectFilename", PT_STRINGBUTTON, GetSelfPosEffectFilename());
	AddProperty("SelfPosEffectAnchor", PT_STRING, GetSelfPosEffectAnchor());
	AddProperty("SelfPosEffectTime", PT_FLOAT, GetSelfPosEffectTime());

	AddProperty("TargetEffectFilename", PT_STRINGBUTTON, GetTargetEffectFilename());
	AddProperty("TargetEffectAnchor", PT_STRING, GetTargetEffectAnchor());
	AddProperty("TargetEffectTime", PT_FLOAT, GetTargetEffectTime());

	AddProperty("TargetPosEffectFilename", PT_STRINGBUTTON, GetTargetPosEffectFilename());
	AddProperty("TargetPosEffectTime", PT_FLOAT, GetTargetPosEffectTime());

	AddProperty("ScriptHandler_Enter", PT_STRING, GetScriptHandler_Enter());
	AddProperty("ScriptHandler_Leave", PT_STRING, GetScriptHandler_Leave());
}
//----------------------------------------------------------------------------
void SkillStep::OnPropertyChanged (const PropertyObject &obj)
{
	Gameable::OnPropertyChanged(obj);

	if ("Probability" == obj.Name)
	{
		SetProbability(PX2_ANY_AS(obj.Data, float));
	}
	else if ("IsSkillCallOverAtThisStep" == obj.Name)
	{
		SetSkillCallOverAtThisStep(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("SkillCallOverTimeType" == obj.Name)
	{
		SetSkillCallOverTimeType((TimeType)PX2_ANY_AS(obj.Data, int));
	}
	else if ("SkillCallOverValue" == obj.Name)
	{
		SetSkillCallOverValue(PX2_ANY_AS(obj.Data, float));
	}
	else if ("AnimName" == obj.Name)
	{
		SetAnimName(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("AnimName1" == obj.Name)
	{
		SetAnimName1(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("SelfEffectFilename" == obj.Name)
	{
		SetSelfEffectFilename(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("SelfEffectAnchor" == obj.Name)
	{
		SetSelfEffectAnchor(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("SelfEffectTime" == obj.Name)
	{
		SetSelfEffectTime(PX2_ANY_AS(obj.Data, float));
	}
	else if ("SelfPosEffectFilename" == obj.Name)
	{
		SetSelfPosEffectFilename(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("SelfPosEffectAnchor" == obj.Name)
	{
		SetSelfPosEffectAnchor(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("SelfPosEffectTime" == obj.Name)
	{
		SetSelfPosEffectTime(PX2_ANY_AS(obj.Data, float));
	}
	else if ("TargetEffectFilename" == obj.Name)
	{
		SetTargetEffectFilename(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("TargetEffectAnchor" == obj.Name)
	{
		SetTargetEffectAnchor(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("TargetEffectTime" == obj.Name)
	{
		SetTargetEffectTime(PX2_ANY_AS(obj.Data, float));
	}
	else if ("TargetPosEffectFilename" == obj.Name)
	{
		SetTargetPosEffectFilename(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("TargetPosEffectTime" == obj.Name)
	{
		SetTargetPosEffectTime(PX2_ANY_AS(obj.Data, float));
	}
	else if ("ScriptHandler_Leave" == obj.Name)
	{
		SetScriptHandler_Leave(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("ScriptHandler_Enter" == obj.Name)
	{
		SetScriptHandler_Enter(PX2_ANY_AS(obj.Data, std::string));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
SkillStep::SkillStep (LoadConstructor value)
	:
Gameable(value),
mSkill(0),
mCurEnteredSkillInstance(0),
mMode(M_RANGETIME),
mAnimProb(1.0f),
mAnimProb1(0.0f),
mIsSkillCallOverAtThisStep(false),
mSkillCallOverTimeType(TT_ANIMPERCENT),
mSkillCallOverValue(1.0f),
mProbability(1.0f),
mSelfEffectTime(3.0f),
mSelfPosEffectTime(3.0f),
mSelfPosEffectDelayTime(0.0f),
mSelfEffect1Time(3.0f),
mSelfPosEffect1Time(3.0f),
mSelfPosEffectDelayTime1(0.0f),
mTargetEffectTime(3.0f),
mTargetPosEffectTime(3.0f)
{
}
//----------------------------------------------------------------------------
void SkillStep::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Gameable::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadEnum(mMode);
	source.Read(mProbability);
	source.ReadBool(mIsSkillCallOverAtThisStep);
	source.ReadEnum(mSkillCallOverTimeType);
	source.Read(mSkillCallOverValue);
	source.ReadString(mAnimName);
	source.ReadString(mAnimName1);

	source.ReadString(mSelfEffectFilename);
	source.ReadString(mSelfEffectAnchor);
	source.Read(mSelfEffectTime);
	source.ReadString(mSelfPosEffectFilename);
	source.ReadString(mSelfPosEffectAnchor);

	source.ReadString(mSelfEffect1Filename);
	source.ReadString(mSelfEffect1Anchor);
	source.Read(mSelfEffect1Time);
	source.ReadString(mSelfPosEffect1Filename);
	source.ReadString(mSelfPosEffect1Anchor);

	source.Read(mSelfPosEffectTime);
	source.ReadString(mTargetEffectFilename);
	source.ReadString(mTargetEffectAnchor);
	source.Read(mTargetEffectTime);
	source.ReadString(mTargetPosEffectFilename);
	source.Read(mTargetPosEffectTime);

	source.ReadPointer(mNextStep);

	source.ReadString(mScriptHandler_Enter);

	PX2_END_DEBUG_STREAM_LOAD(SkillStep, source);
}
//----------------------------------------------------------------------------
void SkillStep::Link (InStream& source)
{
	Gameable::Link(source);

	source.ResolveLink(mNextStep);
}
//----------------------------------------------------------------------------
void SkillStep::PostLink ()
{
	Gameable::PostLink();
}
//----------------------------------------------------------------------------
bool SkillStep::Register (OutStream& target) const
{
	if (Gameable::Register(target))
	{
		target.Register(mNextStep);

		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void SkillStep::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Gameable::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteEnum(mMode);
	target.Write(mProbability);
	target.WriteBool(mIsSkillCallOverAtThisStep);
	target.WriteEnum(mSkillCallOverTimeType);
	target.Write(mSkillCallOverValue);
	target.WriteString(mAnimName);
	target.WriteString(mAnimName1);

	target.WriteString(mSelfEffectFilename);
	target.WriteString(mSelfEffectAnchor);
	target.Write(mSelfEffectTime);
	target.WriteString(mSelfPosEffectFilename);
	target.WriteString(mSelfPosEffectAnchor);
	target.Write(mSelfPosEffectTime);

	target.WriteString(mSelfEffect1Filename);
	target.WriteString(mSelfEffect1Anchor);
	target.Write(mSelfEffect1Time);
	target.WriteString(mSelfPosEffect1Filename);
	target.WriteString(mSelfPosEffect1Anchor);
	target.Write(mSelfPosEffect1Time);

	target.WriteString(mTargetEffectFilename);
	target.WriteString(mTargetEffectAnchor);
	target.Write(mTargetEffectTime);
	target.WriteString(mTargetPosEffectFilename);
	target.Write(mTargetPosEffectTime);

	target.WritePointer(mNextStep);

	target.WriteString(mScriptHandler_Enter);

	PX2_END_DEBUG_STREAM_SAVE(SkillStep, target);
}
//----------------------------------------------------------------------------
int SkillStep::GetStreamingSize (Stream &stream) const
{
	int size = Gameable::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_ENUMSIZE(mMode);
	size += sizeof(mProbability);
	size += PX2_BOOLSIZE(mIsSkillCallOverAtThisStep);
	size += PX2_BOOLSIZE(mSkillCallOverTimeType);
	size += sizeof(mSkillCallOverValue);
	size += PX2_STRINGSIZE(mAnimName);
	size += PX2_STRINGSIZE(mAnimName1);

	size += PX2_STRINGSIZE(mSelfEffectFilename);
	size += PX2_STRINGSIZE(mSelfEffectAnchor);
	size += sizeof(mSelfEffectTime);
	size += PX2_STRINGSIZE(mSelfPosEffectFilename);
	size += PX2_STRINGSIZE(mSelfPosEffectAnchor);
	size += sizeof(mSelfPosEffectTime);

	size += PX2_STRINGSIZE(mSelfEffect1Filename);
	size += PX2_STRINGSIZE(mSelfEffect1Anchor);
	size += sizeof(mSelfEffect1Time);
	size += PX2_STRINGSIZE(mSelfPosEffect1Filename);
	size += PX2_STRINGSIZE(mSelfPosEffect1Anchor);
	size += sizeof(mSelfPosEffect1Time);

	size += PX2_STRINGSIZE(mTargetEffectFilename);
	size += PX2_STRINGSIZE(mTargetEffectAnchor);
	size += sizeof(mTargetEffectTime);
	size += PX2_STRINGSIZE(mTargetPosEffectFilename);
	size += sizeof(mTargetPosEffectTime);

	size += PX2_POINTERSIZE(mNextStep);

	size += PX2_STRINGSIZE(mScriptHandler_Enter);

	return size;
}
//----------------------------------------------------------------------------