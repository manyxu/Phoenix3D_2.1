// PX2E_DlgSetCurveVal.cpp

#include "PX2E_DlgSetCurveVal.hpp"
#include "PX2Assert.hpp"
using namespace PX2Editor;

BEGIN_EVENT_TABLE(DlgSetCurveVal, wxDialog)
EVT_BUTTON(wxID_ANY, DlgSetCurveVal::OnButton)
END_EVENT_TABLE()

//----------------------------------------------------------------------------
DlgSetCurveVal::DlgSetCurveVal(wxWindow *parent)
{
	const bool success =
		wxXmlResource::Get()->LoadDialog(this,
		parent, TEXT("SetCurveVal"));

	assertion(success, "LoadDialog failed!");
	PX2_UNUSED(success);

	mLabel = (wxStaticText*)FindWindow(XRCID("mLabel"));
	assertion(mLabel != 0, "Window must be find!");

	mVal = (wxTextCtrl*)FindWindow(XRCID("mVal"));
	assertion(mVal != 0, "Window must be find!");

	mOK = (wxButton*)FindWindow(XRCID("mOK"));
	assertion(mOK != 0, "Window must be find!");

	mCancel = (wxButton*)FindWindow(XRCID("mCancel"));
	assertion(mCancel != 0, "Window must be find!");
}
//----------------------------------------------------------------------------
void DlgSetCurveVal::SetLabel(std::string str)
{
	mLabel->SetLabelText(str);
}
//----------------------------------------------------------------------------
void DlgSetCurveVal::SetVal(float val)
{
	mVal->SetValue(wxString().FromDouble((double)val));
}
//----------------------------------------------------------------------------
float DlgSetCurveVal::GetVal()
{
	double val = 0.0;
	mVal->GetValue().ToDouble(&val);
	return (float)val;
}
//----------------------------------------------------------------------------
void DlgSetCurveVal::OnButton(wxCommandEvent& event)
{
	if (event.GetEventObject() == mOK)
	{
		EndDialog(wxID_OK);
	}
	else if (event.GetEventObject() == mCancel)
	{
		EndDialog(wxID_CANCEL);
	}
}
//----------------------------------------------------------------------------