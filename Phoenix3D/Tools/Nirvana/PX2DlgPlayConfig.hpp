// PX2DlgPlayConfig.hpp

#ifndef PX2DLGPLAYCONFIG_HPP
#define PX2DLGPLAYCONFIG_HPP

#include "PX2EditorPre.hpp"

namespace PX2
{

	class DlgPlayConfig : public wxDialog
	{
	public:
		DlgPlayConfig(wxWindow *parent);

		void OnButton(wxCommandEvent& event);

	protected:
		DECLARE_EVENT_TABLE();

		wxComboBox *mGP_Pix;
		wxComboBox *mEP_CtrlType;
		wxButton *mOK;
		wxButton *mCancel;
	};

}

#endif