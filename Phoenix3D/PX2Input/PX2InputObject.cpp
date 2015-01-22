/*
*
* ÎÄ¼þÃû³Æ	£º	PX2InputObject.cpp
*
*/

#include "PX2InputObject.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
// InputObject
//----------------------------------------------------------------------------
InputObject::~InputObject ()
{
}
//----------------------------------------------------------------------------
InputObject::InputObject (const std::string &vendor, InputType type, 
	bool buffered, int devID, InputManager *creator)
	:
mVendor(vendor),
mInputType(type),
mIsBuffered(buffered),
mDevID(devID),
mCreator(creator)
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// EventArg
//----------------------------------------------------------------------------
EventArg::EventArg (InputObject* obj)
	:
TheObject(obj) 
{
}
//----------------------------------------------------------------------------
EventArg::~EventArg()
{
}
//----------------------------------------------------------------------------