// PX2UserConstant.cpp

#include "PX2FogColorConstant.hpp"
#include "PX2Camera.hpp"
#include "PX2Renderable.hpp"
#include "PX2GraphicsRoot.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, ShaderFloat, FogColorConstant);
PX2_IMPLEMENT_STREAM(FogColorConstant);
PX2_IMPLEMENT_FACTORY(FogColorConstant);
PX2_IMPLEMENT_DEFAULT_NAMES(ShaderFloat, FogColorConstant);

//----------------------------------------------------------------------------
FogColorConstant::FogColorConstant ()
	:
ShaderFloat(1)
{
	EnableUpdater();
}
//----------------------------------------------------------------------------
FogColorConstant::~FogColorConstant ()
{
}
//----------------------------------------------------------------------------
void FogColorConstant::Update(const ShaderStruct *struc)
{
	const float* source = (const float*)PX2_GR.GetFogColor();
	float* target = mData;
	for (int i = 0; i < 4; ++i)
	{
		*target++ = *source++;
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// ³Ö¾Ã»¯
//----------------------------------------------------------------------------
FogColorConstant::FogColorConstant (LoadConstructor value)
	:
ShaderFloat(value)
{
}
//----------------------------------------------------------------------------
void FogColorConstant::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	ShaderFloat::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(FogColorConstant, source);
}
//----------------------------------------------------------------------------
void FogColorConstant::Link (InStream& source)
{
	ShaderFloat::Link(source);
}
//----------------------------------------------------------------------------
void FogColorConstant::PostLink ()
{
	ShaderFloat::PostLink();
}
//----------------------------------------------------------------------------
bool FogColorConstant::Register (OutStream& target) const
{
	if (ShaderFloat::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void FogColorConstant::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	ShaderFloat::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(FogColorConstant, target);
}
//----------------------------------------------------------------------------
int FogColorConstant::GetStreamingSize (Stream &stream) const
{
	int size = ShaderFloat::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	return size;
}
//----------------------------------------------------------------------------
