// PX2InspView.cpp

#include "PX2InspView.hpp"
#include "PX2ObjectInspector.hpp"
#include "PX2SimulationEventType.hpp"
#include "PX2Selection.hpp"
using namespace PX2Editor;
using namespace PX2;

BEGIN_EVENT_TABLE(InspWindow, wxWindow)
EVT_SIZE(InspWindow::OnSize)
END_EVENT_TABLE()

//----------------------------------------------------------------------------
InspWindow::InspWindow(wxWindow *parent) :
wxWindow(parent, wxID_ANY),
mCurWindow(0)
{
	SetBackgroundColour(wxColour(255, 255, 255));
}
//----------------------------------------------------------------------------
InspWindow::~InspWindow()
{
	if (mCurWindow)
	{
		delete mCurWindow;
		mCurWindow = 0;
	}
}
//----------------------------------------------------------------------------
void InspWindow::OnSize(wxSizeEvent& e)
{
	PX2_UNUSED(e);

	wxSize size = GetClientSize();

	if (mCurWindow)
	{
		mCurWindow->SetSize(size);
	}
}
//----------------------------------------------------------------------------
void InspWindow::DoExecute(PX2::Event *ent)
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
void InspWindow::_SetObject(PX2::Object *obj)
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
void InspWindow::_ChangeToWindow(std::string str, int userData)
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