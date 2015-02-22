// PX2Sound.cpp

#include "PX2Sound.hpp"
#include "PX2SoundSystem.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
Sound::Sound()
{
}
//----------------------------------------------------------------------------
Sound::~Sound()
{
}
//----------------------------------------------------------------------------
void Sound::MinusNumPlaySameTime()
{
	SoundSystem *sys = SoundSystem::GetSingletonPtr();
	if (sys)
	{
		sys->_MinusNumPlaySameTime(Filename.c_str());
	}
}
//----------------------------------------------------------------------------