// PX2EngineLoop.cpp

#include "PX2EngineLoop.hpp"
#include "PX2Time.hpp"
#include "PX2LuaManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
EngineLoop::EngineLoop() :
mPt_Data(0),

mRendererInput(0),

mTimerMan(0),
mEventWorld(0),
mLanguageMan(0),
mRoot(0),
mIMEDisp(0),
mInputMan(0),
mResMan(0),
mScriptMan(0),
mFontMan(0),
mADMan(0),
mSelection(0),
mCreater(0),
mAccoutManager(0),

mIsInBackground(false),

mAppTime(0),
mLastAppTime(0),
mElapsedTime(0),

mIsDoAdjustScreen(true),
mPlayType(PT_NONE)
{
}
//----------------------------------------------------------------------------
EngineLoop::~EngineLoop()
{
}
//----------------------------------------------------------------------------
void EngineLoop::SetPt_Data(void *data)
{
	mPt_Data = data;
}
//----------------------------------------------------------------------------
void *EngineLoop::GetPt_Data()
{
	return mPt_Data;
}
//----------------------------------------------------------------------------
void EngineLoop::SetPt_Size(const Sizef &size)
{
	mPt_Size = size;
}
//----------------------------------------------------------------------------
const Sizef &EngineLoop::GetPt_Size() const
{
	return mPt_Size;
}
//----------------------------------------------------------------------------