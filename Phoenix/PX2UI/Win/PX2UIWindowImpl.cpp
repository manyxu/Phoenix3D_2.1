// PX2UIWindowImpl.cpp

#include "PX2UIWindowImpl.hpp"
#include "PX2UIWindow.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
UIWindowImpl::UIWindowImpl(UIWindow *window) :
mIsSubclassed(false),
mWindow(window)
{
}
//----------------------------------------------------------------------------
UIWindowImpl::UIWindowImpl() :
mIsSubclassed(false),
mWindow(0)
{
}
//----------------------------------------------------------------------------
UIWindowImpl::~UIWindowImpl()
{
}
//----------------------------------------------------------------------------