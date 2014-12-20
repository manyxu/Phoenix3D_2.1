/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Project.cpp
*
*/

#include "PX2Project.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2XMLData.hpp"
#include "PX2UIManager.hpp"
#include "PX2StringHelp.hpp"
#include "PX2OutStream.hpp"
#include "PX2InStream.hpp"
#include "PX2LanguageManager.hpp"
#include "PX2GameManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
Project::Project ()
	:
mIsInGamePlay(false),
mIsShowProjectInfo(true),
mIsShowSceneBound(true),
mIsSceneWired(false),
mIsUIWired(false),
mUICameraPercent(1.0f),
mIsShowUI(true),
mIsShowUIRange(true),
mIsShowGrid(true),
mIsInEditor(false),
mIsPublish(false),
mIsImagesEncrypt(false),
mIsDarkScale(false),
mDarkMax(1.0f),
mDarkSpeed(0.5f),
mCurDarkValue(0.0f)
{
	mSize = Sizef(960.0f, 640.0f);
	mColor = Float4::BLACK;
	SetUI(new0 UIFrame());
	SetLogicGroup(new0 LogicGroup());
}
//----------------------------------------------------------------------------
Project::~Project ()
{
}
//----------------------------------------------------------------------------
void Project::AddUpdateCallback (ProjectUpdateCallback callback)
{
	if (HasCallback(callback))
		return;

	mCallbacks.push_back(callback);
}
//----------------------------------------------------------------------------
bool Project::HasCallback (ProjectUpdateCallback callback)
{
	for (int i=0; i<(int)mCallbacks.size(); i++)
	{
		if (callback == mCallbacks[i])
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void Project::RemoveUpdateCallback (ProjectUpdateCallback callback)
{
	std::vector<ProjectUpdateCallback>::iterator it = mCallbacks.begin();
	for (; it!=mCallbacks.end(); it++)
	{
		if (*it == callback)
		{
			mCallbacks.erase(it);
			return;
		}
	}
}
//----------------------------------------------------------------------------
void Project::ClearCallbacks ()
{
	mCallbacks.clear();
}
//----------------------------------------------------------------------------
void Project::SetPlayDarkScaleEffect (bool scale)
{
	mIsDarkScale = scale;
}
//----------------------------------------------------------------------------
bool Project::IsPlayDarkScaleEffect () const
{
	return mIsDarkScale;
}
//----------------------------------------------------------------------------
void Project::SetDarkMax (float darkMax)
{
	mDarkMax = darkMax;
}
//----------------------------------------------------------------------------
float Project::GetDarkMax () const
{
	return mDarkMax;
}
//----------------------------------------------------------------------------
void Project::SetDarkSpeed (float speed)
{
	mDarkSpeed = speed;
}
//----------------------------------------------------------------------------
void Project::SetCurDarkValue (float val)
{
	mCurDarkValue = val;
}
//----------------------------------------------------------------------------
float Project::GetDarkSpeed () const
{
	return mDarkSpeed;
}
//----------------------------------------------------------------------------
float Project::GetCurDarkValue () const
{
	return mCurDarkValue;
}
//----------------------------------------------------------------------------
void Project::Update (double appSeconds, double elapsedSeconds)
{
	if (mIsDarkScale)
	{
		mCurDarkValue += mDarkSpeed * (float)elapsedSeconds;

		if (mCurDarkValue < 0.0f)
			mCurDarkValue = 0.0f;

		if (mCurDarkValue > mDarkMax)
			mCurDarkValue = mDarkMax;
	}

	for (int i=0; i<(int)mCallbacks.size(); i++)
	{
		(*mCallbacks[i])(appSeconds, elapsedSeconds);
	}

	Renderer *defRenderer = Renderer::GetDefaultRenderer();

	if (mScene)
	{
		defRenderer->SetCamera(mScene->GetCameraActor()->GetCamera());
		PX2_GR.SetRenderViewPort(defRenderer, true);
		mScene->Update(appSeconds, elapsedSeconds);

		mScene->ComputeVisibleSetAndEnvironment();
	}

	UIView *uiView = UIManager::GetSingleton().GetDefaultView();
	if (uiView)
	{
		Camera *uiCamera = uiView->GetCamera();
		defRenderer->SetCamera(uiCamera);
		uiView->CallRendererSetViewport();
		PX2_GR.SetRenderViewPort(defRenderer, true);
		uiView->Update(appSeconds, elapsedSeconds);

		uiView->ComputeVisibleSet();
	}
}
//----------------------------------------------------------------------------
bool Project::Save (const std::string &filename)
{
	// xml
	XMLData data;
	data.Create();

	XMLNode projNode = data.NewChild("Project");
	projNode.SetAttributeString("Name", mName.c_str());
	projNode.SetAttributeInt("Width", (int)mSize.Width);
	projNode.SetAttributeInt("Height", (int)mSize.Height);
	projNode.SetAttributeFloat("Color0", mColor[0]);
	projNode.SetAttributeFloat("Color1", mColor[1]);
	projNode.SetAttributeFloat("Color2", mColor[2]);
	projNode.SetAttributeFloat("Color3", mColor[3]);
	projNode.SetAttributeBool("IsUseImagesEncrypt", mIsImagesEncrypt);
	projNode.SetAttributeBool("IsShowProjectInfo", mIsShowProjectInfo);
	projNode.SetAttributeBool("IsShowSceneBound", mIsShowSceneBound);
	projNode.SetAttributeBool("IsSceneWired", mIsSceneWired);
	projNode.SetAttributeBool("IsUIWired", mIsUIWired);
	projNode.SetAttributeFloat("UICameraPercent", mUICameraPercent);
	projNode.SetAttributeBool("IsShowUI", mIsShowUI);
	projNode.SetAttributeBool("IsShowUIRange", mIsShowUIRange);
	projNode.SetAttributeBool("IsShowGrid", mIsShowGrid);

	XMLNode sceneNode = projNode.NewChild("Scene");
	sceneNode.SetAttributeString("Filename", mSceneFilename.c_str());

	XMLNode languageNode = projNode.NewChild("Language");
	languageNode.SetAttributeString("Filename", mLanguage.c_str());

	XMLNode languageNode1 = projNode.NewChild("Language1");
	languageNode1.SetAttributeString("Filename", mLanguage.c_str());

	std::string outPath;
	std::string outBaseName;
	std::string outExt;
	StringHelp::SplitFullFilename(filename, outPath, outBaseName, outExt);
	std::string outName = outPath + outBaseName + ".px2ui";

	if (mUI)
	{
		Transform beforeLocalTrans = mUI->LocalTransform;
		Transform beforeWorldTrans = mUI->WorldTransform;
		OutStream output;
		mUI->LocalTransform.MakeIdentity();
		mUI->WorldTransform.MakeIdentity();
		output.Insert(mUI);
		output.Save(outName);
		mUI->LocalTransform = beforeLocalTrans;
		mUI->WorldTransform = beforeWorldTrans;
	}


/*
	XMLNode projNode("Project");
	projNode.Create(data.GetDoc());
	projNode.SetAttributeString("Name", mName.c_str());
	projNode.SetAttributeInt("Width", mWidth);
	projNode.SetAttributeInt("Height", mHeight);
	projNode.SetAttributeFloat("Color0", mColor[0]);
	projNode.SetAttributeFloat("Color1", mColor[1]);
	projNode.SetAttributeFloat("Color2", mColor[2]);
	projNode.SetAttributeFloat("Color3", mColor[3]);
	projNode.SetAttributeBool("IsUseImagesEncrypt", mIsImagesEncrypt);
	projNode.SetAttributeBool("IsShowProjectInfo", mIsShowProjectInfo);
	projNode.SetAttributeBool("IsShowSceneBound", mIsShowSceneBound);
	projNode.SetAttributeBool("IsSceneWired", mIsSceneWired);
	projNode.SetAttributeBool("IsUIWired", mIsUIWired);
	projNode.SetAttributeFloat("UICameraPercent", mUICameraPercent);
	projNode.SetAttributeBool("IsShowUI", mIsShowUI);
	projNode.SetAttributeBool("IsShowUIRange", mIsShowUIRange);
	projNode.SetAttributeBool("IsShowGrid", mIsShowGrid);

	XMLNode sceneNode("Scene");
	sceneNode.Create(projNode.mDoc);
	sceneNode.SetAttributeString("Filename", mSceneFilename.c_str());
	projNode.LinkEndChild(sceneNode);

	XMLNode languageNode("Language");
	languageNode.Create(projNode.mDoc);
	languageNode.SetAttributeString("Filename", mLanguage.c_str());
	projNode.LinkEndChild(languageNode);

	XMLNode languageNode1("Language1");
	languageNode1.Create(projNode.mDoc);
	languageNode1.SetAttributeString("Filename", mLanguage.c_str());
	projNode.LinkEndChild(languageNode1);

	std::string outPath;
	std::string outBaseName;
	std::string outExt;
	StringHelp::SplitFullFilename(filename, outPath, outBaseName, outExt);
	std::string outName = outPath + outBaseName + ".px2ui";

	if (mUI)
	{
		Transform beforeLocalTrans = mUI->LocalTransform;
		Transform beforeWorldTrans = mUI->WorldTransform;
		OutStream output;
		mUI->LocalTransform.MakeIdentity();
		mUI->WorldTransform.MakeIdentity();
		output.Insert(mUI);
		output.Save(outName);
		mUI->LocalTransform = beforeLocalTrans;
		mUI->WorldTransform = beforeWorldTrans;
	}

	data.LinkEndChild(projNode);
*/
	if (data.SaveFile(filename))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool Project::Load (const std::string &filename)
{
	std::string name;
	int width = 0;
	int height = 0;
	std::string sceneFilename;
	std::string uiFilename;
	std::string languageFilename;
	
	char *buffer = 0;
	int bufferSize = 0;
	if (ResourceManager::GetSingleton().LoadBuffer(filename, bufferSize,
		buffer))
	{
		XMLData data;
		if (data.LoadBuffer(buffer, bufferSize))
		{
			XMLNode rootNode = data.GetRootNode();
			name = rootNode.AttributeToString("Name");
			width = rootNode.AttributeToInt("Width");
			height = rootNode.AttributeToInt("Height");
			Float4 color = Float4::WHITE;
			color[0] = rootNode.AttributeToFloat("Color0");
			color[1] = rootNode.AttributeToFloat("Color1");
			color[2] = rootNode.AttributeToFloat("Color2");
			color[3] = rootNode.AttributeToFloat("Color3");
			bool isShowProjInfo = rootNode.AttributeToBool("IsShowProjectInfo");
			bool isShowSceneBound = rootNode.AttributeToBool("IsShowSceneBound");
			bool isSceneWired = rootNode.AttributeToBool("IsSceneWired");
			bool isUIWired = rootNode.AttributeToBool("IsUIWired");
			float uiCameraPercent = rootNode.AttributeToFloat("UICameraPercent");
			bool isShowUI = rootNode.AttributeToBool("IsShowUI");
			bool isShowUIRange = rootNode.AttributeToBool("IsShowUIRange");
			bool isShowGrid = rootNode.AttributeToBool("IsShowGrid");
			
			bool isUseImagesEncrypt = false;
			if (rootNode.HasAttribute("IsUseImagesEncrypt"))
			{
				isUseImagesEncrypt = rootNode.AttributeToBool("IsUseImagesEncrypt");
			}

			mName = name;
			mSize = Sizef((float)width, (float)height);

			SetColor(color);
			SetShowProjectInfo(isShowProjInfo);
			SetShowSceneBound(isShowSceneBound);
			SetSceneWired(isSceneWired);
			SetUIWired(isUIWired);
			SetUICameraPercent(uiCameraPercent);
			SetShowUI(isShowUI);
			SetShowUIRange(isShowUIRange);
			SetShowGrid(isShowGrid);
			SetUseImagesEncrypt(isUseImagesEncrypt);

			XMLNode sceneNode = rootNode.GetChild("Scene");
			if (!sceneNode.IsNull())
			{
				sceneFilename = sceneNode.AttributeToString("Filename");
				SetSceneFilename(sceneFilename);
			}
			XMLNode languageNode = rootNode.GetChild("Language");
			if (!languageNode.IsNull())
			{
				languageFilename = languageNode.AttributeToString("Filename");
				SetLanguage(languageFilename);
			}
			XMLNode languageNode1 = rootNode.GetChild("Language1");
			if (!languageNode1.IsNull())
			{
				languageFilename = languageNode1.AttributeToString("Filename");
				SetLanguage1(languageFilename);
			}

			std::string outPath;
			std::string outBaseName;
			std::string outExt;
			StringHelp::SplitFullFilename(filename, outPath, outBaseName, outExt);
			
			std::string uiInName = outPath + outBaseName + ".px2ui";
			SetUIFilename(uiInName);

			std::string logicInName = outPath + outBaseName + ".px2logic";
			SetLogicFilename(logicInName);
		}
	}
	else
	{
		return false;
	}

	return true;
}
//----------------------------------------------------------------------------
void Project::SetSceneFilename (const std::string &filename)
{
	mSceneFilename = filename;
}
//----------------------------------------------------------------------------
void Project::SetUIFilename (const std::string &filename)
{
	mUIFilename = filename;
}
//----------------------------------------------------------------------------
void Project::SetLogicFilename (const std::string &filename)
{
	mLogicGroupFilename = filename;
}
//----------------------------------------------------------------------------
void Project::SetLanguage (const std::string &filename)
{
	mLanguage = filename;

	if ("" != mLanguage)
	{
		PX2_LM.Add(mLanguage.c_str());
	}
}
//----------------------------------------------------------------------------
void Project::SetLanguage1 (const std::string &filename)
{
	mLanguage1 = filename;

	if ("" != mLanguage1)
	{
		PX2_LM.Add(mLanguage1.c_str());
	}
}
//----------------------------------------------------------------------------
void Project::SetScene (Scene *scene)
{
	if (mScene == scene)
		return;

	if (mScene)
	{
		mScene->GoOutFromEventWorld();
	}

	mScene = scene;
	if (mScene)
	{
		mScene->ComeInToEventWorld();
	}
}
//----------------------------------------------------------------------------
void Project::SetUI (UIFrame *frame)
{
	mUI = frame;
	UIManager::GetSingleton().GetDefaultView()->SetMainFrame(frame);
}
//----------------------------------------------------------------------------
void Project::SetLogicGroup (LogicGroup *group)
{
	mLogicGroup = group;
}
//----------------------------------------------------------------------------
void Project::SetShowProjectInfo (bool show)
{
	mIsShowProjectInfo = show;
}
//----------------------------------------------------------------------------
void Project::SetSceneWired (bool wire)
{
	mIsSceneWired = wire;
}
//----------------------------------------------------------------------------
void Project::SetShowSceneBound (bool show)
{
	mIsShowSceneBound = show;
}
//----------------------------------------------------------------------------
void Project::SetUIWired (bool wire)
{
	mIsUIWired = wire;
}
//----------------------------------------------------------------------------
void Project::SetUICameraPercent (float percent)
{
	mUICameraPercent = percent;
}
//----------------------------------------------------------------------------
void Project::SetShowUI (bool show)
{
	mIsShowUI = show;
}
//----------------------------------------------------------------------------
void Project::SetShowUIRange (bool show)
{
	mIsShowUIRange = show;
}
//----------------------------------------------------------------------------
void Project::SetShowGrid(bool show)
{
	mIsShowGrid = show;
}
//----------------------------------------------------------------------------