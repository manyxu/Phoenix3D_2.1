/*
*
* 文件名称	：	PX2SkyActor.cpp
*
*/

#include "PX2SkyActor.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Actor, SkyActor);
PX2_IMPLEMENT_STREAM(SkyActor);
PX2_IMPLEMENT_FACTORY(SkyActor);

//----------------------------------------------------------------------------
SkyActor::SkyActor (SkySphere *sky)
	:
mSky(sky)
{
	if (sky)
	{
		SetMovable(sky);
	}

	SetPickable(false);
}
//----------------------------------------------------------------------------
SkyActor::~SkyActor ()
{
}
//----------------------------------------------------------------------------
void SkyActor::SetSky (SkySphere *sky)
{
	mSky = sky;
	SetMovable(mSky);
}
//----------------------------------------------------------------------------
void SkyActor::DoEnter ()
{
}
//----------------------------------------------------------------------------
void SkyActor::DoExecute (Event *event)
{
	PX2_UNUSED(event);
}
//----------------------------------------------------------------------------
void SkyActor::DoLeave ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称支持
//----------------------------------------------------------------------------
Object* SkyActor::GetObjectByName (const std::string& name)
{
	Object* found = Actor::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	return 0;
}
//----------------------------------------------------------------------------
void SkyActor::GetAllObjectsByName (const std::string& name,
	std::vector<Object*>& objects)
{
	Actor::GetAllObjectsByName(name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
SkyActor::SkyActor (LoadConstructor value)
	:
Actor(value)
{
}
//----------------------------------------------------------------------------
void SkyActor::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Actor::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadPointer(mSky);

	PX2_END_DEBUG_STREAM_LOAD(SkyActor, source);
}
//----------------------------------------------------------------------------
void SkyActor::Link (InStream& source)
{
	Actor::Link(source);
	source.ResolveLink(mSky);
}
//----------------------------------------------------------------------------
void SkyActor::PostLink ()
{
	Actor::PostLink();
}
//----------------------------------------------------------------------------
bool SkyActor::Register (OutStream& target) const
{
	if (Actor::Register(target))
	{
		target.Register(mSky);

		return true;
	}	

	return false;
}
//----------------------------------------------------------------------------
void SkyActor::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Actor::Save(target);
	PX2_VERSION_SAVE(target);

	target.WritePointer(mSky);

	PX2_END_DEBUG_STREAM_SAVE(SkyActor, target);
}
//----------------------------------------------------------------------------
int SkyActor::GetStreamingSize (Stream &stream) const
{
	int size = Actor::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	size += PX2_POINTERSIZE(mSky);

	return size;
}
//----------------------------------------------------------------------------