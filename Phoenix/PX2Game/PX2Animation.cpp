/*
*
* 文件名称	：	PX2Animation.cpp
*
*/

#include "PX2Animation.hpp"
#include "PX2Character.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Gameable, Animation);
PX2_IMPLEMENT_STREAM(Animation);
PX2_IMPLEMENT_ABSTRACT_FACTORY(Animation);
PX2_IMPLEMENT_DEFAULT_NAMES(Gameable, Animation);

//----------------------------------------------------------------------------
Animation::Animation ()
{
}
//----------------------------------------------------------------------------
Animation::Animation (AnimType type)
	:
mAnimType(type),
mAnimNormalTime(0.0f),
mAnimTime(0.0f),
mFrequency(1.0f),
mIsPlayOnce(false),
mIsPlayedKeepPlaying(false),
mIsAnimPlaying(false),
mAnimPlayedTime(0.0f),
mCharacter(0)
{
}
//----------------------------------------------------------------------------
Animation::~Animation ()
{
}
//----------------------------------------------------------------------------
void Animation::Update (double appSeconds, double elapsedSeconds)
{
	PX2_UNUSED(appSeconds);

	if (mIsAnimPlaying)
	{
		mAnimPlayedTime += (float)elapsedSeconds;

		if (mIsPlayOnce)
		{
			if (mAnimPlayedTime>mAnimTime && !mIsPlayedKeepPlaying)
			{
				mIsAnimPlaying = false;
			}
		}
	}
}
//----------------------------------------------------------------------------
void Animation::SetTime (float time)
{
	mAnimTime = time;
}
//----------------------------------------------------------------------------
void Animation::SetFrequency (float frequency)
{
	mFrequency = frequency;
}
//----------------------------------------------------------------------------
void Animation::SetFilename (const std::string &filename)
{
	mAnimFilename = filename;
}
//----------------------------------------------------------------------------
void Animation::SetPlayOnce (bool once)
{
	mIsPlayOnce = once;
}
//----------------------------------------------------------------------------
bool Animation::IsPlaying () const
{
	return mIsAnimPlaying;
}
//----------------------------------------------------------------------------
void Animation::Stop ()
{
	mIsAnimPlaying = false;
}
//----------------------------------------------------------------------------
void Animation::SaveToXMLNode (XMLNode nodeParent)
{
	XMLNode nodeClass = nodeParent.NewChild("Class");
	nodeClass.SetAttributeString("Type", "Animation");

	Gameable::SaveToXMLNode(nodeClass);

	XMLNode nodeProperty = nodeClass.NewChild("Property");
	nodeProperty.SetAttributeInt("AnimType", (int)GetAnimType());
	nodeProperty.SetAttributeFloat("NormalTime", GetTime());
	nodeProperty.SetAttributeFloat("Time", GetTime());
	nodeProperty.SetAttributeString("Filename", GetFilename());
	nodeProperty.SetAttributeBool("IsPlayOnce", IsPlayOnce());
}
//----------------------------------------------------------------------------
void Animation::LoadFromXMLNode (XMLNode node)
{
	XMLNode nodeClass = node.GetChild("Class");
	if (!nodeClass.IsNull())
	{
		Gameable::LoadFromXMLNode(nodeClass);
	}
	else
	{
		assertion(false, "");
	}

	XMLNode nodeProperty = node.GetChild("Property");
	if (!nodeProperty.IsNull())
	{
		mAnimType = (AnimType)(nodeProperty.AttributeToInt("AnimType"));

		SetTime(nodeProperty.AttributeToFloat("Time"));

		if (nodeProperty.HasAttribute("NormalTime"))
		{
			SetNormalTime(nodeProperty.AttributeToFloat("NormalTime"));
		}
		else
		{
			SetNormalTime(GetTime());
		}

		SetFilename(nodeProperty.AttributeToString("Filename"));

		if (nodeProperty.HasAttribute("IsPlayOnce"))
		{
			SetPlayOnce(nodeProperty.AttributeToBool("IsPlayOnce"));
		}
	}
	else
	{
		assertion(false, "");
	}
}
//----------------------------------------------------------------------------
void Animation::SetCharacter (Character *character)
{
	mCharacter = character;
}
//----------------------------------------------------------------------------
void Animation::LetCharacterPlay ()
{
	if (mCharacter)
		mCharacter->PlayAnim(this);
}
//----------------------------------------------------------------------------
void Animation::OnPlay (Character *character)
{
	PX2_UNUSED(character);

	mIsAnimPlaying = true;
	mAnimPlayedTime = 0.0f;
}
//----------------------------------------------------------------------------
void Animation::OnRemove (Character *character)
{
	PX2_UNUSED(character);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void Animation::RegistProperties ()
{
	Gameable::RegistProperties();

	AddPropertyClass("Animation");

	std::vector<std::string> animTypes;
	animTypes.push_back("AT_2DFRAMES");
	animTypes.push_back("AT_2DSKELETON");
	animTypes.push_back("AT_3DSKELETON");
	AddPropertyEnum("AnimType", (int)GetAnimType(), animTypes, false);

	AddProperty("NormalTime", PT_FLOAT, GetNormalTime());
	AddProperty("Time", PT_FLOAT, GetTime());
	AddProperty("Frequency", PT_FLOAT, GetFrequency());
	AddProperty("Filename", PT_STRINGBUTTON, GetFilename());
	AddProperty("IsPlayOnce", PT_BOOL, IsPlayOnce());
	AddProperty("IsPlayedKeepPlaying", PT_BOOL, IsPlayedKeepPlaying());
}
//----------------------------------------------------------------------------
void Animation::OnPropertyChanged (const PropertyObject &obj)
{
	Gameable::OnPropertyChanged(obj);

	if ("NormalTime" == obj.Name)
	{
		SetNormalTime(PX2_ANY_AS(obj.Data, float));
	}
	else if ("Time" == obj.Name)
	{
		SetTime(PX2_ANY_AS(obj.Data, float));
	}
	else if ("Frequency" == obj.Name)
	{
		SetFrequency(PX2_ANY_AS(obj.Data, float));
	}
	else if ("Filename" == obj.Name)
	{
		SetFilename(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("IsPlayOnce" == obj.Name)
	{
		SetPlayOnce(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("IsPlayedKeepPlaying" == obj.Name)
	{
		SetPlayedKeepPlaying(PX2_ANY_AS(obj.Data, bool));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Animation::Animation (LoadConstructor value)
	:
Gameable(value),
mAnimType(AT_2DFRAMES),
mAnimNormalTime(0.0f),
mAnimTime(0.0f),
mFrequency(1.0f),
mIsPlayOnce(false),
mIsPlayedKeepPlaying(false),
mIsAnimPlaying(false),
mAnimPlayedTime(0.0f),
mCharacter(0)
{
}
//----------------------------------------------------------------------------
void Animation::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Gameable::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadEnum(mAnimType);
	source.Read(mAnimNormalTime);
	source.Read(mAnimTime);
	source.ReadString(mAnimFilename);
	source.Read(mFrequency);
	source.ReadBool(mIsPlayOnce);

	PX2_END_DEBUG_STREAM_LOAD(Animation, source);
}
//----------------------------------------------------------------------------
void Animation::Link (InStream& source)
{
	Gameable::Link(source);
}
//----------------------------------------------------------------------------
void Animation::PostLink ()
{
	Gameable::PostLink();

	SetFilename(mAnimFilename);
}
//----------------------------------------------------------------------------
bool Animation::Register (OutStream& target) const
{
	if (Gameable::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void Animation::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Gameable::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteEnum(mAnimType);
	target.Write(mAnimNormalTime);
	target.Write(mAnimTime);
	target.WriteString(mAnimFilename);
	target.Write(mFrequency);
	target.WriteBool(mIsPlayOnce);

	PX2_END_DEBUG_STREAM_SAVE(Animation, target);
}
//----------------------------------------------------------------------------
int Animation::GetStreamingSize (Stream &stream) const
{
	int size = Gameable::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_ENUMSIZE(mAnimType);
	size += sizeof(mAnimNormalTime);
	size += sizeof(mAnimTime);
	size += PX2_STRINGSIZE(mAnimFilename);
	size += sizeof(mFrequency);
	size += PX2_BOOLSIZE(mIsPlayOnce);

	return size;
}
//----------------------------------------------------------------------------