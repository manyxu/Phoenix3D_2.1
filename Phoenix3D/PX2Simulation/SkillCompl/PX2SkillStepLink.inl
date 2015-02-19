// PX2SkillStepLink.inl

//----------------------------------------------------------------------------
inline void SkillStepLink::SetLinkToActor(bool toActor)
{
	mIsLinkToActor = toActor;
}
//----------------------------------------------------------------------------
inline bool SkillStepLink::IsLinkToActor() const
{
	return mIsLinkToActor;
}
//----------------------------------------------------------------------------
inline void SkillStepLink::SetToActorAnchorID(int id)
{
	mToActorAnchorID = id;
}
//----------------------------------------------------------------------------
inline int SkillStepLink::GetToActorAnchorID() const
{
	return mToActorAnchorID;
}
//----------------------------------------------------------------------------
inline void SkillStepLink::SetLinkDir(const AVector &dir)
{
	mLinkDir = dir;
}
//----------------------------------------------------------------------------
inline const AVector &SkillStepLink::GetLinkDir() const
{
	return mLinkDir;
}
//----------------------------------------------------------------------------
inline void SkillStepLink::SetSpeed(float speed)
{
	mSpeed = speed;
}
//----------------------------------------------------------------------------
inline float SkillStepLink::GetSpeed() const
{
	return mSpeed;
}
//----------------------------------------------------------------------------
inline void SkillStepLink::SetLinkToTime(float linkToTime)
{
	mLinkToTime = linkToTime;
}
//----------------------------------------------------------------------------
inline float SkillStepLink::GetLinkToTime() const
{
	return mLinkToTime;
}
//----------------------------------------------------------------------------
inline void SkillStepLink::SetLinkedDoOver(bool linkedOver)
{
	mLinkedDoOver = linkedOver;
}
//----------------------------------------------------------------------------
inline bool SkillStepLink::IsLinkedDoOver() const
{
	return mLinkedDoOver;
}
//----------------------------------------------------------------------------
inline void SkillStepLink::SetCurLinkedSkillInstance(SkillInstance *si)
{
	mCurLinkedSkillInstance = si;
}
//----------------------------------------------------------------------------
inline SkillInstance *SkillStepLink::GetCurLinkedSkillInstance() const
{
	return mCurLinkedSkillInstance;
}
//----------------------------------------------------------------------------
inline void SkillStepLink::SetScriptHandler_OnLinked(
	const std::string &handler)
{
	mScriptHandler_OnLinked = handler;
}
//----------------------------------------------------------------------------
inline const std::string &SkillStepLink::GetScriptHandler_OnLinked() const
{
	return mScriptHandler_OnLinked;
}
//----------------------------------------------------------------------------
inline void SkillStepLink::SetScriptHandler_OnDisLinked(
	const std::string &handler)
{
	mScriptHandler_OnDisLinked = handler;
}
//----------------------------------------------------------------------------
inline const std::string &SkillStepLink::GetScriptHandler_OnDisLinked() const
{
	return mScriptHandler_OnDisLinked;
}
//----------------------------------------------------------------------------