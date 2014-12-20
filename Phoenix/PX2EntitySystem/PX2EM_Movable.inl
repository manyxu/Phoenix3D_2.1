/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EM_Movable.inl
*
*/

//----------------------------------------------------------------------------
inline bool EM_Movable::IsSetMovableBlock () const
{
	return mIsSetMovableBlock;
}
//----------------------------------------------------------------------------
inline const std::string &EM_Movable::GetMovableFilename () const
{
	return mMovableFilename;
}
//----------------------------------------------------------------------------
inline Movable *EM_Movable::GetMovable () const
{
	return mMovable;
}
//----------------------------------------------------------------------------