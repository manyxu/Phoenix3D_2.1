/*
*
* ÎÄ¼þÃû³Æ	£º	PX2SkillStep.inl
*
*/

//----------------------------------------------------------------------------
inline Skill *SkillStep::GetSkill ()
{
	return mSkill;
}
//----------------------------------------------------------------------------
inline SkillInstance *SkillStep::GetCurEnteredSkillInstance ()
{
	return mCurEnteredSkillInstance;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetProbability (float pro)
{
	mProbability = pro;
}
//----------------------------------------------------------------------------
inline float SkillStep::GetProbability () const
{
	return mProbability;
}
//----------------------------------------------------------------------------
inline SkillStep::Mode SkillStep::GetMode () const
{
	return mMode;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetSkillCallOverAtThisStep (bool callOver)
{
	mIsSkillCallOverAtThisStep = callOver;
}
//----------------------------------------------------------------------------
inline bool SkillStep::IsSkillCallOverAtThisStep () const
{
	return mIsSkillCallOverAtThisStep;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetSkillCallOverTimeType (TimeType type)
{
	mSkillCallOverTimeType = type;
}
//----------------------------------------------------------------------------
inline SkillStep::TimeType SkillStep::GetSkillCallOverTimeType () const
{
	return mSkillCallOverTimeType;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetSkillCallOverValue (float val)
{
	mSkillCallOverValue = val;
}
//----------------------------------------------------------------------------
inline float SkillStep::GetSkillCallOverValue () const
{
	return mSkillCallOverValue;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetAnimName (const std::string &animName)
{
	mAnimName = animName;
}
//----------------------------------------------------------------------------
inline const std::string &SkillStep::GetAnimName () const
{
	return mAnimName;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetAnimProb (float prob)
{
	mAnimProb = prob;
}
//----------------------------------------------------------------------------
inline float SkillStep::GetAnimProb () const
{
	return mAnimProb;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetAnimProb1 (float prob)
{
	mAnimProb1 = prob;
}
//----------------------------------------------------------------------------
inline float SkillStep::GetAnimProb1 () const
{
	return mAnimProb1;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetAnimName1 (const std::string &animName1)
{
	mAnimName1 = animName1;
}
//----------------------------------------------------------------------------
inline const std::string &SkillStep::GetAnimName1 () const
{
	return mAnimName1;
}
//----------------------------------------------------------------------------
// effect
//----------------------------------------------------------------------------
inline void SkillStep::SetSelfEffectFilename (
	const std::string &selfEffectFilename)
{
	mSelfEffectFilename = selfEffectFilename;
}
//----------------------------------------------------------------------------
inline const std::string &SkillStep::GetSelfEffectFilename () const
{
	return mSelfEffectFilename;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetSelfEffectAnchor (const std::string &selfAnchor)
{
	mSelfEffectAnchor = selfAnchor;
}
//----------------------------------------------------------------------------
inline const std::string SkillStep::GetSelfEffectAnchor () const
{
	return mSelfEffectAnchor;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetSelfEffectTime (float seconds)
{
	mSelfEffectTime = seconds;
}
//----------------------------------------------------------------------------
inline float SkillStep::GetSelfEffectTime () const
{
	return mSelfEffectTime;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetSelfPosEffectFilename (
	const std::string &posEffectFilename)
{
	mSelfPosEffectFilename = posEffectFilename;
}
//----------------------------------------------------------------------------
inline const std::string &SkillStep::GetSelfPosEffectFilename () const
{
	return mSelfPosEffectFilename;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetSelfPosEffectAnchor (const std::string &selfAnchor)
{
	mSelfPosEffectAnchor = selfAnchor;
}
//----------------------------------------------------------------------------
inline const std::string SkillStep::GetSelfPosEffectAnchor () const
{
	return mSelfPosEffectAnchor;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetSelfPosEffectTime (float seconds)
{
	mSelfPosEffectTime = seconds;
}
//----------------------------------------------------------------------------
inline float SkillStep::GetSelfPosEffectTime () const
{
	return mSelfPosEffectTime;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetSelfPosEffectDelayTime (float seconeds)
{
	mSelfPosEffectDelayTime = seconeds;
}
//----------------------------------------------------------------------------
inline float SkillStep::GetSelfPosEffectDelayTime () const
{
	return mSelfPosEffectDelayTime;
}
//----------------------------------------------------------------------------
// effect1
//----------------------------------------------------------------------------
inline void SkillStep::SetSelfEffect1Filename (
	const std::string &selfEffectFilename)
{
	mSelfEffect1Filename = selfEffectFilename;
}
//----------------------------------------------------------------------------
inline const std::string &SkillStep::GetSelfEffect1Filename () const
{
	return mSelfEffect1Filename;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetSelfEffect1Anchor (const std::string &selfAnchor)
{
	mSelfEffect1Anchor = selfAnchor;
}
//----------------------------------------------------------------------------
inline const std::string SkillStep::GetSelfEffect1Anchor () const
{
	return mSelfEffect1Anchor;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetSelfEffect1Time (float seconds)
{
	mSelfEffect1Time = seconds;
}
//----------------------------------------------------------------------------
inline float SkillStep::GetSelfEffect1Time () const
{
	return mSelfEffect1Time;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetSelfPosEffect1Filename (
	const std::string &posEffectFilename)
{
	mSelfPosEffect1Filename = posEffectFilename;
}
//----------------------------------------------------------------------------
inline const std::string &SkillStep::GetSelfPosEffect1Filename () const
{
	return mSelfPosEffect1Filename;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetSelfPosEffect1Anchor (const std::string &selfAnchor)
{
	mSelfPosEffect1Anchor = selfAnchor;
}
//----------------------------------------------------------------------------
inline const std::string SkillStep::GetSelfPosEffect1Anchor () const
{
	return mSelfPosEffect1Anchor;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetSelfPosEffect1Time (float seconds)
{
	mSelfPosEffect1Time = seconds;
}
//----------------------------------------------------------------------------
inline float SkillStep::GetSelfPosEffect1Time () const
{
	return mSelfPosEffect1Time;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetSelfPosEffectDelayTime1 (float seconeds)
{
	mSelfPosEffectDelayTime1 = seconeds;
}
//----------------------------------------------------------------------------
inline float SkillStep::GetSelfPosEffectDelayTime1 () const
{
	return mSelfPosEffectDelayTime1;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
inline void SkillStep::SetTargetEffectFilename (
	const std::string &targetEffectFilename)
{
	mTargetEffectFilename = targetEffectFilename;
}
//----------------------------------------------------------------------------
inline const std::string &SkillStep::GetTargetEffectFilename () const
{
	return mTargetEffectFilename;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetTargetEffectAnchor (const std::string &targetAnchor)
{
	mTargetEffectAnchor = targetAnchor;
}
//----------------------------------------------------------------------------
inline const std::string &SkillStep::GetTargetEffectAnchor () const
{
	return mTargetEffectAnchor;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetTargetEffectTime (float seconds)
{
	mTargetEffectTime = seconds;
}
//----------------------------------------------------------------------------
inline float SkillStep::GetTargetEffectTime () const
{
	return mTargetEffectTime;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetTargetPosEffectFilename (const std::string &posEffectFilename)
{
	mTargetPosEffectFilename = posEffectFilename;
}
//----------------------------------------------------------------------------
inline const std::string &SkillStep::GetTargetPosEffectFilename () const
{
	return mTargetPosEffectFilename;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetAnimedTargetPosEffectFilename (const std::string &effectFilename)
{
	mAnimedTargetPosEffectFilename = effectFilename;
}
//----------------------------------------------------------------------------
inline const std::string &SkillStep::GetAnimedTargetPosEffectFilename () const
{
	return mAnimedTargetPosEffectFilename;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetTargetPosEffectTime (float seconds)
{
	mTargetPosEffectTime = seconds;
}
//----------------------------------------------------------------------------
inline float SkillStep::GetTargetPosEffectTime () const
{
	return mTargetPosEffectTime;
}
//----------------------------------------------------------------------------
inline SkillStep *SkillStep::GetNextStep ()
{
	return mNextStep;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetScriptHandler_Leave (const std::string &handler)
{
	mScriptHandler_Leave = handler;
}
//----------------------------------------------------------------------------
inline const std::string &SkillStep::GetScriptHandler_Leave () const
{
	return mScriptHandler_Leave;
}
//----------------------------------------------------------------------------
inline void SkillStep::SetScriptHandler_Enter (const std::string &handler)
{
	mScriptHandler_Enter = handler;
}
//----------------------------------------------------------------------------
inline const std::string &SkillStep::GetScriptHandler_Enter () const
{
	return mScriptHandler_Enter;
}
//----------------------------------------------------------------------------