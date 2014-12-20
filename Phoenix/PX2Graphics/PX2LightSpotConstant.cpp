/*
*
* 文件名称	：	PX2LightSpotConstant.cpp
*
*/

#include "PX2LightSpotConstant.hpp"
#include "PX2Camera.hpp"
#include "PX2Renderable.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, ShaderFloat, LightSpotConstant);
PX2_IMPLEMENT_STREAM(LightSpotConstant);
PX2_IMPLEMENT_FACTORY(LightSpotConstant);

//----------------------------------------------------------------------------
LightSpotConstant::LightSpotConstant (Light* light)
:
ShaderFloat(1),
mLight(light)
{
	EnableUpdater();
}
//----------------------------------------------------------------------------
LightSpotConstant::~LightSpotConstant ()
{
}
//----------------------------------------------------------------------------
void LightSpotConstant::SetLight (Light *light)
{
	mLight = light;
}
//----------------------------------------------------------------------------
Light* LightSpotConstant::GetLight ()
{
	return mLight;
}
//----------------------------------------------------------------------------
void LightSpotConstant::Update (const Renderable*, const Camera*)
{
	mData[0] = mLight->Angle;
	mData[1] = mLight->CosAngle;
	mData[2] = mLight->SinAngle;
	mData[3] = mLight->Exponent;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称
//----------------------------------------------------------------------------
Object* LightSpotConstant::GetObjectByName (const std::string& name)
{
	Object* found = ShaderFloat::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	PX2_GET_OBJECT_BY_NAME(mLight, name, found);
	return 0;
}
//----------------------------------------------------------------------------
void LightSpotConstant::GetAllObjectsByName (const std::string& name,
											 std::vector<Object*>& objects)
{
	ShaderFloat::GetAllObjectsByName(name, objects);

	PX2_GET_ALL_OBJECTS_BY_NAME(mLight, name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化
//----------------------------------------------------------------------------
LightSpotConstant::LightSpotConstant (LoadConstructor value)
:
ShaderFloat(value)
{
}
//----------------------------------------------------------------------------
void LightSpotConstant::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	ShaderFloat::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadPointer(mLight);

	PX2_END_DEBUG_STREAM_LOAD(LightSpotConstant, source);
}
//----------------------------------------------------------------------------
void LightSpotConstant::Link (InStream& source)
{
	ShaderFloat::Link(source);

	source.ResolveLink(mLight);
}
//----------------------------------------------------------------------------
void LightSpotConstant::PostLink ()
{
	ShaderFloat::PostLink();
}
//----------------------------------------------------------------------------
bool LightSpotConstant::Register (OutStream& target) const
{
	if (ShaderFloat::Register(target))
	{
		target.Register(mLight);
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void LightSpotConstant::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	ShaderFloat::Save(target);
	PX2_VERSION_SAVE(target);

	target.WritePointer(mLight);

	PX2_END_DEBUG_STREAM_SAVE(LightSpotConstant, target);
}
//----------------------------------------------------------------------------
int LightSpotConstant::GetStreamingSize (Stream &stream) const
{
	int size = ShaderFloat::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	size += PX2_POINTERSIZE(mLight);
	return size;
}
//----------------------------------------------------------------------------
