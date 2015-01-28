// PX2EditParams.hpp

#ifndef PX2EDITORPARAMS_HPP
#define PX2EDITORPARAMS_HPP

#include "PX2EditPre.hpp"
#include "PX2Singleton.hpp"
#include "PX2Singleton_NeedNew.hpp"
#include "PX2Object.hpp"

namespace PX2
{

	class EditParams : public Object
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(EditParams);

	public:
		EditParams();
		~EditParams();
		bool Save(std::string filename);
		bool Load(std::string filename);
	public:
		float GridSize;
	};

	PX2_REGISTER_STREAM(EditParams);
	typedef Pointer0<EditParams> EditParamsPtr;
}

#endif