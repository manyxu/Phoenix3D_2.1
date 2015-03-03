// PX2EditTimeLineEdit.hpp

#ifndef PX2EDITCURVEEDIT_HPP
#define PX2EDITCURVEEDIT_HPP

#include "PX2EditPre.hpp"
#include "PX2Float2.hpp"

namespace PX2
{

	class TimeLineEdit
	{
	public:
		TimeLineEdit();
		~TimeLineEdit();

		void SetCtrlsScale(const Float2 &scale);
		const Float2 &GetCtrlsScale() const;

		void GetInRange(float &inMin, float &inMax);
		void GetOutRange(float &outMin, float &outMax);

	protected:
		Float2 mCtrlsScale;
	};

}

#endif