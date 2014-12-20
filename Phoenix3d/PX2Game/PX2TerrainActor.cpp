/*
*
* 文件名称	：	PX2RawTerrainActor.cpp
*
*/

#include "PX2TerrainActor.hpp"
#include "PX2Scene.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Actor, TerrainActor);
PX2_IMPLEMENT_STREAM(TerrainActor);
PX2_IMPLEMENT_FACTORY(TerrainActor);

TerrainActor::TerrainActor ()
	:
mIsUseLOD(false)
{
}
//----------------------------------------------------------------------------
TerrainActor::~TerrainActor ()
{
}
//----------------------------------------------------------------------------
void TerrainActor::UseLod (bool use)
{
	mIsUseLOD = use;

	if (!mIsUseLOD)
	{
		SetMovable(mRawTerrain);
	}
	else
	{
		SetMovable(mLODTerrain);
	}
}
//----------------------------------------------------------------------------
void TerrainActor::SetRawTerrain (RawTerrain *terrain)
{
	mRawTerrain = terrain;
	UseLod(mIsUseLOD);
}
//----------------------------------------------------------------------------
void TerrainActor::SetLODTerrain(LODTerrain *terrain)
{
	mLODTerrain = terrain;
	UseLod(mIsUseLOD);
}
//----------------------------------------------------------------------------
void TerrainActor::DoEnter ()
{
}
//----------------------------------------------------------------------------
void TerrainActor::DoExecute (Event *event)
{
	PX2_UNUSED(event);
}
//----------------------------------------------------------------------------
void TerrainActor::DoLeave ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void TerrainActor::RegistProperties ()
{
	Actor::RegistProperties();

	AddPropertyClass("TerrainActor");

	AddProperty("IsUseLod", Object::PT_BOOL, IsUseLod(), false);
}
//----------------------------------------------------------------------------
void TerrainActor::OnPropertyChanged (const PropertyObject &obj)
{
	Actor::OnPropertyChanged(obj);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称支持
//----------------------------------------------------------------------------
Object* TerrainActor::GetObjectByName (const std::string& name)
{
	Object* found = Actor::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	return 0;
}
//----------------------------------------------------------------------------
void TerrainActor::GetAllObjectsByName (const std::string& name,
	std::vector<Object*>& objects)
{
	Actor::GetAllObjectsByName(name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
TerrainActor::TerrainActor (LoadConstructor value)
	:
Actor(value)
{
}
//----------------------------------------------------------------------------
void TerrainActor::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Actor::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadBool(mIsUseLOD);
	source.ReadPointer(mRawTerrain);
	source.ReadPointer(mLODTerrain);

	PX2_END_DEBUG_STREAM_LOAD(TerrainActor, source);
}
//----------------------------------------------------------------------------
void TerrainActor::Link (InStream& source)
{
	Actor::Link(source);
	source.ResolveLink(mRawTerrain);
	source.ResolveLink(mLODTerrain);
}
//----------------------------------------------------------------------------
void TerrainActor::PostLink ()
{
	Actor::PostLink();
}
//----------------------------------------------------------------------------
bool TerrainActor::Register (OutStream& target) const
{
	if (Actor::Register(target))
	{
		target.Register(mRawTerrain);
		target.Register(mLODTerrain);

		return true;
	}	

	return false;
}
//----------------------------------------------------------------------------
void TerrainActor::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Actor::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteBool(mIsUseLOD);
	target.WritePointer(mRawTerrain);
	target.WritePointer(mLODTerrain);

	PX2_END_DEBUG_STREAM_SAVE(TerrainActor, target);
}
//----------------------------------------------------------------------------
int TerrainActor::GetStreamingSize (Stream &stream) const
{
	int size = Actor::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_BOOLSIZE(mIsUseLOD);
	size += PX2_POINTERSIZE(mRawTerrain);
	size += PX2_POINTERSIZE(mLODTerrain);

	return size;
}
//----------------------------------------------------------------------------