/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIInputStaticText.hpp
*
*/

#ifndef PX2UIINPUTSTATICTEXT_HPP
#define PX2UIINPUTSTATICTEXT_HPP

#include "PX2UIStaticText.hpp"
#include "PX2IMEDelegate.hpp"

namespace PX2
{

	class UIInputStaticText;

	enum UIISTCallType
	{
		UIISTCT_ATTACHWITHIME,
		UIISTCT_DETACHWITHWITHIME,
		UIISTCT_INSERTTEXT,
		UIISTCT_DELETEBACKWARD,
		UIISTCT_ENTER,
		UIISTCT_MAX_TYPE
	};
	typedef void (*UIInputStaticTextCallback) (UIInputStaticText *inputText, UIISTCallType type);

	class UIInputStaticText : public UIStaticText , public IMEDelegate
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(UIInputStaticText);

	public:
		UIInputStaticText ();
		virtual ~UIInputStaticText ();

		virtual bool AttachWithIME();
		virtual bool DetachWithIME();

		void SetCallback (UIInputStaticTextCallback callback);
		UIInputStaticTextCallback GetCallback () const;

		void SetRealText (const std::string realText);
		const std::string &GetRealText () const;
		virtual const char *GetContentText () const;

		void SetPassword (bool isPassword);
		bool IsPassword () const;

		void SetFixedWidth (float fixedWidth);
		float GetFixedWidth () const;

		float GetTextWidth () const;

	protected:
		virtual void InsertText (const char *text, int length);
		virtual void DeleteBackward ();

		std::string mInputString;
		UIInputStaticTextCallback mCallback;

		bool mIsPassword;
		std::string mRealText;

		float mFixedWidth;
	};

#include "PX2UIInputStaticText.inl"
	PX2_REGISTER_STREAM(UIInputStaticText);
	typedef Pointer0<UIInputStaticText> UIInputStaticTextPtr;

}

#endif