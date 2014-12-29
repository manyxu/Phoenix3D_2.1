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
}
//----------------------------------------------------------------------------
Actor::~Actor()
{
}
//----------------------------------------------------------------------------

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
bool Actor::IsHasComponent (Component* controller)
{
	for (int i = 0; i < GetNumComponents(); i++)
	{
		if (mComponents[i] == controller)
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void Actor::AttachComponent (Component* controller)
{
	// 控制器必须存在
	if (!controller)
	{
		assertion(false, "Cannot attach a null controller\n");
		return;
	}

	if (IsHasComponent(controller))
		return;

	mComponents.push_back(controller);
	controller->SetActor(this);
	controller->OnAttach();

	SortControls();
}
//----------------------------------------------------------------------------
void Actor::DetachComponent (Component* controller)
{
	std::vector<ComponentPtr>::iterator it = mComponents.begin();

	for (; it != mComponents.end(); it++)
	{
		if (controller == *it)
		{
			controller->OnDetach();
			controller->SetActor(0);
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
bool Actor::UpdateComponents(double applicationTime)
{
	bool someoneUpdated = false;

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