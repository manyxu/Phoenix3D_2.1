/*
*
* ÎÄ¼þÃû³Æ	£º	PX2MARMSoundSystem.hpp
*
*/

#ifndef PX2MARMSOUNDSYSTEM_HPP
#define PX2MARMSOUNDSYSTEM_HPP

#include "PX2SoundSystem.hpp"
#include "PX2MARMSound.hpp"
#include "PX2SmartPointer.hpp"
#include "PX2WavReader.hpp"

namespace PX2
{
	class WavReader;
	class MARMSoundSystem : public SoundSystem
	{
	public:
		MARMSoundSystem ();
		virtual ~MARMSoundSystem ();

		virtual void Clear ();

		virtual void Update (double appSeconds, double elapsedSeconds);

		virtual void SetListener (const APoint *position,
			const AVector *velocity, const AVector *forward,
			const AVector *up);

		virtual void PlayMusic (int channel, const char *filename,
			bool isLoop, float fadeSeconds, float volume=1.0f);
		virtual void SetMusicVolume (int channel, float volume);

		virtual bool PlaySound2DControl (const char *filename,
			float volume, bool isLoop, Sound *&sound);
		virtual bool PlaySound3DControl (const char *filename, 
			const SoundCreateInfo3D &createInfo, Sound *&sound);

public_internal:
		bool Initialize (const SoundSystemInitInfo &initInfo);
		bool Terminate ();

	protected:
		enum SoundType
		{
			ST_2D,
			ST_3D
		};

		typedef std::map<std::string, WavReaderPtr> MARMSoundResMap;

		WavReader *GetSoundResource (const char *fileName, SoundType type);
		MARMSoundResMap mSoundResMap;
		int mMaxMusicChannels;

		int mOutputFreq;
		int mStereoEnabled;
	};

}

#endif