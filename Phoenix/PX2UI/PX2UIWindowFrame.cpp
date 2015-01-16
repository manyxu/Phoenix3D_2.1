// PX2WindowFrame.cpp

#include "PX2UIWindowFrame.hpp"
using namespace PX2;
using namespace std;

PX2_IMPLEMENT_RTTI(PX2, UISizeFrame, UIWindowFrame);
PX2_IMPLEMENT_STREAM(UIWindowFrame);
PX2_IMPLEMENT_FACTORY(UIWindowFrame);

//----------------------------------------------------------------------------
UIWindowFrame::UIWindowFrame()
{
	mCaptionFrame = new0 UITitleFrame();
	AttachChild(mCaptionFrame);
	mCaptionFrame->SetSize(0.0f, 30.0f);
	mCaptionFrame->SetRelativeType_V(UISizeFrame::LT_ONE);
	mCaptionFrame->SetSizeRelativeType(UISizeFrame::SRT_H);
}
//----------------------------------------------------------------------------
UIWindowFrame::~UIWindowFrame()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UIWindowFrame::UIWindowFrame(LoadConstructor value) :
UISizeFrame(value)
{
}
//----------------------------------------------------------------------------
void UIWindowFrame::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UISizeFrame::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(UIWindowFrame, source);
}
//----------------------------------------------------------------------------
void UIWindowFrame::Link(InStream& source)
{
	UISizeFrame::Link(source);
}
//----------------------------------------------------------------------------
void UIWindowFrame::PostLink()
{
	UISizeFrame::PostLink();
}
//----------------------------------------------------------------------------
bool UIWindowFrame::Register(OutStream& target) const
{
	return UISizeFrame::Register(target);
}
//----------------------------------------------------------------------------
void UIWindowFrame::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UISizeFrame::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(UIWindowFrame, target);
}
//----------------------------------------------------------------------------
int UIWindowFrame::GetStreamingSize(Stream &stream) const
{
	int size = UISizeFrame::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------