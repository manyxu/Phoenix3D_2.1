// PX2Billboard.inl

//----------------------------------------------------------------------------
inline bool Billboard::IsDynamic () const
{
	return mIsDynamic;
}
//----------------------------------------------------------------------------
inline const Float2 &Billboard::GetAnchorPoint () const
{
	return mAnchorPoint;
}
//----------------------------------------------------------------------------
inline bool Billboard::IsUseTexAsSize () const
{
	return mIsUseTexAsSize;
}
//----------------------------------------------------------------------------
inline bool Billboard::IsUseTrim () const
{
	return mIsUseTrim;
}
//----------------------------------------------------------------------------
inline void Billboard::SetDoAlphaDisAfterStop (bool doAlphaDis)
{
	mIsDoAlphaDisAfterStop = doAlphaDis;
}
//----------------------------------------------------------------------------
inline bool Billboard::IsDoAlphaDisAfterStop () const
{
	return mIsDoAlphaDisAfterStop;
}
//----------------------------------------------------------------------------
inline void Billboard::SetDoAlphaDisAfterStopSpeed (float speed)
{
	mDoAlphaDisAfterStopSpeed = speed;
}
//----------------------------------------------------------------------------
inline float Billboard::GetDoAlphaDisAfterStopSpeed () const
{
	return mDoAlphaDisAfterStopSpeed;
}
//----------------------------------------------------------------------------