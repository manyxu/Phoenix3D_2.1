// PX2GameServer.cpp

#include "PX2GameServer.hpp"
using namespace PX2;

//-----------------------------------------------------------------------------
GameServer::GameServer(ServerType serverType, int port, int numMaxConnects,
	int numMaxMsgHandlers):
	Server(serverType, port, numMaxConnects, numMaxMsgHandlers)
{
}
//-----------------------------------------------------------------------------
GameServer::~GameServer()
{
}
//-----------------------------------------------------------------------------
int GameServer::OnConnect(unsigned int clientID)
{
	return 0;
}
//-----------------------------------------------------------------------------
int GameServer::OnDisconnect(unsigned int clientID)
{
	return 0;
}
//-----------------------------------------------------------------------------