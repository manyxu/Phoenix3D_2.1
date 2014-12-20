/*
*
* ÎÄ¼þÃû³Æ	£º	PX2SkyActor.hpp
*
*/

#ifndef PX2SKYACTOR_HPP
#define PX2SKYACTOR_HPP

#include "PX2Actor.hpp"
#include "PX2SkySphere.hpp"

namespace PX2
{

	class SkyActor : public Actor
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(SkyActor);

	public:
		SkyActor (SkySphere *sky=0);
		virtual ~SkyActor ();

		void SetSky (SkySphere *sky);
		SkySphere *GetSky ();

		virtual void DoEnter ();
		virtual void DoExecute (Event *event);
		virtual void DoLeave ();

	protected:
		SkySpherePtr mSky;
	};

	PX2_REGISTER_STREAM(SkyActor);
	typedef Pointer0<SkyActor> SkyActorPtr;
#include "PX2SkyActor.inl"

}

#endif