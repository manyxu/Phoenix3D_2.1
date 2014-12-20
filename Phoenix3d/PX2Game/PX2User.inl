/*
*
* ÎÄ¼şÃû³Æ	£º	PX2User.inl
*
*/

//----------------------------------------------------------------------------
inline const std::string &User::GetName () const
{
	return mName;
}
//----------------------------------------------------------------------------
inline const std::string &User::GetUserName () const
{
	return mUserName;
}
//----------------------------------------------------------------------------
inline int User::GetNumUserActors () const
{
	return (int)mUserActors.size();
}
//----------------------------------------------------------------------------
