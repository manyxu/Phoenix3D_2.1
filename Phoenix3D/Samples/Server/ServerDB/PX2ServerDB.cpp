// PX2ServerDB.cpp

#include "PX2ServerDB.hpp"
#include "PX2Log.hpp"
#include "PX2DBObject.hpp"
#include "db.pb.h"
using namespace PX2Server;
using namespace PX2;
using namespace db_proto;

//----------------------------------------------------------------------------
ServerDB::ServerDB(Server::ServerType serverType, int port,
	int numMaxConnects, int numMaxMsgHandlers) :
	Server(serverType, port, numMaxConnects, numMaxMsgHandlers)
{
	RegisterHandler(AD_REG_ACCOUNT, (Server::MsgHandleFunc)&ServerDB::OnRegAccount);
	RegisterHandler(AD_AUTH_ACCOUNT, (Server::MsgHandleFunc)&ServerDB::OnAuthAccount);
}
//----------------------------------------------------------------------------
ServerDB::~ServerDB()
{
}
//----------------------------------------------------------------------------
int ServerDB::OnConnect(unsigned int clientid)
{
	PX2_UNUSED(clientid);

	return 0;
}
//----------------------------------------------------------------------------
int ServerDB::OnDisconnect(unsigned int clientid)
{
	PX2_UNUSED(clientid);

	return 0;
}
//----------------------------------------------------------------------------
int ServerDB::OnRegAccount(unsigned int clientid, const void *pbuffer, int buflen)
{
	ADRegAccountC msg;
	if (!msg.ParseFromArray(pbuffer, buflen))
	{
		PX2_LOG_ERROR("abc");
		return -4;
	}

	const std::string &userName = msg.username();
	const std::string &password = msg.password_md5();
	int clid = msg.clientid();

	OnCreateAccout(userName, password);

	return 0;
}
//----------------------------------------------------------------------------
int ServerDB::OnAuthAccount(unsigned int clientid, const void *pbuffer, int buflen)
{
	return 0;
}
//----------------------------------------------------------------------------
bool ServerDB::OnCreateAccout(const std::string &useName, const std::string &password_md5)
{
	sprintf(mSQLBuf, "call sp_Create_Account_001(%s, '%s', '%s')", "NULL", useName.c_str(), password_md5.c_str());

	DBObject *dbObj = DBPool::GetSingleton().GetDBRandom();

	if (!dbObj->Execute(mSQLBuf))
	{
		PX2_LOG_ERROR("%s error.", mSQLBuf);
		return false;
	}

	int result = 0;
	if (dbObj->Fetch())
	{
		*dbObj >> result;
	}
	dbObj->EndFetch();

	return 0;
}
//----------------------------------------------------------------------------