/*
*
* ÎÄ¼þÃû³Æ	£º	PX2PostureState.cpp
*
*/

#include "PX2PostureState.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
PostureState::PostureState ()
{
}
//----------------------------------------------------------------------------
PostureState::~PostureState ()
{
}
//----------------------------------------------------------------------------
void PostureState::Update (Character *b, double appSeconds,
	double elapsedSeconds)
{
	PX2_UNUSED(b);
	PX2_UNUSED(appSeconds);
	PX2_UNUSED(elapsedSeconds);
}
//----------------------------------------------------------------------------
void PostureState::StateEnter (Character *b)
{
	PX2_UNUSED(b);
}
//----------------------------------------------------------------------------
void PostureState::StateExit (Character *b)
{
	PX2_UNUSED(b);
}
//----------------------------------------------------------------------------