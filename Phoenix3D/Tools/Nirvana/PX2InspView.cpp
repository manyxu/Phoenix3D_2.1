// PX2InspView.cpp

#include "PX2InspView.hpp"
#include "PX2ObjectInspector.hpp"
#include "PX2SimulationEventType.hpp"
#include "PX2Selection.hpp"
using namespace PX2Editor;
using namespace PX2;

BEGIN_EVENT_TABLE(InspView, wxWindow)
EVT_SIZE(InspView::OnSize)
END_EVENT_TABLE()

//----------------------------------------------------------------------------
InspView::InspView(wxWindow *parent) :
wxWindow(parent, wxID_ANY),
mCurWindow(0)
{
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
void InspView::OnSize(wxSizeEvent& e)
{
	PX2_UNUSED(e);

	wxSize size = GetClientSize();

	if (mCurWindow)
	{
		mCurWindow->SetSize(size);
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

	if (mCurWindow)
	{
		wxSize size = GetClientSize();
		mCurWindow->SetSize(size);
	}
}
//----------------------------------------------------------------------------