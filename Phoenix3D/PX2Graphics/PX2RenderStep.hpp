// PX2RenderStep.hpp

#ifndef PX2RENDERSTEP_HPP
#define PX2RENDERSTEP_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2Object.hpp"
#include "PX2Size.hpp"
#include "PX2Rect.hpp"
#include "PX2Culler.hpp"
#include "PX2Node.hpp"
#include "PX2RenderTarget.hpp"

namespace PX2
{

	class Renderer;

	class RenderStep : public Object
	{
		PX2_DECLARE_RTTI;

	public:
		RenderStep();
		~RenderStep();

	public:
		virtual void Update(double appSeconds, double elapsedSeconds);

	protected:
		bool mIsUpdated;

	public:
		void Enable(bool enable);
		bool IsEnable() const;

	protected:
		bool mIsEnable;

		// Size
	public:
		void SetSize(const Sizef &size);
		const Sizef &GetSize() const;

		void SetSizeChangeReAdjustCamera(bool doReAdjust);

	protected:
		virtual void OnSizeChange();

		Sizef mSize;
		bool mIsSizeChangeReAdjustCamera;

		// ViewPort
	public:
		void SetViewPort(const Rectf &viewPort);
		const Rectf &GetViewPort() const;

	protected:
		Rectf mViewPort;

		// Renderer Camera Culler
	public:
		virtual void SetRenderer(Renderer *renderer);
		Renderer *GetRenderer();

		virtual void SetCamera(Camera *camera);
		Camera *GetCamera();

		bool GetPickRay(float x, float y, APoint& origin, AVector& direction);

	protected:
		Renderer *mRenderer;
		CameraPtr mCamera;
		Culler mCuller;

		// Node
	public:
		virtual void SetNode(Node *node);
		Node *GetNode();

	protected:
		NodePtr mNode;

		// Draw
	public:
		void SetPriority(int priority); // 越大月在前
		int GetPriority() const;

		void SetDoDepthClear(bool clear);
		bool IsDoDepthClear();

		virtual void ComputeVisibleSetAndEnv();
		virtual void Draw();

	public_internal:
		static bool LessThan(const RenderStep *step0, const RenderStep *step1);

	protected:
		int mPriority;
		bool mIsDoClearDepth;

	public_internal:
		// 编辑器中调用
		void _Tick(double appTime, double elapsedTime);

		// Help
	public:
		std::pair<float, float> CalPixelToWorld();
	};

#include "PX2RenderStep.inl"
	typedef Pointer0<RenderStep> RenderStepPtr;

}

#endif