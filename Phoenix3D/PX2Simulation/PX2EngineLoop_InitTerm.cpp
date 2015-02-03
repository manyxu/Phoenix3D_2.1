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

	mScriptMan->SetUserTypePointer("PX2_LOG", "Logger", Logger::GetSingletonPtr());
	mScriptMan->SetUserTypePointer("PX2_LM", "LanguageManager", &(PX2_LM));
	mScriptMan->SetUserTypePointer("PX2_RM", "ResourceManager", ResourceManager::GetSingletonPtr());
	mScriptMan->SetUserTypePointer("PX2_SM", "ScriptManager", ScriptManager::GetSingletonPtr());
	mScriptMan->SetUserTypePointer("PX2_SELECTION", "Selection", Selection::GetSingletonPtr());
	mScriptMan->SetUserTypePointer("PX2_CREATER", "Creater", Creater::GetSingletonPtr());

	return true;
}
//----------------------------------------------------------------------------
bool EngineLoop::InitlizeRenderer()
{
	Renderer *defRenderer = CreateRenderer(mPt_Data, (int)mPt_Size.Width,
		(int)mPt_Size.Height, 0, mRendererInput);

	Renderer::SetDefaultRenderer(defRenderer);

	return true;
}
//----------------------------------------------------------------------------
Renderer *EngineLoop::CreateRenderer(void *ptData, int width, int height,
	int numMultisamples, RendererInput* &renderInput)
{
	PdrRendererInput *pdrRenderInput = new0 PdrRendererInput();
	renderInput = pdrRenderInput;

	Renderer *renderer = 0;
	Texture::Format colorFormat = Texture::TF_A8R8G8B8;
	Texture::Format depthStencilFormat = Texture::TF_D24S8;

#if defined(_WIN32) || defined(WIN32)

	HWND hWnd = (HWND)ptData;

#ifdef PX2_USE_DX9
	pdrRenderInput->mWindowHandle = hWnd;
	pdrRenderInput->mDriver = Direct3DCreate9(D3D_SDK_VERSION);
	assertion(pdrRenderInput->mDriver != 0, "Failed to create Direct3D9\n");
	renderer = new0 Renderer(*pdrRenderInput, width, height,
		colorFormat, depthStencilFormat, numMultisamples);

#else
	pdrRenderInput->mWindowHandle = hWnd;
	pdrRenderInput->mRendererDC = GetDC(hWnd);
	renderer = new0 Renderer(*pdrRenderInput, width, height,
		colorFormat, depthStencilFormat, numMultisamples);
#endif

#else

#ifdef PX2_USE_OPENGLES2

#ifdef __ANDROID__
	pdrRenderInput->mWindowHandle = 0;
	pdrRenderInput->mRendererDC = EGL_DEFAULT_DISPLAY;
#endif

	renderer = new0 Renderer(*pdrRenderInput, width, height,
		colorFormat, depthStencilFormat, numMultisamples);
#endif

#endif

	renderer->SetClearColor(Float4::WHITE);

	return renderer;
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

	if (mInputMan)
	{
		delete0(mInputMan);
		mInputMan = 0;
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
		mRendererInput->Ternamate();

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

		PX2_GR.SetScreenSize(screenSize);
		PX2_GR.SetViewRect(mAdjustViewPort);
		proj->SetViewRect(mAdjustViewPort);
	}
	else
	{
		Rectf rect = Rectf(0.0f, 0.0f, screenSize.Width, screenSize.Height);

		PX2_GR.SetScreenSize(screenSize);
		PX2_GR.SetViewRect(rect);
		proj->SetViewRect(rect);
	}
}
//----------------------------------------------------------------------------