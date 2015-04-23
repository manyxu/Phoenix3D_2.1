// PX2ClientConnect.cpp

#include "PX2Test_ClientConnect.hpp"
#include "PX2NetEventBuffer.hpp"
#include "PX2Test_ClientData.hpp"
#include "account.pb.h"
using namespace PX2;
using namespace account_proto;

//----------------------------------------------------------------------------
TestClientConnector::TestClientConnector() :
ClientConnector(1000)
{
	RegisterHandler(account_proto::CA_REG_ACCOUNT, (ServerMsgHandleFunc)&TestClientConnector::OnRegAccount);
	RegisterHandler(account_proto::CA_AUTH_ACCOUNT, (ServerMsgHandleFunc)&TestClientConnector::OnAuthAccount);
	RegisterHandler(account_proto::CA_NEW_ACCOUNT, (ServerMsgHandleFunc)&TestClientConnector::OnNewAccount);
	RegisterHandler(account_proto::CA_SERVER_LIST, (ServerMsgHandleFunc)&TestClientConnector::OnServerList);
}
//----------------------------------------------------------------------------
TestClientConnector::~TestClientConnector()
{
}
//----------------------------------------------------------------------------
int TestClientConnector::OnRegAccount(const void *pbuffer, int buflen)
{
	account_proto::CARegAccountS msg;
	if (!msg.ParseFromArray(pbuffer, buflen))
	{
		return -1;
	}
	if (msg.result() == 0)
	{
		printf("reg account succeed: uin=%d\n", msg.uin());
	}
	else
	{
		printf("reg account failed: result=%d\n", msg.result());
	}

	return 0;
}
//----------------------------------------------------------------------------
int TestClientConnector::OnAuthAccount(const void *pbuffer, int buflen)
{
	account_proto::CAAuthAccountS msg;
	if (!msg.ParseFromArray(pbuffer, buflen))
	{
		return -1;
	}
	if (msg.result() == 0)
	{
		gClientData.UIN = msg.uin();
		gClientData.SessionID = msg.sid();

		printf("auth account succeed: uin=%d, sid=%s\n", msg.uin(), msg.sid().c_str());
	}
	else
	{
		printf("auth account failed: %d\n", msg.result());
	}

	return 0;
}
//----------------------------------------------------------------------------
int TestClientConnector::OnNewAccount(const void *pbuffer, int buflen)
{
	account_proto::CANewAccountS msg;
	if (!msg.ParseFromArray(pbuffer, buflen))
	{
		return -1;
	}
	if (msg.result() == 0)
	{
		printf("newaccount succeed: uin=%d, passwd=%s\n", msg.uin(), msg.passwd_md5().c_str());
		gClientData.UIN = msg.uin();
		gClientData.Passwd_md5 = msg.passwd_md5();
	}
	else
	{
		printf("newaccount failed: result=%d\n", msg.result());
	}

	return 0;
}
//----------------------------------------------------------------------------
int TestClientConnector::OnServerList(const void *pbuffer, int buflen)
{
	account_proto::CAServerListS msg;
	if (!msg.ParseFromArray(pbuffer, buflen))
	{
		return -1;
	}

	printf("OnServerList, version=%d\n", msg.version());

	for (int i = 0; i < msg.desc_array().size(); i++)
	{
		const account_proto::CAServerDesc &desc = msg.desc_array(i);
		printf("serverid=%d, status=%d, name=%s, addr=%s, port=%d\n",
			desc.id(), desc.status(), desc.name().c_str(), 
			desc.addr().c_str(), desc.port());
	}

	return 0;
}
//----------------------------------------------------------------------------