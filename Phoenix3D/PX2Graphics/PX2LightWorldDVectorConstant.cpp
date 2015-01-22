/*
*
* 文件名称	：	PX2LightWorldDVectorConstant.cpp
*
*/

#include "PX2LightWorldDVectorConstant.hpp"
#include "PX2Camera.hpp"
#include "PX2Renderable.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, ShaderFloat, LightWorldDVectorConstant);
PX2_IMPLEMENT_STREAM(LightWorldDVectorConstant);
PX2_IMPLEMENT_FACTORY(LightWorldDVectorConstant);

//----------------------------------------------------------------------------
LightWorldDVectorConstant::LightWorldDVectorConstant (Light* light)
:
ShaderFloat(1),
mLight(light)
{
	EnableUpdater();
}
//----------------------------------------------------------------------------
LightWorldDVectorConstant::~LightWorldDVectorConstant ()
{
}
//----------------------------------------------------------------------------
void LightWorldDVectorConstant::SetLight (Light *light)
{
	mLight = light;
}
//----------------------------------------------------------------------------
Light* LightWorldDVectorConstant::GetLight ()
{
	return mLight;
}
//----------------------------------------------------------------------------
void LightWorldDVectorConstant::Update (const Renderable*, const Camera*)
{
	const AVector& worldDVector = mLight->DVector;

	const float* source = (const float*)worldDVector;
	float* target = mData;
	for (int i = 0; i < 4; ++i)
	{
		*target++ = *source++;
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称
//----------------------------------------------------------------------------
Object* LightWorldDVectorConstant::GetObjectByName (const std::string& name)
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
void LightWorldDVectorConstant::GetAllObjectsByName (const std::string& name,
													 std::vector<Object*>& objects)
{
	ShaderFloat::GetAllObjectsByName(name, objects);

	PX2_GET_ALL_OBJECTS_BY_NAME(mLight, name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化
//----------------------------------------------------------------------------
LightWorldDVectorConstant::LightWorldDVectorConstant (LoadConstructor value)
:
ShaderFloat(value)
{
}
//----------------------------------------------------------------------------
void LightWorldDVectorConstant::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	ShaderFloat::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadPointer(mLight);

	PX2_END_DEBUG_STREAM_LOAD(LightWorldDVectorConstant, source);
}
//----------------------------------------------------------------------------
void LightWorldDVectorConstant::Link (InStream& source)
{
	ShaderFloat::Link(source);

	source.ResolveLink(mLight);
}
//----------------------------------------------------------------------------
void LightWorldDVectorConstant::PostLink ()
{
	ShaderFloat::PostLink();
}
//----------------------------------------------------------------------------
bool LightWorldDVectorConstant::Register (OutStream& target) const
{
	if (ShaderFloat::Register(target))
	{
		target.Register(mLight);
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void LightWorldDVectorConstant::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	ShaderFloat::Save(target);
	PX2_VERSION_SAVE(target);

	target.WritePointer(mLight);

	PX2_END_DEBUG_STREAM_SAVE(LightWorldDVectorConstant, target);
}
//----------------------------------------------------------------------------
int LightWorldDVectorConstant::GetStreamingSize (Stream &stream) const
{
	int size = ShaderFloat::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	size += PX2_POINTERSIZE(mLight);
	return size;
}
//----------------------------------------------------------------------------
