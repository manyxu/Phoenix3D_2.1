// ScoreCharacter.cpp

#include "SampleCharacter.hpp"
#include "PX2AnimationFrames.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Character, SampleChara);
PX2_IMPLEMENT_STREAM(SampleChara);
PX2_IMPLEMENT_FACTORY(SampleChara);
PX2_IMPLEMENT_DEFAULT_NAMES(Actor, SampleChara);

//----------------------------------------------------------------------------
SampleChara::SampleChara()
{
	Node *helpNode = GetNodeHelp();
	if (helpNode) helpNode->Show(false);

	SetAnimType(AT_FRAMES);

	Node *rootNode = new0 Node();
	AttachChild(rootNode);
	rootNode->SetName("RootNode");

	Node *animNode = new0 Node();
	rootNode->AttachChild(animNode);
	animNode->SetName("AnimNode");

	AnimationFrames *anim = new0 AnimationFrames();
	anim->SetFilename("Data/Sample/images/wbdz/wbdz_Move/wbdz_Move.xml");
	AddAnim(anim);

	//SetHeading(AVector::UNIT_X);
	PlayAnim(anim);
}
//----------------------------------------------------------------------------
SampleChara::~SampleChara()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
SampleChara::SampleChara(LoadConstructor value) :
Character(value)
{
}
//----------------------------------------------------------------------------
void SampleChara::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Character::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(SampleChara, source);
}
//----------------------------------------------------------------------------
void SampleChara::Link(InStream& source)
{
	Character::Link(source);
}
//----------------------------------------------------------------------------
void SampleChara::PostLink()
{
	Character::PostLink();
}
//----------------------------------------------------------------------------
bool SampleChara::Register(OutStream& target) const
{
	if (Character::Register(target))
		return true;

	return false;
}
//----------------------------------------------------------------------------
void SampleChara::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Character::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(Character, target);
}
//----------------------------------------------------------------------------
int SampleChara::GetStreamingSize(Stream &stream) const
{
	int size = Character::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------