// PX2InputManager.hpp

#ifndef PX2INPUTMANAGER_HPP
#define PX2INPUTMANAGER_HPP

#include "PX2Singleton_NeedNew.hpp"
#include "PX2InputEventListener.hpp"

namespace PX2
{

	class InputManager : public Singleton<InputManager>
	{
	public:
		InputManager();
		~InputManager();

		InputEventListener *GetDefaultListener();

	protected:
		InputEventListenerPtr mInputEventListener;
	};

#include "PX2InputManager.inl"

#define PX2_INPUTMAN InputManager::GetSingleton()

}

#endif