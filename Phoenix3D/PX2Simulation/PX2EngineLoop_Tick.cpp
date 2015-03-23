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

	if (mEventWorld)
		mEventWorld->Update((float)mElapsedTime);

	PX2_RM.Update(mAppTime, mElapsedTime);
	PX2_FM.Update();

	Project *proj = Project::GetSingletonPtr();

	PX2_GR.Update(mAppTime, mElapsedTime);

	if (mIsInBackground) return;

	PX2_GR.ComputeVisibleSetAndEnv();

	Renderer *defaultRenderer = Renderer::GetDefaultRenderer();
	if (defaultRenderer && defaultRenderer->PreDraw())
	{
		defaultRenderer->SetViewport(Rectf(0.0f, 0.0f, mScreenSize.Width, mScreenSize.Height));
        if (proj) defaultRenderer->SetClearColor(proj->GetBackgroundColor());
		defaultRenderer->ClearBuffers();

		if (proj)
		{
			defaultRenderer->SetViewport(mAdjustViewPort);
			defaultRenderer->SetClearColor(proj->GetProjBackgroundColor());
			defaultRenderer->ClearBuffers();
		}

		PX2_GR.Draw();

		defaultRenderer->PostDraw();
		defaultRenderer->DisplayColorBuffer();
	}
}
//----------------------------------------------------------------------------