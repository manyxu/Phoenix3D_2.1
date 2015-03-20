// PX2TerrainMakingPanel.hpp

#ifndef PX2TERRAINMAKINGPANEL_HPP
#define PX2TERRAINMAKINGPANEL_HPP

#include "PX2EditorPre.hpp"
#include "PX2EventHandler.hpp"

namespace PX2Editor
{

	class TerrainMakingPanel : public PX2::EventHandler, public wxPanel
	{
	public:
		TerrainMakingPanel(wxWindow *parent);
		virtual ~TerrainMakingPanel();

		void OnChoice(wxCommandEvent &event);
		void OnSliderUpdate(wxCommandEvent &event);
		void OnRadio(wxCommandEvent &event);
		void OnListboxDClick(wxCommandEvent& event);
		void OnTextEnter(wxCommandEvent& event);
		void OnButton(wxCommandEvent& event);
		void OnCheckBox(wxCommandEvent &event);

		void RefleshCtrls();
		void RefreshOnTerainProcess();
		void RefreshSelectPage();

		virtual void DoExecute(PX2::Event *event);

	protected:
		DECLARE_EVENT_TABLE();
		void _SetBut(wxButton *but);

		wxButton *mHeightBut;
		wxButton *mTexBut;
		wxButton *mJunglerBut;

		wxChoice *mInterplate;
		wxSlider *mBurshSize;
		wxSlider *mBurshStrength;

		wxRadioBox *mHeightModeRadio;
		wxTextCtrl *mFixHVal;

		wxRadioBox *mTexLayerRadio;

		wxTextCtrl *mXIndex;
		wxTextCtrl *mYIndex;
		wxTextCtrl *mURepeatText;
		wxSlider *mURepeatSlider;
		wxTextCtrl *mVRepeatText;
		wxSlider *mVRepeatSlider;

		wxListBox *mLayerListCtrl;

		wxCheckBox *mShowTerrainGrid;
	};

}

#endif