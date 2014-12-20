/*
*
* 文件名称	：	PX2InputPushTransformController.cpp
*
*/

#include "PX2InputPushTransformController.hpp"
#include "PX2InputEventAdapter.hpp"
#include "PX2Time.hpp"
#include "PX2Math.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, PushTransformController, InputPushTransformController);
PX2_IMPLEMENT_STREAM(InputPushTransformController);
PX2_IMPLEMENT_FACTORY(InputPushTransformController);
PX2_IMPLEMENT_DEFAULT_NAMES(PushTransformController, InputPushTransformController);

//----------------------------------------------------------------------------
InputPushTransformController::InputPushTransformController ()
	:
mPressedTime(0.0f),
mReleasedTime(0.0f),
mPushTriggerSpeed(100.0f),
mConvertCallback(0),
mIsPressedValid(false),
mMinPos(AVector::ZERO),
mMaxPos(AVector::ZERO),
mMinPosSmall(AVector::ZERO),
mMaxPosSmall(AVector::ZERO),
mSideMoveLength(0.0f)
{
	InputEventAdapter::GetSingleton().GetInputEventListener()->AddHandler(this);
}
//----------------------------------------------------------------------------
InputPushTransformController::~InputPushTransformController ()
{
	InputEventAdapter::GetSingleton().GetInputEventListener()->RemoveHandler(this);
}
//----------------------------------------------------------------------------
void InputPushTransformController::SetLockDir (const AVector &dir)
{
	mLockDir = dir;
	mLockDir.Normalize();
}
//----------------------------------------------------------------------------
void InputPushTransformController::SetReleaseVelocity (const AVector &velocity)
{
	mReleasedVec = velocity;
	SetVelocity(velocity);
}
//----------------------------------------------------------------------------
void InputPushTransformController::SetVelocity(const AVector &velocity)
{
	PushTransformController::SetVelocity(velocity);
}
//----------------------------------------------------------------------------
void InputPushTransformController::SetTransScope(const AVector &min,const AVector &max)
{
	mMinPos = min;
	mMaxPos = max;
}
//----------------------------------------------------------------------------
void InputPushTransformController::SetTransScopeSmall (const AVector &min, const AVector &max)
{
	mMinPosSmall = min;
	mMaxPosSmall = max;

	mSideMoveLength = (mMinPosSmall-mMinPos).Length();
}
//----------------------------------------------------------------------------
bool InputPushTransformController::Update (double applicationTime)
{
	if (!Controller::Update(applicationTime))
		return false;

	float elapsedTime = (float)GetElapsedTime();

	if (!IsSmallTransScope())
	{
		// 减小速度
		AVector vecTemp = mVelocity;
		float vecLength = vecTemp.Normalize();
		vecLength -= mFriction * elapsedTime;
		if (vecLength <= 0.0f)
		{
			SetVelocity(AVector::ZERO);
		}
		else
		{
			SetVelocity(vecTemp * vecLength);
		}
	}
	else
	{
		if (!mIsPressedValid) // 没有按下
		{
			if (0.0f == mSideMoveLength)
				mSideMoveLength = 1.0f;

			AVector smallDir = GetSmallTransDir();
			if (AVector::ZERO != smallDir)
			{
				float moveDirLength = smallDir.Normalize();
				float adjuge = moveDirLength/mSideMoveLength;

				mVelocity += smallDir * mFriction * adjuge * adjuge * elapsedTime;
			}
		}
		else
		{
			mVelocity = AVector::ZERO;
		}
	}

	AVector velocityDis = mVelocity*elapsedTime;

	AVector movedDis;
	if (IsXY())
	{
		movedDis.X() = velocityDis.X();
		movedDis.Y() = velocityDis.Y();
	}
	else
	{
		movedDis.X() = velocityDis.X();
		movedDis.Z() = velocityDis.Z();
	}

	AVector beforeSmallDir = GetSmallTransDir();

	OnMoving(movedDis);

	if (IsSmallTransScope())
	{
		AVector smallDir = GetSmallTransDir();
		if (smallDir==AVector::ZERO && beforeSmallDir!=AVector::ZERO)
		{
			SetVelocity(AVector::ZERO);
		}
	}

	return true;
}
//----------------------------------------------------------------------------
bool InputPushTransformController::IsSmallTransScope ()
{
	AVector smallScope = mMaxPosSmall - mMinPosSmall;
	float lengthSquare = smallScope.SquaredLength();

	return 0.0f!=lengthSquare;
}
//----------------------------------------------------------------------------
AVector InputPushTransformController::GetSmallTransDir ()
{
	Movable *movable = DynamicCast<Movable>(mObject);
	if (!movable)
		AVector::ZERO;

	APoint curPos = movable->LocalTransform.GetTranslate();

	AVector moveDir = AVector::ZERO;
	if (curPos.X() < mMinPosSmall.X())
	{
		moveDir.X() = mMinPosSmall.X() - curPos.X();
	}

	if (curPos.Y() < mMinPosSmall.Y())
	{
		moveDir.Y() = mMinPosSmall.Y() - curPos.Y();
	}

	if (curPos.Z() < mMinPosSmall.Z())
	{
		moveDir.Z() = mMinPosSmall.Z() - curPos.Z();
	}

	if(curPos.X()>mMaxPosSmall.X())
	{
		moveDir.X() = mMaxPosSmall.X() - curPos.X();
	}

	if(curPos.Y()>mMaxPosSmall.Y())
	{
		moveDir.Y() = mMaxPosSmall.Y() - curPos.Y();
	}

	if(curPos.Z()>mMaxPosSmall.Z())
	{
		moveDir.Z() = mMaxPosSmall.Z() - curPos.Z();
	}

	return moveDir;
}
//----------------------------------------------------------------------------
void InputPushTransformController::OnMoving (const AVector &dis)
{
	PushTransformController::OnMoving(dis);

	Movable *movable = DynamicCast<Movable>(mObject);
	if (!movable)
		return;

	APoint curPos = movable->LocalTransform.GetTranslate();

	TransScope(curPos);

	movable->LocalTransform.SetTranslate(curPos);
}
//----------------------------------------------------------------------------
bool InputPushTransformController::TouchMoved (const InputEventData &data)
{
	if (!Active)
		return false;

	if (!InputEventHandler::TouchMoved(data))
		return false;

	if (!mIsPressedValid)
		return false;

	Movable *mov = DynamicCast<Movable>(GetControlledable());
	if (!mov)
		return false;

	mCurTouchPos.X() = (float)data.TState.X.Absoulate;
	mCurTouchPos.Y() = (float)data.TState.Y.Absoulate;

	if (mConvertCallback)
	{
		mConvertCallback(mCurTouchPos, data.TState.X.Absoulate,
			data.TState.Y.Absoulate);
	}

	AVector moveDis = mCurTouchPos - mLastTouchPos;

	APoint pos = mov->LocalTransform.GetTranslate();
	pos += moveDis;

	// Scope
	TransScope(pos);

	mov->LocalTransform.SetTranslate(pos);
	
	mLastTouchPos = mCurTouchPos;

	return true;
}
//----------------------------------------------------------------------------
bool InputPushTransformController::TouchPressed (const InputEventData &data)
{
	if (!Active)
		return false;

	mIsPressedValid = false;

	if (!InputEventHandler::TouchPressed(data))
		return false;

	mIsPressedValid = true;

	mPressedTime = (float)GetTimeInSeconds();
	mPressedPos.X() = (float)data.TState.X.Absoulate;
	mPressedPos.Y() = (float)data.TState.Y.Absoulate;

	if (mConvertCallback)
	{
		mConvertCallback(mPressedPos, data.TState.X.Absoulate, 
			data.TState.Y.Absoulate);
	}

	mCurTouchPos = mPressedPos;
	mLastTouchPos = mPressedPos;
	
	SetVelocity(AVector::ZERO);

	return true;
}
//----------------------------------------------------------------------------
bool InputPushTransformController::TouchReleased (const InputEventData &data)
{
	if (!Active)
		return false;

	if (!InputEventHandler::TouchReleased(data))
		return false;

	if (!mIsPressedValid)
		return false;

	mIsPressedValid = false;

	mReleasedTime = (float)GetTimeInSeconds();
	mReleasedPos.X() = (float)data.TState.X.Absoulate;
	mReleasedPos.Y() = (float)data.TState.Y.Absoulate;

	if (mConvertCallback)
	{
		mConvertCallback(mReleasedPos, data.TState.X.Absoulate,
			data.TState.Y.Absoulate);
	}

	float deltaTime = mReleasedTime - mPressedTime;
	if (deltaTime <= 0.0f)
	{
		deltaTime = 1.0f;
	}

	AVector speed = mReleasedPos - mPressedPos;
	speed /= deltaTime;

	float judge = 0.0f;

	AVector moveDir = AVector::ZERO;

	if (mLockDir != AVector::ZERO)
	{
		judge = mLockDir.Dot(speed);
		moveDir = mLockDir;
	}
	else
	{
		judge = speed.Length();
		moveDir = speed;
	}

	moveDir.Normalize();

	if (Mathf::FAbs(judge) >= mPushTriggerSpeed)
	{
		AVector vec = moveDir;

		if (mLockDir != AVector::ZERO)
		{
			vec.X() *= mLockDir.X();
			vec.Y() *= mLockDir.Y();
			vec.Z() *= mLockDir.Z();
		}

		SetReleaseVelocity(vec * judge);
	}

	if (IsSmallTransScope() && GetSmallTransDir()!=AVector::ZERO)
	{
		SetReleaseVelocity(AVector::ZERO);
	}

	return true;
}
//----------------------------------------------------------------------------
bool InputPushTransformController::TouchCancelled (const InputEventData &data)
{
	if (!Active)
		return false;

	if (!InputEventHandler::TouchCancelled(data))
		return false;

	mIsPressedValid = false;

	return true;
}
//----------------------------------------------------------------------------
bool InputPushTransformController::TransScope(APoint &pos)
{
	if (mMinPos.X()>mMaxPos.X() || mMinPos.Y()>mMaxPos.Y() || mMinPos.Z()>mMaxPos.Z() || mMinPos == mMaxPos )
	{
		return false;
	}

	if (mMinPos.X()>pos.X())
	{
		pos.X() = mMinPos.X();
		mVelocity.X() = 0.0f;
	}

	if (mMinPos.Y()>pos.Y())
	{
		pos.Y() = mMinPos.Y();
		mVelocity.Y() = 0.0f;
	}

	if (mMinPos.Z()>pos.Z())
	{
		pos.Z() = mMinPos.Z();
		mVelocity.Z() = 0.0f;
	}

	if(pos.X()>mMaxPos.X())
	{
		pos.X() = mMaxPos.X();
		mVelocity.X() = 0.0f;
	}

	if(pos.Y()>mMaxPos.Y())
	{
		pos.Y() = mMaxPos.Y();
		mVelocity.Y() = 0.0f;
	}

	if(pos.Z()>mMaxPos.Z())
	{
		pos.Z() = mMaxPos.Z();
		mVelocity.Z() = 0.0f;
	}

	return true;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化
//----------------------------------------------------------------------------
InputPushTransformController::InputPushTransformController (LoadConstructor value)
	:
PushTransformController(value),
mPressedTime(0.0f),
mReleasedTime(0.0f),
mPushTriggerSpeed(100.0f),
mConvertCallback(0),
mIsPressedValid(false),
mMinPos(AVector::ZERO),
mMaxPos(AVector::ZERO),
mMinPosSmall(AVector::ZERO),
mMaxPosSmall(AVector::ZERO),
mSideMoveLength(0.0f)
{
	InputEventAdapter::GetSingleton().GetInputEventListener()->AddHandler(this);
}
//----------------------------------------------------------------------------
void InputPushTransformController::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	PushTransformController::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadAggregate(mLockDir);
	source.Read(mPushTriggerSpeed);

	PX2_END_DEBUG_STREAM_LOAD(InputPushTransformController, source);
}
//----------------------------------------------------------------------------
void InputPushTransformController::Link (InStream& source)
{
	PushTransformController::Link(source);
}
//----------------------------------------------------------------------------
void InputPushTransformController::PostLink ()
{
	PushTransformController::PostLink();
}
//----------------------------------------------------------------------------
bool InputPushTransformController::Register (OutStream& target) const
{
	return PushTransformController::Register(target);
}
//----------------------------------------------------------------------------
void InputPushTransformController::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	PushTransformController::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteAggregate(mLockDir);
	target.Write(mPushTriggerSpeed);

	PX2_END_DEBUG_STREAM_SAVE(InputPushTransformController, target);
}
//----------------------------------------------------------------------------
int InputPushTransformController::GetStreamingSize (Stream &stream) const
{
	int size = PushTransformController::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += sizeof(mLockDir);
	size += sizeof(mPushTriggerSpeed);

	return size;
}
//----------------------------------------------------------------------------
