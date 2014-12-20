/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Event.cpp
*
*/

#include "PX2Event.hpp"
using namespace PX2;

Event::Event ()
:
mEventType(0),
mSender(0),
mReceiver(0),
mDelayTime(0.0f),
mDelayTiming(0.0f),
mIsDoDelay(false)
{
	mEventChannel.FillUserChannel();
}
//----------------------------------------------------------------------------
Event::Event (const Event& event)
{
	Initlize(event);
}
//----------------------------------------------------------------------------
Event::~Event ()
{
	mSender = 0;
	mReceiver = 0;
}
//----------------------------------------------------------------------------
Event& Event::operator= (const Event& event)
{
	Initlize(event);
	return (*this);
}
//----------------------------------------------------------------------------
void Event::SetEventType (EventType eventType)
{
	mEventType = eventType;
}
//----------------------------------------------------------------------------
Event::EventType Event::GetEventType ()
{
	return mEventType;
}
//----------------------------------------------------------------------------
void Event::SetChannel (const EventChannel& eventChannel)
{
	if (eventChannel.IsEmpty())
	{
		assertion(false, "input eventChannel must not be empty.");
	}

	mEventChannel = eventChannel;
}
//----------------------------------------------------------------------------
const EventChannel& Event::GetChannel ()
{
	return mEventChannel;
}
//----------------------------------------------------------------------------
void Event::SetTimeDelay (float timeDelay)
{
	mDelayTime = timeDelay;
	mDelayTiming = timeDelay;

	if (mDelayTiming > 0.0f)
		mIsDoDelay = true;
}
//----------------------------------------------------------------------------
void Event::SetSender (EventHandler *handler)
{
	mSender = handler;
}
//----------------------------------------------------------------------------
EventHandler* Event::GetSender ()
{
	return mSender;
}
//----------------------------------------------------------------------------
void Event::SetReceiver (EventHandler *handler)
{
	mReceiver = handler;
}
//----------------------------------------------------------------------------
EventHandler* Event::GetReceiver ()
{
	return mReceiver;
}
//----------------------------------------------------------------------------
bool Event::IsSystemEvent () const
{
	return mEventChannel.IsEmpty();
}
//----------------------------------------------------------------------------
void Event::SetBeSystemEvent ()
{
	mEventChannel.Clear();
}
//----------------------------------------------------------------------------
void Event::Initlize (const Event &event)
{
	mEventChannel = event.mEventChannel;
	mEventType = event.mEventType;
	mEventData = event.mEventData;
	mSender = event.mSender;
	mReceiver = event.mReceiver;
}
//----------------------------------------------------------------------------
void Event::Update (float timeDetail)
{
	if (mIsDoDelay)
	{
		mDelayTiming -= timeDetail;

		if (mDelayTiming < 0.0f)
			mDelayTiming = 0.0f;
	}
}
//----------------------------------------------------------------------------
bool Event::IsDelayActted ()
{
	if (mIsDoDelay && 0.0f==mDelayTiming)
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------