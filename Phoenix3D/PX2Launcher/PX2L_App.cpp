// PX2L_App.cpp

#include "PX2L_App.hpp"
#include "PX2L_MainFrame.hpp"
#include "PX2EngineLoop.hpp"
#include "PX2LuaManager.hpp"
using namespace PX2Launcher;
using namespace PX2;

//-----------------------------------------------------------------------------
IMPLEMENT_APP(PX2Launcher::L_App)
//-----------------------------------------------------------------------------
L_App::L_App()
{
}
//-----------------------------------------------------------------------------
L_App::~L_App()
{
}
//-----------------------------------------------------------------------------
bool L_App::OnInit()
{
	PX2_ENGINELOOP.Initlize();


	PX2_ENGINELOOP.Play(EngineLoop::PT_NONE);

	LuaManager *luaMan = (LuaManager*)ScriptManager::GetSingletonPtr();
	luaMan->CallFile("DataLauncher/scripts/language.lua");

	luaMan->CallFile("DataLauncher/scripts/start.lua");

	wxLog::SetLogLevel(0);

	wxImage::AddHandler(new wxBMPHandler());
	wxImage::AddHandler(new wxPNGHandler());
	wxImage::AddHandler(new wxGIFHandler());
	wxFileSystem::AddHandler(new wxArchiveFSHandler());
	wxXmlResource::Get()->InitAllHandlers();
	//wxXmlResource::Get()->Load(wxT("DataLauncher/wxfbp/*.xrc"));

	int displayWidth, displayHeight;
	wxDisplaySize(&displayWidth, &displayHeight);

	std::string title = "Launcher";
	title += Renderer::GetRenderTag();

#if defined(_WIN64) || defined(WIN64)
	title += "64";
#endif

#ifdef _DEBUG
	title += "D";
#endif

	mMainFrame = new L_MainFrame(title, 0, 0, wxMin(1024, displayWidth), wxMin(768, displayHeight));
	mMainFrame->SetMinClientSize(wxSize(800, 600));
	//luaMan->SetUserTypePointer("L_MainFrame", "L_MainFrame", mMainFrame);

	mMainFrame->Initlize();
	SetTopWindow(mMainFrame);
	mMainFrame->Center();

	//PX2_ENGINELOOP.SetPt_Data(mMainFrame->GetRenderViewScene()->GetHandle());
	//PX2_ENGINELOOP.SetPt_Size(Sizef(1024.0f, 768.0f));
	//PX2_ENGINELOOP.InitlizeRenderer();

	mMainFrame->Show(true);

	return true;
}
//-----------------------------------------------------------------------------
int L_App::OnExit()
{
	PX2_ENGINELOOP.Ternamate();

	return 0;
}
//-----------------------------------------------------------------------------