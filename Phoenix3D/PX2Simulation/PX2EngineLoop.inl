// PX2EngineLoop.inl

//----------------------------------------------------------------------------
inline float EngineLoop::GetElapsedTime()
{
	return (float)(mAppTime - mLastAppTime);
}
//----------------------------------------------------------------------------
inline const Sizef &EngineLoop::GetBoostSize() const
{
	return mBoostSize;
}
//----------------------------------------------------------------------------
inline const std::string &EngineLoop::GetProjectPath() const
{
	return mProjectPath;
}
//----------------------------------------------------------------------------
inline void EngineLoop::_SetDoAdjustScreen(bool adjust)
{
	mIsDoAdjustScreen = adjust;
}
//----------------------------------------------------------------------------
inline bool EngineLoop::IsDoAdjustScreen() const
{
	return mIsDoAdjustScreen;
}
//----------------------------------------------------------------------------
inline const Sizef &EngineLoop::GetScreenSize() const
{
	return mScreenSize;
}
//----------------------------------------------------------------------------
inline EngineLoop::PlayType EngineLoop::GetPlayType() const
{
	return mPlayType;
}
//----------------------------------------------------------------------------