/*
*
* ÎÄ¼şÃû³Æ	£º	PX2NetClientConnect.inl
*
*/

//----------------------------------------------------------------------------
inline StreamSocket &ClientConnect::GetSocket ()
{
	return mSocket;
}
//----------------------------------------------------------------------------
inline int ClientConnect::GetConnectState()
{
	return mConnectState; 
}
//----------------------------------------------------------------------------
inline void ClientConnect::SetConnectState(int state)
{
	mConnectState = state;
	mConnStateTime = 0.0f;
}
