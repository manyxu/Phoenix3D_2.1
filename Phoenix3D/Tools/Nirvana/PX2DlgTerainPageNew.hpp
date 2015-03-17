// PX2DlgTerainPageNew.hpp

#ifndef PX2DLGTERRAINPAGENEW_HPP
#define PX2DLGTERRAINPAGENEW_HPP

#include "PX2EditorPre.hpp"

namespace PX2Editor
{

	class DlgTerrainPageNew : public wxDialog
	{
	public:
		DlgTerrainPageNew (wxWindow *parent);

		void OnButton (wxCommandEvent& event);

		int mRowI;
		int mColI;

	protected:
		DECLARE_EVENT_TABLE();

		wxTextCtrl *mRowIndex;
		wxTextCtrl *mColIndex;
		wxButton *mOK;
		wxButton *mCancel;
	};

}

#endif