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
		void Update(double appSeconds, double elapsedSeconds);

	protected:
		bool mIsUpdated;

		// Rect
	public:
		void SetRect(const Rectf &rect);
		const Rectf &GetRect() const;
		Sizef GetSize() const;

	protected:
		virtual void OnRectChange();
		Rectf mRect;

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
		void SetNode(Node *node);
		Node *GetNode();

	protected:
		NodePtr mNode;

		// Draw
	public:
		void ComputeVisibleSet();
		void Draw();

		// Help
	public:
		std::pair<float, float> CalPixelToWorld();
	};

#include "PX2RenderStep.inl"
	typedef Pointer0<RenderStep> RenderStepPtr;

}

#endif