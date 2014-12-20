/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Animation.inl
*
*/

//----------------------------------------------------------------------------
inline Animation::AnimType Animation::GetAnimType () const
{
	return mAnimType;
}
//----------------------------------------------------------------------------
inline void Animation::SetNormalTime (float time)
{
	mAnimNormalTime = time;
}
//----------------------------------------------------------------------------
inline float Animation::GetNormalTime () const
{
	return mAnimNormalTime;
}
//----------------------------------------------------------------------------
inline float Animation::GetTime () const
{
	return mAnimTime;
}
//----------------------------------------------------------------------------
inline float Animation::GetFrequency () const
{
	return mFrequency;
}
//----------------------------------------------------------------------------
inline const std::string &Animation::GetFilename () const
{
	return mAnimFilename;
}
//----------------------------------------------------------------------------
inline bool Animation::IsPlayOnce () const
{
	return mIsPlayOnce;
}
//----------------------------------------------------------------------------
inline void Animation::SetPlayedKeepPlaying (bool isPlayedKeepPlaying)
{
	mIsPlayedKeepPlaying = isPlayedKeepPlaying;
}
//----------------------------------------------------------------------------
inline bool Animation::IsPlayedKeepPlaying () const
{
	return mIsPlayedKeepPlaying;
}
//----------------------------------------------------------------------------
inline const Character *Animation::GetCharacter () const
{
	return mCharacter;
}
//----------------------------------------------------------------------------