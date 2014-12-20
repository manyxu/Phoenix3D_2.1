/*
*
* ÎÄ¼þÃû³Æ	£º	PX2ActionState.hpp
*
*/

#ifndef PX2ACTIONSTATE_HPP
#define PX2ACTIONSTATE_HPP

#include "PX2State.hpp"

namespace PX2
{

	class Character;

	class ActionState : public State<Character>
	{
	public:
		virtual void Update (Character *b, double appSeconds,
			double elapsedSeconds);
		virtual void StateEnter (Character *b);
		virtual void StateExit (Character *b);

	protected:
		ActionState ();
		virtual ~ActionState ();
	};

}

#endif