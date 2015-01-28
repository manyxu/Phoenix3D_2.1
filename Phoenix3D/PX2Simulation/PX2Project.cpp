// PX2Project.cpp

#include "PX2Project.hpp"
#include "PX2XMLData.hpp"
#include "PX2StringHelp.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2StringTokenizer.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2Renderer.hpp"
#include "PX2UIManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
Pointer0<Project> Project::msProject;
//----------------------------------------------------------------------------
Project::Project()
{
	if (ScriptManager::GetSingletonPtr())
		PX2_SM.SetUserTypePointer("PX2_PROJ", "Project", this);

	msProject = this;

	mBackgroundColor = Float4::MakeColor(255, 255, 200, 255);
	
	mSceneRenderStep = new0 RenderStep();
	mSceneRenderStep->SetRenderer(Renderer::GetDefaultRenderer());
	PX2_GR.AddRenderStep(mSceneRenderStep);

	mUIFrame = new0 UIFrame();
	SetUIFrame(mUIFrame);
}
//----------------------------------------------------------------------------
Project::~Project ()
{
	PX2_GR.RemoveRenderStep(mSceneRenderStep);
	mSceneRenderStep = 0;

	if (ScriptManager::GetSingletonPtr())
		PX2_SM.SetUserTypePointer("PX2_PROJ", "Project", 0);
}
//----------------------------------------------------------------------------
void Project::Destory()
{
	if (msProject)
	{
		msProject = 0;
		Project::Set(0);
	}
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
		std::string outName = outPath + outBaseName + ".px2obj";

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
	generalNode.SetAttributeInt("width", (int)mSize.Width);
	generalNode.SetAttributeInt("height", (int)mSize.Height);
	std::string colorStr =
		StringHelp::IntToString((int)(mBackgroundColor[0] * 255.0f)) + "," +
		StringHelp::IntToString((int)(mBackgroundColor[1] * 255.0f)) + "," +
		StringHelp::IntToString((int)(mBackgroundColor[2] * 255.0f)) + "," +
		StringHelp::IntToString((int)(mBackgroundColor[3] * 255.0f));
	generalNode.SetAttributeString("color", colorStr);

	// scene
	XMLNode sceneNode = projNode.NewChild("scene");
	sceneNode.SetAttributeString("filename", mSceneFilename.c_str());

	// language
	XMLNode languageNode = projNode.NewChild("language");

	// publish
	XMLNode publish = projNode.NewChild("publish");

	// setting
	XMLNode settingNode = projNode.NewChild("setting");

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
				width = generalNode.AttributeToInt("width");
				height = generalNode.AttributeToInt("height");
				std::string colorStr = generalNode.AttributeToString("color");
				StringTokenizer stk(colorStr, ",");
				Float4 color = Float4::MakeColor(
					StringHelp::StringToInt(stk[0]),
					StringHelp::StringToInt(stk[1]),
					StringHelp::StringToInt(stk[2]),
					StringHelp::StringToInt(stk[3]));

				SetName(name);
				SetSize(Sizef((float)width, (float)height));
				SetBackgroundColor(color);
			}

			// scene
			XMLNode sceneNode = rootNode.GetChild("scene");
			if (!sceneNode.IsNull())
			{
				sceneFilename = sceneNode.AttributeToString("filename");
				SetSceneFilename(sceneFilename);
			}

			// language
			XMLNode languageNode = rootNode.GetChild("language");

			// publish
			XMLNode publishNode = rootNode.GetChild("publish");

			// setting
			XMLNode settingNode = rootNode.GetChild("setting");

			// split file names
			std::string outPath;
			std::string outBaseName;
			std::string outExt;
			StringHelp::SplitFullFilename(filename, outPath, outBaseName, outExt);

			// ui
			mUIFilename = outPath + outBaseName + ".px2ui";
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
	}

	mScene = scene;
	
	if (mScene)
	{
		mScene->ComeInEventWorld();
	}

	mSceneRenderStep->SetNode(mScene);

	if (mScene)
	{
		CameraActor *camActor = mScene->GetUseCameraActor();

		if (camActor)
		{
			mSceneRenderStep->SetCamera(camActor->GetCamera());
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

	PX2_UIM.GetDefaultUIView()->SetNode(mUIFrame);
}
//----------------------------------------------------------------------------
void Project::SetSize(float width, float height)
{
	mSize = Sizef(width, height);
}
//----------------------------------------------------------------------------
void Project::SetSize(const Sizef &size)
{
	mSize = size;
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