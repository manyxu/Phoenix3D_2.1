/*
*
* ÎÄ¼þÃû³Æ	£º	PX2IMEDelegate.hpp
*
*/

#ifndef PX2IMEDELEGATE_HPP
#define PX2IMEDELEGATE_HPP

#include "PX2UnityPre.hpp"
#include "PX2Rect.hpp"
#include "PX2SmartPointer.hpp"

namespace PX2
{

	class IMEKeyboardNotificationInfo
	{
	public:
		IMEKeyboardNotificationInfo ();
		~IMEKeyboardNotificationInfo ();

		Rectf Begin;
		Rectf End;
		float Duration;
	};
	
	class IMEDelegate
	{
	public:
		virtual ~IMEDelegate();

		virtual bool AttachWithIME();
		virtual bool DetachWithIME();

	protected:
		friend class IMEDispatcher;

		IMEDelegate ();

		virtual bool CanAttachWithIME ();
		virtual void DidAttachWidhIME ();
		virtual bool CanDetachWidthIME ();
		virtual void DidDetachWidthIME ();

		virtual void InsertText (const char *text, int length);
		virtual void DeleteBackward ();

		virtual const char *GetContentText () const;

		virtual void KeyboardWillShow (IMEKeyboardNotificationInfo &info);
		virtual void KeyboardDidShow (IMEKeyboardNotificationInfo &info);
		virtual void KeyboardWillHide (IMEKeyboardNotificationInfo &info);
		virtual void KeyboardDidHide (IMEKeyboardNotificationInfo &info);

	private:
		std::string mEmptyStr;
	};
	typedef Pointer0<IMEDelegate> IMEDelegatePtr;

}

#endif