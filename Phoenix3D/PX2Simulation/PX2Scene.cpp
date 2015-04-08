// PX2Scene.cpp

#include "PX2Scene.hpp"
#include "PX2Project.hpp"
#include "PX2Creater.hpp"
#include "PX2Actor.hpp"
#include "PX2SimulationEventType.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI_V(PX2, Node, Scene, 2);
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
mIsScene_UseBloom(false),
mIsScene_BloomRenderTargetSizeSameWithScreen(false),
mScene_BloomRenderTargetSize(Float2(512.0f, 512.0f)),
mScene_BloomBrightWeight(0.3f),
mScene_BloomBlurDeviation(1.0f),
mScene_BloomBlurWeight(1.0f),
mScene_BloomWeight(1.0f),
mBloomBrightParam(Float4::ZERO),
mBloomParam(Float4::UNIT),
mIsScene_UseShadowMap(false),
mIsScene_ShadowRenderTargetSizeSameWithScreen(false),
mScene_ShadowRenderTargetSize(Float2(512.0f, 512.0f))
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
void Scene::SetScene_UseBloom(bool isUseBloom)
{
	mIsScene_UseBloom = isUseBloom;

	Event *ent = SimuES::CreateEventX(SimuES::Scene_BloomChanged);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void Scene::SetScene_BloomBrightWeight(float weight)
{
	mScene_BloomBrightWeight = weight;
	mBloomBrightParam[0] = weight;

	if (mIsScene_UseBloom)
	{
		Event *ent = SimuES::CreateEventX(SimuES::Scene_BloomChanged);
		PX2_EW.BroadcastingLocalEvent(ent);
	}
}
//----------------------------------------------------------------------------
void Scene::SetScene_BloomRenderTargetSizeSameWithScreen(
	bool sizeSameWithScreen)
{
	mIsScene_BloomRenderTargetSizeSameWithScreen = sizeSameWithScreen;

	if (mIsScene_UseBloom)
	{
		Event *ent = SimuES::CreateEventX(SimuES::Scene_BloomChanged);
		PX2_EW.BroadcastingLocalEvent(ent);
	}
}
//----------------------------------------------------------------------------
bool Scene::IsScene_BloomRenderTargetSizeSameWithScreen() const
{
	return mIsScene_BloomRenderTargetSizeSameWithScreen;
}
//----------------------------------------------------------------------------
float Scene::GetScene_BloomBrightWeight() const
{
	return mScene_BloomBrightWeight;
}
//----------------------------------------------------------------------------
void Scene::SetScene_BloomRenderTargetSize(const Float2 &size)
{
	mScene_BloomRenderTargetSize = size;

	if (mIsScene_UseBloom)
	{
		Event *ent = SimuES::CreateEventX(SimuES::Scene_BloomChanged);
		PX2_EW.BroadcastingLocalEvent(ent);
	}
}
//----------------------------------------------------------------------------
void Scene::SetScene_BloomBlurDeviation(float deviation)
{
	mScene_BloomBlurDeviation = deviation;

	if (mIsScene_UseBloom)
	{
		Event *ent = SimuES::CreateEventX(SimuES::Scene_BloomChanged);
		PX2_EW.BroadcastingLocalEvent(ent);
	}
}
//----------------------------------------------------------------------------
void Scene::SetScene_BloomBlurWeight(float weight)
{
	mScene_BloomBlurWeight = weight;

	if (mIsScene_UseBloom)
	{
		Event *ent = SimuES::CreateEventX(SimuES::Scene_BloomChanged);
		PX2_EW.BroadcastingLocalEvent(ent);
	}
}
//----------------------------------------------------------------------------
void Scene::SetScene_BloomWeight(float weight)
{
	mScene_BloomWeight = weight;
	mBloomParam[0] = weight;

	if (mIsScene_UseBloom)
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
		actor->ToggleUseShadowMap(useShadowMap);
	}
}
//----------------------------------------------------------------------------
void Scene::SetScene_UseShadowMap(bool isUseShadowMap)
{
	mIsScene_UseShadowMap = isUseShadowMap;

	Event *ent = SimuES::CreateEventX(SimuES::Scene_ShadowMapChange);
	PX2_EW.BroadcastingLocalEvent(ent);

	Any data = mIsScene_UseShadowMap;
	Node::TravelExecute(this, _SceneTravelExecuteFun_ShadowMap, &data);
}
//----------------------------------------------------------------------------
void Scene::SetScene_ShadowRenderTargetSizeSameWithScreen(bool sameWithScreen)
{
	mIsScene_ShadowRenderTargetSizeSameWithScreen = sameWithScreen;

	if (mIsScene_UseShadowMap)
	{
		Event *ent = SimuES::CreateEventX(SimuES::Scene_ShadowMapChange);
		PX2_EW.BroadcastingLocalEvent(ent);

		// 重新刷新深度图
		Any data = mIsScene_UseShadowMap;
		Node::TravelExecute(this, _SceneTravelExecuteFun_ShadowMap, &data);
	}
}
//----------------------------------------------------------------------------
void Scene::SetScene_ShadowRenderTargetSize(const Float2 &size)
{
	mScene_ShadowRenderTargetSize = size;

	if (mIsScene_UseShadowMap)
	{
		Event *ent = SimuES::CreateEventX(SimuES::Scene_ShadowMapChange);
		PX2_EW.BroadcastingLocalEvent(ent);

		// 重新刷新深度图
		Any data = mIsScene_UseShadowMap;
		Node::TravelExecute(this, _SceneTravelExecuteFun_ShadowMap, &data);
	}
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

	AddProperty("IsScene_UseBloom", PT_BOOL, mIsScene_UseBloom);
	AddProperty("IsScene_BloomRenderTargetSizeSameWithScreen", PT_BOOL,
		mIsScene_BloomRenderTargetSizeSameWithScreen);
	AddProperty("Scene_BloomRenderTargetSize", PT_FLOAT2,
		mScene_BloomRenderTargetSize);
	AddProperty("Scene_BloomBrightWeight", PT_FLOAT,
		mScene_BloomBrightWeight);
	AddProperty("Scene_BloomBlurDeviation", PT_FLOAT,
		mScene_BloomBlurDeviation);
	AddProperty("Scene_BloomBlurWeight", PT_FLOAT, mScene_BloomBlurWeight);
	AddProperty("Scene_BloomWeight", PT_FLOAT, mScene_BloomWeight);

	AddProperty("IsScene_UseShadowMap", PT_BOOL, mIsScene_UseShadowMap);
	AddProperty("IsScene_ShadowRenderTargetSizeSameWithScreen", PT_BOOL,
		mIsScene_ShadowRenderTargetSizeSameWithScreen);
	AddProperty("Scene_ShadowRenderTargetSize", PT_FLOAT2,
		mScene_ShadowRenderTargetSize);
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

	else if ("IsScene_UseBloom" == obj.Name)
	{
		SetScene_UseBloom(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("IsScene_BloomRenderTargetSizeSameWithScreen" == obj.Name)
	{
		SetScene_BloomRenderTargetSizeSameWithScreen(PX2_ANY_AS(obj.Data,
			bool));
	}
	else if ("Scene_BloomRenderTargetSize" == obj.Name)
	{
		SetScene_BloomRenderTargetSize(PX2_ANY_AS(obj.Data, Float2));
	}
	else if ("Scene_BloomBrightWeight" == obj.Name)
	{
		SetScene_BloomBrightWeight(PX2_ANY_AS(obj.Data, float));
	}
	else if ("Scene_BloomBlurDeviation" == obj.Name)
	{
		SetScene_BloomBlurDeviation(PX2_ANY_AS(obj.Data, float));
	}
	else if ("Scene_BloomBlurWeight" == obj.Name)
	{
		SetScene_BloomBlurWeight(PX2_ANY_AS(obj.Data, float));
	}
	else if ("Scene_BloomWeight" == obj.Name)
	{
		SetScene_BloomWeight(PX2_ANY_AS(obj.Data, float));
	}

	else if ("IsScene_UseShadowMap" == obj.Name)
	{
		SetScene_UseShadowMap(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("IsScene_ShadowRenderTargetSizeSameWithScreen" == obj.Name)
	{
		SetScene_ShadowRenderTargetSizeSameWithScreen(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("Scene_ShadowRenderTargetSize" == obj.Name)
	{
		SetScene_ShadowRenderTargetSize(PX2_ANY_AS(obj.Data, Float2));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Scene::Scene(LoadConstructor value) :
Node(value),
mIsShowHelpNode(true),
mIsScene_UseBloom(false),
mIsScene_BloomRenderTargetSizeSameWithScreen(false),
mScene_BloomRenderTargetSize(Float2(512.0f, 512.0f)),
mScene_BloomBrightWeight(0.3f),
mScene_BloomBlurDeviation(1.0f),
mScene_BloomBlurWeight(1.0f),
mScene_BloomWeight(1.0f),
mBloomParam(Float4::UNIT),
mIsScene_UseShadowMap(false),
mIsScene_ShadowRenderTargetSizeSameWithScreen(false),
mScene_ShadowRenderTargetSize(Float2(512.0f, 512.0f))
{
	mScene_ShadowRenderTargetSize = Float2(512.0f, 512.0f);
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
		source.ReadBool(mIsScene_UseBloom);
		source.ReadBool(mIsScene_BloomRenderTargetSizeSameWithScreen);
		source.ReadAggregate(mScene_BloomRenderTargetSize);
		source.Read(mScene_BloomBrightWeight);

		source.Read(mScene_BloomBlurDeviation);
		source.Read(mScene_BloomBlurWeight);
		source.Read(mScene_BloomWeight);

		source.ReadBool(mIsScene_UseShadowMap);
		source.ReadBool(mIsScene_ShadowRenderTargetSizeSameWithScreen);
		source.ReadAggregate(mScene_ShadowRenderTargetSize);
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

	mBloomBrightParam[0] = mScene_BloomBrightWeight;
	mBloomParam[0] = mScene_BloomWeight;
}
//----------------------------------------------------------------------------
void Scene::PostLink()
{
	Node::PostLink();
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

	target.WriteBool(mIsScene_UseBloom);
	target.WriteBool(mIsScene_BloomRenderTargetSizeSameWithScreen);
	target.WriteAggregate(mScene_BloomRenderTargetSize);
	target.Write(mScene_BloomBrightWeight);

	target.Write(mScene_BloomBlurDeviation);
	target.Write(mScene_BloomBlurWeight);
	target.Write(mScene_BloomWeight);

	target.WriteBool(mIsScene_UseShadowMap);
	target.WriteBool(mIsScene_ShadowRenderTargetSizeSameWithScreen);
	target.WriteAggregate(mScene_ShadowRenderTargetSize);

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
			size += PX2_BOOLSIZE(mIsScene_UseBloom);
			size += PX2_BOOLSIZE(mIsScene_BloomRenderTargetSizeSameWithScreen);
			size += sizeof(mScene_BloomRenderTargetSize);
			size += sizeof(mScene_BloomBrightWeight);

			size += sizeof(mScene_BloomBlurDeviation);
			size += sizeof(mScene_BloomBlurWeight);
			size += sizeof(mScene_BloomWeight);

			size += PX2_BOOLSIZE(mIsScene_UseShadowMap);
			size += PX2_BOOLSIZE(mIsScene_ShadowRenderTargetSizeSameWithScreen);
			size += sizeof(mScene_ShadowRenderTargetSize);
		}
	}
	else
	{
		size += PX2_BOOLSIZE(mIsShowHelpNode);

		size += PX2_BOOLSIZE(mIsScene_UseBloom);
		size += PX2_BOOLSIZE(mIsScene_BloomRenderTargetSizeSameWithScreen);
		size += sizeof(mScene_BloomRenderTargetSize);
		size += sizeof(mScene_BloomBrightWeight);

		size += sizeof(mScene_BloomBlurDeviation);
		size += sizeof(mScene_BloomBlurWeight);
		size += sizeof(mScene_BloomWeight);

		size += PX2_BOOLSIZE(mIsScene_UseShadowMap);
		size += PX2_BOOLSIZE(mIsScene_ShadowRenderTargetSizeSameWithScreen);
		size += sizeof(mScene_ShadowRenderTargetSize);
	}

	return size;
}
//----------------------------------------------------------------------------