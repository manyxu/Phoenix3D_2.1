// PX2_MakingWindow.hpp

#ifndef PX2E_MAKINGWINDOW_HPP
#define PX2E_MAKINGWINDOW_HPP

#include "PX2EditorPre.hpp"
#include "PX2Object.hpp"

namespace PX2Editor
{

	class MakingWindow : public wxScrolled<wxWindow>
	{
	public:
		MakingWindow(wxWindow *parent);
		~MakingWindow();

		void OnSize(wxSizeEvent& e);

	protected:
		DECLARE_EVENT_TABLE()
		void SetObject(PX2::Object *object);
		void ChangeToWindow(const std::string &str, int userData = 0);

		PX2::ObjectPtr mObject;
		std::string mCurWinStr;
		wxWindow *mCurWindow;
		wxSize mCurWindowOriginSize;
	};

}

#endif