/*
*
* ÎÄ¼þÃû³Æ	£º	PX2SkillCDTimeBuf.inl
*
*/

//----------------------------------------------------------------------------
inline void SkillCDTimeBuf::SetSkillName (const std::string &skillName)
{
	mSkillName = skillName;
}
//----------------------------------------------------------------------------
inline const std::string &SkillCDTimeBuf::GetSkillName () const
{
	return mSkillName;
}
//----------------------------------------------------------------------------
inline void SkillCDTimeBuf::SetMode (Mode mode)
{
	mMode = mode;
}
//----------------------------------------------------------------------------
inline SkillCDTimeBuf::Mode SkillCDTimeBuf::GetMode () const
{
	return mMode;
}
//----------------------------------------------------------------------------
inline void SkillCDTimeBuf::SetValue (float percent)
{
	mValue = percent;
}
//----------------------------------------------------------------------------
inline float SkillCDTimeBuf::GetValue () const
{
	return mValue;
}
//----------------------------------------------------------------------------
inline void SkillCDTimeBuf::SetLastingMaxTime (float lastingMaxTime)
{
	mLastingMaxTime = lastingMaxTime;
}
//----------------------------------------------------------------------------
inline float SkillCDTimeBuf::GetLastingMaxTime () const
{
	return mLastingMaxTime;
}
//----------------------------------------------------------------------------