/*
*
* ÎÄ¼þÃû³Æ	£º	PX2SoundSystem.hpp
*
*/

//----------------------------------------------------------------------------
inline void SoundSystem::SetMaxNumPlaySameTime (int num)
{
	mMaxNumPlaySameTime = num;
}
//----------------------------------------------------------------------------
inline int SoundSystem::GetMaxNumPlaySameTime () const
{
	return mMaxNumPlaySameTime;
}
//----------------------------------------------------------------------------
inline void SoundSystem::SetPlaySameTimeRange (float time)
{
	mPlaySameTimeRange = time;
}
//----------------------------------------------------------------------------
inline float SoundSystem::GetPlaySameTimeRange () const
{
	return mPlaySameTimeRange;
}
//----------------------------------------------------------------------------
inline SoundSystem::SystemType SoundSystem::GetSystemType () const
{
	return mSystemType;
}
//----------------------------------------------------------------------------
inline const APoint &SoundSystem::GetListenerPos () const
{
	return mListenPos;
}
//----------------------------------------------------------------------------
inline bool SoundSystem::IsMusicEnable () const
{
	return mIsMusicEnable;
}
//----------------------------------------------------------------------------
inline bool SoundSystem::IsSoundEnable () const
{
	return mIsSoundEnable;
}
//----------------------------------------------------------------------------