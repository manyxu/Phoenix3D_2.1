// X_UIMan.cpp

#include "X_Man.hpp"
#include "X_Net.hpp"
#include "X_UIMan.hpp"
#include "X_BatMan.hpp"
#include "X_DefMan.hpp"
#include "X_Event.hpp"
#include "X_UserActor.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2Project.hpp"
#include "PX2EventWorld.hpp"
#include "PX2AccoutManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
X_Man::X_Man() :
mCurGameDataVersion(0),
mIsHasAccounts(false),
mIndexActorTryToPlay(0),
mIndexActorPlay(0),
mMapIDTryToEnter(0),
mMapIDEntered(0)
{
}
//----------------------------------------------------------------------------
X_Man::~X_Man()
{
}
//----------------------------------------------------------------------------
bool X_Man::Init()
{
	EventWorld::GetSingleton().ComeIn(this);

	X_Net *net = new0 X_Net();
	net->Init();

	X_UIMan *sMan = new0 X_UIMan();
	sMan->Init();
	PX2_EW.ComeIn(sMan);

	X_BatMan *batMan = new0 X_BatMan();
	PX2_UNUSED(batMan);

	// Show Company
	X_UIMAN.Create_CompanyFrame();

	Event *ent = X_EventSpace::CreateEventX(X_EventSpace::Show_SplashOver);
	ent->SetTimeDelay(2.0f);
	PX2_EW.BroadcastingLocalEvent(ent);

	return true;
}
//----------------------------------------------------------------------------
bool X_Man::Init_Start()
{
	X_UIMAN.Destory_CompanyFrame();

	X_UIMAN.Create_StartupFrame();

	Init_Updated();

	return true;
}
//----------------------------------------------------------------------------
bool X_Man::Init_Updated()
{
	X_UIMAN.Destory_StartupFrame();

	X_DEFM.LoadAll();
	PX2_SM.CallFile("Data/scripts/general.lua");

	ConnectToAccountServer();

	return true;
}
//----------------------------------------------------------------------------
bool X_Man::Term()
{
	User *user = PX2_AM.GetUser(0);
	if (user)
	{
		X_UserActor *userActor = (X_UserActor*)user->GetUserActor(0);
		if (userActor) PX2_EW.GoOut(userActor);
	}

	X_BatMan *batMan = X_BatMan::GetSingletonPtr();
	if (batMan)
	{
		delete0(batMan);
		X_BatMan::Set(0);
	}

	X_UIMan *sMan = X_UIMan::GetSingletonPtr();
	if (sMan)
	{
		PX2_EW.GoOut(sMan);

		delete0(sMan);
		X_UIMan::Set(0);
	}

	X_Net *net = X_Net::GetSingletonPtr();
	net->Term();
	delete0(net);
	X_Net::Set(0);

	EventWorld::GetSingleton().GoOut(this);

	return true;
}
//----------------------------------------------------------------------------
void X_Man::Update(float appSeconds, float elapsedSeconds)
{
	X_UIMAN.Update(appSeconds, elapsedSeconds);
}
//----------------------------------------------------------------------------
bool X_Man::IsUseNet() const
{
	return false;
}
//----------------------------------------------------------------------------
bool X_Man::NetStating() const
{
	//if (D_NET.mGameConnect->GetConnectState() == CONNSTATE_CONN_ERROR)
	//{
	//	D_UIMAN.CloseNetTip();
	//	D_UIMAN.OpenNetDisConnectFrame();

	//	return false;
	//}

	return true;
}
//----------------------------------------------------------------------------