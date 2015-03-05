// PX2Edit.cpp

#include "PX2Edit.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2EditEventType.hpp"
#include "PX2Selection.hpp"
#include "PX2Creater.hpp"
#include "PX2RedoUndo.hpp"
#include "PX2Project.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
int Edit::msEditorID = 6001;
//----------------------------------------------------------------------------
Edit::Edit() :
mEditType(ET_SCENE),
mEditMode(EM_NONE),
mEditMap(0),
mGeoObjFactory(0),
mEditParams(0),
IsAltDown(false),
IsCtrlDown(false),
IsShiftDown(false)
{
	mTimeLineEidt = new0 TimeLineEdit();
}
//----------------------------------------------------------------------------
Edit::~Edit()
{
	delete0(mTimeLineEidt);
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
	PX2_SELECTION.Clear();

	SetEditType(ET_SCENE);
	SetEditMode(EM_NONE);

	PX2_URDOMAN.Clear();
}
//----------------------------------------------------------------------------
void Edit::SetEditType(EditType type)
{
	mEditType = type;

	Event *ent = EditEventSpace::CreateEventX(EditEventSpace::SetEditType);
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

	Actor *actor = DynamicCast<Actor>(mCopyObject);
	Scene *scene = PX2_PROJ.GetScene();

	if (actor && scene)
	{
	}
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