/*
*
* 文件名称	：	PX2InputManager.hpp
*
*/

#ifndef PX2INPUTMANAGER_HPP
#define PX2INPUTMANAGER_HPP

#include "PX2InputPre.hpp"
#include "PX2InputDataTypes.hpp"
#include "PX2InputObject.hpp"
#include "PX2FactoryCreator.hpp"
#include "PX2Size.hpp"
#include "PX2Singleton.hpp"

namespace PX2
{

	class InputManager : public Singleton<InputManager>
	{
	public:
		virtual ~InputManager();

		static InputManager *CreateInputSystem (std::size_t winHandle);
		static InputManager *CreateInputSystem (ParamList &paramList);
		static void DestroyInputSystem (InputManager *manager);

		const std::string &GetInputSystemName();
		int GetNumberOfDevices (InputType type);
		DeviceList GetFreeDevicesList();

		// 如果bufferMode为false，键盘无法接受到按键消息，只能通过
		// Keyboard::IsKeyDown进行实时状态查询
		InputObject *CreateInputObject (InputType type, 
			bool bufferMode, const std::string &vendor="");
		void DestroyInputObject (InputObject *obj);

		void AddFactoryCreator (FactoryCreator* factory);
		void RemoveFactoryCreator (FactoryCreator* factory);

		void SetSize (Sizef size);
		const Sizef &GetSize ();

	protected:
		virtual void Initialize (ParamList &paramList) = 0;

		InputManager(const std::string& name);

		Sizef mSize;
		std::vector<FactoryCreator*> mFactories;
		FactoryCreatedObject mFactoryObjects;
		const std::string mInputSystemName;
	};

#include "PX2InputManager.inl"

}

#endif