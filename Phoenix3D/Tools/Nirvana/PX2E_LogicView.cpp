// PX2E_LogicView.cpp

#include "PX2E_LogicView.hpp"
#include "PX2E_NirMan.hpp"
#include "PX2Project.hpp"
#include "PX2EditEventType.hpp"
#include "PX2Edit.hpp"
#include "PX2ScriptManager.hpp"
using namespace PX2Editor;
using namespace PX2;

const int sID_LogicViewTimer = PX2_EDIT_GETID;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::LogicView, wxWindow)
BEGIN_EVENT_TABLE(LogicView, wxWindow)
EVT_TIMER(sID_LogicViewTimer, LogicView::OnTimer)
EVT_SIZE(LogicView::OnSize)
EVT_PAINT(LogicView::OnPaint)
EVT_ERASE_BACKGROUND(LogicView::OnEraseBackground)
EVT_LEFT_DOWN(LogicView::OnLeftDown)
EVT_LEFT_UP(LogicView::OnLeftUp)
EVT_MIDDLE_DOWN(LogicView::OnMiddleDown)
EVT_MIDDLE_UP(LogicView::OnMiddleUp)
EVT_MOUSEWHEEL(LogicView::OnMouseWheel)
EVT_RIGHT_DOWN(LogicView::OnRightDown)
EVT_RIGHT_UP(LogicView::OnRightUp)
EVT_MOTION(LogicView::OnMotion)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
LogicView::LogicView()
{
}
//----------------------------------------------------------------------------
LogicView::LogicView(wxWindow *parent) :
wxWindow(parent, -1),
mIsInited(false),
mCameraMoveSpeed(40.0f),
mCurCameraMoveSpeed_W(0.0f),
mCurCameraMoveSpeed_S(0.0f),
mCurCameraMoveSpeed_A(0.0f),
mCurCameraMoveSpeed_D(0.0f),
mIsRightDown(false),
mIsRightDownOnMotion(false),
mEditMenu(0)
{
	mCtrlTimer.SetOwner(this, sID_LogicViewTimer);
	mCtrlTimer.Start(15);
}
//----------------------------------------------------------------------------
LogicView::~LogicView()
{
	if (mEditMenu)
	{
		delete mEditMenu;
		mEditMenu = 0;
	}
}
//----------------------------------------------------------------------------
void LogicView::OnTimer(wxTimerEvent& event)
{
	int ival = event.GetInterval();
	double dIval = ival / 1000.0;

	if (sID_LogicViewTimer == event.GetId())
	{
	}
}
//----------------------------------------------------------------------------
void LogicView::OnSize(wxSizeEvent& e)
{
	wxSize size = e.GetSize();

	//	if (mEditRenderView)
	//	{
	//		mEditRenderView->OnSize(Sizef((float)size.GetWidth(),
	//			(float)size.GetHeight()));
	//	}

	mSize = size;
}
//----------------------------------------------------------------------------
void LogicView::OnPaint(wxPaintEvent& e)
{
	wxPaintDC dc(this);
	PX2_UNUSED(e);
}
//----------------------------------------------------------------------------
void LogicView::OnEraseBackground(wxEraseEvent& e)
{
	if (!mIsInited) return;
	PX2_UNUSED(e);
}
//----------------------------------------------------------------------------
void LogicView::OnLeftDown(wxMouseEvent& e)
{
	SetFocus();

	wxPoint mousePos = e.GetPosition();
	APoint pos = _wxPointToAPoint(mousePos);

	//	if (mEditRenderView)
	{
		//		mEditRenderView->OnLeftDown(pos);
	}
}
//----------------------------------------------------------------------------
void LogicView::OnLeftUp(wxMouseEvent& e)
{
	wxPoint mousePos = e.GetPosition();
	APoint pos = _wxPointToAPoint(mousePos);

	//	if (mEditRenderView)
	{
		//		mEditRenderView->OnLeftUp(pos);
	}
}
//----------------------------------------------------------------------------
void LogicView::OnMiddleDown(wxMouseEvent& e)
{
	SetFocus();

	wxPoint mousePos = e.GetPosition();
	APoint pos = _wxPointToAPoint(mousePos);

	//	if (mEditRenderView)
	{
		//		mEditRenderView->OnMiddleDown(pos);
	}
}
//----------------------------------------------------------------------------
void LogicView::OnMiddleUp(wxMouseEvent& e)
{
	wxPoint mousePos = e.GetPosition();
	APoint pos = _wxPointToAPoint(mousePos);

	//	if (mEditRenderView)
	{
		//		mEditRenderView->OnMiddleUp(pos);
	}
}
//----------------------------------------------------------------------------
void LogicView::OnMouseWheel(wxMouseEvent& e)
{
	float delta = (float)e.GetWheelRotation();

	//	if (mEditRenderView)
	{
		//		mEditRenderView->OnMouseWheel(delta);
	}
}
//----------------------------------------------------------------------------
void LogicView::OnRightDown(wxMouseEvent& e)
{
	mIsRightDown = true;
	mIsRightDownOnMotion = false;

	SetFocus();

	wxPoint mousePos = e.GetPosition();
	APoint pos = _wxPointToAPoint(mousePos);

	//	if (mEditRenderView)
	{
		//		mEditRenderView->OnRightDown(pos);
	}
}
//----------------------------------------------------------------------------
void LogicView::OnRightUp(wxMouseEvent& e)
{
	wxPoint mousePos = e.GetPosition();
	APoint pos = _wxPointToAPoint(mousePos);

	//if (mEditRenderView)
	//{
	//	mEditRenderView->OnRightUp(pos);

	//	if (!mIsRightDownOnMotion)
	//	{
	//		if (mEditMenu)
	//		{
	//			delete mEditMenu;
	//			mEditMenu = 0;
	//		}

	//		mEditMenu = new wxMenu();
	//		NirMan::GetSingleton().SetCurMenu(mEditMenu);

	//		PX2_SM.CallString("CreateStageEditMenu()");

	//		if (mEditMenu) PopupMenu(mEditMenu, mousePos.x, mousePos.y);
	//	}
	//}
}
//----------------------------------------------------------------------------
void LogicView::OnMotion(wxMouseEvent& e)
{
	wxPoint mousePos = e.GetPosition();
	APoint pos = _wxPointToAPoint(mousePos);

	//if (mEditRenderView)
	//{
	//	mEditRenderView->OnMotion(pos);
	//}

	if (mIsRightDown)
	{
		mIsRightDownOnMotion = true;
	}
}
//----------------------------------------------------------------------------
void LogicView::DoExecute(PX2::Event *event)
{
	//if (EditEventSpace::IsEqual(event, EditEventSpace::NewScene) ||
	//	EditEventSpace::IsEqual(event, EditEventSpace::LoadedScene))
	//{
	//	mEditRenderView = 0;

	//	RenderStep *sceneRenderStep = PX2_PROJ.GetSceneRenderStep();
	//	Camera *sceneRenderStepCamera = sceneRenderStep->GetCamera();
	//	Renderer *sceneRenderStepRenderer = sceneRenderStep->GetRenderer();

	//	mEditRenderView = new0 EditRenderView();
	//	mEditRenderView->SetRenderer(sceneRenderStepRenderer);
	//	mEditRenderView->SetCamera(sceneRenderStepCamera);

	//	SetSize(GetSize());
	//}
	//else if (EditEventSpace::IsEqual(event, EditEventSpace::CloseScene))
	//{
	//	mEditRenderView = 0;
	//}
}
//----------------------------------------------------------------------------
APoint LogicView::_wxPointToAPoint(wxPoint &point)
{
	return APoint((float)point.x, 0.0f, (float)(mSize.GetHeight() - point.y));
}
//----------------------------------------------------------------------------