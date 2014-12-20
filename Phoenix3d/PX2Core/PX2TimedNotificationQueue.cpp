/*
*
* 文件名称	：	PX2TimedNotificationQueue.cpp
*
*/

#include "PX2TimedNotificationQueue.hpp"
#include "PX2Memory.hpp"
#include "PX2ScopedCS.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
TimedNotificationQueue::TimedNotificationQueue()
{
	mMutex = new0 Mutex();
}
//----------------------------------------------------------------------------
TimedNotificationQueue::~TimedNotificationQueue()
{
	Clear();

	if (mMutex)
	{
		delete0(mMutex);
		mMutex = 0;
	}
}
//----------------------------------------------------------------------------
void TimedNotificationQueue::EnqueueNotification(Notification *notification,
	Timestamp timestamp)
{
	assertion(!notification, "notification should not be 0.\n");

	ScopedCS cs(mMutex);

	mQueue.insert(NfQueue::value_type(timestamp, notification));
	
	mAvailable.Set();
}
//----------------------------------------------------------------------------
NotificationPtr TimedNotificationQueue::DequeueNotification()
{
	ScopedCS cs(mMutex);

	NfQueue::iterator it = mQueue.begin();
	if (it != mQueue.end())
	{
		Timestamp::TimeDiff sleep = -it->first.Elapsed();
		if (sleep <= 0)
		{
			NotificationPtr ptr = it->second;
			mQueue.erase(it);
			return ptr;
		}
	}
	return 0;
}
//----------------------------------------------------------------------------
NotificationPtr TimedNotificationQueue::WaitDequeueNotification()
{
	for (;;)
	{
		mMutex->Enter();

		NfQueue::iterator it = mQueue.begin();
		if (it != mQueue.end())
		{
			mMutex->Leave();

			Timestamp::TimeDiff sleep = -it->first.Elapsed();
			if (sleep <= 0)
			{
				return DequeueOne(it);
			}
			else if (!Wait(sleep))
			{
				return DequeueOne(it);
			}
			else 
			{
				continue;
			}
		}
		else
		{
			mMutex->Leave();
		}
		mAvailable.Wait();
	}
}
//----------------------------------------------------------------------------
NotificationPtr TimedNotificationQueue::WaitDequeueNotification(
	long milliseconds)
{
	while (milliseconds >= 0)
	{
		mMutex->Enter();

		NfQueue::iterator it = mQueue.begin();
		if (it != mQueue.end())
		{
			mMutex->Leave();

			Timestamp now;
			Timestamp::TimeDiff sleep = it->first - now;
			if (sleep <= 0)
			{
				return DequeueOne(it);
			}
			else if (sleep <= 1000*Timestamp::TimeDiff(milliseconds))
			{
				if (!Wait(sleep))
				{
					return DequeueOne(it);
				}
				else 
				{
					milliseconds -= static_cast<long>((now.Elapsed() + 999)/1000);
					continue;
				}
			}
		}
		else
		{
			mMutex->Leave();
		}

		if (milliseconds > 0)
		{
			Timestamp now;
			mAvailable.Wait(milliseconds);
			milliseconds -= static_cast<long>((now.Elapsed() + 999)/1000);
		}
		else return 0;
	}
	return 0;
}
//----------------------------------------------------------------------------
bool TimedNotificationQueue::Wait (Timestamp::TimeDiff interval)
{
	// 最多等8小时
	const Timestamp::TimeDiff MAX_SLEEP = 8*60*60*Timestamp::TimeDiff(1000000);

	while (interval > 0)
	{
		Timestamp now;
		Timestamp::TimeDiff sleep = (interval <= MAX_SLEEP ? interval : MAX_SLEEP);

		if (mAvailable.Wait(static_cast<long>((sleep + 999)/1000)))
			return true;

		interval -= now.Elapsed();
	}

	return false;
}
//----------------------------------------------------------------------------
bool TimedNotificationQueue::IsEmpty() const
{
	ScopedCS cs(mMutex);

	return mQueue.empty();
}
//----------------------------------------------------------------------------
int TimedNotificationQueue::GetSize() const
{
	ScopedCS cs(mMutex);

	return (int)mQueue.size();
}
//----------------------------------------------------------------------------
void TimedNotificationQueue::Clear()
{
	ScopedCS cs(mMutex);

	mQueue.clear();	
}
//----------------------------------------------------------------------------
NotificationPtr TimedNotificationQueue::DequeueOne(NfQueue::iterator& it)
{
	ScopedCS cs(mMutex);
	NotificationPtr ptr = it->second;
	mQueue.erase(it);

	return ptr;
}
//----------------------------------------------------------------------------