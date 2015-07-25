// PX2DynLibManager.hpp

#ifndef PX2DYNLIBMANAGER_HPP
#define PX2DYNLIBMANAGER_HPP

#include "PX2UnityPre.hpp"
#include "PX2Singleton.hpp"
#include "PX2DynLib.hpp"

namespace PX2
{

	class DynLibManager
	{
	public:
		PX2_SINGLETION(DynLibManager);

	public:
		DynLib *Load(const std::string &filename);
		void Unload(DynLib *dynlib);

	protected:
		typedef std::map<std::string, DynLib*> PluginList;
		PluginList mPluginList;
	};

}

#endif