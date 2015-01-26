// PX2UIView.hpp

#ifndef PX2UIVIEW_HPP
#define PX2UIVIEW_HPP

#include "PX2Object.hpp"
#include "PX2Size.hpp"
#include "PX2RenderStep.hpp"

namespace PX2
{

	class UIView : public RenderStep
	{
	public:
		UIView();
		~UIView();

		void SetCameraAutoCenter(bool autoCenter);
		bool IsCameraAutoCenter() const;

	protected:
		virtual void OnRectChange();

		bool mIsCameraAutoCenter;

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