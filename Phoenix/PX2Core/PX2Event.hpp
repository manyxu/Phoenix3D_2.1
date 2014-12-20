// Copyright 2013-2014 LinkJoy, Inc. All Rights Reserved.

#ifndef PX2EVENT_HPP
#define PX2EVENT_HPP

#include "PX2EventChannel.hpp"
#include "PX2EventHandler.hpp"
#include "PX2EventData.hpp"

namespace PX2
{

	/// 系统事件
	enum SystemEvent
	{
		EVENT_NONE = -1,
	};

	/// 事件对象
	class Event
	{
	public:
		typedef int EventType;

	public:
		Event ();
		Event (const Event& event);
		~Event ();

		// 赋值
		Event& operator= (const Event& event);

		// 事件
		void SetEventType (EventType eventType);
		EventType GetEventType ();

		// 通道
		void SetChannel (const EventChannel& eventChannel);
		const EventChannel &GetChannel ();

		// 延时(秒)
		void SetTimeDelay (float timeDelay);
		float GetTimeDelay ();
		bool IsDoDelay ();

		// 数据
		template <class DType>
		void SetData (DType data);

		template <class DType>
		DType GetData ();

		// 发送/接收者
		void SetSender (EventHandler *handler);
		EventHandler* GetSender ();
		void SetReceiver (EventHandler *handler);
		EventHandler* GetReceiver ();

public_internal:
		void Update (float timeDetail);
		bool IsDelayActted (); //< 延时时间的时间倒计时到0，触发事件
		bool IsSystemEvent () const;
		void SetBeSystemEvent (); //< mEventChannel为0消息
		void Initlize (const Event &event);

		bool mIsDoDelay;
		float mDelayTime;
		float mDelayTiming;

		EventChannel mEventChannel;
		EventType mEventType;
		EventData mEventData;
		
		EventHandler* mSender;
		EventHandler* mReceiver;
	};

#include "PX2Event.inl"

}

#endif