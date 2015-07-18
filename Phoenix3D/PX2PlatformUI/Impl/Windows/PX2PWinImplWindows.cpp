// PX2PWinImplWindow.cpp

#include "PX2PWinImplWindows.hpp"
#include "PX2PApplication.hpp"
#include "PX2PAppImplWindows.hpp"
#include <windowsx.h>
using namespace PX2;

//----------------------------------------------------------------------------
PWinImplWindows::PWinImplWindows() :
mhWnd(0),
mOldWndProc(::DefWindowProc)
{
	mWindowClassName = "PlatformWindow";
}
//----------------------------------------------------------------------------
PWinImplWindows::~PWinImplWindows()
{

}
//----------------------------------------------------------------------------
const std::string &PWinImplWindows::GetSuperClassName() const
{
	return mSuperClassName;
}
//----------------------------------------------------------------------------
const std::string &PWinImplWindows::GetWindowClassName() const
{
	return mWindowClassName;
}
//----------------------------------------------------------------------------
void PWinImplWindows::Create(PWinImpl *parent, const std::string &tilte,
	const Vector2f &pos, const Sizef &size)
{
	HINSTANCE instance = (HINSTANCE)(PApplication::GetSingleton()
		.GetWinInstance());
	
	if (!mSuperClassName.empty() && !_RegisterSuperClass()) return;
	if (mSuperClassName.empty() && !_RegisterWindowClass()) return;

	HWND parentHWnd = NULL;
	if (parent) parentHWnd = ((PWinImplWindows*)parent)->mhWnd;

	DWORD exStyle = WS_EX_STATICEDGE | WS_EX_APPWINDOW;
	DWORD style = WS_VISIBLE | WS_OVERLAPPEDWINDOW;

	if (parent)
		exStyle = 0;

	mhWnd = ::CreateWindowEx(exStyle,
		mWindowClassName.c_str(), tilte.c_str(),
		style,
		(int)pos.X(), (int)pos.Y(), (int)size.Width, (int)size.Height,
		parentHWnd, NULL, instance, this);
}
//----------------------------------------------------------------------------
void PWinImplWindows::Show(bool show, bool takeFocus)
{
	assertion(TRUE == IsWindow(mhWnd), "must be a window");
	::ShowWindow(mhWnd, show ? (takeFocus ? SW_SHOWNORMAL : SW_SHOWNOACTIVATE)
		: SW_HIDE);
}
//----------------------------------------------------------------------------
void PWinImplWindows::ShowModal()
{
	assertion(TRUE == IsWindow(mhWnd), "must be a window");

	UINT nRet = 0;
	HWND hWndParent = GetWindowOwner(mhWnd);
	
	::ShowWindow(mhWnd, SW_SHOWNORMAL);
	::EnableWindow(hWndParent, FALSE);

	MSG msg = { 0 };
	while (::IsWindow(mhWnd) && ::GetMessage(&msg, NULL, 0, 0)) 
	{
		if (msg.message == WM_CLOSE && msg.hwnd == mhWnd)
		{
			nRet = msg.wParam;
			::EnableWindow(hWndParent, TRUE);
			::SetFocus(hWndParent);
		}

		PAppImplWindows *appWindow = (PAppImplWindows*)(
			PApplication::GetSingleton().GetImpl());

		if (!appWindow->_TranslateMessage(&msg))
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

	PX2_UNUSED(nRet);
}
//----------------------------------------------------------------------------
bool PWinImplWindows::_RegisterSuperClass()
{
	return false;
}
//----------------------------------------------------------------------------
bool PWinImplWindows::_RegisterWindowClass()
{
	HINSTANCE instance = (HINSTANCE)(PApplication::GetSingleton()
		.GetWinInstance());
	
	WNDCLASS wc = { 0 };
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.lpfnWndProc = PWinImplWindows::_WndProc;
	wc.hInstance = instance;
	wc.hCursor = ::LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = NULL;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = mWindowClassName.c_str();
	ATOM ret = ::RegisterClass(&wc);

	return ret != NULL || ::GetLastError() == ERROR_CLASS_ALREADY_EXISTS;
}
//----------------------------------------------------------------------------
LRESULT CALLBACK PWinImplWindows::_WndProc(HWND hWnd, UINT uMsg, WPARAM wParam,
	LPARAM lParam)
{
	PWinImplWindows* pThis = NULL;

	if (uMsg == WM_NCCREATE)
	{
		LPCREATESTRUCT lpcs = reinterpret_cast<LPCREATESTRUCT>(lParam);
		pThis = static_cast<PWinImplWindows*>(lpcs->lpCreateParams);
		pThis->mhWnd = hWnd;

		::SetWindowLongPtr(hWnd, GWLP_USERDATA, 
			reinterpret_cast<LPARAM>(pThis));
	}
	else
	{
		pThis = reinterpret_cast<PWinImplWindows*>(::GetWindowLongPtr(hWnd,
			GWLP_USERDATA));

		if (uMsg == WM_NCDESTROY && pThis != NULL)
		{
			LRESULT lRes = ::CallWindowProc(pThis->mOldWndProc, hWnd, uMsg, 
				wParam, lParam);
			::SetWindowLongPtr(pThis->mhWnd, GWLP_USERDATA, 0L);

			pThis->mhWnd = NULL;
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
LRESULT PWinImplWindows::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return ::CallWindowProc(mOldWndProc, mhWnd, uMsg, wParam, lParam);
}
//----------------------------------------------------------------------------
void PWinImplWindows::OnFinalMessage(HWND hWnd)
{
}
//----------------------------------------------------------------------------