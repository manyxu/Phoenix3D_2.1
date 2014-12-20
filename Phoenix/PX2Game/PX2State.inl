/*
*
* ÎÄ¼þÃû³Æ	£º	PX2State.inl
*
*/

//----------------------------------------------------------------------------
template <typename T>
State<T>::State ()
	:
mIsBlocked(false)
{
}
//----------------------------------------------------------------------------
template <typename T>
State<T>::~State ()
{
}
//----------------------------------------------------------------------------
template <typename T>
void State<T>::OnEvent (T *owner, Event *event)
{
	PX2_UNUSED(owner);
	PX2_UNUSED(event);
}
//----------------------------------------------------------------------------
template <typename T>
void State<T>::Block ()
{
	mIsBlocked = true;
}
//----------------------------------------------------------------------------
template <typename T>
void State<T>::UnBlock ()
{
	mIsBlocked = false;
}
//----------------------------------------------------------------------------
template <typename T>
bool State<T>::IsBlocked ()
{
	return mIsBlocked;
}
//----------------------------------------------------------------------------