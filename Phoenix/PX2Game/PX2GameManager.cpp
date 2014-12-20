/*
*
* ÎÄ¼þÃû³Æ	£º	PX2GameManager.cpp
*
*/

#include "PX2GameManager.hpp"
#include "PX2XMLData.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2AccoutManager.hpp"
#include "PX2AddingManager.hpp"
#include "PX2DeletingManager.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2LogicManager.hpp"
#include "PX2SoundManager.hpp"
#include "PX2Project.hpp"
#include "PX2Scene3D.hpp"
#include "PX2Animation3DSkeleton.hpp"
#include "PX2ActorPicker.hpp"
#include "PX2Float2.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
GameManager::GameManager ()
	:
mBoostWidth(0),
mBoostHeight(0),
mIsPlaying(false)
{
	AccoutManager *am = new0 AccoutManager();
	PX2_UNUSED(am);

	AddingManager *adm = new0 AddingManager();
	PX2_UNUSED(adm);

	DeletingManager *dm = new0 DeletingManager();
	PX2_UNUSED(dm);

	LogicManager *lm = new0 LogicManager();
	PX2_UNUSED(lm);

	SoundManager *sm = new0 SoundManager();
	PX2_UNUSED(sm);

	mGameViewAdjustType = GAVT_H_CENTER | GAVT_V_CENTER;

	mPlayMode = PM_SIMPLE;

	VertexFormat *vf = VertexFormat::Create(1,
		VertexFormat::AU_POSITION, VertexFormat::AT_FLOAT3, 0);

	StandardMesh stdMesh(vf);
	mXYPlane = stdMesh.Rectangle(4, 4, 1000.0f, 1000.0f);
	mXYPlane->UpdateModelSpace(Renderable::GU_MODEL_BOUND_ONLY);
	mXYPlane->WorldTransformIsCurrent = true;
	mXYPlane->Update(0.0f);

	mCamCtrlModule = new0 CamCtrlModule ();
	mCamCtrlModule->SetName("CamCtrlModule");
}
//----------------------------------------------------------------------------
GameManager::~GameManager ()
{
	mXYPlane = 0;
	mMainCharacter = 0;
	mCamCtrlModule = 0;

	SoundManager *sm = SoundManager::GetSingletonPtr();
	if (sm)
	{
		delete0(sm);
		SoundManager::Set(0);
	}

	LogicManager *lm = LogicManager::GetSingletonPtr();
	if (lm)
	{
		delete0(lm);
		LogicManager::Set(0);
	}

	AccoutManager *am  = AccoutManager::GetSingletonPtr();
	if (am)
	{
		delete0(am);
		AccoutManager::Set(0);
	}

	AddingManager *adm = AddingManager::GetSingletonPtr();
	if (adm)
	{
		delete0(adm);
		AddingManager::Set(0);
	}

	DeletingManager *dm = DeletingManager::GetSingletonPtr();
	if (dm)
	{
		delete0(dm);
		DeletingManager::Set(0);
	}
}
//----------------------------------------------------------------------------
void GameManager::SetMainCharacter (Character *chara)
{
	mMainCharacter = chara;
}
//----------------------------------------------------------------------------
Character *GameManager::CreateEngineDefaultCharacter ()
{
	Character *chara = new0 Character();
	chara->SetMovableFilename("Data/engine/actor/model.PX2OF", true);

	Animation3DSkeleton *as_stand = new0 Animation3DSkeleton("stand", "");
	as_stand->SetFilename("Data/engine/actor/anim_stand.PX2OF");
	as_stand->SetNormalTime(1.1f);
	as_stand->SetTime(1.1f);
	as_stand->SetFrequency(1.0f);
	as_stand->SetPlayOnce(false);
	chara->AddAnim(as_stand);

	Animation3DSkeleton *as_run = new0 Animation3DSkeleton("run", "");
	as_run->SetFilename("Data/engine/actor/anim_run.PX2OF");
	as_run->SetNormalTime(1.1f);
	as_run->SetTime(1.1f);
	as_run->SetFrequency(1.0f);
	as_run->SetPlayOnce(false);
	chara->AddAnim(as_run);

	return chara;
}
//----------------------------------------------------------------------------
void GameManager::Update (double appSeconds, double elapsedSeconds)
{
	Project *proj = Project::GetSingletonPtr();
	if (!proj)
		return;

	PX2_AM.Update((float)appSeconds, (float)elapsedSeconds);

	AddingManager *adm = AddingManager::GetSingletonPtr();
	if (adm)
	{
		adm->Update(appSeconds, elapsedSeconds);
	}

	DeletingManager *dm = DeletingManager::GetSingletonPtr();
	if (dm)
	{
		dm->Update(appSeconds, elapsedSeconds);
	}

	SoundManager *sm = SoundManager::GetSingletonPtr();
	if (sm)
	{
		sm->Update(appSeconds, elapsedSeconds);
	}

	if (mIsPlaying)
	{
		Scene *scene = PX2_PROJ.GetScene();
		if (scene)
		{
			CameraActor *cameraActor = scene->GetCameraActor();
			mCamCtrlModule->SetCameraActor(cameraActor);
			mCamCtrlModule->SetCenterActor(mMainCharacter);

			mCamCtrlModule->Update(appSeconds, elapsedSeconds);
		}
	}
}
//----------------------------------------------------------------------------
bool GameManager::LoadBoost (const char *filename)
{
	XMLData data;

	int bufferSize = 0;
	char *buffer = 0;
	ResourceManager::GetSingleton().LoadBuffer(filename, bufferSize, buffer);

	if (!buffer || bufferSize==0)
		return false;

	if (data.LoadBuffer(buffer, bufferSize))
	{
		data.GetNodeByPath("config.var").AttribToInt("width", mBoostWidth);
		data.GetNodeByPath("config.var").AttribToInt("height", mBoostHeight);
		mProjectPath = data.GetNodeByPath("play.var").AttributeToString("projectpath");

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool GameManager::WirteBoost (const char *filename, int boostWidth, 
	int boostHeight)
{
	mBoostWidth = boostWidth;
	mBoostHeight = boostHeight;

	XMLData data;

	data.Create();
	
	XMLNode boostNode = data.NewChild("boost");
	boostNode.SetAttributeString("name", "boost");

	XMLNode configNode = boostNode.NewChild("config");

	XMLNode varNode_config = configNode.NewChild("var");
	varNode_config.SetAttributeInt("width", boostWidth);
	varNode_config.SetAttributeInt("height", boostHeight);

	XMLNode playNode = boostNode.NewChild("play");
	XMLNode varNode_play = playNode.NewChild("var");
	varNode_play.SetAttributeString("projectpath", mProjectPath);

	return data.SaveFile(filename);
}
//----------------------------------------------------------------------------
void GameManager::SetGameViewAdjustType (int types)
{
	mGameViewAdjustType = types;
}
//----------------------------------------------------------------------------
Rectf GameManager::CalGameViewRect (float screenWidth, float screenHeight)
{
	if (!Project::GetSingletonPtr())
		return Rectf();

	int projWidth = PX2_PROJ.GetWidth();
	int projHeight = PX2_PROJ.GetHeight();

	float widthOverHeight = screenWidth/screenHeight;
	float projWidthOverHeight = (float)projWidth/(float)projHeight;

	float gameViewWidth = 0.0f;
	float gameViewHeight = 0.0f;
	float offsetX = 0.0f;
	float offsetY = 0.0f;

	int types = GameManager::GetSingleton().GetGameViewAjustType();

	if (widthOverHeight > projWidthOverHeight)
	{
		gameViewWidth = screenHeight * projWidthOverHeight;
		gameViewHeight = screenHeight;

		offsetY = 0.0f;

		if (0 != (GameManager::GAVT_H_LEFT&types))
		{
			offsetX = 0.0f;
		}
		else if (0 != (GameManager::GAVT_H_CENTER&types))
		{
			offsetX = (screenWidth - gameViewWidth)/2.0f;
		}
		else if (0 != (GameManager::GAVT_H_RIGHT&types))
		{
			offsetX = screenHeight - gameViewWidth;
		}
	}
	else
	{
		gameViewWidth = screenWidth;
		gameViewHeight = screenWidth / projWidthOverHeight;

		offsetX = 0.0f;

		if (0 != (GameManager::GAVT_V_BUTTON&types))
		{
			offsetY = 0.0f;
		}
		else if (0 != (GameManager::GAVT_V_CENTER&types))
		{
			offsetY = (screenHeight - gameViewHeight)/2.0f;
		}
		else if (0 != (GameManager::GAVT_V_TOP&types))
		{
			offsetY = screenHeight - gameViewHeight;
		}
	}

	Rectf rect(offsetX, offsetY, offsetX+gameViewWidth, offsetY+gameViewHeight);

	return rect;
}
//----------------------------------------------------------------------------
bool GameManager::GetSceneDownPos (Scene *scene, const APoint &curPos,
	APoint &lastPos)
{
	Picker picker;

	APoint orgin = curPos;
	orgin.Z() += 10000.0f;
	AVector dir = -AVector::UNIT_Z;
	picker.Execute(scene->GetSceneNode(), orgin, dir, 0.0f,
		Mathf::MAX_REAL);

	if ((int)picker.Records.size() > 0)
	{
		PickRecord pickRecord = picker.GetClosestToZero();

		lastPos = orgin + dir * pickRecord.T;

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool GameManager::GetSceneTerrainDownPos (Scene *scene, const APoint &curPos, 
	APoint &lastPos)
{
	Scene3D *scene3D = DynamicCast<Scene3D>(scene);
	if (!scene3D)
		return false;

	TerrainActor *terrainActor = scene3D->GetTerrainActor();
	if (!terrainActor)
		return false;

	RawTerrain *terrain = terrainActor->GetRawTerrain();
	if (!terrain)
		return false;

	Picker picker;

	AVector dir = -AVector::UNIT_Z;
	APoint orgin = curPos;
	orgin.Z() += 10000.0f;

	picker.Execute(terrain, orgin, dir, 0.0f, Mathf::MAX_REAL);
	if ((int)picker.Records.size() > 0)
	{
		PickRecord pickRecord = picker.GetClosestToZero();

		lastPos = orgin + dir * pickRecord.T;

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool GameManager::GetSceneDownPos (Scene *scene, Actor *actor, 
	APoint &lastPos)
{
	const APoint &curPos = actor->GetPosition();
	bool isPickable = actor->IsPickable();

	actor->SetPickable(false);

	bool result = GetSceneDownPos(scene, curPos, lastPos);

	actor->SetPickable(isPickable);

	return result;
}
//----------------------------------------------------------------------------
bool GameManager::GetSceneTerrainDownPos (Scene *scene, Actor *actor,
	APoint &lastPos)
{
	const APoint &curPos = actor->GetPosition();
	bool isPickable = actor->IsPickable();

	actor->SetPickable(false);

	bool result = GetSceneTerrainDownPos(scene, curPos, lastPos);

	actor->SetPickable(isPickable);

	return result;
}
//----------------------------------------------------------------------------
bool GameManager::ScenePick (Movable *mov, const Float2 &screenPos, 
	APoint &lastPos)
{
	Renderer *renderer = Renderer::GetDefaultRenderer();
	if (!renderer)
		return false;

	CameraPtr beforeCamera = renderer->GetCamera();

	Scene *scene = PX2_PROJ.GetScene();
	renderer->SetCamera(scene->GetCameraActor()->GetCamera());

	const Rectf &rect = GraphicsRoot::GetSingleton().GetRect();
	if (!rect.IsEmpty()) 
		renderer->SetViewport((int)rect.Left, (int)rect.Bottom,
		(int)rect.Width(), (int)rect.Height());

	APoint origin;
	AVector dir;
	renderer->GetPickRay((int)screenPos[0], (int)screenPos[1], origin, dir);

	Picker picker;
	picker.Execute(mov, origin, dir, 0.0f, Mathf::MAX_REAL);

	if ((int)picker.Records.size() > 0)
	{
		PickRecord pickRecord = picker.GetClosestToZero();
		lastPos = origin + dir * pickRecord.T;

		renderer->SetCamera(beforeCamera);

		return true;
	}

	renderer->SetCamera(beforeCamera);

	return false;
}
//----------------------------------------------------------------------------
bool GameManager::ScenePick (Scene *scene, const Float2 &screenPos, 
	APoint &lastPos, Actor* &lastActor)
{
	Renderer *renderer = Renderer::GetDefaultRenderer();
	if (!renderer)
		return false;

	CameraPtr beforeCamera = renderer->GetCamera();

	renderer->SetCamera(scene->GetCameraActor()->GetCamera());

	const Rectf &rect = GraphicsRoot::GetSingleton().GetRect();
	if (!rect.IsEmpty()) 
		renderer->SetViewport((int)rect.Left, (int)rect.Bottom,
		(int)rect.Width(), (int)rect.Height());

	APoint origin;
	AVector dir;
	renderer->GetPickRay((int)screenPos[0], (int)screenPos[1], origin, dir);

	ActorPicker actorPicker;
	actorPicker.Execute(scene, origin, dir, 0.0f, Mathf::MAX_REAL);

	if ((int)actorPicker.Records.size() > 0)
	{
		ActorPickRecord pickRecord = actorPicker.GetClosestToZero();

		lastActor = pickRecord.Intersected;
		lastPos = origin + dir*pickRecord.T;

		renderer->SetCamera(beforeCamera);

		return true;
	}

	renderer->SetCamera(beforeCamera);

	return false;
}
//----------------------------------------------------------------------------
void GameManager::Play (bool play)
{
	mIsPlaying = play;
}
//----------------------------------------------------------------------------
bool GameManager::TouchMoved (const InputEventData &data)
{
	if (!mIsPlaying)
		return false;

	if (0 != data.ViewID)
		return false;

	if (!InputEventHandler::TouchMoved(data))
		return false;

	return true;
}
//----------------------------------------------------------------------------
bool GameManager::TouchPressed (const InputEventData &data)
{
	if (!mIsPlaying)
		return false;

	if (0 != data.ViewID)
		return false;

	if (!InputEventHandler::TouchPressed(data))
		return false;

	Scene *scene = PX2_PROJ.GetScene();
	if (scene)
	{
		APoint pickedPos;
		Actor *pickedActor = 0;
		if (ScenePick(scene, 
			Float2((float)data.TState.X.Absoulate, (float)data.TState.Y.Absoulate), pickedPos, 
			pickedActor))
		{
			if (pickedActor)
			{
				pickedActor->OnTouchPressed(pickedPos);
			}
		}
		else
		{
			if (mMainCharacter)
			{
				mXYPlane->WorldTransform.SetTranslate(mMainCharacter->GetPosition());
				mXYPlane->Update(0.0f);
			}

			if (ScenePick(mXYPlane, Float2((float)data.TState.X.Absoulate, (float)data.TState.Y.Absoulate), pickedPos))
			{
				if (mMainCharacter)
					mMainCharacter->GoTo(pickedPos);
			}
		}
	}

	return true;
}
//----------------------------------------------------------------------------
bool GameManager::TouchReleased (const InputEventData &data)
{
	if (!mIsPlaying)
		return false;

	if (0 != data.ViewID)
		return false;

	if (!InputEventHandler::TouchReleased(data))
		return false;

	Scene *scene = PX2_PROJ.GetScene();
	if (scene)
	{
		APoint pickedPos;
		Actor *pickedActor = 0;
		if (ScenePick(scene, 
			Float2((float)data.TState.X.Absoulate, (float)data.TState.Y.Absoulate), pickedPos, 
			pickedActor))
		{
			if (pickedActor)
			{
				pickedActor->OnTouchReleased(pickedPos);
			}
		}
		else
		{
			if (mMainCharacter)
			{
				mXYPlane->WorldTransform.SetTranslate(mMainCharacter->GetPosition());
				mXYPlane->Update(0.0f);
			}
		}
	}

	return true;
}
//----------------------------------------------------------------------------
bool GameManager::TouchCancelled (const InputEventData &data)
{
	if (!mIsPlaying)
		return false;

	if (0 != data.ViewID)
		return false;

	if (!InputEventHandler::TouchCancelled(data))
		return false;

	return true;
}
//----------------------------------------------------------------------------
void GameManager::LogCurMemory (const std::string &tag)
{
#ifdef PX2_USE_MEMORY
	double toM = 1024.0*1024.0;
	double cTB = (double)Memory::GetCurTotalBytes();
	double cTM = cTB/toM;
	PX2_LOG_INFO("%s->memory: %d bytes(%.1lf m)", tag.c_str(), (int)cTB, 
		(float)cTM);
#else
#endif
}
//----------------------------------------------------------------------------