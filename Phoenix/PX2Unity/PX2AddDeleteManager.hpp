// PX2AddDeleteManager.hpp

#ifndef PX2ADDDELETEMANAGER_HPP
#define PX2ADDDELETEMANAGER_HPP

#include "PX2Node.hpp"
#include "PX2Singleton_NeedNew.hpp"

namespace PX2
{

	class AddingObj
	{
	public:
		AddingObj();
		~AddingObj();

		float UpdateTime;
		float DelayTime; // seconds
		MovablePtr TheMov;
		bool DoResetPlay;
		NodePtr TheNode;
	};
	typedef Pointer0<AddingObj> AddingObjPtr;

	class DeletingObj
	{
	public:
		DeletingObj();
		~DeletingObj();

		float UpdateTime; // seconds
		float StopDelayTime;
		float DeleteDelayTime;
		MovablePtr Mov;
		NodePtr TheParent;
	};
	typedef Pointer0<DeletingObj> DeletingObjPtr;

	class AddDeleteManager : public Singleton<AddDeleteManager>
	{
	public:
		AddDeleteManager();
		virtual ~AddDeleteManager();

		void Clear();

		void AddAddingObjResetPlay(Movable *mov, float delayTime);
		void AddAddingObj(Node *parent, Movable *mov, float delayTime,
			bool doResetPlay);

		void AddDeletingObj(Movable *mov, float stopDelayTime,
			float deleteAfterStopDelayTime);

		void Update(double appSeconds, double elapsedSeconds);

	protected:
		static float msFreqElapseTemp;
		float mFreqElapsingTime;

		std::list<AddingObjPtr> mAddingObjs;

		std::list<DeletingObjPtr> mStopingObjs;
		std::list<DeletingObjPtr> mDeletingObjs;
	};

#define PX2_ADM AddDeleteManager::GetSingleton()

}

#endif