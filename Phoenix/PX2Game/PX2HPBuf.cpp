/*
*
* 文件名称	：	PX2EffectBuf.cpp
*
*/

#include "PX2HPBuf.hpp"
#include "PX2Character.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Buf, HPBuf);
PX2_IMPLEMENT_STREAM(HPBuf);
PX2_IMPLEMENT_FACTORY(HPBuf);
PX2_IMPLEMENT_DEFAULT_NAMES(Buf, HPBuf);

//----------------------------------------------------------------------------
HPBuf::HPBuf ()
	:
mMode(M_LASTING),
mValue(0.0f),
mExcessHP(0.0f)
{
}
//----------------------------------------------------------------------------
HPBuf::~HPBuf ()
{
}
//----------------------------------------------------------------------------
HPBuf *HPBuf::Create ()
{
	return new0 HPBuf();
}
//----------------------------------------------------------------------------
void HPBuf::Update (double appSeconds, double elapsedSeconds)
{
	Buf::Update(appSeconds, elapsedSeconds);

	if (M_LASTING == mMode)
	{
		int curHP = mCharacter->GetCurHP();

		float absHP = Mathf::FAbs(mValue);
		float sign = Mathf::Sign(mValue);

		float changeHP = absHP * (float)elapsedSeconds;
		mExcessHP += changeHP;

		int iHP = (int)mExcessHP;

		curHP += (int)sign*iHP;

		if (curHP < 0.0f)
		{
			curHP = 0;
		}

		if (curHP > mCharacter->GetMHP())
		{
			curHP = mCharacter->GetMHP();
		}

		mCharacter->SetCurHP(curHP);

		mExcessHP = mExcessHP - iHP;
	}
	else if (M_LASTINGPERSECOND == mMode)
	{
		mOneSecondsTiming += (float)elapsedSeconds;

		bool doCal = false;

		float val = mValue;
		if (mOneSecondsTiming > 1.0f)
		{
			val = mValue;

			doCal = true;

			mOneSecondsTiming -= 1.0f;
		}

		if (IsOver())
		{
			doCal = true;

			val = mValue * mOneSecondsTiming;
		}

		if (doCal)
		{
			int curHP = mCharacter->GetCurHP();

			curHP += (int)val;

			if (curHP < 0.0f)
			{
				curHP = 0;
			}

			if (curHP > mCharacter->GetMHP())
			{
				curHP = mCharacter->GetMHP();
			}

			mCharacter->SetCurHP(curHP);
		}
	}
	else if (M_NOREDUCE == mMode)
	{
		mCharacter->SetCurHPNoReduce(true);
	}
}
//----------------------------------------------------------------------------
void HPBuf::OnAdded ()
{
	Buf::OnAdded();

	if (M_IMMEDIATE == mMode)
	{
		int curHP = mCharacter->GetCurHP();

		int modHP = mCharacter->GetMHP();
		int addHP = (int)((float)modHP * mValue);

		curHP += addHP;

		if (curHP > modHP)
		{
			curHP = modHP;
		}

		mCharacter->SetCurHP(curHP);
	}
	else if (M_NOREDUCE == mMode)
	{
		mCharacter->SetCurHPNoReduce(true);
	}
}
//----------------------------------------------------------------------------
void HPBuf::OnRemoved ()
{
	Buf::OnRemoved();

	if (M_NOREDUCE == mMode)
	{
		mCharacter->SetCurHPNoReduce(false);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
HPBuf::HPBuf (LoadConstructor value)
	:
Buf(value),
mMode(M_LASTING),
mValue(0.0f),
mExcessHP(0.0f)
{
}
//----------------------------------------------------------------------------
void HPBuf::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Buf::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadEnum(mMode);
	source.Read(mValue);

	PX2_END_DEBUG_STREAM_LOAD(HPBuf, source);
}
//----------------------------------------------------------------------------
void HPBuf::Link (InStream& source)
{
	Buf::Link(source);
}
//----------------------------------------------------------------------------
void HPBuf::PostLink ()
{
	Buf::PostLink();
}
//----------------------------------------------------------------------------
bool HPBuf::Register (OutStream& target) const
{
	if (Buf::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void HPBuf::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Buf::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteEnum(mMode);
	target.Write(mValue);

	PX2_END_DEBUG_STREAM_SAVE(HPBuf, target);
}
//----------------------------------------------------------------------------
int HPBuf::GetStreamingSize (Stream &stream) const
{
	int size = Buf::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_ENUMSIZE(mMode);
	size += sizeof(mValue);

	return size;
}
//----------------------------------------------------------------------------