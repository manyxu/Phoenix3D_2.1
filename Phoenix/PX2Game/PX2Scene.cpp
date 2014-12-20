/*
*
* 文件名称	：	PX2Scene.cpp
*
*/

#include "PX2Scene.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2Interpolate.hpp"
#include "PX2SkyActor.hpp"
#include "PX2Renderer.hpp"
#include "PX2GameEventType.hpp"
#include "PX2Character.hpp"
#include "PX2SoundActor.hpp"
#include "PX2GridMap.hpp"
#include "PX2GameManager.hpp"
#include "PX2Project.hpp"
#include "PX2CameraShake.hpp"
using namespace PX2;
using namespace std;

PX2_IMPLEMENT_RTTI(PX2, Gameable, Scene);
PX2_IMPLEMENT_STREAM(Scene);
PX2_IMPLEMENT_FACTORY(Scene);

//----------------------------------------------------------------------------
int Scene::msNextID = 0;
//----------------------------------------------------------------------------
int Scene::GetNextID ()
{
	return ++msNextID;
}
//----------------------------------------------------------------------------
Scene::Scene ()
	:
mUpdateCallback(0),
mSceneID(0),
mLength(100.0f),
mWidth(100.0f),
mSceneManageType(SMT_NONE),
mViewportX(0),
mViewportY(0),
mViewportWidth(-1),
mViewportHeight(-1),
mIsAdjustCamWithViewPort(false),
mIsActorPositionChanged(false),
mCellSpace(0)
{
	mSceneNode = new0 Node();
	
	CameraPtr cam = new0 Camera();
	cam->SetName("DefaultCamera");
	CameraActorPtr camActor = new0 CameraActor(cam);
	camActor->SetName("DefaultCameraActor");
	AddActor(camActor);

	SetCameraActor(camActor);
	camActor->ShowHelpMovable(false);
	camActor->GetCameraNode()->EnableUpdate(true);
}
//----------------------------------------------------------------------------
Scene::~Scene ()
{
	// make out of event space
	for (int i=0; i<(int)mActors.size(); i++)
		mActors[i]->GoOutFromEventWorld();

	mActors.clear(); //需要在MoveMgr之前释放所有Actor之中的MoveUnit
}
//----------------------------------------------------------------------------
void Scene::SetCameraActor (CameraActor *camActor)
{
	mCameraActor = camActor;
	mCamera = camActor->GetCamera();
	mCuller.SetCamera(mCamera);	
	GraphicsRoot::GetSingleton().SetCamera(mCamera);
}
//-----------------------------------------------------------------------------
void Scene::SetSceneLength (float length)
{
	mLength = length;
}
//-----------------------------------------------------------------------------
void Scene::SetSceneWidth (float width)
{
	mWidth = width;
}
//-----------------------------------------------------------------------------
void Scene::SetSceneManageType (SceneManageType type)
{
	mSceneManageType = type;

	mCellSpace = 0;

	if (SMT_OCTREE == mSceneManageType)
	{
	}
	else if (SMT_CELL2D == mSceneManageType)
	{
		mCellSpace = new0 CellSpace(this, mLength, mWidth, 4, 20);
	}
}
//-----------------------------------------------------------------------------
void Scene::GetRangeActors (std::vector<Actor*> &actors, const APoint &center, 
	float radius, bool useActorSelfRadius, const std::bitset<16> &bits)
{
	actors.clear();

	if (SMT_NONE == mSceneManageType)
	{
		for (int i=0; i<GetNumActors(); i++)
		{
			Actor *actor = GetActor(i);
			if (!actor->IsVisible())
				continue;

			const APoint &pos = actor->GetPosition();
			AVector dir = pos - center;
			float lengthSquare = dir.SquaredLength();

			float adjustLength = radius;
			if (useActorSelfRadius)
			{
				adjustLength += actor->GetSelfRadius();
			}

			if (lengthSquare < adjustLength*adjustLength)
			{
				if (actor->IsContainAllBits(bits))
				{
					actors.push_back(actor);
				}
			}
		}
	}
	else
	{
		if (SMT_OCTREE == mSceneManageType)
		{
		}
		else if (SMT_CELL2D == mSceneManageType)
		{
			mCellSpace->CalculateNeighbors(actors, center, radius, 
				useActorSelfRadius, bits);
		}
	}
}
//-----------------------------------------------------------------------------
void Scene::GetRangeActorsExcept (Actor *except, std::vector<Actor*> &actors,
	const APoint &center, float radius, bool useActorSelfRadius,
	const std::bitset<PX2_ACTOR_BS_SIZE> &bits)
{
	GetRangeActors(actors, center, radius, useActorSelfRadius, bits);

	std::vector<Actor*>::iterator it = actors.begin();
	for (; it!=actors.end();)
	{
		if (except == *it)
		{
			it = actors.erase(it);
		}
		else
		{
			it++;
		}
	}
}
//-----------------------------------------------------------------------------
void Scene::Update (double appSeconds, double elapsedSeconds)
{
	static double frame_time = 0;
	frame_time += elapsedSeconds;

	if (mCameraActor)
	{
		const APoint &curPos = mCameraActor->GetPosition();
		SoundSystem::GetSingleton().SetListener(&curPos, 0, 0, 0);
	}

	for (int i=0; i<GetNumActors(); i++)
	{
		Actor *actor = mActors[i];
		Movable *mov = actor->GetMovable();
		if (mov && !mov->GetParent())
		{
			mSceneNode->AttachChild(mov);
		}

		actor->Update(appSeconds, elapsedSeconds);//elapsedSeconds);
	}

	// Scene
	mSceneNode->Update(appSeconds, false);

	if (mCameraActor)
	{
		const APoint &curPos = mCameraActor->GetPosition();
		AVector curDir;
		mCameraActor->GetCameraNode()->LocalTransform.GetRotate().GetColumn(1, curDir);

		static bool isBoforePosUpdated = false;
		static AVector lastShakeVec;

		float strength = CameraShake::ShakeCamera(curPos);

		if (strength > 0.0f)
		{
			if (!isBoforePosUpdated)
			{
				isBoforePosUpdated = true;
				lastShakeVec = AVector::ZERO;
			}

			AVector camRandom(Mathf::SymmetricRandom(), Mathf::SymmetricRandom(),
				Mathf::SymmetricRandom());
			camRandom.Normalize();

			AVector randomVec = camRandom * strength;

			APoint pos = curPos - lastShakeVec + randomVec;
			mCameraActor->SetPosition(pos);

			lastShakeVec = randomVec;
		}
		else
		{
			if (isBoforePosUpdated)
			{
				isBoforePosUpdated = false;
				mCameraActor->SetPosition(curPos - lastShakeVec);
			}
		}
	}
	if (mUpdateCallback)
	{
		mUpdateCallback(appSeconds, elapsedSeconds);
	}

	mIsActorPositionChanged = false;
}
//----------------------------------------------------------------------------
void Scene::CallRendererSetViewport ()
{
	float projWidth = (float)PX2_PROJ.GetWidth();
	float projHeight = (float)PX2_PROJ.GetHeight();

	const Rectf &rect = GameManager::GetSingleton().GetGameViewRect();

	float widthScale = rect.Width()/projWidth;
	float heightScale = rect.Height()/projHeight;

	float newX = rect.Left + mViewportX*widthScale;
	float newY = rect.Bottom + mViewportY*heightScale;
	float newWidth = mViewportWidth*widthScale;
	float newHeight = mViewportHeight*heightScale;

	Renderer *defaultRenderer = Renderer::GetDefaultRenderer();
	if (defaultRenderer && -1!=mViewportWidth && -1!=mViewportHeight)
	{
		defaultRenderer->SetViewport((int)newX, (int)newY, (int)newWidth, 
			(int)newHeight);

		if (mIsAdjustCamWithViewPort)
		{
			Camera *camera = defaultRenderer->GetCamera();
			if (camera && camera->IsPerspective())
			{
				float upFovDegrees = 0.0f;
				float aspectRatio = 0.0f;
				float dMin = 0.0f;
				float dMax = 0.0f;
				camera->GetFrustum(upFovDegrees, aspectRatio, dMin, dMax);
				camera->SetFrustum(upFovDegrees,
					(float)mViewportWidth/(float)mViewportHeight,
					dMin, dMax);
			}
		}
	}
}
//----------------------------------------------------------------------------
void Scene::AddActor (Actor *actor)
{
	assertion(actor!=0, "actor must not be 0.");

	if (!actor)
		return;

	if (IsActorIn(actor))
		return;

	mActors.push_back(actor);
	actor->SetScene(this);
	mActorsMap[actor->GetID()] = actor;

	if (SMT_OCTREE == mSceneManageType)
	{
	}
	else if (SMT_CELL2D == mSceneManageType)
	{
		mCellSpace->AddActor(actor);
	}
}
//----------------------------------------------------------------------------
bool Scene::RemoveActor (Actor *actor)
{
	std::vector<ActorPtr>::iterator it = mActors.begin();
	for (; it!=mActors.end(); it++)
	{
		if (*it == actor)
		{
			if (SMT_OCTREE == mSceneManageType)
			{
			}
			else if (SMT_CELL2D == mSceneManageType)
			{
				mCellSpace->RemoveActor(actor);
			}

			SoundActor *soundActor = DynamicCast<SoundActor>(actor);
			if (soundActor)
			{
				soundActor->Stop();
			}

			actor->SetScene(0);
			mActorsMap.erase(actor->GetID());

			mActors.erase(it);

			return true;
		}		
	}

	return false;
}
//----------------------------------------------------------------------------
bool Scene::IsActorIn (Actor *actor)
{
	for (int i=0; i<(int)mActors.size(); i++)
	{
		if (actor == mActors[i])
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
Actor *Scene::GetActor (const std::string &name) const
{
	for (int i=0; i<(int)mActors.size(); i++)
	{
		if (name == mActors[i]->GetName())
			return mActors[i];
	}

	return 0;
}
//----------------------------------------------------------------------------
Actor *Scene::GetActor (int i)
{
	assertion(0<=i && i<(int)mActors.size(), "i should be in range.");

	if (0<=i && i<(int)mActors.size())
	{
		return mActors[i];
	}

	return 0;
}
//----------------------------------------------------------------------------
Actor *Scene::GetActor (PX2::Movable *object)
{
	for (int i=0; i<(int)mActors.size(); i++)
	{
		if (object == mActors[i]->GetMovable())
			return mActors[i];
	}

	return 0;
}
//----------------------------------------------------------------------------
Actor *Scene::GetActorByID (int id)
{
	std::map<int, Actor*>::iterator it = mActorsMap.find(id);
	if (it != mActorsMap.end())
	{
		return it->second;
	}

	return 0;
}
//----------------------------------------------------------------------------
void Scene::OnActorPositionChanged (Actor *actor, const APoint &beforcePos)
{
	PX2_UNUSED(beforcePos);

	mIsActorPositionChanged = true;

	SceneManageType smt = GetSceneManageType();

	if (SMT_OCTREE == smt)
	{
	}
	else if (SMT_CELL2D == smt)
	{
		mCellSpace->UpdateActor(actor);
	}
}
//----------------------------------------------------------------------------
void Scene::CalLights ()
{
	GraphicsRoot::GetSingleton().ClearAllLights();

	for (int i=0; i<GetNumActors(); i++)
	{
		Actor *actor = GetActor(i);
		if (actor)
		{
			actor->CalLights ();
		}
	}
}
//----------------------------------------------------------------------------
void Scene::ShowHelpMovables (bool show)
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
void Scene::ComputeVisibleSet ()
{
	mCuller.SetCamera(GetCameraActor()->GetCamera());
	mCuller.ComputeVisibleSet(GetSceneNode());
	mCuller.ComputeEnvironment();
}
//----------------------------------------------------------------------------
void Scene::DoEnter ()
{
}
//----------------------------------------------------------------------------
void Scene::DoExecute (Event *event)
{
	if (GameEventSpace::IsEqual(event, GameEventSpace::CharacterDie))
	{
	}
	else if (GameEventSpace::IsEqual(event, GameEventSpace::ActorDelete))
	{
		Actor *actor = event->GetData<Actor*>();
		RemoveActor(actor);
	}
}
//----------------------------------------------------------------------------
void Scene::DoLeave ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称支持
//----------------------------------------------------------------------------
Object* Scene::GetObjectByName (const std::string& name)
{
	Object* found = Gameable::GetObjectByName(name);

	if (found)
	{
		return found;
	}

	PX2_GET_OBJECT_BY_NAME(mCameraActor, name, found);

	PX2_GET_OBJECT_BY_NAME(mSceneNode, name, found);

	const int numActors = (int)mActors.size();
	for (int i=0; i<numActors; ++i)
	{
		PX2_GET_OBJECT_BY_NAME(mActors[i], name, found);
	}

	return 0;
}
//----------------------------------------------------------------------------
void Scene::GetAllObjectsByName (const std::string& name,
	std::vector<Object*>& objects)
{
	Gameable::GetAllObjectsByName(name, objects);

	PX2_GET_ALL_OBJECTS_BY_NAME(mCameraActor, name, objects);

	PX2_GET_ALL_OBJECTS_BY_NAME(mSceneNode, name, objects);

	const int numActors = (int)mActors.size();
	for (int i = 0; i < numActors; ++i)
	{
		PX2_GET_ALL_OBJECTS_BY_NAME(mActors[i], name, objects);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------
void Scene::RegistProperties ()
{
	Gameable::RegistProperties();

	AddPropertyClass("Scene");
	AddProperty("SceneID", PT_INT, GetSceneID());

	AddProperty("Length", PT_FLOAT, GetSceneLength());
	AddProperty("Width", PT_FLOAT, GetSceneWidth());

	std::vector<std::string> sceneManageTypes;
	sceneManageTypes.push_back("SMT_NONE");
	sceneManageTypes.push_back("SMT_OCTREE");
	sceneManageTypes.push_back("SMT_CELL2D");
	AddPropertyEnum("SceneManageType", GetSceneManageType(), sceneManageTypes);

	AddProperty("IsAdjustCamWidthViewPort", PT_BOOL, IsAdjustCamWidthViewPort());
	int vXPos = 0;
	int vYPos = 0;
	int vWidth = 0;
	int vHeight = 0;
	GetViewport(vXPos, vYPos, vWidth, vHeight);
	Rectf sceneViewPort = Rectf((float)vXPos, (float)vYPos, (float)vWidth, 
		(float)vHeight);
	AddProperty("SceneViewPort", PT_RECT, sceneViewPort);

	AddProperty("NumActors", PT_INT, GetNumActors(), false);
}
//----------------------------------------------------------------------------
void Scene::OnPropertyChanged (const PropertyObject &obj)
{
	Gameable::OnPropertyChanged(obj);
	
	if ("SceneID" == obj.Name)
	{
		SetSceneID(PX2_ANY_AS(obj.Data, int));
	}
	else if ("SceneManageType" == obj.Name)
	{
		SetSceneManageType((SceneManageType)PX2_ANY_AS(obj.Data, int));
	}
	else if ("Length" == obj.Name)
	{
		SetSceneLength(PX2_ANY_AS(obj.Data, float));
	}
	else if ("Width" == obj.Name)
	{
		SetSceneWidth(PX2_ANY_AS(obj.Data, float));
	}
	else if ("IsAdjustCamWidthViewPort" == obj.Name)
	{
		SetAdjustCamWidthViewPort(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("SceneViewPort" == obj.Name)
	{
		Rectf rect = PX2_ANY_AS(obj.Data, Rectf);
		SetViewPort((int)rect.Left, (int)rect.Bottom, (int)rect.Width(),
			(int)rect.Height());
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Scene::Scene (LoadConstructor value)
	:
Gameable(value),
mUpdateCallback(0),
mSceneID(0),
mLength(100.0f),
mWidth(100.0f),
mSceneManageType(SMT_NONE),
mViewportX(0),
mViewportY(0),
mViewportWidth(-1),
mViewportHeight(-1),
mIsAdjustCamWithViewPort(false),
mIsActorPositionChanged(false),
mCellSpace(0)
{
	mSceneNode = new0 Node();
}
//----------------------------------------------------------------------------
void Scene::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Gameable::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadPointer(mCameraActor);
	source.ReadPointer(mCamera);
	source.Read(mSceneID);
	source.Read(mLength);
	source.Read(mWidth);
	source.ReadEnum(mSceneManageType);
	source.Read(mViewportX);
	source.Read(mViewportY);
	source.Read(mViewportWidth);
	source.Read(mViewportHeight);
	source.ReadBool(mIsAdjustCamWithViewPort);

	int numActors;
	source.Read(numActors);
	if (numActors > 0)
	{
		mActors.resize(numActors);
		source.ReadPointerVV(numActors, &mActors[0]);
	}

	PX2_END_DEBUG_STREAM_LOAD(Scene, source);
}
//----------------------------------------------------------------------------
void Scene::Link (InStream& source)
{
	Gameable::Link(source);

	SetSceneManageType(mSceneManageType);

	source.ResolveLink(mCameraActor);
	source.ResolveLink(mCamera);

	const int numActors = (int)mActors.size();
	for (int i=0; i<numActors; ++i)
	{
		if (mActors[i])
		{
			source.ResolveLink(mActors[i]);
		}
	}
}
//----------------------------------------------------------------------------
void Scene::PostLink ()
{
	Gameable::PostLink();

	const int numActors = (int)mActors.size();
	for (int i=0; i<numActors; ++i)
	{
		if (mActors[i])
		{
			mActors[i]->SetScene(this);

			if (SMT_OCTREE == mSceneManageType)
			{
			}
			else if (SMT_CELL2D == mSceneManageType)
			{
				mCellSpace->AddActor(mActors[i]);
			}
		}
	}

	mCuller.SetCamera(mCamera);
	GraphicsRoot::GetSingleton().SetCamera(mCamera);
}
//----------------------------------------------------------------------------
bool Scene::Register (OutStream& target) const
{
	if (Gameable::Register(target))
	{
		target.Register(mCameraActor);
		target.Register(mCamera);

		const int numActors = (int)mActors.size();
		for (int i = 0; i < numActors; ++i)
		{
			if (mActors[i])
			{
				target.Register(mActors[i]);
			}
		}

		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void Scene::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Gameable::Save(target);
	PX2_VERSION_SAVE(target);

	target.WritePointer(mCameraActor);
	target.WritePointer(mCamera);
	target.Write(mSceneID);
	target.Write(mLength);
	target.Write(mWidth);
	target.WriteEnum(mSceneManageType);
	target.Write(mViewportX);
	target.Write(mViewportY);
	target.Write(mViewportWidth);
	target.Write(mViewportHeight);
	target.WriteBool(mIsAdjustCamWithViewPort);

	const int numActors = (int)mActors.size();
	target.Write(numActors);
	for (int i=0; i<numActors; ++i)
	{
		if (mActors[i])
		{
			target.WritePointer(mActors[i]);
		}
		else
		{
			target.WritePointer((Actor*)0);
		}
	}

	PX2_END_DEBUG_STREAM_SAVE(Scene, target);
}
//----------------------------------------------------------------------------
int Scene::GetStreamingSize (Stream &stream) const
{
	int size = Gameable::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_POINTERSIZE(mCameraActor);
	size += PX2_POINTERSIZE(mCamera);
	size += sizeof(mSceneID);
	size += sizeof(mLength);
	size += sizeof(mWidth);
	size += PX2_ENUMSIZE(mSceneManageType);
	size += sizeof(mViewportX);
	size += sizeof(mViewportY);
	size += sizeof(mViewportWidth);
	size += sizeof(mViewportHeight);
	size += PX2_BOOLSIZE(mIsAdjustCamWithViewPort);

	int numActors = (int)mActors.size();
	size += sizeof(numActors);
	size += numActors*PX2_POINTERSIZE(mActors[0]);

	return size;
}
//----------------------------------------------------------------------------
