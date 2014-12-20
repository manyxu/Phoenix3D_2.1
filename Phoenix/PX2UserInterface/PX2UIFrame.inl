/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIFrame.inl
*
*/

//----------------------------------------------------------------------------
inline bool UIFrame::IsUseLayType () const
{
	return mIsUseLayType;
}
//----------------------------------------------------------------------------
inline UIFrame::LayType UIFrame::GetHLayType () const
{
	return mHLayType;
}
//----------------------------------------------------------------------------
inline float UIFrame::GetHLayValue () const
{
	return mHLayValue;
}
//----------------------------------------------------------------------------
inline UIFrame::LayType UIFrame::GetVLayType () const
{
	return mVLayType;
}
//----------------------------------------------------------------------------
inline float UIFrame::GetVLayValue () const
{
	return mVLayValue;
}
//----------------------------------------------------------------------------
inline bool UIFrame::IsEnable () const
{
	return mIsEnable;
}
//----------------------------------------------------------------------------
inline void UIFrame::SetUICallback (UICallback callback)
{
	mUICallback = callback;
}
//----------------------------------------------------------------------------
inline UICallback UIFrame::GetUICallback () const
{
	return mUICallback;
}
//----------------------------------------------------------------------------
inline const std::string &UIFrame::GetScriptHandler () const
{
	return mScriptHandler;
}
//----------------------------------------------------------------------------
inline const std::string &UIFrame::GetUserScriptName () const
{
	return mUserScriptName;
}
//----------------------------------------------------------------------------
inline const std::string &UIFrame::GetScriptName () const
{
	return mScriptName;
}
//----------------------------------------------------------------------------