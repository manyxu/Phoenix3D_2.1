/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Win32Mouse.cpp
*
*/

#include "PX2Win32Mouse.hpp"
#include "PX2Win32InputManager.hpp"
#include "PX2Assert.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
Win32Mouse::Win32Mouse (InputManager* creator, IDirectInput8* directInput8, 
	bool buffered, DWORD coopSettings)
	:
Mouse(creator->GetInputSystemName(), buffered, 0, creator),
mMouse(0),
mDirectInput(directInput8),
mCoopSetting(coopSettings),
mHwnd(0)
{
	static_cast<Win32InputManager*>(mCreator)->SetMouseUsed(true);
}
//----------------------------------------------------------------------------
Win32Mouse::~Win32Mouse()
{
	if (mMouse)
	{
		mMouse->Unacquire();
		mMouse->Release();
		mMouse = 0;
	}

	static_cast<Win32InputManager*>(mCreator)->SetMouseUsed(false);
}
//----------------------------------------------------------------------------
void Win32Mouse::Initialize()
{
	mState.Clear();

	DIPROPDWORD dipdw;
	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = MOUSE_DX_BUFFERSIZE;

	if (FAILED(mDirectInput->CreateDevice(GUID_SysMouse, &mMouse, 0)))
	{
		assertion(false, "Failed to create device.");
	}

	if (FAILED(mMouse->SetDataFormat(&c_dfDIMouse2)))
	{
		assertion(false, "Failed to set format");
	}

	mHwnd = ((Win32InputManager*)mCreator)->GetWindowHandle();

	if (FAILED(mMouse->SetCooperativeLevel(mHwnd, mCoopSetting)))
	{
		assertion(false, "Failed to set coop level");
	}

	if (FAILED(mMouse->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph)))
	{
		assertion(false, "Failed to set property");
	}

	HRESULT hr = mMouse->Acquire();
	if (FAILED(hr) && hr != DIERR_OTHERAPPHASPRIO)
	{
		assertion(false, "Failed to aquire mouse!");
	}
}
//----------------------------------------------------------------------------
void Win32Mouse::Capture ()
{
	mState.X.Relative = mState.Y.Relative = mState.Z.Relative = 0;
	const Sizef &winSize = InputManager::GetSingleton().GetSize();

	DIDEVICEOBJECTDATA diBuff[MOUSE_DX_BUFFERSIZE];
	DWORD numBuffers = MOUSE_DX_BUFFERSIZE;

	HRESULT hr = mMouse->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), diBuff,
		&numBuffers, 0);
	if (hr != DI_OK)
	{
		hr = mMouse->Acquire();
		while( hr == DIERR_INPUTLOST ) 
			hr = mMouse->Acquire();

		hr = mMouse->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), diBuff,
			&numBuffers, 0);

		if( FAILED(hr) )
			return;
	}

	bool axesMoved = false;

	for (unsigned int i=0; i<numBuffers; ++i)
	{
		switch (diBuff[i].dwOfs)
		{
		case DIMOFS_BUTTON0:
			if (!DoMouseClick(0, diBuff[i])) return;
			break;
		case DIMOFS_BUTTON1:
			if (!DoMouseClick(1, diBuff[i])) return;
			break;
		case DIMOFS_BUTTON2:
			if (!DoMouseClick(2, diBuff[i])) return;
			break;
		case DIMOFS_BUTTON3:
			if (!DoMouseClick(3, diBuff[i])) return;
			break;
		case DIMOFS_BUTTON4:
			if (!DoMouseClick(4, diBuff[i])) return;
			break;	
		case DIMOFS_BUTTON5:
			if (!DoMouseClick(5, diBuff[i])) return;
			break;
		case DIMOFS_BUTTON6:
			if (!DoMouseClick(6, diBuff[i])) return;
			break;
		case DIMOFS_BUTTON7:
			if (!DoMouseClick(7, diBuff[i])) return;
			break;
		case DIMOFS_X:
			mState.X.Relative += diBuff[i].dwData;
			axesMoved = true;
			break;
		case DIMOFS_Y:
			mState.Y.Relative += diBuff[i].dwData;
			axesMoved = true;
			break;
		case DIMOFS_Z:
			mState.Z.Relative += diBuff[i].dwData;
			axesMoved = true;
			break;
		default: break;
		}
	}

	if (axesMoved)
	{
		if (mCoopSetting & DISCL_NONEXCLUSIVE)
		{
			POINT point;
			GetCursorPos(&point);
			ScreenToClient(mHwnd, &point);
			mState.X.Absoulate = point.x;
			mState.Y.Absoulate = point.y;
		}
		else
		{
			mState.X.Absoulate += mState.X.Relative;
			mState.Y.Absoulate += mState.Y.Relative;
		}
		mState.Z.Absoulate += mState.Z.Relative;

		if( mState.X.Absoulate < 0 )
			mState.X.Absoulate = 0;
		else if( mState.X.Absoulate > winSize.Width )
			mState.X.Absoulate = (int)winSize.Width;
		if( mState.Y.Absoulate < 0 )
			mState.Y.Absoulate = 0;
		else if( mState.Y.Absoulate > winSize.Height )
			mState.Y.Absoulate = (int)winSize.Height;

		// listener
		if (mListener && mIsBuffered)
			mListener->MouseMoved(MouseEvent(this, mState));
	}
}
//----------------------------------------------------------------------------
bool Win32Mouse::DoMouseClick (int mouseButton, DIDEVICEOBJECTDATA &di)
{
	if (di.dwData & 0x80)
	{
		mState.Buttons |= 1 << mouseButton; //turn the bit flag on

		if (mListener && mIsBuffered)
			return mListener->MousePressed(MouseEvent(this, mState), 
			(MouseButtonID)mouseButton);
	}
	else
	{
		mState.Buttons &= ~(1 << mouseButton); //turn the bit flag off

		if( mListener && mIsBuffered )
			return mListener->MouseReleased(MouseEvent(this, mState), 
			(MouseButtonID)mouseButton );
	}

	return true;
}
//----------------------------------------------------------------------------