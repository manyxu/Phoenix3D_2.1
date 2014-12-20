/*
*
* ÎÄ¼þÃû³Æ	£º	PX2SoundActor.inl
*
*/

//----------------------------------------------------------------------------
inline PX2::Soundable *SoundActor::GetSoundable () const
{
	return mSoundable;
}
//----------------------------------------------------------------------------
inline bool SoundActor::IsPlaying () const
{
	return mIsPlaying;
}
//----------------------------------------------------------------------------
inline float SoundActor::GetVolume () const
{
	return mVolume;
}
//----------------------------------------------------------------------------
inline void SoundActor::SetInRangeAutoPlay (bool autoPlay)
{
	mIsInRangeAutoPlay = autoPlay;
}
//----------------------------------------------------------------------------
inline bool SoundActor::IsInRangeAutoPlay () const
{
	return mIsInRangeAutoPlay;
}
//----------------------------------------------------------------------------
inline bool SoundActor::IsAutoVolumeByRange () const
{
	return mIsAutoVolumeByRange;
}
//----------------------------------------------------------------------------