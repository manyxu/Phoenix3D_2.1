/*
*
* ÎÄ¼þÃû³Æ	£º	PX2RunningState.cpp
*
*/

#include "PX2RunningState.hpp"
#include "PX2Character.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
RunningState::RunningState ()
{
}
//----------------------------------------------------------------------------
RunningState::~RunningState ()
{
}
//----------------------------------------------------------------------------
void RunningState::Update (Character *chara, double appSeconds,
	double elapsedSeconds)
{
	PX2_UNUSED(chara);
	PX2_UNUSED(appSeconds);
	PX2_UNUSED(elapsedSeconds);
}
//----------------------------------------------------------------------------
void RunningState::StateEnter (Character *chara)
{
	if (!chara->IsStaticType())
	{
		chara->PlayAnimByName("run");
	}
}
//----------------------------------------------------------------------------
void RunningState::StateExit (Character *chara)
{
	PX2_UNUSED(chara);
}
//----------------------------------------------------------------------------