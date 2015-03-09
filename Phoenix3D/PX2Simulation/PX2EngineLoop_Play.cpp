// PX2EngineLoop_Play.cpp

#include "PX2EngineLoop.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2Project.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void EngineLoop::Play(EngineLoop::PlayType type)
{
	mPlayType = type;

	_SetDoAdjustScreenViewRect(PT_PLAY == type);

	std::string startFilename = "Data/" + mProjectName + "/scripts/start.lua";
	PX2_SM.CallFile(startFilename.c_str());
}
//----------------------------------------------------------------------------