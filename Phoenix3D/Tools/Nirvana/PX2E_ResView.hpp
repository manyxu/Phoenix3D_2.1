// PX2E_ResView.hpp

#ifndef PX2E_RESVIEW_HPP
#define PX2E_RESVIEW_HPP

#include "PX2EditorPre.hpp"
#include "PX2EditParams.hpp"
#include "PX2wxAui.hpp"
#include "PX2E_ResSplitPanel.hpp"
#include "PX2E_ResTreeItem.hpp"

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

		PX2wxAuiToolBar *mResTreeBar;
		wxSplitterWindow *mSplitter;

		ResSplitPanel *mSplitPanel;
		wxSearchCtrl *mSearchCtrl;

		void Splitter1OnIdle(wxIdleEvent&)
		{
			mSplitter->SetSashPosition(120);
			mSplitter->Disconnect(wxEVT_IDLE, wxIdleEventHandler(ResView::Splitter1OnIdle), NULL, this);
		}
	};

}

#endif