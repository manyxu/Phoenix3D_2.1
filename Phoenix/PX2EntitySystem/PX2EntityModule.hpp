/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EntityModule.hpp
*
*/

#ifndef PX2ENTITYMODULE_HPP
#define PX2ENTITYMODULE_HPP

#include "PX2Object.hpp"
#include "PX2Visitor.hpp"

namespace PX2
{

	class Entity;

	class EntityModule : public Object
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(EntityModule);
		PX2_VISITOR;
	public:
		EntityModule ();
		~EntityModule();

		virtual void Update (float appTime, float elapsedTime);

		// create
		static EntityModule *Create (int type);

		// entity
	public:
		Entity*GetEntity ();
		const Entity *GetEntity () const;

public_internal:
		void SetEntity (Entity *ent);

	protected:
		Entity *mEntity;
	};

	PX2_REGISTER_STREAM(EntityModule);
	typedef Pointer0<EntityModule> EntityModulePtr;
#include "PX2EntityModule.inl"

}

#endif