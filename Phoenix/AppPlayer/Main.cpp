// Main.cpp

#include "PX2UIPre.hpp"
#include "PX2UIWindow.hpp"
#include "PX2UIPaintManager_Win.hpp"
#include <objbase.h>
using namespace PX2;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
	PX2::Memory::Initialize();

	UIPaintManager_Win::SetResourceInstance(hInstance);

	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr)) return 0;

	UIWindow* pFrame = new UIWindow();
	if (pFrame == NULL) return 0;
	pFrame->Create(0, _T("Test123"), UIWS_FRAME, Rectf(0.0f, 0.0f, 800.0f, 600.0f));

	UIPaintManager_Win::MessageLoop();

	::CoUninitialize();

	PX2::Memory::Terminate("abc.text", false);

	return 0;
}