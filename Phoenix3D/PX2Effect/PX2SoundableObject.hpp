// PX2SoundableObject.hpp

#ifndef PX2SOUNDABLEOBJECT_HPP
#define PX2SOUNDABLEOBJECT_HPP

#include "PX2EffectObject.hpp"
#include "PX2APoint.hpp"

namespace PX2
{

	class SoundableObject : public EffectObject
	{
	public:
		SoundableObject ();
		virtual ~SoundableObject ();

		virtual bool Update (Effectable *able, float elapsedTime);

		float VolumeInit;
		float Volume;
	};
	typedef Pointer0<SoundableObject> SoundableObjectPtr;

}

#endif