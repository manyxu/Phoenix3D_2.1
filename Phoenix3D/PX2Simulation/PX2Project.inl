// PX2Project.inl

//----------------------------------------------------------------------------
inline const Sizef & Project::GetSize() const
{
	return mSize;
}
//----------------------------------------------------------------------------
inline float Project::GetWidth() const
{
	return mSize.Width;
}
//----------------------------------------------------------------------------
inline float Project::GetHeight() const
{
	return mSize.Height;
}
//----------------------------------------------------------------------------
inline Scene *Project::GetScene()
{
	return mScene;
}
//----------------------------------------------------------------------------
inline const std::string &Project::GetSceneFilename() const
{
	return mSceneFilename;
}
//----------------------------------------------------------------------------
inline RenderStep *Project::GetSceneRenderStep()
{
	return mSceneRenderStep;
}
//----------------------------------------------------------------------------
inline UIFrame *Project::GetUIFrame()
{
	return mUIFrame;
}
//----------------------------------------------------------------------------
inline const std::string &Project::GetUIFilename() const
{
	return mUIFilename;
}
//----------------------------------------------------------------------------
inline UIView *Project::GetUIRenderStep()
{
	return mUIRenderStep;
}
//----------------------------------------------------------------------------
inline const Rectf &Project::GetViewPort() const
{
	return mViewPort;
}
//----------------------------------------------------------------------------
inline void Project::SetEdit_UICameraPercent(float percent)
{
	mEdit_UICameraPercent = percent;
}
//----------------------------------------------------------------------------
inline float Project::GetEdit_UICameraPercent() const
{
	return mEdit_UICameraPercent;
}
//----------------------------------------------------------------------------