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

		void Clear();
		virtual void Update(double appSeconds, double elapsedSeconds);

	protected:
		bool mIsUpdated;

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

		bool GetPickRay(int x, int y, APoint& origin, AVector& direction);

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
		void ComputeVisibleSet();
		void Draw();

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