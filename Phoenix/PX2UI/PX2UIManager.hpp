// PX2UIManager.hpp

#ifndef PX2UIMANAGER_HPP
#define PX2UIMANAGER_HPP

#include "PX2UIPre.hpp"
#include "PX2Singleton.hpp"

namespace PX2
{

	class UIManager
	{
	public:
		UIManager();
		~UIManager();

		virtual void Run();
	};

}

#endif