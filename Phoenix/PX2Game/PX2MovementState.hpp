/*
*
* ÎÄ¼þÃû³Æ	£º	PX2MovementState.hpp
*
*/

#ifndef PX2MOVEMENTSTATE_HPP
#define PX2MOVEMENTSTATE_HPP

#include "PX2State.hpp"

namespace PX2
{

	class Character;

	class MovementState : public State<Character>
	{
	public:
		virtual void Update (Character *b, double appSeconds,
			double elapsedSeconds);
		virtual void StateEnter (Character *b);
		virtual void StateExit (Character *b);

	protected:
		MovementState ();
		virtual ~MovementState();
	};

}

#endif