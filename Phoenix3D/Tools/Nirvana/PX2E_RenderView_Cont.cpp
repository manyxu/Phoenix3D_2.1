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
	PX2wxAuiToolBar *renderViewToolBar = new PX2wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
		wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_HORIZONTAL);
	renderViewToolBar->SetArtProvider(new PX2wxAuiToolBarArt(1));
	renderViewToolBar->SetSize(wxSize(-1, 24));

	if (RVT_SCENEUI == type)
	{
		NirMan::GetSingleton().SetCurToolBar(renderViewToolBar);
		PX2_SM.CallString("e_CreateToolBarSceneUI()");
	}
	else if (RVT_PREVIEW == type)
	{
		NirMan::GetSingleton().SetCurToolBar(renderViewToolBar);
		PX2_SM.CallString("e_CreateToolBarPreView()");
	}
	else if(RVT_TIMELINE == type)
	{
		NirMan::GetSingleton().SetCurToolBar(renderViewToolBar);
		PX2_SM.CallString("e_CreateToolBarTimeLine()");
	}

	renderViewToolBar->Realize();

	return renderViewToolBar;
}
//----------------------------------------------------------------------------
RenderView_Cot::RenderView_Cot(RenderViewType type, wxWindow *parent) :
wxWindow(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER),
mRenderView(0)
{
	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer(wxVERTICAL);

	mRenderViewBar = _CreateRenderViewBar(type);

	bSizer55->Add(mRenderViewBar, 0, wxEXPAND, 0);

	bSizer54->Add(bSizer55, 0, wxEXPAND, 0);

	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer(wxVERTICAL);

	mRenderView = new RenderView(type, this);
	bSizer57->Add(mRenderView, 1, wxEXPAND | wxTOP, 0);

	bSizer54->Add(bSizer57, 1, wxEXPAND, 0);

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