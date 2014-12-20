/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIButton.inl
*
*/

//----------------------------------------------------------------------------
inline UIButton::AfterReleasedType UIButton::GetAfterReleasedType () const
{
	return mAfterReleasedType;
}
//----------------------------------------------------------------------------
inline void UIButton::SetAfterReleasedRecoverTime (float time)
{
	mAfterReleasedRecoverTime = time;
}
//----------------------------------------------------------------------------
inline float UIButton::GetAfterReleasedRecoverTime () const
{
	return mAfterReleasedRecoverTime;
}
//----------------------------------------------------------------------------
inline void UIButton::SetNotPickNotSetNormal (bool setNormal)
{
	mIsNotPickNotSetNormal = setNormal;
}
//----------------------------------------------------------------------------
inline bool UIButton::IsNotPickNotSetNormal () const
{
	return mIsNotPickNotSetNormal;
}
//----------------------------------------------------------------------------