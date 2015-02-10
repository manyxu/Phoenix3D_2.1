// PX2UIEditBox.cpp

#include "PX2UIEditBox.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI_V(PX2, UIFrame, UIEditBox, 1);
PX2_IMPLEMENT_STREAM(UIEditBox);
PX2_IMPLEMENT_FACTORY(UIEditBox);
PX2_IMPLEMENT_DEFAULT_NAMES(UIFrame, UIEditBox);

//----------------------------------------------------------------------------
void UIEditBoxInputStaticTextCallback(UIInputText *inputText, 
	UIInputTextCallType type)
{
	UIEditBox *editBox = DynamicCast<UIEditBox>(inputText->GetParent());
	if (!editBox) return;

	if (UIITCT_ATTACHWITHIME == type)
	{
		editBox->OnAttachWithIME();
	}
	else if (UIITCT_DETACHWITHWITHIME == type)
	{
		editBox->OnDetachWithIME();
	}
	else if (UIITCT_INSERTTEXT == type)
	{
		editBox->OnTextChanged();
	}
	else if (UIITCT_DELETEBACKWARD == type)
	{
		editBox->OnTextChanged();
	}
	else if (UIITCT_ENTER == type)
	{
		editBox->OnEnter();
	}
}
//----------------------------------------------------------------------------
UIEditBox::UIEditBox() :
mFadePicBoxStartX(6.0f),
mFixedWidth(-1.0f)
{
	SetName("UIEditBox");

	UIPicBoxPtr backPicBox = new0 UIPicBox("Data/engine/common.xml", "editbox_back");
	backPicBox->SetName("EditBoxBack");
	backPicBox->SetPicBoxType(UIPicBox::PBT_NINE);
	backPicBox->SetAnchorPoint(0.0f, 0.0f);
	backPicBox->SetTexCornerSize(4.0f, 4.0f);
	backPicBox->LocalTransform.SetTranslate(APoint(0.0f, 2.0f, 0.0f));
	SetBackPicBox(backPicBox);

	UIPicBoxPtr fadePicBox = new0 UIPicBox("Data/engine/white.png");
	fadePicBox->SetColor(Float3::BLACK);
	fadePicBox->LocalTransform.SetTranslate(APoint(mFadePicBoxStartX, -2.0f, 0.0f));
	fadePicBox->SetAnchorPoint(0.5f, 0.5f);
	fadePicBox->SetName("EditBoxFadeRect");
	mFadeCtrl = new0 InterpCurveAlphaController();
	mFadeCtrl->mValues.Reset();
	mFadeCtrl->mValues.AddPoint(0.0f, 1.0f, 0.0f, 0.0f, ICM_CONSTANT);
	mFadeCtrl->mValues.AddPoint(0.5f, 0.0f, 0.0f, 0.0f, ICM_CONSTANT);
	mFadeCtrl->Repeat = Controller::RT_WRAP;
	mFadeCtrl->MaxTime = 1.0f;
	mFadeCtrl->SetRelatively(false);
	fadePicBox->AttachController(mFadeCtrl);
	mFadeCtrl->ResetPlay();
	SetFadePicBox(fadePicBox);
	mFadePicBox->Show(false);

	mInputText = new0 UIInputText();
	mInputText->SetName("EditBoxInputText");
	mInputText->SetRectUseage(UIText::RU_ALIGNS);
	mInputText->SetAligns(TEXTALIGN_LEFT | TEXTALIGN_VCENTER);
	mInputText->SetFontWidth(20);
	mInputText->SetFontHeight(20);
	mInputText->LocalTransform.SetTranslate(APoint(8.0f, -4.0f, -1.0f));
	AttachChild(mInputText);
	mInputText->SetCallback(UIEditBoxInputStaticTextCallback);

	SetSize(150.0f, 30.0f);
}
//----------------------------------------------------------------------------
UIEditBox::~UIEditBox()
{
}
//----------------------------------------------------------------------------
void UIEditBox::SetPassword(bool isPassword)
{
	return mInputText->SetPassword(isPassword);
}
//----------------------------------------------------------------------------
bool UIEditBox::IsPassword() const
{
	return mInputText->IsPassword();
}
//----------------------------------------------------------------------------
void UIEditBox::Enable(bool enable)
{
	UIFrame::Enable(enable);

	if (!enable)
	{
		mFadePicBox->Show(false);
		mInputText->DetachWithIME();
	}
}
//----------------------------------------------------------------------------
void UIEditBox::SetBackPicBox(UIPicBox *picBox)
{
	if (mBackPicBox)
	{
		DetachChild(mBackPicBox);
	}

	mBackPicBox = picBox;

	AttachChild(mBackPicBox);
}
//----------------------------------------------------------------------------
void UIEditBox::SetFadePicBox(UIPicBox *picBox)
{
	if (mFadePicBox)
	{
		DetachChild(mFadePicBox);
	}

	mFadePicBox = picBox;

	if (mFadePicBox)
		AttachChild(mFadePicBox);
}
//----------------------------------------------------------------------------
const std::string &UIEditBox::GetText() const
{
	return mInputText->GetText();
}
//----------------------------------------------------------------------------
const std::string &UIEditBox::GetRealText() const
{
	return mInputText->GetRealText();
}
//----------------------------------------------------------------------------
void UIEditBox::OnSizeChanged()
{
	if (mBackPicBox)
	{
		mBackPicBox->SetSize(mSize);
	}

	if (mFadePicBox)
	{
		APoint pos = mFadePicBox->LocalTransform.GetTranslate();
		pos.Z() = mSize.Height*0.5f;
		mFadePicBox->LocalTransform.SetTranslate(pos);
		mFadePicBox->SetSize(2.0f, mSize.Height*0.8f);
	}

	if (mInputText)
	{
		std::string realText = mInputText->GetRealText();
		mInputText->SetRect(Rectf(0.0f, 0.0f, mSize.Width, mSize.Height));
		mInputText->SetText(realText);
	}
}
//----------------------------------------------------------------------------
void UIEditBox::SetText(const std::string &text)
{
	mInputText->SetRealText(text);

	if (mFadePicBox)
	{
		float width = mInputText->GetTextWidth();
		width += 1.0f;
		const APoint &curPos = mFadePicBox->LocalTransform.GetTranslate();

		mFadePicBox->LocalTransform.SetTranslate(APoint(mFadePicBoxStartX
			+ width, curPos.Y(), curPos.Z()));
	}
}
//----------------------------------------------------------------------------
void UIEditBox::SetFixedWidth(float fixedWidth)
{
	mFixedWidth = fixedWidth;

	if (mInputText)
	{
		mInputText->SetFixedWidth(fixedWidth);
	}
}
//----------------------------------------------------------------------------
void UIEditBox::OnAttachWithIME()
{
	if (mUICallback)
	{
		mUICallback(this, UICT_EDITBOX_ATTACHWITHIME);
	}

	if (mFadePicBox)
	{
		float width = mInputText->GetTextWidth();
		width += 1.0f;
		const APoint &curPos = mFadePicBox->LocalTransform.GetTranslate();

		mFadePicBox->LocalTransform.SetTranslate(APoint(mFadePicBoxStartX
			+ width, curPos.Y(), curPos.Z()));
	}
}
//----------------------------------------------------------------------------
void UIEditBox::OnDetachWithIME()
{
	if (mUICallback)
	{
		mUICallback(this, UICT_EDITBOX_DETACHWITHIME);
	}
}
//----------------------------------------------------------------------------
void UIEditBox::OnTextChanged()
{
	if (mUICallback)
	{
		mUICallback(this, UICT_EDITBOX_TEXTCHANGED);
	}

	if (mFadePicBox)
	{
		float width = mInputText->GetTextWidth();
		width += 1.0f;
		const APoint &curPos = mFadePicBox->LocalTransform.GetTranslate();

		mFadePicBox->LocalTransform.SetTranslate(APoint(mFadePicBoxStartX
			+ width, curPos.Y(), curPos.Z()));
	}
}
//----------------------------------------------------------------------------
void UIEditBox::OnEnter()
{
	if (mUICallback)
	{
		mUICallback(this, UICT_EDITBOX_ENTER);
	}
}
//----------------------------------------------------------------------------
void UIEditBox::OnChildPicked(int info, Movable *child)
{
	if (!IsEnable())
		return;

	PX2_UNUSED(child);

	if (2 == info)
	{
		mFadePicBox->Culling = Movable::CULL_DYNAMIC;
		mInputText->AttachWithIME();
	}
}
//----------------------------------------------------------------------------
void UIEditBox::OnNotPicked(int pickInfo)
{
	if (!IsEnable())
		return;

	if (2 == pickInfo)
	{
		mFadePicBox->Culling = Movable::CULL_ALWAYS;
		mInputText->DetachWithIME();
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void UIEditBox::RegistProperties()
{
	UIFrame::RegistProperties();
	AddPropertyClass("UIEditBox");

	AddProperty("IsPassword", PT_BOOL, IsPassword());
	AddProperty("Size", PT_SIZE, GetSize());
	AddProperty("Text", PT_STRING, GetText());
	AddProperty("RealText", PT_STRING, GetRealText(), false);
	AddProperty("FixedWidth", PT_FLOAT, GetFixedWidth());
}
//----------------------------------------------------------------------------
void UIEditBox::OnPropertyChanged(const PropertyObject &obj)
{
	UIFrame::OnPropertyChanged(obj);

	if ("IsPassword" == obj.Name)
	{
		SetPassword(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("Size" == obj.Name)
	{
		SetSize(PX2_ANY_AS(obj.Data, Sizef));
	}
	else if ("Text" == obj.Name)
	{
		SetText(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("FixedWidth" == obj.Name)
	{
		SetFixedWidth(PX2_ANY_AS(obj.Data, float));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UIEditBox::UIEditBox(LoadConstructor value) :
UIFrame(value),
mFadePicBoxStartX(6.0f),
mFixedWidth(-1.0f)
{
}
//----------------------------------------------------------------------------
void UIEditBox::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UIFrame::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadPointer(mBackPicBox);
	source.ReadPointer(mFadePicBox);
	source.ReadPointer(mFadeCtrl);
	source.ReadPointer(mInputText);
	source.ReadAggregate(mSize);
	source.Read(mFixedWidth);

	PX2_END_DEBUG_STREAM_LOAD(UIEditBox, source);
}
//----------------------------------------------------------------------------
void UIEditBox::Link(InStream& source)
{
	UIFrame::Link(source);

	source.ResolveLink(mBackPicBox);
	source.ResolveLink(mFadePicBox);
	source.ResolveLink(mFadeCtrl);
	source.ResolveLink(mInputText);
}
//----------------------------------------------------------------------------
void UIEditBox::PostLink()
{
	UIFrame::PostLink();

	if (mFadePicBox)
	{
		mFadePicBox->Culling = Movable::CULL_ALWAYS;
	}

	if (mFadeCtrl)
	{
		mFadeCtrl->ResetPlay();
	}

	if (mInputText)
	{
		mInputText->SetCallback(UIEditBoxInputStaticTextCallback);
	}
}
//----------------------------------------------------------------------------
bool UIEditBox::Register(OutStream& target) const
{
	if (UIFrame::Register(target))
	{
		target.Register(mBackPicBox);
		target.Register(mFadePicBox);
		target.Register(mFadeCtrl);
		target.Register(mInputText);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void UIEditBox::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UIFrame::Save(target);
	PX2_VERSION_SAVE(target);

	target.WritePointer(mBackPicBox);
	target.WritePointer(mFadePicBox);
	target.WritePointer(mFadeCtrl);
	target.WritePointer(mInputText);
	target.WriteAggregate(mSize);

	target.Write(mFixedWidth);

	PX2_END_DEBUG_STREAM_SAVE(UIEditBox, target);
}
//----------------------------------------------------------------------------
int UIEditBox::GetStreamingSize(Stream &stream) const
{
	int size = UIFrame::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_POINTERSIZE(mBackPicBox);
	size += PX2_POINTERSIZE(mFadePicBox);
	size += PX2_POINTERSIZE(mFadeCtrl);
	size += PX2_POINTERSIZE(mInputText);
	size += sizeof(mSize);
	size += sizeof(mFixedWidth);

	return size;
}
//----------------------------------------------------------------------------