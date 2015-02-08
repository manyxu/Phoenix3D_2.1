// PX2GameServer.hpp

#ifndef PX2GAMESERVER_HPP
#define PX2GAMESERVER_HPP

#include "PX2NetServer.hpp"

namespace PX2
{

	class GameServer : public Server
	{
	public:
		GameServer(ServerType serverType, int port, int numMaxConnects,
			int numMaxMsgHandlers);
		virtual ~GameServer();

	protected:
		virtual int OnConnect(unsigned int clientID);
		virtual int OnDisconnect(unsigned int clientID);
	};

}

#endif