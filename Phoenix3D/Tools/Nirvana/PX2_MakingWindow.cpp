// PX2_MakingWindow.cpp

#include "PX2_MakingWindow.hpp"
#include "PX2TerrainActor.hpp"
#include "PX2Edit.hpp"
#include "PX2E_Define.hpp"
#include "PX2TerrainMakingPanel.hpp"
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

	SetBackgroundColour(Float3TowxColour(PX2_EDIT.GetEditParams()->GetCurTheme()->Color_Page_Background));
	SetForegroundColour(Float3TowxColour(PX2_EDIT.GetEditParams()->GetCurTheme()->Color_Page_Foreground));
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
	mObject = obj;

	if (mObject)
	{
		TerrainActor *terActor = DynamicCast<TerrainActor>(mObject);
		Terrain *terrain = DynamicCast<Terrain>(mObject);
		TerrainPage *terrainPage = DynamicCast<TerrainPage>(mObject);
		Edit::EditType editType = PX2_EDIT.GetEditType();

		if (editType == Edit::ET_TERRAIN && (terActor || terrain || terrainPage))
		{
			ChangeToWindow("TerrainMaking");
		}
		else
		{
			ChangeToWindow("");
		}
	}
	else
	{
		ChangeToWindow("");
	}
}
//----------------------------------------------------------------------------
void MakingWindow::ChangeToWindow(const std::string &str, int userData)
{
	PX2_UNUSED(userData);

	if (mCurWindow)
	{
		delete mCurWindow;
		mCurWindow = 0;
	}

	mCurWinStr = str;

	if ("TerrainMaking" == str)
	{
		TerrainMakingPanel *terMakingPanel = new TerrainMakingPanel(this);
		mCurWindow = terMakingPanel;
		terMakingPanel->RefleshCtrls();
	}

	if (mCurWindow)
	{
		mCurWindowOriginSize = mCurWindow->GetSize();

		wxSize clentSize = GetClientSize();
		mCurWindow->SetSize(clentSize.GetWidth(), mCurWindowOriginSize.GetHeight());

		SetVirtualSize(clentSize.GetWidth(), mCurWindowOriginSize.GetHeight());

		Refresh();
	}
}
//----------------------------------------------------------------------------