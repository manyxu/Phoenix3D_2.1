/*
*
* 文件名称	：	PX2LightAttenuationConstant.cpp
*
*/

#include "PX2LightAttenuationConstant.hpp"
#include "PX2Camera.hpp"
#include "PX2Renderable.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, ShaderFloat, LightAttenuationConstant);
PX2_IMPLEMENT_STREAM(LightAttenuationConstant);
PX2_IMPLEMENT_FACTORY(LightAttenuationConstant);

//----------------------------------------------------------------------------
LightAttenuationConstant::LightAttenuationConstant (Light* light)
    :
    ShaderFloat(1),
    mLight(light)
{
    EnableUpdater();
}
//----------------------------------------------------------------------------
LightAttenuationConstant::~LightAttenuationConstant ()
{
}
//----------------------------------------------------------------------------
void LightAttenuationConstant::SetLight (Light *light)
{
	mLight = light;
}
//----------------------------------------------------------------------------
Light* LightAttenuationConstant::GetLight ()
{
    return mLight;
}
//----------------------------------------------------------------------------
void LightAttenuationConstant::Update (const Renderable*, const Camera*)
{
    mData[0] = mLight->Constant;
    mData[1] = mLight->Linear;
    mData[2] = mLight->Quadratic;
    mData[3] = mLight->Intensity;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称支持
//----------------------------------------------------------------------------
Object* LightAttenuationConstant::GetObjectByName (const std::string& name)
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
void LightAttenuationConstant::GetAllObjectsByName (const std::string& name,
    std::vector<Object*>& objects)
{
    ShaderFloat::GetAllObjectsByName(name, objects);

    PX2_GET_ALL_OBJECTS_BY_NAME(mLight, name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化
//----------------------------------------------------------------------------
LightAttenuationConstant::LightAttenuationConstant (LoadConstructor value)
    :
    ShaderFloat(value)
{
}
//----------------------------------------------------------------------------
void LightAttenuationConstant::Load (InStream& source)
{
    PX2_BEGIN_DEBUG_STREAM_LOAD(source);

    ShaderFloat::Load(source);
	PX2_VERSION_LOAD(source);

    source.ReadPointer(mLight);

    PX2_END_DEBUG_STREAM_LOAD(LightAttenuationConstant, source);
}
//----------------------------------------------------------------------------
void LightAttenuationConstant::Link (InStream& source)
{
    ShaderFloat::Link(source);

    source.ResolveLink(mLight);
}
//----------------------------------------------------------------------------
void LightAttenuationConstant::PostLink ()
{
    ShaderFloat::PostLink();
}
//----------------------------------------------------------------------------
bool LightAttenuationConstant::Register (OutStream& target) const
{
    if (ShaderFloat::Register(target))
    {
        target.Register(mLight);
        return true;
    }
    return false;
}
//----------------------------------------------------------------------------
void LightAttenuationConstant::Save (OutStream& target) const
{
    PX2_BEGIN_DEBUG_STREAM_SAVE(target);

    ShaderFloat::Save(target);
	PX2_VERSION_SAVE(target);

    target.WritePointer(mLight);

    PX2_END_DEBUG_STREAM_SAVE(LightAttenuationConstant, target);
}
//----------------------------------------------------------------------------
int LightAttenuationConstant::GetStreamingSize (Stream &stream) const
{
    int size = ShaderFloat::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
    size += PX2_POINTERSIZE(mLight);
    return size;
}
//----------------------------------------------------------------------------