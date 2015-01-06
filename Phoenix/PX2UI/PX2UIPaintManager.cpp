// PX2UIPaintManager.cpp

#include "PX2UIPaintManager.hpp"
using namespace PX2;

UIPaintManager::UIPaintManager() :
mIsResizeNeeded(false)
{
}
//----------------------------------------------------------------------------
UIPaintManager::~UIPaintManager()
{

}
//----------------------------------------------------------------------------
void UIPaintManager::Init()
{

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