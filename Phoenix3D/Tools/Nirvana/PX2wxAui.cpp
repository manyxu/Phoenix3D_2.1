// PX2wxAui.cpp

#include "PX2wxAui.hpp"
using namespace PX2Editor;

BEGIN_EVENT_TABLE(PX2wxAuiNotebook, wxAuiNotebook)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
PX2wxAuiNotebook::PX2wxAuiNotebook(wxWindow* parent) :
wxAuiNotebook(parent)
{
	Connect(wxEVT_COMMAND_AUINOTEBOOK_BEGIN_DRAG,
		wxAuiNotebookEventHandler(PX2wxAuiNotebook::DragFun_Begin));

	Connect(wxEVT_COMMAND_AUINOTEBOOK_END_DRAG,
		wxAuiNotebookEventHandler(PX2wxAuiNotebook::DragFun_End));

	Connect(wxEVT_COMMAND_AUINOTEBOOK_DRAG_MOTION,
		wxAuiNotebookEventHandler(PX2wxAuiNotebook::DragFun_Motion));
}
//----------------------------------------------------------------------------
PX2wxAuiNotebook::~PX2wxAuiNotebook()
{
}
//----------------------------------------------------------------------------
void PX2wxAuiNotebook::DragFun_Begin(wxAuiNotebookEvent &evt)
{
	wxAuiTabCtrl* src_tabs = (wxAuiTabCtrl*)evt.GetEventObject();

	if (src_tabs)
	{
		src_tabs->SetCursor(wxCursor(wxCURSOR_ARROW));
		int src_idx = evt.GetSelection();
		DeletePage(src_idx);

		int numPages = m_tabs.GetPageCount();
		if (0 == numPages)
		{

		}
		else if (1 == numPages)
		{
			SetTabCtrlHeight(0);
		}
	}
}
//----------------------------------------------------------------------------
void PX2wxAuiNotebook::DragFun_End(wxAuiNotebookEvent &ent)
{

}
void PX2wxAuiNotebook::DragFun_Motion(wxAuiNotebookEvent &ent)
{

}
//----------------------------------------------------------------------------