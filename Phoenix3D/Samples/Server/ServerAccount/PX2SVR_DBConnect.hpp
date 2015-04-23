// PX2SVR_ServerDBConnect.hpp

#ifndef PX2SER_DBCONNECT_HPP
#define PX2SER_DBCONNECT_HPP

#include "PX2NetClientConnector.hpp"
#include "PX2Singleton_NeedNew.hpp"

namespace PX2Server
{

	class DBConnect : public PX2::ClientConnector, public PX2::Singleton<DBConnect>
	{
	public:
		DBConnect();
		~DBConnect();
	};

}

#endif