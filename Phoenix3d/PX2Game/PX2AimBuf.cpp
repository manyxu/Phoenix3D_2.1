/*
*
* 文件名称	：	PX2AimBuf.cpp
*
*/

#include "PX2AimBuf.hpp"
#include "PX2Character.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Buf, AimBuf);
PX2_IMPLEMENT_STREAM(AimBuf);
PX2_IMPLEMENT_FACTORY(AimBuf);
PX2_IMPLEMENT_DEFAULT_NAMES(Buf, AimBuf);

//----------------------------------------------------------------------------
AimBuf::AimBuf ()
	:
mMode(M_CANTBEANIMED),
mValue(0)
{
}
//----------------------------------------------------------------------------
AimBuf::~AimBuf ()
{
}
//----------------------------------------------------------------------------
AimBuf *AimBuf::Create ()
{
	return new0 AimBuf();
}
//----------------------------------------------------------------------------
void AimBuf::Update (double appSeconds, double elapsedSeconds)
{
	Buf::Update(appSeconds, elapsedSeconds);

	if (M_CANTBEANIMED == mMode)
	{
		mCharacter->SetCanBeAimed(false);
	}
}
//----------------------------------------------------------------------------
void AimBuf::OnAdded ()
{
	Buf::OnAdded();

	if (M_CANTBEANIMED == mMode)
	{
		mCharacter->SetCanBeAimed(false);
	}
}
//----------------------------------------------------------------------------
void AimBuf::OnRemoved ()
{
	Buf::OnRemoved();

	if (M_CANTBEANIMED == mMode)
	{
		mCharacter->SetCanBeAimed(true);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
AimBuf::AimBuf (LoadConstructor value)
	:
Buf(value),
mMode(M_CANTBEANIMED),
mValue(0)
{
}
//----------------------------------------------------------------------------
void AimBuf::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Buf::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadEnum(mMode);
	source.Read(mValue);

	PX2_END_DEBUG_STREAM_LOAD(AimBuf, source);
}
//----------------------------------------------------------------------------
void AimBuf::Link (InStream& source)
{
	Buf::Link(source);
}
//----------------------------------------------------------------------------
void AimBuf::PostLink ()
{
	Buf::PostLink();
}
//----------------------------------------------------------------------------
bool AimBuf::Register (OutStream& target) const
{
	if (Buf::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void AimBuf::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Buf::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteEnum(mMode);
	target.Write(mValue);

	PX2_END_DEBUG_STREAM_SAVE(AimBuf, target);
}
//----------------------------------------------------------------------------
int AimBuf::GetStreamingSize (Stream &stream) const
{
	int size = Buf::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_ENUMSIZE(mMode);
	size += sizeof(mValue);

	return size;
}
//----------------------------------------------------------------------------