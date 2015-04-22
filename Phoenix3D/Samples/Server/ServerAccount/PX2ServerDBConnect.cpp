// PX2ServerDBConnect.cpp

#include "PX2ServerDBConnect.hpp"
#include "PX2NetEventBuffer.hpp"
#include "PX2Log.hpp"
#include "PX2System.hpp"
#include "PX2Semaphore.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
static BufferEventQueue *s_QueryQue = 0;
static BufferEventQueue *s_ResultQue = 0;
static Semaphore *sSemaphore;
static bool s_bStopDBConn = false;
static int sNumDBConn = 0;
static long volatile s_NumActiveConn = 0;
static long volatile s_MaxUIN = 0;

//----------------------------------------------------------------------------
DWORD WINAPI DBConnThreadProc(LPVOID pparam)
{
	//InterlockedIncrement(&s_NumActiveConn);

	//ResDB *pdb = CreateResDBFromRealDB("db_meta.xml", "127.0.0.1", "accounts", "guest", "123456");
	//if (pdb == NULL)
	//{
	//	InterlockedDecrement(&s_NumActiveConn);
	//	return 1;
	//}

	//ResTable *pconsttb = pdb->GetTable("acc_const_tb");
	//ACC_CONST_TB maxuin;
	//strcpy(maxuin.name, "MAX_UIN");
	//if (pconsttb->FindRecord(&maxuin, 1, &maxuin) == 1)
	//{
	//	s_MaxUIN = maxuin.intvalue;
	//}

	//ResTable *paccounts = pdb->GetTable("account_tb");
	//if (paccounts == NULL)
	//{
	//	InterlockedDecrement(&s_NumActiveConn);
	//	return 2;
	//}
	//ACCOUNT_TB account;

	//for (;;)
	//{
	//	DWORD n = WaitForSingleObject(s_hSemaphore, INFINITE);
	//	if (s_bStopDBConn) break;

	//	BufferEvent *pevent = s_QueryQue->PopBufferEvent();
	//	if (pevent == NULL) continue;

	//	HandleQueryEvent(pevent, pconsttb, maxuin, paccounts, account);

	//	s_QueryQue->FreeBufferEvent(pevent);
	//}

	//delete pdb;
	//InterlockedDecrement(&s_NumActiveConn);
	return 0;
}
//----------------------------------------------------------------------------
bool StartDBConnections(int num_conn)
{
	int max_events[] = {
		4096, 4096, 4096, 4096, 4096, 4096, 4096, 4096, 4096, 
		1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024,
		1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024 };
	s_QueryQue = new0 BufferEventQueue(16, 64 * 1024, max_events);
	s_ResultQue = new0 BufferEventQueue(16, 64 * 1024, max_events);

	s_bStopDBConn = false;
	sNumDBConn = num_conn;
	s_NumActiveConn = 0;

	sSemaphore = new0 Semaphore(0, 99999);

	for (int i = 0; i < num_conn; i++)
	{
		HANDLE h = CreateThread(NULL, 0, DBConnThreadProc, NULL, 0, NULL);
		CloseHandle(h);
	}

	return true;
}
//----------------------------------------------------------------------------
void StopDBConnections()
{
	s_bStopDBConn = true;

	sSemaphore->Set(sNumDBConn);

	while (s_NumActiveConn > 0)
	{
		System::SleepSeconds(0.1f);
	}

	System::SleepSeconds(0.1f);

	delete0(s_QueryQue);
	delete0(s_ResultQue);
}
//----------------------------------------------------------------------------
void PostDBQueryEvent(BufferEvent *pevent)
{
	s_QueryQue->PostBufferEvent(pevent);

	sSemaphore->Set();
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