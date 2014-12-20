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
	Event *ent = 0;
	ent = InputEventSpace::CreateEventX(InputEventSpace::KeyPressed);

	InputEventData data;
	data.UnCoveredType = ent->GetEventType();
	data.KCode = arg.Key;

	ent->SetData<InputEventData>(data);

	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);

	OnInputEventData(data);

	return true;
}
//----------------------------------------------------------------------------
bool InputEventListener::KeyReleased (const KeyEvent &arg)
{
	Event *ent = 0;
	ent = InputEventSpace::CreateEventX(InputEventSpace::KeyReleased);

	InputEventData data;
	data.UnCoveredType = ent->GetEventType();
	data.KCode = arg.Key;

	ent->SetData<InputEventData>(data);

	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);

	OnInputEventData(data);

	return true;
}
//----------------------------------------------------------------------------
bool InputEventListener::MouseMoved (const MouseEvent &arg)
{
	bool converted = InputEventAdapter::GetSingleton().IsConverted2Touch();
	const Sizef &winSize = InputManager::GetSingleton().GetSize();

	/*arg.State.IsButtonDown();*/
	Event::EventType entType = InputEventSpace::MouseMoved;
	if (converted)
	{
		if (!arg.State.IsButtonDown(MBID_LEFT) 
			&& !arg.State.IsButtonDown(MBID_RIGHT)
			&& !arg.State.IsButtonDown(MBID_MIDDLE))
			return false;

		entType = InputEventSpace::TouchMoved;
	}

	Event *ent = 0;
	ent = InputEventSpace::CreateEventX(entType);

	InputEventData data;
	data.UnCoveredType = ent->GetEventType();
	data.MState = arg.State;
	InputEventAdapter::CoordinateToPX2(data.MState.Y, winSize);
	if (converted)
	{
		data.TState.X = data.MState.X;
		data.TState.Y = data.MState.Y;
		data.TState.Z = data.MState.Z;
	}

	ent->SetData<InputEventData>(data);

	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);

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

	Event *ent = 0;
	ent = InputEventSpace::CreateEventX(entType);

	InputEventData data;
	data.UnCoveredType = ent->GetEventType();
	data.MButtonID = id;
	data.MState = arg.State;
	InputEventAdapter::CoordinateToPX2(data.MState.Y, winSize);
	if (converted)
	{
		data.TState.X = data.MState.X;
		data.TState.Y = data.MState.Y;
		data.TState.Z = data.MState.Z;
	}

	ent->SetData<InputEventData>(data);

	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);

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

	Event *ent = 0;
	ent = InputEventSpace::CreateEventX(entType);

	InputEventData data;
	data.UnCoveredType = ent->GetEventType();
	data.MButtonID = id;
	data.MState = arg.State;
	InputEventAdapter::CoordinateToPX2(data.MState.Y, winSize);
	if (converted)
	{
		data.TState.X = data.MState.X;
		data.TState.Y = data.MState.Y;
		data.TState.Z = data.MState.Z;
	}

	ent->SetData<InputEventData>(data);

	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);

	OnInputEventData(data);

	return true;
}
//----------------------------------------------------------------------------
bool InputEventListener::TouchMoved (const MultiTouchEvent &arg)
{
	Event::EventType entType = InputEventSpace::TouchMoved;

	Event *ent = 0;
	ent = InputEventSpace::CreateEventX(entType);

	InputEventData data;
	data.UnCoveredType = ent->GetEventType();
	data.TState = arg.State;
	ent->SetData<InputEventData>(data);

	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);

	OnInputEventData(data);

	return true;
}
//----------------------------------------------------------------------------
bool InputEventListener::TouchPressed (const MultiTouchEvent &arg)
{
	Event::EventType entType = InputEventSpace::TouchPressed;

	Event *ent = 0;
	ent = InputEventSpace::CreateEventX(entType);

	InputEventData data;
	data.UnCoveredType = ent->GetEventType();
	data.TState = arg.State;
	ent->SetData<InputEventData>(data);

	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);

	OnInputEventData(data);

	return true;
}
//----------------------------------------------------------------------------
bool InputEventListener::TouchReleased (const MultiTouchEvent &arg)
{
	Event::EventType entType = InputEventSpace::TouchReleased;

	Event *ent = 0;
	ent = InputEventSpace::CreateEventX(entType);

	InputEventData data;
	data.UnCoveredType = ent->GetEventType();
	data.TState = arg.State;
	ent->SetData<InputEventData>(data);

	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);

	OnInputEventData(data);

	return true;
}
//----------------------------------------------------------------------------
bool InputEventListener::TouchCancelled (const MultiTouchEvent &arg)
{
	Event::EventType entType = InputEventSpace::TouchCancelled;

	Event *ent = 0;
	ent = InputEventSpace::CreateEventX(entType);

	InputEventData data;
	data.UnCoveredType = ent->GetEventType();
	data.TState = arg.State;
	ent->SetData<InputEventData>(data);

	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);

	OnInputEventData(data);

	return true;
}
//----------------------------------------------------------------------------
void InputEventListener::OnLargeSmall (float val)
{
	Event::EventType entType = InputEventSpace::TouchMoved;

	Event *ent = 0;
	ent = InputEventSpace::CreateEventX(entType);

	InputEventData data;
	data.UnCoveredType = ent->GetEventType();
	data.IsLargeSmall = true;
	data.LargeSmallValue = val;
	ent->SetData<InputEventData>(data);

	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);

	OnInputEventData(data);
}
//----------------------------------------------------------------------------
void InputEventListener::TouchMoved(int num, int ids[], float xs[], float ys[])
{
	Sizef size = PX2_IEA.GetSize();

	Event::EventType entType = InputEventSpace::TouchMoved;
	Event *ent = 0;
	ent = InputEventSpace::CreateEventX(entType);
	InputEventData data;
	data.UnCoveredType = ent->GetEventType();

	if (num > 0)
	{
		int id = ids[0];
		int x = (int)xs[0];
		int y = (int)ys[0];
		PX2_UNUSED(id);

#if defined __ANDROID__
		y = size.Height - y;
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
		y = size.Height - y;
#endif

		MultiTouchState state;

		state.X.Absoulate = x;
		state.X.IsAbsoulateOnly = true;
		state.Y.Absoulate = y;
		state.Y.IsAbsoulateOnly = true;
		state.TouchTypes = MTET_MOVED;

		data.TStates.push_back(data.TState);
	}

	ent->SetData<InputEventData>(data);

	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);

	OnInputEventData(data);
}
//----------------------------------------------------------------------------
void InputEventListener::TouchPressed(int num, int ids[], float xs[], float ys[])
{
	Sizef size = PX2_IEA.GetSize();

	Event::EventType entType = InputEventSpace::TouchPressed;
	Event *ent = 0;
	ent = InputEventSpace::CreateEventX(entType);
	InputEventData data;
	data.UnCoveredType = ent->GetEventType();

	if (num > 0)
	{
		int id = ids[0];
		int x = (int)xs[0];
		int y = (int)ys[0];
		PX2_UNUSED(id);

#if defined __ANDROID__
		y = size.Height - y;
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
		y = size.Height - y;
#endif

		MultiTouchState state;

		state.X.Absoulate = x;
		state.X.IsAbsoulateOnly = true;
		state.Y.Absoulate = y;
		state.Y.IsAbsoulateOnly = true;
		state.TouchTypes = MTET_PRESSED;

		data.TStates.push_back(data.TState);
	}

	ent->SetData<InputEventData>(data);

	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);

	OnInputEventData(data);
}
//----------------------------------------------------------------------------
void InputEventListener::TouchReleased(int num, int ids[], float xs[], float ys[])
{
	Sizef size = PX2_IEA.GetSize();

	Event::EventType entType = InputEventSpace::TouchReleased;
	Event *ent = 0;
	ent = InputEventSpace::CreateEventX(entType);
	InputEventData data;
	data.UnCoveredType = ent->GetEventType();

	if (num > 0)
	{
		int id = ids[0];
		int x = (int)xs[0];
		int y = (int)ys[0];
		PX2_UNUSED(id);

#if defined __ANDROID__
		y = size.Height - y;
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
		y = size.Height - y;
#endif

		MultiTouchState state;

		state.X.Absoulate = x;
		state.X.IsAbsoulateOnly = true;
		state.Y.Absoulate = y;
		state.Y.IsAbsoulateOnly = true;
		state.TouchTypes = MTET_RELEASED;

		data.TStates.push_back(data.TState);
	}

	ent->SetData<InputEventData>(data);

	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);

	OnInputEventData(data);
}
//----------------------------------------------------------------------------
void InputEventListener::TouchCancelled(int num, int ids[], float xs[], float ys[])
{
	Sizef size = PX2_IEA.GetSize();

	Event::EventType entType = InputEventSpace::TouchCancelled;
	Event *ent = 0;
	ent = InputEventSpace::CreateEventX(entType);
	InputEventData data;
	data.UnCoveredType = ent->GetEventType();

	if (num > 0)
	{
		int id = ids[0];
		int x = (int)xs[0];
		int y = (int)ys[0];
		PX2_UNUSED(id);

#if defined __ANDROID__
		y = size.Height - y;
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
		y = size.Height - y;
#endif

		MultiTouchState state;

		state.X.Absoulate = x;
		state.X.IsAbsoulateOnly = true;
		state.Y.Absoulate = y;
		state.Y.IsAbsoulateOnly = true;
		state.TouchTypes = MTET_CANCELLED;

		data.TStates.push_back(data.TState);
	}

	ent->SetData<InputEventData>(data);

	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);

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
		if (data.UnCoveredType == InputEventSpace::UnCover(InputEventSpace::TouchPressed))
		{
			mHandlers[i]->TouchPressed(data);
		}
		else if (data.UnCoveredType == InputEventSpace::UnCover(InputEventSpace::TouchReleased))
		{
			mHandlers[i]->TouchReleased(data);
		}
		else if (data.UnCoveredType == InputEventSpace::UnCover(InputEventSpace::TouchCancelled))
		{
			mHandlers[i]->TouchCancelled(data);
		}
		else if (data.UnCoveredType == InputEventSpace::UnCover(InputEventSpace::TouchMoved))
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
	}
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