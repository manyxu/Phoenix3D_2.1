/*
*
* 文件名称	：	PX2SkillCDTimeBuf.cpp
*
*/

#include "PX2SkillCDTimeBuf.hpp"
#include "PX2Character.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Buf, SkillCDTimeBuf);
PX2_IMPLEMENT_STREAM(SkillCDTimeBuf);
PX2_IMPLEMENT_FACTORY(SkillCDTimeBuf);
PX2_IMPLEMENT_DEFAULT_NAMES(Buf, SkillCDTimeBuf);

//----------------------------------------------------------------------------
SkillCDTimeBuf::SkillCDTimeBuf ()
	:
mMode(M_IMMEDIATE),
mValue(0.0f),
mLastingMaxTime(-1.0f),
mMValue(0.0f),
mLastingTimeUpdate(0.0f)
{
}
//----------------------------------------------------------------------------
SkillCDTimeBuf::~SkillCDTimeBuf ()
{
}
//----------------------------------------------------------------------------
SkillCDTimeBuf *SkillCDTimeBuf::Create ()
{
	return new0 SkillCDTimeBuf();
}
//----------------------------------------------------------------------------
void SkillCDTimeBuf::Update (double appSeconds, double elapsedSeconds)
{
	Buf::Update(appSeconds, elapsedSeconds);

	if (M_LASTING == mMode)
	{
		if (mLastingMaxTime > 0)
		{
			mLastingTimeUpdate += (float)elapsedSeconds;

			if (mLastingTimeUpdate > mLastingMaxTime)
			{
				return;
			}
		}

		Skill *skill = mCharacter->GetSkillByName(mSkillName);
		if (skill)
		{
			float baseCDTime = skill->GetCDTime();
			mMValue += (baseCDTime * mValue * (float)elapsedSeconds);
			skill->AddMCDTime(GetAddedIDString(), mMValue);
		}
		else
		{
			//assertion(false, "SkillCDTimeBuf::OnAdded does not find the skill %s",
			//	mSkillName.c_str());
			//PX2_LOG_ERROR("SkillCDTimeBuf::OnAdded does not find the skill %s", 
			//	mSkillName.c_str());
		}
	}
}
//----------------------------------------------------------------------------
void SkillCDTimeBuf::OnAdded ()
{
	Buf::OnAdded();

	if (M_IMMEDIATE == mMode)
	{
		Skill *skill = mCharacter->GetSkillByName(mSkillName);
		if (skill)
		{
			float baseCDTime = skill->GetCDTime();
			mMValue = baseCDTime * mValue;
			skill->AddMCDTime(GetAddedIDString(), mMValue);
		}
		else
		{
			//assertion(false, "SkillCDTimeBuf::OnAdded does not find the skill %s",
			//	mSkillName.c_str());
			//PX2_LOG_ERROR("SkillCDTimeBuf::OnAdded does not find the skill %s", 
			//	mSkillName.c_str());
		}
	}
}
//----------------------------------------------------------------------------
void SkillCDTimeBuf::OnRemoved ()
{
	Buf::OnRemoved();

	Skill *skill = mCharacter->GetSkillByName(mSkillName);
	if (skill)
	{
		skill->RemoveMCDTime(GetAddedIDString());
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
SkillCDTimeBuf::SkillCDTimeBuf (LoadConstructor value)
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
void SkillCDTimeBuf::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Buf::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadEnum(mMode);
	source.ReadString(mSkillName);
	source.Read(mValue);
	source.Read(mLastingMaxTime);

	PX2_END_DEBUG_STREAM_LOAD(SkillCDTimeBuf, source);
}
//----------------------------------------------------------------------------
void SkillCDTimeBuf::Link (InStream& source)
{
	Buf::Link(source);
}
//----------------------------------------------------------------------------
void SkillCDTimeBuf::PostLink ()
{
	Buf::PostLink();
}
//----------------------------------------------------------------------------
bool SkillCDTimeBuf::Register (OutStream& target) const
{
	if (Buf::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void SkillCDTimeBuf::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Buf::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteEnum(mMode);
	target.WriteString(mSkillName);
	target.Write(mValue);
	target.Write(mLastingMaxTime);

	PX2_END_DEBUG_STREAM_SAVE(SkillCDTimeBuf, target);
}
//----------------------------------------------------------------------------
int SkillCDTimeBuf::GetStreamingSize (Stream &stream) const
{
	int size = Buf::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_ENUMSIZE(mMode);
	size += PX2_STRINGSIZE(mSkillName);
	size += sizeof(mValue);
	size += sizeof(mLastingMaxTime);

	return size;
}
//----------------------------------------------------------------------------