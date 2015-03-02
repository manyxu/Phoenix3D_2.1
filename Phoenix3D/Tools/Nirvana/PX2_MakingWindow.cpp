// PX2_MakingWindow.cpp

#include "PX2_MakingWindow.hpp"
using namespace PX2Editor;
using namespace PX2;

BEGIN_EVENT_TABLE(MakingWindow, wxWindow)
EVT_SIZE(MakingWindow::OnSize)
END_EVENT_TABLE()

//-----------------------------------------------------------------------------
MakingWindow::MakingWindow(wxWindow *parent) :
wxScrolled<wxWindow>(parent, wxID_ANY),
mCurWindow(0)
{
	SetScrollRate(10, 10);
	EnableScrolling(false, true);
}
//-----------------------------------------------------------------------------
MakingWindow::~MakingWindow()
{
}
//-----------------------------------------------------------------------------
void MakingWindow::OnSize(wxSizeEvent& e)
{
	PX2_UNUSED(e);

	if (mCurWindow)
	{
		wxSize clentSize = GetClientSize();
		mCurWindow->SetSize(clentSize.GetWidth(), mCurWindowOriginSize.GetHeight());

		SetVirtualSize(clentSize.GetWidth(), mCurWindowOriginSize.GetHeight());
	}
}
//----------------------------------------------------------------------------
void MakingWindow::SetObject(PX2::Object *obj)
{
	if (mObject == obj && obj)
		return;

	mObject = obj;

	if (mObject)
	{
	}
	else
	{
		ChangeToWindow("");
	}
}
//----------------------------------------------------------------------------
void MakingWindow::ChangeToWindow(const std::string &str, int userData)
{
}
//----------------------------------------------------------------------------