/*
*
* ÎÄ¼þÃû³Æ	£º	PX2InputObject.hpp
*
*/

#ifndef PX2INPUTOBJECT_HPP
#define PX2INPUTOBJECT_HPP

#include "PX2InputPre.hpp"

namespace PX2
{

	class InputManager;

	enum InputType
	{
		IT_UNKNOWN,
		IT_MOUSE,
		IT_KEYBOARD,
		IT_TOUCH,
		IT_MULTITOUCH,
		IT_MAX_TYPE
	};

	class InputObject
	{
	public:
		virtual ~InputObject ();

		virtual void Initialize() = 0;	
		virtual void Capture () = 0;

		const std::string &GetVendor() const;
		int GetDevID () const;

		InputType GetInputType ();

		InputManager *GetCreator () const;

		virtual bool IsBuffered () const;

	protected:
		InputObject (const std::string &vendor, InputType type, bool buffered,
			int devID, InputManager *creator);
		
		std::string mVendor;
		int mDevID;
		InputType mInputType;
		bool mIsBuffered;
		InputManager *mCreator;
	};

	typedef std::multimap<InputType, std::string> DeviceList;

	// EventArg
	class EventArg
	{
	public:
		EventArg (InputObject* obj);
		virtual ~EventArg ();

		const InputObject *TheObject;
	};

	#include "PX2InputObject.inl"

}

#endif