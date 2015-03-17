// PX2DlgPlayConfig.cpp

#include "PX2DlgPlayConfig.hpp"
#include "PX2StringTokenizer.hpp"
#include "PX2StringHelp.hpp"
#include "PX2Assert.hpp"
#include "PX2EngineLoop.hpp"
using namespace PX2Editor;

BEGIN_EVENT_TABLE(DlgPlayConfig, wxDialog)
EVT_BUTTON(wxID_ANY, DlgPlayConfig::OnButton)
END_EVENT_TABLE()

//----------------------------------------------------------------------------
DlgPlayConfig::DlgPlayConfig(wxWindow *parent)
{
	const bool success =
		wxXmlResource::Get()->LoadDialog(this,
		parent, TEXT("PlayConfig"));
	PX2_UNUSED(success);

	mGP_Pix = (wxComboBox*)FindWindow(XRCID("mGP_Pix"));
	assertion(mGP_Pix != 0, "Window must be find!");

	mEP_CtrlType = (wxComboBox*)FindWindow(XRCID("mEP_CtrlType"));
	assertion(mEP_CtrlType != 0, "Window must be find!");

	mOK = (wxButton*)FindWindow(XRCID("mOK"));
	mCancel = (wxButton*)FindWindow(XRCID("mCancel"));

	const Sizef &boostSize = PX2_ENGINELOOP.GetBoostSize();
	int iBoostWidth = (int)boostSize.Width;
	int iBoostHeight = (int)boostSize.Height;

	std::string pixStr = StringHelp::IntToString(iBoostWidth) + " x " + StringHelp::IntToString(iBoostHeight);
	for (int i = 0; i < (int)mGP_Pix->GetCount(); i++)
	{
		std::string str = mGP_Pix->GetString(i).ToStdString();
		if (pixStr == str)
		{
			mGP_Pix->Select(i);
		}
	}

	std::string epcmStr = PX2_ENGINELOOP.GetPlayLogicModeStr();
	for (int i = 0; i < (int)mEP_CtrlType->GetCount(); i++)
	{
		std::string str = mEP_CtrlType->GetString(i).ToStdString();

		if (str == epcmStr)
		{
			mEP_CtrlType->Select(i);
		}
	}
}
//----------------------------------------------------------------------------
void DlgPlayConfig::OnButton(wxCommandEvent& event)
{
	if (event.GetEventObject() == mOK)
	{
		int selPixIndex = mGP_Pix->GetCurrentSelection();
		wxString pixConfig = mGP_Pix->GetString(selPixIndex);
		StringTokenizer strTok(pixConfig.ToStdString(), " ");

		int width = StringHelp::StringToInt(strTok[0]);
		int height = StringHelp::StringToInt(strTok[2]);
		PX2_ENGINELOOP.SetBoostSize(Sizef((float)width, (float)height));

		int selCtrlIndex = mEP_CtrlType->GetCurrentSelection();
		wxString ctrlType = mEP_CtrlType->GetString(selCtrlIndex);

		if (ctrlType == "simple" || selCtrlIndex == -1)
		{
			PX2_ENGINELOOP.SetPlayLogicMode(EngineLoop::PLM_SIMPLE);
		}
		else if (ctrlType == "logic")
		{
			PX2_ENGINELOOP.SetPlayLogicMode(EngineLoop::PLM_LOGIC);
		}

		PX2_ENGINELOOP.WriteBoost();

		EndDialog(wxID_OK);
	}
	else if (event.GetEventObject() == mCancel)
	{
		EndDialog(wxID_CANCEL);
	}
}
//----------------------------------------------------------------------------