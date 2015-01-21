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

	public:
		void AddMainMenuItem(const std::string &title);

	protected:
		DECLARE_EVENT_TABLE()

		void _CreateMenu();
		void _CreateMainToolBar();
		void _CreateViews();
		void _CreateStatusBar();

		bool mIsInitlized;
		wxMenuBar *mMainMenuBar;
		wxAuiManager *mAuiManager;
		wxTimer mTimer;

		RenderView *mRenderView;
	};

}

#endif