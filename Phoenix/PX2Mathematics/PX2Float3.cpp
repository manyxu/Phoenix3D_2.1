/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Float3.cpp
*
*/

#include "PX2Float3.hpp"
using namespace PX2;

const Float3 Float3::ZERO(0.0f, 0.0f, 0.0f);
const Float3 Float3::UNIT(1.0f, 1.0f, 1.0f);
const Float3 Float3::BLACK(0.0f, 0.0f, 0.0f);
const Float3 Float3::WHITE(1.0f, 1.0f, 1.0f);
const Float3 Float3::RED(1.0f, 0.0f, 0.0f);
const Float3 Float3::GREEN(0.0f, 1.0f, 0.0f);
const Float3 Float3::BLUE(0.0f, 0.0f, 1.0f);
const Float3 Float3::YELLOW(1.0f, 1.0f, 0.0f);

const Float3 Float3::WINGREEN(MakeColor(132, 254, 109));
const Float3 Float3::WINBLUE(MakeColor(114, 239, 255));
const Float3 Float3::WINPURPLE(MakeColor(222, 80, 226));
const Float3 Float3::WINORANGE(MakeColor(255, 175, 26));

//----------------------------------------------------------------------------
Float3::Float3 ()
{
}
//----------------------------------------------------------------------------
Float3::~Float3 ()
{
}
//----------------------------------------------------------------------------
Float3::Float3 (float f0, float f1, float f2)
{
    mTuple[0] = f0;
    mTuple[1] = f1;
    mTuple[2] = f2;
}
//----------------------------------------------------------------------------
Float3::Float3 (const Float3& tuple)
{
    mTuple[0] = tuple.mTuple[0];
    mTuple[1] = tuple.mTuple[1];
    mTuple[2] = tuple.mTuple[2];
}
//----------------------------------------------------------------------------
Float3& Float3::operator= (const Float3& tuple)
{
    mTuple[0] = tuple.mTuple[0];
    mTuple[1] = tuple.mTuple[1];
    mTuple[2] = tuple.mTuple[2];
    return *this;
}
//----------------------------------------------------------------------------
Float3 Float3::operator+ (const Float3& tuple) const
{
	Float3 tupleTemp;

	for (int i=0; i<3; ++i)
	{
		tupleTemp[i] = mTuple[i] + tuple[i];
	}

	return tupleTemp;
}
//----------------------------------------------------------------------------
Float3 Float3::operator- (const Float3& tuple) const
{
	Float3 tupleTemp;

	for (int i=0; i<3; ++i)
	{
		tupleTemp[i] = mTuple[i] - tuple[i];
	}

	return tupleTemp;
}
//----------------------------------------------------------------------------
Float3 Float3::operator* (float scalar) const
{
	Float3 tupleTemp;

	for (int i=0; i<3; ++i)
	{
		tupleTemp[i] = mTuple[i] * scalar;
	}

	return tupleTemp;
}
//----------------------------------------------------------------------------
Float3 Float3::operator/ (float scalar) const
{
	Float3 tupleTemp;

	for (int i=0; i<3; ++i)
	{
		tupleTemp[i] = mTuple[i] / scalar;
	}

	return tupleTemp;
}
//----------------------------------------------------------------------------
Float3& Float3::operator+= (const Float3& tuple)
{
	for (int i=0; i<3; ++i)
	{
		mTuple[i] += tuple[i];
	}

	return *this;
}
//----------------------------------------------------------------------------
Float3& Float3::operator-= (const Float3& tuple)
{
	for (int i=0; i<3; ++i)
	{
		mTuple[i] -= tuple[i];
	}

	return *this;
}
//----------------------------------------------------------------------------
Float3& Float3::operator*= (float scalar)
{
	for (int i=0; i<3; ++i)
	{
		mTuple[i] *= scalar;
	}

	return *this;
}
//----------------------------------------------------------------------------
Float3& Float3::operator/= (float scalar)
{
	for (int i=0; i<3; ++i)
	{
		mTuple[i] /= scalar;
	}

	return *this;
}
//----------------------------------------------------------------------------
Float3& Float3::operator- ()
{
	for (int i=0; i<3; ++i)
	{
		mTuple[i] = -mTuple[i];
	}

	return *this;
}
//----------------------------------------------------------------------------
Float3 Float3::MakeColor (unsigned int r, unsigned int g, unsigned int b)
{
	return Float3((float)r/255.0f, (float)g/255.0f, (float)b/255.0f);
}
//----------------------------------------------------------------------------