// PX2Skill.inl

//----------------------------------------------------------------------------
inline void Skill::SetCharacter(Character *chara)
{
	mCharacter = chara;
}
//----------------------------------------------------------------------------
inline Character *Skill::GetCharacter()
{
	return mCharacter;
}
//----------------------------------------------------------------------------
inline int Skill::GetTypeID() const
{
	return mTypeID;
}
//----------------------------------------------------------------------------
inline void Skill::SetDefPointer(void *pointer)
{
	mDefPointer = pointer;
}
//----------------------------------------------------------------------------
inline void *Skill::GetDefPointer()
{
	return mDefPointer;
}
//----------------------------------------------------------------------------
inline void Skill::SetBeRangeType(bool isRangeType)
{
	mIsRangeType = isRangeType;
}
//----------------------------------------------------------------------------
inline bool Skill::IsRangeType() const
{
	return mIsRangeType;
}
//----------------------------------------------------------------------------
inline void Skill::SetNumRangeLock(int num)
{
	mNumRangeLock = num;
}
//----------------------------------------------------------------------------
inline int Skill::GetNumRangeLock() const
{
	return mNumRangeLock;
}
//----------------------------------------------------------------------------
inline void Skill::SetNearFarType(NearFarType type)
{
	mNearFarType = type;
}
//----------------------------------------------------------------------------
inline Skill::NearFarType Skill::GetNearFarType() const
{
	return mNearFarType;
}
//----------------------------------------------------------------------------
inline void Skill::SetShapeType(ShapeType type)
{
	mShapeType = type;
}
//----------------------------------------------------------------------------
inline Skill::ShapeType Skill::GetShapeType() const
{
	return mShapeType;
}
//----------------------------------------------------------------------------
inline void Skill::SetPursurtTarget(bool isPursurtTarget)
{
	mIsPursurtTarget = isPursurtTarget;
}
//----------------------------------------------------------------------------
inline bool Skill::IsPursurtTarget() const
{
	return mIsPursurtTarget;
}
//----------------------------------------------------------------------------
inline void Skill::SetPriority(int priority)
{
	mPriority = priority;
}
//----------------------------------------------------------------------------
inline int Skill::GetPriority() const
{
	return mPriority;
}
//----------------------------------------------------------------------------
inline void Skill::SetOnCD(bool cd)
{
	mIsOnCD = cd;
}
//----------------------------------------------------------------------------
inline bool Skill::IsOnCD() const
{
	return mIsOnCD;
}
//----------------------------------------------------------------------------
inline void Skill::SetOnCDTime(float onCDTime)
{
	mOnCDTime = onCDTime;
}
//----------------------------------------------------------------------------
inline float Skill::GetOnCDTime() const
{
	return mOnCDTime;
}
//----------------------------------------------------------------------------
inline void Skill::PauseCD(bool pause)
{
	mIsPauseCD = pause;
}
//----------------------------------------------------------------------------
inline bool Skill::IsPauseCD() const
{
	return mIsPauseCD;
}
//----------------------------------------------------------------------------
inline bool Skill::IsActivatting() const
{
	return mIsActivatting;
}
//----------------------------------------------------------------------------
inline void Skill::SetAffectGroupType(AffectGroupType type)
{
	mAffectGroupType = type;
}
//----------------------------------------------------------------------------
inline Skill::AffectGroupType Skill::GetAffectGroupType() const
{
	return mAffectGroupType;
}
//----------------------------------------------------------------------------
inline int Skill::GetNumInstances() const
{
	return (int)mSkillInstances.size();
}
//----------------------------------------------------------------------------
inline SkillStep *Skill::GetFirstSkillStep()
{
	return mFirstSkillStep;
}
//----------------------------------------------------------------------------