// PX2ServerInfoManager.cpp

#include "PX2ServerInfoManager.hpp"
#include "PX2XMLData.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
ServerInfoManager::ServerInfoManager()
{
}
//----------------------------------------------------------------------------
ServerInfoManager::~ServerInfoManager()
{
}
//----------------------------------------------------------------------------
bool ServerInfoManager::LoadServerInfo(const std::string &filename)
{
	XMLData data;
	if (data.LoadFile(filename))
	{
		XMLNode rootNode = data.GetRootNode();
		XMLNode child = rootNode.IterateChild();

		while (!child.IsNull())
		{
			ServerInfo *info = new0 ServerInfo();

			info->Type = child.GetName();
			info->Name = child.AttributeToString("name");
			info->IP = child.AttributeToString("ip");
			info->WWWAddr = child.AttributeToString("wwwaddr");
			info->NumMaxConnect = child.AttributeToInt("nummaxconnect");
			info->Port = child.AttributeToInt("port");

			mServerInfos.push_back(info);

			child = rootNode.IterateChild(child);
		}
	}

	return true;
}
//----------------------------------------------------------------------------
void ServerInfoManager::Clear()
{
	mServerInfos.clear();
}
//----------------------------------------------------------------------------
const ServerInfo *ServerInfoManager::GetServerInfoByType(
	const std::string &type)
const
{
	for (int i = 0; i < (int)mServerInfos.size(); i++)
	{
		if (type == mServerInfos[i]->Type)
			return mServerInfos[i];
	}

	return 0;
}
//----------------------------------------------------------------------------
const ServerInfo *ServerInfoManager::GetServerInfoByName(
	const std::string &name)
const
{
	for (int i = 0; i < (int)mServerInfos.size(); i++)
	{
		if (name == mServerInfos[i]->Name)
			return mServerInfos[i];
	}

	return 0;
}
//----------------------------------------------------------------------------