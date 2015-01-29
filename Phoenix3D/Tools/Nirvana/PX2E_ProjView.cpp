// PX2E_RenderView.cpp

#include "PX2E_ProjView.hpp"
#include "PX2E_ProjTree.hpp"
using namespace PX2Editor;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::ProjView, wxWindow)
BEGIN_EVENT_TABLE(ProjView, wxWindow)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
ProjView::ProjView()
{
}
//----------------------------------------------------------------------------
ProjView::ProjView(wxWindow *parent) :
wxWindow(parent, wxID_ANY),
mProjTree(0)
{
	SetBackgroundColour(wxColour(207, 214, 229));
	//SetBackgroundColour(wxColour(0, 214, 229));

	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer(wxVERTICAL);

	mProjTreeBar = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
		wxTB_HORIZONTAL | wxTB_FLAT | wxTB_NODIVIDER);
	//mProjTreeBar->SetBackgroundColour(wxColour(207, 214, 229));
	mProjTreeBar->SetBackgroundColour(wxColour(0, 214, 229));
	mProjTreeBar->SetForegroundColour(wxColour(207, 214, 229));
	//mProjTreeBar->SetForegroundColour(wxColour(0, 214, 229));
	mProjTreeBar->Realize();

	bSizer55->Add(mProjTreeBar, 0, wxEXPAND | wxBOTTOM, 5);

	bSizer54->Add(bSizer55, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer(wxVERTICAL);

	wxSearchCtrl *searchCtrl = new wxSearchCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1, 22),
		wxTE_CAPITALIZE | wxTE_CENTER | wxTE_PROCESS_ENTER | wxNO_BORDER);
	searchCtrl->ShowSearchButton(false);
	searchCtrl->ShowCancelButton(false);
	//searchCtrl->Enable(false);
	bSizer56->Add(searchCtrl, 0, wxEXPAND, 5);

	bSizer54->Add(bSizer56, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer(wxVERTICAL);

	mProjTree = new ProjTree(this);
	bSizer57->Add(mProjTree, 1, wxEXPAND | wxTOP, 2);

	bSizer54->Add(bSizer57, 1, wxEXPAND, 5);

	this->SetSizer(bSizer54);
	this->Layout();
}
//----------------------------------------------------------------------------
ProjView::~ProjView()
{
}
//----------------------------------------------------------------------------
ProjTree *ProjView::GetProjTree()
{
	return mProjTree;
}
//----------------------------------------------------------------------------