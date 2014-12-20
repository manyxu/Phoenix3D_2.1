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
inline const Rectf &GameManager::GetGameViewRect () const
{
	return mGameViewRect;
}
//----------------------------------------------------------------------------
inline int GameManager::GetGameViewAjustType () const
{
	return mGameViewAdjustType;
}
//----------------------------------------------------------------------------
inline VertexFormat *GameManager::GetVertexFormatUser ()
{
	return mVertexFormatUser;
}
//----------------------------------------------------------------------------
inline Texture2DMaterial *GameManager::GetMaterialUser ()
{
	return mMaterialUser;
}
//----------------------------------------------------------------------------