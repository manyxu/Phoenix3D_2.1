/*
*
* ÎÄ¼þÃû³Æ	£º	PX2NetClientConnect.inl
*
*/

//----------------------------------------------------------------------------
inline StreamSocket &ClientConnector::GetSocket ()
{
	return mSocket;
}
//----------------------------------------------------------------------------
inline int ClientConnector::GetConnectState()
{
	return mConnectState; 
}
//----------------------------------------------------------------------------
inline void ClientConnector::SetConnectState(int state)
{
	mConnectState = state;
	mConnStateTime = 0.0f;
}
//----------------------------------------------------------------------------
template<class T>
int ClientConnector::SendMsgToServer(int msgid, const T &msg)
{
	BufferEvent *pevent = MsgToBufferEvent(msgid, msg, mSendQue);
	if (pevent == 0) return -1;
	mSendQue->PostBufferEvent(pevent);

	return 0;
}
//----------------------------------------------------------------------------
template<class T>
BufferEvent *ClientConnector::CreateSendEvent(int msgid, const T &msg)
{
	return MsgToBufferEvent(msgid, msg, mSendQue);
}
//----------------------------------------------------------------------------