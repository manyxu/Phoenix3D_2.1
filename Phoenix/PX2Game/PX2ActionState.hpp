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
		virtual void Update (Character *chara, double appSeconds,
			double elapsedSeconds);
		virtual void StateEnter (Character *chara);
		virtual void StateExit (Character *chara);

	protected:
		ActionState ();
		virtual ~ActionState ();
	};

}

#endif