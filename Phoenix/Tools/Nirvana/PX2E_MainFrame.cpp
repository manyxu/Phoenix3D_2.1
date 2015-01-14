// PX2E_MainFrame.cpp

#include "PX2E_MainFrame.hpp"
#include "PX2EngineLoop.hpp"
using namespace PX2Editor;
using namespace PX2;

//----------------------------------------------------------------------------
E_MainFrame::E_MainFrame(const std::string &title, int xPos, int yPos,
	int width, int height) :
	PX2WXFrame(title, xPos, yPos, width, height)
{
}
//----------------------------------------------------------------------------
E_MainFrame::~E_MainFrame()
{
}
//----------------------------------------------------------------------------
void E_MainFrame::OnTimer_Update()
{
	PX2_ENGINELOOP.Tick();
}
//----------------------------------------------------------------------------