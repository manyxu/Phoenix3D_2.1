// PX2UIObjectCtrl.hpp

#ifndef PX2UIOBJECTCTRL_HPP
#define PX2UIOBJECTCTRL_HPP

#include "PX2EditPre.hpp"
#include "PX2EventHandler.hpp"
#include "PX2Movable.hpp"
#include "PX2Vector2.hpp"
#include "PX2SwitchNode.hpp"

namespace PX2
{

	class RenderStep;

	class PX2_EDIT_ITEM UIObjectCtrl : public PX2::EventHandler
	{
	public:
		UIObjectCtrl ();
		virtual ~UIObjectCtrl ();

		enum ShapeType
		{
			ST_NONE = 0,
			ST_RECT,
			ST_CROSS,
			ST_MAX_TYPE
		};
		void SetShapeType (ShapeType type);
		ShapeType GetShapeType ();

		// -1为没有drag，0 为drag整体
		// 从左下开始，逆时针为1-8
		void SetDragIndex (int index);
		int GetDragIndex ();

		PX2::Movable *GetCtrlsGroup ();

		// PX2 Event
		virtual void DoExecute (PX2::Event *event);

		void OnLeftDown(RenderStep *renderStep, const PX2::APoint &pos);
		void OnLeftUp(RenderStep *renderStep, const PX2::APoint &pos);
		void OnMotion(bool leftDown, RenderStep *renderStep,
			PX2::APoint posNow, PX2::APoint posBefore);

	protected:
		void UpdateOnSelectUI();
		int _GetDragIndex (RenderStep *renderStep, const PX2::APoint &pos);

		ShapeType mShapeType;

		int mDragIndex;
		PX2::SwitchNodePtr mCtrlsGroup;
		PX2::NodePtr mRectCtrl;
		PX2::NodePtr mCrossCtrl;
		float mSmallRectSize;
	};

	typedef Pointer0<UIObjectCtrl> UIObjectCtrlPtr;

}

#endif