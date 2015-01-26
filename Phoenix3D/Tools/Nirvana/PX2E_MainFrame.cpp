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
#include "PX2EditEventType.hpp"
#include "PX2UIEventType.hpp"
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
	mAuiManager(0),
	mRenderView(0),
	mIsShowRenderView(false),
	mProjView(0),
	mIsCrossCursor(false)
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
void E_MainFrame::AddEventHandlers()
{
	PX2_EW.ComeIn(this);
	PX2_EW.ComeIn(mRenderView);
	PX2_EW.ComeIn(mProjView->GetProjTree());
	PX2_EW.ComeIn(mInspView);
}
//----------------------------------------------------------------------------
void E_MainFrame::DoExecute(Event *event)
{
	if (EditEventSpace::IsEqual(event, EditEventSpace::NewProject))
	{
		_ShowRenderView(true);
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::LoadedProject))
	{
		_ShowRenderView(true);
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::CloseProject))
	{
		_ShowRenderView(false);
	}
	else if (UIEventSpace::IsEqual(event, UIEventSpace::TabDrag))
	{
		_CreateView(new ResView(this), "ResView", "ResView", "ResView",
			wxAuiPaneInfo().Right());
	}
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
		PX2_EDIT.IsAltDown = wxGetKeyState(WXK_ALT);
		PX2_EDIT.IsCtrlDown = wxGetKeyState(WXK_CONTROL);
		PX2_EDIT.IsShiftDown = wxGetKeyState(WXK_SHIFT);

		//if (PX2_EDIT.IsAltDown)
		//{
		//	if (!mIsCrossCursor)
		//	{
		//		wxSetCursor(wxNullCursor);
		//		mIsCrossCursor = true;
		//	}
		//}
		//else
		//{
		//	if (mIsCrossCursor)
		//	{
		//		wxSetCursor(*wxSTANDARD_CURSOR);
		//		mIsCrossCursor = false;
		//	}
		//}

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
void E_MainFrame::OnSetEditMode(int mode)
{
	PX2_EDIT.SetEditMode((Edit::EditMode)mode);
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
	mProjView = new ProjView(this);

	_CreateView(mProjView, "ProjView", "ProjView", "ProjView",
		wxAuiPaneInfo().Left());
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateMainView()
{
	mStartView = new StartView(this);

	WindowObj objStart;
	objStart.TheWindow = mStartView;
	objStart.Caption = "StartView";
	objStart.Name = "StartView";

	std::vector<WindowObj> objs;
	objs.push_back(objStart);

	mNoteBookCenter = _CreateView(objs, "Center", wxAuiPaneInfo().CenterPane(), true);

	mRenderView = new RenderView(this);
	mRenderView->Show(false);
	mIsShowRenderView = false;
}
//----------------------------------------------------------------------------
void E_MainFrame::_ShowRenderView(bool show)
{
	if (show == mIsShowRenderView)
		return;

	if (show)
	{
		mIsShowRenderView = true;
		mRenderView->Show(true);
		mNoteBookCenter->AddPage(mRenderView, "Stage");
		int index = mNoteBookCenter->GetPageIndex(mRenderView);
		mNoteBookCenter->SetSelection(index);
	}
	else
	{
		mIsShowRenderView = false;
		mRenderView->Show(false);
		int index = mNoteBookCenter->GetPageIndex(mRenderView);
		mNoteBookCenter->RemovePage(index);
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateInsp()
{
	WindowObj objRes;
	mResView = new ResView(this);
	objRes.TheWindow = mResView;
	objRes.Caption = "ResView";
	objRes.Name = "ResView";

	WindowObj objInsp;
	mInspView = new InspView(this);
	objInsp.TheWindow = mInspView;
	objInsp.Caption = "InspView";
	objInsp.Name = "InspView";

	std::vector<WindowObj> objs;
	objs.push_back(objRes);
	objs.push_back(objInsp);

	_CreateView(objs, "Insp", wxAuiPaneInfo().Right());
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateTimeLine()
{
	_CreateView(new TimeLineView(this), "TimeLine", "TimeLine", "TimeLine",
		wxAuiPaneInfo().DefaultPane());
}
//----------------------------------------------------------------------------
PX2wxAuiNotebook *E_MainFrame::_CreateView(wxWindow *window0, const std::string &name0,
	const std::string &caption0, const std::string &caption,
	wxAuiPaneInfo &paneInfo, bool isTopStyle)
{
	WindowObj obj;
	obj.TheWindow = window0;
	obj.Name = name0;
	obj.Caption = caption0;

	std::vector<WindowObj> winObjs;
	winObjs.push_back(obj);

	return _CreateView(winObjs, caption, paneInfo, isTopStyle);
}
//----------------------------------------------------------------------------
PX2wxAuiNotebook *E_MainFrame::_CreateView(std::vector<WindowObj> &objs,
	const std::string &caption,
	wxAuiPaneInfo &paneInfo,
	bool isTopStyle)
{
	PX2wxAuiNotebook* noteBook = new PX2wxAuiNotebook(this, isTopStyle);
	PX2wxAuiTabArt *tabArt = new PX2wxAuiTabArt(isTopStyle);
	noteBook->SetArtProvider(tabArt);
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
		styleFlag ^= wxAUI_NB_TAB_FIXED_WIDTH;
	}

	noteBook->SetWindowStyleFlag(styleFlag);
	noteBook->SetTabCtrlHeight(24);
	noteBook->Freeze();

	wxBitmap bitMap = wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, wxSize(16, 16));
	for (int i = 0; i < (int)objs.size(); i++)
	{
		WindowObj &obj = objs[i];

		noteBook->AddPage(obj.TheWindow, obj.Caption, false, bitMap);

		WindowObj winObj;
		winObj.Name = obj.Name;
		winObj.TheWindow = obj.TheWindow;
		winObj.NoteBook = noteBook;
		mWindowObjs[obj.Name] = winObj;
	}

	noteBook->UpdateTabsHeight();
	noteBook->Thaw();

	paneInfo.CloseButton(true).MaximizeButton(true).MinimizeButton(true)
		.PinButton(true).FloatingSize(220, 150).MinSize(100, 100).Caption(caption);
	mAuiManager->AddPane(noteBook, paneInfo);

	noteBook->Refresh();

	return noteBook;
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateStatusBar()
{
	wxStatusBar *status = CreateStatusBar();
	status->SetFieldsCount(1);
	status->SetStatusText("Welcome to Phoenix editor!");

	status->SetBackgroundColour(wxColour(0, 122, 204));
	status->SetForegroundColour(wxColour(255, 122, 204));
}
//----------------------------------------------------------------------------