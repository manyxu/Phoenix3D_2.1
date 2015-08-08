// SamplePlugin.hpp

#ifndef SOCCERPLUGIN_HPP
#define SOCCERPLUGIN_HPP

#include "PX2Plugin.hpp"
#include "SamplePre.hpp"

namespace PX2
{

	class SOCCER_DLL_ITEM SamplePlugin : public Plugin
	{
	public:
		SamplePlugin();
		virtual ~SamplePlugin();

		virtual std::string GetName();

		virtual void OnInstall();
		virtual void OnTernamate();
		virtual void OnUnstall();
	};

}

#endif