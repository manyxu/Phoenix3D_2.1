/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Component.inl
*
*/

//----------------------------------------------------------------------------
inline void Component::SetPriority(int priority)
{
	mPriority = priority;
}
//----------------------------------------------------------------------------
inline int Component::GetPriority() const
{
	return mPriority;
}
//----------------------------------------------------------------------------
inline Componable *Component::GetCompable()
{
	return mCompable;
}
//----------------------------------------------------------------------------
inline void Component::SetCompable(Componable *compable)
{
	mCompable = compable;
}
//----------------------------------------------------------------------------