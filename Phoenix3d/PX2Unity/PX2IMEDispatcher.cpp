/*
*
* ÎÄ¼þÃû³Æ	£º	PX2IMEDispatcher.hpp
*
*/

#include "PX2IMEDispatcher.hpp"
#include "PX2JNI.hpp"
#include "PX2StringHelp.hpp"
using namespace PX2;

#ifdef __MARMALADE__
#include "s3e.h"
#include "s3eOSReadString.h"


static int32 CharInputHandler(void* sys, void*)
{
	s3eKeyboardCharEvent * event = (s3eKeyboardCharEvent*)sys;
	if(event->m_Char == 8)
	{
		IMEDispatcher::GetSingleton().DispathDeleteBackward();
	}
	if(event->m_Char < ' ') return 0;

	char dest[32];
	int length = StringHelp::UnicodeToUTF8(dest, sizeof(dest), &event->m_Char, 1);
	IMEDispatcher::GetSingleton().DispathInsertText(dest, length);
    return 0;
}

static int32 KeyInputHandler(void* sys, void*)
{
	s3eKeyboardEvent * event = (s3eKeyboardEvent*)sys;

	if(!event->m_Pressed)
	{
		if(event->m_Key == s3eKeyBackspace)
		{
			IMEDispatcher::GetSingleton().DispathDeleteBackward();
		}
	}
	return 0;
}
#endif

//----------------------------------------------------------------------------
// IMEDispatcher::Impl
//----------------------------------------------------------------------------
IMEDispatcher::Impl::Impl ()
	:
mDelegateWithIME(0)
{
}
//----------------------------------------------------------------------------
IMEDispatcher::Impl::~Impl ()
{
}
//----------------------------------------------------------------------------
IMEDispatcher::DelegateIter IMEDispatcher::Impl::FindDelegate (
	IMEDelegate *delegate)
{
	DelegateIter it = mDelegateList.begin();
	for (; it!=mDelegateList.end(); ++it)
	{
		if (delegate == *it)
			return it;
	}

	return mDelegateList.end();
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// IMEDispatcher
//----------------------------------------------------------------------------
IMEDispatcher::IMEDispatcher ()
{
	mImpl = new0 IMEDispatcher::Impl();

#ifdef __MARMALADE__
//	s3eKeyboardRegister(S3E_KEYBOARD_KEY_EVENT, KeyInputHandler, NULL);
//	s3eKeyboardRegister(S3E_KEYBOARD_CHAR_EVENT, CharInputHandler, NULL);
#endif
}
//----------------------------------------------------------------------------
IMEDispatcher::~IMEDispatcher ()
{
	delete0(mImpl);
}

void IMEDispatcher::Update()
{/*
	while(1)
	{
		s3eWChar wc = s3eKeyboardGetChar();
		if(wc == S3E_WEOF) break;

		char dest[32];
		int length = StringHelp::UnicodeToUTF8(dest, sizeof(dest), &wc, 1);
		IMEDispatcher::GetSingleton().DispathInsertText(dest, length);
	}*/
}

//----------------------------------------------------------------------------
void IMEDispatcher::SetKeyboardState (bool open)
{
#if defined(__ANDROID__)
	SetKeyboardStateJNI(open? 1 : 0);
#elif defined(__MARMALADE__)
	//s3eKeyboardSetInt(S3E_KEYBOARD_GET_CHAR, open?1:0);
	
	if(open && s3eOSReadStringAvailable() == S3E_TRUE)
	{
		const char *pstr = s3eOSReadStringUTF8("", 0);
		if(pstr) DispathInsertText(pstr, strlen(pstr));
	}
#else
	PX2_UNUSED(open);
#endif
}
//----------------------------------------------------------------------------
void IMEDispatcher::DispathInsertText (const char *text, int length)
{
	if (!mImpl || !text || length<=0)
		return;

	if (!mImpl->mDelegateWithIME)
		return;

	mImpl->mDelegateWithIME->InsertText(text, length);
}
//----------------------------------------------------------------------------
void IMEDispatcher::DispathDeleteBackward ()
{
	if (!mImpl)
		return;

	if (!mImpl->mDelegateWithIME)
		return;

	mImpl->mDelegateWithIME->DeleteBackward();
}
//----------------------------------------------------------------------------
const char *IMEDispatcher::GetContentText () const
{
	if (mImpl && mImpl->mDelegateWithIME)
	{
		return mImpl->mDelegateWithIME->GetContentText();
	}

	return mEmptyString.c_str();
}
//----------------------------------------------------------------------------
void IMEDispatcher::DispatchKeyboardWillShow (IMEKeyboardNotificationInfo &info)
{
	if (!mImpl)
		return;

	DelegateIter it = mImpl->mDelegateList.begin();
	for (; it!=mImpl->mDelegateList.end(); it++)
	{
		if (*it)
		{
			(*it)->KeyboardWillShow(info);
		}
	}
}
//----------------------------------------------------------------------------
void IMEDispatcher::DispatchKeyboardDidShow (IMEKeyboardNotificationInfo &info)
{
	if (!mImpl)
		return;

	DelegateIter it = mImpl->mDelegateList.begin();
	for (; it!=mImpl->mDelegateList.end(); it++)
	{
		if (*it)
		{
			(*it)->KeyboardDidShow(info);
		}
	}
}
//----------------------------------------------------------------------------
void IMEDispatcher::DispatchKeyboardWillHide (IMEKeyboardNotificationInfo &info)
{
	if (!mImpl)
		return;

	DelegateIter it = mImpl->mDelegateList.begin();
	for (; it!=mImpl->mDelegateList.end(); it++)
	{
		if (*it)
		{
			(*it)->KeyboardWillHide(info);
		}
	}
}
//----------------------------------------------------------------------------
void IMEDispatcher::DispatchKeyboardDidHide (IMEKeyboardNotificationInfo &info)
{
	if (!mImpl)
		return;

	DelegateIter it = mImpl->mDelegateList.begin();
	for (; it!=mImpl->mDelegateList.end(); it++)
	{
		if (*it)
		{
			(*it)->KeyboardDidHide(info);
		}
	}
}
//----------------------------------------------------------------------------
void IMEDispatcher::AddDelegate (IMEDelegate *delegate)
{
	if (!delegate || !mImpl)
		return;

	if (mImpl->mDelegateList.end() != mImpl->FindDelegate(delegate))
		return;

	mImpl->mDelegateList.push_front(delegate);
}
//----------------------------------------------------------------------------
bool IMEDispatcher::AttachDelegateWithIME (IMEDelegate *delegate)
{
	if (!mImpl || !delegate)
		return false;

	DelegateIter end = mImpl->mDelegateList.end();
	DelegateIter iter = mImpl->FindDelegate(delegate);

	if (end == iter)
		return false;

	if (mImpl->mDelegateWithIME)
	{
		if (!mImpl->mDelegateWithIME->CanAttachWithIME() ||
			!mImpl->mDelegateWithIME->CanDetachWidthIME())
			return false;

		mImpl->mDelegateWithIME->DidDetachWidthIME();
		mImpl->mDelegateWithIME = 0;
	}

	if (delegate->CanAttachWithIME())
	{
		mImpl->mDelegateWithIME = *iter;
		delegate->DidAttachWidhIME();

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool IMEDispatcher::DetachDelegateWithIME (IMEDelegate *delegate)
{
	if (!mImpl || !delegate)
		return false;

	if (mImpl->mDelegateWithIME != delegate)
		return false;

	if (!delegate->CanDetachWidthIME())
		return false;
	
	delegate->DidDetachWidthIME();
	mImpl->mDelegateWithIME = 0;

	return true;
}
//----------------------------------------------------------------------------
void IMEDispatcher::RemoveDelegate (IMEDelegate *delegate)
{
	if (!delegate || !mImpl)
		return;

	DelegateIter it = mImpl->FindDelegate(delegate);
	DelegateIter end = mImpl->mDelegateList.end();

	if (it == end)
		return;

	if (mImpl->mDelegateWithIME)
	{
		if (*it == mImpl->mDelegateWithIME)
		{
			mImpl->mDelegateWithIME = 0;
		}

		mImpl->mDelegateList.erase(it);
	}
}
//----------------------------------------------------------------------------