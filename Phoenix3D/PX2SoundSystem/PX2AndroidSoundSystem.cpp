/*
*
* ÎÄ¼þÃû³Æ	£º	PX2AndroidSoundSystem.cpp
*
*/

#include "PX2AndroidSoundSystem.hpp"
#include "PX2AndroidSound.hpp"
#include "PX2JNI.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
AndroidSoundSystem::AndroidSoundSystem ()
{
}
//----------------------------------------------------------------------------
AndroidSoundSystem::~AndroidSoundSystem ()
{
}
//----------------------------------------------------------------------------
void AndroidSoundSystem::Clear ()
{
#ifdef __ANDROID__
	ClearMedialJNI();
#endif
}
//----------------------------------------------------------------------------
void AndroidSoundSystem::Update (double appSeconds, double elapsedSeconds)
{
	PX2_UNUSED(appSeconds);
	PX2_UNUSED(elapsedSeconds);

	SoundSystem::Update(appSeconds, elapsedSeconds);
}
//----------------------------------------------------------------------------
void AndroidSoundSystem::SetListener (const APoint *position,
	const AVector *velocity, const AVector *forward, const AVector *up)
{
	SoundSystem::SetListener(position, velocity, forward, up);
}
//----------------------------------------------------------------------------
void AndroidSoundSystem::PlayMusic (int channel, const char *filename,
	bool isLoop, float fadeSeconds, float volume)
{
	PX2_UNUSED(channel);
	PX2_UNUSED(filename);
	PX2_UNUSED(isLoop);
	PX2_UNUSED(fadeSeconds);
	PX2_UNUSED(volume);

#ifdef __ANDROID__
	if (0 == filename)
	{
		StopMusicJNI(channel);

		mMusicChannel[channel].Filename = "";
		mMusicChannel[channel].Volume = volume;
	}
	else
	{
		PlayMusicJNI(channel, filename, volume, isLoop);

		mMusicChannel[channel].Filename = filename;
		mMusicChannel[channel].Volume = volume;
	}
#endif

	EnableMusic(IsMusicEnable());
}
//----------------------------------------------------------------------------
void AndroidSoundSystem::SetMusicVolume (int channel, float volume)
{
	PX2_UNUSED(channel);
	PX2_UNUSED(volume);

#ifdef __ANDROID__
	SetMusicVolumeJNI(channel, volume);
#endif

	mMusicChannel[channel].Volume = volume;
}
//----------------------------------------------------------------------------
 bool AndroidSoundSystem::PlaySound2DControl (const char *filename,
	float volume, bool isLoop, Sound *&rSound)
{
	if (!SoundSystem::PlaySound2DControl(filename, volume, isLoop, rSound))
		return false;

	int ret = -1;

#ifdef __ANDROID__
	ret = PlaySound2DJNI(filename, volume, false);
#endif

	if (-1 != ret)
	{
		rSound = new0 AndroidSound(ret);
		rSound->Filename = filename;

		return true;
	}
	else
	{
		return false;
	}
}
//----------------------------------------------------------------------------
bool AndroidSoundSystem::PlaySound3DControl (const char *filename, 
	const SoundCreateInfo3D &createInfo, Sound *&rSound)
{
	if (!SoundSystem::PlaySound3DControl(filename, createInfo, rSound))
		return false;

	rSound = 0;

	return true;
}
//----------------------------------------------------------------------------
void AndroidSoundSystem::LoadSound (const char *filename)
{
	SoundSystem::LoadSound(filename);

#ifdef __ANDROID__
	LoadSoundJNI(filename);
#endif
}
//----------------------------------------------------------------------------
void AndroidSoundSystem::UnloadSound (const char *filename)
{
	SoundSystem::UnloadSound(filename);

#ifdef __ANDROID__
	UnLoadSoundJNI(filename);
#endif
}
//----------------------------------------------------------------------------
AndroidSoundSystem::MusicChannelInfo::MusicChannelInfo ()
{
}
//----------------------------------------------------------------------------
AndroidSoundSystem::MusicChannelInfo::~MusicChannelInfo ()
{
}
//----------------------------------------------------------------------------