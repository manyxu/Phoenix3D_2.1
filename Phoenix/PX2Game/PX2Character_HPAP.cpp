/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Character_HPAP.cpp
*
*/

#include "PX2Character.hpp"
#include "PX2GameEventType.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void Character::AddCurHP (int hp, int tag)
{
	PX2_UNUSED(tag);

	int curHP = GetCurHP();
	curHP += hp;

	SetCurHP(curHP);
}
//----------------------------------------------------------------------------
void Character::SetCurHP (int hp)
{
	if (mIsCurHPNoReduce)
	{
		return;
	}

	if (hp < 0)
		hp = 0;

	int modifiedHP = GetMHP();
	if (hp > modifiedHP)
		hp = modifiedHP;

	mHP = hp;
}
//----------------------------------------------------------------------------
void Character::AddMHP (const std::string &factorName, int modHP)
{
	mMMapHPs[factorName] = modHP;

	CalMHP();
}
//----------------------------------------------------------------------------
void Character::RemoveMHP (const std::string &factorName)
{
	std::map<std::string, int>::iterator it = mMMapHPs.find(factorName);
	if (it != mMMapHPs.end())
	{
		mMMapHPs.erase(it);
	}

	CalMHP();
}
//----------------------------------------------------------------------------
void Character::CalMHP ()
{
	mMHP = GetBaseHPCurLevel();

	std::map<std::string, int>::iterator it = mMMapHPs.begin();
	for (; it!=mMMapHPs.end(); it++)
	{
		mMHP += it->second;
	}
}
//----------------------------------------------------------------------------
void Character::SetBaseHPCurLevel (int hp)
{
	mBaseHPCurLevel = hp;

	CalMHP();
}
//----------------------------------------------------------------------------
void Character::SetCurAP (int ap)
{
	if (ap < 0)
		ap = 0;

	mAP = ap;
}
//----------------------------------------------------------------------------
void Character::AddMAP (const std::string &factorName, int modAP)
{
	mMMapAPs[factorName] = modAP;

	CalMAP();
}
//----------------------------------------------------------------------------
void Character::RemoveMAP (const std::string &factorName)
{
	std::map<std::string, int>::iterator it = mMMapAPs.find(factorName);	
	if (it != mMMapAPs.end())
	{
		mMMapAPs.erase(it);
	}

	CalMAP();
}
//----------------------------------------------------------------------------
void Character::CalMAP ()
{
	mMAP = GetBaseAPCurLevel();

	std::map<std::string, int>::iterator it = mMMapAPs.begin();
	for (; it!=mMMapAPs.end(); it++)
	{
		mMAP += it->second;
	}
}
//----------------------------------------------------------------------------
void Character::SetBaseAPCurLevel (int ap)
{
	mBaseAPCurLevel = ap;

	CalMAP();
}
//----------------------------------------------------------------------------
void Character::SetDead (bool dead)
{
	mIsDead = false;
}
//----------------------------------------------------------------------------
void Character::Die ()
{
	mIsDead = true;

	SetAimTarget(0);
	AddStopSpeedTag("Die");

	Event *ent = GameEventSpace::CreateEventX(GameEventSpace::CharacterDie);
	ent->SetData<Character*>(this);
	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);

	if (mIsDieDoDelete)
	{
		Event *deleteEnt = GameEventSpace::CreateEventX(GameEventSpace::ActorDelete);
		deleteEnt->SetData<Actor*>(this);
		deleteEnt->SetTimeDelay(10.0f);
		EventWorld::GetSingleton().BroadcastingLocalEvent(deleteEnt);
	}

	for (int i=0; i<GetNumSkills(); i++)
	{
		Skill *skill = GetSkill(i);
		if (skill && skill->IsEnable() && skill->IsDieActivate())
		{
			skill->Activate();
		}
	}

	if (!mScriptHandler_OnDie.empty())
		CallString(mScriptHandler_OnDie.c_str());

	std::map<std::string, std::string>::iterator it =
		mScriptHandlers_OnDie.begin();
	for (; it!=mScriptHandlers_OnDie.end(); it++)
	{
		CallString(it->second.c_str());
	}
}
//----------------------------------------------------------------------------
void Character::AddScriptHandler_OnDie (const std::string &name,
	const std::string &handler)
{
	mScriptHandlers_OnDie[name] = handler;
}
//----------------------------------------------------------------------------
void Character::RemoveScriptHandler_OnDie (const std::string &name)
{
	std::map<std::string, std::string>::iterator it =
		mScriptHandlers_OnDie.find(name);	
	if (it != mScriptHandlers_OnDie.end())
	{
		mScriptHandlers_OnDie.erase(it);
	}
}
//----------------------------------------------------------------------------