// PX2EngineLoop_Tick.cpp

#include "PX2EngineLoop.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void EngineLoop::Tick()
{
	mAppTime = GetTimeInSeconds();
	mElapsedTime = GetElapsedTime();

	mLastAppTime = mAppTime;

	Renderer *defaultRenderer = Renderer::GetDefaultRenderer();
	if (defaultRenderer->PreDraw())
	{
		defaultRenderer->InitRenderStates();
		defaultRenderer->ClearBuffers();

		// scene
		//if (scene)
		//{
		//	mRenderer->SetCamera(scene->GetCameraActor()->GetCamera());
		//	PX2_GR.SetRenderViewPort(mRenderer, true, &projSize, &scene->GetViewport());
		//	mRenderer->Draw(scene->GetCuller().GetVisibleSet().Sort());
		//}

		//// ui
		//if (uiView && proj->IsShowUI())
		//{
		//	mRenderer->InitRenderStates();
		//	mRenderer->ClearDepthBuffer();

		//	CameraPtr beforeCam = mRenderer->GetCamera();

		//	mRenderer->SetCamera(uiView->GetCamera());
		//	uiView->CallRendererSetViewport ();
		//	mRenderer->Draw(uiView->GetCuller().GetVisibleSet().Sort());
		//	if (proj->IsShowProjectInfo())
		//	{				
		//		DrawInfo(uiView->GetCamera());
		//	}

		//	mRenderer->SetCamera(beforeCam);
		//}

		defaultRenderer->PostDraw();
		defaultRenderer->DisplayColorBuffer();
	}
}
//----------------------------------------------------------------------------