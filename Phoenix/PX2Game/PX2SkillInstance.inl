/*
*
* ÎÄ¼þÃû³Æ	£º	PX2SkillInstance.inl
*
*/

//----------------------------------------------------------------------------
inline int SkillInstance::GetCurInstanceID () const
{
	return mCurInstanceID;
}
//----------------------------------------------------------------------------
inline void SkillInstance::SetBeShared (bool shared)
{
	mIsShared = shared;
}
//----------------------------------------------------------------------------
inline bool SkillInstance::IsBeShared () const
{
	return mIsShared;
}
//----------------------------------------------------------------------------
inline bool SkillInstance::IsSkillCallOver () const
{
	return mIsSkillCallOver;
}
//----------------------------------------------------------------------------
inline Skill *SkillInstance::GetSkill ()
{
	return mSkill;
}
//----------------------------------------------------------------------------
inline bool SkillInstance::IsOver () const
{
	return mIsOver;
}
//----------------------------------------------------------------------------
inline void SkillInstance::SetAimTarget (int id)
{
	mAnimTarget = id;
}
//----------------------------------------------------------------------------
inline int SkillInstance::GetAimTarget () const
{
	return mAnimTarget;
}
//----------------------------------------------------------------------------
inline int SkillInstance::GetNumTargets () const
{
	return (int)mTargets.size();
}
//----------------------------------------------------------------------------