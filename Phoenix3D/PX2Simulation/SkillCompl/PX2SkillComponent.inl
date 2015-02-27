// PX2SkillComponent.inl

//----------------------------------------------------------------------------
inline int SkillComponent::GetNumSkills() const
{
	return (int)mSkills.size();
}
//----------------------------------------------------------------------------
inline Skill *SkillComponent::GetDefSkill()
{
	return mDefSkill;
}
//----------------------------------------------------------------------------
inline void SkillComponent::SetWatchDistance(float dist)
{
	mWatchDistance = dist;
}
//----------------------------------------------------------------------------
inline float SkillComponent::GetWatchDistance() const
{
	return mWatchDistance;
}
//----------------------------------------------------------------------------
inline int SkillComponent::GetAimTarget() const
{
	return mAimTargetID;
}
//----------------------------------------------------------------------------
inline void SkillComponent::SetCanBeAimed(bool can)
{
	mIsCanAimed = can;
}
//----------------------------------------------------------------------------
inline bool SkillComponent::IsCanBeAimed() const
{
	return mIsCanAimed;
}
//----------------------------------------------------------------------------
inline int SkillComponent::GetNumAimingMe() const
{
	return mNumAimingMe;
}
//----------------------------------------------------------------------------