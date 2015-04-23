// PX2ServerLoopSimu.cpp

#include "PX2ServerLoopAccount.hpp"
#include "PX2ServerUserManager.hpp"
#include "PX2Time.hpp"
#include "PX2LocalDateTime.hpp"
#include "PX2System.hpp"
#include "PX2Log.hpp"
#include "PX2StringHelp.hpp"
#include "PX2FString.hpp"
#include "PX2ServerAuth.hpp"
#include "PX2ServerDBConnect.hpp"
#include "PX2ServerAccount.hpp"
#include "PX2NetInitTerm.hpp"
#include "PX2ServerInfoManager.hpp"
#include "account.pb.h"
using namespace PX2Server;
using namespace PX2;

//----------------------------------------------------------------------------
ServerLoopAccount::ServerLoopAccount() :
mDBConnect(0),
mServerAccount(0)
{
}
//----------------------------------------------------------------------------
ServerLoopAccount::~ServerLoopAccount()
{
}
//----------------------------------------------------------------------------
bool ServerLoopAccount::Initlize()
{
	ServerLoop::Initlize();

	PX2_SVRINFOMAN.LoadServerInfo("DataServer/config.xml");

	const ServerInfo *serverInfoDB = PX2_SVRINFOMAN.GetServerInfoByName("server_db");
	if (!serverInfoDB) return false;
	const ServerInfo *serverInfoAC = PX2_SVRINFOMAN.GetServerInfoByName("server_account");
	if (!serverInfoAC) return false;

	mAuthManager = new0 AuthManager(10000);

	mDBConnect = new0 DBConnect();
	if (mDBConnect->ConnectB(serverInfoDB->IP, serverInfoDB->Port) < 0)
	{
		PX2_LOG_ERROR("failed to connect to db server.");

		return false;
	}

	PX2_LOG_INFO("db connections succeeded");

	mServerAccount = new0 ServerAccount(Server::ST_IOCP, serverInfoAC->Port, 20000, account_proto::MsgType_ARRAYSIZE);
	if (!mServerAccount->Start())
	{
		return false;
	}

	return true;
}
//----------------------------------------------------------------------------
bool ServerLoopAccount::Ternamate()
{
	PX2_SVRINFOMAN.Clear();

	System::SleepSeconds(0.1f);

	delete0(mAuthManager);
	delete0(mServerAccount);
	StopDBConnections();

	ServerLoop::Ternamate();

	return true;
}
//----------------------------------------------------------------------------
void ServerLoopAccount::Run()
{
	while (!mIsShutdownServer)
	{
		mServerAccount->HandleClientEvents();
		mServerAccount->HandleDBEvents();

		mAuthManager->Update();

		System::SleepSeconds(0.1f);
	}
}
//----------------------------------------------------------------------------