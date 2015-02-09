// PX2wxAui.hpp

#ifndef PX2WXAUI_HPP
#define PX2WXAUI_HPP

#include "PX2EditorPre.hpp"

namespace PX2Editor
{

	class PX2wxAuiNotebook : public wxAuiNotebook
	{
	public:
		PX2wxAuiNotebook(wxWindow* parent, bool isTop);
		~PX2wxAuiNotebook();

		void DragFun_Begin(wxAuiNotebookEvent &ent);
		void DragFun_End(wxAuiNotebookEvent &ent);
		void DragFun_Motion(wxAuiNotebookEvent &ent);
		void Tab_Click(wxAuiNotebookEvent &ent);

		void UpdateTabsHeight();

		DECLARE_EVENT_TABLE()

	protected:
		bool mIsTop;
	};

	class PX2wxAuiToolBar : public wxAuiToolBar
	{
	public:
		PX2wxAuiToolBar();

		PX2wxAuiToolBar(wxWindow* parent,
			wxWindowID id = wxID_ANY,
			const wxPoint& pos = wxDefaultPosition,
			const wxSize& size = wxDefaultSize,
			long style = wxAUI_TB_DEFAULT_STYLE);

		~PX2wxAuiToolBar();
		wxAuiToolBarItemArray GetItems();
		void SetItemsState(int state);
	};

	class PX2wxAuiToolBarArt : public wxAuiDefaultToolBarArt
	{
	public:
		PX2wxAuiToolBarArt();
		~PX2wxAuiToolBarArt();

		virtual void DrawBackground(
			wxDC& dc,
			wxWindow* wnd,
			const wxRect& rect);

		virtual void DrawPlainBackground(wxDC& dc,
			wxWindow* wnd,
			const wxRect& rect);

		virtual void DrawButton(
			wxDC& dc,
			wxWindow* wnd,
			const wxAuiToolBarItem& item,
			const wxRect& rect);

		void SetHightlightColor(wxColour color);

	protected:
		wxColour mBackColor;
	};

	class PX2wxAuiTabArt : public wxAuiSimpleTabArt
	{
	public:
		PX2wxAuiTabArt(bool isTop);
		virtual ~PX2wxAuiTabArt();

		wxAuiTabArt* Clone();

		void SetSizingInfo(const wxSize& tabCtrlSize,
			size_t tabCount);

		virtual void DrawBorder(
			wxDC& dc,
			wxWindow* wnd,
			const wxRect& rect);

		virtual void DrawBackground(
			wxDC& dc,
			wxWindow* wnd,
			const wxRect& rect);

		virtual void DrawTab(wxDC& dc,
			wxWindow* wnd,
			const wxAuiNotebookPage& pane,
			const wxRect& inRect,
			int closeButtonState,
			wxRect* outTabRect,
			wxRect* outButtonRect,
			int* xExtent);

		virtual void DrawButton(
			wxDC& dc,
			wxWindow* wnd,
			const wxRect& inRect,
			int bitmapId,
			int buttonState,
			int orientation,
			wxRect* outRect);

		virtual wxSize GetTabSize(
                 wxDC& dc,
                 wxWindow* wnd,
                 const wxString& caption,
                 const wxBitmap& bitmap,
                 bool active,
                 int closeButtonState,
                 int* xExtent);

	protected:
		bool mIsTop;
	};

}

#endif