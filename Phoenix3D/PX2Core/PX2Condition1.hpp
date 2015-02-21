// PX2Condition1.hpp

#ifndef PX2CONDITION1_HPP
#define PX2CONDITION1_HPP

#include "PX2CorePre.hpp"
#include "PX2ConditionType.hpp"

namespace PX2
{

	void CreateCondition (ConditionType &cond);
	void CloseCondition (ConditionType &cond);
	void PostCondition (ConditionType &cond);
	void WaitCondition (ConditionType &cond);

}

#endif