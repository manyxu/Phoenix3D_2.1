/*
*
* ÎÄ¼þÃû³Æ	£º	PX2InputEvents.cpp
*
*/

#include "PX2InputEvent.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
// InputEventSpace
//----------------------------------------------------------------------------
PX2_IMPLEMENT_EVENT(InputEventSpace);

//----------------------------------------------------------------------------
// InputEventData
//----------------------------------------------------------------------------
InputEventData::InputEventData ()
	:
ViewID(0),
	UnCoveredType(-1),
	KCode(KC_UNASSIGNED),
	MButtonID(MBID_LEFT),
	IsLargeSmall(false),
	LargeSmallValue(0.0f)
{
}
//----------------------------------------------------------------------------
InputEventData::~InputEventData ()
{
}
//----------------------------------------------------------------------------
bool InputEventData::ConvertMultiTouchToLargeSmall ()
{
	return IsLargeSmall;
}
//----------------------------------------------------------------------------