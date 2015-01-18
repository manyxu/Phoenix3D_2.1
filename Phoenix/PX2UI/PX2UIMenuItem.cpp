// PX2UIMenuItem.cpp

#include "PX2UIMenuItem.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, UISizeFrame, UIMenuItem);
PX2_IMPLEMENT_STREAM(UIMenuItem);
PX2_IMPLEMENT_FACTORY(UIMenuItem);
PX2_IMPLEMENT_DEFAULT_NAMES(UISizeFrame, UIMenuItem)

//----------------------------------------------------------------------------
UIMenuItem::UIMenuItem(const std::string &name, const std::string &text)
{
	SetName(name);

	mPB_Pressed = new0 UIPicBox();
	AttachChild(mPB_Pressed);
	mPB_Pressed->SetAnchorPoint(0.0f, 0.0f);
	mPB_Pressed->Show(false);

	mT_Text = new0 UIText();
	AttachChild(mT_Text);
	mT_Text->SetFontWidthHeight(12, 12);
	mT_Text->SetColor(Float3::WHITE);
	mT_Text->SetAligns(TEXTALIGN_HCENTER | TEXTALIGN_VCENTER);
	mT_Text->SetRectUseage(UIText::RU_ALIGNS);
	mT_Text->SetText(text);

	SetSizeRelativeType(UISizeFrame::SRT_V);
}
//----------------------------------------------------------------------------
UIMenuItem::~UIMenuItem()
{
}
//----------------------------------------------------------------------------
void UIMenuItem::OnSizeChanged()
{
	UISizeFrame::OnSizeChanged();

	const Sizef &size = GetSize();

	mPB_Pressed->SetSize(size);
	mT_Text->SetRect(Rectf(0.0f, 0.0f, size.Width, size.Height));
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UIMenuItem::UIMenuItem(LoadConstructor value)
:
UISizeFrame(value)
{
}
//----------------------------------------------------------------------------
void UIMenuItem::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UISizeFrame::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(UIMenuItem, source);
}
//----------------------------------------------------------------------------
void UIMenuItem::Link(InStream& source)
{
	UISizeFrame::Link(source);
}
//----------------------------------------------------------------------------
void UIMenuItem::PostLink()
{
	UISizeFrame::PostLink();
}
//----------------------------------------------------------------------------
bool UIMenuItem::Register(OutStream& target) const
{
	return UISizeFrame::Register(target);
}
//----------------------------------------------------------------------------
void UIMenuItem::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UISizeFrame::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(UIMenuItem, target);
}
//----------------------------------------------------------------------------
int UIMenuItem::GetStreamingSize(Stream &stream) const
{
	int size = UISizeFrame::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------