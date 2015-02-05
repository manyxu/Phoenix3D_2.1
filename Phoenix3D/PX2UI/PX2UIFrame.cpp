// PX2UIFrame.cpp

#include "PX2UIFrame.hpp"
using namespace PX2;
using namespace std;

PX2_IMPLEMENT_RTTI(PX2, Node, UIFrame);
PX2_IMPLEMENT_STREAM(UIFrame);
PX2_IMPLEMENT_FACTORY(UIFrame);

//----------------------------------------------------------------------------
UIFrame::UIFrame() :
mUICallback(0)
{
}
//----------------------------------------------------------------------------
UIFrame::~UIFrame()
{
}
//----------------------------------------------------------------------------
void UIFrame::SetSize(float width, float height)
{
	SetSize(Sizef(width, height));
}
//----------------------------------------------------------------------------
void UIFrame::SetSize(const Sizef &size)
{
	mSize = size;
	OnSizeChanged();
}
//----------------------------------------------------------------------------
void UIFrame::OnSizeChanged()
{
}
//----------------------------------------------------------------------------
void UIFrame::SetWidth(float width)
{
	SetSize(Sizef(width, mSize.Height));
}
//----------------------------------------------------------------------------
void UIFrame::SetHeight(float height)
{
	SetSize(Sizef(mSize.Width, height));
}
//----------------------------------------------------------------------------
void UIFrame::SetBorderSize(float width, float height)
{
	SetBorderSize(Sizef(width, height));
}
//----------------------------------------------------------------------------
void UIFrame::SetBorderSize(const Sizef &size)
{
	mBorderSize = size;

	OnBorderSizeChanged();
}
//----------------------------------------------------------------------------
void UIFrame::SetBorderWidth(float width)
{
	SetBorderSize(Sizef(width, mSize.Height));
}
//----------------------------------------------------------------------------
void UIFrame::SetBorderHeight(float height)
{
	SetBorderSize(Sizef(mSize.Width, height));
}
//----------------------------------------------------------------------------
void UIFrame::OnBorderSizeChanged()
{
}
//----------------------------------------------------------------------------
void UIFrame::OnChildPicked(int info, Movable *child)
{
	if (!IsEnable())
		return;

	UIFrame *frame = DynamicCast<UIFrame>(GetParent());
	if (frame)
	{
		frame->OnChildPicked(info, child);
	}
}
//----------------------------------------------------------------------------
void UIFrame::OnChildUIAfterPicked(int info, Movable *child)
{
	if (!IsEnable())
		return;

	UIFrame *frame = DynamicCast<UIFrame>(GetParent());
	if (frame)
	{
		frame->OnChildUIAfterPicked(info, child);
	}
}
//----------------------------------------------------------------------------
InputPushTransformController *UIFrame::CreateAddIPTCtrl(bool doResetPlay)
{
	DestoryIPTCtrl();

	mIPTCtrl = new0 InputPushTransformController();
	AttachController(mIPTCtrl);
	mIPTCtrl->SetName("IPTCtrl");

	if (doResetPlay) mIPTCtrl->ResetPlay();

	return mIPTCtrl;
}
//----------------------------------------------------------------------------
void UIFrame::DestoryIPTCtrl()
{
	if (mIPTCtrl)
	{
		DetachController(mIPTCtrl);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UIFrame::UIFrame(LoadConstructor value) :
Node(value),
mUICallback(0)
{
}
//----------------------------------------------------------------------------
void UIFrame::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Node::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadString(mUIScriptHandler);

	source.ReadPointer(mIPTCtrl);

	PX2_END_DEBUG_STREAM_LOAD(UIFrame, source);
}
//----------------------------------------------------------------------------
void UIFrame::Link(InStream& source)
{
	Node::Link(source);

	if (mIPTCtrl)
		source.ResolveLink(mIPTCtrl);
}
//----------------------------------------------------------------------------
void UIFrame::PostLink()
{
	Node::PostLink();
}
//----------------------------------------------------------------------------
bool UIFrame::Register(OutStream& target) const
{
	if (Node::Register(target))
	{
		target.Register(mIPTCtrl);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void UIFrame::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Node::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteString(mUIScriptHandler);

	target.WritePointer(mIPTCtrl);

	PX2_END_DEBUG_STREAM_SAVE(UIFrame, target);
}
//----------------------------------------------------------------------------
int UIFrame::GetStreamingSize(Stream &stream) const
{
	int size = Node::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_STRINGSIZE(mUIScriptHandler);
	
	size += PX2_POINTERSIZE(mIPTCtrl);

	return size;
}
//----------------------------------------------------------------------------