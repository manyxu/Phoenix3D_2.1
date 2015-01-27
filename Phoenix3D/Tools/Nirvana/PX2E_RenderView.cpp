// PX2E_RenderView.cpp

#include "PX2E_RenderView.hpp"
#include "PX2Project.hpp"
#include "PX2EditEventType.hpp"
#include "PX2Edit.hpp"
using namespace PX2Editor;
using namespace PX2;

const int sID_CTRLTIMER = PX2_EDIT_GETID;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::RenderView, wxWindow)
BEGIN_EVENT_TABLE(RenderView, wxWindow)
EVT_TIMER(sID_CTRLTIMER, RenderView::OnTimer)
EVT_SIZE(RenderView::OnSize)
EVT_PAINT(RenderView::OnPaint)
EVT_ERASE_BACKGROUND(RenderView::OnEraseBackground)
EVT_LEFT_DOWN(RenderView::OnLeftDown)
EVT_LEFT_UP(RenderView::OnLeftUp)
EVT_MIDDLE_DOWN(RenderView::OnMiddleDown)
EVT_MIDDLE_UP(RenderView::OnMiddleUp)
EVT_MOUSEWHEEL(RenderView::OnMouseWheel)
EVT_RIGHT_DOWN(RenderView::OnRightDown)
EVT_RIGHT_UP(RenderView::OnRightUp)
EVT_MOTION(RenderView::OnMotion)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
RenderView::RenderView()
{
}
//----------------------------------------------------------------------------
RenderView::RenderView(wxWindow *parent):
wxWindow(parent, -1),
mIsInited(false),
mCameraMoveSpeed(40.0f),
mCurCameraMoveSpeed_W(0.0f),
mCurCameraMoveSpeed_S(0.0f),
mCurCameraMoveSpeed_A(0.0f),
mCurCameraMoveSpeed_D(0.0f)
{
	mCtrlTimer.SetOwner(this, sID_CTRLTIMER);
	mCtrlTimer.Start(15);
}
//----------------------------------------------------------------------------
RenderView::~RenderView()
{
}
//----------------------------------------------------------------------------
void RenderView::OnTimer(wxTimerEvent& event)
{
	int ival = event.GetInterval();
	double dIval = ival / 1000.0;

	if (sID_CTRLTIMER == event.GetId())
	{
		_Update(dIval);
	}
}
//----------------------------------------------------------------------------
void RenderView::OnSize(wxSizeEvent& e)
{
	wxSize size = e.GetSize();

	if (mEditRenderView)
	{
		mEditRenderView->OnSize(Sizef((float)size.GetWidth(), 
			(float)size.GetHeight()));
	}

	mSize = size;
}
//----------------------------------------------------------------------------
void RenderView::OnPaint(wxPaintEvent& e)
{
	wxPaintDC dc(this);
	PX2_UNUSED(e);
}
//----------------------------------------------------------------------------
void RenderView::OnEraseBackground(wxEraseEvent& e)
{
	if (!mIsInited) return;
	PX2_UNUSED(e);
}
//----------------------------------------------------------------------------
void RenderView::OnLeftDown(wxMouseEvent& e)
{
	SetFocus();

	wxPoint mousePos = e.GetPosition();
	APoint pos = _wxPointToAPoint(mousePos);

	if (mEditRenderView)
	{
		mEditRenderView->OnLeftDown(pos);
	}
}
//----------------------------------------------------------------------------
void RenderView::OnLeftUp(wxMouseEvent& e)
{
	wxPoint mousePos = e.GetPosition();
	APoint pos = _wxPointToAPoint(mousePos);

	if (mEditRenderView)
	{
		mEditRenderView->OnLeftUp(pos);
	}
}
//----------------------------------------------------------------------------
void RenderView::OnMiddleDown(wxMouseEvent& e)
{
	SetFocus();

	wxPoint mousePos = e.GetPosition();
	APoint pos = _wxPointToAPoint(mousePos);

	if (mEditRenderView)
	{
		mEditRenderView->OnMiddleDown(pos);
	}
}
//----------------------------------------------------------------------------
void RenderView::OnMiddleUp(wxMouseEvent& e)
{
	wxPoint mousePos = e.GetPosition();
	APoint pos = _wxPointToAPoint(mousePos);

	if (mEditRenderView)
	{
		mEditRenderView->OnMiddleUp(pos);
	}
}
//----------------------------------------------------------------------------
void RenderView::OnMouseWheel(wxMouseEvent& e)
{
	float delta = (float)e.GetWheelRotation();

	if (mEditRenderView)
	{
		mEditRenderView->OnMouseWheel(delta);
	}
}
//----------------------------------------------------------------------------
void RenderView::OnRightDown(wxMouseEvent& e)
{
	SetFocus();

	wxPoint mousePos = e.GetPosition();
	APoint pos = _wxPointToAPoint(mousePos);

	if (mEditRenderView)
	{
		mEditRenderView->OnRightDown(pos);
	}
}
//----------------------------------------------------------------------------
void RenderView::OnRightUp(wxMouseEvent& e)
{
	wxPoint mousePos = e.GetPosition();
	APoint pos = _wxPointToAPoint(mousePos);

	if (mEditRenderView)
	{
		mEditRenderView->OnRightUp(pos);
	}
}
//----------------------------------------------------------------------------
void RenderView::OnMotion(wxMouseEvent& e)
{
	wxPoint mousePos = e.GetPosition();
	APoint pos = _wxPointToAPoint(mousePos);

	if (mEditRenderView)
	{
		mEditRenderView->OnMotion(pos);
	}
}
//----------------------------------------------------------------------------
void RenderView::DoExecute(PX2::Event *event)
{
	if (EditEventSpace::IsEqual(event, EditEventSpace::NewScene) ||
		EditEventSpace::IsEqual(event, EditEventSpace::LoadedScene))
	{
		mEditRenderView = 0;

		RenderStep *sceneRenderStep = PX2_PROJ.GetSceneRenderStep();
		Camera *sceneRenderStepCamera = sceneRenderStep->GetCamera();
		Renderer *sceneRenderStepRenderer = sceneRenderStep->GetRenderer();

		mEditRenderView = new0 EditRenderView();
		mEditRenderView->SetRenderer(sceneRenderStepRenderer);
		mEditRenderView->SetCamera(sceneRenderStepCamera);

		SetSize(GetSize());
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::CloseScene))
	{
		mEditRenderView = 0;
	}
}
//----------------------------------------------------------------------------
void RenderView::_Update(double detalSeconds)
{
	//bool altDown = wxGetKeyState(WXK_ALT);
	//bool ctrlDown = wxGetKeyState(WXK_CONTROL);
	//bool shiftDown = wxGetKeyState(WXK_SHIFT);
	//bool wDown = wxGetKeyState((wxKeyCode)(_T('W')));
	//bool sDown = wxGetKeyState((wxKeyCode)(_T('S')));
	//bool aDown = wxGetKeyState((wxKeyCode)(_T('A')));
	//bool dDown = wxGetKeyState((wxKeyCode)(_T('D')));

	//// cal move speed
	//float speedParam0 = (mCameraMoveSpeed / 0.2f);
	//float speedParam1 = (mCameraMoveSpeed / 0.1f);
	//if (wDown)
	//{
	//	mCurCameraMoveSpeed_W = mCameraMoveSpeed;
	//}
	//else
	//{
	//	float curSpeedTemp = mCurCameraMoveSpeed_W;
	//	curSpeedTemp -= (float)detalSeconds * (speedParam0 + speedParam1*(float)detalSeconds);
	//	if (curSpeedTemp >= 0.0f)
	//	{
	//		mCurCameraMoveSpeed_W = curSpeedTemp;
	//	}
	//	else
	//	{
	//		mCurCameraMoveSpeed_W = 0.0f;
	//	}
	//}

	//if (sDown)
	//{
	//	mCurCameraMoveSpeed_S = mCameraMoveSpeed;
	//}
	//else
	//{
	//	float curSpeedTemp = mCurCameraMoveSpeed_S;
	//	curSpeedTemp -= (float)detalSeconds * (speedParam0 + speedParam1*(float)detalSeconds);
	//	if (curSpeedTemp > 0.0f)
	//	{
	//		mCurCameraMoveSpeed_S = curSpeedTemp;
	//	}
	//	else
	//	{
	//		mCurCameraMoveSpeed_S = 0.0f;
	//	}
	//}

	//if (aDown)
	//{
	//	mCurCameraMoveSpeed_A = mCameraMoveSpeed;
	//}
	//else
	//{
	//	float curSpeedTemp = mCurCameraMoveSpeed_A;
	//	curSpeedTemp -= (float)detalSeconds * (speedParam0 + speedParam1*(float)detalSeconds);
	//	if (curSpeedTemp > 0.0f)
	//	{
	//		mCurCameraMoveSpeed_A = curSpeedTemp;
	//	}
	//	else
	//	{
	//		mCurCameraMoveSpeed_A = 0.0f;
	//	}
	//}

	//if (dDown)
	//{
	//	mCurCameraMoveSpeed_D = mCameraMoveSpeed;
	//}
	//else
	//{
	//	float curSpeedTemp = mCurCameraMoveSpeed_D;
	//	curSpeedTemp -= (float)detalSeconds * (speedParam0 + speedParam1*(float)detalSeconds);
	//	if (curSpeedTemp > 0.0f)
	//	{
	//		mCurCameraMoveSpeed_D = curSpeedTemp;
	//	}
	//	else
	//	{
	//		mCurCameraMoveSpeed_D = 0.0f;
	//	}
	//}

	//// move
	//float moveValue_W = mCurCameraMoveSpeed_W * (float)detalSeconds;
	//float moveValue_S = mCurCameraMoveSpeed_S * (float)detalSeconds;
	//float moveValue_A = mCurCameraMoveSpeed_A * (float)detalSeconds;
	//float moveValue_D = mCurCameraMoveSpeed_D * (float)detalSeconds;

	//if (shiftDown)
	//{
	//	moveValue_W = moveValue_W * 4.0f;
	//	moveValue_S = moveValue_S * 4.0f;
	//	moveValue_A = moveValue_A * 4.0f;
	//	moveValue_D = moveValue_D * 4.0f;
	//}

	//// 统一控制移动速度
	//float scale = 0.5f;
	//moveValue_W = moveValue_W * scale;
	//moveValue_S = moveValue_S * scale;
	//moveValue_A = moveValue_A * scale;
	//moveValue_D = moveValue_D * scale;

	//float moveValueV = moveValue_W - moveValue_S;
	//float moveValueH = moveValue_A - moveValue_D;

	//if (mEditRenderView)
	//	mEditRenderView->OnMoveHV(altDown, moveValueH, moveValueV);
}
//----------------------------------------------------------------------------
APoint RenderView::_wxPointToAPoint(wxPoint &point)
{
	return APoint((float)point.x, 0.0f, (float)(mSize.GetHeight() - point.y));
}
//----------------------------------------------------------------------------