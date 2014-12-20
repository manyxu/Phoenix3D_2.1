/*
*
* 文件名称	：	PX2UIScoreStaticText.cpp
*
*/

#include "PX2UIScoreStaticText.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, UIStaticText, UIScoreStaticText);
PX2_IMPLEMENT_STREAM(UIScoreStaticText);
PX2_IMPLEMENT_FACTORY(UIScoreStaticText);
PX2_IMPLEMENT_DEFAULT_NAMES(UIStaticText, UIScoreStaticText);

//----------------------------------------------------------------------------
UIScoreStaticText::UIScoreStaticText ()
	:
mNum(0)
{
	mSSTCtrl = new0 UIScoreStaticTextCtrl();
	AttachController(mSSTCtrl);
}
//----------------------------------------------------------------------------
UIScoreStaticText::~UIScoreStaticText ()
{
}
//----------------------------------------------------------------------------
void UIScoreStaticText::SetNumAnimInit (int num)
{
	mSSTCtrl->SetNumInit(num);
}
//----------------------------------------------------------------------------
void UIScoreStaticText::SetNumAnim (int num)
{
	mSSTCtrl->SetNum(num);
}
//----------------------------------------------------------------------------
void UIScoreStaticText::SetNum (int num)
{
	mNum = num;

	std::string str = StringHelp::IntToString(mNum);

	SetText(str);

	if (str.empty())
	{
		Culling = Movable::CULL_ALWAYS;
	}
	else
	{
		Culling = Movable::CULL_DYNAMIC;
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void UIScoreStaticText::RegistProperties ()
{
	UIStaticText::RegistProperties();

	AddPropertyClass("UIScoreStaticText");

	AddProperty("Speed", PT_FLOAT, mSSTCtrl->GetSpeed());
}
//----------------------------------------------------------------------------
void UIScoreStaticText::OnPropertyChanged (const PropertyObject &obj)
{
	UIStaticText::OnPropertyChanged(obj);

	if ("Speed" == obj.Name)
	{
		mSSTCtrl->SetSpeed(PX2_ANY_AS(obj.Data, float));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UIScoreStaticText::UIScoreStaticText (LoadConstructor value)
	:
UIStaticText(value),
mNum(0)
{
}
//----------------------------------------------------------------------------
void UIScoreStaticText::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UIStaticText::Load(source);
	PX2_VERSION_LOAD(source);

	source.Read(mNum);
	source.ReadPointer(mSSTCtrl);

	PX2_END_DEBUG_STREAM_LOAD(UIScoreStaticText, source);
}
//----------------------------------------------------------------------------
void UIScoreStaticText::Link (InStream& source)
{
	UIStaticText::Link(source);
	source.ResolveLink(mSSTCtrl);
}
//----------------------------------------------------------------------------
void UIScoreStaticText::PostLink ()
{
	UIStaticText::PostLink();
}
//----------------------------------------------------------------------------
bool UIScoreStaticText::Register (OutStream& target) const
{
	if (UIStaticText::Register(target))
	{
		target.Register(mSSTCtrl);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void UIScoreStaticText::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UIStaticText::Save(target);
	PX2_VERSION_SAVE(target);

	target.Write(mNum);
	target.WritePointer(mSSTCtrl);

	PX2_END_DEBUG_STREAM_SAVE(UIScoreStaticText, target);
}
//----------------------------------------------------------------------------
int UIScoreStaticText::GetStreamingSize (Stream &stream) const
{
	int size = UIStaticText::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += sizeof(mNum);
	size += PX2_POINTERSIZE(mSSTCtrl);

	return size;
}
//----------------------------------------------------------------------------