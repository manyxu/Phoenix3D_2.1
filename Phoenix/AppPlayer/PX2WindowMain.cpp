// PX2WindowMain.cpp

#include "PX2WindowMain.hpp"
#include "PX2WindowStandard.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
WindowMain::WindowMain()
{
}
//----------------------------------------------------------------------------
WindowMain::~WindowMain()
{
}
//----------------------------------------------------------------------------
void WindowMain::CreateWindows()
{
	UIWindowPtr window = new0 WindowStandard();
	window->Create(0, "1", UIWS_CHILD, Rectf(200.0f, 200.0f, 400.0f, 300.0f));
}
//----------------------------------------------------------------------------