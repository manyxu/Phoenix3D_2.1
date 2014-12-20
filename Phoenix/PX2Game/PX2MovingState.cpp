/*
*
* ÎÄ¼þÃû³Æ	£º	PX2MovingState.cpp
*
*/

#include "PX2MovingState.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
MovingState::MovingState ()
{
}
//----------------------------------------------------------------------------
MovingState::~MovingState ()
{
}
//----------------------------------------------------------------------------
void MovingState::Update (Character *chara, double appSeconds,
	double elapsedSeconds)
{
	PX2_UNUSED(chara);
	PX2_UNUSED(appSeconds);
	PX2_UNUSED(elapsedSeconds);
}
//----------------------------------------------------------------------------
void MovingState::StateEnter (Character *chara)
{
	PX2_UNUSED(chara);
}
//----------------------------------------------------------------------------
void MovingState::StateExit (Character *chara)
{
	PX2_UNUSED(chara);
}
//----------------------------------------------------------------------------