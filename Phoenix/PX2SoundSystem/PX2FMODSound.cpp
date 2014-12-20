/*
*
* ÎÄ¼þÃû³Æ	£º	PX2FMODSound.cpp
*
*/

#include "PX2FMODSound.hpp"

using namespace PX2;

//----------------------------------------------------------------------------
FMODSound::FMODSound (FMOD::Channel *channel)
{
	mChannel = channel;
}
//----------------------------------------------------------------------------
FMODSound::~FMODSound ()
{
	if (mChannel)
		mChannel->stop();
}
//----------------------------------------------------------------------------
bool FMODSound::IsPlaying ()
{
	bool isPlaying = false;
	mChannel->isPlaying(&isPlaying);

	return isPlaying;
}
//----------------------------------------------------------------------------
void FMODSound::SetVolume (float volume)
{
	mChannel->setVolume(volume);
}
//----------------------------------------------------------------------------
void FMODSound::SetPaused (bool paused)
{
	mChannel->setPaused(paused);
}
//----------------------------------------------------------------------------
void FMODSound::Stop ()
{
	mChannel->stop();
}
//----------------------------------------------------------------------------
void FMODSound::SetPosition (const APoint &position)
{
	FMOD_VECTOR pos;
	pos.x = position.X();
	pos.y = position.Y();
	pos.z = position.Z();

	if (mChannel)
		mChannel->set3DAttributes(&pos, 0);
}
//----------------------------------------------------------------------------
void FMODSound::SetVelocity (const AVector &velocity)
{
	FMOD_VECTOR vec;
	vec.x = velocity.X();
	vec.y = velocity.Y();
	vec.z = velocity.Z();

	if (mChannel)
		mChannel->set3DAttributes(0, &vec);
}
//----------------------------------------------------------------------------
void FMODSound::SetDistance (float minDistance, float maxDistance)
{
	if (mChannel)
		mChannel->set3DMinMaxDistance(minDistance, maxDistance);
}
//----------------------------------------------------------------------------