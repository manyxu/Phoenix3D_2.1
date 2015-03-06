// PX2UIButtonBase.hpp

#ifndef PX2UIBUTTONBASE_HPP
#define PX2UIBUTTONBASE_HPP

#include "PX2UIPre.hpp"
#include "PX2UIFrame.hpp"
#include "PX2UIPicBox.hpp"
#include "PX2UIText.hpp"

namespace PX2
{

	class UIButtonBase : public UIFrame
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(UIButtonBase);

	public:
		virtual ~UIButtonBase();

		enum ButtonState
		{
			BS_NORMAL,
			BS_HOVERED,
			BS_PRESSED,
			BS_DISABLED,
			BS_MAX_STATE
		};
		virtual void SetButtonState(ButtonState state);
		ButtonState GetButtonState() const;

		void SetPicBox(ButtonState state, UIPicBox *pic);
		UIPicBox *GetPicBoxAtState(ButtonState state);

		virtual void OnSizeChanged();

	protected:
		UIButtonBase();

		UIPicBoxPtr mPicBoxNormal;
		UIPicBoxPtr mPicBoxOver;
		UIPicBoxPtr mPicBoxDown;
		UIPicBoxPtr mPicBoxDisabled;

		ButtonState mButtonState;
	};

	PX2_REGISTER_STREAM(UIButtonBase);
	typedef Pointer0<UIButtonBase> UIButtonBasePtr;
#include "PX2UIButtonBase.inl"

}

#endif