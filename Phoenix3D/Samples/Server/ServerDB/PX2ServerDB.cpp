// PX2ServerDB.cpp

#include "PX2ServerDB.hpp"
#include "PX2Log.hpp"
#include "PX2DataBase.hpp"
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
	DataBase *db = DataBase::GetSingletonPtr();

	DBInsert stmt(db);
	stmt.SetQuery("INSERT INTO `account_tb` (`uin`, `username`, `password`) VALUES ");

	DBQueryStream query;
	query << 10004 << ", " << useName << ", " << password_md5;

	if (!stmt.AddRow(query.str())) return false;

	bool ret = stmt.Execute();
	if (!ret)
	{
		PX2_LOG_ERROR("sql exe error.");
	}

	return ret;
}
//----------------------------------------------------------------------------