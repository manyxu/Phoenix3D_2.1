// PX2ServerDB.cpp

#include "PX2ServerDB.hpp"
using namespace PX2Server;
using namespace PX2;

//----------------------------------------------------------------------------
ServerDB::ServerDB(Server::ServerType serverType, int port,
	int numMaxConnects, int numMaxMsgHandlers) :
	Server(serverType, port, numMaxConnects, numMaxMsgHandlers)
{
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