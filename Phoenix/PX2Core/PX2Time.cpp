/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Time.cpp
*
*/

#include "PX2Time.hpp"

namespace PX2
{

#if defined(_WIN32) || defined(WIN32)
	#include <Windows.h>
	int gettimeofday(struct timeval * val, struct timezone *)
	{
		LARGE_INTEGER liTime, liFreq;
		QueryPerformanceFrequency( &liFreq );
		QueryPerformanceCounter( &liTime );
		val->tv_sec     = (long)( liTime.QuadPart / liFreq.QuadPart );
		val->tv_usec    = (long)( liTime.QuadPart * 1000000.0 / liFreq.QuadPart - val->tv_sec * 1000000.0 );

		return 0;
	}
	void timersub(struct timeval *cur, struct timeval *last, struct timeval *delta)
	{
		delta->tv_sec = cur->tv_sec - last->tv_sec;
		delta->tv_usec = cur->tv_usec - last->tv_usec;
	}
#endif

#ifdef __APPLE__
#include <sys/time.h>
	static timeval gsInitial;
	static bool gsInitializedTime = false;
#elif defined(__MARMALADE__)
#include "s3eTimer.h"
#else
#include <sys/timeb.h>
	static timeval gsInitial;
	static long gsInitialSec = 0;
	static long gsInitialUSec = 0;
	static bool gsInitializedTime = false;
#endif

	//----------------------------------------------------------------------------
	double GetTimeInMicroseconds ()
	{
#if defined(_WIN32) || defined(WIN32) || defined(__ANDROID__) || defined(__APPLE__)
		if (!gsInitializedTime)
		{
			gsInitializedTime = true;
			gettimeofday(&gsInitial, 0);
			return 0.0;
		}

		struct timeval currentTime;
		gettimeofday(&currentTime, 0);

		struct timeval deltaTime;
		timersub(&currentTime, &gsInitial, &deltaTime);

		return double(1000000)*deltaTime.tv_sec + deltaTime.tv_usec;
#elif defined(__MARMALADE__)
		return s3eTimerGetMs()*1000;
//#else
//		struct timeb currentTime;
//
//		if (!gsInitializedTime)
//		{
//			gsInitializedTime = true;
//			ftime(&currentTime);
//			gsInitialSec = (long)currentTime.time;
//			gsInitialUSec = 1000*currentTime.millitm;
//		}
//
//		ftime(&currentTime);
//		long currentSec = (long)currentTime.time;
//		long currentUSec = 1000*currentTime.millitm;
//		long deltaSec = currentSec - gsInitialSec;
//		long deltaUSec = currentUSec - gsInitialUSec;
//		if (deltaUSec < 0)
//		{
//			deltaUSec += 1000000;
//			--deltaSec;
//		}
//
//		return 1000000*deltaSec + deltaUSec;
#endif
	}
	//----------------------------------------------------------------------------
	double GetTimeInSeconds ()
	{
		double microseconds = GetTimeInMicroseconds();
		return 0.000001*microseconds;
	}
	//----------------------------------------------------------------------------
	void ResetTime ()
	{
#ifndef __MARMALADE__
		gsInitializedTime = false;
#endif
	}
	//----------------------------------------------------------------------------

}