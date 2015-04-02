// PX2Edit.cpp

#include "PX2Edit.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2EditEventType.hpp"
#include "PX2Selection.hpp"
#include "PX2Creater.hpp"
#include "PX2RedoUndo.hpp"
#include "PX2Project.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2EngineLoop.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
int Edit::msEditorID = 6001;
//----------------------------------------------------------------------------
Edit::Edit() :
mEditType(ET_SCENE),
mEditAxisMode(EAM_WORLD),
mEditMode(EM_NONE),
mEditMap(0),
mGeoObjFactory(0),
mEditParams(0),
IsAltDown(false),
IsCtrlDown(false),
IsShiftDown(false),
IsKeyDown_W(false),
IsKeyDown_S(false),
IsKeyDown_A(false),
IsKeyDown_D(false),
IsLeftMouseDown(false),
IsRightMouseDown(false),
IsMidMouseDown(false),
mCameraMoveLevel(1),
mCameraMoveSpeedBase(20.0f)
{
	mTimeLineEidt = new0 TimeLineEdit();
	mTerrainEdit = new0 TerrainEdit();

	mHelpNode = new0 Node();
	mHelpNode->AttachChild(mTerrainEdit->GetBrush()->GetRenderable());
}
//----------------------------------------------------------------------------
Edit::~Edit()
{
	delete0(mTimeLineEidt);
	delete0(mTerrainEdit);
}
//----------------------------------------------------------------------------
bool Edit::Initlize()
{
	PX2_GR.SetInEditor(true);

	mEditMap = new0 EditMap();

	mGeoObjFactory = new0 GeoObjFactory();

	mEditParams = new0 EditParams();
	mEditParams->Load("DataEditor/config/editconfig.xml");
	mEditParams->SetCurTheme(mEditParams->GetCurThemeTypeStr());
	
	return true;
}
//----------------------------------------------------------------------------
bool Edit::Ternamate()
{
	mEditParams->Save("DataEditor/config/editconfig.xml");

	if (mEditMap)
	{
		delete0(mEditMap);
	}

	if (mGeoObjFactory)
	{
		delete0(mGeoObjFactory);
	}

	mEditParams = 0;
	
	return true;
}
//----------------------------------------------------------------------------
void Edit::Reset()
{
	mCopyObject = 0;
	mSelectPath_ChildFilenames.clear();
	mSelectPath_ChildPaths.clear();

	PX2_SELECTION.Clear();

	SetEditType(ET_SCENE);
	SetEditMode(EM_NONE);

	PX2_URDOMAN.Clear();
}
//----------------------------------------------------------------------------
void Edit::SetEditType(EditType type)
{
	Project *proj = Project::GetSingletonPtr();
	if (!proj) return;

	if (mEditType == type) return;

	// disable old
	if (ET_SCENE == mEditType) 
	{
	}
	else if (ET_TERRAIN == mEditType)
	{
		mTerrainEdit->SetTerrain(0);
		mTerrainEdit->GetBrush()->GetRenderable()->Show(false);
	}
	else if (ET_UI == mEditType)
	{
	}
	else if (ET_SIMULATE == mEditType)
	{
		PX2_ENGINELOOP.Play(EngineLoop::PT_NONE);
		GetEditMap()->LoadProject(GetEditMap()->GetProjectFilePath().c_str());
	}
	else if (ET_PLAY == mEditType)
	{
		PX2_ENGINELOOP.Play(EngineLoop::PT_NONE);
		GetEditMap()->LoadProject(GetEditMap()->GetProjectFilePath().c_str());
	}

	mEditType = type;

	Scene *scene = proj->GetScene();

	// set new
	if (ET_TERRAIN == type)
	{
		mTerrainEdit->GetBrush()->GetRenderable()->Show(true);
		TerrainActor *terrainActor = scene->GetTerrainActor();
		if (terrainActor) mTerrainEdit->SetTerrain(terrainActor->GetRawTerrain());
	}
	else if (ET_SIMULATE == type || ET_PLAY == type)
	{
		if (proj)
		{
			std::string path = proj->GetSceneFilename();

			Scene *scene = proj->GetScene();
			if (scene && !path.empty())
			{
				PX2_EDIT.GetEditMap()->SaveScene(path.c_str());
			}
		}

		GetEditMap()->SaveProject();

		if (ET_SIMULATE == type)
		{
			PX2_ENGINELOOP.Play(EngineLoop::PT_SIMULATE);
		}
		else if (ET_PLAY == type)
		{
			PX2_ENGINELOOP.Play(EngineLoop::PT_PLAY);
		}
	}

	Event *ent = EditEventSpace::CreateEventX(EditEventSpace::SetEditType);
	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void Edit::SetEditAxisMode(EditAxisMode mode)
{
	mEditAxisMode = mode;

	Event *ent = EditEventSpace::CreateEventX(EditEventSpace::SetEditAxisMode);
	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void Edit::SetEditMode(EditMode mode)
{
	mEditMode = mode;

	Event *ent = EditEventSpace::CreateEventX(EditEventSpace::SetEditMode);
	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
int Edit::GetEditID()
{
	return msEditorID++;
}
//----------------------------------------------------------------------------
void Edit::SetPickPos(const APoint &pos)
{
	mPickPos = pos;

	Event *ent = EditEventSpace::CreateEventX(EditEventSpace::SetPickPos);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
bool Edit::DeleteSelection()
{
	bool deleted = false;

	int numObjs = PX2_SELECTION.GetNumObjects();
	for (int i = 0; i < numObjs; i++)
	{
		Object *obj = PX2_SELECTION.GetObjectAt(i);

		if (PX2_CREATER.RemoveObject(obj))
		{
			deleted = true;
		}
	}

	if (deleted)
	{
		PX2_SELECTION.Clear();
	}

	return deleted;
}
//----------------------------------------------------------------------------
void Edit::SetSelectedResource(const SelectResData &data)
{
	mSelectResData = data;

	Event *ent = EditEventSpace::CreateEventX(EditEventSpace::SelectRes);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void Edit::PasteCopyedObject()
{
	if (!mCopyObject) return;

	Movable *mov = DynamicCast<Movable>(mCopyObject);

	if (mov && mov->GetParent())
	{
		Node *parentNode = DynamicCast<Node>(mov->GetParent());
		if (parentNode)
		{
			MovablePtr newMov = DynamicCast<Movable>(PX2_RM.ShareCopy(mov, true, true, false));	
			PX2_CREATER.AddObject(parentNode, newMov);
		}
	}
}
//----------------------------------------------------------------------------
bool Edit::Import(const char *pathname)
{
	int numObjs = PX2_SELECTION.GetNumObjects();
	if (1 != numObjs) return false;

	Object *selectObj = PX2_SELECTION.GetFirstObject();

	InStream inStream;
	if (inStream.Load(pathname))
	{
		Object *obj = inStream.GetObjectAt(0);
		PX2_CREATER.AddObject(selectObj, obj);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool Edit::Export(PX2::Object *obj, const char *pathname)
{
	if (!obj) return false;

	Controller *ctrl = DynamicCast<Controller>(obj);
	Movable *mov = DynamicCast<Movable>(obj);

	Controlledable *ctrlAble = 0;
	Node *node = 0;

	if (ctrl)
	{
		ctrlAble = ctrl->GetControlledable();
		ctrlAble->DetachController(ctrl);
	}
	else if (mov)
	{
		node = DynamicCast<Node>(mov->GetParent());
		if (node) node->DetachChild(mov);
	}

	OutStream outStream;
	outStream.Insert(obj);
	if (outStream.Save(pathname))
	{
		if (ctrl && ctrlAble)
		{
			ctrlAble->AttachController(ctrl);
		}
		else if (mov && node)
		{
			node->AttachChild(mov);
		}

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void Edit::AnimPlay()
{
	Object *obj = PX2_SELECTION.GetFirstObject();
	Controller *ctrl = DynamicCast<Controller>(obj);
	Controlledable *ctrlable = DynamicCast<Controlledable>(obj);
	Animation *anim = DynamicCast<Animation>(obj);

	if (ctrl)
	{
		ctrl->Play();
	}
	else if (ctrlable)
	{
		ctrlable->Play();
	}
	else if (anim)
	{
		anim->LetCharacterPlay();
	}
}
//----------------------------------------------------------------------------
void Edit::AnimResetPlay()
{
	Object *obj = PX2_SELECTION.GetFirstObject();
	Controller *ctrl = DynamicCast<Controller>(obj);
	Controlledable *ctrlable = DynamicCast<Controlledable>(obj);
	Animation *anim = DynamicCast<Animation>(obj);

	if (ctrl)
	{
		ctrl->ResetPlay();
	}
	else if (ctrlable)
	{
		ctrlable->ResetPlay();
	}
	else if (anim)
	{
		anim->LetCharacterPlay();
	}
}
//----------------------------------------------------------------------------
void Edit::AnimStop()
{
	Object *obj = PX2_SELECTION.GetFirstObject();
	Controller *ctrl = DynamicCast<Controller>(obj);
	Controlledable *ctrlable = DynamicCast<Controlledable>(obj);
	Animation *anim = DynamicCast<Animation>(obj);

	if (ctrl)
	{
		ctrl->Stop();
	}
	else if (ctrlable)
	{
		ctrlable->Stop();
	}
	else if (anim)
	{
		anim->LetCharacterPlay();
	}
}
//----------------------------------------------------------------------------
void Edit::AnimReset()
{
	Object *obj = PX2_SELECTION.GetFirstObject();
	Controller *ctrl = DynamicCast<Controller>(obj);
	Controlledable *ctrlable = DynamicCast<Controlledable>(obj);

	if (ctrl)
	{
		ctrl->Reset();
	}
	else if (ctrlable)
	{
		ctrlable->Reset();
	}
}
//----------------------------------------------------------------------------
bool Edit::IsAnimPlaying()
{
	Object *obj = PX2_SELECTION.GetFirstObject();
	Controller *ctrl = DynamicCast<Controller>(obj);
	Controlledable *ctrlable = DynamicCast<Controlledable>(obj);

	if (ctrl)
	{
		return ctrl->IsPlaying();
	}
	else if (ctrlable)
	{
		ctrlable->IsPlaying();
	}

	return false;
}
//----------------------------------------------------------------------------
void Edit::AnimPlayStop()
{
	if (IsAnimPlaying())
		AnimStop();
	else
		AnimPlay();
}
//----------------------------------------------------------------------------
void Edit::MakeSelectTimeLineEdit()
{
	PX2::Object *obj = PX2_SELECTION.GetFirstObject();

	EffectModule *eftModule = DynamicCast<EffectModule>(obj);
	InterpCurveController *interpCurve = DynamicCast<InterpCurveController>(obj);

	if (eftModule || interpCurve)
	{
		if (!mTimeLineEidt->HasCurveGroup(obj))
		{
			mTimeLineEidt->CreateAddCurveGroup(obj);
		}
	}
}
//----------------------------------------------------------------------------
void Edit::OnFindSelectInProjTree()
{
	Object *obj = PX2_SELECTION.GetFirstObject();
	if (obj)
	{
		Event *ent = EditEventSpace::CreateEventX(EditEventSpace::FindActorInProjectTree);
		PX2_EW.BroadcastingLocalEvent(ent);
	}
}
//----------------------------------------------------------------------------
void Edit::OnFindSelectInResTree()
{
	Object *obj = PX2_SELECTION.GetFirstObject();
	if (obj)
	{
		Event *ent = EditEventSpace::CreateEventX(EditEventSpace::FindActorInResTree);
		PX2_EW.BroadcastingLocalEvent(ent);
	}
}
//----------------------------------------------------------------------------
void Edit::SetPreViewObject(Object *obj)
{
	mPreObject = obj;

	Event *ent = EditEventSpace::CreateEventX(EditEventSpace::SetPreViewObject);
	ent->SetData<PX2::Object*>(obj);
	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------