/*
*
* 文件名称	：	PX2FreezeBuf.cpp
*
*/

#include "PX2GroupBuf.hpp"
#include "PX2Character.hpp"
#include "PX2Project.hpp"
#include "PX2Scene.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Buf, GroupBuf);
PX2_IMPLEMENT_STREAM(GroupBuf);
PX2_IMPLEMENT_FACTORY(GroupBuf);
PX2_IMPLEMENT_DEFAULT_NAMES(Buf, GroupBuf);

//----------------------------------------------------------------------------
GroupBuf::GroupBuf ()
	:
mToGroupCharacterID(-1),
mBeforeGroup(-1)
{
}
//----------------------------------------------------------------------------
GroupBuf::~GroupBuf ()
{
}
//----------------------------------------------------------------------------
GroupBuf *GroupBuf::Create ()
{
	return new0 GroupBuf();
}
//----------------------------------------------------------------------------
void GroupBuf::Update (double appSeconds, double elapsedSeconds)
{
	Buf::Update(appSeconds, elapsedSeconds);

	Scene *scene = PX2_PROJ.GetScene();
	Character *targetChar = DynamicCast<Character>(scene->GetActorByID(mToGroupCharacterID));
	if (targetChar)
	{
		mCharacter->SetGroup(targetChar->GetGroup());

		if (targetChar->IsDead() || targetChar->IsFreezed())
			SetOver(true);
	}
	else
	{
		SetOver(true);
	}
}
//----------------------------------------------------------------------------
void GroupBuf::OnAdded ()
{
	Buf::OnAdded();

	mBeforeGroup = mCharacter->GetGroup();

	Scene *scene = PX2_PROJ.GetScene();
	Character *targetChar = DynamicCast<Character>(scene->GetActorByID(mToGroupCharacterID));
	if (targetChar)
	{
		mCharacter->SetGroup(targetChar->GetGroup());
	}
	else
	{
		SetOver(true);
	}
}
//----------------------------------------------------------------------------
void GroupBuf::OnRemoved ()
{
	Buf::OnRemoved();

	mCharacter->SetGroup(mBeforeGroup);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
GroupBuf::GroupBuf (LoadConstructor value)
	:
Buf(value),
mToGroupCharacterID(-1),
mBeforeGroup(-1)
{
}
//----------------------------------------------------------------------------
void GroupBuf::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Buf::Load(source);
	PX2_VERSION_LOAD(source);

	source.Read(mToGroupCharacterID);
	source.Read(mBeforeGroup);

	PX2_END_DEBUG_STREAM_LOAD(GroupBuf, source);
}
//----------------------------------------------------------------------------
void GroupBuf::Link (InStream& source)
{
	Buf::Link(source);
}
//----------------------------------------------------------------------------
void GroupBuf::PostLink ()
{
	Buf::PostLink();
}
//----------------------------------------------------------------------------
bool GroupBuf::Register (OutStream& target) const
{
	if (Buf::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void GroupBuf::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Buf::Save(target);
	PX2_VERSION_SAVE(target);

	target.Write(mToGroupCharacterID);
	target.Write(mBeforeGroup);

	PX2_END_DEBUG_STREAM_SAVE(GroupBuf, target);
}
//----------------------------------------------------------------------------
int GroupBuf::GetStreamingSize (Stream &stream) const
{
	int size = Buf::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += sizeof(mToGroupCharacterID);
	size += sizeof(mBeforeGroup);

	return size;
}
//----------------------------------------------------------------------------