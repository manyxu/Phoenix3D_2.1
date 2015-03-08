// PX2EditRenderView_PreView.hpp

#ifndef PX2EDITUIRENDERVIEW_PREVIEW_HPP
#define PX2EDITUIRENDERVIEW_PREVIEW_HPP

#include "PX2EditPre.hpp"
#include "PX2EditRenderView.hpp"
#include "PX2Polysegment.hpp"
#include "PX2UIObjectCtrl.hpp"

namespace PX2
{

	class EditRenderView_PreView : public EditRenderView
	{
	public:
		EditRenderView_PreView();
		virtual ~EditRenderView_PreView();

		virtual void Tick(double elapsedTime);

	public:
		virtual void OnSize(const Sizef& size);
		virtual void OnLeftDown(const APoint &pos);
		virtual void OnLeftUp(const APoint &pos);
		virtual void OnMiddleDown(const APoint &pos);
		virtual void OnMiddleUp(const APoint &pos);
		virtual void OnMouseWheel(float delta);
		virtual void OnRightDown(const APoint &pos);
		virtual void OnRightUp(const APoint &pos);
		virtual void OnMotion(const APoint &pos);

		// Event
	public:
		virtual void DoExecute(Event *event);
	};

	typedef Pointer0<EditRenderView_PreView> EditRenderView_PreViewPtr;

}

#endif