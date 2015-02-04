// PX2E_ResView.hpp

#ifndef PX2E_RESVIEW_HPP
#define PX2E_RESVIEW_HPP

#include "PX2EditorPre.hpp"
#include "PX2EditParams.hpp"
#include "PX2E_ResSplitPanel.hpp"
#include "PX2E_ResTreeItem.hpp"
using namespace PX2;

namespace PX2Editor
{

	class ResView : public wxWindow
	{
		DECLARE_DYNAMIC_CLASS(ResView)

	public:
		ResView(wxWindow *parent);
		virtual ~ResView();

		void SetColorForTheme(EditParams::Theme theme);
		void SetColorTreeItem(EditParams::Theme theme, ResTreeItem *treeItem);

	protected:
		DECLARE_EVENT_TABLE()
		ResView();

		wxToolBar *mResTreeBar;
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