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
void MovementState::Update (Character *b, double appSeconds,
	double elapsedSeconds)
{
	PX2_UNUSED(b);
	PX2_UNUSED(appSeconds);
	PX2_UNUSED(elapsedSeconds);
}
//----------------------------------------------------------------------------
void MovementState::StateEnter (Character *b)
{
	PX2_UNUSED(b);
}
//----------------------------------------------------------------------------
void MovementState::StateExit (Character *b)
{
	PX2_UNUSED(b);
}
//----------------------------------------------------------------------------