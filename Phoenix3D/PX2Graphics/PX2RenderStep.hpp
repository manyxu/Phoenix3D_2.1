// PX2RenderStep.hpp

#ifndef PX2RENDERSTEP_HPP
#define PX2RENDERSTEP_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2Object.hpp"
#include "PX2Size.hpp"
#include "PX2Rect.hpp"
#include "PX2Culler.hpp"
#include "PX2Node.hpp"

namespace PX2
{

	class Renderer;

	class RenderStep : public Object
	{
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
		void SetSize(const Sizef &rect);
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
		void SetRenderer(Renderer *renderer);
		Renderer *GetRenderer();

		void SetCamera(Camera *camera);
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
		void SetPriority(int priority);
		int GetPriority() const;

		void SetDoDepthClear(bool clear);
		bool IsDoDepthClear();

		void ComputeVisibleSet();
		void Draw();

	public_internal:
		static bool LessThan(const RenderStep *step0, const RenderStep *step1);

	protected:
		int mPriority;
		bool mIsDoClearDepth;

	public_internal:
		// ±à¼­Æ÷ÖÐµ÷ÓÃ
		void _Tick(double appTime, double elapsedTime);

		// Help
	public:
		std::pair<float, float> CalPixelToWorld();
	};

#include "PX2RenderStep.inl"
	typedef Pointer0<RenderStep> RenderStepPtr;

}

#endif