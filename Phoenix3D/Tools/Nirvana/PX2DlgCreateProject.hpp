// PX2DlgCreateProject.hpp

#ifndef PX2DLGCREATEPROJECT_HPP
#define PX2DLGCREATEPROJECT_HPP

#include "PX2EditorPre.hpp"

namespace PX2Editor
{

	class DlgCreateProject : public wxDialog
	{
	public:
		DlgCreateProject(wxWindow *parent);

		void OnButton(wxCommandEvent& event);

		std::string mProjName;
		int mScreenOrientation;
		int mProjWidth;
		int mProjHeight;

	protected:
		DECLARE_EVENT_TABLE();

		wxTextCtrl *mName;
		wxChoice *mChoiceScreenOrientation;
		wxTextCtrl *mWidth;
		wxTextCtrl *mHeight;
		wxButton *mOK;
		wxButton *mCancel;
	};

}

#endif