/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EventFactory.cpp
*
*/

#include "PX2EventFactory.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
EventFactory::EventFactory ()
{
	mEventImplement = new EventFactoryImplement();	
	assertion(mEventImplement!=0, "mEventImplement was not created successfully.");
}
//----------------------------------------------------------------------------
EventFactory::~EventFactory ()
{
	if (mEventImplement)
	{
		delete mEventImplement;
		mEventImplement = 0;
	}
}
//----------------------------------------------------------------------------
EventFactory &EventFactory::GetInstance ()
{
	return *(GetInstancePtr());
}
//----------------------------------------------------------------------------
EventFactory* EventFactory::GetInstancePtr ()
{
	static EventFactory instance;
	return &instance;
}
//----------------------------------------------------------------------------
Event* EventFactory::CreateEventX ()
{
	return mEventImplement->CreateEventX();
}
//----------------------------------------------------------------------------
void EventFactory::DestoryEvent (Event* event)
{
	assertion(event!=0, "event must exist.");
	mEventImplement->DestoryEvent(event);
}
//----------------------------------------------------------------------------
void EventFactory::RegisterEventSpace (EventSpace* eventSpace)
{
	return mEventImplement->RegisterEventSpace(eventSpace);
}
//----------------------------------------------------------------------------
void EventFactory::UnRegisterEventSpace (const std::string &name)
{
	return mEventImplement->UnRegisterEventSpace(name);
}
//----------------------------------------------------------------------------
EventSpace* EventFactory::GetEventSpace (const std::string &name) const
{
	return mEventImplement->GetEventSpace(name);
}
//----------------------------------------------------------------------------
EventSpace* EventFactory::FindEventSpace (Event* event) const
{
	return mEventImplement->FindEventSpace(event);
}
//----------------------------------------------------------------------------