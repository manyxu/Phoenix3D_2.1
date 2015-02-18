// PX2AnimationObject.hpp

#ifndef PX2ANIMATIONOBJECT_HPP
#define PX2ANIMATIONOBJECT_HPP

#include "PX2Animation.hpp"

namespace PX2
{

	const float ANIMATION_BLENDTIME = 0.2f;

	class AnimationObject
	{
	public:
		AnimationObject();
		~AnimationObject();

		void Update(double appTime, double elapsedTime);
		bool IsBlendOver();

		void BeforeRemove();

		AnimationPtr TheAnim;
		float BlendTime;
		float BlendWeight;

	public_internal:
		Character *TheCharacter;
	};

	typedef Pointer0<AnimationObject> AnimationObjectPtr;
#include "PX2AnimationObject.inl"

}

#endif