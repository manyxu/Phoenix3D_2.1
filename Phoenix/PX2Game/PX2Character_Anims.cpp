/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Character_Anims.cpp
*
*/

#include "PX2Character.hpp"
#include "PX2Animation3DSkeleton.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
bool Character::AddAnim (Animation *anim)
{
	if (HasAnim(anim))
		return false;

	mAnims.push_back(anim);
	anim->SetCharacter(this);

	if (anim->GetName() == "stand")
		mStandbyAnim = anim;

	return true;
}
//----------------------------------------------------------------------------
bool Character::HasAnim (Animation *anim)
{
	assertion(0!=anim, "anim must not be 0.");

	if (!anim)
		return false;

	for (int i=0; i <(int)mAnims.size(); i++)
	{
		if (mAnims[i] == anim)
		{
			return true;
		}
	}

	return false;
}
//----------------------------------------------------------------------------
bool Character::RemoveAnim (Animation *anim)
{
	if (!HasAnim(anim))
		return false;

	std::vector<AnimationPtr>::iterator it = mAnims.begin();
	for (; it!=mAnims.end(); it++)
	{
		if (*it == anim)
		{
			anim->OnRemove(this);
			anim->SetCharacter(0);
			mAnims.erase(it);

			if (mCurAnim == anim)
				mCurAnim = 0;

			return true;
		}
	}

	return false;
}
//----------------------------------------------------------------------------
void Character::RemoveAllAnims ()
{
	for (int i=0; i<(int)mAnims.size(); i++)
	{
		mAnims[i]->SetCharacter(0);
	}

	mAnims.clear();
}
//----------------------------------------------------------------------------
Animation *Character::GetAnim (int i)
{
	if (0<=i && i<(int)mAnims.size())
		return mAnims[i];

	return 0;
}
//----------------------------------------------------------------------------
void Character::PlayAnim (Animation *anim)
{
	bool sameAnim = false;
	if (mCurAnim == anim)
		sameAnim = true;

	if (!HasAnim(anim))
		return;

	if (mCurAnim)
	{
		mCurAnim->Stop();
	}	

	Node *charNode = (Node*)GetMovable();
	if (mCurAnim && charNode)
	{
		Animation3DSkeleton *anim3dSk = DynamicCast<Animation3DSkeleton>((Animation*)mCurAnim);
		Node *animNode = anim3dSk->GetAnimNode();
		charNode->DetachChild(animNode);

		if (!sameAnim)
		{	
			mLastAnimObj = new0 AnimationObject();
			mLastAnimObj->TheAnim = mCurAnim;
			mLastAnimObj->BlendTime = 0.0f;
			mLastAnimObj->TheCharacter = this;
		}
		else
		{
			mLastAnimObj = 0;
		}
	}

	if (mModelAnimMovable && mModelAnimMovable->GetParent())
	{ // simple remove
	//	charNode->DetachChild(mModelAnimMovable);
	}

	mCurAnim = anim;

	mCurAnim->OnPlay(this);
}
//----------------------------------------------------------------------------
void Character::PlayAnimByName (const std::string &name)
{
	Animation *anim = GetAnimByName(name);
	if (anim)
	{
		PlayAnim(anim);
	}
}
//----------------------------------------------------------------------------
void Character::StopAnim (Animation *anim)
{
	if (!HasAnim(anim))
		return;

	anim->Stop();
}
//----------------------------------------------------------------------------
void Character::PlayCurAnim ()
{
	if (mCurAnim)
		mCurAnim->LetCharacterPlay();
}
//----------------------------------------------------------------------------
void Character::StopCurAnim ()
{
	if (mCurAnim)
		mCurAnim->Stop();
}
//----------------------------------------------------------------------------
bool Character::IsHasAnimPlaying () const
{
	for (int i=0; i<(int)mAnims.size(); i++)
	{
		if (mAnims[i]->IsPlaying())
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
Animation * Character::GetAnimByName (const std::string &name)
{
	for (int i=0; i <(int)mAnims.size(); i++)
	{
		if (mAnims[i]->GetName() == name)
		{
			return mAnims[i];
		}
	}

	return 0;
}
//----------------------------------------------------------------------------
bool Character::IsNodeHasMesh (Node *node)
{
	for (int i=0; i<node->GetNumChildren(); i++)
	{
		TriMesh *mesh = DynamicCast<TriMesh>(node->GetChild(i));
		if (mesh)
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void Character::SetModelTagName (const std::string &modelTagName)
{
	mModelTagName = modelTagName;

	for (int i=0; i <(int)mAnims.size(); i++)
	{
		if (mAnims[i])
		{
			mAnims[i]->SetCharacter(this);
		}
	}
}
//----------------------------------------------------------------------------