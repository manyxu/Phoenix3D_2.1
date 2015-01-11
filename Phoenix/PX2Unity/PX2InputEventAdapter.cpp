/*
*
* ÎÄ¼þÃû³Æ	£º	PX2InputEventAdapter.cpp
*
*/

#include "PX2InputEventAdapter.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
InputEventAdapter::InputEventAdapter ()
{
	mEventListener = new0 InputEventListener();

	mInputManager = 0;
	mKeyboard = 0 ;
	mMouse = 0;
	mMultiTouch = 0;
	mIsConverted2Touch = false;
}
//----------------------------------------------------------------------------
InputEventAdapter::~InputEventAdapter ()
{
	if (mEventListener)
	{
		delete0(mEventListener);
	}
}
//----------------------------------------------------------------------------
void InputEventAdapter::AddParam (int windowID)
{

#if defined(_WIN32) || defined(WIN32)
	std::ostringstream wnd;
	wnd << (size_t)windowID;

	mParamList.insert(std::make_pair(std::string("Window"), wnd.str()));

	mParamList.insert(std::make_pair(std::string("Win32Keyboard"),
		std::string("DISCL_FOREGROUND" )));
	mParamList.insert(std::make_pair(std::string("Win32Keyboard"),
		std::string("DISCL_NONEXCLUSIVE")));

	mParamList.insert(std::make_pair(std::string("Win32Mouse"),
		std::string("DISCL_FOREGROUND" )));
	mParamList.insert(std::make_pair(std::string("Win32Mouse"),
		std::string("DISCL_NONEXCLUSIVE")));

#elif defined(__ANDROID__)

#endif
}
//----------------------------------------------------------------------------
bool InputEventAdapter::Initlize ()
{
	mInputManager = InputManager::CreateInputSystem(mParamList);

#if defined(_WIN32) || defined(WIN32)
	mKeyboard = (Keyboard*)mInputManager->CreateInputObject(IT_KEYBOARD, false);
	mKeyboard->SetEventCallback(mEventListener);

	mMouse = (Mouse*)mInputManager->CreateInputObject(IT_MOUSE, true);
	mMouse->SetEventCallback(mEventListener);
#endif

#if defined(__ANDROID__) || defined(__MARMALADE__)
	mMultiTouch = (MultiTouch*)mInputManager->CreateInputObject(IT_TOUCH, true);
	mMultiTouch->SetEventCallback(mEventListener);
#endif

	return true;
}
//----------------------------------------------------------------------------
bool InputEventAdapter::Ternamate ()
{
	if (mInputManager)
	{
		InputManager::DestroyInputSystem(mInputManager);
		mInputManager = 0;
		InputManager::Set(0);
	}

	return true;
}
//----------------------------------------------------------------------------
void InputEventAdapter::SetRect (const Rectf &rect)
{
	mRect = rect;
}
//----------------------------------------------------------------------------
void InputEventAdapter::Update ()
{
	if (mKeyboard)
		mKeyboard->Capture();

	if (mMouse)
		mMouse->Capture();
}
//----------------------------------------------------------------------------
void InputEventAdapter::CoordinateToPX2 (Axis &Y, const Sizef &winSize)
{
	Y.Absoulate = (int)winSize.Height - Y.Absoulate;
	Y.Relative = -Y.Relative;
}
//----------------------------------------------------------------------------