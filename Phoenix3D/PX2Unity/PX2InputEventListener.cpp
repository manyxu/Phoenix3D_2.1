// PX2InputEventListener.cpp

#include "PX2InputEventListener.hpp"
#include "PX2EventWorld.hpp"
#include "PX2GraphicsRoot.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
InputEventListener::InputEventListener(int viewID) :
mViewID(viewID)
{
}
//----------------------------------------------------------------------------
InputEventListener::~InputEventListener()
{
}
//----------------------------------------------------------------------------
void InputEventListener::OnInputEventData(InputEventData &data)
{
	data.ViewID = mViewID;

	Event *ent = InputEventSpace::CreateEventX(data.TheEventType);
	ent->SetData<InputEventData>(data);
	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void InputEventListener::KeyPressed(KeyCode code)
{
	InputEventData data;
	data.TheEventType = InputEventSpace::KeyPressed;
	data.KCode = code;

	OnInputEventData(data);
}
//----------------------------------------------------------------------------
void InputEventListener::KeyReleased(KeyCode code)
{
	InputEventData data;
	data.TheEventType = InputEventSpace::KeyReleased;
	data.KCode = code;

	OnInputEventData(data);
}
//----------------------------------------------------------------------------
void InputEventListener::MouseMoved(const APoint &pos)
{
	InputEventData data;
	data.TheEventType = InputEventSpace::MouseMoved;
	data.MTPos = pos;

	OnInputEventData(data);
}
//----------------------------------------------------------------------------
void InputEventListener::MousePressed(MouseButtonID id, const APoint &pos)
{
	InputEventData data;
	data.TheEventType = InputEventSpace::MousePressed;
	data.MButtonID = id;
	data.MTPos = pos;

	OnInputEventData(data);
}
//----------------------------------------------------------------------------
void InputEventListener::MouseReleased(MouseButtonID id, const APoint &pos)
{
	InputEventData data;
	data.TheEventType = InputEventSpace::MouseReleased;
	data.MButtonID = id;
	data.MTPos = pos;

	OnInputEventData(data);
}
//----------------------------------------------------------------------------
void InputEventListener::MouseWheeled(float val)
{
	InputEventData data;
	data.TheEventType = InputEventSpace::MouseWheeled;
	data.MButtonID = MBID_MIDDLE;
	data.MWheel = val;

	OnInputEventData(data);
}
//----------------------------------------------------------------------------
void InputEventListener::TouchMoved(int num, int ids[], float xs[], float ys[])
{
	InputEventData data;
	data.TheEventType = InputEventSpace::TouchMoved;

	_OnTouchData(data, num, ids, xs, ys);

	OnInputEventData(data);
}
//----------------------------------------------------------------------------
void InputEventListener::TouchPressed(int num, int ids[], float xs[], 
	float ys[])
{
	InputEventData data;
	data.TheEventType = InputEventSpace::TouchPressed;

	_OnTouchData(data, num, ids, xs, ys);

	OnInputEventData(data);
}
//----------------------------------------------------------------------------
void InputEventListener::TouchReleased(int num, int ids[], float xs[], 
	float ys[])
{
	InputEventData data;
	data.TheEventType = InputEventSpace::TouchPressed;

	_OnTouchData(data, num, ids, xs, ys);

	OnInputEventData(data);
}
//----------------------------------------------------------------------------
void InputEventListener::TouchCancelled(int num, int ids[], float xs[],
	float ys[])
{
	InputEventData data;
	data.TheEventType = InputEventSpace::TouchCancelled;

	_OnTouchData(data, num, ids, xs, ys);

	OnInputEventData(data);
}
//----------------------------------------------------------------------------
void InputEventListener::_OnTouchData(InputEventData &data, int num,
	int ids[], float xs[], float ys[])
{
	for (int i = 0; i < num; i++)
	{
		int id = ids[i];
		float x = xs[i];
		float y = ys[i];
		PX2_UNUSED(id);

		const Sizef &size = PX2_GR.GetSize();
		y = size.Height - y;

		APoint pos = APoint(x, 0.0f, y);

		data.TPoses.push_back(pos);

		if (0 == i)
		{
			data.MTPos = pos;
		}
	}
}
//----------------------------------------------------------------------------
void InputEventListener::KeypadMsg(bool back, bool menu)
{
	PX2_UNUSED(back);
	PX2_UNUSED(menu);
}
//----------------------------------------------------------------------------