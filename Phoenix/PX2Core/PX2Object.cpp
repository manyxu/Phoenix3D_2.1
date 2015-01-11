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
Object::Object ()
	:
mReadedVersion(0),
mCurStream(NULL),
mIsNameChangeable(true)
{
	mEventHandler = new0 EventHandler();
}
//----------------------------------------------------------------------------
Object::~Object ()
{
	if (!mEventHandler->IsInWorld())
		GoOutEventWorld();
}
//----------------------------------------------------------------------------