// PX2GraphicsRoot.inl

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
inline void GraphicsRoot::SetProjectSize(const Sizef &size)
{
	mProjectSize = size;
}
//----------------------------------------------------------------------------
inline const Sizef &GraphicsRoot::GetProjectSize() const
{
	return mProjectSize;
}
//----------------------------------------------------------------------------
inline Light *GraphicsRoot::GetLight_Dir()
{
	return mLight_Dir;
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
inline void GraphicsRoot::SetFogColorHeight (const Float4 &fogColor)
{
	mFogColorHeight = fogColor;
}
//----------------------------------------------------------------------------
inline const Float4 &GraphicsRoot::GetFogColorHeight () const
{
	return mFogColorHeight;
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
inline RenderStep *GraphicsRoot::GetRenderStepScene()
{
	return mRenderStepScene;
}
//----------------------------------------------------------------------------
inline RenderStep *GraphicsRoot::GetRenderStepUI()
{
	return mRenderStepUI;
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