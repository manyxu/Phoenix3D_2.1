// PX2TimerManager.hpp

#ifndef PX2TIMERMANAGER_HPP
#define PX2TIMERMANAGER_HPP

#include "PX2Singleton_NeedNew.hpp"
#include "PX2Timer.hpp"
#include "PX2Time.hpp"

namespace PX2
{

	class PX2_CORE_ITEM TimerManager : public Singleton<TimerManager>
	{
	public:
		TimerManager ();
		virtual ~TimerManager ();

		static int GetNextID ();

		// 增加定时器
		// 如果interval为0则为一次性定时器，在delaySeconds后触发
		template <typename TIMER>
		void AddTimer (int timerID, double interval, double delaySeconds=0, 
			void *act=0, void *userData=0)
		{
			TIMER *timer = new0 TIMER;
			timer->mTimerID = timerID;
			timer->mInterval = interval;
			timer->Action = act;
			timer->UserData = userData;
			double startTime = GetTimeInSeconds();
			timer->StartTime = (float)startTime;
			startTime += delaySeconds;
			mMapTimers.insert(std::make_pair(startTime, timer));
		}

		template <typename TIMER>
		int AddTimer (double interval, double delaySeconds=0, void *act=0,
			void *userData=0)
		{
			TIMER *timer = new0 TIMER;
			timer->mTimerID = GetNextID();
			timer->mInterval = interval;
			timer->Action = act;
			timer->UserData = userData;
			double startTime = GetTimeInSeconds();
			timer->StartTime = (float)startTime;
			startTime += delaySeconds;
			mMapTimers.insert(std::make_pair(startTime, timer));

			return timer->mTimerID;
		}

		void RemoveTimer (int timerID);

		void ClearTimers ();

		Timer *GetTimer (int id) const;

		void Update (double appTime);

	private:
		std::multimap<double, Timer*> mMapTimers; // MultiMaps允许Key重复的元素

		static int msCurTimerID;
	};

#define PX2_TimerM TimerManager::GetSingleton()

}

#endif