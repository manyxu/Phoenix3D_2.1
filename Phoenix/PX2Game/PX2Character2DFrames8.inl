/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Character2DFrames8.inl
*
*/

//----------------------------------------------------------------------------
inline bool Character2DFrames8::IsShowSelfRadiusRange () const
{
	return mIsShowSelfRadiusRange;
}
//----------------------------------------------------------------------------
inline bool Character2DFrames8::IsShowHeadingDir () const
{
	return mIsShowHeadingDir;
}
//----------------------------------------------------------------------------
inline float Character2DFrames8::GetAnimSize () const
{
	return mAnimSize;
}
//----------------------------------------------------------------------------
inline float Character2DFrames8::GetShadowSize ()
{
	return mShadowSize;
}
//----------------------------------------------------------------------------
inline Node *Character2DFrames8::GetShadowNode ()
{
	return mShadowNode;
}
//----------------------------------------------------------------------------
inline const std::string &Character2DFrames8::GetShadowFilename () const
{
	return mShadowFilename;
}
//----------------------------------------------------------------------------
inline Node *Character2DFrames8::GetInfoNode ()
{
	return mInfoNode;
}
//----------------------------------------------------------------------------
inline Node *Character2DFrames8::GetActorNode ()
{
	return mActorNode;
}
//----------------------------------------------------------------------------
inline Node *Character2DFrames8::GetAnimNode ()
{
	return mAnimObject;
}
//----------------------------------------------------------------------------
inline const APoint &Character2DFrames8::GetOffset () const
{
	return mOffset;
}
//----------------------------------------------------------------------------
inline const APoint &Character2DFrames8::GetRolateNodeOffset () const
{
	return mRolateNodeOffset;
}
//----------------------------------------------------------------------------
inline const APoint &Character2DFrames8::GetAttackFrontNodeOffset () const
{
	return mAttackFrontOffset;
}
//----------------------------------------------------------------------------