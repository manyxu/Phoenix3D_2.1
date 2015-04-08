// PX2EnvirParam.cpp

#include "PX2EnvirParam.hpp"
#include "PX2Renderable.hpp"
#include "PX2GraphicsEventType.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Object, EnvirParam);
PX2_IMPLEMENT_STREAM(EnvirParam);
PX2_IMPLEMENT_FACTORY(EnvirParam);

//----------------------------------------------------------------------------
EnvirParam::EnvirParam()
{
	mFogParam = Float4(-10.0f, 0.0f, 0.0f, 120.0f);
	mFogColorHeight = Float4::RED;
	mFogColorDist = Float4::BLUE;

	mLight_Dir_Projector = new0 Projector(true);

	mLight_Dir = new0 Light(Light::LT_DIRECTIONAL);
	mLight_Dir->Ambient = Float4(0.5f, 0.5f, 0.5f, 1.0f);
	mLight_Dir->Diffuse = Float4(0.5f, 0.5f, 0.5f, 1.0f);
	mLight_Dir->Specular = Float4(0.5f, 0.5f, 0.5f, 1.0f);
	AVector lightVec(-1.0f, -1.0f, -1.0f);
	lightVec.Normalize();
	mLight_Dir->SetDirection(lightVec);
}
//----------------------------------------------------------------------------
EnvirParam::~EnvirParam()
{
	mAllLights.clear();
	mLight_Dir = 0;
}
//----------------------------------------------------------------------------
void EnvirParam::AddLight(Light *light)
{
	if (!light) return;

	bool bIn = false;
	for (int i = 0; i < (int)mAllLights.size(); i++)
	{
		if (light == mAllLights[i])
			bIn = true;
	}

	if (!bIn)
	{
		if (Light::LT_DIRECTIONAL == light->GetType())
		{
			mLight_Dir = light;
		}

		mAllLights.push_back(light);
	}
}
//----------------------------------------------------------------------------
void EnvirParam::RemoveLight(Light *light)
{
	std::vector<Pointer0<Light> >::iterator it = mAllLights.begin();
	for (; it != mAllLights.end(); it++)
	{
		if (*it == light)
		{
			mAllLights.erase(it);
			return;
		}
	}
}
//----------------------------------------------------------------------------
void EnvirParam::ClearAllLights()
{
	mAllLights.clear();
}
//----------------------------------------------------------------------------
int EnvirParam::GetNumLights()
{
	return (int)mAllLights.size();
}
//----------------------------------------------------------------------------
Light *EnvirParam::GetLight(int index)
{
	int numLights = (int)mAllLights.size();
	if (index >= 0 && index < numLights)
	{
		return mAllLights[index];
	}

	return 0;
}
//----------------------------------------------------------------------------
void EnvirParam::ComputeEnvironment(VisibleSet &vs)
{
	for (int i = 0; i < vs.GetNumVisible(); i++)
	{
		PX2::Renderable *renderable = vs.GetVisible(i);
		PX2::APoint renPos = renderable->WorldTransform.GetTranslate();
		renderable->ClearLights();

		for (int j = 0; j < (int)mAllLights.size(); j++)
		{
			PX2::Light *light = mAllLights[j];
			Bound lightBound;
			lightBound.SetCenter(light->Position);
			lightBound.SetRadius(light->Range);

			if (Light::LT_POINT == light->GetType() &&
				renderable->WorldBound.TestIntersection(lightBound))
			{
				renderable->AddLight(light);
			}
		}
	}
}
//----------------------------------------------------------------------------
void EnvirParam::SetLight_Dir_DepthTexture(Texture *tex)
{
	mLight_Dir_DepthTexture = tex;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
EnvirParam::EnvirParam(LoadConstructor value) :
Object(value)
{
}
//----------------------------------------------------------------------------
void EnvirParam::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Object::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadPointer(mLight_Dir);
	source.ReadPointer(mLight_Dir_Projector);

	source.ReadAggregate(mFogParam);
	source.ReadAggregate(mFogColorDist);
	source.ReadAggregate(mFogColorHeight);

	PX2_END_DEBUG_STREAM_LOAD(EnvirParam, source);
}
//----------------------------------------------------------------------------
void EnvirParam::Link(InStream& source)
{
	Object::Link(source);

	if (mLight_Dir)
		source.ResolveLink(mLight_Dir);

	if (mLight_Dir_Projector)
		source.ResolveLink(mLight_Dir_Projector);
}
//----------------------------------------------------------------------------
void EnvirParam::PostLink()
{
	Object::PostLink();
}
//----------------------------------------------------------------------------
bool EnvirParam::Register(OutStream& target) const
{
	if (Object::Register(target))
	{
		if (mLight_Dir)
			target.Register(mLight_Dir);

		if (mLight_Dir_Projector)
			target.Register(mLight_Dir_Projector);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void EnvirParam::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Object::Save(target);
	PX2_VERSION_SAVE(target);

	target.WritePointer(mLight_Dir);
	target.WritePointer(mLight_Dir_Projector);

	target.WriteAggregate(mFogParam);
	target.WriteAggregate(mFogColorDist);
	target.WriteAggregate(mFogColorHeight);

	PX2_END_DEBUG_STREAM_SAVE(EnvirParam, target);
}
//----------------------------------------------------------------------------
int EnvirParam::GetStreamingSize(Stream &stream) const
{
	int size = Object::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_POINTERSIZE(mLight_Dir);
	size += PX2_POINTERSIZE(mLight_Dir_Projector);

	size += sizeof(mFogParam);
	size += sizeof(mFogColorDist);
	size += sizeof(mFogColorHeight);

	return size;
}
//----------------------------------------------------------------------------