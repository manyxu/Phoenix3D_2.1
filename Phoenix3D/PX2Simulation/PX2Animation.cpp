// PX2Animation.cpp

#include "PX2Animation.hpp"
#include "PX2Character.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Object, Animation);
PX2_IMPLEMENT_STREAM(Animation);
PX2_IMPLEMENT_ABSTRACT_FACTORY(Animation);
PX2_IMPLEMENT_DEFAULT_NAMES(Object, Animation);

//----------------------------------------------------------------------------
Animation::Animation() :
mCharacter(0),
mAnimType(AT_MAX_TYPE),
mAnimTime(0.0f),
mFrequency(1.0f),
mIsPlayOnce(false),
mIsPlayedKeepPlaying(false),
mIsUseBlend(true),
mIsPlaying(false),
mPlayedTime(0.0f)
{
}
//----------------------------------------------------------------------------
Animation::Animation(AnimType type) :
mCharacter(0),
mAnimType(type),
mAnimTime(0.0f),
mFrequency(1.0f),
mIsPlayOnce(false),
mIsPlayedKeepPlaying(false),
mIsUseBlend(true),
mIsPlaying(false),
mPlayedTime(0.0f)
{
}
//----------------------------------------------------------------------------
Animation::~Animation()
{
}
//----------------------------------------------------------------------------
void Animation::Update(float appSeconds, float elapsedSeconds)
{
	PX2_UNUSED(appSeconds);

	if (mIsPlaying)
	{
		mPlayedTime += elapsedSeconds;

		if (mIsPlayOnce)
		{
			if (!mIsPlayedKeepPlaying && mPlayedTime > mAnimTime)
			{
				mIsPlaying = false;
			}
		}
	}
}
//----------------------------------------------------------------------------
void Animation::SetFilename(const std::string &filename)
{
	mFilename = filename;
}
//----------------------------------------------------------------------------
void Animation::SetTime(float time)
{
	mAnimTime = time;
}
//----------------------------------------------------------------------------
void Animation::SetFrequency(float frequency)
{
	mFrequency = frequency;
}
//----------------------------------------------------------------------------
void Animation::SetPlayOnce(bool once)
{
	mIsPlayOnce = once;
}
//----------------------------------------------------------------------------
bool Animation::IsPlaying() const
{
	return mIsPlaying;
}
//----------------------------------------------------------------------------
void Animation::Stop()
{
	mIsPlaying = false;
}
//----------------------------------------------------------------------------
void Animation::LetCharacterPlay()
{
	if (mCharacter)
		mCharacter->PlayAnim(this);
}
//----------------------------------------------------------------------------
void Animation::OnPlay (Character *actor)
{
	PX2_UNUSED(actor);

	mIsPlaying = true;
	mPlayedTime = 0.0f;
}
//----------------------------------------------------------------------------
void Animation::OnRemove(Character *character)
{
}
//----------------------------------------------------------------------------
void Animation::SetCharacter(Character *character)
{
	mCharacter = character;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void Animation::RegistProperties()
{
	Object::RegistProperties();

	AddPropertyClass("Animation");
}
//----------------------------------------------------------------------------
void Animation::OnPropertyChanged(const PropertyObject &obj)
{
	Object::OnPropertyChanged(obj);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Animation::Animation(LoadConstructor value) :
Object(value),
mCharacter(0),
mAnimType(AT_MAX_TYPE),
mAnimTime(0.0f),
mFrequency(1.0f),
mIsPlayOnce(false),
mIsPlayedKeepPlaying(false),
mIsUseBlend(true),
mIsPlaying(false),
mPlayedTime(0.0f)
{
}
//----------------------------------------------------------------------------
void Animation::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Object::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadEnum(mAnimType);
	source.ReadString(mFilename);
	source.Read(mAnimNormalTime);
	source.Read(mAnimTime);
	source.Read(mFrequency);
	source.ReadBool(mIsPlayOnce);
	source.ReadBool(mIsPlayedKeepPlaying);
	source.ReadBool(mIsUseBlend);

	PX2_END_DEBUG_STREAM_LOAD(Animation, source);
}
//----------------------------------------------------------------------------
void Animation::Link(InStream& source)
{
	Object::Link(source);
}
//----------------------------------------------------------------------------
void Animation::PostLink()
{
	Object::PostLink();
}
//----------------------------------------------------------------------------
bool Animation::Register(OutStream& target) const
{
	if (Object::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void Animation::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Object::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteEnum(mAnimType);
	target.WriteString(mFilename);
	target.Write(mAnimNormalTime);
	target.Write(mAnimTime);
	target.Write(mFrequency);
	target.WriteBool(mIsPlayOnce);
	target.WriteBool(mIsPlayedKeepPlaying);
	target.WriteBool(mIsUseBlend);

	PX2_END_DEBUG_STREAM_SAVE(Animation, target);
}
//----------------------------------------------------------------------------
int Animation::GetStreamingSize(Stream &stream) const
{
	int size = Object::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_ENUMSIZE(mAnimType);
	size += PX2_STRINGSIZE(mFilename);
	size += sizeof(mAnimNormalTime);
	size += sizeof(mAnimTime);
	size += sizeof(mFrequency);
	size += PX2_BOOLSIZE(mIsPlayOnce);
	size += PX2_BOOLSIZE(mIsPlayedKeepPlaying);
	size += PX2_BOOLSIZE(mIsUseBlend);

	return size;
}
//----------------------------------------------------------------------------