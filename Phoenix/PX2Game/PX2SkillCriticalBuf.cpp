/*
*
* 文件名称	：	PX2SkillCriticalBuf.cpp
*
*/

#include "PX2SkillCriticalBuf.hpp"
#include "PX2Character.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Buf, SkillCriticalBuf);
PX2_IMPLEMENT_STREAM(SkillCriticalBuf);
PX2_IMPLEMENT_FACTORY(SkillCriticalBuf);
PX2_IMPLEMENT_DEFAULT_NAMES(Buf, SkillCriticalBuf);

//----------------------------------------------------------------------------
SkillCriticalBuf::SkillCriticalBuf ()
	:
mPercent(0.0f),
mProbability(0.0f)
{
}
//----------------------------------------------------------------------------
SkillCriticalBuf::~SkillCriticalBuf ()
{
}
//----------------------------------------------------------------------------
SkillCriticalBuf *SkillCriticalBuf::Create ()
{
	return new0 SkillCriticalBuf();
}
//----------------------------------------------------------------------------
void SkillCriticalBuf::OnAdded ()
{
	Buf::OnAdded();

	Skill *skill = mCharacter->GetSkillByName(mSkillName);
	if (skill)
	{
		skill->SetCriticalPercent(mPercent);
		skill->SetCriticalProbability(mProbability);
	}
	else
	{
		//assertion(false, "SkillCriticalBuf::OnAdded does not find the skill %s",
		//	mSkillName.c_str());
		//PX2_LOG_ERROR("SkillCriticalBuf::OnAdded does not find the skill %s", 
		//	mSkillName.c_str());
	}
}
//----------------------------------------------------------------------------
void SkillCriticalBuf::OnRemoved ()
{
	Buf::OnRemoved();

	Skill *skill = mCharacter->GetSkillByName(mSkillName);
	if (skill)
	{
		skill->SetCriticalPercent(0.0f);
		skill->SetCriticalProbability(0.0f);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
SkillCriticalBuf::SkillCriticalBuf (LoadConstructor value)
	:
Buf(value),
	mPercent(0.0f),
	mProbability(0.0f)
{
}
//----------------------------------------------------------------------------
void SkillCriticalBuf::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Buf::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadString(mSkillName);
	source.Read(mPercent);
	source.Read(mProbability);

	PX2_END_DEBUG_STREAM_LOAD(SkillCriticalBuf, source);
}
//----------------------------------------------------------------------------
void SkillCriticalBuf::Link (InStream& source)
{
	Buf::Link(source);
}
//----------------------------------------------------------------------------
void SkillCriticalBuf::PostLink ()
{
	Buf::PostLink();
}
//----------------------------------------------------------------------------
bool SkillCriticalBuf::Register (OutStream& target) const
{
	if (Buf::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void SkillCriticalBuf::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Buf::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteString(mSkillName);
	target.Write(mPercent);
	target.Write(mProbability);

	PX2_END_DEBUG_STREAM_SAVE(SkillCriticalBuf, target);
}
//----------------------------------------------------------------------------
int SkillCriticalBuf::GetStreamingSize (Stream &stream) const
{
	int size = Buf::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_STRINGSIZE(mSkillName);
	size += sizeof(mPercent);
	size += sizeof(mProbability);

	return size;
}
//----------------------------------------------------------------------------