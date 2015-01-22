// Main.cpp

#include "PX2UIPre.hpp"
#include "PX2UIWindow.hpp"
#include "PX2UIPaintManager.hpp"
#include "PX2WindowMain.hpp"
using namespace PX2;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
	PX2::Memory::Initialize();

	UIPaintManager *uiPaintMan = UIPaintManager::Create();
	uiPaintMan->SetPlatformData(hInstance);

	WindowMainPtr winMain = new0 WindowMain();
	winMain->Create(0, "MainWindow", UIWS_FRAME, Rectf(0.0f, 0.0f, 800.0f, 600.0f));
	winMain->CenterWindow();

	WindowMainPtr winMain1 = new0 WindowMain();
	winMain1->Create(winMain, "MainWindow1", UIWS_CHILD, Rectf(0.0f, 0.0f, 800.0f, 600.0f));
	//winMain1->CenterWindow();

	uiPaintMan->Run();

	winMain = 0;
	winMain1 = 0;
	delete0(uiPaintMan);

	PX2::Memory::Terminate("abc.text", false);

	return 0;
}