// PX2UIView.inl

//----------------------------------------------------------------------------
inline bool RenderStep::IsEnable() const
{
	return mIsEnable;
}
//----------------------------------------------------------------------------
inline const Sizef &RenderStep::GetSize() const
{
	return mSize;
}
//----------------------------------------------------------------------------
inline const Rectf &RenderStep::GetViewPort() const
{
	return mViewPort;
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
inline void RenderStep::SetPriority(int priority)
{
	mPriority = priority;
}
//----------------------------------------------------------------------------
inline int RenderStep::GetPriority() const
{
	return mPriority;
}
//----------------------------------------------------------------------------
inline void RenderStep::SetDoDepthClear(bool clear)
{
	mIsDoClearDepth = clear;
}
//----------------------------------------------------------------------------
inline bool RenderStep::IsDoDepthClear()
{
	return mIsDoClearDepth;
}
//----------------------------------------------------------------------------