// PX2AmbientActor.cpp

#include "PX2AmbientRegionActor.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2AVector.hpp"
#include "PX2RenderStepScene.hpp"
#include "PX2Project.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, TriggerActor, AmbientRegionActor);
PX2_IMPLEMENT_STREAM(AmbientRegionActor);
PX2_IMPLEMENT_FACTORY(AmbientRegionActor);

//----------------------------------------------------------------------------
AmbientRegionActor::AmbientRegionActor() :
mHorAngle(45.0f),
mVerAngle(45.0f),
mLightCameraExtent(10.0f),
mSpecularPow(10.0f),
mIntensity(1.0f),
mLightCameraLookDistance(50.0f)
{
	SetName("AmbientRegionActor");

	mAmbientColor = Float3(0.4f, 0.4f, 0.4f);
	mDiffuseColor = Float3(1.0f, 1.0f, 1.0f);
	mSpecularColor = Float3(1.0f, 1.0f, 1.0f);

	mFogColorHeight = Float3::WHITE;
	mFogParamHeight = Float2(-10.0f, 0.0f);

	mFogColorDist = Float3::WHITE;
	mFogParamDist = Float2(80.0f, 120.0f);

	CreateGetHelpNode()->Show(false);
}
//----------------------------------------------------------------------------
AmbientRegionActor::~AmbientRegionActor()
{
}
//----------------------------------------------------------------------------
void AmbientRegionActor::UpdateWorldData(double applicationTime, 
	double elapsedTime)
{
	TriggerActor::UpdateWorldData(applicationTime, elapsedTime);

	SetFogColorHeight(mFogColorHeight);
	SetFogParamHeight(mFogParamHeight);
	SetFogColorDistance(mFogColorDist);
	SetFogParamDistance(mFogParamDist);
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetLightCameraLookPostion(const APoint &pos)
{
	mLightCameraLookPosition = pos;

	_UpdateDirLightCamera();
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetLightCameraLookDistance(float dist)
{
	mLightCameraLookDistance = dist;

	_UpdateDirLightCamera();
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetLightCameraExtent(float extent)
{
	mLightCameraExtent = extent;

	_UpdateDirLightCamera();
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetParent(Movable* parent)
{
	TriggerActor::SetParent(parent);

	_UpdateDirLightCamera();
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetHorAngle(float angle)
{
	mHorAngle = angle;

	_UpdateDirLightCamera();
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetVerAngle(float angle)
{
	mVerAngle = angle;

	_UpdateDirLightCamera();
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetAmbientColor(const Float3 &color)
{
	mAmbientColor = color;

	_UpdateDirLightCamera();
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetDiffuseColor(const Float3 &color)
{
	mDiffuseColor = color;

	_UpdateDirLightCamera();
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetSpecularColor(const Float3 &color)
{
	mSpecularColor = color;

	_UpdateDirLightCamera();
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetSpecularPow(float pow)
{
	mSpecularPow = pow;

	_UpdateDirLightCamera();
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetIntensity(float intensity)
{
	mIntensity = intensity;

	_UpdateDirLightCamera();
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetFogColorHeight(const Float3 &color)
{
	mFogColorHeight = color;

	_UpdateFog();
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetFogParamHeight(const Float2 &param)
{
	mFogParamHeight = param;

	_UpdateFog();
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetFogColorDistance(const Float3 &dist)
{
	mFogColorDist = dist;

	_UpdateFog();
}
//----------------------------------------------------------------------------
void AmbientRegionActor::SetFogParamDistance(const Float2 &param)
{
	mFogParamDist = param;

	_UpdateFog();
}
//----------------------------------------------------------------------------
void AmbientRegionActor::_UpdateDirLightCamera()
{
	AVector dir = AVector::AnglesToDirection(Mathf::DEG_TO_RAD*mHorAngle,
		Mathf::DEG_TO_RAD*mVerAngle);
	dir.Normalize();

	Scene *scene = DynamicCast<Scene>(GetTopestParent());
	if (scene)
	{
		EnvirParam *envirParam = scene->GetEnvirParam();

		Light *lightDir = envirParam->GetLight_Dir();
		Projector *projector = envirParam->GetLight_Dir_Projector();

		lightDir->Ambient = Float4(mAmbientColor[0], mAmbientColor[1],
			mAmbientColor[2], mIntensity);
		lightDir->Intensity = mIntensity;
		lightDir->Diffuse = Float4(mDiffuseColor[0], mDiffuseColor[1],
			mDiffuseColor[2], 1.0f);
		lightDir->Specular = Float4(mSpecularColor[0], mSpecularColor[1],
			mSpecularColor[2], mSpecularPow);

		float upDot = dir.Dot(-AVector::UNIT_Z);
		if (upDot >= 0.99f)
		{
		}
		else
		{
			AVector upTemp = AVector::UNIT_Z;
			AVector right = dir.UnitCross(upTemp);
			AVector up = right.UnitCross(dir);

			lightDir->DVector = dir;
			lightDir->UVector = up;
			lightDir->RVector = right;

			APoint camPos = mLightCameraLookPosition - dir*mLightCameraLookDistance;
			projector->SetFrame(camPos, lightDir->DVector,
				lightDir->UVector, lightDir->RVector);
		}

		if (!projector->IsPerspective())
		{
			projector->SetFrustum(0.1f, 100.0f,
				-mLightCameraExtent, mLightCameraExtent, -mLightCameraExtent,
				mLightCameraExtent);
		}
		else
		{
			projector->SetFrustum(mLightCameraExtent, 1.0f, 1.0f, 100.0f);
		}
	}
}
//----------------------------------------------------------------------------
void AmbientRegionActor::_UpdateFog()
{
	Scene *scene = DynamicCast<Scene>(GetTopestParent());
	if (scene)
	{
		EnvirParam *envirParam = scene->GetEnvirParam();

		envirParam->SetFogColorHeight(Float4(mFogColorHeight[0], mFogColorHeight[1],
			mFogColorHeight[2], 1.0f));

		envirParam->SetFogColorDist(Float4(mFogColorDist[0], mFogColorDist[1],
			mFogColorDist[2], 1.0f));

		Float4 fogParam = Float4(mFogParamHeight[0], mFogParamHeight[1],
			mFogParamDist[0], mFogParamDist[1]);
		envirParam->SetFogParam(fogParam);
	}
	else
	{
		assertion(false, "there must be a scene.");
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void AmbientRegionActor::RegistProperties()
{
	TriggerActor::RegistProperties();

	AddPropertyClass("AmbientRegionActor");

	AddProperty("HorAngle", Object::PT_FLOAT, mHorAngle);
	AddProperty("VerAngle", Object::PT_FLOAT, mVerAngle);
	AddProperty("LightCameraLookPosition", Object::PT_APOINT3, mLightCameraLookPosition);
	AddProperty("LightCameraLookDistance", Object::PT_FLOAT, mLightCameraLookDistance);
	AddProperty("LightCameraExtent", Object::PT_FLOAT, mLightCameraExtent);

	AddProperty("AmbientColor", Object::PT_COLOR3FLOAT3, mAmbientColor);
	AddProperty("DiffuseColor", Object::PT_COLOR3FLOAT3, mDiffuseColor);
	AddProperty("SpecularColor", Object::PT_COLOR3FLOAT3, mSpecularColor);
	AddProperty("SpecularPow", Object::PT_FLOAT, mSpecularPow);
	AddProperty("Intensity", Object::PT_FLOAT, mIntensity);

	AddProperty("FogColorHeight", PT_COLOR3FLOAT3, mFogColorHeight);
	AddProperty("FogParamHeight", PT_FLOAT2, mFogParamHeight);
	AddProperty("FogColorDistance", PT_COLOR3FLOAT3, mFogColorDist);
	AddProperty("FogParamDistance", PT_FLOAT2, mFogParamDist);
}
//----------------------------------------------------------------------------
void AmbientRegionActor::OnPropertyChanged(const PropertyObject &obj)
{
	TriggerActor::OnPropertyChanged(obj);

	if ("HorAngle" == obj.Name)
	{
		SetHorAngle(PX2_ANY_AS(obj.Data, float));
	}
	else if ("VerAngle" == obj.Name)
	{
		SetVerAngle(PX2_ANY_AS(obj.Data, float));
	}
	else if ("LightCameraLookPosition" == obj.Name)
	{
		SetLightCameraLookPostion(PX2_ANY_AS(obj.Data, APoint));
	}
	else if ("LightCameraLookDistance" == obj.Name)
	{
		SetLightCameraLookDistance(PX2_ANY_AS(obj.Data, float));
	}
	else if ("LightCameraExtent" == obj.Name)
	{
		SetLightCameraExtent(PX2_ANY_AS(obj.Data, float));
	}
	else if ("AmbientColor" == obj.Name)
	{
		SetAmbientColor(PX2_ANY_AS(obj.Data, Float3));
	}
	else if ("DiffuseColor" == obj.Name)
	{
		SetDiffuseColor(PX2_ANY_AS(obj.Data, Float3));
	}
	else if ("SpecularColor" == obj.Name)
	{
		SetSpecularColor(PX2_ANY_AS(obj.Data, Float3));
	}
	else if ("SpecularPow" == obj.Name)
	{
		SetSpecularPow(PX2_ANY_AS(obj.Data, float));
	}
	else if ("Intensity" == obj.Name)
	{
		SetIntensity(PX2_ANY_AS(obj.Data, float));
	}
	else if ("FogColorHeight" == obj.Name)
	{
		SetFogColorHeight(PX2_ANY_AS(obj.Data, Float3));
	}
	else if ("FogParamHeight" == obj.Name)
	{
		SetFogParamHeight(PX2_ANY_AS(obj.Data, Float2));
	}
	else if ("FogColorDistance" == obj.Name)
	{
		SetFogColorDistance(PX2_ANY_AS(obj.Data, Float3));
	}
	else if ("FogParamDistance" == obj.Name)
	{
		SetFogParamDistance(PX2_ANY_AS(obj.Data, Float2));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称支持
//----------------------------------------------------------------------------
Object* AmbientRegionActor::GetObjectByName(const std::string& name)
{
	Object* found = TriggerActor::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	return 0;
}
//----------------------------------------------------------------------------
void AmbientRegionActor::GetAllObjectsByName(const std::string& name,
	std::vector<Object*>& objects)
{
	TriggerActor::GetAllObjectsByName(name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
AmbientRegionActor::AmbientRegionActor(LoadConstructor value) :
TriggerActor(value)
{
}
//----------------------------------------------------------------------------
void AmbientRegionActor::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	TriggerActor::Load(source);
	PX2_VERSION_LOAD(source);

	source.Read(mHorAngle);
	source.Read(mVerAngle);

	source.ReadAggregate(mAmbientColor);
	source.ReadAggregate(mDiffuseColor);
	source.ReadAggregate(mSpecularColor);
	source.Read(mSpecularPow);
	source.Read(mIntensity);

	source.ReadAggregate(mLightCameraLookPosition);
	source.Read(mLightCameraLookDistance);
	source.Read(mLightCameraExtent);

	source.ReadAggregate(mFogColorHeight);
	source.ReadAggregate(mFogParamHeight);
	source.ReadAggregate(mFogColorDist);
	source.ReadAggregate(mFogParamDist);

	PX2_END_DEBUG_STREAM_LOAD(AmbientRegionActor, source);
}
//----------------------------------------------------------------------------
void AmbientRegionActor::Link(InStream& source)
{
	TriggerActor::Link(source);
}
//----------------------------------------------------------------------------
void AmbientRegionActor::PostLink()
{
	TriggerActor::PostLink();

	SetHorAngle(mHorAngle);
	SetVerAngle(mVerAngle);
	SetAmbientColor(mAmbientColor);
	SetDiffuseColor(mDiffuseColor);
	SetSpecularColor(mSpecularColor);
	SetSpecularPow(mSpecularPow);

	_UpdateDirLightCamera();
}
//----------------------------------------------------------------------------
bool AmbientRegionActor::Register(OutStream& target) const
{
	if (TriggerActor::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void AmbientRegionActor::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	TriggerActor::Save(target);
	PX2_VERSION_SAVE(target);
	
	target.Write(mHorAngle);
	target.Write(mVerAngle);

	target.WriteAggregate(mAmbientColor);
	target.WriteAggregate(mDiffuseColor);
	target.WriteAggregate(mSpecularColor);
	target.Write(mSpecularPow);
	target.Write(mIntensity);

	target.WriteAggregate(mLightCameraLookPosition);
	target.Write(mLightCameraLookDistance);
	target.Write(mLightCameraExtent);

	target.WriteAggregate(mFogColorHeight);
	target.WriteAggregate(mFogParamHeight);
	target.WriteAggregate(mFogColorDist);
	target.WriteAggregate(mFogParamDist);

	PX2_END_DEBUG_STREAM_SAVE(AmbientRegionActor, target);
}
//----------------------------------------------------------------------------
int AmbientRegionActor::GetStreamingSize(Stream &stream) const
{
	int size = TriggerActor::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += sizeof(mHorAngle);
	size += sizeof(mVerAngle);

	size += sizeof(mAmbientColor);
	size += sizeof(mDiffuseColor);
	size += sizeof(mSpecularColor);
	size += sizeof(mSpecularPow);
	size += sizeof(mIntensity);

	size += sizeof(mLightCameraLookPosition);
	size += sizeof(mLightCameraLookDistance);
	size += sizeof(mLightCameraExtent);

	size += sizeof(mFogColorHeight);
	size += sizeof(mFogParamHeight);
	size += sizeof(mFogColorDist);
	size += sizeof(mFogParamDist);

	return size;
}
//----------------------------------------------------------------------------