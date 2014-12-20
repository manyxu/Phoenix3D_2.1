/*
*
* ÎÄ¼þÃû³Æ	£º	PX2AccoutManager.hpp
*
*/

#ifndef PX2ACCOUTMANAGER_HPP
#define PX2ACCOUTMANAGER_HPP

#include "PX2GamePre.hpp"
#include "PX2User.hpp"
#include "PX2ServerInfo.hpp"
#include "PX2Singleton.hpp"

namespace PX2
{

	class AccoutManager : public Singleton<AccoutManager>
	{
	public:
		AccoutManager ();
		~AccoutManager();

		void Update (float appTime, float elapsedTime);

		bool LoadServerList (const std::string &filename);
		const ServerInfo *GetServerInfoByType (const std::string &type) const;
		const ServerInfo *GetServerInfoByName (const std::string &name) const;

		// users
		void AddUser (User *user);
		void DeleteUser (User *user);
		User *GetUser (const int i) const;
		User *GetUser (const std::string &name) const;
		void DeleteAllUsers ();

	protected:
		std::vector<ServerInfoPtr> mServerInfos;
		std::vector<UserPtr> mUsers;
	};

#include "PX2AccoutManager.inl"

#define PX2_AM AccoutManager::GetSingleton()

}

#endif