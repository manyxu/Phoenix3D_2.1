// Main.cpp

#include "PX2PlatformUIPre.hpp"
#include "PX2Memory.hpp"
#include "PX2PApplication.hpp"
#include "PX2PWindow.hpp"
#include <windows.h>
using namespace PX2;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
	Memory::Initialize();

	PApplicationPtr app = new0 PApplication();
	app->SetWinInstance(hInstance);

	PWindowPtr win = new0 PWindow();
	win->Create(0, "PWindow", Vector2f::ZERO, Sizef(640.0f, 400.0f));
	win->Show();

	app->Run();

	win = 0;
	app = 0;

	Memory::Terminate("MonicaMemoryReport.txt");

	return 0;
}