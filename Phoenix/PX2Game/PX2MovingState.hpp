/*
*
* ÎÄ¼þÃû³Æ	£º	PX2MovingState.hpp
*
*/

#ifndef PX2MOVINGSTATE_HPP
#define PX2MOVINGSTATE_HPP

#include "PX2MovementState.hpp"

namespace PX2
{

	class MovingState : public MovementState
	{
		PX2_SINGLETION(MovingState);

	protected:
		virtual void Update (Character *chara, double appSeconds,
			double elapsedSeconds);
		virtual void StateEnter (Character *chara);
		virtual void StateExit (Character *chara);
	};

}

#endif