/*
*
* 文件名称	：	PX2UIPushFrame.cpp
*
*/

#include "PX2UIPushFrame.hpp"
using namespace PX2;
using namespace std;

PX2_IMPLEMENT_RTTI(PX2, UIFrame, UIPushFrame);
PX2_IMPLEMENT_STREAM(UIPushFrame);
PX2_IMPLEMENT_FACTORY(UIPushFrame);
PX2_IMPLEMENT_DEFAULT_NAMES(UIFrame, UIPushFrame)

//----------------------------------------------------------------------------
void UIPushFrameTouchConvert (APoint &touchPos, int xPos, int yPos)
{
	touchPos.X() = (float)xPos;
	touchPos.Y() = 0.0f;
	touchPos.Z() = (float)yPos;
}
//----------------------------------------------------------------------------
UIPushFrame::UIPushFrame ()
{
	mCtrl = new0 InputPushTransformController();
	AttachController(mCtrl);
	mCtrl->SetTouchConvertCallback(UIPushFrameTouchConvert);
}
//----------------------------------------------------------------------------
UIPushFrame::~UIPushFrame ()
{
}
//----------------------------------------------------------------------------
void UIPushFrame::SetDirType (DirType type)
{
	mDirType = type;

	if (DT_X == mDirType)
	{
		mCtrl->SetLockDir(AVector(1.0f, 0.0f, 0.0f));
	}
	else if (DT_Z == mDirType)
	{
		mCtrl->SetLockDir(AVector(0.0f, 0.0f, 1.0f));
	}
	else if (DT_XZ == mDirType)
	{
		mCtrl->SetLockDir(AVector(1.0f, 0.0f, 1.0f));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UIPushFrame::UIPushFrame (LoadConstructor value)
	:
UIFrame(value)
{
}
//----------------------------------------------------------------------------
void UIPushFrame::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UIFrame::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadPointer(mCtrl);

	PX2_END_DEBUG_STREAM_LOAD(UIPushFrame, source);
}
//----------------------------------------------------------------------------
void UIPushFrame::Link (InStream& source)
{
	UIFrame::Link(source);

	if (mCtrl)
	{
		source.ResolveLink(mCtrl);
		mCtrl->SetTouchConvertCallback(UIPushFrameTouchConvert);
	}
}
//----------------------------------------------------------------------------
void UIPushFrame::PostLink ()
{
	UIFrame::PostLink();
}
//----------------------------------------------------------------------------
bool UIPushFrame::Register (OutStream& target) const
{
	if (UIFrame::Register(target))
	{
		target.Register(mCtrl);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void UIPushFrame::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UIFrame::Save(target);
	PX2_VERSION_SAVE(target);

	target.WritePointer(mCtrl);

	PX2_END_DEBUG_STREAM_SAVE(UIPushFrame, target);
}
//----------------------------------------------------------------------------
int UIPushFrame::GetStreamingSize (Stream &stream) const
{
	int size = UIFrame::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	size += PX2_POINTERSIZE(mCtrl);

	return size;
}
//----------------------------------------------------------------------------