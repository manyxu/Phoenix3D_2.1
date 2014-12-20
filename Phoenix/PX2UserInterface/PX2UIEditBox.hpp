/*
*
* 文件名称	：	PX2UIEditBox.hpp
*
*/

#ifndef PX2UIEDITBOX_HPP
#define PX2UIEDITBOX_HPP

#include "PX2UIFrame.hpp"
#include "PX2UIInputStaticText.hpp"
#include "PX2UIPicBox.hpp"

namespace PX2
{

	class UIEditBox : public UIFrame
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(UIEditBox);

	public:
		UIEditBox ();
		virtual ~UIEditBox ();

		virtual void Enable (bool enable);

		void SetPassword (bool isPassword);
		bool IsPassword () const;

		void SetBackPicBox (UIPicBox *picBox);
		UIPicBox *GetBackPicBox () const;

		void SetFadePicBox (UIPicBox *picBox);
		UIPicBox *GetFadePicBox () const;

		void SetSize (float width, float height);
		void SetSize (const Sizef &size);
		float GetWidth () const;
		float GetHeight () const;
		const Sizef &GetSize () const;

		void SetText (const std::string &text);
		const std::string &GetText () const;
		const std::string &GetRealText () const;

		void SetFixedWidth (float fixedWidth);
		float GetFixedWidth () const;

		virtual void OnAttachWithIME ();
		virtual void OnDetachWithIME ();
		virtual void OnTextChanged ();
		virtual void OnEnter (); // 回车

	public_internal:
		virtual void OnChildPicked (int info, Movable *child);
		virtual void OnNotPicked (int pickInfo);

	protected:
		UIInputStaticTextPtr mInputStaticText;
		UIPicBoxPtr mBackPicBox;
		UIPicBoxPtr mFadePicBox;
		InterpCurveAlphaControllerPtr mFadeCtrl;

		Sizef mSize;

		const float mFadePicBoxStartX;

		float mFixedWidth;
	};

	PX2_REGISTER_STREAM(UIEditBox);
	typedef Pointer0<UIEditBox> UIEditBoxPtr;
	#include "PX2UIEditBox.inl"

}

#endif