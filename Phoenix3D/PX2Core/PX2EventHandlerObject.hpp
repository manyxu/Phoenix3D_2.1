// PX2EventHandlerObject.hpp

#ifndef PX2EVENTHANDLEROBJECT_HPP
#define PX2EVENTHANDLEROBJECT_HPP

#include "PX2EventHandler.hpp"

namespace PX2
{

	class Object;

	class PX2_CORE_ITEM ObjectEventHandler : public EventHandler
	{
	public:
		ObjectEventHandler(Object *obj);
		virtual ~ObjectEventHandler();

		virtual void DoExecute(Event *event);

	protected:
		ObjectEventHandler();

		Object *mObject;
	};

}

#endif