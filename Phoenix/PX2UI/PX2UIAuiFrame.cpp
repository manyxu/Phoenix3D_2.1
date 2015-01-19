// PX2UIAuiFrame.cpp

#include "PX2UIAuiFrame.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, UISizeFrame, UIAuiFrame);
PX2_IMPLEMENT_STREAM(UIAuiFrame);
PX2_IMPLEMENT_FACTORY(UIAuiFrame);
PX2_IMPLEMENT_DEFAULT_NAMES(UISizeFrame, UIAuiFrame)

//----------------------------------------------------------------------------
UIAuiFrame::UIAuiFrame()
{

}
//----------------------------------------------------------------------------
UIAuiFrame::~UIAuiFrame()
{

}
//----------------------------------------------------------------------------
void UIAuiFrame::AddFrame(AuiPosType posType, UISizeFrame *frame)
{
	UIAuiFrame *containAuiFrame = 0;
	std::map<AuiPosType, Pointer0<UIAuiFrame> >::iterator it = mFrames.find(posType);
	if (it == mFrames.end())
	{
		containAuiFrame = new0 UIAuiFrame();
		AttachChild(containAuiFrame);
		mFrames[posType] = containAuiFrame;
	}
	else
	{
		containAuiFrame = it->second;
	}

	containAuiFrame->AttachChild(frame);
}
//----------------------------------------------------------------------------
void UIAuiFrame::OnParentSizeChanged(const Sizef &parentSize,
	const Sizef &parentBorderSize)
{
	UISizeFrame::OnParentSizeChanged(parentSize, parentBorderSize);
	const Sizef &size = GetSize();

	UIAuiFrame *centerFrame = mFrames[APT_CENTER];
	UIAuiFrame *leftFrame = mFrames[APT_LEFT];
	UIAuiFrame *topFrame = mFrames[APT_TOP];
	UIAuiFrame *rightFrame = mFrames[APT_RIGHT];
	UIAuiFrame *botFrame = mFrames[APT_BOTTON];

	int numh = 0;
	if (leftFrame)
		numh += 1;
	if (centerFrame)
		numh += 1;
	if (rightFrame)
		numh += 1;

	int numv = 0;
	if (topFrame)
		numv += 1;
	if (centerFrame)
		numv += 1;
	if (botFrame)
		numv += 1;

	float widthOneSize = size.Width;
	if (numh > 0)
		widthOneSize = size.Width / numh;


	float heightOneSize = size.Height;
	if (numv > 0)
		heightOneSize = size.Height / numv;

	if (leftFrame)
	{
		leftFrame->SetSize(Sizef(widthOneSize, heightOneSize));
	}

	if (centerFrame)
	{
		centerFrame->LocalTransform.SetTranslateX(widthOneSize);
		centerFrame->SetSize(Sizef(widthOneSize, heightOneSize));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UIAuiFrame::UIAuiFrame(LoadConstructor value) :
UISizeFrame(value)
{
}
//----------------------------------------------------------------------------
void UIAuiFrame::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UISizeFrame::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(UIAuiFrame, source);
}
//----------------------------------------------------------------------------
void UIAuiFrame::Link(InStream& source)
{
	UISizeFrame::Link(source);
}
//----------------------------------------------------------------------------
void UIAuiFrame::PostLink()
{
	UISizeFrame::PostLink();
}
//----------------------------------------------------------------------------
bool UIAuiFrame::Register(OutStream& target) const
{
	return UISizeFrame::Register(target);
}
//----------------------------------------------------------------------------
void UIAuiFrame::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UISizeFrame::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(UIAuiFrame, target);
}
//----------------------------------------------------------------------------
int UIAuiFrame::GetStreamingSize(Stream &stream) const
{
	int size = UISizeFrame::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------