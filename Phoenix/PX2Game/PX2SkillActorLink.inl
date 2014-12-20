/*
*
* ÎÄ¼þÃû³Æ	£º	PX2SkillActorLink.inl
*
*/

//----------------------------------------------------------------------------
inline void SkillActorLink::SetTargetType (TargetType type)
{
	mTargetType = type;
}
//----------------------------------------------------------------------------
inline SkillActorLink::TargetType SkillActorLink::GetTargetType () const
{
	return mTargetType;
}
//----------------------------------------------------------------------------
inline void SkillActorLink::SetFromActorID (int ID)
{
	mFromActorID = ID;
}
//----------------------------------------------------------------------------
inline int SkillActorLink::GetFromActorID () const
{
	return mFromActorID;
}
//----------------------------------------------------------------------------
inline void SkillActorLink::SetFromActorAnchor (const std::string &anchor)
{
	mFromActorAnchor = anchor;
}
//----------------------------------------------------------------------------
inline const std::string &SkillActorLink::GetFromActorAnchor () const
{
	return mFromActorAnchor;
}
//----------------------------------------------------------------------------
inline void SkillActorLink::SetToActorID (int ID)
{
	mToActorID = ID;
}
//----------------------------------------------------------------------------
inline int SkillActorLink::GetToActorID () const
{
	return mToActorID;
}
//----------------------------------------------------------------------------
inline void SkillActorLink::SetToActorAnchor (const std::string &anchor)
{
	mToActorAnchor = anchor;
}
//----------------------------------------------------------------------------
inline const std::string &SkillActorLink::GetToActorAnchor () const
{
	return mToActorAnchor;
}
//----------------------------------------------------------------------------
inline void SkillActorLink::SetToPosition (const APoint &pos)
{
	mToPos = pos;
}
//----------------------------------------------------------------------------
inline const APoint &SkillActorLink::GetToPosition () const
{
	return mToPos;
}
//----------------------------------------------------------------------------
inline void SkillActorLink::SetLinkSpeed (float speed)
{
	mLinkSpeed = speed;
}
//----------------------------------------------------------------------------
inline float SkillActorLink::GetLinkSpeed () const
{
	return mLinkSpeed;
}
//----------------------------------------------------------------------------
inline bool SkillActorLink::IsLinked () const
{
	return mIsLinked;
}
//----------------------------------------------------------------------------
inline bool SkillActorLink::IsOver () const
{
	return mIsOver;
}
//----------------------------------------------------------------------------