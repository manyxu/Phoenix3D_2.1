// PX2EngineLoop.cpp

#include "PX2EngineLoop.hpp"
#include "PX2Time.hpp"
#include "PX2LuaManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
EngineLoop::EngineLoop() :
mTimerMan(0),
mEventWorld(0),
mLanguageMan(0),
mRoot(0),
mIMEDisp(0),
mResMan(0),
mScriptMan(0),
mFontMan(0),
mADMan(0),
mUIManager(0),
mAccoutManager(0),

mIsInBackground(false),

mAppTime(0),
mLastAppTime(0),
mElapsedTime(0)
{
}
//----------------------------------------------------------------------------
EngineLoop::~EngineLoop()
{
}
//----------------------------------------------------------------------------