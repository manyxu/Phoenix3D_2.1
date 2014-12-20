/*
*
* ÎÄ¼þÃû³Æ	£º	PX2PhoneInputManager.cpp
*
*/

#include "PX2PhoneInputManager.hpp"
#include "PX2PhoneMultiTouch.hpp"
#include "PX2Memory.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
PhoneInputManager::PhoneInputManager()
	:
InputManager("PhoneInputManager"),
mIsMuliTouchUsed(false)
{
	mFactories.push_back(this);
}
//----------------------------------------------------------------------------
PhoneInputManager::~PhoneInputManager()
{
}
//----------------------------------------------------------------------------
DeviceList PhoneInputManager::GetFreeDeviceList()
{
	DeviceList ret;

	if (false == mIsMuliTouchUsed)
		ret.insert(std::make_pair(IT_TOUCH, mInputSystemName));

	return ret;
}
//----------------------------------------------------------------------------
int PhoneInputManager::GetNumDevices(InputType type)
{
	switch (type)
	{
	case IT_TOUCH :
		return 1;
	default :
		return 0;
	}

	return 0;
}
//----------------------------------------------------------------------------
int PhoneInputManager::GetNumFreeDevices (InputType type)
{
	switch (type)
	{
	case IT_TOUCH :
		return mIsMuliTouchUsed ? 0 : 1;
	default : 
		return 0;
	}

	return 0;
}
//----------------------------------------------------------------------------
bool PhoneInputManager::IsVendorExist(InputType type, const std::string &vendor)
{
	if((type == IT_TOUCH) && vendor == mInputSystemName )
		return true;

	return false;
}
//----------------------------------------------------------------------------
InputObject* PhoneInputManager::CreateObject(InputManager* creator, 
	InputType type, bool bufferMode, const std::string &vendor)
{	
	PX2_UNUSED(creator);
	PX2_UNUSED(type);
	PX2_UNUSED(bufferMode);
	PX2_UNUSED(vendor);


	InputObject *obj = 0;

	switch (type)
	{
	case IT_TOUCH:
		{
			if (mIsMuliTouchUsed == false )
				obj = new PhoneMultiTouch(this, bufferMode);
			break;
		}
	default:
		break;
	}

	if (obj == 0)
	{
		assertion(false, "No devices match requested type.");
	}

	return obj;
}
//----------------------------------------------------------------------------
void PhoneInputManager::DestroyObject (InputObject *obj)
{
	delete0(obj);
}
//----------------------------------------------------------------------------
void PhoneInputManager::Initialize (ParamList &paramList)
{
	PX2_UNUSED(paramList);
}
//----------------------------------------------------------------------------