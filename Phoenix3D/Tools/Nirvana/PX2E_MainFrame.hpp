// PX2E_MainFrame.hpp

#ifndef PX2E_MAINFRAME_HPP
#define PX2E_MAINFRAME_HPP

#include "PX2EditorPre.hpp"
#include "PX2EventHandler.hpp"
#include "PX2Singleton_NeedNew.hpp"

namespace PX2Editor
{

	class StartView;
	class RenderView;
	class ProjView;
	class ResView;
	class InspView;
	class PX2wxAuiNotebook;

	class E_MainFrame : public wxFrame, public PX2::EventHandler, public PX2::Singleton<E_MainFrame>
	{
	public:
		E_MainFrame(const std::string &title, int xPos, int yPos,
			int width, int height);
		virtual ~E_MainFrame();

		bool Initlize();
		void AddEventHandlers();

		RenderView *GetRenderView();

		virtual void DoExecute(PX2::Event *event);

		void OnTimer(wxTimerEvent& e);
		void OnMenuItem(wxCommandEvent &e);

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

		void OnSetEditMode(int type);
		void OnSetting();

	public:
		wxMenu *AddMainMenuItem(const std::string &title);
		wxMenuItem *AddMenuItem(wxMenu *menu, const std::string &title,
			const std::string &script);
		void AddSeparater(wxMenu *menu);
		wxAuiManager *GetAuiMananger();

	protected:
		DECLARE_EVENT_TABLE()

		void _CreateMenu();
		void _CreateMainToolBar();
		void _CreateViews();
		void _CreateProjView();
		void _CreateMainView();
		void _ShowRenderView(bool show);
		void _CreateInsp();
		void _CreateTimeLine();
		void _CreateStatusBar();

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

		PX2wxAuiNotebook *_CreateView(wxWindow *window0, const std::string &name0, const std::string &caption0,
			const std::string &caption,
			wxAuiPaneInfo &paneInfo,
			bool isTopStyle=false);

		PX2wxAuiNotebook *_CreateView(std::vector<WindowObj> &objs, const std::string &caption,
			wxAuiPaneInfo &paneInfo,
			bool isTopStyle = false);

		bool mIsInitlized;
		
		wxMenuBar *mMainMenuBar;
		wxAuiManager *mAuiManager;
		std::map<std::string, WindowObj> mWindowObjs;

		wxTimer mTimer;
		std::map<int, std::string> mIDScripts;

		StartView *mStartView;
		RenderView *mRenderView;
		bool mIsShowRenderView;
		ProjView *mProjView;
		ResView *mResView;
		InspView *mInspView;

		PX2wxAuiNotebook *mNoteBookCenter;

		bool mIsCrossCursor;
	};

}

#endif