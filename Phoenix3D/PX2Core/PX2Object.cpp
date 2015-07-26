// PX2Object.cpp

#include "PX2Object.hpp"
#include "PX2EventHandlerObject.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
Object::Object () :
mIsEnable(true),
mReadedVersion(0),
mCurStream(NULL),
mIsNameChangeable(true),
mID(0)
{
	mEventHandler = new0 ObjectEventHandler(this);
}
//----------------------------------------------------------------------------
Object::~Object ()
{
	if (mEventHandler->IsInWorld())
		GoOutEventWorld();

	delete0(mEventHandler);
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