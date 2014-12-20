/*
*
* ÎÄ¼þÃû³Æ	£º	PX2AndroidSoundSystem.hpp
*
*/

#ifndef PX2ANDROIDSOUNDSYSTEM_HPP
#define PX2ANDROIDSOUNDSYSTEM_HPP

#include "PX2SoundSystem.hpp"
#include "PX2SmartPointer.hpp"

namespace PX2
{

	class AndroidSoundSystem : public SoundSystem
	{
	public:
		AndroidSoundSystem ();
		virtual ~AndroidSoundSystem ();

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
		virtual void LoadSound (const char *filename);
		virtual void UnloadSound (const char *filename);

	protected:

		struct MusicChannelInfo
		{
			MusicChannelInfo ();
			~MusicChannelInfo ();

			std::string Filename;
			float Volume;
		};
		MusicChannelInfo mMusicChannel[4];
	};

}

#endif