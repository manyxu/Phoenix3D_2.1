/*
*
* 文件名称	：	PX2Animation.cpp
*
*/

#include "PX2Animation.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Object, Animation);
PX2_IMPLEMENT_STREAM(Animation);
PX2_IMPLEMENT_ABSTRACT_FACTORY(Animation);
PX2_IMPLEMENT_DEFAULT_NAMES(Object, Animation);

//----------------------------------------------------------------------------
Animation::Animation() :
mAnimType(AT_MAX_TYPE),
mTime(0.0f),
mFrequency(1.0f),
mIsPlayOnce(false),
mIsPlayedKeepPlaying(false),
mIsPlaying(false),
mPlayedTime(0.0f)
{
}
//----------------------------------------------------------------------------
Animation::Animation(AnimType type) :
mAnimType(type),
mTime(0.0f),
mFrequency(1.0f),
mIsPlayOnce(false),
mIsPlayedKeepPlaying(false),
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
			if (mPlayedTime > mTime && !mIsPlayedKeepPlaying)
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
	mTime = time;
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
void Animation::OnPlay (Actor *actor)
{
	PX2_UNUSED(actor);

	mIsPlaying = true;
	mPlayedTime = 0.0f;
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
	mAnimType(AT_MAX_TYPE),
	mTime(0.0f),
	mFrequency(1.0f),
	mIsPlayOnce(false),
	mIsPlayedKeepPlaying(false),
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

	PX2_END_DEBUG_STREAM_SAVE(Animation, target);
}
//----------------------------------------------------------------------------
int Animation::GetStreamingSize(Stream &stream) const
{
	int size = Object::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------