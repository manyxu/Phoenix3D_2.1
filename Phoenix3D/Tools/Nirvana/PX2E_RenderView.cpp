// PX2E_RenderView.cpp

#include "PX2E_RenderView.hpp"
#include "PX2E_NirMan.hpp"
#include "PX2EditRenderView_Scene.hpp"
#include "PX2EditRenderView_UI.hpp"
#include "PX2EditRenderView_Logic.hpp"
#include "PX2EditRenderView_Res.hpp"
#include "PX2Project.hpp"
#include "PX2EditEventType.hpp"
#include "PX2Edit.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2UIPicBox.hpp"
#include "PX2EngineLoop.hpp"
using namespace PX2Editor;
using namespace PX2;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::RenderView, wxWindow)
BEGIN_EVENT_TABLE(RenderView, wxWindow)
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
RenderView::RenderView(RenderViewType viewType, wxWindow *parent) :
wxWindow(parent, wxID_ANY),
mRenderViewType(viewType),
mTimerID(-1),
mIsInited(false),
mIsRightDown(false),
mIsRightDownOnMotion(false),
mEditMenu(0)
{
	mTimerID = PX2_EDIT_GETID;
	Connect(mTimerID, wxEVT_TIMER, wxTimerEventHandler(RenderView::OnTimer));

	mTimer.SetOwner(this, mTimerID);
	mTimer.Start(25);

	PX2_EW.ComeIn(this);
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

	if (mTimerID == event.GetId())
	{
		std::map<std::string, PX2::EditRenderViewPtr>::iterator it
			= mEditRenderViews.begin();
		for (; it != mEditRenderViews.end(); it++)
		{
			EditRenderView *renderView = it->second;
			if (renderView && renderView->IsRenderStepCreated())
			{
				renderView->Tick(dIval);
			}
		}
	}
}
//----------------------------------------------------------------------------
void RenderView::OnSize(wxSizeEvent& e)
{
	mSize = GetSize();

	Sizef sz = Sizef((float)mSize.GetWidth(), (float)mSize.GetHeight());
	
	if (RVT_SCENEUI==mRenderViewType && !mEditRenderViews.empty())
	{
		PX2_ENGINELOOP.SetSize(sz);
	}

	std::map<std::string, PX2::EditRenderViewPtr>::iterator it = mEditRenderViews.begin();
	for (; it != mEditRenderViews.end(); it++)
	{
		it->second->OnSize(sz);
	}
}
//----------------------------------------------------------------------------
void RenderView::OnPaint(wxPaintEvent& e)
{
	wxPaintDC dc(this);
	PX2_UNUSED(e);

	if (mEditRenderViews.empty())
	{
		dc.Clear();
	}
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

	std::map<std::string, PX2::EditRenderViewPtr>::iterator it = mEditRenderViews.begin();
	for (; it != mEditRenderViews.end(); it++)
	{
		it->second->OnLeftDown(pos);
	}
}
//----------------------------------------------------------------------------
void RenderView::OnLeftUp(wxMouseEvent& e)
{
	wxPoint mousePos = e.GetPosition();
	APoint pos = _wxPointToAPoint(mousePos);

	std::map<std::string, PX2::EditRenderViewPtr>::iterator it = mEditRenderViews.begin();
	for (; it != mEditRenderViews.end(); it++)
	{
		it->second->OnLeftUp(pos);
	}
}
//----------------------------------------------------------------------------
void RenderView::OnMiddleDown(wxMouseEvent& e)
{
	SetFocus();

	wxPoint mousePos = e.GetPosition();
	APoint pos = _wxPointToAPoint(mousePos);

	std::map<std::string, PX2::EditRenderViewPtr>::iterator it = mEditRenderViews.begin();
	for (; it != mEditRenderViews.end(); it++)
	{
		it->second->OnMiddleDown(pos);
	}
}
//----------------------------------------------------------------------------
void RenderView::OnMiddleUp(wxMouseEvent& e)
{
	wxPoint mousePos = e.GetPosition();
	APoint pos = _wxPointToAPoint(mousePos);

	std::map<std::string, PX2::EditRenderViewPtr>::iterator it = mEditRenderViews.begin();
	for (; it != mEditRenderViews.end(); it++)
	{
		it->second->OnMiddleUp(pos);
	}
}
//----------------------------------------------------------------------------
void RenderView::OnMouseWheel(wxMouseEvent& e)
{
	float delta = (float)e.GetWheelRotation()*0.03f;

	std::map<std::string, PX2::EditRenderViewPtr>::iterator it = mEditRenderViews.begin();
	for (; it != mEditRenderViews.end(); it++)
	{
		it->second->OnMouseWheel(delta);
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

	std::map<std::string, PX2::EditRenderViewPtr>::iterator it = mEditRenderViews.begin();
	for (; it != mEditRenderViews.end(); it++)
	{
		it->second->OnRightDown(pos);
	}
}
//----------------------------------------------------------------------------
void RenderView::OnRightUp(wxMouseEvent& e)
{
	wxPoint mousePos = e.GetPosition();
	APoint pos = _wxPointToAPoint(mousePos);

	std::map<std::string, PX2::EditRenderViewPtr>::iterator it = mEditRenderViews.begin();
	for (; it != mEditRenderViews.end(); it++)
	{
		it->second->OnRightUp(pos);
	}

	if (RVT_SCENEUI == mRenderViewType)
	{
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

	std::map<std::string, PX2::EditRenderViewPtr>::iterator it = mEditRenderViews.begin();
	for (; it != mEditRenderViews.end(); it++)
	{
		it->second->OnMotion(pos);
	}

	if (mIsRightDown)
	{
		mIsRightDownOnMotion = true;
	}
}
//----------------------------------------------------------------------------
void RenderView::DoExecute(PX2::Event *event)
{
	if (EditEventSpace::IsEqual(event, EditEventSpace::NewProject))
	{
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::LoadedProject))
	{
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::CloseProject))
	{
		Refresh();
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::NewScene) ||
		EditEventSpace::IsEqual(event, EditEventSpace::LoadedScene))
	{
		if (RVT_SCENEUI == mRenderViewType)
		{
			_NewEditRenderView("Scene");
		}
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::CloseScene))
	{
		if (RVT_SCENEUI == mRenderViewType)
		{
			_CloseEidtRenderView("Scene");
		}
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::NewUI) ||
		EditEventSpace::IsEqual(event, EditEventSpace::LoadedUI))
	{
		if (RVT_SCENEUI == mRenderViewType)
		{
			_NewEditRenderView("UI");
		}
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::CloseUI))
	{
		if (RVT_SCENEUI == mRenderViewType)
		{
			_CloseEidtRenderView("UI");
		}
	}
}
//----------------------------------------------------------------------------
APoint RenderView::_wxPointToAPoint(wxPoint &point)
{
	return APoint((float)point.x, 0.0f, (float)(mSize.GetHeight() - point.y));
}
//----------------------------------------------------------------------------
void RenderView::_CloseEidtRenderView(const std::string &name)
{
	std::map<std::string, PX2::EditRenderViewPtr>::iterator it
		= mEditRenderViews.find(name);
	if (it != mEditRenderViews.end())
	{
		mEditRenderViews.erase(it);
	}
}
//----------------------------------------------------------------------------
void RenderView::_NewEditRenderView(const std::string &name)
{
	wxSize size = GetClientSize();
	Sizef sz(size.x, size.y);

	EditRenderView *renderView = 0;
	if ("Scene" == name)
	{
		RenderStep *rs_Scene = PX2_PROJ.GetSceneRenderStep();
		Renderer *rsRender_Scene = rs_Scene->GetRenderer();
		Camera *rsCamera_Scene = rs_Scene->GetCamera();

		renderView = new0 EditRenderView_Scene();
		renderView->SetRenderStep(rs_Scene);
		renderView->SetRenderer(rsRender_Scene);
		renderView->SetCamera(rsCamera_Scene);
	}
	else if ("UI" == name)
	{
		const Sizef &projSize = PX2_PROJ.GetSize();

		UIView *rs_UI = PX2_PROJ.GetUIRenderStep();
		Renderer *rs_Render_UI = rs_UI->GetRenderer();
		Camera *rs_Camera_UI = rs_UI->GetCamera();
		CameraNode *rs_CameraNode_UI = rs_UI->GetCameraNode();

		rs_UI->SetCameraAutoAdjust(false);
		rs_UI->SetCameraFrustumSize(sz);

		renderView = new0 EditRenderView_UI();
		renderView->SetRenderStep(rs_UI);
		renderView->SetRenderer(rs_Render_UI);
		renderView->SetCamera(rs_Camera_UI);

		rs_CameraNode_UI->LocalTransform.SetTranslateXZ(
			projSize.Width / 2.0f, projSize.Height / 2.0f);
	}
	else if ("Res" == name)
	{
		renderView = new0 EditRenderView_Res();

		renderView->SetPt_Data(GetHandle());
		renderView->SetPt_Size(sz);
		
		renderView->InitlizeRendererStep();
	}

	renderView->OnSize(sz);

	mEditRenderViews[name] = renderView;

	if (RVT_SCENEUI == mRenderViewType && !mEditRenderViews.empty())
	{
		PX2_ENGINELOOP.SetSize(sz);
	}
}
//----------------------------------------------------------------------------