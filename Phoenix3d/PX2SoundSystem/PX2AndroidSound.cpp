/*
*
* ÎÄ¼þÃû³Æ	£º	PX2AndroidSound.hpp
*
*/

#include "PX2AndroidSound.hpp"
#include "PX2JNI.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
AndroidSound::AndroidSound (int instance)
	:
mInstance(instance)
{
}
//----------------------------------------------------------------------------
AndroidSound::~AndroidSound ()
{
}
//----------------------------------------------------------------------------
bool AndroidSound::IsPlaying ()
{
	return true;
}
//----------------------------------------------------------------------------
void AndroidSound::SetVolume (float volume)
{
#ifdef __ANDROID__
	SetSoundVolumeJNI(mInstance, volume);
#endif
}
//----------------------------------------------------------------------------
void AndroidSound::SetPaused (bool paused)
{
#ifdef __ANDROID__
	if (paused)
		PauseSoundJNI(mInstance);
	else
		ResumeSoundJNI(mInstance);
#endif
}
//----------------------------------------------------------------------------
void AndroidSound::Stop ()
{
#ifdef __ANDROID__
	StopSoundJNI(mInstance);
#endif
}
//----------------------------------------------------------------------------
void AndroidSound::SetPosition (const APoint &position)
{
	PX2_UNUSED(position);
}
//----------------------------------------------------------------------------
void AndroidSound::SetVelocity (const AVector &velocity)
{
	PX2_UNUSED(velocity);
}
//----------------------------------------------------------------------------
void AndroidSound::SetDistance (float minDistance, float maxDistance)
{
	PX2_UNUSED(minDistance);
	PX2_UNUSED(maxDistance);
}
//----------------------------------------------------------------------------
