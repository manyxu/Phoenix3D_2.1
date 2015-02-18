// PX2Skill.cpp

#include "PX2Skill.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Object, Skill);
PX2_IMPLEMENT_STREAM(Skill);
PX2_IMPLEMENT_FACTORY(Skill);
PX2_IMPLEMENT_DEFAULT_NAMES(Object, Skill);

//----------------------------------------------------------------------------
PX2_IMPLEMENT_PM_F(Skill, ActivateProbability);
PX2_IMPLEMENT_PM_F(Skill, NumMultiInstance);
PX2_IMPLEMENT_PM_F(Skill, CDTime);
PX2_IMPLEMENT_PM_F(Skill, ActivateAllowTimes);
//----------------------------------------------------------------------------
PX2_IMPLEMENT_PM_F(Skill, TrigerDistance);
PX2_IMPLEMENT_PM_F(Skill, RadiusLength);
PX2_IMPLEMENT_PM_F(Skill, Width);
PX2_IMPLEMENT_PM_F(Skill, FanDegree);
//----------------------------------------------------------------------------
Skill::Skill() :
mCharacter(0),
mDefPointer(0),
mTypeID(0),
mIsRangeType(false),
mNumRangeLock(-1),
mNearFarType(NFT_NEAR),
mShapeType(ST_SPHERE),
mIsPursurtTarget(true),
mLevel(0),
mMaxLevel(0),
mPriority(0),
mIsOnCD(false),
mOnCDTime(0.0f),
mIsActivatting(false),
mActivatedTimes(0),
mAffectGroupType(AGT_ENEMYS)
{
	PX2_INIT_PM_F(TrigerDistance);
	PX2_INIT_PM_F(RadiusLength);
	PX2_INIT_PM_F(Width);
	PX2_INIT_PM_F(FanDegree);
	PX2_INIT_PM_F(ActivateProbability);
	PX2_INIT_PM_F(NumMultiInstance);
	PX2_INIT_PM_F(CDTime);
	PX2_INIT_PM_F(ActivateAllowTimes);
}
//----------------------------------------------------------------------------
Skill::~Skill()
{
}
//----------------------------------------------------------------------------
void Skill::OnAdded()
{
}
//----------------------------------------------------------------------------
void Skill::OnRemove()
{
}
//----------------------------------------------------------------------------
void Skill::SetTypeID(int id)
{
	mTypeID = id;
}
//----------------------------------------------------------------------------
void Skill::SetLevel(int level)
{
	mLevel = level;
}
//----------------------------------------------------------------------------
void Skill::SetMaxLevel(int level)
{
	mMaxLevel = level;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Skill::Skill(LoadConstructor value) :
Object(value),
mCharacter(0),
mDefPointer(0),
mTypeID(0),
mIsRangeType(false),
mNumRangeLock(-1),
mNearFarType(NFT_NEAR),
mShapeType(ST_SPHERE),
mIsPursurtTarget(true),
mLevel(0),
mMaxLevel(0),
mPriority(0),
mIsOnCD(false),
mOnCDTime(0.0f),
mIsActivatting(false),
mActivatedTimes(0)
{
}
//----------------------------------------------------------------------------
void Skill::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Object::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(Skill, source);
}
//----------------------------------------------------------------------------
void Skill::Link(InStream& source)
{
	Object::Link(source);

	if (mFirstSkillStep)
		source.ResolveLink(mFirstSkillStep);
}
//----------------------------------------------------------------------------
void Skill::PostLink()
{
	Object::PostLink();

	if (mFirstSkillStep)
		mFirstSkillStep->SetSkill(this);
}
//----------------------------------------------------------------------------
bool Skill::Register(OutStream& target) const
{
	if (Object::Register(target))
	{
		if (mFirstSkillStep)
			target.Register(mFirstSkillStep);

		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void Skill::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Object::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(Skill, target);
}
//----------------------------------------------------------------------------
int Skill::GetStreamingSize(Stream &stream) const
{
	int size = Object::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------