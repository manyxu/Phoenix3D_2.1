/*
*
* ÎÄ¼þÃû³Æ	£º	PX2FMODSoundSystem.cpp
*
*/

#include "PX2FMODSoundSystem.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2Time.hpp"
#include "PX2Log.hpp"

#ifdef PX2_USE_FMOD
#include <fmod.hpp>
#endif

using namespace PX2;

//----------------------------------------------------------------------------
// MusicChannelInfo
//----------------------------------------------------------------------------
FMODSoundSystem::MusicChannelInfo::MusicChannelInfo ()
	:
ChannelMain(0),
ChannelFadein(0),
SoundMain(0),
SoundFadein(0),
FadeinTime(0.0f),
FadeinTimeLeft(0.0f),
MainVolume(0.0f),
FadeinVolume(0.0f),
Volume(0.0f)
{
}
//----------------------------------------------------------------------------
FMODSoundSystem::MusicChannelInfo::~MusicChannelInfo ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// FMODSoundRes
//----------------------------------------------------------------------------
FMODSoundSystem::FMODSoundRes::FMODSoundRes ()
	:
TheFMODSound(0)
{
}
//----------------------------------------------------------------------------
FMODSoundSystem::FMODSoundRes::~FMODSoundRes ()
{
	if (TheFMODSound)
		TheFMODSound->release();

	TheFMODSound = 0;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// FMODSoundSystem
//----------------------------------------------------------------------------
FMODSoundSystem::FMODSoundSystem ()
	:
SoundSystem(ST_FMOD),
mFMODSystem(0),
mChannelGroupMusic(0),
mChannelGroupSound(0)
{
}
//----------------------------------------------------------------------------
FMODSoundSystem::~FMODSoundSystem ()
{
	Terminate ();
}
//----------------------------------------------------------------------------
bool FMODSoundSystem::Initialize (const SoundSystemInitInfo &initInfo)
{
	if (FMOD::System_Create(&mFMODSystem) != FMOD_OK)
	{
		assertion(false, "FMOD::System_Create failed.");
		PX2_LOG_ERROR("FMOD::System_Create failed.");

		return false;
	}

	unsigned int version;
	if (mFMODSystem->getVersion(&version) != FMOD_OK)
	{
		assertion(false, "FMOD::getVersion failed.");
		PX2_LOG_ERROR("FMOD::getVersion failed.");

		return false;
	}

	if (version < FMOD_VERSION)
		return false;

	FMOD_CAPS caps;
	FMOD_SPEAKERMODE speakermode = FMOD_SPEAKERMODE_STEREO;
	if (mFMODSystem->getDriverCaps(0, &caps, 0, &speakermode) != FMOD_OK)
	{
		assertion (false, "FMOD::getDriverCaps failed.");
		PX2_LOG_ERROR("FMOD::getDriverCaps failed.");

		return false;
	}

	if (mFMODSystem->setSpeakerMode(speakermode) != FMOD_OK)
	{
		assertion (false, "FMOD::setSpeakerMode failed.");

		return false;
	}

	if (caps&FMOD_CAPS_HARDWARE_EMULATED)
	{
		if (mFMODSystem->setDSPBufferSize(1024, 10) != FMOD_OK)
		{
			assertion (false, "FMOD::setDSPBufferSize failed.");

			return false;
		}
	}

	if (mFMODSystem->init(initInfo.MaxChannels, FMOD_INIT_NORMAL, 0) != FMOD_OK)
	{
		assertion (false, "FMOD::init failed.");

		return false;
	}

	mFMODSystem->set3DSettings(initInfo.DopplerScale, initInfo.DistanceFactor,
		initInfo.RolloffScale);
	mFMODSystem->createChannelGroup(0, &mChannelGroupSound);

	return true;
}
//----------------------------------------------------------------------------
bool FMODSoundSystem::Terminate ()
{
	mSoundResMap.clear();

	if (mFMODSystem)
		mFMODSystem->release();
	mFMODSystem = 0;

	return true;
}
//----------------------------------------------------------------------------
void FMODSoundSystem::Clear ()
{
	mSoundResMap.clear();

	ClearMusicChannel(0, true, true);
	ClearMusicChannel(1, true, true);
	ClearMusicChannel(2, true, true);
	ClearMusicChannel(3, true, true);
}
//----------------------------------------------------------------------------
void FMODSoundSystem::Update (double appSeconds, double elapsedSeconds)
{
	PX2_UNUSED(appSeconds);

	float detalTime = (float)elapsedSeconds;

	for (int i=0; i<4; i++)
	{
		if (mMusicChannel[i].FadeinTimeLeft > 0.0f)
		{
			if (mMusicChannel[i].FadeinTimeLeft > detalTime)
				mMusicChannel[i].FadeinTimeLeft -= detalTime;
			else
				mMusicChannel[i].FadeinTimeLeft = 0.0f;

			float blend = (float)mMusicChannel[i].FadeinTimeLeft/
				(float)mMusicChannel[i].FadeinTime;

			if (mMusicChannel[i].ChannelMain)
				mMusicChannel[i].ChannelMain->setVolume(
				mMusicChannel[i].MainVolume*blend);
			if (mMusicChannel[i].ChannelFadein)
				mMusicChannel[i].ChannelFadein->setVolume(
				mMusicChannel[i].FadeinVolume*(1.0f-blend));
		}

		if (mMusicChannel[i].FadeinTime!=0.0f && 
			mMusicChannel[i].FadeinTimeLeft==0.0f)
		{
			if (mMusicChannel[i].ChannelMain)
			{
				mMusicChannel[i].ChannelMain->stop();
				mMusicChannel[i].SoundMain->release();
			}

			mMusicChannel[i].ChannelMain = mMusicChannel[i].ChannelFadein;
			mMusicChannel[i].SoundMain = mMusicChannel[i].SoundFadein;
			mMusicChannel[i].MainVolume = mMusicChannel[i].FadeinVolume;
			mMusicChannel[i].ChannelFadein = 0;
			mMusicChannel[i].SoundFadein = 0;
			mMusicChannel[i].FadeinTimeLeft = 0.0f;
		}
	}

	if (mFMODSystem)
		mFMODSystem->update();
}
//----------------------------------------------------------------------------
void FMODSoundSystem::SetListener (const APoint *position,
	const AVector *velocity, const AVector *forward,
	const AVector *up)
{
	SoundSystem::SetListener(position, velocity, forward, up);

	bool hasPos = false;
	FMOD_VECTOR pos;
	if (position)
	{
		hasPos = true;
		pos.x = position->X();
		pos.y = position->Y();
		pos.z = position->Z();
	}

	bool hasVec = false;
	FMOD_VECTOR vec;
	if (velocity)
	{
		hasVec = true;
		vec.x = velocity->X();
		vec.y = velocity->Y();
		vec.z = velocity->Z();
	}

	bool hasForward = false;
	FMOD_VECTOR forw;
	if (forward)
	{
		hasForward = true;
		forw.x = forward->X();
		forw.y = forward->Y();
		forw.z = forward->Z();
	}

	bool hasUp = false;
	FMOD_VECTOR upTemp;
	if (up)
	{
		hasUp = true;
		upTemp.x = up->X();
		upTemp.y = up->Y();
		upTemp.z = up->Z();
	}

	mFMODSystem->set3DListenerAttributes(0, hasPos ? &pos : 0, 
		hasVec ? &vec : 0, hasForward ? &forw : 0, hasUp? &upTemp : 0);
}
//----------------------------------------------------------------------------
void FMODSoundSystem::PlayMusic (int channel, const char *filename,
	bool isLoop, float fadeSeconds, float volume)
{
	FMOD::Sound *sound = 0;
	MusicChannelInfo &info = mMusicChannel[channel];

	if (filename)
	{
		if (info.SoundMain && std::string(filename)==info.MainPath)
		{
			ClearMusicChannel(channel, false, true);
			info.FadeinTime = 0.0f;
			info.FadeinTimeLeft =0.0f;
			info.MainVolume = volume;
			info.ChannelMain->setVolume(volume);
			return;
		}
		else if (info.SoundFadein && std::string(filename)==info.FadeinPath)
		{
			info.FadeinVolume = volume;
			return;
		}
		else if (mFMODSystem->createStream(filename, FMOD_2D|FMOD_LOOP_NORMAL,
			0, &sound) != FMOD_OK)
		{
			sound = 0;
		}
	}

	PlayMusicInternal(channel, sound, isLoop, fadeSeconds, volume);

	EnableMusic(IsMusicEnable());
}
//----------------------------------------------------------------------------
void FMODSoundSystem::SetMusicVolume (int channel, float volume)
{
	if (channel<0 || channel>4)
	{	
		assertion(false, "channel should in right range.");
		return;
	}

	mMusicChannel[channel].Volume = volume;

	if (mMusicChannel[channel].ChannelMain)
		mMusicChannel[channel].ChannelMain->setVolume(volume);

	if (mMusicChannel[channel].ChannelFadein)
		mMusicChannel[channel].ChannelFadein->setVolume(volume);
}
//----------------------------------------------------------------------------
bool FMODSoundSystem::PlaySound2DControl (const char *filename,
	float volume, bool isLoop, Sound *&rSound)
{
	if (!SoundSystem::PlaySound2DControl(filename, volume, isLoop, rSound))
		return false;
	FMODSoundSystem::FMODSoundRes *pres = GetSoundResource(filename, ST_2D);
	if(pres == NULL) return false;

	FMOD::Sound* fSound = pres->TheFMODSound;
	FMODSound *soundObj = 0;

	if (fSound)
	{
		FMOD::Channel *channel = 0;
		mFMODSystem->playSound(FMOD_CHANNEL_FREE, fSound, true, &channel);
		if (channel)
		{
			channel->setChannelGroup(mChannelGroupSound);
			channel->setVolume(volume);
			channel->setLoopCount(isLoop ? -1:0);
			channel->setPaused(false);

			soundObj = new0 FMODSound(channel);
			soundObj->Filename = filename;
		}
	}

	rSound = soundObj;

	return true;
}
//----------------------------------------------------------------------------
bool FMODSoundSystem::PlaySound3DControl (const char *filename, 
	const SoundCreateInfo3D &createInfo, Sound *&rSound)
{
	if (!SoundSystem::PlaySound3DControl(filename, createInfo, rSound))
		return false;

	FMOD::Sound *fSound = GetSoundResource(filename, ST_3D)->TheFMODSound;
	FMODSound *soundObj = 0;

	if (fSound)
	{
		FMOD::Channel *channel = 0;
		mFMODSystem->playSound(FMOD_CHANNEL_FREE, fSound, true, &channel);
		if (channel)
		{
			channel->setChannelGroup(mChannelGroupSound);
			channel->setVolume(createInfo.Volume);
			channel->setLoopCount(createInfo.IsLoop? -1:0);
			channel->set3DMinMaxDistance(createInfo.MinDistance, 
				createInfo.MaxDistance);

			FMOD_VECTOR pos;
			pos.x = createInfo.Position.X();
			pos.y = createInfo.Position.Y();
			pos.z = createInfo.Position.Z();
			FMOD_VECTOR vec;
			vec.x = createInfo.Velocity.X();
			vec.y = createInfo.Velocity.Y();
			vec.z = createInfo.Velocity.Z();
			channel->set3DAttributes(&pos, &vec);
			channel->setPaused(false);
			
			soundObj = new0 FMODSound(channel);
			soundObj->Filename = filename;
		}
	}

	rSound = soundObj;

	return true;
}
//----------------------------------------------------------------------------
void FMODSoundSystem::PlayMusicInternal(int channel, FMOD::Sound *sound,
	bool isLoop, float fadeTime, float volume, 
	const char *path)
{
	assertion(channel<4, "channel should be less than 4.");

	if (channel<0 || channel>=4)
		return;

	mMusicChannel[channel].FadeinTime = fadeTime;
	mMusicChannel[channel].FadeinTime = fadeTime;

	if (fadeTime == 0.0f)
	{
		ClearMusicChannel(channel, true, true);

		if (sound)
		{
			mFMODSystem->playSound(FMOD_CHANNEL_FREE, sound, true, 
				&mMusicChannel[channel].ChannelMain);
			mMusicChannel[channel].SoundMain = sound;
			mMusicChannel[channel].MainVolume = volume;
			mMusicChannel[channel].ChannelMain->setChannelGroup(mChannelGroupMusic);
			mMusicChannel[channel].ChannelMain->setVolume(volume);
			mMusicChannel[channel].ChannelMain->setLoopCount(isLoop ? -1:0);
			mMusicChannel[channel].ChannelMain->setPaused(false);
		}

		mMusicChannel[channel].MainPath = std::string(path);
	}
	else
	{
		ClearMusicChannel(channel, false, true);

		if (sound)
		{
			mFMODSystem->playSound(FMOD_CHANNEL_FREE, sound, true, 
				&mMusicChannel[channel].ChannelFadein);
			mMusicChannel[channel].SoundFadein = sound;
			mMusicChannel[channel].FadeinVolume = volume;
			mMusicChannel[channel].ChannelFadein->setChannelGroup(mChannelGroupMusic);
			mMusicChannel[channel].ChannelFadein->setVolume(0.0f);
			mMusicChannel[channel].ChannelFadein->setLoopCount(isLoop ? -1:0);
			mMusicChannel[channel].ChannelFadein->setPaused(false);
		}

		mMusicChannel[channel].FadeinPath = std::string(path);
	}
}
//----------------------------------------------------------------------------
void FMODSoundSystem::ClearMusicChannel (int channel, bool main, bool fadein)
{
	MusicChannelInfo &info = mMusicChannel[channel];
	if (main && info.ChannelMain)
	{
		info.ChannelMain->stop();
		info.ChannelMain = 0;
		if (info.SoundMain)
		{
			info.SoundMain->release();
			info.SoundMain = 0;
		}
	}

	if (fadein && info.ChannelFadein)
	{
		info.ChannelFadein->stop();
		info.ChannelFadein = 0;
		if (info.SoundFadein)
		{
			info.SoundFadein->release();
			info.SoundFadein = 0;
		}
	}
}
//----------------------------------------------------------------------------
FMODSoundSystem::FMODSoundRes *FMODSoundSystem::GetSoundResource (
	const char *fileName, SoundType type)
{
	if (!fileName)
		return 0;

	FMODSoundResMap::iterator it = mSoundResMap.find(fileName);
	if (it != mSoundResMap.end())
	{
		return (*it).second;
	}

	int bufferSize = 0;
	char *buffer = 0;
	if (PX2_RM.LoadBuffer(fileName, bufferSize, buffer))
	{
		FMOD::Sound *sound = 0;
		FMOD_MODE mode = FMOD_LOOP_NORMAL|FMOD_3D_LINEARROLLOFF|FMOD_HARDWARE
			|FMOD_OPENMEMORY;

		if (type == ST_2D)
			mode |= FMOD_2D;
		else
			mode |= FMOD_3D;

		FMOD_CREATESOUNDEXINFO exinfo;
		memset(&exinfo, 0, sizeof(exinfo));
		exinfo.cbsize = sizeof(exinfo);
		exinfo.length = bufferSize;

		if (mFMODSystem->createSound((const char*)buffer, mode, &exinfo,
			&sound) != FMOD_OK)
		{
			assertion(false, "createSound %s failed.", fileName);
			PX2_LOG_ERROR("createSound %s failed.", fileName);
		}

		FMODSoundResPtr res = new0 FMODSoundRes;
		res->SoundFilename = std::string(fileName);
		res->TheFMODSound = sound;
		mSoundResMap[res->SoundFilename] = res;

		return res;
	}
	else
	{
		assertion(false, "Open sound file failed: %s", fileName);
		PX2_LOG_ERROR("Open sound file failed: %s", fileName);

		return 0;
	}
}
//----------------------------------------------------------------------------
void FMODSoundSystem::EnableSounds (bool enable)
{
	SoundSystem::EnableSounds(enable);

	if (!enable)
		mChannelGroupSound->setVolume(0.0f);
	else
		mChannelGroupSound->setVolume(1.0f);
}
//----------------------------------------------------------------------------