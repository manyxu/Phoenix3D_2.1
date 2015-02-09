// PX2UIFrame.inl

//----------------------------------------------------------------------------
inline const Sizef &UIFrame::GetSize() const
{
	return mSize;
}
//----------------------------------------------------------------------------
inline float UIFrame::GetWidth() const
{
	return mSize.Width;
}
//----------------------------------------------------------------------------
inline float UIFrame::GetHeight() const
{
	return mSize.Height;
}
//----------------------------------------------------------------------------
inline const Sizef &UIFrame::GetBorderSize() const
{
	return mBorderSize;
}
//----------------------------------------------------------------------------
inline void UIFrame::SetUICallback(UICallback callback)
{
	mUICallback = callback;
}
//----------------------------------------------------------------------------
inline UICallback UIFrame::GetUICallback() const
{
	return mUICallback;
}
//----------------------------------------------------------------------------
inline void UIFrame::SetScriptHandler(const std::string &scriptHandler)
{
	mUIScriptHandler = scriptHandler;
}
//----------------------------------------------------------------------------
inline const std::string &UIFrame::GetScriptHandler() const
{
	return mUIScriptHandler;
}
//----------------------------------------------------------------------------
inline InputPushTransformController *UIFrame::GetIPTCtrl()
{
	return mIPTCtrl;
}
//----------------------------------------------------------------------------