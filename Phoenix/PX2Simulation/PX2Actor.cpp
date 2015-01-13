/*
*
* 文件名称	：	PX2UIFrame.cpp
*
*/

#include "PX2Actor.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Node, Actor);
PX2_IMPLEMENT_STREAM(Actor);
PX2_IMPLEMENT_FACTORY(Actor);
PX2_IMPLEMENT_DEFAULT_NAMES(Node, Actor);

//----------------------------------------------------------------------------
Actor::Actor()
{
	SetName("Actor");

	mNode = new0 Node();
	AttachChild(mNode);
	mNode->SetName("Node");

	mHelperNode = new0 Node();
	AttachChild(mHelperNode);
	mHelperNode->SetName("HelpNode");
}
//----------------------------------------------------------------------------
Actor::~Actor()
{
}
//----------------------------------------------------------------------------
void Actor::UpdateWorldData (double applicationTime)
{
	UpdateComponents(applicationTime);

	Node::UpdateWorldData(applicationTime);
}
//----------------------------------------------------------------------------
void Actor::SetMovable (Movable *mov)
{
	mNode->DetachAllChildren();
	mNode->AttachChild(mov);
}
//----------------------------------------------------------------------------
void Actor::AddMovable(Movable *mov)
{
	mNode->AttachChild(mov);
}
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Actor::Actor(LoadConstructor value)
	:
Node(value)
{
}
//----------------------------------------------------------------------------
void Actor::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Node::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(Actor, source);
}
//----------------------------------------------------------------------------
void Actor::Link(InStream& source)
{
	Node::Link(source);
}
//----------------------------------------------------------------------------
void Actor::PostLink()
{
	Node::PostLink();
}
//----------------------------------------------------------------------------
bool Actor::Register(OutStream& target) const
{
	return Node::Register(target);
}
//----------------------------------------------------------------------------
void Actor::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Node::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(Actor, target);
}
//----------------------------------------------------------------------------
int Actor::GetStreamingSize(Stream &stream) const
{
	int size = Node::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------