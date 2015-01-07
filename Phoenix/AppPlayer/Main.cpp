// Main.cpp

#include "PX2UIPre.hpp"
#include "PX2UIWindow_Win.hpp"
#include "PX2UIPaintManager_Win.hpp"
#include <objbase.h>
using namespace PX2;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
	UIPaintManager_Win::SetResourceInstance(hInstance);

	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr)) return 0;

	UIWindow_Win* pFrame = new UIWindow_Win();
	if (pFrame == NULL) return 0;
	pFrame->Create(NULL, _T("Test123"), (WS_VISIBLE | WS_OVERLAPPEDWINDOW), WS_EX_WINDOWEDGE,
		0, 0, 800, 600, 0);

	UIPaintManager_Win::MessageLoop();

	::CoUninitialize();
	return 0;
}