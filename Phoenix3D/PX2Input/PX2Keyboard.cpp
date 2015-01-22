/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Keyboard.cpp
*
*/

#include "PX2Keyboard.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
// KeyEvent
//----------------------------------------------------------------------------
KeyEvent::KeyEvent (InputObject* obj, KeyCode kc, unsigned int txt)
	: 
EventArg(obj),
Key(kc), 
Text(txt)
{
}
//----------------------------------------------------------------------------
KeyEvent::~KeyEvent()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Keyboard
//----------------------------------------------------------------------------
Keyboard::Keyboard (const std::string &vendor, bool buffered, int devID,
	InputManager* creator)
	:
InputObject(vendor, IT_KEYBOARD, buffered, devID, creator),
mModifiers(0),
mTextMode(Keyboard::TTM_UNICODE)
{
}
//----------------------------------------------------------------------------
Keyboard::~Keyboard()
{
}
//----------------------------------------------------------------------------