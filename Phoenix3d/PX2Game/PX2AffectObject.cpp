/*
*
* ÎÄ¼þÃû³Æ	£º	PX2AffectObject.cpp
*
*/

#include "PX2AffectObject.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
AffectObject::AffectObject ()
	:
AffectCharacter(0),
AffectSkill(0),
AffectSkillInstance(0),
AffectItem(0),
AffectBuf(0),
AffectType(1),
IsCrited(false),
Value(0.0f),
LastAffectDoType(0),
LastAffectDoTypeValue(0.0f),
BeAffectCharacter(0)
{
}
//----------------------------------------------------------------------------
AffectObject::~AffectObject()
{
}
//----------------------------------------------------------------------------