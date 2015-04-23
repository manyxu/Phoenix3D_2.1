// PX2ServerLoopDB.cpp

#include "PX2ServerLoopDB.hpp"
#include "PX2ServerDB.hpp"
#include "PX2System.hpp"
#include "PX2Log.hpp"
#include "PX2DBObject.hpp"
#include "PX2ServerInfoManager.hpp"
#include "db.pb.h"
using namespace PX2Server;
using namespace PX2;

//----------------------------------------------------------------------------
ServerLoopDB::ServerLoopDB() :
mServerDB(0)
{
}
//----------------------------------------------------------------------------
ServerLoopDB::~ServerLoopDB()
{
}
//----------------------------------------------------------------------------
bool ServerLoopDB::Initlize()
{
	ServerLoop::Initlize();

	PX2_SVRINFOMAN.LoadServerInfo("DataServer/config.xml");
	const ServerInfo *serverInfo = PX2_SVRINFOMAN.GetServerInfoByName("server_db");
	if (!serverInfo) return false;

	int numCpus = System::GetNumCPUs();
	PX2_LOG_INFO("Num CPU = %d", numCpus);

	mServerDB = new0 ServerDB(Server::ST_IOCP, serverInfo->Port, 
		serverInfo->NumMaxConnect, db_proto::MsgType_ARRAYSIZE);
	if (!mServerDB->Start())
	{
		return false;
	}

	const std::vector<int> &threadIDs = mServerDB->GetThreadIDs();

	mDBPool = new0 DBPool();
	if (mDBPool->ConnectAllDB(threadIDs, serverInfo->IP, "phoenix3d", "phoenix3d",
		"phoenix3d", 3306))
	{
		PX2_LOG_INFO("Connect DB success.");
	}
	else
	{
		PX2_LOG_ERROR("Connect DB failed.");
	}

	return true;
}
//----------------------------------------------------------------------------
bool ServerLoopDB::Ternamate()
{
	PX2_SVRINFOMAN.Clear();

	System::SleepSeconds(0.1f);

	delete0(mServerDB);
	delete0(mDBPool);

	ServerLoop::Ternamate();

	return true;
}
//----------------------------------------------------------------------------
void ServerLoopDB::Run()
{
	while (!mIsShutdownServer)
	{
		mServerDB->HandleClientEvents();

		System::SleepSeconds(0.1f);
	}
}
//----------------------------------------------------------------------------