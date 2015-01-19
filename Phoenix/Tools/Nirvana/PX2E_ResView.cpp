// PX2E_RenderView.cpp

#include "PX2E_ResView.hpp"
using namespace PX2Editor;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::ResView, wxWindow)
BEGIN_EVENT_TABLE(ResView, wxWindow)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
ResView::ResView()
{
}
//----------------------------------------------------------------------------
ResView::ResView(wxWindow *parent) :
wxWindow(parent, -1)
{
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer(wxVERTICAL);

	mResTreeBar = new wxToolBar(this, wxID_ANY, wxPoint(0, -2), wxDefaultSize, wxTB_HORIZONTAL | wxTB_FLAT | wxTB_NODIVIDER);
	mResTreeBar->SetBackgroundColour(wxColour(207, 214, 229));
	mResTreeBar->SetForegroundColour(wxColour(207, 214, 229));
	mResTreeBar->Realize();

	bSizer10->Add(mResTreeBar, 1, wxEXPAND, 0);

	bSizer9->Add(bSizer10, 0, wxEXPAND | wxALIGN_CENTER_HORIZONTAL, 0);

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer(wxVERTICAL);

	//mResTree = new ResTree(this);
	//bSizer11->Add(mResTree, 1, wxALL | wxEXPAND, 1);

	bSizer9->Add(bSizer11, 1, wxEXPAND, 0);

	this->SetSizer(bSizer9);

	this->Layout();
}
//----------------------------------------------------------------------------
ResView::~ResView()
{
}
//----------------------------------------------------------------------------