// PX2EditRenderView.cpp

#include "PX2EditRenderView.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2Project.hpp"
#include "PX2Renderer.hpp"
#include "PX2Texture.hpp"
#include "PX2EngineLoop.hpp"
#include "PX2RendererInput.hpp"
#include "PX2InputEvent.hpp"
#include "PX2InputEventData.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
EditRenderView::EditRenderView(int renderViewID) :
mRenderViewID(renderViewID),
mPt_Data(0),
mRendererInput(0),
mRenderer(0),
mIsEnable(true),
mIsShow(true),
mIsLeftDown(false),
mIsRightDown(false),
mIsMiddleDown(false),
mIsRenderCreated(false)
{
	PX2_EW.ComeIn(this);
}
//----------------------------------------------------------------------------
bool EditRenderView::InitlizeRendererStep(const std::string &name)
{
	mRenderer = Renderer::CreateRenderer(mPt_Data, (int)mPt_Size.Width,
		(int)mPt_Size.Height, 0, mRendererInput);
	mRenderer->SetClearColor(Float4::WHITE);

	mSize = mPt_Size;

	mRenderStep = new0 RenderStep();
	mRenderStep->SetName(name);

	SetRenderer(mRenderer);

	mRenderStep->SetSize(mSize);

	mIsRenderCreated = true;
	
	return true;
}
//----------------------------------------------------------------------------
bool EditRenderView::IsRenderStepCreated() const
{
	return mIsRenderCreated;
}
//----------------------------------------------------------------------------
EditRenderView::~EditRenderView()
{
	PX2_EW.GoOut(this);

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
void EditRenderView::SetRenderStep(RenderStep *rs)
{
	mRenderStep = rs;
}
//----------------------------------------------------------------------------
RenderStep *EditRenderView::GetRenderStep()
{
	return mRenderStep;
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
void EditRenderView::Tick(double elapsedTime)
{
	//if (!IsEnable()) return;

	if (mRenderStep && mIsRenderCreated)
	{
		double tiemInSeconds = Time::GetTimeInSeconds();

		mRenderStep->Update(tiemInSeconds, elapsedTime);

		mRenderStep->ComputeVisibleSetAndEnv();

		Renderer *renderer = mRenderStep->GetRenderer();
		if (renderer && renderer->PreDraw())
		{
			renderer->InitRenderStates();
			renderer->ClearBuffers();

			mRenderStep->Draw();

			renderer->PostDraw();
			renderer->DisplayColorBuffer();
		}
	}
}
//----------------------------------------------------------------------------
void EditRenderView::Enable(bool enable)
{
	mIsEnable = enable;

	if (mRenderStep)
	{
		mRenderStep->Enable(enable);
	}

	if (mRenderStepCtrl)
	{
		mRenderStepCtrl->Enable(enable);
	}

	if (mRenderStepCtrl1)
	{
		mRenderStepCtrl1->Enable(enable);
	}
}
//----------------------------------------------------------------------------
bool EditRenderView::IsEnable() const
{
	return mIsEnable;
}
//----------------------------------------------------------------------------
void EditRenderView::Show(bool show)
{
	mIsShow = show;

	if (mRenderStep)
	{
		mRenderStep->Show(show);
	}

	if (mRenderStepCtrl)
	{
		mRenderStepCtrl->Show(show);
	}

	if (mRenderStepCtrl1)
	{
		mRenderStepCtrl1->Show(show);
	}
}
//----------------------------------------------------------------------------
bool EditRenderView::IsShow() const
{
	return mIsShow;
}
//----------------------------------------------------------------------------
void EditRenderView::OnSize(const Sizef& size)
{
	mSize = size;

	if (mRenderStep)
		mRenderStep->SetSize(mSize);

	if (mRenderStepCtrl)
		mRenderStepCtrl->SetSize(mSize);

	if (mRenderStepCtrl1)
		mRenderStepCtrl1->SetSize(mSize);
}
//----------------------------------------------------------------------------
void EditRenderView::OnLeftDown(const APoint &pos)
{
	mIsLeftDown = true;
	mLastMousePoint = pos;

	if (mRenderStepCtrl)
		mPixelToWorld = mRenderStepCtrl->CalPixelToWorld();
}
//----------------------------------------------------------------------------
void EditRenderView::OnLeftUp(const APoint &pos)
{
	mIsLeftDown = false;
	mLastMousePoint = pos;
}
//----------------------------------------------------------------------------
void EditRenderView::OnLeftDClick(const APoint &pos)
{
	mLastMousePoint = pos;
}
//----------------------------------------------------------------------------
void EditRenderView::OnMiddleDown(const APoint &pos)
{
	mIsMiddleDown = true;
	mLastMousePoint = pos;

	if (mRenderStepCtrl)
		mPixelToWorld = mRenderStepCtrl->CalPixelToWorld();
}
//----------------------------------------------------------------------------
void EditRenderView::OnMiddleUp(const APoint &pos)
{
	mIsMiddleDown = false;
	mLastMousePoint = pos;
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
	mLastMousePoint = pos;

	if (mRenderStepCtrl)
		mPixelToWorld = mRenderStepCtrl->CalPixelToWorld();
}
//----------------------------------------------------------------------------
void EditRenderView::OnRightUp(const APoint &pos)
{
	mIsRightDown = false;
	mLastMousePoint = pos;
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
void EditRenderView::DoExecute(Event *event)
{
	if (!IsEnable()) return;

	if (InputEventSpace::IsEqual(event, InputEventSpace::MousePressed))
	{
		InputEventData data = event->GetData<InputEventData>();

		if (data.ViewID == mRenderViewID)
		{
			if (MBID_LEFT == data.MButtonID)
				OnLeftDown(data.MTPos);
			else if (MBID_RIGHT == data.MButtonID)
				OnRightDown(data.MTPos);
			else if (MBID_MIDDLE == data.MButtonID)
				OnMiddleDown(data.MTPos);
		}
	}
	else if (InputEventSpace::IsEqual(event, InputEventSpace::MouseReleased))
	{
		InputEventData data = event->GetData<InputEventData>();

		if (data.ViewID == mRenderViewID)
		{
			if (MBID_LEFT == data.MButtonID)
				OnLeftUp(data.MTPos);
			else if (MBID_RIGHT == data.MButtonID)
				OnRightUp(data.MTPos);
			else if (MBID_MIDDLE == data.MButtonID)
				OnMiddleUp(data.MTPos);
		}
	}
	else if (InputEventSpace::IsEqual(event, InputEventSpace::MouseDoublePressed))
	{
		InputEventData data = event->GetData<InputEventData>();

		if (data.ViewID == mRenderViewID)
		{
			if (MBID_LEFT == data.MButtonID)
				OnLeftDClick(data.MTPos);
		}
	}
	else if (InputEventSpace::IsEqual(event, InputEventSpace::MouseMoved))
	{
		InputEventData data = event->GetData<InputEventData>();

		if (data.ViewID == mRenderViewID)
		{
			OnMotion(data.MTPos);
		}
	}
	else if (InputEventSpace::IsEqual(event, InputEventSpace::MouseWheeled))
	{
		InputEventData data = event->GetData<InputEventData>();
		
		if (data.ViewID == mRenderViewID)
		{
			OnMouseWheel(data.MWheel);
		}
	}
}
//----------------------------------------------------------------------------