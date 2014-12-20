/*
*
* ÎÄ¼þÃû³Æ	£º	PX2ActionState.cpp
*
*/

#include "PX2ActionState.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
ActionState::ActionState ()
{
}
//----------------------------------------------------------------------------
ActionState::~ActionState ()
{
}
//----------------------------------------------------------------------------
void ActionState::Update (Character *chara, double appSeconds,
	double elapsedSeconds)
{
	PX2_UNUSED(chara);
	PX2_UNUSED(appSeconds);
	PX2_UNUSED(elapsedSeconds);
}
//----------------------------------------------------------------------------
void ActionState::StateEnter (Character *chara)
{
	PX2_UNUSED(chara);
}
//----------------------------------------------------------------------------
void ActionState::StateExit (Character *chara)
{
	PX2_UNUSED(chara);
}
//----------------------------------------------------------------------------