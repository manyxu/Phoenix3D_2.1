// PX2Component.hpp

#ifndef PX2COMPONENT_HPP
#define PX2COMPONENT_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2Object.hpp"

namespace PX2
{

	class Componable;

	class Component : public Object
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(Component);

	public:
		Component();
		~Component();

		virtual bool Update(double applicationTime);

		void SetPriority (int priority);
		int GetPriority () const;

		virtual void OnAttach ();
		virtual void OnDetach ();

		Componable *GetCompable();

	public_internal:
		void SetCompable(Componable *actor);

	protected:
		Componable *mCompable;
		int mPriority;
	};

#include "PX2Component.inl"
	PX2_REGISTER_STREAM(Component);
	typedef Pointer0<Component> ComponentPtr;

}

#endif