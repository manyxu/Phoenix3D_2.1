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
#include "account.pb.h"
using namespace PX2Server;
using namespace PX2;

//----------------------------------------------------------------------------
ServerLoopAccount::ServerLoopAccount() :
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

	int numCpus = System::GetNumCPUs();
	PX2_LOG_INFO("Num CPU = %d", numCpus);

	mAuthManager = new0 AuthManager(10000);

	if (!StartDBConnections(1))
	{
		PX2_LOG_ERROR("failed to start db connects");
		return 2;
	}
	PX2_LOG_INFO("db connections succeeded");

	mServerAccount = new0 ServerAccount(Server::ST_IOCP, 20055, 20000, account_proto::MsgType_ARRAYSIZE);
	if (!mServerAccount->Start())
	{
		return 3;
	}

	return true;
}
//----------------------------------------------------------------------------
bool ServerLoopAccount::Ternamate()
{
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