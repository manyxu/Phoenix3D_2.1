/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Notification.hpp
*
*/

#ifndef PX2NOTIFICATION_HPP
#define PX2NOTIFICATION_HPP

#include "PX2CorePre.hpp"
#include "PX2SmartPointer.hpp"

namespace PX2
{

	class Notification
	{
	public:
		Notification();
		virtual ~Notification();
		virtual std::string GetTypeName() const;
	};

	typedef Pointer0<Notification> NotificationPtr;

}

#endif