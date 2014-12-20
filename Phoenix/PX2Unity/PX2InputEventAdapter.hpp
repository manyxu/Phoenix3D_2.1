/*
*
* 文件名称	：	PX2InputEventHandler.hpp
*
*/

#ifndef PX2INPUTEVENTADAPTER_HPP
#define PX2INPUTEVENTADAPTER_HPP

#include "PX2UnityPre.hpp"
#include "PX2Keyboard.hpp"
#include "PX2Mouse.hpp"
#include "PX2MultiTouch.hpp"
#include "PX2InputManager.hpp"
#include "PX2InputEventListener.hpp"

namespace PX2
{

	class InputEventAdapter : public Singleton<InputEventAdapter>
	{
	public:
		InputEventAdapter ();
		~InputEventAdapter ();

		// 使用此函数添加窗口句柄
		void AddParam (int windowID);

		bool Initlize (); // 如果在编辑器中不需要调用这些
		bool Ternamate (); // 如果在编辑器中不需要调用这些

		void SetSize (float width, float height);
		void SetSize (const Sizef &size);
		const Sizef &GetSize () const;
		void SetWidth (float width);
		float GetWidth ();
		void SetHeight (float height);
		float GetHeight ();

		void SetRect (const Rectf &rect);
		const Rectf &GetRect () const;

		void Convert2Touch (bool convert);
		bool IsConverted2Touch ();

		void Update ();

		InputManager *GetInputManager ();
		Keyboard *GetKeyboard ();
		Mouse *GetMouse ();
		InputEventListener *GetInputEventListener ();

		static void CoordinateToPX2 (Axis &Y, const Sizef &winSize);

	protected:
		Sizef mSize;
		Rectf mRect;
		ParamList mParamList;
		InputManager *mInputManager;
		Keyboard *mKeyboard;
		Mouse *mMouse;
		MultiTouch *mMultiTouch;
		bool mIsConverted2Touch;
		InputEventListener *mEventListener;
	};

#include "PX2InputEventAdapter.inl"

#define PX2_IEA InputEventAdapter::GetSingleton()

}

#endif