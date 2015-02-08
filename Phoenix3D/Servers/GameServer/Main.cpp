// Main.cpp

#include "PX2NetInitTerm.hpp"
#include "PX2XMLData.hpp"
#include "PX2System.hpp"
#include "PX2Log.hpp"
#include "PX2GameServer.hpp"
#include "PX2StringHelp.hpp"
#include "PX2FString.hpp"
using namespace PX2;

int main()
{
	Memory::Initialize();

	InitializeNetwork();

	StringHelp::Initlize();
	FString::Initlize();

	Logger *logger = new0 Logger();

#if defined(_WIN32) || defined(WIN32)
	logger->AddFileHandler("GameServer_Log.txt", LT_INFO | LT_ERROR | LT_USER);
#endif
	logger->AddOutputWindowHandler(LT_INFO | LT_ERROR | LT_USER);
	logger->StartLogger();

	int nunProcess = System::GetNumCPUs();
	PX2_LOG_INFO("%d Cpus", nunProcess);

	XMLData configData;
	configData.LoadFile("config.xml");

	ServerPtr srv = new0 GameServer(Server::ST_IOCP, 2048, 20000, 200);
	
	if (!srv->Start())
	{
		return -1;
	}
	
	srv->Run();

	System::SleepSeconds(0.1f);

	TerminateNetwork();

	if (logger)
	{
		delete0(logger);
		Logger::Set(0);
	}

	FString::Ternimate();

	Memory::Terminate("GameServer_MemoryReport.txt", false);

	return 0;
}