// PX2UIPaintManager.cpp

#include "PX2UIPaintManager.hpp"
#include "PX2Memory.hpp"

#ifdef PX2_PLATFORM_WINDOWS
#include "PX2UIPaintManager_Win.hpp"
#endif

using namespace PX2;

//----------------------------------------------------------------------------
UIPaintManager::UIPaintManager() :
mIsResizeNeeded(false),
mPlatformData(0)
{
}
//----------------------------------------------------------------------------
UIPaintManager::~UIPaintManager()
{

}
//----------------------------------------------------------------------------
UIPaintManager *UIPaintManager::Create()
{
#ifdef PX2_PLATFORM_WINDOWS
	return new0 UIPaintManager_Win();
#endif
}
//----------------------------------------------------------------------------
void UIPaintManager::SetPlatformData(void *data)
{
	mPlatformData = data;
}
//----------------------------------------------------------------------------
void UIPaintManager::Init()
{

}
//----------------------------------------------------------------------------
void UIPaintManager::Invalidate(const Rectf &rcItem)
{
	PX2_UNUSED(rcItem);
}
//----------------------------------------------------------------------------
const Float2 &UIPaintManager::GetMousePos() const
{
	return mLastMousePos;
}
//----------------------------------------------------------------------------
void UIPaintManager::SetMinMaxInfo(int cx, int cy)
{
	assertion(cx>=0 && cy>=0, "should bigger than 0");

	mMinSize.Width = (float)cx;
	mMinSize.Height = (float)cy;
}
//----------------------------------------------------------------------------
void UIPaintManager::Run()
{
}
//----------------------------------------------------------------------------