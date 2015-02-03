// PX2EventHandlerObject.cpp

#include "PX2EventHandlerObject.hpp"
#include "PX2Object.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
ObjectEventHandler::ObjectEventHandler(Object *obj) :
mObject(obj)
{
}
//----------------------------------------------------------------------------
ObjectEventHandler::~ObjectEventHandler()
{
}
//----------------------------------------------------------------------------
void ObjectEventHandler::DoExecute(Event *event)
{
	mObject->DoExecute(event);
}
//----------------------------------------------------------------------------