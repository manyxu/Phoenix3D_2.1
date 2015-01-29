// PX2EditRenderView_UI.hpp

#ifndef PX2EDITUIRENDERVIEW_UI_HPP
#define PX2EDITUIRENDERVIEW_UI_HPP

#include "PX2EditMapPre.hpp"
#include "PX2EditRenderView.hpp"

namespace PX2
{

	class EditRenderView_UI : public EditRenderView
	{
	public:
		EditRenderView_UI();
		virtual ~EditRenderView_UI();
	};

	typedef Pointer0<EditRenderView_UI> EditUIRenderViewPtr;

}

#endif