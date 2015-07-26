// PX2PlatformSDKEventType.hpp

#ifndef PX2PLATFORMSDKEVENTTYPE_HPP
#define PX2PLATFORMSDKEVENTTYPE_HPP

#include "PX2SimulationPre.hpp"
#include "PX2EventSystem.hpp"

namespace PX2
{

	PX2_DECLARE_EVENT_BEGIN(PX2_SIMULATION_ITEM PlatformSDKSpace)
	PX2_EVENT(Login)
	PX2_EVENT(Buy)
	PX2_DECLARE_EVENT_END(PlatformSDKSpace)

}

#endif