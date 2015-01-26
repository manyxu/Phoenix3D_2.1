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
Actor::Actor() :
mIsPickable(true)
{
	SetName("Actor");

	mNode = new0 Node();
	AttachChild(mNode);
	mNode->SetName("Node");

	mHelpNode = new0 Node();
	AttachChild(mHelpNode);
	mHelpNode->SetName("HelpNode");
	mHelpNode->Show(false);
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
void Actor::SetPickable(bool isPickable)
{
	mIsPickable = isPickable;

	if (mNode)
	{
		mNode->SetDoPick(isPickable);
	}

	if (mHelpNode)
	{
		mHelpNode->SetDoPick(isPickable);
	}
}
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Actor::Actor(LoadConstructor value) :
Node(value),
mIsPickable(true)
{
}
//----------------------------------------------------------------------------
void Actor::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Node::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadBool(mIsPickable);

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

	SetPickable(IsPickable());
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

	target.WriteBool(mIsPickable);

	PX2_END_DEBUG_STREAM_SAVE(Actor, target);
}
//----------------------------------------------------------------------------
int Actor::GetStreamingSize(Stream &stream) const
{
	int size = Node::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_BOOLSIZE(mIsPickable);

	return size;
}
//----------------------------------------------------------------------------