/*
*
* ÎÄ¼þÃû³Æ	£º	PX2NotificationQueue.hpp
*
*/

#ifndef PX2NOTIFICATIONQUEUE_HPP
#define PX2NOTIFICATIONQUEUE_HPP

#include "PX2CorePre.hpp"
#include "PX2Notification.hpp"
#include "PX2Eventt.hpp"

namespace PX2
{

	class NotificationCenter;

	class NotificationQueue
	{
	public:
		NotificationQueue();
		~NotificationQueue();

		static NotificationQueue& GetSingleton();

		void EnqueueNotification (Notification *notification);
		void EnqueueUrgentNotification (Notification *notification);		
		NotificationPtr DequeueNotification();
		
		NotificationPtr WaitDequeueNotification();
		NotificationPtr WaitDequeueNotification(long milliseconds);
		
		void Dispatch(NotificationCenter& notificationCenter);

		void WakeUpAll();

		bool IsEmpty() const;
		int GetNumNotfs() const;
		void Clear();
		bool HasIdleThreads() const;

	private:
		NotificationPtr DequeueOne();

	private:
		typedef std::deque<NotificationPtr> NfQueue;
		struct WaitInfo
		{
			NotificationPtr Nf;
			Eventt Available;
		};
		typedef std::deque<WaitInfo*> WaitQueue;

		NfQueue mNFQueue;
		WaitQueue mWaitQueue;
		mutable Mutex *mMutex;
	};

}

#endif