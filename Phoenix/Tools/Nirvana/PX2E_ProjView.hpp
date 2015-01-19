// PX2E_ProjView.hpp

#ifndef PX2E_PROJVIEW_HPP
#define PX2E_PROJVIEW_HPP

#include "PX2EditorPre.hpp"

namespace PX2Editor
{

	class ProjView : public wxWindow
	{
		DECLARE_DYNAMIC_CLASS(ProjView)

	public:
		ProjView(wxWindow *parent);
		virtual ~ProjView();

	protected:
		DECLARE_EVENT_TABLE()

		ProjView();

		wxToolBar *mResTreeBar;
	};

}

#endif