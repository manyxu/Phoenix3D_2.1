/*
*
* 文件名称	：	PX2ApplicationBase.cpp
*
*/

#include "PX2ToLua.hpp"
#include "PX2ApplicationBase.hpp"
#include "PX2LocalDateTime.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
bool ApplicationBase::msIsInitlized = false;
ApplicationBase::AppInitlizeFun ApplicationBase::msAppInitlizeFun = 0;
ApplicationBase::AppTernamateFun ApplicationBase::msAppTernamateFun = 0;
ApplicationBase* ApplicationBase::msApplication = 0;
ApplicationBase::EntryPoint ApplicationBase::msEntry = 0;
//----------------------------------------------------------------------------
ApplicationBase::ApplicationBase ()
	:
	mXPosition(0),
	mYPosition(0),
	mWidth(800),
	mHeight(600),
	mAllowResize(true),
	mClearColor(Float4(1.0f, 0.0f, 0.0f, 1.0f)),
	mColorFormat(Texture::TF_A8R8G8B8),
	mRenderer(0),
	mDepthStencilFormat(Texture::TF_D24S8),
	mNumMultisamples(0),
	mRoot(0),
	mEventWorld(0),
	mScriptMan(0),
	mTimerMan(0),
	mLanguageMan(0),
	mFontMan(0),
	mInitScreenWidth(960.0f),
	mInitScreenHeight(640.0f),
	mScreenSuitType(AST_960X640),
	mIMEDisp(0),
	mDBM(0),
	mResMan(0),
	mPauseGame(false),
	mFrameRate(0.0f),
	mNumFrames(0),
	mFrameTime(0.0f),
	mUpdateDrawInfo(false),
	mApplicationTime(0.0f),
	mLastApplicationTime(0.0f),
	mElapsedTimeTemp(0.0f),
	mElapsedTimeUser(0.0f),
	mIsTimeInited(false),
	mIsInBackground(false)
{
#ifdef _DEBUG
	mWindowTitle = "ApplicationD";
#else
	mWindowTitle = "Application";
#endif
}
//----------------------------------------------------------------------------
ApplicationBase::~ApplicationBase ()
{
}
//----------------------------------------------------------------------------
bool ApplicationBase::IsInitlized ()
{
	return msIsInitlized;
}
//----------------------------------------------------------------------------
void ApplicationBase::SetInitScreenWidthHeight (float width, float height)
{
	mInitScreenWidth = width;
	mInitScreenHeight = height;

	if (width > height)
	{
		float widthAdjuge = 640.0f * mInitScreenWidth/mInitScreenHeight;
		if (Mathf::FAbs(1136.0f-widthAdjuge) < Mathf::FAbs(960.0f-widthAdjuge))
		{
			mScreenSuitType = AST_1136X640;
		}
		else
		{
			mScreenSuitType = AST_960X640;
		}
	}
	else
	{
		float heightAdjuge = 640.0f * mInitScreenHeight/mInitScreenWidth;
		if (Mathf::FAbs(1136.0f-heightAdjuge) < Mathf::FAbs(960.0f-heightAdjuge))
		{
			mScreenSuitType = AST_640X1136;
		}
		else
		{
			mScreenSuitType = AST_640X960;
		}
	}
}
//----------------------------------------------------------------------------
int ApplicationBase::GetProjSuitType () const
{
	return mScreenSuitType;
}
//----------------------------------------------------------------------------
bool ApplicationBase::Initlize ()
{
	if (msIsInitlized)
		return true;

	// srand
	time_t ti;
	time(&ti);
	srand((unsigned int)ti);

#ifdef PX2_USE_MEMORY
	Memory::Initialize();
#endif

	StringHelp::Initlize();
	FString::Initlize();

	Logger *logger = new0 Logger();

#if defined(_WIN32) || defined(WIN32)
	logger->AddFileHandler("PX2Application_Log.txt", LT_INFO|LT_ERROR|LT_USER);
#endif
	logger->AddOutputWindowHandler(LT_INFO|LT_ERROR|LT_USER);
	logger->StartLogger();

	//DateTime time;
	//int year1 = time.Year();
	//int month1 = time.Month();
	//int week1 = time.Week();
	//int day1 = time.Day();
	//int dayOfWeek1 = time.DayOfWeek();
	//int dayOfYear1 = time.DayOfYear();
	//int hour1 = time.Hour();
	//int minute1 = time.Minute();
	//int second1 = time.Second();
	//int millisecond1 = time.Millisecond();
	//int microsecond1 = time.Microsecond();
	//PX2_LOG_INFO("Year:%d; Month:%d; Week:%d; Day:%d; DayOfWeek:%d; DayOfYear:%d; Hour:%d; Minute:%d; Second:%d; Millisecond:%d; Microsecond:%d",
	//	year1, month1, week1, day1, dayOfWeek1, dayOfYear1, hour1, minute1, second1, millisecond1, microsecond1);

	PX2_LOG_INFO("Begin ApplicationBase::Initlize.");

	mTimerMan = new0 TimerManager();

	mIMEDisp = new0 IMEDispatcher();
	PX2_UNUSED(mIMEDisp);

	mLanguageMan = new0 LanguageManager();

	mResMan = new0 ResourceManager();
	//PX2_LM.Add("Data/engine/engineLanguage.csv");

	mEventWorld = new0 EventWorld();
	mEventWorld->ComeIn(this);

#if defined (PX2_LUA)
	//mScriptMan = ScriptManager::Create(ScriptManager::ST_LUA);
	//LuaManager *luaMan = (LuaManager*)mScriptMan;
#endif

	mRoot = new0 GraphicsRoot();
	mRoot->Initlize();

//	mGameMan = new0 GameManager();
//	mGameMan->LoadBoost("Data/boost.xml");
//	int width = mGameMan->GetBoostWidth();
//	int height = mGameMan->GetBoostHeight();
//
//	std::string projPath = mGameMan->GetProjectPath();
//	if (0!=width && 0!=height)
//	{
//		mWidth = width;
//		mHeight = height;
//	}
//
//	mInputEventAdapter = new0 InputEventAdapter(); // input manager created in it
//	mInputEventAdapter->Convert2Touch(true);
//	mInputEventAdapter->GetInputEventListener()->AddHandler(mGameMan);
//
//	mFontMan = new0 FontManager();
//	PX2_UNUSED(mFontMan);
//
//	mUIManager = new0 UIManager();
//	mEventWorld->ComeIn(mUIManager);
//	mInputEventAdapter->GetInputEventListener()->AddHandler(mUIManager->GetDefaultView());
//
//	SoundSystemInitInfo info;
//	info.MaxChannels = 24;
//	info.DopplerScale = 1.0f;
//	info.DistanceFactor = 100.0f;
//	info.RolloffScale = 1.2f;
//#if defined(_WIN32) || defined(WIN32)
//	mSoundSystem = SoundSystem::Create(SoundSystem::ST_FMOD, info);
//#elif defined (__ANDROID__)
//	mSoundSystem = SoundSystem::Create(SoundSystem::ST_ANDROID, info);
//#endif
//
//	mProject = new0 Project();
//	mProject->SetInGamePlay(true);
//	mProject->Load(projPath);
//#if defined (__ANDROID__)
//	if (AST_960X640==mScreenSuitType)
//	{
//		mProject->SetWidth(960.0f);
//		mProject->SetHeight(640.0f);
//	}
//	else if (AST_1136X640==mScreenSuitType)
//	{
//		mProject->SetWidth(1136.0f);
//		mProject->SetHeight(640.0f);
//	}
//	else if (AST_640X960 == mScreenSuitType)
//	{
//		mProject->SetWidth(640.0f);
//		mProject->SetHeight(960.0f);
//	}
//	else if (AST_640X1136 == mScreenSuitType)
//	{
//		mProject->SetWidth(640.0f);
//		mProject->SetHeight(1136.0f);
//	}
//#endif
//	mUIManager->GetDefaultView()->SetProjSize((float)mProject->GetWidth(), (float)mProject->GetHeight());
//	Float4 color = mProject->GetColor();
//
//	bool loadDataVersion = PX2_RM.LoadDataVersionXML("Data/version.xml");
//	if (!loadDataVersion)
//	{
//		assertion(false, "Load Data/version.xml failed.\n");
//		PX2_LOG_ERROR("Load Data/version.xml failed.");
//	}
//
//	PX2_LOG_INFO("Begin ApplicationBase::OnInitlizeApp.");
	OnInitlizeApp();
//	
//	mInputEventAdapter->Initlize();
//
//	PX2_LOG_INFO("Begin ApplicationBase::OnSize.");
//	OnSize(width, height);
//
//	mScriptMan->SetUserTypePointer("PX2_LOG", "Logger", Logger::GetSingletonPtr());
//	mScriptMan->SetUserTypePointer("PX2_GM", "GameManager", mGameMan);
//	mScriptMan->SetUserTypePointer("PX2_PROJ", "Project", mProject);
//	mScriptMan->SetUserTypePointer("PX2_LM", "LanguageManager", &(PX2_LM));
//	mScriptMan->SetUserTypePointer("PX2_RM", "ResourceManager", mResMan);
//	mScriptMan->SetUserTypePointer("PX2_SM", "ScriptManager", mScriptMan);
//	mScriptMan->SetUserTypePointer("PX2_UIM", "UIManager", mUIManager);
//	mScriptMan->SetUserTypePointer("PX2_SS", "SoundSystem", mSoundSystem);
//	mScriptMan->SetUserTypePointer("PX2_SOUNDM", "SoundManager", SoundManager::GetSingletonPtr());
//	
//	PX2_LOG_INFO("OnInitlize()");
	OnInitlize();
//
//	mGameMan->Play(true);

	msIsInitlized = true;

	return true;
}
//----------------------------------------------------------------------------
int ApplicationBase::GetWidth ()
{
	return mWidth;
}
//----------------------------------------------------------------------------
int ApplicationBase::GetHeight ()
{
	return mHeight;
}
//----------------------------------------------------------------------------
bool ApplicationBase::OnIdle ()
{
	mApplicationTime = (float)GetTimeInSeconds();
	if (mApplicationTime < 0.0f)
	{
		ResetTime();
		mIsTimeInited = false;
	}

	if (!mIsTimeInited)
	{
		mLastApplicationTime = mApplicationTime;
		mElapsedTimeTemp = 0.0f;
		mIsTimeInited = true;
	}
	else
	{
		mElapsedTimeTemp = mApplicationTime - mLastApplicationTime;
		if(mElapsedTimeTemp > 0.2f) mElapsedTimeTemp = 0.2f;
		mLastApplicationTime = mApplicationTime;
	}

	//float elapsedTime = mElapsedTimeTemp;
	//mElapsedTimeUser += mElapsedTimeTemp;
	//if (mElapsedTimeUser < 0.026f)
	//{
	//	return false;
	//}
	//else
	//{
	//	elapsedTime = mElapsedTimeUser;
	//	mElapsedTimeUser = 0.0f;
	//}

	//Project *proj = Project::GetSingletonPtr();
	//bool showProjInfo = false;
	//if (proj)
	//{
	//	showProjInfo = proj->IsShowProjectInfo();
	//}

	//mFrameTime += elapsedTime;
	//++mNumFrames;
	//if (mFrameTime > 1.0f)
	//{
	//	mFrameRate = (float)mNumFrames/mFrameTime;
	//	mFrameTime = 0.0f;
	//	mNumFrames = 0;
	//	mUpdateDrawInfo = true;
	//}

	//if (!showProjInfo)
	//{
	//	mUpdateDrawInfo = false;
	//}

	//if (mDBM)
	//	mDBM->Reset();

	//if (mEventWorld)
	//	mEventWorld->Update(elapsedTime);

	//if (mTimerMan)
	//	mTimerMan->Update(mApplicationTime);

	//PX2_RM.Update(mApplicationTime, elapsedTime);
	//PX2_SS.Update(mApplicationTime, elapsedTime);

	//GameManager *gm = GameManager::GetSingletonPtr();
	//if (gm)
	//	gm->Update(mApplicationTime, elapsedTime);

	//if (proj)
	//	proj->Update(mApplicationTime, elapsedTime);

	//UpdateDrawInfo(0, 0);

	//if (showProjInfo)
	//{
	//	if (!mInfoFrame)
	//	{
	//		CreateInfo();
	//	}

	//	mInfoFrame->Update(mApplicationTime, false);
	//}

	//PX2_FM.Update();

	//if (mDBM)
	//	mDBM->Update();

	return true;
}
//----------------------------------------------------------------------------
bool ApplicationBase::IsPause()
{
	return mPauseGame;
}
//----------------------------------------------------------------------------
bool ApplicationBase::OnResume()
{
	mPauseGame = false;
	return true;
}
//----------------------------------------------------------------------------
bool ApplicationBase::OnPause()
{
	mPauseGame = true;
	return true;
}
//----------------------------------------------------------------------------
void ApplicationBase::DoEnter ()
{
}
//----------------------------------------------------------------------------
void ApplicationBase::DoExecute (Event *event)
{
	PX2_UNUSED(event);
}
//----------------------------------------------------------------------------
void ApplicationBase::DoLeave ()
{
}
//----------------------------------------------------------------------------
void ApplicationBase::ResetRenderStates ()
{
	if (mRenderer)
	{
		mRenderer->InitRenderStates();
	}
}
//----------------------------------------------------------------------------
bool ApplicationBase::Ternamate ()
{
	PX2_LOG_INFO("Begin ApplicationBase::Ternamate.");

	OnTernamate();

	//mInfoFrame = 0;
	//mBackPic = 0;
	//mFrameText = 0;
	//mCurTotalMemory = 0;
	//mMaxTotalMemory = 0;
	//mDebugText = 0;

	if (mResMan)
	{
		mResMan->Clear();
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
		mEventWorld->GoOut(this);

		delete0(mEventWorld);
		EventWorld::Set(0);
	}

	if (mTimerMan)
	{
		delete0(mTimerMan);
		TimerManager::Set(0);
	}

	OnTernamateApp();

	PX2_LOG_INFO("End ApplicationBase::Ternamate.");

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
bool ApplicationBase::OnInitlize ()
{
	PX2_LOG_INFO("ApplicationBase::OnInitlize.");

	return true;
}
//----------------------------------------------------------------------------
bool ApplicationBase::OnTernamate ()
{
	PX2_LOG_INFO("ApplicationBase::OnTernamate.");

	return true;
}
//----------------------------------------------------------------------------
void ApplicationBase::OnSize (int width, int height)
{
	//if (!mProject)
	//	return;

	//mWidth = width;
	//mHeight = height;
	//float projWidth = mProject->GetWidth();
	//float projHeight = mProject->GetHeight();

	//Sizef sz((float)mWidth, (float)mHeight);
	//Rectf rect = GameManager::GetSingleton().CalGameViewRect((float)mWidth, (float)mHeight);
	//mRoot->SetSize(sz);
	//mRoot->SetRect(rect);	
	//mInputEventAdapter->SetRect(rect);
	//mInputEventAdapter->GetInputManager()->SetSize(sz);

	//if (mRenderer) mRenderer->ResizeWindow(mWidth, mHeight);

	//OnProjectSize(projWidth, projHeight);
}
//----------------------------------------------------------------------------
void ApplicationBase::WillEnterForeground (bool firsttime)
{
	if (!mIsInBackground)
		return;

	if (mDBM)
		mDBM->Initlize();

	if (firsttime)
	{
		PX2_FM.Initlize();
	}
	else
	{
#ifdef PX2_USE_OPENGLES2
		//Renderer::GetDefaultRenderer()->OnRestoreDevice();
#endif
		PX2_FM.SetNeedUpdate();

		//PX2_SOUNDM.PreLoad();
	}

//	PX2_SS.EnableMusic(mBeforeInBackgroundMusicEnable);
//	PX2_SS.EnableSounds(mBeforeInBackgroundSoundEnable);

	mIsInBackground = false;
}
//----------------------------------------------------------------------------
void ApplicationBase::CreateInfo ()
{
	//mInfoFrame = new0 UIFrame();

	//mBackPic = new0 UIPicBox();
	//mBackPic->SetAlpha(0.7f);
	//mBackPic->SetSize(1024.0f, 85.0f);
	//mBackPic->SetTexture("Data/engine/whiteRect.png");
	//mBackPic->SetAnchorPoint(Float2(0.0f, 0.0f));
	//mBackPic->LocalTransform.SetTranslate(APoint(0.0f, 1.0f, 0.0f));
	//mInfoFrame->AttachChild(mBackPic);

	//mFrameText = new0 UIStaticText();
	//mFrameText->SetFontScale(0.6f);
	//mFrameText->LocalTransform.SetTranslate(APoint(0.0f, 0.0f, 60.0f));
	//mInfoFrame->AttachChild(mFrameText);

	//mCurTotalMemory = new0 UIStaticText();
	//mCurTotalMemory->SetFontScale(0.6f);
	//mCurTotalMemory->LocalTransform.SetTranslate(APoint(0.0f, 0.0f, 40.0f));
	//mInfoFrame->AttachChild(mCurTotalMemory);

	//mMaxTotalMemory = new0 UIStaticText();
	//mMaxTotalMemory->SetFontScale(0.6f);
	//mMaxTotalMemory->LocalTransform.SetTranslate(APoint(0.0f, 0.0f, 20.0f));
	//mInfoFrame->AttachChild(mMaxTotalMemory);

	//mDebugText = new0 UIStaticText();
	//mDebugText->SetFontScale(0.6f);
	//mDebugText->LocalTransform.SetTranslate(APoint(0.0f, 0.0f, 0.0f));
	//mInfoFrame->AttachChild(mDebugText);

	//Float3 texColor = Float3::BLACK;
	//mFrameText->SetColor(texColor);
	//mCurTotalMemory->SetColor(texColor);
	//mMaxTotalMemory->SetColor(texColor);
	//mDebugText->SetColor(texColor);
}
//----------------------------------------------------------------------------
void ApplicationBase::DidEnterBackground ()
{
	if (mIsInBackground)
		return;

	//mInfoFrame = 0;
	//mBackPic = 0;
	//mFrameText = 0;
	//mCurTotalMemory = 0;
	//mMaxTotalMemory = 0;
	//mDebugText = 0;

	//PX2_FM.Terminate();
	//if (mDBM)
	//	mDBM->Terminate();
	//PX2_AM.DeleteAllUsers();
	//PX2_UIM.Clear();
	//PX2_ADM.Clear();
	//PX2_DM.Clear();
	//PX2_RM.Clear();
	//PX2_SS.Clear();
	//PX2_SM.Clear();
	//PX2_TimerM.ClearTimers();

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
bool ApplicationBase::IsIsInBackground () const
{
	return mIsInBackground;
}
//----------------------------------------------------------------------------
void ApplicationBase::OnProjectSize (int width, int height)
{
	//mUIManager->GetDefaultView()->SetSize((float)width, (float)height);
	//APoint curPos = mUIManager->GetDefaultView()->GetCamera()->GetPosition();
	//mUIManager->GetDefaultView()->GetCamera()->SetPosition(APoint((float)width/2.0f, 
	//	curPos.Y(), (float)height/2.0f));
}
//----------------------------------------------------------------------------
int ApplicationBase::Main (int numArguments, char** arguments)
{
	PX2_UNUSED(numArguments);
	PX2_UNUSED(arguments);
	return 1;
}
//----------------------------------------------------------------------------
void ApplicationBase::UpdateDrawInfo (int x, int y)
{
//	if (mInfoFrame)
//	{
//		mInfoFrame->LocalTransform.SetTranslate(APoint((float)x, -100.0f, (float)y));
//	}
//
//	if (mUpdateDrawInfo)
//	{
//		char fpsMsg[256];
//		sprintf(fpsMsg, "FPS: %.1lf", mFrameRate);
//
//		if (mFrameText)
//			mFrameText->SetText(fpsMsg);
//	}
//
//	double toM = 1024.0*1024.0;
//#ifdef PX2_USE_MEMORY
//	double cTB = (double)Memory::GetCurTotalBytes();
//	double mTB = (double)Memory::GetMaxTotalBytes();
//#else
//	double cTB = 0.0;
//	double mTB = 0.0;
//#endif
//	double cTM = cTB/toM;
//	double mTM = mTB/toM;
//
//	if (mUpdateDrawInfo)
//	{
//		char curTotalMemory[256];
//
//		sprintf(curTotalMemory, "CurMemory: %d bytes(%.1lf m).", (int)cTB, (float)cTM);
//
//		if (mCurTotalMemory)
//			mCurTotalMemory->SetText(curTotalMemory);
//	}
//
//	if (mUpdateDrawInfo)
//	{
//		char maxTotalMemory[256];
//		sprintf(maxTotalMemory, "MaxMemory: %d bytes(%.1lf m)", (int)mTB, (float)mTM);
//
//		if (mMaxTotalMemory)
//			mMaxTotalMemory->SetText(maxTotalMemory);
//	}
//
//	if (mUpdateDrawInfo)
//	{
//		Renderer *renderer = Renderer::GetDefaultRenderer();
//		char debugText[256];
//		sprintf(debugText, 
//			"nVF:%d nVB:%d nIB:%d nT2D:%d nVS:%d nPS:%d nMP:%d nGVS:%d nGPS:%d nGMP:%d nDwPe:%d nStp:%d nDet:%d",
//			renderer->GetNumPdrVertexFormat(),
//			renderer->GetNumPdrVertexBuffer(), 
//			renderer->GetNumPdrIndexBuffer(),
//			renderer->GetNumPdrTexture2D(),
//			renderer->GetNumPdrVertexShader(),
//			renderer->GetNumPdrPixelShader(),
//			renderer->GetNumPdrMaterialPass(),
//			renderer->GetNumGPUVertexShader(),
//			renderer->GetNumGPUPixelShader(),
//			renderer->GetNumGPUMaterialPass(),
//			renderer->GetNumDrawPrimitivePerFrame(),
//			PX2_DM.GetNumStopingObjs(),
//			PX2_DM.GetNumDeletingObjs());
//
//		if (mDebugText)
//			mDebugText->SetText(debugText);
//	}
//
	mUpdateDrawInfo = false;
}
//----------------------------------------------------------------------------
void ApplicationBase::DrawInfo (Camera *cam)
{
	//mInfoCuller.SetCamera(cam);
	//mInfoCuller.ComputeVisibleSet(mInfoFrame);

	//mRenderer->Draw(mInfoCuller.GetVisibleSet());
}
//----------------------------------------------------------------------------
