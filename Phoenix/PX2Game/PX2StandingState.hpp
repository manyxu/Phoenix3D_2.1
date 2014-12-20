/*
*
* ÎÄ¼þÃû³Æ	£º	PX2StandingState.hpp
*
*/

#ifndef PX2STANDINGSTATE_HPP
#define PX2STANDINGSTATE_HPP

#include "PX2PostureState.hpp"

namespace PX2
{

	class StandingState : public PostureState
	{
		PX2_SINGLETION(StandingState);

	public:
		virtual void Update (Character *chara, double appSeconds, 
			double elapsedSeconds);
		virtual void StateEnter (Character *chara);
		virtual void StateExit (Character *chara);
	};

}

#endif