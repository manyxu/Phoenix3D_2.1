// Main.cpp

#include "PX2Net.hpp"
#include "PX2Core.hpp"
#include "PX2Mathematics.hpp"
#include "PX2Test_ClientConnect.hpp"
#include "PX2Test_ClientData.hpp"
#include "PX2ServerInfoManager.hpp"
#include "PX2Crypt.hpp"
#include "account.pb.h"
using namespace PX2;

ClientData gClientData;
static std::vector<std::string> sCmdParams;
static bool sIsHasInput = false;
static bool sIsDoQuit = false;
//----------------------------------------------------------------------------
static int DoConnect(ClientConnector *conn, const char *ip, int port, const char *servername)
{
	if (conn->ConnectNB(ip, (int16_t)port) < 0)
	{
		printf("connect %s failed\n", servername);
		return -1;
	}
	else printf("connect %s begin...\n", servername);

	while (conn->GetConnectState() == CONNSTATE_TRYCONNECT)
	{
		Sleep(20);
		if (conn->Update(0.0f) < 0)
		{
			printf("connect %s failed\n", servername);
			return -1;
		}
	}

	if (conn->GetConnectState() == CONNSTATE_INIT)
	{
		printf("connect %s failed\n", servername);
		return -1;
	}
	else printf("connected\n");

	return 0;
}
//----------------------------------------------------------------------------
static void split(std::string& s, std::string& delim, std::vector< std::string >* ret)
{
	size_t last = 0;
	size_t index = s.find_first_of(delim, last);
	while (index != std::string::npos)
	{
		ret->push_back(s.substr(last, index - last));
		last = index + 1;
		index = s.find_first_of(delim, last);
	}
	if (index - last > 0)
	{
		ret->push_back(s.substr(last, index - last));
	}
}
//----------------------------------------------------------------------------
void InputThreadProc(void* data)
{
	while (!sIsDoQuit)
	{
		if (!sIsHasInput)
		{
			std::cout << "请输入协议测试指令：\n";
			char buffer[256];
			std::cin.getline(buffer, 256);
			std::string cmdbuf(buffer);
			sCmdParams.resize(0);
			split(cmdbuf, std::string(" "), &sCmdParams);

			std::cout << std::endl;
			sIsHasInput = true;
		}
	}
}
//----------------------------------------------------------------------------
int main()
{
	InitializeNetwork();

	time_t ti; time(&ti); srand((unsigned int)ti);

#ifdef PX2_USE_MEMORY
	Memory::Initialize();
#endif

	StringHelp::Initlize();
	FString::Initlize();

	Logger *logger = new0 Logger();

#if defined(_WIN32) || defined(WIN32)
	logger->AddFileHandler("log_server.txt", LT_INFO | LT_ERROR | LT_USER);
#endif
	logger->AddOutputWindowHandler(LT_INFO | LT_ERROR | LT_USER);
	logger->AddConsoleHandler(LT_INFO | LT_ERROR | LT_USER);
	logger->SetLogFileInfo(false);
	logger->StartLogger();

	TestClientConnectorPtr connect_Account = new0 TestClientConnector();
	gClientData.Connect_Accout = connect_Account;

	PX2_SVRINFOMAN.LoadServerInfo("DataServer/config.xml");
	const ServerInfo *serverInfoAC = PX2_SVRINFOMAN.GetServerInfoByName("server_account");
	if (!serverInfoAC) return false;

	if (DoConnect(connect_Account, serverInfoAC->IP.c_str(), serverInfoAC->Port, "account server") != 0)
		return -1;

	Thread *thread = new0 Thread();
	thread->Start(InputThreadProc);

	while (connect_Account->GetConnectState() == CONNSTATE_CONNECTED)
	{
		if (sIsHasInput)
		{
			std::string cmd;
			if (sCmdParams.size() > 0) cmd = sCmdParams[0];

			if (cmd == std::string("quit"))
			{
				sIsDoQuit = true;

				break;
			}
			else if (cmd == std::string("reg"))
			{
				if (sCmdParams.size() == 3)
				{
					account_proto::CARegAccountC msg;
					msg.set_name(sCmdParams[1]);
					msg.set_passwd_md5(Crypt::GetPasswdMd5(sCmdParams[2]));
					connect_Account->SendMsgToServer(account_proto::CA_REG_ACCOUNT, msg);
				}
				else
				{
					printf("参数不对：reg name passwd\n");
				}
			}
			else if (cmd == std::string("newuser"))
			{
				if (sCmdParams.size() == 2)
				{
					account_proto::CANewAccountC msg;
					msg.set_device_id(sCmdParams[1]);
					connect_Account->SendMsgToServer(account_proto::CA_NEW_ACCOUNT, msg);
				}
				else
				{
					printf("参数不对： newuser device_id\n");
				}
			}
			else if (cmd == std::string("svlist"))
			{
				if (sCmdParams.size() == 3)
				{
					account_proto::CAServerListC msg;
					msg.set_version(atoi(sCmdParams[1].c_str()));
					msg.set_svgroup(atoi(sCmdParams[2].c_str()));
					connect_Account->SendMsgToServer(account_proto::CA_SERVER_LIST, msg);
				}
				else
				{
					printf("参数不对：svlist local_ver platform\n");
				}
			}
			else if (cmd == std::string("auth"))
			{
				if (sCmdParams.size() == 4)
				{
					account_proto::CAAuthAccountC msg;
					msg.set_platform(account_proto::ACCOUNT_DEFALUT);
					msg.set_name(sCmdParams[1]);
					msg.set_passwd_md5(Crypt::GetPasswdMd5(sCmdParams[2]));
					connect_Account->SendMsgToServer(account_proto::CA_AUTH_ACCOUNT, msg);
				}
				else
				{
					printf("参数不对：auth name passwd platform\n");
				}
			}
			else if (cmd == std::string("auth91"))
			{
				account_proto::CAAuthAccountC msg;
				msg.set_platform(account_proto::ACCOUNT_91);
				msg.set_uin(123456);
				msg.set_appid(113312);
				msg.set_sid("5e9c3844563640daa9b9d4846031bbd4");
				connect_Account->SendMsgToServer(account_proto::CA_AUTH_ACCOUNT, msg);
			}
			else if (cmd == std::string("authnew"))
			{
				account_proto::CAAuthAccountC msg;
				msg.set_uin(gClientData.UIN);
				msg.set_passwd_md5(gClientData.Passwd_md5);
				msg.set_platform(account_proto::ACCOUNT_DEFALUT);
				connect_Account->SendMsgToServer(account_proto::CA_AUTH_ACCOUNT, msg);
			}

			sIsHasInput = false;
		}

		System::SleepSeconds(0.1f);

		connect_Account->Update(0.0f);
	}

	thread->Join();
	delete0(thread);

	connect_Account->Disconnect();

	System::SleepSeconds(0.1f);

	PX2_SVRINFOMAN.Clear();
	connect_Account = 0;
	gClientData.Connect_Accout = 0;

	if (logger)
	{
		delete0(logger);
		Logger::Set(0);
	}

	FString::Ternimate();

#ifdef PX2_USE_MEMORY
	Memory::Terminate("log_server.txt", false);
#endif

	TerminateNetwork();

	return 0;
}