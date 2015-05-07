// PX2E_RenderView.cpp

#include "PX2E_ProjView.hpp"
#include "PX2E_ProjTree.hpp"
#include "PX2E_Define.hpp"
#include "PX2E_NirMan.hpp"
#include "PX2Project.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2Edit.hpp"
#include "PX2wxAui.hpp"
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
	SetBackgroundColour(Float3TowxColour(PX2_EDIT.GetEditParams()->GetCurTheme()->Color_Page_Background));
	SetForegroundColour(Float3TowxColour(PX2_EDIT.GetEditParams()->GetCurTheme()->Color_Page_Foreground));

	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer(wxVERTICAL);

	mProjTreeBar = new PX2wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
		wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_HORIZONTAL);
	mProjTreeBar->SetArtProvider(new PX2wxAuiToolBarArt(1));

	NirMan::GetSingleton().SetCurToolBar(mProjTreeBar);
	PX2_SM.CallString("e_CreateTooBarProject()");

	mProjTreeBar->Realize();

	bSizer55->Add(mProjTreeBar, 0, wxEXPAND | wxBOTTOM, 0);

	bSizer54->Add(bSizer55, 0, wxEXPAND, 0);

	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer(wxVERTICAL);

	mSearchCtrl = new wxSearchCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1, 22),
		wxTE_CAPITALIZE | wxTE_CENTER | wxTE_PROCESS_ENTER | wxNO_BORDER);
	mSearchCtrl->ShowSearchButton(false);
	mSearchCtrl->ShowCancelButton(false);
	bSizer56->Add(mSearchCtrl, 0, wxEXPAND, 0);

	mSearchCtrl->SetBackgroundColour(Float3TowxColour(PX2_EDIT.GetEditParams()->GetCurTheme()->Color_Page_Background));
	mSearchCtrl->SetForegroundColour(Float3TowxColour(PX2_EDIT.GetEditParams()->GetCurTheme()->Color_Page_Foreground));

	bSizer54->Add(bSizer56, 0, wxEXPAND, 0);

	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer(wxVERTICAL);

	mProjTree = new ProjTree(this);
	bSizer57->Add(mProjTree, 1, wxEXPAND | wxTOP, 0);

	bSizer54->Add(bSizer57, 1, wxEXPAND, 0);

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