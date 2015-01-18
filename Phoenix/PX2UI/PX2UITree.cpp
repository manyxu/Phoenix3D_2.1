// PX2UICaptionFrame.cpp

#include "PX2UITree.hpp"
#include "PX2UIPicBox.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, UISizeFrame, UITree);
PX2_IMPLEMENT_STREAM(UITree);
PX2_IMPLEMENT_FACTORY(UITree);

//----------------------------------------------------------------------------
UITree::UITree()
{
}
//----------------------------------------------------------------------------
UITree::~UITree()
{
}
//----------------------------------------------------------------------------
int UITree::AttachChild(Movable* child)
{
	int ret = UISizeFrame::AttachChild(child);

	float zPos = 0.0f;
	for (int i = 0; i < GetNumChildren(); i++)
	{
		UISizeFrame *sizeFrame = DynamicCast<UISizeFrame>(GetChild(i));
		if (sizeFrame)
		{
			float sizeFrameHeight = sizeFrame->GetHeight();
			sizeFrame->LocalTransform.SetTranslateZ(zPos);
			zPos -= sizeFrameHeight;
		}
	}

	return ret;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UITree::UITree(LoadConstructor value)
:
UISizeFrame(value)
{
}
//----------------------------------------------------------------------------
void UITree::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UISizeFrame::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(UITree, source);
}
//----------------------------------------------------------------------------
void UITree::Link(InStream& source)
{
	UISizeFrame::Link(source);
}
//----------------------------------------------------------------------------
void UITree::PostLink()
{
	UISizeFrame::PostLink();
}
//----------------------------------------------------------------------------
bool UITree::Register(OutStream& target) const
{
	return UISizeFrame::Register(target);
}
//----------------------------------------------------------------------------
void UITree::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UISizeFrame::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(UITree, target);
}
//----------------------------------------------------------------------------
int UITree::GetStreamingSize(Stream &stream) const
{
	int size = UISizeFrame::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------