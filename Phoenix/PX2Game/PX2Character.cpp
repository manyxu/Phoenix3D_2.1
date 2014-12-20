/*
*
* 文件名称	：	PX2Character.cpp
*
*/

#include "PX2Character.hpp"
#include "PX2Assert.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2Project.hpp"
#include "PX2XMLData.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2GameEventType.hpp"
#include "PX2LogicManager.hpp"
#include "PX2EventWorld.hpp"
#include "PX2Scene.hpp"
#include "PX2Animation3DSkeleton.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Actor, Character);
PX2_IMPLEMENT_STREAM(Character);
PX2_IMPLEMENT_FACTORY(Character);
PX2_IMPLEMENT_DEFAULT_NAMES(Actor, Character);

//----------------------------------------------------------------------------
Character::Character ()
	:
mIsAutoWorldBound(true),
mAutoWorldBoundRadius(1.0f),
mLevel(1),
mExp(0),
mExpCurLevel(0),
mIsCurHPNoReduce(false),
mHP(100),
mMHP(100),
mBaseHPCurLevel(100),
mAP(100),
mMAP(100),
mBaseAPCurLevel(100),
mIsDead(false),
mIsDieDoDelete(true),
mWatchDistance(0.0f),
mIsCanAimed(true),
mAimTargetID(0),
mNumAimingMe(0),
mIsFreezed(false),
mCurAffectMeObject(0),
mCurSucAffectObject(0)
{
	mBitSet[BST_CHARACTER] = 1;
}
//----------------------------------------------------------------------------
Character::~Character ()
{
}
//----------------------------------------------------------------------------
void Character::Initlize ()
{
	Actor::Initlize();

	for (int i=0; i<(int)mAnims.size(); i++)
	{
		if (mAnims[i])
			mAnims[i]->Initlize();
	}

	for (int i=0; i<(int)mItems.size(); i++)
	{
		if (mItems[i])
			mItems[i]->Initlize();
	}

	for (int i=0; i<(int)mSkills.size(); i++)
	{
		if (mSkills[i])
			mSkills[i]->Initlize();
	}

	for (int i=0; i<(int)mBufs.size(); i++)
	{
		if (mBufs[i])
			mBufs[i]->Initlize();
	}
}
//----------------------------------------------------------------------------
void Character::SetMovableFilename (const std::string &filename, bool shareVIM)
{
	Actor::SetMovableFilename(filename, shareVIM);

	_CalSkins();

	// 为动作树每个Node加一个BlendTransformController
	if (mModelAnimMovable)
		_CalAnimNode(mModelAnimMovable);
}
//----------------------------------------------------------------------------
void Character::_CalAnimNode (Movable *mov)
{
	const std::string &movName = mov->GetName();

	BlendTransformController *btc = DynamicCast<BlendTransformController>(mov->GetController("BTC"));
	if (!btc)
	{
		btc = new0 BlendTransformController(0, 0, false);
		mov->AttachController(btc);
		btc->SetName("BTC");
	}
	mBTCMap[movName.c_str()] = btc;

	Node *node = DynamicCast<Node>(mov);
	if (node)
	{
		for (int i=0; i<node->GetNumChildren(); i++)
		{
			_CalAnimNode(node->GetChild(i));
		}
	}
}
//----------------------------------------------------------------------------
void Character::_CalSkins ()
{
	Node *node = DynamicCast<Node>(mMovable);

	if (!node)
		return;

	for (int i=0; i<node->GetNumChildren(); i++)
	{
		Movable *mov = node->GetChild(i);
		TriMesh *triMesh = DynamicCast<TriMesh>(mov);
		Node *node = DynamicCast<Node>(mov);
		if (triMesh)
		{
			bool hasSkinCtrl = false;

			for (int i=0; i<triMesh->GetNumControllers(); i++)
			{
				SkinController *skinCtrl = DynamicCast<SkinController>(
					triMesh->GetController(i));
				if (skinCtrl)
				{
					hasSkinCtrl = true;
				}
			}

			if (hasSkinCtrl)
				mSkinMovable = triMesh;
		}
		else if (node)
		{
			bool hasSkinCtrl = false;

			for (int i=0; i<node->GetNumChildren(); i++)
			{
				TriMesh *mesh = DynamicCast<TriMesh>(node->GetChild(i));
				if (mesh)
				{
					for (int i=0; i<mesh->GetNumControllers(); i++)
					{
						SkinController *skinCtrl = DynamicCast<SkinController>(mesh->GetController(i));
						if (skinCtrl)
						{
							hasSkinCtrl = true;
						}
					}
				}
			}

			if (hasSkinCtrl)
			{
				mSkinMovable = node;
			}
			else
			{
				int numVaildChild = node->GetNumChildren();
				if (0 != numVaildChild)
				{
					mModelAnimMovable = node;
				}
			}
		}
	}
}
//----------------------------------------------------------------------------
void Character::Update (double appSeconds, double elapsedSeconds)
{
	// state machines
	if (mActionSM)
		mActionSM->Update(appSeconds, elapsedSeconds);

	if (mMovementSM)
		mMovementSM->Update(appSeconds, elapsedSeconds);

	if (mPostureSM)
		mPostureSM->Update(appSeconds, elapsedSeconds);

	// base
	Actor::Update(appSeconds, elapsedSeconds);

	if (mMovable)
	{
		if (mIsAutoWorldBound)
		{
			mMovable->WorldBoundIsCurrent = true;
			mMovable->WorldBound.SetCenter(GetPosition());
			mMovable->WorldBound.SetRadius(mAutoWorldBoundRadius);
		}
		else
		{
			mMovable->WorldBoundIsCurrent = false;
		}
	}

	// animations
	Animation *standAnim = GetStandAnim();
	if (!IsDead())
	{
		if (mCurAnim)
		{
			mCurAnim->Update(appSeconds, elapsedSeconds);

			if (!mCurAnim->IsPlaying())
			{
				if (standAnim)
					PlayAnim(standAnim);
			}
		}
		else
		{
			if (standAnim)
				PlayAnim(standAnim);
		}
	}

	if (mLastAnimObj)
	{
		mLastAnimObj->Update(appSeconds, elapsedSeconds);

		if (mLastAnimObj->IsBlendOver())
		{
			mLastAnimObj->BeforeRemove();
			mLastAnimObj = 0;
		}
	}

	float weight = 1.0f;
	if (mLastAnimObj)
	{
		weight = mLastAnimObj->BlendTime/ANIMATION_BLENDTIME;
	}

	Animation3DSkeleton *lastAnim = 0;
	if (mLastAnimObj) lastAnim = DynamicCast<Animation3DSkeleton>(mLastAnimObj->TheAnim);
	Animation3DSkeleton *curAnim = DynamicCast<Animation3DSkeleton>(mCurAnim);

	std::map<FString, KeyframeControllerPtr> *lastAnimKFCMap = 0;
	if (lastAnim)
	{
		lastAnimKFCMap = &(lastAnim->GetKeyframeCtrlMap());
	}
	std::map<FString, KeyframeControllerPtr> *curAnimKFCMap = 0;
	if (curAnim)
	{
		curAnimKFCMap = &(curAnim->GetKeyframeCtrlMap());
	}

	std::map<FString, BlendTransformController*>::iterator it = mBTCMap.begin();
	for (; it!=mBTCMap.end(); it++)
	{
		FString name = it->first;
		BlendTransformController *ctrl = it->second;

		if (lastAnimKFCMap && curAnimKFCMap)
		{
			ctrl->SetController01((*lastAnimKFCMap)[name], (*curAnimKFCMap)[name]);
			ctrl->SetWeight(weight);
		}
		else if (curAnimKFCMap)
		{
			ctrl->SetController0(0);
			ctrl->SetController1((*curAnimKFCMap)[name]);
			ctrl->SetWeight(1.0f);
		}
		if (!lastAnimKFCMap && !curAnimKFCMap)
		{
			ctrl->SetController01(0, 0);
		}
	}

	// skills
	for (int i=0; i<(int)mSkills.size(); i++)
	{
		Skill *skill = mSkills[i];
		if (skill)
		{
			skill->Update(appSeconds, elapsedSeconds);
		}
	}

	// bufs
	for (int i=0; i<(int)mBufs.size(); i++)
	{
		Buf *buf = mBufs[i];
		if (buf)
		{
			buf->Update(appSeconds, elapsedSeconds);
		}
	}

	std::vector<BufPtr>::iterator itBuf = mBufs.begin();
	for (; itBuf!=mBufs.end();)
	{
		Buf *buf = *itBuf;
		if (buf->IsOver())
		{
			(*itBuf)->OnRemoved();
			(*itBuf)->SetCharacter(0);

			itBuf = mBufs.erase(itBuf);
		}
		else
		{
			itBuf++;
		}
	}
}
//----------------------------------------------------------------------------
void Character::SaveToXMLNode (XMLNode nodeParent)
{
	XMLNode nodeClass = nodeParent.NewChild("Class");
	nodeClass.SetAttributeString("Type", "Character");

	Actor::SaveToXMLNode(nodeClass);

	XMLNode nodeProperty = nodeClass.NewChild("Property");
	nodeProperty.SetAttributeInt("HP", GetCurHP());
	nodeProperty.SetAttributeInt("BaseHPCurLevel", GetBaseHPCurLevel());
	nodeProperty.SetAttributeInt("AP", GetCurAP());
	nodeProperty.SetAttributeInt("BaseAPCurLevel", GetBaseAPCurLevel());
	nodeProperty.SetAttributeFloat("WatchDistance", GetWatchDistance());
	nodeProperty.SetAttributeString("ScriptHandler_OnBeAffect", GetScriptHandler_OnBeAffect());
	nodeProperty.SetAttributeString("ScriptHandler_OnSucAffect", GetScriptHandler_OnSucAffect());
	nodeProperty.SetAttributeString("ScriptHandler_OnDie", GetScriptHandler_OnDie());

	for (int i=0; i<GetNumAnims(); i++)
	{
		XMLNode nodeObject = nodeClass.NewChild("Object");
		nodeObject.SetAttributeString("RttiName", mAnims[i]->GetRttiType().GetName());

		mAnims[i]->SaveToXMLNode(nodeObject);
	}

	for (int i=0; i<GetNumItems(); i++)
	{
		XMLNode nodeObject = nodeClass.NewChild("Object");
		nodeObject.SetAttributeString("RttiName", mItems[i]->GetRttiType().GetName());

		mItems[i]->SaveToXMLNode(nodeObject);
	}

	for (int i=0; i<GetNumSkills(); i++)
	{
		XMLNode nodeObject = nodeClass.NewChild("Object");
		nodeObject.SetAttributeString("RttiName", mSkills[i]->GetRttiType().GetName());

		mSkills[i]->SaveToXMLNode(nodeObject);
	}
}
//----------------------------------------------------------------------------
void Character::LoadFromXMLNode (XMLNode node)
{
	XMLNode nodeBaseClass = node.GetChild("Class");
	if (!nodeBaseClass.IsNull())
	{
		std::string typeName = nodeBaseClass.AttributeToString("Type");
		Actor::LoadFromXMLNode(nodeBaseClass);
	}
	else
	{
		assertion(false, "");
	}

	XMLNode nextNode = node.IterateChild(nodeBaseClass);
	while (!nextNode.IsNull())
	{
		if ("Property" == nextNode.GetNameStr())
		{
			if (nextNode.HasAttribute("WatchDistance"))
			{
				SetWatchDistance(nextNode.AttributeToFloat("WatchDistance"));
			}

			if (nextNode.HasAttribute("ScriptHandler_OnBeAffect"))
			{
				SetScriptHandler_OnBeAffect(nextNode.AttributeToString("ScriptHandler_OnBeAffect"));
			}

			if (nextNode.HasAttribute("ScriptHandler_OnSucAffect"))
			{
				SetScriptHandler_OnSucAffect(nextNode.AttributeToString("ScriptHandler_OnSucAffect"));
			}

			if (nextNode.HasAttribute("ScriptHandler_OnDie"))
			{
				SetScriptHandler_OnDie(nextNode.AttributeToString("ScriptHandler_OnDie"));
			}
		}
		else if ("Object" == nextNode.GetNameStr())
		{
			const std::string rttiName = nextNode.AttributeToString("RttiName");
			Gameable *gameable = LogicManager::GetSingleton().CreateFromRttiName(rttiName);
			if (gameable)
			{
				XMLNode objectNodeClass = nextNode.GetChild("Class");
				if (!objectNodeClass.IsNull())
				{
					gameable->LoadFromXMLNode(objectNodeClass);
				}
				else
				{
					assertion(false, "");
				}
			}

			Animation *anim = DynamicCast<Animation>(gameable);
			Skill *skill = DynamicCast<Skill>(gameable);
			Item *item = DynamicCast<Item>(gameable);
			
			if (anim)
			{
				AddAnim(anim);
			}
			else if (skill)
			{
				AddSkill(skill);
			}
			else if (item)
			{
				AddItem(item);
			}
		}

		nextNode = node.IterateChild(nextNode);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void Character::RegistProperties ()
{
	Actor::RegistProperties();

	AddPropertyClass("Character");

	AddProperty("ModelFilename", PT_STRINGBUTTON, GetMoveableFilename());
	AddProperty("ModelTagName", PT_STRING, GetModelTagName());
}
//----------------------------------------------------------------------------
void Character::OnPropertyChanged (const PropertyObject &obj)
{
	Actor::OnPropertyChanged(obj);

	if ("ModelFilename" == obj.Name)
	{
		SetMovableFilename(PX2_ANY_AS(obj.Data, std::string), true);

		Event *ent = GameEventSpace::CreateEventX(GameEventSpace::CharacterSetMovable);
		ent->SetData<Character*>(this);
		PX2_EW.BroadcastingLocalEvent(ent);
	}
	else if ("ModelTagName" == obj.Name)
	{
		SetModelTagName(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("Level" == obj.Name)
	{
		SetLevel(PX2_ANY_AS(obj.Data, int));
	}
	else if ("Group" == obj.Name)
	{
		SetGroup(PX2_ANY_AS(obj.Data, int));
	}
	else if ("WatchDistance" == obj.Name)
	{
		SetWatchDistance(PX2_ANY_AS(obj.Data, float));
	}
	else if ("ScriptHandler_OnBeAffect" == obj.Name)
	{
		SetScriptHandler_OnBeAffect(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("ScriptHandler_OnSucAffect" == obj.Name)
	{
		SetScriptHandler_OnSucAffect(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("ScriptHandler_OnDie" == obj.Name)
	{
		SetScriptHandler_OnDie(PX2_ANY_AS(obj.Data, std::string));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Character::Character (LoadConstructor value)
	:
Actor(value),
mIsAutoWorldBound(true),
mAutoWorldBoundRadius(1.0f),
mLevel(0),
mIsCurHPNoReduce(false),
mHP(0),
mMHP(0),
mIsFreezed(false),
mIsDead(false),
mIsDieDoDelete(true),
mBaseHPCurLevel(0),
mExp(0),
mExpCurLevel(0),
mAP(100),
mMAP(0),
mBaseAPCurLevel(100),
mWatchDistance(10.0f),
mIsCanAimed(true),
mAimTargetID(0),
mNumAimingMe(0),
mCurAffectMeObject(0),
mCurSucAffectObject(0)
{
	mBitSet[BST_CHARACTER] = 1;
}
//----------------------------------------------------------------------------
void Character::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Actor::Load(source);
	PX2_VERSION_LOAD(source);

	int numAnims = 0;
	source.Read(numAnims);
	for (int i=0; i<numAnims; i++)
	{
		Animation *anim = 0;
		source.ReadPointer(anim);
		mAnims.push_back(anim);
	}
	source.ReadPointer(mCurAnim);
	source.ReadString(mModelTagName);

	int numItems = 0;
	source.Read(numItems);
	for (int i=0; i<numItems; i++)
	{
		Item *item = 0;
		source.ReadPointer(item);
		mItems.push_back(item);
	}

	int numEquippedItem = 0;
	source.Read(numEquippedItem);
	for (int i=0; i<numEquippedItem; i++)
	{
		Item *equipItem = 0;
		source.ReadPointer(equipItem);
		mEquippedItems.push_back(equipItem);
	}
	
	int numSkills = 0;
	source.Read(numSkills);
	for (int i=0; i<numSkills; i++)
	{
		Skill *skill = 0;
		source.ReadPointer(skill);
		mSkills.push_back(skill);
	}

	int numBufs = 0;
	source.Read(numBufs);
	for (int i=0; i<numBufs; i++)
	{
		Buf *buf = 0;
		source.ReadPointer(buf);
		mBufs.push_back(buf);
	}

	source.Read(mLevel);
	source.Read(mGroup);
	source.Read(mHP);
	source.Read(mMHP);
	source.Read(mBaseHPCurLevel);
	source.Read(mAP);

	int numMMapAPs = 0;
	source.Read(numMMapAPs);
	for (int i=0; i<numMMapAPs; i++)
	{
		std::string name;
		int val = 0;
		source.ReadString(name);
		source.Read(val);
		mMMapAPs[name] = val;
	}
	source.Read(mMAP);

	source.Read(mBaseAPCurLevel);
	source.Read(mExp);
	source.Read(mExpCurLevel);

	source.Read(mWatchDistance);
	source.ReadBool(mIsCanAimed);

	source.ReadString(mScriptHandler_OnBeAffect);
	source.ReadString(mScriptHandler_OnSucAffect);
	source.ReadString(mScriptHandler_OnDie);

	PX2_END_DEBUG_STREAM_LOAD(Character, source);
}
//----------------------------------------------------------------------------
void Character::Link (InStream& source)
{
	Actor::Link(source);

	int numAnims = (int)mAnims.size();
	for (int i=0; i<numAnims; i++)
	{
		source.ResolveLink(mAnims[i]);
		if (mAnims[i])
			mAnims[i]->SetCharacter(this);
	}
	source.ResolveLink(mCurAnim);

	int numItems = (int)mItems.size();
	for (int i=0; i<numItems; i++)
	{
		source.ResolveLink(mItems[i]);
		if (mItems[i])
			mItems[i]->SetCharacter(this);
	}

	int numEquippedItem = (int)mEquippedItems.size();
	for (int i=0; i<numEquippedItem; i++)
	{
		source.ResolveLink(mEquippedItems[i]);
		if (mEquippedItems[i])
			mEquippedItems[i]->SetCharacter(this);
	}

	for (int i=0; i<(int)mSkills.size(); i++)
	{
		source.ResolveLink(mSkills[i]);
		if (mSkills[i])
			mSkills[i]->SetCharacter(this);
	}

	for (int i=0; i<(int)mBufs.size(); i++)
	{
		source.ResolveLink(mBufs[i]);
		if (mBufs[i])
			mBufs[i]->SetCharacter(this);
	}
}
//----------------------------------------------------------------------------
void Character::PostLink ()
{
	Actor::PostLink();

	mStandbyAnim = GetAnimByName("Standby");
	mDefSkill = GetSkillByName("Def");

	SetCanBeAimed(IsCanBeAimed());
}
//----------------------------------------------------------------------------
bool Character::Register (OutStream& target) const
{
	if (Actor::Register(target))
	{
		int numAnims = (int)mAnims.size();
		for (int i=0; i<numAnims; i++)
		{
			target.Register(mAnims[i]);
		}
		target.Register(mCurAnim);

		int numItems = (int)mItems.size();
		for (int i=0; i<numItems; i++)
		{
			target.Register(mItems[i]);
		}

		int numEquippedItem = (int)mEquippedItems.size();
		for (int i=0; i<numEquippedItem; i++)
		{
			target.Register(mEquippedItems[i]);
		}

		int numSkills = GetNumSkills();
		for (int i=0; i<numSkills; i++)
		{
			target.Register(mSkills[i]);
		}

		int numBufs = GetNumBufs();
		for (int i=0; i<numBufs; i++)
		{
			target.Register(mBufs[i]);
		}

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void Character::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Actor::Save(target);
	PX2_VERSION_SAVE(target);

	int numAnims = (int)mAnims.size();
	target.Write(numAnims);
	for (int i=0; i<numAnims; i++)
	{
		target.WritePointer(mAnims[i]);
	}
	target.WritePointer(mCurAnim);
	target.WriteString(mModelTagName);

	int numItems = (int)mItems.size();
	target.Write(numItems);
	for (int i=0; i<numItems; i++)
	{
		target.WritePointer(mItems[i]);
	}

	int numEquippedItem = (int)mEquippedItems.size();
	target.Write(numEquippedItem);
	for (int i=0; i<numEquippedItem; i++)
	{
		target.WritePointer(mEquippedItems[i]);
	}

	int numSkills = (int)mSkills.size();
	target.Write(numSkills);
	for (int i=0; i<numSkills; i++)
	{
		target.WritePointer(mSkills[i]);
	}

	int numBufs = (int)mBufs.size();
	target.Write(numBufs);
	for (int i=0; i<numBufs; i++)
	{
		target.WritePointer(mBufs[i]);
	}

	target.Write(mLevel);
	target.Write(mGroup);
	target.Write(mHP);
	target.Write(mMHP);
	target.Write(mBaseHPCurLevel);
	target.Write(mAP);

	int numMMapAPs = (int)mMMapAPs.size();	
	target.Write(numMMapAPs);
	for (std::map<std::string, int>::const_iterator it = mMMapAPs.begin(); it!=mMMapAPs.end(); it++)
	{
		target.WriteString(it->first);
		target.Write(it->second);
	}
	target.Write(mMAP);
	
	target.Write(mBaseAPCurLevel);
	target.Write(mExp);
	target.Write(mExpCurLevel);

	target.Write(mWatchDistance);
	target.WriteBool(mIsCanAimed);

	target.WriteString(mScriptHandler_OnBeAffect);
	target.WriteString(mScriptHandler_OnSucAffect);
	target.WriteString(mScriptHandler_OnDie);

	PX2_END_DEBUG_STREAM_SAVE(Character, target);
}
//----------------------------------------------------------------------------
int Character::GetStreamingSize (Stream &stream) const
{
	int size = Actor::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	int numAnims = (int)mAnims.size();
	size += sizeof(numAnims);
	size += numAnims * PX2_POINTERSIZE(0);
	size += PX2_POINTERSIZE(mCurAnim);
	size += PX2_STRINGSIZE(mModelTagName);

	int numItems = (int)mItems.size();
	size += sizeof(numItems);
	size += numItems * PX2_POINTERSIZE(0);

	int numEquippedItem = (int)mEquippedItems.size();
	size += sizeof(numEquippedItem);
	size += numEquippedItem * PX2_POINTERSIZE(0);

	int numSkills = (int)mSkills.size();
	size += sizeof(numSkills);
	size += numSkills * PX2_POINTERSIZE(0);

	int numBufs = (int)mBufs.size();
	size += sizeof(numBufs);
	size += numBufs * PX2_POINTERSIZE(0);

	size += sizeof(mLevel);
	size += sizeof(mGroup);
	size += sizeof(mHP);
	size += sizeof(mMHP);
	size += sizeof(mBaseHPCurLevel);
	size += sizeof(mAP);

	int numMMapAPs = (int)mMMapAPs.size();	
	size += sizeof(numMMapAPs);
	PX2_UNUSED(numMMapAPs);
	for (std::map<std::string, int>::const_iterator it = mMMapAPs.begin(); it!=mMMapAPs.end(); it++)
	{
		size += PX2_STRINGSIZE(it->first);
		size += sizeof(it->second);
	}
	size += sizeof(mMAP);

	size += sizeof(mBaseAPCurLevel);
	size += sizeof(mExp);
	size += sizeof(mExpCurLevel);

	size += sizeof(mWatchDistance);
	size += PX2_BOOLSIZE(mIsCanAimed);

	size += PX2_STRINGSIZE(mScriptHandler_OnBeAffect);
	size += PX2_STRINGSIZE(mScriptHandler_OnSucAffect);
	size += PX2_STRINGSIZE(mScriptHandler_OnDie);

	return size;
}
//----------------------------------------------------------------------------