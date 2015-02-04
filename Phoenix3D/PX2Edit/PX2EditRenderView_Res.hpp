// PX2EditRenderView_Res.hpp

#ifndef PX2EDITUIRENDERVIEW_RES_HPP
#define PX2EDITUIRENDERVIEW_RES_HPP

#include "PX2EditMapPre.hpp"
#include "PX2EditRenderView.hpp"
#include "PX2Polysegment.hpp"
#include "PX2UIGridFrame.hpp"
#include "PX2UnityPre.hpp"
#include "PX2UICheckButton.hpp"

namespace PX2
{

	class EditRenderView_Res : public EditRenderView, public Visitor
	{
	public:
		EditRenderView_Res();
		virtual ~EditRenderView_Res();

		virtual bool InitlizeRendererStep(const std::string &name);

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

	public:
		virtual void Visit(Object *obj, const int info);

	protected:
		void _RefreshRes(const std::vector<std::string> &dirPaths,
			const std::vector<std::string> &resFilenames);

		UIFramePtr mFrame;
		UIGridFramePtr mGridFrame;
		float mItemSize;

		std::map<std::string, ResHandle> mHandlers;

		PX2::UICheckButtonPtr mLastBut;

		// Event
	public:
		virtual void DoExecute(Event *event);
	};

	typedef Pointer0<EditRenderView_Res> EditRenderView_ResPtr;

}

#endif