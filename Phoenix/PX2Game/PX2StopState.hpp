/*
*
* ÎÄ¼þÃû³Æ	£º	PX2StopState.hpp
*
*/

#ifndef PX2STOPSTATE_HPP
#define PX2STOPSTATE_HPP

#include "PX2MovementState.hpp"

namespace PX2
{

	class StopState : public MovementState
	{
		PX2_SINGLETION(StopState);

	protected:
		virtual void Update (Character *chara, double appSeconds,
			double elapsedSeconds);
		virtual void StateEnter (Character *chara);
		virtual void StateExit (Character *chara);
	};

}

#endif