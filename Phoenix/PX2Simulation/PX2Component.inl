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
inline Actor *Component::GetActor()
{
	return mActor;
}
//----------------------------------------------------------------------------
inline void Component::SetActor(Actor *actor)
{
	mActor = actor;
}
//----------------------------------------------------------------------------