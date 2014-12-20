/*
*
* ÎÄ¼þÃû³Æ	£º	PX2AndroidSound.hpp
*
*/

#ifndef PX2ANDROIDSOUND_HPP
#define PX2ANDROIDSOUND_HPP

#include "PX2Sound.hpp"

namespace PX2
{

	class AndroidSound : public Sound
	{
	public:
		AndroidSound (int instance);
		virtual ~AndroidSound ();

		virtual bool IsPlaying ();
		virtual void SetVolume (float volume);
		virtual void SetPaused (bool paused);
		virtual void Stop ();

		virtual void SetPosition (const APoint &position);
		virtual void SetVelocity (const AVector &velocity);
		virtual void SetDistance (float minDistance, float maxDistance);

	private:
		AndroidSound();

		int mInstance;
	};

}

#endif