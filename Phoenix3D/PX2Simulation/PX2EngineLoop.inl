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
inline const Sizef &EngineLoop::GetSize() const
{
	return mSize;
}
//----------------------------------------------------------------------------
inline EngineLoop::PlayType EngineLoop::GetPlayType() const
{
	return mPlayType;
}
//----------------------------------------------------------------------------