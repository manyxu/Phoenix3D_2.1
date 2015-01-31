// PX2EditEventType.hpp

#ifndef PX2EDITEVENTTYPE_HPP
#define PX2EDITEVENTTYPE_HPP

#include "PX2EventSystem.hpp"

namespace PX2
{

	PX2_DECLARE_EVENT_BEGIN(EditEventSpace)
	PX2_EVENT(NewProject)
	PX2_EVENT(LoadedProject)
	PX2_EVENT(SavedProject)
	PX2_EVENT(CloseProject)
	PX2_EVENT(NewScene)
	PX2_EVENT(LoadedScene)
	PX2_EVENT(SavedScene)
	PX2_EVENT(CloseScene)
	PX2_EVENT(NewUI)
	PX2_EVENT(LoadedUI)
	PX2_EVENT(CloseUI)
	PX2_EVENT(NewLogic)
	PX2_EVENT(LoadedLogic)

	PX2_EVENT(RefreshRes)

	PX2_EVENT(ObjectTransformChanged)
	PX2_EVENT(SetEditMode)
	PX2_EVENT(SceneNodeDrag) // data==1 drag; data==0 no drag

	PX2_DECLARE_EVENT_END(EditEventSpace)

}

#endif