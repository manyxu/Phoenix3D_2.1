// PX2UIWindow_Win.hpp

#include "PX2UIWindowImpl_Win.hpp"
#include "PX2UIPaintManager_Win.hpp"
#include "PX2Assert.hpp"
#include "PX2UIPre.hpp"
#include "PX2UIDefine.hpp"
#include "PX2UIMapping_Win.hpp"
#include "PX2UIWindow.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
UIWindowImpl_Win::UIWindowImpl_Win(UIWindow *window) :
UIWindowImpl(window),
mHWnd(0),
mOldWndProc(::DefWindowProc)
{

}
//----------------------------------------------------------------------------
UIWindowImpl_Win::UIWindowImpl_Win() :
mHWnd(0),
mOldWndProc(::DefWindowProc)
{
}
//----------------------------------------------------------------------------
UIWindowImpl_Win::~UIWindowImpl_Win()
{
}
//----------------------------------------------------------------------------
HWND UIWindowImpl_Win::GetHWND() const
{
	return mHWnd;
}
//----------------------------------------------------------------------------
UIWindowImpl *UIWindowImpl_Win::Create(UIWindowImpl *parent, const std::string &name,
	UIWindowStyle style, const Rectf &rect)
{
	HWND parHWnd = 0;
	if (parent)
	{
		parHWnd = ((UIWindowImpl_Win*)parent)->GetHWND();
	}

	Create(parHWnd, name.c_str(), gUIWindowStype[style], 0,
		(int)rect.Left, (int)rect.Top, (int)rect.Width(), (int)rect.Height(), 
		0);

	return this;
}
//----------------------------------------------------------------------------
HWND UIWindowImpl_Win::Create(HWND hwndParent, LPCTSTR pstrName, 
	DWORD dwStyle, DWORD dwExStyle, int x, int y, int cx, int cy, HMENU hMenu)
{
	if (GetSuperClassName() != NULL && !RegisterSuperclass()) return NULL;
	if (GetSuperClassName() == NULL && !RegisterWindowClass()) return NULL;

	HINSTANCE hInst = ((UIPaintManager_Win*)UIPaintManager::GetSingletonPtr())
		->GetResourceInstance();

	mHWnd = ::CreateWindowEx(dwExStyle, GetClassName().c_str(), pstrName, 
		dwStyle, x, y, cx, cy, hwndParent, hMenu, 
		hInst, this);

	assertion(0 != mHWnd, "mHWnd must not be null");

	return mHWnd;
}
//----------------------------------------------------------------------------
HWND UIWindowImpl_Win::Subcalss(HWND hWnd)
{
	assertion(TRUE == ::IsWindow(hWnd), "must be awindow");
	mOldWndProc = SubclassWindow(hWnd, __WndProc);

	if (0 == mOldWndProc)
		return 0;

	mIsSubclassed = true;
	mHWnd = hWnd;

	return mHWnd;
}
//----------------------------------------------------------------------------
void UIWindowImpl_Win::UnSubclass()
{
	assertion(TRUE==::IsWindow(mHWnd), "");

	if (!::IsWindow(mHWnd)) 
		return;

	if (!mIsSubclassed)
		return;

	SubclassWindow(mHWnd, mOldWndProc);

	mOldWndProc = ::DefWindowProc;
	
	mIsSubclassed = false;
}
//----------------------------------------------------------------------------
void UIWindowImpl_Win::ShowWindow(bool show, bool takeFocus)
{
	assertion(TRUE == ::IsWindow(mHWnd), "must be awindow");

	if (!::IsWindow(mHWnd)) return;

	::ShowWindow(mHWnd, show ? (takeFocus ? SW_SHOWNORMAL : SW_SHOWNOACTIVATE) : SW_HIDE);
}
//----------------------------------------------------------------------------
bool UIWindowImpl_Win::ShowModal()
{
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
}
//----------------------------------------------------------------------------
void UIWindowImpl_Win::Close()
{
	assertion(TRUE == ::IsWindow(mHWnd), "must be awindow");

	if (!::IsWindow(mHWnd)) 
		return;

	PostMessage(WM_CLOSE);
}
//----------------------------------------------------------------------------
void UIWindowImpl_Win::CenterWindow()
{
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
}
//----------------------------------------------------------------------------
void UIWindowImpl_Win::SetIcon(unsigned int res)
{
	HINSTANCE hInst = ((UIPaintManager_Win*)UIPaintManager::GetSingletonPtr())
		->GetResourceInstance();

	HICON hIcon = (HICON)::LoadImage(hInst,
		MAKEINTRESOURCE(res), IMAGE_ICON, ::GetSystemMetrics(SM_CXICON), 
		::GetSystemMetrics(SM_CYICON), LR_DEFAULTCOLOR);

	::SendMessage(mHWnd, WM_SETICON, (WPARAM)TRUE, (LPARAM)hIcon);
	hIcon = (HICON)::LoadImage(hInst, MAKEINTRESOURCE(res),
		IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), LR_DEFAULTCOLOR);

	::SendMessage(mHWnd, WM_SETICON, (WPARAM)FALSE, (LPARAM)hIcon);
}
//----------------------------------------------------------------------------
LPCTSTR UIWindowImpl_Win::GetSuperClassName() const
{
	return 0;
}
//----------------------------------------------------------------------------
LRESULT UIWindowImpl_Win::SendMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	ASSERT(::IsWindow(mHWnd));
	return ::SendMessage(mHWnd, uMsg, wParam, lParam);
}
//----------------------------------------------------------------------------
LRESULT UIWindowImpl_Win::PostMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	ASSERT(::IsWindow(mHWnd));
	return ::PostMessage(mHWnd, uMsg, wParam, lParam);
}
//----------------------------------------------------------------------------
bool UIWindowImpl_Win::RegisterWindowClass()
{
	HINSTANCE hInst = ((UIPaintManager_Win*)UIPaintManager::GetSingletonPtr())
		->GetResourceInstance();

	WNDCLASS wc = { 0 };
	wc.style = gUIClassStype[mClassType];
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.lpfnWndProc = UIWindowImpl_Win::__WndProc;
	wc.hInstance = hInst;
	wc.hCursor = ::LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = NULL;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = GetClassName().c_str();
	ATOM ret = ::RegisterClass(&wc);
	ASSERT(ret != NULL || ::GetLastError() == ERROR_CLASS_ALREADY_EXISTS);
	return ret != NULL || ::GetLastError() == ERROR_CLASS_ALREADY_EXISTS;
}
//----------------------------------------------------------------------------
bool UIWindowImpl_Win::RegisterSuperclass()
{
	HINSTANCE hInst = ((UIPaintManager_Win*)UIPaintManager::GetSingletonPtr())
		->GetResourceInstance();

	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(WNDCLASSEX);
	if (!::GetClassInfoEx(NULL, GetSuperClassName(), &wc))
	{
		if (!::GetClassInfoEx(hInst, GetSuperClassName(), &wc))
		{
			ASSERT(!"Unable to locate window class");
			return NULL;
		}
	}
	mOldWndProc = wc.lpfnWndProc;
	wc.lpfnWndProc = __ControlProc;
	wc.hInstance = hInst;
	wc.lpszClassName = GetClassName().c_str();
	ATOM ret = ::RegisterClassEx(&wc);

	ASSERT(ret != NULL || ::GetLastError() == ERROR_CLASS_ALREADY_EXISTS);

	return ret != NULL || ::GetLastError() == ERROR_CLASS_ALREADY_EXISTS;
}
//----------------------------------------------------------------------------
LRESULT UIWindowImpl_Win::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_CREATE)
	{
	}
	if (uMsg == WM_DESTROY) 
	{
		::PostQuitMessage(0L);
	}
	if (uMsg == WM_SETFOCUS) 
	{
	}
	if (uMsg == WM_ERASEBKGND)
	{
		return 1;
	}
	if (uMsg == WM_PAINT)
	{
		PAINTSTRUCT ps = { 0 };
		::BeginPaint(mHWnd, &ps);
		::EndPaint(mHWnd, &ps);
		return 0;
	}

	return ::CallWindowProc(mOldWndProc, mHWnd, uMsg, wParam, lParam);
}
//----------------------------------------------------------------------------
void UIWindowImpl_Win::OnFinalMessage(HWND hWnd)
{
	PX2_UNUSED(hWnd);
}
//----------------------------------------------------------------------------
LRESULT CALLBACK UIWindowImpl_Win::__WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	UIWindowImpl_Win* pThis = NULL;
	if (uMsg == WM_NCCREATE)
	{
		LPCREATESTRUCT lpcs = reinterpret_cast<LPCREATESTRUCT>(lParam);
		pThis = static_cast<UIWindowImpl_Win*>(lpcs->lpCreateParams);
		pThis->mHWnd = hWnd;
		::SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LPARAM>(pThis));
	}
	else 
	{
		pThis = reinterpret_cast<UIWindowImpl_Win*>(::GetWindowLongPtr(hWnd, GWLP_USERDATA));
		if (uMsg == WM_NCDESTROY && pThis != NULL) 
		{
			LRESULT lRes = ::CallWindowProc(pThis->mOldWndProc, hWnd, uMsg, wParam, lParam);
			::SetWindowLongPtr(pThis->mHWnd, GWLP_USERDATA, 0L);
			if (pThis->mIsSubclassed) pThis->UnSubclass();
			pThis->mHWnd = 0;
			pThis->OnFinalMessage(hWnd);
			return lRes;
		}
	}
	if (pThis != NULL) 
	{
		return pThis->HandleMessage(uMsg, wParam, lParam);
	}
	else
	{
		return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
}
//----------------------------------------------------------------------------
LRESULT CALLBACK UIWindowImpl_Win::__ControlProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	UIWindowImpl_Win* pThis = NULL;
	if (uMsg == WM_NCCREATE) {
		LPCREATESTRUCT lpcs = reinterpret_cast<LPCREATESTRUCT>(lParam);
		pThis = static_cast<UIWindowImpl_Win*>(lpcs->lpCreateParams);
		::SetProp(hWnd, "WndX", (HANDLE)pThis);
		pThis->mHWnd = hWnd;
	}
	else {
		pThis = reinterpret_cast<UIWindowImpl_Win*>(::GetProp(hWnd, "WndX"));
		if (uMsg == WM_NCDESTROY && pThis != NULL) {
			LRESULT lRes = ::CallWindowProc(pThis->mOldWndProc, hWnd, uMsg, wParam, lParam);
			if (pThis->mIsSubclassed) pThis->UnSubclass();
			::SetProp(hWnd, "WndX", NULL);
			pThis->mHWnd = NULL;
			pThis->OnFinalMessage(hWnd);
			return lRes;
		}
	}
	if (pThis != NULL) 
	{
		return pThis->HandleMessage(uMsg, wParam, lParam);
	}
	else
	{
		return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
}
//----------------------------------------------------------------------------