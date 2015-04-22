// PX2ServerDBConnect.hpp

#ifndef PX2SERVERDBCONNECT_HPP
#define PX2SERVERDBCONNECT_HPP

namespace PX2
{

	class BufferEvent;
	class BufferEventQueue;

}

extern bool StartDBConnections(int num_conn);
extern void StopDBConnections();
extern void PostDBQueryEvent(PX2::BufferEvent *pevent);
extern PX2::BufferEvent *PopDBResultEvent();
extern void FreeDBResultEvent(PX2::BufferEvent *pevent);
extern PX2::BufferEventQueue *GetDBQueryEventQue();
extern PX2::BufferEventQueue *GetDBResultEventQue();

#endif