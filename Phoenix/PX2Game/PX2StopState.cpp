/*
*
* ÎÄ¼þÃû³Æ	£º	PX2StopState.cpp
*
*/

#include "PX2StopState.hpp"
#include "PX2Character.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
StopState::StopState ()
{
}
//----------------------------------------------------------------------------
StopState::~StopState ()
{
}
//----------------------------------------------------------------------------
void StopState::Update (Character *chara, double appSeconds,
	double elapsedSeconds)
{
	PX2_UNUSED(chara);
	PX2_UNUSED(appSeconds);
	PX2_UNUSED(elapsedSeconds);
}
//----------------------------------------------------------------------------
void StopState::StateEnter (Character *chara)
{
	chara->AddStopSpeedTag("StopState");

	if (!chara->IsStaticType())
	{
	}
}
//----------------------------------------------------------------------------
void StopState::StateExit (Character *chara)
{
	chara->RemoveStopSpeedTag("StopState");
}
//----------------------------------------------------------------------------