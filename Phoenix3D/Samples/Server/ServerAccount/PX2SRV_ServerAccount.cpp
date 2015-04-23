// PX2ServerAccount.cpp

#include "PX2SRV_ServerAccount.hpp"
#include "PX2ServerDBConnect.hpp"
#include "PX2NetEventBuffer.hpp"
#include "PX2ServerAuth.hpp"
#include "PX2ServerDBConnect.hpp"
#include "PX2Log.hpp"
#include "account.pb.h"
using namespace PX2Server;
using namespace PX2;
using namespace account_proto;

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
void ServerAccount::HandleDBEvents()
{
	//PX2::BufferEvent *pevent;
	//while ((pevent = PopDBResultEvent()) != 0)
	//{
	//	HandleDBEvent(pevent);
	//	FreeDBResultEvent(pevent);
	//}
}
//----------------------------------------------------------------------------
int ServerAccount::HandleDBEvent(BufferEvent *pevent)
{
	int msgid = ReadMessageID(pevent->mBuffer);

	//if (msgid == AD_REG_ACCOUNT)
	//{
	//	ADRegAccountS msg;
	//	msg.ParseFromArray(pevent->m_Buffer + MSGID_BYTES, pevent->m_DataLen - MSGID_BYTES);

	//	PX2_LOG_ERROR("HandleDBEvent AD_REG_ACCOUNT, result=%d, info=%s, uin=%d", msg.result(), msg.info().c_str(), msg.uin());

	//	CARegAccountS msg2;
	//	msg2.set_result(msg.result());
	//	msg2.set_info(msg.info());
	//	msg2.set_uin(msg.uin());

	//	SendMsgToClient<CARegAccountS>(msg.clientid(), CA_REG_ACCOUNT, msg2);
	//}
	//else if (msgid == AD_AUTH_ACCOUNT)
	//{
	//	ADAuthAccountS msg;
	//	msg.ParseFromArray(pevent->m_Buffer + MSGID_BYTES, pevent->m_DataLen - MSGID_BYTES);

	//	PX2_LOG_ERROR("HandleDBEvent AD_AUTH_ACCOUNT, result=%d, info=%s, uin=%d", msg.result(), msg.info().c_str(), msg.uin());

	//	int authresult = msg.result();
	//	AuthSession *psession = AuthSessionMgr::getSingleton().FindSession(msg.sessionid());
	//	if (psession)
	//	{
	//		psession->authorized = (authresult == 0);
	//		psession->uin = msg.uin();
	//	}

	//	CAAuthAccountS msg2;
	//	msg2.set_result(authresult);
	//	msg2.set_info(msg.info());

	//	if (psession && authresult == 0)
	//	{
	//		msg2.set_sessionid(msg.sessionid());
	//		msg2.set_uin(msg.uin());
	//	}
	//	else
	//	{
	//		msg2.set_sessionid(0);
	//		msg2.set_uin(0);
	//	}

	//	SendMsgToClient<CAAuthAccountS>(msg.clientid(), CA_AUTH_ACCOUNT, msg2);
	//}

	return 0;
}
//----------------------------------------------------------------------------
template<class T>
int ServerAccount::SendMsgToDB(int msgid, T &msg)
{
	BufferEvent *pevent = MsgToBufferEvent(GetDBQueryEventQue(), msgid, msg);
	if (0 == pevent) return -1;

	PostDBQueryEvent(pevent);
	
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

	//ADRegAccountC msg2;
	//msg2.set_name(msg.name());
	//msg2.set_passwd_md5(msg.passwd_md5());
	//msg2.set_clientid(clientid);

	//return SendMsgToDB<ADRegAccountC>(AD_REG_ACCOUNT, msg2);

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

	unsigned int sid = AuthManager::GetSingleton().AllocAuth(msg.name().c_str(), msg.cpid(), msg.appid());
	if (sid == 0)
	{
		PX2_LOG_INFO("AllocSession failed, name=%s, clientid=%u", msg.name(), clientid);
		return -5;
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