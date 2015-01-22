// PX2UIView.inl

//----------------------------------------------------------------------------
inline const Sizef &RenderStep::GetSize() const
{
	return mSize;
}
//----------------------------------------------------------------------------
inline void RenderStep::SetRenderer(Renderer *renderer)
{
	mRenderer = renderer;
}
//----------------------------------------------------------------------------
inline Renderer *RenderStep::GetRenderer()
{
	return mRenderer;
}
//----------------------------------------------------------------------------
inline Camera *RenderStep::GetCamera()
{
	return mCamera;
}
//----------------------------------------------------------------------------
inline Node *RenderStep::GetNode()
{
	return mNode;
}
//----------------------------------------------------------------------------