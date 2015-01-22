/*
*
* ÎÄ¼þÃû³Æ	£º	PX2MultiTouch.cpp
*
*/

#include "PX2MultiTouch.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
// MultiTouchState
//----------------------------------------------------------------------------
MultiTouchState::MultiTouchState ()
	:
TouchTypes(0),
ID(-1)
{
}
//----------------------------------------------------------------------------
void MultiTouchState::Clear ()
{
	ID = -1;
	X.Clear();
	Y.Clear();
	Z.Clear();
	TouchTypes = MTET_NONE;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// MultiTouchEvent
//----------------------------------------------------------------------------
MultiTouchEvent::MultiTouchEvent (InputObject *obj, const MultiTouchState &mts)
	:
EventArg(obj),
State(mts)
{
}
//----------------------------------------------------------------------------
MultiTouchEvent::~MultiTouchEvent ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// MouseListener
//----------------------------------------------------------------------------
MultiTouchListener::~MultiTouchListener()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// MultiTouch
//----------------------------------------------------------------------------
MultiTouch::~MultiTouch ()
{
}
//----------------------------------------------------------------------------
void MultiTouch::SetEventCallback (MultiTouchListener *touchListener)
{
	mListener = touchListener;
}
//----------------------------------------------------------------------------
void MultiTouch::ClearStates ()
{
	mStates.clear();
}
//----------------------------------------------------------------------------
std::vector<MultiTouchState> MultiTouch::GetMultiTouchStates () const
{
	return mStates;
}
//----------------------------------------------------------------------------
const std::vector<MultiTouchState> MultiTouch::GetFirstNumTouchStates (int num)
{
	int numTemp = 0;

	std::vector<MultiTouchState> states;
	for (unsigned int i = 0; i < mStates.size(); i++) 
	{
		if (!(mStates[i].HasTouchType(MTET_NONE))) 
		{
			states.push_back(mStates[i]);
		}

		numTemp++;

		if (numTemp == num)
		{
			return states;
		}
	}

	return states;
}
//----------------------------------------------------------------------------
const std::vector<MultiTouchState> MultiTouch::GetMultiTouchStatesOfType (
	MultiTouchEventType type)
{
	std::vector<MultiTouchState> states;
	for (unsigned int i = 0; i < mStates.size(); i++) 
	{
		if (!(mStates[i].HasTouchType(type))) 
		{
			states.push_back(mStates[i]);
		}
	}
	return states;
}
//----------------------------------------------------------------------------
MultiTouch::MultiTouch (const std::string &vendor, bool buffered, int devID,
	InputManager *creator)
	:
InputObject(vendor, IT_MULTITOUCH, buffered, devID, creator),
mListener(0) 
{
}
//----------------------------------------------------------------------------