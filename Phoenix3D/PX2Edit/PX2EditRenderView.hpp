// PX2EditRenderView.hpp

#ifndef PX2EDITRENDERVIEW_HPP
#define PX2EDITRENDERVIEW_HPP

#include "PX2EditMapPre.hpp"
#include "PX2Node.hpp"
#include "PX2Renderable.hpp"
#include "PX2RenderStep.hpp"
#include "PX2EditDefine.hpp"
#include "PX2SceneNodeCtrl.hpp"
#include "PX2Renderer.hpp"

namespace PX2
{

	class RendererInput;

	class EditRenderView : public EventHandler
	{
	public:
		EditRenderView();
		virtual ~EditRenderView();

	public:
		void SetPt_Data(void *data);
		void *GetPt_Data();
		void SetPt_Size(const Sizef &size);
		const Sizef &GetPt_Size() const;

		virtual bool InitlizeRendererStep(const std::string &name);
		bool IsRenderStepCreated() const;

	protected:
		void *mPt_Data;
		Sizef mPt_Size;

	public:
		void SetRenderer(Renderer *renderer);
		void SetCamera(Camera *camera);
		void SetRenderStep(RenderStep *rs);
		RenderStep *GetRenderStep();
		RenderStep *GetRenderStepCtrl();
		RenderStep *GetRenderStepCtrl1();
		virtual void Tick(double elapsedTime);

		void Enable(bool enable);
		bool IsEnable() const;

	protected:
		RendererInput *mRendererInput;
		Renderer *mRenderer;
		RenderStepPtr mRenderStep;

		RenderStepPtr mRenderStepCtrl;
		RenderStepPtr mRenderStepCtrl1;
		bool mIsRenderCreated;

		bool mIsEnable;

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