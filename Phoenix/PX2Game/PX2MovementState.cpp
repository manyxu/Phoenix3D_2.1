/*
*
* ÎÄ¼þÃû³Æ	£º	PX2MovementState.cpp
*
*/

#include "PX2MovementState.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
MovementState::MovementState ()
{
}
//----------------------------------------------------------------------------
MovementState::~MovementState ()
{
}
//----------------------------------------------------------------------------
void MovementState::Update (Character *chara, double appSeconds,
	double elapsedSeconds)
{
	PX2_UNUSED(chara);
	PX2_UNUSED(appSeconds);
	PX2_UNUSED(elapsedSeconds);
}
//----------------------------------------------------------------------------
void MovementState::StateEnter (Character *chara)
{
	PX2_UNUSED(chara);
}
//----------------------------------------------------------------------------
void MovementState::StateExit (Character *chara)
{
	PX2_UNUSED(chara);
}
//----------------------------------------------------------------------------