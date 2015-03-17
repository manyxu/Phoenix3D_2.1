// PX2DlgTerainPageNew.cpp

#include "PX2DlgTerainPageNew.hpp"
#include "PX2Assert.hpp"
using namespace PX2Editor;

BEGIN_EVENT_TABLE(DlgTerrainPageNew, wxDialog)
	EVT_BUTTON(wxID_ANY, DlgTerrainPageNew::OnButton)
END_EVENT_TABLE()

DlgTerrainPageNew::DlgTerrainPageNew (wxWindow *parent)
:
mRowI(0),
mColI(0)
{
	const bool success = 
		wxXmlResource::Get()->LoadDialog(this,
		parent, TEXT("TerrainPageNew") );

	assertion(success, "LoadDialog failed!");
	PX2_UNUSED(success);

	mRowIndex = (wxTextCtrl*)FindWindow(XRCID("mRowIndex"));
	assertion(mRowIndex!=0, "Window must be find!");
	mColIndex = (wxTextCtrl*)FindWindow(XRCID("mColIndex"));
	assertion(mColIndex!=0, "Window must be find!");

	mOK = (wxButton*)FindWindow(XRCID("mOK"));
	mCancel = (wxButton*)FindWindow(XRCID("mCancel"));
}
//----------------------------------------------------------------------------
void DlgTerrainPageNew::OnButton (wxCommandEvent& event)
{
	if (event.GetEventObject() == mOK)
	{
		wxString strIX = mRowIndex->GetValue();
		wxString strIY = mColIndex->GetValue();

		double indexX = 0.0;
		strIX.ToDouble(&indexX);
		mRowI = (int)indexX;

		double indexY = 0.0;
		strIY.ToDouble(&indexY);
		mColI = (int)indexY;

		EndDialog(wxID_OK);
	}
	else if (event.GetEventObject() == mCancel)
	{
		EndDialog(wxID_CANCEL);
	}
}
//----------------------------------------------------------------------------