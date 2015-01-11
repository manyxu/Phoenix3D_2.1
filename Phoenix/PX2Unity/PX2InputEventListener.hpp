/*
*
* 文件名称	：	PX2InputEventListener.hpp
*
*/

#ifndef PX2INPUTEVENTLISTENER_HPP
#define PX2INPUTEVENTLISTENER_HPP

#include "PX2UnityPre.hpp"
#include "PX2Keyboard.hpp"
#include "PX2Mouse.hpp"
#include "PX2MultiTouch.hpp"
#include "PX2InputEvent.hpp"
#include "PX2InputEventHandler.hpp"

namespace PX2
{
	
	class InputEventListener : public KeyListener, public MouseListener
		, public MultiTouchListener
	{
	public:
		InputEventListener ();
		~InputEventListener ();

		// handlers
		bool HasHandler (InputEventHandler *handler);
		void AddHandler (InputEventHandler *handler);
		void RemoveHandler (InputEventHandler *handler);
		int GetNumHandlers ();
		void RemoveAllHandlers ();

		void OnInputEventData (const InputEventData &data);

public_internal:
		// called in pc
		virtual bool KeyPressed (const KeyEvent &arg);
		virtual bool KeyReleased (const KeyEvent &arg);

		virtual bool MouseMoved (const MouseEvent &arg);
		virtual bool MousePressed (const MouseEvent &arg, MouseButtonID id);
		virtual bool MouseReleased (const MouseEvent &arg, MouseButtonID id);
		virtual bool MouseWheeled (float val);

		// called in android 
		// Phoenix3d\Phoenix2p1\GamePlay\Proj.Android\jni\phoenix3d_px2_library_PX2Natives.cpp
		void TouchMoved (int num, int ids[], float xs[], float ys[]);
		void TouchPressed (int num, int ids[], float xs[], float ys[]);
		void TouchReleased (int num, int ids[], float xs[], float ys[]);
		void TouchCancelled (int num, int ids[], float xs[], float ys[]);
		void KeypadMsg (bool back, bool menu);

		// called in ios
		virtual bool TouchMoved (const MultiTouchEvent &arg);
		virtual bool TouchPressed (const MultiTouchEvent &arg);
		virtual bool TouchReleased (const MultiTouchEvent &arg);
		virtual bool TouchCancelled (const MultiTouchEvent &arg);

	protected:
		std::vector<InputEventHandler*> mHandlers; // 不参与管理Handler的生命
	};

}

#endif