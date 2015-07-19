// Main.cpp

#include "PX2PlatformUIPre.hpp"
#include "PX2PApplication.hpp"
#include "PX2PWindow.hpp"
#include "PX2EngineLoop.hpp"
#include "PX2Edit.hpp"
#include "PX2EditRenderView_Scene.hpp"
#include <windows.h>
using namespace PX2;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
	PX2_ENGINELOOP.Initlize();

	Edit *edit = new0 Edit();
	edit->Initlize();

	PApplicationPtr app = new0 PApplication();
	app->SetWinInstance(hInstance);

	Sizef size(640.0f, 400.0f);
	PWindowPtr win = new0 PWindow();
	win->Create(0, "PWindow", Vector2f::ZERO, size);
	win->CenterWindow();
	win->Show();
	win->Maximize();

	PWindowPtr win1 = new0 PWindow();
	win1->Create(win, "PWindow", Vector2f::ZERO, size);
	win1->CenterWindow();
	win1->Show();

	PX2_ENGINELOOP.SetPt_Data(win->GetWinHandle());
	PX2_ENGINELOOP.SetPt_Size(size);
	PX2_ENGINELOOP.InitlizeRenderer();

	while (1)
	{
		MSG msg;
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				continue;
			}

			::TranslateMessage(&msg);
			::DispatchMessage(&msg);

		}
		else
		{
			PX2_ENGINELOOP.Tick();
			//OnIdle();
		}
	}

	if (edit)
	{
		edit->Ternamate();
		delete0(edit);
		Edit::Set(0);
	}
	PX2_ENGINELOOP.Ternamate();

	win = 0;
	app = 0;

	Memory::Terminate("MonicaMemoryReport.txt");

	return 0;
}