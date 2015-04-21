// PX2ServerAuth.hpp

#ifndef PX2SERVERAUTH_HPP
#define PX2SERVERAUTH_HPP

#include "PX2ServerPre.hpp"
#include "PX2Singleton_NeedNew.hpp"

namespace PX2Server
{

	const int NumMaxAccoutNameSize = 32;

	class Auth
	{
	public:
		Auth();
		~Auth();

		char Username[NumMaxAccoutNameSize];
		unsigned int UIN;
		unsigned int CPID;
		unsigned int APPID;
		unsigned int StartTime;	
		bool IsUsed;
		bool IsAuthorized;
	};

	class AuthManager : public PX2::Singleton<AuthManager>
	{
	public:
		AuthManager(unsigned int numMaxAuth);
		~AuthManager();

		unsigned int AllocAuth(const char *pname, unsigned int cpid, 
			unsigned int appid);
		Auth *FindAuth(unsigned int id);

		void Update();

	private:
		std::vector<Auth> mAuths;
		std::vector<unsigned int> mFreeIDs;
		unsigned int mTicks;
	};


}

#endif