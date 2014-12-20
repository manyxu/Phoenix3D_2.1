/*
*
* 文件名称	：	PX2Buf.cpp
*
*/

#include "PX2Buf.hpp"
#include "PX2Character.hpp"
#include "PX2Project.hpp"
#include "PX2Scene.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Gameable, Buf);
PX2_IMPLEMENT_STREAM(Buf);
PX2_IMPLEMENT_FACTORY(Buf);
PX2_IMPLEMENT_DEFAULT_NAMES(Gameable, Buf);

//----------------------------------------------------------------------------
int Buf::msNextID = 0;
//----------------------------------------------------------------------------
int Buf::GetNextID ()
{
	++msNextID;
	return msNextID;
}
//----------------------------------------------------------------------------
std::string Buf::GetNextIDStr ()
{
	return "Buf__" + StringHelp::IntToString(GetNextID());
}
//----------------------------------------------------------------------------
Buf::Buf ()
	:
mID(0),
mTypeID(0),
mIsClassOnlyOne(false),
mTimeAdded(0.0f),
mIsUseCenterIDAlive(false),
mIsUseRange(false),
mCenterCharacterID(-1),
mRadius(1.0f),
mIsOver(false)
{
}
//----------------------------------------------------------------------------
Buf::~Buf ()
{
}
//----------------------------------------------------------------------------
void Buf::SetID (int id)
{
	mID = id;
}
//----------------------------------------------------------------------------
void Buf::SetTypeID (int typeID)
{
	mTypeID = typeID;
}
//----------------------------------------------------------------------------
void Buf::Update (double appSeconds, double elapsedSeconds)
{
	PX2_UNUSED(appSeconds);

	mTimeAdded += (float)elapsedSeconds;

	Character *chara = GetCharacter();

	Actor *centerActor = 0;
	Character *centerChar = 0;
	if ((mIsUseRange || mIsUseCenterIDAlive) && mCenterCharacterID>0)
	{
		centerActor = PX2_PROJ.GetScene()->GetActorByID(mCenterCharacterID);
		if (!centerActor)
		{
			SetOver(true);
			return;
		}

		centerChar = DynamicCast<Character>(centerActor);
		if (centerChar && centerChar->IsDead())
		{
			SetOver(true);
			return;
		}
	}

	if (mIsUseRange)
	{
		APoint center;
		if (mCenterCharacterID>0)
		{
			if (centerActor)
			{
				center = centerActor->GetPosition();
			}			

			if (centerChar && centerChar->IsDead())
			{
				SetOver(true);
				return;
			}
		}
		else
		{
			center = mCenter;
		}

		AVector dir = center - mCharacter->GetPosition();
		float squaredLength = dir.SquaredLength();
		if (squaredLength > mRadius*mRadius)
		{
			SetOver(true);
			return;
		}
	}

	if (mTimeAdded > mTime)
	{
		SetOver(true);
		return;
	}
}
//----------------------------------------------------------------------------
void Buf::ResetTimeAdded ()
{
	mTimeAdded = 0.0f;
}
//----------------------------------------------------------------------------
void Buf::OnAdded ()
{
	mAddedIDString = GetNextIDStr();

	if (!mScriptHandler_OnAdded.empty())
	{
		CallString(mScriptHandler_OnAdded.c_str());
	}
}
//----------------------------------------------------------------------------
void Buf::OnRemoved ()
{
	if (!mScriptHandler_OnRemoved.empty())
	{
		CallString(mScriptHandler_OnRemoved.c_str());
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Buf::Buf (LoadConstructor value)
	:
Gameable(value),
mID(0),
mTypeID(0),
mIsClassOnlyOne(false),
mIsUseCenterIDAlive(false),
mIsUseRange(false),
mCenterCharacterID(-1),
mRadius(1.0f),
mTimeAdded(0.0f),
mIsOver(false)
{
}
//----------------------------------------------------------------------------
void Buf::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Gameable::Load(source);
	PX2_VERSION_LOAD(source);

	source.Read(mID);
	source.Read(mTypeID);
	source.ReadString(mClassStr);
	source.ReadBool(mIsClassOnlyOne);
	source.Read(mTime);
	source.ReadBool(mIsUseCenterIDAlive);
	source.ReadBool(mIsUseRange);
	source.ReadAggregate(mCenter);
	source.Read(mCenterCharacterID);
	source.Read(mRadius);
	source.ReadString(mScriptHandler_OnAdded);
	source.ReadString(mScriptHandler_OnRemoved);

	PX2_END_DEBUG_STREAM_LOAD(Buf, source);
}
//----------------------------------------------------------------------------
void Buf::Link (InStream& source)
{
	Gameable::Link(source);
}
//----------------------------------------------------------------------------
void Buf::PostLink ()
{
	Gameable::PostLink();
}
//----------------------------------------------------------------------------
bool Buf::Register (OutStream& target) const
{
	if (Gameable::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void Buf::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Gameable::Save(target);
	PX2_VERSION_SAVE(target);

	target.Write(mID);
	target.Write(mTypeID);
	target.WriteString(mClassStr);
	target.WriteBool(mIsClassOnlyOne);
	target.Write(mTime);
	target.WriteBool(mIsUseCenterIDAlive);
	target.WriteBool(mIsUseRange);
	target.WriteAggregate(mCenter);
	target.Write(mCenterCharacterID);
	target.Write(mRadius);
	target.WriteString(mScriptHandler_OnAdded);
	target.WriteString(mScriptHandler_OnRemoved);

	PX2_END_DEBUG_STREAM_SAVE(Buf, target);
}
//----------------------------------------------------------------------------
int Buf::GetStreamingSize (Stream &stream) const
{
	int size = Gameable::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += sizeof(mID);
	size += sizeof(mTypeID);
	size += PX2_STRINGSIZE(mClassStr);
	size += PX2_BOOLSIZE(mIsClassOnlyOne);
	size += sizeof(mTime);
	size += PX2_BOOLSIZE(mIsUseCenterIDAlive);
	size += PX2_BOOLSIZE(mIsUseRange);
	size += sizeof(mCenter);
	size += sizeof(mCenterCharacterID);
	size += sizeof(mRadius);
	size += PX2_STRINGSIZE(mScriptHandler_OnAdded);
	size += PX2_STRINGSIZE(mScriptHandler_OnRemoved);

	return size;
}
//----------------------------------------------------------------------------