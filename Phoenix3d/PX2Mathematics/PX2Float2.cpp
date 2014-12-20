/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Float2.cpp
*
*/

#include "PX2Float2.hpp"
using namespace PX2;

const Float2 Float2::ZERO(0.0f, 0.0f);
const Float2 Float2::UNIT(1.0f, 1.0f);
const Float2 Float2::HALFUNIT(0.5f, 0.5f);

//----------------------------------------------------------------------------
Float2::Float2 ()
{
}
//----------------------------------------------------------------------------
Float2::~Float2 ()
{
}
//----------------------------------------------------------------------------
Float2::Float2 (float f0, float f1)
{
	mTuple[0] = f0;
	mTuple[1] = f1;
}
//----------------------------------------------------------------------------
Float2::Float2 (const Float2& tuple)
{
	mTuple[0] = tuple.mTuple[0];
	mTuple[1] = tuple.mTuple[1];
}
//----------------------------------------------------------------------------
Float2& Float2::operator= (const Float2& tuple)
{
	mTuple[0] = tuple.mTuple[0];
	mTuple[1] = tuple.mTuple[1];
	return *this;
}
//----------------------------------------------------------------------------
