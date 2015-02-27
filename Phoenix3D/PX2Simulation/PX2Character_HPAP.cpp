// PX2Character_HPAP.cpp

#include "PX2Character.hpp"
#include "PX2SimulationEventType.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void Character::OnCalMHP()
{
}
//----------------------------------------------------------------------------
void Character::SetBaseHPCurLevel(float hp)
{
	mBaseHPCurLevel = hp;
}
//----------------------------------------------------------------------------
inline float Character::GetHPPercent() const
{
	return (float)GetHP() / (float)GetMHP();
}
//----------------------------------------------------------------------------
void Character::OnCalMAP()
{
}
//----------------------------------------------------------------------------
void Character::SetDead(bool dead)
{
	mIsDead = dead;
}
//----------------------------------------------------------------------------
void Character::Die()
{
	mIsDead = true;

	Event *ent = SimuES::CreateEventX(SimuES::Character_Die);
	ent->SetData<Character*>(this);
	PX2_EW.BroadcastingLocalEvent(ent);

	if (mIsDieDoDelete)
	{
		Event *deleteEnt = SimuES::CreateEventX(SimuES::Actor_Delete);
		deleteEnt->SetData<Actor*>(this);
		deleteEnt->SetTimeDelay(10.0f);
		EventWorld::GetSingleton().BroadcastingLocalEvent(deleteEnt);
	}
}
//----------------------------------------------------------------------------
void Character::SetBaseAPCurLevel(float ap)
{
	mBaseAPCurLevel = ap;
}
//----------------------------------------------------------------------------