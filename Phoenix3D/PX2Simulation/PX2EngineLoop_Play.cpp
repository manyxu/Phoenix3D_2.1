// PX2EngineLoop_Play.cpp

#include "PX2EngineLoop.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2Project.hpp"
#include "PX2GraphicsRoot.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void EngineLoop::Play(EngineLoop::PlayType type)
{
	PX2_GR.SetPlayType((GraphicsRoot::PlayType)type);

	mPlayType = type;

	_SetDoAdjustScreenViewRect(PT_PLAY == type);

	if (!Project::GetSingletonPtr()) return;

	if (!PX2_GR.IsInEditor())
	{
		std::string callFilename;
		if (PT_PLAY == type)
		{
			callFilename = "Data/" + mProjectName + "/scripts/start.lua";
		}
		else
		{
			callFilename = "Data/" + mProjectName + "/scripts/end.lua";
		}

		PX2_SM.CallFile(callFilename.c_str());
	}
}
//----------------------------------------------------------------------------