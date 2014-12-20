/*
*
* ÎÄ¼þÃû³Æ	£º	PX2GameSoundManager.cpp
*
*/

#include "PX2SoundManager.hpp"
#include "PX2SoundSystem.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
SoundManager::SoundManager ()
{

}
//----------------------------------------------------------------------------
SoundManager::~SoundManager()
{
}
//----------------------------------------------------------------------------
void SoundManager::ClearPreLoadSoundFiles ()
{
	for (int i=0; i<(int)mPreLoadSoundFiles.size(); i++)
	{
		PX2_SS.UnloadSound(mPreLoadSoundFiles[i].c_str());
	}

	mPreLoadSoundFiles.clear();
}
//----------------------------------------------------------------------------
void SoundManager::AddPreLoadSound (const std::string &filename)
{
	mPreLoadSoundFiles.push_back(filename);
}
//----------------------------------------------------------------------------
void SoundManager::PreLoad ()
{
	for (int i=0; i<(int)mPreLoadSoundFiles.size(); i++)
	{
		if (!mPreLoadSoundFiles[i].empty())
		{
			PX2_SS.LoadSound(mPreLoadSoundFiles[i].c_str());
		}
	}
}
//----------------------------------------------------------------------------
void SoundManager::Clear ()
{
	std::map<std::string, SoundCtrlObjPtr>::iterator it = 
		mSoundMap.begin();
	for (; it!=mSoundMap.end();)
	{
		SoundCtrlObj *obj = it->second;
		if (obj->TheSound)
		{
			obj->TheSound->MinusNumPlaySameTime();
			obj->TheSound->Stop();
		}
	}

	mSoundMap.clear();

	for (int i=0; i<(int)mASoundArray.size(); i++)
	{
		mASoundArray[i]->TheSound->MinusNumPlaySameTime();
		mASoundArray[i]->TheSound->Stop();
	}
	mASoundArray.clear();
}
//----------------------------------------------------------------------------
void SoundManager::Update (double appSeconds, double elapsedSeconds)
{
	PX2_UNUSED(appSeconds);

	std::map<std::string, SoundCtrlObjPtr>::iterator it = 
		mSoundMap.begin();
	std::map<std::string, SoundCtrlObjPtr>::iterator ittemp;

	for (; it!=mSoundMap.end();)
	{
		SoundCtrlObj *obj = it->second;
		if (obj->IsDoingStop)
		{
			float curVolume = obj->CurVolume;
			curVolume -= (obj->DisSpeed*(float)elapsedSeconds);
			if (curVolume <= 0.0f)
			{
				if (obj->TheSound)
				{
					obj->TheSound->Stop();
				}
				ittemp = it;
				it++;
				mSoundMap.erase(ittemp);
			}
			else
			{
				obj->CurVolume = curVolume;
				if (obj->TheSound)
				{
					obj->TheSound->SetVolume(curVolume);
				}

				it++;
			}
		}
		else
		{
			it++;
		}
	}

	std::vector<SoundCtrlObjPtr>::iterator it1=mASoundArray.begin(); 
	for(; it1!=mASoundArray.end();)
	{
		(*it1)->DeleteTime -= (float)elapsedSeconds;

		if ((*it1)->DeleteTime <= 0.0f)
		{
			(*it1)->TheSound->MinusNumPlaySameTime();
			(*it1)->TheSound->Stop();

			it1 = mASoundArray.erase(it1);
		}
		else
		{
			it1++;
		}
	}
}
//----------------------------------------------------------------------------
void SoundManager::PlaySound (const std::string &name,
	const std::string &filename, float volume, bool isLoop)
{
	SoundCtrlObjPtr sObj;

	std::map<std::string, SoundCtrlObjPtr>::iterator it = mSoundMap.find(name);
	if (it == mSoundMap.end())
	{
		sObj = new0 SoundCtrlObj();

		Sound *sound = 0;
		PX2_SS.ResetNumPlaySameTime(filename);
		PX2_SS.PlaySound2DControl(filename.c_str(), volume, isLoop, sound);		
		if (sound)
		{
			sObj->TheSound = sound;
			mSoundMap[name] = sObj;
		}
	}
	else
	{
		sObj = it->second;

		Sound *sound = 0;
		PX2_SS.ResetNumPlaySameTime(filename);
		PX2_SS.PlaySound2DControl(filename.c_str(), volume, isLoop, sound);
		if (sound)
		{
			sObj->TheSound = sound;
		}
	}

	if (sObj)
	{
		sObj->SoundName = name;
		sObj->SoundFilename = filename;
		sObj->InitVolume = volume;
		sObj->CurVolume = volume;
	}
}
//----------------------------------------------------------------------------
void SoundManager::PlayASound (const std::string &filename, float volume,
	float deleteTime)
{
	PX2_SS.ResetNumPlaySameTime(filename);

	Sound *sound = 0;
	if (PX2_SS.PlaySound2DControl(filename.c_str(), volume, false, sound))
	{
		if (sound)
		{
			SoundCtrlObjPtr sObj = new0 SoundCtrlObj();
			sObj->TheSound = sound;
			sObj->DeleteTime = deleteTime;

			mASoundArray.push_back(sObj);
		}
	}
}
//----------------------------------------------------------------------------
void SoundManager::StopSound (const std::string &name, float disTime)
{
	std::map<std::string, SoundCtrlObjPtr>::iterator it = mSoundMap.find(name);
	if (it != mSoundMap.end())
	{
		it->second->IsDoingStop = true;
		it->second->DisTime = disTime;

		if (0.0f == disTime)
		{
			disTime = 0.001f;
		}

		it->second->DisSpeed = it->second->CurVolume/disTime;
	}
}
//----------------------------------------------------------------------------
SoundManager::SoundCtrlObj::SoundCtrlObj ()
	:
InitVolume(1.0f),
CurVolume(1.0f),
IsDoingStop(false),
StopDelayTime(0.0f),
DisTime(0.0f),
DisSpeed(1.0),
DeleteTime(0.0f)
{
}
//----------------------------------------------------------------------------
SoundManager::SoundCtrlObj::~SoundCtrlObj ()
{
}
//----------------------------------------------------------------------------