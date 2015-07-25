// PX2PluginManager.cpp

#include "PX2PluginManager.hpp"
#include "PX2DynLibManager.hpp"
#include "PX2Assert.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
typedef void(*DLL_LOAD_PLUGIN)(void);
typedef void(*DLL_UNLOAD_PLUGIN)(void);
//----------------------------------------------------------------------------
PluginManager::PluginManager()
{
}
//----------------------------------------------------------------------------
PluginManager::~PluginManager()
{
}
//----------------------------------------------------------------------------
void PluginManager::Load(const std::string &filename)
{
	DynLib* lib = DynLibManager::GetSingleton().Load(filename);
	mPluginLibs.push_back(lib);

	DLL_LOAD_PLUGIN pFunc = (DLL_LOAD_PLUGIN)lib->GetSymbol(
		"DllLoadPlugin");

	if (!pFunc)
	{
		assertion(false, "Cannot find symbol dllStartPlugin in library : %s",
			filename.c_str());
	}

	pFunc();
}
//----------------------------------------------------------------------------
void PluginManager::Unload(const std::string &filename)
{
	std::vector<DynLib *>::iterator i;

	for (i = mPluginLibs.begin(); i != mPluginLibs.end(); ++i)
	{
		const std::string &libName = (*i)->GetName();

		if (libName == filename)
		{
			DLL_UNLOAD_PLUGIN pFunc = (DLL_UNLOAD_PLUGIN)(*i)->GetSymbol(
				"DllUnloadPlugin");

			pFunc();

			DynLibManager::GetSingleton().Unload(*i);

			mPluginLibs.erase(i);
			
			return;
		}

	}
}
//----------------------------------------------------------------------------
void PluginManager::UnloadPlugins()
{
	for (std::vector<DynLib *>::reverse_iterator i = mPluginLibs.rbegin(); 
		i != mPluginLibs.rend(); ++i)
	{
		DLL_UNLOAD_PLUGIN pFunc = (DLL_UNLOAD_PLUGIN)(*i)->GetSymbol(
			"DllUnloadPlugin");

		pFunc();

		DynLibManager::GetSingleton().Unload(*i);

	}
	mPluginLibs.clear();

	for (std::vector<Plugin *>::reverse_iterator i = mPlugins.rbegin(); 
		i != mPlugins.rend(); ++i)
	{
		(*i)->Unstall();
	}

	mPlugins.clear();
}
//----------------------------------------------------------------------------
void PluginManager::InstallPlugin(Plugin* plugin)
{
	PX2_LOG_INFO("Installing plugin: %s", plugin->GetName().c_str());

	mPlugins.push_back(plugin);
	
	plugin->Install();
	plugin->Initialise();

	PX2_LOG_INFO("Plugin successfully installed");
}
//----------------------------------------------------------------------------
void PluginManager::UninstallPlugin(Plugin* plugin)
{
	PX2_LOG_INFO("Uninstalling plugin: %s", plugin->GetName().c_str());

	std::vector<Plugin *>::iterator i = std::find(mPlugins.begin(),
		mPlugins.end(), plugin);
	if (i != mPlugins.end())
	{
		plugin->Terminate();
		plugin->Unstall();

		mPlugins.erase(i);
	}

	PX2_LOG_INFO("Plugin successfully uninstalled");
}
//----------------------------------------------------------------------------