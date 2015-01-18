// PX2EditTitleWindow.hpp

#ifndef PX2EDITTITLEFRAME_HPP
#define PX2EDITTITLEFRAME_HPP

#include "PX2UITitleFrame.hpp"

namespace PX2
{

	class EditTitleFrame : public UITitleFrame
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_STREAM(EditTitleFrame);

	public:
		EditTitleFrame();
		virtual ~EditTitleFrame();
	};

	PX2_REGISTER_STREAM(EditTitleFrame);
	typedef Pointer0<EditTitleFrame> EditTitleFramePtr;

}

#endif