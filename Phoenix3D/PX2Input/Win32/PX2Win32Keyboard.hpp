/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Win32Keyboard.hpp
*
*/

#ifndef PX2WIN32KEYBOARD_HPP
#define PX2WIN32KEYBOARD_HPP

#include "PX2Keyboard.hpp"

namespace PX2
{

	class Win32Keyboard : public Keyboard
	{
	public:
		Win32Keyboard (InputManager *creator, IDirectInput8 *directInput8,
			bool buffered, DWORD coopSettings);
		virtual ~Win32Keyboard();

		virtual void Initialize();

		virtual bool IsKeyDown (KeyCode key) const;
		virtual const std::string &GetAsString (KeyCode kc);
		virtual void CopyKeyStates (char keys[256]) const;
		virtual void SetBuffered (bool buffered);
		virtual void Capture();

	protected:
		void ReadBuffered ();
		void Read ();
		int TranslateText (KeyCode kc);

		IDirectInput8 *mDirectInput;
		IDirectInputDevice8 *mKeyboard;
		DWORD mCoopSetting;
		unsigned char mKeyBuffer[256];
		WCHAR mDeadKey;
		std::string mGetString;
	};

}

#endif