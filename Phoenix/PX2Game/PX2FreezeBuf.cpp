/*
*
* 文件名称	：	PX2FreezeBuf.cpp
*
*/

#include "PX2FreezeBuf.hpp"
#include "PX2Character.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Buf, FreezeBuf);
PX2_IMPLEMENT_STREAM(FreezeBuf);
PX2_IMPLEMENT_FACTORY(FreezeBuf);
PX2_IMPLEMENT_DEFAULT_NAMES(Buf, FreezeBuf);

//----------------------------------------------------------------------------
FreezeBuf::FreezeBuf ()
{
}
//----------------------------------------------------------------------------
FreezeBuf::~FreezeBuf ()
{
}
//----------------------------------------------------------------------------
FreezeBuf *FreezeBuf::Create ()
{
	return new0 FreezeBuf();
}
//----------------------------------------------------------------------------
void FreezeBuf::Update (double appSeconds, double elapsedSeconds)
{
	Buf::Update(appSeconds, elapsedSeconds);

	mCharacter->Freeze(true);
}
//----------------------------------------------------------------------------
void FreezeBuf::OnAdded ()
{
	Buf::OnAdded();

	mCharacter->Freeze(true);
}
//----------------------------------------------------------------------------
void FreezeBuf::OnRemoved ()
{
	Buf::OnRemoved();

	mCharacter->Freeze(false);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
FreezeBuf::FreezeBuf (LoadConstructor value)
	:
Buf(value)
{
}
//----------------------------------------------------------------------------
void FreezeBuf::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Buf::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(FreezeBuf, source);
}
//----------------------------------------------------------------------------
void FreezeBuf::Link (InStream& source)
{
	Buf::Link(source);
}
//----------------------------------------------------------------------------
void FreezeBuf::PostLink ()
{
	Buf::PostLink();
}
//----------------------------------------------------------------------------
bool FreezeBuf::Register (OutStream& target) const
{
	if (Buf::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void FreezeBuf::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Buf::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(FreezeBuf, target);
}
//----------------------------------------------------------------------------
int FreezeBuf::GetStreamingSize (Stream &stream) const
{
	int size = Buf::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------