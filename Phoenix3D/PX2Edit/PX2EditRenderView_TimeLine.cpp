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
#include "PX2EditDefine.hpp"
#include "PX2SimulationEventType.hpp"
#include "PX2EffectActor.hpp"
#include "PX2Effectable.hpp"
#include "PX2EffectableController.hpp"
#include "PX2EditEventType.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
EditRenderView_TimeLine::EditRenderView_TimeLine() :
EditRenderView(RVT_TIMELINE),
mMoveMode(MM_PAN),
mLeftWidth(TimeLineLeftWidth+2.0f),
mPixelOverCamIn(1.0f),
mPixelOverCamOut(1.0f),
mUPerGrid(0.0f),
mVPerGrid(0.0f),
mXStart(0.0f),
mXEnd(0.0f),
mZStart(0.0f),
mZEnd(0.0f)
{
	PX2_INPUTMAN.CreateAddListener(RVT_TIMELINE);
}
//----------------------------------------------------------------------------
EditRenderView_TimeLine::~EditRenderView_TimeLine()
{
	PX2_EDIT.GetTimeLineEdit()->SetTimeLineRenderStep_UIGroup(0);
	PX2_EDIT.GetTimeLineEdit()->SetTimeLineRenderStep_Grid(0);

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

	mUIViewGrid = new0 UIView(mRenderViewID);
	mUIViewGrid->SetName(name);
	mUIViewGrid->SetSize(mSize);
	mUIViewGrid->SetCameraAutoAdjust(false);
	PX2_EDIT.GetTimeLineEdit()->SetTimeLineRenderStep_Grid(mUIViewGrid);
	mRenderStep = mUIViewGrid;

	float rWidth = 2.0f*mSize.Width;
	float scaleX = rWidth / 22.5f;
	float scaleZ = scaleX * (mPixelOverCamIn / mPixelOverCamOut);
	PX2_EDIT.GetTimeLineEdit()->SetCtrlsScale(Float2(scaleX, scaleZ));

	mUIViewUIGroup = new UIView(mRenderViewID);
	mUIViewUIGroup->SetPickAcceptRect(Rectf(0.0f, 0.0f, mLeftWidth, mSize.Height));
	PX2_EDIT.GetTimeLineEdit()->SetTimeLineRenderStep_UIGroup(mUIViewUIGroup);
	mRenderStepCtrl = mUIViewUIGroup;

	SetRenderer(mRenderer);

	mIsRenderCreated = true;

	return true;
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::Tick(double elapsedTime)
{
	if (!IsEnable()) return;

	double tiemInSeconds = GetTimeInSeconds();

	mRenderStep->Update(tiemInSeconds, elapsedTime);
	mRenderStep->ComputeVisibleSetAndEnv();

	mRenderStepCtrl->Update(tiemInSeconds, elapsedTime);
	mRenderStepCtrl->ComputeVisibleSetAndEnv();

	if (mRenderer && mRenderer->PreDraw())
	{
		mRenderer->InitRenderStates();

		mRenderer->SetClearColor(Float4::MakeColor(80, 80, 80, 255));
		mRenderer->ClearBuffers();

		mRenderStep->Draw();

		for (int i = 0; i < (int)mFontStrs.size(); i++)
		{
			mRenderer->Draw(mFontStrs[i].x, mFontStrs[i].y, Float4::WHITE,
				mFontStrs[i].str);
		}

		// draw left
		mRenderer->SetClearColor(Float4::BLACK);
		mRenderer->ClearBuffers(0, -1, (int)mLeftWidth, (int)mSize.Height + 1);
		mRenderer->SetClearColor(Float4(0.6f, 0.6f, 0.6f, 1.0f));
		mRenderer->ClearColorBuffer(0, 0, (int)mLeftWidth - 1, (int)mSize.Height + 1);

		mRenderStepCtrl->Draw();

		mRenderer->PostDraw();
		mRenderer->DisplayColorBuffer();
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

	mUIViewGrid->GetCameraNode()->LocalTransform.SetTranslate(pos);
	mUIViewGrid->GetCameraNode()->Update(GetTimeInSeconds(), 0.0f);

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

	mUIViewGrid->GetCameraNode()->LocalTransform.SetTranslate(pos);
	mUIViewGrid->GetCameraNode()->Update(GetTimeInSeconds(), 0.0f);

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
	CurveCtrl *ctrl = PX2_EDIT.GetTimeLineEdit()->GetSelectedCurveCtrl();
	Camera *camera = mUIViewGrid->GetCamera();
	CameraNode *cameraNode = mUIViewGrid->GetCameraNode();

	if (!ctrl) return;

	float inMin = Mathf::MAX_REAL;
	float inMax = -Mathf::MAX_REAL;
	PX2_EDIT.GetTimeLineEdit()->GetInRange(inMin, inMax);

	float outMin = Mathf::MAX_REAL;
	float outMax = -Mathf::MAX_REAL;
	PX2_EDIT.GetTimeLineEdit()->GetOutRange(outMin, outMax);

	float inLength = inMax - inMin;
	float outLength = outMax - outMin;

	if (inLength == 0.0f)
	{
		inLength = 10.0f;
	}
	if (outLength == 0.0f)
	{
		outLength = 10.0f;
	}

	float rightWidth = (float)mSize.Width - mLeftWidth;
	float leftOverWidth = (float)mLeftWidth / (float)mSize.Width;
	float allOverRight = (float)mSize.Width / rightWidth;
	inLength *= allOverRight;

	PX2_UNUSED(leftOverWidth);

	float dMin = 0.0f;
	float dMax = 0.0f;
	float uMin = 0.0f;
	float uMax = 0.0f;
	float rMin = 0.0f;
	float rMax = 0.0f;
	camera->GetFrustum(dMin, dMax, uMin, uMax, rMin, rMax);
	rMax = inLength / 2.0f * 1.5f;
	rMin = -rMax;
	uMax = outLength / 2.0f * 1.5f;
	uMin = -uMax;
	camera->SetFrustum(dMin, dMax, uMin, uMax, rMin, rMax);

	APoint camPos = camera->GetPosition();
	APoint ctrPos = ctrl->GetOutVal();
	camPos.X() = ctrPos.X();
	camPos.Z() = ctrPos.Z();
	mUIViewGrid->GetCameraNode()->LocalTransform.SetTranslate(camPos);
	mUIViewGrid->GetCameraNode()->Update(GetTimeInSeconds(), 0.0f);

	_RefreshGrid(true);
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::ZoomCamera(float xDetal, float zDetal)
{
	Camera *camera = mUIViewGrid->GetCamera();

	float dMin = 0.0f;
	float dMax = 0.0f;
	float uMin = 0.0f;
	float uMax = 0.0f;
	float rMin = 0.0f;
	float rMax = 0.0f;
	camera->GetFrustum(dMin, dMax, uMin, uMax, rMin, rMax);
	float uMaxTemp = uMax;
	float rMaxTemp = rMax;

	if (xDetal > 0.0f)
	{
		rMaxTemp *= xDetal;
	}
	else
	{
		rMaxTemp /= -xDetal;
	}

	if (zDetal > 0.0f)
	{
		uMaxTemp *= zDetal;
	}
	else
	{
		uMaxTemp /= -zDetal;
	}

	if (uMaxTemp > 0.0f)
	{
		uMax = uMaxTemp;
	}
	if (rMaxTemp > 0.0f)
	{
		rMax = rMaxTemp;
	}

	uMin = -uMax;
	rMin = -rMax;
	camera->SetFrustum(dMin, dMax, uMin, uMax, rMin, rMax);

	_RefreshGrid(true);
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::ZoomCameraTo(float xMax, float zMax)
{
	if (xMax <= 0.0f || zMax <= 0.0f) return;

	Camera *camera = mUIViewGrid->GetCamera();

	float dMin = 0.0f;
	float dMax = 0.0f;
	float uMin = 0.0f;
	float uMax = 0.0f;
	float rMin = 0.0f;
	float rMax = 0.0f;
	camera->GetFrustum(dMin, dMax, uMin, uMax, rMin, rMax);

	rMax = xMax;
	rMin = -rMax;
	uMax = zMax;
	uMin = -uMax;
	camera->SetFrustum(dMin, dMax, uMin, uMax, rMin, rMax);

	_RefreshGrid(true);
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
	Polysegment *gird = PX2_EDIT.GetTimeLineEdit()->GetGridPoly();

	PX2_UNUSED(doScale);

	int width = (int)mSize.Width;
	int height = (int)mSize.Height;

	if (width <= 0 && height <= 0) return;

	Camera *camera = mUIViewGrid->GetCamera();
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

	VertexBufferAccessor vba(gird);
	float zPosTemp = 0.0f;
	while (zPosTemp < mZEnd)
	{
		zPosTemp += mVPerGrid;

		vba.Position<Float3>(2 * segNum) = Float3(mXStart, 1.0f, zPosTemp);
		vba.Color<Float3>(0, 2 * segNum) = gray;
		vba.Position<Float3>(2 * segNum + 1) = Float3(mXEnd, 1.0f, zPosTemp);
		vba.Color<Float3>(0, 2 * segNum + 1) = gray;

		mRenderer->SetCamera(mUIViewGrid->GetCamera());
		Vector2f scrv = mUIViewGrid->PointWorldToViewPort(APoint(0.0f, 0.0f, zPosTemp));
		FontStr fs;
		fs.x = iTemp + (int)mLeftWidth;
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

		Vector2f scrv = mUIViewGrid->PointWorldToViewPort(APoint(0.0f, 0.0f,
			zPosTemp));
		FontStr fs;
		fs.x = iTemp + (int)mLeftWidth;
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

		Vector2f scrv = mUIViewGrid->PointWorldToViewPort(APoint(xPosTemp, 0.0f, 0.0f));
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

		Vector2f scrv = mUIViewGrid->PointWorldToViewPort(APoint(xPosTemp, 0.0f,
			0.0f));
		FontStr fs;
		fs.x = (int)scrv.X() + iTemp;
		fs.y = height - zTemp;
		fs.str = StringHelp::FloatToString(xPosTemp);
		mFontStrs.push_back(fs);

		segNum++;
	}

	Float3 zeroLineColorRed = Float3::MakeColor(150, 28, 36);
	Float3 zeroLineColorBlue = Float3::MakeColor(63, 72, 175);

	vba.Position<Float3>(2 * segNum) = Float3(mXStart, 1.0f, 0.0f);
	vba.Color<Float3>(0, 2 * segNum) = zeroLineColorRed;
	vba.Position<Float3>(2 * segNum + 1) = Float3(mXEnd, 1.0f, 0.0f);
	vba.Color<Float3>(0, 2 * segNum + 1) = zeroLineColorRed;
	segNum++;
	vba.Position<Float3>(2 * segNum) = Float3(0.0f, 1.0f, mZStart);
	vba.Color<Float3>(0, 2 * segNum) = zeroLineColorBlue;
	vba.Position<Float3>(2 * segNum + 1) = Float3(0.0f, 1.0f, mZEnd);
	vba.Color<Float3>(0, 2 * segNum + 1) = zeroLineColorBlue;
	segNum++;

	Vector2f scrv = mUIViewGrid->PointWorldToViewPort(APoint::ORIGIN);
	FontStr fs;
	fs.x = iTemp + (int)mLeftWidth;
	fs.y = height - (int)scrv.Y();
	fs.str = "0.0";
	mFontStrs.push_back(fs);

	FontStr fs1;
	fs1.x = (int)scrv.X() + iTemp;
	fs1.y = height - zTemp;
	fs1.str = "0.0";
	mFontStrs.push_back(fs1);

	gird->SetNumSegments(segNum);

	gird->UpdateModelSpace(Renderable::GU_MODEL_BOUND_ONLY);

	if (mRenderer) mRenderer->Update(gird->GetVertexBuffer());

	if (doScale)
	{
		float rWidth = 2.0f * rMax;
		float scaleX = rWidth / 22.5f;

		float uHeight = 2.0f * uMax;
		float scaleZ = uHeight / (((float)mSize.Height / (float)mSize.Width)*22.5f);
		PX2_EDIT.GetTimeLineEdit()->SetCtrlsScale(Float2(scaleX, scaleZ));
	}
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::_TrySelectCurveCtrlPoint(const APoint &pos)
{
	APoint origin;
	AVector direction;
	mRenderStep->GetPickRay(pos.X(), pos.Z(), origin, direction);

	Node *gridNode = PX2_EDIT.GetTimeLineEdit()->GetCurveEditNode_Grid();

	Picker picker;
	picker.Execute(gridNode, origin, direction, 0.0f, Mathf::MAX_REAL);

	if ((int)(picker.Records.size()) > 0)
	{
		Movable *mov = picker.GetClosestNonnegative().Intersected;

		CurveCtrl *ctrl = PX2_EDIT.GetTimeLineEdit()->TrySelectCurve(mov);

		if (ctrl)
		{
			//UnToggleAllInterps();
			//EnableInterps(true);
			//ToggleInterp(ctrl->GetInterpCurveMode());

			PX2_EDIT.GetTimeLineEdit()->SetSelectedCurveCtrl(ctrl);
		}
		else
		{
			PX2_EDIT.GetTimeLineEdit()->SetSelectedCurveCtrl(0);
		}
	}
	else
	{
		PX2_EDIT.GetTimeLineEdit()->SetSelectedCurveCtrl(0);
	}
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::OnSize(const Sizef& size)
{
	mSize = size;

	if (mRenderer) mRenderer->ResizeWindow((int)size.Width, (int)size.Height);

	EditRenderView::OnSize(size);

	FitViewToAll();

	if (mUIViewUIGroup)
		mUIViewUIGroup->SetPickAcceptRect(Rectf(0.0f, 0.0f, mLeftWidth, mSize.Height));
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::OnLeftDown(const APoint &pos)
{
	EditRenderView::OnLeftDown(pos);

	_TrySelectCurveCtrlPoint(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::OnLeftUp(const APoint &pos)
{
	EditRenderView::OnLeftUp(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::OnLeftDClick(const APoint &pos)
{
	EditRenderView::OnLeftDClick(pos);

	Rectf rect(0, 0, mLeftWidth, mSize.Height);
	bool leftContain = rect.IsInsize(Float2(pos.X(), pos.Z()));
	bool isCtrlDown = PX2_EDIT.IsCtrlDown;

	if (!leftContain && isCtrlDown)
	{
		UICurveGroup *uiCurveGroup = PX2_EDIT.GetTimeLineEdit()->GetSelectedUICurveGroup();
		if (!uiCurveGroup) return;

		Camera *camera = PX2_EDIT.GetTimeLineEdit()->GetTimeLineRenderStep_Grid()->GetCamera();

		APoint camPos = camera->GetPosition();
		Vector2f camScreenPos = mUIViewGrid->PointWorldToViewPort(camPos);
		float xDissCam = pos.X() - camScreenPos.X();
		float zDissCam = pos.Z() - camScreenPos.Y();
		float xDissCamReal = xDissCam / mPixelOverCamIn;
		float zDissCamReal = zDissCam / mPixelOverCamOut;
		APoint pointPos = camPos + AVector(xDissCamReal, 0.0f, zDissCamReal);

		CurveGroup *curveGroup = uiCurveGroup->GetCurveGroup();
		curveGroup->AddPoint(pointPos);
	}
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
	float val = 1.2f * Mathf::Sign(delta);
	ZoomCamera(val, val);
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

	bool isCtrlDown = PX2_EDIT.IsCtrlDown;
	CurveCtrl *selectedCtrl = PX2_EDIT.GetTimeLineEdit()->GetSelectedCurveCtrl();

	if (isCtrlDown && !leftContain && selectedCtrl && mIsLeftDown)
	{
		Camera *camera = mRenderStep->GetCamera();

		const APoint &outVal = selectedCtrl->GetOutVal();
		Vector2f posInViewPort = mUIViewGrid->PointWorldToViewPort(outVal);

		float xDiss = pos.X() - posInViewPort.X();
		float zDiss = pos.Z() - posInViewPort.Y();
		float xDissReal = xDiss / mPixelOverCamIn;
		float zDissReal = zDiss / mPixelOverCamOut;

		AVector arrive = AVector(-xDissReal, 0.0f, -zDissReal);
		arrive.Normalize();
		AVector leave = AVector(xDissReal, 0.0f, zDissReal);
		leave.Normalize();

		if (CurveCtrl::SM_ARRIVE == selectedCtrl->GetSelectMode())
		{
			if (xDiss < 0.0f)
			{
				selectedCtrl->SetArriveTangent(arrive);

				InterpCurveMode mode = selectedCtrl->GetInterpCurveMode();
				if (ICM_CURVE_AUTO == mode || ICM_CURVE_AUTOCLAMPED == mode)
				{
					selectedCtrl->SetInterpCurveMode(ICM_CURVE_USER);
					//UnToggleAllInterps();
					//ToggleInterp(ICM_CURVE_USER);
				}
			}
		}
		else if (CurveCtrl::SM_LEAVE == selectedCtrl->GetSelectMode())
		{
			if (xDiss > 0.0f)
			{
				selectedCtrl->SetLeaveTangent(leave);

				InterpCurveMode mode = selectedCtrl->GetInterpCurveMode();
				if (ICM_CURVE_AUTO == mode || ICM_CURVE_AUTOCLAMPED == mode)
				{
					selectedCtrl->SetInterpCurveMode(ICM_CURVE_USER);
					//UnToggleAllInterps();
					//ToggleInterp(ICM_CURVE_USER);
				}
			}
		}
		else if (CurveCtrl::SM_CENTER == selectedCtrl->GetSelectMode())
		{
			APoint camPos = camera->GetPosition();
			Vector2f camScreenPos = mUIViewGrid->PointWorldToViewPort(camPos);
			float xDissCam = pos.X() - camScreenPos.X();
			float zDissCam = pos.Z() - camScreenPos.Y();
			float xDissCamReal = xDissCam / mPixelOverCamIn;
			float zDissCamReal = zDissCam / mPixelOverCamOut;
			APoint pointPos = camPos + AVector(xDissCamReal, 0.0f, zDissCamReal);
			pointPos.Y() = 0.0f;

			selectedCtrl->SetInVal(pointPos.X()); // ctrl may changed

			selectedCtrl = PX2_EDIT.GetTimeLineEdit()->GetSelectedCurveCtrl(); // ctrl may changed, can it again
			if (selectedCtrl) selectedCtrl->SetOutVal(pointPos);
		}
	}

	bool doMovCal = false;

	if (mIsMiddleDown && !leftContain)
		doMovCal = true;

	if (mIsRightDown && !leftContain)
		doMovCal = true;

	if (doMovCal)
	{
		if (MM_PAN == mMoveMode)
		{
			APoint pos = mUIViewGrid->GetCameraNode()->LocalTransform.GetTranslate();
			pos += AVector(movedX, 0.0f, movedZ);
			mUIViewGrid->GetCameraNode()->LocalTransform.SetTranslate(pos);
			mUIViewGrid->GetCameraNode()->Update(GetTimeInSeconds(), 0.0f);

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

	if (EditEventSpace::IsEqual(event, EditEventSpace::CurveChangedByPropertyGrid))
	{
		Object *obj = event->GetData<Object*>();
		PX2_EDIT.GetTimeLineEdit()->UpdateCurve(obj);
	}
	else if (SimuES_E::IsEqual(event, SimuES_E::RemoveObject))
	{
		Object *obj = event->GetData<Object*>();
		EffectModule *module = DynamicCast<EffectModule>(obj);
		Movable *movable = DynamicCast<Movable>(obj);
		InterpCurveController *icCtrl = DynamicCast<InterpCurveController>(obj);

		if (module)
		{
			RemoveCurveGroup(module);
		}
		else if (movable)
		{
			RemoveCurveGroup(movable);
		}
		else if (icCtrl)
		{
			RemoveCurveGroup(icCtrl);
		}
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::TimeLine_FitHor))
	{
		FitViewHorizontally();
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::TimeLine_FitVer))
	{
		FitViewVertically();
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::TimeLine_Fit_Selected))
	{
		FitViewToSelected();
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::TimeLine_Pan))
	{
		mMoveMode = MM_PAN;
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::TimeLine_Zoom))
	{
		mMoveMode = MM_ZOOM;
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::TimeLine_CurveMode))
	{
		InterpCurveMode icmMode = (InterpCurveMode)event->GetData<int>();

		CurveCtrl *ctrl = PX2_EDIT.GetTimeLineEdit()->GetSelectedCurveCtrl();
		if (ctrl)
		{
			ctrl->SetInterpCurveMode(icmMode);
		}
	}
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::RemoveCurveGroup(PX2::EffectModule *module)
{
	if (!module) return;

	PX2_EDIT.GetTimeLineEdit()->RemoveGroup(module);
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::RemoveCurveGroup(InterpCurveController *ctrl)
{
	if (!ctrl) return;

	PX2_EDIT.GetTimeLineEdit()->RemoveGroup(ctrl);
}
//----------------------------------------------------------------------------
void _TimeLineTravelExecuteFun(Movable *mov, Any *data)
{
	PX2_UNUSED(data);

	Effectable *eftAble = DynamicCast<Effectable>(mov);
	if (eftAble)
	{
		for (int i = 0; i < eftAble->GetEffectableController()->GetNumModules(); i++)
		{
			EffectModule *module = eftAble->GetEffectableController()->GetModule(i);
			PX2_EDIT.GetTimeLineEdit()->RemoveGroup(module);
		}
	}

	for (int i = 0; i < mov->GetNumControllers(); i++)
	{
		InterpCurveController *icCtrl = DynamicCast<InterpCurveController>(
			mov->GetController(i));
		if (icCtrl)
		{
			PX2_EDIT.GetTimeLineEdit()->RemoveGroup(icCtrl);
		}
	}
}
//----------------------------------------------------------------------------
void EditRenderView_TimeLine::RemoveCurveGroup(Movable *mov)
{
	Node::TravelExecute(mov, _TimeLineTravelExecuteFun);
}
//----------------------------------------------------------------------------