/*
*
* ÎÄ¼þÃû³Æ	£º	PX2AddingManager.hpp
*
*/

#ifndef PX2ADDINGMANAGER_HPP
#define PX2ADDINGMANAGER_HPP

#include "PX2Movable.hpp"
#include "PX2SmartPointer.hpp"
#include "PX2Actor.hpp"
#include "PX2Scene.hpp"

namespace PX2
{

	class AddingObj
	{
	public:
		AddingObj();
		~AddingObj();

		float AddedTime;
		float DelayTime; //s
		MovablePtr TheMov;
		ActorPtr TheActor;
		bool DoResetPlay;
		NodePtr TheNode;
		ScenePtr TheScene;
	};
	typedef Pointer0<AddingObj> AddingObjPtr;

	class AddingManager : public Singleton<AddingManager>
	{
	public:
		AddingManager ();
		virtual ~AddingManager ();

		void Clear ();

		void AddAddingObjResetPlay (Movable *mov, float delayTime);
		void AddAddingObj (Node *parent, Movable *mov, float delayTime, bool doResetPlay);
		void AddAddingObj (Scene *scene, Actor *actor, float delayTime, bool doResetPlay);

		virtual void Update (double appSeconds, double elapsedSeconds);

	protected:
		float mElapsedTime;
		std::list<AddingObjPtr> mAddingObjs;
	};

	#define PX2_ADM AddingManager::GetSingleton()

}

#endif