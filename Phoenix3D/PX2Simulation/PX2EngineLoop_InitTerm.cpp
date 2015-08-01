// PX2EngineLoop_InitTerm.cpp

#include "PX2EngineLoop.hpp"
#include "PX2Assert.hpp"
#include "PX2LuaManager.hpp"
#include "PX2RendererInput.hpp"
#include "PX2LocalDateTime.hpp"
#include "PX2PluginManager.hpp"
#include "PX2ToLua.hpp"
using namespace PX2;

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}
#include "tolua++.h"

//----------------------------------------------------------------------------
bool EngineLoop::Initlize()
{
	time_t ti; time(&ti); srand((unsigned int)ti);

#ifdef PX2_USE_MEMORY
	Memory::Initialize();
#endif

	StringHelp::Initlize();
	FString::Initlize();

	Logger *logger = new0 Logger();

#if defined(_WIN32) || defined(WIN32)
	logger->AddFileHandler("PX2Application_Log.txt", LT_INFO | LT_ERROR | LT_USER);
#endif
	logger->AddOutputWindowHandler(LT_INFO | LT_ERROR | LT_USER);
	logger->StartLogger();

	LocalDateTime time;
	int year1 = time.Year();
	int month1 = time.Month();
	int week1 = time.Week();
	int day1 = time.Day();
	int dayOfWeek1 = time.DayOfWeek();
	int dayOfYear1 = time.DayOfYear();
	int hour1 = time.Hour();
	int minute1 = time.Minute();
	int second1 = time.Second();
	int millisecond1 = time.Millisecond();
	int microsecond1 = time.Microsecond();
	PX2_LOG_INFO("Year:%d; Month:%d; Week:%d; Day:%d; DayOfWeek:%d; DayOfYear:%d; Hour:%d; Minute:%d; Second:%d; Millisecond:%d; Microsecond:%d",
		year1, month1, week1, day1, dayOfWeek1, dayOfYear1, hour1, minute1, second1, millisecond1, microsecond1);

	mDynLibMan = new0 DynLibManager();
	PX2_UNUSED(mDynLibMan);
	mPluginMan = new0 PluginManager();
	PX2_UNUSED(mPluginMan);

	mTimerMan = new0 TimerManager();

	mIMEDisp = new0 IMEDispatcher();

	mInputMan = new0 InputManager();

	mLanguageMan = new0 LanguageManager();
	mResMan = new0 ResourceManager();

	//PX2_LM.Add("Data/engine/engineLanguage.csv");

	mEventWorld = new0 EventWorld();

	mScriptMan = new0 LuaManager();

	mRoot = new0 GraphicsRoot();
	mRoot->Initlize();

	mFontMan = new0 FontManager();
	PX2_UNUSED(mFontMan);

	mADMan = new0 AddDeleteManager();
	PX2_UNUSED(mADMan);

	mSelection = new0 Selection();
	PX2_UNUSED(mSelection);

	mCreater = new0 Creater();
	PX2_UNUSED(mCreater);

	mURDoMan = new0 URDoManager();
	PX2_UNUSED(mURDoMan);

	mAccoutManager = new0 AccoutManager();

	LuaManager *luaMan = (LuaManager*)mScriptMan;
	tolua_PX2_open(luaMan->GetLuaState());

	mScriptMan->SetUserTypePointer("PX2_ENGINELOOP", "EngineLoop", this);
	mScriptMan->SetUserTypePointer("PX2_LOG", "Logger", Logger::GetSingletonPtr());
	mScriptMan->SetUserTypePointer("PX2_LM", "LanguageManager", &(PX2_LM));
	mScriptMan->SetUserTypePointer("PX2_RM", "ResourceManager", ResourceManager::GetSingletonPtr());
	mScriptMan->SetUserTypePointer("PX2_SM", "ScriptManager", ScriptManager::GetSingletonPtr());
	mScriptMan->SetUserTypePointer("PX2_SELECTION", "Selection", Selection::GetSingletonPtr());
	mScriptMan->SetUserTypePointer("PX2_CREATER", "Creater", Creater::GetSingletonPtr());
	mScriptMan->SetUserTypePointer("PX2_URM", "URDoManager", URDoManager::GetSingletonPtr());

	LoadBoost("Data/boost.xml");

	return true;
}
//----------------------------------------------------------------------------
bool EngineLoop::InitlizeRenderer()
{
	Renderer *defRenderer = Renderer::CreateRenderer(mPt_Data, (int)mPt_Size.Width,
		(int)mPt_Size.Height, 0, mRendererInput);

	Renderer::SetDefaultRenderer(defRenderer);

	mScreenSize = mPt_Size;

	return true;
}
//----------------------------------------------------------------------------
void EngineLoop::WillEnterForeground(bool isFirstTime)
{
	if (!mIsInBackground)
		return;

	if (isFirstTime)
	{
		PX2_FM.Initlize();
	}
	else
	{
		Renderer::GetDefaultRenderer()->OnRestoreDevice();

		PX2_FM.SetNeedUpdate();
	}

	//	PX2_SS.EnableMusic(mBeforeInBackgroundMusicEnable);
	//	PX2_SS.EnableSounds(mBeforeInBackgroundSoundEnable);

	//PX2_SOUNDM.PreLoad();

	mIsInBackground = false;
}
//----------------------------------------------------------------------------
void EngineLoop::DidEnterBackground()
{
	PX2_FM.Terminate();
	PX2_AM.DeleteAllUsers();
	PX2_ADM.Clear();;
	PX2_RM.Clear();
	PX2_SM.Clear();
	PX2_TimerM.ClearTimers();

	//mBeforeInBackgroundMusicEnable = PX2_SS.IsMusicEnable();
	//mBeforeInBackgroundSoundEnable = PX2_SS.IsSoundEnable();
	//PX2_SS.EnableMusic(false);
	//PX2_SS.EnableSounds(false);

	Renderer::GetDefaultRenderer()->OnLostDevice();

	mIsInBackground = true;
}
//----------------------------------------------------------------------------
bool EngineLoop::Ternamate()
{
	Play(EngineLoop::PT_NONE);

	PX2_EW.Shutdown(true);

	PX2_PLUGINMAN.TernamateAllPlugins();
	
	if (mSelection)
	{
		mSelection->Clear();
		delete0(mSelection);
		Selection::Set(0);
	}

	if (mURDoMan)
	{
		delete0(mURDoMan);
		URDoManager::Set(0);
	}

	if (mCreater)
	{
		delete0(mCreater);
		Creater::Set(0);
	}

	if (mADMan)
	{
		mADMan->Clear();
		delete0(mADMan);
		AddDeleteManager::Set(0);
	}

	if (mAccoutManager)
	{
		delete0(mAccoutManager);
		AccoutManager::Set(0);
	}

	Project::Destory();

	if (mScriptMan)
	{
		delete0(mScriptMan);
		ScriptManager::Set(0);
	}

	if (mFontMan)
	{
		delete0(mFontMan);
		FontManager::Set(0);
	}

	if (mScriptMan)
	{
		delete0(mScriptMan);
		ScriptManager::Set(0);
	}

	bool isInEditor = mRoot->IsInEditor();
	if (mRoot)
	{
		mRoot->Terminate();
		delete0(mRoot);
		GraphicsRoot::Set(0);
	}

	if (mInputMan)
	{
		delete0(mInputMan);
		mInputMan = 0;
	}

	if (mResMan)
	{
		mResMan->Clear();
		delete0(mResMan);
		ResourceManager::Set(0);
	}

	if (mLanguageMan)
	{
		delete0(mLanguageMan);
		LanguageManager::Set(0);
	}

	if (mIMEDisp)
	{ // 需要在资源管理器之后释放
		delete0(mIMEDisp);
		IMEDispatcher::Set(0);
	}

	if (mEventWorld)
	{
		delete0(mEventWorld);
		EventWorld::Set(0);
	}

	if (mTimerMan)
	{
		delete0(mTimerMan);
		TimerManager::Set(0);
	}

	Renderer *defaultRenderer = Renderer::GetDefaultRenderer();
	if (defaultRenderer)
	{
		delete0(defaultRenderer);
		Renderer::SetDefaultRenderer(0);
	}

	if (mRendererInput)
	{
		mRendererInput->Ternamate();

		delete0(mRendererInput);
		mRendererInput = 0;
	}

	PX2_PLUGINMAN.UnloadPlugins();
	if (mPluginMan)
	{
		delete0(mPluginMan);
		PluginManager::Set(0);
	}

	if (mDynLibMan)
	{
		delete0(mDynLibMan);
		DynLibManager::Set(0);
	}

	Logger *logger = Logger::GetSingletonPtr();
	if (logger)
	{
		delete0(logger);
		Logger::Set(0);
	}

	FString::Ternimate();

#ifdef PX2_USE_MEMORY

	if (isInEditor)
	{
		Memory::Terminate("Editor_MemoryReport.txt", false);
	}
	else
	{
		Memory::Terminate("PX2Application_MemoryReport.txt", false);
	}

#endif

	return true;
}
//----------------------------------------------------------------------------
bool EngineLoop::LoadBoost(const std::string &filename)
{
	XMLData data;

	int bufferSize = 0;
	char *buffer = 0;
	ResourceManager::GetSingleton().LoadBuffer(filename, bufferSize, buffer);
	if (!buffer || bufferSize == 0) return false;

	if (data.LoadBuffer(buffer, bufferSize))
	{
		mBoostSize.Width = data.GetNodeByPath("config.var").AttributeToFloat("width");
		mBoostSize.Height = data.GetNodeByPath("config.var").AttributeToFloat("height");
		mProjectName = data.GetNodeByPath("play.var").AttributeToString("projectname");
		mPlayLogicMode = _StrToPlayLogicMode(data.GetNodeByPath("play.var").AttributeToString("playlogicmode"));

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
std::string EngineLoop::GetPlayLogicModeStr() const
{
	if (PLM_SIMPLE == mPlayLogicMode)
		return "simple";

	return "logic";
}
//----------------------------------------------------------------------------
EngineLoop::PlayLogicMode EngineLoop::_StrToPlayLogicMode(const std::string &str)
{
	if ("simple" == str)
		EngineLoop::PLM_SIMPLE;
	
	return PLM_LOGIC;
}
//----------------------------------------------------------------------------
void EngineLoop::SetBoostSize(const Sizef &size)
{
	mBoostSize = size;
}
//----------------------------------------------------------------------------
void EngineLoop::SetPlayLogicMode(PlayLogicMode mode)
{
	mPlayLogicMode = mode;
}
//----------------------------------------------------------------------------
bool EngineLoop::WriteBoost()
{
	XMLData data;

	data.Create();

	XMLNode boostNode = data.NewChild("boost");
	boostNode.SetAttributeString("name", "boost");

	XMLNode configNode = boostNode.NewChild("config");

	XMLNode varNode_config = configNode.NewChild("var");
	varNode_config.SetAttributeInt("width", (int)mBoostSize.Width);
	varNode_config.SetAttributeInt("height", (int)mBoostSize.Height);

	XMLNode playNode = boostNode.NewChild("play");
	XMLNode varNode_play = playNode.NewChild("var");
	varNode_play.SetAttributeString("projectname", mProjectName);
	varNode_play.SetAttributeString("playlogicmode", GetPlayLogicModeStr());

	return data.SaveFile("Data/boost.xml");
}
//----------------------------------------------------------------------------
void EngineLoop::SetScreenSize(const Sizef &screenSize)
{
	mScreenSize = screenSize;

	Renderer *defaultRenderer = Renderer::GetDefaultRenderer();
	if (defaultRenderer) defaultRenderer->ResizeWindow((int)mScreenSize.Width, 
		(int)mScreenSize.Height);

	Project *proj = Project::GetSingletonPtr();
	if (!proj) return;

	const Sizef &projSize = proj->GetSize();

	if (IsDoAdjustScreenViewRect())
	{
		float screenWidthOverHeight = screenSize.Width / screenSize.Height;
		float projWidthOverHeight = projSize.Width / projSize.Height;

		if (screenWidthOverHeight >= projWidthOverHeight)
		{
			float left = (screenWidthOverHeight - projWidthOverHeight) / 2.0f * screenSize.Height;

			mAdjustViewPort.Left = left;
			mAdjustViewPort.Bottom = 0.0f;
			mAdjustViewPort.Right = screenSize.Width - left;
			mAdjustViewPort.Top = screenSize.Height;
		}
		else
		{
			float bot = (1.0f / screenWidthOverHeight - 1.0f / projWidthOverHeight) / 2.0f * screenSize.Width;

			mAdjustViewPort.Left = 0.0f;
			mAdjustViewPort.Bottom = bot;
			mAdjustViewPort.Right = screenSize.Width;
			mAdjustViewPort.Top = screenSize.Height - bot;
		}
	}
	else
	{
		mAdjustViewPort = Rectf(0.0f, 0.0f, screenSize.Width, screenSize.Height);
	}

	PX2_GR.SetScreenSize(screenSize);
	PX2_GR.SetViewRect(mAdjustViewPort);
	proj->SetViewRect(mAdjustViewPort);
}
//----------------------------------------------------------------------------
Rectf EngineLoop::GetViewPortAdjustFromProject(const Rectf &viewPort)
{
	Project *proj = Project::GetSingletonPtr();
	if (!proj) return Rectf();

	const Sizef &projSize = proj->GetSize();

	Rectf rect;

	float leftPercent = viewPort.Left / projSize.Width;
	float bottomPercent = viewPort.Bottom / projSize.Height;
	float widthPercent = viewPort.Width() / projSize.Width;
	float heightPercent = viewPort.Height() / projSize.Height;

	rect.Left = mAdjustViewPort.Left + leftPercent * mAdjustViewPort.Width();
	rect.Bottom = mAdjustViewPort.Bottom + bottomPercent * mAdjustViewPort.Height();
	rect.Right = Mathf::Floor(rect.Left + widthPercent * mAdjustViewPort.Width());
	rect.Top = Mathf::Floor(rect.Bottom + heightPercent * mAdjustViewPort.Height());

	return rect;
}
//----------------------------------------------------------------------------
Rectf EngineLoop::GetViewPortAdjustFromProject(float left, float bottom,
	float width, float height)
{
	Rectf rect;
	rect.Left = left;
	rect.Bottom = bottom;
	rect.Right = left + width;
	rect.Top = bottom + height;
	return GetViewPortAdjustFromProject(rect);
}
//----------------------------------------------------------------------------