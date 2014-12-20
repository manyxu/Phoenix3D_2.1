/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Actor_Movable.cpp
*
*/

#include "PX2Actor.hpp"
#include "PX2Scene.hpp"
#include "PX2Scene3D.hpp"
#include "PX2ResourceManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void Actor::SetMovableFilename (const std::string &filename, bool shareVIM)
{
	mIsShareVIM = shareVIM;

	mMoveableFilename = filename;

	Object *obj = 0;
	
	if (mIsShareVIM)
	{
		obj = PX2_RM.BlockLoadShareCopy(filename, true, true, false);
	}
	else
	{
		obj = PX2_RM.BlockLoadCopy(filename);
	}

	Movable *mov = DynamicCast<Movable>(obj);
	if (mov)
	{
		SetMovable(mov);
	}
}
//----------------------------------------------------------------------------
void Actor::SetMovable (Movable *movable)
{
	if (mScene && mMovable)
	{
		mScene->GetSceneNode()->DetachChild(mMovable);
	}

	mMovable = movable;

	mMovable->LocalTransform.SetScale(mScale);
	mMovable->LocalTransform.SetRotate(Matrix3f().MakeEulerXYZ(
		mRotation.X(), mRotation.Y(), mRotation.Z()));
	mMovable->LocalTransform.SetTranslate(mPosition);

	mMovable->Show(mIsVisible);

	if (mScene && mMovable)
	{
		mScene->GetSceneNode()->AttachChild(mMovable);
	}

	SetBakeObject(IsBakeObject());
	SetBakeTarget(IsBakeTarget());
}
//----------------------------------------------------------------------------
void Actor::ShowHelpMovable (bool show)
{
	mIsShowHelpMovable = show;

	if (mHelpMovable)
	{
		if (mIsShowHelpMovable)
		{
			mHelpMovable->Culling = Movable::CULL_DYNAMIC;
		}
		else
		{
			mHelpMovable->Culling = Movable::CULL_ALWAYS;
		}
	}
}
//----------------------------------------------------------------------------
void Actor::SetHelpMovable (Movable *movable)
{
	Node *parent = 0;
	if (mHelpMovable)
	{
		parent = DynamicCast<Node>(mHelpMovable->GetParent());
		if (parent)
		{
			parent->DetachChild(mHelpMovable);
		}
	}

	mHelpMovable = movable;

	mHelpMovable->LocalTransform.SetTranslate(mPosition);
	mHelpMovable->LocalTransform.SetRotate(Matrix3f().MakeEulerXYZ(
		mRotation.X(), mRotation.Y(), mRotation.Z()));
	mHelpMovable->Show(mIsVisible);

	if (mHelpMovable && parent)
	{
		parent->AttachChild(mHelpMovable);
	}

	SetPickable(IsPickable());
}
//----------------------------------------------------------------------------
void Actor::SetPickable (bool isPickable)
{
	mIsPickable = isPickable;

	if (mMovable)
	{
		mMovable->SetDoPick(isPickable);
	}

	if (mHelpMovable)
	{
		mHelpMovable->SetDoPick(isPickable);
	}
}
//----------------------------------------------------------------------------
APoint Actor::GetAnchorPos (const std::string &name)
{
	if (!mMovable)
		return APoint::ORIGIN;

	Movable *mov = DynamicCast<Movable>(mMovable->GetObjectByName(name));
	if (mov)
	{
		return mov->WorldTransform.GetTranslate();
	}

	return APoint::ORIGIN;
}
//----------------------------------------------------------------------------
Node *Actor::GetAnchor (const std::string &name)
{
	if (!mMovable)
		return 0;

	return DynamicCast<Node>(mMovable->GetObjectByName(name));
}
//----------------------------------------------------------------------------
void Actor::SetVisible (bool visible)
{
	mIsVisible = visible;

	if (mMovable)
	{
		if (!mIsVisible)
			mMovable->Culling = Movable::CULL_ALWAYS;
		else
			mMovable->Culling = Movable::CULL_DYNAMIC;
	}
}
//----------------------------------------------------------------------------
void Actor::SetTransparent (float alpha)
{
	mActorTransparent = alpha;
}
//----------------------------------------------------------------------------
void Actor::SetScene (Scene *scene)
{
	if (mScene == scene)
		return;

	if (scene)
	{
		Node *sceneNode = scene->GetSceneNode();

		if (sceneNode)
		{
			//double appTime = GetTimeInSeconds();

			if (mMovable)
			{
				sceneNode->AttachChild(mMovable);
				//mMovable->Update(appTime);
			}

			if (mHelpMovable)
			{
				sceneNode->AttachChild(mHelpMovable);
				//mHelpMovable->Update(appTime);
			}
		}
	}
	else
	{
		if (mScene)
		{
			Node *sceneNode = mScene->GetSceneNode();

			if (sceneNode)
			{
				if (mMovable)
				{
					sceneNode->DetachChild(mMovable);
				}

				if (mHelpMovable)
				{
					sceneNode->DetachChild(mHelpMovable);
				}
			}
		}
	}

	mScene = scene;
}
//----------------------------------------------------------------------------
void Actor::CalLights ()
{
}
//----------------------------------------------------------------------------
void Actor::SetSceneContainer (void *container)
{
	mSceneContainer = container;
}
//----------------------------------------------------------------------------
void Actor::SetSceneContainerIndex (int index)
{
	mSceneContainerIndex = index;
}
//----------------------------------------------------------------------------
EffectNode *Actor::AddActorEffect (const std::string &anchor, 
	const std::string &effectName, const std::string &effectFilename)
{
	if (!mMovable)
		return 0;

	Node *anchorNode = DynamicCast<Node>(mMovable->GetObjectByName(anchor));
	if (anchorNode)
	{
		EffectNode *en = DynamicCast<EffectNode>(PX2_RM.BlockLoadCopy(effectFilename));
		anchorNode->AttachChild(en);
		en->SetName(effectName);
		en->ResetPlay();

		return en;
	}

	return 0;
}
//----------------------------------------------------------------------------
void Actor::RemoveActorEffect (const std::string &effectName)
{
	if (!mMovable)
		return;

	EffectNode *en = DynamicCast<EffectNode>(mMovable->GetObjectByName(effectName));
	if (en)
	{
		Node *parent = DynamicCast<Node>(en->GetParent());
		if (parent)
		{
			parent->DetachChild(en);
		}
	}
}
//----------------------------------------------------------------------------
EffectNode *Actor::GetActorEffect (const std::string &effectName)
{
	EffectNode *en = DynamicCast<EffectNode>(mMovable->GetObjectByName(\
		effectName));
	return en;
}
//----------------------------------------------------------------------------