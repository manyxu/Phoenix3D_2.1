// PX2EditRenderView_UI.hpp

#ifndef PX2EDITUIRENDERVIEW_UI_HPP
#define PX2EDITUIRENDERVIEW_UI_HPP

#include "PX2EditPre.hpp"
#include "PX2EditRenderView.hpp"
#include "PX2Polysegment.hpp"

namespace PX2
{

	class EditRenderView_UI : public EditRenderView
	{
	public:
		EditRenderView_UI();
		virtual ~EditRenderView_UI();

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

	protected:
		void _CreateGridGeometry();
		void _CreateNodeCtrl();
		void _UpdateProjectRange();
		void _AdjustCameraPercent();
		void _PickPos();

		PX2::PolysegmentPtr mProjRangeSegment;
		PX2::NodePtr mRangeNode;

		// Event
	public:
		virtual void DoExecute(Event *event);
	};

	typedef Pointer0<EditRenderView_UI> EditRenderView_UIPtr;

}

#endif