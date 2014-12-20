/*
*
* ÎÄ¼þÃû³Æ	£º	PX2GameObject.inl
*
*/

//----------------------------------------------------------------------------
inline void Gameable::Enable (bool enable)
{
	mIsEnable = enable;
}
//----------------------------------------------------------------------------
inline bool Gameable::IsEnable () const
{
	return mIsEnable;
}
//----------------------------------------------------------------------------
inline int Gameable::GetServerID () const
{
	return mServerID;
}
//----------------------------------------------------------------------------
inline const std::string &Gameable::GetScriptHandler_Init () const
{
	return mScriptHandler_Init;
}
//----------------------------------------------------------------------------
inline const std::string &Gameable::GetUserScriptName () const
{
	return mUserScriptName;
}
//----------------------------------------------------------------------------
inline const std::string &Gameable::GetScriptName () const
{
	return mScriptName;
}
//----------------------------------------------------------------------------