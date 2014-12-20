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

#ifndef PX2EVENTWORLD_HPP
#define PX2EVENTWORLD_HPP

#include "PX2EventSystemPre.hpp"
#include "PX2EventHandler.hpp"
#include "PX2Singleton.hpp"

namespace PX2
{

	/// 消息世界
	class EventWorld : public Singleton<EventWorld>
	{
	public:
		EventWorld ();
		~EventWorld ();

		// 消息句柄
		void ComeIn (EventHandler *handler);
		void GoOut (EventHandler *handler);

		/// 更新
		/**
		* 1.为每个事件句柄添加一个新的更新消息
		* 2.分发各个事件，对事件进行相应处理
		* 3.流逝时间单位（秒）
		*/
		void Update (float detalTime);

		/// 广播本地消息
		/**
		* 该消息只能广播非系统消息，如果是一个系统消息，会出现一个断言失败。
		*/
		void BroadcastingLocalEvent (Event* event);

		/// 广播网络消息
		/**
		*
		*/
		void BroadcastingNetEvent (Event* event);

	private:
		bool _AddHandler (EventHandler* handler);
		void _RemoveHandler (EventHandler* handler);
		void _UpdateEvent (float detalTime);
		void _BroadcastingEvent (Event* event);
		void SwapEventList ();

		typedef std::vector<Event*> EventList;
		typedef std::vector<EventHandler*> EventHandlerList;

		EventList* mNowEventList;
		EventList* mNextEventList;
		EventHandlerList mAddingHandlers;
		EventHandlerList mHandlers;
	};

	typedef Pointer0<EventWorld> EventWorldPtr;

#define PX2_EW EventWorld::GetSingleton()

}

#endif