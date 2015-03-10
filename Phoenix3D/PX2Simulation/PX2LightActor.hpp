// PX2LightActor.hpp

#ifndef PX2LIGHTACTOR_HPP
#define PX2LIGHTACTOR_HPP

#include "PX2Actor.hpp"
#include "PX2Light.hpp"
#include "PX2LightNode.hpp"

namespace PX2
{

	class LightActor : public Actor
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(LightActor);

	public:
		LightActor();
		virtual ~LightActor();

		Light *GetLight();
		LightNode *GetLightNode();

	public_internal:
		virtual void SetParent(Movable* parent);

	protected:
		LightPtr mLight;
		LightNodePtr mLightNode;
	};

	PX2_REGISTER_STREAM(LightActor);
	typedef Pointer0<LightActor> LightActorPtr;
#include "PX2LightActor.inl"

}

#endif