/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EditorApp.cpp
*
*/

#include "PX2EditorApp.hpp"
#include "PX2MainFrame.hpp"
using namespace PX2Editor;
using namespace PX2;

//-----------------------------------------------------------------------------
IMPLEMENT_APP(PX2Editor::EditorApp)
//-----------------------------------------------------------------------------
EditorApp::EditorApp()
{
}
//-----------------------------------------------------------------------------
EditorApp::~EditorApp()
{
}
//-----------------------------------------------------------------------------
bool EditorApp::OnInit()
{
	wxLog::SetLogLevel(0);

	int displayWidth, displayHeight;
	wxDisplaySize(&displayWidth, &displayHeight);

#if defined _DEBUG
#if defined(_WIN64) || defined(WIN64)
	mMainFrame = new MainFrame("NirvanaDx964D", 0, 0, wxMin(1024,
		displayWidth), wxMin(768, displayHeight));
#else
	mMainFrame = new MainFrame("NirvanaDx9D", 0, 0, wxMin(1024,
		displayWidth), wxMin(768, displayHeight));
#endif
#else
#if defined(_WIN64) || defined(WIN64)
	mMainFrame = new MainFrame("NirvanaDx964", 0, 0, wxMin(1024,
		displayWidth), wxMin(768, displayHeight));
#else
	mMainFrame = new MainFrame("NirvanaDx9", 0, 0, wxMin(1024,
		displayWidth), wxMin(768, displayHeight));
#endif
#endif

	mMainFrame->Show(true);
	SetTopWindow(mMainFrame);
	mMainFrame->Center();
	//mMainFrame->Maximize();

	return true;
}
//-----------------------------------------------------------------------------
int EditorApp::OnExit()
{
	return 0;
}
//-----------------------------------------------------------------------------