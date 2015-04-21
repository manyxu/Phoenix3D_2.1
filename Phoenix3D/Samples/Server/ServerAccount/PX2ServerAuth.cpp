// PX2ServerAuth.cpp

#include "PX2ServerAuth.hpp"
using namespace PX2;
using namespace PX2Server;

//----------------------------------------------------------------------------
// Auth
//----------------------------------------------------------------------------
Auth::Auth()
{
	memset(Username, 0, NumMaxAccoutNameSize);
	UIN = 0;
	CPID = 0;
	APPID = 0;
	StartTime = 0;
	IsUsed = false;
	IsAuthorized = false;
}
//----------------------------------------------------------------------------
Auth::~Auth()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// AuthManager
//----------------------------------------------------------------------------
AuthManager::AuthManager(unsigned int numMaxAuth)
{
	mAuths.resize(numMaxAuth);

	for (unsigned int i=0; i<numMaxAuth; i++)
	{
		mAuths[i].IsUsed = false;
		mFreeIDs.push_back(i + 1);
	}

	mTicks = 0;
}
//----------------------------------------------------------------------------
AuthManager::~AuthManager()
{
}
//----------------------------------------------------------------------------
unsigned int AuthManager::AllocAuth(const char *userName, unsigned int cpid, 
	unsigned int appid)
{
	if (mFreeIDs.empty())
		return 0;

	unsigned int id = mFreeIDs.back();
	mFreeIDs.pop_back();

	unsigned int i = id - 1;
	strncpy(mAuths[i].Username, userName, NumMaxAccoutNameSize);

	mAuths[i].UIN = 0;
	mAuths[i].CPID = cpid;
	mAuths[i].APPID = appid;
	mAuths[i].StartTime = mTicks;
	mAuths[i].IsUsed = true;

	return id;
}
//----------------------------------------------------------------------------
Auth *AuthManager::FindAuth(unsigned int id)
{
	if (id==0 || id>mAuths.size()) return 0;

	Auth *ptmp = &mAuths[id - 1];

	if (!ptmp->IsUsed) return 0;

	return ptmp;
}
//----------------------------------------------------------------------------
void AuthManager::Update()
{
	mTicks++;

	for (size_t i =0; i<(int)mAuths.size(); i++)
	{
		Auth *ptmp = &mAuths[i];
		if (ptmp->IsUsed && (mTicks - ptmp->StartTime)>=100000)
		{
			ptmp->IsUsed = false;
			mFreeIDs.push_back(i + 1);
		}
	}
}
//----------------------------------------------------------------------------