// PX2ServerLoop.cpp

#include "PX2ServerLoop.hpp"
#include "PX2Time.hpp"
#include "PX2LocalDateTime.hpp"
#include "PX2System.hpp"
using namespace PX2Server;
using namespace PX2;

//----------------------------------------------------------------------------
ServerLoop::ServerLoop() :
mIsShutdownServer(false),
mCurDay(-1)
{
}
//----------------------------------------------------------------------------
ServerLoop::~ServerLoop()
{
}
//----------------------------------------------------------------------------
void ServerLoop::Run()
{
	double lastReportTimeTime = GetTimeInSeconds();

	int cursaveday = -1;
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
				// save
			}

		}

		System::SleepSeconds(0.1f);
	}

}
//----------------------------------------------------------------------------