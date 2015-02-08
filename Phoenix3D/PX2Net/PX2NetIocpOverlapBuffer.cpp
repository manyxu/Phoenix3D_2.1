// PX2NetIocpOverlapBuffer.cpp

#include "PX2NetIocpOverlapBuffer.h"
#include "PX2Assert.hpp"
#include "PX2ScopedCS.hpp"
using namespace PX2;

//-----------------------------------------------------------------------------
void OverlapBuffer::Init(int op)
{
	assertion(4096 == (int)sizeof(OverlapBuffer), "");

	mOperation = op;
	mDataPos = 0;
	mDataLength = 0;
}
//-----------------------------------------------------------------------------
void OverlapBuffer::PrepareRecv()
{
	mWSABuf.buf = mBuffer + GetFreePos();
	mWSABuf.len = GetFirstFreeBufLen();
}
//-----------------------------------------------------------------------------
void OverlapBuffer::PrepareSend()
{
	mWSABuf.buf = mBuffer + mDataPos;
	mWSABuf.len = GetFirstDataBufLen();
}
//-----------------------------------------------------------------------------
int OverlapBuffer::GetFreePos()
{
	int pos = mDataPos + mDataLength;

	if (pos >= MAX_OVERLAPBUF_SIZE) 
		pos -= MAX_OVERLAPBUF_SIZE;

	return pos;
}
//-----------------------------------------------------------------------------
int OverlapBuffer::GetFirstFreeBufLen()
{
	int free_pos = GetFreePos();
	int free_len = MAX_OVERLAPBUF_SIZE - mDataLength;

	if (free_pos + free_len > MAX_OVERLAPBUF_SIZE) 
		return MAX_OVERLAPBUF_SIZE - free_pos;
	else 
		return free_len;
}
//-----------------------------------------------------------------------------
int OverlapBuffer::GetFirstDataBufLen()
{
	if (mDataPos + mDataLength > MAX_OVERLAPBUF_SIZE)
		return MAX_OVERLAPBUF_SIZE - mDataPos;
	else
		return mDataLength;
}
//-----------------------------------------------------------------------------
int OverlapBuffer::PushData(const char *psrc, int srclen)
{
	int free_pos = GetFreePos();
	int free_len1 = GetFirstFreeBufLen();
	int free_len2 = MAX_OVERLAPBUF_SIZE - mDataLength - free_len1;

	int len1 = srclen <= free_len1 ? srclen : free_len1;
	memcpy(mBuffer + free_pos, psrc, len1);

	int len2 = 0;
	if (len1 < srclen && free_len2>0)
	{
		len2 = srclen - len1 < free_len2 ? srclen - len1 : free_len2;
		memcpy(mBuffer, psrc + len1, len2);
	}

	mDataLength += len1 + len2;

	return len1 + len2;
}
//-----------------------------------------------------------------------------
void OverlapBuffer::PopData(char *pdest, int len)
{
	assertion(len <= mDataLength, "");

	int datalen1 = GetFirstDataBufLen();

	int len1 = len <= datalen1 ? len : datalen1;
	memcpy(pdest, mBuffer + mDataPos, len1);

	if (len1 < len)
	{
		memcpy(pdest + len1, mBuffer, len - len1);
	}

	mDataPos += len;

	if (mDataPos >= MAX_OVERLAPBUF_SIZE) 
		mDataPos -= MAX_OVERLAPBUF_SIZE;

	mDataLength -= len;
}
//-----------------------------------------------------------------------------
unsigned short OverlapBuffer::PopUShort()
{
	unsigned short v;
	PopData((char *)&v, 2);
	return v;
}
//-----------------------------------------------------------------------------
unsigned int OverlapBuffer::PopUInt()
{
	unsigned int v;
	PopData((char *)&v, 4);
	return v;
}
//-----------------------------------------------------------------------------
void OverlapBuffer::DataAppended(int len)
{
	mDataLength += len;
	assert(mDataLength <= MAX_OVERLAPBUF_SIZE);
}
//-----------------------------------------------------------------------------
OverlapBufferMgr::OverlapBufferMgr(int max_olbuf) :
mMaxBuffers(max_olbuf)
{
	mAllBuffers = new OverlapBuffer[max_olbuf];

	mFreeBuffers.reserve(max_olbuf);
	for (int i = 0; i < max_olbuf; i++)
	{
		mFreeBuffers.push_back(mAllBuffers + i);
	}
}
//-----------------------------------------------------------------------------
OverlapBufferMgr::~OverlapBufferMgr()
{
	delete[] mAllBuffers;
}
//-----------------------------------------------------------------------------
OverlapBuffer *OverlapBufferMgr::AllocBuffer(int op)
{
	ScopedCS cs(&mMutex);

	size_t i = mFreeBuffers.size();
	if (i == 0)
	{
		return 0;
	}
	else
	{
		OverlapBuffer *pbuf = mFreeBuffers[i - 1];
		pbuf->Init(op);
		mFreeBuffers.pop_back();

		return pbuf;
	}
}
//-----------------------------------------------------------------------------
void OverlapBufferMgr::FreeBuffer(OverlapBuffer *p)
{
	ScopedCS cs(&mMutex);

	mFreeBuffers.push_back(p);
}
//-----------------------------------------------------------------------------
int OverlapBufferMgr::GetUsedBuffers()
{
	ScopedCS cs(&mMutex);

	return mMaxBuffers - int(mFreeBuffers.size());
}
//-----------------------------------------------------------------------------