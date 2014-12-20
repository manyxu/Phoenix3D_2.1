/*
*
* 文件名称	：	PX2UIBagFrame.cpp
*
*/

#include "PX2UIBagFrame.hpp"
#include "PX2UIPicBox.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, UIPushFrame, UIBagFrame);
PX2_IMPLEMENT_STREAM(UIBagFrame);
PX2_IMPLEMENT_FACTORY(UIBagFrame);
PX2_IMPLEMENT_DEFAULT_NAMES(UIPushFrame, UIBagFrame)

//----------------------------------------------------------------------------
UIBagFrame::UIBagFrame ()
	:
mIsBagFrameNeedUpdate(true),
mAlignItemType(ATT_SIZE_WIDTH),
mScrollBack(0),
mScrollFront(0),
mContentLength(0.0f),
mNeedMoveLength(0.0f)
{
	SetSize(100, 100);
	SetCornorSize(10, 10);
	SetAlignItemSize(20, 20);
	SetDirType(DT_Z);
	mCtrl->SetPushTriggerSpeed(10.0f);
	mCtrl->SetMaxVelocity(400.0f);
	mCtrl->SetFriction(100.0f);
}
//----------------------------------------------------------------------------
UIBagFrame::~UIBagFrame()
{
}
//----------------------------------------------------------------------------
void UIBagFrame::SetAlignItemType (AlignItemType type)
{
	mAlignItemType = type;
	mIsBagFrameNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIBagFrame::SetSize (float width, float height)
{
	mSize.Width = width;
	mSize.Height = height;

	mIsBagFrameNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIBagFrame::SetSize (const Sizef &size)
{
	mSize = size;

	mIsBagFrameNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIBagFrame::SetCornorSize (float width, float height)
{
	mCornorSize.Width = width;
	mCornorSize.Height = height;

	mIsBagFrameNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIBagFrame::SetCornorSize (const Sizef &size)
{
	mCornorSize = size;

	mIsBagFrameNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIBagFrame::SetAlignItemSize (float width, float height)
{
	mItemSize.Width = width;
	mItemSize.Height = height;

	mIsBagFrameNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIBagFrame::SetAlignItemSize (const Sizef &size)
{
	mItemSize = size;

	mIsBagFrameNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIBagFrame::SetAlignItemNum (float numWidth, float numHeight)
{
	mAlignItemNum = Float2(numWidth, numHeight);

	mIsBagFrameNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIBagFrame::SetAlignItemNum (const Float2 &itemNum)
{
	mAlignItemNum = itemNum;

	mIsBagFrameNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIBagFrame::UpdateWorldData (double applicationTime)
{
	if (!mCtrl->IsPlaying())
		mCtrl->ResetPlay();

	if (mIsBagFrameNeedUpdate)
	{	
		const APoint &localTrans = LocalTransform.GetTranslate();
		int numValidChild = UpdateAlignItems();

		int numWidth = (int)((mSize.Width-mCornorSize.Width*2.0f)/mItemSize.Width);
		int zIndex = (int)(Mathf::Max(0.0f,(float)(numValidChild-1))/numWidth);
		
		mContentLength = 0.0f;
		mNeedMoveLength = 0.001f;
		if (DT_Z == mDirType)
		{
			mContentLength = mCornorSize.Height*2.0f + 
				(zIndex+1) * mItemSize.Height;
			if (mContentLength > mSize.Height)
				mNeedMoveLength = mContentLength - mSize.Height;
			mCtrl->SetTransScope(AVector(localTrans.X(), localTrans.Y(), localTrans.Z()), 
				AVector(localTrans.X(), localTrans.Y(), localTrans.Z()+mNeedMoveLength));
		}

		float scroolPercent = mSize.Height/mContentLength;

		if (mScrollBack)
		{
			mScrollBack->SetSize(10.0f, mSize.Height);
			mScrollBack->LocalTransform.SetTranslate(APoint(mSize.Width-5.0f, 0.0f, mSize.Height/2.0f));
		}

		if (scroolPercent >= 1.0f)
		{
			if (mScrollFront)
				mScrollFront->Show(false);

			if (mScrollBack)
				mScrollBack->Show(false);
		}
		else
		{
			if (mScrollFront)
				mScrollFront->Show(true);
			if (mScrollBack)
				mScrollBack->Show(true);

			if (mScrollFront)
			{
				mScrollFront->SetSize(10.0f, mSize.Height*scroolPercent);
			}
		}

		mIsBagFrameNeedUpdate = false;
	}

	if (mScrollFront && mScrollFront->IsShow())
	{
		float zPos = LocalTransform.GetTranslate().Z();
		const Sizef &scrollSize = mScrollFront->GetSize();
		float posZ = mSize.Height-(mSize.Height-scrollSize.Height)*(Mathf::FAbs(zPos)/mNeedMoveLength)-scrollSize.Height/2.0f;
		mScrollFront->LocalTransform.SetTranslate(APoint(mSize.Width-5.0f, 0.0f, posZ));
	}
	
	UIPushFrame::UpdateWorldData(applicationTime);
}
//----------------------------------------------------------------------------
int UIBagFrame::UpdateAlignItems ()
{
	int numValidChild = 0;
	for (int i=0; i<GetNumChildren(); i++)
	{
		Movable *mov = GetChild(i);

		if (mov)
		{
			APoint pos;

			if (ATT_SIZE_WIDTH == mAlignItemType)
			{
				int numWidth = (int)((mSize.Width-mCornorSize.Width*2.0f)/mItemSize.Width);
				if (0 == numWidth)
					numWidth = 1;

				int xIndex = numValidChild%numWidth;
				int zIndex = numValidChild/numWidth;

				pos.X() = mCornorSize.Width + mItemSize.Width/2.0f  + mItemSize.Width*xIndex;
				pos.Z() = mSize.Height - mCornorSize.Height - mItemSize.Height/2.0f -  mItemSize.Height*zIndex;
			}
			else if (ATT_NUM_WIDTH == mAlignItemType)
			{
				assertion(0.0f!=mAlignItemNum[0], "");
				assertion(0.0f!=mAlignItemNum[1], "");

				mItemSize.Width = (mSize.Width-mCornorSize.Width*2.0f)/mAlignItemNum[0];
				mItemSize.Height = (mSize.Height-mCornorSize.Height*2.0f)/mAlignItemNum[1];

				int numWidth = (int)mAlignItemNum[0];

				int xIndex = numValidChild%numWidth;
				int zIndex = numValidChild/numWidth;

				pos.X() = mCornorSize.Width + mItemSize.Width/2.0f  + mItemSize.Width*xIndex;
				pos.Z() = mSize.Height - mCornorSize.Height - mItemSize.Height/2.0f -  mItemSize.Height*zIndex;
			}

			mov->LocalTransform.SetTranslate(pos);

			numValidChild++;
		}
	}

	return numValidChild;
}
//----------------------------------------------------------------------------
int UIBagFrame::AttachChild (Movable* child)
{
	mIsBagFrameNeedUpdate = true;

	return UIPushFrame::AttachChild(child);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UIBagFrame::UIBagFrame (LoadConstructor value)
	:
UIPushFrame(value),
mScrollBack(0),
mScrollFront(0),
mContentLength(0),
mNeedMoveLength(0.0f)
{
}
//----------------------------------------------------------------------------
void UIBagFrame::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UIPushFrame::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadBool(mIsBagFrameNeedUpdate);
	source.ReadEnum(mAlignItemType);
	source.ReadAggregate(mSize);
	source.ReadAggregate(mCornorSize);
	source.ReadAggregate(mItemSize);
	source.ReadAggregate(mAlignItemNum);

	PX2_END_DEBUG_STREAM_LOAD(UIBagFrame, source);
}
//----------------------------------------------------------------------------
void UIBagFrame::Link (InStream& source)
{
	UIPushFrame::Link(source);
}
//----------------------------------------------------------------------------
void UIBagFrame::PostLink ()
{
	UIPushFrame::PostLink();
}
//----------------------------------------------------------------------------
bool UIBagFrame::Register (OutStream& target) const
{
	if (UIPushFrame::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void UIBagFrame::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UIPushFrame::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteBool(mIsBagFrameNeedUpdate);
	target.WriteEnum(mAlignItemType);
	target.WriteAggregate(mSize);
	target.WriteAggregate(mCornorSize);
	target.WriteAggregate(mItemSize);
	target.WriteAggregate(mAlignItemNum);

	PX2_END_DEBUG_STREAM_SAVE(UIBagFrame, target);
}
//----------------------------------------------------------------------------
int UIBagFrame::GetStreamingSize (Stream &stream) const
{
	int size = UIPushFrame::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_BOOLSIZE(mIsBagFrameNeedUpdate);
	size += PX2_ENUMSIZE(mAlignItemType);
	size += sizeof(mSize);
	size += sizeof(mCornorSize);
	size += sizeof(mItemSize);
	size += sizeof(mAlignItemNum);

	return size;
}
//----------------------------------------------------------------------------