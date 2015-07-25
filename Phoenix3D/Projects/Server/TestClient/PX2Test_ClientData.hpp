// PX2Test_ClientData.hpp

#ifndef PX2TEST_CLIENTDATA_HPP
#define PX2TEST_CLIENTDATA_HPP

#include "PX2Test_ClientConnect.hpp"

class ClientData
{
public:
	ClientData();
	~ClientData();

	PX2::TestClientConnector *Connect_Accout;
	PX2::TestClientConnector *Connect_Simu;

	unsigned int UIN;
	std::string SessionID;
	std::string Passwd_md5;
};

extern ClientData gClientData;

#endif