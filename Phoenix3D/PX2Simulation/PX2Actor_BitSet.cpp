// PX2Actor_BitSet.cpp

#include "PX2Actor.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void Actor::SetTypeID(int typeID)
{
	mTypeID = typeID;
}
//----------------------------------------------------------------------------
void Actor::SetGroup(int group)
{
	mGroup = group;

	if (1 == group)
	{
		mBitSet[BST_GROUP1] = 1;
		mBitSet[BST_GROUP2] = 0;
	}
	else if (2 == group)
	{
		mBitSet[BST_GROUP1] = 0;
		mBitSet[BST_GROUP2] = 1;
	}
}
//----------------------------------------------------------------------------
bool Actor::IsContainAllBits(const std::bitset<PX2_ACTOR_BS_SIZE> &bits) const
{
	if (bits.none())
		return false;

	if (mBitSet[BST_CHARACTER] && !bits[BST_CHARACTER])
		return false;

	if (!bits[BST_BUILDINGINGORE])
	{
		if (mBitSet[BST_BUILDING] && !bits[BST_BUILDING])
			return false;
	}

	if (!mBitSet[BST_CANBEAIMED] && bits[BST_CANBEAIMED])
		return false;

	if (mBitSet[BST_GROUP1] && !bits[BST_GROUP1])
		return false;

	if (mBitSet[BST_GROUP2] && !bits[BST_GROUP2])
		return false;

	return true;
}
//----------------------------------------------------------------------------