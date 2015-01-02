// PX2UIWindow_Win.hpp

#include "PX2UIWindow_Win.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
UIWindow_Win::UIWindow_Win() :
mHWnd(0)
{

}
//----------------------------------------------------------------------------
UIWindow_Win::~UIWindow_Win()
{
}
//----------------------------------------------------------------------------
HWND UIWindow_Win::GetHWND() const
{
	return mHWnd;
}
//----------------------------------------------------------------------------
UIWindow *UIWindow_Win::Create(UIWindow *parent, const std::string &name,
	unsigned long stype, unsigned long exStyle, const Rectf &rect)
{

}
//----------------------------------------------------------------------------
UIWindow *UIWindow_Win::Subcalss(UIWindow *window)
{

}
//----------------------------------------------------------------------------
void UIWindow_Win::UnSubclass()
{

}
//----------------------------------------------------------------------------
void UIWindow_Win::ShowWindow(bool show = true, bool takeFocus = true)
{

}
//----------------------------------------------------------------------------
bool UIWindow_Win::ShowModal()
{

}
//----------------------------------------------------------------------------
void UIWindow_Win::Close()
{

}
//----------------------------------------------------------------------------
void UIWindow_Win::CenterWindow()
{

}
//----------------------------------------------------------------------------
void UIWindow_Win::SetIcon(unsigned int res)
{

}
//----------------------------------------------------------------------------
LPCTSTR UIWindow_Win::GetSuperClassName() const
{
	return 0;
}
//----------------------------------------------------------------------------
unsigned int UIWindow_Win::GetClassStyle() const
{
	return 0;
}
//----------------------------------------------------------------------------
bool UIWindow_Win::RegisterWindowClass()
{
	WNDCLASS wc = { 0 };
	wc.style = GetClassStyle();
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.lpfnWndProc = __WndProc;
	wc.hInstance = CPaintManagerUI::GetResourceInstance();
	wc.hCursor = ::LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = NULL;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = GetWindowClassName();
	ATOM ret = ::RegisterClass(&wc);

	ASSERT(ret != NULL || ::GetLastError() == ERROR_CLASS_ALREADY_EXISTS);

	return ret != NULL || ::GetLastError() == ERROR_CLASS_ALREADY_EXISTS;
}
//----------------------------------------------------------------------------
bool UIWindow_Win::RegisterSuperclass()
{
	// Get the class information from an existing
	// window so we can subclass it later on...
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(WNDCLASSEX);
	if (!::GetClassInfoEx(NULL, GetSuperClassName(), &wc))
	{
		if (!::GetClassInfoEx(CPaintManagerUI::GetResourceInstance(), GetSuperClassName(), &wc)) 
		{
			ASSERT(!"Unable to locate window class");
			return NULL;
		}
	}
	mOldWndProc = wc.lpfnWndProc;
	wc.lpfnWndProc = __ControlProc;
	wc.hInstance = CPaintManagerUI::GetResourceInstance();
	wc.lpszClassName = GetWindowClassName();
	ATOM ret = ::RegisterClassEx(&wc);
	ASSERT(ret != NULL || ::GetLastError() == ERROR_CLASS_ALREADY_EXISTS);
	return ret != NULL || ::GetLastError() == ERROR_CLASS_ALREADY_EXISTS;
}
//----------------------------------------------------------------------------