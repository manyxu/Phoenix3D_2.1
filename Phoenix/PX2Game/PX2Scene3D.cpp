/*
*
* 文件名称	：	PX2Scene3D.cpp
*
*/

#include "PX2Scene3D.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2Interpolate.hpp"
#include "PX2SkyActor.hpp"
#include "PX2EffectActor.hpp"
#include "PX2SoundActor.hpp"
#include "PX2UIManager.hpp"
#include "PX2Character.hpp"
using namespace PX2;
using namespace std;

PX2_IMPLEMENT_RTTI(PX2, Scene, Scene3D);
PX2_IMPLEMENT_STREAM(Scene3D);
PX2_IMPLEMENT_FACTORY(Scene3D);

//----------------------------------------------------------------------------
Scene3D::Scene3D ()
	:
mBakeSizeType(BST_NORMAL),
mIsUseLightTexture(false)
{
	GraphicsRoot::GetSingleton().ClearAllLights();

	mDefaultARActor = new0 AmbientRegionActor();
	mDefaultARActor->SetName("DefaultAmibient");
	AddActor(mDefaultARActor);

	SkySphere *skySphere = new0 SkySphere();
	SkyActor *skyActor = new0 SkyActor(skySphere);
	skyActor->SetName("DefaultSky");
	AddActor(skyActor);
}
//----------------------------------------------------------------------------
Scene3D::~Scene3D ()
{
	mDefaultARActor = 0;
}
//----------------------------------------------------------------------------
static AVector AnglesToDirection(float angle0, float angle1)
{
	return AVector(Mathf::Cos(angle1)*Mathf::Cos(angle0), 
		-Mathf::Cos(angle1)*Mathf::Sin(angle0), -Mathf::Sin(angle1));
}
//-----------------------------------------------------------------------------
void Scene3D::Update (double appSeconds, double elapsedSeconds)
{
	Scene::Update(appSeconds, elapsedSeconds);
}
//----------------------------------------------------------------------------
void Scene3D::OnAddedActor (Actor *actor)
{
	if (actor->IsDerived(TerrainActor::TYPE))
	{
		mTerrainActor = DynamicCast<TerrainActor>(actor);
	}
}
//----------------------------------------------------------------------------
void Scene3D::ShowHelpMovables (bool show)
{
	for (int i=0; i<(int)mActors.size(); i++)
	{
		if (mActors[i])
		{
			mActors[i]->ShowHelpMovable(show);
		}
	}
}
//----------------------------------------------------------------------------
void Scene3D::SetUseLightTexture (bool use)
{
	mIsUseLightTexture = use;

	for (int i=0; i<GetNumActors(); i++)
	{
		Actor *actor = GetActor(i);
		EffectActor *ea = DynamicCast<EffectActor>(actor);
		SkyActor *skya = DynamicCast<SkyActor>(actor);
		SoundActor *sa = DynamicCast<SoundActor>(actor);
		CameraActor *ca = DynamicCast<CameraActor>(actor);
		AmbientRegionActor *aa = DynamicCast<AmbientRegionActor>(actor);
		
		if (ea)
		{
		}
		else if (skya)
		{
		}
		else if (sa)
		{
		}
		else if (ca)
		{
		}
		else if (aa)
		{
		}
		else if (actor)
		{
			actor->SetUseLightTexture(use);
		}
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void Scene3D::RegistProperties ()
{
	Scene::RegistProperties();

	AddPropertyClass("Scene3D");

	std::vector<std::string> bakeSizeTypes;
	bakeSizeTypes.push_back("BST_NORMAL");
	bakeSizeTypes.push_back("BST_NORMALOVER2");
	bakeSizeTypes.push_back("BST_NORMALOVER4");

	AddPropertyEnum("BakeSizeType", GetBakeSizeType(), bakeSizeTypes);
}
//----------------------------------------------------------------------------
void Scene3D::OnPropertyChanged (const PropertyObject &obj)
{
	Scene::OnPropertyChanged(obj);

	if ("BakeSizeType" == obj.Name)
	{
		SetBakeSizeType((BakeSizeType)PX2_ANY_AS(obj.Data, int));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称支持
//----------------------------------------------------------------------------
Object* Scene3D::GetObjectByName (const std::string& name)
{
	Object* found = Scene::GetObjectByName(name);

	if (found)
	{
		return found;
	}

	PX2_GET_OBJECT_BY_NAME(mSceneNode, name, found);

	const int numActors = (int)mActors.size();
	for (int i=0; i<numActors; ++i)
	{
		PX2_GET_OBJECT_BY_NAME(mActors[i], name, found);
	}

	return 0;
}
//----------------------------------------------------------------------------
void Scene3D::GetAllObjectsByName (const std::string& name,
	std::vector<Object*>& objects)
{
	Scene::GetAllObjectsByName(name, objects);

	PX2_GET_ALL_OBJECTS_BY_NAME(mSceneNode, name, objects);

	const int numActors = (int)mActors.size();
	for (int i = 0; i < numActors; ++i)
	{
		PX2_GET_ALL_OBJECTS_BY_NAME(mActors[i], name, objects);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Scene3D::Scene3D (LoadConstructor value)
	:
Scene(value),
mBakeSizeType(BST_NORMAL),
mIsUseLightTexture(false)
{
}
//----------------------------------------------------------------------------
void Scene3D::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Scene::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadPointer(mTerrainActor);
	source.ReadPointer(mDefaultARActor);
	source.ReadEnum(mBakeSizeType);
	source.ReadBool(mIsUseLightTexture);

	PX2_END_DEBUG_STREAM_LOAD(Scene3D, source);
}
//----------------------------------------------------------------------------
void Scene3D::Link (InStream& source)
{
	Scene::Link(source);

	GraphicsRoot::GetSingleton().ClearAllLights();

	source.ResolveLink(mTerrainActor);
	source.ResolveLink(mDefaultARActor);
}
//----------------------------------------------------------------------------
void Scene3D::PostLink ()
{
	Scene::PostLink();
}
//----------------------------------------------------------------------------
bool Scene3D::Register (OutStream& target) const
{
	if (Scene::Register(target))
	{
		target.Register(mTerrainActor);
		target.Register(mDefaultARActor);

		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void Scene3D::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Scene::Save(target);
	PX2_VERSION_SAVE(target);

	target.WritePointer(mTerrainActor);
	target.WritePointer(mDefaultARActor);
	target.Write(mBakeSizeType);
	target.WriteBool(mIsUseLightTexture);

	PX2_END_DEBUG_STREAM_SAVE(Scene3D, target);
}
//----------------------------------------------------------------------------
int Scene3D::GetStreamingSize (Stream &stream) const
{
	int size = Scene::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	size += PX2_POINTERSIZE(mTerrainActor);
	size += PX2_POINTERSIZE(mDefaultARActor);
	size += PX2_ENUMSIZE(mBakeSizeType);
	size += PX2_BOOLSIZE(mIsUseLightTexture);

	return size;
}
//----------------------------------------------------------------------------
