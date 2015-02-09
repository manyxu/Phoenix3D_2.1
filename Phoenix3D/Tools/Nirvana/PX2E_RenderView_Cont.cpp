// PX2E_RenderView_Cont.cpp

#include "PX2E_RenderView_Cont.hpp"
#include "PX2E_NirMan.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2wxAui.hpp"
using namespace PX2Editor;
using namespace PX2;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::RenderView_Cot, wxWindow)
BEGIN_EVENT_TABLE(RenderView_Cot, wxWindow)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
RenderView_Cot::RenderView_Cot()
{
}
//----------------------------------------------------------------------------
wxAuiToolBar *RenderView_Cot::_CreateRenderViewBar(RenderViewType type)
{
	PX2wxAuiToolBar *renderViewToolBar = (PX2wxAuiToolBar*)new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
		wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_HORIZONTAL);
	renderViewToolBar->SetArtProvider(new PX2wxAuiToolBarArt());
	renderViewToolBar->SetSize(wxSize(-1, 24));

	if (RVT_SCENEUI == type)
	{
		NirMan::GetSingleton().SetCurToolBar(renderViewToolBar);

		if (RVT_SCENEUI == type)
			PX2_SM.CallString("e_CreateToolBarSceneUI()");
	}

	renderViewToolBar->Realize();

	return renderViewToolBar;
}
//----------------------------------------------------------------------------
RenderView_Cot::RenderView_Cot(RenderViewType type, wxWindow *parent) :
wxWindow(parent, wxID_ANY),
mRenderView(0)
{
	SetBackgroundColour(wxColour(207, 214, 229));

	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer(wxVERTICAL);

	mRenderViewBar = _CreateRenderViewBar(type);

	bSizer55->Add(mRenderViewBar, 0, wxEXPAND, 5);

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