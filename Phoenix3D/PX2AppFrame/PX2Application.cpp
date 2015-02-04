/*
*
* 文件名称	：	PX2Application.cpp
*
*/

#include "PX2Application.hpp"
#include "PX2IMEDispatcher.hpp"
#include "PX2EngineLoop.hpp"
#include "PX2InputManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
#if defined(_WIN32) || defined(WIN32)

static std::queue<int> s_isUniChar;
static BYTE s_lobyte;
static BYTE s_hibyte;

#define GET_WHEEL_DELTA_WPARAM(wParam) ((short)HIWORD(wParam))

LRESULT CALLBACK MsWindowEventHandler (HWND handle, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	int sizeX = 0;
	int sizeY = 0;
	static bool firsttime = true;
	static bool isCreated = false;
	float wheeldelta = 0.0f;

	switch (message) 
	{
	case WM_CREATE:
		isCreated = true;
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_SIZE:
		sizeX = LOWORD(lParam);
		sizeY = HIWORD(lParam);

		if (isCreated)
			ApplicationBase::msApplication->OnSize(sizeX, sizeY);

		switch (wParam)
		{
		case SIZE_RESTORED:
			if (ApplicationBase::msApplication->IsInitlized())
				ApplicationBase::msApplication->WillEnterForeground(firsttime);
			firsttime = false;
			break;
		case SIZE_MINIMIZED:
			if (ApplicationBase::msApplication->IsInitlized())
				ApplicationBase::msApplication->DidEnterBackground();
			break;
		}
		break;
	case WM_LBUTTONDOWN:
		if (MK_LBUTTON == wParam)
		{
			POINT point = { (short)LOWORD(lParam), (short)HIWORD(lParam) };

			PX2_INPUTMAN.GetDefaultListener()->MousePressed(MBID_LEFT, 
				APoint((float)point.x, 0.0f, PX2_GR.GetScreenSize().Height-(float)point.y));
		}
		break;
	case WM_LBUTTONUP:

		PX2_INPUTMAN.GetDefaultListener()->MouseReleased(MBID_LEFT,
			APoint((float)LOWORD(lParam), 0.0f, PX2_GR.GetScreenSize().Height - (float)HIWORD(lParam)));

		break;
	case WM_MOUSEWHEEL:
		wheeldelta = (float)GET_WHEEL_DELTA_WPARAM(wParam);
		PX2_INPUTMAN.GetDefaultListener()->MouseWheeled(wheeldelta);
		break;
	case WM_IME_CHAR:	
		if (wParam > 0x7f) 
		{
			s_isUniChar.push(2);
		}
		else 
		{
			s_isUniChar.push(0);
		}
		break;
	case WM_CHAR:
		if (s_isUniChar.empty())
		{
			if (wParam < 0x20)
			{
				if (VK_BACK == wParam)
				{
					IMEDispatcher::GetSingleton().DispathDeleteBackward();
				}
				else if (VK_RETURN == wParam)
				{
					IMEDispatcher::GetSingleton().DispathInsertText("\n", 1);
				}
				else if (VK_TAB == wParam)
				{
					// tab input
				}
				else if (VK_ESCAPE == wParam)
				{
					// ESC input
				}
			}
			else if (wParam < 128)
			{
				IMEDispatcher::GetSingleton().DispathInsertText((const char*)&wParam, 1);
			}
		}
		else
		{
			int& rate = s_isUniChar.front();
			if (rate == 2) 
			{
				--rate;
				s_lobyte = (BYTE)wParam;
				break;
			}
			else if (rate == 1)
			{
				s_isUniChar.pop();
				s_hibyte = (BYTE)wParam;
				DWORD wideChar = MAKEWORD(s_lobyte, s_hibyte);

				wchar_t s_ch[3] = {0};
				int nUTF16Size = ::MultiByteToWideChar(
					CP_ACP,
					0,
					(LPCSTR)&wideChar,
					4,
					s_ch,
					3);
				if (nUTF16Size == 0) 
				{
					return -1;
				}

				int u8Len = ::WideCharToMultiByte(CP_UTF8, 0, s_ch, nUTF16Size, 0, 0, 0, 0);

				char szUtf8[8] = {0};
				int length = WideCharToMultiByte(CP_UTF8, 0, s_ch, nUTF16Size, szUtf8, u8Len, 0, 0);
				PX2_UNUSED(length);
				IMEDispatcher::GetSingleton().DispathInsertText(szUtf8, 3);
			}
			else 
			{
				s_isUniChar.pop();
			}
		}
		break;
	default:
		break;
	}

	return DefWindowProc(handle, message, wParam, lParam);
}
#endif
//----------------------------------------------------------------------------
Application::Application ()
{
#if defined(_WIN32) || defined(WIN32)
	mhWnd = 0;
#endif
}
//----------------------------------------------------------------------------
Application::~Application ()
{
}
//----------------------------------------------------------------------------
int Application::Entry (int numArguments, char** arguments)
{
	Application* theApp = (Application*)msApplication;
	return theApp->Main(numArguments, arguments);
}
//----------------------------------------------------------------------------
#if defined(_WIN32) || defined(WIN32)
int Application::Main (int numArguments, char** arguments)
{
	PX2_UNUSED(numArguments);
	PX2_UNUSED(arguments);

	Initlize ();

	// 显示窗口
	ShowWindow(mhWnd, SW_SHOWNORMAL);
	UpdateWindow(mhWnd);

	// 消息循环
	bool applicationRunning = true;
	while (applicationRunning)
	{
		MSG msg;
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				applicationRunning = false;
				continue;
			}

			HACCEL accel = 0;
			if (!TranslateAccelerator(mhWnd, accel, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

		}
		else
		{
			OnIdle();
		}
	}

	Ternamate ();

	return 0;
}
#endif
//----------------------------------------------------------------------------
bool Application::OnIdle ()
{
	return ApplicationBase::OnIdle();
}
//----------------------------------------------------------------------------
#if defined __ANDROID__
int Application::Main (int numArguments, char** arguments)
{
	return 0;
}
#endif
//----------------------------------------------------------------------------
bool Application::Initlize()
{
	if (msIsInitlized)
		return true;

	PX2_ENGINELOOP.Initlize();

	// Load boost
	PX2_ENGINELOOP.LoadBoost("Data/boost.xml");
	const Sizef &boostSize = PX2_ENGINELOOP.GetBoostSize();
	mWidth = (int)boostSize.Width;
	mHeight = (int)boostSize.Height;
	std::string projectPath = PX2_ENGINELOOP.GetProjectPath();
	PX2_ENGINELOOP.SetPt_Size(boostSize);

#if defined(_WIN32) || defined(WIN32)
	static char sWindowClass[] = "Phoenix2 ApplicationBase";
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = MsWindowEventHandler;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = 0;
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszClassName = sWindowClass;
	wc.lpszMenuName = 0;
	RegisterClass(&wc);

	DWORD dwStyle;
	if (mAllowResize)
	{
		dwStyle = WS_OVERLAPPEDWINDOW;
	}
	else
	{
		dwStyle = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
	}

	// 请求特定客户区大小的窗口大小
	RECT rect = { 0, 0, mWidth - 1, mHeight - 1 };
	AdjustWindowRect(&rect, dwStyle, FALSE);

	// 创建窗口
	mhWnd = CreateWindow(sWindowClass, mWindowTitle.c_str(),
		dwStyle, mXPosition, mYPosition,
		rect.right - rect.left + 1, rect.bottom - rect.top + 1, 0, 0, 0, 0);

	PX2_ENGINELOOP.SetPt_Data(mhWnd);

	// 居中
	RECT rcDesktop, rcWindow;
	GetWindowRect(GetDesktopWindow(), &rcDesktop);

	HWND hTaskBar = FindWindow(TEXT("Shell_TrayWnd"), NULL);
	if (hTaskBar != NULL)
	{
		APPBARDATA abd;

		abd.cbSize = sizeof(APPBARDATA);
		abd.hWnd = hTaskBar;

		SHAppBarMessage(ABM_GETTASKBARPOS, &abd);
		SubtractRect(&rcDesktop, &rcDesktop, &abd.rc);
	}
	GetWindowRect(mhWnd, &rcWindow);
	int offsetX = (rcDesktop.right - rcDesktop.left - (rcWindow.right - rcWindow.left)) / 2;
	offsetX = (offsetX > 0) ? offsetX : rcDesktop.left;
	int offsetY = (rcDesktop.bottom - rcDesktop.top - (rcWindow.bottom - rcWindow.top)) / 2;
	offsetY = (offsetY > 0) ? offsetY : rcDesktop.top;
	SetWindowPos(mhWnd, 0, offsetX, offsetY, 0, 0, SWP_NOCOPYBITS | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER);
	mXPosition = offsetX;
	mYPosition = offsetY;
#endif
	PX2_ENGINELOOP.InitlizeRenderer();
	PX2_ENGINELOOP.SetScreenSize(boostSize);

	// Load Project
	_LoadProject(projectPath);

	msIsInitlized = true;

	return false;
}
//----------------------------------------------------------------------------
bool Application::Ternamate()
{
	return ApplicationBase::Ternamate();
}
//----------------------------------------------------------------------------