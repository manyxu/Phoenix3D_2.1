
#ifndef __MOVEUNIT_H__
#define __MOVEUNIT_H__

#include "../RVO/Vector2.h"
#include "GridMovePre.h"
#include "GridMap.h"

#ifdef USE_RVO
namespace RVO
{
	class RVOSimulator;
}
#endif

namespace GridMove
{

	class MoveManager;

	class MoveUnit
	{
		enum
		{
			STATE_STOP = 0,
			STATE_MOVE
		};

		friend class MoveManager;
	public:

		// 使用ROV时有效
		void SetCollisionRadius(float radius);

		void SetMaskRadius(float radius);

		void ClearObstacle();
		bool IsStop()
		{
			return mState == STATE_STOP;
		}

		void LeaveMap();
		void SetPosition(float x, float y);
		void SetSpeed(float speed);
		void SetTarget(float x, float y); //往这个目标点直线走
		void SetTarget(MoveUnit *target, int range);
		void Stop();
		bool IsOnObstacle();

		void Update(float dtime);

		void GetPosition(float &x, float &y);
		void GetDirection(float &x, float &y);

	private:
		MoveUnit();
		~MoveUnit();
		void SetObstacle(const RVO::Vector2 &pos);
		void GoPath(const RVO::Vector2 &finalgoal);
		void CheckNewPath();
		bool GetNearGoal(RVO::Vector2 &goal); //路径太长，寻路太耗，所以缩短， 返回是否缩短了

	private:
#ifdef USE_RVO
		RVO::RVOSimulator *mSimulator;
		size_t mAgent;
#endif

		float mSpeed;
		float mAccumMoveLen;

		int mState;
		RVO::Vector2 mTargetPos;

		CNaviPath mNaviPath;
		int mCurPathPoint;
		int mMoveSegLen;

		RVO::Vector2 mCurPos;
		RVO::Vector2 mCurDir;

		float mMaskRadius;
		RVO::Vector2 mMaskStopPoint;
		bool mMaskStop;
	};

}

#endif