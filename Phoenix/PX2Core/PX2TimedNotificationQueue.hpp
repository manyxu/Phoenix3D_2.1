/*
*
* ÎÄ¼þÃû³Æ	£º	PX2TimedNotificationQueue.hpp
*
*/

#ifndef PX2TIMEDNOTIFICATIONQUEUE_HPP
#define PX2TIMEDNOTIFICATIONQUEUE_HPP

#include "PX2Timestamp.hpp"
#include "PX2Notification.hpp"
#include "PX2Mutex.hpp"
#include "PX2Eventt.hpp"

namespace PX2
{

	class TimedNotificationQueue
	{
	public:
		TimedNotificationQueue();
		~TimedNotificationQueue();

		void EnqueueNotification (Notification *notification,
			Timestamp timestamp);
		NotificationPtr DequeueNotification ();
		NotificationPtr WaitDequeueNotification ();
		NotificationPtr WaitDequeueNotification (long milliseconds);

		bool IsEmpty() const;
		int GetSize() const;
		void Clear();

	protected:
		typedef std::multimap<Timestamp, NotificationPtr> NfQueue;
		NotificationPtr DequeueOne(NfQueue::iterator& it);
		bool Wait(Timestamp::TimeDiff interval);

	private:
		NfQueue mQueue;
		Eventt mAvailable;
		mutable Mutex *mMutex;
	};

}

#endif