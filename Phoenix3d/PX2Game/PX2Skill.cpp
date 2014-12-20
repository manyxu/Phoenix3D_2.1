/*
*
* 文件名称	：	PX2Skill.cpp
*
*/

#include "PX2Skill.hpp"
#include "PX2Character.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2Time.hpp"
#include "PX2Project.hpp"
#include "PX2Scene.hpp"
#include "PX2LogicManager.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI_V(PX2, Gameable, Skill, 2);
PX2_IMPLEMENT_STREAM(Skill);
PX2_IMPLEMENT_FACTORY(Skill);
PX2_IMPLEMENT_DEFAULT_NAMES(Gameable, Skill);

//----------------------------------------------------------------------------
Skill::Skill ()
	:
mCharacter(0),
mID(0),
mTypeID(0),
mDefPointer(0),
mActivateProbability(1.0f),
mPriority(0),
mIsPositive(true),
mIsDieActivate(false),
mRangeType(RT_NEAR),
mIsHasTrack(false),
mIsAbleToBuilding(false),
mShapeType(ST_SPHERE),
mIsRangeAffect(false),
mNumTargetsLock(-1),
mNumMultiInstance(1),
mLevel(1),
mMaxLevel(1),
mIsActivateNeedCharacterAnimTarget(true),
mActivateAllowTimes(-1),
mActivatedTimes(0),
mIsOnCD(false),
mOnCDTime(2.0f),
mIsActivatting(false),
mAffectGroupType(AGT_ENEMY),
mPhysicsAP(0),
mMagicAP(0),
mCriticalPercent(0.0f),
mCriticalProbability(0.0f)
{
	PX2_INIT_PM_F(RadiusLength);
	PX2_INIT_PM_F(Width);
	PX2_INIT_PM_F(FanDegree);
	PX2_INIT_PM_F(CDTime);
	PX2_INIT_PM_F(TrigerDistance);
}
//----------------------------------------------------------------------------
Skill::~Skill ()
{
}
//----------------------------------------------------------------------------
void Skill::Initlize ()
{
	Gameable::Initlize();

	SkillStep *step = mFirstSkillStep;
	while (step)
	{
		step->Initlize();

		step = step->GetNextStep();
	}
}
//----------------------------------------------------------------------------
void Skill::Update (double appSeconds, double elapsedSeconds)
{
	Gameable::UpdateControllers(appSeconds);

	float cdTime = GetMCDTime();

	// Update CD
	if (IsOnCD())
	{
		float onCDTimeTemp = GetOnCDTime();
		onCDTimeTemp += (float)elapsedSeconds;

		if (onCDTimeTemp > cdTime)
		{
			SetOnCDTime(0.0f);
			SetOnCD(false);
		}
		else
		{
			SetOnCDTime(onCDTimeTemp);
		}
	}

	for (int i=0; i<(int)mSkillInstances.size(); i++)
	{
		mSkillInstances[i]->Update(appSeconds, elapsedSeconds);
	}

	std::vector<SkillInstancePtr>::iterator it = mSkillInstances.begin();
	for (; it!=mSkillInstances.end();)
	{
		if ((*it)->IsOver())
		{
			it = mSkillInstances.erase(it);
		}
		else
		{
			it++;
		}
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void Skill::RegistProperties ()
{
	Gameable::RegistProperties();

	AddPropertyClass("Skill");
	AddProperty("ScriptHandler_OnAdded", PT_STRING, GetScriptHandler_OnAdded());
	AddProperty("ScriptHandler_OnRemove", PT_STRING, GetScriptHandler_OnRemove());
	AddProperty("TypeID", PT_INT, GetTypeID());
	AddProperty("ActivateProbability", PT_FLOAT, GetActivateProbability());
	AddProperty("Priority", PT_INT, GetPriority());
	AddProperty("TypeString", PT_STRING, GetTypeString());
	AddProperty("IsPositive", PT_BOOL, IsPositive());
	AddProperty("IsDieActivate", PT_BOOL, IsDieActivate());

	std::vector<std::string> rangeTypes;
	rangeTypes.push_back("RT_NEAR");
	rangeTypes.push_back("RT_FAR");
	AddPropertyEnum("RageType", (int)GetRangeType(), rangeTypes);

	std::vector<std::string> shapeTypes;
	shapeTypes.push_back("ST_SPHERE");
	shapeTypes.push_back("ST_FAN");
	shapeTypes.push_back("ST_BOX");
	AddPropertyEnum("ShapeType", (int)GetShapeType(), shapeTypes);

	AddProperty("BaseRadiusLength", PT_FLOAT, GetRadiusLength());
	AddProperty("ModifiedBaseRadiusLength", PT_FLOAT, GetMRadiusLength(), false);
	AddProperty("BaseWidth", PT_FLOAT, GetWidth());
	AddProperty("ModifiedWidth", PT_FLOAT, GetMWidth(), false);
	AddProperty("BaseFanDegree", PT_FLOAT, GetFanDegree());
	AddProperty("ModifiedFanDegree", PT_FLOAT, GetMFanDegree(), false);
	AddProperty("RangeAffect", PT_BOOL, IsRangeAffect());
	AddProperty("NumTargetsLock", PT_INT, GetNumTargetsLock());
	AddProperty("NumMultiInstance", PT_INT, GetNumMultiInstance());

	AddProperty("BaseCDTime", PT_FLOAT, GetCDTime());
	AddProperty("ModifiedCDTime", PT_FLOAT, GetMCDTime(), false);	

	AddProperty("Level", PT_INT, GetLevel());
	AddProperty("MaxLevel", PT_INT, GetMaxLevel());
	AddProperty("PhysicsAP", PT_INT, GetPhysicsAP());
	AddProperty("MagicAP", PT_INT, GetMagicAP());

	std::vector<std::string> affectGroupTypes;
	affectGroupTypes.push_back("AGT_ENEMY");
	affectGroupTypes.push_back("AGT_SELF");
	affectGroupTypes.push_back("AGT_BOTH");
	AddPropertyEnum("AffectGroupType", (int)GetAffectGroupType(), affectGroupTypes);

	AddProperty("IsActivateNeedCharacterAnimTarget", PT_BOOL, IsActivateNeedCharacterAnimTarget());

	AddProperty("ActivateAllowTimes", PT_INT, GetActivateAllowTimes());
}
//----------------------------------------------------------------------------
void Skill::OnPropertyChanged (const PropertyObject &obj)
{
	Gameable::OnPropertyChanged(obj);

	if ("ScriptHandler_OnAdded" == obj.Name)
	{
		SetScriptHandler_OnAdded(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("ScriptHandler_OnRemove" == obj.Name)
	{
		SetScriptHandler_OnRemove(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("TypeID" == obj.Name)
	{
		SetTypeID(PX2_ANY_AS(obj.Data, int));
	}
	else if ("ActivateProbability" == obj.Name)
	{
		SetActivateProbability(PX2_ANY_AS(obj.Data, float));
	}
	else if ("Priority" == obj.Name)
	{
		SetPriority(PX2_ANY_AS(obj.Data, int));
	}
	else if ("TypeString" == obj.Name)
	{
		SetTypeString(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("IsPositive" == obj.Name)
	{
		SetPositive(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("IsDieActivate" == obj.Name)
	{
		SetDieActivate(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("RageType" == obj.Name)
	{
		SetRangeType((RangeType)PX2_ANY_AS(obj.Data, int));
	}
	else if ("ShapeType" == obj.Name)
	{
		SetShapeType((ShapeType)PX2_ANY_AS(obj.Data, int));
	}
	else if ("BaseRadiusLength" == obj.Name)
	{
		SetRadiusLength(PX2_ANY_AS(obj.Data, float));
	}
	else if ("BaseWidth" == obj.Name)
	{
		SetWidth(PX2_ANY_AS(obj.Data, float));
	}
	else if ("BaseFanDegree" == obj.Name)
	{
		SetFanDegree(PX2_ANY_AS(obj.Data, float));
	}
	else if ("RangeAffect" == obj.Name)
	{
		SetBeRangeAffect(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("NumTargetsLock" == obj.Name)
	{
		SetNumTargetsLock(PX2_ANY_AS(obj.Data, int));
	}
	else if ("NumMultiInstance" == obj.Name)
	{
		SetNumMultiInstance(PX2_ANY_AS(obj.Data, int));
	}
	else if ("BaseCDTime" == obj.Name)
	{
		SetCDTime(PX2_ANY_AS(obj.Data, float));
	}
	else if ("Level" == obj.Name)
	{
		SetLevel(PX2_ANY_AS(obj.Data, int));
	}
	else if ("MaxLevel" == obj.Name)
	{
		SetMaxLevel(PX2_ANY_AS(obj.Data, int));
	}
	else if ("PhysicsAP" == obj.Name)
	{
		SetPhysicsAP(PX2_ANY_AS(obj.Data, int));
	}
	else if ("MagicAP" == obj.Name)
	{
		SetMagicAP(PX2_ANY_AS(obj.Data, int));
	}
	else if ("AffectGroupType" == obj.Name)
	{
		SetAffectGroupType((AffectGroupType)PX2_ANY_AS(obj.Data, int));
	}
	else if ("IsActivateNeedCharacterAnimTarget" == obj.Name)
	{
		SetActivateNeedCharacterAimTarget(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("ActivateAllowTimes" == obj.Name)
	{
		SetActivateAllowTimes(PX2_ANY_AS(obj.Data, int));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Skill::Skill (LoadConstructor value)
	:
Gameable(value),
mCharacter(0),
mDefPointer(0),
mID(-1),
mTypeID(-1),
mActivateProbability(1.0f),
mPriority(0),
mIsPositive(true),
mIsDieActivate(false),
mRangeType(RT_NEAR),
mIsHasTrack(false),
mIsAbleToBuilding(false),
mShapeType(ST_SPHERE),
mIsRangeAffect(false),
mNumTargetsLock(-1),
mNumMultiInstance(1),
mLevel(1),
mMaxLevel(1),
mPhysicsAP(0),
mMagicAP(0),
mCriticalPercent(0.0f),
mCriticalProbability(0.0f),
mAffectGroupType(AGT_ENEMY),
mIsActivateNeedCharacterAnimTarget(true),
mActivateAllowTimes(-1),
mActivatedTimes(0),
mIsOnCD(false),
mOnCDTime(2.0f),
mIsActivatting(false)
{
	PX2_INIT_PM_F(RadiusLength);
	PX2_INIT_PM_F(Width);
	PX2_INIT_PM_F(FanDegree);
	PX2_INIT_PM_F(CDTime);
	PX2_INIT_PM_F(TrigerDistance);
}
//----------------------------------------------------------------------------
void Skill::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Gameable::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadString(mScriptHandler_OnAdded);
	source.ReadString(mScriptHandler_OnRemove);
	source.Read(mID);
	source.Read(mTypeID);
	source.Read(mActivateProbability);
	source.Read(mPriority);
	source.ReadBool(mIsPositive);
	source.ReadBool(mIsDieActivate);
	source.ReadString(mTypeString);
	source.ReadEnum(mRangeType);
	source.ReadBool(mIsHasTrack);
	source.ReadEnum(mShapeType);
	source.Read(mRadiusLength);
	source.Read(mMRadiusLength);
	source.Read(mWidth);
	source.Read(mMWidth);
	source.Read(mFanDegree);
	source.Read(mMFanDegree);
	source.ReadBool(mIsRangeAffect);
	source.Read(mNumTargetsLock);
	source.Read(mNumMultiInstance);
	source.Read(mCDTime);
	source.Read(mMCDTime);
	source.Read(mLevel);
	source.Read(mMaxLevel);
	source.Read(mPhysicsAP);
	source.Read(mMagicAP);
	source.Read(mCriticalPercent);
	source.Read(mCriticalProbability);
	source.ReadEnum(mAffectGroupType);
	source.ReadBool(mIsActivateNeedCharacterAnimTarget);
	source.Read(mActivateAllowTimes);

	source.ReadPointer(mFirstSkillStep);

	PX2_END_DEBUG_STREAM_LOAD(Skill, source);
}
//----------------------------------------------------------------------------
void Skill::Link (InStream& source)
{
	Gameable::Link(source);

	source.ResolveLink(mFirstSkillStep);
}
//----------------------------------------------------------------------------
void Skill::PostLink ()
{
	Gameable::PostLink();

	if (mFirstSkillStep)
		mFirstSkillStep->SetSkill(this);
}
//----------------------------------------------------------------------------
bool Skill::Register (OutStream& target) const
{
	if (Gameable::Register(target))
	{
		target.Register(mFirstSkillStep);

		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void Skill::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Gameable::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteString(mScriptHandler_OnAdded);
	target.WriteString(mScriptHandler_OnRemove);
	target.Write(mID);
	target.Write(mTypeID);
	target.Write(mActivateProbability);
	target.Write(mPriority);
	target.WriteBool(mIsPositive);
	target.WriteBool(mIsDieActivate);
	target.WriteString(mTypeString);
	target.WriteEnum(mRangeType);
	target.WriteBool(mIsHasTrack);
	target.WriteEnum(mShapeType);
	target.Write(mRadiusLength);
	target.Write(mMRadiusLength);
	target.Write(mWidth);
	target.Write(mMWidth);
	target.Write(mFanDegree);
	target.Write(mMFanDegree);
	target.WriteBool(mIsRangeAffect);
	target.Write(mNumTargetsLock);
	target.Write(mNumMultiInstance);
	target.Write(mCDTime);
	target.Write(mMCDTime);
	target.Write(mLevel);
	target.Write(mMaxLevel);
	target.Write(mPhysicsAP);
	target.Write(mMagicAP);
	target.Write(mCriticalPercent);
	target.Write(mCriticalProbability);
	target.Write(mAffectGroupType);
	target.WriteBool(mIsActivateNeedCharacterAnimTarget);
	target.Write(mActivateAllowTimes);

	target.WritePointer(mFirstSkillStep);

	PX2_END_DEBUG_STREAM_SAVE(Skill, target);
}
//----------------------------------------------------------------------------
int Skill::GetStreamingSize (Stream &stream) const
{
	int size = Gameable::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_STRINGSIZE(mScriptHandler_OnAdded);
	size += PX2_STRINGSIZE(mScriptHandler_OnRemove);
	size += sizeof(mID);
	size += sizeof(mTypeID);
	size += sizeof(mActivateProbability);
	size += sizeof(mPriority);
	size += PX2_BOOLSIZE(mIsPositive);
	size += PX2_BOOLSIZE(mIsDieActivate);
	size += PX2_STRINGSIZE(mTypeString);
	size += PX2_ENUMSIZE(mRangeType);
	size += PX2_BOOLSIZE(mIsHasTrack);
	size += PX2_ENUMSIZE(mShapeType);
	size += sizeof(mRadiusLength);
	size += sizeof(mMRadiusLength);
	size += sizeof(mWidth);
	size += sizeof(mMWidth);
	size += sizeof(mFanDegree);
	size += sizeof(mMFanDegree);
	size += PX2_BOOLSIZE(mIsRangeAffect);
	size += sizeof(mNumTargetsLock);
	size += sizeof(mNumMultiInstance);
	size += sizeof(mCDTime);
	size += sizeof(mMCDTime);
	size += sizeof(mLevel);
	size += sizeof(mMaxLevel);
	size += sizeof(mPhysicsAP);
	size += sizeof(mMagicAP);
	size += sizeof(mCriticalPercent);
	size += sizeof(mCriticalProbability);
	size += PX2_ENUMSIZE(mAffectGroupType);
	size += PX2_BOOLSIZE(mIsActivateNeedCharacterAnimTarget);
	size += sizeof(mActivateAllowTimes);

	size += PX2_POINTERSIZE(mFirstSkillStep);

	if (stream.IsIn())
	{
		int readedVersion = GetReadedVersion();
		if (1 <= readedVersion)
		{
			size += PX2_BOOLSIZE(mIsLearnedSkill);
		}

		if (2 <= readedVersion)
		{
			size += PX2_BOOLSIZE(mIsBoxDoRolate);
		}
	}
	else
	{
		size += PX2_BOOLSIZE(mIsLearnedSkill);
		size += PX2_BOOLSIZE(mIsBoxDoRolate);
	}

	return size;
}
//----------------------------------------------------------------------------