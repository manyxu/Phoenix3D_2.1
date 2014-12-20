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
		virtual void Update (Character *chara, double appSeconds,
			double elapsedSeconds);
		virtual void StateEnter (Character *chara);
		virtual void StateExit (Character *chara);

	protected:
		MovementState ();
		virtual ~MovementState();
	};

}

#endif