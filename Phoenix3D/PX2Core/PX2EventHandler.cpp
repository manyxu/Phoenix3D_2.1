// PX2EventHandler.cpp

#include "PX2Event.hpp"
#include "PX2EventHandler.hpp"
#include "PX2EventWorld.hpp"
using namespace PX2;

EventHandler::EventHandler ()
:
mEntered(false),
mEnableUpdate(true),
mWorld(0)
{
	mChannel.Fill();
}
//----------------------------------------------------------------------------
EventHandler::~EventHandler()
{
}
//----------------------------------------------------------------------------
void EventHandler::SetChannel (const EventChannel &channel)
{
	mChannel = channel;
}
//----------------------------------------------------------------------------
const EventChannel &EventHandler::GetChannel () const
{
	return mChannel;
}
//----------------------------------------------------------------------------
void EventHandler::MergeChannel (const EventChannel &channel)
{
	mChannel.Merge(channel);
}
//----------------------------------------------------------------------------
void EventHandler::DisMergeChannel (const EventChannel &channel)
{
	mChannel.DisMerge(channel);
}
//----------------------------------------------------------------------------
void EventHandler::ClearChannel ()
{
	mChannel.Clear();
}
//----------------------------------------------------------------------------
bool EventHandler::IsListening (const EventChannel &channel)
{
	return mChannel.IsListening(channel);
}
//----------------------------------------------------------------------------
EventWorld* EventHandler::GetWorld ()
{
	return mWorld;
}
//----------------------------------------------------------------------------
bool EventHandler::IsInWorld () const
{
	return (mWorld != 0);
}
//----------------------------------------------------------------------------
bool EventHandler::IsInWorld (EventWorld* world) const
{
	if (world)
		return (mWorld == world);

	return false;
}
//----------------------------------------------------------------------------
void EventHandler::DoEnter ()
{
}
//----------------------------------------------------------------------------
void EventHandler::DoExecute (Event *event)
{
	PX2_UNUSED(event);
}
//----------------------------------------------------------------------------
void EventHandler::DoLeave ()
{
}
//----------------------------------------------------------------------------
void EventHandler::Execute (Event* event)
{
	assertion(event!=0, "event must exist.");
	if (mEntered)
	{
		DoExecute(event);
	}
}
//----------------------------------------------------------------------------
void EventHandler::Enter (EventWorld* world)
{
	mWorld = world;
	mEntered = true;
	DoEnter();
}
//----------------------------------------------------------------------------
void EventHandler::Leave ()
{
	mEntered = false;
	DoLeave();
	mWorld = 0;
}
//----------------------------------------------------------------------------