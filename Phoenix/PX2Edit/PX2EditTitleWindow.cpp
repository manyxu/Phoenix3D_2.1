// PX2EditTitleWindow.cpp

#include "PX2EditTitleWindow.hpp"
#include "PX2UIPicBox.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, UITitleFrame, EditTitleFrame);
PX2_IMPLEMENT_STREAM(EditTitleFrame);
PX2_IMPLEMENT_FACTORY(EditTitleFrame);

//----------------------------------------------------------------------------
EditTitleFrame::EditTitleFrame()
{
	mB_Table->Show(false);

	mB_Close->SetSize(Sizef(44.0f, 18.0f));
	mB_Close->GetPicBoxAtState(UIButtonBase::BS_NORMAL)->SetTexture("Data/editor/frame/minmaxclose.xml", "close_normal");
	mB_Close->GetPicBoxAtState(UIButtonBase::BS_HOVERED)->SetTexture("Data/editor/frame/minmaxclose.xml", "close_over");
	mB_Close->GetPicBoxAtState(UIButtonBase::BS_PRESSED)->SetTexture("Data/editor/frame/minmaxclose.xml", "close_down");
	mB_Close->GetPicBoxAtState(UIButtonBase::BS_DISABLED)->SetTexture("Data/editor/frame/minmaxclose.xml", "close_dis");
	mB_Close->SetRelativeValue_H(-22.0f);
	mB_Close->SetRelativeValue_V(-9.0f);

	mB_Max->SetSize(Sizef(23.0f, 18.0f));
	mB_Max->GetPicBoxAtState(UIButtonBase::BS_NORMAL)->SetTexture("Data/editor/frame/minmaxclose.xml", "max_normal");
	mB_Max->GetPicBoxAtState(UIButtonBase::BS_HOVERED)->SetTexture("Data/editor/frame/minmaxclose.xml", "max_over");
	mB_Max->GetPicBoxAtState(UIButtonBase::BS_PRESSED)->SetTexture("Data/editor/frame/minmaxclose.xml", "max_down");
	mB_Max->GetPicBoxAtState(UIButtonBase::BS_DISABLED)->SetTexture("Data/editor/frame/minmaxclose.xml", "max_dis");
	mB_Max->SetRelativeValue_H(-44.0f - 11.5f);
	mB_Max->SetRelativeValue_V(-9.0f);

	mB_Min->SetSize(Sizef(27.0f, 18.0f));
	mB_Min->GetPicBoxAtState(UIButtonBase::BS_NORMAL)->SetTexture("Data/editor/frame/minmaxclose.xml", "min_normal");
	mB_Min->GetPicBoxAtState(UIButtonBase::BS_HOVERED)->SetTexture("Data/editor/frame/minmaxclose.xml", "min_over");
	mB_Min->GetPicBoxAtState(UIButtonBase::BS_PRESSED)->SetTexture("Data/editor/frame/minmaxclose.xml", "min_down");
	mB_Min->GetPicBoxAtState(UIButtonBase::BS_DISABLED)->SetTexture("Data/editor/frame/minmaxclose.xml", "min_dis");
	mB_Min->SetRelativeValue_H(-44.0f - 23.0f - 13.5f);
	mB_Min->SetRelativeValue_V(-9.0f);
}
//----------------------------------------------------------------------------
EditTitleFrame::~EditTitleFrame()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
EditTitleFrame::EditTitleFrame(LoadConstructor value)
:
UITitleFrame(value)
{
}
//----------------------------------------------------------------------------
void EditTitleFrame::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UITitleFrame::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(EditTitleFrame, source);
}
//----------------------------------------------------------------------------
void EditTitleFrame::Link(InStream& source)
{
	UITitleFrame::Link(source);
}
//----------------------------------------------------------------------------
void EditTitleFrame::PostLink()
{
	UITitleFrame::PostLink();
}
//----------------------------------------------------------------------------
bool EditTitleFrame::Register(OutStream& target) const
{
	return UITitleFrame::Register(target);
}
//----------------------------------------------------------------------------
void EditTitleFrame::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UITitleFrame::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(EditTitleFrame, target);
}
//----------------------------------------------------------------------------
int EditTitleFrame::GetStreamingSize(Stream &stream) const
{
	int size = UITitleFrame::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------