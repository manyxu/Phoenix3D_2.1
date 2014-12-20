/*
*
* ÎÄ¼þÃû³Æ	£º	PX2StateMachine.hpp
*
*/

#ifndef PX2STATEMACHINE_HPP
#define PX2STATEMACHINE_HPP

#include "PX2State.hpp"
#include "PX2EventHandler.hpp"

namespace PX2
{

	template <typename T>
	class StateMachine : public EventHandler
	{
	public:
		StateMachine (T *owner);
		virtual ~StateMachine ();

		void SetCurrentState (State<T> *state);
		void SetGlobalState (State<T> *state);
		void SetPreviousState (State<T> *state);

		State<T> *GetCurrentState () const;
		State<T> *GetGlobalState () const;
		State<T> *GetPreviousState () const;

		void ChangeToState (State<T> *newState);
		void RevertToPreviousState ();
		bool IsInState (const State<T> *state) const;

		virtual void Update (double appSeconds, double elapsedSeconds);

		virtual void DoEnter ();
		virtual void DoExecute (Event *event);
		virtual void DoLeave ();

	private:
		StateMachine();

		T *mOwner;
		State<T> *mCurrentState;
		State<T> *mPreviousState;
		State<T> *mGlobalState;
	};

#include "PX2StateMachine.inl"

}

#endif