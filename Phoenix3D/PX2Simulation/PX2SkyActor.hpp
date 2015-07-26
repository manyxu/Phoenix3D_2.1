// PX2SkyActor.hpp

#ifndef PX2SKYACTOR_HPP
#define PX2SKYACTOR_HPP

#include "PX2Actor.hpp"
#include "PX2SkyMesh.hpp"

namespace PX2
{

	class PX2_SIMULATION_ITEM SkyActor : public Actor
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(SkyActor);

	public:
		SkyActor();
		virtual ~SkyActor();

		SkyMesh *GetSky();

	protected:
		SkyMeshPtr mSkyMesh;
	};

#include "PX2SkyActor.inl"
	PX2_REGISTER_STREAM(SkyActor);
	typedef Pointer0<SkyActor> SkyActorPtr;

}

#endif