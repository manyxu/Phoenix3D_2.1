// PX2Actor.hpp

#ifndef PX2ACTOR_HPP
#define PX2ACTOR_HPP

#include "PX2SimulationPre.hpp"
#include "PX2Node.hpp"
#include "PX2Component.hpp"

namespace PX2
{

	class Actor : public Node
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(Actor);

	public:
		Actor();
		~Actor();

	protected:
		virtual void UpdateWorldData(double applicationTime);

		// Movable
	public:
		void SetMovable (Movable *mov);
		void AddMovable (Movable *mov);

		Node *GetNode ();
		Node *GetHelpNode ();

	protected:
		NodePtr mNode;
		NodePtr mHelperNode;

		// Component
	public:
		int GetNumComponents () const;
		Component *GetComponent (int i) const;
		Component *GetComponentByName (const std::string &name) const;
		bool IsHasComponent (Component* component);
		void AttachComponent (Component* component);
		void DetachComponent (Component* component);
		void DetachAllComponents();
		void SortComponents(); // 按照优先级从大到小排序

	protected:
		bool UpdateComponents(double applicationTime);

		std::vector<ComponentPtr> mComponents;
	};

#include "PX2Actor.inl"
	PX2_REGISTER_STREAM(Actor);
	typedef Pointer0<Actor> EntityPtr;

}

#endif