// PX2EditRenderView_PreView.cpp

#include "PX2EditRenderView_PreView.hpp"
#include "PX2Edit.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2StandardMesh.hpp"
#include "PX2VertexColor4Material.hpp"
#include "PX2Project.hpp"
#include "PX2EditEventType.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2InputManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
EditRenderView_PreView::EditRenderView_PreView() :
EditRenderView(4)
{
	// mRenderViewID is 4
	PX2_INPUTMAN.CreateAddListener(mRenderViewID);

	mPicFrame = new0 UIFrame();

	mUIPicBox = new0 UIPicBox();
	mPicFrame->AttachChild(mUIPicBox);

	mUIText = new0 UIText();
	mPicFrame->AttachChild(mUIText);

	mModelNode = new0 Node();
}
//----------------------------------------------------------------------------
EditRenderView_PreView::~EditRenderView_PreView()
{
	if (mRenderStep)
	{
		PX2_GR.RemoveRenderSteps(mRenderStep);
		mRenderStep = 0;
	}

	if (mRenderStepCtrl)
	{
		PX2_GR.RemoveRenderSteps(mRenderStepCtrl);
		mRenderStepCtrl = 0;
	}

	if (mRenderStepCtrl1)
	{
		PX2_GR.RemoveRenderSteps(mRenderStepCtrl1);
		mRenderStepCtrl1 = 0;
	}
}
//----------------------------------------------------------------------------
bool EditRenderView_PreView::InitlizeRendererStep(const std::string &name)
{
	mRenderer = Renderer::CreateRenderer(mPt_Data, (int)mPt_Size.Width,
		(int)mPt_Size.Height, 0, mRendererInput);
	mRenderer->SetClearColor(Float4::MakeColor(64, 64, 64, 255));

	mSize = mPt_Size;

	mUIView = new0 UIView(mRenderViewID);
	mRenderStep = mUIView;
	mRenderStep->SetName(name);

	mRenderer->SetCamera(mUIView->GetCamera());
	SetRenderer(mRenderer);

	mRenderStep->SetSize(mSize);

	mRenderStep->SetNode(mPicFrame);

	mIsRenderCreated = true;

	return true;
}
//----------------------------------------------------------------------------
void EditRenderView_PreView::Tick(double elapsedTime)
{
	if (!IsEnable()) return;

	EditRenderView::Tick(elapsedTime);
}
//----------------------------------------------------------------------------
void EditRenderView_PreView::OnSize(const Sizef& size)
{
	mSize = size;

	EditRenderView::OnSize(size);

	if (mRenderStep)
	{
		mRenderStep->GetRenderer()->ResizeWindow((int)size.Width,
			(int)size.Height);
	}
}
//----------------------------------------------------------------------------
void EditRenderView_PreView::OnLeftDown(const APoint &pos)
{
	EditRenderView::OnLeftDown(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_PreView::OnLeftUp(const APoint &pos)
{
	EditRenderView::OnLeftUp(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_PreView::OnMiddleDown(const APoint &pos)
{
	EditRenderView::OnMiddleDown(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_PreView::OnMiddleUp(const APoint &pos)
{
	EditRenderView::OnMiddleUp(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_PreView::OnMouseWheel(float delta)
{
	PX2_UNUSED(delta);
}
//----------------------------------------------------------------------------
void EditRenderView_PreView::OnRightDown(const APoint &pos)
{
	EditRenderView::OnRightDown(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_PreView::OnRightUp(const APoint &pos)
{
	EditRenderView::OnRightUp(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_PreView::OnMotion(const APoint &pos)
{
	APoint curPos = pos;
	APoint lastPos = mLastMousePoint;
	AVector delta = curPos - lastPos;
	mLastMousePoint = curPos;

	if (delta == AVector::ZERO) return;
}
//----------------------------------------------------------------------------
void EditRenderView_PreView::DoExecute(Event *event)
{
	EditRenderView::DoExecute(event);

	if (EditEventSpace::IsEqual(event, EditEventSpace::SetPreViewObject))
	{
		PX2::Object *obj = event->GetData<PX2::Object*>();
		SetObject(obj);
	}
}
//----------------------------------------------------------------------------
void EditRenderView_PreView::SetObject(PX2::Object *obj)
{
	Texture2D *d2Tex = DynamicCast<Texture2D>(obj);
	Movable *mov = DynamicCast<Movable>(obj);
	if (d2Tex)
	{
		const SelectResData &data = PX2_EDIT.GetSelectedResource();
		SelectResData::SelectResType selectResType = data.GetSelectResType();

		std::string texStr = "";

		if (selectResType == SelectResData::RT_NORMAL)
		{
			mUIPicBox->SetTexture(data.ResPathname);
			mUIPicBox->SetSize(mSize);
			mUIPicBox->LocalTransform.SetTranslate(APoint(mSize.Width / 2.0f, 0.0f, mSize.Height / 2.0f));

			Texture2D *tex2D = DynamicCast<Texture2D>(PX2_RM.BlockLoad(data.ResPathname));
			if (tex2D)
			{
				texStr = "width:" + StringHelp::IntToString((int)tex2D->GetWidth()) + " "
					+ "height:" + StringHelp::IntToString((int)tex2D->GetHeight()) + " ";
			}
		}
		else if (selectResType == SelectResData::RT_TEXPACKELEMENT)
		{
			PX2_RM.AddTexPack(data.ResPathname);
			const TexPackElement &texPackEle = PX2_RM.GetTexPackElement(
				data.ResPathname, data.EleName);
			if (texPackEle.IsValid())
			{
				mUIPicBox->SetTexture(data.ResPathname, data.EleName);
				mUIPicBox->SetSize((float)texPackEle.W, (float)texPackEle.H);
				mUIPicBox->LocalTransform.SetTranslate(APoint(texPackEle.W / 2.0f, 0.0f, texPackEle.H / 2.0f));

				texStr = "width:" + StringHelp::IntToString(texPackEle.W) + " " + "height:" + StringHelp::IntToString(texPackEle.H) + " ";
			}
		}
		mUIText->SetRect(Rectf(0.0f, 0.0f, mSize.Width, mSize.Height));
		mUIText->SetText(texStr);
	}
	else if (mov)
	{
		mUIText->SetText("");

		mModel = mov;
		mModelNode->DetachAllChildren();
		mModelNode->AttachChild(mov);
		mov->ResetPlay();
	}
}
//----------------------------------------------------------------------------