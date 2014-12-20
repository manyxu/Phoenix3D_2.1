/*
*
* ÎÄ¼þÃû³Æ	£º	PX2AbstractObserver.hpp
*
*/

#ifndef PX2ABSTRACTOBSERVER_HPP
#define PX2ABSTRACTOBSERVER_HPP

#include "PX2CorePre.hpp"
#include "PX2Notification.hpp"

namespace PX2
{

	class AbstractObserver
	{
	public:
		AbstractObserver();
		AbstractObserver(const AbstractObserver& observer);
		virtual ~AbstractObserver();

		AbstractObserver& operator = (const AbstractObserver& observer);

		virtual void Notify (Notification* nf) const = 0;
		virtual bool Equals (const AbstractObserver& observer) const = 0;
		virtual bool Accepts (Notification* nf) const = 0;
		virtual AbstractObserver* Clone() const = 0;
		virtual void Disable() = 0;
	};

}

#endif