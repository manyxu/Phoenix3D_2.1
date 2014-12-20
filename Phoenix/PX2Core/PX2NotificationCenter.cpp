/*
*
* ÎÄ¼þÃû³Æ	£º	PX2NotificationCenter.cpp
*
*/

#include "PX2NotificationCenter.hpp"
#include "PX2AbstractObserver.hpp"
#include "PX2ScopedCS.hpp"
#include "PX2Assert.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
NotificationCenter::NotificationCenter()
{
	mMutex = new0 Mutex();
}
//----------------------------------------------------------------------------
NotificationCenter::~NotificationCenter()
{
	delete0(mMutex);
}
//----------------------------------------------------------------------------
NotificationCenter& NotificationCenter::GetSingleton()
{
	static NotificationCenter cet;
	return cet;
}
//----------------------------------------------------------------------------
void NotificationCenter::AddObserver(const AbstractObserver& observer)
{
	ScopedCS cs(mMutex);
	mObservers.push_back(observer.Clone());
}
//----------------------------------------------------------------------------
void NotificationCenter::RemoveObserver(const AbstractObserver& observer)
{
	ScopedCS cs(mMutex);

	for (ObserverList::iterator it = mObservers.begin();
		it != mObservers.end(); ++it)
	{
		if (observer.Equals(**it))
		{
			(*it)->Disable();
			mObservers.erase(it);
			return;
		}
	}
}
//----------------------------------------------------------------------------
bool NotificationCenter::HasObserver(const AbstractObserver& observer) const
{
	ScopedCS cs(mMutex);

	for (ObserverList::const_iterator it = mObservers.begin();
		it != mObservers.end(); ++it)
		if (observer.Equals(**it)) 
			return true;

	return false;
}
//----------------------------------------------------------------------------
void NotificationCenter::PostNotification(Notification *notification)
{
	assertion(0!=notification, "notification must not be 0.\n");

	mMutex->Enter();
	ObserverList observersToNotify(mObservers);
	mMutex->Leave();

	for (ObserverList::iterator it = observersToNotify.begin();
		it != observersToNotify.end(); ++it)
	{
		(*it)->Notify(notification);
	}
}
//----------------------------------------------------------------------------
bool NotificationCenter::HasObservers() const
{
	ScopedCS cs(mMutex);
	return !mObservers.empty();
}
//----------------------------------------------------------------------------
std::size_t NotificationCenter::GetNumObservers() const
{
	ScopedCS cs(mMutex);
	return mObservers.size();
}
//----------------------------------------------------------------------------