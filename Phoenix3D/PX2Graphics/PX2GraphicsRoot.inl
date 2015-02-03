/*
*
* ÎÄ¼þÃû³Æ	£º	PX2GraphicsRoot.inl
*
*/

//----------------------------------------------------------------------------
inline void GraphicsRoot::SetInEditor (bool isInEditor)
{
	mIsInEditor = isInEditor;
}
//----------------------------------------------------------------------------
inline bool GraphicsRoot::IsInEditor () const
{
	return mIsInEditor;
}
//----------------------------------------------------------------------------
inline void GraphicsRoot::SetViewRect (const Rectf &rect)
{
	mViewRect = rect;
}
//----------------------------------------------------------------------------
inline const Rectf &GraphicsRoot::GetViewRect () const
{
	return mViewRect;
}
//----------------------------------------------------------------------------
inline void GraphicsRoot::SetScreenSize (const Sizef &size)
{
	mScreenSize = size;
}
//----------------------------------------------------------------------------
inline const Sizef &GraphicsRoot::GetScreenSize () const
{
	return mScreenSize;
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
inline void GraphicsRoot::SetFogColorDist (const Float4 &fogColor)
{
	mFogColorDist = fogColor;
}
//----------------------------------------------------------------------------
inline const Float4 &GraphicsRoot::GetFogColorDist () const
{
	return mFogColorDist;
}
//----------------------------------------------------------------------------
inline TriMesh *GraphicsRoot::GetXYPlane()
{
	return mTriMeshXY;
}
//----------------------------------------------------------------------------
inline TriMesh *GraphicsRoot::GetXZPlane()
{
	return mTriMeshXZ;
}
//----------------------------------------------------------------------------
inline TriMesh *GraphicsRoot::GetYZPlane()
{
	return mTriMeshYZ;
}
//----------------------------------------------------------------------------