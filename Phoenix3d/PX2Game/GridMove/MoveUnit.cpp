
#include "MoveUnit.h"
#include "MoveManager.h"

#ifdef USE_RVO
#include "..\\RVO\\RVOSimulator.h"
const float OUTRANGE_FLT = -9999999.0f;
#endif

using namespace GridMove;

//----------------------------------------------------------------------------
inline Point2D RVOVec2Point2D(const RVO::Vector2 &vec)
{
	return Point2D(int(vec.x()*FIXPOINT_SCALE), int(vec.y()*FIXPOINT_SCALE));
}
//----------------------------------------------------------------------------
inline RVO::Vector2 Point2D2RVOVec(const Point2D &pt)
{
	return RVO::Vector2(pt.x/FIXPOINT_SCALE, pt.y/FIXPOINT_SCALE);
}
//----------------------------------------------------------------------------
MoveUnit::MoveUnit() 
	: 
mState(STATE_STOP), 
mCurPathPoint(-1),
mMaskStop(false),
mSpeed(0.0f),
mMaskRadius(0.0f),
mMoveSegLen(0),
mAccumMoveLen(0.0f)
{
}
//----------------------------------------------------------------------------
MoveUnit::~MoveUnit()
{
}
//----------------------------------------------------------------------------
void MoveUnit::SetCollisionRadius(float radius)
{
	PX2_UNUSED(radius);

	radius *= 0.8f;

#ifdef USE_RVO
	mSimulator->setAgentRadius(mAgent, radius);
#endif
}
//----------------------------------------------------------------------------
void MoveUnit::SetMaskRadius(float radius)
{
	mMaskRadius = radius*1.2f;
}
//----------------------------------------------------------------------------
void MoveUnit::LeaveMap()
{
#ifdef USE_RVO
	mSimulator->setAgentPosition(mAgent, RVO::Vector2(OUTRANGE_FLT,OUTRANGE_FLT));
	mSimulator->setAgentMaxSpeed(mAgent, 0);
#endif
}
//----------------------------------------------------------------------------
void MoveUnit::SetPosition(float x, float y)
{
#ifdef USE_RVO
	mSimulator->setAgentPosition(mAgent, RVO::Vector2(x,y));
#endif
	mCurPos = RVO::Vector2(x,y);
}
//----------------------------------------------------------------------------
void MoveUnit::SetSpeed(float speed)
{
#ifdef USE_RVO
	mSimulator->setAgentMaxSpeed(mAgent, speed);
#endif
	mSpeed = speed;
}
//----------------------------------------------------------------------------
bool MoveUnit::GetNearGoal(RVO::Vector2 &goal)
{
	MoveManager *moveMan = MoveManager::GetSingletonPtr();
	if (!moveMan)
		return false;

	const RVO::Vector2 &curpos = mCurPos;

	RVO::Vector2 vec = goal - curpos;
	float len = abs(vec);
	float maxlen = moveMan->GetGridSizeX()*10.0f;

	if(len > maxlen*1.2f) //防止剩下的那段太短
	{
		goal = curpos + vec*(maxlen/len);
		return true;
	}
	else
	{
		return false;
	}
}
//----------------------------------------------------------------------------
void MoveUnit::SetTarget(float x, float y)
{
	MoveManager::GetSingletonPtr()->LimitPointInRange(x, y);

	mTargetPos = RVO::Vector2(x, y);

	GoPath(mTargetPos);
}
//----------------------------------------------------------------------------
void MoveUnit::Stop()
{
#ifdef USE_RVO
	mSimulator->setAgentMaxSpeed(mAgent, 0);
#endif

	mState = STATE_STOP;
	SetObstacle(mCurPos);
}
//----------------------------------------------------------------------------
void MoveUnit::SetObstacle (const RVO::Vector2 &pos)
{
	MoveManager *moveMan = MoveManager::GetSingletonPtr();
	if (!moveMan)
		return;
	
	ClearObstacle();

	mMaskStopPoint = pos;
	Point2D pt = RVOVec2Point2D(pos);
	int r = int(mMaskRadius*FIXPOINT_SCALE)-1;

	moveMan->GetMap()->UpdateMask(pt.x-r, pt.y-r, pt.x+r, pt.y+r, true);

	mMaskStop = true;
}
//----------------------------------------------------------------------------
void MoveUnit::ClearObstacle()
{
	MoveManager *moveMan = MoveManager::GetSingletonPtr();
	if (!moveMan)
		return;

	if (mMaskStop)
	{
		Point2D pt = RVOVec2Point2D(mMaskStopPoint);
		int r = int(mMaskRadius*FIXPOINT_SCALE)-1;

		if (moveMan->GetMap())
		{
			moveMan->GetMap()->UpdateMask(pt.x-r, pt.y-r, pt.x+r, pt.y+r, false);
		}
		mMaskStop = false;
	}
}
//----------------------------------------------------------------------------
bool MoveUnit::IsOnObstacle()
{
	MoveManager *moveMan = MoveManager::GetSingletonPtr();
	if (!moveMan)
		return false;

	if (moveMan->GetMap())
	{
		Point2D pt = RVOVec2Point2D(mCurPos);
		if(!moveMan->GetMap()->CanWalk(pt.x, pt.y, CLogicMap::maskStop)) return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void MoveUnit::GoPath(const RVO::Vector2 &finalgoal)
{
	MoveManager *moveMan = MoveManager::GetSingletonPtr();
	if (!moveMan)
		return;

	RVO::Vector2 goal = finalgoal;
	bool changed = GetNearGoal(goal);
	Point2D start = RVOVec2Point2D(mCurPos);
	Point2D end = RVOVec2Point2D(goal);

	CLogicMap *pmap = moveMan->GetMap();
	bool isfind = false;

	PX2_UNUSED(changed);
	PX2_UNUSED(pmap);

	/*
	if(changed)
	{
		isfind = pmap->FindPointWalkable(end, 2);
		if(!isfind) end = RVOVec2Point2D(finalgoal);
	}
	if(!isfind) isfind = pmap->FindPointWalkable(end, 20);
	assert(isfind);
	*/

	if (start == end)
	{
		isfind = false;
	}
	else
	{
		//isfind = moveMan->GetMap()->FindNaviPath(mNaviPath, Point2D(215, 3099), Point2D(750, 2600));

		isfind = moveMan->GetMap()->FindNaviPath(mNaviPath, start, end);
		assert(isfind);
	}

	if (!isfind)
	{
		Stop();
		return;
	}

	assert(mNaviPath.GetNumPoint() > 1);

	mNaviPath.SmoothPath();
	mNaviPath.ComputePathSegLen();
	mCurPathPoint = 0;
	mMoveSegLen = 0;
	mAccumMoveLen = 0.0f;
	mState = STATE_MOVE;

	ClearObstacle();
}
//----------------------------------------------------------------------------
void MoveUnit::Update(float dtime)
{
	if(mState==STATE_STOP)
	{
		return;
	}

	assert(mCurPathPoint < mNaviPath.GetNumPoint()-1);

#ifndef USE_RVO
	if (!mNaviPath.IsPathOK(mCurPathPoint, mMoveSegLen))
	{
		CheckNewPath();
		return;
	}

	mAccumMoveLen += mSpeed*dtime*FIXPOINT_SCALE;
	int movelen = int(mAccumMoveLen);
	mAccumMoveLen -= movelen;

	Point2D curpt = mNaviPath.MoveOnPath(mCurPathPoint, mMoveSegLen,  movelen);
	if (mCurPathPoint == mNaviPath.GetNumPoint()-1)
	{
		mCurPos = RVO::Vector2(mNaviPath.GetPathGoal().x/ FIXPOINT_SCALE, mNaviPath.GetPathGoal().y/ FIXPOINT_SCALE);
		CheckNewPath();
		return;
	}

	mCurPos = RVO::Vector2(curpt.x/FIXPOINT_SCALE, curpt.y/FIXPOINT_SCALE);

	Point2D vec = mNaviPath.GetPathPoint(mCurPathPoint+1) - mNaviPath.GetPathPoint(mCurPathPoint);
	mCurDir = RVO::Vector2(vec.x/FIXPOINT_SCALE, vec.y/FIXPOINT_SCALE);
	mCurDir = RVO::normalize(mCurDir);

#else
	RVO::Vector2 goal = Point2D2RVOVec(mNaviPath.GetPathPoint(mCurPathPoint+1));
	RVO::Vector2 curpos = mSimulator->getAgentPosition(mAgent);
	RVO::Vector2 dpos = goal - curpos;
	float abssq = RVO::absSq(dpos);
	float radius = mSimulator->getAgentRadius(mAgent);

	if(abssq < radius*radius) //reach next pathpoint
	{
		mCurPathPoint++;
		if(mCurPathPoint == mNaviPath.GetNumPoint()-1)
		{
			CheckNewPath();
			return;
		}

		goal = Point2D2RVOVec(mNaviPath.GetPathPoint(mCurPathPoint+1));
		dpos = goal - curpos;
	}

	RVO::normalize(dpos);
	mCurDir = dpos;
	mCurPos = curpos;

	float angle = std::rand() * 2.0f * 3.14159f / RAND_MAX;
	float dist = std::rand() * 0.0001f / RAND_MAX;
	float maxspeed = mSimulator->getAgentMaxSpeed(mAgent);

	dpos = dpos*maxspeed + dist * RVO::Vector2(std::cos(angle), std::sin(angle));
	mSimulator->setAgentPrefVelocity(mAgent, dpos);
#endif
}
//----------------------------------------------------------------------------
void MoveUnit::GetPosition(float &x, float &y)
{
	x = mCurPos.x();
	y = mCurPos.y();
}
//----------------------------------------------------------------------------
void MoveUnit::GetDirection(float &x, float &y)
{
	x = mCurDir.x();
	y = mCurDir.y();
}
//----------------------------------------------------------------------------
void MoveUnit::CheckNewPath()
{
	RVO::Vector2 vec = mTargetPos - mCurPos;
	float r = 0.1f;

	if (absSq(vec) > r*r) //还没到目标， 继续往目标寻路
	{
		GoPath(mTargetPos);
	}
	else
	{
		Stop();
	}
}
//----------------------------------------------------------------------------