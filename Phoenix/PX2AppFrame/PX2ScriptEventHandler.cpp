/*
*
* ÎÄ¼þÃû³Æ	£º	PX2ScriptEventHandler.cpp
*
*/

#include "PX2ScriptEventHandler.hpp"
#include "PX2InputEvent.hpp"
#include "PX2ScriptManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
ScriptEventHandler::ScriptEventHandler ()
{
}
//----------------------------------------------------------------------------
ScriptEventHandler::~ScriptEventHandler ()
{
}
//----------------------------------------------------------------------------
void ScriptEventHandler::DoEnter ()
{
}
//----------------------------------------------------------------------------
void ScriptEventHandler::DoExecute (Event *event)
{
	//if (InputEventSpace::IsEqual(event, InputEventSpace::KeyPressed))
	//{
	//	InputEventData data = event->GetData<InputEventData>();

	//	char str[256];
	//	sprintf(str, "OnKeyPressed(%d)", data.KCode);
	//	PX2_SM.CallString(str);
	//}
	//else if (InputEventSpace::IsEqual(event, InputEventSpace::KeyReleased))
	//{
	//	InputEventData data = event->GetData<InputEventData>();

	//	char str[256];
	//	sprintf(str, "OnKeyReleased(%d)", data.KCode);
	//	PX2_SM.CallString(str);
	//}
	//else if (InputEventSpace::IsEqual(event, InputEventSpace::MouseMoved))
	//{
	//	InputEventData data = event->GetData<InputEventData>();

	//	char str[256];
	//	sprintf(str, "OnMouseMoved(%d,%d,%d)", data.MButtonID, 
	//		data.MState.X.Absoulate, data.MState.Y.Absoulate);
	//	PX2_SM.CallString(str);
	//}
	//else if (InputEventSpace::IsEqual(event, InputEventSpace::MousePressed))
	//{
	//	InputEventData data = event->GetData<InputEventData>();

	//	char str[256];
	//	sprintf(str, "OnMousePressed(%d,%d,%d)", data.MButtonID, 
	//		data.MState.X.Absoulate, data.MState.Y.Absoulate);
	//	PX2_SM.CallString(str);
	//}
	//else if (InputEventSpace::IsEqual(event, InputEventSpace::MouseReleased))
	//{
	//	InputEventData data = event->GetData<InputEventData>();

	//	char str[256];
	//	sprintf(str, "OnMouseReleased(%d,%d,%d)", data.MButtonID, 
	//		data.MState.X.Absoulate, data.MState.Y.Absoulate);
	//	PX2_SM.CallString(str);
	//}
	//else if (InputEventSpace::IsEqual(event, InputEventSpace::TouchPressed))
	//{
	//	InputEventData data = event->GetData<InputEventData>();

	//	char str[256];
	//	sprintf(str, "OnTouchPressed(%d,%d)", data.TState.X.Absoulate, 
	//		data.TState.Y.Absoulate);
	//	PX2_SM.CallString(str);
	//}
	//else if (InputEventSpace::IsEqual(event, InputEventSpace::TouchMoved))
	//{
	//	InputEventData data = event->GetData<InputEventData>();

	//	char str[256];
	//	sprintf(str, "OnTouchMoved(%d,%d)", data.TState.X.Absoulate, 
	//		data.TState.Y.Absoulate);
	//	PX2_SM.CallString(str);
	//}
	//else if (InputEventSpace::IsEqual(event, InputEventSpace::TouchReleased))
	//{
	//	InputEventData data = event->GetData<InputEventData>();

	//	char str[256];
	//	sprintf(str, "OnTouchReleased(%d,%d)", data.TState.X.Absoulate, 
	//		data.TState.Y.Absoulate);
	//	PX2_SM.CallString(str);
	//}
	//else if (InputEventSpace::IsEqual(event, InputEventSpace::TouchCancelled))
	//{
	//	InputEventData data = event->GetData<InputEventData>();

	//	char str[256];
	//	sprintf(str, "OnTouchCancelled(%d,%d)", data.TState.X.Absoulate, 
	//		data.TState.Y.Absoulate);
	//	PX2_SM.CallString(str);
	//}
}
//----------------------------------------------------------------------------
void ScriptEventHandler::DoLeave ()
{
}
//----------------------------------------------------------------------------