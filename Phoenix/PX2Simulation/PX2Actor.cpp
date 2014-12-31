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
// Component
//----------------------------------------------------------------------------
Component *Actor::GetComponentByName (const std::string &name) const
{
	for (int i = 0; i < GetNumComponents(); i++)
	{
		if (mComponents[i]->GetName() == name)
			return mComponents[i];
	}

	return 0;
}
//----------------------------------------------------------------------------
bool Actor::IsHasComponent (Component* component)
{
	for (int i = 0; i < GetNumComponents(); i++)
	{
		if (mComponents[i] == component)
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void Actor::AttachComponent (Component* component)
{
	// 控制器必须存在
	if (!component)
	{
		assertion(false, "Cannot attach a null component\n");
		return;
	}

	if (IsHasComponent(component))
		return;

	mComponents.push_back(component);
	component->SetActor(this);
	component->OnAttach();

	SortControls();
}
//----------------------------------------------------------------------------
void Actor::DetachComponent (Component* component)
{
	std::vector<ComponentPtr>::iterator it = mComponents.begin();

	for (; it != mComponents.end(); it++)
	{
		if (component == *it)
		{
			component->OnDetach();
			component->SetActor(0);
			mComponents.erase(it);
			return;
		}
	}
}
//----------------------------------------------------------------------------
void Actor::DetachAllComponents ()
{
	for (int i = 0; i < GetNumComponents(); ++i)
	{
		// Unbind
		mComponents[i]->OnDetach();
		mComponents[i]->SetActor(0);
	}

	mComponents.clear();
}
//----------------------------------------------------------------------------
void Actor::SortComponents ()
{
	//std::sort(mComponents.begin(), mComponents.end(), Component::LessThan);
}
//----------------------------------------------------------------------------
bool Actor::UpdateComponents (double applicationTime)
{
	bool someoneUpdated = false;

	for (int i = 0; i < GetNumComponents(); ++i)
	{
		if (mComponents[i]->Update(applicationTime))
		{
			someoneUpdated = true;
		}
	}

	return someoneUpdated;
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