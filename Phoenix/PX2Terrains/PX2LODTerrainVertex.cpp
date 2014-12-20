/*
*
* ÎÄ¼þÃû³Æ	£º	PX2LodTerrainVertex.cpp
*
*/

#include "PX2LODTerrainVertex.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
LODTerrainVertex::LODTerrainVertex ()
{
	mDependent[0] = 0;
	mDependent[1] = 0;
	mEnabled = false;
}
//----------------------------------------------------------------------------
void LODTerrainVertex::Enable ()
{
	mEnabled = true;

	if (mDependent[0])
	{
		if (!mDependent[0]->mEnabled)
		{
			mDependent[0]->Enable();
		}
	}

	if (mDependent[1])
	{
		if (!mDependent[1]->mEnabled)
		{
			mDependent[1]->Enable();
		}
	}
}
//----------------------------------------------------------------------------
void LODTerrainVertex::Disable ()
{
	mEnabled = false;

	if (mDependent[0])
	{
		if (mDependent[0]->mEnabled)
		{
			mDependent[0]->Disable();
		}
	}

	if (mDependent[1])
	{
		if (mDependent[1]->mEnabled)
		{
			mDependent[1]->Disable();
		}
	}
}
//----------------------------------------------------------------------------
