// PX2E_RenderView.cpp

#include "PX2E_ProjView.hpp"
#include "PX2E_ProjTree.hpp"
#include "PX2Project.hpp"
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
	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer(wxVERTICAL);

	mProjTreeBar = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
		wxTB_HORIZONTAL | wxTB_FLAT | wxTB_NODIVIDER);
	mProjTreeBar->Realize();

	bSizer55->Add(mProjTreeBar, 0, wxEXPAND | wxBOTTOM, 5);

	bSizer54->Add(bSizer55, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer(wxVERTICAL);

	mSearchCtrl = new wxSearchCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1, 22),
		wxTE_CAPITALIZE | wxTE_CENTER | wxTE_PROCESS_ENTER | wxNO_BORDER);
	mSearchCtrl->ShowSearchButton(false);
	mSearchCtrl->ShowCancelButton(false);
	//searchCtrl->Enable(false);
	bSizer56->Add(mSearchCtrl, 0, wxEXPAND, 5);

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
void ProjView::SetColorForTheme(PX2::EditParams::Theme theme)
{
	float r = theme.backColor[0] * 255.0f;
	float g = theme.backColor[1] * 255.0f;
	float b = theme.backColor[2] * 255.0f;
	SetBackgroundColour(wxColour(r, g, b));
	mProjTree->SetBackgroundColour(wxColour(r, g, b));

	r = theme.toolBarColor[0] * 255.0f;
	g = theme.toolBarColor[1] * 255.0f;
	b = theme.toolBarColor[2] * 255.0f;
	mProjTreeBar->SetBackgroundColour(wxColour(r, g, b));
	mProjTreeBar->SetForegroundColour(wxColour(r, g, b));

	r = theme.searchColor[0] * 255.0f;
	g = theme.searchColor[1] * 255.0f;
	b = theme.searchColor[2] * 255.0f;

	mSearchCtrl->SetBackgroundColour(wxColour(r, g, b));
	Project *proj = Project::GetSingletonPtr();
	if (proj)
	{
		mProjTree->SetItemsColour();
	}
}
//----------------------------------------------------------------------------