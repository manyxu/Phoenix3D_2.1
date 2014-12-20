/*
*
* ÎÄ¼þÃû³Æ	£º	PX2MARMSound.hpp
*
*/

#ifndef PX2MARMSOUND_HPP
#define PX2MARMSOUND_HPP

#include "PX2Sound.hpp"

namespace PX2
{

	class MARMSound : public Sound
	{
	public:
		MARMSound (int channel);
		virtual ~MARMSound ();

		virtual bool IsPlaying ();
		virtual void SetVolume (float volume);
		virtual void SetPaused (bool paused);
		virtual void Stop ();

		virtual void SetPosition (const APoint &position);
		virtual void SetVelocity (const AVector &velocity);
		virtual void SetDistance (float minDistance, float maxDistance);

	private:
		int mChannel;
	};

}

#endif