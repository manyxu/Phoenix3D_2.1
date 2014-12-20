/*
*
* ÎÄ¼þÃû³Æ	£º	PX2GameManager.inl
*
*/

//----------------------------------------------------------------------------
inline int GameManager::GetBoostWidth () const
{
	return mBoostWidth;
}
//----------------------------------------------------------------------------
inline int GameManager::GetBoostHeight () const
{
	return mBoostHeight;
}
//----------------------------------------------------------------------------
inline const std::string &GameManager::GetProjectPath () const
{
	return mProjectPath;
}
//----------------------------------------------------------------------------
inline int GameManager::GetGameViewAjustType () const
{
	return mGameViewAdjustType;
}
//----------------------------------------------------------------------------
inline bool GameManager::IsPlaying () const
{
	return mIsPlaying;
}
//----------------------------------------------------------------------------
inline void GameManager::SetPlayMode (PlayMode mode)
{
	mPlayMode = mode;
}
//----------------------------------------------------------------------------
inline GameManager::PlayMode GameManager::GetPlayMode () const
{
	return mPlayMode;
}
//----------------------------------------------------------------------------
inline Character *GameManager::GetMainCharacter () const
{
	return mMainCharacter;
}
//----------------------------------------------------------------------------