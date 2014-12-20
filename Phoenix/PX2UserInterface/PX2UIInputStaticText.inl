/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIInputStaticText.inl
*
*/

//----------------------------------------------------------------------------
inline bool UIInputStaticText::IsPassword () const
{
	return mIsPassword;
}
//----------------------------------------------------------------------------
inline const std::string &UIInputStaticText::GetRealText () const
{
	return mRealText;
}
//----------------------------------------------------------------------------
inline void UIInputStaticText::SetCallback (UIInputStaticTextCallback callback)
{
	mCallback = callback;
}
//----------------------------------------------------------------------------
inline UIInputStaticTextCallback UIInputStaticText::GetCallback () const
{
	return mCallback;
}
//----------------------------------------------------------------------------
inline float UIInputStaticText::GetFixedWidth () const
{
	return mFixedWidth;
}
//----------------------------------------------------------------------------