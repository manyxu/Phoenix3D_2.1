// PX2SkillStepFarTrack.cpp

#include "PX2SkillStepFarTrack.hpp"
#include "PX2Skill.hpp"
#include "PX2SkillInstance.hpp"
#include "PX2Character.hpp"
#include "PX2Scene.hpp"
#include "PX2AddDeleteManager.hpp"
#include "PX2Project.hpp"
#include "PX2SkillInstance.hpp"
#include "PX2SkillActor.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, SkillStep, SkillStepFarTrack);
PX2_IMPLEMENT_STREAM(SkillStepFarTrack);
PX2_IMPLEMENT_FACTORY(SkillStepFarTrack);
PX2_IMPLEMENT_DEFAULT_NAMES(SkillStep, SkillStepFarTrack);

//----------------------------------------------------------------------------
SkillStepFarTrack::SkillStepFarTrack() :
SkillStep(M_FLY),
mIsTrackToActor(true),
mSpeed(5.0f),
mTrackTime(0.0f),
mDegree(30.0f),
mIsAlignTrace(false),
mIsDoDamageOnTrack(false),
mDamageOnTrackFrequency(0.1f),
mCurTrackSkillInstance(0)
{
}
//----------------------------------------------------------------------------
SkillStepFarTrack::~SkillStepFarTrack()
{
}
//----------------------------------------------------------------------------
void SkillStepFarTrack::SetBeTrackToActor(bool isToActor)
{
	mIsTrackToActor = isToActor;
}
//----------------------------------------------------------------------------
void SkillStepFarTrack::SetTrackDir(const AVector &dir)
{
	mTrackDir = dir;
}
//----------------------------------------------------------------------------
void SkillStepFarTrack::SetSpeed(float speed)
{
	mSpeed = speed;
}
//----------------------------------------------------------------------------
void SkillStepFarTrack::SetDegree(float degree)
{
	mDegree = degree;
}
//----------------------------------------------------------------------------
void SkillStepFarTrack::SetDoDamageOnTrack(bool doDamgeOnTrack)
{
	mIsDoDamageOnTrack = doDamgeOnTrack;
}
//----------------------------------------------------------------------------
void SkillStepFarTrack::OnEnter(SkillInstance *instance)
{
	SkillStep::OnEnter(instance);

	Skill *skill = instance->GetSkill();
	Character *character = skill->GetCharacter();
	Scene *scene = DynamicCast<Scene>(character->GetParent());

	std::map<EffectType, SkillStep_EffectObj>::iterator it = mEffectObjs.find(ET_SELF_POS);
	if (it == mEffectObjs.end()) return;

	SkillStep_EffectObj &effectObj = it->second;

	// from
	APoint fromPos = character->GetAnchorPos(effectObj.AnchorID);

	// to
	int aimTarget = instance->GetAimTarget();
	Character *aimTargetChar = DynamicCast<Character>(scene->GetActorByID(aimTarget));
	if (aimTargetChar)
	{
		SkillActorPtr skillActor = new0 SkillActor();

		instance->AddSkillActor(aimTarget, skillActor);

		skillActor->SetID(Scene::msIDCover + scene->GetNextID());

		if (!effectObj.EffectFilename.empty())
			skillActor->SetMovableFilename(effectObj.EffectFilename);

		if (IsTrackToActor()) skillActor->SetTargetType(SkillActor::TT_ACTOR);
		else skillActor->SetTargetType(SkillActor::TT_POSITION);

		skillActor->SetCharacterGroup(character->GetGroup());
		skillActor->SetSkillTypeID(skill->GetTypeID());
		skillActor->LocalTransform.SetTranslate(fromPos);
		skillActor->SetBeginPos(fromPos);
		skillActor->SetTrackSpeed(GetSpeed());
		skillActor->SetDoDamageOnTrack(IsDoDamageOnTrack());

		if (IsTrackToActor())
		{
			skillActor->SetTargetID(instance->GetAimTarget());
		}
		else
		{
			const APoint &targetPos = aimTargetChar->LocalTransform.GetTranslate();
			AVector dir = targetPos - fromPos;
			dir.Z() = 0.0f;
			dir.Normalize();

			APoint tarPos = fromPos + dir * mSpeed * mTrackTime;

			skillActor->SetTargetPos(tarPos);
		}

		skillActor->SetDegree(GetDegree());
		skillActor->SetAlignTrace(IsAlignTrace());

		Node *helpNode = skillActor->GetNodeHelp();
		if (helpNode) helpNode->Show(false);

		scene->AttachChild(skillActor);

		skillActor->Start();
	}
}
//----------------------------------------------------------------------------
void SkillStepFarTrack::OnTrack(SkillInstance *trackInstance)
{
	PX2_UNUSED(trackInstance);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void SkillStepFarTrack::RegistProperties()
{
	SkillStep::RegistProperties();

	AddPropertyClass("SkillStepFarTrack");

	AddProperty("IsTrackToActor", PT_BOOL, IsTrackToActor());
	AddProperty("TrackDir", PT_AVECTOR3, GetTrackDir());
	AddProperty("Speed", PT_FLOAT, GetSpeed());
	AddProperty("TrackTime", PT_FLOAT, GetTrackTime());
	AddProperty("Degree", PT_FLOAT, GetDegree());
	AddProperty("IsAlignTrace", PT_BOOL, IsAlignTrace());
	AddProperty("IsDoDamageOnTrack", PT_BOOL, IsDoDamageOnTrack());
	AddProperty("ScriptHandler_OnTrack", PT_STRING, GetScriptHandler_OnTrack());
}
//----------------------------------------------------------------------------
void SkillStepFarTrack::OnPropertyChanged(const PropertyObject &obj)
{
	SkillStep::OnPropertyChanged(obj);

	if ("IsTrackToActor" == obj.Name)
	{
		SetBeTrackToActor(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("TrackDir" == obj.Name)
	{
		SetTrackDir(PX2_ANY_AS(obj.Data, AVector));
	}
	else if ("Speed" == obj.Name)
	{
		SetSpeed(PX2_ANY_AS(obj.Data, float));
	}
	else if ("TrackTime" == obj.Name)
	{
		SetTrackTime(PX2_ANY_AS(obj.Data, float));
	}
	else if ("Degree" == obj.Name)
	{
		SetDegree(PX2_ANY_AS(obj.Data, float));
	}
	else if ("IsAlignTrace" == obj.Name)
	{
		SetAlignTrace(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("IsDoDamageOnTrack" == obj.Name)
	{
		SetDoDamageOnTrack(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("ScriptHandler_OnTrack" == obj.Name)
	{
		SetScriptHandler_OnTrack(PX2_ANY_AS(obj.Data, std::string));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
SkillStepFarTrack::SkillStepFarTrack(LoadConstructor value)
:
SkillStep(value),
mIsTrackToActor(true),
mSpeed(5.0f),
mTrackTime(0.0f),
mDegree(30.0f),
mIsAlignTrace(false),
mIsDoDamageOnTrack(false),
mDamageOnTrackFrequency(0.1f),
mCurTrackSkillInstance(0)
{
}
//----------------------------------------------------------------------------
void SkillStepFarTrack::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	SkillStep::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadBool(mIsTrackToActor);
	source.ReadAggregate(mTrackDir);
	source.Read(mSpeed);
	source.Read(mTrackTime);
	source.Read(mDegree);
	source.ReadBool(mIsAlignTrace);
	source.ReadBool(mIsDoDamageOnTrack);
	source.Read(mDamageOnTrackFrequency);
	source.ReadString(mScriptHandler_OnTrack);

	PX2_END_DEBUG_STREAM_LOAD(SkillStepFarTrack, source);
}
//----------------------------------------------------------------------------
void SkillStepFarTrack::Link(InStream& source)
{
	SkillStep::Link(source);
}
//----------------------------------------------------------------------------
void SkillStepFarTrack::PostLink()
{
	SkillStep::PostLink();
}
//----------------------------------------------------------------------------
bool SkillStepFarTrack::Register(OutStream& target) const
{
	if (SkillStep::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void SkillStepFarTrack::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	SkillStep::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteBool(mIsTrackToActor);
	target.WriteAggregate(mTrackDir);
	target.Write(mSpeed);
	target.Write(mTrackTime);
	target.Write(mDegree);
	target.WriteBool(mIsAlignTrace);
	target.WriteBool(mIsDoDamageOnTrack);
	target.Write(mDamageOnTrackFrequency);
	target.WriteString(mScriptHandler_OnTrack);

	PX2_END_DEBUG_STREAM_SAVE(SkillStepFarTrack, target);
}
//----------------------------------------------------------------------------
int SkillStepFarTrack::GetStreamingSize(Stream &stream) const
{
	int size = SkillStep::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_BOOLSIZE(mIsTrackToActor);
	size += sizeof(mTrackDir);
	size += sizeof(mSpeed);
	size += sizeof(mTrackTime);
	size += sizeof(mDegree);
	size += PX2_BOOLSIZE(mIsAlignTrace);
	size += PX2_BOOLSIZE(mIsDoDamageOnTrack);
	size += sizeof(mDamageOnTrackFrequency);
	size += PX2_STRINGSIZE(mScriptHandler_OnTrack);

	return size;
}
//----------------------------------------------------------------------------