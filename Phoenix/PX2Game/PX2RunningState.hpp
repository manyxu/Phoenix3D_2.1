/*
*
* ÎÄ¼þÃû³Æ	£º	PX2RunningState.hpp
*
*/

#ifndef PX2RUNNINGSTATE_HPP
#define PX2RUNNINGSTATE_HPP

#include "PX2PostureState.hpp"

namespace PX2
{

	class RunningState : public PostureState
	{
		PX2_SINGLETION(RunningState);

	public:
		virtual void Update (Character *chara, double appSeconds, 
			double elapsedSeconds);
		virtual void StateEnter (Character *chara);
		virtual void StateExit (Character *chara);
	};

}

#endif