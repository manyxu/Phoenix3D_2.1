// PX2E_RenderView.cpp

#include "PX2E_RenderView.hpp"
#include "PX2Project.hpp"
using namespace PX2Editor;
using namespace PX2;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::RenderView, wxWindow)
BEGIN_EVENT_TABLE(RenderView, wxWindow)
EVT_SIZE(RenderView::OnSize)
EVT_PAINT(RenderView::OnPaint)
EVT_ERASE_BACKGROUND(RenderView::OnEraseBackground)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
RenderView::RenderView()
{
}
//----------------------------------------------------------------------------
RenderView::RenderView(wxWindow *parent):
wxWindow(parent, -1),
mIsInited(false)
{
}
//----------------------------------------------------------------------------
RenderView::~RenderView()
{
}
//----------------------------------------------------------------------------
void RenderView::OnSize(wxSizeEvent& e)
{
	Project *proj = Project::GetSingletonPtr();
	if (!proj) return;

	wxSize size = e.GetSize();

	RenderStep *renderStep = proj->GetSceneRenderStep();
	renderStep->SetSize((float)size.GetWidth(), (float)size.GetHeight());
}
//----------------------------------------------------------------------------
void RenderView::OnPaint(wxPaintEvent& e)
{
	wxPaintDC dc(this);
	PX2_UNUSED(e);
}
//----------------------------------------------------------------------------
void RenderView::OnEraseBackground(wxEraseEvent& e)
{
	if (!mIsInited) return;
	PX2_UNUSED(e);
}
//----------------------------------------------------------------------------