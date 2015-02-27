// PX2Character_Anim.cpp

#include "PX2Character.hpp"
#include "PX2Animation3DSkeleton.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
bool Character::AddAnim(Animation *anim)
{
	if (HasAnim(anim)) return false;

	int id = anim->GetID();
	mAnimsMap[id] = anim;
	anim->SetCharacter(this);

	return true;
}
//----------------------------------------------------------------------------
bool Character::HasAnim(Animation *anim)
{
	return HasAnim(anim->GetID());
}
//----------------------------------------------------------------------------
bool Character::HasAnim(int id)
{
	std::map<int, AnimationPtr>::iterator it = mAnimsMap.find(id);
	if (it != mAnimsMap.end())
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool Character::RemoveAnim(Animation *anim)
{
	return RemoveAnim(anim->GetID());
}
//----------------------------------------------------------------------------
bool Character::RemoveAnim(int id)
{
	std::map<int, AnimationPtr>::iterator it = mAnimsMap.find(id);
	if (it != mAnimsMap.end())
	{
		it->second->SetCharacter(0);

		mAnimsMap.erase(it);
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void Character::RemoveAllAnims()
{
	std::map<int, AnimationPtr>::iterator it = mAnimsMap.begin();
	for (; it != mAnimsMap.end(); it++)
	{
		it->second->SetCharacter(0);
	}

	mAnimsMap.clear();
}
//----------------------------------------------------------------------------
int Character::GetNumAnims() const
{
	return (int)mAnimsMap.size();
}
//----------------------------------------------------------------------------
Animation *Character::GetAnimByID(int id)
{
	std::map<int, AnimationPtr>::iterator it = mAnimsMap.find(id);
	if (it != mAnimsMap.end())
	{
		return it->second;
	}

	return 0;
}
//----------------------------------------------------------------------------
void Character::SetDefaultAnimID(int id)
{
	mDefaultAnim = GetAnimByID(id);
}
//----------------------------------------------------------------------------
void Character::PlayAnim(Animation *anim)
{
	if (!HasAnim(anim)) return;

	bool sameAnim = false;
	if (mCurPlayingAnim == anim)
		sameAnim = true;

	if (mCurPlayingAnim)
		mCurPlayingAnim->Stop();

	Node *charNode = DynamicCast<Node>(GetMovable());
	if (mCurPlayingAnim && charNode)
	{
		Animation3DSkeleton *anim3dSk = DynamicCast<Animation3DSkeleton>(mCurPlayingAnim);

		if (anim3dSk)
		{
			Node *animNode = anim3dSk->GetAnimNode();
			charNode->DetachChild(animNode);
		}

		if (!sameAnim)
		{
			mLastAnimObj = new0 AnimationObject();
			mLastAnimObj->TheAnim = mCurPlayingAnim;
			mLastAnimObj->BlendTime = 0.0f;
			mLastAnimObj->TheCharacter = this;
		}
		else
		{
			mLastAnimObj = 0;
		}
	}

	mCurPlayingAnim = anim;

	if (mCurPlayingAnim)
		mCurPlayingAnim->OnPlay(this);
}
//----------------------------------------------------------------------------
void Character::PlayAnimByID(int id)
{
	Animation *anim = GetAnimByID(id);
	if (anim) PlayAnim(anim);
}
//----------------------------------------------------------------------------
void Character::StopAnim(Animation *anim)
{
	if (!HasAnim(anim))
		return;

	anim->Stop();
}
//----------------------------------------------------------------------------
void Character::PlayCurAnim()
{
	if (mCurPlayingAnim)
		mCurPlayingAnim->LetCharacterPlay();
}
//----------------------------------------------------------------------------
void Character::StopCurAnim()
{
	if (mCurPlayingAnim)
		mCurPlayingAnim->Stop();
}
//----------------------------------------------------------------------------
bool Character::IsHasAnimPlaying() const
{
	std::map<int, AnimationPtr>::const_iterator it = mAnimsMap.begin();
	for (; it != mAnimsMap.end(); it++)
	{
		if (it->second->IsPlaying())
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------