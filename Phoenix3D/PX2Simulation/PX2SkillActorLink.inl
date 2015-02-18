// PX2SkillActorLink.inl

//----------------------------------------------------------------------------
inline void SkillActorLink::SetTargetType(TargetType type)
{
	mTargetType = type;
}
//----------------------------------------------------------------------------
inline SkillActorLink::TargetType SkillActorLink::GetTargetType() const
{
	return mTargetType;
}
//----------------------------------------------------------------------------
inline void SkillActorLink::SetFromActorID(int ID)
{
	mFromActorID = ID;
}
//----------------------------------------------------------------------------
inline int SkillActorLink::GetFromActorID() const
{
	return mFromActorID;
}
//----------------------------------------------------------------------------
inline void SkillActorLink::SetFromActorAnchorID(int anchorID)
{
	mFormAnchorID = anchorID;
}
//----------------------------------------------------------------------------
inline int SkillActorLink::GetFromActorAnchorID() const
{
	return mFormAnchorID;
}
//----------------------------------------------------------------------------
inline void SkillActorLink::SetToActorID(int ID)
{
	mToActorID = ID;
}
//----------------------------------------------------------------------------
inline int SkillActorLink::GetToActorID() const
{
	return mToActorID;
}
//----------------------------------------------------------------------------
inline void SkillActorLink::SetToActorAnchorID(int anchorID)
{
	mToAnchorID = anchorID;
}
//----------------------------------------------------------------------------
inline int SkillActorLink::GetToActorAnchorID() const
{
	return mToAnchorID;
}
//----------------------------------------------------------------------------
inline void SkillActorLink::SetToPosition(const APoint &pos)
{
	mToPos = pos;
}
//----------------------------------------------------------------------------
inline const APoint &SkillActorLink::GetToPosition() const
{
	return mToPos;
}
//----------------------------------------------------------------------------
inline void SkillActorLink::SetLinkSpeed(float speed)
{
	mLinkSpeed = speed;
}
//----------------------------------------------------------------------------
inline float SkillActorLink::GetLinkSpeed() const
{
	return mLinkSpeed;
}
//----------------------------------------------------------------------------
inline bool SkillActorLink::IsLinked() const
{
	return mIsLinked;
}
//----------------------------------------------------------------------------
inline bool SkillActorLink::IsOver() const
{
	return mIsOver;
}
//----------------------------------------------------------------------------