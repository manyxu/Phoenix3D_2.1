/*
*
* ÎÄ¼þÃû³Æ	£º	PX2TriggerActor.hpp
*
*/

#ifndef PX2TRIGGERACTOR_HPP
#define PX2TRIGGERACTOR_HPP

#include "PX2Actor.hpp"
#include "PX2AxisAlignedBox3.hpp"
#include "PX2Sphere3.hpp"

namespace PX2
{

	class TriggerActor : public Actor
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(TriggerActor);

	public:
		TriggerActor ();
		virtual ~TriggerActor ();

		void Enable (bool enable);
		bool IsEnable ();

		enum AreaType
		{
			AT_BOX,
			AT_SPHERE,
			AT_MAX_TYPE
		};
		AreaType GetAreaType ();
		void SetArea (PX2::AxisAlignedBox3f box);
		void SetArea (PX2::Sphere3f sphere);

		bool IsPointIn (PX2::APoint point);

		virtual void DoEnter ();
		virtual void DoExecute (Event *event);
		virtual void DoLeave ();

	private:
		bool mEnable;
		AreaType mAreaType;
		AxisAlignedBox3f mBox;
		Sphere3f mSphere;
	};

	PX2_REGISTER_STREAM(TriggerActor);
	typedef Pointer0<TriggerActor> TriggerActorPtr;
#include "PX2TriggerActor.inl"

}

#endif