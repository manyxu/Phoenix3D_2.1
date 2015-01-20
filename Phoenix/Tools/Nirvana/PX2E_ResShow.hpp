// PX2E_ResShow.hpp

#ifndef PX2E_RESSHOW_HPP
#define PX2E_RESSHOW_HPP

#include "PX2EditorPre.hpp"

namespace PX2Editor
{

	class ResShow : public wxWindow
	{
		DECLARE_DYNAMIC_CLASS(ResShow)

	public:
		ResShow(wxWindow *parent);
		virtual ~ResShow();

	protected:
		DECLARE_EVENT_TABLE()
		ResShow();
	};

}

#endif