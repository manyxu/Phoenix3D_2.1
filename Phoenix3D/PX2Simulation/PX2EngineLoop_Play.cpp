// PX2EngineLoop_Play.cpp

#include "PX2EngineLoop.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void EngineLoop::Play(EngineLoop::PlayType type)
{
	mPlayType = type;

	_SetDoAdjustScreen(PT_PLAY == type);
}
//----------------------------------------------------------------------------