/*
*
* 文件名称	：	PX2EffectNode.cpp
*
*/

#include "PX2EffectNode.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Node, EffectNode);
PX2_IMPLEMENT_STREAM(EffectNode);
PX2_IMPLEMENT_FACTORY(EffectNode);
PX2_IMPLEMENT_DEFAULT_NAMES(Node, EffectNode);

//----------------------------------------------------------------------------
EffectNode::EffectNode ()
	:
mIsAutoPlay(false),
	mEffectScale(1.0f)
{
}
//----------------------------------------------------------------------------
EffectNode::~EffectNode ()
{
}
//----------------------------------------------------------------------------
void EffectNode::UpdateWorldData(double applicationTime)
{
	Node::UpdateWorldData(applicationTime);

	if (mIsAutoPlay)
	{
		if (!IsPlaying())
		{
			ResetPlay();
		}
	}
}
//----------------------------------------------------------------------------
void EffectNode::RegistProperties ()
{
	Node::RegistProperties();

	AddPropertyClass("EffectNode");
	AddProperty("IsAutoPlay", PT_BOOL, Any(IsAutoPlay()));
}
//----------------------------------------------------------------------------
void EffectNode::OnPropertyChanged (const PropertyObject &obj)
{
	Node::OnPropertyChanged(obj);

	if ("IsAutoPlay" == obj.Name)
	{
		SetAutoPlay(PX2_ANY_AS(obj.Data, bool));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化
//----------------------------------------------------------------------------
EffectNode::EffectNode (LoadConstructor value)
	:
Node(value),
mIsAutoPlay(false),
mEffectScale(1.0f)
{
}
//----------------------------------------------------------------------------
void EffectNode::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Node::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadBool(mIsAutoPlay);

	PX2_END_DEBUG_STREAM_LOAD(EffectNode, source);
}
//----------------------------------------------------------------------------
void EffectNode::Link (InStream& source)
{
	Node::Link(source);
}
//----------------------------------------------------------------------------
void EffectNode::PostLink ()
{
	Node::PostLink();
}
//----------------------------------------------------------------------------
bool EffectNode::Register (OutStream& target) const
{
	return Node::Register(target);
}
//----------------------------------------------------------------------------
void EffectNode::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Node::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteBool(mIsAutoPlay);

	PX2_END_DEBUG_STREAM_SAVE(EffectNode, target);
}
//----------------------------------------------------------------------------
int EffectNode::GetStreamingSize (Stream &stream) const
{
	int size = Node::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_BOOLSIZE(mIsAutoPlay);

	return size;
}
//----------------------------------------------------------------------------
