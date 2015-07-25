// X_Skill.inl

//----------------------------------------------------------------------------
inline void X_Skill::SetNextSkillID(int skillID)
{
	mNextSkillID = skillID;
}
//----------------------------------------------------------------------------
inline int X_Skill::GetNextSkillID() const
{
	return mNextSkillID;
}
//----------------------------------------------------------------------------
inline void X_Skill::SetDefPartIndex(int defPartIndex)
{
	mDefPartIndex = defPartIndex;
}
//----------------------------------------------------------------------------
inline int X_Skill::GetDefPartIndex() const
{
	return mDefPartIndex;
}
//----------------------------------------------------------------------------
inline void X_Skill::SetDefParts(const std::vector<int> &defParts)
{
	mDefParts = defParts;
}
//----------------------------------------------------------------------------
inline const std::vector<int> &X_Skill::GetDefParts() const
{
	return mDefParts;
}
//----------------------------------------------------------------------------