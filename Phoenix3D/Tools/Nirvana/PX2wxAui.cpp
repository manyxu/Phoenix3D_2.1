// PX2wxAui.cpp

#include "PX2wxAui.hpp"
#include "PX2EngineLoop.hpp"
#include "PX2NirvanaUIEventType.hpp"
#include "PX2E_MainFrame.hpp"
#include "PX2Edit.hpp"
#include "PX2EditParams.hpp"
using namespace PX2Editor;

BEGIN_EVENT_TABLE(PX2wxAuiNotebook, wxAuiNotebook)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
PX2wxAuiNotebook::PX2wxAuiNotebook(wxWindow* parent, bool isTop) :
wxAuiNotebook(parent),
mIsTop(isTop)
{
	m_selectedFont.SetWeight(wxNORMAL);

	Connect(wxEVT_COMMAND_AUINOTEBOOK_BEGIN_DRAG,
		wxAuiNotebookEventHandler(PX2wxAuiNotebook::DragFun_Begin));

	Connect(wxEVT_COMMAND_AUINOTEBOOK_END_DRAG,
		wxAuiNotebookEventHandler(PX2wxAuiNotebook::DragFun_End));

	Connect(wxEVT_COMMAND_AUINOTEBOOK_DRAG_MOTION,
		wxAuiNotebookEventHandler(PX2wxAuiNotebook::DragFun_Motion));
	Connect(wxEVT_COMMAND_AUINOTEBOOK_PAGE_CHANGED,
		wxAuiNotebookEventHandler(PX2wxAuiNotebook::Tab_Click));
}
//----------------------------------------------------------------------------
PX2wxAuiNotebook::~PX2wxAuiNotebook()
{
}
//----------------------------------------------------------------------------
void PX2wxAuiNotebook::DragFun_Begin(wxAuiNotebookEvent &evt)
{
	Freeze();
	wxAuiTabCtrl* src_tabs = (wxAuiTabCtrl*)evt.GetEventObject();
	if (src_tabs)
	{
		int numPages = m_tabs.GetPageCount();

		if (numPages > 1)
		{
			src_tabs->SetCursor(wxCursor(wxCURSOR_ARROW));
			int src_idx = evt.GetSelection();
			wxWindow *window = GetPage(src_idx);
			RemovePage(src_idx);
			Update();

			Event *ent = NirvanaUIEventSpace::CreateEventX(NirvanaUIEventSpace::TabDrag);
			ent->SetData<wxWindow*>(window);
			PX2_EW.BroadcastingLocalEvent(ent);
		}
		
		UpdateTabsHeight();
		Thaw();
		Refresh();
	}
	
}
//----------------------------------------------------------------------------
void PX2wxAuiNotebook::DragFun_End(wxAuiNotebookEvent &ent)
{
}
//----------------------------------------------------------------------------
void PX2wxAuiNotebook::DragFun_Motion(wxAuiNotebookEvent &ent)
{
}
//----------------------------------------------------------------------------
void PX2wxAuiNotebook::Tab_Click(wxAuiNotebookEvent &ent)
{
	int numPages = m_tabs.GetPageCount();

	if (numPages > 1)
	{
		wxAuiManager *auiMan = E_MainFrame::GetSingleton().GetAuiMananger();
		if (auiMan)
		{
			int src_idx = ent.GetSelection();
			wxString title = GetPageText(src_idx);
			wxString paneName = "Right";
			auiMan->GetPane(paneName).caption = title;
			auiMan->Update();
		}
	}
}
//----------------------------------------------------------------------------
void PX2wxAuiNotebook::UpdateTabsHeight()
{
	if (!mIsTop)
	{
		int numPages = m_tabs.GetPageCount();
		if (1 == numPages)
		{
			SetTabCtrlHeight(0);
		}
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
PX2wxAuiToolBarArt::PX2wxAuiToolBarArt()
{
}
//----------------------------------------------------------------------------
PX2wxAuiToolBarArt::~PX2wxAuiToolBarArt()
{

}
//----------------------------------------------------------------------------
void PX2wxAuiToolBarArt::DrawBackground(
	wxDC& dc,
	wxWindow*,
	const wxRect& _rect)
{
	wxRect rect = _rect;
	rect.height++;

	EditParams *params = PX2_EDIT.GetEditParams();
	if (params)
	{
		EditParams::Theme theme = params->GetCurTheme();
		float r = theme.inactiveColor[0] * 255.0f;
		float g = theme.inactiveColor[1] * 255.0f;
		float b = theme.inactiveColor[2] * 255.0f;
		//wxColour color = wxColour(207, 214, 229);
		wxColour color = wxColour(r, g, b);
		wxColour startColour = color.ChangeLightness(125);
		wxColour endColour = color.ChangeLightness(125);

		dc.GradientFillLinear(rect, color, color, wxSOUTH);
	}
}
//----------------------------------------------------------------------------
void PX2wxAuiToolBarArt::DrawPlainBackground(wxDC& dc,
	wxWindow*,
	const wxRect& _rect)
{
	wxRect rect = _rect;
	rect.height++;

	EditParams *params = PX2_EDIT.GetEditParams();
	if (params)
	{
		EditParams::Theme theme = params->GetCurTheme();
		float r = theme.inactiveColor[0] * 255.0f;
		float g = theme.inactiveColor[1] * 255.0f;
		float b = theme.inactiveColor[2] * 255.0f;
		//dc.SetBrush(wxColour(214, 219, 233));
		dc.SetBrush(wxColour(r, g, b));

		dc.DrawRectangle(rect.GetX() - 1, rect.GetY() - 1,
			rect.GetWidth() + 2, rect.GetHeight() + 1);
	}
}
//----------------------------------------------------------------------------
PX2wxAuiTabArt::PX2wxAuiTabArt(bool isTop)
{
	m_fixedTabWidth = 80;
	mIsTop = isTop;
}
//----------------------------------------------------------------------------
PX2wxAuiTabArt::~PX2wxAuiTabArt()
{
}
//----------------------------------------------------------------------------
wxAuiTabArt* PX2wxAuiTabArt::Clone()
{
	return new PX2wxAuiTabArt(*this);
}
//----------------------------------------------------------------------------
void PX2wxAuiTabArt::SetSizingInfo(const wxSize& tab_ctrl_size,
	size_t tab_count)
{
	m_fixedTabWidth = 120;

	int tot_width = (int)tab_ctrl_size.x - GetIndentSize() - 4;

	if (m_flags & wxAUI_NB_CLOSE_BUTTON)
		tot_width -= m_activeCloseBmp.GetWidth();
	if (m_flags & wxAUI_NB_WINDOWLIST_BUTTON)
		tot_width -= m_activeWindowListBmp.GetWidth();

	if (tab_count > 0)
	{
		m_fixedTabWidth = tot_width / (int)tab_count;
	}


	if (m_fixedTabWidth < 120)
		m_fixedTabWidth = 120;

	if (m_fixedTabWidth > tot_width / 2)
		m_fixedTabWidth = tot_width / 2;

	if (m_fixedTabWidth > 160)
		m_fixedTabWidth = 120;
}
//----------------------------------------------------------------------------
void PX2wxAuiTabArt::DrawBorder(wxDC& dc, wxWindow* wnd, const wxRect& rect)
{
	int i, border_width = GetBorderWidth(wnd);

	wxRect theRect(rect);
	for (i = 0; i < border_width; ++i)
	{
		dc.DrawRectangle(theRect.x, theRect.y, theRect.width, theRect.height);
		theRect.Deflate(1);
	}
}
//----------------------------------------------------------------------------
void PX2wxAuiTabArt::DrawBackground(wxDC& dc, wxWindow*,
	const wxRect& rect)
{
	//dc.SetBrush(wxBrush(wxColour(44, 61, 91)));
	EditParams *params = PX2_EDIT.GetEditParams();
	if (params)
	{
		EditParams::Theme theme = params->GetCurTheme();
		float r = theme.tabBackColor[0] * 255.0f;
		float g = theme.tabBackColor[1] * 255.0f;
		float b = theme.tabBackColor[2] * 255.0f;
		dc.SetBrush(wxBrush(wxColour(r, g, b)));
		dc.DrawRectangle(-1, -5, rect.GetWidth() + 2, rect.GetHeight() + 5);

		//// draw base line
		if (mIsTop)
		{
			r = theme.activeColor[0] * 255.0f;
			g = theme.activeColor[1] * 255.0f;
			b = theme.activeColor[2] * 255.0f;
			dc.SetBrush(wxBrush(wxColour(r, g, b)));
			dc.DrawRectangle(-1, rect.GetHeight() - 4, rect.GetWidth() + 2, 4);
		}
	}
}
//----------------------------------------------------------------------------
static void DrawButtons(wxDC& dc,
	const wxRect& _rect,
	const wxBitmap& bmp,
	const wxColour& bkcolour,
	int button_state)
{
	wxRect rect = _rect;

	if (button_state == wxAUI_BUTTON_STATE_PRESSED)
	{
		rect.x++;
		rect.y++;
	}

	if (button_state == wxAUI_BUTTON_STATE_HOVER ||
		button_state == wxAUI_BUTTON_STATE_PRESSED)
	{
		dc.SetBrush(wxBrush(bkcolour.ChangeLightness(120)));
		dc.SetPen(wxPen(bkcolour.ChangeLightness(75)));

		// draw the background behind the button
		dc.DrawRectangle(rect.x, rect.y, 15, 15);
	}

	// draw the button itself
	dc.DrawBitmap(bmp, rect.x, rect.y, true);
}
//----------------------------------------------------------------------------
wxString wxAuiChopText(wxDC& dc, const wxString& text, int max_size);
//----------------------------------------------------------------------------
void PX2wxAuiTabArt::DrawTab(wxDC& dc,
	wxWindow* wnd,
	const wxAuiNotebookPage& page,
	const wxRect& in_rect,
	int close_button_state,
	wxRect* out_tab_rect,
	wxRect* out_button_rect,
	int* x_extent)
{
	wxCoord normal_textx, normal_texty;
	wxCoord selected_textx, selected_texty;
	wxCoord textx, texty;

	// if the caption is empty, measure some temporary text
	wxString caption = page.caption;
	if (caption.empty())
		caption = wxT("Xj");

	dc.SetFont(m_selectedFont);
	dc.GetTextExtent(caption, &selected_textx, &selected_texty);

	dc.SetFont(m_normalFont);
	dc.GetTextExtent(caption, &normal_textx, &normal_texty);

	// figure out the size of the tab
	wxSize tab_size = GetTabSize(dc,
		wnd,
		page.caption,
		page.bitmap,
		page.active,
		close_button_state,
		x_extent);

	wxCoord tab_height = tab_size.y;
	wxCoord tab_width = tab_size.x;
	wxCoord tab_x = in_rect.x;
	wxCoord tab_y = in_rect.y + in_rect.height - tab_height;

	caption = page.caption;

	// select pen, brush and font for the tab to be drawn
	EditParams *params = PX2_EDIT.GetEditParams();
	if (params)
	{
		EditParams::Theme theme = params->GetCurTheme();

		if (page.active)
		{
			if (mIsTop)
			{
				float r = theme.activeColor[0] * 255.0f;
				float g = theme.activeColor[1] * 255.0f;
				float b = theme.activeColor[2] * 255.0f;
				dc.SetPen(wxPen(wxColour(r, g, b)));
				dc.SetBrush(wxColour(r, g, b));
				dc.SetFont(m_selectedFont);
			}
			else
			{
				int r = theme.backColor[0] * 255.0f;
				int g = theme.backColor[1] * 255.0f;
				int b = theme.backColor[2] * 255.0f;
				dc.SetPen(wxPen(wxColour(r, g, b)));
				dc.SetBrush(wxColour(r, g, b));
				dc.SetFont(m_selectedFont);
			}

			textx = selected_textx;
			texty = selected_texty;
		}
		else
		{
			int r = theme.inactiveColor[0] * 255.0f;
			int g = theme.inactiveColor[1] * 255.0f;
			int b = theme.inactiveColor[2] * 255.0f;
			if (mIsTop)
			{
				dc.SetPen(wxPen(wxColour(r, g, b)));
				dc.SetBrush(wxColour(r, g, b));
			}
			else
			{
				dc.SetPen(wxPen(wxColour(r, g, b)));
				dc.SetBrush(wxColour(r, g, b));
			}

			dc.SetFont(m_normalFont);
			textx = normal_textx;
			texty = normal_texty;
		}
	}
	

	// -- draw line --

	wxPoint points[5];
	points[0].x = tab_x;
	points[0].y = tab_y;
	points[1].x = tab_x + tab_width;
	points[1].y = tab_y;
	points[2].x = tab_x + tab_width;
	points[2].y = tab_y + tab_height;
	points[3].x = tab_x;
	points[3].y = tab_y + tab_height;
	points[4] = points[0];

	if (mIsTop)
	{
		points[0].y -= 4;
		points[1].y -= 4;

		points[2].y = tab_y + tab_height - 4;
		points[3].y = tab_y + tab_height - 4;	
	}
	else
	{
		points[0].y -= 4;
		points[1].y -= 4;

		points[2].y = tab_y + tab_height - 4;
		points[3].y = tab_y + tab_height - 4;
	}

	dc.SetClippingRegion(in_rect);

	dc.DrawPolygon(WXSIZEOF(points) - 1, points);

	dc.SetPen(*wxGREY_PEN);

	//dc.DrawLines(active ? WXSIZEOF(points) - 1 : WXSIZEOF(points), points);
	//dc.DrawLines(WXSIZEOF(points), points);


	int text_offset;

	int close_button_width = 0;
	if (close_button_state != wxAUI_BUTTON_STATE_HIDDEN)
	{
		close_button_width = m_activeCloseBmp.GetWidth();
		text_offset = tab_x + ((tab_width - close_button_width) / 2) - (textx / 2);
	}
	else
	{
		text_offset = tab_x + (tab_width - textx)/ 2 ;
	}

	if (page.active)
		dc.SetTextForeground(wxColour(0, 0, 0));
	else
		dc.SetTextForeground(wxColour(255, 255, 255));

	// chop text if necessary
	wxString draw_text = wxAuiChopText(dc,
		caption,
		tab_width - (text_offset - tab_x) - close_button_width);

	// draw tab text
	dc.DrawText(draw_text,
		text_offset,
		(tab_y + tab_height - texty) / 2);

	// draw focus rectangle
	if (page.active && (wnd->FindFocus() == wnd))
	{
		wxRect focusRect(text_offset, ((tab_y + tab_height) / 2 - (texty / 2) + 1),
			selected_textx, selected_texty);

		focusRect.Inflate(2, 2);

		wxRendererNative::Get().DrawFocusRect(wnd, dc, focusRect, 0);
	}

	// draw close button if necessary
	if (close_button_state != wxAUI_BUTTON_STATE_HIDDEN)
	{
		wxBitmap bmp;
		if (page.active)
			bmp = m_activeCloseBmp;
		else
			bmp = m_disabledCloseBmp;

		wxRect rect(tab_x + tab_width - close_button_width - 1,
			tab_y + (tab_height / 2) - (bmp.GetHeight() / 2) + 1,
			close_button_width,
			tab_height - 1);
		DrawButtons(dc, rect, bmp, *wxWHITE, close_button_state);

		*out_button_rect = rect;
	}


	*out_tab_rect = wxRect(tab_x, tab_y, tab_width, tab_height);

	dc.DestroyClippingRegion();	
}
//----------------------------------------------------------------------------
void PX2wxAuiTabArt::DrawButton(wxDC& dc,
	wxWindow* WXUNUSED(wnd),
	const wxRect& in_rect,
	int bitmap_id,
	int button_state,
	int orientation,
	wxRect* out_rect)
{
	wxBitmap bmp;
	wxRect rect;

	switch (bitmap_id)
	{
	case wxAUI_BUTTON_CLOSE:
		if (button_state & wxAUI_BUTTON_STATE_DISABLED)
			bmp = m_disabledCloseBmp;
		else
			bmp = m_activeCloseBmp;
		break;
	case wxAUI_BUTTON_LEFT:
		if (button_state & wxAUI_BUTTON_STATE_DISABLED)
			bmp = m_disabledLeftBmp;
		else
			bmp = m_activeLeftBmp;
		break;
	case wxAUI_BUTTON_RIGHT:
		if (button_state & wxAUI_BUTTON_STATE_DISABLED)
			bmp = m_disabledRightBmp;
		else
			bmp = m_activeRightBmp;
		break;
	case wxAUI_BUTTON_WINDOWLIST:
		if (button_state & wxAUI_BUTTON_STATE_DISABLED)
			bmp = m_disabledWindowListBmp;
		else
			bmp = m_activeWindowListBmp;
		break;
	}

	if (!bmp.IsOk())
		return;

	rect = in_rect;

	if (orientation == wxLEFT)
	{
		rect.SetX(in_rect.x);
		rect.SetY(((in_rect.y + in_rect.height) / 2) - (bmp.GetHeight() / 2));
		rect.SetWidth(bmp.GetWidth());
		rect.SetHeight(bmp.GetHeight());
	}
	else
	{
		rect = wxRect(in_rect.x + in_rect.width - bmp.GetWidth(),
			((in_rect.y + in_rect.height) / 2) - (bmp.GetHeight() / 2),
			bmp.GetWidth(), bmp.GetHeight());
	}


	DrawButtons(dc, rect, bmp, wxColour(255, 242, 244), button_state);

	*out_rect = rect;
}
//----------------------------------------------------------------------------
wxSize PX2wxAuiTabArt::GetTabSize(wxDC& dc,
	wxWindow* WXUNUSED(wnd),
	const wxString& caption,
	const wxBitmap& WXUNUSED(bitmap),
	bool WXUNUSED(active),
	int closeButtonState,
	int* xExtent)
{
	wxCoord measured_textx, measured_texty;

	dc.SetFont(m_measuringFont);
	dc.GetTextExtent(caption, &measured_textx, &measured_texty);

	wxCoord tab_height = measured_texty + 5;
	wxCoord tab_width = measured_textx  + 6;

	if (closeButtonState != wxAUI_BUTTON_STATE_HIDDEN)
		tab_width += m_activeCloseBmp.GetWidth();

	if (m_flags & wxAUI_NB_TAB_FIXED_WIDTH)
	{
		tab_width = m_fixedTabWidth;
	}

	*xExtent = tab_width + 1;

	return wxSize(tab_width, tab_height);
}