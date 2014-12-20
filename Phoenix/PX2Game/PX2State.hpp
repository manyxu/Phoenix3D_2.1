/*
*
* ÎÄ¼þÃû³Æ	£º	PX2State.hpp
*
*/

#ifndef PX2STATE_HPP
#define PX2STATE_HPP

#include "PX2GamePre.hpp"
#include "PX2Controlledable.hpp"
#include "PX2Event.hpp"
#include "PX2Singleton1.hpp"

namespace PX2
{

	template <typename T>
	class State : public Controlledable
	{
	public:
		virtual void StateEnter (T *owner) = 0;
		virtual void StateExit (T *owner) = 0;
		virtual void Update (T *owner, double appSeconds,
			double elapsedSeconds) = 0;
		virtual void OnEvent (T *owner, Event *event);

		void Block ();
		void UnBlock ();
		bool IsBlocked ();

	protected:
		State ();
		virtual ~State ();

		bool mIsBlocked;

	private:
		State (const State &);
		State &operator= (const State &);
	};

#include "PX2State.inl"

}

#endif