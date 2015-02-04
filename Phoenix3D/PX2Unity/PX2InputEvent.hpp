// PX2InputEvent.hpp

#ifndef PX2INPUTEVENT_HPP
#define PX2INPUTEVENT_HPP

#include "PX2UnityPre.hpp"
#include "PX2EventHandler.hpp"
#include "PX2EventSpace.hpp"
#include "PX2EventSpaceRegister.hpp"
#include "PX2EventSpaceRegisterMCR.hpp"
#include "PX2EventWorld.hpp"

namespace PX2
{

	PX2_DECLARE_EVENT_BEGIN(InputEventSpace)
	PX2_EVENT(KeyPressed)
	PX2_EVENT(KeyReleased)
	PX2_EVENT(MouseMoved)
	PX2_EVENT(MousePressed)
	PX2_EVENT(MouseReleased)
	PX2_EVENT(MouseWheeled)
	PX2_EVENT(TouchPressed)
	PX2_EVENT(TouchMoved)
	PX2_EVENT(TouchReleased)
	PX2_EVENT(TouchCancelled)
	PX2_DECLARE_EVENT_END(InputEventSpace);

}

#endif