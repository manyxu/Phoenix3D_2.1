/*
*
* ÎÄ¼þÃû³Æ	£º	PX2StateMachine.inl
*
*/

//----------------------------------------------------------------------------
template <typename T>
StateMachine<T>::StateMachine(T *owner)
	:
mOwner(owner),
mCurrentState(0),
mPreviousState(0),
mGlobalState(0)
{
}
//----------------------------------------------------------------------------
template <typename T>
StateMachine<T>::StateMachine()
{
}
//----------------------------------------------------------------------------
template <typename T>
StateMachine<T>::~StateMachine ()
{
}
//----------------------------------------------------------------------------
template <typename T>
inline void StateMachine<T>::SetCurrentState (State<T> *state)
{
	mCurrentState = state;
}
//----------------------------------------------------------------------------
template <typename T>
inline void StateMachine<T>::SetGlobalState (State<T> *state)
{
	mGlobalState = state;
}
//----------------------------------------------------------------------------
template <typename T>
inline void StateMachine<T>::SetPreviousState (State<T> *state)
{
	mPreviousState = state;
}
//----------------------------------------------------------------------------
template <typename T>
inline State<T> *StateMachine<T>::GetCurrentState () const
{
	return mCurrentState;
}
//----------------------------------------------------------------------------
template <typename T>
inline State<T> *StateMachine<T>::GetGlobalState () const
{
	return mGlobalState;
}
//----------------------------------------------------------------------------
template <typename T>
inline State<T> *StateMachine<T>::GetPreviousState () const
{
	return mPreviousState;
}
//----------------------------------------------------------------------------
template <typename T>
void StateMachine<T>::ChangeToState (State<T> *newState)
{
	if (mCurrentState == newState)
		return;

	mPreviousState = mCurrentState;

	if (mCurrentState)
		mCurrentState->StateExit(mOwner);

	mCurrentState = newState;

	if (mCurrentState)
		mCurrentState->StateEnter(mOwner);
}
//----------------------------------------------------------------------------
template <typename T>
void StateMachine<T>::RevertToPreviousState ()
{
	ChangeToState(mPreviousState);
}
//----------------------------------------------------------------------------
template <typename T>
bool StateMachine<T>::IsInState (const State<T> *state) const
{
	if (typeid(*mCurrentState) == typeid(*state))
		return true;

	return false;
}
//----------------------------------------------------------------------------
template <typename T>
void StateMachine<T>::Update (double appSeconds, double elapsedSeconds)
{
	if (mGlobalState)  
		mGlobalState->Update(mOwner, appSeconds, elapsedSeconds);

	if (mCurrentState)
		mCurrentState->Update(mOwner, appSeconds, elapsedSeconds);
}
//----------------------------------------------------------------------------
template <typename T>
void StateMachine<T>::DoEnter ()
{

}
//----------------------------------------------------------------------------
template <typename T>
void StateMachine<T>::DoExecute (Event *event)
{
	if (mCurrentState)
		mCurrentState->OnEvent(mOwner, event);

	if (mGlobalState)
		mGlobalState->OnEvent(mOwner, event);
}
//----------------------------------------------------------------------------
template <typename T>
void StateMachine<T>::DoLeave ()
{
}
//----------------------------------------------------------------------------