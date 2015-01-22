/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Win32InputManager.hpp
*
*/

#ifndef PX2WIN32INPUTMANAGER_HPP
#define PX2WIN32INPUTMANAGER_HPP

#include "PX2InputManager.hpp"
#include "PX2FactoryCreator.hpp"

namespace PX2
{

	class Win32InputManager : public InputManager, public FactoryCreator
	{
	public:
		Win32InputManager();
		virtual ~Win32InputManager();

		virtual DeviceList GetFreeDeviceList();
		virtual int GetNumDevices(InputType type);
		virtual int GetNumFreeDevices (InputType type);
		virtual bool IsVendorExist(InputType type, const std::string &vendor);
		virtual InputObject* CreateObject(InputManager* creator, InputType iType,
			bool bufferMode, const std::string &vendor="");
		virtual void DestroyObject (InputObject *obj);

		void SetKeyboardUsed (bool used);
		void SetMouseUsed (bool used);
		HWND GetWindowHandle ();

	protected:
		virtual void Initialize (ParamList &paramList);
		void ParseConfigSettings (ParamList &paramList);
		void EnumerateDevices ();
		static BOOL CALLBACK DIEnumDevCallback(LPCDIDEVICEINSTANCE lpddi,
			LPVOID pvRef);

		HWND mhWnd;
		IDirectInput8* mDirectInput;
		DWORD mKeyboardSettings;
		DWORD mMouseSettings;
		bool mIsKeyboardUsed;
		bool mIsMouseUsed;
	};

#include "PX2Win32InputManager.inl"

}

#endif
