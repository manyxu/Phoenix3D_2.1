// PX2TerrainMakingPanel.cpp

#include "PX2TerrainMakingPanel.hpp"
#include "PX2Edit.hpp"
#include "PX2Project.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2EditEventType.hpp"
using namespace PX2Editor;
using namespace PX2;

#define SIZE_ADJUST 10
#define STENGTH_ADJUST 0.1f

BEGIN_EVENT_TABLE(TerrainMakingPanel, wxPanel)
EVT_BUTTON(wxID_ANY, TerrainMakingPanel::OnButton)
EVT_CHOICE(wxID_ANY, TerrainMakingPanel::OnChoice)
EVT_SLIDER(wxID_ANY, TerrainMakingPanel::OnSliderUpdate)
EVT_RADIOBOX(wxID_ANY, TerrainMakingPanel::OnRadio)
EVT_LISTBOX_DCLICK(wxID_ANY, TerrainMakingPanel::OnListboxDClick)
EVT_TEXT_ENTER(wxID_ANY, TerrainMakingPanel::OnTextEnter)
EVT_CHECKBOX(wxID_ANY, TerrainMakingPanel::OnCheckBox)
END_EVENT_TABLE()

//-----------------------------------------------------------------------------
TerrainMakingPanel::TerrainMakingPanel(wxWindow *parent) :
mHeightBut(0),
mTexBut(0),
mInterplate(0),
mBurshSize(0),
mBurshStrength(0),
mHeightModeRadio(0),
mShowTerrainGrid(0)
{
	const bool bSuccess = wxXmlResource::Get()->LoadPanel(this, parent,
		TEXT("TerrainMaking"));

	assertion(bSuccess, "Load TerrainBrush failed!");
	PX2_UNUSED(bSuccess);

	mHeightBut = (wxButton*)FindWindow(XRCID("mHeightBut"));
	mTexBut = (wxButton*)FindWindow(XRCID("mTexBut"));
	mJunglerBut = (wxButton*)FindWindow(XRCID("mJunglerBut"));

	// bursh
	mInterplate = (wxChoice*)FindWindow(XRCID("InterplateMode"));
	assertion(mInterplate != 0, "Window must be find!");

	mBurshSize = (wxSlider*)FindWindow(XRCID("Size"));
	assertion(mBurshSize != 0, "Window must be find!");

	mBurshStrength = (wxSlider*)FindWindow(XRCID("Strength"));
	assertion(mBurshStrength != 0, "Window must be find!");

	// height
	mHeightModeRadio = (wxRadioBox*)FindWindow(XRCID("mHeightModeRadio"));
	assertion(mHeightModeRadio != 0, "Window must be find!");

	mFixHVal = (wxTextCtrl*)FindWindow(XRCID("mFixHVal"));
	assertion(mFixHVal != 0, "Window must be find!");

	mXIndex = (wxTextCtrl*)FindWindow(XRCID("mXIndex"));
	assertion(mXIndex != 0, "Window must be find!");
	mYIndex = (wxTextCtrl*)FindWindow(XRCID("mYIndex"));
	assertion(mYIndex != 0, "Window must be find!");

	mURepeatText = (wxTextCtrl*)FindWindow(XRCID("mURepeatText"));
	assertion(mURepeatText != 0, "Window must be find!");

	mURepeatSlider = (wxSlider*)FindWindow(XRCID("mURepeatSlider"));
	assertion(mURepeatSlider != 0, "Window must be find!");

	mVRepeatText = (wxTextCtrl*)FindWindow(XRCID("mVRepeatText"));
	assertion(mVRepeatText != 0, "Window must be find!");

	mVRepeatSlider = (wxSlider*)FindWindow(XRCID("mVRepeatSlider"));
	assertion(mVRepeatSlider != 0, "Window must be find!");

	mTexLayerRadio = (wxRadioBox*)FindWindow(XRCID("mTexLayerRadio"));
	assertion(mTexLayerRadio != 0, "Window must be find!");

	mLayerListCtrl = (wxListBox*)FindWindow(XRCID("mLayerListCtrl"));
	assertion(mLayerListCtrl != 0, "Window must be find!");

	mShowTerrainGrid = (wxCheckBox*)FindWindow(XRCID("mShowTerrainGrid"));
	assertion(mShowTerrainGrid != 0, "Window must be find!");

	RefreshOnTerainProcess();

	PX2_EW.ComeIn(this);
}
//-----------------------------------------------------------------------------
TerrainMakingPanel::~TerrainMakingPanel()
{
	PX2_EW.GoOut(this);
}
//-----------------------------------------------------------------------------
void TerrainMakingPanel::OnChoice(wxCommandEvent &event)
{
	if (event.GetEventObject() == mInterplate)
	{
		int selectIndex = mInterplate->GetCurrentSelection();
		wxString selectString = mInterplate->GetString(selectIndex);

		if (selectString == "Cos")
		{
			PX2_EDIT.GetTerrainEdit()->GetBrush()->SetInterplateMode(TerrainBrush::IM_COS);
		}
		else if (selectString == "Square")
		{
			PX2_EDIT.GetTerrainEdit()->GetBrush()->SetInterplateMode(TerrainBrush::IM_SQUARE);
		}
		else if (selectString == "Linear")
		{
			PX2_EDIT.GetTerrainEdit()->GetBrush()->SetInterplateMode(TerrainBrush::IM_LINER);
		}
		else if (selectString == "None")
		{
			PX2_EDIT.GetTerrainEdit()->GetBrush()->SetInterplateMode(TerrainBrush::IM_NONE);
		}
	}
}
//-----------------------------------------------------------------------------
void TerrainMakingPanel::OnSliderUpdate(wxCommandEvent &event)
{
	if (event.GetEventObject() == mBurshSize)
	{
		int value = mBurshSize->GetValue();
		if (value > 0)
		{
			float size = ((float)value / 10.0f) * SIZE_ADJUST;
			PX2_EDIT.GetTerrainEdit()->GetBrush()->SetSize(size);
		}
	}
	else if (event.GetEventObject() == mBurshStrength)
	{
		int value = mBurshStrength->GetValue();
		if (value > 0)
		{
			float strength = ((float)value / 100.0f) * STENGTH_ADJUST;
			PX2_EDIT.GetTerrainEdit()->GetBrush()->SetStrength(strength);
		}
	}
	else if (event.GetEventObject() == mURepeatSlider)
	{
		PX2::TerrainPage *page = PX2_EDIT.GetTerrainEdit()->GetBrush()->GetSelectedPage();
		PX2::RawTerrainPage *rawPage = DynamicCast<RawTerrainPage>(page);

		int value = mURepeatSlider->GetValue();

		int selectIndex = PX2_EDIT.GetTerrainEdit()->GetTextureProcess()->GetSelectedLayer();

		if (rawPage)
		{
			PX2::Float2 uv = rawPage->GetUV(selectIndex);
			uv[0] = (float)value;
			rawPage->SetUV(selectIndex, uv);

			wxString strU = wxString::Format("%.2f", uv[0]);
			mURepeatText->Clear();
			mURepeatText->SetValue(strU);
		}
	}
	else if (event.GetEventObject() == mVRepeatSlider)
	{
		PX2::TerrainPage *page = PX2_EDIT.GetTerrainEdit()->GetBrush()->GetSelectedPage();
		PX2::RawTerrainPage *rawPage = DynamicCast<RawTerrainPage>(page);

		int value = mVRepeatSlider->GetValue();

		int selectIndex = PX2_EDIT.GetTerrainEdit()->GetTextureProcess()->GetSelectedLayer();

		if (rawPage)
		{
			PX2::Float2 uv = rawPage->GetUV(selectIndex);
			uv[1] = (float)value;
			rawPage->SetUV(selectIndex, uv);

			wxString strV = wxString::Format("%.2f", uv[1]);
			mVRepeatText->Clear();
			mVRepeatText->SetValue(strV);
		}
	}
}
//-----------------------------------------------------------------------------
void TerrainMakingPanel::OnRadio(wxCommandEvent &event)
{
	wxString str = event.GetString();

	if (event.GetEventObject() == mHeightModeRadio)
	{
		if ("Raise" == str)
		{
			PX2_EDIT.GetTerrainEdit()->GetHeightProcess()
				->SetHeightMode(TerrainHeightProcess::HM_RAISE);
		}
		else if ("Lower" == str)
		{
			PX2_EDIT.GetTerrainEdit()->GetHeightProcess()
				->SetHeightMode(TerrainHeightProcess::HM_LOWER);
		}
		else if ("Fatten" == str)
		{
			PX2_EDIT.GetTerrainEdit()->GetHeightProcess()
				->SetHeightMode(TerrainHeightProcess::HM_FLATTEN);
		}
		else if ("Smooth" == str)
		{
			PX2_EDIT.GetTerrainEdit()->GetHeightProcess()
				->SetHeightMode(TerrainHeightProcess::HM_SMOOTH);
		}
		else if ("Hole" == str)
		{
			PX2_EDIT.GetTerrainEdit()->GetHeightProcess()
				->SetHeightMode(TerrainHeightProcess::MH_HOLE);
		}
		else if ("FixH" == str)
		{
			PX2_EDIT.GetTerrainEdit()->GetHeightProcess()
				->SetHeightMode(TerrainHeightProcess::HM_FIXH);
		}
	}
	else if (event.GetEventObject() == mTexLayerRadio)
	{
		if ("LayerBase" == str)
		{
			PX2_EDIT.GetTerrainEdit()->GetTextureProcess()->SetSelectedLayer(0);
		}
		else if ("Layer1" == str)
		{
			PX2_EDIT.GetTerrainEdit()->GetTextureProcess()->SetSelectedLayer(1);
		}
		else if ("Layer2" == str)
		{
			PX2_EDIT.GetTerrainEdit()->GetTextureProcess()->SetSelectedLayer(2);
		}
		else if ("Layer3" == str)
		{
			PX2_EDIT.GetTerrainEdit()->GetTextureProcess()->SetSelectedLayer(3);
		}
		else if ("Layer4" == str)
		{
			PX2_EDIT.GetTerrainEdit()->GetTextureProcess()->SetSelectedLayer(4);
		}
	}
}
//-----------------------------------------------------------------------------
void TerrainMakingPanel::OnListboxDClick(wxCommandEvent& event)
{
	if (event.GetEventObject() == mLayerListCtrl)
	{
		int select = mLayerListCtrl->GetSelection();
		std::string texStr = mLayerListCtrl->GetString(select);
		Texture2D *tex2D = DynamicCast<Texture2D>(PX2_RM.BlockLoad(texStr));

		if (tex2D)
		{
			Event *ent = EditEventSpace::CreateEventX(EditEventSpace::ToSelectRes);
			ent->SetData<Object*>(tex2D);
			PX2_EW.BroadcastingLocalEvent(ent);
		}
	}
}
//-----------------------------------------------------------------------------
void TerrainMakingPanel::OnTextEnter(wxCommandEvent& event)
{
	if (event.GetEventObject() == mFixHVal)
	{
		wxAny any = mFixHVal->GetValue();
		float hVal = 0.0f;
		if (any.GetAs<float>(&hVal))
		{
			PX2_EDIT.GetTerrainEdit()->GetHeightProcess()
				->SetFixHVal(hVal);
		}
	}

	int selectIndex = PX2_EDIT.GetTerrainEdit()->GetTextureProcess()->GetSelectedLayer();
	PX2::TerrainPage *page = PX2_EDIT.GetTerrainEdit()->GetBrush()->GetSelectedPage();
	PX2::RawTerrainPage *rawPage = DynamicCast<RawTerrainPage>(page);
	if (!rawPage)
		return;

	PX2::Float2 uv = rawPage->GetUV(selectIndex);

	if (event.GetEventObject() == mURepeatText)
	{
		int value = wxAtoi(event.GetString().GetData());
		uv[0] = (float)value;
		rawPage->SetUV(selectIndex, uv);

		mURepeatSlider->SetValue(value);
	}
	else if (event.GetEventObject() == mVRepeatText)
	{
		int value = wxAtoi(event.GetString().GetData());
		uv[1] = (float)value;

		rawPage->SetUV(selectIndex, uv);
		mVRepeatSlider->SetValue(value);
	}
}
//-----------------------------------------------------------------------------
void TerrainMakingPanel::OnButton(wxCommandEvent& event)
{
	if (event.GetEventObject() == mHeightBut)
	{
		PX2_EDIT.GetTerrainEdit()->SetEditType(
			TerrainProcess::TPT_HEIGHT);

		RefreshOnTerainProcess();
	}
	else if (event.GetEventObject() == mTexBut)
	{
		PX2_EDIT.GetTerrainEdit()->SetEditType(
			TerrainProcess::TPT_TEXTURE);

		RefreshOnTerainProcess();
	}
	else if (event.GetEventObject() == mJunglerBut)
	{
		PX2_EDIT.GetTerrainEdit()->SetEditType(
			TerrainProcess::TPT_JUNGLER);

		RefreshOnTerainProcess();
	}
}
//-----------------------------------------------------------------------------
void TerrainMakingPanel::RefreshOnTerainProcess()
{
	TerrainProcess::TerProType terProType = PX2_EDIT.GetTerrainEdit()->GetEditType();
	mHeightBut->Enable(TerrainProcess::TPT_HEIGHT != terProType);
	mTexBut->Enable(TerrainProcess::TPT_TEXTURE != terProType);
	mJunglerBut->Enable(TerrainProcess::TPT_JUNGLER != terProType);
	_SetBut(mHeightBut);
	_SetBut(mTexBut);
	_SetBut(mJunglerBut);

	mHeightModeRadio->Enable(TerrainProcess::TPT_HEIGHT == terProType);

	mTexLayerRadio->Enable(TerrainProcess::TPT_TEXTURE == terProType);
	mURepeatText->Enable(TerrainProcess::TPT_TEXTURE == terProType);
	mURepeatSlider->Enable(TerrainProcess::TPT_TEXTURE == terProType);
	mVRepeatText->Enable(TerrainProcess::TPT_TEXTURE == terProType);
	mVRepeatSlider->Enable(TerrainProcess::TPT_TEXTURE == terProType);
	mLayerListCtrl->Enable(TerrainProcess::TPT_TEXTURE == terProType);
}
//-----------------------------------------------------------------------------
void TerrainMakingPanel::_SetBut(wxButton *but)
{
	if (but->IsEnabled())
	{
		but->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
		but->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT));
	}
	else
	{
		but->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
		but->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT));
	}
}
//-----------------------------------------------------------------------------
void TerrainMakingPanel::RefreshSelectPage()
{
	Project *proj = Project::GetSingletonPtr();
	if (!proj) return;

	Scene *scene = proj->GetScene();
	if (!scene) return;

	TerrainActor *terrainActor = scene->GetTerrainActor();
	if (!terrainActor) return;

	RawTerrain *terrain = terrainActor->GetRawTerrain();
	if (!terrain) return;

	int selectIndex = PX2_EDIT.GetTerrainEdit()->GetTextureProcess()->GetSelectedLayer();

	// rawPage
	PX2::TerrainPage *page = PX2_EDIT.GetTerrainEdit()->GetBrush()->GetSelectedPage();
	PX2::RawTerrainPage *rawPage = DynamicCast<RawTerrainPage>(page);

	if (rawPage && terrain)
	{
		int xIndex = 0;
		int yIndex = 0;
		terrain->GetPageIndex(xIndex, yIndex, rawPage);
		wxString strXIndex = wxString::Format("%d", xIndex);
		wxString strYIndex = wxString::Format("%d", yIndex);
		mXIndex->Clear();
		mXIndex->WriteText(strXIndex);
		mYIndex->Clear();
		mYIndex->WriteText(strYIndex);

		Float2 uv = rawPage->GetUV(selectIndex);

		PX2::Texture2D *tex2d = 0;
		tex2d = rawPage->GetTexture(selectIndex);
		if (tex2d)
		{
			wxString strU = wxString::Format("%.2f", uv[0]);
			wxString strV = wxString::Format("%.2f", uv[1]);
			mURepeatText->Clear();
			mURepeatText->WriteText(strU);
			mURepeatSlider->SetValue(int(uv[0]));

			mVRepeatText->Clear();
			mVRepeatText->WriteText(strV);
			mVRepeatSlider->SetValue(int(uv[1]));
		}
		else
		{
			mURepeatText->Clear();
			mVRepeatText->Clear();
			mURepeatSlider->SetValue(0);
			mVRepeatSlider->SetValue(0);
		}
	}
	else
	{
		mXIndex->Clear();
		mYIndex->Clear();

		mURepeatText->Clear();
		mURepeatSlider->SetValue(0);

		mVRepeatText->Clear();
		mVRepeatSlider->SetValue(0);
	}

	mTexLayerRadio->Select(selectIndex);

	mLayerListCtrl->Clear();
	if (rawPage)
	{
		for (int i = 0; i < 5; i++)
		{
			Texture2D *tex2D = rawPage->GetTexture(i);
			if (tex2D)
			{
				mLayerListCtrl->Append(tex2D->GetResourcePath());
			}
			else
			{
				mLayerListCtrl->Append("");
			}
		}
	}
}
//-----------------------------------------------------------------------------
void TerrainMakingPanel::RefleshCtrls()
{
	PX2::Project *proj = PX2::Project::GetSingletonPtr();
	if (!proj) return;

	Scene *scene = DynamicCast<Scene>(proj->GetScene());
	if (!scene) return;

	bool showPageLine = PX2_EDIT.GetTerrainEdit()->IsPageLineShow();
	mShowTerrainGrid->SetValue(showPageLine);

	float sz = PX2_EDIT.GetTerrainEdit()->GetBrush()->GetSize();
	float szValue = 10.0f * sz / SIZE_ADJUST;
	mBurshSize->SetValue((int)szValue);

	float strength = PX2_EDIT.GetTerrainEdit()->GetBrush()
		->GetStrength();
	float strengthValue = 100.0f * strength / STENGTH_ADJUST;
	mBurshStrength->SetValue((int)strengthValue);

	TerrainHeightProcess::HeightMode mode = PX2_EDIT.GetTerrainEdit()
		->GetHeightProcess()->GetHeightMode();

	if (mode == TerrainHeightProcess::HM_RAISE)
	{
		mHeightModeRadio->SetSelection(0);
	}
	else if (mode == TerrainHeightProcess::HM_LOWER)
	{
		mHeightModeRadio->SetSelection(1);
	}
	else if (mode == TerrainHeightProcess::HM_FLATTEN)
	{
		mHeightModeRadio->SetSelection(2);
	}
	else if (mode == TerrainHeightProcess::HM_SMOOTH)
	{
		mHeightModeRadio->SetSelection(3);
	}
	else if (mode == TerrainHeightProcess::HM_FIXH)
	{
		mHeightModeRadio->SetSelection(4);
	}

	std::string strFixVal = StringHelp::FloatToString(
		PX2_EDIT.GetTerrainEdit()->GetHeightProcess()->GetFixHVal());
	mFixHVal->SetValue(strFixVal);

	RefreshSelectPage();
}
//-----------------------------------------------------------------------------
void TerrainMakingPanel::OnCheckBox(wxCommandEvent &event)
{
	if (mShowTerrainGrid == event.GetEventObject())
	{
		PX2_EDIT.GetTerrainEdit()->ShowPageLine(
			mShowTerrainGrid->IsChecked());
	}
}
//-----------------------------------------------------------------------------
void TerrainMakingPanel::DoExecute(PX2::Event *event)
{
	if (EditEventSpace::IsEqual(event, EditEventSpace::SelectTerrainPage))
	{
		RefreshSelectPage();
	}
}
//-----------------------------------------------------------------------------