/*
*
* 文件名称	：	PX2SkillStepLink.cpp
*
*/

#include "PX2SkillStepLink.hpp"
#include "PX2SkillInstance.hpp"
#include "PX2Skill.hpp"
#include "PX2Character.hpp"
#include "PX2Scene.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2Project.hpp"
#include "PX2DeletingManager.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, SkillStep, SkillStepLink);
PX2_IMPLEMENT_STREAM(SkillStepLink);
PX2_IMPLEMENT_FACTORY(SkillStepLink);
PX2_IMPLEMENT_DEFAULT_NAMES(SkillStep, SkillStepLink);

//----------------------------------------------------------------------------
SkillStepLink::SkillStepLink ()
	:
SkillStep(M_LINK),
mIsLinkToActor(true),
mSpeed(0.0f),
mLinkToTime(0.0f),
mLinkedDoOver(true),
mCurLinkedSkillInstance(0)
{
}
//----------------------------------------------------------------------------
SkillStepLink::~SkillStepLink ()
{
}
//----------------------------------------------------------------------------
void SkillStepLink::OnEnter (SkillInstance *instance)
{
	SkillStep::OnEnter(instance);

	Skill *skill = instance->GetSkill();
	Character *character = skill->GetCharacter();
	Scene *scene = character->GetScene();
	Node *sceneNode = DynamicCast<Node>(scene->GetSceneNode());
	APoint charPos = character->GetPosition();

	int aimTarget = instance->GetAimTarget();
	Character *aimTargetChar = DynamicCast<Character>(scene->GetActorByID(
		aimTarget));
	if (aimTargetChar)
	{
		SkillActorLinkPtr skillActorLink = new0 SkillActorLink();

		instance->AddSkillActor(aimTarget, skillActorLink);

		skillActorLink->SetID(10000+scene->GetNextID());

		skillActorLink->Initlize();

		if (!mSelfEffectFilename.empty())
			skillActorLink->SetMovableFilename(mSelfEffectFilename);

		skillActorLink->SetFromActorID(character->GetID());
		skillActorLink->SetFromActorAnchor(mSelfEffectAnchor);

		if (IsLinkToActor())
		{
			skillActorLink->SetTargetType(SkillActorLink::TT_ACTOR);
			skillActorLink->SetToActorID(aimTarget);
			skillActorLink->SetToActorAnchor(GetToActorAnchor());
		}
		else
		{
			APoint toPos = charPos + mLinkDir * mSpeed * mLinkToTime; 

			skillActorLink->SetTargetType(SkillActorLink::TT_POSITION);
			skillActorLink->SetToPosition(toPos);
		}

		skillActorLink->SetPosition(charPos);
		skillActorLink->SetLinkSpeed(GetSpeed());

		skillActorLink->ShowHelpMovable(false);

		scene->AddActor(skillActorLink);

		skillActorLink->Start();

		if (!mSelfPosEffectFilename.empty())
		{
			APoint pos = character->GetPosition();
			Transform trans;
			trans.SetTranslate(pos);
			trans.SetRotate(character->GetMovable()->WorldTransform.GetRotate());

			if (!mSelfPosEffectFilename.empty())
			{
				Node *anchor = character->GetAnchor(mSelfPosEffectAnchor);
				if (anchor)
				{
					//trans = anchor->WorldTransform;
					trans.SetTranslate(anchor->WorldTransform.GetTranslate());
				}
			}

			Object *obj = PX2_RM.BlockLoadShareCopy(mSelfPosEffectFilename, false,
				false, true);
			if (obj)
			{
				EffectNode *effectNode = DynamicCast<EffectNode>(obj);
				if (effectNode)
				{
					effectNode->SetSelfCtrled(true);
					effectNode->WorldTransform = trans;
					effectNode->WorldTransformIsCurrent = true;
					sceneNode->AttachChild(effectNode);
					effectNode->ResetPlay();

					PX2_DM.AddDeletingObj(effectNode, mSelfPosEffectTime, 3.0f);
				}
			}
		}
	}
	else
	{
		if (PX2_PROJ.IsInEditor())
		{
			SkillActorLinkPtr skillActorLink = new0 SkillActorLink();

			instance->AddSkillActor(aimTarget, skillActorLink);

			skillActorLink->SetID(10000+scene->GetNextID());

			skillActorLink->Initlize();

			if (!mSelfEffectFilename.empty())
				skillActorLink->SetMovableFilename(mSelfEffectFilename);

			skillActorLink->SetFromActorID(character->GetID());
			skillActorLink->SetFromActorAnchor(mSelfEffectAnchor);

			if (IsLinkToActor())
			{
				skillActorLink->SetTargetType(SkillActorLink::TT_ACTOR);
				skillActorLink->SetToActorID(aimTarget);
				skillActorLink->SetToActorAnchor(GetToActorAnchor());
			}
			else
			{
				APoint toPos = charPos + mLinkDir * mSpeed * mLinkToTime; 

				skillActorLink->SetTargetType(SkillActorLink::TT_POSITION);
				skillActorLink->SetToPosition(toPos);
			}

			skillActorLink->SetPosition(charPos);
			skillActorLink->SetLinkSpeed(GetSpeed());

			skillActorLink->ShowHelpMovable(false);

			scene->AddActor(skillActorLink);

			skillActorLink->Start();
		}
		else
		{
			// over
		}
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void SkillStepLink::RegistProperties ()
{
	SkillStep::RegistProperties();

	AddPropertyClass("SkillStepLink");

	AddProperty("IsLinkToActor", PT_BOOL, IsLinkToActor());
	AddProperty("LinkDir", PT_AVECTOR3, GetLinkDir());
	AddProperty("Speed", PT_FLOAT, GetSpeed());
	AddProperty("LinkToTime", PT_FLOAT, GetLinkToTime());
	AddProperty("LinkedDoOver", PT_BOOL, IsLinkedDoOver());
	AddProperty("ScriptHandler_OnLinked", PT_STRING, GetScriptHandler_OnLinked());
	AddProperty("ScriptHandler_OnDisLinked", PT_STRING, GetScriptHandler_OnDisLinked());
}
//----------------------------------------------------------------------------
void SkillStepLink::OnPropertyChanged (const PropertyObject &obj)
{
	SkillStep::OnPropertyChanged(obj);

	if ("IsLinkToActor" == obj.Name)
	{
		SetLinkToActor(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("LinkDir" == obj.Name)
	{
		SetLinkDir(PX2_ANY_AS(obj.Data, AVector));
	}
	else if ("Speed" == obj.Name)
	{
		SetSpeed(PX2_ANY_AS(obj.Data, float));
	}
	else if ("LinkToTime" == obj.Name)
	{
		SetLinkToTime(PX2_ANY_AS(obj.Data, float));
	}
	else if ("LinkedDoOver" == obj.Name)
	{
		SetLinkedDoOver(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("ScriptHandler_OnLinked" == obj.Name)
	{
		SetScriptHandler_OnLinked(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("ScriptHandler_OnDisLinked" == obj.Name)
	{
		SetScriptHandler_OnDisLinked(PX2_ANY_AS(obj.Data, std::string));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
SkillStepLink::SkillStepLink (LoadConstructor value)
	:
SkillStep(value),
mIsLinkToActor(true),
mSpeed(0.0f),
mLinkToTime(0.0f),
mLinkedDoOver(true),
mCurLinkedSkillInstance(0)
{
}
//----------------------------------------------------------------------------
void SkillStepLink::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	SkillStep::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadBool(mIsLinkToActor);
	source.ReadAggregate(mLinkDir);
	source.Read(mSpeed);
	source.Read(mLinkToTime);
	source.ReadBool(mLinkedDoOver);
	source.ReadString(mScriptHandler_OnLinked);
	source.ReadString(mScriptHandler_OnDisLinked);

	PX2_END_DEBUG_STREAM_LOAD(SkillStepLink, source);
}
//----------------------------------------------------------------------------
void SkillStepLink::Link (InStream& source)
{
	SkillStep::Link(source);
}
//----------------------------------------------------------------------------
void SkillStepLink::PostLink ()
{
	SkillStep::PostLink();
}
//----------------------------------------------------------------------------
bool SkillStepLink::Register (OutStream& target) const
{
	if (SkillStep::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void SkillStepLink::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	SkillStep::Save(target);
	PX2_VERSION_SAVE(target);	

	target.WriteBool(mIsLinkToActor);
	target.WriteAggregate(mLinkDir);
	target.Write(mSpeed);
	target.Write(mLinkToTime);
	target.WriteBool(mLinkedDoOver);
	target.WriteString(mScriptHandler_OnLinked);
	target.WriteString(mScriptHandler_OnDisLinked);

	PX2_END_DEBUG_STREAM_SAVE(SkillStepLink, target);
}
//----------------------------------------------------------------------------
int SkillStepLink::GetStreamingSize (Stream &stream) const
{
	int size = SkillStep::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_BOOLSIZE(mIsLinkToActor);
	size += sizeof(mLinkDir);
	size += sizeof(mSpeed);
	size += sizeof(mLinkToTime);
	size += PX2_BOOLSIZE(mLinkedDoOver);
	size += PX2_STRINGSIZE(mScriptHandler_OnLinked);
	size += PX2_STRINGSIZE(mScriptHandler_OnDisLinked);

	return size;
}
//----------------------------------------------------------------------------