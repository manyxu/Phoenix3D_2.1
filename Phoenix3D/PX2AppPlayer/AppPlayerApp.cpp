// AppPlayerApp.cpp

#include "AppPlayerApp.hpp"
#include "PX2Renderer.hpp"
#include "PX2EngineLoop.hpp"

PX2_IMPLEMENT_APPLICATION(AppPlayerApp)
//----------------------------------------------------------------------------
AppPlayerApp::AppPlayerApp ()
{
	mWindowTitle = "AppPlayer";
	mWindowTitle += Renderer::GetRenderTag();

#if defined(_WIN64) || defined(WIN64)
	mWindowTitle += "64";
#endif

#ifdef _DEBUG
	mWindowTitle += "D";
#endif
}
//----------------------------------------------------------------------------
AppPlayerApp::~AppPlayerApp ()
{
	// 所有内存释放,必须在析构函数之前释放
}
//----------------------------------------------------------------------------
bool AppPlayerApp::Initlize()
{
	if (Application::Initlize())
	{
		std::string projectName = PX2_ENGINELOOP.GetProjectName();
		std::string projectPath = "Data/" + projectName + "/" + projectName 
			+ ".px2proj";

		// Load Project
		_LoadProject(projectPath);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------