/*
*
* 文件名称	：	PX2LightModelDVectorConstant.cpp
*
*/

#include "PX2LightModelDVectorConstant.hpp"
#include "PX2Camera.hpp"
#include "PX2Renderable.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, ShaderFloat, LightModelDVectorConstant);
PX2_IMPLEMENT_STREAM(LightModelDVectorConstant);
PX2_IMPLEMENT_FACTORY(LightModelDVectorConstant);

//----------------------------------------------------------------------------
LightModelDVectorConstant::LightModelDVectorConstant (Light* light)
:
ShaderFloat(1),
mLight(light)
{
	EnableUpdater();
}
//----------------------------------------------------------------------------
LightModelDVectorConstant::~LightModelDVectorConstant ()
{
}
//----------------------------------------------------------------------------
void LightModelDVectorConstant::SetLight (Light *light)
{
	mLight = light;
}
//----------------------------------------------------------------------------
Light* LightModelDVectorConstant::GetLight ()
{
	return mLight;
}
//----------------------------------------------------------------------------
void LightModelDVectorConstant::Update (const Renderable* renderable, 
										const Camera*)
{
	const HMatrix& worldInvMatrix = renderable->WorldTransform.Inverse();
	AVector modelDVector = worldInvMatrix*mLight->DVector;
	modelDVector.Normalize();

	const float* source = (const float*)modelDVector;
	float* target = mData;
	for (int i = 0; i < 4; ++i)
	{
		*target++ = *source++;
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称支持
//----------------------------------------------------------------------------
Object* LightModelDVectorConstant::GetObjectByName (const std::string& name)
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
void LightModelDVectorConstant::GetAllObjectsByName (const std::string& name,
													 std::vector<Object*>& objects)
{
	ShaderFloat::GetAllObjectsByName(name, objects);

	PX2_GET_ALL_OBJECTS_BY_NAME(mLight, name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
LightModelDVectorConstant::LightModelDVectorConstant (LoadConstructor value)
:
ShaderFloat(value)
{
}
//----------------------------------------------------------------------------
void LightModelDVectorConstant::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	ShaderFloat::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadPointer(mLight);

	PX2_END_DEBUG_STREAM_LOAD(LightModelDVectorConstant, source);
}
//----------------------------------------------------------------------------
void LightModelDVectorConstant::Link (InStream& source)
{
	ShaderFloat::Link(source);

	source.ResolveLink(mLight);
}
//----------------------------------------------------------------------------
void LightModelDVectorConstant::PostLink ()
{
	ShaderFloat::PostLink();
}
//----------------------------------------------------------------------------
bool LightModelDVectorConstant::Register (OutStream& target) const
{
	if (ShaderFloat::Register(target))
	{
		target.Register(mLight);
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void LightModelDVectorConstant::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	ShaderFloat::Save(target);
	PX2_VERSION_SAVE(target);

	target.WritePointer(mLight);

	PX2_END_DEBUG_STREAM_SAVE(LightModelDVectorConstant, target);
}
//----------------------------------------------------------------------------
int LightModelDVectorConstant::GetStreamingSize (Stream &stream) const
{
	int size = ShaderFloat::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	size += PX2_POINTERSIZE(mLight);
	return size;
}
//----------------------------------------------------------------------------
