/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Semaphore.cpp
*
*/

#include "PX2Semaphore.hpp"
#include "PX2Assert.hpp"
using namespace PX2;

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
//----------------------------------------------------------------------------
Semaphore::Semaphore (int n)
	:
mInitNum(n),
mMax(n)
{
	assertion(n>0, "n>0.\n");

	mHandle = CreateSemaphoreW(NULL, mInitNum, mMax, NULL);
	assertion(0!=mHandle, "mHandle should create failed.\n");
}
//----------------------------------------------------------------------------
Semaphore::Semaphore (int n, int max)
	:
mInitNum(n),
mMax(max),
mHandle(0)
{
	assertion(n>=0 && max>0 && n<=max, "n>0 && max>0 && n<=max.\n");

	mHandle = CreateSemaphoreW(NULL, mInitNum, mMax, NULL);
	assertion(0!=mHandle, "mHandle should create failed.\n");
}
//----------------------------------------------------------------------------
Semaphore::~Semaphore ()
{
	CloseHandle(mHandle);
}
//----------------------------------------------------------------------------
void Semaphore::Set()
{
	if (!ReleaseSemaphore(mHandle, 1, NULL))
	{
		assertion(false, "wait for semaphore failed");
	}
}
//----------------------------------------------------------------------------
void Semaphore::Wait()
{
	switch (WaitForSingleObject(mHandle, INFINITE))
	{
	case WAIT_OBJECT_0:
		return;
	default:
		assertion(false, "wait for semaphore failed");
		break;
	}
}
//----------------------------------------------------------------------------
bool Semaphore::Wait(long milliseconds)
{
	switch (WaitForSingleObject(mHandle, milliseconds + 1))
	{
	case WAIT_TIMEOUT:
		return false;
	case WAIT_OBJECT_0:
		return true;
	default:
		assertion(false, "wait for semaphore failed");
		break;
	}

	return false;
}
//----------------------------------------------------------------------------
#elif defined(__LINUX__) || defined(__APPLE__) || defined(__ANDROID__)

#ifdef __APPLE__
#include <sys/time.h>
#else
#include <sys/timeb.h>
#endif
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

Semaphore::Semaphore (int n)
	:
mInitNum(n),
mMax(n)
{

}
//----------------------------------------------------------------------------
Semaphore::Semaphore (int n, int max)
	:
mInitNum(n),
mMax(max)
{
	assertion(n >= 0 && max > 0 && n <= max, "n >= 0 && max > 0 && n <= max");

	if (pthread_mutex_init(&mMutex, NULL))
		assertion(false, "cannot create semaphore (mutex)");
	if (pthread_cond_init(&mCond, NULL))
		assertion(false, "cannot create semaphore (condition)");
}
//----------------------------------------------------------------------------
Semaphore::~Semaphore ()
{
	pthread_cond_destroy(&mCond);
	pthread_mutex_destroy(&mMutex);
}
//----------------------------------------------------------------------------
void Semaphore::Set()
{
	if (pthread_mutex_lock(&mMutex))	
		assertion(false, "cannot signal semaphore (lock)");
	if (mInitNum < mMax)
	{
		++mInitNum;
	}
	else
	{
		pthread_mutex_unlock(&mMutex);
		assertion(false, "cannot signal semaphore: count would exceed maximum");
	}	
	if (pthread_cond_signal(&mCond))
	{
		pthread_mutex_unlock(&mMutex);
		assertion(false, "cannot signal semaphore");
	}
	pthread_mutex_unlock(&mMutex);
}
//----------------------------------------------------------------------------
void Semaphore::Wait()
{
	if (pthread_mutex_lock(&mMutex))
		assertion(false, "wait for semaphore failed (lock)"); 
	while (mInitNum < 1) 
	{
		if (pthread_cond_wait(&mCond, &mMutex))
		{
			pthread_mutex_unlock(&mMutex);
			assertion(false, "wait for semaphore failed");
		}
	}
	--mInitNum;
	pthread_mutex_unlock(&mMutex);
}
//----------------------------------------------------------------------------
bool Semaphore::Wait(long milliseconds)
{
	int rc = 0;
	struct timespec abstime;

#if defined(__VMS)
	struct timespec delta;
	delta.tv_sec  = milliseconds / 1000;
	delta.tv_nsec = (milliseconds % 1000)*1000000;
	pthread_get_expiration_np(&delta, &abstime);
#elif defined(POCO_VXWORKS)
	clock_gettime(CLOCK_REALTIME, &abstime);
	abstime.tv_sec  += milliseconds / 1000;
	abstime.tv_nsec += (milliseconds % 1000)*1000000;
	if (abstime.tv_nsec >= 1000000000)
	{
		abstime.tv_nsec -= 1000000000;
		abstime.tv_sec++;
	}
#else
	struct timeval tv;
	gettimeofday(&tv, NULL);
	abstime.tv_sec  = tv.tv_sec + milliseconds / 1000;
	abstime.tv_nsec = tv.tv_usec*1000 + (milliseconds % 1000)*1000000;
	if (abstime.tv_nsec >= 1000000000)
	{
		abstime.tv_nsec -= 1000000000;
		abstime.tv_sec++;
	}
#endif

	if (pthread_mutex_lock(&mMutex) != 0)
		assertion(false, "wait for semaphore failed (lock)"); 
	while (mInitNum < 1) 
	{
		if ((rc = pthread_cond_timedwait(&mCond, &mMutex, &abstime)))
		{
			if (rc == ETIMEDOUT)
				break;
			pthread_mutex_unlock(&mMutex);
			assertion(false, "cannot wait for semaphore");
		}
	}
	if (rc == 0) --mInitNum;
	pthread_mutex_unlock(&mMutex);
	return rc == 0;
}
#endif
//----------------------------------------------------------------------------