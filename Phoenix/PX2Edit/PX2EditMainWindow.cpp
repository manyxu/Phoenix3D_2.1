// PX2EditMainWindow.cpp

#include "PX2EditMainWindow.hpp"
using namespace PX2;
using namespace std;

PX2_IMPLEMENT_RTTI(PX2, UIWindowFrame, EditMainWindow);
PX2_IMPLEMENT_STREAM(EditMainWindow);
PX2_IMPLEMENT_FACTORY(EditMainWindow);

//----------------------------------------------------------------------------
EditMainWindow::EditMainWindow()
{
	mPB_Back = new0 UIPicBox();
	AttachChild(mPB_Back);
	mPB_Back->SetAnchorPoint(0.0f, 0.0f);
	mPB_Back->SetTexture("Data/engine/white.png");
	mPB_Back->SetColor(Float3::MakeColor(49, 52, 57));

	// title
	mTitleHeight = 30.0f;
	mEditTitleFrame = new0 EditTitleFrame();
	SetTitleFrame(mEditTitleFrame);
	mEditTitleFrame->LocalTransform.SetTranslateY(-1.0f);
	mEditTitleFrame->SetSize(0.0f, mTitleHeight);
	mEditTitleFrame->SetRelativeType_V(UISizeFrame::LT_ONE);
	mEditTitleFrame->SetRelativeValue_V(-mTitleHeight);
	mEditTitleFrame->SetSizeRelativeType(UISizeFrame::SRT_H);

	// menu bar
	mMenuBarHeight = 20.0f;
	mMenuBar = new0 UIMenuBar();
	AttachChild(mMenuBar);
	mMenuBar->GetBackPicBox()->SetTexture("Data/editor/menu/menubar_back.png");
	mMenuBar->LocalTransform.SetTranslateY(-1.0f);
	mMenuBar->SetSize(0.0f, mMenuBarHeight);
	mMenuBar->SetRelativeType_V(UISizeFrame::LT_ONE);
	mMenuBar->SetRelativeValue_V(-mTitleHeight - mMenuBarHeight);
	mMenuBar->SetSizeRelativeType(UISizeFrame::SRT_H);

	EditMenuItem *menuFile = new0 EditMenuItem("File", "File");
	menuFile->SetWidth(60.0f);
	mMenuBar->AddItem(menuFile);

	EditMenuItem *menuWindow = new0 EditMenuItem("Windows", "Windows");
	menuWindow->SetWidth(60.0f);
	mMenuBar->AddItem(menuWindow);

	EditMenuItem *menuHelp = new0 EditMenuItem("Help", "Help");
	menuHelp->SetWidth(60.0f);
	mMenuBar->AddItem(menuHelp);

	// AuiMain
	mMainAuiFrame = new0 UIAuiFrame();
	AttachChild(mMainAuiFrame);

	// SceneTree
	mSceneTree = new0 EditSceneTree();
	mMainAuiFrame->AddFrame(UIAuiFrame::APT_LEFT, mSceneTree);
	mMainAuiFrame->SetSizeRelativeType(UISizeFrame::SRT_HV);
	mMainAuiFrame->SetSizeRelativeVal_V(-mTitleHeight - mMenuBarHeight);

	mMainAuiFrame->AddFrame(UIAuiFrame::APT_CENTER, new0 EditSceneTree());
}
//----------------------------------------------------------------------------
EditMainWindow::~EditMainWindow()
{
}
//----------------------------------------------------------------------------
void EditMainWindow::OnParentSizeChanged(const Sizef &parentSize,
	const Sizef &parentBorderSize)
{
	UIWindowFrame::OnParentSizeChanged(parentSize, parentBorderSize);

	const Sizef &size = GetSize();
	mPB_Back->SetSize(size);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
EditMainWindow::EditMainWindow(LoadConstructor value) :
UIWindowFrame(value)
{
}
//----------------------------------------------------------------------------
void EditMainWindow::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UIWindowFrame::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(EditMainWindow, source);
}
//----------------------------------------------------------------------------
void EditMainWindow::Link(InStream& source)
{
	UIWindowFrame::Link(source);
}
//----------------------------------------------------------------------------
void EditMainWindow::PostLink()
{
	UIWindowFrame::PostLink();
}
//----------------------------------------------------------------------------
bool EditMainWindow::Register(OutStream& target) const
{
	return UIWindowFrame::Register(target);
}
//----------------------------------------------------------------------------
void EditMainWindow::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UIWindowFrame::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(EditMainWindow, target);
}
//----------------------------------------------------------------------------
int EditMainWindow::GetStreamingSize(Stream &stream) const
{
	int size = UIWindowFrame::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------