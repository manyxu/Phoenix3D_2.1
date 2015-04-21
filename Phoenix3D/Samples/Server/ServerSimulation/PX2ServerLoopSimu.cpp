// PX2ServerLoopSimu.cpp

#include "PX2ServerLoopSimu.hpp"
#include "PX2ServerUserManager.hpp"
#include "PX2Time.hpp"
#include "PX2LocalDateTime.hpp"
#include "PX2System.hpp"
#include "PX2Log.hpp"
#include "PX2StringHelp.hpp"
#include "PX2FString.hpp"
using namespace PX2Server;
using namespace PX2;

//----------------------------------------------------------------------------
ServerLoopSimu::ServerLoopSimu()
{
}
//----------------------------------------------------------------------------
ServerLoopSimu::~ServerLoopSimu()
{
}
//----------------------------------------------------------------------------
bool ServerLoopSimu::Initlize()
{
	time_t ti; time(&ti); srand((unsigned int)ti);

#ifdef PX2_USE_MEMORY
	Memory::Initialize();
#endif

	StringHelp::Initlize();
	FString::Initlize();

	Logger *logger = new0 Logger();

#if defined(_WIN32) || defined(WIN32)
	logger->AddFileHandler("log_server.txt", LT_INFO | LT_ERROR | LT_USER);
#endif
	logger->AddOutputWindowHandler(LT_INFO | LT_ERROR | LT_USER);
	logger->AddConsoleHandler(LT_INFO | LT_ERROR | LT_USER);
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

	UserManager userMan(5000);

	return true;
}
//----------------------------------------------------------------------------
bool ServerLoopSimu::Ternamate()
{
	Logger *logger = Logger::GetSingletonPtr();
	if (logger)
	{
		delete0(logger);
		Logger::Set(0);
	}

	FString::Ternimate();

#ifdef PX2_USE_MEMORY
	Memory::Terminate("log_server.txt", false);
#endif

	return true;
}
//----------------------------------------------------------------------------
void ServerLoopSimu::Run()
{
	int curSaveDay = -1;
	double lastReportTimeTime = GetTimeInSeconds();
	while (!mIsShutdownServer)
	{
		double curTime = GetTimeInSeconds();

		if (curTime - lastReportTimeTime > 600.0)
		{
			// 每10分钟向帐号服务器汇报状态

			lastReportTimeTime = curTime;

			// 每天3点保存角色数据

			LocalDateTime time;
			int hour = time.Hour();
			int day = time.Day();
			if (3 == hour && mCurDay != day)
			{

				curSaveDay = day;
			}

		}

		System::SleepSeconds(0.1f);
	}

}
//----------------------------------------------------------------------------