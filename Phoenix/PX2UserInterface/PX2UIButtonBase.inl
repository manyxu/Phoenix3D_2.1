/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIButtonBase.inl
*
*/

//----------------------------------------------------------------------------
inline UIButtonBase::ButtonState UIButtonBase::GetButtonState () const
{
	return mButtonState;
}
//----------------------------------------------------------------------------
inline const Sizef &UIButtonBase::GetSize () const
{
	return mSize;
}
//----------------------------------------------------------------------------
inline float UIButtonBase::GetWidth ()
{
	return mSize.Width;
}
//----------------------------------------------------------------------------
inline float UIButtonBase::GetHeight ()
{
	return mSize.Height;
}
//----------------------------------------------------------------------------