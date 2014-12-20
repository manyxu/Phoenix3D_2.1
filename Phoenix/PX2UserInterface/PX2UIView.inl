/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIView.inl
*
*/

//----------------------------------------------------------------------------
inline int UIView::GetID ()
{
	return mID;
}
//----------------------------------------------------------------------------
inline const Sizef &UIView::GetSize () const
{
	return mSize;
}
//----------------------------------------------------------------------------
inline float UIView::GetWidth ()
{
	return mSize.Width;
}
//----------------------------------------------------------------------------
inline float UIView::GetHeight ()
{
	return mSize.Height;
}
//----------------------------------------------------------------------------
inline const Sizef &UIView::GetProjSize () const
{
	return mProjSize;
}
//----------------------------------------------------------------------------
inline float UIView::GetProjWidth () const
{
	return mProjSize.Width;
}
//----------------------------------------------------------------------------
inline float UIView::GetProjHeight () const
{
	return mProjSize.Height;
}
//----------------------------------------------------------------------------
inline bool UIView::IsEnable () const
{
	return mIsEnable;
}
//----------------------------------------------------------------------------
inline void UIView::SetRenderer(Renderer *renderer)
{
	mRenderer = renderer;
}
//----------------------------------------------------------------------------
inline void UIView::SetMainFrame (UIFrame *frame)
{
	mUIMainFrame = frame;
}
//----------------------------------------------------------------------------
inline Renderer *UIView::GetRenderer ()
{
	return mRenderer;
}
//----------------------------------------------------------------------------
inline Camera *UIView::GetCamera ()
{
	return mCamera;
}
//----------------------------------------------------------------------------
inline UIFrame *UIView::GetMainFrame ()
{
	return mUIMainFrame;
}
//----------------------------------------------------------------------------
inline void UIView::SetSuperTopFrame (UIFrame *superTopFrame)
{
	mSuperTopFrame = superTopFrame;
}
//----------------------------------------------------------------------------
inline UIFrame *UIView::GetSuperTopFrame ()
{
	return mSuperTopFrame;
}
//----------------------------------------------------------------------------
inline Culler &UIView::GetCuller ()
{
	return mCuller;
}
//----------------------------------------------------------------------------
inline std::vector<UIPicBoxPtr> &UIView::GetPickedPicBoxs ()
{
	return mPickedPicBoxes;
}
//----------------------------------------------------------------------------
inline bool UIView::IsPressed () const
{
	return mIsPressed;
}
//----------------------------------------------------------------------------