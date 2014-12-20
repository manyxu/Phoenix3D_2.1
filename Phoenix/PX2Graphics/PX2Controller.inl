/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Controller.inl
*
*/

//----------------------------------------------------------------------------
inline int Controller::GetPriority () const
{
	return mPriority;
}
//----------------------------------------------------------------------------
inline float Controller::GetMaxPlayTime () const
{
	return mMaxPlayTime;
}
//----------------------------------------------------------------------------
inline float Controller::GetDelayPlayTime () const
{
	return mDelayPlayTime;
}
//----------------------------------------------------------------------------
inline float Controller::GetRunTime () const
{
	if (!mIsTimeInited)
		return 0.0f;

	return (float)mApplicationTime - (float)mInitedApplicationIime;
}
//----------------------------------------------------------------------------
inline Controlledable* Controller::GetControlledable () const
{
    return mObject;
}
//----------------------------------------------------------------------------
inline double Controller::GetApplicationTime () const
{
    return mApplicationTime;
}
//----------------------------------------------------------------------------
inline bool Controller::IsTimeInited ()
{
	return mIsTimeInited;
}
//----------------------------------------------------------------------------
inline float Controller::GetElapsedTime () const
{
	return (float)mApplicationTime - (float)mLastApplicationTime;
}
//----------------------------------------------------------------------------
inline float Controller::GetPlayedTime () const
{
	return mPlayedTime;
}
//----------------------------------------------------------------------------
inline void Controller::SetPlayedDoDetach(bool doDetach)
{
	mIsPlayedDoDetach = doDetach;
}
//----------------------------------------------------------------------------
inline bool Controller::IsPlayedDoDetach () const
{
	return mIsPlayedDoDetach;
}
//----------------------------------------------------------------------------
inline void Controller::SetPlayedCallback (CtrlPlayedCallback callback)
{
	mPlayedCallback = callback;
}
//----------------------------------------------------------------------------
inline CtrlPlayedCallback Controller::GetPlayedCallback ()
{
	return mPlayedCallback;
}
//----------------------------------------------------------------------------