/*
*
* 文件名称	：	PX2EventBuffer.hpp
*
*/

#ifndef PX2NETEVENTBUFFER_HPP
#define PX2NETEVENTBUFFER_HPP

#include "PX2NetPre.hpp"
#include "PX2Mutex.hpp"
#include "PX2ScopedCS.hpp"

namespace PX2
{

	class BufferEvent
	{
	public:
		void Init (int bufsize);
		void Reset ();
		void PushData (const char *pdata, int datalen);
		char *PrepareDataSpace (int datalen);

		int GetMessageID ();

	public:
		enum
		{
			HEAD_SIZE = 16,
			MSGID_RESERVED = 0,
		};

	public:
		unsigned int m_ClientID;
		int m_BufferSize;
		int mDataLength;

		char mBuffer[1];
	};


	class BufferEventPool
	{
	public:
		BufferEventPool(int bufsize, int num_reserve, int max_event);
		~BufferEventPool();

		BufferEvent *AllocBufferEvent();
		void FreeBufferEvent(BufferEvent *pevent);

		int GetBufferSize(){ return m_BufferSize; }
		int GetNumEventMalloc(){ return m_NumEventMalloc; }

	private:
		int m_BufferSize;
		int m_NumEventMalloc;
		int m_MaxEventMalloc;
		std::vector<BufferEvent *>m_Pool;
	};


	class BufferEventQueue
	{
	public:
		// minbufsize, maxbufsize must be pow of 2
		BufferEventQueue(int minbufsize, int maxbufsize, int *max_events);
		~BufferEventQueue();

		BufferEvent *AllocBufferEvent(int nbytes);
		void FreeBufferEvent(BufferEvent *pevent);

		void InsertEventFront(BufferEvent *pevent);
		void PostBufferEvent(BufferEvent *pevent);
		BufferEvent *PopBufferEvent();

		bool PostConnectEvent(unsigned int clientid);
		bool PostDisconnectEvent(unsigned int clientid);

		int GetNumAllocEvent(){ return m_nAllocEvent; }
		int GetNumEventInPool(int *num_per_pool);
		int GetEventQueLen();

	private:
		std::vector<BufferEventPool *>m_Pools;	
		int m_MinBufSizeIndex;
		int m_MaxBufSizeIndex;

		int m_CurUsedMemory;
		int m_MemoryLimit;
		int m_nAllocEvent;

		std::deque<BufferEvent *>m_EventQue;

		Mutex m_PoolMutex;
		Mutex m_QueMutex;
	};

#define MSGID_BYTES 1   //msgid用多少个字节表示
#define MSGLEN_BYTES 2  //msg的长度用多少字节表示

	inline int ReadMessageID (const void *pbuffer)
	{
		return *(unsigned char *)pbuffer;
	}

	inline void WriteMessageID (void *pbuffer, int msgid)
	{
		*(unsigned char *)pbuffer = (unsigned char)msgid;
	}

	inline int ReadMessageLen (const void *pbuffer)
	{
		const unsigned char *ptmp = (const unsigned char *)pbuffer;
		return ptmp[0] + (ptmp[1]<<8);
	}

	inline void WriteMessageLen (void *pbuffer, int len)
	{
		unsigned char *ptmp = (unsigned char *)pbuffer;
		ptmp[0] = len&0xff;
		ptmp[1] = (len>>8)&0xff;
	}

	template<class T>
	BufferEvent *MsgToBufferEvent (int msgid, T &msg, BufferEventQueue *peventque)
	{
		int nbytes = msg.ByteSize();

		BufferEvent *pevent = peventque->AllocBufferEvent(nbytes + MSGID_BYTES);
		if(pevent == 0) return 0;

		WriteMessageID(pevent->mBuffer, msgid);
		if(!msg.SerializeToArray(pevent->mBuffer+MSGID_BYTES, nbytes))
		{
			peventque->FreeBufferEvent(pevent);
			assert(false);
			return 0;
		}

		pevent->mDataLength = nbytes + MSGID_BYTES;
		return pevent;
	}

	template<class T>
	int MsgToRawBuffer (int msgid, T &msg, char *buffer, int buffersize)
	{
		int nbytes = msg.ByteSize();
		assert(nbytes < buffersize-MSGLEN_BYTES-MSGID_BYTES);

		WriteMessageLen(buffer, nbytes+MSGID_BYTES);
		WriteMessageID(buffer+MSGLEN_BYTES, msgid);

		if(!msg.SerializeToArray(buffer+MSGLEN_BYTES+MSGID_BYTES, nbytes))
		{
			assert(false);
			return -1;
		}

		return nbytes+MSGLEN_BYTES+MSGID_BYTES;
	}

#include "PX2NetEventBuffer.inl"
	
}

#endif