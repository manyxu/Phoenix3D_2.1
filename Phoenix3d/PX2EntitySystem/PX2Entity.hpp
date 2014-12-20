/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Entity.hpp
*
*/

#ifndef PX2ENTITY_HPP
#define PX2ENTITY_HPP

#include "PX2EntitySystemPre.hpp"
#include "PX2EntityModule.hpp"
#include "PX2Node.hpp"

namespace PX2
{

	class Entity : public Object
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(Entity);

	public:
		Entity ();
		~Entity();

		virtual void Update (float appTime, float elapsedTime);

		// modules
	public:
		void AddM (int type);
		void RemM (int type);
		bool IsHasM (int type) const;
		EntityModule *GetM (int type);
		template <typename T>
		T *GetM (int type);

	protected:
		std::vector<EntityModulePtr> mEntityModules;

		// SceneEntity
public_internal:
		void SetSceneEntity (Entity *ent);
		Entity *GetSceneEntity ();
		const Entity *GetSceneEntity () const;

	protected:
		Entity *mSceneEntity;
	};

	PX2_REGISTER_STREAM(Entity);
	typedef Pointer0<Entity> EntityPtr;
#include "PX2Entity.inl"

}

#endif