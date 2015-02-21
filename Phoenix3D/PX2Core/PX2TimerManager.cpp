// PX2TimerManager.cpp

#include "PX2TimerManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
int TimerManager::msCurTimerID = 1;
//----------------------------------------------------------------------------
TimerManager::TimerManager ()
{
}
//----------------------------------------------------------------------------
TimerManager::~TimerManager ()
{
	std::multimap<double, Timer*>::iterator it = mMapTimers.begin();
	for (; it!=mMapTimers.end(); ++it)
	{
		delete0(it->second);
	}

	mMapTimers.clear();
}
//----------------------------------------------------------------------------
int TimerManager::GetNextID ()
{
	return msCurTimerID++;
}
//----------------------------------------------------------------------------
void TimerManager::RemoveTimer (int timerID)
{
	std::multimap<double, Timer*>::iterator it = mMapTimers.begin();
	for (; it!=mMapTimers.end(); it++)
	{
		if (timerID == (it->second)->mTimerID)
		{
			delete0(it->second);
			mMapTimers.erase(it);
			return;
		}
	}
}
//----------------------------------------------------------------------------
void TimerManager::ClearTimers ()
{
	std::multimap<double, Timer*>::iterator it = mMapTimers.begin();
	for (; it!=mMapTimers.end(); it++)
	{
		delete0(it->second);
	}

	mMapTimers.clear();
}
//----------------------------------------------------------------------------
Timer *TimerManager::GetTimer (int id) const
{
	std::multimap<double, Timer*>::const_iterator it = mMapTimers.begin();
	for (; it!=mMapTimers.end(); it++)
	{
		if (id == it->second->mTimerID)
			return it->second;
	}

	return 0;
}
//----------------------------------------------------------------------------
struct TimerManTmpStruct
{
	Timer *TheTimer;
	double StartTime;
};
void TimerManager::Update  (double appTime)
{
	std::vector<TimerManTmpStruct> vecs;

	std::multimap<double, Timer*>::iterator it = mMapTimers.begin();
	for (; it!=mMapTimers.end();)
	{
		double startTime = it->first;
		Timer *timer = it->second;

		if (appTime < startTime)
		{
			break;
		}
		else if (0.0 != timer->mInterval) // 非一次性定时器
		{
			double newStartTime = timer->mInterval + appTime;
			mMapTimers.erase(it++);

			if (timer->OnTimer(appTime))
			{
				TimerManTmpStruct tmp;
				tmp.TheTimer = timer;
				tmp.StartTime = newStartTime;
				vecs.push_back(tmp);
			}
			else
			{
				delete0(timer);
			}
		}
		else
		{
			timer->OnTimer(appTime);
			delete0(timer);
			mMapTimers.erase(it++);
		}
	}

	for (size_t i=0; i<vecs.size(); ++i)
	{
		mMapTimers.insert(std::make_pair(vecs[i].StartTime, vecs[i].TheTimer));
	}
}
//----------------------------------------------------------------------------