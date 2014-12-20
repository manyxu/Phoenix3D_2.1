/*
*
* ÎÄ¼þÃû³Æ	£º	PX2NotificationQueue.cpp
*
*/

#include "PX2NotificationQueue.hpp"
#include "PX2NotificationCenter.hpp"
#include "PX2ScopedCS.hpp"
#include "PX2Assert.hpp"
#include "PX2Memory.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
NotificationQueue::NotificationQueue()
{
	mMutex = new0 Mutex();
}
//----------------------------------------------------------------------------
NotificationQueue::~NotificationQueue()
{
	Clear();
	delete0(mMutex);
}
//----------------------------------------------------------------------------
NotificationQueue& NotificationQueue::GetSingleton()
{
	static NotificationQueue que;
	return que;
}
//----------------------------------------------------------------------------
void NotificationQueue::EnqueueNotification(Notification *notification)
{
	assertion(0!=notification, "notification must not be 0.\n");

	ScopedCS cs(mMutex);

	if (mWaitQueue.empty())
	{
		mNFQueue.push_back(notification);
	}
	else
	{
		WaitInfo* wi = mWaitQueue.front();
		mWaitQueue.pop_front();
		wi->Nf = notification;
		wi->Available.Set();
	}	
}
//----------------------------------------------------------------------------
void NotificationQueue::EnqueueUrgentNotification(Notification *notification)
{
	assertion(0!=notification, "notification must not be 0.\n");

	ScopedCS cs(mMutex);

	if (mWaitQueue.empty())
	{
		mNFQueue.push_front(notification);
	}
	else
	{
		WaitInfo* wi = mWaitQueue.front();
		mWaitQueue.pop_front();
		wi->Nf = notification;
		wi->Available.Set();
	}	
}
//----------------------------------------------------------------------------
NotificationPtr NotificationQueue::DequeueNotification()
{
	ScopedCS cs(mMutex);

	return DequeueOne();
}
//----------------------------------------------------------------------------
NotificationPtr NotificationQueue::WaitDequeueNotification()
{
	NotificationPtr nf;
	WaitInfo* wi = 0;
	{
		ScopedCS cs(mMutex);

		nf = DequeueOne();
		if (nf)
			return nf;

		wi = new0 WaitInfo;
		mWaitQueue.push_back(wi);
	}
	wi->Available.Wait();
	nf = wi->Nf;
	delete0(wi);

	return nf;
}
//----------------------------------------------------------------------------
NotificationPtr NotificationQueue::WaitDequeueNotification(long milliseconds)
{
	NotificationPtr nf;
	WaitInfo* wi = 0;
	{
		ScopedCS cs(mMutex);
		nf = DequeueOne();
		if (nf)
			return nf;
		wi = new0 WaitInfo;
		mWaitQueue.push_back(wi);
	}
	if (wi->Available.Wait(milliseconds))
	{
		nf = wi->Nf;
	}
	else
	{
		ScopedCS cs(mMutex);
		nf = wi->Nf;
		for (WaitQueue::iterator it = mWaitQueue.begin(); 
			it != mWaitQueue.end(); ++it)
		{
			if (*it == wi)
			{
				mWaitQueue.erase(it);
				break;
			}
		}
	}
	delete0(wi);

	return nf;
}
//----------------------------------------------------------------------------
void NotificationQueue::Dispatch(NotificationCenter& notificationCenter)
{
	ScopedCS cs(mMutex);
	NotificationPtr nf = DequeueOne();
	while (nf)
	{
		notificationCenter.PostNotification(nf);
		nf = DequeueOne();
	}
}
//----------------------------------------------------------------------------
void NotificationQueue::WakeUpAll()
{
	ScopedCS cs(mMutex);
	for (WaitQueue::iterator it = mWaitQueue.begin(); it != mWaitQueue.end();
		++it)
	{
		(*it)->Available.Set();
	}
	mWaitQueue.clear();
}
//----------------------------------------------------------------------------
bool NotificationQueue::IsEmpty() const
{
	ScopedCS cs(mMutex);
	return mNFQueue.empty();
}
//----------------------------------------------------------------------------
int NotificationQueue::GetNumNotfs() const
{
	ScopedCS cs(mMutex);
	return static_cast<int>(mNFQueue.size());
}
//----------------------------------------------------------------------------
void NotificationQueue::Clear()
{
	ScopedCS cs(mMutex);
	mNFQueue.clear();	
}
//----------------------------------------------------------------------------
bool NotificationQueue::HasIdleThreads() const
{
	ScopedCS cs(mMutex);
	return !mWaitQueue.empty();
}
//----------------------------------------------------------------------------
NotificationPtr NotificationQueue::DequeueOne()
{
	NotificationPtr nf;

	if (!mNFQueue.empty())
	{
		nf = mNFQueue.front();
		mNFQueue.pop_front();
	}

	return nf;
}
//----------------------------------------------------------------------------