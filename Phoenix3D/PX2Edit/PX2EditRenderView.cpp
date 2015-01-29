// PX2EditRenderView.cpp

#include "PX2EditRenderView.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2Project.hpp"
#include "PX2Renderer.hpp"
#include "PX2Texture.hpp"
#include "PX2EngineLoop.hpp"
#include "PX2RendererInput.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
EditRenderView::EditRenderView() :
mPt_Data(0),
mRendererInput(0),
mRenderer(0),
mIsLeftDown(false),
mIsRightDown(false),
mIsMiddleDown(false),
mIsRenderCreated(false)
{
}
//----------------------------------------------------------------------------
bool EditRenderView::InitlizeRendererStep()
{
	mRenderer = PX2_ENGINELOOP.CreateRenderer(mPt_Data, (int)mPt_Size.Width,
		(int)mPt_Size.Height, 0, mRendererInput);

	mSize = mPt_Size;

	mRenderStep = new0 RenderStep();

	SetRenderer(mRenderer);

	mRenderStep->SetRect(Rectf(0.0f, 0.0f, mSize.Width, mSize.Height));

	mIsRenderCreated = true;

	return true;
}
//----------------------------------------------------------------------------
EditRenderView::~EditRenderView()
{
	if (mRenderStep)
	{
		PX2_GR.RemoveRenderStep(mRenderStep);
		mRenderStep = 0;
	}

	if (mRenderStepCtrl)
	{
		PX2_GR.RemoveRenderStep(mRenderStepCtrl);
		mRenderStepCtrl = 0;
	}

	if (mRenderStepCtrl1)
	{
		PX2_GR.RemoveRenderStep(mRenderStepCtrl1);
		mRenderStepCtrl1 = 0;
	}

	if (mIsRenderCreated && mRenderer)
	{
		delete0(mRenderer);
		mRenderer = 0;

		mRendererInput->Ternamate();
		delete0(mRendererInput);
		mRendererInput = 0;
	}
}
//----------------------------------------------------------------------------
void EditRenderView::SetPt_Data(void *data)
{
	mPt_Data = data;
}
//----------------------------------------------------------------------------
void *EditRenderView::GetPt_Data()
{
	return mPt_Data;
}
//----------------------------------------------------------------------------
void EditRenderView::SetPt_Size(const Sizef &size)
{
	mPt_Size = size;
}
//----------------------------------------------------------------------------
const Sizef &EditRenderView::GetPt_Size() const
{
	return mPt_Size;
}
//----------------------------------------------------------------------------
void EditRenderView::SetRenderer(Renderer *renderer)
{
	mRenderer = renderer;

	if (mRenderStep)
		mRenderStep->SetRenderer(renderer);

	if (mRenderStepCtrl)
		mRenderStepCtrl->SetRenderer(renderer);

	if (mRenderStepCtrl1)
		mRenderStepCtrl1->SetRenderer(renderer);
}
//----------------------------------------------------------------------------
void EditRenderView::SetCamera(Camera *camera)
{
	if (mRenderStep)
		mRenderStep->SetCamera(camera);

	if (mRenderStepCtrl)
		mRenderStepCtrl->SetCamera(camera);
	
	if (mRenderStepCtrl1)
		mRenderStepCtrl1->SetCamera(camera);
}
//----------------------------------------------------------------------------
RenderStep *EditRenderView::GetRenderStepCtrl()
{
	return mRenderStepCtrl;
}
//----------------------------------------------------------------------------
RenderStep *EditRenderView::GetRenderStepCtrl1()
{
	return mRenderStepCtrl1;
}
//----------------------------------------------------------------------------
void EditRenderView::Draw()
{
	if (mRenderStep && mIsRenderCreated)
	{
		Renderer *renderer = mRenderStep->GetRenderer();
		if (renderer && renderer->PreDraw())
		{
			renderer->InitRenderStates();
			renderer->ClearBuffers();



			renderer->PostDraw();
			renderer->DisplayColorBuffer();
		}
	}
}
//----------------------------------------------------------------------------
void EditRenderView::OnSize(const Sizef& size)
{
	mSize = size;

	Project *proj = Project::GetSingletonPtr();
	if (!proj) return;

	Rectf rect = Rectf(0.0f, 0.0f, mSize.Width, mSize.Height);

	RenderStep *renderStep = proj->GetSceneRenderStep();
	renderStep->SetRect(rect);

	if (mRenderStep)
		mRenderStep->SetRect(rect);

	if (mRenderStepCtrl)
		mRenderStepCtrl->SetRect(rect);

	if (mRenderStepCtrl1)
		mRenderStepCtrl1->SetRect(rect);
}
//----------------------------------------------------------------------------
void EditRenderView::OnLeftDown(const APoint &pos)
{
	mIsLeftDown = true;

	if (mRenderStepCtrl)
		mPixelToWorld = mRenderStepCtrl->CalPixelToWorld();

	PX2_UNUSED(pos);
}
//----------------------------------------------------------------------------
void EditRenderView::OnLeftUp(const APoint &pos)
{
	mIsLeftDown = false;

	PX2_UNUSED(pos);
}
//----------------------------------------------------------------------------
void EditRenderView::OnMiddleDown(const APoint &pos)
{
	mIsMiddleDown = true;

	if (mRenderStepCtrl)
		mPixelToWorld = mRenderStepCtrl->CalPixelToWorld();

	PX2_UNUSED(pos);
}
//----------------------------------------------------------------------------
void EditRenderView::OnMiddleUp(const APoint &pos)
{
	mIsMiddleDown = false;

	PX2_UNUSED(pos);
}
//----------------------------------------------------------------------------
void EditRenderView::OnMouseWheel(float delta)
{
	PX2_UNUSED(delta);
}
//----------------------------------------------------------------------------
void EditRenderView::OnRightDown(const APoint &pos)
{
	mIsRightDown = true;

	if (mRenderStepCtrl)
		mPixelToWorld = mRenderStepCtrl->CalPixelToWorld();

	PX2_UNUSED(pos);
}
//----------------------------------------------------------------------------
void EditRenderView::OnRightUp(const APoint &pos)
{
	mIsRightDown = false;

	PX2_UNUSED(pos);
}
//----------------------------------------------------------------------------
void EditRenderView::OnMotion(const APoint &pos)
{
	APoint curPos = pos;
	APoint lastPos = mLastMousePoint;
	AVector delta = curPos - lastPos;
	mLastMousePoint = curPos;

	if (delta == AVector::ZERO) return;
}
//----------------------------------------------------------------------------