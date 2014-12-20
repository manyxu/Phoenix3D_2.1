/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Actor_Props.cpp
*
*/

#include "PX2Actor.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void Actor::SetStaticType (bool isStaticType)
{
	mIsStaticType = isStaticType;

	if (mIsStaticType)
	{
		AddStopSpeedTag("StaticType");
	}
	else
	{
		RemoveStopSpeedTag("StaticType");
	}
}
//----------------------------------------------------------------------------
void Actor::SetBeBuilding (bool isBuilding)
{
	mBitSet[BST_BUILDING] = isBuilding;
	mIsBuilding = isBuilding;

	if (mIsBuilding)
		SetStaticType(true);
}
//----------------------------------------------------------------------------
void Actor::SetSelfRadius (float radius)
{
	mSelfRadius = radius;
}
//----------------------------------------------------------------------------
void Actor::SetHeight (float height)
{
	mHeight = height;
}
//----------------------------------------------------------------------------