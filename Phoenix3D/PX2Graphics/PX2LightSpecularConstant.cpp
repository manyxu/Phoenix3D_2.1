/*
*
* 文件名称	：	PX2LightSpecularConstant.cpp
*
*/

#include "PX2LightSpecularConstant.hpp"
#include "PX2Camera.hpp"
#include "PX2Renderable.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, ShaderFloat, LightSpecularConstant);
PX2_IMPLEMENT_STREAM(LightSpecularConstant);
PX2_IMPLEMENT_FACTORY(LightSpecularConstant);

//----------------------------------------------------------------------------
LightSpecularConstant::LightSpecularConstant (Light* light)
:
ShaderFloat(1),
mLight(light)
{
	EnableUpdater();
}
//----------------------------------------------------------------------------
LightSpecularConstant::~LightSpecularConstant ()
{
}
//----------------------------------------------------------------------------
void LightSpecularConstant::SetLight (Light *light)
{
	mLight = light;
}
//----------------------------------------------------------------------------
Light* LightSpecularConstant::GetLight ()
{
	return mLight;
}
//----------------------------------------------------------------------------
void LightSpecularConstant::Update (const Renderable*, const Camera*)
{
	const float* source = (const float*)mLight->Specular;
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
Object* LightSpecularConstant::GetObjectByName (const std::string& name)
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
void LightSpecularConstant::GetAllObjectsByName (const std::string& name,
												 std::vector<Object*>& objects)
{
	ShaderFloat::GetAllObjectsByName(name, objects);

	PX2_GET_ALL_OBJECTS_BY_NAME(mLight, name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
LightSpecularConstant::LightSpecularConstant (LoadConstructor value)
:
ShaderFloat(value)
{
}
//----------------------------------------------------------------------------
void LightSpecularConstant::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	ShaderFloat::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadPointer(mLight);

	PX2_END_DEBUG_STREAM_LOAD(LightSpecularConstant, source);
}
//----------------------------------------------------------------------------
void LightSpecularConstant::Link (InStream& source)
{
	ShaderFloat::Link(source);

	source.ResolveLink(mLight);
}
//----------------------------------------------------------------------------
void LightSpecularConstant::PostLink ()
{
	ShaderFloat::PostLink();
}
//----------------------------------------------------------------------------
bool LightSpecularConstant::Register (OutStream& target) const
{
	if (ShaderFloat::Register(target))
	{
		target.Register(mLight);
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void LightSpecularConstant::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	ShaderFloat::Save(target);
	PX2_VERSION_SAVE(target);

	target.WritePointer(mLight);

	PX2_END_DEBUG_STREAM_SAVE(LightSpecularConstant, target);
}
//----------------------------------------------------------------------------
int LightSpecularConstant::GetStreamingSize (Stream &stream) const
{
	int size = ShaderFloat::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	size += PX2_POINTERSIZE(mLight);
	return size;
}
//----------------------------------------------------------------------------
