// PX2UICaptionFrame.cpp

#include "PX2UITitleFrame.hpp"
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

	mPB_Logo = new0 UIPicBox();
	AttachChild(mPB_Logo);
	mPB_Logo->LocalTransform.SetTranslateY(-1.0f);
	mPB_Logo->SetTexture("Data/engine/phoenix.png");
	mPB_Logo->SetSize(20.0f, 20.0f);

	mT_Title = new0 UIText();
	AttachChild(mT_Title);
	mT_Title->SetText("Nirvana - Phoenix Engine Editor");
	mT_Title->SetFontWidthHeight(12, 12);
	mT_Title->SetRectUseage(UIText::RU_ALIGNS);
	mT_Title->SetAligns(TEXTALIGN_LEFT | TEXTALIGN_VCENTER);
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
	mPB_Logo->LocalTransform.SetTranslateXZ(mSize.Height / 2.0f, -mSize.Height / 2.0f);

	float t_titleLeft = 40.0f;
	mT_Title->SetRect(Rectf(t_titleLeft, -mSize.Height, mSize.Width, 0.0f));
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