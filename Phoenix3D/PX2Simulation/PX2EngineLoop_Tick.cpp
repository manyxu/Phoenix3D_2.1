// PX2EngineLoop_Tick.cpp

#include "PX2EngineLoop.hpp"
#include "PX2Project.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void EngineLoop::Tick()
{
	mAppTime = GetTimeInSeconds();
	mElapsedTime = GetElapsedTime();
	mLastAppTime = mAppTime;

	Project *proj = Project::GetSingletonPtr();
	if (!proj) return;

	mUIManager->Update(mAppTime, mElapsedTime);

	PX2_GR.ComputeVisibleSet();

	Renderer *defaultRenderer = Renderer::GetDefaultRenderer();
	if (defaultRenderer->PreDraw())
	{
		defaultRenderer->SetClearColor(proj->GetBackgroundColor());
		defaultRenderer->InitRenderStates();
		defaultRenderer->ClearBuffers();

		PX2_GR.Draw();

		defaultRenderer->PostDraw();
		defaultRenderer->DisplayColorBuffer();
	}
}
//----------------------------------------------------------------------------