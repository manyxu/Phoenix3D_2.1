// PX2wxAui.hpp

#ifndef PX2WXAUI_HPP
#define PX2WXAUI_HPP

#include "PX2EditorPre.hpp"

namespace PX2Editor
{

	class PX2wxAuiNotebook : public wxAuiNotebook
	{
	public:
		PX2wxAuiNotebook(wxWindow* parent);
		~PX2wxAuiNotebook();

		void DragFun_Begin(wxAuiNotebookEvent &ent);
		void DragFun_End(wxAuiNotebookEvent &ent);
		void DragFun_Motion(wxAuiNotebookEvent &ent);

		DECLARE_EVENT_TABLE()
	};

}

#endif