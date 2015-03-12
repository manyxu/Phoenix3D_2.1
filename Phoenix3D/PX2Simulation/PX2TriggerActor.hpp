// PX2TriggerActor.hpp

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
		TriggerActor();
		virtual ~TriggerActor();

		// Areas
	public:
		enum AreaType
		{
			AT_SPHERE,
			AT_BOX,
			AT_MAX_TYPE
		};
		void SetAreaType(AreaType type);
		AreaType GetAreaType() const;

		void SetAreaParam(const AVector &vec);
		const AVector &GetAreaParam() const;

		bool IsPointIn(const PX2::APoint &point) const;

	protected:
		AreaType mAreaType;
		AVector mAreaParam;
		MovablePtr mAreaMovable;

		// Triger
	public:
		enum TrigerType
		{
			TT_ENTER_ONCE,
			TT_ENTER_EVERYENTER,
			TT_MAX_TYPE
		};
		void SetTrigerType(TrigerType type);
		TrigerType GetTrigerType() const;

		virtual void Triger();
		void ResetTriger();
		bool IsTrigered() const;

	private:
		TrigerType mTrigerType;
		bool mIsTrigered;
	};

	PX2_REGISTER_STREAM(TriggerActor);
	typedef Pointer0<TriggerActor> TriggerActorPtr;
#include "PX2TriggerActor.inl"

}

#endif