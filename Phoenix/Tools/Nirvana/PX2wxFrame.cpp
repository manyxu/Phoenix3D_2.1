/*
*
* ÎÄ¼þÃû³Æ	£º	PX2MainFrame.cpp
*
*/

#include "PX2wxFrame.hpp"
using namespace PX2Editor;
using namespace PX2;

//----------------------------------------------------------------------------
#define ID_FRAMETIMER (wxID_HIGHEST+1)
//----------------------------------------------------------------------------
BEGIN_EVENT_TABLE(PX2WXFrame, wxFrame)
EVT_TIMER(ID_FRAMETIMER, PX2WXFrame::OnTimer)
EVT_SIZE(PX2WXFrame::OnSize)
EVT_MOTION(PX2WXFrame::OnMotion)
EVT_ENTER_WINDOW(PX2WXFrame::OnEnterWindow)
EVT_LEAVE_WINDOW(PX2WXFrame::OnLeaveWindow)
EVT_LEFT_DOWN(PX2WXFrame::OnLeftDown)
EVT_LEFT_UP(PX2WXFrame::OnLeftUp)
END_EVENT_TABLE();
//----------------------------------------------------------------------------
PX2WXFrame::PX2WXFrame(const std::string &title, int xPos, int yPos,
	int width, int height) :
wxFrame(0, -1, title, wxPoint(xPos, yPos), wxSize(width, height), 
	wxSYSTEM_MENU | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX | wxCLIP_CHILDREN)
{
	mBorderSize = wxSize(6, 6);
	mIsMouseDown_Left = false;
	mIsDoSizing = false;
	mSizeDir = 0;

	mTimer.SetOwner(this, ID_FRAMETIMER);
	mTimer.Start(25);
}
//----------------------------------------------------------------------------
PX2WXFrame::~PX2WXFrame()
{
}
//----------------------------------------------------------------------------
void PX2WXFrame::OnTimer(wxTimerEvent& e)
{
	if (mIsDoSizing)
		_Sizing();

	PX2_UNUSED(e);
}
//----------------------------------------------------------------------------
void PX2WXFrame::OnSize(wxSizeEvent& e)
{
	PX2_UNUSED(e);
}
//----------------------------------------------------------------------------
void PX2WXFrame::OnMotion(wxMouseEvent& e)
{
	PX2_UNUSED(e);

	if (!mIsDoSizing)
	{
		_CalIsInSizingRange();
	}
}
//----------------------------------------------------------------------------
void PX2WXFrame::OnEnterWindow(wxMouseEvent& e)
{
	PX2_UNUSED(e);
}
//----------------------------------------------------------------------------
void PX2WXFrame::OnLeaveWindow(wxMouseEvent& e)
{
	PX2_UNUSED(e);
}
//----------------------------------------------------------------------------
void PX2WXFrame::OnLeftDown(wxMouseEvent& e)
{
	PX2_UNUSED(e);

	mIsMouseDown_Left = true;

	if (_CalIsInSizingRange())
	{
		mIsDoSizing = true;
	}
}
//----------------------------------------------------------------------------
void PX2WXFrame::OnLeftUp(wxMouseEvent& e)
{
	PX2_UNUSED(e);

	mIsMouseDown_Left = false;

	if (mIsDoSizing)
	{
		mIsDoSizing = false;
	}
}
//----------------------------------------------------------------------------
bool PX2WXFrame::_CalIsInSizingRange()
{
	wxPoint mousePos = wxGetMousePosition();
	mBeforeSizingRect = GetRect();

	// border
	wxRect clientRect = mBeforeSizingRect;
	clientRect.x += mBorderSize.GetWidth();
	clientRect.y += mBorderSize.GetHeight();
	clientRect.width -= mBorderSize.GetWidth()*2.0f;
	clientRect.height -= mBorderSize.GetHeight()*2.0f;

	bool isInSizingRange = !clientRect.Contains(mousePos);

	if (isInSizingRange)
	{
		mSizeDir = _CalSizeDir(mBeforeSizingRect, mBorderSize, mousePos);

		if (1==mSizeDir || 2==mSizeDir)
		{
			SetCursor(wxCURSOR_SIZEWE);
		}
		else if(3==mSizeDir || 4==mSizeDir)
		{
			SetCursor(wxCURSOR_SIZENS);
		}
		else if (5==mSizeDir||6==mSizeDir)
		{
			SetCursor(wxCURSOR_SIZENWSE);
		}
		else if (7==mSizeDir||8==mSizeDir)
		{
			SetCursor(wxCURSOR_SIZENESW);
		}
		else
		{
			SetCursor(wxCURSOR_ARROW);
		}
	}
	else
	{
		mSizeDir = 0;
		SetCursor(wxCURSOR_ARROW);
	}

	return isInSizingRange;
}
//----------------------------------------------------------------------------
int PX2WXFrame::_CalSizeDir(const wxRect &frameRect, const wxSize &borderSize,
	const wxPoint &mousePos)
{
	wxRect rectLT = wxRect(frameRect.x, frameRect.y, borderSize.GetWidth(), borderSize.GetHeight());
	wxRect rectRT = wxRect(frameRect.GetRight() - borderSize.GetWidth(), frameRect.y, borderSize.GetWidth(), borderSize.GetHeight());

	wxRect rectLB = wxRect(frameRect.x, frameRect.GetBottom() - borderSize.GetHeight(), borderSize.GetWidth(), borderSize.GetHeight());
	wxRect rectRB = wxRect(frameRect.GetRight() - borderSize.GetWidth(), frameRect.GetBottom()-borderSize.GetHeight(),
		borderSize.GetWidth(), borderSize.GetHeight());

	wxRect rectT = wxRect(frameRect.x+borderSize.GetWidth(), frameRect.y, 
		frameRect.GetWidth() - borderSize.GetWidth()*2.0f, borderSize.GetHeight());
	wxRect rectB = wxRect(frameRect.x + borderSize.GetWidth(), frameRect.GetBottom() - borderSize.GetHeight(),
		frameRect.GetWidth() - borderSize.GetWidth()*2.0f, borderSize.GetHeight());

	wxRect rectL = wxRect(frameRect.x, frameRect.y+borderSize.GetHeight(),
		borderSize.GetWidth(), frameRect.GetHeight()-borderSize.GetHeight()*2.0f);
	wxRect rectR = wxRect(frameRect.GetRight()-borderSize.GetWidth(), frameRect.y + borderSize.GetHeight(),
		borderSize.GetWidth(), frameRect.GetHeight() - borderSize.GetHeight()*2.0f);

	if (rectLT.Contains(mousePos))
	{
		return 5;
	}
	else if (rectRB.Contains(mousePos))
	{
		return 6;
	}
	else if (rectRT.Contains(mousePos))
	{
		return 7;
	}
	else if (rectLB.Contains(mousePos))
	{
		return 8;
	}
	else if (rectT.Contains(mousePos))
	{
		return 3;
	}
	else if (rectB.Contains(mousePos))
	{
		return 4;
	}
	else if (rectL.Contains(mousePos))
	{
		return 1;
	}
	else if (rectR.Contains(mousePos))
	{
		return 2;
	}

	return 0;
}
//----------------------------------------------------------------------------
void PX2WXFrame::_Sizing()
{
	wxPoint mousePos = wxGetMousePosition();

	wxSize newSize;
	wxPoint newPos = wxPoint(mBeforeSizingRect.x, mBeforeSizingRect.y);

	int halfBorderSize = mBorderSize.GetWidth() / 2.0f;
	
	// lr
	if (1 == mSizeDir)
	{
		newPos.x = mousePos.x - halfBorderSize;
		newSize.Set(mBeforeSizingRect.GetRight() - newPos.x, mBeforeSizingRect.GetHeight());
	}
	else if (2 == mSizeDir)
	{
		newSize.Set(mousePos.x - mBeforeSizingRect.x + halfBorderSize, mBeforeSizingRect.GetHeight());
	}
	// tb
	else if (3 == mSizeDir)
	{
		newPos.y = mousePos.y - halfBorderSize;
		newSize.Set(mBeforeSizingRect.GetWidth(), mBeforeSizingRect.GetBottom() - newPos.y);
	}
	else if (4 == mSizeDir)
	{
		newSize.Set(mBeforeSizingRect.GetWidth(), mousePos.y - mBeforeSizingRect.y + halfBorderSize);
	}
	// ltrb
	else if (5 == mSizeDir)
	{
		newPos.x = mousePos.x - halfBorderSize;
		newPos.y = mousePos.y - halfBorderSize;
		newSize.Set(mBeforeSizingRect.GetRight() - newPos.x, mBeforeSizingRect.GetBottom() - newPos.y);
	}
	else if (6 == mSizeDir)
	{
		newSize.Set(mousePos.x - mBeforeSizingRect.x + halfBorderSize,
			mousePos.y - mBeforeSizingRect.y + halfBorderSize);
	}
	// rtlb
	else if (7 == mSizeDir)
	{
		newPos.y = mousePos.y - halfBorderSize;
		newSize.Set(mousePos.x - mBeforeSizingRect.x + halfBorderSize, mBeforeSizingRect.GetBottom() - newPos.y);
	}
	else if (8 == mSizeDir)
	{
		newPos.x = mousePos.x - halfBorderSize;
		newSize.Set(mBeforeSizingRect.GetRight() - newPos.x, mousePos.y - mBeforeSizingRect.y + halfBorderSize);
	}

	if (0 != mSizeDir)
	{
		SetSize(wxRect(newPos.x, newPos.y, newSize.GetWidth(), newSize.GetHeight()));
	}
}
//----------------------------------------------------------------------------