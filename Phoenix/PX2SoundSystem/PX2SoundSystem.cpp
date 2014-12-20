/*
*
* ÎÄ¼þÃû³Æ	£º	PX2SoundSystem.cpp
*
*/

#include "PX2SoundSystem.hpp"
#include "PX2Time.hpp"

#ifdef PX2_USE_FMOD
#include "PX2FMODSoundSystem.hpp"
#elif defined(__ANDROID__)
#include "PX2AndroidSoundSystem.hpp"
#elif defined(__MARMALADE__)
#include "PX2MARMSoundSystem.hpp"
#endif

using namespace PX2;

//----------------------------------------------------------------------------
SoundSystemInitInfo::SoundSystemInitInfo ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// SoundCreateInfo3D
//----------------------------------------------------------------------------
SoundCreateInfo3D::SoundCreateInfo3D ()
	:
MinDistance(0.0f),
MaxDistance(0.0f),
Volume(1.0f),
IsLoop(true)
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// SoundSystem
//----------------------------------------------------------------------------
SoundSystem::SoundSystem ()
	:
mSystemType(ST_NULL),
mMaxNumPlaySameTime(5),
mPlaySameTimeRange(0.2f),
mIsMusicEnable(true),
mIsSoundEnable(true)
{
}
//----------------------------------------------------------------------------
SoundSystem::SoundSystem (SystemType type)
	:
mSystemType(type),
mMaxNumPlaySameTime(3),
mPlaySameTimeRange(0.2f),
mIsMusicEnable(true),
mIsSoundEnable(true)
{
}
//----------------------------------------------------------------------------
SoundSystem::~SoundSystem ()
{
}
//----------------------------------------------------------------------------
void SoundSystem::Clear ()
{
}
//----------------------------------------------------------------------------
void SoundSystem::Update (double appSeconds, double elapsedSeconds)
{
	PX2_UNUSED(appSeconds);
	PX2_UNUSED(elapsedSeconds);
}
//----------------------------------------------------------------------------
SoundSystem *SoundSystem::Create (SystemType type,
	const SoundSystemInitInfo &initInfo)
{
	PX2_UNUSED(type);

#ifdef PX2_USE_FMOD
	FMODSoundSystem *soundSystem = new0 FMODSoundSystem();
	if (!soundSystem->Initialize(initInfo))
	{
		delete0(soundSystem);
		return 0;
	}

	return soundSystem;
#elif defined(__ANDROID__)
	AndroidSoundSystem *as = new0 AndroidSoundSystem();
	return as;
#elif defined(__MARMALADE__)
	MARMSoundSystem *ss = new0 MARMSoundSystem();
	if(!ss->Initialize(initInfo))
	{
		delete0(ss);
		return 0;
	}
	return ss;
#else
	assertion(false, "Not supported now.");
	return 0;
#endif
}
//----------------------------------------------------------------------------
void SoundSystem::SetListener (const APoint *position,
	const AVector *velocity, const AVector *forward,
	const AVector *up)
{
	if (position)
	{
		mListenPos = *position;
	}

	PX2_UNUSED(velocity);
	PX2_UNUSED(forward);
	PX2_UNUSED(up);
}
//----------------------------------------------------------------------------
void SoundSystem::EnableMusic (bool enable)
{
	mIsMusicEnable = enable;

	for (int i=0; i<4; i++)
	{
		SetMusicVolume(i, enable? 1.0f : 0.0f);
	}
}
//----------------------------------------------------------------------------
bool SoundSystem::PlaySound2DControl (const char *filename,
	float volume, bool isLoop, Sound *&sound)
{
	PX2_UNUSED(volume);
	PX2_UNUSED(isLoop);
	PX2_UNUSED(sound);

	if (!IsSoundEnable())
		return false;

	if (CanPlaySameTime(filename, (float)GetTimeInSeconds()))
	{
		mNumCurPlaying[filename]++;

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void SoundSystem::LoadSound (const char *filename)
{
	PX2_UNUSED(filename);
}
//----------------------------------------------------------------------------
void SoundSystem::UnloadSound (const char *filename)
{
	PX2_UNUSED(filename);
}
//----------------------------------------------------------------------------
bool SoundSystem::PlaySound3DControl (const char *filename, 
	const SoundCreateInfo3D &createInfo, Sound *&sound)
{
	PX2_UNUSED(createInfo);
	PX2_UNUSED(sound);

	if (!IsSoundEnable())
		return false;

	if (CanPlaySameTime(filename, (float)GetTimeInSeconds()))
	{
		mNumCurPlaying[filename]++;

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void SoundSystem::EnableSounds (bool enable)
{
	mIsSoundEnable = enable;
}
//----------------------------------------------------------------------------
bool SoundSystem::CanPlaySameTime (const std::string &filename, float playTime)
{
	std::map<std::string, float>::iterator itLastPlayTime = mLastPlayTime.find(filename);
	
	if (itLastPlayTime != mLastPlayTime.end())
	{
		float timeDist = playTime - itLastPlayTime->second;

		if (timeDist < mPlaySameTimeRange)
		{
			return false;
		}
		else
		{
			itLastPlayTime->second = playTime;
		}
	}
	else
	{
		mLastPlayTime[filename] = playTime;
	}

	std::map<std::string, int>::iterator it = mNumCurPlaying.find(filename);

	if (it != mNumCurPlaying.end())
	{
		int curNum = it->second;
		
		if (curNum < mMaxNumPlaySameTime)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (0 < mMaxNumPlaySameTime)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
//----------------------------------------------------------------------------
int SoundSystem::GetNumPlaySameTime (const std::string &filename)
{
	std::map<std::string, int>::iterator it = mNumCurPlaying.find(filename);

	if (it != mNumCurPlaying.end())
	{
		return it->second;
	}

	return 0;
}
//----------------------------------------------------------------------------
void SoundSystem::MinusNumPlaySameTime (const std::string &filename)
{
	std::map<std::string, int>::iterator it = mNumCurPlaying.find(filename);

	if (it != mNumCurPlaying.end())
	{
		it->second--;

		if (it->second < 0)
		{
			it->second = 0;
		//	assertion(false, "MinusNumPlaySameTime < 0.0f\n");
		}
	}
}
//----------------------------------------------------------------------------
void SoundSystem::ResetNumPlaySameTime (const std::string &filename)
{
	mNumCurPlaying.erase(filename);
	mLastPlayTime.erase(filename);
}
//----------------------------------------------------------------------------