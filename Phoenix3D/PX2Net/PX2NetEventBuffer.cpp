/*
*
* 文件名称	：	PX2EventBuffer.cpp
*
*/

#include "PX2NetEventBuffer.hpp"
#include "PX2Log.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void BufferEvent::PushData(const char *pdata, int datalen)
{
	if(mDataLength+datalen > m_BufferSize)
	{
		PX2_LOG_ERROR(
		"PushData get wrong params, datalen=%d, mDataLength=%d, m_BufferSize=%d",
			datalen, mDataLength, m_BufferSize);
		return;
	}

	memcpy(mBuffer+mDataLength, pdata, datalen);
	mDataLength += datalen;
}
//----------------------------------------------------------------------------
char *BufferEvent::PrepareDataSpace(int datalen)
{
	if(mDataLength+datalen > m_BufferSize)
	{
		PX2_LOG_ERROR(
		"PrepareDataSpace get wrong params, datalen=%d, mDataLength=%d, m_BufferSize=%d", 
			datalen, mDataLength, m_BufferSize);
		return 0;
	}

	char *pret = mBuffer + mDataLength;
	mDataLength += datalen;

	return pret;
}
//----------------------------------------------------------------------------
BufferEventPool::BufferEventPool(int bufsize, int num_reserve, int max_event) 
	: 
m_BufferSize(bufsize),
m_NumEventMalloc(0), 
m_MaxEventMalloc(max_event)
{
	for(int i=0; i<num_reserve; i++)
	{
		BufferEvent *pevent =
			(BufferEvent *)malloc(m_BufferSize+BufferEvent::HEAD_SIZE);
		pevent->Init(m_BufferSize);
		m_Pool.push_back(pevent);

		m_NumEventMalloc++;
	}
}
//----------------------------------------------------------------------------
BufferEventPool::~BufferEventPool()
{
	for(size_t i=0; i<m_Pool.size(); i++)
	{
		free(m_Pool[i]);
	}
}
//----------------------------------------------------------------------------
BufferEvent *BufferEventPool::AllocBufferEvent()
{
	if(m_Pool.empty())
	{
		if(m_NumEventMalloc >= m_MaxEventMalloc) return 0;

		int buflen = m_BufferSize+BufferEvent::HEAD_SIZE;
		BufferEvent *pevent = (BufferEvent *)malloc(buflen);
		if(pevent == 0) return 0;

		pevent->Init(m_BufferSize);
		m_NumEventMalloc++;
		return pevent;
	}
	else
	{
		BufferEvent *pevent = m_Pool.back();
		pevent->Reset();
		m_Pool.pop_back();
		return pevent;
	}
}
//----------------------------------------------------------------------------
void BufferEventPool::FreeBufferEvent(BufferEvent *pevent)
{
	if(pevent->m_BufferSize != m_BufferSize)
	{
		PX2_LOG_ERROR("wrong bufferevent, input_size=%d, size=%d", 
			pevent->m_BufferSize, m_BufferSize);
		return;
	}
	m_Pool.push_back(pevent);
}
//----------------------------------------------------------------------------
inline bool IsPowerOfTwo( int n )
{
	return (((n & (n-1)) == 0) && (n != 0));
}
//----------------------------------------------------------------------------
inline int PrevIntLog2( unsigned x )
{
	float fx;
	unsigned int rx;

	if( x<=1 ) return x - 1;

	fx = (float)(int)(x);
	rx = *(unsigned int*)(&fx);

	return (rx >> 23) - 127;
}
//----------------------------------------------------------------------------
inline int NextIntLog2( unsigned x )
{
	float fx;
	unsigned int rx;

	if (x <= 1) return x - 1;

	fx = (float)(int)(x - 1);
	rx = *(unsigned int*)(&fx);

	return (rx >> 23) - 126;
}
//----------------------------------------------------------------------------
BufferEventQueue::BufferEventQueue(int minbufsize, int maxbufsize, 
	int *max_events)
	: 
m_nAllocEvent(0)
{
	if(!IsPowerOfTwo(minbufsize) || !IsPowerOfTwo(maxbufsize))
	{
		PX2_LOG_ERROR("wrong minbufsize=%d, maxbufsize=%d", minbufsize,
			maxbufsize);
	}

	m_MinBufSizeIndex = PrevIntLog2(minbufsize);
	m_MaxBufSizeIndex = PrevIntLog2(maxbufsize);

	int nreserve = 0;
	int npool = m_MaxBufSizeIndex-m_MinBufSizeIndex+1;
	m_Pools.resize(npool);
	for(int i=0; i<npool; i++)
	{
		int bufsize = 1<<(i+m_MinBufSizeIndex);

		m_Pools[i] = new BufferEventPool(bufsize, nreserve, max_events[i]);
	}
}
//----------------------------------------------------------------------------
BufferEventQueue::~BufferEventQueue()
{
	size_t i;
	for(i=0; i<m_Pools.size(); i++)
	{
		delete m_Pools[i];
	}
}
//----------------------------------------------------------------------------
BufferEvent *BufferEventQueue::AllocBufferEvent(int nbytes)
{
	ScopedCS lock(&m_PoolMutex);

	int index = NextIntLog2(nbytes);
	if(index > m_MaxBufSizeIndex)
	{
		PX2_LOG_ERROR("alloc too large buffer");
		return 0;
	}

	if(index < m_MinBufSizeIndex) index = m_MinBufSizeIndex;
	BufferEvent *pevent = m_Pools[index-m_MinBufSizeIndex]->AllocBufferEvent();
	if (pevent != 0)
	{
		m_nAllocEvent++;
	}
	else
	{
		PX2_LOG_ERROR("alloc buffer return 0");
	}

	return pevent;
}
//----------------------------------------------------------------------------
void BufferEventQueue::FreeBufferEvent(BufferEvent *pevent)
{
	ScopedCS lock(&m_PoolMutex);

	if(pevent == 0)
	{
		PX2_LOG_ERROR("freebufferevent 0");
		return;
	}

	int index = NextIntLog2(pevent->m_BufferSize);
	if(index<m_MinBufSizeIndex && index>m_MaxBufSizeIndex)
	{
		PX2_LOG_ERROR(
			"freebufferevent received wrong buffer, buffersize=%d",
			pevent->m_BufferSize);
		return;
	}

	m_nAllocEvent--;
	m_Pools[index-m_MinBufSizeIndex]->FreeBufferEvent(pevent);
}
//----------------------------------------------------------------------------
void BufferEventQueue::InsertEventFront(BufferEvent *pevent)
{
	ScopedCS lock(&m_QueMutex);

	if(!m_EventQue.empty() && pevent->GetMessageID()==m_EventQue.front()->GetMessageID()) //多次插入reconnect消息导致问题
	{
		return;
	}

	m_EventQue.push_front(pevent);
}
//----------------------------------------------------------------------------
void BufferEventQueue::PostBufferEvent(BufferEvent *pevent)
{
	ScopedCS lock(&m_QueMutex);

	m_EventQue.push_back(pevent);
}
//----------------------------------------------------------------------------
BufferEvent *BufferEventQueue::PopBufferEvent()
{
	ScopedCS lock(&m_QueMutex);

	if(m_EventQue.empty())
	{
		return 0;
	}
	else
	{
		BufferEvent *pevent = m_EventQue.front();
		m_EventQue.pop_front();
		return pevent;
	}
}
//----------------------------------------------------------------------------
bool BufferEventQueue::PostConnectEvent(unsigned int clientid)
{
	BufferEvent *pevent = AllocBufferEvent(MSGID_BYTES+1);
	if(pevent == 0) return false;

	pevent->m_ClientID = clientid;
	WriteMessageID(pevent->mBuffer, BufferEvent::MSGID_RESERVED);
	pevent->mBuffer[MSGID_BYTES] = 0;
	pevent->mDataLength = MSGID_BYTES+1;

	PostBufferEvent(pevent);

	return true;
}
//----------------------------------------------------------------------------
bool BufferEventQueue::PostDisconnectEvent(unsigned int clientid)
{
	BufferEvent *pevent = AllocBufferEvent(MSGID_BYTES+1);
	if(pevent == 0) return false;

	pevent->m_ClientID = clientid;
	WriteMessageID(pevent->mBuffer, BufferEvent::MSGID_RESERVED);
	pevent->mBuffer[MSGID_BYTES] = 1;
	pevent->mDataLength = MSGID_BYTES+1;

	PostBufferEvent(pevent);

	return true;
}
//----------------------------------------------------------------------------
int BufferEventQueue::GetNumEventInPool(int *num_per_pool)
{
	ScopedCS lock(&m_PoolMutex);

	int count = 0;
	for(size_t i=0; i<m_Pools.size(); i++)
	{
		num_per_pool[count++] = m_Pools[i]->GetNumEventMalloc();
	}

	return count;
}
//----------------------------------------------------------------------------
int BufferEventQueue::GetEventQueLen()
{
	ScopedCS lock(&m_QueMutex);

	return int(m_EventQue.size());
}
//----------------------------------------------------------------------------