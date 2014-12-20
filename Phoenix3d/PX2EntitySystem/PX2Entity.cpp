/*
*
* 文件名称	：	PX2Entity.cpp
*
*/

#include "PX2Entity.hpp"
#include "PX2EntityModuleType.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Object, Entity);
PX2_IMPLEMENT_STREAM(Entity);
PX2_IMPLEMENT_FACTORY(Entity);
//----------------------------------------------------------------------------
Entity::Entity()
	:
mSceneEntity(0)
{
	mEntityModules.resize(EMT_MAX_TYPE);
	AddM(EMT_ID);
}
//----------------------------------------------------------------------------
Entity::~Entity ()
{
}
//----------------------------------------------------------------------------
void Entity::Update (float appTime, float elapsedTime)
{
	for (std::vector<EntityModulePtr>::iterator it = mEntityModules.begin(); 
		it!=mEntityModules.end(); it++)
	{
		(*it)->Update(appTime, elapsedTime);
	}
}
//----------------------------------------------------------------------------
void Entity::AddM (int type)
{
	if (0 == mEntityModules[type])
	{
		mEntityModules[type] = EntityModule::Create(type);
	}
}
//----------------------------------------------------------------------------
void Entity::RemM (int type)
{
	mEntityModules[type] = 0;
}
//----------------------------------------------------------------------------
bool Entity::IsHasM (int type) const
{
	return 0!=mEntityModules[type];
}
//----------------------------------------------------------------------------
EntityModule *Entity::GetM (int type)
{
	return mEntityModules[type];
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称支持
//----------------------------------------------------------------------------
Object* Entity::GetObjectByName (const std::string& name)
{
	Object* found = Object::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	for (int i=0; i<(int)mEntityModules.size(); i++)
	{
		PX2_GET_OBJECT_BY_NAME(mEntityModules[i], name, found);
	}

	return 0;
}
//----------------------------------------------------------------------------
void Entity::GetAllObjectsByName (const std::string& name,
	std::vector<Object*>& objects)
{
	Object::GetAllObjectsByName(name, objects);

	for (std::vector<EntityModulePtr>::iterator it = mEntityModules.begin(); 
		it!=mEntityModules.end(); it++)
	{
		for (int i=0; i<(int)mEntityModules.size(); i++)
		{
			PX2_GET_ALL_OBJECTS_BY_NAME(mEntityModules[i], name, objects);
		}
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Entity::Entity (LoadConstructor value)
	:
Object(value),
mSceneEntity(0)
{
	AddM(EMT_ID);
	mEntityModules.resize(EMT_MAX_TYPE);
}
//----------------------------------------------------------------------------
void Entity::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Object::Load(source);
	
	int numModules = 0;
	source.Read(numModules);
	if (numModules > 0)
	{
		mEntityModules.resize(numModules);
		source.ReadPointerVV(numModules, &mEntityModules[0]);
	}

	PX2_END_DEBUG_STREAM_LOAD(Entity, source);
}
//----------------------------------------------------------------------------
void Entity::Link (InStream& source)
{
	Object::Link(source);

	int numModules = (int)mEntityModules.size();
	for (int i=0; i<numModules; i++)
	{
		if (mEntityModules[i])
		{
			source.ResolveLink(mEntityModules[i]);
			if (mEntityModules[i])
			{
				mEntityModules[i]->SetEntity(this);
			}
		}
	}
}
//----------------------------------------------------------------------------
void Entity::PostLink ()
{
	Object::PostLink();
}
//----------------------------------------------------------------------------
bool Entity::Register (OutStream& target) const
{
	if (Object::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void Entity::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Object::Save(target);

	int numModules = (int)mEntityModules.size();
	target.Write(numModules);
	for (int i=0; i<(int)mEntityModules.size(); i++)
	{
		target.WritePointer(mEntityModules[i]);
	}

	PX2_END_DEBUG_STREAM_SAVE(Entity, target);
}
//----------------------------------------------------------------------------
int Entity::GetStreamingSize (Stream &stream) const
{
	int size = Object::GetStreamingSize(stream);
	int numModules = (int)mEntityModules.size();
	size += sizeof(numModules);
	size += numModules * PX2_POINTERSIZE(0);
	return size;
}
//----------------------------------------------------------------------------