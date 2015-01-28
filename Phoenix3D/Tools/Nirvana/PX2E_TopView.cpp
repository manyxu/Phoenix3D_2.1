// PX2E_TopView.cpp

#include "PX2E_TopView.hpp"
using namespace PX2Editor;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::TopView, wxWindow)
BEGIN_EVENT_TABLE(TopView, wxWindow)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
TopView::TopView()
{
}
//----------------------------------------------------------------------------
TopView::TopView(wxWindow *parent) :
wxWindow(parent, -1)
{
	SetBackgroundColour(wxColour(207, 214, 229));
}
//----------------------------------------------------------------------------
TopView::~TopView()
{
}
//----------------------------------------------------------------------------