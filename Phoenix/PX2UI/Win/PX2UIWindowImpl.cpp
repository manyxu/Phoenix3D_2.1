// PX2UIWindowImpl.cpp

#include "PX2UIWindowImpl.hpp"
#include "PX2UIWindow.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
UIWindowImpl::UIWindowImpl(UIWindow *window) :
mIsSubclassed(false),
mWindow(window),
mClassType(UICS_FRAME)
{
	mClassName = "UIWindow";
}
//----------------------------------------------------------------------------
UIWindowImpl::UIWindowImpl() :
mIsSubclassed(false),
mWindow(0),
mClassType(UICS_FRAME)
{
	mClassName = "UIWindow";
}
//----------------------------------------------------------------------------
UIWindowImpl::~UIWindowImpl()
{
}
//----------------------------------------------------------------------------
void UIWindowImpl::SetClassStyle(UIClassType stype)
{
	mClassType = stype;
}
//----------------------------------------------------------------------------
UIClassType UIWindowImpl::GetClassStype() const
{
	return mClassType;
}
//----------------------------------------------------------------------------
void UIWindowImpl::SetClassName(const std::string &className)
{
	mClassName = className;
}
//----------------------------------------------------------------------------
const std::string &UIWindowImpl::GetClassName() const
{
	return mClassName;
}
//----------------------------------------------------------------------------