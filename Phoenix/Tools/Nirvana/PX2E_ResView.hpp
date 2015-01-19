// PX2E_ResView.hpp

#ifndef PX2E_RESVIEW_HPP
#define PX2E_RESVIEW_HPP

#include "PX2EditorPre.hpp"

namespace PX2Editor
{

	class ResView : public wxWindow
	{
		DECLARE_DYNAMIC_CLASS(ResView)

	public:
		ResView(wxWindow *parent);
		virtual ~ResView();

	protected:
		DECLARE_EVENT_TABLE()
		ResView();

		wxToolBar *mResTreeBar;
	};

}

#endif