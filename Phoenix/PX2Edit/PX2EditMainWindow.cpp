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
	mPB_Back->SetColor(Float3::MakeColor(41, 57, 85));
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

	mPB_Back->SetSize(GetSize());
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