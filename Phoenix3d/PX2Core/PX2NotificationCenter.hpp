/*
*
* ÎÄ¼þÃû³Æ	£º	PX2NotificationCenter.hpp
*
*/

#ifndef PX2NOTIFICATIONCENTER_HPP
#define PX2NOTIFICATIONCENTER_HPP

#include "PX2CorePre.hpp"
#include "PX2SmartPointer.hpp"
#include "PX2Mutex.hpp"
#include "PX2Notification.hpp"

namespace PX2
{

	class AbstractObserver;

	class NotificationCenter
	{
	public:
		NotificationCenter();
		~NotificationCenter();

		static NotificationCenter& GetSingleton();

		void AddObserver(const AbstractObserver& observer);
		void RemoveObserver(const AbstractObserver& observer);
		bool HasObserver(const AbstractObserver& observer) const;
		bool HasObservers() const;
		std::size_t GetNumObservers() const;

		void PostNotification(Notification *notification);

	private:
		typedef std::vector<Pointer0<AbstractObserver> > ObserverList;
		ObserverList mObservers;
		mutable Mutex *mMutex;
	};


}

#endif