/*
*
* ÎÄ¼þÃû³Æ	£º	PX2InputEventListener.cpp
*
*/

#include "PX2InputEventListener.hpp"
#include "PX2InputEventAdapter.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
InputEventListener::InputEventListener ()
{
}
//----------------------------------------------------------------------------
InputEventListener::~InputEventListener ()
{
}
//----------------------------------------------------------------------------
bool InputEventListener::KeyPressed (const KeyEvent &arg)
{
	InputEventData data;
	data.TheEventType = InputEventSpace::KeyPressed;
	data.KCode = arg.Key;

	OnInputEventData(data);

	return true;
}
//----------------------------------------------------------------------------
bool InputEventListener::KeyReleased (const KeyEvent &arg)
{
	InputEventData data;
	data.TheEventType = InputEventSpace::KeyReleased;
	data.KCode = arg.Key;

	OnInputEventData(data);

	return true;
}
//----------------------------------------------------------------------------
bool InputEventListener::MouseMoved (const MouseEvent &arg)
{
	bool converted = InputEventAdapter::GetSingleton().IsConverted2Touch();
	const Sizef &winSize = InputManager::GetSingleton().GetSize();

	Event::EventType entType = InputEventSpace::MouseMoved;
	if (converted)
	{
		if (!arg.State.IsButtonDown(MBID_LEFT) 
			&& !arg.State.IsButtonDown(MBID_RIGHT)
			&& !arg.State.IsButtonDown(MBID_MIDDLE))
			return false;

		entType = InputEventSpace::TouchMoved;
	}

	InputEventData data;
	data.TheEventType = entType;
	data.MState = arg.State;
	InputEventAdapter::CoordinateToPX2(data.MState.Y, winSize);
	if (converted)
	{
		data.TState.X = data.MState.X;
		data.TState.Y = data.MState.Y;
		data.TState.Z = data.MState.Z;
	}

	OnInputEventData(data);

	return true;
}
//----------------------------------------------------------------------------
bool InputEventListener::MousePressed (const MouseEvent &arg, 
	MouseButtonID id)
{
	bool converted = InputEventAdapter::GetSingleton().IsConverted2Touch();
	const Sizef &winSize = InputManager::GetSingleton().GetSize();

	Event::EventType entType = InputEventSpace::MousePressed;
	if (converted)
	{
		entType = InputEventSpace::TouchPressed;
	}

	InputEventData data;
	data.TheEventType = entType;
	data.MButtonID = id;
	data.MState = arg.State;
	InputEventAdapter::CoordinateToPX2(data.MState.Y, winSize);
	if (converted)
	{
		data.TState.X = data.MState.X;
		data.TState.Y = data.MState.Y;
		data.TState.Z = data.MState.Z;
	}

	OnInputEventData(data);

	return true;
}
//----------------------------------------------------------------------------
bool InputEventListener::MouseReleased (const MouseEvent &arg,
	MouseButtonID id)
{
	bool converted = InputEventAdapter::GetSingleton().IsConverted2Touch();
	const Sizef &winSize = InputManager::GetSingleton().GetSize();

	Event::EventType entType = InputEventSpace::MouseReleased;
	if (converted)
	{
		entType = InputEventSpace::TouchReleased;
	}

	InputEventData data;
	data.TheEventType = entType;
	data.MButtonID = id;
	data.MState = arg.State;
	InputEventAdapter::CoordinateToPX2(data.MState.Y, winSize);
	if (converted)
	{
		data.TState.X = data.MState.X;
		data.TState.Y = data.MState.Y;
		data.TState.Z = data.MState.Z;
	}

	OnInputEventData(data);

	return true;
}
//----------------------------------------------------------------------------
bool InputEventListener::MouseWheeled (float val)
{
	Event::EventType entType = InputEventSpace::MouseWheeled;

	InputEventData data;
	data.TheEventType = entType;
	data.IsLargeSmall = true;
	data.LargeSmallValue = val;

	OnInputEventData(data);

	return true;
}
//----------------------------------------------------------------------------
bool InputEventListener::TouchMoved (const MultiTouchEvent &arg)
{
	Event::EventType entType = InputEventSpace::TouchMoved;

	InputEventData data;
	data.TheEventType = entType;
	data.TState = arg.State;

	OnInputEventData(data);

	return true;
}
//----------------------------------------------------------------------------
bool InputEventListener::TouchPressed (const MultiTouchEvent &arg)
{
	Event::EventType entType = InputEventSpace::TouchPressed;

	InputEventData data;
	data.TheEventType = entType;
	data.TState = arg.State;

	OnInputEventData(data);

	return true;
}
//----------------------------------------------------------------------------
bool InputEventListener::TouchReleased (const MultiTouchEvent &arg)
{
	Event::EventType entType = InputEventSpace::TouchReleased;

	InputEventData data;
	data.TheEventType = entType;
	data.TState = arg.State;

	OnInputEventData(data);

	return true;
}
//----------------------------------------------------------------------------
bool InputEventListener::TouchCancelled (const MultiTouchEvent &arg)
{
	Event::EventType entType = InputEventSpace::TouchCancelled;

	InputEventData data;
	data.TheEventType = entType;
	data.TState = arg.State;

	OnInputEventData(data);

	return true;
}
//----------------------------------------------------------------------------
void InputEventListener::TouchMoved(int num, int ids[], float xs[], float ys[])
{
	Event::EventType entType = InputEventSpace::TouchMoved;

	InputEventData data;
	data.TheEventType = entType;

	if (num > 0)
	{
		int id = ids[0];
		int x = (int)xs[0];
		int y = (int)ys[0];
		PX2_UNUSED(id);

#if defined __ANDROID__
		float rectHeight = PX2_IEA.GetRect().Height();
		y = rectHeight - y;
#endif

		data.TState.X.Absoulate = x;
		data.TState.X.IsAbsoulateOnly = true;
		data.TState.Y.Absoulate = y;
		data.TState.Y.IsAbsoulateOnly = true;
		data.TState.TouchTypes = MTET_MOVED;
	}

	for (int i=0; i<num; i++)
	{
		int id = ids[i];
		int x = (int)xs[0];
		int y = (int)ys[0];
		PX2_UNUSED(id);

#if defined __ANDROID__
		float rectHeight = PX2_IEA.GetRect().Height();
		y = rectHeight - y;
#endif

		MultiTouchState state;

		state.X.Absoulate = x;
		state.X.IsAbsoulateOnly = true;
		state.Y.Absoulate = y;
		state.Y.IsAbsoulateOnly = true;
		state.TouchTypes = MTET_MOVED;

		data.TStates.push_back(data.TState);
	}

	OnInputEventData(data);
}
//----------------------------------------------------------------------------
void InputEventListener::TouchPressed(int num, int ids[], float xs[], float ys[])
{
	Event::EventType entType = InputEventSpace::TouchPressed;

	InputEventData data;
	data.TheEventType = entType;

	if (num > 0)
	{
		int id = ids[0];
		int x = (int)xs[0];
		int y = (int)ys[0];
		PX2_UNUSED(id);

#if defined __ANDROID__
		float rectHeight = PX2_IEA.GetRect().Height();
		y = rectHeight - y;
#endif

		data.TState.X.Absoulate = x;
		data.TState.X.IsAbsoulateOnly = true;
		data.TState.Y.Absoulate = y;
		data.TState.Y.IsAbsoulateOnly = true;
		data.TState.TouchTypes = MTET_PRESSED;
	}

	for (int i=0; i<num; i++)
	{
		int id = ids[i];
		int x = (int)xs[0];
		int y = (int)ys[0];
		PX2_UNUSED(id);

#if defined __ANDROID__
		float rectHeight = PX2_IEA.GetRect().Height();
		y = rectHeight - y;
#endif

		MultiTouchState state;

		state.X.Absoulate = x;
		state.X.IsAbsoulateOnly = true;
		state.Y.Absoulate = y;
		state.Y.IsAbsoulateOnly = true;
		state.TouchTypes = MTET_PRESSED;

		data.TStates.push_back(data.TState);
	}

	OnInputEventData(data);
}
//----------------------------------------------------------------------------
void InputEventListener::TouchReleased(int num, int ids[], float xs[], float ys[])
{
	Event::EventType entType = InputEventSpace::TouchReleased;

	InputEventData data;
	data.TheEventType = entType;

	if (num > 0)
	{
		int id = ids[0];
		int x = (int)xs[0];
		int y = (int)ys[0];
		PX2_UNUSED(id);

#if defined __ANDROID__
		float rectHeight = PX2_IEA.GetRect().Height();
		y = rectHeight - y;
#endif

		data.TState.X.Absoulate = x;
		data.TState.X.IsAbsoulateOnly = true;
		data.TState.Y.Absoulate = y;
		data.TState.Y.IsAbsoulateOnly = true;
		data.TState.TouchTypes = MTET_RELEASED;
	}

	for (int i=0; i<num; i++)
	{
		int id = ids[i];
		int x = (int)xs[0];
		int y = (int)ys[0];
		PX2_UNUSED(id);

#if defined __ANDROID__
		float rectHeight = PX2_IEA.GetRect().Height();
		y = rectHeight - y;
#endif

		MultiTouchState state;

		state.X.Absoulate = x;
		state.X.IsAbsoulateOnly = true;
		state.Y.Absoulate = y;
		state.Y.IsAbsoulateOnly = true;
		state.TouchTypes = MTET_RELEASED;

		data.TStates.push_back(data.TState);
	}

	OnInputEventData(data);
}
//----------------------------------------------------------------------------
void InputEventListener::TouchCancelled(int num, int ids[], float xs[], float ys[])
{
	Event::EventType entType = InputEventSpace::TouchCancelled;

	InputEventData data;
	data.TheEventType = entType;

	if (num > 0)
	{
		int id = ids[0];
		int x = (int)xs[0];
		int y = (int)ys[0];
		PX2_UNUSED(id);

#if defined __ANDROID__
		float rectHeight = PX2_IEA.GetRect().Height();
		y = rectHeight - y;
#endif

		data.TState.X.Absoulate = x;
		data.TState.X.IsAbsoulateOnly = true;
		data.TState.Y.Absoulate = y;
		data.TState.Y.IsAbsoulateOnly = true;
		data.TState.TouchTypes = MTET_CANCELLED;
	}

	for (int i=0; i<num; i++)
	{
		int id = ids[i];
		int x = (int)xs[0];
		int y = (int)ys[0];
		PX2_UNUSED(id);

#if defined __ANDROID__
		float rectHeight = PX2_IEA.GetRect().Height();
		y = rectHeight - y;
#endif

		MultiTouchState state;

		state.X.Absoulate = x;
		state.X.IsAbsoulateOnly = true;
		state.Y.Absoulate = y;
		state.Y.IsAbsoulateOnly = true;
		state.TouchTypes = MTET_CANCELLED;

		data.TStates.push_back(data.TState);
	}

	OnInputEventData(data);
}
//----------------------------------------------------------------------------
void InputEventListener::KeypadMsg (bool back, bool menu)
{
	PX2_UNUSED(back);
	PX2_UNUSED(menu);
}
//----------------------------------------------------------------------------
void InputEventListener::OnInputEventData (const InputEventData &data)
{
	for (int i=0; i<(int)mHandlers.size(); i++)
	{
		mHandlers[i]->SetSigned(false);
	}

	for (int i=0; i<(int)mHandlers.size(); i++)
	{
		if (data.TheEventType == InputEventSpace::TouchPressed)
		{
			mHandlers[i]->TouchPressed(data);
		}
		else if (data.TheEventType == InputEventSpace::TouchReleased)
		{
			mHandlers[i]->TouchReleased(data);
		}
		else if (data.TheEventType == InputEventSpace::TouchCancelled)
		{
			mHandlers[i]->TouchCancelled(data);
		}
		else if (data.TheEventType == InputEventSpace::TouchMoved)
		{
#if defined(_WIN32) || defined(WIN32)
			if (data.IsLargeSmall)
			{
				mHandlers[i]->TouchMoved(data);
			}
			else
			{
				if (InputEventAdapter::GetSingleton().GetMouse()->GetMouseState().IsButtonDown(MBID_LEFT) ||
					InputEventAdapter::GetSingleton().GetMouse()->GetMouseState().IsButtonDown(MBID_RIGHT))
				{
					mHandlers[i]->TouchMoved(data);
				}
			}
#else
			mHandlers[i]->TouchMoved(data);
#endif
		}

		if (mHandlers[i]->IsSigned() && mHandlers[i]->IsSignIgnoreOtherHandlers())
			break;
	}

	Event *ent = InputEventSpace::CreateEventX(data.TheEventType);
	ent->SetData<InputEventData>(data);
	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
bool InputEventListener::HasHandler (InputEventHandler *handler)
{
	for (int i=0; i<(int)mHandlers.size(); i++)
	{
		if (handler == mHandlers[i])
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
static bool IEHSortFun (const InputEventHandler *handler0, const InputEventHandler *handler1)
{
	int priority0 = handler0->GetPriority();
	int priority1 = handler1->GetPriority();

	if (priority0 == priority1)
	{
		return handler0 < handler1;
	}
	else
	{
		return priority0 > priority1;
	}
}
//----------------------------------------------------------------------------
void InputEventListener::AddHandler (InputEventHandler *handler)
{
	if (HasHandler(handler))
		return;

	mHandlers.push_back(handler);

	std::sort(mHandlers.begin(), mHandlers.end(), IEHSortFun);
}
//----------------------------------------------------------------------------
void InputEventListener::RemoveHandler (InputEventHandler *handler)
{
	std::vector<InputEventHandler*>::iterator it = mHandlers.begin();
	for (; it!=mHandlers.end(); it++)
	{
		if (handler == *it)
		{
			mHandlers.erase(it);

			std::sort(mHandlers.begin(), mHandlers.end(), IEHSortFun);

			return;
		}
	}
}
//----------------------------------------------------------------------------
int InputEventListener::GetNumHandlers ()
{
	return (int)mHandlers.size();
}
//----------------------------------------------------------------------------
void InputEventListener::RemoveAllHandlers ()
{
	mHandlers.clear();
}
//----------------------------------------------------------------------------