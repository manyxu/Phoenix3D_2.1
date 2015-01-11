/*
*
* ÎÄ¼þÃû³Æ	£º	PX2MainFrame.cpp
*
*/

#include "PX2MainFrame.hpp"
using namespace PX2Editor;
using namespace PX2;

//----------------------------------------------------------------------------
BEGIN_EVENT_TABLE(MainFrame, wxFrame)
END_EVENT_TABLE();
//----------------------------------------------------------------------------
MainFrame::MainFrame(const std::string &title, int xPos, int yPos,
	int width, int height)
	:
	wxFrame(0, -1, title, wxPoint(xPos, yPos), wxSize(width, height), 
	wxSYSTEM_MENU|wxMINIMIZE_BOX|wxMAXIMIZE_BOX|wxCLOSE_BOX|wxCLIP_CHILDREN)
{
}
//----------------------------------------------------------------------------
MainFrame::~MainFrame()
{
}
//----------------------------------------------------------------------------