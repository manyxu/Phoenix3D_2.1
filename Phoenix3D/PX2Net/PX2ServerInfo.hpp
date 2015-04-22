// PX2ServerInfo.hpp

#ifndef PX2SERVERINFO_HPP
#define PX2SERVERINFO_HPP

#include "PX2SmartPointer.hpp"

namespace PX2
{

	class ServerInfo
	{
	public:
		ServerInfo();
		~ServerInfo();

		int ID;
		int Status;
		std::string Type;
		std::string Name;
		std::string Addr;
		std::string WWWAddr;
	};

	typedef Pointer0<ServerInfo> ServerInfoPtr;

}

#endif