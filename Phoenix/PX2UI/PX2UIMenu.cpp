// PX2UIMenu.cpp

#include "PX2UIMenu.hpp"
#include "PX2UIButton.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, UISizeFrame, UIMenuBar);
PX2_IMPLEMENT_STREAM(UIMenuBar);
PX2_IMPLEMENT_FACTORY(UIMenuBar);
PX2_IMPLEMENT_DEFAULT_NAMES(UISizeFrame, UIMenuBar)

//----------------------------------------------------------------------------
UIMenuBar::UIMenuBar()
{
	mPB_Back = new0 UIPicBox();
	AttachChild(mPB_Back);
	mPB_Back->SetPicBoxType(UIPicBox::PBT_NINE);
	mPB_Back->SetAnchorPoint(0.0f, 0.0f);
}
//----------------------------------------------------------------------------
UIMenuBar::~UIMenuBar()
{
}
//----------------------------------------------------------------------------
UIPicBox *UIMenuBar::GetBackPicBox()
{
	return mPB_Back;
}
//----------------------------------------------------------------------------
void UIMenuBar::AddItem(UIMenuItem *item)
{
	item->LocalTransform.SetTranslateY(-1.0f);
	AttachChild(item);

	_SortItemsPos();
}
//----------------------------------------------------------------------------
void UIMenuBar::OnParentSizeChanged(const Sizef &parentSize,
	const Sizef &parentBorderSize)
{
	UISizeFrame::OnParentSizeChanged(parentSize, parentBorderSize);

	mPB_Back->SetSize(mSize);
}
//----------------------------------------------------------------------------
void UIMenuBar::_SortItemsPos()
{
	float xStart = 0.0f;
	for (int i = 0; i < GetNumChildren(); i++)
	{
		UISizeFrame *sizeFrame = DynamicCast<UISizeFrame>(GetChild(i));
		if (sizeFrame)
		{
			sizeFrame->LocalTransform.SetTranslateX(xStart);
			xStart += sizeFrame->GetWidth();
		}
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UIMenuBar::UIMenuBar(LoadConstructor value)
:
UISizeFrame(value)
{
}
//----------------------------------------------------------------------------
void UIMenuBar::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UISizeFrame::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(UIMenuBar, source);
}
//----------------------------------------------------------------------------
void UIMenuBar::Link(InStream& source)
{
	UISizeFrame::Link(source);
}
//----------------------------------------------------------------------------
void UIMenuBar::PostLink()
{
	UISizeFrame::PostLink();
}
//----------------------------------------------------------------------------
bool UIMenuBar::Register(OutStream& target) const
{
	return UISizeFrame::Register(target);
}
//----------------------------------------------------------------------------
void UIMenuBar::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UISizeFrame::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(UIMenuBar, target);
}
//----------------------------------------------------------------------------
int UIMenuBar::GetStreamingSize(Stream &stream) const
{
	int size = UISizeFrame::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------