// PX2EditRenderView_TimeLine.cpp

#include "PX2EditRenderView_TimeLine.hpp"
#include "PX2Edit.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2StandardMesh.hpp"
#include "PX2VertexColor4Material.hpp"
#include "PX2Project.hpp"
#include "PX2EditEventType.hpp"
#include "PX2InputManager.hpp"
#include "PX2Float2.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
EditRenderView_TimeLine::EditRenderView_TimeLine() :
EditRenderView(RVT_TIMELINE),
mMoveMode(MM_PAN),
mLeftWidth(100.0f),
mPixelOverCamIn(0.0f),
mPixelOverCamOut(0.0f),
mUPerGrid(0.0f),
mVPerGrid(0.0f),
mXStart(0.0f),
mXEnd(0.0f),
mZStart(0.0f),
mZEnd(0.0f)
{
	// mRenderViewID is 3
	PX2_INPUTMAN.CreateAddListener(RVT_TIMELINE);

	mFrame = new0 UIFrame();

	mGridNode = new0 Node();
	mFrame->AttachChild(mGridNode);

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PC);
	VertexBuffer *vBuffer = new0 VertexBuffer(4096, vf->GetStride(), Buffer::BU_DYNAMIC);
	mGridPoly = new0 Polysegment(vf, vBuffer, false);
	VertexColor4Material *mtl = new0 VertexColor4Material();
	mGridPoly->SetMaterialInstance(mtl->CreateInstance());
	mGridNode->AttachChild(mGridPoly);
}
//----------------------------------------------------------------------------
EditRenderView_TimeLine::~EditRenderView_TimeLine()
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
bool EditRenderView_TimeLine::InitlizeRendererStep(const std::string &name)
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

	mRenderStep->SetNode(mFrame);

	mIsRenderCreated = true;

	return true;
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::Tick(double elapsedTime)
{
	if (!IsEnable()) return;

	if (mRenderStep && mIsRenderCreated)
	{
		double tiemInSeconds = GetTimeInSeconds();

		mRenderStep->Update(tiemInSeconds, elapsedTime);

		mRenderStep->ComputeVisibleSet();

		Renderer *renderer = mRenderStep->GetRenderer();
		if (renderer && renderer->PreDraw())
		{
			renderer->InitRenderStates();

			mRenderer->SetClearColor(Float4::MakeColor(64, 64, 64, 255));
			renderer->ClearBuffers();

			mRenderStep->Draw();

			for (int i = 0; i < (int)mFontStrs.size(); i++)
			{
				mRenderer->Draw(mFontStrs[i].x, mFontStrs[i].y, Float4::WHITE,
					mFontStrs[i].str);
			}

			// draw left
			mRenderer->SetClearColor(Float4::BLACK);
			mRenderer->ClearBuffers(0, -1, mLeftWidth, mSize.Height + 1);
			mRenderer->SetClearColor(Float4(0.6f, 0.6f, 0.6f, 1.0f));
			mRenderer->ClearColorBuffer(0, 0, mLeftWidth - 1, mSize.Height + 1);

			renderer->PostDraw();
			renderer->DisplayColorBuffer();
		}
	}
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::FitViewHorizontally()
{
	if (!mRenderStep) return;
	Camera *camera = mRenderStep->GetCamera();

	float inMin = Mathf::MAX_REAL;
	float inMax = -Mathf::MAX_REAL;
	PX2_EDIT.GetTimeLineEdit()->GetInRange(inMin, inMax);

	float inLength = inMax - inMin;
	bool inLenghtZero = false;
	if (inLength == 0.0f)
	{
		inLength = 10.0f;
		inLenghtZero = true;
	}

	float rightWidth = (float)mSize.Width - mLeftWidth;
	float leftOverWidth = (float)mLeftWidth / (float)mSize.Width;
	float allOverRight = (float)mSize.Width / rightWidth;
	inLength *= allOverRight;

	float dMin = 0.0f;
	float dMax = 0.0f;
	float uMin = 0.0f;
	float uMax = 0.0f;
	float rMin = 0.0f;
	float rMax = 0.0f;
	camera->GetFrustum(dMin, dMax, uMin, uMax, rMin, rMax);
	rMax = inLength / 2.0f * 1.5f;
	rMin = -rMax;
	camera->SetFrustum(dMin, dMax, uMin, uMax, rMin, rMax);

	APoint pos = camera->GetPosition();

	if (inLenghtZero)
		pos.X() = inMin;
	else
		pos.X() = inMin + inLength / 2.0f - inLength*leftOverWidth;

	mUIView->GetCameraNode()->LocalTransform.SetTranslate(pos);

	_RefreshGrid(true);
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::FitViewVertically()
{
	if (!mRenderStep) return;
	Camera *camera = mRenderStep->GetCamera();

	float outMin = Mathf::MAX_REAL;
	float outMax = -Mathf::MAX_REAL;
	PX2_EDIT.GetTimeLineEdit()->GetOutRange(outMin, outMax);

	float outLength = outMax - outMin;
	bool outLenghtZero = false;
	if (outLength == 0.0f)
	{
		outLength = 10.0f;
		outLenghtZero = true;
	}

	float dMin = 0.0f;
	float dMax = 0.0f;
	float uMin = 0.0f;
	float uMax = 0.0f;
	float rMin = 0.0f;
	float rMax = 0.0f;
	camera->GetFrustum(dMin, dMax, uMin, uMax, rMin, rMax);
	uMax = outLength / 2.0f * 1.5f;
	uMin = -uMax;
	camera->SetFrustum(dMin, dMax, uMin, uMax, rMin, rMax);

	APoint pos = camera->GetPosition();

	if (outLenghtZero)
		pos.Z() = outMin;
	else
		pos.Z() = outMin + outLength / 2.0f;

	mUIView->GetCameraNode()->LocalTransform.SetTranslate(pos);

	_RefreshGrid(true);
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::FitViewToAll()
{
	FitViewHorizontally();
	FitViewVertically();
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::FitViewToSelected()
{
}
//----------------------------------------------------------------------------
float _GetGridSpacing(int gridNum)
{
	if (gridNum & 0x01) // Odd numbers
	{
		return Mathf::Pow(10.f, 0.5f*((float)(gridNum - 1)) + 1.f);
	}
	else // Even numbers
	{
		return 0.5f * Mathf::Pow(10.f, 0.5f*((float)(gridNum)) + 1.f);
	}
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::_RefreshGrid(bool doScale)
{
	int width = (int)mSize.Width;
	int height = (int)mSize.Height;

	if (width <= 0 && height <= 0) return;

	Camera *camera = mRenderStep->GetCamera();
	APoint pos = camera->GetPosition();
	float dMin = 0.0f;
	float dMax = 0.0f;
	float uMin = 0.0f;
	float uMax = 0.0f;
	float rMin = 0.0f;
	float rMax = 0.0f;
	camera->GetFrustum(dMin, dMax, uMin, uMax, rMin, rMax);
	if (0.0f == rMax || 0.0f == uMax || 0.0f == dMax) return;

	float inLength = rMax - rMin;
	float outLength = uMax - uMin;
	inLength = Mathf::FAbs(inLength);
	outLength = Mathf::FAbs(outLength);

	mPixelOverCamIn = width / inLength;
	mPixelOverCamOut = height / outLength;

	int minPixelsPerInGrid = 35;
	int minPixelsPerOutGrid = 25;
	float minGridSpacing = 0.001f;

	int gridNum = 0;
	float inGridSpacing = minGridSpacing;
	while (inGridSpacing*mPixelOverCamIn < minPixelsPerInGrid)
	{
		inGridSpacing = minGridSpacing * _GetGridSpacing(gridNum);
		gridNum++;
	}
	mUPerGrid = inGridSpacing;

	gridNum = 0;
	float outGridSpacing = minGridSpacing;
	while (outGridSpacing*mPixelOverCamOut < minPixelsPerOutGrid)
	{
		outGridSpacing = minGridSpacing * _GetGridSpacing(gridNum);
		gridNum++;
	}
	mVPerGrid = outGridSpacing;

	mXStart = pos.X() + rMin;
	mXEnd = pos.X() + rMax;
	mZStart = pos.Z() + uMin;
	mZEnd = pos.Z() + uMax;

	Float3 gray(0.62f, 0.62f, 0.62f);
	int segNum = 0;
	mFontStrs.clear();
	int iTemp = 4;
	int zTemp = 4;

	VertexBufferAccessor vba(mGridPoly);
	float zPosTemp = 0.0f;
	while (zPosTemp < mZEnd)
	{
		zPosTemp += mVPerGrid;

		vba.Position<Float3>(2 * segNum) = Float3(mXStart, 1.0f, zPosTemp);
		vba.Color<Float3>(0, 2 * segNum) = gray;
		vba.Position<Float3>(2 * segNum + 1) = Float3(mXEnd, 1.0f, zPosTemp);
		vba.Color<Float3>(0, 2 * segNum + 1) = gray;

		mRenderer->SetCamera(mRenderStep->GetCamera());
		Vector2f scrv = mRenderer->PointWorldToViewPort(APoint(0.0f, 0.0f, zPosTemp));
		FontStr fs;
		fs.x = iTemp + mLeftWidth;
		fs.y = height - (int)scrv.Y();
		fs.str = StringHelp::FloatToString(zPosTemp);
		mFontStrs.push_back(fs);

		segNum++;
	}
	zPosTemp = 0.0f;
	while (zPosTemp > mZStart)
	{
		zPosTemp -= mVPerGrid;

		vba.Position<Float3>(2 * segNum) = Float3(mXStart, 1.0f, zPosTemp);
		vba.Color<Float3>(0, 2 * segNum) = gray;
		vba.Position<Float3>(2 * segNum + 1) = Float3(mXEnd, 1.0f, zPosTemp);
		vba.Color<Float3>(0, 2 * segNum + 1) = gray;

		Vector2f scrv = mRenderer->PointWorldToViewPort(APoint(0.0f, 0.0f,
			zPosTemp));
		FontStr fs;
		fs.x = iTemp + mLeftWidth;
		fs.y = height - (int)scrv.Y();
		fs.str = StringHelp::FloatToString(zPosTemp);
		mFontStrs.push_back(fs);

		segNum++;
	}
	float xPosTemp = 0.0f;
	while (xPosTemp < mXEnd)
	{
		xPosTemp += mUPerGrid;

		vba.Position<Float3>(2 * segNum) = Float3(xPosTemp, 1.0f, mZStart);
		vba.Color<Float3>(0, 2 * segNum) = gray;
		vba.Position<Float3>(2 * segNum + 1) = Float3(xPosTemp, 1.0f, mZEnd);
		vba.Color<Float3>(0, 2 * segNum + 1) = gray;

		Vector2f scrv = mRenderer->PointWorldToViewPort(APoint(xPosTemp, 0.0f, 0.0f));
		FontStr fs;
		fs.x = (int)scrv.X() + iTemp;
		fs.y = height - zTemp;
		fs.str = StringHelp::FloatToString(xPosTemp);
		mFontStrs.push_back(fs);

		segNum++;
	}
	xPosTemp = 0.0f;
	while (xPosTemp > mXStart)
	{
		xPosTemp -= mUPerGrid;

		vba.Position<Float3>(2 * segNum) = Float3(xPosTemp, 1.0f, mZStart);
		vba.Color<Float3>(0, 2 * segNum) = gray;
		vba.Position<Float3>(2 * segNum + 1) = Float3(xPosTemp, 1.0f, mZEnd);
		vba.Color<Float3>(0, 2 * segNum + 1) = gray;

		Vector2f scrv = mRenderer->PointWorldToViewPort(APoint(xPosTemp, 0.0f,
			0.0f));
		FontStr fs;
		fs.x = (int)scrv.X() + iTemp;
		fs.y = height - zTemp;
		fs.str = StringHelp::FloatToString(xPosTemp);
		mFontStrs.push_back(fs);

		segNum++;
	}

	vba.Position<Float3>(2 * segNum) = Float3(mXStart, 1.0f, 0.0f);
	vba.Color<Float3>(0, 2 * segNum) = Float3::WHITE;
	vba.Position<Float3>(2 * segNum + 1) = Float3(mXEnd, 1.0f, 0.0f);
	vba.Color<Float3>(0, 2 * segNum + 1) = Float3::WHITE;
	segNum++;
	vba.Position<Float3>(2 * segNum) = Float3(0.0f, 1.0f, mZStart);
	vba.Color<Float3>(0, 2 * segNum) = Float3::WHITE;
	vba.Position<Float3>(2 * segNum + 1) = Float3(0.0f, 1.0f, mZEnd);
	vba.Color<Float3>(0, 2 * segNum + 1) = Float3::WHITE;
	segNum++;

	Vector2f scrv = mRenderer->PointWorldToViewPort(APoint::ORIGIN);
	FontStr fs;
	fs.x = iTemp + mLeftWidth;
	fs.y = height - (int)scrv.Y();
	fs.str = "0.0";
	mFontStrs.push_back(fs);

	FontStr fs1;
	fs1.x = (int)scrv.X() + iTemp;
	fs1.y = height - zTemp;
	fs1.str = "0.0";
	mFontStrs.push_back(fs1);

	mGridPoly->SetNumSegments(segNum);

	mGridPoly->UpdateModelSpace(Renderable::GU_MODEL_BOUND_ONLY);

	if (mRenderer) mRenderer->Update(mGridPoly->GetVertexBuffer());
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::OnSize(const Sizef& size)
{
	mSize = size;

	EditRenderView::OnSize(size);

	if (mRenderStep)
	{
		mRenderStep->GetRenderer()->ResizeWindow((int)size.Width,
			(int)size.Height);
	}

	FitViewToAll();
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::OnLeftDown(const APoint &pos)
{
	EditRenderView::OnLeftDown(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::OnLeftUp(const APoint &pos)
{
	EditRenderView::OnLeftUp(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::OnMiddleDown(const APoint &pos)
{
	EditRenderView::OnMiddleDown(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::OnMiddleUp(const APoint &pos)
{
	EditRenderView::OnMiddleUp(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::OnMouseWheel(float delta)
{
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::OnRightDown(const APoint &pos)
{
	EditRenderView::OnRightDown(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::OnRightUp(const APoint &pos)
{
	EditRenderView::OnRightUp(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::OnMotion(const APoint &pos)
{
	AVector diff = pos - mLastMousePoint;
	if (AVector::ZERO == diff) return;

	float movedX = -diff.X() / mPixelOverCamIn;
	float movedZ = -diff.Z() / mPixelOverCamOut;
	Rectf rect(0, 0, mLeftWidth, mSize.Height);
	bool leftContain = rect.IsInsize(Float2(pos.X(), pos.Z()));

	bool doMovCal = false;

	if (mIsMiddleDown && !leftContain)
		doMovCal = true;

	if (mIsRightDown && !leftContain)
		doMovCal = true;

	if (doMovCal)
	{
		if (MM_PAN == mMoveMode)
		{
			APoint pos = mUIView->GetCameraNode()->LocalTransform.GetTranslate();
			pos += AVector(movedX, 0.0f, movedZ);
			mUIView->GetCameraNode()->LocalTransform.SetTranslate(pos);
			_RefreshGrid(false);
		}
		else if (MM_ZOOM == mMoveMode)
		{
		}
	}

	mLastMousePoint = pos;
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::DoExecute(Event *event)
{
	EditRenderView::DoExecute(event);
}
//----------------------------------------------------------------------------