// PX2UIFrame.cpp

#include "PX2UIRelativeFrame.hpp"
#include "PX2Time.hpp"
using namespace PX2;
using namespace std;

PX2_IMPLEMENT_RTTI(PX2, UIFrame, UIRelativeFrame);
PX2_IMPLEMENT_STREAM(UIRelativeFrame);
PX2_IMPLEMENT_FACTORY(UIRelativeFrame);

//----------------------------------------------------------------------------
UIRelativeFrame::UIRelativeFrame() :
mPosRelativeType_H(PT_NONE),
mRelativeVal_H(0.0f),
mPosRelativeType_V(PT_NONE),
mRelativeVal_V(0.0f),
mIsRelativeChanged(false)
{
}
//----------------------------------------------------------------------------
UIRelativeFrame::~UIRelativeFrame()
{
}
//----------------------------------------------------------------------------
void UIRelativeFrame::OnSizeChanged()
{
	UIFrame::OnSizeChanged();

	mIsRelativeChanged = true;
}
//----------------------------------------------------------------------------
void UIRelativeFrame::OnBorderSizeChanged()
{
	UIFrame::OnSizeChanged();

	mIsRelativeChanged = true;
}
//----------------------------------------------------------------------------
void UIRelativeFrame::UpdateWorldData(double applicationTime, double elapsedTime)
{
	UIFrame::UpdateWorldData(applicationTime, elapsedTime);

	if (mIsRelativeChanged)
	{
		_UpdateRelative();
	}
}
//----------------------------------------------------------------------------
void UIRelativeFrame::OnParentSizeChanged(const Sizef &parentSize,
	const Sizef &parentBorderSize)
{
	PX2_UNUSED(parentSize);
	PX2_UNUSED(parentBorderSize);

	// pos h
	if (LT_ZERO == mPosRelativeType_H)
	{
		APoint localPos = LocalTransform.GetTranslate();
		localPos.X() = parentBorderSize.Width + mRelativeVal_H;
		LocalTransform.SetTranslate(localPos);
	}
	else if (LT_HALF == mPosRelativeType_H)
	{
		APoint localPos = LocalTransform.GetTranslate();
		localPos.X() = parentSize.Width / 2.0f + mRelativeVal_H;
		LocalTransform.SetTranslate(localPos);
	}
	else if (LT_ONE == mPosRelativeType_H)
	{
		APoint localPos;
		localPos.X() = parentSize.Width - parentBorderSize.Width + mRelativeVal_H;
		LocalTransform.SetTranslate(localPos);
	}

	// pos v
	if (LT_ZERO == mPosRelativeType_V)
	{
		APoint localPos = LocalTransform.GetTranslate();
		localPos.Z() = parentBorderSize.Height + mRelativeVal_V;
		LocalTransform.SetTranslate(localPos);
	}
	else if (LT_HALF == mPosRelativeType_V)
	{
		APoint localPos = LocalTransform.GetTranslate();
		localPos.Z() = parentSize.Height / 2.0f + mRelativeVal_V;
		LocalTransform.SetTranslate(localPos);
	}
	else if (LT_ONE == mPosRelativeType_V)
	{
		APoint localPos = LocalTransform.GetTranslate();
		localPos.Z() = parentSize.Height - parentBorderSize.Height + mRelativeVal_V;
		LocalTransform.SetTranslate(localPos);
	}
}
//----------------------------------------------------------------------------
void UIRelativeFrame::SetRelativeType_H(RelativeType type)
{
	mPosRelativeType_H = type;
	mIsRelativeChanged = true;
}
//----------------------------------------------------------------------------
void UIRelativeFrame::SetRelativeType_V(RelativeType type)
{
	mPosRelativeType_V = type;
	mIsRelativeChanged = true;
}
//----------------------------------------------------------------------------
void UIRelativeFrame::SetRelativeValue_H(float val)
{
	mRelativeVal_H = val;
	mIsRelativeChanged = true;
}
//----------------------------------------------------------------------------
void UIRelativeFrame::SetRelativeValue_V(float val)
{
	mRelativeVal_V = val;
	mIsRelativeChanged = true;
}
//----------------------------------------------------------------------------
void UIRelativeFrame::_UpdateRelative()
{
	for (int i = 0; i < GetNumChildren(); i++)
	{
		UIRelativeFrame *sizeFrame = DynamicCast<UIRelativeFrame>(GetChild(i));
		if (sizeFrame)
		{
			sizeFrame->OnParentSizeChanged(GetSize(), GetBorderSize());
		}
	}

	mIsRelativeChanged = false;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UIRelativeFrame::UIRelativeFrame(LoadConstructor value) :
UIFrame(value),
mPosRelativeType_H(PT_NONE),
mRelativeVal_H(0.0f),
mPosRelativeType_V(PT_NONE),
mRelativeVal_V(0.0f),
mIsRelativeChanged(false)
{
}
//----------------------------------------------------------------------------
void UIRelativeFrame::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UIFrame::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadAggregate(mSize);
	source.ReadAggregate(mBorderSize);

	PX2_END_DEBUG_STREAM_LOAD(UIRelativeFrame, source);
}
//----------------------------------------------------------------------------
void UIRelativeFrame::Link(InStream& source)
{
	UIFrame::Link(source);
}
//----------------------------------------------------------------------------
void UIRelativeFrame::PostLink()
{
	UIFrame::PostLink();
}
//----------------------------------------------------------------------------
bool UIRelativeFrame::Register(OutStream& target) const
{
	return UIFrame::Register(target);
}
//----------------------------------------------------------------------------
void UIRelativeFrame::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UIFrame::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteAggregate(mSize);
	target.WriteAggregate(mBorderSize);

	PX2_END_DEBUG_STREAM_SAVE(UIRelativeFrame, target);
}
//----------------------------------------------------------------------------
int UIRelativeFrame::GetStreamingSize(Stream &stream) const
{
	int size = UIFrame::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += sizeof(mSize);
	size += sizeof(mBorderSize);

	return size;
}
//----------------------------------------------------------------------------