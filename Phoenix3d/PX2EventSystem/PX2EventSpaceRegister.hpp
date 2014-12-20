/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2EventChannel.hpp
*
* 版本		:	1.0 (2011/02/01)
*
* 作者		：	more
*
*/

#ifndef PX2EVENTSPACEREGISTER_HPP
#define PX2EVENTSPACEREGISTER_HPP

#include "PX2EventSystemPre.hpp"
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