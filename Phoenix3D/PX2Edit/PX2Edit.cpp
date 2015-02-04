// PX2Edit.cpp

#include "PX2Edit.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2EditEventType.hpp"
#include "PX2Selection.hpp"
#include "PX2Creater.hpp"
#include "PX2RedoUndo.hpp"
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
}
//----------------------------------------------------------------------------
Edit::~Edit()
{
}
//----------------------------------------------------------------------------
bool Edit::Initlize()
{
	PX2_GR.SetInEditor(true);

	mEditMap = new0 EditMap();

	mGeoObjFactory = new0 GeoObjFactory();

	mEditParams = new0 EditParams();
	mEditParams->Load("DataEditor/config/editConfig.xml");
	
	return true;
}
//----------------------------------------------------------------------------
bool Edit::Ternamate()
{
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