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

	CameraActor *camActor = new0 CameraActor();
	AttachChild(camActor);
	camActor->LocalTransform.SetTranslate(APoint(0.0f, -5.0f, 1.0f));

	SetUseCameraActor(camActor);
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
	}

	return Node::AttachChild(child);
}
//----------------------------------------------------------------------------
int Scene::DetachChild(Movable* child)
{
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

	source.ReadPointer(mCameraActor);

	PX2_END_DEBUG_STREAM_LOAD(Scene, source);
}
//----------------------------------------------------------------------------
void Scene::Link(InStream& source)
{
	Node::Link(source);

	if (mCameraActor)
		source.ResolveLink(mCameraActor);
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
		target.Register(mCameraActor);
		
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

	target.WritePointer(mCameraActor);

	PX2_END_DEBUG_STREAM_SAVE(Scene, target);
}
//----------------------------------------------------------------------------
int Scene::GetStreamingSize(Stream &stream) const
{
	int size = Node::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_POINTERSIZE(mCameraActor);

	return size;
}
//----------------------------------------------------------------------------