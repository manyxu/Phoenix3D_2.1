// Main.cpp

#include "PX2UIPre.hpp"
#include "PX2UIWindow.hpp"
#include "PX2UIPaintManager.hpp"
#include <objbase.h>
using namespace PX2;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
	PX2::Memory::Initialize();

	UIPaintManager *uiPaintMan = UIPaintManager::Create();
	uiPaintMan->SetPlatformData(hInstance);

	UIWindow* pFrame = new0 UIWindow();
	if (pFrame == NULL) return 0;
	pFrame->Create(0, _T("Test123"), UIWS_FRAME, Rectf(0.0f, 0.0f, 800.0f, 600.0f));

	uiPaintMan->Run();

	delete0(uiPaintMan);

	PX2::Memory::Terminate("abc.text", false);

	return 0;
}