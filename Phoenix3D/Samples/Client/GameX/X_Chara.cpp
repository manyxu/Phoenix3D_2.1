// X_Chara.cpp

#include "X_Chara.hpp"
#include "X_Event.hpp"
#include "PX2Project.hpp"
#include "PX2AddDeleteManager.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Character, X_Chara);
PX2_IMPLEMENT_STREAM(X_Chara);
PX2_IMPLEMENT_FACTORY(X_Chara);
PX2_IMPLEMENT_DEFAULT_NAMES(Character, X_Chara);

//----------------------------------------------------------------------------
X_Chara::X_Chara(CharaType type) :
mActorDef(0),
mModelDef(0),
mCurLevelExp(0),
mGold(0),
mNewPlayerGuideID(0),
mNumMaxBag(0),
mIsModelLoaded(false),
mIsAnimsLoaded(false),
mCurDefPartSkillIndex(-1),
mCollectPartSkillNum(0),
mIsHardStraight(false),
mHardStraightETime(0.0f)
{
	SetCharType(type);

	ConstructInit();

	if (type == CT_PLAYER)
	{
		SetGroup(1);
	}
	else if (type == CT_MONSTER)
	{
		SetGroup(2);
	}
}
//----------------------------------------------------------------------------
X_Chara::X_Chara()
{
}
//----------------------------------------------------------------------------
X_Chara::~X_Chara()
{
}
//----------------------------------------------------------------------------
void X_Chara::ConstructInit()
{
}
//----------------------------------------------------------------------------
void X_Chara::SetCharType(CharaType type)
{
	mCharType = type;
}
//----------------------------------------------------------------------------
void X_Chara::Update(double appSeconds, double elapsedSeconds)
{
	Character::Update(appSeconds, elapsedSeconds);
}
//----------------------------------------------------------------------------
void X_Chara::DoExecute(Event *event)
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
X_Chara::X_Chara(LoadConstructor value) :
Character(value),
mCharType(CT_PLAYER),
mActorDef(0),
mModelDef(0),
mCurLevelExp(0),
mGold(0),
mNewPlayerGuideID(0),
mNumMaxBag(0),
mCurDefPartSkillIndex(-1),
mCollectPartSkillNum(0)
{
	ConstructInit();
}
//----------------------------------------------------------------------------
void X_Chara::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Character::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(X_Chara, source);
}
//----------------------------------------------------------------------------
void X_Chara::Link(InStream& source)
{
	Character::Link(source);
}
//----------------------------------------------------------------------------
void X_Chara::PostLink()
{
	Character::PostLink();
}
//----------------------------------------------------------------------------
bool X_Chara::Register(OutStream& target) const
{
	if (Character::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void X_Chara::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Character::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(X_Chara, target);
}
//----------------------------------------------------------------------------
int X_Chara::GetStreamingSize(Stream &stream) const
{
	int size = Character::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------