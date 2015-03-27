// PX2UIView.hpp

#ifndef PX2UIVIEW_HPP
#define PX2UIVIEW_HPP

#include "PX2Object.hpp"
#include "PX2Size.hpp"
#include "PX2RenderStep.hpp"
#include "PX2CameraNode.hpp"
#include "PX2Renderable.hpp"
#include "PX2UICallback.hpp"
#include "PX2UIButton.hpp"

namespace PX2
{

	class UIView : public RenderStep
	{
		PX2_DECLARE_RTTI;

	public:
		UIView(int viewID);
		~UIView();

		int GetViewID() const;

		virtual void Update(double appSeconds, double elapsedSeconds);

	protected:
		int mViewID;

		// Node
	public:
		virtual void SetNode(Node *node);

		void SetSuperTopMoveable(Movable *movable);
		Movable *GetSuperTopMovbale();
		void PushTopMovable(Movable *movable);
		void PopTopMovable();

		Movable *GetTopestMovable();

	protected:
		MovablePtr mSuperTopMovable;
		std::deque<MovablePtr> mTopMovables;

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
		void SetPickAcceptRect(const Rectf &rect);
		const Rectf &GetPickAcceptRect() const;

		void SetNotPickedCallback(NotPickedCallback callback);

		std::vector<RenderablePtr> &GetPickedRenderables();

	public_internal:
		std::list<UIButtonPtr > mPressedButs;

	protected:
		void _DoPick(float x, float z, int pickInfo,
			std::vector<RenderablePtr> &vec);

		Rectf mPickAcceptRect;

		float mMoveAdjugeParam;
		float mMoveAdjugeParamSquare;

		bool mIsPressedVailed;
		bool mIsPressed;
		APoint mPressedPos;

		std::vector<RenderablePtr> mPickedRenderables;
		NotPickedCallback mNotPickedCallback;

		// general
	protected:
		static float msUICameraZ;

		// public
	public:
		virtual void DoExecute(Event *event);
	};

#include "PX2UIView.inl"
	typedef Pointer0<UIView> UIViewPtr;

}

#endif