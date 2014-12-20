/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EventBuffer.inl
*
*/

//----------------------------------------------------------------------------
inline void BufferEvent::Init(int bufsize)
{
	m_BufferSize = bufsize;
	m_DataLen = 0;
}
//----------------------------------------------------------------------------
inline void BufferEvent::Reset()
{
	m_DataLen = 0;
}
//----------------------------------------------------------------------------
inline int BufferEvent::GetMessageID()
{
	return *(unsigned char *)m_Buffer;
}
//----------------------------------------------------------------------------