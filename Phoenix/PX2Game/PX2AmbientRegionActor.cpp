/*
*
* 文件名称	：	PX2AmbientRegionActor.cpp
*
*/

#include "PX2AmbientRegionActor.hpp"
#include "PX2GraphicsRoot.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI_V(PX2, TriggerActor, AmbientRegionActor, 7);
PX2_IMPLEMENT_STREAM(AmbientRegionActor);
PX2_IMPLEMENT_FACTORY(AmbientRegionActor);

//----------------------------------------------------------------------------
AmbientRegionActor::AmbientRegionActor ()
{
	mIsEnableGI = false;

	mHorAngle = 30.0f;
	mVerAngle = 15.0f;
	mLightIntensity = 1.0f;

	mAmbientColor_Bake = Float3(0.4f, 0.4f, 0.4f);
	mDiffColor_Bake = Float3(1.0f, 1.0f, 1.0f);
	mSpecColor_Bake = Float3(0.5f, 0.5f, 0.5f);

	mLight = new0 Light(Light::LT_DIRECTIONAL);
	mLight->SetDirection(AVector(-1.0f, -1.0f, -1.0f));
	mLight->Ambient = Float4(0.2f, 0.2f, 0.2f, 1.0f);
	mLight->Diffuse = Float4(1.0f, 1.0f, 1.0f, 1.0f);
	mLight->Specular = Float4(0.5f, 0.5f, 0.5f, 1.0f);

	mFogParam = Float2(60.0f, 240.0f);
	mFogColor = Float3::WHITE;

	mBakeShadowAngle = 0.0f; 

	mBakeSkyLightColor = Float3::WHITE;

	mAmbientScale_Bake = 1.0f;
	mDiffuseScale_Bake = 1.0f;
	mSpecularScale_Bake = 1.0f;

	mFogParam1 = Float2(-30.0f, 0.0f);

	mAmbientColor = Float3(0.4f, 0.4f, 0.4f);
	mDirLightDiffColor = Float3(1.0f, 1.0f, 1.0f);
	mLightSpecColor = Float3(0.5f, 0.5f, 0.5f);
	mLightSpecPow = 10.0f;

	ShowHelpMovable(false);
}
//----------------------------------------------------------------------------
AmbientRegionActor::~AmbientRegionActor ()
{
}
//----------------------------------------------------------------------------
void AmbientRegionActor::Update(double appSeconds, double elapsedSeconds)
{
	TriggerActor::Update(appSeconds, elapsedSeconds);

	PX2_GR.SetFogParam(Float4(mFogParam[0],mFogParam[1], mFogParam1[0], mFogParam1[1]));
	PX2_GR.SetFogColor(Float4(mFogColor[0], mFogColor[1], mFogColor[2], 1.0f));
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetAmbientColor_Bake (const Float3 &color)
{
	mAmbientColor_Bake = color;
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetDiffColor_Bake (const Float3 &color)
{
	mDiffColor_Bake = color;
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetSpecColor_Bake (const Float3 &color)
{
	mSpecColor_Bake = color;
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetSpecularScale_Bake (float scale)
{
	mSpecularScale_Bake = scale;
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetAmbientColor (const Float3 &color)
{
	mAmbientColor = color;

	if (mLight)
	{
		mLight->Ambient = Float4(color[0], color[1], color[2], 1.0f);
	}
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetLightDiffColor (const Float3 &color)
{
	mDirLightDiffColor = color;

	if (mLight)
	{
		mLight->Diffuse = Float4(color[0], color[1], color[2], 1.0f);
	}
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetLightSpecColor (const Float3 &color)
{
	mLightSpecColor = color;

	if (mLight)
	{
		mLight->Specular = Float4(color[0], color[1], color[2], mLightSpecPow);
	}
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetLightSpecPow (float pow)
{
	mLightSpecPow = pow;

	if (mLight)
	{
		mLight->Specular = Float4(mLightSpecColor[0], mLightSpecColor[1], mLightSpecColor[2], mLightSpecPow);
	}
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetLightIntensity (float intensity)
{
	mLightIntensity = intensity;

	if (mLight)
	{
		mLight->Intensity = intensity;
	}
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetHorAngle (float angle)
{
	mHorAngle = angle;

	if (mLight)
	{
		AVector dir = AVector::AnglesToDirection(Mathf::DEG_TO_RAD*mHorAngle, 
			Mathf::DEG_TO_RAD*mVerAngle);

		mLight->SetDirection(dir);
	}
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetVerAngle (float angle)
{
	mVerAngle = angle;

	if (mLight)
	{
		AVector dir = AVector::AnglesToDirection(Mathf::DEG_TO_RAD*mHorAngle, 
			Mathf::DEG_TO_RAD*mVerAngle);
		mLight->SetDirection(dir);
	}
}
//----------------------------------------------------------------------------
void AmbientRegionActor::CalLights ()
{
	if (mLight)
	{
		GraphicsRoot::GetSingleton().RemoveLight(mLight);
	}
}
//----------------------------------------------------------------------------
void AmbientRegionActor::DoEnter ()
{
}
//----------------------------------------------------------------------------
void AmbientRegionActor::DoExecute (Event *event)
{
	PX2_UNUSED(event);
}
//----------------------------------------------------------------------------
void AmbientRegionActor::DoLeave ()
{
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetScene (Scene *scene)
{
	if (scene)
	{
		if (mLight)
		{
			GraphicsRoot::GetSingleton().AddLight(mLight);
		}
	}
	else
	{
		if (mLight)
		{
			GraphicsRoot::GetSingleton().RemoveLight(mLight);
		}
	}

	TriggerActor::SetScene(scene);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void AmbientRegionActor::RegistProperties ()
{
	TriggerActor::RegistProperties();

	AddPropertyClass("AmbientRegionActor");

	AddProperty("Bake_IsEnableGI", Object::PT_BOOL, mIsEnableGI);
	AddProperty("Bake_GISkyLightColor", Object::PT_COLOR3FLOAT3, mBakeSkyLightColor);

	AddProperty("Bake_AmbientColor", Object::PT_COLOR3FLOAT3, mAmbientColor_Bake);
	AddProperty("Bake_AmbientColorScale", Object::PT_FLOAT, mAmbientScale_Bake);

	AddProperty("Bake_DiffColor", Object::PT_COLOR3FLOAT3, mDiffColor_Bake);
	AddProperty("Bake_DiffColorScale", Object::PT_FLOAT, mDiffuseScale_Bake);

	AddProperty("Bake_SpecColor", Object::PT_COLOR3FLOAT3, mSpecColor_Bake);
	AddProperty("Bake_SpecColorScale", Object::PT_FLOAT, mSpecularScale_Bake);
	
	AddProperty("Bake_ShadowAngle", Object::PT_FLOAT, mBakeShadowAngle);

	AddProperty("Light_AmbientColor", Object::PT_COLOR3FLOAT3, mAmbientColor);
	AddProperty("Light_DiffColor", Object::PT_COLOR3FLOAT3, mDirLightDiffColor);
	AddProperty("Light_SpecColor", Object::PT_COLOR3FLOAT3, mLightSpecColor);
	AddProperty("Light_SpecPow", Object::PT_FLOAT, mLightSpecPow);

	AddProperty("Light_HorAngle", Object::PT_FLOAT, mHorAngle);
	AddProperty("Light_VerAngle", Object::PT_FLOAT, mVerAngle);
	
	AddProperty("FogParam", Object::PT_FLOAT2, mFogParam);
	AddProperty("FogParam1", Object::PT_FLOAT2, mFogParam1);
	AddProperty("FogColor", Object::PT_COLOR3FLOAT3, mFogColor);
}
//----------------------------------------------------------------------------
void AmbientRegionActor::OnPropertyChanged (const PropertyObject &obj) 
{ 
	TriggerActor::OnPropertyChanged(obj);

	if ("Bake_IsEnableGI" == obj.Name)
	{
		EnableBakeGI(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("Bake_GISkyLightColor" == obj.Name)
	{
		SetGISkyLightColor(PX2_ANY_AS(obj.Data, Float3));
	}
	if ("Bake_AmbientColor" == obj.Name)
	{
		SetAmbientColor_Bake(PX2_ANY_AS(obj.Data, Float3));
	}
	else if ("Bake_AmbientColorScale" == obj.Name)
	{
		SetAmbientScale_Bake(PX2_ANY_AS(obj.Data, float));
	}
	else if ("Bake_DiffColor" == obj.Name)
	{
		SetDiffColor_Bake(PX2_ANY_AS(obj.Data, Float3));
	}
	else if ("Bake_DiffColorScale" == obj.Name)
	{
		SetDiffuseScale_Bake(PX2_ANY_AS(obj.Data, float));
	}
	else if ("Bake_SpecColor" == obj.Name)
	{
		SetDiffColor_Bake(PX2_ANY_AS(obj.Data, Float3));
	}
	else if ("Bake_SpecColorScale" == obj.Name)
	{
		SetSpecularScale_Bake(PX2_ANY_AS(obj.Data, float));
	}

	else if ("Bake_ShadowAngle" == obj.Name)
	{
		SetBakeShadowAngle(PX2_ANY_AS(obj.Data, float));
	}

	else if ("Light_HorAngle" == obj.Name)
	{
		SetHorAngle(PX2_ANY_AS(obj.Data, float));
	}
	else if ("Light_VerAngle" == obj.Name)
	{
		SetVerAngle(PX2_ANY_AS(obj.Data, float));
	}

	else if ("Light_AmbientColor" == obj.Name)
	{
		mAmbientColor = PX2_ANY_AS(obj.Data, Float3);
		SetAmbientColor(mAmbientColor);
	}
	else if ("Light_DiffColor" == obj.Name)
	{
		mDirLightDiffColor = PX2_ANY_AS(obj.Data, Float3);
		SetLightDiffColor(mDirLightDiffColor);
	}
	else if ("Light_SpecColor" == obj.Name)
	{
		mLightSpecColor = PX2_ANY_AS(obj.Data, Float3);
		SetLightSpecColor(mLightSpecColor);
	}
	else if ("Light_SpecPow" == obj.Name)
	{
		mLightSpecPow = PX2_ANY_AS(obj.Data, float);
		SetLightSpecPow(mLightSpecPow);
	}
	else if ("FogParam" == obj.Name)
	{
		mFogParam = PX2_ANY_AS(obj.Data, Float2);
		Float4 lastParam = Float4(mFogParam[0],mFogParam[1], mFogParam1[0], mFogParam1[1]);
		PX2_GR.SetFogParam(lastParam);
	}
	else if ("FogColor" == obj.Name)
	{
		mFogColor = PX2_ANY_AS(obj.Data, Float3);
		Float4 lastColor = Float4(mFogColor[0], mFogColor[1], mFogColor[2], 1.0f);
		PX2_GR.SetFogColor(lastColor);
	}
	else if ("FogParam1" == obj.Name)
	{
		mFogParam1 = PX2_ANY_AS(obj.Data, Float2);
		Float4 lastParam = Float4(mFogParam[0],mFogParam[1], mFogParam1[0], mFogParam1[1]);
		PX2_GR.SetFogParam(lastParam);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称支持
//----------------------------------------------------------------------------
Object* AmbientRegionActor::GetObjectByName (const std::string& name)
{
	Object* found = TriggerActor::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	return 0;
}
//----------------------------------------------------------------------------
void AmbientRegionActor::GetAllObjectsByName (const std::string& name,
	std::vector<Object*>& objects)
{
	TriggerActor::GetAllObjectsByName(name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
AmbientRegionActor::AmbientRegionActor (LoadConstructor value)
	:
TriggerActor(value)
{
	mIsEnableGI = false;

	mHorAngle = 30.0f;
	mVerAngle = 15.0f;
	mLightIntensity = 1.0f;

	mAmbientColor_Bake = Float3(0.4f, 0.4f, 0.4f);
	mDiffColor_Bake = Float3(1.0f, 1.0f, 1.0f);
	mSpecColor_Bake = Float3(0.5f, 0.5f, 0.5f);

	mBakeShadowAngle = 0.0f; 

	mFogParam = Float2(60.0f, 240.0f);
	mFogColor = Float3::WHITE;

	mBakeSkyLightColor = Float3::WHITE;

	mAmbientScale_Bake = 1.0f;
	mDiffuseScale_Bake = 1.0f;
	mSpecularScale_Bake = 1.0f;

	mFogParam1 = Float2(-30.0f, 0.0f);

	mAmbientColor = Float3(0.4f, 0.4f, 0.4f);
	mDirLightDiffColor = Float3(1.0f, 1.0f, 1.0f);
	mLightSpecColor = Float3(0.5f, 0.5f, 0.5f);
	mLightSpecPow = 10.0f;
}
//----------------------------------------------------------------------------
void AmbientRegionActor::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	TriggerActor::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadAggregate<Float3>(mAmbientColor_Bake);
	source.ReadAggregate<Float3>(mDiffColor_Bake);
	source.ReadAggregate<Float3>(mSpecColor_Bake);
	source.Read(mLightIntensity);
	source.Read(mHorAngle);
	source.Read(mVerAngle);
	source.ReadPointer(mLight);

	int readedVersion = GetReadedVersion();
	if (1 <= readedVersion)
	{
		source.Read(mBakeShadowAngle);
	}
	if (2 <= readedVersion)
	{
		source.ReadAggregate(mFogParam);
		source.ReadAggregate(mFogColor);
	}
	if (3 <= readedVersion)
	{
		source.ReadAggregate(mBakeSkyLightColor);
	}
	if (4 <= readedVersion)
	{
		source.Read(mAmbientScale_Bake);
		source.Read(mDiffuseScale_Bake);
		source.Read(mSpecularScale_Bake);
	}
	if (5 <= readedVersion)
	{
		source.Read(mFogParam1);
	}
	if (6 <= readedVersion)
	{
		source.ReadBool(mIsEnableGI);
	}
	if (7 <= readedVersion)
	{
		source.ReadAggregate(mAmbientColor);
		source.ReadAggregate(mDirLightDiffColor);
		source.ReadAggregate(mLightSpecColor);
		source.Read(mLightSpecPow);
	}

	PX2_END_DEBUG_STREAM_LOAD(AmbientRegionActor, source);
}
//----------------------------------------------------------------------------
void AmbientRegionActor::Link (InStream& source)
{
	TriggerActor::Link(source);

	if (mLight)
		source.ResolveLink(mLight);
}
//----------------------------------------------------------------------------
void AmbientRegionActor::PostLink ()
{
	TriggerActor::PostLink();

	PX2_GR.SetFogParam(Float4(mFogParam[0],mFogParam[1], mFogParam1[0], mFogParam1[1]));
	PX2_GR.SetFogColor(Float4(mFogColor[0], mFogColor[1], mFogColor[2], 1.0f));
}
//----------------------------------------------------------------------------
bool AmbientRegionActor::Register (OutStream& target) const
{
	if (TriggerActor::Register(target))
	{
		if (mLight)
			target.Register(mLight);

		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void AmbientRegionActor::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	TriggerActor::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteAggregate<Float3>(mAmbientColor_Bake);
	target.WriteAggregate<Float3>(mDiffColor_Bake);
	target.WriteAggregate<Float3>(mSpecColor_Bake);
	target.Write(mLightIntensity);
	target.Write(mHorAngle);
	target.Write(mVerAngle);
	target.WritePointer(mLight);
	
	target.Write(mBakeShadowAngle);

	target.WriteAggregate(mFogParam);
	target.WriteAggregate(mFogColor);

	target.WriteAggregate(mBakeSkyLightColor);

	target.Write(mAmbientScale_Bake);
	target.Write(mDiffuseScale_Bake);
	target.Write(mSpecularScale_Bake);

	target.WriteAggregate(mFogParam1);

	target.WriteBool(mIsEnableGI);

	target.WriteAggregate(mAmbientColor);
	target.WriteAggregate(mDirLightDiffColor);
	target.WriteAggregate(mLightSpecColor);
	target.Write(mLightSpecPow);

	PX2_END_DEBUG_STREAM_SAVE(AmbientRegionActor, target);
}
//----------------------------------------------------------------------------
int AmbientRegionActor::GetStreamingSize (Stream &stream) const
{
	int size = TriggerActor::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	size += sizeof(mAmbientColor_Bake);
	size += sizeof(mDiffColor_Bake);
	size += sizeof(mSpecColor_Bake);
	size += sizeof(mLightIntensity);
	size += sizeof(mHorAngle);
	size += sizeof(mVerAngle);
	size += PX2_POINTERSIZE(mLight);

	if (stream.IsIn())
	{
		int readedVersion = GetReadedVersion();
		if (1 <= readedVersion)
		{
			size += sizeof(mBakeShadowAngle);
		}
		if (2 <= readedVersion)
		{
			size += sizeof(mFogParam);
			size += sizeof(mFogColor);
		}
		if (3 <= readedVersion)
		{
			size += sizeof(mBakeSkyLightColor);
		}
		if (4 <= readedVersion)
		{
			size += sizeof(mAmbientScale_Bake);
			size += sizeof(mDiffuseScale_Bake);
			size += sizeof(mSpecularScale_Bake);
		}
		if (5 <= readedVersion)
		{
			size += sizeof(mFogParam1);
		}
		if (6 <= readedVersion)
		{
			size += PX2_BOOLSIZE(mIsEnableGI);
		}
		if (7 <= readedVersion)
		{
			size += sizeof(mAmbientColor);
			size += sizeof(mDirLightDiffColor);
			size += sizeof(mLightSpecColor);
			size += sizeof(mLightSpecPow);
		}
	}
	else
	{
		size += sizeof(mBakeShadowAngle);

		size += sizeof(mFogParam);
		size += sizeof(mFogColor);

		size += sizeof(mBakeSkyLightColor);

		size += sizeof(mAmbientScale_Bake);
		size += sizeof(mDiffuseScale_Bake);
		size += sizeof(mSpecularScale_Bake);

		size += sizeof(mFogParam1);

		size += PX2_BOOLSIZE(mIsEnableGI);

		size += sizeof(mAmbientColor);
		size += sizeof(mDirLightDiffColor);
		size += sizeof(mLightSpecColor);
		size += sizeof(mLightSpecPow);
	}

	return size;
}
//----------------------------------------------------------------------------