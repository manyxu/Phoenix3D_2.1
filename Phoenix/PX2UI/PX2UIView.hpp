// PX2UIView.hpp

#ifndef PX2UIVIEW_HPP
#define PX2UIVIEW_HPP

#include "PX2Object.hpp"
#include "PX2Size.hpp"
#include "PX2UIFrame.hpp"

namespace PX2
{

	class Renderer;
	class Camera;

	class UIView : public Object
	{
	public:
		UIView();
		~UIView();

		void Clear();

	protected:
		static float msUICameraZ;

		// Size
	public:
		void SetSize(float width, float height);
		void SetSize(const Sizef &size);
		const Sizef &GetSize() const;

	protected:
		void OnSizeChange();
		Sizef mSize;

		// Renderer Camera Culler
	public:
		void SetRenderer(Renderer *renderer);
		Renderer *GetRenderer();

		void SetCamera(Camera *camera);
		Camera *GetCamera();

	protected:
		Renderer *mRenderer;
		CameraPtr mCamera;
		Culler mCuller;

		// UIFrame
	public:
		void SetFrame(UIFrame *frame);
		UIFrame *GetFrame();

	protected:
		UIFramePtr mUIFrame;

		// Pick
	public:

	protected:
		float mMoveAdjugeParam;
	};

#include "PX2UIView.inl"
	typedef Pointer0<UIView> UIViewPtr;

}

#endif