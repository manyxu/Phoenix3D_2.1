// PX2E_TimeLineRender.cpp

#include "PX2E_TimeLineRender.hpp"
using namespace PX2Editor;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::TimeLineRender, wxWindow)
BEGIN_EVENT_TABLE(TimeLineRender, wxWindow)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
TimeLineRender::TimeLineRender()
{
}
//----------------------------------------------------------------------------
TimeLineRender::TimeLineRender(wxWindow *parent) :
wxWindow(parent, -1)
{
	SetBackgroundColour(wxColour(207, 214, 229));
	//SetBackgroundColour(wxColour(0, 214, 229));
}
//----------------------------------------------------------------------------
TimeLineRender::~TimeLineRender()
{
}
//----------------------------------------------------------------------------