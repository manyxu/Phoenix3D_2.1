/*
*
* ÎÄ¼þÃû³Æ	£º	PX2GridMoveBehavior.cpp
*
*/

#include "PX2GridMoveBehavior.hpp"
#include "PX2Actor.hpp"
#include "PX2Character.hpp"
#include "GridMove/MoveUnit.h"
#include "GridMove/MoveManager.h"
using namespace GridMove;
using namespace PX2;

//----------------------------------------------------------------------------
GridMoveBehavior::GridMoveBehavior(Actor *actor)
	:
mActor(actor), 
mUnit(0), 
mTargetActor(0), 
mStopAccumTime(0.0f)
{
}
//----------------------------------------------------------------------------
GridMoveBehavior::~GridMoveBehavior()
{
	if(mUnit)
	{
		mUnit->LeaveMap();
		mUnit->ClearObstacle();

		MoveManager *movMan = MoveManager::GetSingletonPtr();
		if (movMan)
		{
			movMan->FreeUnit(mUnit);
		}
	}
}
//----------------------------------------------------------------------------
void GridMoveBehavior::Clear ()
{
	if (mUnit)
		mUnit->ClearObstacle();
}
//----------------------------------------------------------------------------
void GridMoveBehavior::SetSpeed (float speed)
{
	if (mUnit)
	{
		mUnit->SetSpeed(speed);
	}
}
//----------------------------------------------------------------------------
bool GridMoveBehavior::StandOnMask()
{
	if (mUnit)
	{
		return mUnit->IsOnObstacle();
	}
	return false;
}
//----------------------------------------------------------------------------
void GridMoveBehavior::SetTarget(Actor *targetActor, const APoint *targetPos)
{
	MoveManager *movMan = MoveManager::GetSingletonPtr();
	if (!movMan)
		return;

	if(!mUnit)
	{
		mUnit = movMan->NewUnit();
		mUnit->SetCollisionRadius(mActor->GetSelfRadius());
		mUnit->SetMaskRadius(mActor->GetSelfRadius());
	}

	mUnit->SetPosition(mActor->GetPosition().X(), mActor->GetPosition().Y());
	mUnit->SetSpeed(mActor->GetSpeed());

	mTargetActor = targetActor;
	if (mTargetActor)
	{
		const APoint &targetPos = mTargetActor->GetPosition();
		mUnit->SetTarget(targetPos.X(), targetPos.Y());
	}
	else if (targetPos)
	{
		mUnit->SetTarget(targetPos->X(), targetPos->Y());
	}
	else
	{
		mUnit->Stop();
	}
}
//----------------------------------------------------------------------------
bool GridMoveBehavior::Update(float elapsedSeconds, APoint &pos,
	AVector &direction)
{
	PX2_UNUSED(elapsedSeconds);

	if (!mUnit) 
		return false;

	float x, y;
	mUnit->GetPosition(x, y);
	pos = APoint(x, y, 0);

	mUnit->GetDirection(x, y);
	direction = AVector(x, y, 0);

	//if (mUnit->IsStop() && mTargetActor!=NULL)
	//{
	//	mStopAccumTime += elapsedSeconds;
	//	if(mStopAccumTime >= 1.0f)
	//	{
	//		mStopAccumTime = 0;
	//		SetTarget(mTargetActor, NULL);
	//	}
	//}

	return true;
}
//----------------------------------------------------------------------------