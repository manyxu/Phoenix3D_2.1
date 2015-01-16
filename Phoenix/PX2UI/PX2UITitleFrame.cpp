// PX2UICaptionFrame.cpp

#include "PX2UICaptionFrame.hpp"
#include "PX2UIPicBox.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, UISizeFrame, UITitleFrame);
PX2_IMPLEMENT_STREAM(UITitleFrame);
PX2_IMPLEMENT_FACTORY(UITitleFrame);

//----------------------------------------------------------------------------
UITitleFrame::UITitleFrame()
{
	mPB_Back = new0 UIPicBox();
	AttachChild(mPB_Back);
	mPB_Back->SetTexture("Data/engine/white.png");
	mPB_Back->SetAnchorPoint(0.0f, 1.0f);
	mPB_Back->SetColor(Float3::MakeColor(214, 219, 230));
}
//----------------------------------------------------------------------------
UITitleFrame::~UITitleFrame()
{
}
//----------------------------------------------------------------------------
void UITitleFrame::OnParentSizeChanged(const Sizef &parentSize,
	const Sizef &parentBorderSize)
{
	UISizeFrame::OnParentSizeChanged(parentSize, parentBorderSize);

	mPB_Back->SetSize(mSize);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UITitleFrame::UITitleFrame(LoadConstructor value)
:
UISizeFrame(value)
{
}
//----------------------------------------------------------------------------
void UITitleFrame::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UISizeFrame::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(UITitleFrame, source);
}
//----------------------------------------------------------------------------
void UITitleFrame::Link(InStream& source)
{
	UISizeFrame::Link(source);
}
//----------------------------------------------------------------------------
void UITitleFrame::PostLink()
{
	UISizeFrame::PostLink();
}
//----------------------------------------------------------------------------
bool UITitleFrame::Register(OutStream& target) const
{
	return UISizeFrame::Register(target);
}
//----------------------------------------------------------------------------
void UITitleFrame::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UISizeFrame::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(UITitleFrame, target);
}
//----------------------------------------------------------------------------
int UITitleFrame::GetStreamingSize(Stream &stream) const
{
	int size = UISizeFrame::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------