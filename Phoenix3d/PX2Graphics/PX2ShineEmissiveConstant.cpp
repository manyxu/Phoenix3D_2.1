/*
*
* 文件名称	：	PX2ShineEmissiveConstant.cpp
*
*/

#include "PX2ShineEmissiveConstant.hpp"
#include "PX2Camera.hpp"
#include "PX2Renderable.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, ShaderFloat, ShineEmissiveConstant);
PX2_IMPLEMENT_STREAM(ShineEmissiveConstant);
PX2_IMPLEMENT_FACTORY(ShineEmissiveConstant);

//----------------------------------------------------------------------------
ShineEmissiveConstant::ShineEmissiveConstant (Shine* shine)
:
ShaderFloat(1),
mShine(shine)
{
	EnableUpdater();
}
//----------------------------------------------------------------------------
ShineEmissiveConstant::~ShineEmissiveConstant ()
{
}
//----------------------------------------------------------------------------
Shine* ShineEmissiveConstant::GetShine ()
{
	return mShine;
}
//----------------------------------------------------------------------------
void ShineEmissiveConstant::Update (const Renderable*, const Camera*)
{
	const float* source = (const float*)mShine->Emissive;
	float* target = mData;
	for (int i = 0; i < 4; ++i)
	{
		*target++ = *source++;
	}
}
//----------------------------------------------------------------------------
void ShineEmissiveConstant::Float_OnRegistProperties (Object *parObj)
{
	parObj->AddProperty("Shine_Ambinet_Emissive", Object::PT_COLOR3FLOAT3,
		Float3(mShine->Emissive[0], mShine->Emissive[1], mShine->Emissive[2]),
		false);
}
//----------------------------------------------------------------------------
void ShineEmissiveConstant::Float_OnPropertyChanged (Object *parObj, 
	const PropertyObject &obj)
{
	PX2_UNUSED(parObj);
	PX2_UNUSED(obj);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称
//----------------------------------------------------------------------------
Object* ShineEmissiveConstant::GetObjectByName (const std::string& name)
{
	Object* found = ShaderFloat::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	PX2_GET_OBJECT_BY_NAME(mShine, name, found);
	return 0;
}
//----------------------------------------------------------------------------
void ShineEmissiveConstant::GetAllObjectsByName (const std::string& name,
													std::vector<Object*>& objects)
{
	ShaderFloat::GetAllObjectsByName(name, objects);

	PX2_GET_ALL_OBJECTS_BY_NAME(mShine, name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化
//----------------------------------------------------------------------------
ShineEmissiveConstant::ShineEmissiveConstant (LoadConstructor value)
:
ShaderFloat(value)
{
}
//----------------------------------------------------------------------------
void ShineEmissiveConstant::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	ShaderFloat::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadPointer(mShine);

	PX2_END_DEBUG_STREAM_LOAD(ShineEmissiveConstant, source);
}
//----------------------------------------------------------------------------
void ShineEmissiveConstant::Link (InStream& source)
{
	ShaderFloat::Link(source);

	source.ResolveLink(mShine);
}
//----------------------------------------------------------------------------
void ShineEmissiveConstant::PostLink ()
{
	ShaderFloat::PostLink();
}
//----------------------------------------------------------------------------
bool ShineEmissiveConstant::Register (OutStream& target) const
{
	if (ShaderFloat::Register(target))
	{
		target.Register(mShine);
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void ShineEmissiveConstant::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	ShaderFloat::Save(target);
	PX2_VERSION_SAVE(target);

	target.WritePointer(mShine);

	PX2_END_DEBUG_STREAM_SAVE(ShineEmissiveConstant, target);
}
//----------------------------------------------------------------------------
int ShineEmissiveConstant::GetStreamingSize (Stream &stream) const
{
	int size = ShaderFloat::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	size += PX2_POINTERSIZE(mShine);
	return size;
}
//----------------------------------------------------------------------------