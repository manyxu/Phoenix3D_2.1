/*
*
* ÎÄ¼þÃû³Æ	£º	PX2StandingState.cpp
*
*/

#include "PX2StandingState.hpp"
#include "PX2Character.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
StandingState::StandingState ()
{
}
//----------------------------------------------------------------------------
StandingState::~StandingState ()
{
}
//----------------------------------------------------------------------------
void StandingState::Update (Character *chara, double appSeconds,
	double elapsedSeconds)
{
	PX2_UNUSED(chara);
	PX2_UNUSED(appSeconds);
	PX2_UNUSED(elapsedSeconds);
}
//----------------------------------------------------------------------------
void StandingState::StateEnter (Character *chara)
{
	chara->PlayAnimByName("stand");
}
//----------------------------------------------------------------------------
void StandingState::StateExit (Character *chara)
{
	PX2_UNUSED(chara);
}
//----------------------------------------------------------------------------