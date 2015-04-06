// PX2Project.cpp

#include "PX2Project.hpp"
#include "PX2XMLData.hpp"
#include "PX2StringHelp.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2StringTokenizer.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2Renderer.hpp"
#include "PX2UIView.hpp"
#include "PX2UIPicBox.hpp"
#include "PX2EngineLoop.hpp"
#include "PX2GraphicsRoot.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Object, Project);

//----------------------------------------------------------------------------
Project::Project() :
mEdit_UICameraPercent(1.0f),
mScreenOrientation(SO_LANDSCAPE),
mIsScene_UseBloom(false),
mIsScene_UseShadowMap(false)
{
	if (ScriptManager::GetSingletonPtr())
		PX2_SM.SetUserTypePointer("PX2_PROJ", "Project", this);

	PX2_ENGINELOOP.msProject = this;

	mBackgroundColor = Float4(0.5f, 0.5f, 0.5f, 1.0f);
	mProjBackgroundColor = Float4::WHITE;
	
	mSceneRenderStep = new0 RenderStepScene();
	mSceneRenderStep->SetPriority(20);
	mSceneRenderStep->SetName("Scene");
	mSceneRenderStep->SetRenderer(Renderer::GetDefaultRenderer());
	PX2_GR.AddRenderStep(mSceneRenderStep->GetName().c_str(), mSceneRenderStep);

	mUIRenderStep = new0 UIView(0);
	mUIRenderStep->SetPriority(10);
	mUIRenderStep->SetDoDepthClear(true);
	mUIRenderStep->SetName("UI");
	mUIRenderStep->SetRenderer(Renderer::GetDefaultRenderer());
	PX2_GR.AddRenderStep(mUIRenderStep->GetName().c_str(), mUIRenderStep);

	mUIFrame = new0 UIFrame();
	mUIFrame->SetName("RootFrame");
	SetUIFrame(mUIFrame);

	mIsScene_ShowShadowBloomEveryPass = false;

	mIsScene_BloomRenderTargetSizeSameWithScreen = true;
	mScene_BloomRenderTargetSize = Float2(512.0f, 512.0f);
	mScene_BloomBrightWeight = 0.3f;
	mScene_BloomBlurDeviation = 1.0f;
	mScene_BloomBlurWeight = 1.0f;
	mScene_BloomWeight = 1.0f;

	mIsScene_ShadowRenderTargetSizeSameWithScreen = false;
	mScene_ShadowRenderTargetSize = Float2(512.0f, 512.0f);
}
//----------------------------------------------------------------------------
Project::~Project ()
{
	PX2_GR.RemoveRenderSteps(mSceneRenderStep);
	mSceneRenderStep = 0;

	PX2_GR.RemoveRenderSteps(mUIRenderStep);
	mUIRenderStep = 0;

	if (ScriptManager::GetSingletonPtr())
		PX2_SM.SetUserTypePointer("PX2_PROJ", "Project", 0);
}
//----------------------------------------------------------------------------
void Project::Destory()
{
	if (PX2_ENGINELOOP.msProject)
	{
		PX2_ENGINELOOP.msProject = 0;
		Project::Set(0);
	}
}
//----------------------------------------------------------------------------
void Project::SetScreenOrientation(ScreenOrientation so)
{
	mScreenOrientation = so;
}
//----------------------------------------------------------------------------
Project::ScreenOrientation Project::_FromSOStr(const std::string &str)
{
	if ("landscape" == str) return SO_LANDSCAPE;
	else if ("portrait" == str) return SO_PORTRAIT;

	return SO_PORTRAIT;
}
//----------------------------------------------------------------------------
std::string Project::_ToSOStr(Project::ScreenOrientation so)
{
	if (SO_LANDSCAPE == so) return "landscape";
	else if (SO_PORTRAIT == so) return "portrait";

	return "portrait";
}
//----------------------------------------------------------------------------
bool Project::Save(const std::string &filename)
{
	if (!SaveConfig(filename))
		return false;

	std::string outPath;
	std::string outBaseName;
	std::string outExt;
	StringHelp::SplitFullFilename(filename, outPath, outBaseName, outExt);

	if (mUIFrame)
	{
		std::string outName = outPath + outBaseName + "_ui.px2obj";

		OutStream output;
		output.Insert(mUIFrame);
		output.Save(outName);
	}

	return false;
}
//----------------------------------------------------------------------------
bool Project::SaveConfig(const std::string &filename)
{
	// xml
	XMLData data;
	data.Create();

	XMLNode projNode = data.NewChild("project");

	// general
	XMLNode generalNode = projNode.NewChild("general");
	generalNode.SetAttributeString("name", GetName().c_str());
	generalNode.SetAttributeString("screenorientation", _ToSOStr(mScreenOrientation));
	generalNode.SetAttributeInt("width", (int)mSize.Width);
	generalNode.SetAttributeInt("height", (int)mSize.Height);
	std::string colorStr =
		StringHelp::IntToString((int)(mBackgroundColor[0] * 255.0f)) + "," +
		StringHelp::IntToString((int)(mBackgroundColor[1] * 255.0f)) + "," +
		StringHelp::IntToString((int)(mBackgroundColor[2] * 255.0f)) + "," +
		StringHelp::IntToString((int)(mBackgroundColor[3] * 255.0f));
	generalNode.SetAttributeString("backcolor", colorStr);
	std::string projColorStr =
		StringHelp::IntToString((int)(mProjBackgroundColor[0] * 255.0f)) + "," +
		StringHelp::IntToString((int)(mProjBackgroundColor[1] * 255.0f)) + "," +
		StringHelp::IntToString((int)(mProjBackgroundColor[2] * 255.0f)) + "," +
		StringHelp::IntToString((int)(mProjBackgroundColor[3] * 255.0f));
	generalNode.SetAttributeString("projcolor", projColorStr);

	// scene
	XMLNode sceneNode = projNode.NewChild("scene");
	sceneNode.SetAttributeString("filename", mSceneFilename.c_str());

	// render setting
	XMLNode renderNode = projNode.NewChild("render_setting");
	renderNode.SetAttributeBool("scene_isusebloom", mIsScene_UseBloom);
	renderNode.SetAttributeBool("scene_bloomrendertarget_sizesamewithscreen", mIsScene_BloomRenderTargetSizeSameWithScreen);
	renderNode.SetAttributeFloat("scene_bloomrendertarget_width", mScene_BloomRenderTargetSize[0]);
	renderNode.SetAttributeFloat("scene_bloomrendertarget_height", mScene_BloomRenderTargetSize[1]);
	renderNode.SetAttributeFloat("scene_bloombrightweight", mScene_BloomBrightWeight);
	renderNode.SetAttributeFloat("scene_bloomblurdeviation", mScene_BloomBlurDeviation);
	renderNode.SetAttributeFloat("scene_bloomblurweight", mScene_BloomBlurWeight);
	renderNode.SetAttributeFloat("scene_bloomweight", mScene_BloomWeight);

	renderNode.SetAttributeBool("scene_isuseshadowmap", mIsScene_UseShadowMap);
	renderNode.SetAttributeBool("scene_shadowrendertargetsizesamewithscreen", mIsScene_ShadowRenderTargetSizeSameWithScreen);
	renderNode.SetAttributeFloat("scene_shadowrendertargetsize_width", mScene_ShadowRenderTargetSize[0]);
	renderNode.SetAttributeFloat("scene_shadowrendertargetsize_height", mScene_ShadowRenderTargetSize[1]);

	// language
	XMLNode languageNode = projNode.NewChild("language");

	// publish
	XMLNode publish = projNode.NewChild("publish");

	// setting
	XMLNode settingNode = projNode.NewChild("edit_setting");
	settingNode.SetAttributeFloat("uicamerapercent", mEdit_UICameraPercent);

	if (data.SaveFile(filename))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool Project::Load(const std::string &filename)
{
	std::string name;
	int width = 0;
	int height = 0;
	std::string sceneFilename;
	std::string uiFilename;
	std::string languageFilename;

	char *buffer = 0;
	int bufferSize = 0;
	if (PX2_RM.LoadBuffer(filename, bufferSize, buffer))
	{
		XMLData data;
		if (data.LoadBuffer(buffer, bufferSize))
		{
			XMLNode rootNode = data.GetRootNode();

			// general
			XMLNode generalNode = rootNode.GetChild("general");
			if (!generalNode.IsNull())
			{
				name = generalNode.AttributeToString("name");

				SetScreenOrientation(_FromSOStr(generalNode.AttributeToString("screenorientation")));

				width = generalNode.AttributeToInt("width");
				height = generalNode.AttributeToInt("height");

				std::string colorStr = generalNode.AttributeToString("backcolor");
				StringTokenizer stk(colorStr, ",");
				Float4 color = Float4::MakeColor(
					StringHelp::StringToInt(stk[0]),
					StringHelp::StringToInt(stk[1]),
					StringHelp::StringToInt(stk[2]),
					StringHelp::StringToInt(stk[3]));

				std::string projcolorStr = generalNode.AttributeToString("projcolor");
				StringTokenizer stkprojcolor(projcolorStr, ",");
				Float4 projcolor = Float4::MakeColor(
					StringHelp::StringToInt(stkprojcolor[0]),
					StringHelp::StringToInt(stkprojcolor[1]),
					StringHelp::StringToInt(stkprojcolor[2]),
					StringHelp::StringToInt(stkprojcolor[3]));

				Sizef size = Sizef((float)width, (float)height);
				SetName(name);
				SetSize(size);
				mViewRect = Rectf(0.0f, 0.0f, size.Width, size.Height);
				SetBackgroundColor(color);
				SetProjBackgroundColor(projcolor);
			}

			// scene
			XMLNode sceneNode = rootNode.GetChild("scene");
			if (!sceneNode.IsNull())
			{
				sceneFilename = sceneNode.AttributeToString("filename");
				SetSceneFilename(sceneFilename);
			}

			XMLNode renderNode = rootNode.GetChild("render_setting");
			if (!renderNode.IsNull())
			{
				mIsScene_UseBloom = renderNode.AttributeToBool("scene_isusebloom");
				mIsScene_BloomRenderTargetSizeSameWithScreen = renderNode.AttributeToBool("scene_bloomrendertarget_sizesamewithscreen");
				mScene_BloomRenderTargetSize[0] = renderNode.AttributeToFloat("scene_bloomrendertarget_width");
				mScene_BloomRenderTargetSize[1] = renderNode.AttributeToFloat("scene_bloomrendertarget_height");
				mScene_BloomBrightWeight = renderNode.AttributeToFloat("scene_bloombrightweight");
				mScene_BloomBlurDeviation = renderNode.AttributeToFloat("scene_bloomblurdeviation");
				mScene_BloomBlurWeight = renderNode.AttributeToFloat("scene_bloomblurweight");
				mScene_BloomWeight = renderNode.AttributeToFloat("scene_bloomweight");

				mIsScene_UseShadowMap = renderNode.AttributeToBool("scene_isuseshadowmap");
				mIsScene_ShadowRenderTargetSizeSameWithScreen = renderNode.AttributeToBool("scene_shadowrendertargetsizesamewithscreen");
				mScene_ShadowRenderTargetSize[0] = renderNode.AttributeToFloat("scene_shadowrendertargetsize_width");
				mScene_ShadowRenderTargetSize[1] = renderNode.AttributeToFloat("scene_shadowrendertargetsize_height");
			}

			// language
			XMLNode languageNode = rootNode.GetChild("language");

			// publish
			XMLNode publishNode = rootNode.GetChild("publish");

			// setting
			XMLNode settingNode = rootNode.GetChild("setting");
			if (!settingNode.IsNull())
			{
				if (settingNode.HasAttribute("uicamerapercent"))
					mEdit_UICameraPercent = settingNode.AttributeToFloat("uicamerapercent");
			}

			// split file names
			std::string outPath;
			std::string outBaseName;
			std::string outExt;
			StringHelp::SplitFullFilename(filename, outPath, outBaseName, outExt);

			// ui
			mUIFilename = outPath + outBaseName + "_ui.px2obj";

			if (mSceneRenderStep)
			{
				mSceneRenderStep->SetUseBloom(mIsScene_UseBloom);
				mSceneRenderStep->SetScene_BloomRenderTargetSizeSameWithScreen(mIsScene_BloomRenderTargetSizeSameWithScreen);
				mSceneRenderStep->SetScene_BloomRenderTargetSize(mScene_BloomRenderTargetSize);
				mSceneRenderStep->SetScene_BloomBrightWeight(mScene_BloomBrightWeight);
				mSceneRenderStep->SetScene_BloomBlurDeviation(mScene_BloomBlurDeviation);
				mSceneRenderStep->SetScene_BloomBlurWeight(mScene_BloomBlurWeight);
				mSceneRenderStep->SetScene_BloomWeight(mScene_BloomWeight);
				mSceneRenderStep->SetUseShadowMap(mIsScene_UseShadowMap);
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}
//----------------------------------------------------------------------------
void Project::SetScene(Scene *scene)
{
	if (mScene)
	{
		mScene->GoOutEventWorld();
		mScene = 0;
		mSceneRenderStep->SetCamera(0);
		PX2_GR.SetCurEnvirParam(0);
	}

	mScene = scene;

	mSceneRenderStep->SetNode(mScene);

	if (mScene)
	{
		mScene->ComeInEventWorld();

		PX2_GR.SetCurEnvirParam(mScene->GetEnvirParam());

		CameraActor *camActor = mScene->GetUseCameraActor();

		if (camActor)
		{
			Camera *camera = camActor->GetCamera();
			Renderer::GetDefaultRenderer()->SetCamera(camera);
			mSceneRenderStep->SetCamera(camera);
		}
		else
		{
			mSceneRenderStep->SetCamera(0);
		}
	}
	else
	{
		mSceneRenderStep->SetCamera(0);
	}

	mSceneRenderStep->SetSize(mSize);
}
//----------------------------------------------------------------------------
void Project::SetSceneFilename(const std::string &scenefilename)
{
	mSceneFilename = scenefilename;
}
//----------------------------------------------------------------------------
void Project::SetUIFrame(UIFrame *ui)
{
	mUIFrame = ui;
	mUIRenderStep->SetNode(mUIFrame);
}
//----------------------------------------------------------------------------
void Project::SetSize(float width, float height)
{
	SetSize(Sizef(width, height));
}
//----------------------------------------------------------------------------
void Project::SetSize(const Sizef &size)
{
	mSize = size;

	PX2_GR.SetProjectSize(size);

	if (mSceneRenderStep)
	{
		mUIRenderStep->SetSize(mSize);
	}

	if (mUIRenderStep)
	{
		mUIRenderStep->SetSize(mSize);
	}
}
//----------------------------------------------------------------------------
void Project::SetBackgroundColor(const Float4 &color)
{
	mBackgroundColor = color;
}
//----------------------------------------------------------------------------
const Float4 &Project::GetBackgroundColor() const
{
	return mBackgroundColor;
}
//----------------------------------------------------------------------------
void Project::SetProjBackgroundColor(const Float4 &color)
{
	mProjBackgroundColor = color;
}
//----------------------------------------------------------------------------
const Float4 &Project::GetProjBackgroundColor() const
{
	return mProjBackgroundColor;
}
//----------------------------------------------------------------------------
bool Project::LoadScene(const std::string &pathname)
{
	Scene *newscene = DynamicCast<Scene>(PX2_RM.BlockLoad(pathname));
	if (newscene)
	{
		Project::GetSingleton().SetScene(newscene);
		Project::GetSingleton().SetSceneFilename(pathname);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool Project::LoadUI(const std::string &pathname)
{
	ObjectPtr uiObj = PX2_RM.BlockLoad(pathname);
	UIFrame *ui = DynamicCast<UIFrame>(uiObj);
	if (ui)
	{
		Project::GetSingleton().SetUIFrame(ui);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void Project::SetViewRect(const Rectf &viewRect)
{
	if (mSceneRenderStep)
	{
		mSceneRenderStep->SetViewPort(viewRect);
	}

	if (mUIRenderStep)
	{
		mUIRenderStep->SetViewPort(viewRect);
	}
}
//----------------------------------------------------------------------------
void Project::SetScene_UseBloom(bool isUseBloom)
{
	mIsScene_UseBloom = isUseBloom;

	if (mSceneRenderStep)
	{
		mSceneRenderStep->SetUseBloom(isUseBloom);
	}
}
//----------------------------------------------------------------------------
void Project::SetScene_BloomBrightWeight(float weight)
{
	mScene_BloomBrightWeight = weight;

	if (mSceneRenderStep)
	{
		mSceneRenderStep->SetScene_BloomBrightWeight(mScene_BloomBrightWeight);
	}
}
//----------------------------------------------------------------------------
void Project::SetScene_ShowShadowBloomEveryPass(
	bool isShowShadowBloomEveryPass)
{
	mIsScene_ShowShadowBloomEveryPass = isShowShadowBloomEveryPass;

	if (mSceneRenderStep)
	{
		mSceneRenderStep->SetScene_ShowShadowBloomEveryPass(
			isShowShadowBloomEveryPass);
	}
}
//----------------------------------------------------------------------------
bool Project::IsScene_ShowShadowBloomEveryPass() const
{
	return mIsScene_ShowShadowBloomEveryPass;
}
//----------------------------------------------------------------------------
void Project::SetScene_BloomRenderTargetSizeSameWithScreen(
	bool sizeSameWithScreen)
{
	mIsScene_BloomRenderTargetSizeSameWithScreen = sizeSameWithScreen;

	if (mSceneRenderStep)
	{
		mSceneRenderStep->SetScene_BloomRenderTargetSizeSameWithScreen(
			sizeSameWithScreen);
	}
}
//----------------------------------------------------------------------------
bool Project::IsScene_BloomRenderTargetSizeSameWithScreen() const
{
	return mIsScene_BloomRenderTargetSizeSameWithScreen;
}
//----------------------------------------------------------------------------
float Project::GetScene_BloomBrightWeight() const
{
	return mScene_BloomBrightWeight;
}
//----------------------------------------------------------------------------
void Project::SetScene_BloomRenderTargetSize(const Float2 &size)
{
	mScene_BloomRenderTargetSize = size;

	if (mSceneRenderStep)
	{
		mSceneRenderStep->SetScene_BloomRenderTargetSize(size);
	}
}
//----------------------------------------------------------------------------
void Project::SetScene_BloomBlurDeviation(float deviation)
{
	mScene_BloomBlurDeviation = deviation;

	if (mSceneRenderStep)
	{
		mSceneRenderStep->SetScene_BloomBlurDeviation(deviation);
	}
}
//----------------------------------------------------------------------------
void Project::SetScene_BloomBlurWeight(float weight)
{
	mScene_BloomBlurWeight = weight;

	if (mSceneRenderStep)
	{
		mSceneRenderStep->SetScene_BloomBlurWeight(weight);
	}
}
//----------------------------------------------------------------------------
void Project::SetScene_BloomWeight(float weight)
{
	mScene_BloomWeight = weight;

	if (mSceneRenderStep)
	{
		mSceneRenderStep->SetScene_BloomWeight(weight);
	}
}
//----------------------------------------------------------------------------
void Project::SetScene_UseShadowMap(bool isUseShadowMap)
{
	mIsScene_UseShadowMap = isUseShadowMap;

	if (mSceneRenderStep)
	{
		mSceneRenderStep->SetUseShadowMap(isUseShadowMap);
	}
}
//----------------------------------------------------------------------------
void Project::SetScene_ShadowRenderTargetSizeSameWithScreen(bool sameWithScreen)
{
	mIsScene_ShadowRenderTargetSizeSameWithScreen = sameWithScreen;

	if (mSceneRenderStep)
	{
		mSceneRenderStep->SetShadowRenderTargetSizeSameWithScreen(sameWithScreen);
	}
}
//----------------------------------------------------------------------------
void Project::SetScene_ShadowRenderTargetSize(const Float2 &size)
{
	mScene_ShadowRenderTargetSize = size;

	if (mSceneRenderStep)
	{
		mSceneRenderStep->SetShadowRenderTargetSize(size);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void Project::RegistProperties()
{
	Object::RegistProperties();

	AddPropertyClass("Project");

	std::vector<std::string> screenOrientations;
	screenOrientations.push_back("SO_LANDSCAPE");
	screenOrientations.push_back("SO_PORTRAIT");

	AddPropertyEnum("ScreenOrientation", (int)mScreenOrientation,
		screenOrientations);

	AddProperty("Size", PT_SIZE, mSize);

	Float3 color(mBackgroundColor[0], mBackgroundColor[1], mBackgroundColor[1]);
	AddProperty("BackgroundColor", PT_COLOR3FLOAT3, color);

	Float3 colorProj(mProjBackgroundColor[0], mProjBackgroundColor[1],
		mProjBackgroundColor[2]);
	AddProperty("ProjBackgroundColor", PT_COLOR3FLOAT3, colorProj);

	AddProperty("ViewRect", PT_RECT, mViewRect, false);

	AddProperty("IsScene_ShowShadowBloomEveryPass", PT_BOOL,
		mIsScene_ShowShadowBloomEveryPass);

	AddProperty("IsScene_UseBloom", PT_BOOL, mIsScene_UseBloom);
	AddProperty("IsScene_BloomRenderTargetSizeSameWithScreen", PT_BOOL,
		mIsScene_BloomRenderTargetSizeSameWithScreen);
	AddProperty("Scene_BloomRenderTargetSize", PT_FLOAT2, 
		mScene_BloomRenderTargetSize);
	AddProperty("Scene_BloomBrightWeight", PT_FLOAT, 
		mScene_BloomBrightWeight);
	AddProperty("Scene_BloomBlurDeviation", PT_FLOAT,
		mScene_BloomBlurDeviation);
	AddProperty("Scene_BloomBlurWeight", PT_FLOAT, mScene_BloomBlurWeight);
	AddProperty("Scene_BloomWeight", PT_FLOAT, mScene_BloomWeight);

	AddProperty("IsScene_UseShadowMap", PT_BOOL, mIsScene_UseShadowMap);
	AddProperty("IsScene_ShadowRenderTargetSizeSameWithScreen", PT_BOOL, 
		mIsScene_ShadowRenderTargetSizeSameWithScreen);
	AddProperty("Scene_ShadowRenderTargetSize", PT_FLOAT2,
		mScene_ShadowRenderTargetSize);
}
//----------------------------------------------------------------------------
void Project::OnPropertyChanged(const PropertyObject &obj)
{
	Object::OnPropertyChanged(obj);

	if ("ScreenOrientation" == obj.Name)
	{
		SetScreenOrientation((ScreenOrientation)PX2_ANY_AS(obj.Data, int));
	}
	else if ("Size" == obj.Name)
	{
		SetSize(PX2_ANY_AS(obj.Data, Sizef));
	}
	else if ("BackgroundColor" == obj.Name)
	{
		Float3 backColor = PX2_ANY_AS(obj.Data, Float3);
		mBackgroundColor = Float4(backColor[0], backColor[1], backColor[2],
			1.0f);
	}
	else if ("ProjBackgroundColor" == obj.Name)
	{
		Float3 progBackColor = PX2_ANY_AS(obj.Data, Float3);
		mProjBackgroundColor = Float4(progBackColor[0], progBackColor[1],
			progBackColor[2], 1.0f);
	}
	else if ("IsScene_UseBloom" == obj.Name)
	{
		SetScene_UseBloom(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("IsScene_ShowShadowBloomEveryPass" == obj.Name)
	{
		SetScene_ShowShadowBloomEveryPass(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("IsScene_BloomRenderTargetSizeSameWithScreen" == obj.Name)
	{
		SetScene_BloomRenderTargetSizeSameWithScreen(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("Scene_BloomRenderTargetSize" == obj.Name)
	{
		SetScene_BloomRenderTargetSize(PX2_ANY_AS(obj.Data, Float2));
	}
	else if ("Scene_BloomBrightWeight" == obj.Name)
	{
		SetScene_BloomBrightWeight(PX2_ANY_AS(obj.Data, float));
	}
	else if ("Scene_BloomBlurDeviation" == obj.Name)
	{
		SetScene_BloomBlurDeviation(PX2_ANY_AS(obj.Data, float));
	}
	else if ("Scene_BloomBlurWeight" == obj.Name)
	{
		SetScene_BloomBlurWeight(PX2_ANY_AS(obj.Data, float));
	}
	else if ("Scene_BloomWeight" == obj.Name)
	{
		SetScene_BloomWeight(PX2_ANY_AS(obj.Data, float));
	}
	else if ("IsScene_UseShadowMap" == obj.Name)
	{
		SetScene_UseShadowMap(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("IsScene_ShadowRenderTargetSizeSameWithScreen" == obj.Name)
	{
		SetScene_ShadowRenderTargetSizeSameWithScreen(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("Scene_ShadowRenderTargetSize" == obj.Name)
	{
		SetScene_ShadowRenderTargetSize(PX2_ANY_AS(obj.Data, Float2));
	}
}
//----------------------------------------------------------------------------