// PX2E_RenderView.cpp

#include "PX2E_RenderView.hpp"
using namespace PX2Editor;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::RenderView, wxWindow)
BEGIN_EVENT_TABLE(RenderView, wxWindow)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
RenderView::RenderView()
{
}
//----------------------------------------------------------------------------
RenderView::RenderView(wxWindow *parent):
wxWindow(parent, -1)
{
}
//----------------------------------------------------------------------------
RenderView::~RenderView()
{
}
//----------------------------------------------------------------------------