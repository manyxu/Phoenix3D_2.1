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
inline UIFrame::RelativeType UIFrame::GetRelativeType_H() const
{
	return mPosRelativeType_H;
}
//----------------------------------------------------------------------------
inline UIFrame::RelativeType UIFrame::GetRelativeType_V() const
{
	return mPosRelativeType_V;
}
//----------------------------------------------------------------------------
inline float UIFrame::GetRelativeValue_H() const
{
	return mRelativeVal_H;
}
//----------------------------------------------------------------------------
inline float UIFrame::GetRelativeValue_V() const
{
	return mRelativeVal_V;
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
inline void UIFrame::SetUIView(UIView *uiView)
{
	mUIView = uiView;
}
//----------------------------------------------------------------------------
inline UIView *UIFrame::GetUIView()
{
	return mUIView;
}
//----------------------------------------------------------------------------
inline InputPushTransformController *UIFrame::GetIPTCtrl()
{
	return mIPTCtrl;
}
//----------------------------------------------------------------------------