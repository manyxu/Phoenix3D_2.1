/*
*
* ÎÄ¼þÃû³Æ	£º	PX2MARMSoundSystem.cpp
*
*/

#include "PX2MARMSoundSystem.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2Time.hpp"
#include "PX2Log.hpp"
#include "PX2WavReader.hpp"

#include "s3eAudio.h"
#include "s3eSound.h"

using namespace PX2;

//----------------------------------------------------------------------------
// MARMSoundSystem
//----------------------------------------------------------------------------
MARMSoundSystem::MARMSoundSystem ()
	:
SoundSystem(ST_MARM)
{
}
//----------------------------------------------------------------------------
MARMSoundSystem::~MARMSoundSystem ()
{
	Terminate ();
}
//----------------------------------------------------------------------------
bool MARMSoundSystem::Initialize (const SoundSystemInitInfo &initInfo)
{
	mMaxMusicChannels = s3eAudioGetInt(S3E_AUDIO_NUM_CHANNELS);
	mOutputFreq = s3eSoundGetInt(S3E_SOUND_OUTPUT_FREQ);
	mStereoEnabled = s3eSoundGetInt(S3E_SOUND_STEREO_ENABLED);

	s3eSoundSetInt(S3E_SOUND_DEFAULT_FREQ, 22050);

	//PlayMusic(0, "Data\\sounds\\game\\bgm.mp3", true, 0, 0.8f);
	return true;
}
//----------------------------------------------------------------------------
bool MARMSoundSystem::Terminate ()
{
	mSoundResMap.clear();
	return true;
}
//----------------------------------------------------------------------------
void MARMSoundSystem::Clear ()
{
	mSoundResMap.clear();
}
//----------------------------------------------------------------------------
void MARMSoundSystem::Update (double appSeconds, double elapsedSeconds)
{
	PX2_UNUSED(appSeconds);
}
//----------------------------------------------------------------------------
void MARMSoundSystem::SetListener (const APoint *position,
	const AVector *velocity, const AVector *forward,
	const AVector *up)
{
}
//----------------------------------------------------------------------------
void MARMSoundSystem::PlayMusic (int channel, const char *filename,
	bool isLoop, float fadeSeconds, float volume)
{
	if(channel >= mMaxMusicChannels) channel = 0;
	s3eAudioSetInt(S3E_AUDIO_CHANNEL, channel);

	if (filename)
	{
		char *p = strstr(filename, "Data");
		assert(p == filename);

		s3eAudioPlay(filename+5, isLoop?0:1);
		s3eAudioSetInt(S3E_AUDIO_VOLUME, int(volume*256));
	}
	else
	{
		s3eAudioStop();
	}
}
//----------------------------------------------------------------------------
void MARMSoundSystem::SetMusicVolume (int channel, float volume)
{
	if(channel >= mMaxMusicChannels) channel = 0;
	s3eAudioSetInt(S3E_AUDIO_CHANNEL, channel);

	s3eAudioSetInt(S3E_AUDIO_VOLUME, int(volume*256));
}
//----------------------------------------------------------------------------
bool MARMSoundSystem::PlaySound2DControl (const char *filename,
	float volume, bool isLoop, Sound *&rSound)
{
	if (!SoundSystem::PlaySound2DControl(filename, volume, isLoop, rSound))
		return false;

	WavReader *pres = GetSoundResource(filename, ST_2D);
	MARMSound *soundobj = NULL;

	if (pres)
	{
		int channel = s3eSoundGetFreeChannel();
		if(channel >= 0)
		{
			s3eSoundChannelSetInt(channel, S3E_CHANNEL_VOLUME, int(volume*S3E_SOUND_MAX_VOLUME));
			s3eSoundChannelPlay(channel, pres->GetSamples(), pres->GetSampleCount(), 1, 0);

			soundobj = new MARMSound(channel);
			soundobj->Filename = filename;
		}
	}

	rSound = soundobj;
	return true;
}
//----------------------------------------------------------------------------
bool MARMSoundSystem::PlaySound3DControl (const char *filename, 
	const SoundCreateInfo3D &createInfo, Sound *&sound)
{
	return false;
}
//----------------------------------------------------------------------------
WavReader *MARMSoundSystem::GetSoundResource (
	const char *fileName, SoundType type)
{
	if (!fileName)
		return 0;

	MARMSoundResMap::iterator it = mSoundResMap.find(fileName);
	if (it != mSoundResMap.end())
	{
		return (*it).second;
	}

	int bufferSize = 0;
	char *buffer = 0;
	WavReader *reader = NULL;
	std::string fullpath(fileName);
	fullpath = fullpath.substr(0, fullpath.find_last_of('.'));
	fullpath += ".wav";

	if (PX2_RM.LoadBuffer(fullpath, bufferSize, buffer))
	{
		reader = new0 WavReader;
		if(!reader->LoadFromBuffer(buffer, bufferSize))
		{
			PX2_LOG_ERROR("Load wav file failed: %s", fullpath.c_str());
			delete0(reader);
			reader = NULL;
		}

		delete1(buffer);
		bufferSize = 0;
	}
	else
	{
		assertion(false, "Open sound file failed: %s", fileName);
		PX2_LOG_ERROR("Open sound file failed: %s", fileName);
	}

	mSoundResMap[std::string(fileName)] = reader;
	return reader;
}
//----------------------------------------------------------------------------