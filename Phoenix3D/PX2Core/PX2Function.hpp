// PX2Function.hpp

#ifndef PX2FUNCTION_HPP
#define PX2FUNCTION_HPP

#include "PX2CorePre.hpp"

//----------------------------------------------------------------------------
#define PX2_DECLARE_FUNCTION \
public: \
	static void RegistFunctions (std::map<std::string, std::vector<FunObject> > &map);
//----------------------------------------------------------------------------

#endif