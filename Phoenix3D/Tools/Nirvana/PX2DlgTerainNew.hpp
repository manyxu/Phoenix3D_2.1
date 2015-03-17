// PX2DlgTerainNew.hpp

#ifndef PX2DLGTERRAINNEW_HPP
#define PX2DLGTERRAINNEW_HPP

#include "PX2EditorPre.hpp"

namespace PX2Editor
{

	class DlgTerrainNew : public wxDialog
	{
	public:
		DlgTerrainNew (wxWindow *parent);

		void OnButton (wxCommandEvent& event);

		std::string mValue_TerrainName;
		int mValue_TerrainWidth;
		int mValue_PageWidth;
		float mValue_GridSpace;

	protected:
		wxButton *mTerrainOK;
		wxButton *mTerrainCancel;
		wxTextCtrl *mTerrainName;
		wxComboBox *mTerrainWidth;
		wxComboBox *mPageWidth;
		wxTextCtrl *mGridSpace;

		DECLARE_EVENT_TABLE();
	};

}

#endif