// PX2InputManager.cpp

#include "PX2InputManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
InputManager::InputManager()
{
	mInputEventListener = new0 InputEventListener(0);
}
//----------------------------------------------------------------------------
InputManager::~InputManager()
{
}
//----------------------------------------------------------------------------