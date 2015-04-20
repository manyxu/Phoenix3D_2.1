// PX2ServerUserManager.hpp

#ifndef PX2SERVERUSERMANAGER_HPP
#define PX2SERVERUSERMANAGER_HPP

#include "PX2CorePre.hpp"
#include "PX2ServerUser.hpp"

namespace PX2Server
{

	const int MaxNickNameLength = 16;

	class UserManager
	{
	public:
		UserManager(int player_pool_size);
		~UserManager();

		User *GetUserByUIN(unsigned int uin);
		User *AllocUser(unsigned int clientid, unsigned int uin);
		void FreePlayer(User *player);
		User *GetUserByID(unsigned int clientid);
		void ResetUserClientID(User *player, unsigned int clientid);

	private:
		std::map<unsigned int, User *> mClientIDToUsers;
		std::map<unsigned int, User *> mUINToUsers;
		std::vector<User> mUserPool;
		std::vector<User*> mFreeUsers;
	};
}

#endif