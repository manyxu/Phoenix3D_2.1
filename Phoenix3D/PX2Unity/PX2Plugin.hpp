// PX2Plugin.hpp

#ifndef PX2PLUGIN_HPP
#define PX2PLUGIN_HPP

#include "PX2UnityPre.hpp"

namespace PX2
{

	class Plugin
	{
	public:
		Plugin() {}
		virtual ~Plugin() {}

		virtual std::string GetName() = 0;

		virtual void Install() = 0;
		virtual void Unstall() = 0;

		virtual void Initialise() = 0;
		virtual void Terminate() = 0;
	};

}

#endif