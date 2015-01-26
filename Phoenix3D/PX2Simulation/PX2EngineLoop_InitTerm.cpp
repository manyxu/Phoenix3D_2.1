// PX2EngineLoop_InitTerm.cpp

#include "PX2EngineLoop.hpp"

#ifdef PX2_USE_DX9
#include "PX2Dx9RendererInput.hpp"
#include "PX2Dx9RendererData.hpp"
#endif

#ifdef PX2_USE_OPENGLES2
#include "PX2OpenGLES2RendererInput.hpp"
#include "PX2OpenGLES2RendererData.hpp"
#endif

#include "PX2Assert.hpp"
#include "PX2LuaManager.hpp"
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

	DateTime time;
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

	mTimerMan = new0 TimerManager();

	mIMEDisp = new0 IMEDispatcher();

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

	mUIManager = new0 UIManager();
	mUIManager->ComeInEventWorld();

	mAccoutManager = new0 AccoutManager();

	LuaManager *luaMan = (LuaManager*)mScriptMan;
	tolua_PX2_open(luaMan->GetLuaState());

	mScriptMan->SetUserTypePointer("PX2_LOG", "Logger", Logger::GetSingletonPtr());
	mScriptMan->SetUserTypePointer("PX2_LM", "LanguageManager", &(PX2_LM));
	mScriptMan->SetUserTypePointer("PX2_RM", "ResourceManager", ResourceManager::GetSingletonPtr());
	mScriptMan->SetUserTypePointer("PX2_SM", "ScriptManager", ScriptManager::GetSingletonPtr());

	return true;
}
//----------------------------------------------------------------------------
bool EngineLoop::InitlizeRenderer()
{
	// renderer
	mRendererInput = new0 RendererInput();
	Renderer *renderer = 0;
	Texture::Format colorFormat = Texture::TF_A8R8G8B8;
	Texture::Format depthStencilFormat = Texture::TF_D24S8;
	int numMultisamples = 0;

#if defined(_WIN32) || defined(WIN32)

	HWND hWnd = (HWND)mPt_Data;
	int width = (int)mPt_Size.Width;
	int height = (int)mPt_Size.Height;

#ifdef PX2_USE_DX9
	mRendererInput->mWindowHandle = hWnd;
	mRendererInput->mDriver = Direct3DCreate9(D3D_SDK_VERSION);
	assertion(mRendererInput->mDriver != 0, "Failed to create Direct3D9\n");
	renderer = new0 Renderer(*mRendererInput, width, height,
		colorFormat, depthStencilFormat, numMultisamples);

#else
	mRendererInput->mWindowHandle = hWnd;
	mRendererInput->mRendererDC = GetDC(hWnd);
	renderer = new0 Renderer(*mRendererInput, width, height,
		colorFormat, depthStencilFormat, numMultisamples);
#endif

#else

#ifdef PX2_USE_OPENGLES2

#ifdef __ANDROID__
	mRendererInput->mWindowHandle = 0;
	mRendererInput->mRendererDC = EGL_DEFAULT_DISPLAY;
#endif

	renderer = new0 Renderer(*mRendererInput, width, height,
		colorFormat, depthStencilFormat, numMultisamples);
#endif

#endif
	Renderer::SetDefaultRenderer(renderer);
	renderer->SetClearColor(Float4::WHITE);

	mUIManager->GetDefaultUIView()->SetRenderer(renderer);

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
#ifdef PX2_USE_OPENGLES2
		Renderer::GetDefaultRenderer()->OnRestoreDevice();
#endif

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
	PX2_UIM.Clear();
	PX2_ADM.Clear();;
	PX2_RM.Clear();
	PX2_SM.Clear();
	PX2_TimerM.ClearTimers();

	//mBeforeInBackgroundMusicEnable = PX2_SS.IsMusicEnable();
	//mBeforeInBackgroundSoundEnable = PX2_SS.IsSoundEnable();
	//PX2_SS.EnableMusic(false);
	//PX2_SS.EnableSounds(false);

#ifdef PX2_USE_OPENGLES2
	Renderer::GetDefaultRenderer()->OnLostDevice();
#endif

	mIsInBackground = true;
}
//----------------------------------------------------------------------------
bool EngineLoop::Ternamate()
{
	PX2_EW.Shutdown(true);
	
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

	if (mResMan)
	{
		mResMan->Clear();
	}

	if (mUIManager)
	{
		mUIManager->Clear();
		delete0(mUIManager);
		UIManager::Set(0);
	}

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

	if (mRoot)
	{
		mRoot->Terminate();
		delete0(mRoot);
		GraphicsRoot::Set(0);
	}

	if (mResMan)
	{
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

#ifdef PX2_USE_DX9
	if (mRendererInput)
	{
		mRendererInput->mDriver->Release();

		delete0(mRendererInput);
		mRendererInput = 0;
	}
#endif

	Logger *logger = Logger::GetSingletonPtr();
	if (logger)
	{
		delete0(logger);
		Logger::Set(0);
	}

	FString::Ternimate();

#ifdef PX2_USE_MEMORY
	Memory::Terminate("PX2Application_MemoryReport.txt", false);
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
		mProjectPath = data.GetNodeByPath("play.var").AttributeToString("projectpath");

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void EngineLoop::SetSize(const Sizef &size)
{
	mSize = size;

	Renderer *dr = Renderer::GetDefaultRenderer();
	if (dr)
	{
		dr->ResizeWindow((int)size.Width, (int)size.Height);
	}
}
//----------------------------------------------------------------------------