// PX2Scene.cpp

#include "PX2Scene.hpp"
#include "PX2Project.hpp"
#include "PX2Creater.hpp"
#include "PX2Actor.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Node, Scene);
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
Scene::Scene()
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
}
//----------------------------------------------------------------------------
Scene::~Scene()
{
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
		int id = actor->GetID();
		if (0 != id)
		{
			mActors[actor->GetID()] = actor;
		}

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
		int id = child->GetID();
		if (0 != id)
		{
			std::map<int, ActorPtr>::iterator it = mActors.find(id);
			if (it != mActors.end())
			{
				mActors.erase(it);
			}
		}

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
void Scene::UpdateWorldData(double applicationTime, double elapsedTime)
{
	Node::UpdateWorldData(applicationTime, elapsedTime);
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
}
//----------------------------------------------------------------------------
void Scene::OnPropertyChanged(const PropertyObject &obj)
{
	Node::OnPropertyChanged(obj);

	if ("Size" == obj.Name)
	{
		SetSize(PX2_ANY_AS(obj.Data, Sizef));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Scene::Scene(LoadConstructor value) :
Node(value)
{
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

	return size;
}
//----------------------------------------------------------------------------