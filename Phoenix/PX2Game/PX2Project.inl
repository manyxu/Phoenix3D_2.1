/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Project.cpp
*
*/

//----------------------------------------------------------------------------
inline void Project::SetName (const std::string &name)
{
	mName = name;
}
//----------------------------------------------------------------------------
inline void Project::SetWidth (int width)
{
	mSize.Width = (float)width;
}
//----------------------------------------------------------------------------
inline void Project::SetHeight (int height)
{
	mSize.Height = (float)height;
}
//----------------------------------------------------------------------------
inline const Sizef &Project::GetSize () const
{
	return mSize;
}
//----------------------------------------------------------------------------
inline void Project::SetInGamePlay (bool inGamePlay)
{
	mIsInGamePlay = inGamePlay;
}
//----------------------------------------------------------------------------
inline bool Project::IsInGamePlay()
{
	return mIsInGamePlay;
}
//----------------------------------------------------------------------------
inline const std::string &Project::GetName () const
{
	return mName;
}
//----------------------------------------------------------------------------
inline const std::string &Project::GetSceneFilename () const
{
	return mSceneFilename;
}
//----------------------------------------------------------------------------
inline const std::string &Project::GetUIFilename () const
{
	return mUIFilename;
}
//----------------------------------------------------------------------------
inline const std::string &Project::GetLogicFilename () const
{
	return mLogicGroupFilename;
}
//----------------------------------------------------------------------------
inline const std::string &Project::GetLanguage () const
{
	return mLanguage;
}
//----------------------------------------------------------------------------
inline const std::string &Project::GetLanguage1 () const
{
	return mLanguage1;
}
//----------------------------------------------------------------------------
inline int Project::GetWidth () const
{
	return (int)mSize.Width;
}
//----------------------------------------------------------------------------
inline int Project::GetHeight () const
{
	return (int)mSize.Height;
}
//----------------------------------------------------------------------------
inline Scene *Project::GetScene ()
{
	return mScene;
}
//----------------------------------------------------------------------------
inline UIFrame *Project::GetUI ()
{
	return mUI;
}
//----------------------------------------------------------------------------
inline LogicGroup *Project::GetLogicGroup ()
{
	return mLogicGroup;
}
//----------------------------------------------------------------------------
inline void Project::SetColor (Float4 color)
{
	mColor = color;
}
//----------------------------------------------------------------------------
inline Float4 Project::GetColor ()
{
	return mColor;
}
//----------------------------------------------------------------------------
inline bool Project::IsShowProjectInfo ()
{
	return mIsShowProjectInfo;
}
//----------------------------------------------------------------------------
inline bool Project::IsSceneWired ()
{
	return mIsSceneWired;
}
//----------------------------------------------------------------------------
inline bool Project::IsShowSceneBound ()
{
	return mIsShowSceneBound;
}
//----------------------------------------------------------------------------
inline bool Project::IsShowGrid ()
{
	return mIsShowGrid;
}
//----------------------------------------------------------------------------
inline bool Project::IsUIWired ()
{
	return mIsUIWired;
}
//----------------------------------------------------------------------------
inline float Project::GetUICameraPercent ()
{
	return mUICameraPercent;
}
//----------------------------------------------------------------------------
inline bool Project::IsShowUI ()
{
	return mIsShowUI;
}
//----------------------------------------------------------------------------
inline bool Project::IsShowUIRange ()
{
	return mIsShowUIRange;
}
//----------------------------------------------------------------------------
inline void Project::SetInEditor (bool inEditor)
{
	mIsInEditor = inEditor;
}
//----------------------------------------------------------------------------
inline bool Project::IsInEditor () const
{
	return mIsInEditor;
}
//----------------------------------------------------------------------------
inline void Project::SetPublish (bool pub)
{
	mIsPublish = pub;
}
//----------------------------------------------------------------------------
inline bool Project::IsPublish () const
{
	return mIsPublish;
}
//----------------------------------------------------------------------------
inline void Project::SetUseImagesEncrypt (bool encrypt)
{
	mIsImagesEncrypt = encrypt;
}
//----------------------------------------------------------------------------
inline bool Project::IsUseImagesEncrypt () const
{
	return mIsImagesEncrypt;
}
//----------------------------------------------------------------------------