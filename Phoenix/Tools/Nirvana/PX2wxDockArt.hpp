/*
*
* ÎÄ¼þÃû³Æ	£º	PX2NwxDockArt.hpp
*
*/

#ifndef PX2NWXDOCKART_HPP
#define PX2NWXDOCKART_HPP

#include "PX2EditorPre.hpp"

class PX2wxDockArt : public wxAuiDefaultDockArt
{
public:
	PX2wxDockArt();

	int GetMetric(int metricId);
	void SetMetric(int metricId, int newVal);
	wxColour GetColour(int id);
	void SetColour(int id, const wxColor& colour);
	void SetFont(int id, const wxFont& font);
	wxFont GetFont(int id);

	void DrawSash(wxDC& dc,
		wxWindow *window,
		int orientation,
		const wxRect& rect);

	void DrawBackground(wxDC& dc,
		wxWindow *window,
		int orientation,
		const wxRect& rect);

	void DrawCaption(wxDC& dc,
		wxWindow *window,
		const wxString& text,
		const wxRect& rect,
		wxAuiPaneInfo& pane);

	void DrawGripper(wxDC& dc,
		wxWindow *window,
		const wxRect& rect,
		wxAuiPaneInfo& pane);

	void DrawBorder(wxDC& dc,
		wxWindow *window,
		const wxRect& rect,
		wxAuiPaneInfo& pane);

	void DrawPaneButton(wxDC& dc,
		wxWindow *window,
		int button,
		int buttonState,
		const wxRect& rect,
		wxAuiPaneInfo& pane);

	void DrawIcon(wxDC& dc,
		const wxRect& rect,
		wxAuiPaneInfo& pane);

protected:

	void DrawCaptionBackground(wxDC& dc, const wxRect& rect, bool active);

	void InitBitmaps();
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

protected:
	wxColour mBackColor;
};

class PX2wxAuiTabArt : public wxAuiSimpleTabArt
{
public:
	PX2wxAuiTabArt();
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
};

#endif