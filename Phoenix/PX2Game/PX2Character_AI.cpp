/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Character_AI.cpp
*
*/

#include "PX2Character.hpp"
#include "PX2Scene.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void Character::Freeze (bool enable)
{
	mIsFreezed = enable;

	if (mIsFreezed)
	{
		//StopSpeed(true);
		StopCurAnim();
	}
	else
	{
		//StopSpeed(false);
		PlayCurAnim();
	}
}
//----------------------------------------------------------------------------
void Character::SetCanBeAimed (bool can)
{
	mBitSet[BST_CANBEAIMED] = can;
	mIsCanAimed = can;
}
//----------------------------------------------------------------------------
void Character::SetAimTarget (int targetID)
{
	if (mAimTargetID == targetID)
		return;

	Character *aimChar = GetAimTargetCharacterAlive();
	if (aimChar)
	{
		aimChar->MinusNumAimingMe();
	}

	mAimTargetID = targetID;

	aimChar = GetAimTargetCharacterAlive();
	if (aimChar)
	{
		aimChar->AddNumAimingMe();
	}
}
//----------------------------------------------------------------------------
Character *Character::GetAimTargetCharacter () const
{
	if (!mScene)
		return 0;

	return DynamicCast<Character>(mScene->GetActorByID(mAimTargetID));
}
//----------------------------------------------------------------------------
Character *Character::GetAimTargetCharacterAlive () const
{
	if (!mScene)
		return 0;

	Character *charac = DynamicCast<Character>(mScene->GetActorByID(mAimTargetID));
	if (charac && !charac->IsDead())
	{
		return charac;
	}

	return 0;
}
//----------------------------------------------------------------------------
void Character::BeAffect (AffectObject *ao)
{
	SetCurAffectMeObject(ao);

	OnBeAffect(ao);

	if (ao->AffectCharacter)
	{
		ao->BeAffectCharacter = this;
		ao->AffectCharacter->OnSucAffect(ao);
	}

	SetCurAffectMeObject(0);
}
//----------------------------------------------------------------------------
void Character::OnBeAffect (AffectObject *ao)
{
	for (int i=0; i<(int)mItems.size(); i++)
	{
		mItems[i]->OnBeAffect(ao);
	}

	if (!mScriptHandler_OnBeAffect.empty())
		CallString(mScriptHandler_OnBeAffect.c_str());

	std::map<std::string, std::string>::iterator it =
		mScriptHandlers_OnBeAffect.begin();
	for (; it!=mScriptHandlers_OnBeAffect.end(); it++)
	{
		CallString(it->second.c_str());
	}
}
//----------------------------------------------------------------------------
void Character::OnSucAffect (AffectObject *ao)
{
	SetCurSucAffectObject(ao);

	for (int i=0; i<(int)mItems.size(); i++)
	{
		mItems[i]->OnSucAffect(ao);
	}

	if (!mScriptHandler_OnSucAffect.empty())
		CallString(mScriptHandler_OnSucAffect.c_str());

	std::map<std::string, std::string>::iterator it =
		mScriptHandlers_OnSucAffect.begin();
	for (; it!=mScriptHandlers_OnSucAffect.end(); it++)
	{
		CallString(it->second.c_str());
	}

	SetCurSucAffectObject(0);
}
//----------------------------------------------------------------------------
void Character::AddScriptHandler_OnBeAffect (const std::string &name,
	const std::string &handler)
{
	mScriptHandlers_OnBeAffect[name] = handler;
}
//----------------------------------------------------------------------------
void Character::RemoveScriptHandler_OnBeAffect (const std::string &name)
{
	std::map<std::string, std::string>::iterator it =
		mScriptHandlers_OnBeAffect.find(name);	
	if (it != mScriptHandlers_OnBeAffect.end())
	{
		mScriptHandlers_OnBeAffect.erase(it);
	}
}
//----------------------------------------------------------------------------
void Character::AddScriptHandler_OnSucAffect (const std::string &name,
	const std::string &handler)
{
	mScriptHandlers_OnSucAffect[name] = handler;
}
//----------------------------------------------------------------------------
void Character::RemoveScriptHandler_OnSucAffect (const std::string &name)
{
	std::map<std::string, std::string>::iterator it =
		mScriptHandlers_OnSucAffect.find(name);	
	if (it != mScriptHandlers_OnSucAffect.end())
	{
		mScriptHandlers_OnSucAffect.erase(it);
	}
}
//----------------------------------------------------------------------------
void Character::SetScriptHandler_OnSucAffectParam (const std::string &name,
	float param)
{
	mScriptHandlers_OnSucAffectParams[name] = param;
}
//----------------------------------------------------------------------------
float Character::GetScriptHandler_OnSucAffectParam (const std::string &name)
{
	return mScriptHandlers_OnSucAffectParams[name];
}
//----------------------------------------------------------------------------
void Character::CreateStateMachines ()
{
	mActionSM = new0 StateMachine<Character>(this);
	mMovementSM = new0 StateMachine<Character>(this);
	mPostureSM = new0 StateMachine<Character>(this);
}
//----------------------------------------------------------------------------