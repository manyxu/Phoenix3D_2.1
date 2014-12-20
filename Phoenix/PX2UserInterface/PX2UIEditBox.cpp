/*
*
* 文件名称	：	PX2UIEditBox.cpp
*
*/

#include "PX2UIEditBox.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI_V(PX2, UIFrame, UIEditBox, 1);
PX2_IMPLEMENT_STREAM(UIEditBox);
PX2_IMPLEMENT_FACTORY(UIEditBox);
PX2_IMPLEMENT_DEFAULT_NAMES(UIFrame, UIEditBox);

//----------------------------------------------------------------------------
void UIEditBoxInputStaticTextCallback (UIInputStaticText *inputText, UIISTCallType type)
{
	UIEditBox *editBox = DynamicCast<UIEditBox>(inputText->GetParent());

	if (UIISTCT_ATTACHWITHIME == type)
	{
		editBox->OnAttachWithIME();
	}
	else if (UIISTCT_DETACHWITHWITHIME == type)
	{
		editBox->OnDetachWithIME();
	}
	else if (UIISTCT_INSERTTEXT == type)
	{
		editBox->OnTextChanged();
	}
	else if (UIISTCT_DELETEBACKWARD == type)
	{
		editBox->OnTextChanged();
	}
	else if (UIISTCT_ENTER == type)
	{
		editBox->OnEnter();
	}
}
//----------------------------------------------------------------------------
UIEditBox::UIEditBox ()
	:
mFadePicBoxStartX(6.0f),
mFixedWidth(-1.0f)
{
	SetName("UIEditBox");

	UIPicBoxPtr backPicBox = new0 UIPicBox();
	backPicBox->SetPicBoxType(UIPicBox::PBT_NINE);
	backPicBox->SetAnchorPoint(0.0f, 0.0f);
	backPicBox->SetTexCornerSize(4.0f, 4.0f);
	backPicBox->SetTexture("Data/engine/common.xml", "editBoxBack");
	backPicBox->LocalTransform.SetTranslate(APoint(0.0f, 2.0f, 0.0f));
	backPicBox->SetName("EditBoxBack");

	SetBackPicBox(backPicBox);

	UIPicBoxPtr fadePicBox = new0 UIPicBox();
	fadePicBox->SetTexture("Data/engine/common.xml", "black");
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
	mFadePicBox->Culling = Movable::CULL_ALWAYS;

	mInputStaticText = new0 UIInputStaticText();
	mInputStaticText->SetRectUseage(UIStaticText::RU_ALIGNS);
	mInputStaticText->SetAligns(TEXTALIGN_LEFT|TEXTALIGN_VCENTER);
	mInputStaticText->SetFontWidth(20);
	mInputStaticText->SetFontHeight(20);
	mInputStaticText->LocalTransform.SetTranslate(APoint(8.0f, -4.0f, -1.0f));
	mInputStaticText->SetName("EditBoxStaticText");
	AttachChild(mInputStaticText);
	mInputStaticText->SetCallback(UIEditBoxInputStaticTextCallback);

	SetSize(150.0f, 30.0f);
}
//----------------------------------------------------------------------------
UIEditBox::~UIEditBox ()
{
}
//----------------------------------------------------------------------------
void UIEditBox::SetPassword (bool isPassword)
{
	return mInputStaticText->SetPassword(isPassword);
}
//----------------------------------------------------------------------------
bool UIEditBox::IsPassword () const
{
	return mInputStaticText->IsPassword();
}
//----------------------------------------------------------------------------
void UIEditBox::Enable (bool enable)
{
	UIFrame::Enable(enable);

	if (!enable)
	{
		mFadePicBox->Culling = Movable::CULL_ALWAYS;
		mInputStaticText->DetachWithIME();
	}
}
//----------------------------------------------------------------------------
void UIEditBox::SetBackPicBox (UIPicBox *picBox)
{
	if (mBackPicBox)
	{
		DetachChild(mBackPicBox);
	}

	mBackPicBox = picBox;

	AttachChild(mBackPicBox);
}
//----------------------------------------------------------------------------
void UIEditBox::SetFadePicBox (UIPicBox *picBox)
{
	if (mFadePicBox)
	{
		DetachChild(mFadePicBox);
	}

	mFadePicBox = picBox;

	AttachChild(mFadePicBox);
}
//----------------------------------------------------------------------------
const std::string &UIEditBox::GetText () const
{
	return mInputStaticText->GetText();
}
//----------------------------------------------------------------------------
const std::string &UIEditBox::GetRealText () const
{
	return mInputStaticText->GetRealText();
}
//----------------------------------------------------------------------------
void UIEditBox::SetSize (float width, float height)
{
	mSize.Width = width;
	mSize.Height = height;

	SetSize(mSize);
}
//----------------------------------------------------------------------------
void UIEditBox::SetSize (const Sizef &size)
{
	mSize = size;

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

	if (mInputStaticText)
	{
		std::string realText = mInputStaticText->GetRealText();
		mInputStaticText->SetRect(Rectf(0.0f, 0.0f, size.Width, size.Height));
		mInputStaticText->SetText(realText);
	}
}
//----------------------------------------------------------------------------
void UIEditBox::SetText (const std::string &text)
{
	mInputStaticText->SetRealText(text);

	if (mFadePicBox)
	{
		float width = mInputStaticText->GetTextWidth();
		width += 1.0f;
		const APoint &curPos = mFadePicBox->LocalTransform.GetTranslate();

		mFadePicBox->LocalTransform.SetTranslate(APoint(mFadePicBoxStartX
			+width, curPos.Y(), curPos.Z()));
	}
}
//----------------------------------------------------------------------------
void UIEditBox::SetFixedWidth (float fixedWidth)
{
	mFixedWidth = fixedWidth;
	
	if (mInputStaticText)
	{
		mInputStaticText->SetFixedWidth(fixedWidth);
	}
}
//----------------------------------------------------------------------------
void UIEditBox::OnAttachWithIME ()
{
	if (mUICallback)
	{
		mUICallback(this, UICT_EDITBOX_ATTACHWITHIME);
	}

	if (mFadePicBox)
	{
		float width = mInputStaticText->GetTextWidth();
		width += 1.0f;
		const APoint &curPos = mFadePicBox->LocalTransform.GetTranslate();

		mFadePicBox->LocalTransform.SetTranslate(APoint(mFadePicBoxStartX
			+width, curPos.Y(), curPos.Z()));
	}
}
//----------------------------------------------------------------------------
void UIEditBox::OnDetachWithIME ()
{
	if (mUICallback)
	{
		mUICallback(this, UICT_EDITBOX_DETACHWITHIME);
	}
}
//----------------------------------------------------------------------------
void UIEditBox::OnTextChanged ()
{
	if (mUICallback)
	{
		mUICallback(this, UICT_EDITBOX_TEXTCHANGED);
	}

	if (mFadePicBox)
	{
		float width = mInputStaticText->GetTextWidth();
		width += 1.0f;
		const APoint &curPos = mFadePicBox->LocalTransform.GetTranslate();

		mFadePicBox->LocalTransform.SetTranslate(APoint(mFadePicBoxStartX
			+width, curPos.Y(), curPos.Z()));
	}
}
//----------------------------------------------------------------------------
void UIEditBox::OnEnter ()
{
	if (mUICallback)
	{
		mUICallback(this, UICT_EDITBOX_ENTER);
	}
}
//----------------------------------------------------------------------------
void UIEditBox::OnChildPicked (int info, Movable *child)
{
	if (!IsEnable())
		return;

	PX2_UNUSED(child);

	if (2 == info)
	{
		mFadePicBox->Culling = Movable::CULL_DYNAMIC;
		mInputStaticText->AttachWithIME();
	}
}
//----------------------------------------------------------------------------
void UIEditBox::OnNotPicked (int pickInfo)
{
	if (!IsEnable())
		return;

	if (2 == pickInfo)
	{
		mFadePicBox->Culling = Movable::CULL_ALWAYS;
		mInputStaticText->DetachWithIME();
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void UIEditBox::RegistProperties ()
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
void UIEditBox::OnPropertyChanged (const PropertyObject &obj)
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
UIEditBox::UIEditBox (LoadConstructor value)
	:
UIFrame(value),
mFadePicBoxStartX(6.0f),
mFixedWidth(-1.0f)
{
}
//----------------------------------------------------------------------------
void UIEditBox::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UIFrame::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadPointer(mBackPicBox);
	source.ReadPointer(mFadePicBox);
	source.ReadPointer(mFadeCtrl);
	source.ReadPointer(mInputStaticText);
	source.ReadAggregate(mSize);

	int readedVersion = GetReadedVersion();
	if (1 <= readedVersion)
	{
		source.Read(mFixedWidth);
	}

	PX2_END_DEBUG_STREAM_LOAD(UIEditBox, source);
}
//----------------------------------------------------------------------------
void UIEditBox::Link (InStream& source)
{
	UIFrame::Link(source);

	source.ResolveLink(mBackPicBox);
	source.ResolveLink(mFadePicBox);
	source.ResolveLink(mFadeCtrl);
	source.ResolveLink(mInputStaticText);
}
//----------------------------------------------------------------------------
void UIEditBox::PostLink ()
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

	if (mInputStaticText)
	{
		mInputStaticText->SetCallback(UIEditBoxInputStaticTextCallback);
	}
}
//----------------------------------------------------------------------------
bool UIEditBox::Register (OutStream& target) const
{
	if (UIFrame::Register(target))
	{
		target.Register(mBackPicBox);
		target.Register(mFadePicBox);
		target.Register(mFadeCtrl);
		target.Register(mInputStaticText);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void UIEditBox::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UIFrame::Save(target);
	PX2_VERSION_SAVE(target);

	target.WritePointer(mBackPicBox);
	target.WritePointer(mFadePicBox);
	target.WritePointer(mFadeCtrl);
	target.WritePointer(mInputStaticText);
	target.WriteAggregate(mSize);

	target.Write(mFixedWidth);

	PX2_END_DEBUG_STREAM_SAVE(UIEditBox, target);
}
//----------------------------------------------------------------------------
int UIEditBox::GetStreamingSize (Stream &stream) const
{
	int size = UIFrame::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion); 

	size += PX2_POINTERSIZE(mBackPicBox);
	size += PX2_POINTERSIZE(mFadePicBox);
	size += PX2_POINTERSIZE(mFadeCtrl);
	size += PX2_POINTERSIZE(mInputStaticText);
	size += sizeof(mSize);

	if (stream.IsIn())
	{
		int readedVersion = GetReadedVersion();

		if (1 <= readedVersion)
		{
			size += sizeof(mFixedWidth);
		}
	}
	else
	{
		size += sizeof(mFixedWidth);
	}

	return size;
}
//----------------------------------------------------------------------------