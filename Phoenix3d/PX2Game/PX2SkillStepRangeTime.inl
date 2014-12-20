/*
*
* ÎÄ¼þÃû³Æ	£º	PX2SkillStepRangeTime.inl
*
*/

//----------------------------------------------------------------------------
inline void SkillStepRangeTime::SetTimeType (TimeType type)
{
	mTimeType = type;
}
//----------------------------------------------------------------------------
inline SkillStepRangeTime::TimeType SkillStepRangeTime::GetTimeType 
	() const
{
	return mTimeType;
}
//----------------------------------------------------------------------------
inline void SkillStepRangeTime::SetValue (float seconds)
{
	mValue = seconds;
}
//----------------------------------------------------------------------------
inline float SkillStepRangeTime::GetValue () const
{
	return mValue;
}
//----------------------------------------------------------------------------