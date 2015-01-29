// PX2Edit.cpp

#include "PX2Edit.hpp"
#include "PX2UIManager.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2EditEventType.hpp"
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
	mEditParams->Load("D:\\PX3D\\Bin\\DataEditor\\config\\editConfig.xml");
	
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
void Edit::SetEditType(EditType type)
{
	mEditType = type;
}
//----------------------------------------------------------------------------
void Edit::SetEditMode(EditMode mode)
{
	mEditMode = mode;

	Event *ent = EditEventSpace::CreateEventX(EditEventSpace::SetEditMode);
	ent->SetData<Edit::EditMode>(mEditMode);
	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
int Edit::GetEditID()
{
	return msEditorID++;
}
//----------------------------------------------------------------------------