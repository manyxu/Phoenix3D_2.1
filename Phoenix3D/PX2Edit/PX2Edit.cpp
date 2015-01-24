// PX2Edit.cpp

#include "PX2Edit.hpp"
#include "PX2UIManager.hpp"
#include "PX2GraphicsRoot.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
int Edit::msEditorID = 6001;
//----------------------------------------------------------------------------
Edit::Edit() :
mEditMap(0)
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
	
	return true;
}
//----------------------------------------------------------------------------
bool Edit::Ternamate()
{
	if (mEditMap)
	{
		delete0(mEditMap);
	}
	
	return true;
}
//----------------------------------------------------------------------------
int Edit::GetEditID()
{
	return msEditorID++;
}
//----------------------------------------------------------------------------