// PX2Actor.hpp

#ifndef PX2ACTOR_HPP
#define PX2ACTOR_HPP

#include "PX2SimulationPre.hpp"
#include "PX2Node.hpp"

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
		NodePtr mHelpNode;
	};

#include "PX2Actor.inl"
	PX2_REGISTER_STREAM(Actor);
	typedef Pointer0<Actor> ActorPtr;

}

#endif