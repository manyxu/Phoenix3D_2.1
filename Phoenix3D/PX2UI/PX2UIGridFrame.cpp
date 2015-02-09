// PX2UIGridFrame.cpp

#include "PX2UIGridFrame.hpp"
#include "PX2UIPicBox.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, UIFrame, UIGridFrame);
PX2_IMPLEMENT_STREAM(UIGridFrame);
PX2_IMPLEMENT_FACTORY(UIGridFrame);
PX2_IMPLEMENT_DEFAULT_NAMES(UIFrame, UIGridFrame)

//----------------------------------------------------------------------------
UIGridFrame::UIGridFrame()
:
mIsBagFrameNeedUpdate(true),
mAlignItemType(ATT_SIZE_WIDTH),
mContentLength(0.0f),
mNeedMoveLength(0.0f)
{
	SetSize(100, 100);
	SetBorderSize(10, 10);
	SetAlignItemSize(20, 20);

	InputPushTransformController *ctrl = CreateAddIPTCtrl();
	ctrl->SetLockDir(AVector::UNIT_Z);
	ctrl->SetPushTriggerSpeed(50.0f);
	ctrl->SetMaxVelocity(400.0f);
	ctrl->SetFriction(200.0f);
}
//----------------------------------------------------------------------------
UIGridFrame::~UIGridFrame()
{
}
//----------------------------------------------------------------------------
void UIGridFrame::OnSizeChanged()
{
	UIFrame::OnSizeChanged();

	mIsBagFrameNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIGridFrame::OnBorderSizeChanged()
{
	UIFrame::OnBorderSizeChanged();

	mIsBagFrameNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIGridFrame::SetAlignItemType(AlignItemType type)
{
	mAlignItemType = type;

	mIsBagFrameNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIGridFrame::SetAlignItemSize(float width, float height)
{
	mItemSize.Width = width;
	mItemSize.Height = height;

	mIsBagFrameNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIGridFrame::SetAlignItemSize(const Sizef &size)
{
	mItemSize = size;

	mIsBagFrameNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIGridFrame::SetAlignItemNum(float numWidth, float numHeight)
{
	mAlignItemNum = Float2(numWidth, numHeight);

	mIsBagFrameNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIGridFrame::SetAlignItemNum(const Float2 &itemNum)
{
	mAlignItemNum = itemNum;

	mIsBagFrameNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIGridFrame::UpdateWorldData(double applicationTime)
{
	if (!mIPTCtrl->IsPlaying()) return;

	if (mIsBagFrameNeedUpdate)
	{
		mIsBagFrameNeedUpdate = false;

		//const APoint &localPos = LocalTransform.GetTranslate();

		int numValidChild = _UpdateAlignItems();

		int numWidth = (int)((mSize.Width - mBorderSize.Width*2.0f) / mItemSize.Width);
		int zIndex = (int)(Mathf::Max(0.0f, (float)(numValidChild - 1)) / numWidth);

		mContentLength = 0.0f;
		mNeedMoveLength = 0.001f;

		mIPTCtrl->SetVelocity(AVector::ZERO);

		if (AVector::UNIT_Z == mIPTCtrl->GetLockDir())
		{
			mContentLength = mBorderSize.Height*2.0f + (zIndex + 1) * mItemSize.Height;
			if (mContentLength > mSize.Height) 
				mNeedMoveLength = mContentLength - mSize.Height;
			
			mIPTCtrl->SetTransScope(AVector::ZERO,
				AVector(0.0f, 0.0f, mNeedMoveLength));
		}
	}

	UIFrame::UpdateWorldData(applicationTime);
}
//----------------------------------------------------------------------------
int UIGridFrame::_UpdateAlignItems()
{
	int numValidChild = 0;
	for (int i = 0; i < GetNumChildren(); i++)
	{
		Movable *mov = GetChild(i);

		if (mov)
		{
			APoint pos;

			if (ATT_SIZE_WIDTH == mAlignItemType)
			{
				int numWidth = (int)((mSize.Width - mBorderSize.Width*2.0f) / mItemSize.Width);
				if (0 == numWidth)
					numWidth = 1;

				int xIndex = numValidChild % numWidth;
				int zIndex = numValidChild / numWidth;

				pos.X() = mBorderSize.Width + mItemSize.Width / 2.0f + mItemSize.Width*xIndex;
				pos.Z() = mSize.Height - mBorderSize.Height - mItemSize.Height / 2.0f - mItemSize.Height*zIndex;
			}
			else if (ATT_NUM_WIDTH == mAlignItemType)
			{
				assertion(0.0f != mAlignItemNum[0], "");
				assertion(0.0f != mAlignItemNum[1], "");

				mItemSize.Width = (mSize.Width - mBorderSize.Width*2.0f) / mAlignItemNum[0];
				mItemSize.Height = (mSize.Height - mBorderSize.Height*2.0f) / mAlignItemNum[1];

				int numWidth = (int)mAlignItemNum[0];

				int xIndex = numValidChild%numWidth;
				int zIndex = numValidChild / numWidth;

				pos.X() = mBorderSize.Width + mItemSize.Width / 2.0f + mItemSize.Width*xIndex;
				pos.Z() = mSize.Height - mBorderSize.Height - mItemSize.Height / 2.0f - mItemSize.Height*zIndex;
			}

			mov->LocalTransform.SetTranslate(pos);

			numValidChild++;
		}
	}

	return numValidChild;
}
//----------------------------------------------------------------------------
int UIGridFrame::AttachChild(Movable* child)
{
	mIsBagFrameNeedUpdate = true;

	return UIFrame::AttachChild(child);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UIGridFrame::UIGridFrame(LoadConstructor value) :
UIFrame(value),
mIsBagFrameNeedUpdate(true),
mAlignItemType(ATT_SIZE_WIDTH),
mContentLength(0.0f),
mNeedMoveLength(0.0f)
{
}
//----------------------------------------------------------------------------
void UIGridFrame::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UIFrame::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadBool(mIsBagFrameNeedUpdate);
	source.ReadEnum(mAlignItemType);
	source.ReadAggregate(mItemSize);
	source.ReadAggregate(mAlignItemNum);

	PX2_END_DEBUG_STREAM_LOAD(UIGridFrame, source);
}
//----------------------------------------------------------------------------
void UIGridFrame::Link(InStream& source)
{
	UIFrame::Link(source);
}
//----------------------------------------------------------------------------
void UIGridFrame::PostLink()
{
	UIFrame::PostLink();
}
//----------------------------------------------------------------------------
bool UIGridFrame::Register(OutStream& target) const
{
	if (UIFrame::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void UIGridFrame::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UIFrame::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteBool(mIsBagFrameNeedUpdate);
	target.WriteEnum(mAlignItemType);
	target.WriteAggregate(mItemSize);
	target.WriteAggregate(mAlignItemNum);

	PX2_END_DEBUG_STREAM_SAVE(UIGridFrame, target);
}
//----------------------------------------------------------------------------
int UIGridFrame::GetStreamingSize(Stream &stream) const
{
	int size = UIFrame::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_BOOLSIZE(mIsBagFrameNeedUpdate);
	size += PX2_ENUMSIZE(mAlignItemType);
	size += sizeof(mItemSize);
	size += sizeof(mAlignItemNum);

	return size;
}
//----------------------------------------------------------------------------