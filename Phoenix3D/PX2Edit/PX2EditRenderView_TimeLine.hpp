// PX2EditRenderView_TimeLine.hpp

#ifndef PX2EDITUIRENDERVIEW_TIMELINE_HPP
#define PX2EDITUIRENDERVIEW_TIMELINE_HPP

#include "PX2EditPre.hpp"
#include "PX2EditRenderView.hpp"
#include "PX2Polysegment.hpp"
#include "PX2UIFrame.hpp"
#include "PX2UIView.hpp"

namespace PX2
{

	class EditRenderView_TimeLine : public EditRenderView
	{
	public:
		EditRenderView_TimeLine();
		virtual ~EditRenderView_TimeLine();

		virtual bool InitlizeRendererStep(const std::string &name);

		virtual void Tick(double elapsedTime);

		void FitViewHorizontally();
		void FitViewVertically();
		void FitViewToAll();
		void FitViewToSelected();

	protected:
		void _RefreshGrid(bool doScale);

		enum MoveMode
		{
			MM_PAN,
			MM_ZOOM,
			MM_MAX_MODE
		};
		MoveMode mMoveMode;

		UIViewPtr mUIView;
		int mLeftWidth;

		UIFramePtr mFrame;
		PX2::PolysegmentPtr mGridPoly;
		PX2::NodePtr mGridNode;

		float mPixelOverCamIn;
		float mPixelOverCamOut;

		// Grid
		float mUPerGrid;
		float mVPerGrid;

		float mXStart;
		float mXEnd;
		float mZStart;
		float mZEnd;

		struct FontStr
		{
			FontStr() { x = 0; y = 0; }
			int x;
			int y;
			std::string str;
		};
		std::vector<FontStr> mFontStrs;

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

	typedef Pointer0<EditRenderView_TimeLine> EditRenderView_TimeLinePtr;

}

#endif