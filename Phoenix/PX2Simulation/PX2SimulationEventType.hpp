// PX2SimulationEventType.hpp

#ifndef PX2SIMULATIONEVENTTYPE_HPP
#define PX2SIMULATIONEVENTTYPE_HPP

#include "PX2SimulationPre.hpp"
#include "PX2EventSystem.hpp"

namespace PX2
{

	PX2_DECLARE_EVENT_BEGIN(SimuES_E)
	PX2_EVENT(AddSelect)
	PX2_EVENT(RemoveSelect)
	PX2_EVENT(RemoveAllSelects)
	PX2_EVENT(PushUnDo)
	PX2_EVENT(UnDo)
	PX2_EVENT(ReDo)
	PX2_EVENT(NoUnDo)
	PX2_EVENT(NoReDo)
	PX2_EVENT(AddObject)
	PX2_EVENT(RemoveObject)
	PX2_DECLARE_EVENT_END(SimuES_E)

}

#endif