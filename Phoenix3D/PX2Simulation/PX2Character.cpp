// PX2Character.cpp

#include "PX2Character.hpp"
#include "PX2TriMesh.hpp"
#include "PX2SkinController.hpp"
#include "PX2Animation3DSkeleton.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
Character::Character() :
mDefaultAnimID(0),
mBaseHPCurLevel(0.0f),
mIsDieDoDelete(true),
mBaseAPCurLevel(0.0f),
mIsDead(false)
{
	PX2_INIT_PM_F(HP);
	PX2_INIT_PM_F(AP);
}
//----------------------------------------------------------------------------
Character::~Character()
{
}
//----------------------------------------------------------------------------
void Character::UpdateWorldData(double applicationTime)
{
	Actor::UpdateWorldData(applicationTime);

	// auto worldbound
	if (mMovable)
	{
		if (mIsAutoWorldBound)
		{
			mMovable->WorldBoundIsCurrent = true;
			mMovable->WorldBound.SetCenter(LocalTransform.GetTranslate());
			mMovable->WorldBound.SetRadius(mAutoWorldBoundRadius);
		}
		else
		{
			mMovable->WorldBoundIsCurrent = false;
		}
	}

	_AnimationBlend();
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
			node->GetController("BTC"));
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