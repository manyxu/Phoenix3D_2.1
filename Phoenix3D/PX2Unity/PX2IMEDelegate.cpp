// PX2IMEDelegate.cpp

#include "PX2IMEDelegate.hpp"
#include "PX2IMEDispatcher.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
// IMEKeyboardNotificationInfo
//----------------------------------------------------------------------------
IMEKeyboardNotificationInfo::IMEKeyboardNotificationInfo ()
	:
Duration(0.0f)
{
}
//----------------------------------------------------------------------------
IMEKeyboardNotificationInfo::~IMEKeyboardNotificationInfo ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// IMEDelegate
//----------------------------------------------------------------------------
IMEDelegate::IMEDelegate ()
{
	if (IMEDispatcher::GetSingletonPtr())
		IMEDispatcher::GetSingletonPtr()->AddDelegate(this);
}
//----------------------------------------------------------------------------
IMEDelegate::~IMEDelegate()
{
	if (IMEDispatcher::GetSingletonPtr())
		IMEDispatcher::GetSingletonPtr()->RemoveDelegate(this);
}
//----------------------------------------------------------------------------
bool IMEDelegate::AttachWithIME()
{
	bool rc = IMEDispatcher::GetSingleton().AttachDelegateWithIME(this);

	if (rc)
	{
		IMEDispatcher::GetSingleton().SetKeyboardState(1);
	}

	return rc;
}
//----------------------------------------------------------------------------
bool IMEDelegate::DetachWithIME()
{
	bool rc = IMEDispatcher::GetSingleton().DetachDelegateWithIME(this);

	if (rc)
	{
		IMEDispatcher::GetSingleton().SetKeyboardState(0);
	}

	return rc;
}
//----------------------------------------------------------------------------
bool IMEDelegate::CanAttachWithIME ()
{
	return true;
}
//----------------------------------------------------------------------------
void IMEDelegate::DidAttachWidhIME ()
{
}
//----------------------------------------------------------------------------
bool IMEDelegate::CanDetachWidthIME ()
{
	return true;
}
//----------------------------------------------------------------------------
void IMEDelegate::DidDetachWidthIME ()
{
}
//----------------------------------------------------------------------------
void IMEDelegate::InsertText (const char *text, int length)
{
	PX2_UNUSED(text);
	PX2_UNUSED(length);
}
//----------------------------------------------------------------------------
void IMEDelegate::DeleteBackward ()
{
}
//----------------------------------------------------------------------------
const char *IMEDelegate::GetContentText () const
{
	return mEmptyStr.c_str();
}
//----------------------------------------------------------------------------
void IMEDelegate::KeyboardWillShow (IMEKeyboardNotificationInfo &info)
{
	PX2_UNUSED(info);
}
//----------------------------------------------------------------------------
void IMEDelegate::KeyboardDidShow (IMEKeyboardNotificationInfo &info)
{
	PX2_UNUSED(info);
}
//----------------------------------------------------------------------------
void IMEDelegate::KeyboardWillHide (IMEKeyboardNotificationInfo &info)
{
	PX2_UNUSED(info);
}
//----------------------------------------------------------------------------
void IMEDelegate::KeyboardDidHide (IMEKeyboardNotificationInfo &info)
{
	PX2_UNUSED(info);
}
//----------------------------------------------------------------------------