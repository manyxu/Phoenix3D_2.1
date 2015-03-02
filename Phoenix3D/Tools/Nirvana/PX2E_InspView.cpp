// PX2E_InspView.cpp

#include "PX2E_InspView.hpp"
#include "PX2ObjectInspector.hpp"
#include "PX2SimulationEventType.hpp"
#include "PX2Selection.hpp"
#include "PX2E_NirMan.hpp"
#include "PX2ScriptManager.hpp"
using namespace PX2Editor;
using namespace PX2;

BEGIN_EVENT_TABLE(InspView, wxWindow)
END_EVENT_TABLE()

//----------------------------------------------------------------------------
InspView::InspView(wxWindow *parent) :
wxWindow(parent, wxID_ANY),
mCurWindow(0)
{
	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer(wxVERTICAL);

	mInspTreeBar = new PX2wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
		wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_HORIZONTAL);
	mInspTreeBar->SetArtProvider(new PX2wxAuiToolBarArt(1));

	NirMan::GetSingleton().SetCurToolBar(mInspTreeBar);
	PX2_SM.CallString("e_CreateTooBarRes()");

	mInspTreeBar->Realize();

	bSizer55->Add(mInspTreeBar, 0, wxEXPAND | wxBOTTOM, 5);

	bSizer54->Add(bSizer55, 0, wxEXPAND, 5);

	mCurSizer = new wxBoxSizer(wxVERTICAL);

	bSizer54->Add(mCurSizer, 1, wxEXPAND, 5);

	this->SetSizer(bSizer54);
	this->Layout();

	PX2_EW.ComeIn(this);

	SetBackgroundColour(wxColour(255, 255, 255));
}
//----------------------------------------------------------------------------
InspView::~InspView()
{
	if (mCurWindow)
	{
		delete mCurWindow;
		mCurWindow = 0;
	}
}
//----------------------------------------------------------------------------
void InspView::DoExecute(PX2::Event *ent)
{
	if (SimuES_E::IsEqual(ent, SimuES_E::AddSelect))
	{
		Object *firstObject = PX2_SELECTION.GetFirstObject();
		_SetObject(firstObject);
	}
	else if (SimuES_E::IsEqual(ent, SimuES_E::RemoveAllSelects))
	{
		_SetObject(0);
	}
}
//----------------------------------------------------------------------------
void InspView::_SetObject(PX2::Object *obj)
{
	if (mObject == obj && obj)
		return;

	mObject = obj;

	if (mObject)
		_ChangeToWindow("Object");
	else
		_ChangeToWindow("");
}
//----------------------------------------------------------------------------
void InspView::_ChangeToWindow(std::string str, int userData)
{
	PX2_UNUSED(userData);

	if (mCurWindow)
	{
		mCurSizer->Clear();

		delete mCurWindow;
		mCurWindow = 0;
	}

	mStrTag = str;

	if ("Object" == str)
	{
		ObjectInspector *inspec = new ObjectInspector(this);
		inspec->SetObject(mObject);
		mCurWindow = inspec;
	}
	else if ("P" == str || "S" == str || "U" == str)
	{
		/**/
	}

	if (mCurWindow) mCurSizer->Add(mCurWindow, 1, wxEXPAND | wxTOP, 2);

	Layout();
	Update();
}
//----------------------------------------------------------------------------