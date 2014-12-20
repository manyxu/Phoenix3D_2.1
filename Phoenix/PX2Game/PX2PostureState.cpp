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
void PostureState::Update (Character *chara, double appSeconds,
	double elapsedSeconds)
{
	PX2_UNUSED(chara);
	PX2_UNUSED(appSeconds);
	PX2_UNUSED(elapsedSeconds);
}
//----------------------------------------------------------------------------
void PostureState::StateEnter (Character *chara)
{
	PX2_UNUSED(chara);
}
//----------------------------------------------------------------------------
void PostureState::StateExit (Character *chara)
{
	PX2_UNUSED(chara);
}
//----------------------------------------------------------------------------