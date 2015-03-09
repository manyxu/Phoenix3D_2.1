// PX2E_StartView.hpp

#ifndef PX2E_STARTVIEW_HPP
#define PX2E_STARTVIEW_HPP

#include "PX2EditorPre.hpp"

namespace PX2Editor
{

	class StartView : public wxPanel
	{
		DECLARE_DYNAMIC_CLASS(StartView)

	public:
		StartView(wxWindow *parent);
		virtual ~StartView();

		void OnButton(wxCommandEvent& event);

	protected:
		DECLARE_EVENT_TABLE()

		StartView();
	};

}

#endif