/*
*
* 文件名称	：	PX2DeletingMan.hpp
*
*/

#ifndef PX2DELETINGMANAGER_HPP
#define PX2DELETINGMANAGER_HPP

#include "PX2GamePre.hpp"
#include "PX2Singleton.hpp"
#include "PX2Movable.hpp"
#include "PX2SmartPointer.hpp"
#include "PX2Actor.hpp"
#include "PX2Scene.hpp"

namespace PX2
{

	class DeletingObj
	{
	public:
		DeletingObj();
		~DeletingObj();

		float AddedTime; //s
		float StopDelayTime;
		float DeleteDelayTime;
		MovablePtr Mov;
		NodePtr TheParent;
		ActorPtr TheActor;
		ScenePtr TheScene;
	};
	typedef Pointer0<DeletingObj> DeletingObjPtr;

	/// 是个删除管理器，用来自动将一个特效或者间隔一定时间从场景删除
	class DeletingManager : public Singleton<DeletingManager>
	{
	public:
		DeletingManager ();
		virtual ~DeletingManager ();

		void Clear ();

		// 先stopDelayTime，然后再延后stopDeleteDelayTime
		void AddDeletingObj (Movable *mov, float stopDelayTime, 
			float deleteAfterStopDelayTime);
		void AddDeletingObj (Actor *actor, float stopDelayTime,
			float deleteAfterStopDelayTime);
		int GetNumStopingObjs () const;
		int GetNumDeletingObjs () const;

		virtual void Update (double appSeconds, double elapsedSeconds);

	protected:
		float mElapsedTime;
		std::list<DeletingObjPtr> mStopingObjs;
		std::list<DeletingObjPtr> mDeletingObjs;
	};

#define PX2_DM DeletingManager::GetSingleton()

}

#endif