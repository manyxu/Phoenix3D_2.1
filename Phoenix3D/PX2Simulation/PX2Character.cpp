// PX2Character.cpp

#include "PX2Character.hpp"
#include "PX2TriMesh.hpp"
#include "PX2SkinController.hpp"
#include "PX2Animation3DSkeleton.hpp"
#include "PX2StandardMesh.hpp"
#include "PX2VertexColor4Material.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2SimulationEventType.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Actor, Character);
PX2_IMPLEMENT_STREAM(Character);
PX2_IMPLEMENT_FACTORY(Character);
PX2_IMPLEMENT_DEFAULT_NAMES(Actor, Character);

//----------------------------------------------------------------------------
Character::Character() :
mDefaultAnimID(0),
mBaseHPCurLevel(0.0f),
mIsDieDoDelete(true),
mBaseAPCurLevel(0.0f),
mIsDead(false),
mIsMovableAutoWorldBound(true),
mMovableAutoWorldBoundRadius(2.0f)
{
	SetName("Chara");

	PX2_INIT_PM_F(HP);
	PX2_INIT_PM_F(AP);

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PC);
	StandardMesh stdMesh(vf);
	stdMesh.SetVertexColor(Float4(1.0f, 0.0f, 0.0f, 1.0f));
	TriMesh *mesh = stdMesh.Box(0.5f, 0.5f, 0.5f);
	PX2::VertexColor4MaterialPtr mtl = new0 VertexColor4Material();
	mtl->GetWireProperty(0, 0)->Enabled = true;
	mtl->GetCullProperty(0, 0)->Enabled = false;
	mesh->LocalTransform.SetUniformScale(0.5f);
	mesh->SetMaterialInstance(mtl->CreateInstance());
	CreateGetHelpNode()->DetachAllChildren();
	CreateGetHelpNode()->AttachChild(mesh);
	CreateGetHelpNode()->SetParentTransformIngore(false, false, true);
}
//----------------------------------------------------------------------------
Character::~Character()
{
}
//----------------------------------------------------------------------------
void Character::UpdateWorldData(double applicationTime, double elapsedTime)
{
	Actor::UpdateWorldData(applicationTime, elapsedTime);

	_AnimationBlend();

	if (mMovable)
	{
		if (mIsMovableAutoWorldBound)
		{
			mMovable->WorldBoundIsCurrent = true;
			mMovable->WorldBound.SetCenter(WorldTransform.GetTranslate());
			mMovable->WorldBound.SetRadius(mMovableAutoWorldBoundRadius);
		}
		else
		{
			mMovable->WorldBoundIsCurrent = false;
		}
	}
}
//----------------------------------------------------------------------------
void Character::_AnimationBlend()
{
	if (mLastAnimObj)
	{
		//mLastAnimObj->Update(appSeconds, elapsedSeconds);

		if (mLastAnimObj->IsBlendOver())
		{
			mLastAnimObj->BeforeRemove();
			mLastAnimObj = 0;
		}
	}

	float weight = 1.0f;
	if (mLastAnimObj)
	{
		weight = mLastAnimObj->BlendTime / ANIMATION_BLENDTIME;
	}

	Animation3DSkeleton *lastAnim = 0;
	float lastAnimTime = 0.0f;
	if (mLastAnimObj)
	{
		lastAnim = DynamicCast<Animation3DSkeleton>(mLastAnimObj->TheAnim);
		lastAnimTime = lastAnim->GetTime();
	}
	Animation3DSkeleton *curAnim = DynamicCast<Animation3DSkeleton>(mCurPlayingAnim);
	float curAnimTime = 0.0f;
	if (curAnim)
	{
		curAnimTime = curAnim->GetTime();
	}

	std::map<FString, KeyframeControllerPtr> *lastAnimKFCMap = 0;
	if (lastAnim)
	{
		lastAnimKFCMap = &(lastAnim->GetKeyframeCtrlMap());
	}
	std::map<FString, KeyframeControllerPtr> *curAnimKFCMap = 0;
	bool isUseBlend = true;
	if (curAnim)
	{
		curAnimKFCMap = &(curAnim->GetKeyframeCtrlMap());
		isUseBlend = curAnim->IsUseBlend();
	}

	std::map<FString, BlendTransformController*>::iterator it = mBTCMap.begin();
	for (; it != mBTCMap.end(); it++)
	{
		FString name = it->first;
		BlendTransformController *ctrl = it->second;

		if (lastAnimKFCMap && curAnimKFCMap)
		{
			if (isUseBlend)
			{
				ctrl->SetController01((*lastAnimKFCMap)[name], (*curAnimKFCMap)[name]);
				ctrl->SetWeight(weight);
			}
			else
			{
				ctrl->SetController0(0);
				ctrl->SetController1((*curAnimKFCMap)[name]);
				ctrl->SetWeight(1.0f);
			}
		}
		if (curAnimKFCMap)
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
}
//----------------------------------------------------------------------------
void Character::SetMovableFilename(const std::string &filename, bool shareVI)
{
	Actor::SetMovableFilename(filename, shareVI);

	_CalSkins();

	// 为动作树每个Node加一个BlendTransformController
	if (mModelAnimMovable)
		_CalAnimNode(mModelAnimMovable);

	SetMovableAutoWorldBoundRadius(mMovableAutoWorldBoundRadius);
}
//----------------------------------------------------------------------------
void Character::_CalSkins()
{
	Node *node = DynamicCast<Node>(mMovable);

	if (!node)
		return;

	for (int i = 0; i < node->GetNumChildren(); i++)
	{
		Movable *mov = node->GetChild(i);
		TriMesh *triMesh = DynamicCast<TriMesh>(mov);
		Node *node = DynamicCast<Node>(mov);
		if (triMesh)
		{
			bool hasSkinCtrl = false;

			for (int i = 0; i < triMesh->GetNumControllers(); i++)
			{
				SkinController *skinCtrl = DynamicCast<SkinController>(
					triMesh->GetController(i));
				if (skinCtrl)
				{
					hasSkinCtrl = true;
				}
			}

			if (hasSkinCtrl)
				mSkinMovables.push_back(triMesh);
		}
		else if (node)
		{
			bool hasSkinCtrl = false;

			for (int i = 0; i < node->GetNumChildren(); i++)
			{
				TriMesh *mesh = DynamicCast<TriMesh>(node->GetChild(i));
				if (mesh)
				{
					for (int i = 0; i < mesh->GetNumControllers(); i++)
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
				mSkinMovables.push_back(node);
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

	for (int i = 0; i < (int)mSkinMovables.size(); i++)
	{
		mSkinMovables[i]->SetUpdatePriority(1);
	}

	if (mModelAnimMovable)
	{
		mModelAnimMovable->SetUpdatePriority(2);
	}

	Node *rootNode = DynamicCast<Node>(mMovable);
	if (rootNode)
	{
		node->SetNeedCalUpdateChild(true);
	}
}
//----------------------------------------------------------------------------
void Character::_CalAnimNode(Movable *mov)
{
	const std::string &movName = mov->GetName();
	Node *node = DynamicCast<Node>(mov);
	if (node)
	{
		BlendTransformController *btc = DynamicCast<BlendTransformController>(
			node->GetControllerByName("BTC"));
		if (!btc)
		{
			btc = new0 BlendTransformController(0, 0, true);
			node->AttachController(btc);
			btc->SetName("BTC");
		}
		mBTCMap[movName.c_str()] = btc;

		for (int i = 0; i < node->GetNumChildren(); i++)
		{
			_CalAnimNode(node->GetChild(i));
		}
	}
}
//----------------------------------------------------------------------------
void Character::SetMovableAutoWorldBoundRadius(float radius)
{
	mMovableAutoWorldBoundRadius = radius;

	if (mMovable)
	{
		if (mIsMovableAutoWorldBound)
		{
			mMovable->WorldBoundIsCurrent = true;
			mMovable->WorldBound.SetCenter(WorldTransform.GetTranslate());
			mMovable->WorldBound.SetRadius(mMovableAutoWorldBoundRadius);
		}
		else
		{
			mMovable->WorldBoundIsCurrent = false;
		}

		UpdateWorldBound();
	}

	if (PX2_GR.IsInEditor())
	{
		Event *ent = SimuES_E::CreateEventX(SimuES_E::BoundChanged);
		PX2_EW.BroadcastingLocalEvent(ent);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void Character::RegistProperties()
{
	Actor::RegistProperties();

	AddPropertyClass("Character");

	AddProperty("IsMovableAutoWorldBound", PT_BOOL, mIsMovableAutoWorldBound);
	AddProperty("MovableAutoWorldBoundRadius", PT_FLOAT, 
		mMovableAutoWorldBoundRadius);
	AddProperty("NumAnimations", PT_INT, (int)mAnimsMap.size(), false);
	AddProperty("DefaultAnimID", PT_INT, mDefaultAnimID);
}
//----------------------------------------------------------------------------
void Character::OnPropertyChanged(const PropertyObject &obj)
{
	Actor::OnPropertyChanged(obj);

	if ("IsMovableAutoWorldBound" == obj.Name)
	{
		SetMovableUseAutoWorldBound(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("MovableAutoWorldBoundRadius" == obj.Name)
	{
		SetMovableAutoWorldBoundRadius(PX2_ANY_AS(obj.Data, float));
	}
	else if ("DefaultAnimID" == obj.Name)
	{
		SetDefaultAnimID(PX2_ANY_AS(obj.Data, int));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Character::Character(LoadConstructor value) :
Actor(value),
mDefaultAnimID(0),
mBaseHPCurLevel(0.0f),
mIsDieDoDelete(true),
mBaseAPCurLevel(0.0f),
mIsDead(false),
mIsMovableAutoWorldBound(true),
mMovableAutoWorldBoundRadius(2.0f)
{
}
//----------------------------------------------------------------------------
void Character::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Actor::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(Character, source);
}
//----------------------------------------------------------------------------
void Character::Link(InStream& source)
{
	Actor::Link(source);
}
//----------------------------------------------------------------------------
void Character::PostLink()
{
	Actor::PostLink();
}
//----------------------------------------------------------------------------
bool Character::Register(OutStream& target) const
{
	if (Actor::Register(target))
		return true;

	return false;
}
//----------------------------------------------------------------------------
void Character::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Actor::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(Character, target);
}
//----------------------------------------------------------------------------
int Character::GetStreamingSize(Stream &stream) const
{
	int size = Actor::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------