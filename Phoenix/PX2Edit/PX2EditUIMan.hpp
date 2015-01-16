// PX2EditUIMan.hpp

#ifndef PX2EDITUIMAN_HPP
#define PX2EDITUIMAN_HPP

#include "PX2Singleton_NeedNew.hpp"
#include "PX2UIFrame.hpp"

namespace PX2
{

	class EditUIMan
	{
	public:
		EditUIMan();
		~EditUIMan();

		void _CreateMainFrame(UIFrame *parent);
	};

}

#endif