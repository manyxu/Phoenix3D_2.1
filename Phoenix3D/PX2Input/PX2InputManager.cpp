/*
*
* ÎÄ¼þÃû³Æ	£º	PX2InputManager.cpp
*
*/

#include "PX2InputManager.hpp"
#include "PX2Memory.hpp"

#if defined(_WIN32) || defined(WIN32)
#include "PX2Win32InputManager.hpp"
#elif defined (__ANDROID__) || defined(__MARMALADE__)
#include "PX2PhoneInputManager.hpp"
#endif

using namespace PX2;
using namespace std;

//----------------------------------------------------------------------------
InputManager::InputManager(const std::string &name) 
	:
mInputSystemName(name)
{
	mFactories.clear();
	mFactoryObjects.clear();
}
//----------------------------------------------------------------------------
InputManager::~InputManager()
{
}
//----------------------------------------------------------------------------
InputManager* InputManager::CreateInputSystem (std::size_t windowhandle)
{
	ParamList pl;

	std::ostringstream wnd;
	wnd << windowhandle;
	pl.insert(std::make_pair(std::string("Window"), wnd.str()));

	return CreateInputSystem(pl);
}
//----------------------------------------------------------------------------
InputManager* InputManager::CreateInputSystem (ParamList &paramList)
{
	InputManager* im = 0;

#if defined(_WIN32) || defined(WIN32)
	im = new0 Win32InputManager();
#elif defined (__ANDROID__) || defined(__MARMALADE__)
	im = new0 PhoneInputManager();
#endif

	if (im)
	{
		im->Initialize(paramList);
	}

	return im;
}
//----------------------------------------------------------------------------
void InputManager::DestroyInputSystem (InputManager* manager)
{
	if (0 == manager)
		return;

	FactoryCreatedObject::iterator it = manager->mFactoryObjects.begin();
	for (; it != manager->mFactoryObjects.end(); it++)
	{
		it->second->DestroyObject(it->first);
	}

	manager->mFactoryObjects.clear();
	delete0(manager);
}
//----------------------------------------------------------------------------
int InputManager::GetNumberOfDevices (InputType type)
{
	int numFactoyObjects = 0;
	FactoryList::iterator it = mFactories.begin();
	for (; it!=mFactories.end(); it++)
	{
		numFactoyObjects += (*it)->GetNumDevices(type);
	}

	return numFactoyObjects;
}
//----------------------------------------------------------------------------
DeviceList InputManager::GetFreeDevicesList()
{
	DeviceList list;
	FactoryList::iterator it = mFactories.begin();
	for (; it!=mFactories.end(); it++)
	{
		DeviceList listTemp = (*it)->GetFreeDeviceList();
		list.insert(listTemp.begin(), listTemp.end());
	}

	return list;
}
//----------------------------------------------------------------------------
InputObject* InputManager::CreateInputObject (InputType type, bool bufferMode,
	const std::string &vendor)
{
	InputObject* obj = 0;
	FactoryList::iterator it=mFactories.begin();
	for (; it!=mFactories.end(); it++)
	{
		if ((*it)->GetNumFreeDevices(type) > 0)
		{
			if (""==vendor || (*it)->IsVendorExist(type, vendor))
			{
				obj = (*it)->CreateObject(this, type, bufferMode, vendor);
				mFactoryObjects[obj] = (*it);
				break;
			}
		}
	}

	if (obj)
	{
		obj->Initialize();
	}

	return obj;
}

//----------------------------------------------------------------------------
void InputManager::DestroyInputObject (InputObject *obj)
{
	if (0 == obj)
		return;

	FactoryCreatedObject::iterator it = mFactoryObjects.find(obj);
	if (it!= mFactoryObjects.end())
	{
		it->second->DestroyObject(obj);
		mFactoryObjects.erase(it);
	}
}
//----------------------------------------------------------------------------
void InputManager::AddFactoryCreator (FactoryCreator *factory)
{
	if(factory)
	{
		mFactories.push_back(factory);
	}
}
//----------------------------------------------------------------------------
void InputManager::RemoveFactoryCreator (FactoryCreator *factory)
{
	if (factory)
	{
		FactoryCreatedObject::iterator it = mFactoryObjects.begin();
		for (; it!=mFactoryObjects.end();)
		{
			if (factory == it->second)
			{
				it->second->DestroyObject(it->first);
				FactoryCreatedObject::iterator itTemp = it;
				it++;
				mFactoryObjects.erase(itTemp);
			}
			else
			{
				it++;
			}
		}

		FactoryList::iterator fact = std::find(mFactories.begin(), 
			mFactories.end(), factory);
		if (fact != mFactories.end())
		{
			mFactories.erase(fact);
		}
	}
}
//----------------------------------------------------------------------------