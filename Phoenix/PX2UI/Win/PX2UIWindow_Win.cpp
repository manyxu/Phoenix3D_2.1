// PX2UIWindow_Win.hpp

#include "PX2UIWindow_Win.hpp"
<<<<<<< HEAD
#include "PX2UIPaintManager_Win.hpp"
#include "PX2Assert.hpp"
#include "PX2UIPre.hpp"
=======
>>>>>>> d7d7322973c15255a2595ab89885b4ef0270c6ca
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
<<<<<<< HEAD
HWND UIWindow_Win::Create(UIWindow *parent, const std::string &name,
	unsigned long stype, unsigned long exStyle, const Rectf &rect)
{
	return Create(((UIWindow_Win*)parent)->GetHWND(), name.c_str(), 
		stype, exStyle, rect.Left, rect.Top, rect.Width(), rect.Height(), 0);
}
//----------------------------------------------------------------------------
HWND UIWindow_Win::Create(HWND hwndParent, LPCTSTR pstrName, 
	DWORD dwStyle, DWORD dwExStyle, int x, int y, int cx, int cy, HMENU hMenu)
{
	if (0!=GetSuperClassName() && !RegisterSuperclass()) 
		return 0;

	if (0==GetSuperClassName() && !RegisterWindowClass())
		return 0;

	mHWnd = ::CreateWindowEx(dwExStyle, GetWindowClassName(), pstrName, 
		dwStyle, x, y, cx, cy, hwndParent, hMenu, 
		UIPaintManager_Win::GetResourceInstance(), this);

	assertion(0 != mHWnd, "mHWnd must not be null");

	return mHWnd;
}
//----------------------------------------------------------------------------
HWND UIWindow_Win::Subcalss (HWND hWnd)
{
	assertion(TRUE==::IsWindow(hWnd), "must be awindow");
	mOldWndProc = SubclassWindow(hWnd, __WndProc);

	if (0 == mOldWndProc)
		return 0;

	mIsSubclassed = true;
	mHWnd = hWnd;
	
	return mHWnd;
=======
UIWindow *UIWindow_Win::Create(UIWindow *parent, const std::string &name,
	unsigned long stype, unsigned long exStyle, const Rectf &rect)
{

}
//----------------------------------------------------------------------------
UIWindow *UIWindow_Win::Subcalss(UIWindow *window)
{

>>>>>>> d7d7322973c15255a2595ab89885b4ef0270c6ca
}
//----------------------------------------------------------------------------
void UIWindow_Win::UnSubclass()
{
<<<<<<< HEAD
	assertion(::IsWindow(mHWnd), "");

	if (!::IsWindow(mHWnd)) 
		return;

	if (!mIsSubclassed)
		return;

	SubclassWindow(mHWnd, mOldWndProc);

	mOldWndProc = ::DefWindowProc;
	
	mIsSubclassed = false;
}
//----------------------------------------------------------------------------
void UIWindow_Win::ShowWindow(bool show, bool takeFocus)
{
	assertion(TRUE == ::IsWindow(mHWnd), "must be awindow");

	if (!::IsWindow(mHWnd)) return;

	::ShowWindow(mHWnd, show ? (takeFocus ? SW_SHOWNORMAL : SW_SHOWNOACTIVATE) : SW_HIDE);
=======

}
//----------------------------------------------------------------------------
void UIWindow_Win::ShowWindow(bool show = true, bool takeFocus = true)
{

>>>>>>> d7d7322973c15255a2595ab89885b4ef0270c6ca
}
//----------------------------------------------------------------------------
bool UIWindow_Win::ShowModal()
{
<<<<<<< HEAD
	assertion(TRUE == ::IsWindow(mHWnd), "must be awindow");

	HWND hWndParent = GetWindowOwner(mHWnd);

	::ShowWindow(mHWnd, SW_SHOWNORMAL);
	::EnableWindow(hWndParent, FALSE);

	MSG msg = { 0 };
	while (::IsWindow(mHWnd) && ::GetMessage(&msg, NULL, 0, 0))
	{
		if (msg.message == WM_CLOSE) 
		{
			::EnableWindow(hWndParent, TRUE);
			::SetFocus(hWndParent);
		}

		if (!UIPaintManager_Win::TranslateMessage(&msg))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
		}

		if (msg.message == WM_QUIT) 
			break;
	}

	::EnableWindow(hWndParent, TRUE);
	::SetFocus(hWndParent);

	if (msg.message == WM_QUIT) 
		::PostQuitMessage(msg.wParam);
	
	return true;
=======

>>>>>>> d7d7322973c15255a2595ab89885b4ef0270c6ca
}
//----------------------------------------------------------------------------
void UIWindow_Win::Close()
{
<<<<<<< HEAD
	assertion(TRUE == ::IsWindow(mHWnd), "must be awindow");

	if (!::IsWindow(mHWnd)) 
		return;

	PostMessage(WM_CLOSE);
=======

>>>>>>> d7d7322973c15255a2595ab89885b4ef0270c6ca
}
//----------------------------------------------------------------------------
void UIWindow_Win::CenterWindow()
{
<<<<<<< HEAD
	assertion(TRUE == ::IsWindow(mHWnd), "must be awindow");
	assertion((GetWindowStyle(mHWnd)&WS_CHILD)==0, "");

	RECT rcDlg = { 0 };
	::GetWindowRect(mHWnd, &rcDlg);

	RECT rcArea = { 0 };
	RECT rcCenter = { 0 };
	HWND hWndParent = ::GetParent(mHWnd);
	HWND hWndCenter = ::GetWindowOwner(mHWnd);
	::SystemParametersInfo(SPI_GETWORKAREA, NULL, &rcArea, NULL);

	if (hWndCenter == NULL)
		rcCenter = rcArea;
	else
		::GetWindowRect(hWndCenter, &rcCenter);

	int DlgWidth = rcDlg.right - rcDlg.left;
	int DlgHeight = rcDlg.bottom - rcDlg.top;

	// Find dialog's upper left based on rcCenter
	int xLeft = (rcCenter.left + rcCenter.right) / 2 - DlgWidth / 2;
	int yTop = (rcCenter.top + rcCenter.bottom) / 2 - DlgHeight / 2;

	// The dialog is outside the screen, move it inside
	if (xLeft < rcArea.left)
		xLeft = rcArea.left;
	else if (xLeft + DlgWidth > rcArea.right)
		xLeft = rcArea.right - DlgWidth;
	if (yTop < rcArea.top) yTop = 
		rcArea.top;
	else if (yTop + DlgHeight > rcArea.bottom)
		yTop = rcArea.bottom - DlgHeight;

	::SetWindowPos(mHWnd, NULL, xLeft, yTop, -1, -1, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
=======

>>>>>>> d7d7322973c15255a2595ab89885b4ef0270c6ca
}
//----------------------------------------------------------------------------
void UIWindow_Win::SetIcon(unsigned int res)
{
<<<<<<< HEAD
	HICON hIcon = (HICON)::LoadImage(UIPaintManager_Win::GetResourceInstance(), 
		MAKEINTRESOURCE(res), IMAGE_ICON, ::GetSystemMetrics(SM_CXICON), 
		::GetSystemMetrics(SM_CYICON), LR_DEFAULTCOLOR);

	::SendMessage(mHWnd, WM_SETICON, (WPARAM)TRUE, (LPARAM)hIcon);
	hIcon = (HICON)::LoadImage(UIPaintManager_Win::GetResourceInstance(), MAKEINTRESOURCE(res), 
		IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), LR_DEFAULTCOLOR);

	::SendMessage(mHWnd, WM_SETICON, (WPARAM)FALSE, (LPARAM)hIcon);
=======

>>>>>>> d7d7322973c15255a2595ab89885b4ef0270c6ca
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
<<<<<<< HEAD
LRESULT UIWindow_Win::SendMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	ASSERT(::IsWindow(mHWnd));
	return ::SendMessage(mHWnd, uMsg, wParam, lParam);
}
//----------------------------------------------------------------------------
LRESULT UIWindow_Win::PostMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	ASSERT(::IsWindow(mHWnd));
	return ::PostMessage(mHWnd, uMsg, wParam, lParam);
}
//----------------------------------------------------------------------------
=======
>>>>>>> d7d7322973c15255a2595ab89885b4ef0270c6ca
bool UIWindow_Win::RegisterWindowClass()
{
	WNDCLASS wc = { 0 };
	wc.style = GetClassStyle();
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.lpfnWndProc = __WndProc;
<<<<<<< HEAD
	wc.hInstance = UIPaintManager_Win::GetResourceInstance();
=======
	wc.hInstance = CPaintManagerUI::GetResourceInstance();
>>>>>>> d7d7322973c15255a2595ab89885b4ef0270c6ca
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
<<<<<<< HEAD
=======
	// Get the class information from an existing
	// window so we can subclass it later on...
>>>>>>> d7d7322973c15255a2595ab89885b4ef0270c6ca
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(WNDCLASSEX);
	if (!::GetClassInfoEx(NULL, GetSuperClassName(), &wc))
	{
<<<<<<< HEAD
		if (!::GetClassInfoEx(UIPaintManager_Win::GetResourceInstance(), GetSuperClassName(), &wc))
=======
		if (!::GetClassInfoEx(CPaintManagerUI::GetResourceInstance(), GetSuperClassName(), &wc)) 
>>>>>>> d7d7322973c15255a2595ab89885b4ef0270c6ca
		{
			ASSERT(!"Unable to locate window class");
			return NULL;
		}
	}
	mOldWndProc = wc.lpfnWndProc;
	wc.lpfnWndProc = __ControlProc;
<<<<<<< HEAD
	wc.hInstance = UIPaintManager_Win::GetResourceInstance();
	wc.lpszClassName = GetWindowClassName();
	ATOM ret = ::RegisterClassEx(&wc);

	ASSERT(ret != NULL || ::GetLastError() == ERROR_CLASS_ALREADY_EXISTS);

=======
	wc.hInstance = CPaintManagerUI::GetResourceInstance();
	wc.lpszClassName = GetWindowClassName();
	ATOM ret = ::RegisterClassEx(&wc);
	ASSERT(ret != NULL || ::GetLastError() == ERROR_CLASS_ALREADY_EXISTS);
>>>>>>> d7d7322973c15255a2595ab89885b4ef0270c6ca
	return ret != NULL || ::GetLastError() == ERROR_CLASS_ALREADY_EXISTS;
}
//----------------------------------------------------------------------------