/*
*
* 文件名称	：	PX2Animation3DSkeleton.cpp
*
*/

#include "PX2Animation3DSkeleton.hpp"
#include "PX2Character.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2Movable.hpp"
#include "PX2TriMesh.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Animation, Animation3DSkeleton);
PX2_IMPLEMENT_STREAM(Animation3DSkeleton);
PX2_IMPLEMENT_FACTORY(Animation3DSkeleton);
PX2_IMPLEMENT_DEFAULT_NAMES(Animation, Animation3DSkeleton);

//----------------------------------------------------------------------------
Animation3DSkeleton::Animation3DSkeleton (const std::string &name,
	const std::string &animTagName)
	:
Animation(Animation::AT_3DSKELETON)
{
	SetName(name);
	SetTagName(animTagName);
}
//----------------------------------------------------------------------------
Animation3DSkeleton::~Animation3DSkeleton ()
{
}
//----------------------------------------------------------------------------
void Animation3DSkeleton::Stop ()
{
	Animation::Stop();
}
//----------------------------------------------------------------------------
bool Animation3DSkeleton::IsPlaying () const
{
	return Animation::IsPlaying();
}
//----------------------------------------------------------------------------
void Animation3DSkeleton::SetTime (float time)
{
	Animation::SetTime(time);
}
//----------------------------------------------------------------------------
void Animation3DSkeleton::SetFrequency (float frequency)
{
	Animation::SetFrequency(frequency);

	std::map<FString, KeyframeControllerPtr>::iterator it = mKeyframeCtrlMap.begin();
	for (; it!=mKeyframeCtrlMap.end(); it++)
	{
		KeyframeController *kfc = it->second;
		if (kfc)
		{
			kfc->Frequency = frequency;
		}
	}
}
//----------------------------------------------------------------------------
void Animation3DSkeleton::SetTagName (const std::string &tagName)
{
	mTagName = tagName;

	SetCharacter(mCharacter);
}
//----------------------------------------------------------------------------
void Animation3DSkeleton::SetFilename (const std::string &filename)
{
	if (filename.empty())
		return;

	Animation::SetFilename(filename);

	NodePtr animObject = DynamicCast<Node>(PX2_RM.BlockLoadCopy(filename));
	if (!animObject)
		return;

	for (int i=0; i<animObject->GetNumChildren(); i++)
	{
		Movable *mov = animObject->GetChild(i);
		Node *node = DynamicCast<Node>(mov);
		Renderable *renderable = DynamicCast<Renderable>(mov);
		if (node && !renderable && !Character::IsNodeHasMesh(node) && node->GetNumValidChildren()>0)
		{
			mAnimNode = node;
		}
	}
	animObject->DetachChild(mAnimNode);

	if (mCharacter && mCharacter->GetCurPlayingAnim()==this)
	{
		LetCharacterPlay();
	}
}
//----------------------------------------------------------------------------
void Animation3DSkeleton::SetPlayOnce (bool once)
{
	Animation::SetPlayOnce(once);

	std::map<FString, KeyframeControllerPtr>::iterator it = mKeyframeCtrlMap.begin();
	for (; it!=mKeyframeCtrlMap.end(); it++)
	{
		KeyframeController *kfc = it->second;
		if (kfc)
		{
			kfc->Repeat = once ? Controller::RT_CLAMP:Controller::RT_WRAP;
		}
	}
}
//----------------------------------------------------------------------------
void Animation3DSkeleton::OnPlay (Character *character)
{
	if (mKeyframeCtrlMap.empty())
	{
		SetCharacter(character);
	}

	if (mKeyframeCtrlMap.empty())
		return;

	Animation::OnPlay(character);

	Movable *charMov = character->GetMovable();
	Node *charNode = DynamicCast<Node>(charMov);

	if (mAnimNode)
	{
		SetFrequency(GetFrequency());
		SetPlayOnce(IsPlayOnce());
	}

	std::map<FString, KeyframeControllerPtr>::iterator it = mKeyframeCtrlMap.begin();
	for (; it!=mKeyframeCtrlMap.end(); it++)
	{
		KeyframeController *kfc = it->second;
		if (kfc)
		{
			kfc->ResetPlay();
		}
	}
}
//----------------------------------------------------------------------------
void Animation3DSkeleton::_CollectKFC (Movable *mov, const std::string &animTagName,
	const std::string &modelTagName)
{
	if (!mov) return;
	
	std::string nodeName = mov->GetName();

	if (!animTagName.empty())
		nodeName = nodeName.substr(animTagName.length(), nodeName.length()-animTagName.length());
	nodeName = modelTagName + nodeName;

	int numContrls = mov->GetNumControllers();
	if (1 == numContrls)
	{
		KeyframeController *kfc = DynamicCast<KeyframeController>(mov->GetController(0));
		if (kfc)
		{
			mKeyframeCtrlMap[FString(nodeName.c_str())] = kfc;
		}
	}
	else if (0 == numContrls)
	{
		KeyframeController *kfc = new0 KeyframeController(0, 0, 0, 0, mov->LocalTransform);
		mov->AttachController(kfc);
		mKeyframeCtrlMap[FString(nodeName.c_str())] = kfc;
		kfc->SetName("KeyframeController");
	}
	else
	{
		assertion(false, "");
	}

	Node *node = DynamicCast<Node>(mov);
	if (node)
	{
		for (int i=0; i<node->GetNumChildren(); i++)
		{
			_CollectKFC(node->GetChild(i), animTagName, modelTagName);
		}
	}
}
//----------------------------------------------------------------------------
void Animation3DSkeleton::SetCharacter (Character *character)
{
	Animation::SetCharacter(character);

	if (!character)
		return;

	const std::string &modelTagname = character->GetModelTagName();

	mKeyframeCtrlMap.clear();
	_CollectKFC(mAnimNode, mTagName, modelTagname);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void Animation3DSkeleton::RegistProperties ()
{
	Animation::RegistProperties();

	AddPropertyClass("Animation3DSkeleton");

	AddProperty("TagName", PT_STRING, GetTagName());
}
//----------------------------------------------------------------------------
void Animation3DSkeleton::OnPropertyChanged (const PropertyObject &obj)
{
	Animation::OnPropertyChanged(obj);

	if ("TagName" == obj.Name)
	{
		SetTagName(PX2_ANY_AS(obj.Data, std::string));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Animation3DSkeleton::Animation3DSkeleton (LoadConstructor value)
	:
Animation(value)
{
}
//----------------------------------------------------------------------------
void Animation3DSkeleton::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Animation::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadString(mTagName);

	PX2_END_DEBUG_STREAM_LOAD(Animation3DSkeleton, source);
}
//----------------------------------------------------------------------------
void Animation3DSkeleton::Link (InStream& source)
{
	Animation::Link(source);
}
//----------------------------------------------------------------------------
void Animation3DSkeleton::PostLink ()
{
	Animation::PostLink();
}
//----------------------------------------------------------------------------
bool Animation3DSkeleton::Register (OutStream& target) const
{
	if (Animation::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void Animation3DSkeleton::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Animation::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteString(mTagName);

	PX2_END_DEBUG_STREAM_SAVE(Animation3DSkeleton, target);
}
//----------------------------------------------------------------------------
int Animation3DSkeleton::GetStreamingSize (Stream &stream) const
{
	int size = Animation::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	size += PX2_STRINGSIZE(mTagName);

	return size;
}
//----------------------------------------------------------------------------