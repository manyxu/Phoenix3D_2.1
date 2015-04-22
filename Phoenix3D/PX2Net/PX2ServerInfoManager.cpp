// PX2ServerInfoManager.cpp

#include "PX2ServerInfoManager.hpp"
#include "PX2XMLData.hpp"
#include "PX2ResourceManager.hpp"
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
	char *buffer = 0;
	int bufferSize = 0;

	if (PX2_RM.LoadBuffer(filename, bufferSize, buffer))
	{
		XMLData data;
		if (data.LoadBuffer(buffer, bufferSize))
		{
			XMLNode rootNode = data.GetRootNode();
			XMLNode child = rootNode.IterateChild();

			while (!child.IsNull())
			{
				ServerInfo *info = new0 ServerInfo();

				info->Type = child.GetName();
				info->Name = child.AttributeToString("name");
				info->Addr = child.AttributeToString("addr");
				info->WWWAddr = child.AttributeToString("wwwaddr");
				info->NumMaxConnect = child.AttributeToInt("nummaxconnect");

				mServerInfos.push_back(info);

				child = rootNode.IterateChild(child);
			}
		}

		return true;
	}

	return false;
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