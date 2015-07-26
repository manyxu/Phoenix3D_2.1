// PX2EffectActor.hpp

#ifndef PX2EFFECTACTOR_HPP
#define PX2EFFECTACTOR_HPP

#include "PX2Actor.hpp"

namespace PX2
{

	class PX2_SIMULATION_ITEM EffectActor : public Actor
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(EffectActor);

	public:
		EffectActor();
		virtual ~EffectActor();
	};

	PX2_REGISTER_STREAM(EffectActor);
	typedef Pointer0<EffectActor> EffectActorPtr;

}

#endif