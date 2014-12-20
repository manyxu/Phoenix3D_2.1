/*
*
* ÎÄ¼þÃû³Æ	£º	PX2LogicActor.hpp
*
*/

#ifndef PX2LOGICACTOR_HPP
#define PX2LOGICACTOR_HPP

#include "PX2Actor.hpp"

namespace PX2
{

	class LogicActor : public Actor
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(LogicActor);

	public:
		LogicActor ();
		virtual ~LogicActor ();

		void Enable (bool enable);
		bool IsEnable ();

		virtual void DoEnter ();
		virtual void DoExecute (Event *event);
		virtual void DoLeave ();

	private:
		bool mEnable;
	};

	PX2_REGISTER_STREAM(LogicActor);
	typedef Pointer0<LogicActor> LogicActorPtr;
#include "PX2LogicActor.inl"

}

#endif