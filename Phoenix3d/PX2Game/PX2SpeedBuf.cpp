/*
*
* 文件名称	：	PX2SpeedBuf.cpp
*
*/

#include "PX2SpeedBuf.hpp"
#include "PX2Character.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Buf, SpeedBuf);
PX2_IMPLEMENT_STREAM(SpeedBuf);
PX2_IMPLEMENT_FACTORY(SpeedBuf);
PX2_IMPLEMENT_DEFAULT_NAMES(Buf, SpeedBuf);

//----------------------------------------------------------------------------
SpeedBuf::SpeedBuf ()
	:
mMode(M_IMMEDIATE),
mValue(0.0f),
mLastingMaxTime(-1.0f),
mMValue(0.0f),
mLastingTimeUpdate(0.0f)
{
}
//----------------------------------------------------------------------------
SpeedBuf::~SpeedBuf ()
{
}
//----------------------------------------------------------------------------
SpeedBuf *SpeedBuf::Create ()
{
	return new0 SpeedBuf();
}
//----------------------------------------------------------------------------
void SpeedBuf::Update (double appSeconds, double elapsedSeconds)
{
	Buf::Update(appSeconds, elapsedSeconds);

	if (M_DOSTOP == mMode)
	{
	}
	else if (M_LASTING == mMode)
	{
		if (mLastingMaxTime > 0.0f)
		{
			mLastingTimeUpdate += (float)elapsedSeconds;

			if (mLastingTimeUpdate > mLastingMaxTime)
			{
				return;
			}
		}

		float baseMaxSpeed = mCharacter->GetMaxSpeed();
		mMValue += (baseMaxSpeed * mValue * (float)elapsedSeconds);
		mCharacter->AddMMaxSpeed(GetAddedIDString(), mMValue);
	}
}
//----------------------------------------------------------------------------
void SpeedBuf::OnAdded ()
{
	Buf::OnAdded();

	if (M_DOSTOP == mMode)
	{
		mCharacter->AddStopSpeedTag(GetAddedIDString());
		mCharacter->SetVelocity(AVector::ZERO);
	}
	else if (M_IMMEDIATE == mMode)
	{
		float baseMaxSpeed = mCharacter->GetMaxSpeed();
		mMValue = baseMaxSpeed * mValue;
		mCharacter->AddMMaxSpeed(GetAddedIDString(), mMValue);
	}
}
//----------------------------------------------------------------------------
void SpeedBuf::OnRemoved ()
{
	Buf::OnRemoved();

	if (M_DOSTOP!=mMode)
	{
		mCharacter->RemoveMMaxSpeed(GetAddedIDString());
	}
	else
	{
		mCharacter->RemoveStopSpeedTag(GetAddedIDString());
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
SpeedBuf::SpeedBuf (LoadConstructor value)
	:
Buf(value),
mMode(M_IMMEDIATE),
mValue(0.0f),
mLastingMaxTime(-1.0f),
mMValue(0.0f),
mLastingTimeUpdate(0.0f)
{
}
//----------------------------------------------------------------------------
void SpeedBuf::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Buf::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadEnum(mMode);
	source.Read(mValue);
	source.Read(mLastingMaxTime);

	PX2_END_DEBUG_STREAM_LOAD(SpeedBuf, source);
}
//----------------------------------------------------------------------------
void SpeedBuf::Link (InStream& source)
{
	Buf::Link(source);
}
//----------------------------------------------------------------------------
void SpeedBuf::PostLink ()
{
	Buf::PostLink();
}
//----------------------------------------------------------------------------
bool SpeedBuf::Register (OutStream& target) const
{
	if (Buf::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void SpeedBuf::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Buf::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteEnum(mMode);
	target.Write(mValue);
	target.Write(mLastingMaxTime);

	PX2_END_DEBUG_STREAM_SAVE(SpeedBuf, target);
}
//----------------------------------------------------------------------------
int SpeedBuf::GetStreamingSize (Stream &stream) const
{
	int size = Buf::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_ENUMSIZE(mMode);
	size += sizeof(mValue);
	size += sizeof(mLastingMaxTime);

	return size;
}
//----------------------------------------------------------------------------