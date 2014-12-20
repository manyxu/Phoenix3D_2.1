/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Character.inl
*
*/

//----------------------------------------------------------------------------
inline void Character::SetUseAutoWorldBound (bool isUseAutoWorldBound)
{
	mIsAutoWorldBound = isUseAutoWorldBound;
}
//----------------------------------------------------------------------------
inline bool Character::IsUseAutoWorldBound () const
{
	return mIsAutoWorldBound;
}
//----------------------------------------------------------------------------
inline void Character::SetAutoWorldBoundRadius (float radius)
{
	mAutoWorldBoundRadius = radius;
}
//----------------------------------------------------------------------------
inline float Character::GetAutoWorldBoundRadius () const
{
	return mAutoWorldBoundRadius;
}
//----------------------------------------------------------------------------
inline int Character::GetLevel () const
{
	return mLevel;
}
//----------------------------------------------------------------------------
inline void Character::SetCurHPNoReduce (bool de)
{
	mIsCurHPNoReduce = de;
}
//----------------------------------------------------------------------------
inline bool Character::IsCurHPNoRecline () const
{
	return mIsCurHPNoReduce;
}
//----------------------------------------------------------------------------
inline int Character::GetCurHP () const
{
	return mHP;
}
//----------------------------------------------------------------------------
inline std::map<std::string, int> Character::GetMMapHPs () const
{
	return mMMapHPs;
}
//----------------------------------------------------------------------------
inline int Character::GetMHP () const
{
	return mMHP;
}
//----------------------------------------------------------------------------
inline float Character::GetHPPercent () const
{
	return (float)GetCurHP()/(float)GetMHP();
}
//----------------------------------------------------------------------------
inline bool Character::IsFreezed () const
{
	return mIsFreezed;
}
//----------------------------------------------------------------------------
inline void Character::SetDieDoDelete (bool isDieDoDelete)
{
	mIsDieDoDelete = isDieDoDelete;
}
//----------------------------------------------------------------------------
inline bool Character::IsDieDoDelete () const
{
	return mIsDieDoDelete;
}
//----------------------------------------------------------------------------
inline bool Character::IsDead () const
{
	return mIsDead;
}
//----------------------------------------------------------------------------
inline int Character::GetBaseHPCurLevel () const
{
	return mBaseHPCurLevel;
}
//----------------------------------------------------------------------------
inline int Character::GetCurAP () const
{
	return mAP;
}
//----------------------------------------------------------------------------
inline std::map<std::string, int> Character::GetMMapAPs () const
{
	return mMMapAPs;
}
//----------------------------------------------------------------------------
inline int Character::GetMAP () const
{
	return mMAP;
}
//----------------------------------------------------------------------------
inline int Character::GetBaseAPCurLevel () const
{
	return mBaseAPCurLevel;
}
//----------------------------------------------------------------------------
inline int Character::GetExp ()
{
	return mExp;
}
//----------------------------------------------------------------------------
inline int Character::GetExpCurLevel ()
{
	return mExpCurLevel;
}
//----------------------------------------------------------------------------
inline void Character::SetScriptHandler_OnDie (const std::string &handler)
{
	mScriptHandler_OnDie = handler;
}
//----------------------------------------------------------------------------
inline const std::string &Character::GetScriptHandler_OnDie () const
{
	return mScriptHandler_OnDie;
}
//----------------------------------------------------------------------------
inline int Character::GetNumAnims () const
{
	return (int)mAnims.size();
}
//----------------------------------------------------------------------------
inline Animation *Character::GetCurPlayingAnim ()
{
	return mCurAnim;
}
//----------------------------------------------------------------------------
inline const std::string &Character::GetModelTagName () const
{
	return mModelTagName;
}
//----------------------------------------------------------------------------
inline Animation *Character::GetStandAnim ()
{
	return mStandbyAnim;
}
//----------------------------------------------------------------------------
inline Movable *Character::GetSkinMovable ()
{
	return mSkinMovable;
}
//----------------------------------------------------------------------------
inline Movable *Character::GetModelAnimMovable ()
{
	return mModelAnimMovable;
}
//----------------------------------------------------------------------------
inline std::map<FString, BlendTransformController*> &Character::GetBTCMap ()
{
	return mBTCMap;
}
//----------------------------------------------------------------------------
inline Skill *Character::GetDefSkill ()
{
	return mDefSkill;
}
//----------------------------------------------------------------------------
inline int Character::GetNumItems () const
{
	return (int)mItems.size();
}
//----------------------------------------------------------------------------
inline int Character::GetNumSkills () const
{
	return (int)mSkills.size();
}
//----------------------------------------------------------------------------
inline int Character::GetNumBufs () const
{
	return (int)mBufs.size();
}
//----------------------------------------------------------------------------
inline void Character::SetWatchDistance (float dist)
{
	mWatchDistance = dist;
}
//----------------------------------------------------------------------------
inline float Character::GetWatchDistance () const
{
	return mWatchDistance;
}
//----------------------------------------------------------------------------
inline bool Character::IsCanBeAimed () const
{
	return mIsCanAimed;
}
//----------------------------------------------------------------------------
inline int Character::GetAimTarget () const
{
	return mAimTargetID;
}
//----------------------------------------------------------------------------
inline int Character::GetNumAimingMe () const
{
	return mNumAimingMe;
}
//----------------------------------------------------------------------------
inline void Character::AddNumAimingMe ()
{
	++mNumAimingMe;
}
//----------------------------------------------------------------------------
inline void Character::MinusNumAimingMe ()
{
	--mNumAimingMe;
}
//----------------------------------------------------------------------------
inline void Character::SetScriptHandler_OnBeAffect (const std::string &handler)
{
	mScriptHandler_OnBeAffect = handler;
}
//----------------------------------------------------------------------------
inline const std::string &Character::GetScriptHandler_OnBeAffect () const
{
	return mScriptHandler_OnBeAffect;
}
//----------------------------------------------------------------------------
inline void Character::SetScriptHandler_OnSucAffect (
	const std::string &handler)
{
	mScriptHandler_OnSucAffect = handler;
}
//----------------------------------------------------------------------------
inline const std::string &Character::GetScriptHandler_OnSucAffect () const
{
	return mScriptHandler_OnSucAffect;
}
//----------------------------------------------------------------------------
inline void Character::SetCurAffectMeObject(AffectObject *ao)
{
	mCurAffectMeObject = ao;
}
//----------------------------------------------------------------------------
inline AffectObject *Character::GetCurAffectMeObject () const
{
	return mCurAffectMeObject;
}
//----------------------------------------------------------------------------
inline void Character::SetCurSucAffectObject (AffectObject *ao)
{
	mCurSucAffectObject = ao;
}
//----------------------------------------------------------------------------
inline AffectObject *Character::GetCurSucAffectObject ()
{
	return mCurSucAffectObject;
}
//----------------------------------------------------------------------------
inline StateMachine<Character> *Character::GetActionSM () const
{
	return mActionSM;
}
//----------------------------------------------------------------------------
inline StateMachine<Character> *Character::GetMovementSM () const
{
	return mMovementSM;
}
//----------------------------------------------------------------------------
inline StateMachine<Character> *Character::GetPostureSM () const
{
	return mPostureSM;
}
//----------------------------------------------------------------------------