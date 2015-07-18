// PX2PWinImplWindow.cpp

#include "PX2PWinImplWindows.hpp"
#include "PX2PApplication.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
PWinImplWindows::PWinImplWindows() :
mhWnd(0)
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

	mhWnd = ::CreateWindowEx(WS_EX_STATICEDGE | WS_EX_APPWINDOW,
		mWindowClassName.c_str(), tilte.c_str(),
		(WS_VISIBLE | WS_OVERLAPPEDWINDOW),
		(int)pos.X(), (int)pos.Y(), (int)size.Width, (int)size.Height,
		parentHWnd, NULL, instance, this);
}
//----------------------------------------------------------------------------
void PWinImplWindows::Show(bool show)
{
	::ShowWindow(mhWnd, show ? SW_SHOW : SW_HIDE);
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
	//PWinImplWindows* pThis = NULL;
	//if (uMsg == WM_NCCREATE)
	//{
	//	LPCREATESTRUCT lpcs = reinterpret_cast<LPCREATESTRUCT>(lParam);
	//	pThis = static_cast<PWinImplWindows*>(lpcs->lpCreateParams);
	//	pThis->m_hWnd = hWnd;
	//	::SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LPARAM>(pThis));
	//}
	//else 
	//{
	//	pThis = reinterpret_cast<PWinImplWindows*>(::GetWindowLongPtr(hWnd, GWLP_USERDATA));
	//	if (uMsg == WM_NCDESTROY && pThis != NULL) {
	//		LRESULT lRes = ::CallWindowProc(pThis->m_OldWndProc, hWnd, uMsg, wParam, lParam);
	//		::SetWindowLongPtr(pThis->m_hWnd, GWLP_USERDATA, 0L);
	//		if (pThis->m_bSubclassed) pThis->Unsubclass();
	//		pThis->m_hWnd = NULL;
	//		pThis->OnFinalMessage(hWnd);
	//		return lRes;
	//	}
	//}
	//if (pThis != NULL)
	//{
	//	return pThis->HandleMessage(uMsg, wParam, lParam);
	//}
	//else
	//{
		return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
	//}
}
//----------------------------------------------------------------------------