// PX2E_App.cpp

#include "PX2E_App.hpp"
#include "PX2E_MainFrame.hpp"
#include "PX2E_RenderView.hpp"
#include "PX2E_ResTree.hpp"
#include "PX2EngineLoop.hpp"
#include "PX2Edit.hpp"
#include "PX2ToLuaEditor.hpp"
#include "PX2LuaManager.hpp"
using namespace PX2Editor;
using namespace PX2;

//-----------------------------------------------------------------------------
IMPLEMENT_APP(PX2Editor::E_App)
//-----------------------------------------------------------------------------
E_App::E_App()
{
}
//-----------------------------------------------------------------------------
E_App::~E_App()
{
}
//-----------------------------------------------------------------------------
bool E_App::OnInit()
{
	PX2_ENGINELOOP.Initlize();

	Edit *edit = new0 Edit();
	edit->Initlize();

	NirMan *nirMan = new0 NirMan();
	nirMan->Initlize();

	PX2_ENGINELOOP.Play(EngineLoop::PT_NONE);

	LuaManager *luaMan = (LuaManager*)ScriptManager::GetSingletonPtr();
	luaMan->CallFile("DataEditor/scripts/language.lua");
	tolua_PX2Editor_open(luaMan->GetLuaState());

	luaMan->CallFile("DataEditor/scripts/start.lua");

	luaMan->SetUserTypePointer("NirMan", "NirMan", nirMan);
	luaMan->SetUserTypePointer("PX2_EDIT", "Edit", Edit::GetSingletonPtr());

	wxLog::SetLogLevel(0);

	wxImage::AddHandler(new wxBMPHandler());
	wxImage::AddHandler(new wxPNGHandler());
	wxImage::AddHandler(new wxGIFHandler());
	wxFileSystem::AddHandler(new wxArchiveFSHandler());
	wxXmlResource::Get()->InitAllHandlers();
	wxXmlResource::Get()->Load(wxT("DataEditor/wxfbp/*.xrc"));

	int displayWidth, displayHeight;
	wxDisplaySize(&displayWidth, &displayHeight);

#if defined _DEBUG
#if defined(_WIN64) || defined(WIN64)
	mMainFrame = new E_MainFrame("NirvanaDx964D", 0, 0, wxMin(1024,
		displayWidth), wxMin(768, displayHeight));
#else
	mMainFrame = new E_MainFrame("NirvanaDx9D", 0, 0, wxMin(1024,
		displayWidth), wxMin(768, displayHeight));
#endif
#else
#if defined(_WIN64) || defined(WIN64)
	mMainFrame = new E_MainFrame("NirvanaDx964", 0, 0, wxMin(1024,
		displayWidth), wxMin(768, displayHeight));
#else
	mMainFrame = new E_MainFrame("NirvanaDx9", 0, 0, wxMin(1024,
		displayWidth), wxMin(768, displayHeight));
#endif
#endif

	luaMan->SetUserTypePointer("E_MainFrame", "E_MainFrame", mMainFrame);

	mMainFrame->Initlize();
	SetTopWindow(mMainFrame);
	mMainFrame->Center();
	mMainFrame->Maximize();

	PX2_ENGINELOOP.SetPt_Data(mMainFrame->GetRenderViewScene()->GetHandle());
	PX2_ENGINELOOP.SetPt_Size(Sizef(1024.0f, 768.0f));
	PX2_ENGINELOOP.InitlizeRenderer();

	mMainFrame->Show(true);

	return true;
}
//-----------------------------------------------------------------------------
int E_App::OnExit()
{
	NirMan *nirMan = NirMan::GetSingletonPtr();
	if (nirMan)
	{
		nirMan->Ternamate();
		delete0(nirMan);
		NirMan::Set(0);
	}

	Edit *edit = Edit::GetSingletonPtr();
	if (edit)
	{
		edit->Ternamate();
		delete0(edit);
		Edit::Set(0);
	}

	PX2_ENGINELOOP.Ternamate();

	return 0;
}
//-----------------------------------------------------------------------------