/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Actor_TransMoving.cpp
*
*/

#include "PX2Actor.hpp"
#include "PX2Scene.hpp"
#include "PX2PropModify.hpp"
#include "PX2MoveBehavior_Free.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
PX2_IMPLEMENT_PM_F(Actor, MaxSpeed);
//----------------------------------------------------------------------------
void Actor::SetScale (const APoint &scale)
{
	if (scale == mScale)
		return;

	mScale = scale;

	if (0.0f==mScale.X() || 0.0f==mScale.Y() || 0.0f==mScale.Z())
	{
		mScale.X() = 0.0001f;
	}

	if (mMovable)
	{
		mMovable->LocalTransform.SetScale(scale);
	}

	if (mHelpMovable)
	{
		mHelpMovable->LocalTransform.SetScale(scale);
	}
}
//----------------------------------------------------------------------------
void Actor::SetRotation (const APoint &rolate)
{
	if (rolate == mRotation)
		return;

	mRotation = rolate;

	if (mMovable)
	{
		mMovable->LocalTransform.SetRotate(Matrix3f().MakeEulerXYZ(
			rolate.X(), rolate.Y(), rolate.Z()));
	}

	if (mHelpMovable)
	{
		mHelpMovable->LocalTransform.SetRotate(Matrix3f().MakeEulerXYZ(
			rolate.X(), rolate.Y(), rolate.Z()));
	}
}
//----------------------------------------------------------------------------
void Actor::SetFace (const AVector &dir, const AVector &uping)
{
	AVector right = dir.Cross(uping);
	right.Normalize();
	AVector up = right.Cross(dir);
	up.Normalize();

	Matrix3f matRot(right, dir, up, true);

	if (mMovable)
	{
		mMovable->LocalTransform.SetRotate(matRot);
	}

	if (mHelpMovable)
	{
		mHelpMovable->LocalTransform.SetRotate(matRot);
	}
}
//----------------------------------------------------------------------------
void Actor::SetPosition (const APoint &position)
{
	if (position == mPosition)
		return;

	APoint beforePosition = mPosition;
	mPosition = position;

	if (mMovable)
	{
		mMovable->LocalTransform.SetTranslate(position);
	}

	if (mHelpMovable)
	{
		mHelpMovable->LocalTransform.SetTranslate(position);
	}

	if (mScene)
	{
		mScene->OnActorPositionChanged(this, beforePosition);
	}
}
//----------------------------------------------------------------------------
float Actor::GetPercentSpeedOverModified ()
{
	if (0.0f == mMMaxSpeed)
		return 0.0f;

	return mMaxSpeed/mMMaxSpeed;
}
//----------------------------------------------------------------------------
void Actor::AddStopSpeedTag (const std::string &tag)
{
	if (IsHasStopSpeedTag(tag))
		return;

	mStopSpeedTags.push_back(tag);
}
//----------------------------------------------------------------------------
void Actor::RemoveStopSpeedTag (const std::string &tag)
{
	std::vector<std::string>::iterator it = mStopSpeedTags.begin();
	for (; it!=mStopSpeedTags.end();)
	{
		if ((*it) == tag)
		{
			it = mStopSpeedTags.erase(it);
		}
		else
		{
			it++;
		}
	}
}
//----------------------------------------------------------------------------
bool Actor::IsHasStopSpeedTag (const std::string &tag) const
{
	for (int i=0; i<(int)mStopSpeedTags.size(); i++)
	{
		if (tag == mStopSpeedTags[i])
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
const std::vector<std::string> Actor::GetStopSpeedTags () const
{
	return mStopSpeedTags;
}
//----------------------------------------------------------------------------
void Actor::SetVelocityDir (const AVector &vec)
{
	mVelocityDir = vec;
}
//----------------------------------------------------------------------------
void Actor::SetHeadingAlignVelocityDir (bool isAlign)
{
	mIsHeadingAlignVelocityDir = isAlign;
}
//----------------------------------------------------------------------------
void Actor::SetHeading (const AVector &heading)
{
	mHeading = heading;
}
//----------------------------------------------------------------------------
void Actor::OnUpdateGoToPosition (const APoint &toPos)
{
	SetPosition(toPos);
}
//----------------------------------------------------------------------------
void Actor::OnUpdateGoToStop ()
{
}
//----------------------------------------------------------------------------
void Actor::SetSmoothHeading (const AVector &soomthHeading)
{
	mSmoothHeading = soomthHeading;
	SetFace(mSmoothHeading);
}
//----------------------------------------------------------------------------
void Actor::SetMoveBehaviorType (MoveBehaviorType type)
{
	mMoveBehaviorType = type;

	if (MBT_NONE == type)
	{
		mMoveBehavior = 0;
	}
	else if (MBT_FREE == type)
	{
		mMoveBehavior = new0 MoveBehaviorFree(this);
	}
	else
	{
		mMoveBehavior = 0;
	}
}
//----------------------------------------------------------------------------
void Actor::GoTo (const APoint &pos)
{
	if (mMoveBehavior)
	{
		mMoveBehavior->SetTarget(0, &pos);
	}	
}
//----------------------------------------------------------------------------