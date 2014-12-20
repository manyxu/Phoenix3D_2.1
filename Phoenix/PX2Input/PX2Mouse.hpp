/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Mouse.hpp
*
*/

#ifndef PX2MOUSE_HPP
#define PX2MOUSE_HPP

#include "PX2InputObject.hpp"
#include "PX2InputDataTypes.hpp"
#if defined(_MSC_VER)
#pragma warning(disable : 4512)
#endif

namespace PX2
{

	enum MouseButtonID
	{
		MBID_LEFT = 0,
		MBID_RIGHT,
		MBID_MIDDLE,
		MBID_Button3,
		MBID_Button4,	
		MBID_Button5, 
		MBID_Button6,	
		MBID_Button7
	};

	class MouseState
	{
	public:
		MouseState ();
		~MouseState ();

		bool IsButtonDown (MouseButtonID button) const;
		void Clear ();

		Axis X;
		Axis Y;
		Axis Z;
		int Buttons;
	};

	class MouseEvent : public EventArg
	{
	public:
		MouseEvent (InputObject *obj, const MouseState &ms);
		virtual ~MouseEvent ();

		const MouseState &State;
	};

	class MouseListener
	{
	public:
		virtual ~MouseListener();
		virtual bool MouseMoved (const MouseEvent &arg) = 0;
		virtual bool MousePressed (const MouseEvent &arg, MouseButtonID id) = 0;
		virtual bool MouseReleased (const MouseEvent &arg, MouseButtonID id) = 0;
	};

	class Mouse : public InputObject
	{
	public:
		virtual ~Mouse ();

		virtual void SetEventCallback (MouseListener *listener);
		MouseListener *GetEventCallback() const;

		const MouseState &GetMouseState () const;

	protected:
		Mouse (const std::string &vendor, bool buffered, int devID, 
			InputManager *creator);

		MouseState mState;
		MouseListener *mListener;
	};

#include "PX2Mouse.inl"

}

#endif