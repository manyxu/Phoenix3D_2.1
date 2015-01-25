// PX2EditParams.hpp

#ifndef PX2EDITORPARAMS_HPP
#define PX2EDITORPARAMS_HPP

#include "PX2EditPre.hpp"
#include "PX2Singleton.hpp"

namespace PX2
{

	class EditParams
	{
	public:
		PX2_SINGLETION(EditParams);

		bool Save(std::string filename);
		bool Load(std::string filename);

	public:
		float GridSize;
	};

}

#endif