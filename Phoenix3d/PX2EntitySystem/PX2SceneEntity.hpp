/*
*
* ÎÄ¼þÃû³Æ	£º	PX2SceneEntity.hpp
*
*/

#ifndef PX2SCENEENTITY_HPP
#define PX2SCENEENTITY_HPP

#include "PX2Entity.hpp"

namespace PX2
{

	class SceneEntity : public Entity
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(SceneEntity);

	public:
		SceneEntity ();
		virtual ~SceneEntity ();

		virtual void Update (float appTime, float elapsedTime);

		// entities
	public:
		bool AddEntity (Entity *ent);
		bool RemoveEntity (Entity *ent);
		int GetNumEntities () const;
		bool IsHasEntity (Entity *ent) const;
		Entity *GetEntityByID (int id);
		std::list<EntityPtr> &GetEntities ();

		void SetCameraEntity (Entity *camEntity);
		Entity *GetCameraEntity ();
	
	protected:
		std::list<EntityPtr> mEntities;
		std::map<int, Entity*> mEntitiesMap;
		EntityPtr mCaneraEntity;

		// Node
	public:
		Node *GetNode ();
		const Node *GetNode () const;

	protected:
		NodePtr mNode;

		// render
	public:
		void ComputeVisibleSet ();
		Culler &GetCuller ();

	protected:
		Culler mCuller;
	};

	PX2_REGISTER_STREAM(SceneEntity);
	typedef Pointer0<SceneEntity> SceneEntityPtr;
#include "PX2SceneEntity.inl"

}

#endif