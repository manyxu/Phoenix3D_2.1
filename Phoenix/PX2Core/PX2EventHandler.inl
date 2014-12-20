// Copyright 2013-2014 LinkJoy, Inc. All Rights Reserved.

//----------------------------------------------------------------------------
inline bool EventHandler::IsUpdateEvent (Event *event)
{
	return (event->mEventType == EVENT_UPDATE_HANDLER);
}
//----------------------------------------------------------------------------