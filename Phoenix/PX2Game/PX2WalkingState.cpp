/*
*
* ÎÄ¼þÃû³Æ	£º	PX2WalkingState.cpp
*
*/

#include "PX2WalkingState.hpp"
#include "PX2Character.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
WalkingState::WalkingState ()
{
}
//----------------------------------------------------------------------------
WalkingState::~WalkingState ()
{
}
//----------------------------------------------------------------------------
void WalkingState::Update (Character *chara, double appSeconds, 
	double elapsedSeconds)
{
	PX2_UNUSED(chara);
	PX2_UNUSED(appSeconds);
	PX2_UNUSED(elapsedSeconds);
}
//----------------------------------------------------------------------------
void WalkingState::StateEnter (Character *chara)
{
	if (!chara->IsStaticType())
	{
		chara->PlayAnimByName("walk");
	}
}
//----------------------------------------------------------------------------
void WalkingState::StateExit (Character *chara)
{
	PX2_UNUSED(chara);
}
//----------------------------------------------------------------------------