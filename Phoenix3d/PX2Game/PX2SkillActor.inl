/*
*
* ÎÄ¼þÃû³Æ	£º	PX2SkillActor.inl
*
*/

//----------------------------------------------------------------------------
inline SkillActor::TargetType SkillActor::GetTargetType () const
{
	return mTargetType;
}
//----------------------------------------------------------------------------
inline void SkillActor::SetCharacterGroup (int group)
{
	mCharacterGroup = group;
}
//----------------------------------------------------------------------------
inline int SkillActor::GetCharacterGroup () const
{
	return mCharacterGroup;
}
//----------------------------------------------------------------------------
inline void SkillActor::SetSkillTypeID (int ID)
{
	mSkillTypeID = ID;
}
//----------------------------------------------------------------------------
inline int SkillActor::GetSkillITypeID () const
{
	return mSkillTypeID;
}
//----------------------------------------------------------------------------
inline void SkillActor::SetAttackSpeed (float speed)
{
	mTrackSpeed = speed;
}
//----------------------------------------------------------------------------
inline float SkillActor::GetAttackSpeed () const
{
	return mTrackSpeed;
}
//----------------------------------------------------------------------------
inline const APoint &SkillActor::GetBeginPos () const
{
	return mBeginPos;
}
//----------------------------------------------------------------------------
inline int SkillActor::GetTargetID () const
{
	return mTargetID;
}
//----------------------------------------------------------------------------
inline const APoint &SkillActor::GetTargetPos () const
{
	return mTargetPos;
}
//----------------------------------------------------------------------------
inline float SkillActor::GetDegree () const
{
	return mDegree;
}
//----------------------------------------------------------------------------
inline void SkillActor::SetSideDegree (float sideDegree)
{
	mSideDegree = sideDegree;
}
//----------------------------------------------------------------------------
inline float SkillActor::GetSideDegree () const
{
	return mSideDegree;
}
//----------------------------------------------------------------------------
inline void SkillActor::SetAlignTrace (bool alignTrace)
{
	mIsAlignTrace = alignTrace;
}
//----------------------------------------------------------------------------
inline bool SkillActor::IsAlignTrace () const
{
	return mIsAlignTrace;
}
//----------------------------------------------------------------------------
inline void SkillActor::SetDoDamageOnTrack (bool damage)
{
	mIsDoDamageOnTrack = damage;
}
//----------------------------------------------------------------------------
inline bool SkillActor::IsDoDamageOnTrack () const
{
	return mIsDoDamageOnTrack;
}
//----------------------------------------------------------------------------
inline bool SkillActor::IsOver () const
{
	return mIsOver;
}
//----------------------------------------------------------------------------