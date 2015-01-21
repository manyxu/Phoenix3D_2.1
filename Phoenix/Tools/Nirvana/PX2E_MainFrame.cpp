// PX2E_MainFrame.cpp

#include "PX2E_MainFrame.hpp"
#include "PX2E_RenderView.hpp"
#include "PX2E_ResView.hpp"
#include "PX2E_ProjView.hpp"
#include "PX2E_PreView.hpp"
#include "PX2E_StartView.hpp"
#include "PX2wxDockArt.hpp"

#include "PX2EngineLoop.hpp"
#include "PX2Edit.hpp"
using namespace PX2Editor;
using namespace PX2;

const int sID_ENGINELOOPTIMER = PX2EDIT_GETID;

BEGIN_EVENT_TABLE(E_MainFrame, wxFrame)
EVT_TIMER(sID_ENGINELOOPTIMER, E_MainFrame::OnTimer)
END_EVENT_TABLE();
//----------------------------------------------------------------------------
E_MainFrame::E_MainFrame(const std::string &title, int xPos, int yPos,
	int width, int height) :
	wxFrame((wxFrame*)0, -1, title, wxPoint(xPos, yPos), wxSize(width, height)),
	mIsInitlized(false),
	mAuiManager(0)
{
}
//----------------------------------------------------------------------------
E_MainFrame::~E_MainFrame()
{
	if (mAuiManager)
	{
		mAuiManager->UnInit();
		delete mAuiManager;
	}
}
//----------------------------------------------------------------------------
bool E_MainFrame::Initlize()
{
	// Aui
	mAuiManager = new wxAuiManager(this, wxAUI_MGR_DEFAULT
		| wxAUI_MGR_TRANSPARENT_DRAG | wxAUI_MGR_ALLOW_ACTIVE_PANE );

	mAuiManager->SetArtProvider(new PX2wxDockArt());
	mAuiManager->GetArtProvider()->SetMetric(wxAUI_DOCKART_CAPTION_SIZE, 24);
	mAuiManager->GetArtProvider()->SetMetric(wxAUI_DOCKART_PANE_BORDER_SIZE, 2);
	mAuiManager->GetArtProvider()->SetMetric(wxAUI_DOCKART_SASH_SIZE, 3);

	mAuiManager->GetArtProvider()->SetColor(wxAUI_DOCKART_BACKGROUND_COLOUR, wxColour(44, 61, 91));
	
	mAuiManager->GetArtProvider()->SetColor(wxAUI_DOCKART_BORDER_COLOUR, wxColour(44, 61, 91));
	mAuiManager->GetArtProvider()->SetColor(wxAUI_DOCKART_SASH_COLOUR, wxColour(44, 61, 91));
	mAuiManager->GetArtProvider()->SetColor(wxAUI_DOCKART_GRIPPER_COLOUR, wxColour(39, 39, 39));

	mAuiManager->GetArtProvider()->SetColor(wxAUI_DOCKART_INACTIVE_CAPTION_COLOUR, wxColour(77, 96, 130));
	mAuiManager->GetArtProvider()->SetColor(wxAUI_DOCKART_INACTIVE_CAPTION_GRADIENT_COLOUR, wxColour(77, 96, 130));

	mAuiManager->GetArtProvider()->SetColor(wxAUI_DOCKART_ACTIVE_CAPTION_COLOUR, wxColour(216, 102, 36));
	mAuiManager->GetArtProvider()->SetColor(wxAUI_DOCKART_ACTIVE_CAPTION_GRADIENT_COLOUR, wxColour(216, 102, 36));

	mAuiManager->SetFlags(mAuiManager->GetFlags() | wxAUI_MGR_LIVE_RESIZE);

	mTimer.SetOwner(this, sID_ENGINELOOPTIMER);
	mTimer.Start(25);

	_CreateMenu();
	_CreateViews();
	_CreateStatusBar();

	mAuiManager->Update();

	mIsInitlized = true;

	return true;
}
//----------------------------------------------------------------------------
RenderView *E_MainFrame::GetRenderView()
{
	return mRenderView;
}
//----------------------------------------------------------------------------
void E_MainFrame::OnTimer(wxTimerEvent& e)
{
	PX2_UNUSED(e);

	if (mIsInitlized)
	{
		PX2_ENGINELOOP.Tick();
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateMenu()
{
	wxMenuBar *mainMenu = new wxMenuBar();
	SetMenuBar(mainMenu);

	wxMenu* menu = new wxMenu();
	mainMenu->Append(menu, "File");
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateMainToolBar()
{
	wxAuiToolBar *mianToolBar = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
		wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_HORIZONTAL);

	mianToolBar->SetArtProvider(new PX2wxAuiToolBarArt());

	mianToolBar->AddTool(PX2EDIT_GETID, _("NewProject"), wxBitmap(wxT("DataEditor/icons/proj.png"), wxBITMAP_TYPE_PNG));
	mianToolBar->AddSeparator();
	mianToolBar->AddTool(PX2EDIT_GETID, _("NewProject1"), wxBitmap(wxT("DataEditor/icons/proj.png"), wxBITMAP_TYPE_PNG));
	mianToolBar->AddTool(PX2EDIT_GETID, _("NewProject2"), wxBitmap(wxT("DataEditor/icons/proj.png"), wxBITMAP_TYPE_PNG));
	mianToolBar->Realize();

	mAuiManager->AddPane(mianToolBar, wxAuiPaneInfo().
		Name(wxT("tb")).Caption(wxT("Toolbar")).
		ToolbarPane().Top().Dockable(false).PaneBorder(false).Resizable(false).Maximize().
		MinSize(200, 28).MaxSize(200, 28));
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateViews()
{
	ProjView *projView = new ProjView(this);
	mAuiManager->AddPane(projView, wxAuiPaneInfo().Name(wxT("ProjView"))
		.Caption("Project").DefaultPane().Left().Icon(wxBitmap("DataEditor/icons/proj.png", wxBITMAP_TYPE_PNG))
		.CloseButton(true).MaximizeButton(true).MinimizeButton(true).PinButton(true)
		.FloatingSize(220, 150).MinSize(100, 100));

	PreView *preView = new PreView(this);
	mAuiManager->AddPane(preView, wxAuiPaneInfo().Name(wxT("PreView"))
		.Caption("PreView").DefaultPane().Right().Icon(wxBitmap("DataEditor/icons/preview.png", wxBITMAP_TYPE_PNG))
		.CloseButton(true).MaximizeButton(true).MinimizeButton(true).PinButton(true)
		.FloatingSize(220, 150).MinSize(100, 100));

	ResView *resView = new ResView(this);
	mAuiManager->AddPane(resView, wxAuiPaneInfo().Name(wxT("ResView"))
		.Caption("Asserts").DefaultPane().Right().Icon(wxBitmap("DataEditor/icons/res.png", wxBITMAP_TYPE_PNG))
		.CloseButton(true).MaximizeButton(true).MinimizeButton(true).PinButton(true)
		.FloatingSize(220, 150).MinSize(100, 100));

	wxSize client_size = GetClientSize();
	wxAuiNotebook* ctrl = new wxAuiNotebook(this, wxID_ANY,
		wxPoint(client_size.x, client_size.y), wxSize(430, 200), 0);
	ctrl->SetArtProvider(new PX2wxAuiTabArt);
	long styleFlag = ctrl->GetWindowStyleFlag();
	styleFlag ^= wxAUI_NB_TAB_FIXED_WIDTH;
	styleFlag ^= wxAUI_NB_WINDOWLIST_BUTTON;
	styleFlag ^= wxAUI_NB_CLOSE_ON_ACTIVE_TAB;
	ctrl->SetWindowStyleFlag(styleFlag);

	ctrl->Freeze();

	wxBitmap page_bmp = wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, wxSize(16, 16));
	StartView *centerView = new StartView(this);
	ctrl->AddPage(centerView, wxT("Start"), false, page_bmp);

	mRenderView = new RenderView(this);
	ctrl->AddPage(mRenderView, wxT("Stage"), false, page_bmp);

	ctrl->Thaw();

	mAuiManager->AddPane(ctrl, wxAuiPaneInfo().Name(wxT("notebook_content")).
		CenterPane().PaneBorder(false));
	ctrl->Refresh();

	//StartView *centerView = new StartView(this);
	//mAuiManager->AddPane(centerView,
	//	wxAuiPaneInfo().Name(wxT("RenderView")).Caption("StartView")
	//	.DefaultPane().Centre().Dockable(true).Icon(wxBitmap("DataEditor/icons/stage.png", wxBITMAP_TYPE_PNG))
	//	.FloatingSize(800, 600).MinSize(100, 100)
	//	.CloseButton(true).MaximizeButton(true).MinimizeButton(true).PinButton(true));

	//mRenderView = new RenderView(this);
	//mAuiManager->AddPane(mRenderView,
	//	wxAuiPaneInfo().Name(wxT("RenderView")).Caption("Stage")
	//	.DefaultPane().Centre().Dockable(true).Icon(wxBitmap("DataEditor/icons/stage.png", wxBITMAP_TYPE_PNG))
	//	.FloatingSize(800, 600).MinSize(100, 100)
	//	.CloseButton(true).MaximizeButton(true).MinimizeButton(true).PinButton(true));
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateStatusBar()
{
	wxStatusBar *status = CreateStatusBar();
	status->SetFieldsCount(1);
	status->SetStatusText("Welcome to Phoenix editor!");
}
//----------------------------------------------------------------------------