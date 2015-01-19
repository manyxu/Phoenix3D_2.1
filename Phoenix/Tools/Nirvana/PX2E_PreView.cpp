// PX2E_PreView.cpp

#include "PX2E_PreView.hpp"
using namespace PX2Editor;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::PreView, wxWindow)
BEGIN_EVENT_TABLE(PreView, wxWindow)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
PreView::PreView()
{
}
//----------------------------------------------------------------------------
PreView::PreView(wxWindow *parent) :
wxWindow(parent, -1)
{
}
//----------------------------------------------------------------------------
PreView::~PreView()
{
}
//----------------------------------------------------------------------------