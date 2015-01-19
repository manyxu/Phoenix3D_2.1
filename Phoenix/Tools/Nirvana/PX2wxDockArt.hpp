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

#endif