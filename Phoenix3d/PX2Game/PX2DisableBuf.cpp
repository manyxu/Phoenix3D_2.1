/*
*
* 文件名称	：	PX2DisableBuf.cpp
*
*/

#include "PX2DisableBuf.hpp"
#include "PX2Character.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Buf, DisableBuf);
PX2_IMPLEMENT_STREAM(DisableBuf);
PX2_IMPLEMENT_FACTORY(DisableBuf);
PX2_IMPLEMENT_DEFAULT_NAMES(Buf, DisableBuf);

//----------------------------------------------------------------------------
DisableBuf::DisableBuf ()
{
}
//----------------------------------------------------------------------------
DisableBuf::~DisableBuf ()
{
}
//----------------------------------------------------------------------------
DisableBuf *DisableBuf::Create ()
{
	return new0 DisableBuf();
}
//----------------------------------------------------------------------------
void DisableBuf::Update (double appSeconds, double elapsedSeconds)
{
	Buf::Update(appSeconds, elapsedSeconds);

	mCharacter->Freeze(true);
}
//----------------------------------------------------------------------------
void DisableBuf::OnAdded ()
{
	Buf::OnAdded();

	mCharacter->Freeze(true);
}
//----------------------------------------------------------------------------
void DisableBuf::OnRemoved ()
{
	Buf::OnRemoved();

	mCharacter->Freeze(false);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
DisableBuf::DisableBuf (LoadConstructor value)
	:
Buf(value)
{
}
//----------------------------------------------------------------------------
void DisableBuf::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Buf::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(DisableBuf, source);
}
//----------------------------------------------------------------------------
void DisableBuf::Link (InStream& source)
{
	Buf::Link(source);
}
//----------------------------------------------------------------------------
void DisableBuf::PostLink ()
{
	Buf::PostLink();
}
//----------------------------------------------------------------------------
bool DisableBuf::Register (OutStream& target) const
{
	if (Buf::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void DisableBuf::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Buf::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(DisableBuf, target);
}
//----------------------------------------------------------------------------
int DisableBuf::GetStreamingSize (Stream &stream) const
{
	int size = Buf::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------