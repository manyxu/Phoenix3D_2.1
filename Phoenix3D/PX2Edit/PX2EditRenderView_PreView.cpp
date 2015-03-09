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
EditRenderView(RVT_PREVIEW),
mPreViewType(PVT_NONE)
{
	// mRenderViewID is 4
	PX2_INPUTMAN.CreateAddListener(RVT_PREVIEW);

	mPicFrame = new0 UIFrame();

	mUIPicBox = new0 UIPicBox();
	mPicFrame->AttachChild(mUIPicBox);

	mUIText = new0 UIText();
	mPicFrame->AttachChild(mUIText);
	mUIText->SetRectUseage(UIText::RU_ALIGNS);
	mUIText->SetAligns(TEXTALIGN_RIGHT | TEXTALIGN_TOP);
	mUIText->SetColor(Float3::WHITE);

	mModelRootNode = new0 Node();

	mModelNode = new0 Node();
	mModelRootNode->AttachChild(mModelNode);

	mModelCamera = new0 Camera();
	mModelCameraNode = new0 CameraNode(mModelCamera);
	mModelNode->AttachChild(mModelCameraNode);
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

	mModelCamera->SetFrustum(35.0f, (float)mSize.Width / (float)mSize.Height, 1.0f, 1000.0f);
	mRenderStepCtrl = new0 RenderStep();
	mRenderStepCtrl->SetSize(mSize);
	mRenderStepCtrl->SetRenderer(mRenderer);
	mRenderStepCtrl->SetNode(mModelRootNode);
	mRenderStepCtrl->SetCamera(mModelCamera);

	mIsRenderCreated = true;

	return true;
}
//----------------------------------------------------------------------------
void EditRenderView_PreView::Tick(double elapsedTime)
{
	if (!IsEnable()) return;

	if (mRenderStep && mIsRenderCreated)
	{
		double tiemInSeconds = GetTimeInSeconds();

		if (PVT_TEXTURE == mPreViewType)
		{
			mRenderStep->Update(tiemInSeconds, elapsedTime);
			mRenderStep->ComputeVisibleSet();
		}
		else if (PVT_MODEL == mPreViewType)
		{
			mRenderStepCtrl->Update(tiemInSeconds, elapsedTime);
			mRenderStepCtrl->ComputeVisibleSet();
		}

		Renderer *renderer = mRenderStep->GetRenderer();
		if (renderer && renderer->PreDraw())
		{
			renderer->InitRenderStates();
			renderer->ClearBuffers();

			if (PVT_TEXTURE == mPreViewType)
				mRenderStep->Draw();
			else if (PVT_MODEL == mPreViewType)
				mRenderStepCtrl->Draw();

			renderer->PostDraw();
			renderer->DisplayColorBuffer();
		}
	}
}
//----------------------------------------------------------------------------
void EditRenderView_PreView::_ReSizeTexture()
{
	if (!mUIPicBox) return;

	float texWidth = 128.0f;
	float texHeight = 128.0f;

	UIPicBox::TexMode tm = mUIPicBox->GetTexMode();
	if (UIPicBox::TM_TEX == tm)
	{
		const std::string &textureFilename = mUIPicBox->GetTextureFilename();
		if (!textureFilename.empty())
		{
			Texture2D *tex = DynamicCast<Texture2D>(PX2_RM.BlockLoad(textureFilename));

			if (tex)
			{
				texWidth = (float)tex->GetWidth();
				texHeight = (float)tex->GetHeight();
			}
		}
	}
	else if (UIPicBox::TM_TEXPACK_ELE == tm)
	{
		const TexPackElement &element = PX2_RM.GetTexPackElement(mUIPicBox->GetTexturePackName(), mUIPicBox->GetElementName());
		if (element.IsValid())
		{
			texWidth = (float)element.W;
			texHeight = (float)element.H;
		}
	}

	float texWidthOverHeight = texWidth / texHeight;

	float sizeWidthOverHeight = mSize.Width / mSize.Height;

	if (texWidthOverHeight > sizeWidthOverHeight)
	{
		mUIPicBox->SetSize(mSize.Width, mSize.Width / texWidthOverHeight);
	}
	else
	{
		mUIPicBox->SetSize(mSize.Height * texWidthOverHeight, mSize.Height);
	}

	mUIPicBox->LocalTransform.SetTranslateXZ(mSize.Width/2.0f, mSize.Height/2.0f);

	if (mUIText) mUIText->SetRect(Rectf(0.0f, 0.0f, mSize.Width, mSize.Height));
}
//----------------------------------------------------------------------------
void EditRenderView_PreView::OnSize(const Sizef& size)
{
	mSize = size;

	EditRenderView::OnSize(size);

	_ReSizeTexture();

	mModelCamera->SetFrustum(35.0f, (float)mSize.Width / (float)mSize.Height, 1.0f, 1000.0f);

	if (mRenderStep)
	{
		mRenderStep->GetRenderer()->ResizeWindow((int)size.Width, (int)size.Height);
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
		mPreViewType = PVT_TEXTURE;

		const SelectResData &data = PX2_EDIT.GetSelectedResource();
		SelectResData::SelectResType selectResType = data.GetSelectResType();

		std::string texStr = "";

		if (selectResType == SelectResData::RT_NORMAL)
		{
			mUIPicBox->SetTexture(data.ResPathname);

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

				texStr = "width:" + StringHelp::IntToString(texPackEle.W) + " " + "height:" + StringHelp::IntToString(texPackEle.H) + " ";
			}
		}
		mUIText->SetText(texStr);

		_ReSizeTexture();
	}
	else if (mov)
	{
		mPreViewType = PVT_MODEL;

		mUIText->SetText("");

		mModelNode->DetachAllChildren();
		mModel = mov;
		mModelNode->AttachChild(mModel);
		mModel->ResetPlay();

		const APoint &boundCenter = mModel->WorldBound.GetCenter();
		float boundRadius = mModel->WorldBound.GetRadius();

		APoint pos = boundCenter + AVector(-boundRadius*2.0f, -boundRadius*2.0f, boundRadius*2.0f);
		AVector dir = boundCenter - pos;

		if (boundRadius > 0.0f)
		{
			dir.Normalize();
			AVector up = AVector(Float3(0.0f, 0.0f, 1.0f));
			AVector right = dir.Cross(up);
			right.Normalize();
			up = right.Cross(dir);
			up.Normalize();

			AVector::Orthonormalize(dir, up, right);

			mModelCameraNode->LocalTransform.SetTranslate(APoint(0.0f, -10.0f, 0.0f));
			mModelCamera->SetAxes(AVector::UNIT_Y, AVector::UNIT_Z, AVector::UNIT_X);
		}
	}
	else
	{
		mPreViewType = PVT_NONE;
	}
}
//----------------------------------------------------------------------------