/*
*
* 文件名称	：	PX2SceneEntity.cpp
*
*/

#include "PX2SceneEntity.hpp"
#include "PX2EntityModuleType.hpp"
#include "PX2EM_ID.hpp"
#include "PX2EM_Movable.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Entity, SceneEntity);
PX2_IMPLEMENT_STREAM(SceneEntity);
PX2_IMPLEMENT_FACTORY(SceneEntity);
//----------------------------------------------------------------------------
SceneEntity::SceneEntity()
{
	mNode = new0 Node ();
	mNode->SetName("SceneNode");


}
//----------------------------------------------------------------------------
SceneEntity::~SceneEntity ()
{
}
//----------------------------------------------------------------------------
void SceneEntity::Update (float appTime, float elapsedTime)
{
	std::list<EntityPtr>::iterator it = mEntities.begin();
	for (; it!=mEntities.end(); it++)
	{
		(*it)->Update(appTime, elapsedTime);
	}
}
//----------------------------------------------------------------------------
bool SceneEntity::AddEntity (Entity *ent)
{
	if (!ent)
		return false;

	if (IsHasEntity(ent))
		return false;

	int id = ((EN_ID*)(ent->GetM(EMT_ID)))->GetID();

	mEntities.push_back(ent);
	mEntitiesMap[id] = ent;
	ent->SetSceneEntity(this);

	return true;
}
//----------------------------------------------------------------------------
bool SceneEntity::RemoveEntity (Entity *ent)
{
	if (!ent)
		return false;

	if (!IsHasEntity(ent))
		return false;

	int id = ((EN_ID*)(ent->GetM(EMT_ID)))->GetID();

	for (std::list<EntityPtr>::iterator it = mEntities.begin();
		it!=mEntities.end(); it++)
	{
		if (*it == ent)
		{
			(*it)->SetSceneEntity(0);
			mEntities.erase(it);
			mEntitiesMap.erase(id);
			return true;
		}
	}

	return false;
}
//----------------------------------------------------------------------------
bool SceneEntity::IsHasEntity (Entity *ent) const
{
	if (!ent)
		return false;

	int id = ((EN_ID*)(ent->GetM(EMT_ID)))->GetID();

	return mEntitiesMap.find(id) != mEntitiesMap.end();
}
//----------------------------------------------------------------------------
Entity *SceneEntity::GetEntityByID (int id)
{
	std::map<int, Entity*>::iterator it = mEntitiesMap.find(id);
	if (it != mEntitiesMap.end())
		return it->second;

	return 0;
}
//----------------------------------------------------------------------------
void SceneEntity::SetCameraEntity (Entity *camEntity)
{
	mCaneraEntity = camEntity;

	EM_Movable *mov = camEntity->GetM<EM_Movable>(EMT_MOVABLE);
	CameraNode *camNode = DynamicCast<CameraNode>(mov);
	if (camNode)
	{
		Camera *camera = camNode->GetCamera();
		mCuller.SetCamera(camera);
		GraphicsRoot::GetSingleton().SetCamera(camera);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称支持
//----------------------------------------------------------------------------
Object* SceneEntity::GetObjectByName (const std::string& name)
{
	Object* found = Entity::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	for (std::list<EntityPtr>::iterator it = mEntities.begin();
		it!=mEntities.end(); it++)
	{
		Entity *ent = *it;
		PX2_GET_OBJECT_BY_NAME(ent, name, found);
	}

	return 0;
}
//----------------------------------------------------------------------------
void SceneEntity::GetAllObjectsByName (const std::string& name,
	std::vector<Object*>& objects)
{
	Entity::GetAllObjectsByName(name, objects);

	for (std::list<EntityPtr>::iterator it = mEntities.begin();
		it!=mEntities.end(); it++)
	{
		Entity *ent = *it;
		PX2_GET_ALL_OBJECTS_BY_NAME(ent, name, objects);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
SceneEntity::SceneEntity (LoadConstructor value)
	:
Entity(value)
{
}
//----------------------------------------------------------------------------
void SceneEntity::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Entity::Load(source);

	int numEntities = 0;
	source.Read(numEntities);
	if (numEntities > 0)
	{
		mEntities.resize(numEntities);
		for (int i=0; i<numEntities; i++)
		{
			Entity *ent = 0;
			source.ReadPointer(ent);
			mEntities.push_back(ent);
		}
	}

	PX2_END_DEBUG_STREAM_LOAD(SceneEntity, source);
}
//----------------------------------------------------------------------------
void SceneEntity::Link (InStream& source)
{
	Entity::Link(source);

	std::list<EntityPtr>::iterator it = mEntities.begin();
	for (; it!=mEntities.end(); it++)
	{
		source.ResolveLink(*it);
		if (*it)
		{
			(*it)->SetSceneEntity(this);
		}
	}
}
//----------------------------------------------------------------------------
void SceneEntity::PostLink ()
{
	Entity::PostLink();
}
//----------------------------------------------------------------------------
bool SceneEntity::Register (OutStream& target) const
{
	if (Entity::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void SceneEntity::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Entity::Save(target);

	int numEntities = (int)mEntities.size();
	target.Write(numEntities);
	std::list<EntityPtr>::const_iterator it = mEntities.begin();
	for (; it!=mEntities.end(); it++)
	{
		target.WritePointer(*it);
	}

	PX2_END_DEBUG_STREAM_SAVE(SceneEntity, target);
}
//----------------------------------------------------------------------------
int SceneEntity::GetStreamingSize (Stream &stream) const
{
	int size = Entity::GetStreamingSize(stream);
	int numEntities = (int)mEntities.size();
	size += sizeof(numEntities);
	size += numEntities * PX2_POINTERSIZE(0);
	return size;
}
//----------------------------------------------------------------------------