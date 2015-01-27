// PX2E_RenderView.cpp

#include "PX2E_RenderView.hpp"
#include "PX2E_NirMan.hpp"
#include "PX2Project.hpp"
#include "PX2EditEventType.hpp"
#include "PX2Edit.hpp"
#include "PX2ScriptManager.hpp"
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
mCurCameraMoveSpeed_D(0.0f),
mIsRightDown(false),
mIsRightDownOnMotion(false),
mEditMenu(0)
{
	mCtrlTimer.SetOwner(this, sID_CTRLTIMER);
	mCtrlTimer.Start(15);
}
//----------------------------------------------------------------------------
RenderView::~RenderView()
{
	if (mEditMenu)
	{
		delete mEditMenu;
		mEditMenu = 0;
	}
}
//----------------------------------------------------------------------------
void RenderView::OnTimer(wxTimerEvent& event)
{
	int ival = event.GetInterval();
	double dIval = ival / 1000.0;

	if (sID_CTRLTIMER == event.GetId())
	{
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
	mIsRightDown = true;
	mIsRightDownOnMotion = false;

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

		if (!mIsRightDownOnMotion)
		{
			if (mEditMenu)
			{
				delete mEditMenu;
				mEditMenu = 0;
			}

			mEditMenu = new wxMenu();
			NirMan::GetSingleton().SetCurMenu(mEditMenu);

			PX2_SM.CallString("CreateStageEditMenu()");

			if (mEditMenu) PopupMenu(mEditMenu, mousePos.x, mousePos.y);
		}
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

	if (mIsRightDown)
	{
		mIsRightDownOnMotion = true;
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
APoint RenderView::_wxPointToAPoint(wxPoint &point)
{
	return APoint((float)point.x, 0.0f, (float)(mSize.GetHeight() - point.y));
}
//----------------------------------------------------------------------------