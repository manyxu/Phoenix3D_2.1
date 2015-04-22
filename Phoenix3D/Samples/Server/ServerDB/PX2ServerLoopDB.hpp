// PX2ServerLoopDB.hpp

#ifndef PX2SERVERLOOPDB_HPP
#define PX2SERVERLOOPDB_HPP

#include "PX2ServerLoop.hpp"

namespace PX2Server
{

	class ServerDB;
	class DBPool;
	
	class ServerLoopDB : public ServerLoop
	{
	public:
		ServerLoopDB();
		virtual ~ServerLoopDB();

		virtual bool Initlize();
		virtual bool Ternamate();

		virtual void Run();

	protected:
		ServerDB *mServerDB;
		DBPool *mDBPool;
	};

}

#endif