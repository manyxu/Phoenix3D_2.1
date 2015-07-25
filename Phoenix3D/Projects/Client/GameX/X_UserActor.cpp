// X_UserActor.cpp

#include "X_UserActor.hpp"
#include "PX2AccoutManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
// X_UserActor
//----------------------------------------------------------------------------
X_UserActor::X_UserActor()
	:
	mTypeID(0)
{
}
//----------------------------------------------------------------------------
X_UserActor::~X_UserActor()
{
}
//----------------------------------------------------------------------------
void X_UserActor::SetLevel(int level)
{
	UserActor::SetLevel(level);
}
//----------------------------------------------------------------------------
void X_UserActor::SetCurLevelExp(int exp)
{
	UserActor::SetCurLevelExp(exp);
}
//----------------------------------------------------------------------------
void X_UserActor::SetTypeID(int typeID)
{
	mTypeID = typeID;
}
//----------------------------------------------------------------------------
int X_UserActor::GetTypeID() const
{
	return mTypeID;
}
//----------------------------------------------------------------------------
X_Chara *X_UserActor::CreateChara()
{
	X_Chara *chara = new0 X_Chara(X_Chara::CT_PLAYER);
	chara->SetTypeID(mTypeID);
	chara->SetLevel(mLevel);

	chara->SetPickable(false);

	return chara;
}
//----------------------------------------------------------------------------
void X_UserActor::SetMainChara(X_Chara *chara)
{
	mMainChara = chara;
}
//----------------------------------------------------------------------------
void X_UserActor::SetGold(int gold)
{
	UserActor::SetGold(gold);
}
//----------------------------------------------------------------------------
void X_UserActor::Update(float appTime, float elapsedTime)
{
	UserActor::Update(appTime, elapsedTime);

	if (mMainChara)
	{
		mMainChara->Update(appTime, elapsedTime);
	}
}
//----------------------------------------------------------------------------
void X_UserActor::DoExecute(Event *event)
{
	PX2_UNUSED(event);
}
//----------------------------------------------------------------------------