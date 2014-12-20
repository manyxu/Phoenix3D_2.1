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
void ActionState::Update (Character *b, double appSeconds,
	double elapsedSeconds)
{
	PX2_UNUSED(b);
	PX2_UNUSED(appSeconds);
	PX2_UNUSED(elapsedSeconds);
}
//----------------------------------------------------------------------------
void ActionState::StateEnter (Character *b)
{
	PX2_UNUSED(b);
}
//----------------------------------------------------------------------------
void ActionState::StateExit (Character *b)
{
	PX2_UNUSED(b);
}
//----------------------------------------------------------------------------