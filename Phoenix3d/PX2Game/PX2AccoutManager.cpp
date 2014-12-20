/*
*
* ÎÄ¼þÃû³Æ	£º	PX2AccoutManager.cpp
*
*/

#include "PX2AccoutManager.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2XMLData.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
AccoutManager::AccoutManager ()
{
}
//----------------------------------------------------------------------------
AccoutManager::~AccoutManager ()
{
}
//----------------------------------------------------------------------------
void AccoutManager::Update (float appTime, float elapsedTime)
{
	for (int i=0; i<(int)mUsers.size(); i++)
	{
		if (mUsers[i])
		{
			mUsers[i]->Update(appTime, elapsedTime);
		}
	}
}
//----------------------------------------------------------------------------
bool AccoutManager::LoadServerList (const std::string &filename)
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
				info->Name = child.AttributeToString("Name");
				info->Address = SocketAddress(
					child.AttributeToString("IP"),
					(uint16_t)child.AttributeToInt("Port"));
				info->WWWAddr = child.AttributeToString("WWWAddr");

				mServerInfos.push_back(info);

				child = rootNode.IterateChild(child);
			}
		}

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
const ServerInfo *AccoutManager::GetServerInfoByType (const std::string &type)
	const
{
	for (int i=0; i<(int)mServerInfos.size(); i++)
	{
		if (type == mServerInfos[i]->Type)
			return mServerInfos[i];
	}

	return 0;
}
//----------------------------------------------------------------------------
const ServerInfo *AccoutManager::GetServerInfoByName (const std::string &name)
	const
{
	for (int i=0; i<(int)mServerInfos.size(); i++)
	{
		if (name == mServerInfos[i]->Name)
			return mServerInfos[i];
	}

	return 0;
}
//----------------------------------------------------------------------------
void AccoutManager::AddUser (User *user)
{
	mUsers.push_back(user);
}
//----------------------------------------------------------------------------
void AccoutManager::DeleteUser (User *user)
{
	std::vector<UserPtr>::iterator it=mUsers.begin();

	for (;it!=mUsers.end();)
	{
		if (user == *it)
		{
			it = mUsers.erase(it);
		}
		else
		{
			it++;
		}
	}
}
//----------------------------------------------------------------------------
User *AccoutManager::GetUser (const std::string &name) const
{
	for (int i=0; i<(int)mUsers.size(); i++)
	{
		if (name == mUsers[i]->GetName())
			return mUsers[i];
	}

	return 0;
}
//----------------------------------------------------------------------------
User *AccoutManager::GetUser (const int i) const
{
	if (i<0 || (int)mUsers.size()<=0 || (int)mUsers.size() < i)
	{
		return 0;
	}

	return mUsers[i];

}
//----------------------------------------------------------------------------
void AccoutManager::DeleteAllUsers ()
{
	mUsers.clear();
}
//----------------------------------------------------------------------------