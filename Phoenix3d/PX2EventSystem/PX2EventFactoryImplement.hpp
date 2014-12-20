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

#ifndef PX2EVENTFACTORYIMPLEMENT_HPP
#define PX2EVENTFACTORYIMPLEMENT_HPP

#include "PX2EventSystemPre.hpp"
#include "PX2Event.hpp"

namespace PX2
{
	class Event;
	class EventSpace;

	/// 事件工厂实现类
	class EventFactoryImplement
	{
	public:
		EventFactoryImplement ();
		~EventFactoryImplement ();

		// 事件
		Event* CreateEventX ();
		void DestoryEvent (Event* event);

		// 事件空间
		void RegisterEventSpace (EventSpace* eventSpace);
		void UnRegisterEventSpace (const std::string &name);
		EventSpace* GetEventSpace (const std::string &name) const;
		EventSpace* FindEventSpace (Event* event) const;

	private:
		typedef std::map<std::string, EventSpace*> EventSpaceMap;

		EventSpaceMap mSpaces;
		int mEventQuantity;
	};

}

#endif