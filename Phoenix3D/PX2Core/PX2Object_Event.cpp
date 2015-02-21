// PX2Object_Event.cpp

#include "PX2Object.hpp"
#include "PX2EventWorld.hpp"
#include "PX2EventHandlerObject.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void Object::ComeInEventWorld()
{
	if (EventWorld::GetSingletonPtr())
		EventWorld::GetSingletonPtr()->ComeIn(mEventHandler);
}
//----------------------------------------------------------------------------
void Object::GoOutEventWorld()
{
	if (EventWorld::GetSingletonPtr())
		EventWorld::GetSingletonPtr()->GoOut(mEventHandler);
}
//----------------------------------------------------------------------------
bool Object::IsInEventWorld()
{
	return mEventHandler->IsInWorld();
}
//----------------------------------------------------------------------------
ObjectEventHandler *Object::GetEventHandler()
{
	return mEventHandler;
}
//----------------------------------------------------------------------------
void Object::DoExecute(Event *event)
{
	PX2_UNUSED(event);
}
//----------------------------------------------------------------------------