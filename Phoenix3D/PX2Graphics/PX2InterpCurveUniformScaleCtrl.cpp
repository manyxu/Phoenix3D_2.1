// PX2InterpCurveTransCtrl.cpp

#include "PX2InterpCurveUniformScaleCtrl.hpp"
#include "PX2Movable.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, InterpCurveFloatController, InterpCurveUniformScaleController);
PX2_IMPLEMENT_STREAM(InterpCurveUniformScaleController);
PX2_IMPLEMENT_FACTORY(InterpCurveUniformScaleController);
PX2_IMPLEMENT_DEFAULT_NAMES(InterpCurveFloatController, InterpCurveUniformScaleController);

//----------------------------------------------------------------------------
InterpCurveUniformScaleController::InterpCurveUniformScaleController ()
	:
InterpCurveFloatController(1.0f)
{
	SetPriority(13);
}
//----------------------------------------------------------------------------
InterpCurveUniformScaleController::~InterpCurveUniformScaleController ()
{
}
//----------------------------------------------------------------------------
void InterpCurveUniformScaleController::_Update (double applicationTime)
{	
	PX2_UNUSED(applicationTime);

	float ctrlTime = (float)GetControlTimeByRangeTime(GetPlayedTimeMinusDelay());
	mCurValueRaw = mValues.Eval(ctrlTime, 1.0f);
	mCurValueRelatived = mCurValueRaw;

	if (mIsRelatively)
	{
		mCurValueRelatived *= mInitValue;
	}

	float curValue = GetCurValueRelatived();

	Movable* movable = StaticCast<Movable>(mObject);
	if (movable)
	{	
		movable->LocalTransform.SetUniformScale(curValue);
	}
}
//----------------------------------------------------------------------------
void InterpCurveUniformScaleController::OnAttach ()
{
	if (IsAttachUpdateInit())
	{
		Movable* movable = StaticCast<Movable>(mObject);
		if (movable)
		{
			mInitValue = movable->LocalTransform.GetUniformScale();
		}
	}
}
//----------------------------------------------------------------------------
void InterpCurveUniformScaleController::OnDetach ()
{
	if (IsDetachResetInit())
	{
		Movable* movable = StaticCast<Movable>(mObject);
		if (movable)
		{
			movable->LocalTransform.SetUniformScale(mInitValue);
		}
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// ³Ö¾Ã»¯
//----------------------------------------------------------------------------
InterpCurveUniformScaleController::InterpCurveUniformScaleController (LoadConstructor value)
	:
InterpCurveFloatController(value)
{
}
//----------------------------------------------------------------------------
void InterpCurveUniformScaleController::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	InterpCurveFloatController::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(InterpCurveUniformScaleController, source);
}
//----------------------------------------------------------------------------
void InterpCurveUniformScaleController::Link (InStream& source)
{
	InterpCurveFloatController::Link(source);
}
//----------------------------------------------------------------------------
void InterpCurveUniformScaleController::PostLink ()
{
	InterpCurveFloatController::PostLink();
}
//----------------------------------------------------------------------------
bool InterpCurveUniformScaleController::Register (OutStream& target) const
{
	return InterpCurveFloatController::Register(target);
}
//----------------------------------------------------------------------------
void InterpCurveUniformScaleController::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	InterpCurveFloatController::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(InterpCurveUniformScaleController, target);
}
//----------------------------------------------------------------------------
int InterpCurveUniformScaleController::GetStreamingSize (Stream &stream) const
{
	int size = InterpCurveFloatController::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------