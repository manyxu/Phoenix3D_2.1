// PX2UIPaintManager.cpp

#include "PX2UIPaintManager.hpp"
using namespace PX2;

<<<<<<< HEAD
UIPaintManager::UIPaintManager() :
mIsResizeNeeded(false)
=======
UIPaintManager::UIPaintManager()
>>>>>>> d7d7322973c15255a2595ab89885b4ef0270c6ca
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
<<<<<<< HEAD
//----------------------------------------------------------------------------
const Float2 &UIPaintManager::GetMousePos() const
{
	return mLastMousePos;
}
//----------------------------------------------------------------------------
void UIPaintManager::SetMinMaxInfo(int cx, int cy)
{
	assertion(cx>=0 && cy>=0, "should bigger than 0");

	mMinSize.Width = cx;
	mMinSize.Height = cy;
}
=======
>>>>>>> d7d7322973c15255a2595ab89885b4ef0270c6ca
//----------------------------------------------------------------------------