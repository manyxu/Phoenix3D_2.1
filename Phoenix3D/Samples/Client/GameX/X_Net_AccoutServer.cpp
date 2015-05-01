// X_Net_AccoutServer.cpp

#include "X_Net.hpp"
#include "X_Man.hpp"
#include "X_Event.hpp"
#include "X_Define.hpp"
#include "PX2PlatformSDK.hpp"
#include "PX2AccoutManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void X_Net::ConnectToAccountServer()
{
	std::string accoutServer = "server_account";
	const ServerInfo *aInfo = PX2_AM.GetServerInfoByType(accoutServer);
	if (aInfo)
	{
		//mAccountConnect->Connect(aInfo->Address);

		//CAServerListC msg;
		//msg.set_version(0); // 需要缓存serverlist和版本号， 在此传入缓存的版本号

		//int serverGroup = 2; // 内网是2
		////if (std::string("91") == ServerPlatform::GetSingleton().GetThirdPlatform())
		////{
		////	if (PX2_RM.GetDataUpdateServerType().empty()) // 如果是平台版本且不是测试版本，是3
		////		serverGroup = 3;
		////}
		//msg.set_svgroup(serverGroup);
		//mAccountConnect->SendMsgToServer(CA_SERVER_LIST, msg);
	}
}
//----------------------------------------------------------------------------
bool X_Net::IsConnected_AccountServer() const
{
	return mIsAccountServerConnected;
}
//----------------------------------------------------------------------------
void X_Net::SendGetGameServerList()
{
}
//----------------------------------------------------------------------------
void X_Net::OnGameServerList()
{
	PX2_LOG_USER("Geted server list");

	mServerListVersion = 0;
	PX2_LOG_USER("GameServerList version:%d", mServerListVersion);

	int gameServerListSize = mGameServerList.size();
	PX2_LOG_USER("GameServerList size:%d", gameServerListSize);
}
//----------------------------------------------------------------------------
void X_Net::SendNewAccount()
{
}
//----------------------------------------------------------------------------
void X_Net::SendRegistMD5(const std::string &userName, const std::string &md5password)
{
}
//----------------------------------------------------------------------------
void X_Net::SendLoginMD5(int uin, const std::string &userName, const std::string &md5password)
{
}
//----------------------------------------------------------------------------
void X_Net::SendLoginTP(int apiID, const std::string &uinstr, const std::string &sessionID, int accountType)
{
}
//----------------------------------------------------------------------------