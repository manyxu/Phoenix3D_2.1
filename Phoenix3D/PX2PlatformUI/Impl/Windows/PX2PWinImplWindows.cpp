// PX2PWinImplWindow.cpp

#include "PX2PWinImplWindows.hpp"
#include "PX2PApplication.hpp"
#include "PX2PAppImplWindows.hpp"
#include <windowsx.h>
#include <windowsx.h>
#include <commctrl.h>
using namespace PX2;

//----------------------------------------------------------------------------
PWinImplWindows::PWinImplWindows() :
mhWnd(0),
mhDcPaint(0),
mhDcOffscreen(0),
mhDcBackground(0),
mhbmpOffscreen(0),
mhbmpBackground(0),
mhUpdateRectPen(0),
mIsUpdateNeeded(true),
mIsOffScreenPaint(true),
mIsAlphaBackground(false),
mOldWndProc(::DefWindowProc)
{
	mWindowClassName = "PlatformWindow";

	if (mhUpdateRectPen)
	{
		mhUpdateRectPen = ::CreatePen(PS_SOLID, 1, RGB(220, 0, 0));
		::InitCommonControls();
	}
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
	DWORD style = WS_OVERLAPPEDWINDOW;

	if (parent)
		exStyle = 0;

	mhWnd = ::CreateWindowEx(exStyle,
		mWindowClassName.c_str(), tilte.c_str(),
		style,
		(int)pos.X(), (int)pos.Y(), (int)size.Width, (int)size.Height,
		parentHWnd, NULL, instance, this);
}
//----------------------------------------------------------------------------
void *PWinImplWindows::GetWinHandle()
{
	return mhWnd;
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
void PWinImplWindows::CenterWindow()
{
	assertion(TRUE == IsWindow(mhWnd), "must be a window");
	assertion((GetWindowStyle(mhWnd)&WS_CHILD) == 0,
		"must not child window.");

	RECT rcDlg = { 0 };
	::GetWindowRect(mhWnd, &rcDlg);
	RECT rcArea = { 0 };
	RECT rcCenter = { 0 };

	HWND hWnd = mhWnd;

	HWND hWndParent = ::GetParent(mhWnd);
	HWND hWndCenter = ::GetWindowOwner(mhWnd);

	if (hWndCenter != NULL)
		hWnd = hWndCenter;

	MONITORINFO oMonitor = {};
	oMonitor.cbSize = sizeof(oMonitor);
	::GetMonitorInfo(::MonitorFromWindow(hWnd, MONITOR_DEFAULTTONEAREST),
		&oMonitor);
	rcArea = oMonitor.rcWork;

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
	if (yTop < rcArea.top)
		yTop = rcArea.top;
	else if (yTop + DlgHeight > rcArea.bottom)
		yTop = rcArea.bottom - DlgHeight;

	::SetWindowPos(mhWnd, NULL, xLeft, yTop, -1, -1,
		SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
}
//----------------------------------------------------------------------------
void PWinImplWindows::Minimize()
{
	::ShowWindow(mhWnd, SW_MINIMIZE);
}
//----------------------------------------------------------------------------
void PWinImplWindows::Maximize()
{
	::ShowWindow(mhWnd, SW_MAXIMIZE);
}
//----------------------------------------------------------------------------
void PWinImplWindows::Restore()
{
	::ShowWindow(mhWnd, SW_RESTORE);
}
//----------------------------------------------------------------------------
void PWinImplWindows::SetNeedUpdate()
{
	mIsUpdateNeeded = true;
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
LRESULT PWinImplWindows::OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam,
	BOOL& bHandled)
{
	if (::IsIconic(mhWnd))
		bHandled = FALSE;

	return (wParam == 0) ? TRUE : FALSE;
}
//----------------------------------------------------------------------------
LRESULT PWinImplWindows::OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam,
	BOOL& bHandled)
{
	return 0;
}
//----------------------------------------------------------------------------
LRESULT PWinImplWindows::OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam,
	BOOL& bHandled)
{
	return 0;
}
//----------------------------------------------------------------------------
LRESULT PWinImplWindows::OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam,
	BOOL& bHandled)
{
	const Rectf &captionRect = PApplication::GetSingleton().GetCaptionRect();
	const Rectf &cornorRect = PApplication::GetSingleton().GetRoundCorner();

	POINT pt;
	pt.x = GET_X_LPARAM(lParam);
	pt.y = GET_Y_LPARAM(lParam);
	::ScreenToClient(mhWnd, &pt);

	RECT rcClient;
	::GetClientRect(mhWnd, &rcClient);

	// 没有最大化
	if (!::IsZoomed(mhWnd))
	{
		if (pt.y < rcClient.top + cornorRect.Top)
		{
			if (pt.x < rcClient.left + cornorRect.Left)
				return HTTOPLEFT;
			if (pt.x > rcClient.right - cornorRect.Right)
				return HTTOPRIGHT;

			return HTTOP;
		}
		else if (pt.y > rcClient.bottom - cornorRect.Bottom)
		{
			if (pt.x < rcClient.left + cornorRect.Left)
				return HTBOTTOMLEFT;
			if (pt.x > rcClient.right - cornorRect.Right)
				return HTBOTTOMRIGHT;

			return HTBOTTOM;
		}

		if (pt.x < rcClient.left + cornorRect.Left)
			return HTLEFT;

		if (pt.x > rcClient.right - cornorRect.Right)
			return HTRIGHT;
	}

	if (pt.x >= rcClient.left + captionRect.Left &&
		pt.x < rcClient.right - captionRect.Right &&
		pt.y >= captionRect.Top && pt.y < captionRect.Bottom)
	{
		return HTCAPTION;
	}

	return HTCLIENT;
}
//----------------------------------------------------------------------------
LRESULT PWinImplWindows::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LRESULT lRes = 0;
	BOOL bHandled = TRUE;

	switch (uMsg) {
	case WM_NCACTIVATE:    lRes = OnNcActivate(uMsg, wParam, lParam, bHandled); break;
	case WM_NCCALCSIZE:    lRes = OnNcCalcSize(uMsg, wParam, lParam, bHandled); break;
	case WM_NCPAINT:       lRes = OnNcPaint(uMsg, wParam, lParam, bHandled); break;
	case WM_NCHITTEST:     lRes = OnNcHitTest(uMsg, wParam, lParam, bHandled); break;
	default:
		bHandled = FALSE;
	}

	if (bHandled)
		return lRes;

	if (_MessageHandler(uMsg, wParam, lParam, lRes))
	{
		return lRes;
	}

	return ::CallWindowProc(mOldWndProc, mhWnd, uMsg, wParam, lParam);
}
//----------------------------------------------------------------------------
bool PWinImplWindows::_MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam,
	LRESULT& lRes)
{
	switch (uMsg)
	{
	case WM_PAINT: {
					   RECT rcPaint = { 0 };
					   if (!::GetUpdateRect(mhWnd, &rcPaint, FALSE)) return true;
					   //if (m_pRoot == NULL) {
					   //	PAINTSTRUCT ps = { 0 };
					   //	::BeginPaint(m_hWndPaint, &ps);
					   //	::EndPaint(m_hWndPaint, &ps);
					   //	return true;
					   //}

					   //if (mIsUpdateNeeded)
					   {
						   mIsUpdateNeeded = false;

						   RECT rcClient = { 0 };
						   ::GetClientRect(mhWnd, &rcClient);
						   if (!::IsRectEmpty(&rcClient))
						   {
							   //if (m_pRoot->IsUpdateNeeded()) 
							   //{
							   //	m_pRoot->SetPos(rcClient);

							   //	if (mhDcOffscreen != NULL) ::DeleteDC(mhDcOffscreen);
							   //	if (mhDcBackground != NULL) ::DeleteDC(mhDcBackground);
							   //	if (mhbmpOffscreen != NULL) ::DeleteObject(mhbmpOffscreen);
							   //	if (mhbmpBackground != NULL) ::DeleteObject(mhbmpBackground);

							   //	mhDcOffscreen = NULL;
							   //	mhDcBackground = NULL;
							   //	mhbmpOffscreen = NULL;
							   //	mhbmpBackground = NULL;
							   //}
							   //else
							   //{
							   //}
						   }

						   if (mIsOffScreenPaint && mhbmpOffscreen == NULL)
						   {
							   RECT rcClient = { 0 };
							   ::GetClientRect(mhWnd, &rcClient);
							   mhDcOffscreen = ::CreateCompatibleDC(mhDcPaint);
							   mhbmpOffscreen = ::CreateCompatibleBitmap(mhDcPaint,
								   rcClient.right - rcClient.left, rcClient.bottom - rcClient.top);
						   }

						   // Begin Windows paint
						   PAINTSTRUCT ps = { 0 };
						   ::BeginPaint(mhWnd, &ps);
						   if (mIsOffScreenPaint)
						   {
							   HBITMAP hOldBitmap = (HBITMAP) ::SelectObject(mhDcOffscreen, mhbmpOffscreen);
							   int iSaveDC = ::SaveDC(mhDcOffscreen);

							   if (mIsAlphaBackground)
							   {
								   if (mhbmpBackground == NULL)
								   {
									   RECT rcClient = { 0 };
									   ::GetClientRect(mhWnd, &rcClient);
									   mhDcBackground = ::CreateCompatibleDC(mhDcPaint);;
									   mhbmpBackground = ::CreateCompatibleBitmap(mhDcPaint, rcClient.right - rcClient.left, rcClient.bottom - rcClient.top);

									   ::SelectObject(mhDcBackground, mhbmpBackground);
									   ::BitBlt(mhDcBackground, ps.rcPaint.left, ps.rcPaint.top, ps.rcPaint.right - ps.rcPaint.left,
										   ps.rcPaint.bottom - ps.rcPaint.top, ps.hdc, ps.rcPaint.left, ps.rcPaint.top, SRCCOPY);
								   }
								   else
								   {
									   ::SelectObject(mhDcBackground, mhbmpBackground);
								   }

								   ::BitBlt(mhDcOffscreen, ps.rcPaint.left, ps.rcPaint.top, ps.rcPaint.right - ps.rcPaint.left,
									   ps.rcPaint.bottom - ps.rcPaint.top, mhDcBackground, ps.rcPaint.left, ps.rcPaint.top, SRCCOPY);
							   }

							   //m_pRoot->DoPaint(mhDcOffscreen, ps.rcPaint);

							   //for (int i = 0; i < m_aPostPaintControls.GetSize(); i++) {
							   //	CControlUI* pPostPaintControl = static_cast<CControlUI*>(m_aPostPaintControls[i]);
							   //	pPostPaintControl->DoPostPaint(mhDcOffscreen, ps.rcPaint);
							   //}

							   ::RestoreDC(mhDcOffscreen, iSaveDC);
							   ::BitBlt(ps.hdc, ps.rcPaint.left, ps.rcPaint.top, ps.rcPaint.right - ps.rcPaint.left,
								   ps.rcPaint.bottom - ps.rcPaint.top, mhDcOffscreen, ps.rcPaint.left, ps.rcPaint.top, SRCCOPY);
							   ::SelectObject(mhDcOffscreen, hOldBitmap);

							   //if (m_bShowUpdateRect)
							   {
								   HPEN hOldPen = (HPEN)::SelectObject(ps.hdc, mhUpdateRectPen);
								   ::SelectObject(ps.hdc, ::GetStockObject(HOLLOW_BRUSH));
								   ::Rectangle(ps.hdc, rcPaint.left, rcPaint.top, rcPaint.right, rcPaint.bottom);
								   ::SelectObject(ps.hdc, hOldPen);
							   }
						   }
						   else
						   {
							   // A standard paint job
							   int iSaveDC = ::SaveDC(ps.hdc);
							   //m_pRoot->DoPaint(ps.hdc, ps.rcPaint);
							   ::RestoreDC(ps.hdc, iSaveDC);
						   }
						   // All Done!
						   ::EndPaint(mhWnd, &ps);
					   }
					   if (mIsUpdateNeeded)
					   {
						   ::InvalidateRect(mhWnd, NULL, FALSE);
					   }
					   break; }

	default:
		break;
	}

	return false;
}
//----------------------------------------------------------------------------
void PWinImplWindows::OnFinalMessage(HWND hWnd)
{
}
//----------------------------------------------------------------------------