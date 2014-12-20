/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Win32InputManager.cpp
*
*/

#include "PX2Win32InputManager.hpp"
#include "PX2Win32Mouse.hpp"
#include "PX2Win32Keyboard.hpp"
#include "PX2Memory.hpp"
#include "PX2Assert.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
Win32InputManager::Win32InputManager() 
	:
InputManager("Win32InputManager"),
mhWnd(0),
mDirectInput(0),
mKeyboardSettings(0),
mMouseSettings(0),
mIsKeyboardUsed(false),
mIsMouseUsed(false)
{
	mFactories.push_back(this);
}
//----------------------------------------------------------------------------
Win32InputManager::~Win32InputManager()
{
	if (mDirectInput)
	{
		mDirectInput->Release();
		mDirectInput = 0;
	}
}
//----------------------------------------------------------------------------
void Win32InputManager::Initialize (ParamList &paramList)
{
	HINSTANCE hInst = 0;
	HRESULT hr;

	ParamList::iterator i = paramList.find("Window");
	if (i == paramList.end()) 
	{
		assertion(false, 
			"Win32InputManager::Win32InputManager >> No HWND found!");
	}

	unsigned __int64 handle = _strtoui64(i->second.c_str(), 0, 10);
	mhWnd = (HWND)handle;

	if (IsWindow(mhWnd) == 0)
	{
		assertion(false, "The sent HWND is not valid!");
	}

	hInst = GetModuleHandle(0);

	hr = DirectInput8Create( hInst, DIRECTINPUT_VERSION, IID_IDirectInput8, 
		(VOID**)&mDirectInput, 0 );
	if (FAILED(hr))
	{
		assertion(false, "Not able to init DirectX8 Input!");
	}

	ParseConfigSettings(paramList);
	EnumerateDevices();
}
//----------------------------------------------------------------------------
void Win32InputManager::ParseConfigSettings (ParamList &paramList)
{
	std::map<std::string, DWORD> temp;
	temp["DISCL_BACKGROUND"]	= DISCL_BACKGROUND;
	temp["DISCL_EXCLUSIVE"]		= DISCL_EXCLUSIVE;
	temp["DISCL_FOREGROUND"]	= DISCL_FOREGROUND;
	temp["DISCL_NONEXCLUSIVE"]	= DISCL_NONEXCLUSIVE;
	temp["DISCL_NOWINKEY"]		= DISCL_NOWINKEY;

	ParamList::iterator it = paramList.begin();
	for (; it!=paramList.end(); it++)
	{
		if (it->first == "Win32Keyboard")
		{
			mKeyboardSettings |= temp[it->second];
		}
		else if (it->first == "Win32Mouse")
		{
			mMouseSettings |= temp[it->second];
		}
	}

	if (0 == mKeyboardSettings)
	{
		mKeyboardSettings
			= DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY;
	}

	if (0 == mMouseSettings)
	{
		mMouseSettings = DISCL_FOREGROUND | DISCL_NONEXCLUSIVE;
	}
}
//----------------------------------------------------------------------------
void Win32InputManager::EnumerateDevices()
{
	mDirectInput->EnumDevices(0, DIEnumDevCallback, this, DIEDFL_ATTACHEDONLY);
}
//----------------------------------------------------------------------------
BOOL CALLBACK Win32InputManager::DIEnumDevCallback(LPCDIDEVICEINSTANCE lpddi,
	LPVOID pvRef)
{
	PX2_UNUSED(lpddi);
	PX2_UNUSED(pvRef);

	Win32InputManager *manager = static_cast<Win32InputManager*>(pvRef);
	PX2_UNUSED(manager);

	return DIENUM_CONTINUE;
}
//----------------------------------------------------------------------------
DeviceList Win32InputManager::GetFreeDeviceList()
{
	DeviceList list;

	if (!mIsKeyboardUsed)
		list.insert(std::make_pair(IT_KEYBOARD, mInputSystemName));

	if (!mIsMouseUsed)
		list.insert(std::make_pair(IT_MOUSE, mInputSystemName));

	return list;
}
//----------------------------------------------------------------------------
int Win32InputManager::GetNumDevices (InputType type)
{
	switch(type)
	{
	case IT_KEYBOARD:
		return 1;
	case IT_MOUSE:
		return 1;
	default:
		return 0;
	}
}
//----------------------------------------------------------------------------
int Win32InputManager::GetNumFreeDevices (InputType type)
{
	switch (type)
	{
	case IT_KEYBOARD:
		return mIsKeyboardUsed ? 0 : 1;
	case IT_MOUSE:
		return mIsMouseUsed ? 0 : 1;
	default:
		return 0;
	}
}
//----------------------------------------------------------------------------
bool Win32InputManager::IsVendorExist(InputType type, 
	const std::string &vendor)
{
	if (IT_KEYBOARD==type || IT_MOUSE==type && vendor==mInputSystemName)
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
InputObject *Win32InputManager::CreateObject(InputManager* creator, 
	InputType type, bool bufferMode, const std::string &vendor)
{
	PX2_UNUSED(creator);
	PX2_UNUSED(vendor);

	InputObject *obj = 0;

	switch(type)
	{
	case IT_KEYBOARD:
		if (!mIsKeyboardUsed)
		{
			obj = new0 Win32Keyboard(this, mDirectInput, bufferMode, 
				mKeyboardSettings);
		}
		break;
	case IT_MOUSE:
		if (!mIsMouseUsed)
		{
			obj = new0 Win32Mouse(this, mDirectInput, bufferMode, 
				mMouseSettings);
		}
		break;
	default:
		break;
	}

	if (!obj)
	{
		assertion(false, "No devices match requested type.");
	}

	return obj;
}
//----------------------------------------------------------------------------
void Win32InputManager::DestroyObject (InputObject *obj)
{
	delete0(obj);
}
//----------------------------------------------------------------------------
