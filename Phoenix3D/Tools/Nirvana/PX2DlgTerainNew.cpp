// PX2DlgTerainNew.cpp

#include "PX2DlgTerainNew.hpp"
#include "PX2Assert.hpp"
using namespace PX2Editor;

BEGIN_EVENT_TABLE(DlgTerrainNew, wxDialog)
EVT_BUTTON(wxID_ANY, DlgTerrainNew::OnButton)
END_EVENT_TABLE()

DlgTerrainNew::DlgTerrainNew (wxWindow *parent)
{
	const bool success = 
		wxXmlResource::Get()->LoadDialog(this,
		parent, TEXT("TerrainNew") );

	assertion(success, "LoadDialog failed!");
	PX2_UNUSED(success);

	mTerrainOK = (wxButton*)FindWindow(XRCID("TerrainOk"));
	assertion(mTerrainOK!=0, "Window must be find!");

	mTerrainCancel = (wxButton*)FindWindow(XRCID("TerrainCancel"));
	assertion(mTerrainCancel!=0, "Window must be find!");

	mTerrainName = (wxTextCtrl*)FindWindow(XRCID("TerrainName"));
	assertion(mTerrainName!=0, "Window must be find!");

	mTerrainWidth = (wxComboBox*)FindWindow(XRCID("TerrainWidth"));
	assertion(mTerrainWidth!=0, "Window must be find!");

	mPageWidth = (wxComboBox*)FindWindow(XRCID("PageWidth"));
	assertion(mPageWidth!=0, "Window must be find!");

	mGridSpace = (wxTextCtrl*)FindWindow(XRCID("GridSpace"));
	assertion(mGridSpace!=0, "Window must be find!");
}
//----------------------------------------------------------------------------
void DlgTerrainNew::OnButton (wxCommandEvent& event)
{
	if (event.GetEventObject() == mTerrainOK)
	{
		wxString terrainName = mTerrainName->GetValue();
		mValue_TerrainName = std::string(terrainName.ToAscii());

		int selectIndex = mTerrainWidth->GetCurrentSelection();
		wxString terrainWidth = mTerrainWidth->GetString(selectIndex);
		if (terrainWidth == "128 x 128" || selectIndex == -1)
		{
			mValue_TerrainWidth = 128;
		}
		else if (terrainWidth == "256 x 256")
		{
			mValue_TerrainWidth = 256;
		}
		else if (terrainWidth == "512 x 512")
		{
			mValue_TerrainWidth = 512;
		}
		else if (terrainWidth == "1024 x 1024")
		{
			mValue_TerrainWidth = 1024;
		}
		else if (terrainWidth == "2048 x 2048")
		{
			mValue_TerrainWidth = 2048;
		}

		selectIndex = mPageWidth->GetCurrentSelection();
		wxString pageWidth = mPageWidth->GetString(selectIndex);
		if (pageWidth == "32 x 32" || selectIndex == -1)
		{
			mValue_PageWidth = 32;
		}
		else if (pageWidth == "64 x 64")
		{
			mValue_PageWidth = 64;
		}
		else if (pageWidth == "128 x 128")
		{
			mValue_PageWidth = 128;
		}

		wxString wxGridSpace = mGridSpace->GetValue();
		double gridSpace;
		wxGridSpace.ToDouble(&gridSpace);
		mValue_GridSpace = (float)gridSpace;

		EndDialog(wxID_OK);
	}
	else if (event.GetEventObject() == mTerrainCancel)
	{
		EndDialog(wxID_CANCEL);
	}
}
//----------------------------------------------------------------------------