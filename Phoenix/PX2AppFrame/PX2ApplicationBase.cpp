/*
*
* ÎÄ¼þÃû³Æ	£º	PX2ApplicationBase.cpp
*
*/

#include "PX2ApplicationBase.hpp"
#include "PX2EngineLoop.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
bool ApplicationBase::msIsInitlized = false;
ApplicationBase::AppInitlizeFun ApplicationBase::msAppInitlizeFun = 0;
ApplicationBase::AppTernamateFun ApplicationBase::msAppTernamateFun = 0;
ApplicationBase* ApplicationBase::msApplication = 0;
ApplicationBase::EntryPoint ApplicationBase::msEntry = 0;
//----------------------------------------------------------------------------
ApplicationBase::ApplicationBase() :
mXPosition(0),
mYPosition(0),
mWidth(800),
mHeight(600),
mAllowResize(true),
mInitScreenWidth(960.0f),
mInitScreenHeight(640.0f),
mScreenSuitType(AST_960X640)
{
	mWindowTitle = "Application";
}
//----------------------------------------------------------------------------
ApplicationBase::~ApplicationBase ()
{
}
//----------------------------------------------------------------------------
bool ApplicationBase::IsInitlized ()
{
	return msIsInitlized;
}
//----------------------------------------------------------------------------
void ApplicationBase::SetInitScreenWidthHeight (float width, float height)
{
	//mInitScreenWidth = width;
	//mInitScreenHeight = height;

	//if (width > height)
	//{
	//	float widthAdjuge = 640.0f * mInitScreenWidth/mInitScreenHeight;
	//	if (Mathf::FAbs(1136.0f-widthAdjuge) < Mathf::FAbs(960.0f-widthAdjuge))
	//	{
	//		mScreenSuitType = AST_1136X640;
	//	}
	//	else
	//	{
	//		mScreenSuitType = AST_960X640;
	//	}
	//}
	//else
	//{
	//	float heightAdjuge = 640.0f * mInitScreenHeight/mInitScreenWidth;
	//	if (Mathf::FAbs(1136.0f-heightAdjuge) < Mathf::FAbs(960.0f-heightAdjuge))
	//	{
	//		mScreenSuitType = AST_640X1136;
	//	}
	//	else
	//	{
	//		mScreenSuitType = AST_640X960;
	//	}
	//}
}
//----------------------------------------------------------------------------
int ApplicationBase::GetProjSuitType () const
{
	return mScreenSuitType;
}
//----------------------------------------------------------------------------
bool ApplicationBase::Initlize ()
{
	if (msIsInitlized)
		return true;

	PX2_ENGINELOOP.Initlize();

	msIsInitlized = true;

	return true;
}
//----------------------------------------------------------------------------
int ApplicationBase::GetWidth ()
{
	return mWidth;
}
//----------------------------------------------------------------------------
int ApplicationBase::GetHeight ()
{
	return mHeight;
}
//----------------------------------------------------------------------------
bool ApplicationBase::OnIdle ()
{
	PX2_ENGINELOOP.Tick();

	return true;
}
//----------------------------------------------------------------------------
bool ApplicationBase::Ternamate ()
{
	//mInfoFrame = 0;
	//mBackPic = 0;
	//mFrameText = 0;
	//mCurTotalMemory = 0;
	//mMaxTotalMemory = 0;
	//mDebugText = 0;

	PX2_ENGINELOOP.Ternamate();

	return true;
}
//----------------------------------------------------------------------------
void ApplicationBase::OnSize (int width, int height)
{
	//if (!mProject)
	//	return;

	//mWidth = width;
	//mHeight = height;
	//float projWidth = mProject->GetWidth();
	//float projHeight = mProject->GetHeight();

	//Sizef sz((float)mWidth, (float)mHeight);
	//Rectf rect = GameManager::GetSingleton().CalGameViewRect((float)mWidth, (float)mHeight);
	//mRoot->SetSize(sz);
	//mRoot->SetRect(rect);	
	//mInputEventAdapter->SetRect(rect);
	//mInputEventAdapter->GetInputManager()->SetSize(sz);

	//if (mRenderer) mRenderer->ResizeWindow(mWidth, mHeight);

	//OnProjectSize(projWidth, projHeight);
}
//----------------------------------------------------------------------------
void ApplicationBase::WillEnterForeground(bool isFirstTime)
{
	PX2_ENGINELOOP.WillEnterForeground(isFirstTime);
}
//----------------------------------------------------------------------------
void ApplicationBase::DidEnterBackground ()
{
	PX2_ENGINELOOP.DidEnterBackground();
}
//----------------------------------------------------------------------------
int ApplicationBase::Main (int numArguments, char** arguments)
{
	PX2_UNUSED(numArguments);
	PX2_UNUSED(arguments);
	return 1;
}
//----------------------------------------------------------------------------
