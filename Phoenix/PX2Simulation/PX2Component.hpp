// PX2Component.hpp

#ifndef PX2COMPONENT_HPP
#define PX2COMPONENT_HPP

#include "PX2SimulationPre.hpp"
#include "PX2Node.hpp"

namespace PX2
{

	class Actor;

	class Component : public Object
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(Component);

	public:
		Component();
		~Component();

		void SetPriority (int priority);
		int GetPriority () const;

		virtual void OnAttach ();
		virtual void OnDetach ();

		Actor *GetActor ();

	public_internal:
		void SetActor(Actor *actor);

	protected:
		Actor *mActor;

		int mPriority;
	};

#include "PX2Component.inl"
	PX2_REGISTER_STREAM(Component);
	typedef Pointer0<Component> ComponentPtr;

}

#endif