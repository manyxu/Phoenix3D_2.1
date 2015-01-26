// PX2EditRenderView.hpp

#ifndef PX2EDITRENDERVIEW_HPP
#define PX2EDITRENDERVIEW_HPP

#include "PX2EditMapPre.hpp"
#include "PX2Node.hpp"
#include "PX2Renderable.hpp"
#include "PX2RenderStep.hpp"
#include "PX2EditDefine.hpp"

namespace PX2
{

	class EditRenderView
	{
	public:
		EditRenderView();
		~EditRenderView();

	protected:
		void _CreateGridGeometry();

		PX2::RenderablePtr mGrid;
		PX2::NodePtr mGridNode;

	public:
		enum ViewType
		{
			VT_TOP,
			VT_FRONT,
			VT_LEFT,
			VT_PERSPECTIVE,
			VT_MAX_TYPE
		};
		void SetViewType(ViewType viewType);
		ViewType GetViewType();

		enum ViewDetail
		{
			VD_WIREFRAME,
			VD_SOLID,
			VD_TEXTURED
		};
		void SetViewDetail(ViewDetail viewDetail);
		ViewDetail GetViewDetail() const;

		RenderStep *GetRenderStep();

	protected:
		void _ClickSelect(const APoint &scrPos);
		void _ClickSelectScene(const APoint &scrPos, SelectMode mode);

		ViewType mViewType;
		ViewDetail mViewDetail;
		RenderStepPtr mRenderStep;
		APoint mSelectPoint;

	public:
		void OnMoveHV(bool isAltDown, float h, float v);

		void OnSize(const Sizef& size);
		void OnLeftDown(const APoint &pos);
		void OnLeftUp(const APoint &pos);
		void OnMiddleDown(const APoint &pos);
		void OnMiddleUp(const APoint &pos);
		void OnMouseWheel(float delta);
		void OnRightDown(const APoint &pos);
		void OnRightUp(const APoint &pos);
		void OnMotion(const APoint &pos);

	protected:
		void _MoveCamera(float horz, float vert); //< 透视角度，沿着视线方向移动
		void _PanCamera(const float &horz, const float &vert); //< 透视角度，上下左右移动，其他视角和MoveCamera一样
		void _ZoomCamera(float zoom);
		void _RolateCamera(float horz, float vert);
		void _RoundCamera(float horz, float vert);

		Sizef mSize;
		bool mIsLeftDown;
		bool mIsMiddleDown;
		bool mIsRightDown;
		APoint mLastMousePoint;

	public:
		std::pair<float, float> mPixelToWorld;
	};

	typedef Pointer0<EditRenderView> EditRenderViewPtr;

}

#endif