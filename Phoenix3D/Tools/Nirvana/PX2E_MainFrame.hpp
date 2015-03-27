// PX2E_MainFrame.hpp

#ifndef PX2E_MAINFRAME_HPP
#define PX2E_MAINFRAME_HPP

#include "PX2EditorPre.hpp"
#include "PX2EventHandler.hpp"
#include "PX2Singleton_NeedNew.hpp"
#include "PX2EditParams.hpp"
#include "PX2EffectableController.hpp"

namespace PX2Editor
{

	class StartView;
	class RenderView;
	class UIRenderView;
	class ProjView;
	class ResView;
	class InspView;
	class TopView;
	class LogicView;
	class LogView;
	class RenderView_Cot;
	class PX2wxAuiNotebook;
	class PX2wxAuiToolBar;

	class E_MainFrame : public wxFrame, public PX2::EventHandler, public PX2::Singleton<E_MainFrame>
	{
	public:
		E_MainFrame(const std::string &title, int xPos, int yPos,
			int width, int height);
		virtual ~E_MainFrame();

		bool Initlize();

		RenderView *GetRenderViewScene();

		virtual void DoExecute(PX2::Event *event);

		void OnTimer(wxTimerEvent& e);
		void OnCommondItem(wxCommandEvent &e);
		void OnMenuToolItem(wxMouseEvent &e);
		void OnMenuClose(wxMenuEvent &e);
		void OnAllowNotebookDnD(wxAuiNotebookEvent& evt);
		void OnNotebookPageClose(wxAuiNotebookEvent& evt);
		void OnNotebookPageClosed(wxAuiNotebookEvent& evt);

		void OnShortcutKeyDown();

		void OnNewProject();
		void OnOpenProject();
		void OnSaveProject();
		void OnSaveProjectAs();
		void OnCloseProject();

		void OnNewScene();
		void OnOpenScene();
		void OnSaveScene();
		void OnSaveSceneAs();
		void OnCloseScene();

		void OnImport();
		void OnExport();

		void OnShowWindow(const std::string &tag);

		void OnEditorSimulate();
		void OnEditorPlay();
		void OnEditorStop();
		void OnPlay();
		void OnPlayConfig();

		void OnSetting();

		void OnSetEditMode(int type);

		void OnCreateTerrain();
		void OnCreateTerrainPange();

		void InspChangeWindow(int windowType);
		
		void OnResRefresh();
		void OnResClear();
		void OnResOpen();
		void OnResCopyResPath();

		void TimeLine_UIGroup_Delete();
		void TimeLine_UIGroup_DeleteAll();
		void TimeLine_SelectCtrl_InValue();
		void TimeLine_SelectCtrl_OutValue();
		void TimeLine_SelectCtrl_Delete();

	public:
		wxMenu *AddMainMenuItem(const std::string &title);
		wxMenuItem *AddMenuItem(wxMenu *menu, const std::string &title,
			const std::string &script);
		void AddSeparater(wxMenu *menu);
		wxAuiManager *GetAuiMananger();

		void AddTool(PX2wxAuiToolBar *toolBar, const std::string &icon, std::string &script);
		void AddToolSeparater(PX2wxAuiToolBar *toolBar);

	protected:
		DECLARE_EVENT_TABLE()

		void _CreateMainToolBar();
		void _CreateMenu();
		void _CreateViews();

		void _CreateMainView(bool isTopStyle);
		void _CreateProjView(bool isTopStyle);
		void _CreateInspView(bool isTopStyle);
		void _CreatePreView(bool isTopStyle);
		void _CreateResView(bool isTopStyle);
		void _CreateTimeLine(bool isTopStyle);
		void _CreateStatusBar();

		void _UpdateStatusSelectObject(int index);
		void _UpdateStatusSelectRes(int index);
		void _UpdateStatusPickingPos(int index);

		struct WindowObj
		{
			WindowObj()
			{
				TheWindow = 0; 
				NoteBook = 0;
			}
			~WindowObj() {}

			std::string Name;
			std::string Caption;
			wxWindow *TheWindow;

			PX2wxAuiNotebook *NoteBook;
		};

		PX2wxAuiNotebook *_CreateView(wxWindow *window0,
			const std::string &paneName, const std::string &panelCaption,
			wxAuiPaneInfo &paneInfo,
			bool isTopStyle);

		PX2wxAuiNotebook *_CreateView(std::vector<WindowObj> &objs,
			const std::string &panelName,
			const std::string &panelCaption,
			wxAuiPaneInfo &paneInfo,
			bool isTopStyle);

	protected:
		std::string mPerspConfigName;

		bool mIsInitlized;
		
		wxMenuBar *mMainMenuBar;
		wxAuiManager *mAuiManager;
		std::map<std::string, WindowObj> mWindowObjs;

		wxTimer mTimer;
		std::map<int, std::string> mIDScripts;

		PX2wxAuiToolBar *mToolBarCaption;
		PX2wxAuiToolBar *mToolBarMenu;
		PX2wxAuiToolBar *mToolBarMain;

		wxMenu *mToolMenu;

		TopView *mTopView;
		StartView *mStartView;
		RenderView *mRenderViewScene;
		RenderView *mRenderViewLogic;
		ProjView *mProjView;
		ResView *mResView;
		InspView *mInspView;

		RenderView_Cot *mPreViewRenderView_Cot;
		RenderView *mPreView;

		RenderView_Cot *mTimeLineRenderView_Cot;
		RenderView *mTimeLineView;
		
		LogView *mLogView;

		PX2wxAuiNotebook *mNoteBookCenter;

		std::map<wxWindow*, wxAuiNotebook*> mBookMap;

		bool mIsCrossCursor;
	};

}

#endif