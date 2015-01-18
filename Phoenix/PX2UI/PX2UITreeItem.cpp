// PX2UITreeItem.cpp

#include "PX2UITreeItem.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, UISizeFrame, UITreeItem);
PX2_IMPLEMENT_STREAM(UITreeItem);
PX2_IMPLEMENT_FACTORY(UITreeItem);

//----------------------------------------------------------------------------
UITreeItem::UITreeItem()
{
	Sizef sizeItem(200.0f, 20.0f);

	mBT_Arrow = new0 UIButton();
	AttachChild(mBT_Arrow);
	mBT_Arrow->SetSize(16.0f, 16.0f);

	mPB_Icon = new0 UIPicBox();
	AttachChild(mPB_Icon);
	mPB_Icon->SetSize(16.0f, 16.0f);

	mT_Text = new0 UIText();
	AttachChild(mT_Text);
	mT_Text->SetColor(Float3::WHITE);
	mT_Text->SetFontWidthHeight(12, 12);
	mT_Text->SetRectUseage(UIText::RU_ALIGNS);

	SetSize(sizeItem);
}
//----------------------------------------------------------------------------
UITreeItem::~UITreeItem()
{
}
//----------------------------------------------------------------------------
void UITreeItem::OnSizeChanged()
{
	UISizeFrame::OnSizeChanged();

	const Sizef &size = GetSize();

	Sizef arrowSize = mBT_Arrow->GetSize();
	mBT_Arrow->LocalTransform.SetTranslateXZ(arrowSize.Width / 2.0f, size.Height / 2.0f);

	Sizef iconSize = mPB_Icon->GetSize();
	mPB_Icon->SetSize(iconSize);
	mPB_Icon->LocalTransform.SetTranslateXZ(arrowSize.Width + iconSize.Width / 2.0f, size.Height / 2.0f);

	mT_Text->SetRect(Rectf(0.0f, 0.0f, size.Width, size.Height));
	mT_Text->LocalTransform.SetTranslateX(arrowSize.Width + iconSize.Width);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UITreeItem::UITreeItem(LoadConstructor value)
:
UISizeFrame(value)
{
}
//----------------------------------------------------------------------------
void UITreeItem::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UISizeFrame::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(UITreeItem, source);
}
//----------------------------------------------------------------------------
void UITreeItem::Link(InStream& source)
{
	UISizeFrame::Link(source);
}
//----------------------------------------------------------------------------
void UITreeItem::PostLink()
{
	UISizeFrame::PostLink();
}
//----------------------------------------------------------------------------
bool UITreeItem::Register(OutStream& target) const
{
	return UISizeFrame::Register(target);
}
//----------------------------------------------------------------------------
void UITreeItem::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UISizeFrame::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(UITreeItem, target);
}
//----------------------------------------------------------------------------
int UITreeItem::GetStreamingSize(Stream &stream) const
{
	int size = UISizeFrame::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------