// X_Skill.cpp

#include "X_Skill.hpp"
#include "X_Chara.hpp"
#include "X_DefMan.hpp"
#include "X_Chara.hpp"
#include "X_Def.hpp"
#include "X_Event.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Skill, X_Skill);
PX2_IMPLEMENT_STREAM(X_Skill);
PX2_IMPLEMENT_FACTORY(X_Skill);
PX2_IMPLEMENT_DEFAULT_NAMES(Skill, X_Skill);

//----------------------------------------------------------------------------
X_Skill::X_Skill()
	:
	mNextSkillID(0),
	mDefPartIndex(0)
{
}
//----------------------------------------------------------------------------
X_Skill::~X_Skill()
{
}
//----------------------------------------------------------------------------
bool X_Skill::Activate()
{
	return false;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// ³Ö¾Ã»¯
//----------------------------------------------------------------------------
X_Skill::X_Skill(LoadConstructor value) :
Skill(value),
mNextSkillID(0),
mDefPartIndex(0)
{
}
//----------------------------------------------------------------------------
void X_Skill::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Skill::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(X_Skill, source);
}
//----------------------------------------------------------------------------
void X_Skill::Link(InStream& source)
{
	Skill::Link(source);
}
//----------------------------------------------------------------------------
void X_Skill::PostLink()
{
	Skill::PostLink();
}
//----------------------------------------------------------------------------
bool X_Skill::Register(OutStream& target) const
{
	if (Skill::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void X_Skill::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Skill::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(X_Skill, target);
}
//----------------------------------------------------------------------------
int X_Skill::GetStreamingSize(Stream &stream) const
{
	int size = Skill::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------
