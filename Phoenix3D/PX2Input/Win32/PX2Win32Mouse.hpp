/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Win32Mouse.hpp
*
*/

#ifndef PX2WIN32MOUSE_HPP
#define PX2WIN32MOUSE_HPP

#include "PX2InputPre.hpp"
#include "PX2Mouse.hpp"

namespace PX2
{

	class Win32Mouse : public Mouse
	{
	public:
		Win32Mouse (InputManager* creator, IDirectInput8* directInput8,
			bool buffered, DWORD coopSettings );
		virtual ~Win32Mouse();

		virtual void Initialize();
		virtual void Capture();

	protected:
		bool DoMouseClick( int mouseButton, DIDEVICEOBJECTDATA& di );

		IDirectInput8* mDirectInput;
		IDirectInputDevice8* mMouse;
		DWORD mCoopSetting;
		HWND mHwnd;
	};

}

#endif