// PX2E_PreView.cpp

#include "PX2E_TimeLineView.hpp"
#include "PX2E_TimeLineRender.hpp"
#include "PX2E_Define.hpp"
#include "PX2E_NirMan.hpp"
#include "PX2wxAui.hpp"
#include "PX2ScriptManager.hpp"
using namespace PX2Editor;
using namespace PX2;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::TimeLineView, wxWindow)
BEGIN_EVENT_TABLE(TimeLineView, wxWindow)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
TimeLineView::TimeLineView()
{
}
//----------------------------------------------------------------------------
TimeLineView::TimeLineView(wxWindow *parent) :
wxWindow(parent, -1)
{
	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer(wxVERTICAL);

	mTimeLineBar = new PX2wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
		wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_HORIZONTAL);
	mTimeLineBar->SetArtProvider(new PX2wxAuiToolBarArt(1));

	NirMan::GetSingleton().SetCurToolBar(mTimeLineBar);
	PX2_SM.CallString("e_CreateTooBarProject()");

	mTimeLineBar->Realize();

	bSizer55->Add(mTimeLineBar, 0, wxEXPAND | wxBOTTOM, 0);

	bSizer54->Add(bSizer55, 0, wxEXPAND, 0);

	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer(wxVERTICAL);

	mTimeLineRender = new TimeLineRender(this);
	bSizer57->Add(mTimeLineRender, 1, wxEXPAND | wxTOP, 0);

	bSizer54->Add(bSizer57, 1, wxEXPAND, 0);

	this->SetSizer(bSizer54);
	this->Layout();

}
//----------------------------------------------------------------------------
TimeLineView::~TimeLineView()
{
}
//----------------------------------------------------------------------------
void TimeLineView::SetTheme(Theme *theme)
{
}
//----------------------------------------------------------------------------
