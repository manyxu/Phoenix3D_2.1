// PX2SVR_AccountConnect.hpp

#ifndef PX2SER_ACCOUNTCONNECT_HPP
#define PX2SER_ACCOUNTCONNECT_HPP

#include "PX2NetClientConnector.hpp"

namespace PX2Server
{

	class AccountConnect : public PX2::ClientConnector
	{
	public:
		AccountConnect();
		~AccountConnect();
	};

}

#endif