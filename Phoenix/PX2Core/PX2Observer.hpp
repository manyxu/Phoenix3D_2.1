/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Observer.hpp
*
*/

#ifndef PX2OBSERVER_HPP
#define PX2OBSERVER_HPP

#include "PX2NetPre.hpp"
#include "PX2Mutex.hpp"
#include "PX2ScopedCS.hpp"
#include "PX2AbstractObserver.hpp"

namespace PX2
{

	template <class C, class N>
	class Observer: public AbstractObserver
	{
	public:
		typedef void (C::*Callback)(N*);

		Observer(C& object, Callback method);
		Observer(const Observer& observer);
		~Observer();

		Observer& operator = (const Observer& observer);

		virtual void Notify (Notification* nf) const;
		virtual bool Equals (const AbstractObserver& observer) const;
		virtual bool Accepts (Notification* nf) const;
		virtual AbstractObserver* Clone() const;
		virtual void Disable();

	private:
		Observer();

		C *mObject;
		Callback mCallback;
		mutable Mutex mMutex;
	};

#include "PX2Observer.inl"

}

#endif