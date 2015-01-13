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
void GamePlayApp::CreateProject ()
{
	if (mIsProjectCreated)
		return;

	//PX2_LOG_INFO("Begin CreateProject.");

	//mWireProperty = new0 WireProperty();
	//mWireProperty->Enabled = true;
	//mCullProperty = new0 CullProperty();
	//mCullProperty->Enabled = false;
	//mDepthProperty = new DepthProperty();

	//// clear color
	//mClearColor =  Project::GetSingleton().GetColor();
	//mRenderer->SetClearColor(mClearColor);

	//// load scene
	//PX2_LOG_INFO("Begin load scene.");
	//std::string scenePath = Project::GetSingleton().GetSceneFilename();
	//PX2_LOG_INFO("scenePath is %s", scenePath.c_str());
	//if ("" != scenePath)
	//{
	//	ObjectPtr sceneObj = 0;
	//	sceneObj = ResourceManager::GetSingleton().BlockLoad(scenePath);

	//	Scene *scene = DynamicCast<Scene>(sceneObj);
	//	if (scene)
	//	{
	//		Camera *cam = scene->GetCameraActor()->GetCamera();
	//		mRenderer->SetCamera(cam);
	//		GraphicsRoot::GetSingleton().SetCamera(cam);
	//		scene->GetCuller().SetCamera(cam);
	//		scene->ShowHelpMovables(false);
	//		Project::GetSingleton().SetScene(scene);

	//		PX2_LOG_INFO("Load scene successful.");
	//	}
	//	else
	//	{
	//		PX2_LOG_INFO("Load scene failed.");
	//	}
	//}
	//PX2_LOG_INFO("End load scene.");

	//// ui
	//PX2_LOG_INFO("Begin load UI.");
	//std::string uiPath = Project::GetSingleton().GetUIFilename();
	//PX2_LOG_INFO("uiPath is %s: ", uiPath.c_str());
	//if ("" != uiPath)
	//{
	//	ObjectPtr uiObj = 0;
	//	uiObj = ResourceManager::GetSingleton().BlockLoad(uiPath);

	//	UIFrame *ui = DynamicCast<UIFrame>(uiObj);
	//	if (ui)
	//	{
	//		Project::GetSingleton().SetUI(ui);

	//		PX2_LOG_INFO("Load ui successful.");
	//	}
	//	else
	//	{
	//		PX2_LOG_INFO("Load ui failed.");
	//	}
	//}
	//PX2_LOG_INFO("End load UI.");

	//PX2_SM.CallFile("Data/scripts/onCreateProject.lua");

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

	//PX2_LOG_INFO("Begin DestoryProject.");

	//PX2_SM.CallFile("Data/scripts/onDestoryProject.lua");

	//mWireProperty = 0;
	//mCullProperty = 0;
	//mDepthProperty = 0;

	//Project::GetSingleton().ClearCallbacks();
	//Project::GetSingleton().SetScene(0);
	//Project::GetSingleton().SetUI(0);

	mIsProjectCreated = false;

	PX2_LOG_INFO("End DestoryProject.");
}
//----------------------------------------------------------------------------