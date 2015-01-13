// PX2UIView.inl

//----------------------------------------------------------------------------
inline const Sizef &UIView::GetSize() const
{
	return mSize;
}
//----------------------------------------------------------------------------
inline void UIView::SetRenderer(Renderer *renderer)
{
	mRenderer = renderer;
}
//----------------------------------------------------------------------------
inline Renderer *UIView::GetRenderer()
{
	return mRenderer;
}
//----------------------------------------------------------------------------
inline void UIView::SetCamera(Camera *camera)
{
	mCamera = camera;
}
//----------------------------------------------------------------------------
inline Camera *UIView::GetCamera()
{
	return mCamera;
}
//----------------------------------------------------------------------------