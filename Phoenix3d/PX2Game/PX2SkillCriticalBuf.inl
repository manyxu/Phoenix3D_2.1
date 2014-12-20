/*
*
* ÎÄ¼þÃû³Æ	£º	PX2SkillCriticalBuf.inl
*
*/

//----------------------------------------------------------------------------
inline void SkillCriticalBuf::SetSkillName (const std::string &name)
{
	mSkillName = name;
}
//----------------------------------------------------------------------------
inline const std::string &SkillCriticalBuf::GetSkillName () const
{
	return mSkillName;
}
//----------------------------------------------------------------------------
inline void SkillCriticalBuf::SetPercent (float percent)
{
	mPercent = percent;
}
//----------------------------------------------------------------------------
inline float SkillCriticalBuf::GetPercent () const
{
	return mPercent;
}
//----------------------------------------------------------------------------
inline void SkillCriticalBuf::SetProbability (float prob)
{
	mProbability = prob;
}
//----------------------------------------------------------------------------
inline float SkillCriticalBuf::GetProbability () const
{
	return mProbability;
}
//----------------------------------------------------------------------------