/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIButtonBase.hpp
*
*/

#ifndef PX2UIBUTTONBASE_HPP
#define PX2UIBUTTONBASE_HPP

#include "PX2UIPre.hpp"
#include "PX2UIFrame.hpp"
#include "PX2UIPicBox.hpp"

namespace PX2
{

	class UIButtonBase : public UIFrame
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(UIButtonBase);

	public:
		virtual ~UIButtonBase ();

		enum ButtonState
		{
			BS_NORMAL,
			BS_OVER,
			BS_DOWN,
			BS_DISABLED,
			BS_MAX_STATE 
		};
		virtual void SetButtonState (ButtonState state);
		ButtonState GetButtonState () const;

		void SetPicBox (ButtonState state, UIPicBox *pic);
		UIPicBox *GetPicBoxAtState (ButtonState state);

		void SetSize (float width, float height);
		void SetSize (const Sizef &size);
		const Sizef &GetSize () const;
		void SetWidth (float width);
		float GetWidth ();
		void SetHeight (float height);
		float GetHeight ();

	protected:
		UIButtonBase ();
		void OnSizeChanged ();

		UIPicBoxPtr mPicBoxNormal;
		UIPicBoxPtr mPicBoxOver;
		UIPicBoxPtr mPicBoxDown;
		UIPicBoxPtr mPicBoxDisabled;

		Sizef mSize;
		ButtonState mButtonState;
	};

	PX2_REGISTER_STREAM(UIButtonBase);
	typedef Pointer0<UIButtonBase> UIButtonBasePtr;
#include "PX2UIButtonBase.inl"

}

#endif