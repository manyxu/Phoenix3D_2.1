// PX2E_ResSplitPanel.hpp

#ifndef PX2E_RESSPLITPANEL_HPP
#define PX2E_RESSPLITPANEL_HPP

#include "PX2EditorPre.hpp"

namespace PX2Editor
{

	class ResSplitPanel : public wxPanel
	{
	public:

		ResSplitPanel(wxWindow* parent, bool useSplit, wxWindowID id = wxID_ANY, 
			const wxPoint& pos = wxDefaultPosition,
			const wxSize& size = wxSize(500, 300), long style = wxTAB_TRAVERSAL);
		~ResSplitPanel();

		void mSplitterOnIdle(wxIdleEvent&)
		{
			mSplitter->SetSashPosition(150);
			mSplitter->Disconnect(wxEVT_IDLE, 
				wxIdleEventHandler(ResSplitPanel::mSplitterOnIdle), NULL, this);
		}

	protected:
		wxSplitterWindow* mSplitter;
		wxPanel* mLeftPanel;
		wxPanel* mRightPanel;
	};

}

#endif