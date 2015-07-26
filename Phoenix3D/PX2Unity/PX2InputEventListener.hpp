// PX2InputEventListener.hpp

#ifndef PX2INPUTEVENTLISTENER_HPP
#define PX2INPUTEVENTLISTENER_HPP

#include "PX2UnityPre.hpp"
#include "PX2InputEventData.hpp"

namespace PX2
{

	class PX2_UNITY_ITEM InputEventListener
	{
	public:
		InputEventListener(int viewID);
		~InputEventListener();

		void OnInputEventData(InputEventData &data);

	protected:
		int mViewID;

		// all
	public:
		virtual void EnterView();
		virtual void LevelView();

		//  pc
	public:
		virtual void KeyPressed(KeyCode code);
		virtual void KeyReleased(KeyCode code);

		virtual void MouseMoved(const APoint &pos);
		virtual void MousePressed(MouseButtonID id, const APoint &pos);
		virtual void MouseDoublePressed(MouseButtonID id, const APoint &pos);
		virtual void MouseReleased(MouseButtonID id, const APoint &pos);
		virtual void MouseWheeled(float val);

		// android 
	public:
		void TouchMoved(int num, int ids[], float xs[], float ys[]);
		void TouchPressed(int num, int ids[], float xs[], float ys[]);
		void TouchReleased(int num, int ids[], float xs[], float ys[]);
		void TouchCancelled(int num, int ids[], float xs[], float ys[]);
		void KeypadMsg(bool back, bool menu);

	protected:
		void _OnTouchData(InputEventData &data, int num, int ids[], float xs[],
			float ys[]);
	};
	typedef Pointer0<InputEventListener> InputEventListenerPtr;

}

#endif