// PX2E_MainFrame.cpp

#include "PX2E_MainFrame.hpp"
#include "PX2E_RenderView.hpp"
#include "PX2E_ResView.hpp"
#include "PX2E_ProjView.hpp"
#include "PX2E_StartView.hpp"
#include "PX2E_TimeLineView.hpp"
#include "PX2wxDockArt.hpp"
#include "PX2wxAui.hpp"

#include "PX2EngineLoop.hpp"
#include "PX2Edit.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2Project.hpp"
#include "PX2DlgCreateProject.hpp"
#include "PX2InspView.hpp"
#include "PX2ObjectInspector.hpp"
using namespace PX2Editor;
using namespace PX2;

const int sID_ENGINELOOPTIMER = PX2_EDIT_GETID;

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

	//mAuiManager->SetFlags(mAuiManager->GetFlags() | wxAUI_MGR_LIVE_RESIZE);

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
void E_MainFrame::OnMenuItem(wxCommandEvent &e)
{
	int id = e.GetId();

	std::map<int, std::string>::iterator it = mIDScripts.find(id);

	if (it != mIDScripts.end())
	{
		std::string callStr = it->second;
		callStr += "()";
		PX2_SM.CallString(callStr);
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::OnNewProject()
{
	DlgCreateProject dlg(this);

	if (wxID_OK == dlg.ShowModal())
	{
		std::string name = dlg.mProjName;
		std::string projPath = dlg.mProjPath;
		int width = dlg.mProjWidth;
		int height = dlg.mProjHeight;

		std::string path = projPath + "/" + name + ".px2proj";

		PX2_EDIT.GetEditMap()->NewProject(path, name, width, height);
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::OnOpenProject()
{
	wxFileDialog dlg(this,
		wxT("Open project"),
		wxEmptyString,
		wxEmptyString,
		wxT("Project (*.px2proj)|*.px2proj"));

	dlg.CenterOnParent();

	if (wxID_OK == dlg.ShowModal())
	{
		PX2_EDIT.GetEditMap()->LoadProject(dlg.GetPath());
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::OnSaveProject()
{
	EditMap *map = PX2_EDIT.GetEditMap();

	Project *proj = Project::GetSingletonPtr();
	if (proj)
	{
		if (proj->GetScene())
		{
			OnSaveScene();
		}
	}

	map->SaveProject();
}
//----------------------------------------------------------------------------
void E_MainFrame::OnSaveProjectAs()
{
	// save scene first
	EditMap *map = PX2_EDIT.GetEditMap();
	Project *proj = Project::GetSingletonPtr();
	if (proj)
	{
		if (proj->GetScene() && proj->GetSceneFilename().empty())
		{
			OnSaveSceneAs();
		}
	}

	wxFileDialog dlg(this,
		wxT("Save project"),
		wxEmptyString,
		wxEmptyString,
		wxT("Project (*.px2proj)|*.px2proj"),
		wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

	dlg.CenterOnParent();

	if (wxID_OK == dlg.ShowModal())
	{
		map->SaveProjectAs(dlg.GetPath());
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::OnCloseProject()
{
	PX2_EDIT.GetEditMap()->CloseProject();
}
//----------------------------------------------------------------------------
void E_MainFrame::OnNewScene()
{
	EditMap *map = PX2_EDIT.GetEditMap();
	map->NewScene();
}
//----------------------------------------------------------------------------
void E_MainFrame::OnOpenScene()
{
	wxFileDialog dlg(this,
		wxT("Open scene"),
		wxEmptyString,
		wxEmptyString,
		wxT("scene (*.px2obj)|*.px2obj"));

	dlg.CenterOnParent();

	if (wxID_OK == dlg.ShowModal())
	{
		std::string strPath = dlg.GetPath();
		PX2_EDIT.GetEditMap()->LoadScene(strPath);
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::OnSaveScene()
{
	std::string path;
	if (Project::GetSingletonPtr())
		path = Project::GetSingleton().GetSceneFilename();

	if (!path.empty())
	{
		PX2_EDIT.GetEditMap()->SaveScene(path.c_str());
	}
	else
	{
		wxFileDialog dlg(this,
			wxT("Save scene"),
			wxEmptyString,
			wxEmptyString,
			wxT("scene (*.px2obj)|*.px2obj"),
			wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

		dlg.CenterOnParent();

		if (wxID_OK == dlg.ShowModal())
		{
			std::string strPath = dlg.GetPath();
			PX2_EDIT.GetEditMap()->SaveScene(strPath);
		}
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::OnSaveSceneAs()
{
	wxFileDialog dlg(this,
		wxT("Save scene"),
		wxEmptyString,
		wxEmptyString,
		wxT("scene (*.px2obj)|*.px2obj"),
		wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

	dlg.CenterOnParent();

	if (dlg.ShowModal() == wxID_OK)
	{
		std::string strPath = dlg.GetPath();
		PX2_EDIT.GetEditMap()->SaveSceneAs(strPath);
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::OnCloseScene()
{
	EditMap *map = PX2_EDIT.GetEditMap();
	if (map)
	{
		map->CloseScene();
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateMenu()
{
	mMainMenuBar = new wxMenuBar();
	SetMenuBar(mMainMenuBar);
}
//----------------------------------------------------------------------------
wxMenu *E_MainFrame::AddMainMenuItem(const std::string &title)
{
	wxMenu* menu = new wxMenu();
	mMainMenuBar->Append(menu, title);

	return menu;
}
//----------------------------------------------------------------------------
wxMenuItem *E_MainFrame::AddMenuItem(wxMenu *menu, const std::string &title,
	const std::string &script)
{
	int id = PX2_EDIT_GETID;
	wxMenuItem *item = menu->Append(id, title);
	Connect(id, wxEVT_COMMAND_MENU_SELECTED, 
		wxCommandEventHandler(E_MainFrame::OnMenuItem));

	mIDScripts[id] = script;

	return item;
}
//----------------------------------------------------------------------------
void E_MainFrame::AddSeparater(wxMenu *menu)
{
	menu->AppendSeparator();
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateMainToolBar()
{
	wxAuiToolBar *mianToolBar = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
		wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_HORIZONTAL);

	mianToolBar->SetArtProvider(new PX2wxAuiToolBarArt());

	mianToolBar->AddTool(PX2_EDIT_GETID, _("NewProject"), wxBitmap(wxT("DataEditor/icons/proj.png"), wxBITMAP_TYPE_PNG));
	mianToolBar->AddSeparator();
	mianToolBar->AddTool(PX2_EDIT_GETID, _("NewProject1"), wxBitmap(wxT("DataEditor/icons/proj.png"), wxBITMAP_TYPE_PNG));
	mianToolBar->AddTool(PX2_EDIT_GETID, _("NewProject2"), wxBitmap(wxT("DataEditor/icons/proj.png"), wxBITMAP_TYPE_PNG));
	mianToolBar->Realize();

	mAuiManager->AddPane(mianToolBar, wxAuiPaneInfo().
		Name(wxT("tb")).Caption(wxT("Toolbar")).
		ToolbarPane().Top().Dockable(false).PaneBorder(false).Resizable(false).Maximize().
		MinSize(200, 28).MaxSize(200, 28));
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateViews()
{
	_CreateProjView();
	_CreateMainView();
	_CreateInsp();
	_CreateTimeLine();
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateProjView()
{
	wxBitmap icon("DataEditor/icons/proj.png", wxBITMAP_TYPE_PNG);

	_CreateView(new ProjView(this), "ProjView", "ProjView", icon,
		wxAuiPaneInfo().Left()
		.CloseButton(true).MaximizeButton(true).MinimizeButton(true)
		.PinButton(true).FloatingSize(220, 150).MinSize(100, 100));
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateMainView()
{
	mRenderView = new RenderView(this);
	wxBitmap icon("DataEditor/icons/proj.png", wxBITMAP_TYPE_PNG);
	_CreateView(mRenderView, "Center", "Center", icon,
		wxAuiPaneInfo().CenterPane(), true);
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateInsp()
{
	PX2wxAuiNotebook* ctrl = new PX2wxAuiNotebook(this, false);
	ctrl->SetArtProvider(new PX2wxAuiTabArt(false));
	long styleFlag = 0;
	styleFlag ^= wxAUI_NB_TAB_MOVE;
	styleFlag ^= wxAUI_NB_BOTTOM;
	ctrl->SetWindowStyleFlag(styleFlag);
	ctrl->Freeze();

	wxBitmap page_bmp = wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, wxSize(16, 16));

	ResView *resView = new ResView(this);
	ctrl->AddPage(resView, wxT("ResView"), false, wxBitmap("DataEditor/icons/res.png", wxBITMAP_TYPE_PNG));

	InspWindow *inspWin = new InspWindow(this);
	ctrl->AddPage(inspWin, wxT("InspView"), false, page_bmp);

	ctrl->Thaw();

	mAuiManager->AddPane(ctrl, wxAuiPaneInfo().Name(wxT("insp"))
		.Right().Caption("ResView")
		.CloseButton(true).MaximizeButton(true).MinimizeButton(true)
		.PinButton(true).FloatingSize(220, 150).MinSize(100, 100));

	ctrl->Refresh();
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateTimeLine()
{
	_CreateView(new TimeLineView(this), "TimeLine", "TimeLine",
		wxBitmap("DataEditor/icons/res.png", wxBITMAP_TYPE_PNG),
		wxAuiPaneInfo().DefaultPane().Caption("TimeLine")
		.CloseButton(true).MaximizeButton(true).MinimizeButton(true)
		.PinButton(true).FloatingSize(220, 150).MinSize(100, 100));
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateView(wxWindow *window0, 
	const std::string &name, const std::string &caption,
	const wxBitmap &bitMap, wxAuiPaneInfo &paneInfo, bool isTopStyle)
{
	PX2wxAuiNotebook* ctrl = new PX2wxAuiNotebook(this, isTopStyle);
	PX2wxAuiTabArt *tabArt = new PX2wxAuiTabArt(isTopStyle);
	ctrl->SetArtProvider(tabArt);
	long styleFlag = 0;
	styleFlag ^= wxAUI_NB_TAB_MOVE;
	if (isTopStyle)
	{
		styleFlag ^= wxAUI_NB_WINDOWLIST_BUTTON;
		styleFlag ^= wxAUI_NB_CLOSE_ON_ACTIVE_TAB;
	}
	else
	{
		styleFlag ^= wxAUI_NB_BOTTOM;
	}

	ctrl->SetWindowStyleFlag(styleFlag);
	ctrl->SetTabCtrlHeight(24);
	ctrl->Freeze();

	ctrl->AddPage(window0, caption, false, bitMap);

	ctrl->UpdateTabsHeight();
	ctrl->Thaw();

	mAuiManager->AddPane(ctrl, paneInfo);

	ctrl->Refresh();
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateStatusBar()
{
	wxStatusBar *status = CreateStatusBar();
	status->SetFieldsCount(1);
	status->SetStatusText("Welcome to Phoenix editor!");
}
//----------------------------------------------------------------------------