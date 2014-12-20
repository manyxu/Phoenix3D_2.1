/*
*
* ÎÄ¼þÃû³Æ	£º	PX2GameEventType.hpp
*
*/

#ifndef PX2SERVERPLATFORMEVENTTYPE_HPP
#define PX2SERVERPLATFORMEVENTTYPE_HPP

#include "PX2EventSystem.hpp"

namespace PX2
{

	PX2_DECLARE_EVENT_BEGIN(ServerPlatformSpace)
	PX2_EVENT(Login)
	PX2_EVENT(Buy)
	PX2_DECLARE_EVENT_END(ServerPlatformSpace)

}

#endif