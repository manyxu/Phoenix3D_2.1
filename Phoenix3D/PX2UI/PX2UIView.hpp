// PX2UIView.hpp

#ifndef PX2UIVIEW_HPP
#define PX2UIVIEW_HPP

#include "PX2Object.hpp"
#include "PX2Size.hpp"
#include "PX2RenderStep.hpp"
#include "PX2CameraNode.hpp"

namespace PX2
{

	class UIView : public RenderStep
	{
	public:
		UIView();
		~UIView();

		virtual void Update(double appSeconds, double elapsedSeconds);

	public:
		virtual void SetNode(Node *node);

	public:
		CameraNode *GetCameraNode();

		void SetCameraAutoAdjust(bool autoAdjust);
		bool IsCameraAutoAdjust() const;

		void SetCameraFrustumSize(const Sizef &size);
		const Sizef &GetCameraFrustumSize() const;

	protected:
		virtual void OnSizeChange();

		bool mIsCameraAutoAdjust;
		CameraNodePtr mCameraNode;
		Sizef mCameraFrustumSize;

		// Pick
	public:

	protected:
		float mMoveAdjugeParam;

		// general
	protected:
		static float msUICameraZ;
	};

#include "PX2UIView.inl"
	typedef Pointer0<UIView> UIViewPtr;

}

#endif