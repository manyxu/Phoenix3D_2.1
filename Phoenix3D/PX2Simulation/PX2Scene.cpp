// PX2Scene.cpp

#include "PX2Scene.hpp"
#include "PX2Project.hpp"
#include "PX2Creater.hpp"
#include "PX2Actor.hpp"
#include "PX2SimulationEventType.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI_V(PX2, Node, Scene, 3);
PX2_IMPLEMENT_STREAM(Scene);
PX2_IMPLEMENT_FACTORY(Scene);
PX2_IMPLEMENT_DEFAULT_NAMES(Node, Scene);

//----------------------------------------------------------------------------
int Scene::msNextID = 0;
//----------------------------------------------------------------------------
int Scene::GetNextID()
{
	return msNextID++;
}
//----------------------------------------------------------------------------
Scene::Scene() :
mIsShowHelpNode(true),
mIsUseBloom(false),
mIsBloomRenderTargetSizeSameWithScreen(false),
mBloomRenderTargetSize(Float2(512.0f, 512.0f)),
mBloomBrightWeight(0.3f),
mBloomBlurDeviation(1.0f),
mBloomBlurWeight(1.0f),
mBloomWeight(1.0f),
mBloomBrightParam(Float4::ZERO),
mBloomParam(Float4::UNIT),
mIsUseShadowMap(false),
mIsShadowRenderTargetSizeSameWithScreen(false),
mShadowRenderTargetSize(Float2(512.0f, 512.0f))
{
	SetName("Scene");

	mEnvirParam = new0 EnvirParam();

	CameraActor *camActor = new0 CameraActor();
	AttachChild(camActor);
	camActor->LocalTransform.SetTranslate(APoint(0.0f, -5.0f, 1.0f));
	SetUseCameraActor(camActor);

	mDefaultAmbientRegionActor = new0 AmbientRegionActor();
	mDefaultAmbientRegionActor->SetName("DefaultAmbientRegion");
	AttachChild(mDefaultAmbientRegionActor);

	SetColor(Float3::WHITE);

	mIsShowHelpNode = true;
}
//----------------------------------------------------------------------------
Scene::~Scene()
{
}
//----------------------------------------------------------------------------
void Scene::SetAlpha(float alpha)
{
	Movable::SetAlpha(alpha);
}
//----------------------------------------------------------------------------
void Scene::SetColor(const Float3 &color)
{
	Movable::SetColor(color);
}
//----------------------------------------------------------------------------
void Scene::SetBrightness(float brightness)
{
	Movable::SetBrightness(brightness);
}
//----------------------------------------------------------------------------
void Scene::SetUseCameraActor(CameraActor *cameraActor)
{
	mCameraActor = cameraActor;

	Project *proj = Project::GetSingletonPtr();
	if (proj && mCameraActor)
	{
		RenderStep *renderStep = proj->GetSceneRenderStep();
		if (renderStep)
		{
			renderStep->SetCamera(mCameraActor->GetCamera());
		}
	}
}
//----------------------------------------------------------------------------
int Scene::AttachChild(Movable* child)
{
	Actor *actor = DynamicCast<Actor>(child);
	if (actor)
	{
		TerrainActor *terrainActor = DynamicCast<TerrainActor>(child);
		if (terrainActor) mTerrainActor = terrainActor;

		SkyActor *skyActor = DynamicCast<SkyActor>(child);
		if (skyActor) mSkyActor = skyActor;
	}

	return Node::AttachChild(child);
}
//----------------------------------------------------------------------------
int Scene::DetachChild(Movable* child)
{
	if (mDefaultAmbientRegionActor == child) return -1;

	Actor *actor = DynamicCast<Actor>(child);
	if (actor)
	{
		if (mTerrainActor == child)
			mTerrainActor = 0;

		if (mSkyActor == child)
			mSkyActor = 0;
	}

	return Node::DetachChild(child);
}
//----------------------------------------------------------------------------
Actor *Scene::GetActorByID(int id)
{
	std::map<int, ActorPtr>::iterator it = mActors.find(id);
	if (it != mActors.end())
	{
		return it->second;
	}

	return 0;
}
//----------------------------------------------------------------------------
void Scene::OnChildAdded(Movable *child)
{
	Actor *actor = DynamicCast<Actor>(child);
	
	if (actor)
	{
		int id = actor->GetID();
		if (0 != id)
		{
			mActors[actor->GetID()] = actor;
		}
	}
}
//----------------------------------------------------------------------------
void Scene::OnChildRemoved(Movable *child)
{
	Actor *actor = DynamicCast<Actor>(child);

	if (actor)
	{
		int id = actor->GetID();
		if (0 != id)
		{
			std::map<int, ActorPtr>::iterator it = mActors.find(id);
			if (it != mActors.end())
			{
				mActors.erase(it);
			}
		}
	}
}
//----------------------------------------------------------------------------
void _SceneTravelExecuteFun (Movable *mov, Any *data)
{
	Actor *actor = DynamicCast<Actor>(mov);

	if (actor)
	{
		bool show = PX2_ANY_AS(*data , bool);
		actor->GetNodeHelp()->Show(show);
	}
}
//----------------------------------------------------------------------------
void Scene::SetShowHelpNode(bool showHelpNode)
{
	mIsShowHelpNode = showHelpNode;

	Any data = showHelpNode;
	Node::TravelExecute(this, _SceneTravelExecuteFun, &data);
}
//----------------------------------------------------------------------------
void Scene::UpdateWorldData(double applicationTime, double elapsedTime)
{
	Node::UpdateWorldData(applicationTime, elapsedTime);
}
//----------------------------------------------------------------------------
void Scene::SetUseBloom(bool isUseBloom)
{
	mIsUseBloom = isUseBloom;

	Event *ent = SimuES::CreateEventX(SimuES::Scene_BloomChanged);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void Scene::SetBloomBrightWeight(float weight)
{
	mBloomBrightWeight = weight;
	mBloomBrightParam[0] = weight;

	if (mIsUseBloom)
	{
		Event *ent = SimuES::CreateEventX(SimuES::Scene_BloomChanged);
		PX2_EW.BroadcastingLocalEvent(ent);
	}
}
//----------------------------------------------------------------------------
void Scene::SetBloomRenderTargetSizeSameWithScreen(
	bool sizeSameWithScreen)
{
	mIsBloomRenderTargetSizeSameWithScreen = sizeSameWithScreen;

	if (mIsUseBloom)
	{
		Event *ent = SimuES::CreateEventX(SimuES::Scene_BloomChanged);
		PX2_EW.BroadcastingLocalEvent(ent);
	}
}
//----------------------------------------------------------------------------
bool Scene::IsBloomRenderTargetSizeSameWithScreen() const
{
	return mIsBloomRenderTargetSizeSameWithScreen;
}
//----------------------------------------------------------------------------
float Scene::GetBloomBrightWeight() const
{
	return mBloomBrightWeight;
}
//----------------------------------------------------------------------------
void Scene::SetBloomRenderTargetSize(const Float2 &size)
{
	mBloomRenderTargetSize = size;

	if (mIsUseBloom)
	{
		Event *ent = SimuES::CreateEventX(SimuES::Scene_BloomChanged);
		PX2_EW.BroadcastingLocalEvent(ent);
	}
}
//----------------------------------------------------------------------------
void Scene::SetBloomBlurDeviation(float deviation)
{
	mBloomBlurDeviation = deviation;

	if (mIsUseBloom)
	{
		Event *ent = SimuES::CreateEventX(SimuES::Scene_BloomChanged);
		PX2_EW.BroadcastingLocalEvent(ent);
	}
}
//----------------------------------------------------------------------------
void Scene::SetBloomBlurWeight(float weight)
{
	mBloomBlurWeight = weight;

	if (mIsUseBloom)
	{
		Event *ent = SimuES::CreateEventX(SimuES::Scene_BloomChanged);
		PX2_EW.BroadcastingLocalEvent(ent);
	}
}
//----------------------------------------------------------------------------
void Scene::SetBloomWeight(float weight)
{
	mBloomWeight = weight;
	mBloomParam[0] = weight;

	if (mIsUseBloom)
	{
		Event *ent = SimuES::CreateEventX(SimuES::Scene_BloomChanged);
		PX2_EW.BroadcastingLocalEvent(ent);
	}
}
//----------------------------------------------------------------------------
void _SceneTravelExecuteFun_ShadowMap(Movable *mov, Any *data)
{
	Actor *actor = DynamicCast<Actor>(mov);

	if (actor)
	{
		bool useShadowMap = PX2_ANY_AS(*data, bool);
		actor->SetReceiveShadow(useShadowMap);
	}
}
//----------------------------------------------------------------------------
void Scene::SetUseShadowMap(bool isUseShadowMap)
{
	mIsUseShadowMap = isUseShadowMap;

	Event *ent = SimuES::CreateEventX(SimuES::Scene_ShadowMapChange);
	PX2_EW.BroadcastingLocalEvent(ent);

	Any data = mIsUseShadowMap;
	Node::TravelExecute(this, _SceneTravelExecuteFun_ShadowMap, &data);
}
//----------------------------------------------------------------------------
void Scene::SetShadowRenderTargetSizeSameWithScreen(bool sameWithScreen)
{
	mIsShadowRenderTargetSizeSameWithScreen = sameWithScreen;

	if (mIsUseShadowMap)
	{
		Event *ent = SimuES::CreateEventX(SimuES::Scene_ShadowMapChange);
		PX2_EW.BroadcastingLocalEvent(ent);

		// 重新刷新深度图
		Any data = mIsUseShadowMap;
		Node::TravelExecute(this, _SceneTravelExecuteFun_ShadowMap, &data);
	}
}
//----------------------------------------------------------------------------
void Scene::SetShadowRenderTargetSize(const Float2 &size)
{
	mShadowRenderTargetSize = size;

	if (mIsUseShadowMap)
	{
		Event *ent = SimuES::CreateEventX(SimuES::Scene_ShadowMapChange);
		PX2_EW.BroadcastingLocalEvent(ent);

		// 重新刷新深度图
		Any data = mIsUseShadowMap;
		Node::TravelExecute(this, _SceneTravelExecuteFun_ShadowMap, &data);
	}
}
//----------------------------------------------------------------------------
void Scene::SetShadowOffsetProperty_Scale(float scale)
{
	if (mEnvirParam)
		mEnvirParam->SetShadowMap_OffsetPropertyScale(scale);
}
//----------------------------------------------------------------------------
void Scene::SetShadowOffsetProperty_Bias(float bias)
{
	if (mEnvirParam)
		mEnvirParam->SetShadowMap_OffsetPropertyBias(bias);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void Scene::RegistProperties()
{
	Node::RegistProperties();

	AddPropertyClass("Scene");

	AddProperty("NumActors", PT_INT, (int)mActors.size(), false);
	AddProperty("Size", PT_SIZE, mSize);

	AddProperty("IsShowHelpNode", PT_BOOL, IsShowHelpNode());

	AddProperty("IsUseBloom", PT_BOOL, mIsUseBloom);
	AddProperty("IsBloomRenderTargetSizeSameWithScreen", PT_BOOL,
		mIsBloomRenderTargetSizeSameWithScreen);
	AddProperty("BloomRenderTargetSize", PT_FLOAT2,
		mBloomRenderTargetSize);
	AddProperty("BloomBrightWeight", PT_FLOAT,
		mBloomBrightWeight);
	AddProperty("BloomBlurDeviation", PT_FLOAT,
		mBloomBlurDeviation);
	AddProperty("BloomBlurWeight", PT_FLOAT, mBloomBlurWeight);
	AddProperty("BloomWeight", PT_FLOAT, mBloomWeight);

	AddProperty("IsUseShadowMap", PT_BOOL, mIsUseShadowMap);
	AddProperty("IsShadowMapProjectorPerspective", PT_BOOL, 
		mEnvirParam->GetLight_Dir_Projector()->IsPerspective());

	AddProperty("IsShadowRenderTargetSizeSameWithScreen", PT_BOOL,
		mIsShadowRenderTargetSizeSameWithScreen);
	AddProperty("ShadowRenderTargetSize", PT_FLOAT2,
		mShadowRenderTargetSize);

	AddProperty("ShadowOffsetProperty_Scale", PT_FLOAT, GetShadowOffsetProperty_Scale());
	AddProperty("ShadowOffsetProperty_Bias", PT_FLOAT, GetShadowOffsetProperty_Bias());
}
//----------------------------------------------------------------------------
void Scene::OnPropertyChanged(const PropertyObject &obj)
{
	Node::OnPropertyChanged(obj);

	if ("Size" == obj.Name)
	{
		SetSize(PX2_ANY_AS(obj.Data, Sizef));
	}
	else if ("IsShowHelpNode" == obj.Name)
	{
		SetShowHelpNode(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("IsUseBloom" == obj.Name)
	{
		SetUseBloom(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("IsBloomRenderTargetSizeSameWithScreen" == obj.Name)
	{
		SetBloomRenderTargetSizeSameWithScreen(PX2_ANY_AS(obj.Data,
			bool));
	}
	else if ("BloomRenderTargetSize" == obj.Name)
	{
		SetBloomRenderTargetSize(PX2_ANY_AS(obj.Data, Float2));
	}
	else if ("BloomBrightWeight" == obj.Name)
	{
		SetBloomBrightWeight(PX2_ANY_AS(obj.Data, float));
	}
	else if ("BloomBlurDeviation" == obj.Name)
	{
		SetBloomBlurDeviation(PX2_ANY_AS(obj.Data, float));
	}
	else if ("BloomBlurWeight" == obj.Name)
	{
		SetBloomBlurWeight(PX2_ANY_AS(obj.Data, float));
	}
	else if ("BloomWeight" == obj.Name)
	{
		SetBloomWeight(PX2_ANY_AS(obj.Data, float));
	}
	else if ("IsUseShadowMap" == obj.Name)
	{
		SetUseShadowMap(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("IsShadowMapProjectorPerspective" == obj.Name)
	{
		mEnvirParam->GetLight_Dir_Projector()->SetPerspective(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("IsShadowRenderTargetSizeSameWithScreen" == obj.Name)
	{
		SetShadowRenderTargetSizeSameWithScreen(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("ShadowRenderTargetSize" == obj.Name)
	{
		SetShadowRenderTargetSize(PX2_ANY_AS(obj.Data, Float2));
	}
	else if ("ShadowOffsetProperty_Scale" == obj.Name)
	{
		SetShadowOffsetProperty_Scale(PX2_ANY_AS(obj.Data, float));
	}
	else if ("ShadowOffsetProperty_Bias" == obj.Name)
	{
		SetShadowOffsetProperty_Bias(PX2_ANY_AS(obj.Data, float));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Scene::Scene(LoadConstructor value) :
Node(value),
mIsShowHelpNode(true),
mIsUseBloom(false),
mIsBloomRenderTargetSizeSameWithScreen(false),
mBloomRenderTargetSize(Float2(512.0f, 512.0f)),
mBloomBrightWeight(0.3f),
mBloomBlurDeviation(1.0f),
mBloomBlurWeight(1.0f),
mBloomWeight(1.0f),
mBloomParam(Float4::UNIT),
mIsUseShadowMap(false),
mIsShadowRenderTargetSizeSameWithScreen(false),
mShadowRenderTargetSize(Float2(512.0f, 512.0f))
{
	mShadowRenderTargetSize = Float2(512.0f, 512.0f);
}
//----------------------------------------------------------------------------
void Scene::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Node::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadPointer(mEnvirParam);

	source.ReadPointer(mCameraActor);
	source.ReadPointer(mDefaultAmbientRegionActor);
	source.ReadPointer(mTerrainActor);
	source.ReadPointer(mSkyActor);

	int readedVersion = GetReadedVersion();
	if (1 <= readedVersion)
	{
		source.ReadBool(mIsShowHelpNode);
	}
	if (2 <= readedVersion)
	{
		source.ReadBool(mIsUseBloom);
		source.ReadBool(mIsBloomRenderTargetSizeSameWithScreen);
		source.ReadAggregate(mBloomRenderTargetSize);
		source.Read(mBloomBrightWeight);

		source.Read(mBloomBlurDeviation);
		source.Read(mBloomBlurWeight);
		source.Read(mBloomWeight);

		source.ReadBool(mIsUseShadowMap);
		source.ReadBool(mIsShadowRenderTargetSizeSameWithScreen);
		source.ReadAggregate(mShadowRenderTargetSize);
	}
	if (3 <= readedVersion)
	{
		source.ReadAggregate(mViewPort);
	}

	PX2_END_DEBUG_STREAM_LOAD(Scene, source);
}
//----------------------------------------------------------------------------
void Scene::Link(InStream& source)
{
	Node::Link(source);

	if (mEnvirParam)
		source.ResolveLink(mEnvirParam);

	if (mCameraActor)
		source.ResolveLink(mCameraActor);

	if (mDefaultAmbientRegionActor)
		source.ResolveLink(mDefaultAmbientRegionActor);

	if (mTerrainActor)
		source.ResolveLink(mTerrainActor);

	if (mSkyActor)
		source.ResolveLink(mSkyActor);

	mBloomBrightParam[0] = mBloomBrightWeight;
	mBloomParam[0] = mBloomWeight;
}
//----------------------------------------------------------------------------
void Scene::PostLink()
{
	Node::PostLink();

	RegistToScriptSystem();
}
//----------------------------------------------------------------------------
bool Scene::Register(OutStream& target) const
{
	if (Node::Register(target))
	{
		if (mEnvirParam)
			target.Register(mEnvirParam);

		if (mCameraActor) 
			target.Register(mCameraActor);

		if (mDefaultAmbientRegionActor) 
			target.Register(mDefaultAmbientRegionActor);

		if (mTerrainActor)
			target.Register(mTerrainActor);

		if (mSkyActor)
			target.Register(mSkyActor);
		
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void Scene::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Node::Save(target);
	PX2_VERSION_SAVE(target);

	target.WritePointer(mEnvirParam);
	target.WritePointer(mCameraActor);
	target.WritePointer(mDefaultAmbientRegionActor);
	target.WritePointer(mTerrainActor);
	target.WritePointer(mSkyActor);

	target.WriteBool(mIsShowHelpNode);

	target.WriteBool(mIsUseBloom);
	target.WriteBool(mIsBloomRenderTargetSizeSameWithScreen);
	target.WriteAggregate(mBloomRenderTargetSize);
	target.Write(mBloomBrightWeight);

	target.Write(mBloomBlurDeviation);
	target.Write(mBloomBlurWeight);
	target.Write(mBloomWeight);

	target.WriteBool(mIsUseShadowMap);
	target.WriteBool(mIsShadowRenderTargetSizeSameWithScreen);
	target.WriteAggregate(mShadowRenderTargetSize);

	target.WriteAggregate(mViewPort);

	PX2_END_DEBUG_STREAM_SAVE(Scene, target);
}
//----------------------------------------------------------------------------
int Scene::GetStreamingSize(Stream &stream) const
{
	int size = Node::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_POINTERSIZE(mEnvirParam);
	size += PX2_POINTERSIZE(mCameraActor);
	size += PX2_POINTERSIZE(mDefaultAmbientRegionActor);
	size += PX2_POINTERSIZE(mTerrainActor);
	size += PX2_POINTERSIZE(mSkyActor);

	if (stream.IsIn())
	{
		int readedVersion = GetReadedVersion();
		if (1 <= readedVersion)
		{
			size += PX2_BOOLSIZE(mIsShowHelpNode);
		}
		if (2 <= readedVersion)
		{
			size += PX2_BOOLSIZE(mIsUseBloom);
			size += PX2_BOOLSIZE(mIsBloomRenderTargetSizeSameWithScreen);
			size += sizeof(mBloomRenderTargetSize);
			size += sizeof(mBloomBrightWeight);

			size += sizeof(mBloomBlurDeviation);
			size += sizeof(mBloomBlurWeight);
			size += sizeof(mBloomWeight);

			size += PX2_BOOLSIZE(mIsUseShadowMap);
			size += PX2_BOOLSIZE(mIsShadowRenderTargetSizeSameWithScreen);
			size += sizeof(mShadowRenderTargetSize);
		}
		if (3 <= readedVersion)
		{
			size += sizeof(mViewPort);
		}
	}
	else
	{
		size += PX2_BOOLSIZE(mIsShowHelpNode);

		size += PX2_BOOLSIZE(mIsUseBloom);
		size += PX2_BOOLSIZE(mIsBloomRenderTargetSizeSameWithScreen);
		size += sizeof(mBloomRenderTargetSize);
		size += sizeof(mBloomBrightWeight);

		size += sizeof(mBloomBlurDeviation);
		size += sizeof(mBloomBlurWeight);
		size += sizeof(mBloomWeight);

		size += PX2_BOOLSIZE(mIsUseShadowMap);
		size += PX2_BOOLSIZE(mIsShadowRenderTargetSizeSameWithScreen);
		size += sizeof(mShadowRenderTargetSize);

		size += sizeof(mViewPort);
	}

	return size;
}
//----------------------------------------------------------------------------