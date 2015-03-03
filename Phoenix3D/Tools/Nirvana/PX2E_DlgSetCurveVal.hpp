// PX2E_DlgSetCurveVal.hpp

#ifndef PX2E_DLGSETCURVEVAL_HPP
#define PX2E_DLGSETCURVEVAL_HPP

#include "PX2EditorPre.hpp"

namespace PX2Editor
{

	class DlgSetCurveVal : public wxDialog
	{
	public:
		DlgSetCurveVal(wxWindow *parent);

		void SetLabel(std::string str);
		void SetVal(float val);
		float GetVal();

		void OnButton(wxCommandEvent& event);

	protected:
		wxStaticText *mLabel;
		wxTextCtrl *mVal;
		wxButton *mOK;
		wxButton *mCancel;

		DECLARE_EVENT_TABLE();
	};

}

#endif