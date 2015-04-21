// PX2ServerDBConnect.cpp

#include "PX2ServerDBConnect.hpp"
#include "PX2NetEventBuffer.hpp"
#include "PX2Log.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
static BufferEventQueue *s_QueryQue = 0;
static BufferEventQueue *s_ResultQue = 0;
static HANDLE s_hSemaphore;
static bool s_bStopDBConn;
static int s_NumDBConn;
static long volatile s_NumActiveConn;
static long volatile s_MaxUIN = 0;

//----------------------------------------------------------------------------
bool StartDBConnections(int num_conn)
{
	return true;
}
//----------------------------------------------------------------------------
void StopDBConnections()
{

}
//----------------------------------------------------------------------------
BufferEvent *AllocDBQueryEvent(int nbytes)
{
	return s_QueryQue->AllocBufferEvent(nbytes);
}
//----------------------------------------------------------------------------
void PostDBQueryEvent(BufferEvent *pevent)
{
	s_QueryQue->PostBufferEvent(pevent);

	LONG count;
	if (!ReleaseSemaphore(s_hSemaphore, 1, &count))
	{
		PX2_LOG_ERROR("ReleaseSemaphore error");
	}
}
//----------------------------------------------------------------------------
BufferEvent *PopDBResultEvent()
{
	return s_ResultQue->PopBufferEvent();
}
//----------------------------------------------------------------------------
void FreeDBResultEvent(BufferEvent *pevent)
{
	s_ResultQue->FreeBufferEvent(pevent);
}
//----------------------------------------------------------------------------
BufferEventQueue *GetDBQueryEventQue()
{
	return s_QueryQue;
}
//----------------------------------------------------------------------------
BufferEventQueue *GetDBResultEventQue()
{
	return s_ResultQue;
}
//----------------------------------------------------------------------------