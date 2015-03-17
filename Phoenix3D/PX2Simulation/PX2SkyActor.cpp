// PX2SkyActor.cpp

#include "PX2SkyActor.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Actor, SkyActor);
PX2_IMPLEMENT_STREAM(SkyActor);
PX2_IMPLEMENT_FACTORY(SkyActor);
PX2_IMPLEMENT_DEFAULT_NAMES(Actor, SkyActor);

//----------------------------------------------------------------------------
SkyActor::SkyActor() 
{
	SetName("SkyActor");

	mSkyMesh = new0 SkyMesh();
	SetMovable(mSkyMesh);

	SetPickable(false);
}
//----------------------------------------------------------------------------
SkyActor::~SkyActor()
{
}
//----------------------------------------------------------------------------
void SkyActor::RegistProperties()
{
	Actor::RegistProperties();

	AddPropertyClass("SkyActor");

	AddProperty("DayTexture", PT_STRINGBUTTON, mSkyMesh->GetDayTexture());
	AddProperty("SunsetTexture", PT_STRINGBUTTON, mSkyMesh->GetSunsetTexture());
	AddProperty("NightTexture", PT_STRINGBUTTON, mSkyMesh->GetNightTexture());
	AddProperty("SkyHazeTopAltitude", PT_FLOAT, mSkyMesh->GetSkyParam()[0]);
	AddProperty("DayToSunsetSharpness", PT_FLOAT, mSkyMesh->GetSkyParam()[1]);

	AddProperty("SunMoonRadiusAttenuationIn", PT_FLOAT, mSkyMesh->GetSunMoonParam()[0]);
	AddProperty("SunMoonLightnessIn", PT_FLOAT, mSkyMesh->GetSunMoonParam()[1]);
	AddProperty("SunMoonRadiusAttenuationOut", PT_FLOAT, mSkyMesh->GetSunMoonParam()[2]);
	AddProperty("SunMoonLightnessOut", PT_FLOAT, mSkyMesh->GetSunMoonParam()[3]);
}
//----------------------------------------------------------------------------
void SkyActor::OnPropertyChanged(const PropertyObject &obj)
{
	Actor::OnPropertyChanged(obj);

	if ("DayTexture" == obj.Name)
	{
		mSkyMesh->SetDayTexture(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("SunsetTexture" == obj.Name)
	{
		mSkyMesh->SetSunsetTexture(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("NightTexture" == obj.Name)
	{
		mSkyMesh->SetNightTexture(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("SkyHazeTopAltitude" == obj.Name)
	{
		Float4 skyParam = mSkyMesh->GetSkyParam();
		skyParam[0] = PX2_ANY_AS(obj.Data, float);
		mSkyMesh->SetSkyParam(skyParam);
	}
	else if ("DayToSunsetSharpness" == obj.Name)
	{
		Float4 skyParam = mSkyMesh->GetSkyParam();
		skyParam[1] = PX2_ANY_AS(obj.Data, float);
		mSkyMesh->SetSkyParam(skyParam);
	}
	else if ("SunMoonRadiusAttenuationIn" == obj.Name)
	{
		Float4 sunParam = mSkyMesh->GetSunMoonParam();
		sunParam[0] = PX2_ANY_AS(obj.Data, float);
		mSkyMesh->SetSunMoonParam(sunParam);
	}
	else if ("SunMoonLightnessIn" == obj.Name)
	{
		Float4 sunParam = mSkyMesh->GetSunMoonParam();
		sunParam[1] = PX2_ANY_AS(obj.Data, float);
		mSkyMesh->SetSunMoonParam(sunParam);
	}
	else if ("SunMoonRadiusAttenuationOut" == obj.Name)
	{
		Float4 sunParam = mSkyMesh->GetSunMoonParam();
		sunParam[2] = PX2_ANY_AS(obj.Data, float);
		mSkyMesh->SetSunMoonParam(sunParam);
	}
	else if ("SunMoonLightnessOut" == obj.Name)
	{
		Float4 sunParam = mSkyMesh->GetSunMoonParam();
		sunParam[3] = PX2_ANY_AS(obj.Data, float);
		mSkyMesh->SetSunMoonParam(sunParam);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
SkyActor::SkyActor(LoadConstructor value) :
Actor(value)
{
}
//----------------------------------------------------------------------------
void SkyActor::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Actor::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadPointer(mSkyMesh);

	PX2_END_DEBUG_STREAM_LOAD(SkyActor, source);
}
//----------------------------------------------------------------------------
void SkyActor::Link(InStream& source)
{
	Actor::Link(source);

	source.ResolveLink(mSkyMesh);
}
//----------------------------------------------------------------------------
void SkyActor::PostLink()
{
	Actor::PostLink();
}
//----------------------------------------------------------------------------
bool SkyActor::Register(OutStream& target) const
{
	if (Actor::Register(target))
	{
		target.Register(mSkyMesh);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void SkyActor::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Actor::Save(target);
	PX2_VERSION_SAVE(target);

	target.WritePointer(mSkyMesh);

	PX2_END_DEBUG_STREAM_SAVE(SkyActor, target);
}
//----------------------------------------------------------------------------
int SkyActor::GetStreamingSize(Stream &stream) const
{
	int size = Actor::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_POINTERSIZE(mSkyMesh);

	return size;
}
//----------------------------------------------------------------------------