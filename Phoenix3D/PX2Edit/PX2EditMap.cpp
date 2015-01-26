// PX2Edit.cpp

#include "PX2EditMap.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2Project.hpp"
#include "PX2EngineLoop.hpp"
#include "PX2EditEventType.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
EditMap::EditMap()
{
}
//----------------------------------------------------------------------------
EditMap::~EditMap()
{
}
//----------------------------------------------------------------------------
void EditMap::NewProject(const std::string &pathname,
	const std::string &projName, int width, int height)
{
	bool canDoChange = (EngineLoop::PT_NONE == PX2_ENGINELOOP.GetPlayType());
	if (!canDoChange) return;

	CloseProject();

	Project *proj = new0 Project();
	proj->SetName(projName);
	proj->SetSize((float)width, (float)height);
	proj->Save(pathname);
	mProjectFilePath = pathname;

	PX2_ENGINELOOP.SetSize(proj->GetSize());

	Event *ent = EditEventSpace::CreateEventX(EditEventSpace::NewProject);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
bool EditMap::LoadProject(const char *pathname)
{
	bool canDoChange = (EngineLoop::PT_NONE == PX2_ENGINELOOP.GetPlayType());
	if (!canDoChange) return false;

	CloseProject();

	Project *newProj = new0 Project();
	if (newProj->Load(pathname))
	{
		const std::string &sceneFilename = newProj->GetSceneFilename();
		if (!sceneFilename.empty())
		{
			LoadScene(sceneFilename);
		}

		mProjectFilePath = pathname;

		PX2_ENGINELOOP.SetSize(newProj->GetSize());

		Event *event = EditEventSpace::CreateEventX(EditEventSpace::LoadedProject);
		EventWorld::GetSingleton().BroadcastingLocalEvent(event);

		return true;
	}
	else
	{
		Project::Destory();
	}

	return false;
}
//----------------------------------------------------------------------------
bool EditMap::SaveProject()
{
	bool canDoChange = (EngineLoop::PT_NONE == PX2_ENGINELOOP.GetPlayType());

	Project *proj = Project::GetSingletonPtr();
	if (proj)
	{
		if (canDoChange)
		{
			if (proj->Save(mProjectFilePath))
			{
				Event *ent = EditEventSpace::CreateEventX(
					EditEventSpace::SavedProject);
				EventWorld::GetSingleton().BroadcastingLocalEvent(ent);

				return true;
			}
		}
		else
		{
			proj->SaveConfig(mProjectFilePath);
		}
	}

	return false;
}
//----------------------------------------------------------------------------
bool EditMap::SaveProjectAs(const char *pathname)
{
	bool canDoChange = (EngineLoop::PT_NONE == PX2_ENGINELOOP.GetPlayType());

	Project *proj = Project::GetSingletonPtr();
	if (proj)
	{
		if (canDoChange)
		{
			if (proj->Save(pathname))
			{
				Event *ent = EditEventSpace::CreateEventX(
					EditEventSpace::SavedProject);
				EventWorld::GetSingleton().BroadcastingLocalEvent(ent);

				return true;
			}
		}
		else
		{
			proj->SaveConfig(pathname);
		}
	}

	return false;
}
//----------------------------------------------------------------------------
void EditMap::CloseProject()
{
	bool canDoChange = (EngineLoop::PT_NONE == PX2_ENGINELOOP.GetPlayType());
	if (!canDoChange) return;

	Project *oldProj = Project::GetSingletonPtr();
	if (oldProj)
	{
		Scene *scene = PX2_PROJ.GetScene();
		if (scene)
		{
			PX2_RM.ClearRes(oldProj->GetResourcePath());
			oldProj->SetScene(0);
			scene = 0;
		}

		Event *ent = EditEventSpace::CreateEventX(EditEventSpace::CloseProject);
		EventWorld::GetSingleton().BroadcastingLocalEvent(ent);

		Project::Destory();
	}
}
//----------------------------------------------------------------------------
void EditMap::NewScene()
{
	bool canDoChange = (EngineLoop::PT_NONE == PX2_ENGINELOOP.GetPlayType());
	if (!canDoChange) return;

	CloseScene();

	Scene *scene = new0 Scene();
	scene->SetName("Please give me a name.");
	PX2_PROJ.SetScene(scene);
	PX2_PROJ.SetSceneFilename("");

	Event *ent = EditEventSpace::CreateEventX(EditEventSpace::NewScene);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
bool EditMap::LoadScene(const std::string &pathname)
{
	bool canDoChange = (EngineLoop::PT_NONE == PX2_ENGINELOOP.GetPlayType());
	if (!canDoChange) return false;

	CloseScene();

	Scene *newscene = DynamicCast<Scene>(PX2_RM.BlockLoad(pathname));
	if (newscene)
	{
		Project::GetSingleton().SetScene(newscene);
		Project::GetSingleton().SetSceneFilename(pathname);

		Event *ent = EditEventSpace::CreateEventX(EditEventSpace::LoadedScene);
		EventWorld::GetSingleton().BroadcastingLocalEvent(ent);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool EditMap::SaveScene(const std::string &pathname)
{
	bool canDoChange = (EngineLoop::PT_NONE == PX2_ENGINELOOP.GetPlayType());
	if (!canDoChange) return false;

	std::string toPath = _CalSavePath(pathname);

	if (_SaveSceneInternal(toPath))
	{
		PX2_PROJ.SetSceneFilename(toPath);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool EditMap::SaveSceneAs(const std::string &pathname)
{
	bool canDoChange = (EngineLoop::PT_NONE == PX2_ENGINELOOP.GetPlayType());
	if (!canDoChange) return false;

	std::string toPath = _CalSavePath(pathname);

	return _SaveSceneInternal(toPath);
}
//----------------------------------------------------------------------------
void EditMap::CloseScene()
{
	bool canDoChange = (EngineLoop::PT_NONE == PX2_ENGINELOOP.GetPlayType());
	if (!canDoChange) return;

	Scene *scene = PX2_PROJ.GetScene();
	if (scene)
	{
		PX2_RM.ClearRes(scene->GetResourcePath());
		PX2_PROJ.SetScene(0);
		PX2_PROJ.SetSceneFilename("");
		scene = 0;

		Event *ent = EditEventSpace::CreateEventX(EditEventSpace::CloseScene);
		PX2_EW.BroadcastingLocalEvent(ent);
	}
}
//----------------------------------------------------------------------------
std::string EditMap::_CalSavePath(const std::string &pathname)
{
	std::string pathStand = StringHelp::StandardisePath(pathname);
	pathStand = pathStand.substr(0, pathStand.length() - 1);

	std::string toPath = pathStand;
	size_t begin = toPath.find("Data/");
	if (begin != std::string::npos)
	{
		size_t length = toPath.length() - begin;
		toPath = toPath.substr(begin, length);
	}

	return toPath;
}
//----------------------------------------------------------------------------
bool EditMap::_SaveSceneInternal(const std::string &pathname)
{
	Scene *scene = PX2_PROJ.GetScene();
	if (!scene) return false;

	scene->SetResourcePath(pathname);

	OutStream outStream;

	outStream.Insert(scene);

	if (outStream.Save(pathname))
	{
		Event *ent = EditEventSpace::CreateEventX(EditEventSpace::SavedScene);
		EventWorld::GetSingleton().BroadcastingLocalEvent(ent);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------