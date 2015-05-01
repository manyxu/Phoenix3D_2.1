// X_Net_GameServer.cpp

#include "X_Net.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void X_Net::ConnectToGameServer(int serverid)
{
	size_t index = 0;
	if (serverid > 0)
	{
		for (size_t i = 0; i < mGameServerList.size(); i++)
		{
			if (mGameServerList[i].ID == serverid)
			{
				index = i;
				break;
			}
		}
	}

	if ((int)mGameServerList.size() > 0)
	{
		//mGameConnect->Disconnect();

		std::string toStr = mGameServerList[index].WWWAddr;
		//mGameConnect->Connect(mGameServerList[index].Address);

		mTryToConnectGameServerID = mGameServerList[index].ID;
	}
}
//----------------------------------------------------------------------------
void X_Net::ReConnectGameServer()
{
	//CGReConnectC msg;
	//msg.set_uin(D_MAN.GetLoginedUin());
	//msg.set_sid(D_MAN.GetLoginedSessionID());

	//BufferEvent *pevent = mGameConnect->CreateSendEvent(CG_RE_CONNECT, msg);
	//mGameConnect->Reconnect(pevent);

	//PX2_LOG_USER("ReconnectGameServer");
}
//----------------------------------------------------------------------------
bool X_Net::IsConnected_GameServer() const
{
	return mIsGameServerConnected;
}
//----------------------------------------------------------------------------
int X_Net::GetTryToConnectServerID() const
{
	return mTryToConnectGameServerID;
}
//----------------------------------------------------------------------------
void X_Net::SendGameServerLogin(int uIN, const std::string &sessionID)
{
}
//----------------------------------------------------------------------------
void X_Net::SendNewRole(const std::string &nickName, int headId)
{
}
//----------------------------------------------------------------------------