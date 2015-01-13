/*
*
* ÎÄ¼þÃû³Æ	£º	PX2ApplicationBase.cpp
*
*/

#include "PX2ToLua.hpp"
#include "PX2ApplicationBase.hpp"
#include "PX2LocalDateTime.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
bool ApplicationBase::msIsInitlized = false;
ApplicationBase::AppInitlizeFun ApplicationBase::msAppInitlizeFun = 0;
ApplicationBase::AppTernamateFun ApplicationBase::msAppTernamateFun = 0;
ApplicationBase* ApplicationBase::msApplication = 0;
ApplicationBase::EntryPoint ApplicationBase::msEntry = 0;
//----------------------------------------------------------------------------
ApplicationBase::ApplicationBase() :
mClearColor(Float4(1.0f, 0.0f, 0.0f, 1.0f)),
mColorFormat(Texture::TF_A8R8G8B8),
mRenderer(0),
mDepthStencilFormat(Texture::TF_D24S8),
mNumMultisamples(0),
mXPosition(0),
mYPosition(0),
mWidth(800),
mHeight(600),
mAllowResize(true),
mInitScreenWidth(960.0f),
mInitScreenHeight(640.0f),
mScreenSuitType(AST_960X640),
mFrameRate(0.0f),
mNumFrames(0),
mFrameTime(0.0f),
mUpdateDrawInfo(false)
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
	mInitScreenWidth = width;
	mInitScreenHeight = height;

	if (width > height)
	{
		float widthAdjuge = 640.0f * mInitScreenWidth/mInitScreenHeight;
		if (Mathf::FAbs(1136.0f-widthAdjuge) < Mathf::FAbs(960.0f-widthAdjuge))
		{
			mScreenSuitType = AST_1136X640;
		}
		else
		{
			mScreenSuitType = AST_960X640;
		}
	}
	else
	{
		float heightAdjuge = 640.0f * mInitScreenHeight/mInitScreenWidth;
		if (Mathf::FAbs(1136.0f-heightAdjuge) < Mathf::FAbs(960.0f-heightAdjuge))
		{
			mScreenSuitType = AST_640X1136;
		}
		else
		{
			mScreenSuitType = AST_640X960;
		}
	}
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
void ApplicationBase::DoEnter ()
{
}
//----------------------------------------------------------------------------
void ApplicationBase::DoExecute (Event *event)
{
	PX2_UNUSED(event);
}
//----------------------------------------------------------------------------
void ApplicationBase::DoLeave ()
{
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
void ApplicationBase::CreateInfo ()
{
	//mInfoFrame = new0 UIFrame();

	//mBackPic = new0 UIPicBox();
	//mBackPic->SetAlpha(0.7f);
	//mBackPic->SetSize(1024.0f, 85.0f);
	//mBackPic->SetTexture("Data/engine/whiteRect.png");
	//mBackPic->SetAnchorPoint(Float2(0.0f, 0.0f));
	//mBackPic->LocalTransform.SetTranslate(APoint(0.0f, 1.0f, 0.0f));
	//mInfoFrame->AttachChild(mBackPic);

	//mFrameText = new0 UIStaticText();
	//mFrameText->SetFontScale(0.6f);
	//mFrameText->LocalTransform.SetTranslate(APoint(0.0f, 0.0f, 60.0f));
	//mInfoFrame->AttachChild(mFrameText);

	//mCurTotalMemory = new0 UIStaticText();
	//mCurTotalMemory->SetFontScale(0.6f);
	//mCurTotalMemory->LocalTransform.SetTranslate(APoint(0.0f, 0.0f, 40.0f));
	//mInfoFrame->AttachChild(mCurTotalMemory);

	//mMaxTotalMemory = new0 UIStaticText();
	//mMaxTotalMemory->SetFontScale(0.6f);
	//mMaxTotalMemory->LocalTransform.SetTranslate(APoint(0.0f, 0.0f, 20.0f));
	//mInfoFrame->AttachChild(mMaxTotalMemory);

	//mDebugText = new0 UIStaticText();
	//mDebugText->SetFontScale(0.6f);
	//mDebugText->LocalTransform.SetTranslate(APoint(0.0f, 0.0f, 0.0f));
	//mInfoFrame->AttachChild(mDebugText);

	//Float3 texColor = Float3::BLACK;
	//mFrameText->SetColor(texColor);
	//mCurTotalMemory->SetColor(texColor);
	//mMaxTotalMemory->SetColor(texColor);
	//mDebugText->SetColor(texColor);
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
void ApplicationBase::UpdateDrawInfo (int x, int y)
{
//	if (mInfoFrame)
//	{
//		mInfoFrame->LocalTransform.SetTranslate(APoint((float)x, -100.0f, (float)y));
//	}
//
//	if (mUpdateDrawInfo)
//	{
//		char fpsMsg[256];
//		sprintf(fpsMsg, "FPS: %.1lf", mFrameRate);
//
//		if (mFrameText)
//			mFrameText->SetText(fpsMsg);
//	}
//
//	double toM = 1024.0*1024.0;
//#ifdef PX2_USE_MEMORY
//	double cTB = (double)Memory::GetCurTotalBytes();
//	double mTB = (double)Memory::GetMaxTotalBytes();
//#else
//	double cTB = 0.0;
//	double mTB = 0.0;
//#endif
//	double cTM = cTB/toM;
//	double mTM = mTB/toM;
//
//	if (mUpdateDrawInfo)
//	{
//		char curTotalMemory[256];
//
//		sprintf(curTotalMemory, "CurMemory: %d bytes(%.1lf m).", (int)cTB, (float)cTM);
//
//		if (mCurTotalMemory)
//			mCurTotalMemory->SetText(curTotalMemory);
//	}
//
//	if (mUpdateDrawInfo)
//	{
//		char maxTotalMemory[256];
//		sprintf(maxTotalMemory, "MaxMemory: %d bytes(%.1lf m)", (int)mTB, (float)mTM);
//
//		if (mMaxTotalMemory)
//			mMaxTotalMemory->SetText(maxTotalMemory);
//	}
//
//	if (mUpdateDrawInfo)
//	{
//		Renderer *renderer = Renderer::GetDefaultRenderer();
//		char debugText[256];
//		sprintf(debugText, 
//			"nVF:%d nVB:%d nIB:%d nT2D:%d nVS:%d nPS:%d nMP:%d nGVS:%d nGPS:%d nGMP:%d nDwPe:%d nStp:%d nDet:%d",
//			renderer->GetNumPdrVertexFormat(),
//			renderer->GetNumPdrVertexBuffer(), 
//			renderer->GetNumPdrIndexBuffer(),
//			renderer->GetNumPdrTexture2D(),
//			renderer->GetNumPdrVertexShader(),
//			renderer->GetNumPdrPixelShader(),
//			renderer->GetNumPdrMaterialPass(),
//			renderer->GetNumGPUVertexShader(),
//			renderer->GetNumGPUPixelShader(),
//			renderer->GetNumGPUMaterialPass(),
//			renderer->GetNumDrawPrimitivePerFrame(),
//			PX2_DM.GetNumStopingObjs(),
//			PX2_DM.GetNumDeletingObjs());
//
//		if (mDebugText)
//			mDebugText->SetText(debugText);
//	}
//
	mUpdateDrawInfo = false;
}
//----------------------------------------------------------------------------
void ApplicationBase::DrawInfo (Camera *cam)
{
	//mInfoCuller.SetCamera(cam);
	//mInfoCuller.ComputeVisibleSet(mInfoFrame);

	//mRenderer->Draw(mInfoCuller.GetVisibleSet());
}
//----------------------------------------------------------------------------
