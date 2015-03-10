// PX2Componable.cpp

#include "PX2Componable.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Object, Componable);
PX2_IMPLEMENT_STREAM(Componable);
PX2_IMPLEMENT_ABSTRACT_FACTORY(Componable);

//----------------------------------------------------------------------------
Componable::Componable()
{
}
//----------------------------------------------------------------------------
Componable::~Componable()
{
	for (int i = 0; i < GetNumComponents(); i++)
	{
		if (mComponents[i])
		{
			mComponents[i]->SetCompable(0);
			mComponents[i] = 0;
		}
	}
}
//----------------------------------------------------------------------------
Component *Componable::GetComponentByName(const std::string &name) const
{
	for (int i = 0; i < GetNumComponents(); i++)
	{
		if (mComponents[i]->GetName() == name)
			return mComponents[i];
	}

	return 0;
}
//----------------------------------------------------------------------------
bool Componable::IsHasComponent(Component* component)
{
	for (int i = 0; i < GetNumComponents(); i++)
	{
		if (mComponents[i] == component)
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void Componable::AttachComponent(Component* component)
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
	component->SetCompable(this);

	SortComponents();
}
//----------------------------------------------------------------------------
void Componable::DetachComponent(Component* component)
{
	std::vector<ComponentPtr>::iterator it = mComponents.begin();

	for (; it != mComponents.end(); it++)
	{
		if (component == *it)
		{
			component->SetCompable(0);
			mComponents.erase(it);
			return;
		}
	}
}
//----------------------------------------------------------------------------
void Componable::DetachAllComponents()
{
	for (int i = 0; i < GetNumComponents(); ++i)
	{
		mComponents[i]->SetCompable(0);
	}

	mComponents.clear();
}
//----------------------------------------------------------------------------
void Componable::SortComponents()
{
	//std::sort(mComponents.begin(), mComponents.end(), Component::LessThan);
}
//----------------------------------------------------------------------------
bool Componable::UpdateComponents(double applicationTime, double elapsedTime)
{
	bool someoneUpdated = false;

	for (int i = 0; i < GetNumComponents(); ++i)
	{
		if (mComponents[i]->Update(applicationTime, elapsedTime))
		{
			someoneUpdated = true;
		}
	}

	return someoneUpdated;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称支持
//----------------------------------------------------------------------------
Object* Componable::GetObjectByName(const std::string& name)
{
	Object* found = Object::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	for (int i = 0; i < GetNumComponents(); ++i)
	{
		PX2_GET_OBJECT_BY_NAME(mComponents[i], name, found);
	}

	return 0;
}
//----------------------------------------------------------------------------
void Componable::GetAllObjectsByName(const std::string& name,
	std::vector<Object*>& objects)
{
	Object::GetAllObjectsByName(name, objects);

	for (int i = 0; i < GetNumComponents(); ++i)
	{
		PX2_GET_ALL_OBJECTS_BY_NAME(mComponents[i], name, objects);
	}
}
//----------------------------------------------------------------------------
Object* Componable::GetObjectByID(int id)
{
	Object* found = Object::GetObjectByID(id);
	if (found)
	{
		return found;
	}

	for (int i = 0; i < GetNumComponents(); ++i)
	{
		PX2_GET_OBJECT_BY_ID(mComponents[i], id, found);
	}

	return 0;
}
//----------------------------------------------------------------------------
void Componable::GetAllObjectsByID(int id,
	std::vector<Object*>& objects)
{
	Object::GetAllObjectsByID(id, objects);

	for (int i = 0; i < GetNumComponents(); ++i)
	{
		PX2_GET_ALL_OBJECTS_BY_ID(mComponents[i], id, objects);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Componable::Componable(LoadConstructor value)
:
Object(value)
{
}
//----------------------------------------------------------------------------
void Componable::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Object::Load(source);
	PX2_VERSION_LOAD(source);

	int numComps;
	source.Read(numComps);
	mComponents.resize(numComps);
	for (int i = 0; i < numComps; i++)
	{
		source.ReadPointer(mComponents[i]);
	}

	PX2_END_DEBUG_STREAM_LOAD(Componable, source);
}
//----------------------------------------------------------------------------
void Componable::Link(InStream& source)
{
	Object::Link(source);

	int numComps = (int)mComponents.size();
	for (int i = 0; i < numComps; i++)
	{
		source.ResolveLink(mComponents[i]);
	}
}
//----------------------------------------------------------------------------
void Componable::PostLink()
{
	Object::PostLink();
}
//----------------------------------------------------------------------------
bool Componable::Register(OutStream& target) const
{
	if (Object::Register(target))
	{
		int numComps = (int)mComponents.size();
		for (int i = 0; i < numComps; i++)
		{
			target.Register(mComponents[i]);
		}
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void Componable::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Object::Save(target);
	PX2_VERSION_SAVE(target);

	int numComps = (int)mComponents.size();
	target.Write(numComps);
	for (int i = 0; i < numComps; i++)
	{
		target.WritePointer(mComponents[i]);
	}

	PX2_END_DEBUG_STREAM_SAVE(Componable, target);
}
//----------------------------------------------------------------------------
int Componable::GetStreamingSize(Stream &stream) const
{
	int size = Object::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	int numComps = (int)mComponents.size();
	size += sizeof(numComps);
	if (size > 0)
	{
		size += numComps*PX2_POINTERSIZE(mComponents[0]);
	}

	return size;
}
//----------------------------------------------------------------------------