/*
*
* ÎÄ¼þÃû³Æ	£º	PX2FactoryCreator.hpp
*
*/

#ifndef PX2FACTORYCREATOR_HPP
#define PX2FACTORYCREATOR_HPP

#include "PX2InputDataTypes.hpp"
#include "PX2InputObject.hpp"

namespace PX2
{

	class FactoryCreator
	{
	public:
		virtual ~FactoryCreator() {};
		virtual DeviceList GetFreeDeviceList() = 0;
		virtual int GetNumDevices (InputType type) = 0;
		virtual int GetNumFreeDevices (InputType type) = 0;
		virtual bool IsVendorExist(InputType type,
			const std::string & vendor) = 0;
		virtual InputObject* CreateObject(InputManager* creator, InputType iType,
			bool bufferMode, const std::string &vendor="") = 0;
		virtual void DestroyObject (InputObject *obj) = 0;
	};

	typedef std::vector<FactoryCreator*> FactoryList;
	typedef std::map<InputObject*, FactoryCreator*> FactoryCreatedObject;

}

#endif