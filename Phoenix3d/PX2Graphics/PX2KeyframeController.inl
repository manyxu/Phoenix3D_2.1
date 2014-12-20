/*
*
* ÎÄ¼þÃû³Æ	£º	PX2KeyframeController.inl
*
*/

//----------------------------------------------------------------------------
inline int KeyframeController::GetNumCommonTimes () const
{
	return mNumCommonTimes;
}
//----------------------------------------------------------------------------
inline float* KeyframeController::GetCommonTimes () const
{
	return mCommonTimes;
}
//----------------------------------------------------------------------------
inline int KeyframeController::GetNumTranslations () const
{
	return mNumTranslations;
}
//----------------------------------------------------------------------------
inline float* KeyframeController::GetTranslationTimes () const
{
	return mTranslationTimes;
}
//----------------------------------------------------------------------------
inline APoint* KeyframeController::GetTranslations () const
{
	return mTranslations;
}
//----------------------------------------------------------------------------
inline int KeyframeController::GetNumRotations () const
{
	return mNumRotations;
}
//----------------------------------------------------------------------------
inline float* KeyframeController::GetRotationTimes () const
{
	return mRotationTimes;
}
//----------------------------------------------------------------------------
inline HQuaternion* KeyframeController::GetRotations () const
{
	return mRotations;
}
//----------------------------------------------------------------------------
inline int KeyframeController::GetNumScales () const
{
	return mNumScales;
}
//----------------------------------------------------------------------------
inline float* KeyframeController::GetScaleTimes () const
{
	return mScaleTimes;
}
//----------------------------------------------------------------------------
inline float* KeyframeController::GetScales () const
{
	return mScales;
}
//----------------------------------------------------------------------------
