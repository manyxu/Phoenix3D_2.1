// PX2NetIocpOverlapBuffer.h

#ifndef PX2NETIOCPOVERLAPBUFFER_H
#define PX2NETIOCPOVERLAPBUFFER_H

#include "PX2NetPre.hpp"
#include "PX2Mutex.hpp"

namespace PX2
{

	const int MAX_OVERLAPBUF_SIZE = 4096 - sizeof(OVERLAPPED) - sizeof(WSABUF) - 3 * 4;

	class OverlapBuffer
	{
	public:
		void Init(int op);

		int GetOperation() { return mOperation; }
		void PrepareRecv();
		void PrepareSend();

		int GetFreePos();
		int GetFirstFreeBufLen();
		int GetDataLen(){ return mDataLength; }
		int GetFirstDataBufLen();

		int PushData(const char *psrc, int srclen);
		void PopData(char *pdest, int len);
		unsigned short PopUShort();
		unsigned int PopUInt();

		void DataAppended(int len);

	public:
		OVERLAPPED mSysData;
		WSABUF mWSABuf;
		int mOperation;
		int mDataPos;
		int mDataLength;
		char mBuffer[MAX_OVERLAPBUF_SIZE];
	};

	class OverlapBufferMgr
	{
	public:
		OverlapBufferMgr(int max_olbuf);
		~OverlapBufferMgr();

		OverlapBuffer *AllocBuffer(int op);
		void FreeBuffer(OverlapBuffer *p);

		int GetUsedBuffers();

	private:
		int mMaxBuffers;
		Mutex mMutex;
		OverlapBuffer *mAllBuffers;
		std::vector<OverlapBuffer *> mFreeBuffers;
	};
	
}

#endif