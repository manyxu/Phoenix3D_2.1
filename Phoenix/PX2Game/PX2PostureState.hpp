/*
*
* ÎÄ¼þÃû³Æ	£º	PX2PostureState.hpp
*
*/

#ifndef PX2POSTURESTATE_HPP
#define PX2POSTURESTATE_HPP

#include "PX2State.hpp"

namespace PX2
{

	class Character;

	class PostureState : public State<Character>
	{
	public:
		PX2_SINGLETION(PostureState);

		virtual void Update (Character *b, double appSeconds,
			double elapsedSeconds);
		virtual void StateEnter (Character *b);
		virtual void StateExit (Character *b);
	};

}

#endif