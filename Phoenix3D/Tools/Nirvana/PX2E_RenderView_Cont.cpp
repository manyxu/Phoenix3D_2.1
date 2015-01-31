// PX2E_RenderView_Cont.cpp

#include "PX2E_RenderView_Cont.hpp"
using namespace PX2Editor;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::RenderView_Cot, wxWindow)
BEGIN_EVENT_TABLE(RenderView_Cot, wxWindow)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
RenderView_Cot::RenderView_Cot()
{
}
//----------------------------------------------------------------------------
RenderView_Cot::RenderView_Cot(RenderView::RenderViewType type, wxWindow *parent) :
wxWindow(parent, wxID_ANY),
mRenderView(0)
{
	SetBackgroundColour(wxColour(207, 214, 229));

	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer(wxVERTICAL);

	mRenderViewBar = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
		wxTB_HORIZONTAL | wxTB_FLAT | wxTB_NODIVIDER);
	mRenderViewBar->SetBackgroundColour(wxColour(207, 214, 229));
	mRenderViewBar->SetForegroundColour(wxColour(207, 214, 229));
	mRenderViewBar->Realize();

	bSizer55->Add(mRenderViewBar, 0, wxEXPAND | wxBOTTOM, 5);

	bSizer54->Add(bSizer55, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer(wxVERTICAL);

	mRenderView = new RenderView(type, this);
	bSizer57->Add(mRenderView, 1, wxEXPAND | wxTOP, 2);

	bSizer54->Add(bSizer57, 1, wxEXPAND, 5);

	this->SetSizer(bSizer54);
	this->Layout();
}
//----------------------------------------------------------------------------
RenderView_Cot::~RenderView_Cot()
{
}
//----------------------------------------------------------------------------
RenderView *RenderView_Cot::GetRenderView()
{
	return mRenderView;
}
//----------------------------------------------------------------------------