// PX2E_RenderView.cpp

#include "PX2E_UIRenderView.hpp"
#include "PX2E_NirMan.hpp"
#include "PX2Project.hpp"
#include "PX2EditEventType.hpp"
#include "PX2Edit.hpp"
#include "PX2ScriptManager.hpp"
using namespace PX2Editor;
using namespace PX2;

const int sID_UIRenderViewTimer = PX2_EDIT_GETID;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::UIRenderView, wxWindow)
BEGIN_EVENT_TABLE(UIRenderView, wxWindow)
EVT_TIMER(sID_UIRenderViewTimer, UIRenderView::OnTimer)
EVT_SIZE(UIRenderView::OnSize)
EVT_PAINT(UIRenderView::OnPaint)
EVT_ERASE_BACKGROUND(UIRenderView::OnEraseBackground)
EVT_LEFT_DOWN(UIRenderView::OnLeftDown)
EVT_LEFT_UP(UIRenderView::OnLeftUp)
EVT_MIDDLE_DOWN(UIRenderView::OnMiddleDown)
EVT_MIDDLE_UP(UIRenderView::OnMiddleUp)
EVT_MOUSEWHEEL(UIRenderView::OnMouseWheel)
EVT_RIGHT_DOWN(UIRenderView::OnRightDown)
EVT_RIGHT_UP(UIRenderView::OnRightUp)
EVT_MOTION(UIRenderView::OnMotion)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
UIRenderView::UIRenderView()
{
}
//----------------------------------------------------------------------------
UIRenderView::UIRenderView(wxWindow *parent) :
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
	mCtrlTimer.SetOwner(this, sID_UIRenderViewTimer);
	mCtrlTimer.Start(15);
}
//----------------------------------------------------------------------------
UIRenderView::~UIRenderView()
{
	if (mEditMenu)
	{
		delete mEditMenu;
		mEditMenu = 0;
	}
}
//----------------------------------------------------------------------------
void UIRenderView::OnTimer(wxTimerEvent& event)
{
	int ival = event.GetInterval();
	double dIval = ival / 1000.0;

	if (sID_UIRenderViewTimer == event.GetId())
	{
	}
}
//----------------------------------------------------------------------------
void UIRenderView::OnSize(wxSizeEvent& e)
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
void UIRenderView::OnPaint(wxPaintEvent& e)
{
	wxPaintDC dc(this);
	PX2_UNUSED(e);
}
//----------------------------------------------------------------------------
void UIRenderView::OnEraseBackground(wxEraseEvent& e)
{
	if (!mIsInited) return;
	PX2_UNUSED(e);
}
//----------------------------------------------------------------------------
void UIRenderView::OnLeftDown(wxMouseEvent& e)
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
void UIRenderView::OnLeftUp(wxMouseEvent& e)
{
	wxPoint mousePos = e.GetPosition();
	APoint pos = _wxPointToAPoint(mousePos);

//	if (mEditRenderView)
	{
//		mEditRenderView->OnLeftUp(pos);
	}
}
//----------------------------------------------------------------------------
void UIRenderView::OnMiddleDown(wxMouseEvent& e)
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
void UIRenderView::OnMiddleUp(wxMouseEvent& e)
{
	wxPoint mousePos = e.GetPosition();
	APoint pos = _wxPointToAPoint(mousePos);

//	if (mEditRenderView)
	{
//		mEditRenderView->OnMiddleUp(pos);
	}
}
//----------------------------------------------------------------------------
void UIRenderView::OnMouseWheel(wxMouseEvent& e)
{
	float delta = (float)e.GetWheelRotation();

//	if (mEditRenderView)
	{
//		mEditRenderView->OnMouseWheel(delta);
	}
}
//----------------------------------------------------------------------------
void UIRenderView::OnRightDown(wxMouseEvent& e)
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
void UIRenderView::OnRightUp(wxMouseEvent& e)
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
void UIRenderView::OnMotion(wxMouseEvent& e)
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
void UIRenderView::DoExecute(PX2::Event *event)
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
APoint UIRenderView::_wxPointToAPoint(wxPoint &point)
{
	return APoint((float)point.x, 0.0f, (float)(mSize.GetHeight() - point.y));
}
//----------------------------------------------------------------------------