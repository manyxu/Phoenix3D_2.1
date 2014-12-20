/*
*
* ÎÄ¼þÃû³Æ	£º	PX2SkillStepTrack.inl
*
*/

//----------------------------------------------------------------------------
inline bool SkillStepFarTrack::IsTrackToActor () const
{
	return mIsTrackToActor;
}
//----------------------------------------------------------------------------
inline const AVector &SkillStepFarTrack::GetTrackDir () const
{
	return mTrackDir;
}
//----------------------------------------------------------------------------
inline float SkillStepFarTrack::GetSpeed () const
{
	return mSpeed;
}
//----------------------------------------------------------------------------
inline void SkillStepFarTrack::SetTrackTime (float seconds)
{
	mTrackTime = seconds;
}
//----------------------------------------------------------------------------
inline float SkillStepFarTrack::GetTrackTime () const
{
	return mTrackTime;
}
//----------------------------------------------------------------------------
inline float SkillStepFarTrack::GetDegree () const
{
	return mDegree;
}
//----------------------------------------------------------------------------
inline float SkillStepFarTrack::GetSideDegree () const
{
	return mSideDegree;
}
//----------------------------------------------------------------------------
inline void SkillStepFarTrack::SetAlignTrace (bool alignTrace)
{
	mIsAlignTrace = alignTrace;
}
//----------------------------------------------------------------------------
inline bool SkillStepFarTrack::IsAlignTrace () const
{
	return mIsAlignTrace;
}
//----------------------------------------------------------------------------
inline bool SkillStepFarTrack::IsDoDamageOnTrack () const
{
	return mIsDoDamageOnTrack;
}
//----------------------------------------------------------------------------
inline void SkillStepFarTrack::SetDamageOnTrackFrequency (float fre)
{
	mDamageOnTrackFrequency = fre;
}
//----------------------------------------------------------------------------
inline float SkillStepFarTrack::GetDamageOnTrackFrequency () const
{
	return mDamageOnTrackFrequency;
}
//----------------------------------------------------------------------------
inline void SkillStepFarTrack::SetCurTrackSkillInstance (SkillInstance *si)
{
	mCurTrackSkillInstance = si;
}
//----------------------------------------------------------------------------
inline SkillInstance *SkillStepFarTrack::GetCurTrackSkillInstance ()
{
	return mCurTrackSkillInstance;
}
//----------------------------------------------------------------------------
inline void SkillStepFarTrack::SetScriptHandler_OnTrack (const std::string &handler)
{
	mScriptHandler_OnTrack = handler;
}
//----------------------------------------------------------------------------
inline const std::string &SkillStepFarTrack::GetScriptHandler_OnTrack () const
{
	return mScriptHandler_OnTrack;
}
//----------------------------------------------------------------------------