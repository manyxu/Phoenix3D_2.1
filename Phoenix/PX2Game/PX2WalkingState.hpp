/*
*
* ÎÄ¼þÃû³Æ	£º	PX2WalkingState.hpp
*
*/

#ifndef PX2WALKINGSTATE_HPP
#define PX2WALKINGSTATE_HPP

#include "PX2PostureState.hpp"

namespace PX2
{

	class WalkingState : public PostureState
	{
		PX2_SINGLETION(WalkingState);

	public:
		virtual void Update (Character *chara, double appSeconds, 
			double elapsedSeconds);
		virtual void StateEnter (Character *chara);
		virtual void StateExit (Character *chara);
	};

}

#endif