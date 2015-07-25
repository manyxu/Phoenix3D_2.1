// PX2ServerAccount.hpp

#ifndef PX2SRV_SERVERACCOUNT_HPP
#define PX2SRV_SERVERACCOUNT_HPP

#include "PX2NetServer.hpp"

namespace PX2Server
{

	class ServerAccount : public PX2::Server
	{
	public:
		ServerAccount(PX2::Server::ServerType serverType, int port, 
			int numMaxConnects, int numMaxMsgHandlers);
		virtual ~ServerAccount();

		template<class T>
		int SendMsgToDB(int msgid, T &msg);

	protected:
		virtual int OnConnect(unsigned int clientid);
		virtual int OnDisconnect(unsigned int clientid);

		int OnRegAccount(unsigned int clientid, const void *pbuffer, int buflen);
		int OnAuthAccount(unsigned int clientid, const void *pbuffer, int buflen);
		int OnPay(unsigned int clientid, const void *pbuffer, int buflen);
		int OnGameServerAuthAccount(unsigned int clientid, const void *pbuffer, int buflen);
	};

}

#endif