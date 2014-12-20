/*
*
* ÎÄ¼þÃû³Æ	£º	PX2FMODSound.hpp
*
*/

#ifndef PX2FMODSOUND_HPP
#define PX2FMODSOUND_HPP

#include "PX2Sound.hpp"

#ifdef PX2_USE_FMOD
#include <fmod.hpp>
#endif

namespace PX2
{

	class FMODSound : public Sound
	{
	public:
		FMODSound (FMOD::Channel *channel);
		virtual ~FMODSound ();

		virtual bool IsPlaying ();
		virtual void SetVolume (float volume);
		virtual void SetPaused (bool paused);
		virtual void Stop ();

		virtual void SetPosition (const APoint &position);
		virtual void SetVelocity (const AVector &velocity);
		virtual void SetDistance (float minDistance, float maxDistance);

	private:
		FMODSound ();

		FMOD::Channel *mChannel;
	};

}

#endif