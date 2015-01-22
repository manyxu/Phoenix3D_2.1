/*
*
* ÎÄ¼þÃû³Æ	£º	PX2PhoneInputManager.hpp
*
*/

#ifndef PX2PHONEINPUTMANAGER_HPP
#define PX2PHONEINPUTMANAGER_HPP

#include "PX2InputPre.hpp"
#include "PX2InputManager.hpp"

namespace PX2
{

	class PhoneInputManager : public InputManager, public FactoryCreator
	{
	public:
		PhoneInputManager();
		virtual ~PhoneInputManager();

		virtual DeviceList GetFreeDeviceList();
		virtual int GetNumDevices(InputType type);
		virtual int GetNumFreeDevices (InputType type);
		virtual bool IsVendorExist(InputType type, const std::string &vendor);
		virtual InputObject* CreateObject(InputManager* creator, InputType type,
			bool bufferMode, const std::string &vendor="");
		virtual void DestroyObject (InputObject *obj);

		void SetMultiTouchUsed (bool used);

	protected:
		virtual void Initialize (ParamList &paramList);

		bool mIsMuliTouchUsed;
	};

#include "PX2PhoneInputManager.inl"

}

#endif