/*
*
* ÎÄ¼þÃû³Æ	£º	PX2TriggerActor.hpp
*
*/

#ifndef PX2TRIGGERACTOR_HPP
#define PX2TRIGGERACTOR_HPP

#include "PX2Actor.hpp"
#include "PX2Box3.hpp"
#include "PX2Sphere3.hpp"

namespace PX2
{

	class TriggerActor : public Actor
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(TriggerActor);

	public:
		TriggerActor ();
		virtual ~TriggerActor ();

		virtual void Update (double appSeconds, double elapsedSeconds);

		virtual void SetScale (const APoint &scale);

		enum AreaType
		{
			AT_SPHERE,
			AT_BOX,
			AT_MAX_TYPE
		};
		void SetAreaType (AreaType type);
		AreaType GetAreaType () const;

		void SetParam0 (float val);
		void SetParam1 (float val);
		void SetParam2 (float val);
		float GetParam0 () const;
		float GetParam1 () const;
		float GetParam2 () const;

		bool IsPointIn (const PX2::APoint &point) const;

		virtual void DoEnter ();
		virtual void DoExecute (Event *event);
		virtual void DoLeave ();

	private:
		void _RefreshParams ();

		AreaType mAreaType;
		float mParam0;
		float mParam1;
		float mParam2;

		Sphere3f mSphere;
		Box3f mBox;
	};

	PX2_REGISTER_STREAM(TriggerActor);
	typedef Pointer0<TriggerActor> TriggerActorPtr;
#include "PX2TriggerActor.inl"

}

#endif