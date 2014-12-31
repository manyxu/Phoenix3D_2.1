/*
*
* ÎÄ¼þÃû³Æ	£º	PX2AccoutManager.cpp
*
*/

#include "PX2AccoutManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
AccoutManager::AccoutManager()
{
}
//----------------------------------------------------------------------------
AccoutManager::~AccoutManager()
{
}
//----------------------------------------------------------------------------
void AccoutManager::Update(float appTime, float elapsedTime)
{
	for (int i = 0; i < (int)mUsers.size(); i++)
	{
		if (mUsers[i])
		{
			mUsers[i]->Update(appTime, elapsedTime);
		}
	}
}
//----------------------------------------------------------------------------
bool AccoutManager::LoadServerList(const std::string &filename)
{
	return false;
}
//----------------------------------------------------------------------------
const ServerInfo *AccoutManager::GetServerInfoByType(const std::string &type)
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
const ServerInfo *AccoutManager::GetServerInfoByName(const std::string &name)
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
void AccoutManager::AddUser(User *user)
{
	mUsers.push_back(user);
}
//----------------------------------------------------------------------------
void AccoutManager::DeleteUser(User *user)
{
	std::vector<UserPtr>::iterator it = mUsers.begin();

	for (; it != mUsers.end();)
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
User *AccoutManager::GetUser(const std::string &name) const
{
	for (int i = 0; i < (int)mUsers.size(); i++)
	{
		if (name == mUsers[i]->GetName())
			return mUsers[i];
	}

	return 0;
}
//----------------------------------------------------------------------------
User *AccoutManager::GetUser(const int i) const
{
	if (i < 0 || (int)mUsers.size() <= 0 || (int)mUsers.size() < i)
	{
		return 0;
	}

	return mUsers[i];

}
//----------------------------------------------------------------------------
void AccoutManager::DeleteAllUsers()
{
	mUsers.clear();
}
//----------------------------------------------------------------------------