// X_Def.cpp

#include "X_Def.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
AnimDef::AnimDef() :
AnimID(0),
Num(0),
Hit(0)
{
}
//----------------------------------------------------------------------------
AnimDef::~AnimDef()
{

}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
std::string ModelDef::sAnimTypeStrs[ModelDef::AT_MAXTYPE] =
{
	"stand",
	"free",
	"walk",
	"run",
	"fight",
	"death",
	"sleep",
	"hitted",
	"born"
};
//----------------------------------------------------------------------------
ModelDef::ModelDef()
	:
	ModelID(0),
	IconID(0),
	SkinID(0),
	SkinID1(0),
	SkinID2(0)
{
}
//----------------------------------------------------------------------------
ModelDef::~ModelDef()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
ActorDef::ActorDef() :
ActorID(0),
ModelID(0)
{
}
//----------------------------------------------------------------------------
ActorDef::~ActorDef()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
SkillStatusDef::SkillStatusDef()
	:
	StatusID(0),
	StatusRand(0.0f),
	StatusTarget(0)
{
}
//----------------------------------------------------------------------------
SkillStatusDef::~SkillStatusDef()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
SkillDef::SkillDef() :
SkillID(0),
IconID(0),
SkillLevel(0),
CD(0.0f),
AnimTime(0.0f),
SkillType(0),
TargetDistance(0.0f),
RangeType(0),
RangeValue(0.0f),
UseMP(0.0f),
CallAnim(0),
ActAnim(0),
ActAnimRand(0.0f),
ActAnim1(0),
ActAnimRand1(0.0f),
ActPosEffectDelayTime(0.0f),
ActPosEffectDelayTime1(0.0f),
FlySpeed(1.0f),
FlyDegree(0.0f),
FlyAlignTrace(false),
IsFlyRoadLine(true),
FlyRoadLineTime(1.0f),
AtkedAnchor(0),
HurtRatio(0.0f),
HurtAdd(0.0f),
AbsoluteHit(0),
NextSkillID(0),
ClickIntervalTime(0.0f),
MoveDistance(0.0f),
MoveTimePoint(0.0f)
{
}
//----------------------------------------------------------------------------
SkillDef::~SkillDef()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
ItemDef::ItemDef() :
ItemID(0),
ModelID(0),
SkinID(0),
AnchorID(0),
EffectID(0)
{
}
//----------------------------------------------------------------------------
ItemDef::~ItemDef()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
MapDef::MapDef() :
MapID(0),
ResID(0)
{
}
//----------------------------------------------------------------------------
MapDef::~MapDef()
{

}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
MonsterSkillDef::MonsterSkillDef()
	:
	SkillID(0),
	SkillID_ConditionID(0),
	SkillID_ConditionValue(0.0f),
	SkillID_IsRepeat(0)
{
}
//----------------------------------------------------------------------------
MonsterSkillDef::~MonsterSkillDef()
{

}
//----------------------------------------------------------------------------
DropBagDef::DropBagDef() :
DropBagID(0),
DropRand(0.0f),
MFType(0)
{
}
//----------------------------------------------------------------------------
DropBagDef::~DropBagDef()
{
}
//----------------------------------------------------------------------------
MonsterDef::MonsterDef() :
MonID(0),
ModelID(0),
ModelSize(0.0f),
ModelRadius(0.0f),
Mon_Type(0),
Level(0.0f),
HP(0.0f),
MP(0.0f),
Atk(0.0f),
Def(0.0f),
AtkSpeed(0.0f),
Crit(0.0f),
Crit_Hurt(0.0f),
Hit(0.0f),
Flee(0.0f),
AtkType(0),
GuardView(0.0f),
MoveType(0),
PatrolMoveSpeed(0),
FightMoveSpeed(0),
ModelChangeRequire(0),
ModelChangeValue(0.0f),
ModelChangeMonID(0)
{
}
//----------------------------------------------------------------------------
MonsterDef::~MonsterDef()
{

}
//----------------------------------------------------------------------------