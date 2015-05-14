// PX2L_MainFrame.hpp

#ifndef PX2L_MAINFRAME_HPP
#define PX2L_MAINFRAME_HPP

#include "PX2LauncherPre.hpp"
#include "PX2EventHandler.hpp"
#include "PX2Singleton_NeedNew.hpp"
#include "PX2L_MainView.hpp"

namespace PX2Launcher
{

	class L_MainFrame : public wxFrame, public PX2::EventHandler, public PX2::Singleton <L_MainFrame>
	{
	public:
		L_MainFrame(const std::string &title, int xPos, int yPos, int width, int height);
		virtual ~L_MainFrame();

		void OnTimer(wxTimerEvent& e);

		bool Initlize();

	protected:
		DECLARE_EVENT_TABLE()

	protected:
		bool mIsInitlized;

		L_MainView *mMainView;
	};

}

#endif