/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Win32Keyboard.cpp
*
*/

#include "PX2Win32KeyBoard.hpp"
#include "PX2Win32InputManager.hpp"
#include "PX2Assert.hpp"
using namespace PX2;
using namespace std;

//----------------------------------------------------------------------------
Win32Keyboard::Win32Keyboard (InputManager *creator,
	IDirectInput8 *directInput8, bool buffered, DWORD coopSettings)
	:
Keyboard(creator->GetInputSystemName(), buffered, 0, creator)
{
	mKeyboard = 0;
	mDirectInput = directInput8;
	mCoopSetting = coopSettings;

	memset(&mKeyBuffer, 0, 256);
	mDeadKey = '\0';
	static_cast<Win32InputManager*>(mCreator)->SetKeyboardUsed(true);
}
//----------------------------------------------------------------------------
void Win32Keyboard::Initialize()
{
	mModifiers = 0;
	mDeadKey = '\0';

	if (FAILED(mDirectInput->CreateDevice(GUID_SysKeyboard, &mKeyboard, 0)))
	{
		assertion(false, "Could not init device!");
	}

	if (FAILED(mKeyboard->SetDataFormat(&c_dfDIKeyboard)))
	{
		assertion(false, "Format error!");
	}

	HWND hWnd = ((Win32InputManager*)mCreator)->GetWindowHandle();

	if (FAILED(mKeyboard->SetCooperativeLevel(hWnd, mCoopSetting)))
	{
		assertion(false, "Coop error!");
	}

	if (mIsBuffered)
	{
		DIPROPDWORD dipdw;
		dipdw.diph.dwSize       = sizeof(DIPROPDWORD);
		dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
		dipdw.diph.dwObj        = 0;
		dipdw.diph.dwHow        = DIPH_DEVICE;
		dipdw.dwData            = KEYBOARD_DX_BUFFERSIZE;

		if (FAILED(mKeyboard->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph)))
		{
			assertion(false, "Buffer error!");
		}
	}

	HRESULT hr = mKeyboard->Acquire();
	if(FAILED(hr) && hr != DIERR_OTHERAPPHASPRIO)
	{
		assertion(false, "Aquire error!");
	}
}
//----------------------------------------------------------------------------
Win32Keyboard::~Win32Keyboard()
{
	if(mKeyboard)
	{
		mKeyboard->Unacquire();
		mKeyboard->Release();
		mKeyboard = 0;
	}
	static_cast<Win32InputManager*>(mCreator)->SetKeyboardUsed(false);
}
//----------------------------------------------------------------------------
void Win32Keyboard::Capture()
{
	if (mIsBuffered)
		ReadBuffered();
	else
		Read();
}
//----------------------------------------------------------------------------
void Win32Keyboard::ReadBuffered()
{
	DIDEVICEOBJECTDATA diBuff[KEYBOARD_DX_BUFFERSIZE];
	DWORD numBuffers = KEYBOARD_DX_BUFFERSIZE;
	HRESULT hr;

	static bool verifyAfterAltTab = false;

	hr = mKeyboard->GetDeviceData( sizeof(DIDEVICEOBJECTDATA), diBuff,
		&numBuffers, 0 );
	if (hr != DI_OK)
	{
		hr = mKeyboard->Acquire();
		if (hr == E_ACCESSDENIED)
			verifyAfterAltTab = true;

		while( hr == DIERR_INPUTLOST )
			hr = mKeyboard->Acquire();

		return;
	}

	if (FAILED(hr))
	{
		assertion(false, "Problem with Device!");
	}

	for (unsigned int i = 0; i < numBuffers; ++i)
	{
		bool ret = true;
		KeyCode kc = (KeyCode)diBuff[i].dwOfs;

		mKeyBuffer[kc] = static_cast<unsigned char>(diBuff[i].dwData);

		if (diBuff[i].dwData & 0x80)
		{
			if( kc == KC_LCONTROL || kc == KC_RCONTROL )
				mModifiers |= Ctrl;
			else if( kc == KC_LSHIFT || kc == KC_RSHIFT )
				mModifiers |= Shift;
			else if( kc == KC_LMENU || kc == KC_RMENU )
				mModifiers |= Alt;

			if (mListener)
			{
				ret = mListener->KeyPressed(KeyEvent(this, kc, TranslateText(kc)));
			}
		}
		else
		{
			if( kc == KC_LCONTROL || kc == KC_RCONTROL )
				mModifiers &= ~Ctrl;
			else if( kc == KC_LSHIFT || kc == KC_RSHIFT )
				mModifiers &= ~Shift;
			else if( kc == KC_LMENU || kc == KC_RMENU )
				mModifiers &= ~Alt;

			if (mListener)
				ret = mListener->KeyReleased(KeyEvent(this, kc, 0));
		}

		if(ret == false)
			break;
	}

	if (verifyAfterAltTab)
	{
		bool ret = true;

		unsigned char keyBufferCopy[256];
		memcpy(keyBufferCopy, mKeyBuffer, 256);

		Read();

		for (unsigned i = 0; i < 256; i++)
		{
			if (keyBufferCopy[i] != mKeyBuffer[i])
			{
				if (mListener)
				{
					if (mKeyBuffer[i])
						ret = mListener->KeyPressed(KeyEvent(this,
							(KeyCode)i, TranslateText((KeyCode)i)));
					else
						ret = mListener->KeyReleased(KeyEvent(this,
							(KeyCode)i, 0));
				}
			}

			if (ret == false)
				return;
		}

		verifyAfterAltTab = false;
	}
}
//----------------------------------------------------------------------------
void Win32Keyboard::Read()
{
	HRESULT  hr = mKeyboard->GetDeviceState(sizeof(mKeyBuffer), &mKeyBuffer);

	if (hr==DIERR_INPUTLOST || hr==DIERR_NOTACQUIRED)
	{
		hr = mKeyboard->Acquire();
		if (hr != DIERR_OTHERAPPHASPRIO)
			mKeyboard->GetDeviceState(sizeof(mKeyBuffer), &mKeyBuffer);
	}

	//Set Shift, Ctrl, Alt
	mModifiers = 0;
	if (IsKeyDown(KC_LCONTROL) || IsKeyDown(KC_RCONTROL))
		mModifiers |= Ctrl;
	if (IsKeyDown(KC_LSHIFT) || IsKeyDown(KC_RSHIFT))
		mModifiers |= Shift;
	if (IsKeyDown(KC_LMENU) || IsKeyDown(KC_RMENU))
		mModifiers |= Alt;
}
//----------------------------------------------------------------------------
int Win32Keyboard::TranslateText (KeyCode kc)
{
	if( mTextMode == TTM_OFF)
		return 0;

	BYTE keyState[256];
	HKL  layout = GetKeyboardLayout(0);
	if (GetKeyboardState(keyState) == 0)
		return 0;

	unsigned int vk = MapVirtualKeyEx(kc, 3, layout);
	if( vk == 0 )
		return 0;

	WCHAR buff[3] = {0};
	int ascii = ToUnicodeEx(vk, kc, keyState, buff, 3, 0, layout);

	if (ascii==1 && mDeadKey!='\0')
	{
		// A dead key is stored and we have just converted a character key
		// Combine the two into a single character
		WCHAR wcBuff[3] = {buff[0], mDeadKey, '\0'};
		WCHAR out[3];

		mDeadKey = '\0';
		if(FoldStringW(MAP_PRECOMPOSED, (LPWSTR)wcBuff, 3, (LPWSTR)out, 3))
			return out[0];
	}
	else if (ascii == 1)
	{	// We have a single character
		mDeadKey = '\0';
		return buff[0];
	}
	else if(ascii == 2)
	{	// Convert a non-combining diacritical mark into a combining diacritical mark
		// Combining versions range from 0x300 to 0x36F; only 5 (for French) have been mapped below
		// http://www.fileformat.info/info/unicode/block/combining_diacritical_marks/images.htm
		switch(buff[0])	{
		case 0x5E: // Circumflex accent: ?
			mDeadKey = 0x302; break;
		case 0x60: // Grave accent: ?
			mDeadKey = 0x300; break;
		case 0xA8: // Diaeresis: ?
			mDeadKey = 0x308; break;
		case 0xB4: // Acute accent: ?
			mDeadKey = 0x301; break;
		case 0xB8: // Cedilla: ?
			mDeadKey = 0x327; break;
		default:
			mDeadKey = buff[0]; break;
		}
	}

	return 0;
}
//----------------------------------------------------------------------------
bool Win32Keyboard::IsKeyDown( KeyCode key ) const
{
	return (mKeyBuffer[key] & 0x80) != 0;
}
//----------------------------------------------------------------------------
const std::string &Win32Keyboard::GetAsString (KeyCode kc)
{
	char temp[256];

	DIPROPSTRING prop;
	prop.diph.dwSize = sizeof(DIPROPSTRING);
	prop.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	prop.diph.dwObj = static_cast<DWORD>(kc);
	prop.diph.dwHow = DIPH_BYOFFSET;

	if (SUCCEEDED(mKeyboard->GetProperty(DIPROP_KEYNAME, &prop.diph)))
	{
		if (WideCharToMultiByte(CP_ACP, 0, prop.wsz, -1, temp, sizeof(temp),
			0, 0))
			return mGetString.assign(temp);
	}

	std::stringstream str;
	str << "Key_" << (int)kc;
	return mGetString.assign(str.str());
}
//----------------------------------------------------------------------------
void Win32Keyboard::CopyKeyStates (char keys[256]) const
{
	for (int i = 0; i < 256; ++i)
		keys[i] = mKeyBuffer[i]>0 ? 1: 0;
}
//----------------------------------------------------------------------------
void Win32Keyboard::SetBuffered (bool buffered)
{
	if (buffered != mIsBuffered)
	{
		if(mKeyboard)
		{
			mKeyboard->Unacquire();
			mKeyboard->Release();
			mKeyboard = 0;
		}

		mIsBuffered = buffered;
		Initialize();
	}
}
//----------------------------------------------------------------------------
