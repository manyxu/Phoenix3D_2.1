// PX2ServerAccount.cpp

#include "PX2SRV_ServerAccount.hpp"
#include "PX2NetEventBuffer.hpp"
#include "PX2ServerAuth.hpp"
#include "PX2Log.hpp"
#include "PX2SVR_DBConnect.hpp"
#include "account.pb.h"
#include "db.pb.h"
using namespace PX2Server;
using namespace PX2;
using namespace account_proto;
using namespace db_proto;

//----------------------------------------------------------------------------
ServerAccount::ServerAccount(Server::ServerType serverType, int port,
	int numMaxConnects, int numMaxMsgHandlers) :
	Server(serverType, port, numMaxConnects, numMaxMsgHandlers)
{
	RegisterHandler(CA_REG_ACCOUNT, (Server::MsgHandleFunc)&ServerAccount::OnRegAccount);
	RegisterHandler(CA_AUTH_ACCOUNT, (Server::MsgHandleFunc)&ServerAccount::OnAuthAccount);
	RegisterHandler(GA_AUTH_ACCOUNT, (Server::MsgHandleFunc)&ServerAccount::OnGameServerAuthAccount);
}
//----------------------------------------------------------------------------
ServerAccount::~ServerAccount()
{
}
//----------------------------------------------------------------------------
template<class T>
int ServerAccount::SendMsgToDB(int msgid, T &msg)
{
	DBConnect::GetSingleton().SendMsgToServer(msgid, msg);
	
	return 0;
}
//----------------------------------------------------------------------------
int ServerAccount::OnConnect(unsigned int clientid)
{
	PX2_UNUSED(clientid);

	return 0;
}
//----------------------------------------------------------------------------
int ServerAccount::OnDisconnect(unsigned int clientid)
{
	PX2_UNUSED(clientid);

	return 0;
}
//----------------------------------------------------------------------------
int ServerAccount::OnRegAccount(unsigned int clientid, const void *pbuffer,
	int buflen)
{
	CARegAccountC msg;
	if (!msg.ParseFromArray(pbuffer, buflen))
	{
		PX2_LOG_ERROR("Failed to parse RegAccount, clientid=%u", clientid);
		return -4;
	}

	if (msg.passwd_md5().length() != 16)
	{
		PX2_LOG_ERROR("Failed to parse AuthAccount, passwd_md5_len!=16, clientid=%u", clientid);
		return -6;
	}

#ifdef _DEBUG
	PX2_LOG_INFO("OnRegAccount, clientid=%d, name=%s, pwdmd5_len=%d", clientid, msg.name().c_str(), msg.passwd_md5().size());
#endif

	ADRegAccountC msg2;
	msg2.set_username(msg.name());
	msg2.set_password_md5(msg.passwd_md5());
	msg2.set_clientid(clientid);

	return SendMsgToDB<ADRegAccountC>(AD_REG_ACCOUNT, msg2);

	return 0;
}
//----------------------------------------------------------------------------
int ServerAccount::OnAuthAccount(unsigned int clientid, const void *pbuffer,
	int buflen)
{
	CAAuthAccountC msg;
	if (!msg.ParseFromArray(pbuffer, buflen))
	{
		PX2_LOG_INFO("Failed to parse AuthAccount, clientid=%u", clientid);
		return -4;
	}
	if (msg.passwd_md5().length() != 16)
	{
		PX2_LOG_INFO("Failed to parse AuthAccount, passwd_md5_len!=16, clientid=%u", clientid);
		return -6;
	}

#ifdef _DEBUG
	PX2_LOG_INFO("OnAuthAccount, clientid=%d, name=%s, pwdmd5_len=%d", clientid, msg.name().c_str(), msg.passwd_md5().size());
#endif

	//ADAuthAccountC msg2;
	//msg2.set_name(msg.name());
	//msg2.set_passwd_md5(msg.passwd_md5());
	//msg2.set_clientid(clientid);
	//msg2.set_sessionid(sid);

	//return SendMsgToDB<ADAuthAccountC>(AD_AUTH_ACCOUNT, msg2);

	return 0;
}
//----------------------------------------------------------------------------
int ServerAccount::OnPay(unsigned int clientid, const void *pbuffer, 
	int buflen)
{
	return 0;
}
//----------------------------------------------------------------------------
int ServerAccount::OnGameServerAuthAccount(unsigned int clientid,
	const void *pbuffer, int buflen)
{
	GAAuthAccountC msg;
	if (!msg.ParseFromArray(pbuffer, buflen))
	{
		return -1;
	}

	bool isAuthorized = false;
	unsigned int sid = msg.clientid();

	Auth *auth = AuthManager::GetSingleton().FindAuth(sid);
	if (auth && auth->IsAuthorized)
	{
		if (auth->UIN == msg.uin())
		{
			isAuthorized = true;
		}
	}

	GAAuthAccountS sendmsg;
	sendmsg.set_uin(msg.uin());
	sendmsg.set_clientid(msg.clientid());

	if (isAuthorized)
	{
		sendmsg.set_result(0);
		sendmsg.set_info("login authorized");
	}
	else
	{
		sendmsg.set_result(1);
		sendmsg.set_info("login denied");
	}

	return SendMsgToClient(clientid, GA_AUTH_ACCOUNT, sendmsg);
}
//----------------------------------------------------------------------------