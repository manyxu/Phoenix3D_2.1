// PX2E_ResShow.cpp

#include "PX2E_ResShow.hpp"
using namespace PX2Editor;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::ResShow, wxWindow)
BEGIN_EVENT_TABLE(ResShow, wxWindow)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
ResShow::ResShow(wxWindow *parent) :
wxWindow(parent, wxID_ANY)
{
	SetBackgroundColour(wxColour(207, 214, 229));
}
//----------------------------------------------------------------------------
ResShow::ResShow()
{
}
//----------------------------------------------------------------------------
ResShow::~ResShow()
{
}
//----------------------------------------------------------------------------