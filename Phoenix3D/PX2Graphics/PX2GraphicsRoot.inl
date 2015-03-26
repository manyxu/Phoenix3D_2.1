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
inline void GraphicsRoot::SetCurEnvirParam(EnvirParam *param)
{
	mCurEnvirParam = param;
}
//----------------------------------------------------------------------------
inline EnvirParam *GraphicsRoot::GetCurEnvirParam()
{
	return mCurEnvirParam;
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