/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Skill.cpp
*
*/

//----------------------------------------------------------------------------
inline void Skill::SetCharacter (Character *character)
{
	mCharacter = character;
}
//----------------------------------------------------------------------------
inline Character *Skill::GetCharacter ()
{
	return mCharacter;
}
//----------------------------------------------------------------------------
inline int Skill::GetID () const
{
	return mID;
}
//----------------------------------------------------------------------------
inline int Skill::GetTypeID () const
{
	return mTypeID;
}
//----------------------------------------------------------------------------
inline const std::string &Skill::GetTypeString () const
{
	return mTypeString;
}
//----------------------------------------------------------------------------
inline void Skill::SetDefPointer (void *pointer)
{
	mDefPointer = pointer;
}
//----------------------------------------------------------------------------
inline void *Skill::GetDefPointer ()
{
	return mDefPointer;
}
//----------------------------------------------------------------------------
inline void Skill::SetActivateProbability (float prob)
{
	mActivateProbability = prob;
}
//----------------------------------------------------------------------------
inline float Skill::GetActivateProbability () const
{
	return mActivateProbability;
}
//----------------------------------------------------------------------------
inline void Skill::SetPriority (int priority)
{
	mPriority = priority;
}
//----------------------------------------------------------------------------
inline int Skill::GetPriority () const
{
	return mPriority;
}
//----------------------------------------------------------------------------
inline void Skill::SetPositive (bool passive)
{
	mIsPositive = passive;
}
//----------------------------------------------------------------------------
inline bool Skill::IsPositive () const
{
	return mIsPositive;
}
//----------------------------------------------------------------------------
inline void Skill::SetDieActivate (bool dieAct)
{
	mIsDieActivate = dieAct;
}
//----------------------------------------------------------------------------
inline bool Skill::IsDieActivate () const
{
	return mIsDieActivate;
}
//----------------------------------------------------------------------------
inline void Skill::SetBeRangeAffect (bool rangeAffect)
{
	mIsRangeAffect = rangeAffect;
}
//----------------------------------------------------------------------------
inline bool Skill::IsRangeAffect () const
{
	return mIsRangeAffect;
}
//----------------------------------------------------------------------------
inline void Skill::SetNumTargetsLock (int num)
{
	mNumTargetsLock = num;
}
//----------------------------------------------------------------------------
inline int Skill::GetNumTargetsLock () const
{
	return mNumTargetsLock;
}
//----------------------------------------------------------------------------
inline void Skill::SetRangeType (RangeType type)
{
	mRangeType = type;
}
//----------------------------------------------------------------------------
inline Skill::RangeType Skill::GetRangeType () const
{
	return mRangeType;
}
//----------------------------------------------------------------------------
inline void Skill::SetShapeType (ShapeType type)
{
	mShapeType = type;
}
//----------------------------------------------------------------------------
inline Skill::ShapeType Skill::GetShapeType () const
{
	return mShapeType;
}
//----------------------------------------------------------------------------
inline void Skill::SetHasTrack (bool hasTrack)
{
	mIsHasTrack = hasTrack;
}
//----------------------------------------------------------------------------
inline bool Skill::IsHasTrack () const
{
	return mIsHasTrack;
}
//----------------------------------------------------------------------------
inline void Skill::SetAbleToBuilding (bool ableToBuilding)
{
	mIsAbleToBuilding = ableToBuilding;
}
//----------------------------------------------------------------------------
inline bool Skill::IsAbleToBuilding () const
{
	return mIsAbleToBuilding;
}
//----------------------------------------------------------------------------
inline void Skill::SetNumMultiInstance (int numMulti)
{
	mNumMultiInstance = numMulti;
}
//----------------------------------------------------------------------------
inline int Skill::GetNumMultiInstance () const
{
	return mNumMultiInstance;
}
//----------------------------------------------------------------------------
inline int Skill::GetLevel () const
{
	return mLevel;
}
//----------------------------------------------------------------------------
inline int Skill::GetMaxLevel () const
{
	return mMaxLevel;
}
//----------------------------------------------------------------------------
inline void Skill::SetScriptHandler_OnAdded (const std::string &handler)
{
	mScriptHandler_OnAdded = handler;
}
//----------------------------------------------------------------------------
inline const std::string &Skill::GetScriptHandler_OnAdded () const
{
	return mScriptHandler_OnAdded;
}
//----------------------------------------------------------------------------
inline void Skill::SetScriptHandler_OnRemove (const std::string &handler)
{
	mScriptHandler_OnRemove = handler;
}
//----------------------------------------------------------------------------
inline const std::string &Skill::GetScriptHandler_OnRemove () const
{
	return mScriptHandler_OnRemove;
}
//----------------------------------------------------------------------------
inline void Skill::SetActivateNeedCharacterAimTarget (bool need)
{
	mIsActivateNeedCharacterAnimTarget = need;
}
//----------------------------------------------------------------------------
inline bool Skill::IsActivateNeedCharacterAnimTarget () const
{
	return mIsActivateNeedCharacterAnimTarget;
}
//----------------------------------------------------------------------------
inline void Skill::SetActivateAllowTimes (int times)
{
	mActivateAllowTimes = times;
}
//----------------------------------------------------------------------------
inline int Skill::GetActivateAllowTimes () const
{
	return mActivateAllowTimes;
}
//----------------------------------------------------------------------------
inline void Skill::SetActivatedTimes (int times)
{
	mActivatedTimes = times;
}
//----------------------------------------------------------------------------
inline int Skill::GetActivatedTimes () const
{
	return mActivatedTimes;
}
//----------------------------------------------------------------------------
inline int Skill::GetPhysicsAP () const
{
	return mPhysicsAP;
}
//----------------------------------------------------------------------------
inline int Skill::GetMagicAP () const
{
	return mMagicAP;
}
//----------------------------------------------------------------------------
inline float Skill::GetCriticalPercent () const
{
	return mCriticalPercent;
}
//----------------------------------------------------------------------------
inline float Skill::GetCriticalProbability () const
{
	return mCriticalProbability;
}
//----------------------------------------------------------------------------
inline void Skill::SetOnCD (bool cd)
{
	mIsOnCD = cd;
}
//----------------------------------------------------------------------------
inline bool Skill::IsOnCD() const
{
	return mIsOnCD;
}
//----------------------------------------------------------------------------
inline void Skill::SetOnCDTime (float onCDTime)
{
	mOnCDTime = onCDTime;
}
//----------------------------------------------------------------------------
inline float Skill::GetOnCDTime () const
{
	return mOnCDTime;
}
//----------------------------------------------------------------------------
inline int Skill::GetNumInstances () const
{
	return (int)mSkillInstances.size();
}
//----------------------------------------------------------------------------
inline bool Skill::IsActivatting () const
{
	return mIsActivatting;
}
//----------------------------------------------------------------------------
inline SkillStep *Skill::GetFirstSkillStep ()
{
	return mFirstSkillStep;
}
//----------------------------------------------------------------------------
inline void Skill::SetAffectGroupType (AffectGroupType type)
{
	mAffectGroupType = type;
}
//----------------------------------------------------------------------------
inline Skill::AffectGroupType Skill::GetAffectGroupType () const
{
	return mAffectGroupType;
}
//----------------------------------------------------------------------------