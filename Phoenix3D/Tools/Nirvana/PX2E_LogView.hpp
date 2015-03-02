// PX2E_LogView.hpp

#ifndef PX2E_LOGVIEW_HPP
#define PX2E_LOGVIEW_HPP

#include "PX2EditorPre.hpp"
#include "PX2E_LogTextCtrl.hpp"

namespace PX2Editor
{

	class PX2wxAuiToolBar;

	class LogView : public wxWindow
	{
	public:
		LogView(wxWindow *parent);
		~LogView();

		void OnClear(wxCommandEvent& event);
		void OnTextEnter(wxCommandEvent& event);

		LogTextCtrl *GetLogTextCtrl() const;

	protected:
		DECLARE_EVENT_TABLE()

		PX2wxAuiToolBar *mToolBar;
		wxTextCtrl *mCommondTextCtrl;
		LogTextCtrl *mTextCtrl;
	};

}

#endif