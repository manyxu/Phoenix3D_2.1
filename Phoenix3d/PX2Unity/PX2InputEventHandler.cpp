/*
*
* ÎÄ¼þÃû³Æ	£º	PX2InputEventHandler.cpp
*
*/

#include "PX2InputEventHandler.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
InputEventHandler::InputEventHandler ()
	:
mPriority(0)
{
}
//----------------------------------------------------------------------------
InputEventHandler::~InputEventHandler ()
{
}
//----------------------------------------------------------------------------
void InputEventHandler::SetPriority (int priority)
{
	mPriority = priority;
}
//----------------------------------------------------------------------------
int InputEventHandler::GetPriority () const
{
	return mPriority;
}
//----------------------------------------------------------------------------
void InputEventHandler::AddAcceptRange (const Rectf &ar)
{
	mInputRange.AddAcceptRange(ar);
}
//----------------------------------------------------------------------------
bool InputEventHandler::HasAcceptRange (const Rectf &ar)
{
	return mInputRange.HasAcceptRange(ar);
}
//----------------------------------------------------------------------------
void InputEventHandler::RemoveAcceptRange (const Rectf &ar)
{
	mInputRange.RemoveAcceptRange(ar);
}
//----------------------------------------------------------------------------
void InputEventHandler::ClearAcceptRanges ()
{
	mInputRange.ClearAcceptRanges();
}
//----------------------------------------------------------------------------
void InputEventHandler::AddExceptRange (const Rectf &er)
{
	mInputRange.AddExceptRange(er);
}
//----------------------------------------------------------------------------
bool InputEventHandler::HasExceptRange (const Rectf &er)
{
	return mInputRange.HasExceptRange(er);
}
//----------------------------------------------------------------------------
void InputEventHandler::RemoveExceptRange (const Rectf &er)
{
	mInputRange.RemoveExceptRange(er);
}
//----------------------------------------------------------------------------
void InputEventHandler::ClearExceptRanges ()
{
	mInputRange.ClearExceptRanges();
}
//----------------------------------------------------------------------------
bool InputEventHandler::TouchMoved (const InputEventData &data)
{
	if (!IsValuable(data))
		return false;
	
	return true;
}
//----------------------------------------------------------------------------
bool InputEventHandler::TouchPressed (const InputEventData &data)
{
	if (!IsValuable(data))
		return false;

	return true;
}
//----------------------------------------------------------------------------
bool InputEventHandler::TouchReleased (const InputEventData &data)
{
	if (!IsValuable(data))
		return false;

	return true;
}
//----------------------------------------------------------------------------
bool InputEventHandler::TouchCancelled (const InputEventData &data)
{
	if (!IsValuable(data))
		return false;

	return true;
}
//----------------------------------------------------------------------------
bool InputEventHandler::IsValuable (const InputEventData &data)
{
	return mInputRange.IsValuable((float)data.TState.X.Absoulate, 
		(float)data.TState.Y.Absoulate);
}
//----------------------------------------------------------------------------