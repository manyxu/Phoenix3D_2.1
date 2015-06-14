// PX2SkillComponent.inl

//----------------------------------------------------------------------------
inline int SkillController::GetNumSkills() const
{
	return (int)mSkills.size();
}
//----------------------------------------------------------------------------
inline Skill *SkillController::GetDefSkill()
{
	return mDefSkill;
}
//----------------------------------------------------------------------------
inline void SkillController::SetWatchDistance(float dist)
{
	mWatchDistance = dist;
}
//----------------------------------------------------------------------------
inline float SkillController::GetWatchDistance() const
{
	return mWatchDistance;
}
//----------------------------------------------------------------------------
inline int SkillController::GetAimTarget() const
{
	return mAimTargetID;
}
//----------------------------------------------------------------------------
inline void SkillController::SetCanBeAimed(bool can)
{
	mIsCanAimed = can;
}
//----------------------------------------------------------------------------
inline bool SkillController::IsCanBeAimed() const
{
	return mIsCanAimed;
}
//----------------------------------------------------------------------------
inline int SkillController::GetNumAimingMe() const
{
	return mNumAimingMe;
}
//----------------------------------------------------------------------------