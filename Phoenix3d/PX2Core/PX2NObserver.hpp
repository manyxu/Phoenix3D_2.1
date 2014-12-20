/*
*
* ÎÄ¼þÃû³Æ	£º	PX2NObserver.hpp
*
*/

#ifndef PX2NOBSERVER_HPP
#define PX2NOBSERVER_HPP

#include "PX2AbstractObserver.hpp"
#include "PX2SmartPointer.hpp"
#include "PX2Mutex.hpp"
#include "PX2ScopedCS.hpp"
#include "PX2Notification.hpp"

namespace PX2
{

	template <class C, class N>
	class NObserver: public AbstractObserver
	{
	public:
		typedef void (C::*Callback)(const NotificationPtr&);

		NObserver(C& object, Callback method);
		NObserver(const NObserver& observer);
		~NObserver();

		AbstractObserver* Clone() const;
		NObserver& operator = (const NObserver& observer);
		bool Equals (const AbstractObserver& abstractObserver) const;

		bool Accepts (Notification* nf) const;
		void Notify(Notification* nf) const;
		void Disable();

	private:
		NObserver();

		C *mObject;
		Callback mCallback;
		mutable Mutex mMutex;
	};

	typedef Pointer0<NObserver> NObserverPtr;

#include "PX2NObserver.inl"

}

#endif