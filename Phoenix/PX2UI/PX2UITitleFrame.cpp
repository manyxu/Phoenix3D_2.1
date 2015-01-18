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
	SetSizeRelativeType(SRT_H);

	mPB_Back = new0 UIPicBox();
	AttachChild(mPB_Back);
	mPB_Back->SetTexture("Data/engine/white.png");
	mPB_Back->SetAnchorPoint(0.0f, 0.0f);
	mPB_Back->SetColor(Float3::MakeColor(45, 45, 45));

	mB_Table = new0 UIButton();
	AttachChild(mB_Table);
	mB_Table->LocalTransform.SetTranslateY(-1.0f);
	mB_Table->SetWidth(150.0f);
	mB_Table->SetSizeRelativeType(UISizeFrame::SRT_V);

	mPB_Icon = new0 UIPicBox();
	AttachChild(mPB_Icon);
	mPB_Icon->LocalTransform.SetTranslateY(-3.0f);
	mPB_Icon->SetTexture("Data/engine/phoenix.png");
	mPB_Icon->SetSize(20.0f, 20.0f);

	mT_Title = new0 UIText();
	AttachChild(mT_Title);
	mT_Title->LocalTransform.SetTranslateY(-3.0f);
	mT_Title->SetColor(Float3::WHITE);
	mT_Title->SetText("Nirvana - Phoenix Engine Editor");
	mT_Title->SetFontWidthHeight(12, 12);
	mT_Title->SetRectUseage(UIText::RU_ALIGNS);
	mT_Title->SetAligns(TEXTALIGN_LEFT | TEXTALIGN_VCENTER);

	Sizef mcButSize(30.0f, 25.0f);
	mB_Close = new0 UIButton();
	AttachChild(mB_Close);
	mB_Close->SetSize(mcButSize);
	mB_Close->LocalTransform.SetTranslateY(-4.0f);
	mB_Close->SetRelativeType_H(UISizeFrame::LT_ONE);
	mB_Close->SetRelativeValue_H(-mcButSize.Width / 2.0f);
	mB_Close->SetRelativeType_V(UISizeFrame::LT_ONE);
	mB_Close->SetRelativeValue_V(-mcButSize.Height / 2.0f);

	mB_Max = new0 UIButton();
	AttachChild(mB_Max);
	mB_Max->SetSize(mcButSize);
	mB_Max->LocalTransform.SetTranslateY(-4.0f);
	mB_Max->SetRelativeType_H(UISizeFrame::LT_ONE);
	mB_Max->SetRelativeValue_H(-mcButSize.Width / 2.0f - mcButSize.Width);
	mB_Max->SetRelativeType_V(UISizeFrame::LT_ONE);
	mB_Max->SetRelativeValue_V(-mcButSize.Height / 2.0f);

	mB_Min = new0 UIButton();
	AttachChild(mB_Min);
	mB_Min->SetSize(mcButSize);
	mB_Min->LocalTransform.SetTranslateY(-4.0f);
	mB_Min->SetRelativeType_H(UISizeFrame::LT_ONE);
	mB_Min->SetRelativeValue_H(-mcButSize.Width / 2.0f - mcButSize.Width*2.0f);
	mB_Min->SetRelativeType_V(UISizeFrame::LT_ONE);
	mB_Min->SetRelativeValue_V(-mcButSize.Height / 2.0f);
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

	mB_Table->LocalTransform.SetTranslateXZ(75.0f, mSize.Height / 2.0f);

	mPB_Icon->LocalTransform.SetTranslateXZ(mSize.Height / 2.0f, mSize.Height / 2.0f);

	float t_titleLeft = 40.0f;
	mT_Title->SetRect(Rectf(t_titleLeft, 0.0f, mSize.Width, mSize.Height));
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