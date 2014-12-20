/*
*
* ÎÄ¼þÃû³Æ	£º	PX2ScriptEventHandler.hpp
*
*/

#ifndef PX2SCRIPTEVENTHANDLER_HPP
#define PX2SCRIPTEVENTHANDLER_HPP

#include "PX2EventHandler.hpp"

namespace PX2
{

	class ScriptEventHandler : public EventHandler
	{
	public:
		ScriptEventHandler ();
		virtual ~ScriptEventHandler ();

		virtual void DoEnter ();
		virtual void DoExecute (Event *event);
		virtual void DoLeave ();
	};

	typedef Pointer0<ScriptEventHandler> ScriptEventHandlerPtr;

}

#endif