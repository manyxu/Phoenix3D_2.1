/*
*
* Filename	:	GamePlayApp.cpp
*
*/

#include "GamePlayApp.hpp"

PX2_IMPLEMENT_APPLICATION(GamePlayApp)
//----------------------------------------------------------------------------
GamePlayApp::GamePlayApp ()
{
#ifdef _DEBUG
	#if defined(_WIN64) || defined(WIN64)
		mWindowTitle = "GamePlayApp64D";
	#else
		mWindowTitle = "GamePlayAppD";
	#endif
#else
	#if defined(_WIN64) || defined(WIN64)
		mWindowTitle = "GamePlayApp64";
	#else
		mWindowTitle = "GamePlayApp";
	#endif
#endif

	mIsProjectCreated = false;
}
//----------------------------------------------------------------------------
GamePlayApp::~GamePlayApp ()
{
	// 所有内存释放,必须在析构函数之前释放
}
//----------------------------------------------------------------------------
bool GamePlayApp::OnInitlize ()
{
	Application::OnInitlize();

	return true;
}
//----------------------------------------------------------------------------
bool GamePlayApp::OnTernamate ()
{
	DestoryProject();

	return true;
}
//----------------------------------------------------------------------------
void GamePlayApp::WillEnterForeground (bool isFirstTime)
{
	PX2_LOG_INFO("WillEnterForeground");

	Application::WillEnterForeground(isFirstTime);

	if (isFirstTime)
	{
		CreateProject();
	}
}
//----------------------------------------------------------------------------
void GamePlayApp::DidEnterBackground ()
{
	PX2_LOG_INFO("DidEnterBackground");

	//DestoryProject();

	Application::DidEnterBackground();
}
//----------------------------------------------------------------------------
bool GamePlayApp::OnResume()
{
	Application::OnResume();
	return true;
}
//----------------------------------------------------------------------------
bool GamePlayApp::OnPause()
{
	Application::OnPause();
	return true;
}
//----------------------------------------------------------------------------
void GamePlayApp::DoEnter ()
{
}
//----------------------------------------------------------------------------
void GamePlayApp::DoExecute (Event *event)
{
	Project *proj = Project::GetSingletonPtr();
	if (!proj)
		return;

	Scene *scene = proj->GetScene();
	if (!scene)
		return;

	Scene3D *scene3D = DynamicCast<Scene3D>(scene);
	if (!scene3D)
		return;

	if (InputEventSpace::IsEqual(event, InputEventSpace::TouchPressed))
	{
		InputEventData data = event->GetData<InputEventData>();

		float absX = (float)data.TState.X.Absoulate;
		float absY = (float)data.TState.Y.Absoulate;
		mTouchPos[0] = absX;
		mTouchPos[1] = absY;
	}
	else if (InputEventSpace::IsEqual(event, InputEventSpace::TouchReleased))
	{
		InputEventData data = event->GetData<InputEventData>();

		float absX = (float)data.TState.X.Absoulate;
		float absY = (float)data.TState.Y.Absoulate;
		mTouchPos[0] = absX;
		mTouchPos[1] = absY;
	}
	else if (InputEventSpace::IsEqual(event, InputEventSpace::TouchMoved))
	{
		InputEventData data = event->GetData<InputEventData>();

		float absX = (float)data.TState.X.Absoulate;
		float absY = (float)data.TState.Y.Absoulate;

		mTouchPos[0] = absX;
		mTouchPos[1] = absY;
	}
}
//----------------------------------------------------------------------------
void GamePlayApp::DoLeave ()
{

}
//----------------------------------------------------------------------------
bool GamePlayApp::OnIdle ()
{
	bool odle = Application::OnIdle();
	if (!odle)
		return false;

	if (IsIsInBackground())
		return false;

	if (!mIsProjectCreated)
		return false;

	Project *proj = Project::GetSingletonPtr();
	if (!proj)
		return false;

	const Sizef &projSize = proj->GetSize();
	Scene *scene = proj->GetScene();

	UIView *uiView = PX2_UIM.GetDefaultView();

	if (mRenderer->PreDraw())
	{
		mRenderer->SetViewport(0, 0, mWidth, mHeight);
		
		mRenderer->InitRenderStates();
		mRenderer->ClearBuffers();

		// scene
		if (scene)
		{
			mRenderer->SetCamera(scene->GetCameraActor()->GetCamera());
			PX2_GR.SetRenderViewPort(mRenderer, true, &projSize, &scene->GetViewport());
			mRenderer->Draw(scene->GetCuller().GetVisibleSet().Sort());
		}

		// ui
		if (uiView && proj->IsShowUI())
		{
			mRenderer->InitRenderStates();
			mRenderer->ClearDepthBuffer();

			CameraPtr beforeCam = mRenderer->GetCamera();

			mRenderer->SetCamera(uiView->GetCamera());
			uiView->CallRendererSetViewport ();
			mRenderer->Draw(uiView->GetCuller().GetVisibleSet().Sort());
			if (proj->IsShowProjectInfo())
			{				
				DrawInfo(uiView->GetCamera());
			}

			mRenderer->SetCamera(beforeCam);
		}

		mRenderer->PostDraw();
		mRenderer->DisplayColorBuffer();
	}

	return true;
}
//----------------------------------------------------------------------------
void GamePlayApp::CreateProject ()
{
	if (mIsProjectCreated)
		return;

	PX2_LOG_INFO("Begin CreateProject.");

	mWireProperty = new0 WireProperty();
	mWireProperty->Enabled = true;
	mCullProperty = new0 CullProperty();
	mCullProperty->Enabled = false;
	mDepthProperty = new DepthProperty();

	// clear color
	mClearColor =  Project::GetSingleton().GetColor();
	mRenderer->SetClearColor(mClearColor);

	// load scene
	PX2_LOG_INFO("Begin load scene.");
	std::string scenePath = Project::GetSingleton().GetSceneFilename();
	PX2_LOG_INFO("scenePath is %s", scenePath.c_str());
	if ("" != scenePath)
	{
		ObjectPtr sceneObj = 0;
		sceneObj = ResourceManager::GetSingleton().BlockLoad(scenePath);

		Scene *scene = DynamicCast<Scene>(sceneObj);
		if (scene)
		{
			Camera *cam = scene->GetCameraActor()->GetCamera();
			mRenderer->SetCamera(cam);
			GraphicsRoot::GetSingleton().SetCamera(cam);
			scene->GetCuller().SetCamera(cam);
			scene->ShowHelpMovables(false);
			Project::GetSingleton().SetScene(scene);

			PX2_LOG_INFO("Load scene successful.");
		}
		else
		{
			PX2_LOG_INFO("Load scene failed.");
		}
	}
	PX2_LOG_INFO("End load scene.");

	// ui
	PX2_LOG_INFO("Begin load UI.");
	std::string uiPath = Project::GetSingleton().GetUIFilename();
	PX2_LOG_INFO("uiPath is %s: ", uiPath.c_str());
	if ("" != uiPath)
	{
		ObjectPtr uiObj = 0;
		uiObj = ResourceManager::GetSingleton().BlockLoad(uiPath);

		UIFrame *ui = DynamicCast<UIFrame>(uiObj);
		if (ui)
		{
			Project::GetSingleton().SetUI(ui);

			PX2_LOG_INFO("Load ui successful.");
		}
		else
		{
			PX2_LOG_INFO("Load ui failed.");
		}
	}
	PX2_LOG_INFO("End load UI.");

	PX2_SM.CallFile("Data/scripts/onCreateProject.lua");

	//CharacterPtr chara = mGameMan->CreateEngineDefaultCharacter();
	//mGameMan->SetMainCharacter(chara);
	//PX2_PROJ.GetScene()->AddActor(chara);
	
	mIsProjectCreated = true;

	PX2_LOG_INFO("End CreateProject.");
}
//----------------------------------------------------------------------------
void GamePlayApp::DestoryProject ()
{
	if (!mIsProjectCreated)
		return;

	PX2_LOG_INFO("Begin DestoryProject.");

	PX2_SM.CallFile("Data/scripts/onDestoryProject.lua");

	mWireProperty = 0;
	mCullProperty = 0;
	mDepthProperty = 0;

	Project::GetSingleton().ClearCallbacks();
	Project::GetSingleton().SetScene(0);
	Project::GetSingleton().SetUI(0);

	mIsProjectCreated = false;

	PX2_LOG_INFO("End DestoryProject.");
}
//----------------------------------------------------------------------------
void GamePlayApp::ZoomCamera (Camera *cam, float zoom)
{
	if (!cam)
		return;

	Vector3f position = cam->GetPosition();
	AVector dir = cam->GetDVector();
	dir.Normalize();

	position += dir*zoom;
	cam->SetPosition(position);
}
//----------------------------------------------------------------------------
void GamePlayApp::MoveCamera (Camera *cam, const float &horz,
	const float &vert)
{
	if (!cam)
		return;

	Vector3f position = cam->GetPosition();
	AVector dVector = cam->GetDVector();
	AVector uVector = cam->GetUVector();
	AVector rVector = cam->GetRVector();

	dVector.Z() = 0.0f;
	dVector.Normalize();
	rVector.Z() = 0.0f;
	rVector.Normalize();
	position += dVector * vert;
	position += rVector * horz;

	cam->SetPosition(position);
}
//----------------------------------------------------------------------------