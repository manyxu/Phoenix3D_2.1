// X_Net.cpp

#include "X_Net.hpp"
#include "PX2MD5.hpp"
#include "PX2AccoutManager.hpp"
#include "PX2Log.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
X_Net::X_Net() :
mServerListVersion(0),
mIsAccountServerConnected(false),
mIsGameServerConnected(false),
mTryToConnectGameServerID(-1),
mClentSignalServerTime(0.0f)
{
}
//----------------------------------------------------------------------------
X_Net::~X_Net()
{
	for (int i = 0; i < (int)TheLoginData_Actors.size(); i++)
	{
		if (TheLoginData_Actors[i])
		{
			delete0(TheLoginData_Actors[i]);
		}
	}

	TheLoginData_Actors.clear();
}
//----------------------------------------------------------------------------
bool X_Net::Init()
{
	bool loadServerList = PX2_AM.LoadServerList("Data/net/serverlist.xml");
	if (!loadServerList)
	{
		assertion(loadServerList, "LoadServerList failed!\n");
		PX2_LOG_ERROR("LoadServerList failed");
	}

	return true;
}
//----------------------------------------------------------------------------
bool X_Net::Term()
{
	return true;
}
//----------------------------------------------------------------------------
std::string X_Net::GetPasswordMD5(const std::string &readablePasswd)
{
	char buffer[17], out[33];
	memset(buffer, 0, sizeof(buffer));
	memset(out, 0, sizeof(out));

	Md5HashBuffer(buffer, readablePasswd.c_str(), (int)readablePasswd.length());
	Md5HexString(buffer, out);

	memmove(out, out + 8, 16);
	out[16] = 0;

	return std::string(out);
}
//----------------------------------------------------------------------------