/*
*
* 文件名称	：	PX2EngineLoop.cpp
*
*/

#include "PX2EngineLoop.hpp"
#include "PX2Time.hpp"
#include "PX2LuaManager.hpp"
#include "PX2ToLua.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
EngineLoop::EngineLoop ()
	:
mAppTime(0),
mLastAppTime(0),
mTimerMan(0),
mEventWorld(0),
mInputEventAdapter(0),
mLanguageMan(0),
mRoot(0),
mIMEDisp(0),
mDBM(0),
mResMan(0),
mScriptMan(0),
mFontMan(0),
mUIManager(0),
mSoundSystem(0)
{
}
//----------------------------------------------------------------------------
EngineLoop::~EngineLoop ()
{
}
//----------------------------------------------------------------------------
bool EngineLoop::Initlize ()
{
	time_t ti; time(&ti); srand((unsigned int)ti);

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
	mResMan = new0 ResourceManager(); PX2_LM.Add("Data/engine/engineLanguage.csv");

	mEventWorld = new0 EventWorld();

	mScriptMan = ScriptManager::Create(ScriptManager::ST_LUA);
	LuaManager *luaMan = (LuaManager*)mScriptMan;
	tolua_PX2_open(luaMan->GetLuaState());

	mRoot = new0 GraphicsRoot();
	mRoot->Initlize();

	mInputEventAdapter = new0 InputEventAdapter(); // input manager created in it
	mInputEventAdapter->Convert2Touch(true);

	mFontMan = new0 FontManager();
	PX2_UNUSED(mFontMan);

	mUIManager = new0 UIManager();
	mEventWorld->ComeIn(mUIManager);
	mInputEventAdapter->GetInputEventListener()->AddHandler(mUIManager->GetDefaultView());

	SoundSystemInitInfo info;
	info.MaxChannels = 24;
	info.DopplerScale = 1.0f;
	info.DistanceFactor = 100.0f;
	info.RolloffScale = 1.2f;
#if defined(_WIN32) || defined(WIN32)
	mSoundSystem = SoundSystem::Create(SoundSystem::ST_FMOD, info);
#elif defined (__ANDROID__) || defined(__MARMALADE__)
	mSoundSystem = SoundSystem::Create(SoundSystem::ST_ANDROID, info);
#endif

	return true;
}
//----------------------------------------------------------------------------
bool EngineLoop::Ternamate ()
{
	if (mResMan)
	{
		mResMan->Clear();
	}

	if (mSoundSystem)
	{
		delete0(mSoundSystem);
		SoundSystem::Set(0);
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

	if (mInputEventAdapter)
	{
		mInputEventAdapter->Ternamate();
		delete0(mInputEventAdapter);
		InputEventAdapter::Set(0);
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
void EngineLoop::Tick ()
{
	mAppTime = GetTimeInSeconds();
	float elapsedTime = GetElapsedTime();

	mLastAppTime = mAppTime;
}
//----------------------------------------------------------------------------