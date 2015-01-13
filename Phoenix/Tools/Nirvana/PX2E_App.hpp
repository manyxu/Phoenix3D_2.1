// PX2E_App.hpp

#ifndef PX2E_APP_HPP
#define PX2E_APP_HPP

#include "PX2EditorPre.hpp"

namespace PX2Editor
{

	class E_MainFrame;

	class E_App : public wxApp, public PX2::Singleton < E_App >
	{
	public:
		E_App();
		~E_App();

		virtual bool OnInit();
		virtual int OnExit();

	protected:
		E_MainFrame *mMainFrame;
	};

	DECLARE_APP(E_App)
}

#endif