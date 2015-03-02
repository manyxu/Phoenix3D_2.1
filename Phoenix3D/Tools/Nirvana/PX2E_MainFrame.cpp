// PX2E_MainFrame.cpp

#include "PX2E_MainFrame.hpp"
#include "PX2E_RenderView.hpp"
#include "PX2E_ResView.hpp"
#include "PX2E_ProjView.hpp"
#include "PX2E_StartView.hpp"
#include "PX2E_TimeLineView.hpp"
#include "PX2E_TopView.hpp"
#include "PX2E_InspView.hpp"
#include "PX2E_RenderView_Cont.hpp"
#include "PX2E_NirMan.hpp"
#include "PX2wxDockArt.hpp"
#include "PX2wxAui.hpp"

#include "PX2EngineLoop.hpp"
#include "PX2Edit.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2Project.hpp"
#include "PX2EventWorld.hpp"
#include "PX2DlgCreateProject.hpp"
#include "PX2ObjectInspector.hpp"
#include "PX2SimulationEventType.hpp"
#include "PX2EditEventType.hpp"
#include "PX2NirvanaEventType.hpp"
#include "PX2EditParams.hpp"
#include "PX2Format.hpp"

using namespace PX2Editor;
using namespace PX2;

const int sID_ENGINELOOPTIMER = PX2_EDIT_GETID;

BEGIN_EVENT_TABLE(E_MainFrame, wxFrame)
EVT_TIMER(sID_ENGINELOOPTIMER, E_MainFrame::OnTimer)
EVT_MENU_CLOSE(E_MainFrame::OnMenuClose)
EVT_AUINOTEBOOK_ALLOW_DND(wxID_ANY, E_MainFrame::OnAllowNotebookDnD)
EVT_AUINOTEBOOK_PAGE_CLOSE(wxID_ANY, E_MainFrame::OnNotebookPageClose)
EVT_AUINOTEBOOK_PAGE_CLOSED(wxID_ANY, E_MainFrame::OnNotebookPageClosed)
END_EVENT_TABLE();
//----------------------------------------------------------------------------
E_MainFrame::E_MainFrame(const std::string &title, int xPos, int yPos,
	int width, int height) :
	wxFrame((wxFrame*)0, -1, title, wxPoint(xPos, yPos), wxSize(width, height)),
	mIsInitlized(false),
	mAuiManager(0),
	mToolBarMain(0),
	mToolBarMenu(0),
	mToolMenu(0),
	mTopView(0),
	mRenderViewScene(0),
	mRenderViewLogic(0),
	mProjView(0),
	mIsCrossCursor(false)
{
	mPerspConfigName = "nirvana1.0.3.config";

	PX2_EW.ComeIn(this);
}
//----------------------------------------------------------------------------
E_MainFrame::~E_MainFrame()
{
	if (mAuiManager)
	{
		wxString strPerspective = mAuiManager->SavePerspective();

		wxFileOutputStream os(mPerspConfigName);
		wxFileConfig config;
		config.Write("Perspective", strPerspective);
		config.Save(os);
		os.Close();

		mAuiManager->UnInit();
		delete mAuiManager;
	}

	if (mToolMenu)
	{
		delete mToolMenu;
		mToolMenu = 0;
	}
}
//----------------------------------------------------------------------------
bool E_MainFrame::Initlize()
{
	// Aui
	mAuiManager = new wxAuiManager(this, wxAUI_MGR_DEFAULT
		| wxAUI_MGR_TRANSPARENT_DRAG | wxAUI_MGR_ALLOW_ACTIVE_PANE |
		wxAUI_MGR_ALLOW_FLOATING | wxAUI_MGR_LIVE_RESIZE);

	mAuiManager->SetArtProvider(new PX2wxDockArt());
	mAuiManager->GetArtProvider()->SetMetric(wxAUI_DOCKART_CAPTION_SIZE, 24);
	mAuiManager->GetArtProvider()->SetMetric(wxAUI_DOCKART_PANE_BORDER_SIZE, 1);
	mAuiManager->GetArtProvider()->SetMetric(wxAUI_DOCKART_SASH_SIZE, 2);

	mAuiManager->GetArtProvider()->SetColor(wxAUI_DOCKART_BORDER_COLOUR, wxColour(255, 57, 85));

	mTimer.SetOwner(this, sID_ENGINELOOPTIMER);
	mTimer.Start(25);

	//_CreateMenu();
	//_CreateTopView();
	_CreateMenuToolBar();
	_CreateMainToolBar();
	_CreateViews();
	_CreateStatusBar();

	wxFileInputStream is(mPerspConfigName);
	if (is.IsOk())
	{
		wxFileConfig config(is);
		wxString strPerspective;
		if (config.Read(wxString("Perspective"), &strPerspective))
		{
			mAuiManager->LoadPerspective(strPerspective);
		}
	}

	mAuiManager->Update();

	mIsInitlized = true;

	return true;
}
//----------------------------------------------------------------------------
void E_MainFrame::DoExecute(Event *event)
{
	if (EditEventSpace::IsEqual(event, EditEventSpace::NewScene))
	{
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::LoadedScene))
	{
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::CloseScene))
	{
	}
	else if (NirvanaEventSpace::IsEqual(event, NirvanaEventSpace::PinPage))
	{
		PinData dragData = event->GetData<PinData>();

		wxWindow *window = dragData.TheWindow;

		wxString windowName = window->GetName();
		wxString caption = dragData.Caption;

		wxSize size = window->GetSize();
		wxPoint pos = window->GetPosition();

		std::string strCaption = caption.ToStdString();
		std::string strWindowName = windowName.ToStdString();

		PX2wxAuiNotebook *book = _CreateView(window, strWindowName, strCaption,
			wxAuiPaneInfo().Right().FloatingSize(size.GetWidth(), size.GetHeight()).Float(),
			false);
		book->SetSize(size);

		mAuiManager->Update();
	}
	else if (NirvanaEventSpace::IsEqual(event, NirvanaEventSpace::PinPages))
	{
		PinData pinData = event->GetData<PinData>();

		wxAuiPaneInfo &info = mAuiManager->GetPane(pinData.TheBook);
		info.Float().FloatingPosition(pinData.Pos).FloatingSize(pinData.Size);

		mAuiManager->Update();
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::SceneNodeDrag))
	{
		int drag = event->GetData<int>();
		if (1 == drag)
		{
			SetCursor(wxCursor(wxCURSOR_SIZING));
		}
		else if (0 == drag)
		{
			SetCursor(wxCursor(wxCURSOR_ARROW));
		}
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::EditThemeChange))
	{
		if (mAuiManager)
		{
		}
	}
	else if (SimuES_E::IsEqual(event, SimuES_E::AddSelect) ||
		SimuES_E::IsEqual(event, SimuES_E::RemoveSelect) ||
		SimuES_E::IsEqual(event, SimuES_E::RemoveAllSelects))
	{
		_UpdateStatusSelectObject(2);
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::SelectRes))
	{
		_UpdateStatusSelectRes(3);
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::SetPickPos))
	{
		const APoint &pickPos = PX2_EDIT.GetPickPos();
		_UpdateStatusPickingPos(4);
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::_UpdateStatusSelectObject(int index)
{
	wxStatusBar *sb = GetStatusBar();

	std::string str;
	int numObj = PX2_SELECTION.GetNumObjects();
	if (0 == numObj)
	{
		str = PX2_LMVAL("CurSelObjNull");
	}
	else
	{
		Object *firObj = PX2_SELECTION.GetFirstObject();

		str = PX2_LMVAL("CurSelObj");
		str += " " + StringHelp::IntToString(numObj) + PX2_LMVAL("Ge");
		str += " " + PX2_LMVAL("Name") + ": " + firObj->GetName();
	}

	sb->SetStatusText(str, index);
}
//----------------------------------------------------------------------------
void E_MainFrame::_UpdateStatusSelectRes(int index)
{
	const SelectResData &resData = PX2_EDIT.GetSelectedResource();

	wxStatusBar *sb = GetStatusBar();

	std::string str = PX2_LMVAL("CurSelRes") + resData.ResPathname;

	sb->SetStatusText(str, index);
}
//----------------------------------------------------------------------------
void E_MainFrame::_UpdateStatusPickingPos(int index)
{
	const APoint &pickPos = PX2_EDIT.GetPickPos();

	wxStatusBar *sb = GetStatusBar();

	std::string str = PX2_LMVAL("PickingPos") + "(" +
		StringHelp::FloatToString(pickPos[0]) + ", " +
		StringHelp::FloatToString(pickPos[1]) + ", " +
		StringHelp::FloatToString(pickPos[2]) + ")";

	sb->SetStatusText(str, index);
}
//----------------------------------------------------------------------------
RenderView *E_MainFrame::GetRenderViewScene()
{
	return mRenderViewScene;
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

		PX2_ENGINELOOP.Tick();
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::OnMenuClose(wxMenuEvent &WXUNUSED(e))
{
	mToolBarMenu->SetItemsState(wxAUI_BUTTON_STATE_NORMAL);
	mToolBarMenu->Refresh();
}
//----------------------------------------------------------------------------
void E_MainFrame::OnAllowNotebookDnD(wxAuiNotebookEvent& evt)
{
	evt.Allow();
}
//----------------------------------------------------------------------------
void E_MainFrame::OnNotebookPageClose(wxAuiNotebookEvent& evt)
{

}
//----------------------------------------------------------------------------
void E_MainFrame::OnNotebookPageClosed(wxAuiNotebookEvent& evt)
{

}
//----------------------------------------------------------------------------
void E_MainFrame::OnShortcutKeyDown()
{
	if (!IsActive())
	{
		return;
	}

	if (wxGetKeyState(WXK_CONTROL))
	{
		if (wxGetKeyState(WXK_CONTROL_N))
		{
			OnNewProject();
		}
		else if (wxGetKeyState(WXK_CONTROL_O))
		{
			OnOpenProject();
		}	
		else if (wxGetKeyState(WXK_CONTROL_S))
		{
			OnSaveProject();
		}
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::OnCommondItem(wxCommandEvent &e)
{
	int id = e.GetId();

	std::map<int, std::string>::iterator it = mIDScripts.find(id);

	if (it != mIDScripts.end())
	{
		std::string callStr = it->second;
		PX2_SM.CallString(callStr);
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::OnMenuToolItem(wxMouseEvent &e)
{
	int id = e.GetId();

	std::map<int, std::string>::iterator it = mIDScripts.find(id);

	if (it != mIDScripts.end())
	{
		if (mToolMenu)
		{
			delete mToolMenu;
			mToolMenu = 0;
		}

		mToolMenu = new wxMenu();
		NirMan::GetSingleton().SetCurMenu(mToolMenu);

		std::string callStr = it->second;
		PX2_SM.CallString(callStr);
		int idx = mToolBarMenu->GetToolPos(id);

		wxRect parentRect = mToolBarMenu->GetRect();
		wxRect rect = mToolBarMenu->GetItems().Item(idx).GetSizerItem()->GetRect();

		if (mToolMenu)
		{
			PopupMenu(mToolMenu, parentRect.x + rect.x, parentRect.y + parentRect.height - rect.y);
		}
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
		std::string path = dlg.GetPath();
		path = StringHelp::StandardiseFilename(path);
		PX2_EDIT.GetEditMap()->LoadProject(path);
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
		std::string path = dlg.GetPath();
		path = StringHelp::StandardiseFilename(path);
		map->SaveProjectAs(path);
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
void E_MainFrame::OnSetting()
{
	EditParams *params = PX2_EDIT.GetEditParams();
	if (params)
	{
		PX2_SELECTION.Clear();
		PX2_SELECTION.AddObject(params);
	}
	else
	{
		PX2_SELECTION.Clear();
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateMenu()
{
	mMainMenuBar = new wxMenuBar();
	SetMenuBar(mMainMenuBar);

	PX2_SM.CallString("e_CreateMainMenu()");
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
	wxMenuItem *item = new wxMenuItem(menu, id, title);
	menu->Append(item);

	Connect(id, wxEVT_COMMAND_MENU_SELECTED, 
		wxCommandEventHandler(E_MainFrame::OnCommondItem));

	mIDScripts[id] = script;

	return item;
}
//----------------------------------------------------------------------------
void E_MainFrame::AddSeparater(wxMenu *menu)
{
	wxMenuItem *item = new wxMenuItem(menu, wxID_SEPARATOR);
	item->SetBackgroundColour(wxColour(234, 240, 255));
	item->SetTextColour(wxColour(0, 0, 0));
	menu->Append(item);
}
//----------------------------------------------------------------------------
void E_MainFrame::AddTool(PX2wxAuiToolBar *toolBar, const std::string &icon,
	std::string &script)
{
	int id = PX2_EDIT_GETID;
	toolBar->AddTool(id, "", wxBitmap(icon, wxBITMAP_TYPE_PNG));
	Connect(id, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(E_MainFrame::OnCommondItem));

	mIDScripts[id] = script;
}
//----------------------------------------------------------------------------
void E_MainFrame::AddMenuTool(PX2wxAuiToolBar *toolBar, const std::string &MenuTitle, std::string &script)
{
	int id = PX2_EDIT_GETID;
	toolBar->AddTool(id, MenuTitle, wxNullBitmap, wxEmptyString, wxITEM_RADIO);
	
	Connect(id, wxEVT_COMMAND_TOOL_CLICKED,
		wxMouseEventHandler(E_MainFrame::OnMenuToolItem));

	mIDScripts[id] = script;
}
//----------------------------------------------------------------------------
void E_MainFrame::AddToolSeparater(PX2wxAuiToolBar *toolBar)
{
	toolBar->AddSeparator();
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateTopView()
{
	mTopView = new TopView(this);

	mAuiManager->AddPane(mTopView, wxAuiPaneInfo().
		Name(wxT("topview")).ToolbarPane().PaneBorder(false).
		Gripper(false).Top().Dockable(false).PaneBorder(false).Resizable(false).
		MinSize(200, 30).MaxSize(200, 30).Top().Resizable(false).CaptionVisible(false));
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateMainToolBar()
{
	mToolBarMain = new PX2wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
		wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_HORIZONTAL);
	if (mToolBarMain)
	{
		mToolBarMain->SetArtProvider(new PX2wxAuiToolBarArt(1));

		NirMan::GetSingleton().SetCurToolBar(mToolBarMain);

		PX2_SM.CallString("e_CreateToolBarMain()");

		mToolBarMain->Realize();

		mAuiManager->AddPane(mToolBarMain, wxAuiPaneInfo().
			Name(wxT("maintoolbar")).
			Gripper(true).Top().Dockable(false).PaneBorder(true).
			MinSize(200, 28).MaxSize(200, 28).Top().Resizable(false).CaptionVisible(false).
			BottomDockable(false).LeftDockable(false).RightDockable(false).Floatable(false));
	}	
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateMenuToolBar()
{
	mToolBarMenu = new PX2wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
		wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_HORIZONTAL | wxAUI_TB_TEXT | wxAUI_TB_HORZ_TEXT);

	if (mToolBarMenu)
	{
		mToolBarMenu->SetArtProvider(new PX2wxAuiToolBarArt(0));

		NirMan::GetSingleton().SetCurToolBar(mToolBarMenu);

		PX2_SM.CallString("e_CreateToolBarMenu()");

		mToolBarMenu->Realize();

		mToolBarMenu->SetSize(wxSize(-1, 25));

		mAuiManager->AddPane(mToolBarMenu, wxAuiPaneInfo().
			Name(wxT("menutoolbar")).
			ToolbarPane().Gripper(true).Top().Dockable(false).Resizable(false).
			MinSize(200, 25).MaxSize(200, 25).PaneBorder(true));
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateViews()
{
	_CreateProjView(true);
	_CreateMainView(true);
	_CreateInsp(true);
	_CreateTimeLine(true);
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateProjView(bool isTopStyle)
{
	mProjView = new ProjView(this);
	_CreateView(mProjView, "ProjView", PX2_LM.GetValue("Project"),
		wxAuiPaneInfo().Left().CaptionVisible(false), isTopStyle);
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateMainView(bool isTopStyle)
{
	std::vector<WindowObj> objs;

	mStartView = new StartView(this);
	WindowObj objStart;
	objStart.TheWindow = mStartView;
	objStart.Caption = PX2_LMVAL("StartView");
	objStart.Name = "StartView";
	objs.push_back(objStart);

	RenderView_Cot *viewCont_SceneUI = new RenderView_Cot(RVT_SCENEUI, this);
	mRenderViewScene = viewCont_SceneUI->GetRenderView();
	WindowObj objRenderViewScene;
	objRenderViewScene.TheWindow = viewCont_SceneUI;
	objRenderViewScene.Caption = PX2_LMVAL("Stage");
	objRenderViewScene.Name = "Stage";
	objs.push_back(objRenderViewScene);

	RenderView_Cot *viewCont_Logic = new RenderView_Cot(RVT_LOGIC, this);
	mRenderViewLogic = viewCont_Logic->GetRenderView();
	WindowObj objLogicView;
	objLogicView.TheWindow = viewCont_Logic;
	objLogicView.Caption = PX2_LMVAL("LogicView");
	objLogicView.Name = "Logic";
	objs.push_back(objLogicView);

	mNoteBookCenter = _CreateView(objs, "Center", "Center",
		wxAuiPaneInfo().CenterPane(), isTopStyle);
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateInsp(bool isTopStyle)
{
	WindowObj objRes;
	mResView = new ResView(this);
	objRes.TheWindow = mResView;
	objRes.Caption = PX2_LM.GetValue("ResView");
	objRes.Name = "ResView";

	WindowObj objInsp;
	mInspView = new InspView(this);
	objInsp.TheWindow = mInspView;
	objInsp.Caption = PX2_LM.GetValue("InspView");
	objInsp.Name = "InspView";

	std::vector<WindowObj> objs;
	objs.push_back(objRes);
	objs.push_back(objInsp);

	_CreateView(objs, "Right", PX2_LM.GetValue("ResView"), 
		wxAuiPaneInfo().Right().CaptionVisible(false), isTopStyle);
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateTimeLine(bool isTopStyle)
{
	mTimeLineView = new TimeLineView(this);
	_CreateView(mTimeLineView, "TimeLine", PX2_LM.GetValue("TimeLine"),
		wxAuiPaneInfo().DefaultPane().Bottom().CaptionVisible(false), isTopStyle);
}
//----------------------------------------------------------------------------
PX2wxAuiNotebook *E_MainFrame::_CreateView(wxWindow *window0,
	const std::string &paneName, const std::string &panelCaption,
	wxAuiPaneInfo &paneInfo, bool isTopStyle)
{
	WindowObj obj;
	obj.TheWindow = window0;
	obj.Name = paneName;
	obj.Caption = panelCaption;

	std::vector<WindowObj> winObjs;
	winObjs.push_back(obj);

	return _CreateView(winObjs, paneName, panelCaption, paneInfo, isTopStyle);
}
//----------------------------------------------------------------------------
PX2wxAuiNotebook *E_MainFrame::_CreateView(std::vector<WindowObj> &objs,
	const std::string &panelName,
	const std::string &panelCaption,
	wxAuiPaneInfo &paneInfo,
	bool isTopStyle)
{
	PX2wxAuiNotebook* noteBook = new PX2wxAuiNotebook(this, isTopStyle);
	PX2wxAuiTabArt *tabArt = new PX2wxAuiTabArt(isTopStyle);
	noteBook->SetArtProvider(tabArt);
	long styleFlag = 0;
	if (isTopStyle)
	{
		styleFlag ^= wxAUI_NB_WINDOWLIST_BUTTON;
	}
	else
	{
		styleFlag ^= wxAUI_NB_BOTTOM;
	}

	styleFlag ^= wxAUI_NB_TAB_MOVE;
	styleFlag ^= wxAUI_NB_TAB_EXTERNAL_MOVE;
	styleFlag ^= wxAUI_NB_TAB_FIXED_WIDTH;
	styleFlag ^= wxAUI_NB_TAB_SPLIT;
	styleFlag ^= wxAUI_NB_SCROLL_BUTTONS;
	styleFlag ^= wxAUI_NB_CLOSE_BUTTON;

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

		obj.TheWindow->SetName(obj.Name);
	}

	noteBook->UpdateTabsHeight();
	noteBook->Thaw();

	paneInfo.CloseButton(true).MaximizeButton(true).MinimizeButton(true)
		.PinButton(true).MinSize(100, 100).Name(panelName).
		Caption(panelCaption).CaptionVisible(!isTopStyle).Floatable(true).TopDockable(false);
	mAuiManager->AddPane(noteBook, paneInfo);

	noteBook->Refresh();

	return noteBook;
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateStatusBar()
{
	wxStatusBar *status = CreateStatusBar();

	const int numFields = 5;
	status->SetFieldsCount(numFields);

	int widths[numFields] = {0, 300, 250, -1, 300 };
	status->SetStatusWidths(numFields, widths);

	int styles[numFields] = { wxSB_FLAT, wxSB_NORMAL, wxSB_FLAT, wxSB_NORMAL, wxSB_FLAT };
	status->SetStatusStyles(numFields, styles);

	status->SetStatusText(PX2_LMVAL("WelcomeToEditor"), 1);

	_UpdateStatusSelectObject(2);
	_UpdateStatusSelectRes(3);
	_UpdateStatusPickingPos(4);

	status->SetBackgroundColour(wxColour(0, 122, 204));
	status->SetForegroundColour(wxColour(255, 0, 0));
}
//----------------------------------------------------------------------------
wxAuiManager *E_MainFrame::GetAuiMananger()
{
	if (mAuiManager)
	{
		return mAuiManager;
	}
	return 0;
}
//----------------------------------------------------------------------------