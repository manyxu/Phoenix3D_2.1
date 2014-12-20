/*
*
* 文件名称	：	PX2Animation.cpp
*
*/

#include "PX2Animation2DFrames8.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2Character.hpp"
#include "PX2Character2DFrames8.hpp"
#include "PX2Project.hpp"
#include "PX2A2DF8_Mesh.hpp"
#include "PX2GameManager.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Animation, Animation2DFrames8);
PX2_IMPLEMENT_STREAM(Animation2DFrames8);
PX2_IMPLEMENT_FACTORY(Animation2DFrames8);
PX2_IMPLEMENT_DEFAULT_NAMES(Animation, Animation2DFrames8);

//----------------------------------------------------------------------------
Animation2DFrames8::Animation2DFrames8 ()
	:
Animation(Animation::AT_2DFRAMES),
mNumFramePerDir(0),
mInterval(0.1f)
{
}
//----------------------------------------------------------------------------
Animation2DFrames8::~Animation2DFrames8 ()
{
}
//----------------------------------------------------------------------------
void Animation2DFrames8::Stop ()
{
	Animation::Stop();

	if (mMesh)
		mMesh->Stop();
}
//----------------------------------------------------------------------------
bool Animation2DFrames8::IsPlaying () const
{
	if (Animation::IsPlaying())
		return true;

	if (mMesh)
		return mMesh->IsPlaying();

	return false;
}
//----------------------------------------------------------------------------
void Animation2DFrames8::SetTime (float time)
{
	Animation::SetTime(time);

	if (0 == mNumFramePerDir)
		mNumFramePerDir = 1;

	mInterval = GetTime()/mNumFramePerDir;

	SetInterval(mInterval);

	SetPlayOnce(IsPlayOnce());
}
//----------------------------------------------------------------------------
void Animation2DFrames8::SetInterval (float interval)
{
	mInterval = interval;

	if (mMesh)
		mMesh->SetInterval(interval);

	Animation::SetTime(mInterval * mNumFramePerDir);
}
//----------------------------------------------------------------------------
void Animation2DFrames8::SetAnimSize (float size)
{
	if (mMesh)
		mMesh->SetSize(size);
}
//----------------------------------------------------------------------------
void Animation2DFrames8::SetFilename (const std::string &texPackFilename)
{
	Animation::SetFilename(texPackFilename);

	if (texPackFilename.empty())
		return;

	mMesh = new0 A2DF8_Mesh();
	mNumFramePerDir = mMesh->SetTexPack(texPackFilename);

	SetInterval(mInterval);
	SetPlayOnce(mIsPlayOnce);

	if (mCharacter && mCharacter->GetCurPlayingAnim()==this)
	{
		LetCharacterPlay();
	}
}
//----------------------------------------------------------------------------
void Animation2DFrames8::SetColor (const Float3 &color)
{
	PX2_UNUSED(color);
}
//----------------------------------------------------------------------------
void Animation2DFrames8::SetPlayOnce (bool once)
{
	Animation::SetPlayOnce(once);

	if (mMesh)
		mMesh->SetPlayOnce(once);
}
//----------------------------------------------------------------------------
void Animation2DFrames8::OnPlay (Character *character)
{
	Animation::OnPlay(character);

	Character2DFrames8 * bios = DynamicCast<Character2DFrames8>(character);
	if (bios)
	{
		const AVector &dir = bios->GetHeading();
		bios->GetAnimNode()->DetachAllChildren();

		if (mMesh)
			bios->GetAnimNode()->AttachChild(mMesh);

		SetAnimSize(bios->GetAnimSize());
		SetWorldRunDir(dir);

		if (mMesh)
			mMesh->ResetPlay();
	}
	else
	{
		assertion(false, "Animation2DFrames8::OnPlay must be Character2DFrames8");
		PX2_LOG_INFO("Animation2DFrames8::OnPlay must be Character2DFrames8");
	}
}
//----------------------------------------------------------------------------
void Animation2DFrames8::OnRemove (Character *character)
{
	Character2DFrames8 * bios = DynamicCast<Character2DFrames8>(character);
	if (bios)
	{
		bios->GetAnimNode()->DetachChild(mMesh);
	}
	else
	{
		assertion(false, "Animation2DFrames8::OnRemove must be Character2DFrames8");
		PX2_LOG_INFO("Animation2DFrames8::OnRemove must be Character2DFrames8");
	}
}
//----------------------------------------------------------------------------
void Animation2DFrames8::SetWorldRunDir (const AVector &vec)
{
	mWorldRunDir = vec;

	if (mMesh)
		mMesh->SetWorldRunDir(mWorldRunDir);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void Animation2DFrames8::RegistProperties ()
{
	Animation::RegistProperties();
	AddPropertyClass("Animation2DFrames8");

	AddProperty("Interval", PT_FLOAT, GetInterval());
	AddProperty("NumFramesPerDir", PT_INT, GetNumFramesPerDir(), false);
	AddProperty("WorldRunDir", PT_AVECTOR3, GetWorldRunDir());
}
//----------------------------------------------------------------------------
void Animation2DFrames8::OnPropertyChanged (const PropertyObject &obj)
{
	Animation::OnPropertyChanged(obj);
	
	if ("Interval" == obj.Name)
	{
		SetInterval(PX2_ANY_AS(obj.Data, float));
	}
	else if ("WorldRunDir" == obj.Name)
	{
		SetWorldRunDir(PX2_ANY_AS(obj.Data, AVector));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Animation2DFrames8::Animation2DFrames8 (LoadConstructor value)
	:
Animation(value),
mNumFramePerDir(0),
mInterval(0.1f)
{
}
//----------------------------------------------------------------------------
void Animation2DFrames8::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Animation::Load(source);
	PX2_VERSION_LOAD(source);

	source.Read(mInterval);
	source.Read(mNumFramePerDir);

	PX2_END_DEBUG_STREAM_LOAD(Animation2DFrames8, source);
}
//----------------------------------------------------------------------------
void Animation2DFrames8::Link (InStream& source)
{
	Animation::Link(source);
}
//----------------------------------------------------------------------------
void Animation2DFrames8::PostLink ()
{
	Animation::PostLink();
}
//----------------------------------------------------------------------------
bool Animation2DFrames8::Register (OutStream& target) const
{
	if (Animation::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void Animation2DFrames8::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Animation::Save(target);
	PX2_VERSION_SAVE(target);

	target.Write(mInterval);
	target.Write(mNumFramePerDir);

	PX2_END_DEBUG_STREAM_SAVE(Animation2DFrames8, target);
}
//----------------------------------------------------------------------------
int Animation2DFrames8::GetStreamingSize (Stream &stream) const
{
	int size = Animation::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += sizeof(mInterval);
	size += sizeof(mNumFramePerDir);

	return size;
}
//----------------------------------------------------------------------------