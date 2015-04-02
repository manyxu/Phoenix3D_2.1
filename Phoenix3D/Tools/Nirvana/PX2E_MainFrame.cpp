// PX2E_MainFrame.cpp

#include "PX2E_MainFrame.hpp"
#include "PX2E_RenderView.hpp"
#include "PX2E_ResView.hpp"
#include "PX2E_ProjView.hpp"
#include "PX2E_StartView.hpp"
#include "PX2E_TopView.hpp"
#include "PX2E_InspView.hpp"
#include "PX2E_RenderView_Cont.hpp"
#include "PX2E_NirMan.hpp"
#include "PX2E_LogView.hpp"
#include "PX2E_ResTree.hpp"
#include "PX2wxDockArt.hpp"
#include "PX2wxAui.hpp"

#include "PX2DlgCreateProject.hpp"
#include "PX2DlgPlayConfig.hpp"
#include "PX2DlgTerainNew.hpp"
#include "PX2DlgTerainPageNew.hpp"
#include "PX2DlgSetCurveVal.hpp"

#include "PX2EngineLoop.hpp"
#include "PX2Edit.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2Project.hpp"
#include "PX2EventWorld.hpp"
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
	mPerspConfigName = "nirvana1.0.0.config";

	PX2_EW.ComeIn(this);
}
//----------------------------------------------------------------------------
E_MainFrame::~E_MainFrame()
{
	Logger::GetSingleton().RemoveHandler(mLogView->GetLogTextCtrl());

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

	_CreateMenu();
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

	EnableMenusTag("edit", false);

	EnableMenusTag("saveproject", false);
	EnableMenusTag("closeproject", false);

	EnableMenusTag("newscene", false);
	EnableMenusTag("openscene", false);
	EnableMenusTag("savescene", false);
	EnableMenusTag("saveasscene", false);
	EnableMenusTag("closescene", false);

	mIsInitlized = true;

	return true;
}
//----------------------------------------------------------------------------
void E_MainFrame::DoExecute(Event *event)
{
	if (EditEventSpace::IsEqual(event, EditEventSpace::NewProject))
	{
		EnableMenusTag("edit", true);

		EnableMenusTag("saveproject", true);
		EnableMenusTag("closeproject", true);

		EnableMenusTag("newscene", true);
		EnableMenusTag("openscene", true);
		EnableMenusTag("savescene", false);
		EnableMenusTag("saveasscene", false);
		EnableMenusTag("closescene", false);
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::LoadedProject))
	{
		EnableMenusTag("edit", true);

		EnableMenusTag("saveproject", true);
		EnableMenusTag("closeproject", true);

		EnableMenusTag("newscene", true);
		EnableMenusTag("openscene", true);
		EnableMenusTag("savescene", false);
		EnableMenusTag("saveasscene", false);
		EnableMenusTag("closescene", false);
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::CloseProject))
	{
		EnableMenusTag("edit", false);

		EnableMenusTag("saveproject", false);
		EnableMenusTag("closeproject", true);

		EnableMenusTag("newscene", false);
		EnableMenusTag("openscene", false);
		EnableMenusTag("savescene", false);
		EnableMenusTag("saveasscene", false);
		EnableMenusTag("closescene", false);
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::NewScene))
	{
		EnableMenusTag("newscene", true);
		EnableMenusTag("openscene", true);
		EnableMenusTag("savescene", true);
		EnableMenusTag("saveasscene", true);
		EnableMenusTag("closescene", true);
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::LoadedScene))
	{
		EnableMenusTag("newscene", true);
		EnableMenusTag("openscene", true);
		EnableMenusTag("savescene", true);
		EnableMenusTag("saveasscene", true);
		EnableMenusTag("closescene", true);
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::CloseScene))
	{
		EnableMenusTag("newscene", true);
		EnableMenusTag("openscene", true);
		EnableMenusTag("savescene", false);
		EnableMenusTag("saveasscene", false);
		EnableMenusTag("closescene", false);
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

		PX2_EDIT.IsKeyDown_W = wxGetKeyState((wxKeyCode)87) || wxGetKeyState((wxKeyCode)119);
		PX2_EDIT.IsKeyDown_S = wxGetKeyState((wxKeyCode)83) || wxGetKeyState((wxKeyCode)115);
		PX2_EDIT.IsKeyDown_A = wxGetKeyState((wxKeyCode)65) || wxGetKeyState((wxKeyCode)97);
		PX2_EDIT.IsKeyDown_D = wxGetKeyState((wxKeyCode)68) || wxGetKeyState((wxKeyCode)100);

		PX2_EDIT.IsLeftMouseDown = wxGetMouseState().LeftIsDown();
		PX2_EDIT.IsRightMouseDown = wxGetMouseState().RightIsDown();
		PX2_EDIT.IsMidMouseDown = wxGetMouseState().MiddleIsDown();

		PX2_ENGINELOOP.Tick();
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::OnMenuClose(wxMenuEvent &WXUNUSED(e))
{
	if (mToolBarMenu)
	{
		mToolBarMenu->SetItemsState(wxAUI_BUTTON_STATE_NORMAL);
		mToolBarMenu->Refresh();
	}
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

	//if (wxGetKeyState(WXK_CONTROL_Q))
	//{
	//	PX2_SM.CallString("e_OnSelect()");
	//}
	//else if (wxGetKeyState(WXK_CONTROL_W))
	//{
	//	PX2_SM.CallString("e_OnTranslate()");
	//}
	//else if (wxGetKeyState(WXK_CONTROL_E))
	//{
	//	PX2_SM.CallString("e_OnRotate()");
	//}
	//else if (wxGetKeyState(WXK_CONTROL_R))
	//{
	//	PX2_SM.CallString("e_OnScale()");
	//}
	//else if (wxGetKeyState(WXK_DELETE))
	//{
	//	PX2_SM.CallString("e_OnDelete()");
	//}
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
void E_MainFrame::OnChooseItem(wxCommandEvent &e)
{
	int id = e.GetId();

	std::map<int, std::string>::iterator it = mIDScripts.find(id);

	if (it != mIDScripts.end())
	{
		std::string callStr = it->second;

		int selection = e.GetSelection();

		callStr = callStr + "(" + StringHelp::IntToString(selection) + ")";

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
		int screenOriention = dlg.mScreenOrientation;
		int width = dlg.mProjWidth;
		int height = dlg.mProjHeight;

		std::string pathName = name + "/";

		bool isProjectFolderExist = PX2_RM.IsFloderExist("Data/", pathName);
		if (isProjectFolderExist)
		{
			NirMan::GetSingleton().MessageBox(PX2_LMVAL("Notice"), PX2_LMVAL("Tip4"));
			return;
		}
		else
		{
			PX2_RM.CreateFloder("Data/", pathName);
			PX2_RM.CreateFloder("Data/", pathName + "images/");
			PX2_RM.CreateFloder("Data/", pathName + "models/");
			PX2_RM.CreateFloder("Data/", pathName + "scenes/");
			PX2_RM.CreateFloder("Data/", pathName + "scripts/");
			std::string scriptPath = "Data/" + pathName + "scripts/" + "start.lua";
			fopen(scriptPath.c_str(), "wb");

			std::string path = "Data/" + pathName + name +".px2proj";
			PX2_EDIT.GetEditMap()->NewProject(path, name, screenOriention,
				width, height);
		}
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::OnOpenProject()
{
	wxFileDialog dlg(this,
		wxT("Open project"),
		"Data/",
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
void E_MainFrame::OnExit()
{
	if (wxYES == NirMan::GetSingleton().MessageBox(PX2_LM.GetValue("Notice"),
		PX2_LM.GetValue("Tip7"), 1))
	{
		Close(true);
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::OnImport()
{
	int numObjs = PX2_SELECTION.GetNumObjects();
	Object *obj = PX2_SELECTION.GetFirstObject();
	if (1 != numObjs)
	{
		NirMan::GetSingleton().MessageBox(PX2_LMVAL("Notice"), PX2_LMVAL("Tip0"));
		return;
	}

	wxFileDialog dlg(this,
		PX2_LM.GetValue("Import"),
		wxEmptyString,
		wxEmptyString,
		wxT("object (*.px2obj)|*.px2obj|model (*.PX2OBJ)|*.PX2OBJ"));

	dlg.CenterOnParent();

	if (dlg.ShowModal() == wxID_OK)
	{
		PX2_EDIT.Import(dlg.GetPath());
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::OnExport()
{
	int numObjs = PX2_SELECTION.GetNumObjects();
	Object *obj = PX2_SELECTION.GetFirstObject();
	if (1 != numObjs)
	{
		NirMan::GetSingleton().MessageBox(PX2_LM.GetValue("Notice"), PX2_LM.GetValue("Tip3"));
		return;
	}

	wxFileDialog dlg(this,
		PX2_LM.GetValue("Export"),
		wxT("Data/"),
		wxEmptyString,
		wxT("object (*.px2obj)|*.px2obj|model (*.PX2OBJ)|*.PX2OBJ"),
		wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

	dlg.CenterOnParent();

	if (dlg.ShowModal() == wxID_OK)
	{
		PX2_EDIT.Export(obj, dlg.GetPath());
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::OnSetEditMode(int mode)
{
	PX2_EDIT.SetEditMode((Edit::EditMode)mode);
}
//----------------------------------------------------------------------------
void E_MainFrame::OnShowWindow(const std::string &tag)
{
	wxAuiPaneInfo *info = 0;

	if ("Project" == tag)
	{
		info = &(mAuiManager->GetPane(mBookMap[mProjView]));
	}
	else if ("Stage" == tag)
	{
		//info = &(mAuiManager->GetPane(mProjView));
	}
	else if ("TimeLine" == tag)
	{
		info = &(mAuiManager->GetPane(mBookMap[mTimeLineRenderView_Cot]));
	}
	else if ("ResView" == tag)
	{
		info = &(mAuiManager->GetPane(mBookMap[mResView]));
	}
	else if ("InspView" == tag)
	{
		//info = &(mAuiManager->GetPane(mBookMap[mInspView]));
	}
	else if ("ConsoleView" == tag)
	{
		//info = &(mAuiManager->GetPane(mBookMap[mLogView]));
	}
	else if ("PreView" == tag)
	{
		info = &(mAuiManager->GetPane(mBookMap[mPreViewRenderView_Cot]));
	}

	if (info && info->IsValid())
	{
		info->Show(!info->IsShown());
		mAuiManager->Update();

		if (info->IsShown())
		{
			if (info->window)
				info->window->SetFocus();
		}
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::OnEditorSimulate()
{
	bool isCanDoEdit = PX2_EDIT.CanDoEdit();
	if (isCanDoEdit) PX2_EDIT.SetEditType(Edit::ET_SIMULATE);
}
//----------------------------------------------------------------------------
void E_MainFrame::OnEditorPlay()
{
	bool isCanDoEdit = PX2_EDIT.CanDoEdit();
	if (isCanDoEdit) PX2_EDIT.SetEditType(Edit::ET_PLAY);
}
//----------------------------------------------------------------------------
void E_MainFrame::OnEditorStop()
{
	bool isCanDoEdit = PX2_EDIT.CanDoEdit();
	if (!isCanDoEdit) PX2_EDIT.SetEditType(Edit::ET_SCENE);
}
//----------------------------------------------------------------------------
void E_MainFrame::OnPlay()
{
	Project *proj = Project::GetSingletonPtr();
	if (!proj) return;

#if defined(_WIN32) || defined(WIN32)

#ifdef _DEBUG
#if defined(_WIN64) || defined(WIN64)
	WinExec("AppPlayer64D.exe", SW_SHOW);
#else
	WinExec("AppPlayerD.exe", SW_SHOW);
#endif
#else
#if defined(_WIN64) || defined(WIN64)
	WinExec("AppPlayer64.exe", SW_SHOW);
#else
	WinExec("AppPlayer.exe", SW_SHOW);
#endif
#endif

#endif
}
//----------------------------------------------------------------------------
void E_MainFrame::OnPlayConfig()
{
	DlgPlayConfig dlg(this);
	dlg.ShowModal();
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
void E_MainFrame::InspChangeWindow(int windowType)
{
	mInspView->ChangeShowWindow(windowType);
}
//----------------------------------------------------------------------------
void  E_MainFrame::OnCreateTerrain()
{
	Scene *scene = PX2_PROJ.GetScene();
	if (!scene) return;

	TerrainActor *terrainActor = scene->GetTerrainActor();
	if (terrainActor)
	{
		NirMan::GetSingleton().MessageBox(PX2_LMVAL("Notice"), PX2_LMVAL("Tip5"));
	}
	else
	{
		DlgTerrainNew dlg(mRenderViewScene);
		if (dlg.ShowModal() == wxID_OK)
		{
			PX2_CREATER.CreateActor_Terrain(scene, APoint::ORIGIN,
				dlg.mValue_TerrainName,
				dlg.mValue_TerrainWidth,
				dlg.mValue_PageWidth + 1, dlg.mValue_GridSpace);
		}
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::OnCreateTerrainPange()
{
	Scene *scene = PX2_PROJ.GetScene();
	if (!scene) return;

	RawTerrain *rawTerrain = DynamicCast<RawTerrain>(PX2_SELECTION.GetFirstObject());
	if (rawTerrain)
	{
		DlgTerrainPageNew dlg(mRenderViewScene);
		if (dlg.ShowModal() == wxID_OK)
		{
			TerrainPage *page = rawTerrain->GetPage(dlg.mRowI, dlg.mColI);
			if (page)
			{
			}
			else
			{
				PX2_CREATER.CreateTerrainPage(rawTerrain, dlg.mRowI, dlg.mColI);
			}
		}
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::OnResRefresh()
{
	ResTree::GetSingleton().ResRefresh();
}
//----------------------------------------------------------------------------
void E_MainFrame::OnResClear()
{
	ResTree::GetSingleton().ResClear();
}
//----------------------------------------------------------------------------
void E_MainFrame::OnResOpen()
{
	const SelectResData &resData = PX2_EDIT.GetSelectedResource();
	SelectResData::SelectResType type = resData.GetSelectResType();

	if (SelectResData::RT_NORMAL == type)
	{
		std::string filename = resData.ResPathname;

#if defined(_WIN32) || defined(WIN32)
		WCHAR wszPath[MAX_PATH];
		GetCurrentDirectoryW(sizeof(wszPath), wszPath);
		std::wstring fullPath = wszPath + std::wstring(_T("\\")) + filename;

		ShellExecute(0, _T("open"), fullPath.c_str(), 0, 0, SW_SHOW);
#endif
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::OnResCopyResPath()
{
	const SelectResData &resData = PX2_EDIT.GetSelectedResource();
	SelectResData::SelectResType type = resData.GetSelectResType();

	if (type == SelectResData::RT_NORMAL)
	{
		wxTextDataObject *data = new wxTextDataObject(resData.ResPathname);
		wxTheClipboard->SetData(data);
		wxTheClipboard->Close();
	}
	else
	{
		wxTextDataObject *data = new wxTextDataObject(resData.EleName);
		wxTheClipboard->SetData(data);
		wxTheClipboard->Close();
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::TimeLine_UIGroup_Delete()
{
	UICurveGroup *group = PX2_EDIT.GetTimeLineEdit()->GetSelectedUICurveGroup();

	if (group)
	{
		PX2_EDIT.GetTimeLineEdit()->ClearGroup(group);
		PX2_EDIT.GetTimeLineEdit()->SetSelectedUICurveGroup(0);
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::TimeLine_UIGroup_DeleteAll()
{
	PX2_EDIT.GetTimeLineEdit()->ClearAllGroups();
	PX2_EDIT.GetTimeLineEdit()->SetSelectedUICurveGroup(0);
}
//----------------------------------------------------------------------------
void E_MainFrame::TimeLine_SelectCtrl_InValue()
{
	CurveCtrl *ctrl = PX2_EDIT.GetTimeLineEdit()->GetSelectedCurveCtrl();
	if (!ctrl) return;

	DlgSetCurveVal dlg(mTimeLineView);
	dlg.SetVal(ctrl->GetInVal());
	dlg.SetTitle(PX2_LM.GetValue("SetInValue"));
	dlg.SetLabel(PX2_LM.GetValue("NewInValue"));
	if (dlg.ShowModal() == wxID_OK)
	{
		float val = dlg.GetVal();
		ctrl->SetInVal(val);
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::TimeLine_SelectCtrl_OutValue()
{
	CurveCtrl *ctrl = PX2_EDIT.GetTimeLineEdit()->GetSelectedCurveCtrl();
	if (!ctrl) return;

	DlgSetCurveVal dlg(mTimeLineView);
	dlg.SetVal(ctrl->GetOutVal().Z());
	dlg.SetTitle(PX2_LM.GetValue("SetOutValue"));
	dlg.SetLabel(PX2_LM.GetValue("NewOutValue"));
	if (dlg.ShowModal() == wxID_OK)
	{
		float val = dlg.GetVal();

		APoint outVal = ctrl->GetOutVal();
		outVal.Z() = val;
		ctrl->SetOutVal(outVal);
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::TimeLine_SelectCtrl_Delete()
{
	CurveCtrl *ctrl = PX2_EDIT.GetTimeLineEdit()->GetSelectedCurveCtrl();
	if (!ctrl) return;

	CurveGroup *group = PX2_EDIT.GetTimeLineEdit()->GetCurveGroup(
		ctrl->GetCurve());

	int numPoints = group->GetNumPoints();
	if (numPoints <= 1)
	{
		NirMan::GetSingleton().MessageBox(PX2_LM.GetValue("Notice"), PX2_LM.GetValue("Tip6"));
	}
	else
	{
		group->DeletePoint(ctrl->GetIndex());
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::OnProjectTreeShowLevel(int level)
{
	mProjView->GetProjTree()->SetSelectItemLevel((ProjTreeLevel)level);
}
//----------------------------------------------------------------------------
void E_MainFrame::OnProjectExpandSelect()
{
	mProjView->GetProjTree()->ExpandSelect();
}
//----------------------------------------------------------------------------
void E_MainFrame::OnProjectCollapseSelect()
{
	mProjView->GetProjTree()->CollapseSelect();
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
	const std::string &script, const std::string &tag)
{
	int id = PX2_EDIT_GETID;
	wxMenuItem *item = new wxMenuItem(menu, id, title);
	menu->Append(item);

	Connect(id, wxEVT_COMMAND_MENU_SELECTED, 
		wxCommandEventHandler(E_MainFrame::OnCommondItem));

	mIDScripts[id] = script;

	if (!tag.empty())
	{
		mTagMenuItems[tag].push_back(item);
	}

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
void E_MainFrame::EnableMenusTag(const std::string &tag, bool enable)
{
	std::map<std::string, std::vector<wxMenuItem*> >::iterator it =
		mTagMenuItems.find(tag);

	if (it != mTagMenuItems.end())
	{
		for (int i = 0; i < it->second.size(); i++)
		{
			wxMenuItem *menuItem = it->second[i];
			menuItem->Enable(enable);
		}
	}
}
//----------------------------------------------------------------------------
void E_MainFrame::AddTool(PX2wxAuiToolBar *toolBar, const std::string &icon,
	const std::string &script, const std::string &helpStr, int type)
{
	int id = PX2_EDIT_GETID;

	wxItemKind itemKind = wxITEM_NORMAL;
	if (0 == type) itemKind = wxITEM_NORMAL;
	else if (1 == type) itemKind = wxITEM_CHECK;
	else if (2 == type) itemKind = wxITEM_RADIO;

	toolBar->AddTool(id, "", wxBitmap(icon, wxBITMAP_TYPE_PNG), helpStr, 
		itemKind);

	Connect(id, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(E_MainFrame::OnCommondItem));

	mIDScripts[id] = script;
}
//----------------------------------------------------------------------------
void E_MainFrame::AddToolChoose(PX2wxAuiToolBar *toolBar, 
	const std::string &script,
	const std::string &choose0,
	const std::string &choose1,
	const std::string &choose2,
	const std::string &choose3,
	const std::string &choose4)
{
	int id = PX2_EDIT_GETID;

	wxChoice* choice = new wxChoice(toolBar, id);
	if (!choose0.empty()) choice->AppendString(choose0);
	if (!choose1.empty()) choice->AppendString(choose1);
	if (!choose2.empty()) choice->AppendString(choose2);
	if (!choose3.empty()) choice->AppendString(choose3);
	if (!choose4.empty()) choice->AppendString(choose4);
	toolBar->AddControl(choice);
	choice->Select(0);

	Connect(id, wxEVT_COMMAND_CHOICE_SELECTED,
		wxCommandEventHandler(E_MainFrame::OnChooseItem));

	mIDScripts[id] = script;
}
//----------------------------------------------------------------------------
void E_MainFrame::AddToolSeparater(PX2wxAuiToolBar *toolBar)
{
	toolBar->AddSeparator();
}
//----------------------------------------------------------------------------
void E_MainFrame::AddToolStretch(PX2wxAuiToolBar *toolBar)
{
	toolBar->AddStretchSpacer();
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
			ToolbarPane().Gripper(true).Top().Dockable(false).PaneBorder(true).
			MinSize(200, 28).MaxSize(200, 28).Top().Resizable(false).CaptionVisible(false).
			BottomDockable(false).LeftDockable(false).RightDockable(false).Floatable(false));
	}	
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateViews()
{
	_CreateMainView(true);
	_CreateProjView(false);
	_CreatePreView(false);
	_CreateResView(false);
	_CreateInspView(false);
	_CreateTimeLine(false);
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
void E_MainFrame::_CreateInspView(bool isTopStyle)
{
	std::vector<WindowObj> objs;

	mInspView = new InspView(this);
	WindowObj objInsp;
	objInsp.TheWindow = mInspView;
	objInsp.Caption = PX2_LMVAL("InspView");
	objInsp.Name = "InspView";

	mLogView = new LogView(this);
	WindowObj objLog;
	objLog.TheWindow = mLogView;
	objLog.Caption = PX2_LMVAL("ConsoleView");
	objLog.Name = "ConsoleView";

	objs.push_back(objInsp);
	objs.push_back(objLog);

	_CreateView(objs, "InspView", PX2_LM.GetValue("InspView"),
		wxAuiPaneInfo().Right(), isTopStyle);
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreatePreView(bool isTopStyle)
{
	mPreViewRenderView_Cot = new RenderView_Cot(RVT_PREVIEW, this);

	mPreView = mPreViewRenderView_Cot->GetRenderView();
	mPreView->_NewEditRenderView("PreView");

	_CreateView(mPreViewRenderView_Cot, "PreView", PX2_LM.GetValue("PreView"),
		wxAuiPaneInfo().DefaultPane().Right(), isTopStyle);
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateResView(bool isTopStyle)
{
	mResView = new ResView(this);
	
	_CreateView(mResView, "ResView", PX2_LM.GetValue("ResView"),
		wxAuiPaneInfo().DefaultPane().Right(), isTopStyle);
}
//----------------------------------------------------------------------------
void E_MainFrame::_CreateTimeLine(bool isTopStyle)
{
	mTimeLineRenderView_Cot = new RenderView_Cot(RVT_TIMELINE, this);
	mTimeLineView = mTimeLineRenderView_Cot->GetRenderView();
	mTimeLineView->_NewEditRenderView("TimeLine");

	_CreateView(mTimeLineRenderView_Cot, "TimeLine", PX2_LM.GetValue("TimeLine"),
		wxAuiPaneInfo().DefaultPane().Bottom(), isTopStyle);
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

	styleFlag ^= wxAUI_NB_WINDOWLIST_BUTTON;
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

		mBookMap[obj.TheWindow] = noteBook;
	}

	noteBook->UpdateTabsHeight();
	noteBook->Thaw();

	paneInfo.CloseButton(true).MaximizeButton(true).MinimizeButton(true)
		.PinButton(true).MinSize(200., 100).Name(panelName).
		Caption(panelCaption).CaptionVisible(!isTopStyle).Floatable(true);
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