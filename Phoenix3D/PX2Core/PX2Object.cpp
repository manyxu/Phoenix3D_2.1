/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Object.cpp
*
*/

#include "PX2Object.hpp"
#include "PX2StringHelp.hpp"
#include "PX2EventHandler.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
Object::Object () :
mIsEnable(true),
mReadedVersion(0),
mCurStream(NULL),
mIsNameChangeable(true),
mID(0)
{
	mEventHandler = new0 EventHandler();
}
//----------------------------------------------------------------------------
Object::~Object ()
{
	if (mEventHandler->IsInWorld())
		GoOutEventWorld();
}
//----------------------------------------------------------------------------
void Object::Enable(bool enable)
{
	mIsEnable = enable;
}
//----------------------------------------------------------------------------
bool Object::IsEnable() const
{
	return mIsEnable;
}
//----------------------------------------------------------------------------