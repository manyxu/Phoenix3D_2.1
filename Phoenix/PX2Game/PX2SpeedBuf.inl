/*
*
* ÎÄ¼þÃû³Æ	£º	PX2SpeedBuf.inl
*
*/

//----------------------------------------------------------------------------
inline void SpeedBuf::SetMode (Mode mode)
{
	mMode = mode;
}
//----------------------------------------------------------------------------
inline SpeedBuf::Mode SpeedBuf::GetMode () const
{
	return mMode;
}
//----------------------------------------------------------------------------
inline void SpeedBuf::SetValue (float val)
{
	mValue = val;
}
//----------------------------------------------------------------------------
inline float SpeedBuf::GetValue () const
{
	return mValue;
}
//----------------------------------------------------------------------------
inline void SpeedBuf::SetLastingMaxTime (float lastingMaxTime)
{
	mLastingMaxTime = lastingMaxTime;
}
//----------------------------------------------------------------------------
inline float SpeedBuf::GetLastingMaxTime () const
{
	return mLastingMaxTime;
}
//----------------------------------------------------------------------------