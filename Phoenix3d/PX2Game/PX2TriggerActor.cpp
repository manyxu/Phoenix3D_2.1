/*
*
* 文件名称	：	PX2TriggerActor.cpp
*
*/

#include "PX2TriggerActor.hpp"
#include "PX2ContSphere3.hpp"
#include "PX2Node.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Actor, TriggerActor);
PX2_IMPLEMENT_STREAM(TriggerActor);
PX2_IMPLEMENT_FACTORY(TriggerActor);

//----------------------------------------------------------------------------
TriggerActor::TriggerActor ()
	:
mAreaType(AT_MAX_TYPE)
{
}
//----------------------------------------------------------------------------
TriggerActor::~TriggerActor ()
{
}
//----------------------------------------------------------------------------
void TriggerActor::SetArea (PX2::AxisAlignedBox3f box)
{
	mBox = box;
	mAreaType = AT_BOX;
}
//----------------------------------------------------------------------------
void TriggerActor::SetArea (PX2::Sphere3f sphere)
{
	mSphere = sphere;
	mAreaType = AT_SPHERE;
}
//----------------------------------------------------------------------------
bool TriggerActor::IsPointIn (PX2::APoint point)
{
	if (mAreaType == AT_SPHERE)
	{
		return InSphere<float>(point, mSphere);
	}
	else if (mAreaType == AT_BOX)
	{
		if (point.X()>=mBox.Min[0] &&
			point.Y()>=mBox.Min[1] &&
			point.Z()>=mBox.Min[2] &&
			point.X()<=mBox.Max[0] &&
			point.Y()<=mBox.Max[1] &&
			point.Z()<=mBox.Max[2])
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void TriggerActor::DoEnter ()
{
}
//----------------------------------------------------------------------------
void TriggerActor::DoExecute (Event *event)
{
	PX2_UNUSED(event);
}
//----------------------------------------------------------------------------
void TriggerActor::DoLeave ()
{

}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称支持
//----------------------------------------------------------------------------
Object* TriggerActor::GetObjectByName (const std::string& name)
{
	Object* found = Actor::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	return 0;
}
//----------------------------------------------------------------------------
void TriggerActor::GetAllObjectsByName (const std::string& name,
	std::vector<Object*>& objects)
{
	Actor::GetAllObjectsByName(name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
TriggerActor::TriggerActor (LoadConstructor value)
	:
Actor(value)
{
}
//----------------------------------------------------------------------------
void TriggerActor::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Actor::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadBool(mEnable);
	source.ReadEnum(mAreaType);
	source.Read(mBox.Min[0]);
	source.Read(mBox.Min[1]);
	source.Read(mBox.Min[2]);
	source.Read(mBox.Max[0]);
	source.Read(mBox.Max[1]);
	source.Read(mBox.Max[2]);
	source.ReadAggregate<Vector3f>(mSphere.Center);
	source.Read(mSphere.Radius);

	PX2_END_DEBUG_STREAM_LOAD(TriggerActor, source);
}
//----------------------------------------------------------------------------
void TriggerActor::Link (InStream& source)
{
	Actor::Link(source);
}
//----------------------------------------------------------------------------
void TriggerActor::PostLink ()
{
	Actor::PostLink();
}
//----------------------------------------------------------------------------
bool TriggerActor::Register (OutStream& target) const
{
	if (Actor::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void TriggerActor::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Actor::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteBool(mEnable);
	target.WriteEnum(mAreaType);
	target.Write(mBox.Min[0]);
	target.Write(mBox.Min[1]);
	target.Write(mBox.Min[2]);
	target.Write(mBox.Max[0]);
	target.Write(mBox.Max[1]);
	target.Write(mBox.Max[2]);
	target.WriteAggregate<Vector3f>(mSphere.Center);
	target.Write(mSphere.Radius);

	PX2_END_DEBUG_STREAM_SAVE(TriggerActor, target);
}
//----------------------------------------------------------------------------
int TriggerActor::GetStreamingSize (Stream &stream) const
{
	int size = Actor::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_BOOLSIZE(mEnable);
	size += PX2_ENUMSIZE(mAreaType);
	size += sizeof(float)*6;
	size += sizeof(mSphere.Center);
	size += sizeof(float);

	return size;
}
//----------------------------------------------------------------------------