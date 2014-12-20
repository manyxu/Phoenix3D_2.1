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
		virtual void Update (Character *chara, double appSeconds,
			double elapsedSeconds);
		virtual void StateEnter (Character *chara);
		virtual void StateExit (Character *chara);

	protected:
		PostureState ();
		virtual ~PostureState ();
	};

}

#endif