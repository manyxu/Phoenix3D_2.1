// PX2ObjectCopyPool.hpp

#ifndef PX2OBJECTCOPYPOOL_HPP
#define PX2OBJECTCOPYPOOL_HPP

#include "PX2Object.hpp"

namespace PX2
{

	class ObjectCopyPool
	{
	public:
		ObjectCopyPool();
		~ObjectCopyPool();

		// 预先分配多少个对象， 都从prototype拷贝出来
		void PreAlloc (Object *prototype, int num, bool useagain=true);
		ObjectPtr Alloc (Object *prototype);
		void Free (Object *prototype, Object *obj);

	private:
		struct ObjectPool
		{
			bool UseAgain;
			ObjectPtr ProtoType;
			std::vector<ObjectPtr> FreeObjs;
			std::vector<ObjectPtr> UsedObjs;
		};
		typedef Pointer0<ObjectPool> ObjectPoolPtr;

		std::map<void*, ObjectPoolPtr> mPools;
	};

}

#endif