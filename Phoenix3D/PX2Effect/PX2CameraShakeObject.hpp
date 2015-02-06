/*
*
* ÎÄ¼þÃû³Æ	£º	PX2CameraShakeObject.hpp
*
*/

#ifndef PX2CAMERASHAKEOBJECT_HPP
#define PX2CAMERASHAKEOBJECT_HPP

#include "PX2EffectObject.hpp"
#include "PX2APoint.hpp"

namespace PX2
{

	class CameraShakeObject : public EffectObject
	{
	public:
		CameraShakeObject ();
		virtual ~CameraShakeObject ();

		virtual bool Update (Effectable *able, float elapsedTime);

		float StrengthInit;
		float Strength;
	};
	typedef Pointer0<CameraShakeObject> CameraShakeObjectPtr;

}

#endif