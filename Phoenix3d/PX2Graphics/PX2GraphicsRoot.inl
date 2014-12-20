/*
*
* ÎÄ¼þÃû³Æ	£º	PX2GraphicsRoot.inl
*
*/

//----------------------------------------------------------------------------
inline void GraphicsRoot::SetRect (const Rectf &rect)
{
	mRect = rect;
}
//----------------------------------------------------------------------------
inline const Rectf &GraphicsRoot::GetRect () const
{
	return mRect;
}
//----------------------------------------------------------------------------
inline void GraphicsRoot::SetSize (const Sizef &size)
{
	mSize = size;
}
//----------------------------------------------------------------------------
inline const Sizef &GraphicsRoot::GetSize () const
{
	return mSize;
}
//----------------------------------------------------------------------------
inline void GraphicsRoot::SetCamera (Camera *camera)
{
	mCamera = camera;
}
//----------------------------------------------------------------------------
inline PX2::Camera *GraphicsRoot::GetCamera()
{
	return mCamera;
}
//----------------------------------------------------------------------------
inline void GraphicsRoot::SetFogParam (const Float4 &param)
{
	mFogParam = param;
}
//----------------------------------------------------------------------------
inline const Float4 &GraphicsRoot::GetFogParam () const
{
	return mFogParam;
}
//----------------------------------------------------------------------------
inline void GraphicsRoot::SetFogColor (const Float4 &fogColor)
{
	mFogColor = fogColor;
}
//----------------------------------------------------------------------------
inline const Float4 &GraphicsRoot::GetFogColor () const
{
	return mFogColor;
}
//----------------------------------------------------------------------------