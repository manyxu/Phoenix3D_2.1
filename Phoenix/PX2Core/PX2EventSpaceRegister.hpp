// Copyright 2013-2014 LinkJoy, Inc. All Rights Reserved.

#ifndef PX2EVENTSPACEREGISTER_HPP
#define PX2EVENTSPACEREGISTER_HPP

#include "PX2EventSpace.hpp"
#include "PX2EventFactory.hpp"
#include "PX2EventSpaceRegisterMCR.hpp"

namespace PX2
{
	template <class ES>
	class EventSpaceRegister : public EventSpace
	{
	public:
		EventSpaceRegister ();
		virtual ~EventSpaceRegister ();

		static Event* CreateEventX (Event::EventType coveredType);

		static bool IsEqual (Event *event, Event::EventType coveredType);

		static Event::EventType UnCover (Event::EventType coveredType);
		static Event::EventType Cover (Event *event);

		static bool IsIn (Event *event);
	};

#include "PX2EventSpaceRegister.inl"

}

#endif