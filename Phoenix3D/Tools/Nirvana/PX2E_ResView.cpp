// PX2E_RenderView.cpp

#include "PX2E_ResView.hpp"
#include "PX2E_ResSplitPanel.hpp"
#include "PX2E_ResTree.hpp"
#include "PX2E_Define.hpp"
#include "PX2E_NirMan.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2Edit.hpp"
using namespace PX2Editor;
using namespace PX2;

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
	SetBackgroundColour(Float3TowxColour(PX2_EDIT.GetEditParams()->GetCurTheme()->Color_Page_Background));
	SetForegroundColour(Float3TowxColour(PX2_EDIT.GetEditParams()->GetCurTheme()->Color_Page_Foreground));

	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer(wxVERTICAL);

	mResTreeBar = new PX2wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
		wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_HORIZONTAL);
	mResTreeBar->SetArtProvider(new PX2wxAuiToolBarArt(1));

	NirMan::GetSingleton().SetCurToolBar(mResTreeBar);
	PX2_SM.CallString("e_CreateToolBarRes()");

	mResTreeBar->Realize();

	bSizer55->Add(mResTreeBar, 0, wxEXPAND | wxBOTTOM, 0);

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

	mSplitPanel = new ResSplitPanel(this, false);
	bSizer57->Add(mSplitPanel, 1, wxEXPAND | wxTOP, 0);

	bSizer54->Add(bSizer57, 1, wxEXPAND, 0);

	this->SetSizer(bSizer54);
	this->Layout();
}
//----------------------------------------------------------------------------
ResView::~ResView()
{
}
//----------------------------------------------------------------------------