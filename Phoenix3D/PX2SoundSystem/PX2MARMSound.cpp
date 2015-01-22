/*
*
* ÎÄ¼þÃû³Æ	£º	PX2MARMSound.cpp
*
*/

#include "PX2MARMSound.hpp"
#include "s3eSound.h"

using namespace PX2;

//----------------------------------------------------------------------------
MARMSound::MARMSound (int channel)
{
	mChannel = channel;
}
//----------------------------------------------------------------------------
MARMSound::~MARMSound ()
{
//	if (mChannel >= 0)
	//	s3eSoundChannelStop(mChannel);
}
//----------------------------------------------------------------------------
bool MARMSound::IsPlaying ()
{
	return mChannel>=0;
}
//----------------------------------------------------------------------------
void MARMSound::SetVolume (float volume)
{
//	if(mChannel>=0) s3eSoundChannelSetInt(mChannel, S3E_CHANNEL_VOLUME, int(volume*S3E_SOUND_MAX_VOLUME));
}
//----------------------------------------------------------------------------
void MARMSound::SetPaused (bool paused)
{
	if(mChannel>=0) s3eSoundChannelPause(mChannel);
}
//----------------------------------------------------------------------------
void MARMSound::Stop ()
{
	//if(mChannel>=0) s3eSoundChannelStop(mChannel);
}
//----------------------------------------------------------------------------
void MARMSound::SetPosition (const APoint &position)
{
}
//----------------------------------------------------------------------------
void MARMSound::SetVelocity (const AVector &velocity)
{
}
//----------------------------------------------------------------------------
void MARMSound::SetDistance (float minDistance, float maxDistance)
{
}
//----------------------------------------------------------------------------