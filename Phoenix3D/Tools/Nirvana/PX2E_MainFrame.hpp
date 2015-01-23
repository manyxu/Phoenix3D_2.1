// PX2E_MainFrame.hpp

#ifndef PX2E_MAINFRAME_HPP
#define PX2E_MAINFRAME_HPP

#include "PX2EditorPre.hpp"

namespace PX2Editor
{

	class RenderView;

	class E_MainFrame : public wxFrame
	{
	public:
		E_MainFrame(const std::string &title, int xPos, int yPos,
			int width, int height);
		virtual ~E_MainFrame();

		bool Initlize();

		RenderView *GetRenderView();

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

	public:
		wxMenu *AddMainMenuItem(const std::string &title);
		wxMenuItem *AddMenuItem(wxMenu *menu, const std::string &title,
			const std::string &script);
		void AddSeparater(wxMenu *menu);

	protected:
		DECLARE_EVENT_TABLE()

		void _CreateMenu();
		void _CreateMainToolBar();
		void _CreateViews();
		void _CreateInsp();
		void _CreateTimeLine();
		void _CreateStatusBar();
		void _CreateView(const std::string &name, const std::string &caption,
			wxWindow *window0, wxBitmap &bitMap, wxAuiPaneInfo &paneInfo);

		bool mIsInitlized;
		wxMenuBar *mMainMenuBar;
		wxAuiManager *mAuiManager;
		wxTimer mTimer;
		std::map<int, std::string> mIDScripts;

		RenderView *mRenderView;
	};

}

#endif