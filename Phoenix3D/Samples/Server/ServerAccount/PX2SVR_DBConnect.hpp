// PX2SVR_ServerDBConnect.hpp

#ifndef PX2SER_DBCONNECT_HPP
#define PX2SER_DBCONNECT_HPP

#include "PX2NetClientConnector.hpp"

namespace PX2Server
{

	class DBConnect : public PX2::ClientConnector
	{
	public:
		DBConnect();
		~DBConnect();
	};

}

#endif