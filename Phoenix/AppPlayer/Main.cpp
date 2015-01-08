// Main.cpp

#include "PX2UIPre.hpp"
#include "PX2UIWindow.hpp"
#include "PX2UIPaintManager.hpp"
using namespace PX2;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
	PX2::Memory::Initialize();

	UIPaintManager *uiPaintMan = UIPaintManager::Create();
	uiPaintMan->SetPlatformData(hInstance);

	UIWindowPtr frame = new0 UIWindow();
	frame->Create(0, _T("Test123"), UIWS_FRAME, Rectf(0.0f, 0.0f, 800.0f, 600.0f));

	uiPaintMan->Run();

	frame = 0;
	delete0(uiPaintMan);

	PX2::Memory::Terminate("abc.text", false);

	return 0;
}