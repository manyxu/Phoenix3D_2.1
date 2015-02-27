// PX2SkillStep.inl

//----------------------------------------------------------------------------
inline Skill *SkillStep::GetSkill()
{
	return mSkill;
}
//----------------------------------------------------------------------------
inline SkillInstance *SkillStep::GetCurEnteredSkillInstance()
{
	return mCurEnteredSkillInstance;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetProbability(float pro)
{
	mProbability = pro;
}
//----------------------------------------------------------------------------
inline float SkillStep::GetProbability() const
{
	return mProbability;
}
//----------------------------------------------------------------------------
inline SkillStep::Mode SkillStep::GetMode() const
{
	return mMode;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetSkillCallOverTimeType(TimeType type)
{
	mSkillCallOverTimeType = type;
}
//----------------------------------------------------------------------------
inline SkillStep::TimeType SkillStep::GetSkillCallOverTimeType() const
{
	return mSkillCallOverTimeType;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetSkillCallOverValue(float val)
{
	mSkillCallOverValue = val;
}
//----------------------------------------------------------------------------
inline float SkillStep::GetSkillCallOverValue() const
{
	return mSkillCallOverValue;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetSkillCallOverAtThisStep(bool callOver)
{
	mIsSkillCallOverAtThisStep = callOver;
}
//----------------------------------------------------------------------------
inline bool SkillStep::IsSkillCallOverAtThisStep() const
{
	return mIsSkillCallOverAtThisStep;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetScriptHandler_Enter(const std::string &handler)
{
	mScriptHandler_Enter = handler;
}
//----------------------------------------------------------------------------
inline const std::string &SkillStep::GetScriptHandler_Enter() const
{
	return mScriptHandler_Enter;
}
//----------------------------------------------------------------------------
inline SkillStep *SkillStep::GetNextStep()
{
	return mNextStep;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetSkill(Skill *skill)
{
	mSkill = skill;
}
//----------------------------------------------------------------------------