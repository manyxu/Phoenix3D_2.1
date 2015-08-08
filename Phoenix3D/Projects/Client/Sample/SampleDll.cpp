// ScoreDll.cpp

#include "PX2PluginManager.hpp"
#include "SamplePlugin.hpp"

namespace PX2
{

	SamplePlugin *plugin = 0;

	extern "C" void SOCCER_DLL_ITEM DLLLoadPlugin(void)
	{
		plugin = new SamplePlugin();
		PluginManager::GetSingleton().InstallPlugin(plugin);
	}

	extern "C" void SOCCER_DLL_ITEM DLLUnloadPlugin(void)
	{
		PluginManager::GetSingleton().UninstallPlugin(plugin);
	}

}