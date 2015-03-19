// PX2L_App.hpp

#ifndef PX2L_APP_HPP
#define PX2L_APP_HPP

#include "PX2LauncherPre.hpp"

namespace PX2Launcher
{

	class L_MainFrame;

	class L_App : public wxApp
	{
	public:
		L_App();
		~L_App();

		virtual bool OnInit();
		virtual int OnExit();

	protected:
		L_MainFrame *mMainFrame;
	};

	DECLARE_APP(L_App)
}

#endif