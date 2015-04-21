// PX2ServerLoopAccount.hpp

#ifndef PX2SERVERLOOPACCOUNT_HPP
#define PX2SERVERLOOPACCOUNT_HPP

#include "PX2ServerLoop.hpp"

namespace PX2Server
{

	class AuthManager;
	class ServerAccount;

	class ServerLoopAccount : public ServerLoop
	{
	public:
		ServerLoopAccount();
		virtual ~ServerLoopAccount();

		virtual bool Initlize();
		virtual bool Ternamate();

		virtual void Run();

	protected:
		AuthManager *mAuthManager;
		ServerAccount *mServerAccount;
	};

}

#endif