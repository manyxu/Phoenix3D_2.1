// PX2NirvanaEventType.hpp

#ifndef PX2NIRVANAUIEVENTTYPE_HPP
#define PX2NIRVANAUIEVENTTYPE_HPP

#include "PX2EventSystem.hpp"

namespace PX2
{

	PX2_DECLARE_EVENT_BEGIN(NirvanaEventSpace)
	PX2_EVENT(TabDrag)
	PX2_EVENT(SetProjTreeLevel)
	PX2_EVENT(ObjectNameChanged)
	PX2_DECLARE_EVENT_END(NirvanaEventSpace)

}

#endif